#include "RadeonInfo.h"
#include "RadeonInit.h"

#include <SupportDefs.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <bit>

#include "gfx_6_0_d.h"
//#include "gfx_7_2_enum.h"
#include "gfx_6_0.h"
#include "dce_6_0_d.h"
#include "bif_3_0_d.h"
#include "bif_3_0.h"
#include "oss_1_0_d.h"
#include "gmc_6_0_d.h"
#include "gmc_6_0.h"
//#include "si_enums.h"
#include "sid_amdgpu.h"


union GbTileMode {
	struct {
		uint32 microTileMode:    2;
		uint32 arrayMode:        4;
		uint32 pipeConfig:       5;
		uint32 tileSplit:        3;
		uint32 bankWidth:        2;
		uint32 bankHeight:       2;
		uint32 macroTileAspect:  2;
		uint32 numBanks:         2;
		uint32 microTileModeNew: 3;
		uint32 sampleSplit:      2;
		uint32 altPipeConfig:    5;
	};
	uint32 val;
};


#define DRM_ERROR(format...) printf(format)
inline void WARN_ON(bool cond) {if (cond) abort();}
inline void BUG() {abort();}

static inline uint32 amdgpu_gfx_create_bitmask(uint32 bit_width)
{
	return (uint32)((1ULL << bit_width) - 1);
}

static void amdgpu_gfx_parse_disable_cu(unsigned *mask, unsigned max_se, unsigned max_sh)
{
	memset(mask, 0, sizeof(*mask) * max_se * max_sh);
}


static void gfx_v6_0_select_se_sh(struct amdgpu_device *adev, uint32 seNum, uint32 shNum, uint32 instance)
{
	GrbmGfxIndex data{};

	if (seNum == 0xffffffff)
		data.seBroadcastWrites = 1;
	else
		data.seIndex = seNum;

	if (shNum == 0xffffffff)
		data.shBroadcastWrites = 1;
	else
		data.shIndex = shNum;

	if (instance == 0xffffffff)
		data.instanceBroadcastWrites = 1;
	else
		data.instanceIndex = instance;

	WriteReg4AmdGpu(mmGRBM_GFX_INDEX, data.val);
}

static uint32 gfx_v6_0_get_rb_active_bitmap(struct amdgpu_device *adev)
{
	uint32 data, mask;

	data = ReadReg4AmdGpu(mmCC_RB_BACKEND_DISABLE) |
		ReadReg4AmdGpu(mmGC_USER_RB_BACKEND_DISABLE);

	data = GcUserRbBackendDisable{.val = data}.backendDisable /*REG_GET_FIELD(data, GC_USER_RB_BACKEND_DISABLE, BACKEND_DISABLE)*/;

	mask = amdgpu_gfx_create_bitmask(adev->gfx.config.max_backends_per_se/
					 adev->gfx.config.max_sh_per_se);

	return ~data & mask;
}

static void gfx_v6_0_raster_config(struct amdgpu_device *adev, uint32 *rconf)
{
	switch (adev->asic_type) {
	case CHIP_TAHITI:
	case CHIP_PITCAIRN:
		*rconf |= PaScRasterConfig{
			.rbXsel2 = 2,
			.rbXsel = 1,
			.pkrMap = 2,
			.pkrYsel = 1,
			.seMap = 2,
			.seXsel = 2,
			.seYsel = 2
		}.val;
		break;
	case CHIP_VERDE:
		*rconf |= PaScRasterConfig{
			.rbXsel = 1,
			.pkrMap = 2,
			.pkrYsel = 1
		}.val;
		break;
	case CHIP_OLAND:
		*rconf |= PaScRasterConfig{
			.pkrYsel = 1
		}.val;
		break;
	case CHIP_HAINAN:
		*rconf |= 0x0;
		break;
	default:
		DRM_ERROR("unknown asic: 0x%x\n", adev->asic_type);
		break;
	}
}

