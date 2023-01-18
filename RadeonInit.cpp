#include "RadeonInit.h"
#include "Radeon.h"
#include "RadeonData.h"
#include "RadeonFirmware.h"
#include "gfx_6_0.h"
#include "gfx_6_0_d.h"
#include "gmc_6_0.h"
#include "gmc_6_0_d.h"
#include "dce_6_0.h"
#include "dce_6_0_d.h"
#include "oss_1_0.h"
#include "oss_1_0_d.h"
#include "bif_3_0.h"
#include "bif_3_0_d.h"
#include "sid_amdgpu.h"

#include <string.h>
#include <stdio.h>

#define CheckRet(err) {status_t _err = (err); if (_err < B_OK) return _err;}


static void WriteSet(uint32 val)
{
	printf("{");
	bool first = true;
	for (uint32 i = 0; i < 32; i++) {
		if ((1 << i) & val) {
			if (first) first = false; else printf(", ");
			printf("%" B_PRIu32, i);
		}
	}
	printf("}");
}


static bool gmc_v6_0_is_idle()
{
	SrbmStatus status{.val = ReadReg4AmdGpu(mmSRBM_STATUS)};
	return !(
		status.mcbBusy ||
		status.mcbNonDisplayBusy ||
		status.mccBusy ||
		status.mcdBusy ||
		status.vmcBusy
	);
}

static status_t gmc_v6_0_wait_for_idle()
{
	for (uint32 i = 0; i < 1000; i++) {
		if (gmc_v6_0_is_idle()) return B_OK;
		snooze(1000);
	}
	return B_ERROR;
}


static uint32 gfx_v6_0_get_csb_size()
{
	uint32 count = 0;
	const struct cs_section_def *sect = NULL;
	const struct cs_extent_def *ext = NULL;

	if (gDevice.fRlc.csData == NULL)
		return 0;

	/* begin clear state */
	count += 2;
	/* context control state */
	count += 3;

	for (sect = gDevice.fRlc.csData; sect->section != NULL; ++sect) {
		for (ext = sect->section; ext->extent != NULL; ++ext) {
			if (sect->id == SECT_CONTEXT)
				count += 2 + ext->reg_count;
			else
				return 0;
		}
	}
	/* pa_sc_raster_config */
	count += 3;
	/* end clear state */
	count += 2;
	/* clear state */
	count += 2;

	return count;
}

static void si_enable_gui_idle_interrupt(bool enable)
{
	return; // !!!

	CpIntCntlRing0 cpIntCntl {.val = ReadReg4AmdGpu(mmCP_INT_CNTL_RING0)};
	if (enable) {
		cpIntCntl.cntxBusyIntEnable = true;
		cpIntCntl.cntxEmptyIntEnable = true;
		//cpIntCntl.timeStampIntEnable = true;
	} else {
		cpIntCntl.cntxBusyIntEnable = false;
		cpIntCntl.cntxEmptyIntEnable = false;
		//cpIntCntl.timeStampIntEnable = false;
	}
	WriteReg4AmdGpu(mmCP_INT_CNTL_RING0, cpIntCntl.val);

	if (!enable) {
		/* read a gfx register */
		uint32 tmp = ReadReg4AmdGpu(mmDB_DEPTH_INFO);

		uint32 mask = RLC_BUSY_STATUS | GFX_POWER_STATUS | GFX_CLOCK_STATUS | GFX_LS_STATUS;
		for (int i = 0; ; i++) {
			if (!(i < 100000)) {
				printf("[!] si_enable_gui_idle_interrupt: timeout\n");
				uint32 rlcStat = ReadReg4AmdGpu(mmRLC_STAT);
				printf("  RLC_STAT: ");
				WriteSet(rlcStat); printf("\n");
				break;
			}
			if ((ReadReg4AmdGpu(mmRLC_STAT) & mask) == (GFX_CLOCK_STATUS | GFX_POWER_STATUS))
				break;
			snooze(1);
		}
	}
}


// #pragma mark -

