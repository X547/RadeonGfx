#pragma once

#include <SupportDefs.h>
#include "Locks/Mutex.h"


enum {
	RASTER_CONFIG_PKR_MAP_0 = 0,
	RASTER_CONFIG_PKR_MAP_1 = 1,
	RASTER_CONFIG_PKR_MAP_2 = 2,
	RASTER_CONFIG_PKR_MAP_3 = 3,
};

enum {
	RASTER_CONFIG_SE_MAP_0 = 0,
	RASTER_CONFIG_SE_MAP_1 = 1,
	RASTER_CONFIG_SE_MAP_2 = 2,
	RASTER_CONFIG_SE_MAP_3 = 3,
};

enum ArrayMode {
//	ARRAY_LINEAR_GENERAL                             = 0x0,
//	ARRAY_LINEAR_ALIGNED                             = 0x1,
//	ARRAY_1D_TILED_THIN1                             = 0x2,
	ARRAY_1D_TILED_THICK                             = 0x3,
//	ARRAY_2D_TILED_THIN1                             = 0x4,
	ARRAY_PRT_TILED_THIN1                            = 0x5,
	ARRAY_PRT_2D_TILED_THIN1                         = 0x6,
	ARRAY_2D_TILED_THICK                             = 0x7,
	ARRAY_2D_TILED_XTHICK                            = 0x8,
	ARRAY_PRT_TILED_THICK                            = 0x9,
	ARRAY_PRT_2D_TILED_THICK                         = 0xa,
	ARRAY_PRT_3D_TILED_THIN1                         = 0xb,
	ARRAY_3D_TILED_THIN1                             = 0xc,
	ARRAY_3D_TILED_THICK                             = 0xd,
	ARRAY_3D_TILED_XTHICK                            = 0xe,
	ARRAY_PRT_3D_TILED_THICK                         = 0xf,
};

enum {
	AMD_IS_APU = 1 << 0,
};

enum {
	CHIP_TAHITI,
	CHIP_PITCAIRN,
	CHIP_VERDE,
	CHIP_OLAND,
	CHIP_HAINAN,
};

#define AMDGPU_GFX_MAX_SE 4
#define AMDGPU_GFX_MAX_SH_PER_SE 2

struct amdgpu_rb_config {
	uint32 rb_backend_disable;
	uint32 user_rb_backend_disable;
	uint32 raster_config;
	uint32 raster_config_1;
};

struct gb_addr_config {
	uint16_t pipe_interleave_size;
	uint8_t num_pipes;
	uint8_t max_compress_frags;
	uint8_t num_banks;
	uint8_t num_se;
	uint8_t num_rb_per_se;
	uint8_t num_pkrs;
};

struct amdgpu_gfx_config {
	unsigned max_shader_engines;
	unsigned max_tile_pipes;
	unsigned max_cu_per_sh;
	unsigned max_sh_per_se;
	unsigned max_backends_per_se;
	unsigned max_texture_channel_caches;
	unsigned max_gprs;
	unsigned max_gs_threads;
	unsigned max_hw_contexts;
	unsigned sc_prim_fifo_size_frontend;
	unsigned sc_prim_fifo_size_backend;
	unsigned sc_hiz_tile_fifo_size;
	unsigned sc_earlyz_tile_fifo_size;

	unsigned num_tile_pipes;
	unsigned backend_enable_mask;
	unsigned mem_max_burst_length_bytes;
	unsigned mem_row_size_in_kb;
	unsigned shader_engine_tile_size;
	unsigned num_gpus;
	unsigned multi_gpu_tile_size;
	unsigned mc_arb_ramcfg;
	unsigned num_banks;
	unsigned num_ranks;
	unsigned gb_addr_config;
	unsigned num_rbs;
	unsigned gs_vgt_table_depth;
	unsigned gs_prim_buffer_depth;

	uint32 tile_mode_array[32];
	uint32 macrotile_mode_array[16];

	struct gb_addr_config gb_addr_config_fields;
	struct amdgpu_rb_config rb_config[AMDGPU_GFX_MAX_SE][AMDGPU_GFX_MAX_SH_PER_SE];

	/* gfx configure feature */
	uint32 double_offchip_lds_buf;
	/* cached value of DB_DEBUG2 */
	uint32 db_debug2;
	/* gfx10 specific config */
	uint32 num_sc_per_sh;
	uint32 num_packer_per_sc;
	uint32 pa_sc_tile_steering_override;
	uint64 tcc_disabled_mask;
};

struct amdgpu_cu_info {
	uint32 simd_per_cu;
	uint32 max_waves_per_simd;
	uint32 wave_front_size;
	uint32 max_scratch_slots_per_cu;
	uint32 lds_size;

	/* total active CU number */
	uint32 number;
	uint32 ao_cu_mask;
	uint32 ao_cu_bitmap[4][4];
	uint32 bitmap[4][4];
};

struct amdgpu_device {
	uint32 asic_type;
	uint32 flags;
	uint32 rev_id;
	uint32 external_rev_id;
	Mutex grbm_idx_mutex;
	struct {
		amdgpu_gfx_config config;
		amdgpu_cu_info cu_info;
	} gfx;
};