static void gfx_v6_0_write_harvested_raster_configs(struct amdgpu_device *adev,
						    uint32 raster_config, unsigned rb_mask,
						    unsigned num_rb)
{
	unsigned sh_per_se = std::max<unsigned>(adev->gfx.config.max_sh_per_se, 1);
	unsigned num_se = std::max<unsigned>(adev->gfx.config.max_shader_engines, 1);
	unsigned rb_per_pkr = std::min<unsigned>(num_rb / num_se / sh_per_se, 2);
	unsigned rb_per_se = num_rb / num_se;
	unsigned se_mask[4];
	unsigned se;

	se_mask[0] = ((1 << rb_per_se) - 1) & rb_mask;
	se_mask[1] = (se_mask[0] << rb_per_se) & rb_mask;
	se_mask[2] = (se_mask[1] << rb_per_se) & rb_mask;
	se_mask[3] = (se_mask[2] << rb_per_se) & rb_mask;

	WARN_ON(!(num_se == 1 || num_se == 2 || num_se == 4));
	WARN_ON(!(sh_per_se == 1 || sh_per_se == 2));
	WARN_ON(!(rb_per_pkr == 1 || rb_per_pkr == 2));

	for (se = 0; se < num_se; se++) {
		PaScRasterConfig raster_config_se{.val = raster_config};
		unsigned pkr0_mask = ((1 << rb_per_pkr) - 1) << (se * rb_per_se);
		unsigned pkr1_mask = pkr0_mask << rb_per_pkr;
		int idx = (se / 2) * 2;

		if ((num_se > 1) && (!se_mask[idx] || !se_mask[idx + 1])) {
			if (!se_mask[idx])
				raster_config_se.seMap = RASTER_CONFIG_SE_MAP_3;
			else
				raster_config_se.seMap = RASTER_CONFIG_SE_MAP_0;
		}

		pkr0_mask &= rb_mask;
		pkr1_mask &= rb_mask;
		if (rb_per_se > 2 && (!pkr0_mask || !pkr1_mask)) {
			if (!pkr0_mask)
				raster_config_se.pkrMap = RASTER_CONFIG_PKR_MAP_3;
			else
				raster_config_se.pkrMap = RASTER_CONFIG_PKR_MAP_0;
		}

		if (rb_per_se >= 2) {
			unsigned rb0_mask = 1 << (se * rb_per_se);
			unsigned rb1_mask = rb0_mask << 1;

			rb0_mask &= rb_mask;
			rb1_mask &= rb_mask;
			if (!rb0_mask || !rb1_mask) {
				if (!rb0_mask)
					raster_config_se.rbMapPkr0 = RASTER_CONFIG_RB_MAP_3;
				else
					raster_config_se.rbMapPkr0 = RASTER_CONFIG_RB_MAP_0;
			}

			if (rb_per_se > 2) {
				rb0_mask = 1 << (se * rb_per_se + rb_per_pkr);
				rb1_mask = rb0_mask << 1;
				rb0_mask &= rb_mask;
				rb1_mask &= rb_mask;
				if (!rb0_mask || !rb1_mask) {
					if (!rb0_mask)
						raster_config_se.rbMapPkr1 = RASTER_CONFIG_RB_MAP_3;
					else
						raster_config_se.rbMapPkr1 = RASTER_CONFIG_RB_MAP_0;
				}
			}
		}

		/* GRBM_GFX_INDEX has a different offset on SI */
		gfx_v6_0_select_se_sh(adev, se, 0xffffffff, 0xffffffff);
		WriteReg4AmdGpu(mmPA_SC_RASTER_CONFIG, raster_config_se.val);
	}

	/* GRBM_GFX_INDEX has a different offset on SI */
	gfx_v6_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
}

static uint32 gfx_v6_0_get_cu_enabled(struct amdgpu_device *adev)
{
	uint32 data, mask;

	data = ReadReg4AmdGpu(mmCC_GC_SHADER_ARRAY_CONFIG) | ReadReg4AmdGpu(mmGC_USER_SHADER_ARRAY_CONFIG);

	mask = amdgpu_gfx_create_bitmask(adev->gfx.config.max_cu_per_sh);
	return ~CcGcShaderArrayConfig{.val = data}.inactiveCus/*REG_GET_FIELD(data, CC_GC_SHADER_ARRAY_CONFIG, INACTIVE_CUS)*/ & mask;
}

static void gfx_v6_0_set_user_cu_inactive_bitmap(struct amdgpu_device *adev, uint32 bitmap)
{
	if (!bitmap)
		return;

	WriteReg4AmdGpu(mmGC_USER_SHADER_ARRAY_CONFIG, GcUserShaderArrayConfig{.inactiveCus = bitmap}.val);
}