static void WriteRegisterList(const uint32 *registers, const uint32 array_size)
{
	uint32 tmp, reg, and_mask, or_mask;

	if (array_size % 3)
		return;

	for (uint32 i = 0; i < array_size; i += 3) {
		reg = registers[i + 0];
		and_mask = registers[i + 1];
		or_mask = registers[i + 2];

		if (and_mask == 0xffffffff) {
			tmp = or_mask;
		} else {
			tmp = ReadReg4AmdGpu(reg);
			tmp &= ~and_mask;
			tmp |= or_mask;
		}
		WriteReg4AmdGpu(reg, tmp);
	}
}

void InitGoldenRegisters()
{
	switch (gDevice.SharedInfo()->chipsetID) {
		case RADEON_TAHITI:
			WriteRegisterList(tahiti_golden_registers, B_COUNT_OF(tahiti_golden_registers));
			WriteRegisterList(tahiti_golden_rlc_registers, B_COUNT_OF(tahiti_golden_rlc_registers));
			WriteRegisterList(tahiti_mgcg_cgcg_init, B_COUNT_OF(tahiti_mgcg_cgcg_init));
			WriteRegisterList(tahiti_golden_registers2, B_COUNT_OF(tahiti_golden_registers2));
			break;
		case RADEON_PITCAIRN:
			WriteRegisterList(pitcairn_golden_registers, B_COUNT_OF(pitcairn_golden_registers));
			WriteRegisterList(pitcairn_golden_rlc_registers, B_COUNT_OF(pitcairn_golden_rlc_registers));
			WriteRegisterList(pitcairn_mgcg_cgcg_init, B_COUNT_OF(pitcairn_mgcg_cgcg_init));
			break;
		case RADEON_CAPEVERDE:
			WriteRegisterList(verde_golden_registers, B_COUNT_OF(verde_golden_registers));
			WriteRegisterList(verde_golden_rlc_registers, B_COUNT_OF(verde_golden_rlc_registers));
			WriteRegisterList(verde_mgcg_cgcg_init, B_COUNT_OF(verde_mgcg_cgcg_init));
			WriteRegisterList(verde_pg_init, B_COUNT_OF(verde_pg_init));
			break;
		case RADEON_OLAND:
			WriteRegisterList(oland_golden_registers, B_COUNT_OF(oland_golden_registers));
			WriteRegisterList(oland_golden_rlc_registers, B_COUNT_OF(oland_golden_rlc_registers));
			WriteRegisterList(oland_mgcg_cgcg_init, B_COUNT_OF(oland_mgcg_cgcg_init));
			break;
		case RADEON_HAINAN:
			WriteRegisterList(hainan_golden_registers, B_COUNT_OF(hainan_golden_registers));
			WriteRegisterList(hainan_golden_registers2, B_COUNT_OF(hainan_golden_registers2));
			WriteRegisterList(hainan_mgcg_cgcg_init, B_COUNT_OF(hainan_mgcg_cgcg_init));
			break;
		default:
			abort();
	}
}


status_t PreinitGfxRings()
{
	WriteReg4AmdGpu(mmCP_SEM_WAIT_TIMER, 0x0);
	WriteReg4AmdGpu(mmCP_SEM_INCOMPLETE_TIMER_CNTL, 0x0);

	/* Set the write pointer delay */
	WriteReg4AmdGpu(mmCP_RB_WPTR_DELAY, 0);

	WriteReg4AmdGpu(mmCP_DEBUG, 0);
	//WriteReg4AmdGpu(mmSCRATCH_ADDR, ((gDevice.fWritebackBuf.buf->gpuPhysAdr + offsetof(ScratchBuffer, fences[0])) >> 8) & 0xFFFFFFFF);
	WriteReg4AmdGpu(mmSCRATCH_ADDR, 0);

	// WriteReg4AmdGpu(mmSCRATCH_UMSK, 0xff);
	WriteReg4AmdGpu(mmSCRATCH_UMSK, 0);

	return B_OK;
}