// #pragma mark -

static void gfx_v6_0_tiling_mode_table_init(struct amdgpu_device *adev)
{
	const uint32 num_tile_mode_states = B_COUNT_OF(adev->gfx.config.tile_mode_array);
	uint32 reg_offset, split_equal_to_row_size, *tilemode;

	memset(adev->gfx.config.tile_mode_array, 0, sizeof(adev->gfx.config.tile_mode_array));
	tilemode = adev->gfx.config.tile_mode_array;

	switch (adev->gfx.config.mem_row_size_in_kb) {
	case 1:
		split_equal_to_row_size = ADDR_SURF_TILE_SPLIT_1KB;
		break;
	case 2:
	default:
		split_equal_to_row_size = ADDR_SURF_TILE_SPLIT_2KB;
		break;
	case 4:
		split_equal_to_row_size = ADDR_SURF_TILE_SPLIT_4KB;
		break;
	}

	switch (adev->asic_type) {
	case CHIP_VERDE:
		tilemode[0] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_64B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_4,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[1] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_128B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_4,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[2] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_4,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[3] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = split_equal_to_row_size,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_8_BANK
		}.val;
		tilemode[4] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_1D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16
		}.val;
		tilemode[5] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_512B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		tilemode[6] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		tilemode[7] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[8] = GbTileMode {
			.arrayMode = ARRAY_LINEAR_ALIGNED
		}.val;
		tilemode[9] = GbTileMode {
			.microTileMode = ADDR_SURF_DISPLAY_MICRO_TILING,
			.arrayMode = ARRAY_1D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16
		}.val;
		tilemode[10] = GbTileMode {
			.microTileMode = ADDR_SURF_DISPLAY_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_4,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[11] = GbTileMode {
			.microTileMode = ADDR_SURF_DISPLAY_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[12] = GbTileMode {
			.microTileMode = ADDR_SURF_DISPLAY_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_512B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[13] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_1D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16
		}.val;
		tilemode[14] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[15] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[16] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_512B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[17] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = split_equal_to_row_size,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[18] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_1D_TILED_THICK,
			.pipeConfig = ADDR_SURF_P4_8x16
		}.val;
		tilemode[19] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_XTHICK,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = split_equal_to_row_size,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[20] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THICK,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = split_equal_to_row_size,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[21] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_8_BANK
		}.val;
		tilemode[22] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_8_BANK
		}.val;
		tilemode[23] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		tilemode[24] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_512B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		tilemode[25] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[26] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[27] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[28] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[29] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[30] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_2KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		break;
	case CHIP_HAINAN:
		tilemode[0] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_64B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_4,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[1] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_128B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_4,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[2] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_4,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[3] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = split_equal_to_row_size,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_8_BANK
		}.val;
		tilemode[4] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_1D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2
		}.val;
		tilemode[5] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_512B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_8_BANK
		}.val;
		tilemode[6] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_8_BANK
		}.val;
		tilemode[7] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		tilemode[8] = GbTileMode {
			.arrayMode = ARRAY_LINEAR_ALIGNED
		}.val;
		tilemode[9] = GbTileMode {
			.microTileMode = ADDR_SURF_DISPLAY_MICRO_TILING,
			.arrayMode = ARRAY_1D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2
		}.val;
		tilemode[10] = GbTileMode {
			.microTileMode = ADDR_SURF_DISPLAY_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_4,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[11] = GbTileMode {
			.microTileMode = ADDR_SURF_DISPLAY_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[12] = GbTileMode {
			.microTileMode = ADDR_SURF_DISPLAY_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_512B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[13] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_1D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2
		}.val;
		tilemode[14] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[15] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[16] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_512B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[17] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = split_equal_to_row_size,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[18] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_1D_TILED_THICK,
			.pipeConfig = ADDR_SURF_P2
		}.val;
		tilemode[19] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_XTHICK,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = split_equal_to_row_size,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[20] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THICK,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = split_equal_to_row_size,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[21] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_2,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_8_BANK
		}.val;
		tilemode[22] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_2,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_8_BANK
		}.val;
		tilemode[23] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_8_BANK
		}.val;
		tilemode[24] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_512B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_8_BANK
		}.val;
		tilemode[25] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		tilemode[26] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		tilemode[27] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		tilemode[28] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		tilemode[29] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		tilemode[30] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P2,
			.tileSplit = ADDR_SURF_TILE_SPLIT_2KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		break;
	case CHIP_TAHITI:
	case CHIP_PITCAIRN:
		tilemode[0] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_64B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[1] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_128B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[2] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[3] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = split_equal_to_row_size,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		tilemode[4] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_1D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16
		}.val;
		tilemode[5] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_512B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[6] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_8,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[7] = GbTileMode {
			.microTileMode = ADDR_SURF_DEPTH_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[8] = GbTileMode {
			.arrayMode = ARRAY_LINEAR_ALIGNED
		}.val;
		tilemode[9] = GbTileMode {
			.microTileMode = ADDR_SURF_DISPLAY_MICRO_TILING,
			.arrayMode = ARRAY_1D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16
		}.val;
		tilemode[10] = GbTileMode {
			.microTileMode = ADDR_SURF_DISPLAY_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[11] = GbTileMode {
			.microTileMode = ADDR_SURF_DISPLAY_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_2,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[12] = GbTileMode {
			.microTileMode = ADDR_SURF_DISPLAY_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_512B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[13] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_1D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16
		}.val;
		tilemode[14] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[15] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[16] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_512B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[17] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = split_equal_to_row_size,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[18] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_1D_TILED_THICK,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16
		}.val;
		tilemode[19] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_XTHICK,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = split_equal_to_row_size,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[20] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THICK,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = split_equal_to_row_size,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_1,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_16_BANK
		}.val;
		tilemode[21] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_8,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		tilemode[22] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_4_BANK
		}.val;
		tilemode[23] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_256B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_8,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[24] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P8_32x32_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_512B,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[25] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[26] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[27] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[28] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[29] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_1KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_4,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		tilemode[30] = GbTileMode {
			.microTileMode = ADDR_SURF_THIN_MICRO_TILING,
			.arrayMode = ARRAY_2D_TILED_THIN1,
			.pipeConfig = ADDR_SURF_P4_8x16,
			.tileSplit = ADDR_SURF_TILE_SPLIT_2KB,
			.bankWidth = ADDR_SURF_BANK_WIDTH_1,
			.bankHeight = ADDR_SURF_BANK_HEIGHT_2,
			.macroTileAspect = ADDR_SURF_MACRO_ASPECT_1,
			.numBanks = ADDR_SURF_2_BANK
		}.val;
		break;
	default:
		DRM_ERROR("unknown asic: 0x%x\n", adev->asic_type);
		return;
	}

	for (reg_offset = 0; reg_offset < num_tile_mode_states; reg_offset++)
		WriteReg4AmdGpu(mmGB_TILE_MODE0 + reg_offset, tilemode[reg_offset]);
}