status_t InitCP()
{
	auto gfxRing = gDevice.Rings(RADEON_RING_TYPE_GFX_INDEX);
	auto cp1Ring = gDevice.Rings(CAYMAN_RING_TYPE_CP1_INDEX);
	auto cp2Ring = gDevice.Rings(CAYMAN_RING_TYPE_CP2_INDEX);

	printf("  (1)\n");
	if (auto ring = gfxRing.Lock()) {
		CheckRet(ring->Begin(7 + 4));

		/* init the CP */
		ring->Write(PACKET3(PACKET3_ME_INITIALIZE, 5));
		ring->Write(0x1);
		ring->Write(0x0);
		ring->Write(8 /* max_hw_contexts */ - 1);
		ring->Write(PACKET3_ME_INITIALIZE_DEVICE_ID(1));
		ring->Write(0);
		ring->Write(0);

		/* init the CE partitions */
		ring->Write(PACKET3(PACKET3_SET_BASE, 2));
		ring->Write(PACKET3_BASE_INDEX(CE_PARTITION_BASE));
		ring->Write(0xc000);
		ring->Write(0xe000);
		ring->End();
	}
	gfxRing.Switch()->WriteState();

	// si_cp_enable(rdev, true);
	WriteReg4AmdGpu(mmCP_ME_CNTL, 0);
	snooze(50);
	gfxRing.Switch()->WriteState();
#if 1
	printf("  (2)\n");
	if (auto ring = gfxRing.Lock()) {
		CheckRet(ring->Begin(gfx_v6_0_get_csb_size() + 10));

		/* setup clear context state */
		ring->Write(PACKET3(PACKET3_PREAMBLE_CNTL, 0));
		ring->Write(PACKET3_PREAMBLE_BEGIN_CLEAR_STATE);

		for (const struct cs_section_def *sect = gDevice.fRlc.csData; sect->section != NULL; ++sect) {
			for (const struct cs_extent_def *ext = sect->section; ext->extent != NULL; ++ext) {
				if (sect->id == SECT_CONTEXT) {
					ring->Write(PACKET3(PACKET3_SET_CONTEXT_REG, ext->reg_count));
					ring->Write(ext->reg_index - PACKET3_SET_CONTEXT_REG_START);
					for (uint32 i = 0; i < ext->reg_count; i++)
						ring->Write(ext->extent[i]);
				}
			}
		}

		ring->Write(PACKET3(PACKET3_PREAMBLE_CNTL, 0));
		ring->Write(PACKET3_PREAMBLE_END_CLEAR_STATE);

		/* set clear context state */
		ring->Write(PACKET3(PACKET3_CLEAR_STATE, 0));
		ring->Write(0);

		ring->Write(PACKET3(PACKET3_SET_CONTEXT_REG, 2));
		ring->Write(0x00000316);
		ring->Write(0x0000000e); /* VGT_VERTEX_REUSE_BLOCK_CNTL */
		ring->Write(0x00000010); /* VGT_OUT_DEALLOC_CNTL */

		ring->End();
		//CheckRet(ring->WaitEmpty());
	}
	gfxRing.Switch()->WriteState();

	printf("  (3)\n");
	ExternalPtr<RadeonRingBuffer> rings[] = {gfxRing, cp1Ring, cp2Ring};
	for (uint32 i = 0; i < B_COUNT_OF(rings); i++) {
		switch (i) {
			case 0: printf("GFX\n"); break;
			case 1: printf("CP1\n"); break;
			case 2: printf("CP2\n"); break;
		}
		if (auto ring = rings[i].Lock()) {
			CheckRet(ring->Begin(2));

			/* clear the compute context state */
			ring->Write(PACKET3_COMPUTE(PACKET3_CLEAR_STATE, 0));
			ring->Write(0);

			ring->End();
			// CheckRet(ring->WaitEmpty());
		}
		rings[i].Switch()->WriteState();
	}
#endif
	return B_OK;
}


status_t StopMC()
{
	gmc_v6_0_wait_for_idle();

	McSharedBlackoutCntl blackout{.val = ReadReg4AmdGpu(mmMC_SHARED_BLACKOUT_CNTL)};
	if (blackout.blackoutMode != 1) {
		/* Block CPU access */
		WriteReg4AmdGpu(mmBIF_FB_EN, 0);
		/* blackout the MC */
		blackout.blackoutMode = 1;
		WriteReg4AmdGpu(mmMC_SHARED_BLACKOUT_CNTL, blackout.val);
	}
	/* wait for the MC to settle */
	snooze(100);

	return B_OK;
}

status_t ResumeMC()
{
	/* unblackout the MC */
	McSharedBlackoutCntl blackout{.val = ReadReg4AmdGpu(mmMC_SHARED_BLACKOUT_CNTL)};
	blackout.blackoutMode = 0;
	WriteReg4AmdGpu(mmMC_SHARED_BLACKOUT_CNTL, blackout.val);
	/* allow CPU access */
	BifFbEn bifFbEn{.val = ReadReg4AmdGpu(mmBIF_FB_EN)};
	bifFbEn.fbReadEn = true;
	bifFbEn.fbWriteEn = true;
	WriteReg4AmdGpu(mmBIF_FB_EN, bifFbEn.val);
	return B_OK;
}

status_t ResetMC()
{
	SrbmStatus status{.val = ReadReg4AmdGpu(mmSRBM_STATUS)};
	SrbmSoftReset softReset{};
	if (status.vmcBusy) {
		softReset.softResetVmc = true;
	}
	if (status.mcbBusy || status.mcbNonDisplayBusy || status.mccBusy || status.mcdBusy) {
		if (true /*!(adev->flags & AMD_IS_APU)*/) {
			softReset.softResetMc = true;
		}
	}
	if (softReset.val != 0) {
		StopMC();
		gmc_v6_0_wait_for_idle();

		uint32 tmp = ReadReg4AmdGpu(mmSRBM_SOFT_RESET);
		tmp |= softReset.val;
		printf("SRBM_SOFT_RESET = %#" B_PRIx32 "\n", tmp);
		WriteReg4AmdGpu(mmSRBM_SOFT_RESET, tmp);

		snooze(50);

		tmp &= ~softReset.val;
		WriteReg4AmdGpu(mmSRBM_SOFT_RESET, tmp);
		tmp = ReadReg4AmdGpu(mmSRBM_SOFT_RESET);

		snooze(50);

		ResumeMC();
		snooze(50);
	}

	return B_OK;
}

#if 0
status_t ResetMC()
{
	SrbmStatus status{.val = ReadReg4AmdGpu(mmSRBM_STATUS)};
	SrbmSoftReset softReset{};
	softReset.softResetVmc = true;
	softReset.softResetMc = true;
	if (softReset.val != 0) {

		uint32 tmp = ReadReg4AmdGpu(mmSRBM_SOFT_RESET);
		tmp |= softReset.val;
		printf("SRBM_SOFT_RESET = %#" B_PRIx32 "\n", tmp);
		WriteReg4AmdGpu(mmSRBM_SOFT_RESET, tmp);

		snooze(50);

		tmp &= ~softReset.val;
		WriteReg4AmdGpu(mmSRBM_SOFT_RESET, tmp);
		tmp = ReadReg4AmdGpu(mmSRBM_SOFT_RESET);

		snooze(50);
	}

	return B_OK;
}
#endif

status_t InitMC()
{
	printf("SRBM_STATUS: "); WriteSet(ReadReg4AmdGpu(mmSRBM_STATUS)); printf("\n");

	/* Initialize HDP */
	for (int i = 0, j = 0; i < 32; i++, j += 0x6) {
		WriteReg4AmdGpu(0xb05 + j, 0x00000000);
		WriteReg4AmdGpu(0xb06 + j, 0x00000000);
		WriteReg4AmdGpu(0xb07 + j, 0x00000000);
		WriteReg4AmdGpu(0xb08 + j, 0x00000000);
		WriteReg4AmdGpu(0xb09 + j, 0x00000000);
	}
	WriteReg4AmdGpu(mmHDP_REG_COHERENCY_FLUSH_CNTL, 0);

	printf("SRBM_STATUS: "); WriteSet(ReadReg4AmdGpu(mmSRBM_STATUS)); printf("\n");
	if (gmc_v6_0_wait_for_idle() < B_OK) {
		printf("[!] Wait for MC idle timedout !\n");
	}
	printf("SRBM_STATUS: "); WriteSet(ReadReg4AmdGpu(mmSRBM_STATUS)); printf("\n");

	if (true /*!(adev->flags & AMD_IS_APU)*/) {
		/* Lockout access through VGA aperture*/
		VgaHdpControl hdpControl{.val = ReadReg4AmdGpu(mmVGA_HDP_CONTROL)};
		hdpControl.vgaMemoryDisable = true;
		WriteReg4AmdGpu(mmVGA_HDP_CONTROL, hdpControl.val);

		/* disable VGA render */
		VgaRenderControl renderControl{.val = ReadReg4AmdGpu(mmVGA_RENDER_CONTROL)};
		renderControl.vgaVstatusCntl = 0;
		WriteReg4AmdGpu(mmVGA_RENDER_CONTROL, renderControl.val);
	}
	/* Update configuration */
	WriteReg4AmdGpu(mmMC_VM_SYSTEM_APERTURE_LOW_ADDR, gDevice.MemMgr().Switch()->fVramRange.beg / B_PAGE_SIZE);
	WriteReg4AmdGpu(mmMC_VM_SYSTEM_APERTURE_HIGH_ADDR, (gDevice.MemMgr().Switch()->fVramRange.beg + gDevice.MemMgr().Switch()->fVramRange.size - 1) / B_PAGE_SIZE);
	WriteReg4AmdGpu(mmMC_VM_SYSTEM_APERTURE_DEFAULT_ADDR, gDevice.MemMgr().Switch()->fVramScratch->gpuPhysAdr / B_PAGE_SIZE);
	WriteReg4AmdGpu(mmMC_VM_AGP_BASE, 0);
	WriteReg4AmdGpu(mmMC_VM_AGP_TOP, 0x0FFFFFFF);
	WriteReg4AmdGpu(mmMC_VM_AGP_BOT, 0x0FFFFFFF);

	if (gmc_v6_0_wait_for_idle() < B_OK) {
		printf("[!] Wait for MC idle timedout !\n");
	}

	return B_OK;
}