static void gfx_v6_0_setup_rb(struct amdgpu_device *adev)
{
	uint32 i, j;
	uint32 data;
	uint32 raster_config = 0;
	uint32 active_rbs = 0;
	uint32 rb_bitmap_width_per_sh = adev->gfx.config.max_backends_per_se /
					adev->gfx.config.max_sh_per_se;
	unsigned num_rb_pipes;

	adev->grbm_idx_mutex.Acquire();
	for (i = 0; i < adev->gfx.config.max_shader_engines; i++) {
		for (j = 0; j < adev->gfx.config.max_sh_per_se; j++) {
			gfx_v6_0_select_se_sh(adev, i, j, 0xffffffff);
			data = gfx_v6_0_get_rb_active_bitmap(adev);
			active_rbs |= data <<
				((i * adev->gfx.config.max_sh_per_se + j) *
				 rb_bitmap_width_per_sh);
		}
	}
	gfx_v6_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);

	adev->gfx.config.backend_enable_mask = active_rbs;
	adev->gfx.config.num_rbs = std::popcount(active_rbs);

	num_rb_pipes = std::min<unsigned>(adev->gfx.config.max_backends_per_se *
			     adev->gfx.config.max_shader_engines, 16);

	gfx_v6_0_raster_config(adev, &raster_config);

	if (!adev->gfx.config.backend_enable_mask ||
	     adev->gfx.config.num_rbs >= num_rb_pipes)
		WriteReg4AmdGpu(mmPA_SC_RASTER_CONFIG, raster_config);
	else
		gfx_v6_0_write_harvested_raster_configs(adev, raster_config,
							adev->gfx.config.backend_enable_mask,
							num_rb_pipes);

	/* cache the values for userspace */
	for (i = 0; i < adev->gfx.config.max_shader_engines; i++) {
		for (j = 0; j < adev->gfx.config.max_sh_per_se; j++) {
			gfx_v6_0_select_se_sh(adev, i, j, 0xffffffff);
			adev->gfx.config.rb_config[i][j].rb_backend_disable =
				ReadReg4AmdGpu(mmCC_RB_BACKEND_DISABLE);
			adev->gfx.config.rb_config[i][j].user_rb_backend_disable =
				ReadReg4AmdGpu(mmGC_USER_RB_BACKEND_DISABLE);
			adev->gfx.config.rb_config[i][j].raster_config =
				ReadReg4AmdGpu(mmPA_SC_RASTER_CONFIG);
		}
	}
	gfx_v6_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
	adev->grbm_idx_mutex.Release();
}