static void gfx_v6_0_get_csb_buffer(vuint32 *buffer)
{
	uint32 count = 0, i;
	const struct cs_section_def *sect = NULL;
	const struct cs_extent_def *ext = NULL;

	if (gDevice.fRlc.csData == NULL)
		return;
	if (buffer == NULL)
		return;

	buffer[count++] = B_HOST_TO_LENDIAN_INT32(PACKET3(PACKET3_PREAMBLE_CNTL, 0));
	buffer[count++] = B_HOST_TO_LENDIAN_INT32(PACKET3_PREAMBLE_BEGIN_CLEAR_STATE);
	buffer[count++] = B_HOST_TO_LENDIAN_INT32(PACKET3(PACKET3_CONTEXT_CONTROL, 1));
	buffer[count++] = B_HOST_TO_LENDIAN_INT32(0x80000000);
	buffer[count++] = B_HOST_TO_LENDIAN_INT32(0x80000000);

	for (sect = gDevice.fRlc.csData; sect->section != NULL; ++sect) {
		for (ext = sect->section; ext->extent != NULL; ++ext) {
			if (sect->id == SECT_CONTEXT) {
				buffer[count++] =
					B_HOST_TO_LENDIAN_INT32(PACKET3(PACKET3_SET_CONTEXT_REG, ext->reg_count));
				buffer[count++] = B_HOST_TO_LENDIAN_INT32(ext->reg_index - PACKET3_SET_CONTEXT_REG_START);
				for (i = 0; i < ext->reg_count; i++)
					buffer[count++] = B_HOST_TO_LENDIAN_INT32(ext->extent[i]);
			} else {
				return;
			}
		}
	}

	buffer[count++] = B_HOST_TO_LENDIAN_INT32(PACKET3(PACKET3_SET_CONTEXT_REG, 1));
	buffer[count++] = B_HOST_TO_LENDIAN_INT32(PA_SC_RASTER_CONFIG - PACKET3_SET_CONTEXT_REG_START);
	buffer[count++] = B_HOST_TO_LENDIAN_INT32(gDevice.fInfo.gfx.config.rb_config[0][0].raster_config);

	buffer[count++] = B_HOST_TO_LENDIAN_INT32(PACKET3(PACKET3_PREAMBLE_CNTL, 0));
	buffer[count++] = B_HOST_TO_LENDIAN_INT32(PACKET3_PREAMBLE_END_CLEAR_STATE);

	buffer[count++] = B_HOST_TO_LENDIAN_INT32(PACKET3(PACKET3_CLEAR_STATE, 0));
	buffer[count++] = B_HOST_TO_LENDIAN_INT32(0);
}

static void si_wait_for_rlc_serdes()
{
	int i;

	for (i = 0; i < 1000000; i++) {
		if (ReadReg4AmdGpu(mmRLC_SERDES_MASTER_BUSY_0) == 0)
			break;
		snooze(1);
	}

	for (i = 0; i < 1000000; i++) {
		if (ReadReg4AmdGpu(mmRLC_SERDES_MASTER_BUSY_1) == 0)
			break;
		snooze(1);
	}
}