static void gfx_v6_0_setup_spi(struct amdgpu_device *adev)
{
	uint32 i, j, k;
	uint32 data, mask;
	uint32 active_cu = 0;

	adev->grbm_idx_mutex.Acquire();
	for (i = 0; i < adev->gfx.config.max_shader_engines; i++) {
		for (j = 0; j < adev->gfx.config.max_sh_per_se; j++) {
			gfx_v6_0_select_se_sh(adev, i, j, 0xffffffff);
			data = ReadReg4AmdGpu(mmSPI_STATIC_THREAD_MGMT_3);
			active_cu = gfx_v6_0_get_cu_enabled(adev);

			mask = 1;
			for (k = 0; k < 16; k++) {
				mask <<= k;
				if (active_cu & mask) {
					data &= ~mask;
					WriteReg4AmdGpu(mmSPI_STATIC_THREAD_MGMT_3, data);
					break;
				}
			}
		}
	}
	gfx_v6_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
	adev->grbm_idx_mutex.Release();
}

static void gfx_v6_0_get_cu_info(struct amdgpu_device *adev)
{
	uint32 i, j, k, counter, active_cu_number = 0;
	uint32 mask, bitmap, ao_bitmap, ao_cu_mask = 0;
	struct amdgpu_cu_info *cu_info = &adev->gfx.cu_info;
	unsigned disable_masks[4 * 2];
	uint32 ao_cu_num;

	if (adev->flags & AMD_IS_APU)
		ao_cu_num = 2;
	else
		ao_cu_num = adev->gfx.config.max_cu_per_sh;

	memset(cu_info, 0, sizeof(*cu_info));

	amdgpu_gfx_parse_disable_cu(disable_masks, 4, 2);

	adev->grbm_idx_mutex.Acquire();
	for (i = 0; i < adev->gfx.config.max_shader_engines; i++) {
		for (j = 0; j < adev->gfx.config.max_sh_per_se; j++) {
			mask = 1;
			ao_bitmap = 0;
			counter = 0;
			gfx_v6_0_select_se_sh(adev, i, j, 0xffffffff);
			if (i < 4 && j < 2)
				gfx_v6_0_set_user_cu_inactive_bitmap(
					adev, disable_masks[i * 2 + j]);
			bitmap = gfx_v6_0_get_cu_enabled(adev);
			cu_info->bitmap[i][j] = bitmap;

			for (k = 0; k < adev->gfx.config.max_cu_per_sh; k++) {
				if (bitmap & mask) {
					if (counter < ao_cu_num)
						ao_bitmap |= mask;
					counter ++;
				}
				mask <<= 1;
			}
			active_cu_number += counter;
			if (i < 2 && j < 2)
				ao_cu_mask |= (ao_bitmap << (i * 16 + j * 8));
			cu_info->ao_cu_bitmap[i][j] = ao_bitmap;
		}
	}

	gfx_v6_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
	adev->grbm_idx_mutex.Release();

	cu_info->number = active_cu_number;
	cu_info->ao_cu_mask = ao_cu_mask;
}

static void gfx_v6_0_config_init(struct amdgpu_device *adev)
{
	adev->gfx.config.double_offchip_lds_buf = 0;
}

// #pragma mark -

static void gfx_v6_0_constants_init(struct amdgpu_device *adev)
{
	GbAddrConfig gb_addr_config{};
	uint32 mc_arb_ramcfg;
	uint32 sx_debug_1;
	uint32 hdp_host_path_cntl;
	uint32 tmp;

	switch (adev->asic_type) {
	case CHIP_TAHITI:
		adev->gfx.config.max_shader_engines = 2;
		adev->gfx.config.max_tile_pipes = 12;
		adev->gfx.config.max_cu_per_sh = 8;
		adev->gfx.config.max_sh_per_se = 2;
		adev->gfx.config.max_backends_per_se = 4;
		adev->gfx.config.max_texture_channel_caches = 12;
		adev->gfx.config.max_gprs = 256;
		adev->gfx.config.max_gs_threads = 32;
		adev->gfx.config.max_hw_contexts = 8;

		adev->gfx.config.sc_prim_fifo_size_frontend = 0x20;
		adev->gfx.config.sc_prim_fifo_size_backend = 0x100;
		adev->gfx.config.sc_hiz_tile_fifo_size = 0x30;
		adev->gfx.config.sc_earlyz_tile_fifo_size = 0x130;
		gb_addr_config.val = TAHITI_GB_ADDR_CONFIG_GOLDEN;
		break;
	case CHIP_PITCAIRN:
		adev->gfx.config.max_shader_engines = 2;
		adev->gfx.config.max_tile_pipes = 8;
		adev->gfx.config.max_cu_per_sh = 5;
		adev->gfx.config.max_sh_per_se = 2;
		adev->gfx.config.max_backends_per_se = 4;
		adev->gfx.config.max_texture_channel_caches = 8;
		adev->gfx.config.max_gprs = 256;
		adev->gfx.config.max_gs_threads = 32;
		adev->gfx.config.max_hw_contexts = 8;

		adev->gfx.config.sc_prim_fifo_size_frontend = 0x20;
		adev->gfx.config.sc_prim_fifo_size_backend = 0x100;
		adev->gfx.config.sc_hiz_tile_fifo_size = 0x30;
		adev->gfx.config.sc_earlyz_tile_fifo_size = 0x130;
		gb_addr_config.val = TAHITI_GB_ADDR_CONFIG_GOLDEN;
		break;
	case CHIP_VERDE:
		adev->gfx.config.max_shader_engines = 1;
		adev->gfx.config.max_tile_pipes = 4;
		adev->gfx.config.max_cu_per_sh = 5;
		adev->gfx.config.max_sh_per_se = 2;
		adev->gfx.config.max_backends_per_se = 4;
		adev->gfx.config.max_texture_channel_caches = 4;
		adev->gfx.config.max_gprs = 256;
		adev->gfx.config.max_gs_threads = 32;
		adev->gfx.config.max_hw_contexts = 8;

		adev->gfx.config.sc_prim_fifo_size_frontend = 0x20;
		adev->gfx.config.sc_prim_fifo_size_backend = 0x40;
		adev->gfx.config.sc_hiz_tile_fifo_size = 0x30;
		adev->gfx.config.sc_earlyz_tile_fifo_size = 0x130;
		gb_addr_config.val = VERDE_GB_ADDR_CONFIG_GOLDEN;
		break;
	case CHIP_OLAND:
		adev->gfx.config.max_shader_engines = 1;
		adev->gfx.config.max_tile_pipes = 4;
		adev->gfx.config.max_cu_per_sh = 6;
		adev->gfx.config.max_sh_per_se = 1;
		adev->gfx.config.max_backends_per_se = 2;
		adev->gfx.config.max_texture_channel_caches = 4;
		adev->gfx.config.max_gprs = 256;
		adev->gfx.config.max_gs_threads = 16;
		adev->gfx.config.max_hw_contexts = 8;

		adev->gfx.config.sc_prim_fifo_size_frontend = 0x20;
		adev->gfx.config.sc_prim_fifo_size_backend = 0x40;
		adev->gfx.config.sc_hiz_tile_fifo_size = 0x30;
		adev->gfx.config.sc_earlyz_tile_fifo_size = 0x130;
		gb_addr_config.val = VERDE_GB_ADDR_CONFIG_GOLDEN;
		break;
	case CHIP_HAINAN:
		adev->gfx.config.max_shader_engines = 1;
		adev->gfx.config.max_tile_pipes = 4;
		adev->gfx.config.max_cu_per_sh = 5;
		adev->gfx.config.max_sh_per_se = 1;
		adev->gfx.config.max_backends_per_se = 1;
		adev->gfx.config.max_texture_channel_caches = 2;
		adev->gfx.config.max_gprs = 256;
		adev->gfx.config.max_gs_threads = 16;
		adev->gfx.config.max_hw_contexts = 8;

		adev->gfx.config.sc_prim_fifo_size_frontend = 0x20;
		adev->gfx.config.sc_prim_fifo_size_backend = 0x40;
		adev->gfx.config.sc_hiz_tile_fifo_size = 0x30;
		adev->gfx.config.sc_earlyz_tile_fifo_size = 0x130;
		gb_addr_config.val = HAINAN_GB_ADDR_CONFIG_GOLDEN;
		break;
	default:
		BUG();
		break;
	}

	WriteReg4AmdGpu(mmGRBM_CNTL, GrbmCntl{.readTimeout = 0xff}.val);
	WriteReg4AmdGpu(mmSRBM_INT_CNTL, 1);
	WriteReg4AmdGpu(mmSRBM_INT_ACK, 1);

	WriteReg4AmdGpu(mmBIF_FB_EN, BifFbEn{.fbReadEn = 1, .fbWriteEn = 1}.val);

	adev->gfx.config.mc_arb_ramcfg = ReadReg4AmdGpu(mmMC_ARB_RAMCFG);
	mc_arb_ramcfg = adev->gfx.config.mc_arb_ramcfg;

	adev->gfx.config.num_tile_pipes = adev->gfx.config.max_tile_pipes;
	adev->gfx.config.mem_max_burst_length_bytes = 256;
	tmp = McArbRamcfg{.val = mc_arb_ramcfg}.noofcols;
	adev->gfx.config.mem_row_size_in_kb = (4 * (1 << (8 + tmp))) / 1024;
	if (adev->gfx.config.mem_row_size_in_kb > 4)
		adev->gfx.config.mem_row_size_in_kb = 4;
	adev->gfx.config.shader_engine_tile_size = 32;
	adev->gfx.config.num_gpus = 1;
	adev->gfx.config.multi_gpu_tile_size = 64;

	switch (adev->gfx.config.mem_row_size_in_kb) {
	case 1:
	default:
		gb_addr_config.rowSize = 0;
		break;
	case 2:
		gb_addr_config.rowSize = 1;
		break;
	case 4:
		gb_addr_config.rowSize = 2;
		break;
	}
	gb_addr_config.numShaderEngines = 0;
	if (adev->gfx.config.max_shader_engines == 2)
		gb_addr_config.numShaderEngines = 1;
	adev->gfx.config.gb_addr_config = gb_addr_config.val;

	WriteReg4AmdGpu(mmGB_ADDR_CONFIG, gb_addr_config.val);
	WriteReg4AmdGpu(mmDMIF_ADDR_CONFIG, gb_addr_config.val);
	WriteReg4AmdGpu(mmDMIF_ADDR_CALC, gb_addr_config.val);
	WriteReg4AmdGpu(mmHDP_ADDR_CONFIG, gb_addr_config.val);
	WriteReg4AmdGpu(mmDMA_TILING_CONFIG + DMA0_REGISTER_OFFSET, gb_addr_config.val);
	WriteReg4AmdGpu(mmDMA_TILING_CONFIG + DMA1_REGISTER_OFFSET, gb_addr_config.val);

#if 0
	if (adev->has_uvd) {
		WriteReg4AmdGpu(mmUVD_UDEC_ADDR_CONFIG, gb_addr_config);
		WriteReg4AmdGpu(mmUVD_UDEC_DB_ADDR_CONFIG, gb_addr_config);
		WriteReg4AmdGpu(mmUVD_UDEC_DBW_ADDR_CONFIG, gb_addr_config);
	}
#endif
	gfx_v6_0_tiling_mode_table_init(adev);

	gfx_v6_0_setup_rb(adev);

	gfx_v6_0_setup_spi(adev);

	gfx_v6_0_get_cu_info(adev);
	gfx_v6_0_config_init(adev);

	WriteReg4AmdGpu(mmCP_QUEUE_THRESHOLDS, CpQueueThresholds{.roqIb1Start = 0x16, .roqIb2Start = 0x2b}.val);
	WriteReg4AmdGpu(mmCP_MEQ_THRESHOLDS, CpMeqThresholds{.meq1Start = 0x30, .meq2Start = 0x60}.val);

	sx_debug_1 = ReadReg4AmdGpu(mmSX_DEBUG_1);
	WriteReg4AmdGpu(mmSX_DEBUG_1, sx_debug_1);

	WriteReg4AmdGpu(mmSPI_CONFIG_CNTL_1, SpiConfigCntl1{.vtxDoneDelay = 4}.val);

	WriteReg4AmdGpu(mmPA_SC_FIFO_SIZE, PaScFifoSize{
		.scFrontendPrimFifoSize = adev->gfx.config.sc_prim_fifo_size_frontend,
		.scBackendPrimFifoSize = adev->gfx.config.sc_prim_fifo_size_backend,
		.scHizTileFifoSize = adev->gfx.config.sc_hiz_tile_fifo_size,
		.scEarlyzTileFifoSize = adev->gfx.config.sc_earlyz_tile_fifo_size
	}.val);

	WriteReg4AmdGpu(mmVGT_NUM_INSTANCES, 1);
	WriteReg4AmdGpu(mmCP_PERFMON_CNTL, 0);
	WriteReg4AmdGpu(mmSQ_CONFIG, 0);

	WriteReg4AmdGpu(mmPA_SC_FORCE_EOV_MAX_CNTS, PaScForceEovMaxCnts{.forceEovMaxClkCnt = 4095, .forceEovMaxRezCnt = 255}.val);

	WriteReg4AmdGpu(mmVGT_CACHE_INVALIDATION, VgtCacheInvalidation{.cacheInvalidation = VC_AND_TC, .autoInvldEn = ES_AND_GS_AUTO}.val);

	WriteReg4AmdGpu(mmVGT_GS_VERTEX_REUSE, 16);
	WriteReg4AmdGpu(mmPA_SC_LINE_STIPPLE_STATE, 0);

	WriteReg4AmdGpu(mmCB_PERFCOUNTER0_SELECT0, 0);
	WriteReg4AmdGpu(mmCB_PERFCOUNTER0_SELECT1, 0);
	WriteReg4AmdGpu(mmCB_PERFCOUNTER1_SELECT0, 0);
	WriteReg4AmdGpu(mmCB_PERFCOUNTER1_SELECT1, 0);
	WriteReg4AmdGpu(mmCB_PERFCOUNTER2_SELECT0, 0);
	WriteReg4AmdGpu(mmCB_PERFCOUNTER2_SELECT1, 0);
	WriteReg4AmdGpu(mmCB_PERFCOUNTER3_SELECT0, 0);
	WriteReg4AmdGpu(mmCB_PERFCOUNTER3_SELECT1, 0);

	hdp_host_path_cntl = ReadReg4AmdGpu(mmHDP_HOST_PATH_CNTL);
	WriteReg4AmdGpu(mmHDP_HOST_PATH_CNTL, hdp_host_path_cntl);

	WriteReg4AmdGpu(mmPA_CL_ENHANCE, PaClEnhance{.clipVtxReorderEna = 1, .numClipSeq = 3}.val);

	snooze(50);
}


status_t InitGpu(amdgpu_device *dev)
{
	switch (gDevice.SharedInfo()->chipsetID) {
		case RADEON_CAPEVERDE:
			dev->asic_type = CHIP_VERDE;
			break;
		case RADEON_PITCAIRN:
			dev->asic_type = CHIP_PITCAIRN;
			break;
		case RADEON_TAHITI:
			dev->asic_type = CHIP_TAHITI;
			break;
		case RADEON_OLAND:
			dev->asic_type = CHIP_OLAND;
			break;
		case RADEON_HAINAN:
			dev->asic_type = CHIP_HAINAN;
			break;
		default:
			return B_NOT_SUPPORTED;
	}
	gfx_v6_0_constants_init(dev);
	return B_OK;
}