static void RlcStart()
{
	WriteReg4AmdGpu(mmRLC_CNTL, RLC_ENABLE);
	si_enable_gui_idle_interrupt(true);
	snooze(50);
}

static void RlcStop()
{
	WriteReg4AmdGpu(mmRLC_CNTL, 0);
	si_enable_gui_idle_interrupt(false);
	si_wait_for_rlc_serdes();
}

static void RlcReset()
{
	WriteReg4AmdGpu(mmGRBM_SOFT_RESET, ReadReg4AmdGpu(mmGRBM_SOFT_RESET) | (uint32)SOFT_RESET_RLC);
	snooze(50);
	WriteReg4AmdGpu(mmGRBM_SOFT_RESET, ReadReg4AmdGpu(mmGRBM_SOFT_RESET) & ~(uint32)SOFT_RESET_RLC);
	snooze(50);
}

static void si_enable_lbpw(bool enable)
{
	uint32 tmp = ReadReg4AmdGpu(mmRLC_LB_CNTL);
	if (enable)
		tmp |= LOAD_BALANCE_ENABLE;
	else
		tmp &= ~LOAD_BALANCE_ENABLE;
	WriteReg4AmdGpu(mmRLC_LB_CNTL, tmp);
/*
	if (!enable) {
		si_select_se_sh(0xffffffff, 0xffffffff);
		WriteReg4AmdGpu(mmSPI_LB_CU_MASK, 0x00ff);
	}
*/
}

static void RlcResume()
{
	RlcStop();
	RlcReset();

	// gfx_v6_0_init_pg
	WriteReg4AmdGpu(mmRLC_SAVE_AND_RESTORE_BASE, gDevice.fRlc.saveRestoreBuf.buf->gpuPhysAdr >> 8);
	WriteReg4AmdGpu(mmRLC_CLEAR_STATE_RESTORE_BASE, gDevice.fRlc.clearStateBuf.buf->gpuPhysAdr >> 8);

	WriteReg4AmdGpu(mmRLC_RL_BASE, 0);
	WriteReg4AmdGpu(mmRLC_RL_SIZE, 0);
	WriteReg4AmdGpu(mmRLC_LB_CNTL, 0);
	WriteReg4AmdGpu(mmRLC_LB_CNTR_MAX, 0xffffffff);
	WriteReg4AmdGpu(mmRLC_LB_CNTR_INIT, 0);
	WriteReg4AmdGpu(mmRLC_LB_INIT_CU_MASK, 0xffffffff);

	LoadRlcFirmware();
	si_enable_lbpw(true);
	RlcStart();
}

status_t InitRlc()
{
	auto &rlc = gDevice.fRlc;

	rlc.regList = verde_rlc_save_restore_register_list;
	rlc.regListLen = B_COUNT_OF(verde_rlc_save_restore_register_list);
	rlc.csData = si_cs_data;
	rlc.saveRestoreBuf.SetTo(gDevice.MemMgr().Switch()->Alloc(boDomainVramMappable, rlc.regListLen*sizeof(uint32)));
	memcpy(rlc.saveRestoreBuf.adr, rlc.regList, rlc.regListLen*sizeof(uint32));

	rlc.clearStateSize = gfx_v6_0_get_csb_size();
	rlc.clearStateBuf.SetTo(gDevice.MemMgr().Switch()->Alloc(boDomainVramMappable, rlc.clearStateSize*sizeof(uint32) + 256));

	auto clearStateHeader = (vuint32*)rlc.clearStateBuf.adr;
	auto clearStateData = (vuint32*)((uint8*)rlc.clearStateBuf.adr + 256);
	uint64 clearStateDataGpuAdr = rlc.clearStateBuf.buf->gpuPhysAdr + 256;
	clearStateHeader[0] = (uint32)(clearStateDataGpuAdr >> 32);
	clearStateHeader[1] = (uint32)(clearStateDataGpuAdr);
	clearStateHeader[2] = rlc.clearStateSize;
	gfx_v6_0_get_csb_buffer(clearStateData);

	RlcResume();

	return B_OK;
}
