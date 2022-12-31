#pragma once
#include <SupportDefs.h>

// BACO_CNTL
union BacoCntl {
	struct {
		uint32 bacoEn: 1; // 0
		uint32 bacoBclkOff: 1; // 1
		uint32 bacoIsoDis: 1; // 2
		uint32 bacoPowerOff: 1; // 3
		uint32 bacoResetEn: 1; // 4
		uint32 bacoHangProtectionEn: 1; // 5
		uint32 bacoMode: 1; // 6
		uint32 bacoAnaIsoDis: 1; // 7
		uint32 rcuBifConfigDone: 1; // 8
		uint32 pwrgoodBf: 1; // 9
		uint32 pwrgoodGpio: 1; // 10
		uint32 pwrgoodMem: 1; // 11
		uint32 pwrgoodDvo: 1; // 12
		uint32 unknown1: 19;
	};
	uint32 val;
};

// BF_ANA_ISO_CNTL
union BfAnaIsoCntl {
	struct {
		uint32 bfAnaIsoDisMask: 1; // 0
		uint32 bfVddcIsoDisMask: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// BIF_BACO_DEBUG
union BifBacoDebug {
	struct {
		uint32 bifBacoScandumpFlg: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// BIF_BACO_DEBUG_LATCH
union BifBacoDebugLatch {
	struct {
		uint32 bifBacoLatchFlg: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// BIF_BACO_MSIC
union BifBacoMsic {
	struct {
		uint32 bifXtalinSel: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// BIF_BUSNUM_CNTL1
union BifBusnumCntl1 {
	struct {
		uint32 idMask: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// BIF_BUSNUM_CNTL2
union BifBusnumCntl2 {
	struct {
		uint32 autoupdateSel: 8; // 0
		uint32 autoupdateEn: 1; // 8
		uint32 unknown1: 7;
		uint32 hdpregCntl: 1; // 16
		uint32 errorMultipleIdMatch: 1; // 17
		uint32 unknown2: 14;
	};
	uint32 val;
};

// BIF_BUSNUM_LIST0
union BifBusnumList0 {
	struct {
		uint32 id0: 8; // 0
		uint32 id1: 8; // 8
		uint32 id2: 8; // 16
		uint32 id3: 8; // 24
	};
	uint32 val;
};

// BIF_BUSNUM_LIST1
union BifBusnumList1 {
	struct {
		uint32 id4: 8; // 0
		uint32 id5: 8; // 8
		uint32 id6: 8; // 16
		uint32 id7: 8; // 24
	};
	uint32 val;
};

// BIF_BUSY_DELAY_CNTR
union BifBusyDelayCntr {
	struct {
		uint32 delayCnt: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// BIF_CLK_PDWN_DELAY_TIMER
union BifClkPdwnDelayTimer {
	struct {
		uint32 timer: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// BIF_DEBUG_CNTL
union BifDebugCntl {
	struct {
		uint32 debugEn: 1; // 0
		uint32 debugMultiblocken: 1; // 1
		uint32 debugOutEn: 1; // 2
		uint32 debugPadSel: 1; // 3
		uint32 debugByteselBlk1: 1; // 4
		uint32 debugByteselBlk2: 1; // 5
		uint32 debugSyncEn: 1; // 6
		uint32 debugSwap: 1; // 7
		uint32 debugIdselBlk1: 5; // 8
		uint32 unknown1: 3;
		uint32 debugIdselBlk2: 5; // 16
		uint32 unknown2: 3;
		uint32 debugIdselXsp: 1; // 24
		uint32 unknown3: 5;
		uint32 debugSyncClksel: 2; // 30
	};
	uint32 val;
};

// BIF_DEBUG_MUX
union BifDebugMux {
	struct {
		uint32 debugMuxBlk1: 6; // 0
		uint32 unknown1: 2;
		uint32 debugMuxBlk2: 6; // 8
		uint32 unknown2: 18;
	};
	uint32 val;
};

// BIF_DEBUG_OUT
union BifDebugOut {
	struct {
		uint32 debugOutput: 17; // 0
		uint32 unknown1: 15;
	};
	uint32 val;
};

// BIF_DEVFUNCNUM_LIST0
union BifDevfuncnumList0 {
	struct {
		uint32 devfuncId0: 8; // 0
		uint32 devfuncId1: 8; // 8
		uint32 devfuncId2: 8; // 16
		uint32 devfuncId3: 8; // 24
	};
	uint32 val;
};

// BIF_DEVFUNCNUM_LIST1
union BifDevfuncnumList1 {
	struct {
		uint32 devfuncId4: 8; // 0
		uint32 devfuncId5: 8; // 8
		uint32 devfuncId6: 8; // 16
		uint32 devfuncId7: 8; // 24
	};
	uint32 val;
};

// BIF_FB_EN
union BifFbEn {
	struct {
		uint32 fbReadEn: 1; // 0
		uint32 fbWriteEn: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// BIF_FEATURES_CONTROL_MISC
union BifFeaturesControlMisc {
	struct {
		uint32 mstBifReqEpDis: 1; // 0
		uint32 slvBifCplEpDis: 1; // 1
		uint32 bifSlvReqEpDis: 1; // 2
		uint32 bifMstCplEpDis: 1; // 3
		uint32 urPsnPktReportPoisonDis: 1; // 4
		uint32 postPsnOnlyPktReportUrAllDis: 1; // 5
		uint32 postPsnOnlyPktReportUrPartDis: 1; // 6
		uint32 pllSwitchImpctlCalDoneDis: 1; // 7
		uint32 ignoreBeCheckGasketCombDis: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// BIF_PERFCOUNTER0_RESULT
union BifPerfcounter0Result {
	struct {
		uint32 perfcounterResult: 32; // 0
	};
	uint32 val;
};

// BIF_PERFCOUNTER1_RESULT
union BifPerfcounter1Result {
	struct {
		uint32 perfcounterResult: 32; // 0
	};
	uint32 val;
};

// BIF_PERFMON_CNTL
union BifPerfmonCntl {
	struct {
		uint32 perfcounterEn: 1; // 0
		uint32 perfcounterReset0: 1; // 1
		uint32 perfcounterReset1: 1; // 2
		uint32 unknown1: 5;
		uint32 perfSel0: 5; // 8
		uint32 perfSel1: 5; // 13
		uint32 unknown2: 14;
	};
	uint32 val;
};

// BIF_PIF_TXCLK_SWITCH_TIMER
union BifPifTxclkSwitchTimer {
	struct {
		uint32 pll0AckTimer: 3; // 0
		uint32 pll1AckTimer: 3; // 3
		uint32 pllSwitchTimer: 4; // 6
		uint32 unknown1: 22;
	};
	uint32 val;
};

// BIF_RESET_EN
union BifResetEn {
	struct {
		uint32 unknown1: 1;
		uint32 softRstMode: 1; // 1
		uint32 phyResetEn: 1; // 2
		uint32 corResetEn: 1; // 3
		uint32 regResetEn: 1; // 4
		uint32 styResetEn: 1; // 5
		uint32 cfgResetEn: 1; // 6
		uint32 drvResetEn: 1; // 7
		uint32 resetCfgregOnlyEn: 1; // 8
		uint32 hotResetEn: 1; // 9
		uint32 linkDisableResetEn: 1; // 10
		uint32 linkDownResetEn: 1; // 11
		uint32 cfgResetPulseWidth: 6; // 12
		uint32 drvResetDelaySel: 2; // 18
		uint32 pifRstbEn: 1; // 20
		uint32 pifStrapAllvalidEn: 1; // 21
		uint32 bifCorResetEn: 1; // 22
		uint32 func0FlrEn: 1; // 23
		uint32 func1FlrEn: 1; // 24
		uint32 func2FlrEn: 1; // 25
		uint32 func0ResetDelaySel: 2; // 26
		uint32 func1ResetDelaySel: 2; // 28
		uint32 func2ResetDelaySel: 2; // 30
	};
	uint32 val;
};

// BIF_SCRATCH0
union BifScratch0 {
	struct {
		uint32 bifScratch0: 32; // 0
	};
	uint32 val;
};

// BIF_SCRATCH1
union BifScratch1 {
	struct {
		uint32 bifScratch1: 32; // 0
	};
	uint32 val;
};

// BIF_SSA_DISP_LOWER
union BifSsaDispLower {
	struct {
		uint32 unknown1: 2;
		uint32 ssaDispLower: 16; // 2
		uint32 unknown2: 12;
		uint32 ssaDispRegCmpEn: 1; // 30
		uint32 ssaDispRegStallEn: 1; // 31
	};
	uint32 val;
};

// BIF_SSA_DISP_UPPER
union BifSsaDispUpper {
	struct {
		uint32 unknown1: 2;
		uint32 ssaDispUpper: 16; // 2
		uint32 unknown2: 14;
	};
	uint32 val;
};

// BIF_SSA_GFX0_LOWER
union BifSsaGfx0Lower {
	struct {
		uint32 unknown1: 2;
		uint32 ssaGfx0Lower: 16; // 2
		uint32 unknown2: 12;
		uint32 ssaGfx0RegCmpEn: 1; // 30
		uint32 ssaGfx0RegStallEn: 1; // 31
	};
	uint32 val;
};

// BIF_SSA_GFX0_UPPER
union BifSsaGfx0Upper {
	struct {
		uint32 unknown1: 2;
		uint32 ssaGfx0Upper: 16; // 2
		uint32 unknown2: 14;
	};
	uint32 val;
};

// BIF_SSA_GFX1_LOWER
union BifSsaGfx1Lower {
	struct {
		uint32 unknown1: 2;
		uint32 ssaGfx1Lower: 16; // 2
		uint32 unknown2: 12;
		uint32 ssaGfx1RegCmpEn: 1; // 30
		uint32 ssaGfx1RegStallEn: 1; // 31
	};
	uint32 val;
};

// BIF_SSA_GFX1_UPPER
union BifSsaGfx1Upper {
	struct {
		uint32 unknown1: 2;
		uint32 ssaGfx1Upper: 16; // 2
		uint32 unknown2: 14;
	};
	uint32 val;
};

// BIF_SSA_GFX2_LOWER
union BifSsaGfx2Lower {
	struct {
		uint32 unknown1: 2;
		uint32 ssaGfx2Lower: 16; // 2
		uint32 unknown2: 12;
		uint32 ssaGfx2RegCmpEn: 1; // 30
		uint32 ssaGfx2RegStallEn: 1; // 31
	};
	uint32 val;
};

// BIF_SSA_GFX2_UPPER
union BifSsaGfx2Upper {
	struct {
		uint32 unknown1: 2;
		uint32 ssaGfx2Upper: 16; // 2
		uint32 unknown2: 14;
	};
	uint32 val;
};

// BIF_SSA_GFX3_LOWER
union BifSsaGfx3Lower {
	struct {
		uint32 unknown1: 2;
		uint32 ssaGfx3Lower: 16; // 2
		uint32 unknown2: 12;
		uint32 ssaGfx3RegCmpEn: 1; // 30
		uint32 ssaGfx3RegStallEn: 1; // 31
	};
	uint32 val;
};

// BIF_SSA_GFX3_UPPER
union BifSsaGfx3Upper {
	struct {
		uint32 unknown1: 2;
		uint32 ssaGfx3Upper: 16; // 2
		uint32 unknown2: 14;
	};
	uint32 val;
};

// BIF_SSA_MC_LOWER
union BifSsaMcLower {
	struct {
		uint32 unknown1: 2;
		uint32 ssaMcLower: 16; // 2
		uint32 unknown2: 11;
		uint32 ssaMcFbStallEn: 1; // 29
		uint32 ssaMcRegCmpEn: 1; // 30
		uint32 ssaMcRegStallEn: 1; // 31
	};
	uint32 val;
};

// BIF_SSA_MC_UPPER
union BifSsaMcUpper {
	struct {
		uint32 unknown1: 2;
		uint32 ssaMcUpper: 16; // 2
		uint32 unknown2: 14;
	};
	uint32 val;
};

// BIF_SSA_PWR_STATUS
union BifSsaPwrStatus {
	struct {
		uint32 ssaGfxPwrStatus: 1; // 0
		uint32 ssaDispPwrStatus: 1; // 1
		uint32 ssaMcPwrStatus: 1; // 2
		uint32 unknown1: 29;
	};
	uint32 val;
};

// BIF_XDMA_HI
union BifXdmaHi {
	struct {
		uint32 bifXdmaUpperBound: 29; // 0
		uint32 unknown1: 3;
	};
	uint32 val;
};

// BIF_XDMA_LO
union BifXdmaLo {
	struct {
		uint32 bifXdmaLowerBound: 29; // 0
		uint32 unknown1: 2;
		uint32 bifXdmaAperEn: 1; // 31
	};
	uint32 val;
};

// BIOS_SCRATCH_0
union BiosScratch0 {
	struct {
		uint32 biosScratch0: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_1
union BiosScratch1 {
	struct {
		uint32 biosScratch1: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_10
union BiosScratch10 {
	struct {
		uint32 biosScratch10: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_11
union BiosScratch11 {
	struct {
		uint32 biosScratch11: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_12
union BiosScratch12 {
	struct {
		uint32 biosScratch12: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_13
union BiosScratch13 {
	struct {
		uint32 biosScratch13: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_14
union BiosScratch14 {
	struct {
		uint32 biosScratch14: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_15
union BiosScratch15 {
	struct {
		uint32 biosScratch15: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_2
union BiosScratch2 {
	struct {
		uint32 biosScratch2: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_3
union BiosScratch3 {
	struct {
		uint32 biosScratch3: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_4
union BiosScratch4 {
	struct {
		uint32 biosScratch4: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_5
union BiosScratch5 {
	struct {
		uint32 biosScratch5: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_6
union BiosScratch6 {
	struct {
		uint32 biosScratch6: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_7
union BiosScratch7 {
	struct {
		uint32 biosScratch7: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_8
union BiosScratch8 {
	struct {
		uint32 biosScratch8: 32; // 0
	};
	uint32 val;
};

// BIOS_SCRATCH_9
union BiosScratch9 {
	struct {
		uint32 biosScratch9: 32; // 0
	};
	uint32 val;
};

// BUS_CNTL
union BusCntl {
	struct {
		uint32 biosRomWrtEn: 1; // 0
		uint32 biosRomDis: 1; // 1
		uint32 pmiIoDis: 1; // 2
		uint32 pmiMemDis: 1; // 3
		uint32 pmiBmDis: 1; // 4
		uint32 pmiIntDis: 1; // 5
		uint32 vgaRegCoherencyDis: 1; // 6
		uint32 vgaMemCoherencyDis: 1; // 7
		uint32 bifErrRtrBkpressureEn: 1; // 8
		uint32 unknown1: 1;
		uint32 setAzTc: 3; // 10
		uint32 setMcTc: 3; // 13
		uint32 zeroBeWrEn: 1; // 16
		uint32 zeroBeRdEn: 1; // 17
		uint32 rdStallIoWr: 1; // 18
		uint32 unknown2: 13;
	};
	uint32 val;
};

// CAPTURE_HOST_BUSNUM
union CaptureHostBusnum {
	struct {
		uint32 checkEn: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CLKREQB_PAD_CNTL
union ClkreqbPadCntl {
	struct {
		uint32 clkreqbPadA: 1; // 0
		uint32 clkreqbPadSel: 1; // 1
		uint32 clkreqbPadMode: 1; // 2
		uint32 clkreqbPadSpare: 2; // 3
		uint32 clkreqbPadSn0: 1; // 5
		uint32 clkreqbPadSn1: 1; // 6
		uint32 clkreqbPadSn2: 1; // 7
		uint32 clkreqbPadSn3: 1; // 8
		uint32 clkreqbPadSlewn: 1; // 9
		uint32 clkreqbPadWake: 1; // 10
		uint32 clkreqbPadSchmen: 1; // 11
		uint32 clkreqbPadCntlEn: 1; // 12
		uint32 unknown1: 19;
	};
	uint32 val;
};

// CONFIG_APER_SIZE
union ConfigAperSize {
	struct {
		uint32 aperSize: 32; // 0
	};
	uint32 val;
};

// CONFIG_CNTL
union ConfigCntl {
	struct {
		uint32 cfgVgaRamEn: 1; // 0
		uint32 vgaDis: 1; // 1
		uint32 genmoMonoAddressB: 1; // 2
		uint32 grphAdrsel: 2; // 3
		uint32 unknown1: 27;
	};
	uint32 val;
};

// CONFIG_F0_BASE
union ConfigF0Base {
	struct {
		uint32 f0Base: 32; // 0
	};
	uint32 val;
};

// CONFIG_MEMSIZE
union ConfigMemsize {
	struct {
		uint32 configMemsize: 32; // 0
	};
	uint32 val;
};

// CONFIG_REG_APER_SIZE
union ConfigRegAperSize {
	struct {
		uint32 regAperSize: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// HDP_MEM_COHERENCY_FLUSH_CNTL
union HdpMemCoherencyFlushCntl {
	struct {
		uint32 hdpMemFlushAddr: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// HDP_REG_COHERENCY_FLUSH_CNTL
union HdpRegCoherencyFlushCntl {
	struct {
		uint32 hdpRegFlushAddr: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// HOST_BUSNUM
union HostBusnum {
	struct {
		uint32 hostId: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// HW_DEBUG
union HwDebug {
	struct {
		uint32 hw00Debug: 1; // 0
		uint32 hw01Debug: 1; // 1
		uint32 hw02Debug: 1; // 2
		uint32 hw03Debug: 1; // 3
		uint32 hw04Debug: 1; // 4
		uint32 hw05Debug: 1; // 5
		uint32 hw06Debug: 1; // 6
		uint32 hw07Debug: 1; // 7
		uint32 hw08Debug: 1; // 8
		uint32 hw09Debug: 1; // 9
		uint32 hw10Debug: 1; // 10
		uint32 hw11Debug: 1; // 11
		uint32 hw12Debug: 1; // 12
		uint32 hw13Debug: 1; // 13
		uint32 hw14Debug: 1; // 14
		uint32 hw15Debug: 1; // 15
		uint32 hw16Debug: 1; // 16
		uint32 hw17Debug: 1; // 17
		uint32 hw18Debug: 1; // 18
		uint32 hw19Debug: 1; // 19
		uint32 hw20Debug: 1; // 20
		uint32 hw21Debug: 1; // 21
		uint32 hw22Debug: 1; // 22
		uint32 hw23Debug: 1; // 23
		uint32 hw24Debug: 1; // 24
		uint32 hw25Debug: 1; // 25
		uint32 hw26Debug: 1; // 26
		uint32 hw27Debug: 1; // 27
		uint32 hw28Debug: 1; // 28
		uint32 hw29Debug: 1; // 29
		uint32 hw30Debug: 1; // 30
		uint32 hw31Debug: 1; // 31
	};
	uint32 val;
};

// IMPCTL_RESET
union ImpctlReset {
	struct {
		uint32 impSwReset: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// INTERRUPT_CNTL
union InterruptCntl {
	struct {
		uint32 ihDummyRdOverride: 1; // 0
		uint32 ihDummyRdEn: 1; // 1
		uint32 unknown1: 1;
		uint32 ihReqNonsnoopEn: 1; // 3
		uint32 ihIntrDlyCntr: 4; // 4
		uint32 genIhIntEn: 1; // 8
		uint32 genGpioIntEn: 4; // 9
		uint32 selectIntGpioOutput: 2; // 13
		uint32 unknown2: 17;
	};
	uint32 val;
};

// INTERRUPT_CNTL2
union InterruptCntl2 {
	struct {
		uint32 ihDummyRdAddr: 32; // 0
	};
	uint32 val;
};

// MASTER_CREDIT_CNTL
union MasterCreditCntl {
	struct {
		uint32 bifMcRdretCredit: 6; // 0
		uint32 unknown1: 10;
		uint32 bifAzRdretCredit: 6; // 16
		uint32 unknown2: 10;
	};
	uint32 val;
};

// MM_CFGREGS_CNTL
union MmCfgregsCntl {
	struct {
		uint32 mmCfgFuncSel: 3; // 0
		uint32 mmWrToCfgEn: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// MM_DATA
union MmData {
	struct {
		uint32 mmData: 32; // 0
	};
	uint32 val;
};

// MM_INDEX
union MmIndex {
	struct {
		uint32 mmOffset: 31; // 0
		uint32 mmAper: 1; // 31
	};
	uint32 val;
};

// MM_INDEX_HI
union MmIndexHi {
	struct {
		uint32 mmOffsetHi: 32; // 0
	};
	uint32 val;
};

// NEW_REFCLKB_TIMER
union NewRefclkbTimer {
	struct {
		uint32 regStopRefclkEn: 1; // 0
		uint32 stopRefclkTimer: 20; // 1
		uint32 refclkOn: 1; // 21
		uint32 unknown1: 10;
	};
	uint32 val;
};

// NEW_REFCLKB_TIMER_1
union NewRefclkbTimer1 {
	struct {
		uint32 phyPllPdwnTimer: 10; // 0
		uint32 pll0PdnbEn: 1; // 10
		uint32 unknown1: 21;
	};
	uint32 val;
};

// PB0_DFT_DEBUG_CTRL_REG0
union Pb0DftDebugCtrlReg0 {
	struct {
		uint32 dftPhyDebugEn: 1; // 0
		uint32 dftPhyDebugMode: 5; // 1
		uint32 unknown1: 26;
	};
	uint32 val;
};

// PB0_DFT_JIT_INJ_REG0
union Pb0DftJitInjReg0 {
	struct {
		uint32 dftNumSteps: 5; // 0
		uint32 unknown1: 3;
		uint32 dftClkPerStep: 4; // 8
		uint32 unknown2: 10;
		uint32 dftIncrSwpEn: 1; // 22
		uint32 dftDecrSwpEn: 1; // 23
		uint32 dftRecoveryTime: 8; // 24
	};
	uint32 val;
};

// PB0_DFT_JIT_INJ_REG1
union Pb0DftJitInjReg1 {
	struct {
		uint32 dftBypassValue: 8; // 0
		uint32 dftBypassEn: 1; // 8
		uint32 unknown1: 7;
		uint32 dftBlockEn: 1; // 16
		uint32 unknown2: 15;
	};
	uint32 val;
};

// PB0_DFT_JIT_INJ_REG2
union Pb0DftJitInjReg2 {
	struct {
		uint32 dftLaneEn: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_GLB_CTRL_REG0
union Pb0GlbCtrlReg0 {
	struct {
		uint32 backup: 16; // 0
		uint32 cfgIdledetTh: 2; // 16
		uint32 unknown1: 2;
		uint32 dbgRx2txbypSel: 3; // 20
		uint32 dbgRxfebypEn: 1; // 23
		uint32 dbgRxprbsClr: 1; // 24
		uint32 dbgRxtoggleEn: 1; // 25
		uint32 dbgTx2rxlbackEn: 1; // 26
		uint32 unknown2: 3;
		uint32 txcfgCmgoodRange: 2; // 30
	};
	uint32 val;
};

// PB0_GLB_CTRL_REG1
union Pb0GlbCtrlReg1 {
	struct {
		uint32 rxdbgCdrFrBypEn: 1; // 0
		uint32 rxdbgCdrFrBypVal: 6; // 1
		uint32 rxdbgCdrPhBypEn: 1; // 7
		uint32 rxdbgCdrPhBypVal: 6; // 8
		uint32 rxdbgD0thBypEn: 1; // 14
		uint32 rxdbgD0thBypVal: 7; // 15
		uint32 rxdbgD1thBypEn: 1; // 22
		uint32 rxdbgD1thBypVal: 7; // 23
		uint32 tstLospdtstEn: 1; // 30
		uint32 pllCfgDispclkDiv: 1; // 31
	};
	uint32 val;
};

// PB0_GLB_CTRL_REG2
union Pb0GlbCtrlReg2 {
	struct {
		uint32 rxdbgD2thBypEn: 1; // 0
		uint32 rxdbgD2thBypVal: 7; // 1
		uint32 rxdbgD3thBypEn: 1; // 8
		uint32 rxdbgD3thBypVal: 7; // 9
		uint32 rxdbgDxthBypEn: 1; // 16
		uint32 rxdbgDxthBypVal: 7; // 17
		uint32 rxdbgEthBypEn: 1; // 24
		uint32 rxdbgEthBypVal: 7; // 25
	};
	uint32 val;
};

// PB0_GLB_CTRL_REG3
union Pb0GlbCtrlReg3 {
	struct {
		uint32 rxdbgSel: 5; // 0
		uint32 bgCfgLcRegVref0Sel: 2; // 5
		uint32 bgCfgLcRegVref1Sel: 2; // 7
		uint32 bgCfgRoRegVrefSel: 2; // 9
		uint32 bgDbgVrefbypEn: 1; // 11
		uint32 bgDbgIrefbypEn: 1; // 12
		uint32 unknown1: 1;
		uint32 bgDbgAnalogSel: 3; // 14
		uint32 unknown2: 1;
		uint32 dbgDllClkSel: 3; // 18
		uint32 pllDispclkCmosSel: 1; // 21
		uint32 dbgRxpiOffsetBypEn: 1; // 22
		uint32 dbgRxpiOffsetBypVal: 4; // 23
		uint32 dbgRxswapdxBypEn: 1; // 27
		uint32 dbgRxswapdxBypVal: 3; // 28
		uint32 dbgRxleqDcattnBypOvrDisable: 1; // 31
	};
	uint32 val;
};

// PB0_GLB_CTRL_REG4
union Pb0GlbCtrlReg4 {
	struct {
		uint32 dbgRxapuInst: 16; // 0
		uint32 dbgRxdfemuxBypVal: 2; // 16
		uint32 dbgRxdfemuxBypEn: 1; // 18
		uint32 unknown1: 3;
		uint32 dbgRxapuExec: 4; // 22
		uint32 dbgRxdllVregRefSel: 1; // 26
		uint32 pwrgoodOvrd: 1; // 27
		uint32 dbgRxrdataGatingDisable: 1; // 28
		uint32 unknown2: 3;
	};
	uint32 val;
};

// PB0_GLB_CTRL_REG5
union Pb0GlbCtrlReg5 {
	struct {
		uint32 dbgRxapuMode: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_GLB_OVRD_REG0
union Pb0GlbOvrdReg0 {
	struct {
		uint32 txpdtermValOvrdVal: 16; // 0
		uint32 txputermValOvrdVal: 16; // 16
	};
	uint32 val;
};

// PB0_GLB_OVRD_REG1
union Pb0GlbOvrdReg1 {
	struct {
		uint32 txpdtermValOvrdEn: 1; // 0
		uint32 txputermValOvrdEn: 1; // 1
		uint32 tstLospdtstRstOvrdEn: 1; // 2
		uint32 tstLospdtstRstOvrdVal: 1; // 3
		uint32 unknown1: 11;
		uint32 rxtermValOvrdEn: 1; // 15
		uint32 rxtermValOvrdVal: 16; // 16
	};
	uint32 val;
};

// PB0_GLB_OVRD_REG2
union Pb0GlbOvrdReg2 {
	struct {
		uint32 bgPwronOvrdEn: 1; // 0
		uint32 bgPwronOvrdVal: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// PB0_GLB_SCI_STAT_OVRD_REG0
union Pb0GlbSciStatOvrdReg0 {
	struct {
		uint32 ignrAllSciUpdtL0t3: 1; // 0
		uint32 ignrAllSciUpdtL4t7: 1; // 1
		uint32 ignrAllSciUpdtL8t11: 1; // 2
		uint32 ignrAllSciUpdtL12t15: 1; // 3
		uint32 ignrImpcalActiveSciUpdt: 1; // 4
		uint32 unknown1: 3;
		uint32 txnimp: 4; // 8
		uint32 txpimp: 4; // 12
		uint32 rximp: 4; // 16
		uint32 impcalActive: 1; // 20
		uint32 unknown2: 11;
	};
	uint32 val;
};

// PB0_GLB_SCI_STAT_OVRD_REG1
union Pb0GlbSciStatOvrdReg1 {
	struct {
		uint32 ignrModeSciUpdtL0t3: 1; // 0
		uint32 ignrFreqdivSciUpdtL0t3: 1; // 1
		uint32 ignrDllLockSciUpdtL0t3: 1; // 2
		uint32 unknown1: 9;
		uint32 dllLock0: 1; // 12
		uint32 dllLock1: 1; // 13
		uint32 dllLock2: 1; // 14
		uint32 dllLock3: 1; // 15
		uint32 mode0: 2; // 16
		uint32 freqdiv0: 2; // 18
		uint32 mode1: 2; // 20
		uint32 freqdiv1: 2; // 22
		uint32 mode2: 2; // 24
		uint32 freqdiv2: 2; // 26
		uint32 mode3: 2; // 28
		uint32 freqdiv3: 2; // 30
	};
	uint32 val;
};

// PB0_GLB_SCI_STAT_OVRD_REG2
union Pb0GlbSciStatOvrdReg2 {
	struct {
		uint32 ignrModeSciUpdtL4t7: 1; // 0
		uint32 ignrFreqdivSciUpdtL4t7: 1; // 1
		uint32 ignrDllLockSciUpdtL4t7: 1; // 2
		uint32 unknown1: 9;
		uint32 dllLock4: 1; // 12
		uint32 dllLock5: 1; // 13
		uint32 dllLock6: 1; // 14
		uint32 dllLock7: 1; // 15
		uint32 mode4: 2; // 16
		uint32 freqdiv4: 2; // 18
		uint32 mode5: 2; // 20
		uint32 freqdiv5: 2; // 22
		uint32 mode6: 2; // 24
		uint32 freqdiv6: 2; // 26
		uint32 mode7: 2; // 28
		uint32 freqdiv7: 2; // 30
	};
	uint32 val;
};

// PB0_GLB_SCI_STAT_OVRD_REG3
union Pb0GlbSciStatOvrdReg3 {
	struct {
		uint32 ignrModeSciUpdtL8t11: 1; // 0
		uint32 ignrFreqdivSciUpdtL8t11: 1; // 1
		uint32 ignrDllLockSciUpdtL8t11: 1; // 2
		uint32 unknown1: 9;
		uint32 dllLock8: 1; // 12
		uint32 dllLock9: 1; // 13
		uint32 dllLock10: 1; // 14
		uint32 dllLock11: 1; // 15
		uint32 mode8: 2; // 16
		uint32 freqdiv8: 2; // 18
		uint32 mode9: 2; // 20
		uint32 freqdiv9: 2; // 22
		uint32 mode10: 2; // 24
		uint32 freqdiv10: 2; // 26
		uint32 mode11: 2; // 28
		uint32 freqdiv11: 2; // 30
	};
	uint32 val;
};

// PB0_GLB_SCI_STAT_OVRD_REG4
union Pb0GlbSciStatOvrdReg4 {
	struct {
		uint32 ignrModeSciUpdtL12t15: 1; // 0
		uint32 ignrFreqdivSciUpdtL12t15: 1; // 1
		uint32 ignrDllLockSciUpdtL12t15: 1; // 2
		uint32 unknown1: 9;
		uint32 dllLock12: 1; // 12
		uint32 dllLock13: 1; // 13
		uint32 dllLock14: 1; // 14
		uint32 dllLock15: 1; // 15
		uint32 mode12: 2; // 16
		uint32 freqdiv12: 2; // 18
		uint32 mode13: 2; // 20
		uint32 freqdiv13: 2; // 22
		uint32 mode14: 2; // 24
		uint32 freqdiv14: 2; // 26
		uint32 mode15: 2; // 28
		uint32 freqdiv15: 2; // 30
	};
	uint32 val;
};

// PB0_HW_DEBUG
union Pb0HwDebug {
	struct {
		uint32 pb0Hw00Debug: 1; // 0
		uint32 pb0Hw01Debug: 1; // 1
		uint32 pb0Hw02Debug: 1; // 2
		uint32 pb0Hw03Debug: 1; // 3
		uint32 pb0Hw04Debug: 1; // 4
		uint32 pb0Hw05Debug: 1; // 5
		uint32 pb0Hw06Debug: 1; // 6
		uint32 pb0Hw07Debug: 1; // 7
		uint32 pb0Hw08Debug: 1; // 8
		uint32 pb0Hw09Debug: 1; // 9
		uint32 pb0Hw10Debug: 1; // 10
		uint32 pb0Hw11Debug: 1; // 11
		uint32 pb0Hw12Debug: 1; // 12
		uint32 pb0Hw13Debug: 1; // 13
		uint32 pb0Hw14Debug: 1; // 14
		uint32 pb0Hw15Debug: 1; // 15
		uint32 pb0Hw16Debug: 1; // 16
		uint32 pb0Hw17Debug: 1; // 17
		uint32 pb0Hw18Debug: 1; // 18
		uint32 pb0Hw19Debug: 1; // 19
		uint32 pb0Hw20Debug: 1; // 20
		uint32 pb0Hw21Debug: 1; // 21
		uint32 pb0Hw22Debug: 1; // 22
		uint32 pb0Hw23Debug: 1; // 23
		uint32 pb0Hw24Debug: 1; // 24
		uint32 pb0Hw25Debug: 1; // 25
		uint32 pb0Hw26Debug: 1; // 26
		uint32 pb0Hw27Debug: 1; // 27
		uint32 pb0Hw28Debug: 1; // 28
		uint32 pb0Hw29Debug: 1; // 29
		uint32 pb0Hw30Debug: 1; // 30
		uint32 pb0Hw31Debug: 1; // 31
	};
	uint32 val;
};

// PB0_PIF_CNTL
union Pb0PifCntl {
	struct {
		uint32 serialCfgEnable: 1; // 0
		uint32 daFifoReset0: 1; // 1
		uint32 phyCrEnMode: 1; // 2
		uint32 phycmdCrEnMode: 1; // 3
		uint32 eiDetCycleMode: 1; // 4
		uint32 daFifoReset1: 1; // 5
		uint32 rxdetectFifoResetMode: 1; // 6
		uint32 rxdetectTxPwrMode: 1; // 7
		uint32 divinitMode: 1; // 8
		uint32 daFifoReset2: 1; // 9
		uint32 pllBindingEnable: 1; // 10
		uint32 scCalibDoneCntl: 1; // 11
		uint32 unknown1: 1;
		uint32 daFifoReset3: 1; // 13
		uint32 unknown2: 2;
		uint32 txgndTime: 1; // 16
		uint32 ls2ExitTime: 3; // 17
		uint32 eiCycleOffTime: 3; // 20
		uint32 exitL0sInitDis: 1; // 23
		uint32 rxenGater: 4; // 24
		uint32 extendWaitForRampup: 1; // 28
		uint32 ignoreTxdatavalidEpDis: 1; // 29
		uint32 unknown3: 2;
	};
	uint32 val;
};

// PB0_PIF_CNTL2
union Pb0PifCntl2 {
	struct {
		uint32 unknown1: 1;
		uint32 rxdetectSamplTime: 2; // 1
		uint32 unknown2: 4;
		uint32 rxdetectOverrideEn: 1; // 7
		uint32 rxdetectOverrideVal0: 1; // 8
		uint32 rxdetectOverrideVal1: 1; // 9
		uint32 rxdetectOverrideVal2: 1; // 10
		uint32 rxdetectOverrideVal3: 1; // 11
		uint32 rxdetectOverrideVal4: 1; // 12
		uint32 rxdetectOverrideVal5: 1; // 13
		uint32 rxdetectOverrideVal6: 1; // 14
		uint32 rxdetectOverrideVal7: 1; // 15
		uint32 rxdetectOverrideVal8: 1; // 16
		uint32 rxdetectOverrideVal9: 1; // 17
		uint32 rxdetectOverrideVal10: 1; // 18
		uint32 rxdetectOverrideVal11: 1; // 19
		uint32 rxdetectOverrideVal12: 1; // 20
		uint32 rxdetectOverrideVal13: 1; // 21
		uint32 rxdetectOverrideVal14: 1; // 22
		uint32 rxdetectOverrideVal15: 1; // 23
		uint32 rxphystatusDelay: 3; // 24
		uint32 unknown3: 5;
	};
	uint32 val;
};

// PB0_PIF_HW_DEBUG
union Pb0PifHwDebug {
	struct {
		uint32 pb0PifHw00Debug: 1; // 0
		uint32 pb0PifHw01Debug: 1; // 1
		uint32 pb0PifHw02Debug: 1; // 2
		uint32 pb0PifHw03Debug: 1; // 3
		uint32 pb0PifHw04Debug: 1; // 4
		uint32 pb0PifHw05Debug: 1; // 5
		uint32 pb0PifHw06Debug: 1; // 6
		uint32 pb0PifHw07Debug: 1; // 7
		uint32 pb0PifHw08Debug: 1; // 8
		uint32 pb0PifHw09Debug: 1; // 9
		uint32 pb0PifHw10Debug: 1; // 10
		uint32 pb0PifHw11Debug: 1; // 11
		uint32 pb0PifHw12Debug: 1; // 12
		uint32 pb0PifHw13Debug: 1; // 13
		uint32 pb0PifHw14Debug: 1; // 14
		uint32 pb0PifHw15Debug: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_PIF_PAIRING
union Pb0PifPairing {
	struct {
		uint32 x2Lane1_0: 1; // 0
		uint32 x2Lane3_2: 1; // 1
		uint32 x2Lane5_4: 1; // 2
		uint32 x2Lane7_6: 1; // 3
		uint32 x2Lane9_8: 1; // 4
		uint32 x2Lane11_10: 1; // 5
		uint32 x2Lane13_12: 1; // 6
		uint32 x2Lane15_14: 1; // 7
		uint32 x4Lane3_0: 1; // 8
		uint32 x4Lane7_4: 1; // 9
		uint32 x4Lane11_8: 1; // 10
		uint32 x4Lane15_12: 1; // 11
		uint32 unknown1: 4;
		uint32 x8Lane7_0: 1; // 16
		uint32 x8Lane15_8: 1; // 17
		uint32 unknown2: 2;
		uint32 x16Lane15_0: 1; // 20
		uint32 unknown3: 4;
		uint32 multiPif: 1; // 25
		uint32 unknown4: 6;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_0
union Pb0PifPdnbOverride0 {
	struct {
		uint32 txPdnbOverrideEn0: 1; // 0
		uint32 txPdnbOverrideVal0: 3; // 1
		uint32 rxPdnbOverrideEn0: 1; // 4
		uint32 rxPdnbOverrideVal0: 3; // 5
		uint32 rxenOverrideEn0: 1; // 8
		uint32 rxenOverrideVal0: 1; // 9
		uint32 txpwrOverrideEn0: 1; // 10
		uint32 txpwrOverrideVal0: 3; // 11
		uint32 rxpwrOverrideEn0: 1; // 14
		uint32 rxpwrOverrideVal0: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_1
union Pb0PifPdnbOverride1 {
	struct {
		uint32 txPdnbOverrideEn1: 1; // 0
		uint32 txPdnbOverrideVal1: 3; // 1
		uint32 rxPdnbOverrideEn1: 1; // 4
		uint32 rxPdnbOverrideVal1: 3; // 5
		uint32 rxenOverrideEn1: 1; // 8
		uint32 rxenOverrideVal1: 1; // 9
		uint32 txpwrOverrideEn1: 1; // 10
		uint32 txpwrOverrideVal1: 3; // 11
		uint32 rxpwrOverrideEn1: 1; // 14
		uint32 rxpwrOverrideVal1: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_10
union Pb0PifPdnbOverride10 {
	struct {
		uint32 txPdnbOverrideEn10: 1; // 0
		uint32 txPdnbOverrideVal10: 3; // 1
		uint32 rxPdnbOverrideEn10: 1; // 4
		uint32 rxPdnbOverrideVal10: 3; // 5
		uint32 rxenOverrideEn10: 1; // 8
		uint32 rxenOverrideVal10: 1; // 9
		uint32 txpwrOverrideEn10: 1; // 10
		uint32 txpwrOverrideVal10: 3; // 11
		uint32 rxpwrOverrideEn10: 1; // 14
		uint32 rxpwrOverrideVal10: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_11
union Pb0PifPdnbOverride11 {
	struct {
		uint32 txPdnbOverrideEn11: 1; // 0
		uint32 txPdnbOverrideVal11: 3; // 1
		uint32 rxPdnbOverrideEn11: 1; // 4
		uint32 rxPdnbOverrideVal11: 3; // 5
		uint32 rxenOverrideEn11: 1; // 8
		uint32 rxenOverrideVal11: 1; // 9
		uint32 txpwrOverrideEn11: 1; // 10
		uint32 txpwrOverrideVal11: 3; // 11
		uint32 rxpwrOverrideEn11: 1; // 14
		uint32 rxpwrOverrideVal11: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_12
union Pb0PifPdnbOverride12 {
	struct {
		uint32 txPdnbOverrideEn12: 1; // 0
		uint32 txPdnbOverrideVal12: 3; // 1
		uint32 rxPdnbOverrideEn12: 1; // 4
		uint32 rxPdnbOverrideVal12: 3; // 5
		uint32 rxenOverrideEn12: 1; // 8
		uint32 rxenOverrideVal12: 1; // 9
		uint32 txpwrOverrideEn12: 1; // 10
		uint32 txpwrOverrideVal12: 3; // 11
		uint32 rxpwrOverrideEn12: 1; // 14
		uint32 rxpwrOverrideVal12: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_13
union Pb0PifPdnbOverride13 {
	struct {
		uint32 txPdnbOverrideEn13: 1; // 0
		uint32 txPdnbOverrideVal13: 3; // 1
		uint32 rxPdnbOverrideEn13: 1; // 4
		uint32 rxPdnbOverrideVal13: 3; // 5
		uint32 rxenOverrideEn13: 1; // 8
		uint32 rxenOverrideVal13: 1; // 9
		uint32 txpwrOverrideEn13: 1; // 10
		uint32 txpwrOverrideVal13: 3; // 11
		uint32 rxpwrOverrideEn13: 1; // 14
		uint32 rxpwrOverrideVal13: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_14
union Pb0PifPdnbOverride14 {
	struct {
		uint32 txPdnbOverrideEn14: 1; // 0
		uint32 txPdnbOverrideVal14: 3; // 1
		uint32 rxPdnbOverrideEn14: 1; // 4
		uint32 rxPdnbOverrideVal14: 3; // 5
		uint32 rxenOverrideEn14: 1; // 8
		uint32 rxenOverrideVal14: 1; // 9
		uint32 txpwrOverrideEn14: 1; // 10
		uint32 txpwrOverrideVal14: 3; // 11
		uint32 rxpwrOverrideEn14: 1; // 14
		uint32 rxpwrOverrideVal14: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_15
union Pb0PifPdnbOverride15 {
	struct {
		uint32 txPdnbOverrideEn15: 1; // 0
		uint32 txPdnbOverrideVal15: 3; // 1
		uint32 rxPdnbOverrideEn15: 1; // 4
		uint32 rxPdnbOverrideVal15: 3; // 5
		uint32 rxenOverrideEn15: 1; // 8
		uint32 rxenOverrideVal15: 1; // 9
		uint32 txpwrOverrideEn15: 1; // 10
		uint32 txpwrOverrideVal15: 3; // 11
		uint32 rxpwrOverrideEn15: 1; // 14
		uint32 rxpwrOverrideVal15: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_2
union Pb0PifPdnbOverride2 {
	struct {
		uint32 txPdnbOverrideEn2: 1; // 0
		uint32 txPdnbOverrideVal2: 3; // 1
		uint32 rxPdnbOverrideEn2: 1; // 4
		uint32 rxPdnbOverrideVal2: 3; // 5
		uint32 rxenOverrideEn2: 1; // 8
		uint32 rxenOverrideVal2: 1; // 9
		uint32 txpwrOverrideEn2: 1; // 10
		uint32 txpwrOverrideVal2: 3; // 11
		uint32 rxpwrOverrideEn2: 1; // 14
		uint32 rxpwrOverrideVal2: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_3
union Pb0PifPdnbOverride3 {
	struct {
		uint32 txPdnbOverrideEn3: 1; // 0
		uint32 txPdnbOverrideVal3: 3; // 1
		uint32 rxPdnbOverrideEn3: 1; // 4
		uint32 rxPdnbOverrideVal3: 3; // 5
		uint32 rxenOverrideEn3: 1; // 8
		uint32 rxenOverrideVal3: 1; // 9
		uint32 txpwrOverrideEn3: 1; // 10
		uint32 txpwrOverrideVal3: 3; // 11
		uint32 rxpwrOverrideEn3: 1; // 14
		uint32 rxpwrOverrideVal3: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_4
union Pb0PifPdnbOverride4 {
	struct {
		uint32 txPdnbOverrideEn4: 1; // 0
		uint32 txPdnbOverrideVal4: 3; // 1
		uint32 rxPdnbOverrideEn4: 1; // 4
		uint32 rxPdnbOverrideVal4: 3; // 5
		uint32 rxenOverrideEn4: 1; // 8
		uint32 rxenOverrideVal4: 1; // 9
		uint32 txpwrOverrideEn4: 1; // 10
		uint32 txpwrOverrideVal4: 3; // 11
		uint32 rxpwrOverrideEn4: 1; // 14
		uint32 rxpwrOverrideVal4: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_5
union Pb0PifPdnbOverride5 {
	struct {
		uint32 txPdnbOverrideEn5: 1; // 0
		uint32 txPdnbOverrideVal5: 3; // 1
		uint32 rxPdnbOverrideEn5: 1; // 4
		uint32 rxPdnbOverrideVal5: 3; // 5
		uint32 rxenOverrideEn5: 1; // 8
		uint32 rxenOverrideVal5: 1; // 9
		uint32 txpwrOverrideEn5: 1; // 10
		uint32 txpwrOverrideVal5: 3; // 11
		uint32 rxpwrOverrideEn5: 1; // 14
		uint32 rxpwrOverrideVal5: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_6
union Pb0PifPdnbOverride6 {
	struct {
		uint32 txPdnbOverrideEn6: 1; // 0
		uint32 txPdnbOverrideVal6: 3; // 1
		uint32 rxPdnbOverrideEn6: 1; // 4
		uint32 rxPdnbOverrideVal6: 3; // 5
		uint32 rxenOverrideEn6: 1; // 8
		uint32 rxenOverrideVal6: 1; // 9
		uint32 txpwrOverrideEn6: 1; // 10
		uint32 txpwrOverrideVal6: 3; // 11
		uint32 rxpwrOverrideEn6: 1; // 14
		uint32 rxpwrOverrideVal6: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_7
union Pb0PifPdnbOverride7 {
	struct {
		uint32 txPdnbOverrideEn7: 1; // 0
		uint32 txPdnbOverrideVal7: 3; // 1
		uint32 rxPdnbOverrideEn7: 1; // 4
		uint32 rxPdnbOverrideVal7: 3; // 5
		uint32 rxenOverrideEn7: 1; // 8
		uint32 rxenOverrideVal7: 1; // 9
		uint32 txpwrOverrideEn7: 1; // 10
		uint32 txpwrOverrideVal7: 3; // 11
		uint32 rxpwrOverrideEn7: 1; // 14
		uint32 rxpwrOverrideVal7: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_8
union Pb0PifPdnbOverride8 {
	struct {
		uint32 txPdnbOverrideEn8: 1; // 0
		uint32 txPdnbOverrideVal8: 3; // 1
		uint32 rxPdnbOverrideEn8: 1; // 4
		uint32 rxPdnbOverrideVal8: 3; // 5
		uint32 rxenOverrideEn8: 1; // 8
		uint32 rxenOverrideVal8: 1; // 9
		uint32 txpwrOverrideEn8: 1; // 10
		uint32 txpwrOverrideVal8: 3; // 11
		uint32 rxpwrOverrideEn8: 1; // 14
		uint32 rxpwrOverrideVal8: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PDNB_OVERRIDE_9
union Pb0PifPdnbOverride9 {
	struct {
		uint32 txPdnbOverrideEn9: 1; // 0
		uint32 txPdnbOverrideVal9: 3; // 1
		uint32 rxPdnbOverrideEn9: 1; // 4
		uint32 rxPdnbOverrideVal9: 3; // 5
		uint32 rxenOverrideEn9: 1; // 8
		uint32 rxenOverrideVal9: 1; // 9
		uint32 txpwrOverrideEn9: 1; // 10
		uint32 txpwrOverrideVal9: 3; // 11
		uint32 rxpwrOverrideEn9: 1; // 14
		uint32 rxpwrOverrideVal9: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB0_PIF_PWRDOWN_0
union Pb0PifPwrdown0 {
	struct {
		uint32 txPowerStateInTxs2_0: 3; // 0
		uint32 forceRxenInL0s0: 1; // 3
		uint32 rxPowerStateInRxs2_0: 3; // 4
		uint32 pllPowerStateInTxs2_0: 3; // 7
		uint32 pllPowerStateInOff0: 3; // 10
		uint32 unknown1: 3;
		uint32 tx2p5clkClockGatingEn0: 1; // 16
		uint32 unknown2: 7;
		uint32 pllRampUpTime0: 3; // 24
		uint32 unknown3: 1;
		uint32 pllpwrOverrideEn0: 1; // 28
		uint32 pllpwrOverrideVal0: 3; // 29
	};
	uint32 val;
};

// PB0_PIF_PWRDOWN_1
union Pb0PifPwrdown1 {
	struct {
		uint32 txPowerStateInTxs2_1: 3; // 0
		uint32 forceRxenInL0s1: 1; // 3
		uint32 rxPowerStateInRxs2_1: 3; // 4
		uint32 pllPowerStateInTxs2_1: 3; // 7
		uint32 pllPowerStateInOff1: 3; // 10
		uint32 unknown1: 3;
		uint32 tx2p5clkClockGatingEn1: 1; // 16
		uint32 unknown2: 7;
		uint32 pllRampUpTime1: 3; // 24
		uint32 unknown3: 1;
		uint32 pllpwrOverrideEn1: 1; // 28
		uint32 pllpwrOverrideVal1: 3; // 29
	};
	uint32 val;
};

// PB0_PIF_PWRDOWN_2
union Pb0PifPwrdown2 {
	struct {
		uint32 txPowerStateInTxs2_2: 3; // 0
		uint32 forceRxenInL0s2: 1; // 3
		uint32 rxPowerStateInRxs2_2: 3; // 4
		uint32 pllPowerStateInTxs2_2: 3; // 7
		uint32 pllPowerStateInOff2: 3; // 10
		uint32 unknown1: 3;
		uint32 tx2p5clkClockGatingEn2: 1; // 16
		uint32 unknown2: 7;
		uint32 pllRampUpTime2: 3; // 24
		uint32 unknown3: 1;
		uint32 pllpwrOverrideEn2: 1; // 28
		uint32 pllpwrOverrideVal2: 3; // 29
	};
	uint32 val;
};

// PB0_PIF_PWRDOWN_3
union Pb0PifPwrdown3 {
	struct {
		uint32 txPowerStateInTxs2_3: 3; // 0
		uint32 forceRxenInL0s3: 1; // 3
		uint32 rxPowerStateInRxs2_3: 3; // 4
		uint32 pllPowerStateInTxs2_3: 3; // 7
		uint32 pllPowerStateInOff3: 3; // 10
		uint32 unknown1: 3;
		uint32 tx2p5clkClockGatingEn3: 1; // 16
		uint32 unknown2: 7;
		uint32 pllRampUpTime3: 3; // 24
		uint32 unknown3: 1;
		uint32 pllpwrOverrideEn3: 1; // 28
		uint32 pllpwrOverrideVal3: 3; // 29
	};
	uint32 val;
};

// PB0_PIF_SCRATCH
union Pb0PifScratch {
	struct {
		uint32 pifScratch: 32; // 0
	};
	uint32 val;
};

// PB0_PIF_SC_CTL
union Pb0PifScCtl {
	struct {
		uint32 scCalibration: 1; // 0
		uint32 scRxdetect: 1; // 1
		uint32 scExitL1ToL0s: 1; // 2
		uint32 scExitL1ToL0: 1; // 3
		uint32 scEnterL1FromL0s: 1; // 4
		uint32 scEnterL1FromL0: 1; // 5
		uint32 scSpeedChange: 1; // 6
		uint32 unknown1: 1;
		uint32 scPhase1: 1; // 8
		uint32 scPhase2: 1; // 9
		uint32 scPhase3: 1; // 10
		uint32 scPhase4: 1; // 11
		uint32 scPhase5: 1; // 12
		uint32 scPhase6: 1; // 13
		uint32 scPhase7: 1; // 14
		uint32 scPhase8: 1; // 15
		uint32 scLane0Resume: 1; // 16
		uint32 scLane1Resume: 1; // 17
		uint32 scLane2Resume: 1; // 18
		uint32 scLane3Resume: 1; // 19
		uint32 scLane4Resume: 1; // 20
		uint32 scLane5Resume: 1; // 21
		uint32 scLane6Resume: 1; // 22
		uint32 scLane7Resume: 1; // 23
		uint32 scLane8Resume: 1; // 24
		uint32 scLane9Resume: 1; // 25
		uint32 scLane10Resume: 1; // 26
		uint32 scLane11Resume: 1; // 27
		uint32 scLane12Resume: 1; // 28
		uint32 scLane13Resume: 1; // 29
		uint32 scLane14Resume: 1; // 30
		uint32 scLane15Resume: 1; // 31
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_0
union Pb0PifSeqStatus0 {
	struct {
		uint32 seqCalibration0: 1; // 0
		uint32 seqRxdetect0: 1; // 1
		uint32 seqExitL1ToL0s0: 1; // 2
		uint32 seqExitL1ToL0_0: 1; // 3
		uint32 seqEnterL1FromL0s0: 1; // 4
		uint32 seqEnterL1FromL0_0: 1; // 5
		uint32 seqSpeedChange0: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase0: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_1
union Pb0PifSeqStatus1 {
	struct {
		uint32 seqCalibration1: 1; // 0
		uint32 seqRxdetect1: 1; // 1
		uint32 seqExitL1ToL0s1: 1; // 2
		uint32 seqExitL1ToL0_1: 1; // 3
		uint32 seqEnterL1FromL0s1: 1; // 4
		uint32 seqEnterL1FromL0_1: 1; // 5
		uint32 seqSpeedChange1: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase1: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_10
union Pb0PifSeqStatus10 {
	struct {
		uint32 seqCalibration10: 1; // 0
		uint32 seqRxdetect10: 1; // 1
		uint32 seqExitL1ToL0s10: 1; // 2
		uint32 seqExitL1ToL0_10: 1; // 3
		uint32 seqEnterL1FromL0s10: 1; // 4
		uint32 seqEnterL1FromL0_10: 1; // 5
		uint32 seqSpeedChange10: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase10: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_11
union Pb0PifSeqStatus11 {
	struct {
		uint32 seqCalibration11: 1; // 0
		uint32 seqRxdetect11: 1; // 1
		uint32 seqExitL1ToL0s11: 1; // 2
		uint32 seqExitL1ToL0_11: 1; // 3
		uint32 seqEnterL1FromL0s11: 1; // 4
		uint32 seqEnterL1FromL0_11: 1; // 5
		uint32 seqSpeedChange11: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase11: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_12
union Pb0PifSeqStatus12 {
	struct {
		uint32 seqCalibration12: 1; // 0
		uint32 seqRxdetect12: 1; // 1
		uint32 seqExitL1ToL0s12: 1; // 2
		uint32 seqExitL1ToL0_12: 1; // 3
		uint32 seqEnterL1FromL0s12: 1; // 4
		uint32 seqEnterL1FromL0_12: 1; // 5
		uint32 seqSpeedChange12: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase12: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_13
union Pb0PifSeqStatus13 {
	struct {
		uint32 seqCalibration13: 1; // 0
		uint32 seqRxdetect13: 1; // 1
		uint32 seqExitL1ToL0s13: 1; // 2
		uint32 seqExitL1ToL0_13: 1; // 3
		uint32 seqEnterL1FromL0s13: 1; // 4
		uint32 seqEnterL1FromL0_13: 1; // 5
		uint32 seqSpeedChange13: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase13: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_14
union Pb0PifSeqStatus14 {
	struct {
		uint32 seqCalibration14: 1; // 0
		uint32 seqRxdetect14: 1; // 1
		uint32 seqExitL1ToL0s14: 1; // 2
		uint32 seqExitL1ToL0_14: 1; // 3
		uint32 seqEnterL1FromL0s14: 1; // 4
		uint32 seqEnterL1FromL0_14: 1; // 5
		uint32 seqSpeedChange14: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase14: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_15
union Pb0PifSeqStatus15 {
	struct {
		uint32 seqCalibration15: 1; // 0
		uint32 seqRxdetect15: 1; // 1
		uint32 seqExitL1ToL0s15: 1; // 2
		uint32 seqExitL1ToL0_15: 1; // 3
		uint32 seqEnterL1FromL0s15: 1; // 4
		uint32 seqEnterL1FromL0_15: 1; // 5
		uint32 seqSpeedChange15: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase15: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_2
union Pb0PifSeqStatus2 {
	struct {
		uint32 seqCalibration2: 1; // 0
		uint32 seqRxdetect2: 1; // 1
		uint32 seqExitL1ToL0s2: 1; // 2
		uint32 seqExitL1ToL0_2: 1; // 3
		uint32 seqEnterL1FromL0s2: 1; // 4
		uint32 seqEnterL1FromL0_2: 1; // 5
		uint32 seqSpeedChange2: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase2: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_3
union Pb0PifSeqStatus3 {
	struct {
		uint32 seqCalibration3: 1; // 0
		uint32 seqRxdetect3: 1; // 1
		uint32 seqExitL1ToL0s3: 1; // 2
		uint32 seqExitL1ToL0_3: 1; // 3
		uint32 seqEnterL1FromL0s3: 1; // 4
		uint32 seqEnterL1FromL0_3: 1; // 5
		uint32 seqSpeedChange3: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase3: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_4
union Pb0PifSeqStatus4 {
	struct {
		uint32 seqCalibration4: 1; // 0
		uint32 seqRxdetect4: 1; // 1
		uint32 seqExitL1ToL0s4: 1; // 2
		uint32 seqExitL1ToL0_4: 1; // 3
		uint32 seqEnterL1FromL0s4: 1; // 4
		uint32 seqEnterL1FromL0_4: 1; // 5
		uint32 seqSpeedChange4: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase4: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_5
union Pb0PifSeqStatus5 {
	struct {
		uint32 seqCalibration5: 1; // 0
		uint32 seqRxdetect5: 1; // 1
		uint32 seqExitL1ToL0s5: 1; // 2
		uint32 seqExitL1ToL0_5: 1; // 3
		uint32 seqEnterL1FromL0s5: 1; // 4
		uint32 seqEnterL1FromL0_5: 1; // 5
		uint32 seqSpeedChange5: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase5: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_6
union Pb0PifSeqStatus6 {
	struct {
		uint32 seqCalibration6: 1; // 0
		uint32 seqRxdetect6: 1; // 1
		uint32 seqExitL1ToL0s6: 1; // 2
		uint32 seqExitL1ToL0_6: 1; // 3
		uint32 seqEnterL1FromL0s6: 1; // 4
		uint32 seqEnterL1FromL0_6: 1; // 5
		uint32 seqSpeedChange6: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase6: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_7
union Pb0PifSeqStatus7 {
	struct {
		uint32 seqCalibration7: 1; // 0
		uint32 seqRxdetect7: 1; // 1
		uint32 seqExitL1ToL0s7: 1; // 2
		uint32 seqExitL1ToL0_7: 1; // 3
		uint32 seqEnterL1FromL0s7: 1; // 4
		uint32 seqEnterL1FromL0_7: 1; // 5
		uint32 seqSpeedChange7: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase7: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_8
union Pb0PifSeqStatus8 {
	struct {
		uint32 seqCalibration8: 1; // 0
		uint32 seqRxdetect8: 1; // 1
		uint32 seqExitL1ToL0s8: 1; // 2
		uint32 seqExitL1ToL0_8: 1; // 3
		uint32 seqEnterL1FromL0s8: 1; // 4
		uint32 seqEnterL1FromL0_8: 1; // 5
		uint32 seqSpeedChange8: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase8: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_SEQ_STATUS_9
union Pb0PifSeqStatus9 {
	struct {
		uint32 seqCalibration9: 1; // 0
		uint32 seqRxdetect9: 1; // 1
		uint32 seqExitL1ToL0s9: 1; // 2
		uint32 seqExitL1ToL0_9: 1; // 3
		uint32 seqEnterL1FromL0s9: 1; // 4
		uint32 seqEnterL1FromL0_9: 1; // 5
		uint32 seqSpeedChange9: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase9: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB0_PIF_TXPHYSTATUS
union Pb0PifTxphystatus {
	struct {
		uint32 txphystatus0: 1; // 0
		uint32 txphystatus1: 1; // 1
		uint32 txphystatus2: 1; // 2
		uint32 txphystatus3: 1; // 3
		uint32 txphystatus4: 1; // 4
		uint32 txphystatus5: 1; // 5
		uint32 txphystatus6: 1; // 6
		uint32 txphystatus7: 1; // 7
		uint32 txphystatus8: 1; // 8
		uint32 txphystatus9: 1; // 9
		uint32 txphystatus10: 1; // 10
		uint32 txphystatus11: 1; // 11
		uint32 txphystatus12: 1; // 12
		uint32 txphystatus13: 1; // 13
		uint32 txphystatus14: 1; // 14
		uint32 txphystatus15: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_PLL_LC0_CTRL_REG0
union Pb0PllLc0CtrlReg0 {
	struct {
		uint32 pllDbgLcAnalogSel0: 2; // 0
		uint32 pllDbgLcExtResetEn0: 1; // 2
		uint32 pllDbgLcVctlAdcEn0: 1; // 3
		uint32 pllTstLcUsampleEn0: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// PB0_PLL_LC0_OVRD_REG0
union Pb0PllLc0OvrdReg0 {
	struct {
		uint32 pllCfgLcBwCntrlOvrdVal0: 3; // 0
		uint32 pllCfgLcBwCntrlOvrdEn0: 1; // 3
		uint32 pllCfgLcCoreclkDivOvrdVal0: 3; // 4
		uint32 pllCfgLcCoreclkDivOvrdEn0: 1; // 7
		uint32 pllCfgLcCoreclkEnOvrdVal0: 1; // 8
		uint32 pllCfgLcCoreclkEnOvrdEn0: 1; // 9
		uint32 pllCfgLcFbdivOvrdVal0: 8; // 10
		uint32 pllCfgLcFbdivOvrdEn0: 1; // 18
		uint32 pllCfgLcLfCntrlOvrdVal0: 9; // 19
		uint32 pllCfgLcLfCntrlOvrdEn0: 1; // 28
		uint32 pllCfgLcRefdivOvrdVal0: 2; // 29
		uint32 pllCfgLcRefdivOvrdEn0: 1; // 31
	};
	uint32 val;
};

// PB0_PLL_LC0_OVRD_REG1
union Pb0PllLc0OvrdReg1 {
	struct {
		uint32 pllCfgLcRefclkSrcOvrdVal0: 3; // 0
		uint32 pllCfgLcRefclkSrcOvrdEn0: 1; // 3
		uint32 pllLcHsclkLeftEnOvrdVal0: 1; // 4
		uint32 pllLcHsclkLeftEnOvrdEn0: 1; // 5
		uint32 pllLcHsclkRightEnOvrdVal0: 1; // 6
		uint32 pllLcHsclkRightEnOvrdEn0: 1; // 7
		uint32 pllLcPwronOvrdVal0: 1; // 8
		uint32 pllLcPwronOvrdEn0: 1; // 9
		uint32 unknown1: 4;
		uint32 pllCfgLcVcoTuneOvrdVal0: 4; // 14
		uint32 pllCfgLcVcoTuneOvrdEn0: 1; // 18
		uint32 unknown2: 13;
	};
	uint32 val;
};

// PB0_PLL_LC0_SCI_STAT_OVRD_REG0
union Pb0PllLc0SciStatOvrdReg0 {
	struct {
		uint32 pllLc0IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllLc0IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllLc0Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllLc0Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB0_PLL_LC1_SCI_STAT_OVRD_REG0
union Pb0PllLc1SciStatOvrdReg0 {
	struct {
		uint32 pllLc1IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllLc1IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllLc1Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllLc1Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB0_PLL_LC2_SCI_STAT_OVRD_REG0
union Pb0PllLc2SciStatOvrdReg0 {
	struct {
		uint32 pllLc2IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllLc2IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllLc2Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllLc2Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB0_PLL_LC3_SCI_STAT_OVRD_REG0
union Pb0PllLc3SciStatOvrdReg0 {
	struct {
		uint32 pllLc3IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllLc3IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllLc3Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllLc3Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB0_PLL_RO0_CTRL_REG0
union Pb0PllRo0CtrlReg0 {
	struct {
		uint32 pllDbgRoAnalogSel0: 2; // 0
		uint32 pllDbgRoExtResetEn0: 1; // 2
		uint32 pllDbgRoVctlAdcEn0: 1; // 3
		uint32 pllDbgRoLfCntrl0: 7; // 4
		uint32 pllTstRoUsampleEn0: 1; // 11
		uint32 unknown1: 20;
	};
	uint32 val;
};

// PB0_PLL_RO0_OVRD_REG0
union Pb0PllRo0OvrdReg0 {
	struct {
		uint32 pllCfgRoBwCntrlOvrdVal0: 8; // 0
		uint32 pllCfgRoBwCntrlOvrdEn0: 1; // 8
		uint32 pllCfgRoCoreclkDivOvrdVal0: 3; // 9
		uint32 pllCfgRoCoreclkDivOvrdEn0: 1; // 12
		uint32 pllCfgRoCoreclkEnOvrdVal0: 1; // 13
		uint32 pllCfgRoCoreclkEnOvrdEn0: 1; // 14
		uint32 pllCfgRoFbdivOvrdVal0: 13; // 15
		uint32 pllCfgRoFbdivOvrdEn0: 1; // 28
		uint32 unknown1: 1;
		uint32 pllCfgRoVtoiBiasCntrlOvrdVal0: 1; // 30
		uint32 pllCfgRoVtoiBiasCntrlOvrdEn0: 1; // 31
	};
	uint32 val;
};

// PB0_PLL_RO0_OVRD_REG1
union Pb0PllRo0OvrdReg1 {
	struct {
		uint32 pllCfgRoRefdivOvrdVal0: 5; // 0
		uint32 pllCfgRoRefdivOvrdEn0: 1; // 5
		uint32 pllCfgRoVcoModeOvrdVal0: 2; // 6
		uint32 pllCfgRoVcoModeOvrdEn0: 1; // 8
		uint32 pllRoHsclkLeftEnOvrdVal0: 1; // 9
		uint32 pllRoHsclkLeftEnOvrdEn0: 1; // 10
		uint32 pllRoHsclkRightEnOvrdVal0: 1; // 11
		uint32 pllRoHsclkRightEnOvrdEn0: 1; // 12
		uint32 pllRoPwronOvrdVal0: 1; // 13
		uint32 pllRoPwronOvrdEn0: 1; // 14
		uint32 unknown1: 4;
		uint32 pllCfgRoRefclkSrcOvrdVal0: 3; // 19
		uint32 pllCfgRoRefclkSrcOvrdEn0: 1; // 22
		uint32 unknown2: 9;
	};
	uint32 val;
};

// PB0_PLL_RO0_SCI_STAT_OVRD_REG0
union Pb0PllRo0SciStatOvrdReg0 {
	struct {
		uint32 pllRo0IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllRo0IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllRo0Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllRo0Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB0_PLL_RO1_SCI_STAT_OVRD_REG0
union Pb0PllRo1SciStatOvrdReg0 {
	struct {
		uint32 pllRo1IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllRo1IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllRo1Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllRo1Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB0_PLL_RO2_SCI_STAT_OVRD_REG0
union Pb0PllRo2SciStatOvrdReg0 {
	struct {
		uint32 pllRo2IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllRo2IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllRo2Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllRo2Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB0_PLL_RO3_SCI_STAT_OVRD_REG0
union Pb0PllRo3SciStatOvrdReg0 {
	struct {
		uint32 pllRo3IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllRo3IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllRo3Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllRo3Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB0_PLL_RO_GLB_CTRL_REG0
union Pb0PllRoGlbCtrlReg0 {
	struct {
		uint32 pllTstLospdtstSrc: 1; // 0
		uint32 pllRoHsclkLeftEnLutEntryLs0: 1; // 1
		uint32 pllRoHsclkLeftEnLutEntryLs1: 1; // 2
		uint32 pllRoHsclkLeftEnLutEntryLs2: 1; // 3
		uint32 pllRoHsclkRightEnLutEntryLs0: 1; // 4
		uint32 pllRoHsclkRightEnLutEntryLs1: 1; // 5
		uint32 pllRoHsclkRightEnLutEntryLs2: 1; // 6
		uint32 pllRoPwronLutEntryLs2: 1; // 7
		uint32 pllLcPwronLutEntryLs2: 1; // 8
		uint32 pllLcHsclkLeftEnLutEntryLs0: 1; // 9
		uint32 pllLcHsclkLeftEnLutEntryLs1: 1; // 10
		uint32 pllLcHsclkLeftEnLutEntryLs2: 1; // 11
		uint32 pllLcHsclkRightEnLutEntryLs0: 1; // 12
		uint32 pllLcHsclkRightEnLutEntryLs1: 1; // 13
		uint32 pllLcHsclkRightEnLutEntryLs2: 1; // 14
		uint32 unknown1: 1;
		uint32 pllRoHsclkLeftLeftEnGatingEn: 1; // 16
		uint32 pllRoHsclkLeftRightEnGatingEn: 1; // 17
		uint32 pllRoHsclkRightLeftEnGatingEn: 1; // 18
		uint32 pllRoHsclkRightRightEnGatingEn: 1; // 19
		uint32 pllLcHsclkLeftLeftEnGatingEn: 1; // 20
		uint32 pllLcHsclkLeftRightEnGatingEn: 1; // 21
		uint32 pllLcHsclkRightLeftEnGatingEn: 1; // 22
		uint32 pllLcHsclkRightRightEnGatingEn: 1; // 23
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PB0_RX_GLB_CTRL_REG0
union Pb0RxGlbCtrlReg0 {
	struct {
		uint32 rxCfgAdaptModeGen1: 10; // 0
		uint32 rxCfgAdaptModeGen2: 10; // 10
		uint32 rxCfgAdaptModeGen3: 10; // 20
		uint32 rxCfgAdaptRstMode: 2; // 30
	};
	uint32 val;
};

// PB0_RX_GLB_CTRL_REG1
union Pb0RxGlbCtrlReg1 {
	struct {
		uint32 rxCfgCdrFrGainGen1: 4; // 0
		uint32 rxCfgCdrFrGainGen2: 4; // 4
		uint32 rxCfgCdrFrGainGen3: 4; // 8
		uint32 rxCfgCdrPhGainGen1: 4; // 12
		uint32 rxCfgCdrPhGainGen2: 4; // 16
		uint32 rxCfgCdrPhGainGen3: 4; // 20
		uint32 rxCfgCdrPiStpszGen1: 1; // 24
		uint32 rxCfgCdrPiStpszGen2: 1; // 25
		uint32 rxCfgCdrPiStpszGen3: 1; // 26
		uint32 rxCfgLeqDcattnBypEnGen1: 1; // 27
		uint32 rxCfgLeqDcattnBypEnGen2: 1; // 28
		uint32 rxCfgLeqDcattnBypEnGen3: 1; // 29
		uint32 rxAdaptHldAsrtToDclkEn: 2; // 30
	};
	uint32 val;
};

// PB0_RX_GLB_CTRL_REG2
union Pb0RxGlbCtrlReg2 {
	struct {
		uint32 unknown1: 12;
		uint32 rxCfgCdrTimeGen1: 4; // 12
		uint32 rxCfgCdrTimeGen2: 4; // 16
		uint32 rxCfgCdrTimeGen3: 4; // 20
		uint32 rxCfgLeqLoopGainGen1: 2; // 24
		uint32 rxCfgLeqLoopGainGen2: 2; // 26
		uint32 rxCfgLeqLoopGainGen3: 2; // 28
		uint32 rxDclkEnAsrtToAdaptHld: 2; // 30
	};
	uint32 val;
};

// PB0_RX_GLB_CTRL_REG3
union Pb0RxGlbCtrlReg3 {
	struct {
		uint32 rxCfgCdrFrEnGen1: 1; // 0
		uint32 rxCfgCdrFrEnGen2: 1; // 1
		uint32 rxCfgCdrFrEnGen3: 1; // 2
		uint32 unknown1: 17;
		uint32 rxCfgDfeTimeGen1: 4; // 20
		uint32 rxCfgDfeTimeGen2: 4; // 24
		uint32 rxCfgDfeTimeGen3: 4; // 28
	};
	uint32 val;
};

// PB0_RX_GLB_CTRL_REG4
union Pb0RxGlbCtrlReg4 {
	struct {
		uint32 rxCfgFomBerGen1: 3; // 0
		uint32 rxCfgFomBerGen2: 3; // 3
		uint32 rxCfgFomBerGen3: 3; // 6
		uint32 rxCfgLeqPoleBypValGen1: 3; // 9
		uint32 rxCfgLeqPoleBypValGen2: 3; // 12
		uint32 rxCfgLeqPoleBypValGen3: 3; // 15
		uint32 unknown1: 2;
		uint32 rxCfgFomTimeGen1: 4; // 20
		uint32 rxCfgFomTimeGen2: 4; // 24
		uint32 rxCfgFomTimeGen3: 4; // 28
	};
	uint32 val;
};

// PB0_RX_GLB_CTRL_REG5
union Pb0RxGlbCtrlReg5 {
	struct {
		uint32 rxCfgLeqDcattnBypValGen1: 5; // 0
		uint32 rxCfgLeqDcattnBypValGen2: 5; // 5
		uint32 rxCfgLeqDcattnBypValGen3: 5; // 10
		uint32 rxCfgLeqPoleBypEnGen1: 1; // 15
		uint32 rxCfgLeqPoleBypEnGen2: 1; // 16
		uint32 rxCfgLeqPoleBypEnGen3: 1; // 17
		uint32 rxCfgLeqShuntEnGen1: 1; // 18
		uint32 rxCfgLeqShuntEnGen2: 1; // 19
		uint32 rxCfgLeqShuntEnGen3: 1; // 20
		uint32 unknown1: 6;
		uint32 rxCfgTermModeGen1: 1; // 27
		uint32 rxCfgTermModeGen2: 1; // 28
		uint32 rxCfgTermModeGen3: 1; // 29
		uint32 rxForceDllRstRxpwrLs2offToLs0: 1; // 30
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PB0_RX_GLB_CTRL_REG6
union Pb0RxGlbCtrlReg6 {
	struct {
		uint32 rxCfgLeqTimeGen1: 4; // 0
		uint32 rxCfgLeqTimeGen2: 4; // 4
		uint32 rxCfgLeqTimeGen3: 4; // 8
		uint32 rxCfgOcTimeGen1: 4; // 12
		uint32 rxCfgOcTimeGen2: 4; // 16
		uint32 rxCfgOcTimeGen3: 4; // 20
		uint32 rxFrontendPwronLutEntryLs0CdrEn0: 1; // 24
		uint32 unknown1: 1;
		uint32 rxFrontendPwronLutEntryLs2: 1; // 26
		uint32 rxAuxPwronLutEntryLs2: 1; // 27
		uint32 unknown2: 4;
	};
	uint32 val;
};

// PB0_RX_GLB_CTRL_REG7
union Pb0RxGlbCtrlReg7 {
	struct {
		uint32 rxCfgThLoopGainGen1: 4; // 0
		uint32 rxCfgThLoopGainGen2: 4; // 4
		uint32 rxCfgThLoopGainGen3: 4; // 8
		uint32 rxDclkEnLutEntryLs0CdrEn0: 1; // 12
		uint32 rxDclkEnLutEntryLs2: 1; // 13
		uint32 unknown1: 3;
		uint32 rxDllPwronLutEntryLs2: 1; // 17
		uint32 rxCfgDllCpiSelGen1: 3; // 18
		uint32 rxCfgDllCpiSelGen2: 3; // 21
		uint32 rxCfgDllCpiSelGen3: 3; // 24
		uint32 rxCfgDllFlockDisableGen1: 1; // 27
		uint32 rxCfgDllFlockDisableGen2: 1; // 28
		uint32 rxCfgDllFlockDisableGen3: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// PB0_RX_GLB_OVRD_REG0
union Pb0RxGlbOvrdReg0 {
	struct {
		uint32 rxAdaptHldOvrdVal: 1; // 0
		uint32 rxAdaptHldOvrdEn: 1; // 1
		uint32 rxAdaptRstOvrdVal: 1; // 2
		uint32 rxAdaptRstOvrdEn: 1; // 3
		uint32 unknown1: 2;
		uint32 rxCfgDclkDivOvrdVal: 2; // 6
		uint32 rxCfgDclkDivOvrdEn: 1; // 8
		uint32 rxCfgDllFreqModeOvrdVal: 1; // 9
		uint32 rxCfgDllFreqModeOvrdEn: 1; // 10
		uint32 rxCfgPllclkSelOvrdVal: 1; // 11
		uint32 rxCfgPllclkSelOvrdEn: 1; // 12
		uint32 rxCfgRclkDivOvrdVal: 1; // 13
		uint32 rxCfgRclkDivOvrdEn: 1; // 14
		uint32 rxDclkEnOvrdVal: 1; // 15
		uint32 rxDclkEnOvrdEn: 1; // 16
		uint32 rxDllPwronOvrdVal: 1; // 17
		uint32 rxDllPwronOvrdEn: 1; // 18
		uint32 rxFrontendPwronOvrdVal: 1; // 19
		uint32 rxFrontendPwronOvrdEn: 1; // 20
		uint32 rxIdledetPwronOvrdVal: 1; // 21
		uint32 rxIdledetPwronOvrdEn: 1; // 22
		uint32 rxTermEnOvrdVal: 1; // 23
		uint32 rxTermEnOvrdEn: 1; // 24
		uint32 unknown2: 3;
		uint32 rxAuxPwronOvrdVal: 1; // 28
		uint32 rxAuxPwronOvrdEn: 1; // 29
		uint32 rxAdaptFomOvrdVal: 1; // 30
		uint32 rxAdaptFomOvrdEn: 1; // 31
	};
	uint32 val;
};

// PB0_RX_GLB_OVRD_REG1
union Pb0RxGlbOvrdReg1 {
	struct {
		uint32 rxAdaptTrkOvrdVal: 1; // 0
		uint32 rxAdaptTrkOvrdEn: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// PB0_RX_GLB_SCI_STAT_OVRD_REG0
union Pb0RxGlbSciStatOvrdReg0 {
	struct {
		uint32 ignrRxpwrSciUpdtL0t3: 1; // 0
		uint32 ignrRxpwrSciUpdtL4t7: 1; // 1
		uint32 ignrRxpwrSciUpdtL8t11: 1; // 2
		uint32 ignrRxpwrSciUpdtL12t15: 1; // 3
		uint32 ignrElecidledetenSciUpdtL0t3: 1; // 4
		uint32 ignrElecidledetenSciUpdtL4t7: 1; // 5
		uint32 ignrElecidledetenSciUpdtL8t11: 1; // 6
		uint32 ignrElecidledetenSciUpdtL12t15: 1; // 7
		uint32 ignrRxpresethintSciUpdtL0t3: 1; // 8
		uint32 ignrRxpresethintSciUpdtL4t7: 1; // 9
		uint32 ignrRxpresethintSciUpdtL8t11: 1; // 10
		uint32 ignrRxpresethintSciUpdtL12t15: 1; // 11
		uint32 ignrEnablefomSciUpdtL0t3: 1; // 12
		uint32 ignrEnablefomSciUpdtL4t7: 1; // 13
		uint32 ignrEnablefomSciUpdtL8t11: 1; // 14
		uint32 ignrEnablefomSciUpdtL12t15: 1; // 15
		uint32 ignrRequestfomSciUpdtL0t3: 1; // 16
		uint32 ignrRequestfomSciUpdtL4t7: 1; // 17
		uint32 ignrRequestfomSciUpdtL8t11: 1; // 18
		uint32 ignrRequestfomSciUpdtL12t15: 1; // 19
		uint32 ignrResponsemodeSciUpdtL0t3: 1; // 20
		uint32 ignrResponsemodeSciUpdtL4t7: 1; // 21
		uint32 ignrResponsemodeSciUpdtL8t11: 1; // 22
		uint32 ignrResponsemodeSciUpdtL12t15: 1; // 23
		uint32 unknown1: 8;
	};
	uint32 val;
};

// PB0_RX_LANE0_CTRL_REG0
union Pb0RxLane0CtrlReg0 {
	struct {
		uint32 rxBackup0: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel0: 2; // 10
		uint32 rxTstBscanEn0: 1; // 12
		uint32 rxCfgOvrPwrsf0: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE0_SCI_STAT_OVRD_REG0
union Pb0RxLane0SciStatOvrdReg0 {
	struct {
		uint32 rxpwr0: 3; // 0
		uint32 elecidledeten0: 1; // 3
		uint32 rxpresethint0: 3; // 4
		uint32 enablefom0: 1; // 7
		uint32 requestfom0: 1; // 8
		uint32 responsemode0: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE10_CTRL_REG0
union Pb0RxLane10CtrlReg0 {
	struct {
		uint32 rxBackup10: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel10: 2; // 10
		uint32 rxTstBscanEn10: 1; // 12
		uint32 rxCfgOvrPwrsf10: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE10_SCI_STAT_OVRD_REG0
union Pb0RxLane10SciStatOvrdReg0 {
	struct {
		uint32 rxpwr10: 3; // 0
		uint32 elecidledeten10: 1; // 3
		uint32 rxpresethint10: 3; // 4
		uint32 enablefom10: 1; // 7
		uint32 requestfom10: 1; // 8
		uint32 responsemode10: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE11_CTRL_REG0
union Pb0RxLane11CtrlReg0 {
	struct {
		uint32 rxBackup11: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel11: 2; // 10
		uint32 rxTstBscanEn11: 1; // 12
		uint32 rxCfgOvrPwrsf11: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE11_SCI_STAT_OVRD_REG0
union Pb0RxLane11SciStatOvrdReg0 {
	struct {
		uint32 rxpwr11: 3; // 0
		uint32 elecidledeten11: 1; // 3
		uint32 rxpresethint11: 3; // 4
		uint32 enablefom11: 1; // 7
		uint32 requestfom11: 1; // 8
		uint32 responsemode11: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE12_CTRL_REG0
union Pb0RxLane12CtrlReg0 {
	struct {
		uint32 rxBackup12: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel12: 2; // 10
		uint32 rxTstBscanEn12: 1; // 12
		uint32 rxCfgOvrPwrsf12: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE12_SCI_STAT_OVRD_REG0
union Pb0RxLane12SciStatOvrdReg0 {
	struct {
		uint32 rxpwr12: 3; // 0
		uint32 elecidledeten12: 1; // 3
		uint32 rxpresethint12: 3; // 4
		uint32 enablefom12: 1; // 7
		uint32 requestfom12: 1; // 8
		uint32 responsemode12: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE13_CTRL_REG0
union Pb0RxLane13CtrlReg0 {
	struct {
		uint32 rxBackup13: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel13: 2; // 10
		uint32 rxTstBscanEn13: 1; // 12
		uint32 rxCfgOvrPwrsf13: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE13_SCI_STAT_OVRD_REG0
union Pb0RxLane13SciStatOvrdReg0 {
	struct {
		uint32 rxpwr13: 3; // 0
		uint32 elecidledeten13: 1; // 3
		uint32 rxpresethint13: 3; // 4
		uint32 enablefom13: 1; // 7
		uint32 requestfom13: 1; // 8
		uint32 responsemode13: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE14_CTRL_REG0
union Pb0RxLane14CtrlReg0 {
	struct {
		uint32 rxBackup14: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel14: 2; // 10
		uint32 rxTstBscanEn14: 1; // 12
		uint32 rxCfgOvrPwrsf14: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE14_SCI_STAT_OVRD_REG0
union Pb0RxLane14SciStatOvrdReg0 {
	struct {
		uint32 rxpwr14: 3; // 0
		uint32 elecidledeten14: 1; // 3
		uint32 rxpresethint14: 3; // 4
		uint32 enablefom14: 1; // 7
		uint32 requestfom14: 1; // 8
		uint32 responsemode14: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE15_CTRL_REG0
union Pb0RxLane15CtrlReg0 {
	struct {
		uint32 rxBackup15: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel15: 2; // 10
		uint32 rxTstBscanEn15: 1; // 12
		uint32 rxCfgOvrPwrsf15: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE15_SCI_STAT_OVRD_REG0
union Pb0RxLane15SciStatOvrdReg0 {
	struct {
		uint32 rxpwr15: 3; // 0
		uint32 elecidledeten15: 1; // 3
		uint32 rxpresethint15: 3; // 4
		uint32 enablefom15: 1; // 7
		uint32 requestfom15: 1; // 8
		uint32 responsemode15: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE1_CTRL_REG0
union Pb0RxLane1CtrlReg0 {
	struct {
		uint32 rxBackup1: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel1: 2; // 10
		uint32 rxTstBscanEn1: 1; // 12
		uint32 rxCfgOvrPwrsf1: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE1_SCI_STAT_OVRD_REG0
union Pb0RxLane1SciStatOvrdReg0 {
	struct {
		uint32 rxpwr1: 3; // 0
		uint32 elecidledeten1: 1; // 3
		uint32 rxpresethint1: 3; // 4
		uint32 enablefom1: 1; // 7
		uint32 requestfom1: 1; // 8
		uint32 responsemode1: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE2_CTRL_REG0
union Pb0RxLane2CtrlReg0 {
	struct {
		uint32 rxBackup2: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel2: 2; // 10
		uint32 rxTstBscanEn2: 1; // 12
		uint32 rxCfgOvrPwrsf2: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE2_SCI_STAT_OVRD_REG0
union Pb0RxLane2SciStatOvrdReg0 {
	struct {
		uint32 rxpwr2: 3; // 0
		uint32 elecidledeten2: 1; // 3
		uint32 rxpresethint2: 3; // 4
		uint32 enablefom2: 1; // 7
		uint32 requestfom2: 1; // 8
		uint32 responsemode2: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE3_CTRL_REG0
union Pb0RxLane3CtrlReg0 {
	struct {
		uint32 rxBackup3: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel3: 2; // 10
		uint32 rxTstBscanEn3: 1; // 12
		uint32 rxCfgOvrPwrsf3: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE3_SCI_STAT_OVRD_REG0
union Pb0RxLane3SciStatOvrdReg0 {
	struct {
		uint32 rxpwr3: 3; // 0
		uint32 elecidledeten3: 1; // 3
		uint32 rxpresethint3: 3; // 4
		uint32 enablefom3: 1; // 7
		uint32 requestfom3: 1; // 8
		uint32 responsemode3: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE4_CTRL_REG0
union Pb0RxLane4CtrlReg0 {
	struct {
		uint32 rxBackup4: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel4: 2; // 10
		uint32 rxTstBscanEn4: 1; // 12
		uint32 rxCfgOvrPwrsf4: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE4_SCI_STAT_OVRD_REG0
union Pb0RxLane4SciStatOvrdReg0 {
	struct {
		uint32 rxpwr4: 3; // 0
		uint32 elecidledeten4: 1; // 3
		uint32 rxpresethint4: 3; // 4
		uint32 enablefom4: 1; // 7
		uint32 requestfom4: 1; // 8
		uint32 responsemode4: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE5_CTRL_REG0
union Pb0RxLane5CtrlReg0 {
	struct {
		uint32 rxBackup5: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel5: 2; // 10
		uint32 rxTstBscanEn5: 1; // 12
		uint32 rxCfgOvrPwrsf5: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE5_SCI_STAT_OVRD_REG0
union Pb0RxLane5SciStatOvrdReg0 {
	struct {
		uint32 rxpwr5: 3; // 0
		uint32 elecidledeten5: 1; // 3
		uint32 rxpresethint5: 3; // 4
		uint32 enablefom5: 1; // 7
		uint32 requestfom5: 1; // 8
		uint32 responsemode5: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE6_CTRL_REG0
union Pb0RxLane6CtrlReg0 {
	struct {
		uint32 rxBackup6: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel6: 2; // 10
		uint32 rxTstBscanEn6: 1; // 12
		uint32 rxCfgOvrPwrsf6: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE6_SCI_STAT_OVRD_REG0
union Pb0RxLane6SciStatOvrdReg0 {
	struct {
		uint32 rxpwr6: 3; // 0
		uint32 elecidledeten6: 1; // 3
		uint32 rxpresethint6: 3; // 4
		uint32 enablefom6: 1; // 7
		uint32 requestfom6: 1; // 8
		uint32 responsemode6: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE7_CTRL_REG0
union Pb0RxLane7CtrlReg0 {
	struct {
		uint32 rxBackup7: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel7: 2; // 10
		uint32 rxTstBscanEn7: 1; // 12
		uint32 rxCfgOvrPwrsf7: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE7_SCI_STAT_OVRD_REG0
union Pb0RxLane7SciStatOvrdReg0 {
	struct {
		uint32 rxpwr7: 3; // 0
		uint32 elecidledeten7: 1; // 3
		uint32 rxpresethint7: 3; // 4
		uint32 enablefom7: 1; // 7
		uint32 requestfom7: 1; // 8
		uint32 responsemode7: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE8_CTRL_REG0
union Pb0RxLane8CtrlReg0 {
	struct {
		uint32 rxBackup8: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel8: 2; // 10
		uint32 rxTstBscanEn8: 1; // 12
		uint32 rxCfgOvrPwrsf8: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE8_SCI_STAT_OVRD_REG0
union Pb0RxLane8SciStatOvrdReg0 {
	struct {
		uint32 rxpwr8: 3; // 0
		uint32 elecidledeten8: 1; // 3
		uint32 rxpresethint8: 3; // 4
		uint32 enablefom8: 1; // 7
		uint32 requestfom8: 1; // 8
		uint32 responsemode8: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_RX_LANE9_CTRL_REG0
union Pb0RxLane9CtrlReg0 {
	struct {
		uint32 rxBackup9: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel9: 2; // 10
		uint32 rxTstBscanEn9: 1; // 12
		uint32 rxCfgOvrPwrsf9: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB0_RX_LANE9_SCI_STAT_OVRD_REG0
union Pb0RxLane9SciStatOvrdReg0 {
	struct {
		uint32 rxpwr9: 3; // 0
		uint32 elecidledeten9: 1; // 3
		uint32 rxpresethint9: 3; // 4
		uint32 enablefom9: 1; // 7
		uint32 requestfom9: 1; // 8
		uint32 responsemode9: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB0_STRAP_GLB_REG0
union Pb0StrapGlbReg0 {
	struct {
		uint32 unknown1: 15;
		uint32 strapDbgRxdllVregRefSel: 1; // 15
		uint32 unknown2: 16;
	};
	uint32 val;
};

// PB0_TX_GLB_COEFF_ACCEPT_TABLE_REG0
union Pb0TxGlbCoeffAcceptTableReg0 {
	struct {
		uint32 acceptEntry0: 1; // 0
		uint32 acceptEntry1: 1; // 1
		uint32 acceptEntry2: 1; // 2
		uint32 acceptEntry3: 1; // 3
		uint32 acceptEntry4: 1; // 4
		uint32 acceptEntry5: 1; // 5
		uint32 acceptEntry6: 1; // 6
		uint32 acceptEntry7: 1; // 7
		uint32 acceptEntry8: 1; // 8
		uint32 acceptEntry9: 1; // 9
		uint32 acceptEntry10: 1; // 10
		uint32 acceptEntry11: 1; // 11
		uint32 acceptEntry12: 1; // 12
		uint32 acceptEntry13: 1; // 13
		uint32 acceptEntry14: 1; // 14
		uint32 acceptEntry15: 1; // 15
		uint32 acceptEntry16: 1; // 16
		uint32 acceptEntry17: 1; // 17
		uint32 acceptEntry18: 1; // 18
		uint32 acceptEntry19: 1; // 19
		uint32 acceptEntry20: 1; // 20
		uint32 acceptEntry21: 1; // 21
		uint32 acceptEntry22: 1; // 22
		uint32 acceptEntry23: 1; // 23
		uint32 acceptEntry24: 1; // 24
		uint32 acceptEntry25: 1; // 25
		uint32 acceptEntry26: 1; // 26
		uint32 acceptEntry27: 1; // 27
		uint32 acceptEntry28: 1; // 28
		uint32 acceptEntry29: 1; // 29
		uint32 acceptEntry30: 1; // 30
		uint32 acceptEntry31: 1; // 31
	};
	uint32 val;
};

// PB0_TX_GLB_COEFF_ACCEPT_TABLE_REG1
union Pb0TxGlbCoeffAcceptTableReg1 {
	struct {
		uint32 acceptEntry32: 1; // 0
		uint32 acceptEntry33: 1; // 1
		uint32 acceptEntry34: 1; // 2
		uint32 acceptEntry35: 1; // 3
		uint32 acceptEntry36: 1; // 4
		uint32 acceptEntry37: 1; // 5
		uint32 acceptEntry38: 1; // 6
		uint32 acceptEntry39: 1; // 7
		uint32 acceptEntry40: 1; // 8
		uint32 acceptEntry41: 1; // 9
		uint32 acceptEntry42: 1; // 10
		uint32 acceptEntry43: 1; // 11
		uint32 acceptEntry44: 1; // 12
		uint32 acceptEntry45: 1; // 13
		uint32 acceptEntry46: 1; // 14
		uint32 acceptEntry47: 1; // 15
		uint32 acceptEntry48: 1; // 16
		uint32 acceptEntry49: 1; // 17
		uint32 acceptEntry50: 1; // 18
		uint32 acceptEntry51: 1; // 19
		uint32 acceptEntry52: 1; // 20
		uint32 acceptEntry53: 1; // 21
		uint32 acceptEntry54: 1; // 22
		uint32 acceptEntry55: 1; // 23
		uint32 acceptEntry56: 1; // 24
		uint32 acceptEntry57: 1; // 25
		uint32 acceptEntry58: 1; // 26
		uint32 acceptEntry59: 1; // 27
		uint32 acceptEntry60: 1; // 28
		uint32 acceptEntry61: 1; // 29
		uint32 acceptEntry62: 1; // 30
		uint32 acceptEntry63: 1; // 31
	};
	uint32 val;
};

// PB0_TX_GLB_COEFF_ACCEPT_TABLE_REG2
union Pb0TxGlbCoeffAcceptTableReg2 {
	struct {
		uint32 acceptEntry64: 1; // 0
		uint32 acceptEntry65: 1; // 1
		uint32 acceptEntry66: 1; // 2
		uint32 acceptEntry67: 1; // 3
		uint32 acceptEntry68: 1; // 4
		uint32 acceptEntry69: 1; // 5
		uint32 acceptEntry70: 1; // 6
		uint32 acceptEntry71: 1; // 7
		uint32 acceptEntry72: 1; // 8
		uint32 acceptEntry73: 1; // 9
		uint32 acceptEntry74: 1; // 10
		uint32 acceptEntry75: 1; // 11
		uint32 acceptEntry76: 1; // 12
		uint32 acceptEntry77: 1; // 13
		uint32 acceptEntry78: 1; // 14
		uint32 acceptEntry79: 1; // 15
		uint32 acceptEntry80: 1; // 16
		uint32 acceptEntry81: 1; // 17
		uint32 acceptEntry82: 1; // 18
		uint32 acceptEntry83: 1; // 19
		uint32 acceptEntry84: 1; // 20
		uint32 acceptEntry85: 1; // 21
		uint32 acceptEntry86: 1; // 22
		uint32 acceptEntry87: 1; // 23
		uint32 acceptEntry88: 1; // 24
		uint32 acceptEntry89: 1; // 25
		uint32 acceptEntry90: 1; // 26
		uint32 acceptEntry91: 1; // 27
		uint32 acceptEntry92: 1; // 28
		uint32 acceptEntry93: 1; // 29
		uint32 acceptEntry94: 1; // 30
		uint32 acceptEntry95: 1; // 31
	};
	uint32 val;
};

// PB0_TX_GLB_COEFF_ACCEPT_TABLE_REG3
union Pb0TxGlbCoeffAcceptTableReg3 {
	struct {
		uint32 acceptEntry96: 1; // 0
		uint32 acceptEntry97: 1; // 1
		uint32 acceptEntry98: 1; // 2
		uint32 acceptEntry99: 1; // 3
		uint32 acceptEntry100: 1; // 4
		uint32 acceptEntry101: 1; // 5
		uint32 acceptEntry102: 1; // 6
		uint32 acceptEntry103: 1; // 7
		uint32 acceptEntry104: 1; // 8
		uint32 acceptEntry105: 1; // 9
		uint32 acceptEntry106: 1; // 10
		uint32 acceptEntry107: 1; // 11
		uint32 acceptEntry108: 1; // 12
		uint32 acceptEntry109: 1; // 13
		uint32 unknown1: 18;
	};
	uint32 val;
};

// PB0_TX_GLB_CTRL_REG0
union Pb0TxGlbCtrlReg0 {
	struct {
		uint32 txDrvDataAsrtDlyVal: 3; // 0
		uint32 txDrvDataDsrtDlyVal: 3; // 3
		uint32 unknown1: 2;
		uint32 txCfgRptrRstValGen1: 3; // 8
		uint32 txCfgRptrRstValGen2: 3; // 11
		uint32 txCfgRptrRstValGen3: 3; // 14
		uint32 txStaggerCtrl: 2; // 17
		uint32 txDataClkGating: 1; // 19
		uint32 txPresetTableBypass: 1; // 20
		uint32 txCoeffRoundEn: 1; // 21
		uint32 txCoeffRoundDirVer: 1; // 22
		uint32 txDclkEnLsxAlwaysOn: 1; // 23
		uint32 txFrontendPwronInOff: 1; // 24
		uint32 unknown2: 7;
	};
	uint32 val;
};

// PB0_TX_GLB_LANE_SKEW_CTRL
union Pb0TxGlbLaneSkewCtrl {
	struct {
		uint32 txCfgGroupx1En0: 1; // 0
		uint32 txCfgGroupx1En1: 1; // 1
		uint32 txCfgGroupx1En2: 1; // 2
		uint32 txCfgGroupx1En3: 1; // 3
		uint32 txCfgGroupx1En4: 1; // 4
		uint32 txCfgGroupx1En5: 1; // 5
		uint32 txCfgGroupx1En6: 1; // 6
		uint32 txCfgGroupx1En7: 1; // 7
		uint32 txCfgGroupx1En8: 1; // 8
		uint32 txCfgGroupx1En9: 1; // 9
		uint32 txCfgGroupx1En10: 1; // 10
		uint32 txCfgGroupx1En11: 1; // 11
		uint32 txCfgGroupx1En12: 1; // 12
		uint32 txCfgGroupx1En13: 1; // 13
		uint32 txCfgGroupx1En14: 1; // 14
		uint32 txCfgGroupx1En15: 1; // 15
		uint32 txCfgGroupx2EnL0t1: 1; // 16
		uint32 txCfgGroupx2EnL2t3: 1; // 17
		uint32 txCfgGroupx2EnL4t5: 1; // 18
		uint32 txCfgGroupx2EnL6t7: 1; // 19
		uint32 txCfgGroupx2EnL8t9: 1; // 20
		uint32 txCfgGroupx2EnL10t11: 1; // 21
		uint32 txCfgGroupx2EnL12t13: 1; // 22
		uint32 txCfgGroupx2EnL14t15: 1; // 23
		uint32 txCfgGroupx4EnL0t3: 1; // 24
		uint32 txCfgGroupx4EnL4t7: 1; // 25
		uint32 txCfgGroupx4EnL8t11: 1; // 26
		uint32 txCfgGroupx4EnL12t15: 1; // 27
		uint32 txCfgGroupx8EnL0t7: 1; // 28
		uint32 txCfgGroupx8EnL8t15: 1; // 29
		uint32 txCfgGroupx16EnL0t15: 1; // 30
		uint32 unknown1: 1;
	};
	uint32 val;
};

// PB0_TX_GLB_OVRD_REG0
union Pb0TxGlbOvrdReg0 {
	struct {
		uint32 txCfgDclkDivOvrdVal: 3; // 0
		uint32 txCfgDclkDivOvrdEn: 1; // 3
		uint32 txCfgDrv0EnGen1OvrdVal: 4; // 4
		uint32 txCfgDrv0EnOvrdEn: 1; // 8
		uint32 txCfgDrv0TapSelGen1OvrdVal: 4; // 9
		uint32 txCfgDrv0TapSelOvrdEn: 1; // 13
		uint32 txCfgDrv1EnGen1OvrdVal: 5; // 14
		uint32 txCfgDrv1EnOvrdEn: 1; // 19
		uint32 txCfgDrv1TapSelGen1OvrdVal: 5; // 20
		uint32 txCfgDrv1TapSelOvrdEn: 1; // 25
		uint32 txCfgDrv2EnGen1OvrdVal: 4; // 26
		uint32 txCfgDrv2EnOvrdEn: 1; // 30
		uint32 unknown1: 1;
	};
	uint32 val;
};

// PB0_TX_GLB_OVRD_REG1
union Pb0TxGlbOvrdReg1 {
	struct {
		uint32 txCfgDrv2TapSelGen1OvrdVal: 4; // 0
		uint32 txCfgDrv2TapSelOvrdEn: 1; // 4
		uint32 txCfgDrvxEnGen1OvrdVal: 1; // 5
		uint32 txCfgDrvxEnOvrdEn: 1; // 6
		uint32 txCfgDrvxTapSelGen1OvrdVal: 1; // 7
		uint32 txCfgDrvxTapSelOvrdEn: 1; // 8
		uint32 txCfgPllclkSelOvrdVal: 1; // 9
		uint32 txCfgPllclkSelOvrdEn: 1; // 10
		uint32 txCfgTclkDivOvrdVal: 1; // 11
		uint32 txCfgTclkDivOvrdEn: 1; // 12
		uint32 txCmdetEnOvrdVal: 1; // 13
		uint32 txCmdetEnOvrdEn: 1; // 14
		uint32 txDataInOvrdVal: 10; // 15
		uint32 txDataInOvrdEn: 1; // 25
		uint32 txRptrRstnOvrdVal: 1; // 26
		uint32 txRptrRstnOvrdEn: 1; // 27
		uint32 txRxdetEnOvrdVal: 1; // 28
		uint32 txRxdetEnOvrdEn: 1; // 29
		uint32 txWptrRstnOvrdVal: 1; // 30
		uint32 txWptrRstnOvrdEn: 1; // 31
	};
	uint32 val;
};

// PB0_TX_GLB_OVRD_REG2
union Pb0TxGlbOvrdReg2 {
	struct {
		uint32 txWriteEnOvrdVal: 1; // 0
		uint32 txWriteEnOvrdEn: 1; // 1
		uint32 txCfgGroupx1EnOvrdVal: 1; // 2
		uint32 txCfgGroupx1EnOvrdEn: 1; // 3
		uint32 txCfgGroupx2EnOvrdVal: 1; // 4
		uint32 txCfgGroupx2EnOvrdEn: 1; // 5
		uint32 txCfgGroupx4EnOvrdVal: 1; // 6
		uint32 txCfgGroupx4EnOvrdEn: 1; // 7
		uint32 txCfgGroupx8EnOvrdVal: 1; // 8
		uint32 txCfgGroupx8EnOvrdEn: 1; // 9
		uint32 txCfgGroupx16EnOvrdVal: 1; // 10
		uint32 txCfgGroupx16EnOvrdEn: 1; // 11
		uint32 txCfgDrv0EnGen2OvrdVal: 4; // 12
		uint32 txCfgDrv0TapSelGen2OvrdVal: 4; // 16
		uint32 txCfgDrv1EnGen2OvrdVal: 5; // 20
		uint32 txCfgDrv1TapSelGen2OvrdVal: 5; // 25
		uint32 unknown1: 2;
	};
	uint32 val;
};

// PB0_TX_GLB_OVRD_REG3
union Pb0TxGlbOvrdReg3 {
	struct {
		uint32 txCfgDrv2EnGen2OvrdVal: 4; // 0
		uint32 txCfgDrv2TapSelGen2OvrdVal: 4; // 4
		uint32 txCfgDrvxEnGen2OvrdVal: 1; // 8
		uint32 txCfgDrvxTapSelGen2OvrdVal: 1; // 9
		uint32 txCfgDrv0EnGen3OvrdVal: 4; // 10
		uint32 txCfgDrv0TapSelGen3OvrdVal: 4; // 14
		uint32 txCfgDrv1EnGen3OvrdVal: 5; // 18
		uint32 txCfgDrv1TapSelGen3OvrdVal: 5; // 23
		uint32 txCfgDrv2EnGen3OvrdVal: 4; // 28
	};
	uint32 val;
};

// PB0_TX_GLB_OVRD_REG4
union Pb0TxGlbOvrdReg4 {
	struct {
		uint32 txCfgDrv2TapSelGen3OvrdVal: 4; // 0
		uint32 txCfgDrvxEnGen3OvrdVal: 1; // 4
		uint32 txCfgDrvxTapSelGen3OvrdVal: 1; // 5
		uint32 unknown1: 26;
	};
	uint32 val;
};

// PB0_TX_GLB_SCI_STAT_OVRD_REG0
union Pb0TxGlbSciStatOvrdReg0 {
	struct {
		uint32 ignrTxpwrSciUpdtL0t3: 1; // 0
		uint32 ignrTxpwrSciUpdtL4t7: 1; // 1
		uint32 ignrTxpwrSciUpdtL8t11: 1; // 2
		uint32 ignrTxpwrSciUpdtL12t15: 1; // 3
		uint32 ignrIncoherentckSciUpdtL0t3: 1; // 4
		uint32 ignrIncoherentckSciUpdtL4t7: 1; // 5
		uint32 ignrIncoherentckSciUpdtL8t11: 1; // 6
		uint32 ignrIncoherentckSciUpdtL12t15: 1; // 7
		uint32 ignrCoefficientidSciUpdtL0t3: 1; // 8
		uint32 ignrCoefficientidSciUpdtL4t7: 1; // 9
		uint32 ignrCoefficientidSciUpdtL8t11: 1; // 10
		uint32 ignrCoefficientidSciUpdtL12t15: 1; // 11
		uint32 ignrCoefficientSciUpdtL0t3: 1; // 12
		uint32 ignrCoefficientSciUpdtL4t7: 1; // 13
		uint32 ignrCoefficientSciUpdtL8t11: 1; // 14
		uint32 ignrCoefficientSciUpdtL12t15: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE0_CTRL_REG0
union Pb0TxLane0CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode0: 1; // 0
		uint32 txCfgInvData0: 1; // 1
		uint32 txCfgSwingBoostEn0: 1; // 2
		uint32 txDbgPrbsEn0: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE0_OVRD_REG0
union Pb0TxLane0OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal0: 1; // 0
		uint32 txDclkEnOvrdEn0: 1; // 1
		uint32 txDrvDataEnOvrdVal0: 1; // 2
		uint32 txDrvDataEnOvrdEn0: 1; // 3
		uint32 txDrvPwronOvrdVal0: 1; // 4
		uint32 txDrvPwronOvrdEn0: 1; // 5
		uint32 txFrontendPwronOvrdVal0: 1; // 6
		uint32 txFrontendPwronOvrdEn0: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE0_SCI_STAT_OVRD_REG0
union Pb0TxLane0SciStatOvrdReg0 {
	struct {
		uint32 txpwr0: 3; // 0
		uint32 incoherentck0: 1; // 3
		uint32 txmarg0: 3; // 4
		uint32 deemph0: 1; // 7
		uint32 coefficientid0: 2; // 8
		uint32 coefficient0: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE10_CTRL_REG0
union Pb0TxLane10CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode10: 1; // 0
		uint32 txCfgInvData10: 1; // 1
		uint32 txCfgSwingBoostEn10: 1; // 2
		uint32 txDbgPrbsEn10: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE10_OVRD_REG0
union Pb0TxLane10OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal10: 1; // 0
		uint32 txDclkEnOvrdEn10: 1; // 1
		uint32 txDrvDataEnOvrdVal10: 1; // 2
		uint32 txDrvDataEnOvrdEn10: 1; // 3
		uint32 txDrvPwronOvrdVal10: 1; // 4
		uint32 txDrvPwronOvrdEn10: 1; // 5
		uint32 txFrontendPwronOvrdVal10: 1; // 6
		uint32 txFrontendPwronOvrdEn10: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE10_SCI_STAT_OVRD_REG0
union Pb0TxLane10SciStatOvrdReg0 {
	struct {
		uint32 txpwr10: 3; // 0
		uint32 incoherentck10: 1; // 3
		uint32 txmarg10: 3; // 4
		uint32 deemph10: 1; // 7
		uint32 coefficientid10: 2; // 8
		uint32 coefficient10: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE11_CTRL_REG0
union Pb0TxLane11CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode11: 1; // 0
		uint32 txCfgInvData11: 1; // 1
		uint32 txCfgSwingBoostEn11: 1; // 2
		uint32 txDbgPrbsEn11: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE11_OVRD_REG0
union Pb0TxLane11OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal11: 1; // 0
		uint32 txDclkEnOvrdEn11: 1; // 1
		uint32 txDrvDataEnOvrdVal11: 1; // 2
		uint32 txDrvDataEnOvrdEn11: 1; // 3
		uint32 txDrvPwronOvrdVal11: 1; // 4
		uint32 txDrvPwronOvrdEn11: 1; // 5
		uint32 txFrontendPwronOvrdVal11: 1; // 6
		uint32 txFrontendPwronOvrdEn11: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE11_SCI_STAT_OVRD_REG0
union Pb0TxLane11SciStatOvrdReg0 {
	struct {
		uint32 txpwr11: 3; // 0
		uint32 incoherentck11: 1; // 3
		uint32 txmarg11: 3; // 4
		uint32 deemph11: 1; // 7
		uint32 coefficientid11: 2; // 8
		uint32 coefficient11: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE12_CTRL_REG0
union Pb0TxLane12CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode12: 1; // 0
		uint32 txCfgInvData12: 1; // 1
		uint32 txCfgSwingBoostEn12: 1; // 2
		uint32 txDbgPrbsEn12: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE12_OVRD_REG0
union Pb0TxLane12OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal12: 1; // 0
		uint32 txDclkEnOvrdEn12: 1; // 1
		uint32 txDrvDataEnOvrdVal12: 1; // 2
		uint32 txDrvDataEnOvrdEn12: 1; // 3
		uint32 txDrvPwronOvrdVal12: 1; // 4
		uint32 txDrvPwronOvrdEn12: 1; // 5
		uint32 txFrontendPwronOvrdVal12: 1; // 6
		uint32 txFrontendPwronOvrdEn12: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE12_SCI_STAT_OVRD_REG0
union Pb0TxLane12SciStatOvrdReg0 {
	struct {
		uint32 txpwr12: 3; // 0
		uint32 incoherentck12: 1; // 3
		uint32 txmarg12: 3; // 4
		uint32 deemph12: 1; // 7
		uint32 coefficientid12: 2; // 8
		uint32 coefficient12: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE13_CTRL_REG0
union Pb0TxLane13CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode13: 1; // 0
		uint32 txCfgInvData13: 1; // 1
		uint32 txCfgSwingBoostEn13: 1; // 2
		uint32 txDbgPrbsEn13: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE13_OVRD_REG0
union Pb0TxLane13OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal13: 1; // 0
		uint32 txDclkEnOvrdEn13: 1; // 1
		uint32 txDrvDataEnOvrdVal13: 1; // 2
		uint32 txDrvDataEnOvrdEn13: 1; // 3
		uint32 txDrvPwronOvrdVal13: 1; // 4
		uint32 txDrvPwronOvrdEn13: 1; // 5
		uint32 txFrontendPwronOvrdVal13: 1; // 6
		uint32 txFrontendPwronOvrdEn13: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE13_SCI_STAT_OVRD_REG0
union Pb0TxLane13SciStatOvrdReg0 {
	struct {
		uint32 txpwr13: 3; // 0
		uint32 incoherentck13: 1; // 3
		uint32 txmarg13: 3; // 4
		uint32 deemph13: 1; // 7
		uint32 coefficientid13: 2; // 8
		uint32 coefficient13: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE14_CTRL_REG0
union Pb0TxLane14CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode14: 1; // 0
		uint32 txCfgInvData14: 1; // 1
		uint32 txCfgSwingBoostEn14: 1; // 2
		uint32 txDbgPrbsEn14: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE14_OVRD_REG0
union Pb0TxLane14OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal14: 1; // 0
		uint32 txDclkEnOvrdEn14: 1; // 1
		uint32 txDrvDataEnOvrdVal14: 1; // 2
		uint32 txDrvDataEnOvrdEn14: 1; // 3
		uint32 txDrvPwronOvrdVal14: 1; // 4
		uint32 txDrvPwronOvrdEn14: 1; // 5
		uint32 txFrontendPwronOvrdVal14: 1; // 6
		uint32 txFrontendPwronOvrdEn14: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE14_SCI_STAT_OVRD_REG0
union Pb0TxLane14SciStatOvrdReg0 {
	struct {
		uint32 txpwr14: 3; // 0
		uint32 incoherentck14: 1; // 3
		uint32 txmarg14: 3; // 4
		uint32 deemph14: 1; // 7
		uint32 coefficientid14: 2; // 8
		uint32 coefficient14: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE15_CTRL_REG0
union Pb0TxLane15CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode15: 1; // 0
		uint32 txCfgInvData15: 1; // 1
		uint32 txCfgSwingBoostEn15: 1; // 2
		uint32 txDbgPrbsEn15: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE15_OVRD_REG0
union Pb0TxLane15OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal15: 1; // 0
		uint32 txDclkEnOvrdEn15: 1; // 1
		uint32 txDrvDataEnOvrdVal15: 1; // 2
		uint32 txDrvDataEnOvrdEn15: 1; // 3
		uint32 txDrvPwronOvrdVal15: 1; // 4
		uint32 txDrvPwronOvrdEn15: 1; // 5
		uint32 txFrontendPwronOvrdVal15: 1; // 6
		uint32 txFrontendPwronOvrdEn15: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE15_SCI_STAT_OVRD_REG0
union Pb0TxLane15SciStatOvrdReg0 {
	struct {
		uint32 txpwr15: 3; // 0
		uint32 incoherentck15: 1; // 3
		uint32 txmarg15: 3; // 4
		uint32 deemph15: 1; // 7
		uint32 coefficientid15: 2; // 8
		uint32 coefficient15: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE1_CTRL_REG0
union Pb0TxLane1CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode1: 1; // 0
		uint32 txCfgInvData1: 1; // 1
		uint32 txCfgSwingBoostEn1: 1; // 2
		uint32 txDbgPrbsEn1: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE1_OVRD_REG0
union Pb0TxLane1OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal1: 1; // 0
		uint32 txDclkEnOvrdEn1: 1; // 1
		uint32 txDrvDataEnOvrdVal1: 1; // 2
		uint32 txDrvDataEnOvrdEn1: 1; // 3
		uint32 txDrvPwronOvrdVal1: 1; // 4
		uint32 txDrvPwronOvrdEn1: 1; // 5
		uint32 txFrontendPwronOvrdVal1: 1; // 6
		uint32 txFrontendPwronOvrdEn1: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE1_SCI_STAT_OVRD_REG0
union Pb0TxLane1SciStatOvrdReg0 {
	struct {
		uint32 txpwr1: 3; // 0
		uint32 incoherentck1: 1; // 3
		uint32 txmarg1: 3; // 4
		uint32 deemph1: 1; // 7
		uint32 coefficientid1: 2; // 8
		uint32 coefficient1: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE2_CTRL_REG0
union Pb0TxLane2CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode2: 1; // 0
		uint32 txCfgInvData2: 1; // 1
		uint32 txCfgSwingBoostEn2: 1; // 2
		uint32 txDbgPrbsEn2: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE2_OVRD_REG0
union Pb0TxLane2OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal2: 1; // 0
		uint32 txDclkEnOvrdEn2: 1; // 1
		uint32 txDrvDataEnOvrdVal2: 1; // 2
		uint32 txDrvDataEnOvrdEn2: 1; // 3
		uint32 txDrvPwronOvrdVal2: 1; // 4
		uint32 txDrvPwronOvrdEn2: 1; // 5
		uint32 txFrontendPwronOvrdVal2: 1; // 6
		uint32 txFrontendPwronOvrdEn2: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE2_SCI_STAT_OVRD_REG0
union Pb0TxLane2SciStatOvrdReg0 {
	struct {
		uint32 txpwr2: 3; // 0
		uint32 incoherentck2: 1; // 3
		uint32 txmarg2: 3; // 4
		uint32 deemph2: 1; // 7
		uint32 coefficientid2: 2; // 8
		uint32 coefficient2: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE3_CTRL_REG0
union Pb0TxLane3CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode3: 1; // 0
		uint32 txCfgInvData3: 1; // 1
		uint32 txCfgSwingBoostEn3: 1; // 2
		uint32 txDbgPrbsEn3: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE3_OVRD_REG0
union Pb0TxLane3OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal3: 1; // 0
		uint32 txDclkEnOvrdEn3: 1; // 1
		uint32 txDrvDataEnOvrdVal3: 1; // 2
		uint32 txDrvDataEnOvrdEn3: 1; // 3
		uint32 txDrvPwronOvrdVal3: 1; // 4
		uint32 txDrvPwronOvrdEn3: 1; // 5
		uint32 txFrontendPwronOvrdVal3: 1; // 6
		uint32 txFrontendPwronOvrdEn3: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE3_SCI_STAT_OVRD_REG0
union Pb0TxLane3SciStatOvrdReg0 {
	struct {
		uint32 txpwr3: 3; // 0
		uint32 incoherentck3: 1; // 3
		uint32 txmarg3: 3; // 4
		uint32 deemph3: 1; // 7
		uint32 coefficientid3: 2; // 8
		uint32 coefficient3: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE4_CTRL_REG0
union Pb0TxLane4CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode4: 1; // 0
		uint32 txCfgInvData4: 1; // 1
		uint32 txCfgSwingBoostEn4: 1; // 2
		uint32 txDbgPrbsEn4: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE4_OVRD_REG0
union Pb0TxLane4OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal4: 1; // 0
		uint32 txDclkEnOvrdEn4: 1; // 1
		uint32 txDrvDataEnOvrdVal4: 1; // 2
		uint32 txDrvDataEnOvrdEn4: 1; // 3
		uint32 txDrvPwronOvrdVal4: 1; // 4
		uint32 txDrvPwronOvrdEn4: 1; // 5
		uint32 txFrontendPwronOvrdVal4: 1; // 6
		uint32 txFrontendPwronOvrdEn4: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE4_SCI_STAT_OVRD_REG0
union Pb0TxLane4SciStatOvrdReg0 {
	struct {
		uint32 txpwr4: 3; // 0
		uint32 incoherentck4: 1; // 3
		uint32 txmarg4: 3; // 4
		uint32 deemph4: 1; // 7
		uint32 coefficientid4: 2; // 8
		uint32 coefficient4: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE5_CTRL_REG0
union Pb0TxLane5CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode5: 1; // 0
		uint32 txCfgInvData5: 1; // 1
		uint32 txCfgSwingBoostEn5: 1; // 2
		uint32 txDbgPrbsEn5: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE5_OVRD_REG0
union Pb0TxLane5OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal5: 1; // 0
		uint32 txDclkEnOvrdEn5: 1; // 1
		uint32 txDrvDataEnOvrdVal5: 1; // 2
		uint32 txDrvDataEnOvrdEn5: 1; // 3
		uint32 txDrvPwronOvrdVal5: 1; // 4
		uint32 txDrvPwronOvrdEn5: 1; // 5
		uint32 txFrontendPwronOvrdVal5: 1; // 6
		uint32 txFrontendPwronOvrdEn5: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE5_SCI_STAT_OVRD_REG0
union Pb0TxLane5SciStatOvrdReg0 {
	struct {
		uint32 txpwr5: 3; // 0
		uint32 incoherentck5: 1; // 3
		uint32 txmarg5: 3; // 4
		uint32 deemph5: 1; // 7
		uint32 coefficientid5: 2; // 8
		uint32 coefficient5: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE6_CTRL_REG0
union Pb0TxLane6CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode6: 1; // 0
		uint32 txCfgInvData6: 1; // 1
		uint32 txCfgSwingBoostEn6: 1; // 2
		uint32 txDbgPrbsEn6: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE6_OVRD_REG0
union Pb0TxLane6OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal6: 1; // 0
		uint32 txDclkEnOvrdEn6: 1; // 1
		uint32 txDrvDataEnOvrdVal6: 1; // 2
		uint32 txDrvDataEnOvrdEn6: 1; // 3
		uint32 txDrvPwronOvrdVal6: 1; // 4
		uint32 txDrvPwronOvrdEn6: 1; // 5
		uint32 txFrontendPwronOvrdVal6: 1; // 6
		uint32 txFrontendPwronOvrdEn6: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE6_SCI_STAT_OVRD_REG0
union Pb0TxLane6SciStatOvrdReg0 {
	struct {
		uint32 txpwr6: 3; // 0
		uint32 incoherentck6: 1; // 3
		uint32 txmarg6: 3; // 4
		uint32 deemph6: 1; // 7
		uint32 coefficientid6: 2; // 8
		uint32 coefficient6: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE7_CTRL_REG0
union Pb0TxLane7CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode7: 1; // 0
		uint32 txCfgInvData7: 1; // 1
		uint32 txCfgSwingBoostEn7: 1; // 2
		uint32 txDbgPrbsEn7: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE7_OVRD_REG0
union Pb0TxLane7OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal7: 1; // 0
		uint32 txDclkEnOvrdEn7: 1; // 1
		uint32 txDrvDataEnOvrdVal7: 1; // 2
		uint32 txDrvDataEnOvrdEn7: 1; // 3
		uint32 txDrvPwronOvrdVal7: 1; // 4
		uint32 txDrvPwronOvrdEn7: 1; // 5
		uint32 txFrontendPwronOvrdVal7: 1; // 6
		uint32 txFrontendPwronOvrdEn7: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE7_SCI_STAT_OVRD_REG0
union Pb0TxLane7SciStatOvrdReg0 {
	struct {
		uint32 txpwr7: 3; // 0
		uint32 incoherentck7: 1; // 3
		uint32 txmarg7: 3; // 4
		uint32 deemph7: 1; // 7
		uint32 coefficientid7: 2; // 8
		uint32 coefficient7: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE8_CTRL_REG0
union Pb0TxLane8CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode8: 1; // 0
		uint32 txCfgInvData8: 1; // 1
		uint32 txCfgSwingBoostEn8: 1; // 2
		uint32 txDbgPrbsEn8: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE8_OVRD_REG0
union Pb0TxLane8OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal8: 1; // 0
		uint32 txDclkEnOvrdEn8: 1; // 1
		uint32 txDrvDataEnOvrdVal8: 1; // 2
		uint32 txDrvDataEnOvrdEn8: 1; // 3
		uint32 txDrvPwronOvrdVal8: 1; // 4
		uint32 txDrvPwronOvrdEn8: 1; // 5
		uint32 txFrontendPwronOvrdVal8: 1; // 6
		uint32 txFrontendPwronOvrdEn8: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE8_SCI_STAT_OVRD_REG0
union Pb0TxLane8SciStatOvrdReg0 {
	struct {
		uint32 txpwr8: 3; // 0
		uint32 incoherentck8: 1; // 3
		uint32 txmarg8: 3; // 4
		uint32 deemph8: 1; // 7
		uint32 coefficientid8: 2; // 8
		uint32 coefficient8: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB0_TX_LANE9_CTRL_REG0
union Pb0TxLane9CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode9: 1; // 0
		uint32 txCfgInvData9: 1; // 1
		uint32 txCfgSwingBoostEn9: 1; // 2
		uint32 txDbgPrbsEn9: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB0_TX_LANE9_OVRD_REG0
union Pb0TxLane9OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal9: 1; // 0
		uint32 txDclkEnOvrdEn9: 1; // 1
		uint32 txDrvDataEnOvrdVal9: 1; // 2
		uint32 txDrvDataEnOvrdEn9: 1; // 3
		uint32 txDrvPwronOvrdVal9: 1; // 4
		uint32 txDrvPwronOvrdEn9: 1; // 5
		uint32 txFrontendPwronOvrdVal9: 1; // 6
		uint32 txFrontendPwronOvrdEn9: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB0_TX_LANE9_SCI_STAT_OVRD_REG0
union Pb0TxLane9SciStatOvrdReg0 {
	struct {
		uint32 txpwr9: 3; // 0
		uint32 incoherentck9: 1; // 3
		uint32 txmarg9: 3; // 4
		uint32 deemph9: 1; // 7
		uint32 coefficientid9: 2; // 8
		uint32 coefficient9: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_DFT_DEBUG_CTRL_REG0
union Pb1DftDebugCtrlReg0 {
	struct {
		uint32 dftPhyDebugEn: 1; // 0
		uint32 dftPhyDebugMode: 5; // 1
		uint32 unknown1: 26;
	};
	uint32 val;
};

// PB1_DFT_JIT_INJ_REG0
union Pb1DftJitInjReg0 {
	struct {
		uint32 dftNumSteps: 5; // 0
		uint32 unknown1: 3;
		uint32 dftClkPerStep: 4; // 8
		uint32 unknown2: 10;
		uint32 dftIncrSwpEn: 1; // 22
		uint32 dftDecrSwpEn: 1; // 23
		uint32 dftRecoveryTime: 8; // 24
	};
	uint32 val;
};

// PB1_DFT_JIT_INJ_REG1
union Pb1DftJitInjReg1 {
	struct {
		uint32 dftBypassValue: 8; // 0
		uint32 dftBypassEn: 1; // 8
		uint32 unknown1: 7;
		uint32 dftBlockEn: 1; // 16
		uint32 unknown2: 15;
	};
	uint32 val;
};

// PB1_DFT_JIT_INJ_REG2
union Pb1DftJitInjReg2 {
	struct {
		uint32 dftLaneEn: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_GLB_CTRL_REG0
union Pb1GlbCtrlReg0 {
	struct {
		uint32 backup: 16; // 0
		uint32 cfgIdledetTh: 2; // 16
		uint32 unknown1: 2;
		uint32 dbgRx2txbypSel: 3; // 20
		uint32 dbgRxfebypEn: 1; // 23
		uint32 dbgRxprbsClr: 1; // 24
		uint32 dbgRxtoggleEn: 1; // 25
		uint32 dbgTx2rxlbackEn: 1; // 26
		uint32 unknown2: 3;
		uint32 txcfgCmgoodRange: 2; // 30
	};
	uint32 val;
};

// PB1_GLB_CTRL_REG1
union Pb1GlbCtrlReg1 {
	struct {
		uint32 rxdbgCdrFrBypEn: 1; // 0
		uint32 rxdbgCdrFrBypVal: 6; // 1
		uint32 rxdbgCdrPhBypEn: 1; // 7
		uint32 rxdbgCdrPhBypVal: 6; // 8
		uint32 rxdbgD0thBypEn: 1; // 14
		uint32 rxdbgD0thBypVal: 7; // 15
		uint32 rxdbgD1thBypEn: 1; // 22
		uint32 rxdbgD1thBypVal: 7; // 23
		uint32 tstLospdtstEn: 1; // 30
		uint32 pllCfgDispclkDiv: 1; // 31
	};
	uint32 val;
};

// PB1_GLB_CTRL_REG2
union Pb1GlbCtrlReg2 {
	struct {
		uint32 rxdbgD2thBypEn: 1; // 0
		uint32 rxdbgD2thBypVal: 7; // 1
		uint32 rxdbgD3thBypEn: 1; // 8
		uint32 rxdbgD3thBypVal: 7; // 9
		uint32 rxdbgDxthBypEn: 1; // 16
		uint32 rxdbgDxthBypVal: 7; // 17
		uint32 rxdbgEthBypEn: 1; // 24
		uint32 rxdbgEthBypVal: 7; // 25
	};
	uint32 val;
};

// PB1_GLB_CTRL_REG3
union Pb1GlbCtrlReg3 {
	struct {
		uint32 rxdbgSel: 5; // 0
		uint32 bgCfgLcRegVref0Sel: 2; // 5
		uint32 bgCfgLcRegVref1Sel: 2; // 7
		uint32 bgCfgRoRegVrefSel: 2; // 9
		uint32 bgDbgVrefbypEn: 1; // 11
		uint32 bgDbgIrefbypEn: 1; // 12
		uint32 unknown1: 1;
		uint32 bgDbgAnalogSel: 3; // 14
		uint32 unknown2: 1;
		uint32 dbgDllClkSel: 3; // 18
		uint32 pllDispclkCmosSel: 1; // 21
		uint32 dbgRxpiOffsetBypEn: 1; // 22
		uint32 dbgRxpiOffsetBypVal: 4; // 23
		uint32 dbgRxswapdxBypEn: 1; // 27
		uint32 dbgRxswapdxBypVal: 3; // 28
		uint32 dbgRxleqDcattnBypOvrDisable: 1; // 31
	};
	uint32 val;
};

// PB1_GLB_CTRL_REG4
union Pb1GlbCtrlReg4 {
	struct {
		uint32 dbgRxapuInst: 16; // 0
		uint32 dbgRxdfemuxBypVal: 2; // 16
		uint32 dbgRxdfemuxBypEn: 1; // 18
		uint32 unknown1: 3;
		uint32 dbgRxapuExec: 4; // 22
		uint32 dbgRxdllVregRefSel: 1; // 26
		uint32 pwrgoodOvrd: 1; // 27
		uint32 dbgRxrdataGatingDisable: 1; // 28
		uint32 unknown2: 3;
	};
	uint32 val;
};

// PB1_GLB_CTRL_REG5
union Pb1GlbCtrlReg5 {
	struct {
		uint32 dbgRxapuMode: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_GLB_OVRD_REG0
union Pb1GlbOvrdReg0 {
	struct {
		uint32 txpdtermValOvrdVal: 16; // 0
		uint32 txputermValOvrdVal: 16; // 16
	};
	uint32 val;
};

// PB1_GLB_OVRD_REG1
union Pb1GlbOvrdReg1 {
	struct {
		uint32 txpdtermValOvrdEn: 1; // 0
		uint32 txputermValOvrdEn: 1; // 1
		uint32 tstLospdtstRstOvrdEn: 1; // 2
		uint32 tstLospdtstRstOvrdVal: 1; // 3
		uint32 unknown1: 11;
		uint32 rxtermValOvrdEn: 1; // 15
		uint32 rxtermValOvrdVal: 16; // 16
	};
	uint32 val;
};

// PB1_GLB_OVRD_REG2
union Pb1GlbOvrdReg2 {
	struct {
		uint32 bgPwronOvrdEn: 1; // 0
		uint32 bgPwronOvrdVal: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// PB1_GLB_SCI_STAT_OVRD_REG0
union Pb1GlbSciStatOvrdReg0 {
	struct {
		uint32 ignrAllSciUpdtL0t3: 1; // 0
		uint32 ignrAllSciUpdtL4t7: 1; // 1
		uint32 ignrAllSciUpdtL8t11: 1; // 2
		uint32 ignrAllSciUpdtL12t15: 1; // 3
		uint32 ignrImpcalActiveSciUpdt: 1; // 4
		uint32 unknown1: 3;
		uint32 txnimp: 4; // 8
		uint32 txpimp: 4; // 12
		uint32 rximp: 4; // 16
		uint32 impcalActive: 1; // 20
		uint32 unknown2: 11;
	};
	uint32 val;
};

// PB1_GLB_SCI_STAT_OVRD_REG1
union Pb1GlbSciStatOvrdReg1 {
	struct {
		uint32 ignrModeSciUpdtL0t3: 1; // 0
		uint32 ignrFreqdivSciUpdtL0t3: 1; // 1
		uint32 ignrDllLockSciUpdtL0t3: 1; // 2
		uint32 unknown1: 9;
		uint32 dllLock0: 1; // 12
		uint32 dllLock1: 1; // 13
		uint32 dllLock2: 1; // 14
		uint32 dllLock3: 1; // 15
		uint32 mode0: 2; // 16
		uint32 freqdiv0: 2; // 18
		uint32 mode1: 2; // 20
		uint32 freqdiv1: 2; // 22
		uint32 mode2: 2; // 24
		uint32 freqdiv2: 2; // 26
		uint32 mode3: 2; // 28
		uint32 freqdiv3: 2; // 30
	};
	uint32 val;
};

// PB1_GLB_SCI_STAT_OVRD_REG2
union Pb1GlbSciStatOvrdReg2 {
	struct {
		uint32 ignrModeSciUpdtL4t7: 1; // 0
		uint32 ignrFreqdivSciUpdtL4t7: 1; // 1
		uint32 ignrDllLockSciUpdtL4t7: 1; // 2
		uint32 unknown1: 9;
		uint32 dllLock4: 1; // 12
		uint32 dllLock5: 1; // 13
		uint32 dllLock6: 1; // 14
		uint32 dllLock7: 1; // 15
		uint32 mode4: 2; // 16
		uint32 freqdiv4: 2; // 18
		uint32 mode5: 2; // 20
		uint32 freqdiv5: 2; // 22
		uint32 mode6: 2; // 24
		uint32 freqdiv6: 2; // 26
		uint32 mode7: 2; // 28
		uint32 freqdiv7: 2; // 30
	};
	uint32 val;
};

// PB1_GLB_SCI_STAT_OVRD_REG3
union Pb1GlbSciStatOvrdReg3 {
	struct {
		uint32 ignrModeSciUpdtL8t11: 1; // 0
		uint32 ignrFreqdivSciUpdtL8t11: 1; // 1
		uint32 ignrDllLockSciUpdtL8t11: 1; // 2
		uint32 unknown1: 9;
		uint32 dllLock8: 1; // 12
		uint32 dllLock9: 1; // 13
		uint32 dllLock10: 1; // 14
		uint32 dllLock11: 1; // 15
		uint32 mode8: 2; // 16
		uint32 freqdiv8: 2; // 18
		uint32 mode9: 2; // 20
		uint32 freqdiv9: 2; // 22
		uint32 mode10: 2; // 24
		uint32 freqdiv10: 2; // 26
		uint32 mode11: 2; // 28
		uint32 freqdiv11: 2; // 30
	};
	uint32 val;
};

// PB1_GLB_SCI_STAT_OVRD_REG4
union Pb1GlbSciStatOvrdReg4 {
	struct {
		uint32 ignrModeSciUpdtL12t15: 1; // 0
		uint32 ignrFreqdivSciUpdtL12t15: 1; // 1
		uint32 ignrDllLockSciUpdtL12t15: 1; // 2
		uint32 unknown1: 9;
		uint32 dllLock12: 1; // 12
		uint32 dllLock13: 1; // 13
		uint32 dllLock14: 1; // 14
		uint32 dllLock15: 1; // 15
		uint32 mode12: 2; // 16
		uint32 freqdiv12: 2; // 18
		uint32 mode13: 2; // 20
		uint32 freqdiv13: 2; // 22
		uint32 mode14: 2; // 24
		uint32 freqdiv14: 2; // 26
		uint32 mode15: 2; // 28
		uint32 freqdiv15: 2; // 30
	};
	uint32 val;
};

// PB1_HW_DEBUG
union Pb1HwDebug {
	struct {
		uint32 pb1Hw00Debug: 1; // 0
		uint32 pb1Hw01Debug: 1; // 1
		uint32 pb1Hw02Debug: 1; // 2
		uint32 pb1Hw03Debug: 1; // 3
		uint32 pb1Hw04Debug: 1; // 4
		uint32 pb1Hw05Debug: 1; // 5
		uint32 pb1Hw06Debug: 1; // 6
		uint32 pb1Hw07Debug: 1; // 7
		uint32 pb1Hw08Debug: 1; // 8
		uint32 pb1Hw09Debug: 1; // 9
		uint32 pb1Hw10Debug: 1; // 10
		uint32 pb1Hw11Debug: 1; // 11
		uint32 pb1Hw12Debug: 1; // 12
		uint32 pb1Hw13Debug: 1; // 13
		uint32 pb1Hw14Debug: 1; // 14
		uint32 pb1Hw15Debug: 1; // 15
		uint32 pb1Hw16Debug: 1; // 16
		uint32 pb1Hw17Debug: 1; // 17
		uint32 pb1Hw18Debug: 1; // 18
		uint32 pb1Hw19Debug: 1; // 19
		uint32 pb1Hw20Debug: 1; // 20
		uint32 pb1Hw21Debug: 1; // 21
		uint32 pb1Hw22Debug: 1; // 22
		uint32 pb1Hw23Debug: 1; // 23
		uint32 pb1Hw24Debug: 1; // 24
		uint32 pb1Hw25Debug: 1; // 25
		uint32 pb1Hw26Debug: 1; // 26
		uint32 pb1Hw27Debug: 1; // 27
		uint32 pb1Hw28Debug: 1; // 28
		uint32 pb1Hw29Debug: 1; // 29
		uint32 pb1Hw30Debug: 1; // 30
		uint32 pb1Hw31Debug: 1; // 31
	};
	uint32 val;
};

// PB1_PIF_CNTL
union Pb1PifCntl {
	struct {
		uint32 serialCfgEnable: 1; // 0
		uint32 daFifoReset0: 1; // 1
		uint32 phyCrEnMode: 1; // 2
		uint32 phycmdCrEnMode: 1; // 3
		uint32 eiDetCycleMode: 1; // 4
		uint32 daFifoReset1: 1; // 5
		uint32 rxdetectFifoResetMode: 1; // 6
		uint32 rxdetectTxPwrMode: 1; // 7
		uint32 divinitMode: 1; // 8
		uint32 daFifoReset2: 1; // 9
		uint32 pllBindingEnable: 1; // 10
		uint32 scCalibDoneCntl: 1; // 11
		uint32 unknown1: 1;
		uint32 daFifoReset3: 1; // 13
		uint32 unknown2: 2;
		uint32 txgndTime: 1; // 16
		uint32 ls2ExitTime: 3; // 17
		uint32 eiCycleOffTime: 3; // 20
		uint32 exitL0sInitDis: 1; // 23
		uint32 rxenGater: 4; // 24
		uint32 extendWaitForRampup: 1; // 28
		uint32 ignoreTxdatavalidEpDis: 1; // 29
		uint32 unknown3: 2;
	};
	uint32 val;
};

// PB1_PIF_CNTL2
union Pb1PifCntl2 {
	struct {
		uint32 unknown1: 1;
		uint32 rxdetectSamplTime: 2; // 1
		uint32 unknown2: 4;
		uint32 rxdetectOverrideEn: 1; // 7
		uint32 rxdetectOverrideVal0: 1; // 8
		uint32 rxdetectOverrideVal1: 1; // 9
		uint32 rxdetectOverrideVal2: 1; // 10
		uint32 rxdetectOverrideVal3: 1; // 11
		uint32 rxdetectOverrideVal4: 1; // 12
		uint32 rxdetectOverrideVal5: 1; // 13
		uint32 rxdetectOverrideVal6: 1; // 14
		uint32 rxdetectOverrideVal7: 1; // 15
		uint32 rxdetectOverrideVal8: 1; // 16
		uint32 rxdetectOverrideVal9: 1; // 17
		uint32 rxdetectOverrideVal10: 1; // 18
		uint32 rxdetectOverrideVal11: 1; // 19
		uint32 rxdetectOverrideVal12: 1; // 20
		uint32 rxdetectOverrideVal13: 1; // 21
		uint32 rxdetectOverrideVal14: 1; // 22
		uint32 rxdetectOverrideVal15: 1; // 23
		uint32 rxphystatusDelay: 3; // 24
		uint32 unknown3: 5;
	};
	uint32 val;
};

// PB1_PIF_HW_DEBUG
union Pb1PifHwDebug {
	struct {
		uint32 pb1PifHw00Debug: 1; // 0
		uint32 pb1PifHw01Debug: 1; // 1
		uint32 pb1PifHw02Debug: 1; // 2
		uint32 pb1PifHw03Debug: 1; // 3
		uint32 pb1PifHw04Debug: 1; // 4
		uint32 pb1PifHw05Debug: 1; // 5
		uint32 pb1PifHw06Debug: 1; // 6
		uint32 pb1PifHw07Debug: 1; // 7
		uint32 pb1PifHw08Debug: 1; // 8
		uint32 pb1PifHw09Debug: 1; // 9
		uint32 pb1PifHw10Debug: 1; // 10
		uint32 pb1PifHw11Debug: 1; // 11
		uint32 pb1PifHw12Debug: 1; // 12
		uint32 pb1PifHw13Debug: 1; // 13
		uint32 pb1PifHw14Debug: 1; // 14
		uint32 pb1PifHw15Debug: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_PIF_PAIRING
union Pb1PifPairing {
	struct {
		uint32 x2Lane1_0: 1; // 0
		uint32 x2Lane3_2: 1; // 1
		uint32 x2Lane5_4: 1; // 2
		uint32 x2Lane7_6: 1; // 3
		uint32 x2Lane9_8: 1; // 4
		uint32 x2Lane11_10: 1; // 5
		uint32 x2Lane13_12: 1; // 6
		uint32 x2Lane15_14: 1; // 7
		uint32 x4Lane3_0: 1; // 8
		uint32 x4Lane7_4: 1; // 9
		uint32 x4Lane11_8: 1; // 10
		uint32 x4Lane15_12: 1; // 11
		uint32 unknown1: 4;
		uint32 x8Lane7_0: 1; // 16
		uint32 x8Lane15_8: 1; // 17
		uint32 unknown2: 2;
		uint32 x16Lane15_0: 1; // 20
		uint32 unknown3: 4;
		uint32 multiPif: 1; // 25
		uint32 unknown4: 6;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_0
union Pb1PifPdnbOverride0 {
	struct {
		uint32 txPdnbOverrideEn0: 1; // 0
		uint32 txPdnbOverrideVal0: 3; // 1
		uint32 rxPdnbOverrideEn0: 1; // 4
		uint32 rxPdnbOverrideVal0: 3; // 5
		uint32 rxenOverrideEn0: 1; // 8
		uint32 rxenOverrideVal0: 1; // 9
		uint32 txpwrOverrideEn0: 1; // 10
		uint32 txpwrOverrideVal0: 3; // 11
		uint32 rxpwrOverrideEn0: 1; // 14
		uint32 rxpwrOverrideVal0: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_1
union Pb1PifPdnbOverride1 {
	struct {
		uint32 txPdnbOverrideEn1: 1; // 0
		uint32 txPdnbOverrideVal1: 3; // 1
		uint32 rxPdnbOverrideEn1: 1; // 4
		uint32 rxPdnbOverrideVal1: 3; // 5
		uint32 rxenOverrideEn1: 1; // 8
		uint32 rxenOverrideVal1: 1; // 9
		uint32 txpwrOverrideEn1: 1; // 10
		uint32 txpwrOverrideVal1: 3; // 11
		uint32 rxpwrOverrideEn1: 1; // 14
		uint32 rxpwrOverrideVal1: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_10
union Pb1PifPdnbOverride10 {
	struct {
		uint32 txPdnbOverrideEn10: 1; // 0
		uint32 txPdnbOverrideVal10: 3; // 1
		uint32 rxPdnbOverrideEn10: 1; // 4
		uint32 rxPdnbOverrideVal10: 3; // 5
		uint32 rxenOverrideEn10: 1; // 8
		uint32 rxenOverrideVal10: 1; // 9
		uint32 txpwrOverrideEn10: 1; // 10
		uint32 txpwrOverrideVal10: 3; // 11
		uint32 rxpwrOverrideEn10: 1; // 14
		uint32 rxpwrOverrideVal10: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_11
union Pb1PifPdnbOverride11 {
	struct {
		uint32 txPdnbOverrideEn11: 1; // 0
		uint32 txPdnbOverrideVal11: 3; // 1
		uint32 rxPdnbOverrideEn11: 1; // 4
		uint32 rxPdnbOverrideVal11: 3; // 5
		uint32 rxenOverrideEn11: 1; // 8
		uint32 rxenOverrideVal11: 1; // 9
		uint32 txpwrOverrideEn11: 1; // 10
		uint32 txpwrOverrideVal11: 3; // 11
		uint32 rxpwrOverrideEn11: 1; // 14
		uint32 rxpwrOverrideVal11: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_12
union Pb1PifPdnbOverride12 {
	struct {
		uint32 txPdnbOverrideEn12: 1; // 0
		uint32 txPdnbOverrideVal12: 3; // 1
		uint32 rxPdnbOverrideEn12: 1; // 4
		uint32 rxPdnbOverrideVal12: 3; // 5
		uint32 rxenOverrideEn12: 1; // 8
		uint32 rxenOverrideVal12: 1; // 9
		uint32 txpwrOverrideEn12: 1; // 10
		uint32 txpwrOverrideVal12: 3; // 11
		uint32 rxpwrOverrideEn12: 1; // 14
		uint32 rxpwrOverrideVal12: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_13
union Pb1PifPdnbOverride13 {
	struct {
		uint32 txPdnbOverrideEn13: 1; // 0
		uint32 txPdnbOverrideVal13: 3; // 1
		uint32 rxPdnbOverrideEn13: 1; // 4
		uint32 rxPdnbOverrideVal13: 3; // 5
		uint32 rxenOverrideEn13: 1; // 8
		uint32 rxenOverrideVal13: 1; // 9
		uint32 txpwrOverrideEn13: 1; // 10
		uint32 txpwrOverrideVal13: 3; // 11
		uint32 rxpwrOverrideEn13: 1; // 14
		uint32 rxpwrOverrideVal13: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_14
union Pb1PifPdnbOverride14 {
	struct {
		uint32 txPdnbOverrideEn14: 1; // 0
		uint32 txPdnbOverrideVal14: 3; // 1
		uint32 rxPdnbOverrideEn14: 1; // 4
		uint32 rxPdnbOverrideVal14: 3; // 5
		uint32 rxenOverrideEn14: 1; // 8
		uint32 rxenOverrideVal14: 1; // 9
		uint32 txpwrOverrideEn14: 1; // 10
		uint32 txpwrOverrideVal14: 3; // 11
		uint32 rxpwrOverrideEn14: 1; // 14
		uint32 rxpwrOverrideVal14: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_15
union Pb1PifPdnbOverride15 {
	struct {
		uint32 txPdnbOverrideEn15: 1; // 0
		uint32 txPdnbOverrideVal15: 3; // 1
		uint32 rxPdnbOverrideEn15: 1; // 4
		uint32 rxPdnbOverrideVal15: 3; // 5
		uint32 rxenOverrideEn15: 1; // 8
		uint32 rxenOverrideVal15: 1; // 9
		uint32 txpwrOverrideEn15: 1; // 10
		uint32 txpwrOverrideVal15: 3; // 11
		uint32 rxpwrOverrideEn15: 1; // 14
		uint32 rxpwrOverrideVal15: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_2
union Pb1PifPdnbOverride2 {
	struct {
		uint32 txPdnbOverrideEn2: 1; // 0
		uint32 txPdnbOverrideVal2: 3; // 1
		uint32 rxPdnbOverrideEn2: 1; // 4
		uint32 rxPdnbOverrideVal2: 3; // 5
		uint32 rxenOverrideEn2: 1; // 8
		uint32 rxenOverrideVal2: 1; // 9
		uint32 txpwrOverrideEn2: 1; // 10
		uint32 txpwrOverrideVal2: 3; // 11
		uint32 rxpwrOverrideEn2: 1; // 14
		uint32 rxpwrOverrideVal2: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_3
union Pb1PifPdnbOverride3 {
	struct {
		uint32 txPdnbOverrideEn3: 1; // 0
		uint32 txPdnbOverrideVal3: 3; // 1
		uint32 rxPdnbOverrideEn3: 1; // 4
		uint32 rxPdnbOverrideVal3: 3; // 5
		uint32 rxenOverrideEn3: 1; // 8
		uint32 rxenOverrideVal3: 1; // 9
		uint32 txpwrOverrideEn3: 1; // 10
		uint32 txpwrOverrideVal3: 3; // 11
		uint32 rxpwrOverrideEn3: 1; // 14
		uint32 rxpwrOverrideVal3: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_4
union Pb1PifPdnbOverride4 {
	struct {
		uint32 txPdnbOverrideEn4: 1; // 0
		uint32 txPdnbOverrideVal4: 3; // 1
		uint32 rxPdnbOverrideEn4: 1; // 4
		uint32 rxPdnbOverrideVal4: 3; // 5
		uint32 rxenOverrideEn4: 1; // 8
		uint32 rxenOverrideVal4: 1; // 9
		uint32 txpwrOverrideEn4: 1; // 10
		uint32 txpwrOverrideVal4: 3; // 11
		uint32 rxpwrOverrideEn4: 1; // 14
		uint32 rxpwrOverrideVal4: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_5
union Pb1PifPdnbOverride5 {
	struct {
		uint32 txPdnbOverrideEn5: 1; // 0
		uint32 txPdnbOverrideVal5: 3; // 1
		uint32 rxPdnbOverrideEn5: 1; // 4
		uint32 rxPdnbOverrideVal5: 3; // 5
		uint32 rxenOverrideEn5: 1; // 8
		uint32 rxenOverrideVal5: 1; // 9
		uint32 txpwrOverrideEn5: 1; // 10
		uint32 txpwrOverrideVal5: 3; // 11
		uint32 rxpwrOverrideEn5: 1; // 14
		uint32 rxpwrOverrideVal5: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_6
union Pb1PifPdnbOverride6 {
	struct {
		uint32 txPdnbOverrideEn6: 1; // 0
		uint32 txPdnbOverrideVal6: 3; // 1
		uint32 rxPdnbOverrideEn6: 1; // 4
		uint32 rxPdnbOverrideVal6: 3; // 5
		uint32 rxenOverrideEn6: 1; // 8
		uint32 rxenOverrideVal6: 1; // 9
		uint32 txpwrOverrideEn6: 1; // 10
		uint32 txpwrOverrideVal6: 3; // 11
		uint32 rxpwrOverrideEn6: 1; // 14
		uint32 rxpwrOverrideVal6: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_7
union Pb1PifPdnbOverride7 {
	struct {
		uint32 txPdnbOverrideEn7: 1; // 0
		uint32 txPdnbOverrideVal7: 3; // 1
		uint32 rxPdnbOverrideEn7: 1; // 4
		uint32 rxPdnbOverrideVal7: 3; // 5
		uint32 rxenOverrideEn7: 1; // 8
		uint32 rxenOverrideVal7: 1; // 9
		uint32 txpwrOverrideEn7: 1; // 10
		uint32 txpwrOverrideVal7: 3; // 11
		uint32 rxpwrOverrideEn7: 1; // 14
		uint32 rxpwrOverrideVal7: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_8
union Pb1PifPdnbOverride8 {
	struct {
		uint32 txPdnbOverrideEn8: 1; // 0
		uint32 txPdnbOverrideVal8: 3; // 1
		uint32 rxPdnbOverrideEn8: 1; // 4
		uint32 rxPdnbOverrideVal8: 3; // 5
		uint32 rxenOverrideEn8: 1; // 8
		uint32 rxenOverrideVal8: 1; // 9
		uint32 txpwrOverrideEn8: 1; // 10
		uint32 txpwrOverrideVal8: 3; // 11
		uint32 rxpwrOverrideEn8: 1; // 14
		uint32 rxpwrOverrideVal8: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PDNB_OVERRIDE_9
union Pb1PifPdnbOverride9 {
	struct {
		uint32 txPdnbOverrideEn9: 1; // 0
		uint32 txPdnbOverrideVal9: 3; // 1
		uint32 rxPdnbOverrideEn9: 1; // 4
		uint32 rxPdnbOverrideVal9: 3; // 5
		uint32 rxenOverrideEn9: 1; // 8
		uint32 rxenOverrideVal9: 1; // 9
		uint32 txpwrOverrideEn9: 1; // 10
		uint32 txpwrOverrideVal9: 3; // 11
		uint32 rxpwrOverrideEn9: 1; // 14
		uint32 rxpwrOverrideVal9: 3; // 15
		uint32 unknown1: 14;
	};
	uint32 val;
};

// PB1_PIF_PWRDOWN_0
union Pb1PifPwrdown0 {
	struct {
		uint32 txPowerStateInTxs2_0: 3; // 0
		uint32 forceRxenInL0s0: 1; // 3
		uint32 rxPowerStateInRxs2_0: 3; // 4
		uint32 pllPowerStateInTxs2_0: 3; // 7
		uint32 pllPowerStateInOff0: 3; // 10
		uint32 unknown1: 3;
		uint32 tx2p5clkClockGatingEn0: 1; // 16
		uint32 unknown2: 7;
		uint32 pllRampUpTime0: 3; // 24
		uint32 unknown3: 1;
		uint32 pllpwrOverrideEn0: 1; // 28
		uint32 pllpwrOverrideVal0: 3; // 29
	};
	uint32 val;
};

// PB1_PIF_PWRDOWN_1
union Pb1PifPwrdown1 {
	struct {
		uint32 txPowerStateInTxs2_1: 3; // 0
		uint32 forceRxenInL0s1: 1; // 3
		uint32 rxPowerStateInRxs2_1: 3; // 4
		uint32 pllPowerStateInTxs2_1: 3; // 7
		uint32 pllPowerStateInOff1: 3; // 10
		uint32 unknown1: 3;
		uint32 tx2p5clkClockGatingEn1: 1; // 16
		uint32 unknown2: 7;
		uint32 pllRampUpTime1: 3; // 24
		uint32 unknown3: 1;
		uint32 pllpwrOverrideEn1: 1; // 28
		uint32 pllpwrOverrideVal1: 3; // 29
	};
	uint32 val;
};

// PB1_PIF_PWRDOWN_2
union Pb1PifPwrdown2 {
	struct {
		uint32 txPowerStateInTxs2_2: 3; // 0
		uint32 forceRxenInL0s2: 1; // 3
		uint32 rxPowerStateInRxs2_2: 3; // 4
		uint32 pllPowerStateInTxs2_2: 3; // 7
		uint32 pllPowerStateInOff2: 3; // 10
		uint32 unknown1: 3;
		uint32 tx2p5clkClockGatingEn2: 1; // 16
		uint32 unknown2: 7;
		uint32 pllRampUpTime2: 3; // 24
		uint32 unknown3: 1;
		uint32 pllpwrOverrideEn2: 1; // 28
		uint32 pllpwrOverrideVal2: 3; // 29
	};
	uint32 val;
};

// PB1_PIF_PWRDOWN_3
union Pb1PifPwrdown3 {
	struct {
		uint32 txPowerStateInTxs2_3: 3; // 0
		uint32 forceRxenInL0s3: 1; // 3
		uint32 rxPowerStateInRxs2_3: 3; // 4
		uint32 pllPowerStateInTxs2_3: 3; // 7
		uint32 pllPowerStateInOff3: 3; // 10
		uint32 unknown1: 3;
		uint32 tx2p5clkClockGatingEn3: 1; // 16
		uint32 unknown2: 7;
		uint32 pllRampUpTime3: 3; // 24
		uint32 unknown3: 1;
		uint32 pllpwrOverrideEn3: 1; // 28
		uint32 pllpwrOverrideVal3: 3; // 29
	};
	uint32 val;
};

// PB1_PIF_SCRATCH
union Pb1PifScratch {
	struct {
		uint32 pifScratch: 32; // 0
	};
	uint32 val;
};

// PB1_PIF_SC_CTL
union Pb1PifScCtl {
	struct {
		uint32 scCalibration: 1; // 0
		uint32 scRxdetect: 1; // 1
		uint32 scExitL1ToL0s: 1; // 2
		uint32 scExitL1ToL0: 1; // 3
		uint32 scEnterL1FromL0s: 1; // 4
		uint32 scEnterL1FromL0: 1; // 5
		uint32 scSpeedChange: 1; // 6
		uint32 unknown1: 1;
		uint32 scPhase1: 1; // 8
		uint32 scPhase2: 1; // 9
		uint32 scPhase3: 1; // 10
		uint32 scPhase4: 1; // 11
		uint32 scPhase5: 1; // 12
		uint32 scPhase6: 1; // 13
		uint32 scPhase7: 1; // 14
		uint32 scPhase8: 1; // 15
		uint32 scLane0Resume: 1; // 16
		uint32 scLane1Resume: 1; // 17
		uint32 scLane2Resume: 1; // 18
		uint32 scLane3Resume: 1; // 19
		uint32 scLane4Resume: 1; // 20
		uint32 scLane5Resume: 1; // 21
		uint32 scLane6Resume: 1; // 22
		uint32 scLane7Resume: 1; // 23
		uint32 scLane8Resume: 1; // 24
		uint32 scLane9Resume: 1; // 25
		uint32 scLane10Resume: 1; // 26
		uint32 scLane11Resume: 1; // 27
		uint32 scLane12Resume: 1; // 28
		uint32 scLane13Resume: 1; // 29
		uint32 scLane14Resume: 1; // 30
		uint32 scLane15Resume: 1; // 31
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_0
union Pb1PifSeqStatus0 {
	struct {
		uint32 seqCalibration0: 1; // 0
		uint32 seqRxdetect0: 1; // 1
		uint32 seqExitL1ToL0s0: 1; // 2
		uint32 seqExitL1ToL0_0: 1; // 3
		uint32 seqEnterL1FromL0s0: 1; // 4
		uint32 seqEnterL1FromL0_0: 1; // 5
		uint32 seqSpeedChange0: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase0: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_1
union Pb1PifSeqStatus1 {
	struct {
		uint32 seqCalibration1: 1; // 0
		uint32 seqRxdetect1: 1; // 1
		uint32 seqExitL1ToL0s1: 1; // 2
		uint32 seqExitL1ToL0_1: 1; // 3
		uint32 seqEnterL1FromL0s1: 1; // 4
		uint32 seqEnterL1FromL0_1: 1; // 5
		uint32 seqSpeedChange1: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase1: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_10
union Pb1PifSeqStatus10 {
	struct {
		uint32 seqCalibration10: 1; // 0
		uint32 seqRxdetect10: 1; // 1
		uint32 seqExitL1ToL0s10: 1; // 2
		uint32 seqExitL1ToL0_10: 1; // 3
		uint32 seqEnterL1FromL0s10: 1; // 4
		uint32 seqEnterL1FromL0_10: 1; // 5
		uint32 seqSpeedChange10: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase10: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_11
union Pb1PifSeqStatus11 {
	struct {
		uint32 seqCalibration11: 1; // 0
		uint32 seqRxdetect11: 1; // 1
		uint32 seqExitL1ToL0s11: 1; // 2
		uint32 seqExitL1ToL0_11: 1; // 3
		uint32 seqEnterL1FromL0s11: 1; // 4
		uint32 seqEnterL1FromL0_11: 1; // 5
		uint32 seqSpeedChange11: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase11: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_12
union Pb1PifSeqStatus12 {
	struct {
		uint32 seqCalibration12: 1; // 0
		uint32 seqRxdetect12: 1; // 1
		uint32 seqExitL1ToL0s12: 1; // 2
		uint32 seqExitL1ToL0_12: 1; // 3
		uint32 seqEnterL1FromL0s12: 1; // 4
		uint32 seqEnterL1FromL0_12: 1; // 5
		uint32 seqSpeedChange12: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase12: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_13
union Pb1PifSeqStatus13 {
	struct {
		uint32 seqCalibration13: 1; // 0
		uint32 seqRxdetect13: 1; // 1
		uint32 seqExitL1ToL0s13: 1; // 2
		uint32 seqExitL1ToL0_13: 1; // 3
		uint32 seqEnterL1FromL0s13: 1; // 4
		uint32 seqEnterL1FromL0_13: 1; // 5
		uint32 seqSpeedChange13: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase13: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_14
union Pb1PifSeqStatus14 {
	struct {
		uint32 seqCalibration14: 1; // 0
		uint32 seqRxdetect14: 1; // 1
		uint32 seqExitL1ToL0s14: 1; // 2
		uint32 seqExitL1ToL0_14: 1; // 3
		uint32 seqEnterL1FromL0s14: 1; // 4
		uint32 seqEnterL1FromL0_14: 1; // 5
		uint32 seqSpeedChange14: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase14: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_15
union Pb1PifSeqStatus15 {
	struct {
		uint32 seqCalibration15: 1; // 0
		uint32 seqRxdetect15: 1; // 1
		uint32 seqExitL1ToL0s15: 1; // 2
		uint32 seqExitL1ToL0_15: 1; // 3
		uint32 seqEnterL1FromL0s15: 1; // 4
		uint32 seqEnterL1FromL0_15: 1; // 5
		uint32 seqSpeedChange15: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase15: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_2
union Pb1PifSeqStatus2 {
	struct {
		uint32 seqCalibration2: 1; // 0
		uint32 seqRxdetect2: 1; // 1
		uint32 seqExitL1ToL0s2: 1; // 2
		uint32 seqExitL1ToL0_2: 1; // 3
		uint32 seqEnterL1FromL0s2: 1; // 4
		uint32 seqEnterL1FromL0_2: 1; // 5
		uint32 seqSpeedChange2: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase2: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_3
union Pb1PifSeqStatus3 {
	struct {
		uint32 seqCalibration3: 1; // 0
		uint32 seqRxdetect3: 1; // 1
		uint32 seqExitL1ToL0s3: 1; // 2
		uint32 seqExitL1ToL0_3: 1; // 3
		uint32 seqEnterL1FromL0s3: 1; // 4
		uint32 seqEnterL1FromL0_3: 1; // 5
		uint32 seqSpeedChange3: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase3: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_4
union Pb1PifSeqStatus4 {
	struct {
		uint32 seqCalibration4: 1; // 0
		uint32 seqRxdetect4: 1; // 1
		uint32 seqExitL1ToL0s4: 1; // 2
		uint32 seqExitL1ToL0_4: 1; // 3
		uint32 seqEnterL1FromL0s4: 1; // 4
		uint32 seqEnterL1FromL0_4: 1; // 5
		uint32 seqSpeedChange4: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase4: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_5
union Pb1PifSeqStatus5 {
	struct {
		uint32 seqCalibration5: 1; // 0
		uint32 seqRxdetect5: 1; // 1
		uint32 seqExitL1ToL0s5: 1; // 2
		uint32 seqExitL1ToL0_5: 1; // 3
		uint32 seqEnterL1FromL0s5: 1; // 4
		uint32 seqEnterL1FromL0_5: 1; // 5
		uint32 seqSpeedChange5: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase5: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_6
union Pb1PifSeqStatus6 {
	struct {
		uint32 seqCalibration6: 1; // 0
		uint32 seqRxdetect6: 1; // 1
		uint32 seqExitL1ToL0s6: 1; // 2
		uint32 seqExitL1ToL0_6: 1; // 3
		uint32 seqEnterL1FromL0s6: 1; // 4
		uint32 seqEnterL1FromL0_6: 1; // 5
		uint32 seqSpeedChange6: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase6: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_7
union Pb1PifSeqStatus7 {
	struct {
		uint32 seqCalibration7: 1; // 0
		uint32 seqRxdetect7: 1; // 1
		uint32 seqExitL1ToL0s7: 1; // 2
		uint32 seqExitL1ToL0_7: 1; // 3
		uint32 seqEnterL1FromL0s7: 1; // 4
		uint32 seqEnterL1FromL0_7: 1; // 5
		uint32 seqSpeedChange7: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase7: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_8
union Pb1PifSeqStatus8 {
	struct {
		uint32 seqCalibration8: 1; // 0
		uint32 seqRxdetect8: 1; // 1
		uint32 seqExitL1ToL0s8: 1; // 2
		uint32 seqExitL1ToL0_8: 1; // 3
		uint32 seqEnterL1FromL0s8: 1; // 4
		uint32 seqEnterL1FromL0_8: 1; // 5
		uint32 seqSpeedChange8: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase8: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_SEQ_STATUS_9
union Pb1PifSeqStatus9 {
	struct {
		uint32 seqCalibration9: 1; // 0
		uint32 seqRxdetect9: 1; // 1
		uint32 seqExitL1ToL0s9: 1; // 2
		uint32 seqExitL1ToL0_9: 1; // 3
		uint32 seqEnterL1FromL0s9: 1; // 4
		uint32 seqEnterL1FromL0_9: 1; // 5
		uint32 seqSpeedChange9: 1; // 6
		uint32 unknown1: 1;
		uint32 seqPhase9: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// PB1_PIF_TXPHYSTATUS
union Pb1PifTxphystatus {
	struct {
		uint32 txphystatus0: 1; // 0
		uint32 txphystatus1: 1; // 1
		uint32 txphystatus2: 1; // 2
		uint32 txphystatus3: 1; // 3
		uint32 txphystatus4: 1; // 4
		uint32 txphystatus5: 1; // 5
		uint32 txphystatus6: 1; // 6
		uint32 txphystatus7: 1; // 7
		uint32 txphystatus8: 1; // 8
		uint32 txphystatus9: 1; // 9
		uint32 txphystatus10: 1; // 10
		uint32 txphystatus11: 1; // 11
		uint32 txphystatus12: 1; // 12
		uint32 txphystatus13: 1; // 13
		uint32 txphystatus14: 1; // 14
		uint32 txphystatus15: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_PLL_LC0_CTRL_REG0
union Pb1PllLc0CtrlReg0 {
	struct {
		uint32 pllDbgLcAnalogSel0: 2; // 0
		uint32 pllDbgLcExtResetEn0: 1; // 2
		uint32 pllDbgLcVctlAdcEn0: 1; // 3
		uint32 pllTstLcUsampleEn0: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// PB1_PLL_LC0_OVRD_REG0
union Pb1PllLc0OvrdReg0 {
	struct {
		uint32 pllCfgLcBwCntrlOvrdVal0: 3; // 0
		uint32 pllCfgLcBwCntrlOvrdEn0: 1; // 3
		uint32 pllCfgLcCoreclkDivOvrdVal0: 3; // 4
		uint32 pllCfgLcCoreclkDivOvrdEn0: 1; // 7
		uint32 pllCfgLcCoreclkEnOvrdVal0: 1; // 8
		uint32 pllCfgLcCoreclkEnOvrdEn0: 1; // 9
		uint32 pllCfgLcFbdivOvrdVal0: 8; // 10
		uint32 pllCfgLcFbdivOvrdEn0: 1; // 18
		uint32 pllCfgLcLfCntrlOvrdVal0: 9; // 19
		uint32 pllCfgLcLfCntrlOvrdEn0: 1; // 28
		uint32 pllCfgLcRefdivOvrdVal0: 2; // 29
		uint32 pllCfgLcRefdivOvrdEn0: 1; // 31
	};
	uint32 val;
};

// PB1_PLL_LC0_OVRD_REG1
union Pb1PllLc0OvrdReg1 {
	struct {
		uint32 pllCfgLcRefclkSrcOvrdVal0: 3; // 0
		uint32 pllCfgLcRefclkSrcOvrdEn0: 1; // 3
		uint32 pllLcHsclkLeftEnOvrdVal0: 1; // 4
		uint32 pllLcHsclkLeftEnOvrdEn0: 1; // 5
		uint32 pllLcHsclkRightEnOvrdVal0: 1; // 6
		uint32 pllLcHsclkRightEnOvrdEn0: 1; // 7
		uint32 pllLcPwronOvrdVal0: 1; // 8
		uint32 pllLcPwronOvrdEn0: 1; // 9
		uint32 unknown1: 4;
		uint32 pllCfgLcVcoTuneOvrdVal0: 4; // 14
		uint32 pllCfgLcVcoTuneOvrdEn0: 1; // 18
		uint32 unknown2: 13;
	};
	uint32 val;
};

// PB1_PLL_LC0_SCI_STAT_OVRD_REG0
union Pb1PllLc0SciStatOvrdReg0 {
	struct {
		uint32 pllLc0IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllLc0IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllLc0Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllLc0Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB1_PLL_LC1_SCI_STAT_OVRD_REG0
union Pb1PllLc1SciStatOvrdReg0 {
	struct {
		uint32 pllLc1IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllLc1IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllLc1Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllLc1Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB1_PLL_LC2_SCI_STAT_OVRD_REG0
union Pb1PllLc2SciStatOvrdReg0 {
	struct {
		uint32 pllLc2IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllLc2IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllLc2Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllLc2Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB1_PLL_LC3_SCI_STAT_OVRD_REG0
union Pb1PllLc3SciStatOvrdReg0 {
	struct {
		uint32 pllLc3IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllLc3IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllLc3Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllLc3Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB1_PLL_RO0_CTRL_REG0
union Pb1PllRo0CtrlReg0 {
	struct {
		uint32 pllDbgRoAnalogSel0: 2; // 0
		uint32 pllDbgRoExtResetEn0: 1; // 2
		uint32 pllDbgRoVctlAdcEn0: 1; // 3
		uint32 pllDbgRoLfCntrl0: 7; // 4
		uint32 pllTstRoUsampleEn0: 1; // 11
		uint32 unknown1: 20;
	};
	uint32 val;
};

// PB1_PLL_RO0_OVRD_REG0
union Pb1PllRo0OvrdReg0 {
	struct {
		uint32 pllCfgRoBwCntrlOvrdVal0: 8; // 0
		uint32 pllCfgRoBwCntrlOvrdEn0: 1; // 8
		uint32 pllCfgRoCoreclkDivOvrdVal0: 3; // 9
		uint32 pllCfgRoCoreclkDivOvrdEn0: 1; // 12
		uint32 pllCfgRoCoreclkEnOvrdVal0: 1; // 13
		uint32 pllCfgRoCoreclkEnOvrdEn0: 1; // 14
		uint32 pllCfgRoFbdivOvrdVal0: 13; // 15
		uint32 pllCfgRoFbdivOvrdEn0: 1; // 28
		uint32 unknown1: 1;
		uint32 pllCfgRoVtoiBiasCntrlOvrdVal0: 1; // 30
		uint32 pllCfgRoVtoiBiasCntrlOvrdEn0: 1; // 31
	};
	uint32 val;
};

// PB1_PLL_RO0_OVRD_REG1
union Pb1PllRo0OvrdReg1 {
	struct {
		uint32 pllCfgRoRefdivOvrdVal0: 5; // 0
		uint32 pllCfgRoRefdivOvrdEn0: 1; // 5
		uint32 pllCfgRoVcoModeOvrdVal0: 2; // 6
		uint32 pllCfgRoVcoModeOvrdEn0: 1; // 8
		uint32 pllRoHsclkLeftEnOvrdVal0: 1; // 9
		uint32 pllRoHsclkLeftEnOvrdEn0: 1; // 10
		uint32 pllRoHsclkRightEnOvrdVal0: 1; // 11
		uint32 pllRoHsclkRightEnOvrdEn0: 1; // 12
		uint32 pllRoPwronOvrdVal0: 1; // 13
		uint32 pllRoPwronOvrdEn0: 1; // 14
		uint32 unknown1: 4;
		uint32 pllCfgRoRefclkSrcOvrdVal0: 3; // 19
		uint32 pllCfgRoRefclkSrcOvrdEn0: 1; // 22
		uint32 unknown2: 9;
	};
	uint32 val;
};

// PB1_PLL_RO0_SCI_STAT_OVRD_REG0
union Pb1PllRo0SciStatOvrdReg0 {
	struct {
		uint32 pllRo0IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllRo0IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllRo0Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllRo0Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB1_PLL_RO1_SCI_STAT_OVRD_REG0
union Pb1PllRo1SciStatOvrdReg0 {
	struct {
		uint32 pllRo1IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllRo1IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllRo1Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllRo1Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB1_PLL_RO2_SCI_STAT_OVRD_REG0
union Pb1PllRo2SciStatOvrdReg0 {
	struct {
		uint32 pllRo2IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllRo2IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllRo2Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllRo2Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB1_PLL_RO3_SCI_STAT_OVRD_REG0
union Pb1PllRo3SciStatOvrdReg0 {
	struct {
		uint32 pllRo3IgnrPllpwrSciUpdt: 1; // 0
		uint32 pllRo3IgnrFreqmodeSciUpdt: 1; // 1
		uint32 unknown1: 2;
		uint32 pllRo3Pllpwr: 3; // 4
		uint32 unknown2: 1;
		uint32 pllRo3Freqmode: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// PB1_PLL_RO_GLB_CTRL_REG0
union Pb1PllRoGlbCtrlReg0 {
	struct {
		uint32 pllTstLospdtstSrc: 1; // 0
		uint32 pllRoHsclkLeftEnLutEntryLs0: 1; // 1
		uint32 pllRoHsclkLeftEnLutEntryLs1: 1; // 2
		uint32 pllRoHsclkLeftEnLutEntryLs2: 1; // 3
		uint32 pllRoHsclkRightEnLutEntryLs0: 1; // 4
		uint32 pllRoHsclkRightEnLutEntryLs1: 1; // 5
		uint32 pllRoHsclkRightEnLutEntryLs2: 1; // 6
		uint32 pllRoPwronLutEntryLs2: 1; // 7
		uint32 pllLcPwronLutEntryLs2: 1; // 8
		uint32 pllLcHsclkLeftEnLutEntryLs0: 1; // 9
		uint32 pllLcHsclkLeftEnLutEntryLs1: 1; // 10
		uint32 pllLcHsclkLeftEnLutEntryLs2: 1; // 11
		uint32 pllLcHsclkRightEnLutEntryLs0: 1; // 12
		uint32 pllLcHsclkRightEnLutEntryLs1: 1; // 13
		uint32 pllLcHsclkRightEnLutEntryLs2: 1; // 14
		uint32 unknown1: 1;
		uint32 pllRoHsclkLeftLeftEnGatingEn: 1; // 16
		uint32 pllRoHsclkLeftRightEnGatingEn: 1; // 17
		uint32 pllRoHsclkRightLeftEnGatingEn: 1; // 18
		uint32 pllRoHsclkRightRightEnGatingEn: 1; // 19
		uint32 pllLcHsclkLeftLeftEnGatingEn: 1; // 20
		uint32 pllLcHsclkLeftRightEnGatingEn: 1; // 21
		uint32 pllLcHsclkRightLeftEnGatingEn: 1; // 22
		uint32 pllLcHsclkRightRightEnGatingEn: 1; // 23
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PB1_RX_GLB_CTRL_REG0
union Pb1RxGlbCtrlReg0 {
	struct {
		uint32 rxCfgAdaptModeGen1: 10; // 0
		uint32 rxCfgAdaptModeGen2: 10; // 10
		uint32 rxCfgAdaptModeGen3: 10; // 20
		uint32 rxCfgAdaptRstMode: 2; // 30
	};
	uint32 val;
};

// PB1_RX_GLB_CTRL_REG1
union Pb1RxGlbCtrlReg1 {
	struct {
		uint32 rxCfgCdrFrGainGen1: 4; // 0
		uint32 rxCfgCdrFrGainGen2: 4; // 4
		uint32 rxCfgCdrFrGainGen3: 4; // 8
		uint32 rxCfgCdrPhGainGen1: 4; // 12
		uint32 rxCfgCdrPhGainGen2: 4; // 16
		uint32 rxCfgCdrPhGainGen3: 4; // 20
		uint32 rxCfgCdrPiStpszGen1: 1; // 24
		uint32 rxCfgCdrPiStpszGen2: 1; // 25
		uint32 rxCfgCdrPiStpszGen3: 1; // 26
		uint32 rxCfgLeqDcattnBypEnGen1: 1; // 27
		uint32 rxCfgLeqDcattnBypEnGen2: 1; // 28
		uint32 rxCfgLeqDcattnBypEnGen3: 1; // 29
		uint32 rxAdaptHldAsrtToDclkEn: 2; // 30
	};
	uint32 val;
};

// PB1_RX_GLB_CTRL_REG2
union Pb1RxGlbCtrlReg2 {
	struct {
		uint32 unknown1: 12;
		uint32 rxCfgCdrTimeGen1: 4; // 12
		uint32 rxCfgCdrTimeGen2: 4; // 16
		uint32 rxCfgCdrTimeGen3: 4; // 20
		uint32 rxCfgLeqLoopGainGen1: 2; // 24
		uint32 rxCfgLeqLoopGainGen2: 2; // 26
		uint32 rxCfgLeqLoopGainGen3: 2; // 28
		uint32 rxDclkEnAsrtToAdaptHld: 2; // 30
	};
	uint32 val;
};

// PB1_RX_GLB_CTRL_REG3
union Pb1RxGlbCtrlReg3 {
	struct {
		uint32 rxCfgCdrFrEnGen1: 1; // 0
		uint32 rxCfgCdrFrEnGen2: 1; // 1
		uint32 rxCfgCdrFrEnGen3: 1; // 2
		uint32 unknown1: 17;
		uint32 rxCfgDfeTimeGen1: 4; // 20
		uint32 rxCfgDfeTimeGen2: 4; // 24
		uint32 rxCfgDfeTimeGen3: 4; // 28
	};
	uint32 val;
};

// PB1_RX_GLB_CTRL_REG4
union Pb1RxGlbCtrlReg4 {
	struct {
		uint32 rxCfgFomBerGen1: 3; // 0
		uint32 rxCfgFomBerGen2: 3; // 3
		uint32 rxCfgFomBerGen3: 3; // 6
		uint32 rxCfgLeqPoleBypValGen1: 3; // 9
		uint32 rxCfgLeqPoleBypValGen2: 3; // 12
		uint32 rxCfgLeqPoleBypValGen3: 3; // 15
		uint32 unknown1: 2;
		uint32 rxCfgFomTimeGen1: 4; // 20
		uint32 rxCfgFomTimeGen2: 4; // 24
		uint32 rxCfgFomTimeGen3: 4; // 28
	};
	uint32 val;
};

// PB1_RX_GLB_CTRL_REG5
union Pb1RxGlbCtrlReg5 {
	struct {
		uint32 rxCfgLeqDcattnBypValGen1: 5; // 0
		uint32 rxCfgLeqDcattnBypValGen2: 5; // 5
		uint32 rxCfgLeqDcattnBypValGen3: 5; // 10
		uint32 rxCfgLeqPoleBypEnGen1: 1; // 15
		uint32 rxCfgLeqPoleBypEnGen2: 1; // 16
		uint32 rxCfgLeqPoleBypEnGen3: 1; // 17
		uint32 rxCfgLeqShuntEnGen1: 1; // 18
		uint32 rxCfgLeqShuntEnGen2: 1; // 19
		uint32 rxCfgLeqShuntEnGen3: 1; // 20
		uint32 unknown1: 6;
		uint32 rxCfgTermModeGen1: 1; // 27
		uint32 rxCfgTermModeGen2: 1; // 28
		uint32 rxCfgTermModeGen3: 1; // 29
		uint32 rxForceDllRstRxpwrLs2offToLs0: 1; // 30
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PB1_RX_GLB_CTRL_REG6
union Pb1RxGlbCtrlReg6 {
	struct {
		uint32 rxCfgLeqTimeGen1: 4; // 0
		uint32 rxCfgLeqTimeGen2: 4; // 4
		uint32 rxCfgLeqTimeGen3: 4; // 8
		uint32 rxCfgOcTimeGen1: 4; // 12
		uint32 rxCfgOcTimeGen2: 4; // 16
		uint32 rxCfgOcTimeGen3: 4; // 20
		uint32 rxFrontendPwronLutEntryLs0CdrEn0: 1; // 24
		uint32 unknown1: 1;
		uint32 rxFrontendPwronLutEntryLs2: 1; // 26
		uint32 rxAuxPwronLutEntryLs2: 1; // 27
		uint32 unknown2: 4;
	};
	uint32 val;
};

// PB1_RX_GLB_CTRL_REG7
union Pb1RxGlbCtrlReg7 {
	struct {
		uint32 rxCfgThLoopGainGen1: 4; // 0
		uint32 rxCfgThLoopGainGen2: 4; // 4
		uint32 rxCfgThLoopGainGen3: 4; // 8
		uint32 rxDclkEnLutEntryLs0CdrEn0: 1; // 12
		uint32 rxDclkEnLutEntryLs2: 1; // 13
		uint32 unknown1: 3;
		uint32 rxDllPwronLutEntryLs2: 1; // 17
		uint32 rxCfgDllCpiSelGen1: 3; // 18
		uint32 rxCfgDllCpiSelGen2: 3; // 21
		uint32 rxCfgDllCpiSelGen3: 3; // 24
		uint32 rxCfgDllFlockDisableGen1: 1; // 27
		uint32 rxCfgDllFlockDisableGen2: 1; // 28
		uint32 rxCfgDllFlockDisableGen3: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// PB1_RX_GLB_OVRD_REG0
union Pb1RxGlbOvrdReg0 {
	struct {
		uint32 rxAdaptHldOvrdVal: 1; // 0
		uint32 rxAdaptHldOvrdEn: 1; // 1
		uint32 rxAdaptRstOvrdVal: 1; // 2
		uint32 rxAdaptRstOvrdEn: 1; // 3
		uint32 unknown1: 2;
		uint32 rxCfgDclkDivOvrdVal: 2; // 6
		uint32 rxCfgDclkDivOvrdEn: 1; // 8
		uint32 rxCfgDllFreqModeOvrdVal: 1; // 9
		uint32 rxCfgDllFreqModeOvrdEn: 1; // 10
		uint32 rxCfgPllclkSelOvrdVal: 1; // 11
		uint32 rxCfgPllclkSelOvrdEn: 1; // 12
		uint32 rxCfgRclkDivOvrdVal: 1; // 13
		uint32 rxCfgRclkDivOvrdEn: 1; // 14
		uint32 rxDclkEnOvrdVal: 1; // 15
		uint32 rxDclkEnOvrdEn: 1; // 16
		uint32 rxDllPwronOvrdVal: 1; // 17
		uint32 rxDllPwronOvrdEn: 1; // 18
		uint32 rxFrontendPwronOvrdVal: 1; // 19
		uint32 rxFrontendPwronOvrdEn: 1; // 20
		uint32 rxIdledetPwronOvrdVal: 1; // 21
		uint32 rxIdledetPwronOvrdEn: 1; // 22
		uint32 rxTermEnOvrdVal: 1; // 23
		uint32 rxTermEnOvrdEn: 1; // 24
		uint32 unknown2: 3;
		uint32 rxAuxPwronOvrdVal: 1; // 28
		uint32 rxAuxPwronOvrdEn: 1; // 29
		uint32 rxAdaptFomOvrdVal: 1; // 30
		uint32 rxAdaptFomOvrdEn: 1; // 31
	};
	uint32 val;
};

// PB1_RX_GLB_OVRD_REG1
union Pb1RxGlbOvrdReg1 {
	struct {
		uint32 rxAdaptTrkOvrdVal: 1; // 0
		uint32 rxAdaptTrkOvrdEn: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// PB1_RX_GLB_SCI_STAT_OVRD_REG0
union Pb1RxGlbSciStatOvrdReg0 {
	struct {
		uint32 ignrRxpwrSciUpdtL0t3: 1; // 0
		uint32 ignrRxpwrSciUpdtL4t7: 1; // 1
		uint32 ignrRxpwrSciUpdtL8t11: 1; // 2
		uint32 ignrRxpwrSciUpdtL12t15: 1; // 3
		uint32 ignrElecidledetenSciUpdtL0t3: 1; // 4
		uint32 ignrElecidledetenSciUpdtL4t7: 1; // 5
		uint32 ignrElecidledetenSciUpdtL8t11: 1; // 6
		uint32 ignrElecidledetenSciUpdtL12t15: 1; // 7
		uint32 ignrRxpresethintSciUpdtL0t3: 1; // 8
		uint32 ignrRxpresethintSciUpdtL4t7: 1; // 9
		uint32 ignrRxpresethintSciUpdtL8t11: 1; // 10
		uint32 ignrRxpresethintSciUpdtL12t15: 1; // 11
		uint32 ignrEnablefomSciUpdtL0t3: 1; // 12
		uint32 ignrEnablefomSciUpdtL4t7: 1; // 13
		uint32 ignrEnablefomSciUpdtL8t11: 1; // 14
		uint32 ignrEnablefomSciUpdtL12t15: 1; // 15
		uint32 ignrRequestfomSciUpdtL0t3: 1; // 16
		uint32 ignrRequestfomSciUpdtL4t7: 1; // 17
		uint32 ignrRequestfomSciUpdtL8t11: 1; // 18
		uint32 ignrRequestfomSciUpdtL12t15: 1; // 19
		uint32 ignrResponsemodeSciUpdtL0t3: 1; // 20
		uint32 ignrResponsemodeSciUpdtL4t7: 1; // 21
		uint32 ignrResponsemodeSciUpdtL8t11: 1; // 22
		uint32 ignrResponsemodeSciUpdtL12t15: 1; // 23
		uint32 unknown1: 8;
	};
	uint32 val;
};

// PB1_RX_LANE0_CTRL_REG0
union Pb1RxLane0CtrlReg0 {
	struct {
		uint32 rxBackup0: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel0: 2; // 10
		uint32 rxTstBscanEn0: 1; // 12
		uint32 rxCfgOvrPwrsf0: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE0_SCI_STAT_OVRD_REG0
union Pb1RxLane0SciStatOvrdReg0 {
	struct {
		uint32 rxpwr0: 3; // 0
		uint32 elecidledeten0: 1; // 3
		uint32 rxpresethint0: 3; // 4
		uint32 enablefom0: 1; // 7
		uint32 requestfom0: 1; // 8
		uint32 responsemode0: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE10_CTRL_REG0
union Pb1RxLane10CtrlReg0 {
	struct {
		uint32 rxBackup10: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel10: 2; // 10
		uint32 rxTstBscanEn10: 1; // 12
		uint32 rxCfgOvrPwrsf10: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE10_SCI_STAT_OVRD_REG0
union Pb1RxLane10SciStatOvrdReg0 {
	struct {
		uint32 rxpwr10: 3; // 0
		uint32 elecidledeten10: 1; // 3
		uint32 rxpresethint10: 3; // 4
		uint32 enablefom10: 1; // 7
		uint32 requestfom10: 1; // 8
		uint32 responsemode10: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE11_CTRL_REG0
union Pb1RxLane11CtrlReg0 {
	struct {
		uint32 rxBackup11: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel11: 2; // 10
		uint32 rxTstBscanEn11: 1; // 12
		uint32 rxCfgOvrPwrsf11: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE11_SCI_STAT_OVRD_REG0
union Pb1RxLane11SciStatOvrdReg0 {
	struct {
		uint32 rxpwr11: 3; // 0
		uint32 elecidledeten11: 1; // 3
		uint32 rxpresethint11: 3; // 4
		uint32 enablefom11: 1; // 7
		uint32 requestfom11: 1; // 8
		uint32 responsemode11: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE12_CTRL_REG0
union Pb1RxLane12CtrlReg0 {
	struct {
		uint32 rxBackup12: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel12: 2; // 10
		uint32 rxTstBscanEn12: 1; // 12
		uint32 rxCfgOvrPwrsf12: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE12_SCI_STAT_OVRD_REG0
union Pb1RxLane12SciStatOvrdReg0 {
	struct {
		uint32 rxpwr12: 3; // 0
		uint32 elecidledeten12: 1; // 3
		uint32 rxpresethint12: 3; // 4
		uint32 enablefom12: 1; // 7
		uint32 requestfom12: 1; // 8
		uint32 responsemode12: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE13_CTRL_REG0
union Pb1RxLane13CtrlReg0 {
	struct {
		uint32 rxBackup13: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel13: 2; // 10
		uint32 rxTstBscanEn13: 1; // 12
		uint32 rxCfgOvrPwrsf13: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE13_SCI_STAT_OVRD_REG0
union Pb1RxLane13SciStatOvrdReg0 {
	struct {
		uint32 rxpwr13: 3; // 0
		uint32 elecidledeten13: 1; // 3
		uint32 rxpresethint13: 3; // 4
		uint32 enablefom13: 1; // 7
		uint32 requestfom13: 1; // 8
		uint32 responsemode13: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE14_CTRL_REG0
union Pb1RxLane14CtrlReg0 {
	struct {
		uint32 rxBackup14: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel14: 2; // 10
		uint32 rxTstBscanEn14: 1; // 12
		uint32 rxCfgOvrPwrsf14: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE14_SCI_STAT_OVRD_REG0
union Pb1RxLane14SciStatOvrdReg0 {
	struct {
		uint32 rxpwr14: 3; // 0
		uint32 elecidledeten14: 1; // 3
		uint32 rxpresethint14: 3; // 4
		uint32 enablefom14: 1; // 7
		uint32 requestfom14: 1; // 8
		uint32 responsemode14: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE15_CTRL_REG0
union Pb1RxLane15CtrlReg0 {
	struct {
		uint32 rxBackup15: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel15: 2; // 10
		uint32 rxTstBscanEn15: 1; // 12
		uint32 rxCfgOvrPwrsf15: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE15_SCI_STAT_OVRD_REG0
union Pb1RxLane15SciStatOvrdReg0 {
	struct {
		uint32 rxpwr15: 3; // 0
		uint32 elecidledeten15: 1; // 3
		uint32 rxpresethint15: 3; // 4
		uint32 enablefom15: 1; // 7
		uint32 requestfom15: 1; // 8
		uint32 responsemode15: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE1_CTRL_REG0
union Pb1RxLane1CtrlReg0 {
	struct {
		uint32 rxBackup1: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel1: 2; // 10
		uint32 rxTstBscanEn1: 1; // 12
		uint32 rxCfgOvrPwrsf1: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE1_SCI_STAT_OVRD_REG0
union Pb1RxLane1SciStatOvrdReg0 {
	struct {
		uint32 rxpwr1: 3; // 0
		uint32 elecidledeten1: 1; // 3
		uint32 rxpresethint1: 3; // 4
		uint32 enablefom1: 1; // 7
		uint32 requestfom1: 1; // 8
		uint32 responsemode1: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE2_CTRL_REG0
union Pb1RxLane2CtrlReg0 {
	struct {
		uint32 rxBackup2: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel2: 2; // 10
		uint32 rxTstBscanEn2: 1; // 12
		uint32 rxCfgOvrPwrsf2: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE2_SCI_STAT_OVRD_REG0
union Pb1RxLane2SciStatOvrdReg0 {
	struct {
		uint32 rxpwr2: 3; // 0
		uint32 elecidledeten2: 1; // 3
		uint32 rxpresethint2: 3; // 4
		uint32 enablefom2: 1; // 7
		uint32 requestfom2: 1; // 8
		uint32 responsemode2: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE3_CTRL_REG0
union Pb1RxLane3CtrlReg0 {
	struct {
		uint32 rxBackup3: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel3: 2; // 10
		uint32 rxTstBscanEn3: 1; // 12
		uint32 rxCfgOvrPwrsf3: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE3_SCI_STAT_OVRD_REG0
union Pb1RxLane3SciStatOvrdReg0 {
	struct {
		uint32 rxpwr3: 3; // 0
		uint32 elecidledeten3: 1; // 3
		uint32 rxpresethint3: 3; // 4
		uint32 enablefom3: 1; // 7
		uint32 requestfom3: 1; // 8
		uint32 responsemode3: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE4_CTRL_REG0
union Pb1RxLane4CtrlReg0 {
	struct {
		uint32 rxBackup4: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel4: 2; // 10
		uint32 rxTstBscanEn4: 1; // 12
		uint32 rxCfgOvrPwrsf4: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE4_SCI_STAT_OVRD_REG0
union Pb1RxLane4SciStatOvrdReg0 {
	struct {
		uint32 rxpwr4: 3; // 0
		uint32 elecidledeten4: 1; // 3
		uint32 rxpresethint4: 3; // 4
		uint32 enablefom4: 1; // 7
		uint32 requestfom4: 1; // 8
		uint32 responsemode4: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE5_CTRL_REG0
union Pb1RxLane5CtrlReg0 {
	struct {
		uint32 rxBackup5: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel5: 2; // 10
		uint32 rxTstBscanEn5: 1; // 12
		uint32 rxCfgOvrPwrsf5: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE5_SCI_STAT_OVRD_REG0
union Pb1RxLane5SciStatOvrdReg0 {
	struct {
		uint32 rxpwr5: 3; // 0
		uint32 elecidledeten5: 1; // 3
		uint32 rxpresethint5: 3; // 4
		uint32 enablefom5: 1; // 7
		uint32 requestfom5: 1; // 8
		uint32 responsemode5: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE6_CTRL_REG0
union Pb1RxLane6CtrlReg0 {
	struct {
		uint32 rxBackup6: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel6: 2; // 10
		uint32 rxTstBscanEn6: 1; // 12
		uint32 rxCfgOvrPwrsf6: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE6_SCI_STAT_OVRD_REG0
union Pb1RxLane6SciStatOvrdReg0 {
	struct {
		uint32 rxpwr6: 3; // 0
		uint32 elecidledeten6: 1; // 3
		uint32 rxpresethint6: 3; // 4
		uint32 enablefom6: 1; // 7
		uint32 requestfom6: 1; // 8
		uint32 responsemode6: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE7_CTRL_REG0
union Pb1RxLane7CtrlReg0 {
	struct {
		uint32 rxBackup7: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel7: 2; // 10
		uint32 rxTstBscanEn7: 1; // 12
		uint32 rxCfgOvrPwrsf7: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE7_SCI_STAT_OVRD_REG0
union Pb1RxLane7SciStatOvrdReg0 {
	struct {
		uint32 rxpwr7: 3; // 0
		uint32 elecidledeten7: 1; // 3
		uint32 rxpresethint7: 3; // 4
		uint32 enablefom7: 1; // 7
		uint32 requestfom7: 1; // 8
		uint32 responsemode7: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE8_CTRL_REG0
union Pb1RxLane8CtrlReg0 {
	struct {
		uint32 rxBackup8: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel8: 2; // 10
		uint32 rxTstBscanEn8: 1; // 12
		uint32 rxCfgOvrPwrsf8: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE8_SCI_STAT_OVRD_REG0
union Pb1RxLane8SciStatOvrdReg0 {
	struct {
		uint32 rxpwr8: 3; // 0
		uint32 elecidledeten8: 1; // 3
		uint32 rxpresethint8: 3; // 4
		uint32 enablefom8: 1; // 7
		uint32 requestfom8: 1; // 8
		uint32 responsemode8: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_RX_LANE9_CTRL_REG0
union Pb1RxLane9CtrlReg0 {
	struct {
		uint32 rxBackup9: 8; // 0
		uint32 unknown1: 2;
		uint32 rxDbgAnalogSel9: 2; // 10
		uint32 rxTstBscanEn9: 1; // 12
		uint32 rxCfgOvrPwrsf9: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// PB1_RX_LANE9_SCI_STAT_OVRD_REG0
union Pb1RxLane9SciStatOvrdReg0 {
	struct {
		uint32 rxpwr9: 3; // 0
		uint32 elecidledeten9: 1; // 3
		uint32 rxpresethint9: 3; // 4
		uint32 enablefom9: 1; // 7
		uint32 requestfom9: 1; // 8
		uint32 responsemode9: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PB1_STRAP_GLB_REG0
union Pb1StrapGlbReg0 {
	struct {
		uint32 unknown1: 15;
		uint32 strapDbgRxdllVregRefSel: 1; // 15
		uint32 unknown2: 16;
	};
	uint32 val;
};

// PB1_TX_GLB_COEFF_ACCEPT_TABLE_REG0
union Pb1TxGlbCoeffAcceptTableReg0 {
	struct {
		uint32 acceptEntry0: 1; // 0
		uint32 acceptEntry1: 1; // 1
		uint32 acceptEntry2: 1; // 2
		uint32 acceptEntry3: 1; // 3
		uint32 acceptEntry4: 1; // 4
		uint32 acceptEntry5: 1; // 5
		uint32 acceptEntry6: 1; // 6
		uint32 acceptEntry7: 1; // 7
		uint32 acceptEntry8: 1; // 8
		uint32 acceptEntry9: 1; // 9
		uint32 acceptEntry10: 1; // 10
		uint32 acceptEntry11: 1; // 11
		uint32 acceptEntry12: 1; // 12
		uint32 acceptEntry13: 1; // 13
		uint32 acceptEntry14: 1; // 14
		uint32 acceptEntry15: 1; // 15
		uint32 acceptEntry16: 1; // 16
		uint32 acceptEntry17: 1; // 17
		uint32 acceptEntry18: 1; // 18
		uint32 acceptEntry19: 1; // 19
		uint32 acceptEntry20: 1; // 20
		uint32 acceptEntry21: 1; // 21
		uint32 acceptEntry22: 1; // 22
		uint32 acceptEntry23: 1; // 23
		uint32 acceptEntry24: 1; // 24
		uint32 acceptEntry25: 1; // 25
		uint32 acceptEntry26: 1; // 26
		uint32 acceptEntry27: 1; // 27
		uint32 acceptEntry28: 1; // 28
		uint32 acceptEntry29: 1; // 29
		uint32 acceptEntry30: 1; // 30
		uint32 acceptEntry31: 1; // 31
	};
	uint32 val;
};

// PB1_TX_GLB_COEFF_ACCEPT_TABLE_REG1
union Pb1TxGlbCoeffAcceptTableReg1 {
	struct {
		uint32 acceptEntry32: 1; // 0
		uint32 acceptEntry33: 1; // 1
		uint32 acceptEntry34: 1; // 2
		uint32 acceptEntry35: 1; // 3
		uint32 acceptEntry36: 1; // 4
		uint32 acceptEntry37: 1; // 5
		uint32 acceptEntry38: 1; // 6
		uint32 acceptEntry39: 1; // 7
		uint32 acceptEntry40: 1; // 8
		uint32 acceptEntry41: 1; // 9
		uint32 acceptEntry42: 1; // 10
		uint32 acceptEntry43: 1; // 11
		uint32 acceptEntry44: 1; // 12
		uint32 acceptEntry45: 1; // 13
		uint32 acceptEntry46: 1; // 14
		uint32 acceptEntry47: 1; // 15
		uint32 acceptEntry48: 1; // 16
		uint32 acceptEntry49: 1; // 17
		uint32 acceptEntry50: 1; // 18
		uint32 acceptEntry51: 1; // 19
		uint32 acceptEntry52: 1; // 20
		uint32 acceptEntry53: 1; // 21
		uint32 acceptEntry54: 1; // 22
		uint32 acceptEntry55: 1; // 23
		uint32 acceptEntry56: 1; // 24
		uint32 acceptEntry57: 1; // 25
		uint32 acceptEntry58: 1; // 26
		uint32 acceptEntry59: 1; // 27
		uint32 acceptEntry60: 1; // 28
		uint32 acceptEntry61: 1; // 29
		uint32 acceptEntry62: 1; // 30
		uint32 acceptEntry63: 1; // 31
	};
	uint32 val;
};

// PB1_TX_GLB_COEFF_ACCEPT_TABLE_REG2
union Pb1TxGlbCoeffAcceptTableReg2 {
	struct {
		uint32 acceptEntry64: 1; // 0
		uint32 acceptEntry65: 1; // 1
		uint32 acceptEntry66: 1; // 2
		uint32 acceptEntry67: 1; // 3
		uint32 acceptEntry68: 1; // 4
		uint32 acceptEntry69: 1; // 5
		uint32 acceptEntry70: 1; // 6
		uint32 acceptEntry71: 1; // 7
		uint32 acceptEntry72: 1; // 8
		uint32 acceptEntry73: 1; // 9
		uint32 acceptEntry74: 1; // 10
		uint32 acceptEntry75: 1; // 11
		uint32 acceptEntry76: 1; // 12
		uint32 acceptEntry77: 1; // 13
		uint32 acceptEntry78: 1; // 14
		uint32 acceptEntry79: 1; // 15
		uint32 acceptEntry80: 1; // 16
		uint32 acceptEntry81: 1; // 17
		uint32 acceptEntry82: 1; // 18
		uint32 acceptEntry83: 1; // 19
		uint32 acceptEntry84: 1; // 20
		uint32 acceptEntry85: 1; // 21
		uint32 acceptEntry86: 1; // 22
		uint32 acceptEntry87: 1; // 23
		uint32 acceptEntry88: 1; // 24
		uint32 acceptEntry89: 1; // 25
		uint32 acceptEntry90: 1; // 26
		uint32 acceptEntry91: 1; // 27
		uint32 acceptEntry92: 1; // 28
		uint32 acceptEntry93: 1; // 29
		uint32 acceptEntry94: 1; // 30
		uint32 acceptEntry95: 1; // 31
	};
	uint32 val;
};

// PB1_TX_GLB_COEFF_ACCEPT_TABLE_REG3
union Pb1TxGlbCoeffAcceptTableReg3 {
	struct {
		uint32 acceptEntry96: 1; // 0
		uint32 acceptEntry97: 1; // 1
		uint32 acceptEntry98: 1; // 2
		uint32 acceptEntry99: 1; // 3
		uint32 acceptEntry100: 1; // 4
		uint32 acceptEntry101: 1; // 5
		uint32 acceptEntry102: 1; // 6
		uint32 acceptEntry103: 1; // 7
		uint32 acceptEntry104: 1; // 8
		uint32 acceptEntry105: 1; // 9
		uint32 acceptEntry106: 1; // 10
		uint32 acceptEntry107: 1; // 11
		uint32 acceptEntry108: 1; // 12
		uint32 acceptEntry109: 1; // 13
		uint32 unknown1: 18;
	};
	uint32 val;
};

// PB1_TX_GLB_CTRL_REG0
union Pb1TxGlbCtrlReg0 {
	struct {
		uint32 txDrvDataAsrtDlyVal: 3; // 0
		uint32 txDrvDataDsrtDlyVal: 3; // 3
		uint32 unknown1: 2;
		uint32 txCfgRptrRstValGen1: 3; // 8
		uint32 txCfgRptrRstValGen2: 3; // 11
		uint32 txCfgRptrRstValGen3: 3; // 14
		uint32 txStaggerCtrl: 2; // 17
		uint32 txDataClkGating: 1; // 19
		uint32 txPresetTableBypass: 1; // 20
		uint32 txCoeffRoundEn: 1; // 21
		uint32 txCoeffRoundDirVer: 1; // 22
		uint32 txDclkEnLsxAlwaysOn: 1; // 23
		uint32 txFrontendPwronInOff: 1; // 24
		uint32 unknown2: 7;
	};
	uint32 val;
};

// PB1_TX_GLB_LANE_SKEW_CTRL
union Pb1TxGlbLaneSkewCtrl {
	struct {
		uint32 txCfgGroupx1En0: 1; // 0
		uint32 txCfgGroupx1En1: 1; // 1
		uint32 txCfgGroupx1En2: 1; // 2
		uint32 txCfgGroupx1En3: 1; // 3
		uint32 txCfgGroupx1En4: 1; // 4
		uint32 txCfgGroupx1En5: 1; // 5
		uint32 txCfgGroupx1En6: 1; // 6
		uint32 txCfgGroupx1En7: 1; // 7
		uint32 txCfgGroupx1En8: 1; // 8
		uint32 txCfgGroupx1En9: 1; // 9
		uint32 txCfgGroupx1En10: 1; // 10
		uint32 txCfgGroupx1En11: 1; // 11
		uint32 txCfgGroupx1En12: 1; // 12
		uint32 txCfgGroupx1En13: 1; // 13
		uint32 txCfgGroupx1En14: 1; // 14
		uint32 txCfgGroupx1En15: 1; // 15
		uint32 txCfgGroupx2EnL0t1: 1; // 16
		uint32 txCfgGroupx2EnL2t3: 1; // 17
		uint32 txCfgGroupx2EnL4t5: 1; // 18
		uint32 txCfgGroupx2EnL6t7: 1; // 19
		uint32 txCfgGroupx2EnL8t9: 1; // 20
		uint32 txCfgGroupx2EnL10t11: 1; // 21
		uint32 txCfgGroupx2EnL12t13: 1; // 22
		uint32 txCfgGroupx2EnL14t15: 1; // 23
		uint32 txCfgGroupx4EnL0t3: 1; // 24
		uint32 txCfgGroupx4EnL4t7: 1; // 25
		uint32 txCfgGroupx4EnL8t11: 1; // 26
		uint32 txCfgGroupx4EnL12t15: 1; // 27
		uint32 txCfgGroupx8EnL0t7: 1; // 28
		uint32 txCfgGroupx8EnL8t15: 1; // 29
		uint32 txCfgGroupx16EnL0t15: 1; // 30
		uint32 unknown1: 1;
	};
	uint32 val;
};

// PB1_TX_GLB_OVRD_REG0
union Pb1TxGlbOvrdReg0 {
	struct {
		uint32 txCfgDclkDivOvrdVal: 3; // 0
		uint32 txCfgDclkDivOvrdEn: 1; // 3
		uint32 txCfgDrv0EnGen1OvrdVal: 4; // 4
		uint32 txCfgDrv0EnOvrdEn: 1; // 8
		uint32 txCfgDrv0TapSelGen1OvrdVal: 4; // 9
		uint32 txCfgDrv0TapSelOvrdEn: 1; // 13
		uint32 txCfgDrv1EnGen1OvrdVal: 5; // 14
		uint32 txCfgDrv1EnOvrdEn: 1; // 19
		uint32 txCfgDrv1TapSelGen1OvrdVal: 5; // 20
		uint32 txCfgDrv1TapSelOvrdEn: 1; // 25
		uint32 txCfgDrv2EnGen1OvrdVal: 4; // 26
		uint32 txCfgDrv2EnOvrdEn: 1; // 30
		uint32 unknown1: 1;
	};
	uint32 val;
};

// PB1_TX_GLB_OVRD_REG1
union Pb1TxGlbOvrdReg1 {
	struct {
		uint32 txCfgDrv2TapSelGen1OvrdVal: 4; // 0
		uint32 txCfgDrv2TapSelOvrdEn: 1; // 4
		uint32 txCfgDrvxEnGen1OvrdVal: 1; // 5
		uint32 txCfgDrvxEnOvrdEn: 1; // 6
		uint32 txCfgDrvxTapSelGen1OvrdVal: 1; // 7
		uint32 txCfgDrvxTapSelOvrdEn: 1; // 8
		uint32 txCfgPllclkSelOvrdVal: 1; // 9
		uint32 txCfgPllclkSelOvrdEn: 1; // 10
		uint32 txCfgTclkDivOvrdVal: 1; // 11
		uint32 txCfgTclkDivOvrdEn: 1; // 12
		uint32 txCmdetEnOvrdVal: 1; // 13
		uint32 txCmdetEnOvrdEn: 1; // 14
		uint32 txDataInOvrdVal: 10; // 15
		uint32 txDataInOvrdEn: 1; // 25
		uint32 txRptrRstnOvrdVal: 1; // 26
		uint32 txRptrRstnOvrdEn: 1; // 27
		uint32 txRxdetEnOvrdVal: 1; // 28
		uint32 txRxdetEnOvrdEn: 1; // 29
		uint32 txWptrRstnOvrdVal: 1; // 30
		uint32 txWptrRstnOvrdEn: 1; // 31
	};
	uint32 val;
};

// PB1_TX_GLB_OVRD_REG2
union Pb1TxGlbOvrdReg2 {
	struct {
		uint32 txWriteEnOvrdVal: 1; // 0
		uint32 txWriteEnOvrdEn: 1; // 1
		uint32 txCfgGroupx1EnOvrdVal: 1; // 2
		uint32 txCfgGroupx1EnOvrdEn: 1; // 3
		uint32 txCfgGroupx2EnOvrdVal: 1; // 4
		uint32 txCfgGroupx2EnOvrdEn: 1; // 5
		uint32 txCfgGroupx4EnOvrdVal: 1; // 6
		uint32 txCfgGroupx4EnOvrdEn: 1; // 7
		uint32 txCfgGroupx8EnOvrdVal: 1; // 8
		uint32 txCfgGroupx8EnOvrdEn: 1; // 9
		uint32 txCfgGroupx16EnOvrdVal: 1; // 10
		uint32 txCfgGroupx16EnOvrdEn: 1; // 11
		uint32 txCfgDrv0EnGen2OvrdVal: 4; // 12
		uint32 txCfgDrv0TapSelGen2OvrdVal: 4; // 16
		uint32 txCfgDrv1EnGen2OvrdVal: 5; // 20
		uint32 txCfgDrv1TapSelGen2OvrdVal: 5; // 25
		uint32 unknown1: 2;
	};
	uint32 val;
};

// PB1_TX_GLB_OVRD_REG3
union Pb1TxGlbOvrdReg3 {
	struct {
		uint32 txCfgDrv2EnGen2OvrdVal: 4; // 0
		uint32 txCfgDrv2TapSelGen2OvrdVal: 4; // 4
		uint32 txCfgDrvxEnGen2OvrdVal: 1; // 8
		uint32 txCfgDrvxTapSelGen2OvrdVal: 1; // 9
		uint32 txCfgDrv0EnGen3OvrdVal: 4; // 10
		uint32 txCfgDrv0TapSelGen3OvrdVal: 4; // 14
		uint32 txCfgDrv1EnGen3OvrdVal: 5; // 18
		uint32 txCfgDrv1TapSelGen3OvrdVal: 5; // 23
		uint32 txCfgDrv2EnGen3OvrdVal: 4; // 28
	};
	uint32 val;
};

// PB1_TX_GLB_OVRD_REG4
union Pb1TxGlbOvrdReg4 {
	struct {
		uint32 txCfgDrv2TapSelGen3OvrdVal: 4; // 0
		uint32 txCfgDrvxEnGen3OvrdVal: 1; // 4
		uint32 txCfgDrvxTapSelGen3OvrdVal: 1; // 5
		uint32 unknown1: 26;
	};
	uint32 val;
};

// PB1_TX_GLB_SCI_STAT_OVRD_REG0
union Pb1TxGlbSciStatOvrdReg0 {
	struct {
		uint32 ignrTxpwrSciUpdtL0t3: 1; // 0
		uint32 ignrTxpwrSciUpdtL4t7: 1; // 1
		uint32 ignrTxpwrSciUpdtL8t11: 1; // 2
		uint32 ignrTxpwrSciUpdtL12t15: 1; // 3
		uint32 ignrIncoherentckSciUpdtL0t3: 1; // 4
		uint32 ignrIncoherentckSciUpdtL4t7: 1; // 5
		uint32 ignrIncoherentckSciUpdtL8t11: 1; // 6
		uint32 ignrIncoherentckSciUpdtL12t15: 1; // 7
		uint32 ignrCoefficientidSciUpdtL0t3: 1; // 8
		uint32 ignrCoefficientidSciUpdtL4t7: 1; // 9
		uint32 ignrCoefficientidSciUpdtL8t11: 1; // 10
		uint32 ignrCoefficientidSciUpdtL12t15: 1; // 11
		uint32 ignrCoefficientSciUpdtL0t3: 1; // 12
		uint32 ignrCoefficientSciUpdtL4t7: 1; // 13
		uint32 ignrCoefficientSciUpdtL8t11: 1; // 14
		uint32 ignrCoefficientSciUpdtL12t15: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE0_CTRL_REG0
union Pb1TxLane0CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode0: 1; // 0
		uint32 txCfgInvData0: 1; // 1
		uint32 txCfgSwingBoostEn0: 1; // 2
		uint32 txDbgPrbsEn0: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE0_OVRD_REG0
union Pb1TxLane0OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal0: 1; // 0
		uint32 txDclkEnOvrdEn0: 1; // 1
		uint32 txDrvDataEnOvrdVal0: 1; // 2
		uint32 txDrvDataEnOvrdEn0: 1; // 3
		uint32 txDrvPwronOvrdVal0: 1; // 4
		uint32 txDrvPwronOvrdEn0: 1; // 5
		uint32 txFrontendPwronOvrdVal0: 1; // 6
		uint32 txFrontendPwronOvrdEn0: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE0_SCI_STAT_OVRD_REG0
union Pb1TxLane0SciStatOvrdReg0 {
	struct {
		uint32 txpwr0: 3; // 0
		uint32 incoherentck0: 1; // 3
		uint32 txmarg0: 3; // 4
		uint32 deemph0: 1; // 7
		uint32 coefficientid0: 2; // 8
		uint32 coefficient0: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE10_CTRL_REG0
union Pb1TxLane10CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode10: 1; // 0
		uint32 txCfgInvData10: 1; // 1
		uint32 txCfgSwingBoostEn10: 1; // 2
		uint32 txDbgPrbsEn10: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE10_OVRD_REG0
union Pb1TxLane10OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal10: 1; // 0
		uint32 txDclkEnOvrdEn10: 1; // 1
		uint32 txDrvDataEnOvrdVal10: 1; // 2
		uint32 txDrvDataEnOvrdEn10: 1; // 3
		uint32 txDrvPwronOvrdVal10: 1; // 4
		uint32 txDrvPwronOvrdEn10: 1; // 5
		uint32 txFrontendPwronOvrdVal10: 1; // 6
		uint32 txFrontendPwronOvrdEn10: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE10_SCI_STAT_OVRD_REG0
union Pb1TxLane10SciStatOvrdReg0 {
	struct {
		uint32 txpwr10: 3; // 0
		uint32 incoherentck10: 1; // 3
		uint32 txmarg10: 3; // 4
		uint32 deemph10: 1; // 7
		uint32 coefficientid10: 2; // 8
		uint32 coefficient10: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE11_CTRL_REG0
union Pb1TxLane11CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode11: 1; // 0
		uint32 txCfgInvData11: 1; // 1
		uint32 txCfgSwingBoostEn11: 1; // 2
		uint32 txDbgPrbsEn11: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE11_OVRD_REG0
union Pb1TxLane11OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal11: 1; // 0
		uint32 txDclkEnOvrdEn11: 1; // 1
		uint32 txDrvDataEnOvrdVal11: 1; // 2
		uint32 txDrvDataEnOvrdEn11: 1; // 3
		uint32 txDrvPwronOvrdVal11: 1; // 4
		uint32 txDrvPwronOvrdEn11: 1; // 5
		uint32 txFrontendPwronOvrdVal11: 1; // 6
		uint32 txFrontendPwronOvrdEn11: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE11_SCI_STAT_OVRD_REG0
union Pb1TxLane11SciStatOvrdReg0 {
	struct {
		uint32 txpwr11: 3; // 0
		uint32 incoherentck11: 1; // 3
		uint32 txmarg11: 3; // 4
		uint32 deemph11: 1; // 7
		uint32 coefficientid11: 2; // 8
		uint32 coefficient11: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE12_CTRL_REG0
union Pb1TxLane12CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode12: 1; // 0
		uint32 txCfgInvData12: 1; // 1
		uint32 txCfgSwingBoostEn12: 1; // 2
		uint32 txDbgPrbsEn12: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE12_OVRD_REG0
union Pb1TxLane12OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal12: 1; // 0
		uint32 txDclkEnOvrdEn12: 1; // 1
		uint32 txDrvDataEnOvrdVal12: 1; // 2
		uint32 txDrvDataEnOvrdEn12: 1; // 3
		uint32 txDrvPwronOvrdVal12: 1; // 4
		uint32 txDrvPwronOvrdEn12: 1; // 5
		uint32 txFrontendPwronOvrdVal12: 1; // 6
		uint32 txFrontendPwronOvrdEn12: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE12_SCI_STAT_OVRD_REG0
union Pb1TxLane12SciStatOvrdReg0 {
	struct {
		uint32 txpwr12: 3; // 0
		uint32 incoherentck12: 1; // 3
		uint32 txmarg12: 3; // 4
		uint32 deemph12: 1; // 7
		uint32 coefficientid12: 2; // 8
		uint32 coefficient12: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE13_CTRL_REG0
union Pb1TxLane13CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode13: 1; // 0
		uint32 txCfgInvData13: 1; // 1
		uint32 txCfgSwingBoostEn13: 1; // 2
		uint32 txDbgPrbsEn13: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE13_OVRD_REG0
union Pb1TxLane13OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal13: 1; // 0
		uint32 txDclkEnOvrdEn13: 1; // 1
		uint32 txDrvDataEnOvrdVal13: 1; // 2
		uint32 txDrvDataEnOvrdEn13: 1; // 3
		uint32 txDrvPwronOvrdVal13: 1; // 4
		uint32 txDrvPwronOvrdEn13: 1; // 5
		uint32 txFrontendPwronOvrdVal13: 1; // 6
		uint32 txFrontendPwronOvrdEn13: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE13_SCI_STAT_OVRD_REG0
union Pb1TxLane13SciStatOvrdReg0 {
	struct {
		uint32 txpwr13: 3; // 0
		uint32 incoherentck13: 1; // 3
		uint32 txmarg13: 3; // 4
		uint32 deemph13: 1; // 7
		uint32 coefficientid13: 2; // 8
		uint32 coefficient13: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE14_CTRL_REG0
union Pb1TxLane14CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode14: 1; // 0
		uint32 txCfgInvData14: 1; // 1
		uint32 txCfgSwingBoostEn14: 1; // 2
		uint32 txDbgPrbsEn14: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE14_OVRD_REG0
union Pb1TxLane14OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal14: 1; // 0
		uint32 txDclkEnOvrdEn14: 1; // 1
		uint32 txDrvDataEnOvrdVal14: 1; // 2
		uint32 txDrvDataEnOvrdEn14: 1; // 3
		uint32 txDrvPwronOvrdVal14: 1; // 4
		uint32 txDrvPwronOvrdEn14: 1; // 5
		uint32 txFrontendPwronOvrdVal14: 1; // 6
		uint32 txFrontendPwronOvrdEn14: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE14_SCI_STAT_OVRD_REG0
union Pb1TxLane14SciStatOvrdReg0 {
	struct {
		uint32 txpwr14: 3; // 0
		uint32 incoherentck14: 1; // 3
		uint32 txmarg14: 3; // 4
		uint32 deemph14: 1; // 7
		uint32 coefficientid14: 2; // 8
		uint32 coefficient14: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE15_CTRL_REG0
union Pb1TxLane15CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode15: 1; // 0
		uint32 txCfgInvData15: 1; // 1
		uint32 txCfgSwingBoostEn15: 1; // 2
		uint32 txDbgPrbsEn15: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE15_OVRD_REG0
union Pb1TxLane15OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal15: 1; // 0
		uint32 txDclkEnOvrdEn15: 1; // 1
		uint32 txDrvDataEnOvrdVal15: 1; // 2
		uint32 txDrvDataEnOvrdEn15: 1; // 3
		uint32 txDrvPwronOvrdVal15: 1; // 4
		uint32 txDrvPwronOvrdEn15: 1; // 5
		uint32 txFrontendPwronOvrdVal15: 1; // 6
		uint32 txFrontendPwronOvrdEn15: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE15_SCI_STAT_OVRD_REG0
union Pb1TxLane15SciStatOvrdReg0 {
	struct {
		uint32 txpwr15: 3; // 0
		uint32 incoherentck15: 1; // 3
		uint32 txmarg15: 3; // 4
		uint32 deemph15: 1; // 7
		uint32 coefficientid15: 2; // 8
		uint32 coefficient15: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE1_CTRL_REG0
union Pb1TxLane1CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode1: 1; // 0
		uint32 txCfgInvData1: 1; // 1
		uint32 txCfgSwingBoostEn1: 1; // 2
		uint32 txDbgPrbsEn1: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE1_OVRD_REG0
union Pb1TxLane1OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal1: 1; // 0
		uint32 txDclkEnOvrdEn1: 1; // 1
		uint32 txDrvDataEnOvrdVal1: 1; // 2
		uint32 txDrvDataEnOvrdEn1: 1; // 3
		uint32 txDrvPwronOvrdVal1: 1; // 4
		uint32 txDrvPwronOvrdEn1: 1; // 5
		uint32 txFrontendPwronOvrdVal1: 1; // 6
		uint32 txFrontendPwronOvrdEn1: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE1_SCI_STAT_OVRD_REG0
union Pb1TxLane1SciStatOvrdReg0 {
	struct {
		uint32 txpwr1: 3; // 0
		uint32 incoherentck1: 1; // 3
		uint32 txmarg1: 3; // 4
		uint32 deemph1: 1; // 7
		uint32 coefficientid1: 2; // 8
		uint32 coefficient1: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE2_CTRL_REG0
union Pb1TxLane2CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode2: 1; // 0
		uint32 txCfgInvData2: 1; // 1
		uint32 txCfgSwingBoostEn2: 1; // 2
		uint32 txDbgPrbsEn2: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE2_OVRD_REG0
union Pb1TxLane2OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal2: 1; // 0
		uint32 txDclkEnOvrdEn2: 1; // 1
		uint32 txDrvDataEnOvrdVal2: 1; // 2
		uint32 txDrvDataEnOvrdEn2: 1; // 3
		uint32 txDrvPwronOvrdVal2: 1; // 4
		uint32 txDrvPwronOvrdEn2: 1; // 5
		uint32 txFrontendPwronOvrdVal2: 1; // 6
		uint32 txFrontendPwronOvrdEn2: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE2_SCI_STAT_OVRD_REG0
union Pb1TxLane2SciStatOvrdReg0 {
	struct {
		uint32 txpwr2: 3; // 0
		uint32 incoherentck2: 1; // 3
		uint32 txmarg2: 3; // 4
		uint32 deemph2: 1; // 7
		uint32 coefficientid2: 2; // 8
		uint32 coefficient2: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE3_CTRL_REG0
union Pb1TxLane3CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode3: 1; // 0
		uint32 txCfgInvData3: 1; // 1
		uint32 txCfgSwingBoostEn3: 1; // 2
		uint32 txDbgPrbsEn3: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE3_OVRD_REG0
union Pb1TxLane3OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal3: 1; // 0
		uint32 txDclkEnOvrdEn3: 1; // 1
		uint32 txDrvDataEnOvrdVal3: 1; // 2
		uint32 txDrvDataEnOvrdEn3: 1; // 3
		uint32 txDrvPwronOvrdVal3: 1; // 4
		uint32 txDrvPwronOvrdEn3: 1; // 5
		uint32 txFrontendPwronOvrdVal3: 1; // 6
		uint32 txFrontendPwronOvrdEn3: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE3_SCI_STAT_OVRD_REG0
union Pb1TxLane3SciStatOvrdReg0 {
	struct {
		uint32 txpwr3: 3; // 0
		uint32 incoherentck3: 1; // 3
		uint32 txmarg3: 3; // 4
		uint32 deemph3: 1; // 7
		uint32 coefficientid3: 2; // 8
		uint32 coefficient3: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE4_CTRL_REG0
union Pb1TxLane4CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode4: 1; // 0
		uint32 txCfgInvData4: 1; // 1
		uint32 txCfgSwingBoostEn4: 1; // 2
		uint32 txDbgPrbsEn4: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE4_OVRD_REG0
union Pb1TxLane4OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal4: 1; // 0
		uint32 txDclkEnOvrdEn4: 1; // 1
		uint32 txDrvDataEnOvrdVal4: 1; // 2
		uint32 txDrvDataEnOvrdEn4: 1; // 3
		uint32 txDrvPwronOvrdVal4: 1; // 4
		uint32 txDrvPwronOvrdEn4: 1; // 5
		uint32 txFrontendPwronOvrdVal4: 1; // 6
		uint32 txFrontendPwronOvrdEn4: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE4_SCI_STAT_OVRD_REG0
union Pb1TxLane4SciStatOvrdReg0 {
	struct {
		uint32 txpwr4: 3; // 0
		uint32 incoherentck4: 1; // 3
		uint32 txmarg4: 3; // 4
		uint32 deemph4: 1; // 7
		uint32 coefficientid4: 2; // 8
		uint32 coefficient4: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE5_CTRL_REG0
union Pb1TxLane5CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode5: 1; // 0
		uint32 txCfgInvData5: 1; // 1
		uint32 txCfgSwingBoostEn5: 1; // 2
		uint32 txDbgPrbsEn5: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE5_OVRD_REG0
union Pb1TxLane5OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal5: 1; // 0
		uint32 txDclkEnOvrdEn5: 1; // 1
		uint32 txDrvDataEnOvrdVal5: 1; // 2
		uint32 txDrvDataEnOvrdEn5: 1; // 3
		uint32 txDrvPwronOvrdVal5: 1; // 4
		uint32 txDrvPwronOvrdEn5: 1; // 5
		uint32 txFrontendPwronOvrdVal5: 1; // 6
		uint32 txFrontendPwronOvrdEn5: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE5_SCI_STAT_OVRD_REG0
union Pb1TxLane5SciStatOvrdReg0 {
	struct {
		uint32 txpwr5: 3; // 0
		uint32 incoherentck5: 1; // 3
		uint32 txmarg5: 3; // 4
		uint32 deemph5: 1; // 7
		uint32 coefficientid5: 2; // 8
		uint32 coefficient5: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE6_CTRL_REG0
union Pb1TxLane6CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode6: 1; // 0
		uint32 txCfgInvData6: 1; // 1
		uint32 txCfgSwingBoostEn6: 1; // 2
		uint32 txDbgPrbsEn6: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE6_OVRD_REG0
union Pb1TxLane6OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal6: 1; // 0
		uint32 txDclkEnOvrdEn6: 1; // 1
		uint32 txDrvDataEnOvrdVal6: 1; // 2
		uint32 txDrvDataEnOvrdEn6: 1; // 3
		uint32 txDrvPwronOvrdVal6: 1; // 4
		uint32 txDrvPwronOvrdEn6: 1; // 5
		uint32 txFrontendPwronOvrdVal6: 1; // 6
		uint32 txFrontendPwronOvrdEn6: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE6_SCI_STAT_OVRD_REG0
union Pb1TxLane6SciStatOvrdReg0 {
	struct {
		uint32 txpwr6: 3; // 0
		uint32 incoherentck6: 1; // 3
		uint32 txmarg6: 3; // 4
		uint32 deemph6: 1; // 7
		uint32 coefficientid6: 2; // 8
		uint32 coefficient6: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE7_CTRL_REG0
union Pb1TxLane7CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode7: 1; // 0
		uint32 txCfgInvData7: 1; // 1
		uint32 txCfgSwingBoostEn7: 1; // 2
		uint32 txDbgPrbsEn7: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE7_OVRD_REG0
union Pb1TxLane7OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal7: 1; // 0
		uint32 txDclkEnOvrdEn7: 1; // 1
		uint32 txDrvDataEnOvrdVal7: 1; // 2
		uint32 txDrvDataEnOvrdEn7: 1; // 3
		uint32 txDrvPwronOvrdVal7: 1; // 4
		uint32 txDrvPwronOvrdEn7: 1; // 5
		uint32 txFrontendPwronOvrdVal7: 1; // 6
		uint32 txFrontendPwronOvrdEn7: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE7_SCI_STAT_OVRD_REG0
union Pb1TxLane7SciStatOvrdReg0 {
	struct {
		uint32 txpwr7: 3; // 0
		uint32 incoherentck7: 1; // 3
		uint32 txmarg7: 3; // 4
		uint32 deemph7: 1; // 7
		uint32 coefficientid7: 2; // 8
		uint32 coefficient7: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE8_CTRL_REG0
union Pb1TxLane8CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode8: 1; // 0
		uint32 txCfgInvData8: 1; // 1
		uint32 txCfgSwingBoostEn8: 1; // 2
		uint32 txDbgPrbsEn8: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE8_OVRD_REG0
union Pb1TxLane8OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal8: 1; // 0
		uint32 txDclkEnOvrdEn8: 1; // 1
		uint32 txDrvDataEnOvrdVal8: 1; // 2
		uint32 txDrvDataEnOvrdEn8: 1; // 3
		uint32 txDrvPwronOvrdVal8: 1; // 4
		uint32 txDrvPwronOvrdEn8: 1; // 5
		uint32 txFrontendPwronOvrdVal8: 1; // 6
		uint32 txFrontendPwronOvrdEn8: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE8_SCI_STAT_OVRD_REG0
union Pb1TxLane8SciStatOvrdReg0 {
	struct {
		uint32 txpwr8: 3; // 0
		uint32 incoherentck8: 1; // 3
		uint32 txmarg8: 3; // 4
		uint32 deemph8: 1; // 7
		uint32 coefficientid8: 2; // 8
		uint32 coefficient8: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PB1_TX_LANE9_CTRL_REG0
union Pb1TxLane9CtrlReg0 {
	struct {
		uint32 txCfgDispclkMode9: 1; // 0
		uint32 txCfgInvData9: 1; // 1
		uint32 txCfgSwingBoostEn9: 1; // 2
		uint32 txDbgPrbsEn9: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PB1_TX_LANE9_OVRD_REG0
union Pb1TxLane9OvrdReg0 {
	struct {
		uint32 txDclkEnOvrdVal9: 1; // 0
		uint32 txDclkEnOvrdEn9: 1; // 1
		uint32 txDrvDataEnOvrdVal9: 1; // 2
		uint32 txDrvDataEnOvrdEn9: 1; // 3
		uint32 txDrvPwronOvrdVal9: 1; // 4
		uint32 txDrvPwronOvrdEn9: 1; // 5
		uint32 txFrontendPwronOvrdVal9: 1; // 6
		uint32 txFrontendPwronOvrdEn9: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PB1_TX_LANE9_SCI_STAT_OVRD_REG0
union Pb1TxLane9SciStatOvrdReg0 {
	struct {
		uint32 txpwr9: 3; // 0
		uint32 incoherentck9: 1; // 3
		uint32 txmarg9: 3; // 4
		uint32 deemph9: 1; // 7
		uint32 coefficientid9: 2; // 8
		uint32 coefficient9: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PCIEP_HW_DEBUG
union PciepHwDebug {
	struct {
		uint32 hw00Debug: 1; // 0
		uint32 hw01Debug: 1; // 1
		uint32 hw02Debug: 1; // 2
		uint32 hw03Debug: 1; // 3
		uint32 hw04Debug: 1; // 4
		uint32 hw05Debug: 1; // 5
		uint32 hw06Debug: 1; // 6
		uint32 hw07Debug: 1; // 7
		uint32 hw08Debug: 1; // 8
		uint32 hw09Debug: 1; // 9
		uint32 hw10Debug: 1; // 10
		uint32 hw11Debug: 1; // 11
		uint32 hw12Debug: 1; // 12
		uint32 hw13Debug: 1; // 13
		uint32 hw14Debug: 1; // 14
		uint32 hw15Debug: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PCIEP_PORT_CNTL
union PciepPortCntl {
	struct {
		uint32 slvPortReqEn: 1; // 0
		uint32 ciSnoopOverride: 1; // 1
		uint32 hotplugMsgEn: 1; // 2
		uint32 nativePmeEn: 1; // 3
		uint32 pwrFaultEn: 1; // 4
		uint32 pmiBmDis: 1; // 5
		uint32 seqnumDebugMode: 1; // 6
		uint32 unknown1: 1;
		uint32 ciSlvCplStaticAllocLimitS: 7; // 8
		uint32 unknown2: 17;
	};
	uint32 val;
};

// PCIEP_RESERVED
union PciepReserved {
	struct {
		uint32 pciepReserved: 32; // 0
	};
	uint32 val;
};

// PCIEP_SCRATCH
union PciepScratch {
	struct {
		uint32 pciepScratch: 32; // 0
	};
	uint32 val;
};

// PCIEP_STRAP_LC
union PciepStrapLc {
	struct {
		uint32 strapFtsYtsxCount: 2; // 0
		uint32 strapLongYtsxCount: 2; // 2
		uint32 strapMedYtsxCount: 2; // 4
		uint32 strapShortYtsxCount: 2; // 6
		uint32 strapSkipInterval: 3; // 8
		uint32 strapBypassRcvrDet: 1; // 11
		uint32 strapComplianceDis: 1; // 12
		uint32 strapForceCompliance: 1; // 13
		uint32 strapReverseLcLanes: 1; // 14
		uint32 strapAutoRcSpeedNegotiationDis: 1; // 15
		uint32 strapLaneNegotiation: 3; // 16
		uint32 unknown1: 13;
	};
	uint32 val;
};

// PCIEP_STRAP_MISC
union PciepStrapMisc {
	struct {
		uint32 strapReverseLanes: 1; // 0
		uint32 strapE2ePrefixEn: 1; // 1
		uint32 strapExtendedFmtSupported: 1; // 2
		uint32 strapObffSupported: 2; // 3
		uint32 unknown1: 27;
	};
	uint32 val;
};

// PCIE_BUS_CNTL
union PcieBusCntl {
	struct {
		uint32 unknown1: 6;
		uint32 pmiIntDis: 1; // 6
		uint32 immediatePmiDis: 1; // 7
		uint32 unknown2: 24;
	};
	uint32 val;
};

// PCIE_CFG_CNTL
union PcieCfgCntl {
	struct {
		uint32 cfgEnDecToGen2HiddenReg: 1; // 0
		uint32 cfgEnDecToHiddenReg: 1; // 1
		uint32 cfgEnDecToGen3HiddenReg: 1; // 2
		uint32 unknown1: 29;
	};
	uint32 val;
};

// PCIE_CI_CNTL
union PcieCiCntl {
	struct {
		uint32 unknown1: 2;
		uint32 ciSlaveSplitMode: 1; // 2
		uint32 ciSlaveGenUsrDis: 1; // 3
		uint32 ciMstCmplDummyData: 1; // 4
		uint32 unknown2: 1;
		uint32 ciSlvRcRdReqSize: 2; // 6
		uint32 ciSlvOrderingDis: 1; // 8
		uint32 ciRcOrderingDis: 1; // 9
		uint32 ciSlvCplAllocDis: 1; // 10
		uint32 ciSlvCplAllocMode: 1; // 11
		uint32 ciSlvCplAllocSor: 1; // 12
		uint32 ciMstIgnorePageAlignedRequest: 1; // 13
		uint32 unknown3: 18;
	};
	uint32 val;
};

// PCIE_CNTL
union PcieCntl {
	struct {
		uint32 hwinitWrLock: 1; // 0
		uint32 lcHotPlugDelaySel: 3; // 1
		uint32 unknown1: 3;
		uint32 urErrReportDis: 1; // 7
		uint32 pcieMalformAtomicOps: 1; // 8
		uint32 pcieHtNpMemWrite: 1; // 9
		uint32 rxSbAdjPayloadSize: 3; // 10
		uint32 unknown2: 2;
		uint32 rxRcbAtsUcDis: 1; // 15
		uint32 rxRcbReorderEn: 1; // 16
		uint32 rxRcbInvalidSizeDis: 1; // 17
		uint32 rxRcbUnexpCplDis: 1; // 18
		uint32 rxRcbCplTimeoutTestMode: 1; // 19
		uint32 rxRcbChannelOrdering: 1; // 20
		uint32 rxRcbWrongAttrDis: 1; // 21
		uint32 rxRcbWrongFuncnumDis: 1; // 22
		uint32 rxAtsTranCplSplitDis: 1; // 23
		uint32 txCplDebug: 6; // 24
		uint32 unknown3: 1;
		uint32 rxCplPostedReqOrdEn: 1; // 31
	};
	uint32 val;
};

// PCIE_CNTL2
union PcieCntl2 {
	struct {
		uint32 txArbRoundRobinEn: 1; // 0
		uint32 txArbSlvLimit: 5; // 1
		uint32 txArbMstLimit: 5; // 6
		uint32 unknown1: 5;
		uint32 slvMemLsEn: 1; // 16
		uint32 slvMemAggressiveLsEn: 1; // 17
		uint32 mstMemLsEn: 1; // 18
		uint32 replayMemLsEn: 1; // 19
		uint32 slvMemSdEn: 1; // 20
		uint32 slvMemAggressiveSdEn: 1; // 21
		uint32 mstMemSdEn: 1; // 22
		uint32 replayMemSdEn: 1; // 23
		uint32 rxNpMemWriteEncoding: 5; // 24
		uint32 unknown2: 3;
	};
	uint32 val;
};

// PCIE_CONFIG_CNTL
union PcieConfigCntl {
	struct {
		uint32 dynClkLatency: 4; // 0
		uint32 unknown1: 12;
		uint32 ciMaxPayloadSizeMode: 1; // 16
		uint32 ciPrivMaxPayloadSize: 3; // 17
		uint32 ciMaxReadRequestSizeMode: 1; // 20
		uint32 ciPrivMaxReadRequestSize: 3; // 21
		uint32 ciMaxReadSafeMode: 1; // 24
		uint32 ciExtendedTagEnOverride: 1; // 25
		uint32 unknown2: 6;
	};
	uint32 val;
};

// PCIE_DATA
union PcieData {
	struct {
		uint32 pcieData: 32; // 0
	};
	uint32 val;
};

// PCIE_DEBUG_CNTL
union PcieDebugCntl {
	struct {
		uint32 debugPortEn: 8; // 0
		uint32 debugSelect: 1; // 8
		uint32 unknown1: 7;
		uint32 debugLaneEn: 16; // 16
	};
	uint32 val;
};

// PCIE_ERR_CNTL
union PcieErrCntl {
	struct {
		uint32 errReportingDis: 1; // 0
		uint32 strapFirstRcvdErrLog: 1; // 1
		uint32 unknown1: 2;
		uint32 txGenerateLcrcErr: 1; // 4
		uint32 rxGenerateLcrcErr: 1; // 5
		uint32 txGenerateEcrcErr: 1; // 6
		uint32 rxGenerateEcrcErr: 1; // 7
		uint32 aerHdrLogTimeout: 3; // 8
		uint32 aerHdrLogF0TimerExpired: 1; // 11
		uint32 aerHdrLogF1TimerExpired: 1; // 12
		uint32 aerHdrLogF2TimerExpired: 1; // 13
		uint32 ciPSlvBufRdHaltStatus: 1; // 14
		uint32 ciNpSlvBufRdHaltStatus: 1; // 15
		uint32 ciSlvBufHaltReset: 1; // 16
		uint32 unknown2: 15;
	};
	uint32 val;
};

// PCIE_F0_DPA_CAP
union PcieF0DpaCap {
	struct {
		uint32 unknown1: 8;
		uint32 transLatUnit: 2; // 8
		uint32 unknown2: 2;
		uint32 pwrAllocScale: 2; // 12
		uint32 unknown3: 2;
		uint32 transLatVal0: 8; // 16
		uint32 transLatVal1: 8; // 24
	};
	uint32 val;
};

// PCIE_F0_DPA_CNTL
union PcieF0DpaCntl {
	struct {
		uint32 substateStatus: 5; // 0
		uint32 unknown1: 27;
	};
	uint32 val;
};

// PCIE_F0_DPA_LATENCY_INDICATOR
union PcieF0DpaLatencyIndicator {
	struct {
		uint32 transLatIndicatorBits: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_F0_DPA_SUBSTATE_PWR_ALLOC_0
union PcieF0DpaSubstatePwrAlloc0 {
	struct {
		uint32 substatePwrAlloc: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_F0_DPA_SUBSTATE_PWR_ALLOC_1
union PcieF0DpaSubstatePwrAlloc1 {
	struct {
		uint32 substatePwrAlloc: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_F0_DPA_SUBSTATE_PWR_ALLOC_2
union PcieF0DpaSubstatePwrAlloc2 {
	struct {
		uint32 substatePwrAlloc: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_F0_DPA_SUBSTATE_PWR_ALLOC_3
union PcieF0DpaSubstatePwrAlloc3 {
	struct {
		uint32 substatePwrAlloc: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_F0_DPA_SUBSTATE_PWR_ALLOC_4
union PcieF0DpaSubstatePwrAlloc4 {
	struct {
		uint32 substatePwrAlloc: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_F0_DPA_SUBSTATE_PWR_ALLOC_5
union PcieF0DpaSubstatePwrAlloc5 {
	struct {
		uint32 substatePwrAlloc: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_F0_DPA_SUBSTATE_PWR_ALLOC_6
union PcieF0DpaSubstatePwrAlloc6 {
	struct {
		uint32 substatePwrAlloc: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_F0_DPA_SUBSTATE_PWR_ALLOC_7
union PcieF0DpaSubstatePwrAlloc7 {
	struct {
		uint32 substatePwrAlloc: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_FC_CPL
union PcieFcCpl {
	struct {
		uint32 cpldCredits: 8; // 0
		uint32 cplhCredits: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PCIE_FC_NP
union PcieFcNp {
	struct {
		uint32 npdCredits: 8; // 0
		uint32 nphCredits: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PCIE_FC_P
union PcieFcP {
	struct {
		uint32 pdCredits: 8; // 0
		uint32 phCredits: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PCIE_HW_DEBUG
union PcieHwDebug {
	struct {
		uint32 hw00Debug: 1; // 0
		uint32 hw01Debug: 1; // 1
		uint32 hw02Debug: 1; // 2
		uint32 hw03Debug: 1; // 3
		uint32 hw04Debug: 1; // 4
		uint32 hw05Debug: 1; // 5
		uint32 hw06Debug: 1; // 6
		uint32 hw07Debug: 1; // 7
		uint32 hw08Debug: 1; // 8
		uint32 hw09Debug: 1; // 9
		uint32 hw10Debug: 1; // 10
		uint32 hw11Debug: 1; // 11
		uint32 hw12Debug: 1; // 12
		uint32 hw13Debug: 1; // 13
		uint32 hw14Debug: 1; // 14
		uint32 hw15Debug: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PCIE_I2C_REG_ADDR_EXPAND
union PcieI2cRegAddrExpand {
	struct {
		uint32 i2cRegAddr: 17; // 0
		uint32 unknown1: 15;
	};
	uint32 val;
};

// PCIE_I2C_REG_DATA
union PcieI2cRegData {
	struct {
		uint32 i2cRegData: 32; // 0
	};
	uint32 val;
};

// PCIE_INDEX
union PcieIndex {
	struct {
		uint32 pcieIndex: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_INT_CNTL
union PcieIntCntl {
	struct {
		uint32 corrErrIntEn: 1; // 0
		uint32 nonFatalErrIntEn: 1; // 1
		uint32 fatalErrIntEn: 1; // 2
		uint32 usrDetectedIntEn: 1; // 3
		uint32 miscErrIntEn: 1; // 4
		uint32 unknown1: 1;
		uint32 powerStateChgIntEn: 1; // 6
		uint32 linkBwIntEn: 1; // 7
		uint32 quiesceRcvdIntEn: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// PCIE_INT_STATUS
union PcieIntStatus {
	struct {
		uint32 corrErrIntStatus: 1; // 0
		uint32 nonFatalErrIntStatus: 1; // 1
		uint32 fatalErrIntStatus: 1; // 2
		uint32 usrDetectedIntStatus: 1; // 3
		uint32 miscErrIntStatus: 1; // 4
		uint32 unknown1: 1;
		uint32 powerStateChgIntStatus: 1; // 6
		uint32 linkBwIntStatus: 1; // 7
		uint32 quiesceRcvdIntStatus: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// PCIE_LC_BEST_EQ_SETTINGS
union PcieLcBestEqSettings {
	struct {
		uint32 lcBestPreset: 4; // 0
		uint32 lcBestPrecursor: 6; // 4
		uint32 lcBestCursor: 6; // 10
		uint32 lcBestPostcursor: 6; // 16
		uint32 lcBestFom: 8; // 22
		uint32 unknown1: 2;
	};
	uint32 val;
};

// PCIE_LC_BW_CHANGE_CNTL
union PcieLcBwChangeCntl {
	struct {
		uint32 lcBwChangeIntEn: 1; // 0
		uint32 lcHwInitSpeedChange: 1; // 1
		uint32 lcSwInitSpeedChange: 1; // 2
		uint32 lcOtherInitSpeedChange: 1; // 3
		uint32 lcReliabilitySpeedChange: 1; // 4
		uint32 lcFailedSpeedNeg: 1; // 5
		uint32 lcLongLwChange: 1; // 6
		uint32 lcShortLwChange: 1; // 7
		uint32 lcLwChangeOther: 1; // 8
		uint32 lcLwChangeFailed: 1; // 9
		uint32 lcLinkBwNotificationDetectMode: 1; // 10
		uint32 unknown1: 21;
	};
	uint32 val;
};

// PCIE_LC_CDR_CNTL
union PcieLcCdrCntl {
	struct {
		uint32 lcCdrTestOff: 12; // 0
		uint32 lcCdrTestSets: 12; // 12
		uint32 lcCdrSetType: 2; // 24
		uint32 unknown1: 6;
	};
	uint32 val;
};

// PCIE_LC_CNTL
union PcieLcCntl {
	struct {
		uint32 unknown1: 1;
		uint32 lcDontEnterL23InD0: 1; // 1
		uint32 lcResetLIdleCountEn: 1; // 2
		uint32 lcResetLink: 1; // 3
		uint32 lc16xClearTxPipe: 4; // 4
		uint32 lcL0sInactivity: 4; // 8
		uint32 lcL1Inactivity: 4; // 12
		uint32 lcPmiToL1Dis: 1; // 16
		uint32 lcIncNFtsEn: 1; // 17
		uint32 lcLookForIdleInL1l23: 2; // 18
		uint32 lcFactorInExtSync: 1; // 20
		uint32 lcWaitForPmAckDis: 1; // 21
		uint32 lcWakeFromL23: 1; // 22
		uint32 lcL1ImmediateAck: 1; // 23
		uint32 lcAspmToL1Dis: 1; // 24
		uint32 lcDelayCount: 2; // 25
		uint32 lcDelayL0sExit: 1; // 27
		uint32 lcDelayL1Exit: 1; // 28
		uint32 lcExtendWaitForElIdle: 1; // 29
		uint32 lcEscapeL1l23En: 1; // 30
		uint32 lcGateRcvrIdle: 1; // 31
	};
	uint32 val;
};

// PCIE_LC_CNTL2
union PcieLcCntl2 {
	struct {
		uint32 lcTimedOutState: 6; // 0
		uint32 lcStateTimedOut: 1; // 6
		uint32 lcLookForBwReduction: 1; // 7
		uint32 lcMoreTs2En: 1; // 8
		uint32 lcX12NegotiationDis: 1; // 9
		uint32 lcLinkUpReversalEn: 1; // 10
		uint32 lcIllegalState: 1; // 11
		uint32 lcIllegalStateRestartEn: 1; // 12
		uint32 lcWaitForOtherLanesMode: 1; // 13
		uint32 lcElecIdleMode: 2; // 14
		uint32 lcDisableInferredElecIdleDet: 1; // 16
		uint32 lcAllowPdwnInL1: 1; // 17
		uint32 lcAllowPdwnInL23: 1; // 18
		uint32 lcDeassertRxEnInL0s: 1; // 19
		uint32 lcBlockElIdleInL0: 1; // 20
		uint32 lcRcvL0ToRcvL0sDis: 1; // 21
		uint32 lcAssertInactiveDuringHold: 1; // 22
		uint32 lcWaitForLanesInLwNeg: 2; // 23
		uint32 lcPwrDownNegOffLanes: 1; // 25
		uint32 lcDisableLostSymLockArcs: 1; // 26
		uint32 lcLinkBwNotificationDis: 1; // 27
		uint32 lcPmiL1WaitForSlvIdle: 1; // 28
		uint32 lcTestTimerSel: 2; // 29
		uint32 lcEnableInferredElecIdleForPi: 1; // 31
	};
	uint32 val;
};

// PCIE_LC_CNTL3
union PcieLcCntl3 {
	struct {
		uint32 lcSelectDeemphasis: 1; // 0
		uint32 lcSelectDeemphasisCntl: 2; // 1
		uint32 lcRcvdDeemphasis: 1; // 3
		uint32 lcCompToDetect: 1; // 4
		uint32 lcResetTsxCntInRlockEn: 1; // 5
		uint32 lcAutoSpeedChangeAttemptsAllowed: 2; // 6
		uint32 lcAutoSpeedChangeAttemptFailed: 1; // 8
		uint32 lcClrFailedAutoSpdChangeCnt: 1; // 9
		uint32 lcEnhancedHotPlugEn: 1; // 10
		uint32 lcRcvrDetEnOverride: 1; // 11
		uint32 lcEhpRxPhyCmd: 2; // 12
		uint32 lcEhpTxPhyCmd: 2; // 14
		uint32 lcChipBifUsbIdleEn: 1; // 16
		uint32 lcL1BlockReconfigEn: 1; // 17
		uint32 lcAutoDisableSpeedSupportEn: 1; // 18
		uint32 lcAutoDisableSpeedSupportMaxFailSel: 2; // 19
		uint32 lcFastL1EntryExitEn: 1; // 21
		uint32 lcRxphycmdInactiveEnMode: 1; // 22
		uint32 lcDscDontEnterL23AfterPmeAck: 1; // 23
		uint32 lcHwVoltageIfControl: 2; // 24
		uint32 lcVoltageTimerSel: 4; // 26
		uint32 lcGoToRecovery: 1; // 30
		uint32 lcNEieSel: 1; // 31
	};
	uint32 val;
};

// PCIE_LC_CNTL4
union PcieLcCntl4 {
	struct {
		uint32 lcTxEnableBehaviour: 2; // 0
		uint32 unknown1: 2;
		uint32 lcBypassEq: 1; // 4
		uint32 lcRedoEq: 1; // 5
		uint32 lcExtendEieos: 1; // 6
		uint32 lcIgnoreParity: 1; // 7
		uint32 lcEqSearchMode: 2; // 8
		uint32 lcDscCheckCoeffsInRlock: 1; // 10
		uint32 lcUscEqNotReqd: 1; // 11
		uint32 lcUscGoToEq: 1; // 12
		uint32 lcSetQuiesce: 1; // 13
		uint32 lcQuiesceRcvd: 1; // 14
		uint32 lcUnexpectedCoeffsRcvd: 1; // 15
		uint32 lcBypassEqReqPhase: 1; // 16
		uint32 lcForcePresetInEqReqPhase: 1; // 17
		uint32 lcForcePresetValue: 4; // 18
		uint32 lcUscDelayDllps: 1; // 22
		uint32 lcPcieTxFullSwing: 1; // 23
		uint32 lcEqWaitForEvalDone: 1; // 24
		uint32 lc8gtSkipOrderEn: 1; // 25
		uint32 lcWaitForMoreTsInRlock: 6; // 26
	};
	uint32 val;
};

// PCIE_LC_CNTL5
union PcieLcCntl5 {
	struct {
		uint32 lcEqFs0: 6; // 0
		uint32 lcEqFs8: 6; // 6
		uint32 lcEqLf0: 6; // 12
		uint32 lcEqLf8: 6; // 18
		uint32 unknown1: 8;
	};
	uint32 val;
};

// PCIE_LC_FORCE_COEFF
union PcieLcForceCoeff {
	struct {
		uint32 lcForceCoeff: 1; // 0
		uint32 lcForcePreCursor: 6; // 1
		uint32 lcForceCursor: 6; // 7
		uint32 lcForcePostCursor: 6; // 13
		uint32 lc3x3CoeffSearchEn: 1; // 19
		uint32 unknown1: 12;
	};
	uint32 val;
};

// PCIE_LC_FORCE_EQ_REQ_COEFF
union PcieLcForceEqReqCoeff {
	struct {
		uint32 lcForceCoeffInEqReqPhase: 1; // 0
		uint32 lcForcePreCursorReq: 6; // 1
		uint32 lcForceCursorReq: 6; // 7
		uint32 lcForcePostCursorReq: 6; // 13
		uint32 lcFsOtherEnd: 6; // 19
		uint32 lcLfOtherEnd: 6; // 25
		uint32 unknown1: 1;
	};
	uint32 val;
};

// PCIE_LC_LANE_CNTL
union PcieLcLaneCntl {
	struct {
		uint32 lcCorruptedLanes: 16; // 0
		uint32 lcLaneDis: 16; // 16
	};
	uint32 val;
};

// PCIE_LC_LINK_WIDTH_CNTL
union PcieLcLinkWidthCntl {
	struct {
		uint32 lcLinkWidth: 3; // 0
		uint32 unknown1: 1;
		uint32 lcLinkWidthRd: 3; // 4
		uint32 lcReconfigArcMissingEscape: 1; // 7
		uint32 lcReconfigNow: 1; // 8
		uint32 lcRenegotiationSupport: 1; // 9
		uint32 lcRenegotiateEn: 1; // 10
		uint32 lcShortReconfigEn: 1; // 11
		uint32 lcUpconfigureSupport: 1; // 12
		uint32 lcUpconfigureDis: 1; // 13
		uint32 lcUpcfgWaitForRcvrDis: 1; // 14
		uint32 lcUpcfgTimerSel: 1; // 15
		uint32 lcDeassertTxPdnb: 1; // 16
		uint32 lcL1ReconfigEn: 1; // 17
		uint32 lcDynlinkMstEn: 1; // 18
		uint32 lcDualEndReconfigEn: 1; // 19
		uint32 lcUpconfigureCapable: 1; // 20
		uint32 lcDynLanesPwrState: 2; // 21
		uint32 lcEqReversalLogicEn: 1; // 23
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PCIE_LC_N_FTS_CNTL
union PcieLcNFtsCntl {
	struct {
		uint32 lcXmitNFts: 8; // 0
		uint32 lcXmitNFtsOverrideEn: 1; // 8
		uint32 lcXmitFtsBeforeRecovery: 1; // 9
		uint32 unknown1: 6;
		uint32 lcXmitNFtsLimit: 8; // 16
		uint32 lcNFts: 8; // 24
	};
	uint32 val;
};

// PCIE_LC_SPEED_CNTL
union PcieLcSpeedCntl {
	struct {
		uint32 lcGen2EnStrap: 1; // 0
		uint32 lcGen3EnStrap: 1; // 1
		uint32 lcTargetLinkSpeedOverrideEn: 1; // 2
		uint32 lcTargetLinkSpeedOverride: 2; // 3
		uint32 lcForceEnSwSpeedChange: 1; // 5
		uint32 lcForceDisSwSpeedChange: 1; // 6
		uint32 lcForceEnHwSpeedChange: 1; // 7
		uint32 lcForceDisHwSpeedChange: 1; // 8
		uint32 lcInitiateLinkSpeedChange: 1; // 9
		uint32 lcSpeedChangeAttemptsAllowed: 2; // 10
		uint32 lcSpeedChangeAttemptFailed: 1; // 12
		uint32 lcCurrentDataRate: 2; // 13
		uint32 lcDontClrTargetSpdChangeStatus: 1; // 15
		uint32 lcClrFailedSpdChangeCnt: 1; // 16
		uint32 lc1OrMoreTs2SpeedArcEn: 1; // 17
		uint32 lcOtherSideEverSentGen2: 1; // 18
		uint32 lcOtherSideSupportsGen2: 1; // 19
		uint32 lcOtherSideEverSentGen3: 1; // 20
		uint32 lcOtherSideSupportsGen3: 1; // 21
		uint32 lcAutoRecoveryDis: 1; // 22
		uint32 lcSpeedChangeStatus: 1; // 23
		uint32 lcDataRateAdvertised: 2; // 24
		uint32 lcCheckDataRate: 1; // 26
		uint32 lcMultUpstreamAutoSpdChngEn: 1; // 27
		uint32 lcInitSpeedNegInL0sEn: 1; // 28
		uint32 lcInitSpeedNegInL1En: 1; // 29
		uint32 lcDontCheckEqtsInRcfg: 1; // 30
		uint32 lcDelayCoeffUpdateDis: 1; // 31
	};
	uint32 val;
};

// PCIE_LC_STATE0
union PcieLcState0 {
	struct {
		uint32 lcCurrentState: 6; // 0
		uint32 unknown1: 2;
		uint32 lcPrevState1: 6; // 8
		uint32 unknown2: 2;
		uint32 lcPrevState2: 6; // 16
		uint32 unknown3: 2;
		uint32 lcPrevState3: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// PCIE_LC_STATE1
union PcieLcState1 {
	struct {
		uint32 lcPrevState4: 6; // 0
		uint32 unknown1: 2;
		uint32 lcPrevState5: 6; // 8
		uint32 unknown2: 2;
		uint32 lcPrevState6: 6; // 16
		uint32 unknown3: 2;
		uint32 lcPrevState7: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// PCIE_LC_STATE10
union PcieLcState10 {
	struct {
		uint32 lcPrevState40: 6; // 0
		uint32 unknown1: 2;
		uint32 lcPrevState41: 6; // 8
		uint32 unknown2: 2;
		uint32 lcPrevState42: 6; // 16
		uint32 unknown3: 2;
		uint32 lcPrevState43: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// PCIE_LC_STATE11
union PcieLcState11 {
	struct {
		uint32 lcPrevState44: 6; // 0
		uint32 unknown1: 2;
		uint32 lcPrevState45: 6; // 8
		uint32 unknown2: 2;
		uint32 lcPrevState46: 6; // 16
		uint32 unknown3: 2;
		uint32 lcPrevState47: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// PCIE_LC_STATE2
union PcieLcState2 {
	struct {
		uint32 lcPrevState8: 6; // 0
		uint32 unknown1: 2;
		uint32 lcPrevState9: 6; // 8
		uint32 unknown2: 2;
		uint32 lcPrevState10: 6; // 16
		uint32 unknown3: 2;
		uint32 lcPrevState11: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// PCIE_LC_STATE3
union PcieLcState3 {
	struct {
		uint32 lcPrevState12: 6; // 0
		uint32 unknown1: 2;
		uint32 lcPrevState13: 6; // 8
		uint32 unknown2: 2;
		uint32 lcPrevState14: 6; // 16
		uint32 unknown3: 2;
		uint32 lcPrevState15: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// PCIE_LC_STATE4
union PcieLcState4 {
	struct {
		uint32 lcPrevState16: 6; // 0
		uint32 unknown1: 2;
		uint32 lcPrevState17: 6; // 8
		uint32 unknown2: 2;
		uint32 lcPrevState18: 6; // 16
		uint32 unknown3: 2;
		uint32 lcPrevState19: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// PCIE_LC_STATE5
union PcieLcState5 {
	struct {
		uint32 lcPrevState20: 6; // 0
		uint32 unknown1: 2;
		uint32 lcPrevState21: 6; // 8
		uint32 unknown2: 2;
		uint32 lcPrevState22: 6; // 16
		uint32 unknown3: 2;
		uint32 lcPrevState23: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// PCIE_LC_STATE6
union PcieLcState6 {
	struct {
		uint32 lcPrevState24: 6; // 0
		uint32 unknown1: 2;
		uint32 lcPrevState25: 6; // 8
		uint32 unknown2: 2;
		uint32 lcPrevState26: 6; // 16
		uint32 unknown3: 2;
		uint32 lcPrevState27: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// PCIE_LC_STATE7
union PcieLcState7 {
	struct {
		uint32 lcPrevState28: 6; // 0
		uint32 unknown1: 2;
		uint32 lcPrevState29: 6; // 8
		uint32 unknown2: 2;
		uint32 lcPrevState30: 6; // 16
		uint32 unknown3: 2;
		uint32 lcPrevState31: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// PCIE_LC_STATE8
union PcieLcState8 {
	struct {
		uint32 lcPrevState32: 6; // 0
		uint32 unknown1: 2;
		uint32 lcPrevState33: 6; // 8
		uint32 unknown2: 2;
		uint32 lcPrevState34: 6; // 16
		uint32 unknown3: 2;
		uint32 lcPrevState35: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// PCIE_LC_STATE9
union PcieLcState9 {
	struct {
		uint32 lcPrevState36: 6; // 0
		uint32 unknown1: 2;
		uint32 lcPrevState37: 6; // 8
		uint32 unknown2: 2;
		uint32 lcPrevState38: 6; // 16
		uint32 unknown3: 2;
		uint32 lcPrevState39: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// PCIE_LC_STATUS1
union PcieLcStatus1 {
	struct {
		uint32 lcReverseRcvr: 1; // 0
		uint32 lcReverseXmit: 1; // 1
		uint32 lcOperatingLinkWidth: 3; // 2
		uint32 lcDetectedLinkWidth: 3; // 5
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_LC_STATUS2
union PcieLcStatus2 {
	struct {
		uint32 lcTotalInactiveLanes: 16; // 0
		uint32 lcTurnOnLane: 16; // 16
	};
	uint32 val;
};

// PCIE_LC_TRAINING_CNTL
union PcieLcTrainingCntl {
	struct {
		uint32 lcTrainingCntl: 4; // 0
		uint32 lcComplianceReceive: 1; // 4
		uint32 lcLookForMoreNonMatchingTs1: 1; // 5
		uint32 lcL0sL1TrainingCntlEn: 1; // 6
		uint32 lcL1LongWakeFixEn: 1; // 7
		uint32 lcPowerState: 3; // 8
		uint32 lcDontGoToL0sIfL1Armed: 1; // 11
		uint32 lcInitSpdChgWithCsrEn: 1; // 12
		uint32 lcDisableTrainingBitArch: 1; // 13
		uint32 unknown1: 2;
		uint32 lcExtendWaitForSkp: 1; // 16
		uint32 lcAutonomousChangeOff: 1; // 17
		uint32 lcUpconfigureCapOff: 1; // 18
		uint32 lcHwLinkDisEn: 1; // 19
		uint32 lcLinkDisByHw: 1; // 20
		uint32 lcStaticTxPipeCountEn: 1; // 21
		uint32 lcAspmL1NakTimerSel: 2; // 22
		uint32 lcDontDeassertRxEnInRSpeed: 1; // 24
		uint32 lcDontDeassertRxEnInTest: 1; // 25
		uint32 lcResetAspmL1NakTimer: 1; // 26
		uint32 lcShortRcfgTimeout: 1; // 27
		uint32 lcAllowTxL1Control: 1; // 28
		uint32 lcWaitForFomValidAfterTrack: 1; // 29
		uint32 lcExtendEqReqTime: 2; // 30
	};
	uint32 val;
};

// PCIE_PERF_CNTL_EVENT0_PORT_SEL
union PciePerfCntlEvent0PortSel {
	struct {
		uint32 perf0PortSelTxclk: 4; // 0
		uint32 perf0PortSelMstRClk: 4; // 4
		uint32 perf0PortSelMstCClk: 4; // 8
		uint32 perf0PortSelSlvRClk: 4; // 12
		uint32 perf0PortSelSlvSCClk: 4; // 16
		uint32 perf0PortSelSlvNsCClk: 4; // 20
		uint32 perf0PortSelTxclk2: 4; // 24
		uint32 unknown1: 4;
	};
	uint32 val;
};

// PCIE_PERF_CNTL_EVENT1_PORT_SEL
union PciePerfCntlEvent1PortSel {
	struct {
		uint32 perf1PortSelTxclk: 4; // 0
		uint32 perf1PortSelMstRClk: 4; // 4
		uint32 perf1PortSelMstCClk: 4; // 8
		uint32 perf1PortSelSlvRClk: 4; // 12
		uint32 perf1PortSelSlvSCClk: 4; // 16
		uint32 perf1PortSelSlvNsCClk: 4; // 20
		uint32 perf1PortSelTxclk2: 4; // 24
		uint32 unknown1: 4;
	};
	uint32 val;
};

// PCIE_PERF_CNTL_MST_C_CLK
union PciePerfCntlMstCClk {
	struct {
		uint32 event0Sel: 8; // 0
		uint32 event1Sel: 8; // 8
		uint32 counter0Upper: 8; // 16
		uint32 counter1Upper: 8; // 24
	};
	uint32 val;
};

// PCIE_PERF_CNTL_MST_R_CLK
union PciePerfCntlMstRClk {
	struct {
		uint32 event0Sel: 8; // 0
		uint32 event1Sel: 8; // 8
		uint32 counter0Upper: 8; // 16
		uint32 counter1Upper: 8; // 24
	};
	uint32 val;
};

// PCIE_PERF_CNTL_SLV_NS_C_CLK
union PciePerfCntlSlvNsCClk {
	struct {
		uint32 event0Sel: 8; // 0
		uint32 event1Sel: 8; // 8
		uint32 counter0Upper: 8; // 16
		uint32 counter1Upper: 8; // 24
	};
	uint32 val;
};

// PCIE_PERF_CNTL_SLV_R_CLK
union PciePerfCntlSlvRClk {
	struct {
		uint32 event0Sel: 8; // 0
		uint32 event1Sel: 8; // 8
		uint32 counter0Upper: 8; // 16
		uint32 counter1Upper: 8; // 24
	};
	uint32 val;
};

// PCIE_PERF_CNTL_SLV_S_C_CLK
union PciePerfCntlSlvSCClk {
	struct {
		uint32 event0Sel: 8; // 0
		uint32 event1Sel: 8; // 8
		uint32 counter0Upper: 8; // 16
		uint32 counter1Upper: 8; // 24
	};
	uint32 val;
};

// PCIE_PERF_CNTL_TXCLK
union PciePerfCntlTxclk {
	struct {
		uint32 event0Sel: 8; // 0
		uint32 event1Sel: 8; // 8
		uint32 counter0Upper: 8; // 16
		uint32 counter1Upper: 8; // 24
	};
	uint32 val;
};

// PCIE_PERF_CNTL_TXCLK2
union PciePerfCntlTxclk2 {
	struct {
		uint32 event0Sel: 8; // 0
		uint32 event1Sel: 8; // 8
		uint32 counter0Upper: 8; // 16
		uint32 counter1Upper: 8; // 24
	};
	uint32 val;
};

// PCIE_PERF_COUNT0_MST_C_CLK
union PciePerfCount0MstCClk {
	struct {
		uint32 counter0: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT0_MST_R_CLK
union PciePerfCount0MstRClk {
	struct {
		uint32 counter0: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT0_SLV_NS_C_CLK
union PciePerfCount0SlvNsCClk {
	struct {
		uint32 counter0: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT0_SLV_R_CLK
union PciePerfCount0SlvRClk {
	struct {
		uint32 counter0: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT0_SLV_S_C_CLK
union PciePerfCount0SlvSCClk {
	struct {
		uint32 counter0: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT0_TXCLK
union PciePerfCount0Txclk {
	struct {
		uint32 counter0: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT0_TXCLK2
union PciePerfCount0Txclk2 {
	struct {
		uint32 counter0: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT1_MST_C_CLK
union PciePerfCount1MstCClk {
	struct {
		uint32 counter1: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT1_MST_R_CLK
union PciePerfCount1MstRClk {
	struct {
		uint32 counter1: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT1_SLV_NS_C_CLK
union PciePerfCount1SlvNsCClk {
	struct {
		uint32 counter1: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT1_SLV_R_CLK
union PciePerfCount1SlvRClk {
	struct {
		uint32 counter1: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT1_SLV_S_C_CLK
union PciePerfCount1SlvSCClk {
	struct {
		uint32 counter1: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT1_TXCLK
union PciePerfCount1Txclk {
	struct {
		uint32 counter1: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT1_TXCLK2
union PciePerfCount1Txclk2 {
	struct {
		uint32 counter1: 32; // 0
	};
	uint32 val;
};

// PCIE_PERF_COUNT_CNTL
union PciePerfCountCntl {
	struct {
		uint32 globalCountEn: 1; // 0
		uint32 globalShadowWr: 1; // 1
		uint32 globalCountReset: 1; // 2
		uint32 unknown1: 29;
	};
	uint32 val;
};

// PCIE_PORT_DATA
union PciePortData {
	struct {
		uint32 pcieData: 32; // 0
	};
	uint32 val;
};

// PCIE_PORT_INDEX
union PciePortIndex {
	struct {
		uint32 pcieIndex: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_PRBS_CLR
union PciePrbsClr {
	struct {
		uint32 prbsClr: 16; // 0
		uint32 prbsCheckerDebugBusSelect: 4; // 16
		uint32 unknown1: 12;
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_0
union PciePrbsErrcnt0 {
	struct {
		uint32 prbsErrcnt0: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_1
union PciePrbsErrcnt1 {
	struct {
		uint32 prbsErrcnt1: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_10
union PciePrbsErrcnt10 {
	struct {
		uint32 prbsErrcnt10: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_11
union PciePrbsErrcnt11 {
	struct {
		uint32 prbsErrcnt11: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_12
union PciePrbsErrcnt12 {
	struct {
		uint32 prbsErrcnt12: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_13
union PciePrbsErrcnt13 {
	struct {
		uint32 prbsErrcnt13: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_14
union PciePrbsErrcnt14 {
	struct {
		uint32 prbsErrcnt14: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_15
union PciePrbsErrcnt15 {
	struct {
		uint32 prbsErrcnt15: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_2
union PciePrbsErrcnt2 {
	struct {
		uint32 prbsErrcnt2: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_3
union PciePrbsErrcnt3 {
	struct {
		uint32 prbsErrcnt3: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_4
union PciePrbsErrcnt4 {
	struct {
		uint32 prbsErrcnt4: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_5
union PciePrbsErrcnt5 {
	struct {
		uint32 prbsErrcnt5: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_6
union PciePrbsErrcnt6 {
	struct {
		uint32 prbsErrcnt6: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_7
union PciePrbsErrcnt7 {
	struct {
		uint32 prbsErrcnt7: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_8
union PciePrbsErrcnt8 {
	struct {
		uint32 prbsErrcnt8: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_ERRCNT_9
union PciePrbsErrcnt9 {
	struct {
		uint32 prbsErrcnt9: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_FREERUN
union PciePrbsFreerun {
	struct {
		uint32 prbsFreerun: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PCIE_PRBS_HI_BITCNT
union PciePrbsHiBitcnt {
	struct {
		uint32 prbsHiBitcnt: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_PRBS_LO_BITCNT
union PciePrbsLoBitcnt {
	struct {
		uint32 prbsLoBitcnt: 32; // 0
	};
	uint32 val;
};

// PCIE_PRBS_MISC
union PciePrbsMisc {
	struct {
		uint32 prbsEn: 1; // 0
		uint32 prbsTestMode: 2; // 1
		uint32 prbsUserPatternToggle: 1; // 3
		uint32 prbs8bitSel: 1; // 4
		uint32 prbsCommaNum: 2; // 5
		uint32 prbsLockCnt: 5; // 7
		uint32 unknown1: 2;
		uint32 prbsDataRate: 2; // 14
		uint32 prbsChkErrMask: 16; // 16
	};
	uint32 val;
};

// PCIE_PRBS_STATUS1
union PciePrbsStatus1 {
	struct {
		uint32 prbsErrstat: 16; // 0
		uint32 prbsLocked: 16; // 16
	};
	uint32 val;
};

// PCIE_PRBS_STATUS2
union PciePrbsStatus2 {
	struct {
		uint32 prbsBitcntDone: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PCIE_PRBS_USER_PATTERN
union PciePrbsUserPattern {
	struct {
		uint32 prbsUserPattern: 30; // 0
		uint32 unknown1: 2;
	};
	uint32 val;
};

// PCIE_P_BUF_STATUS
union PciePBufStatus {
	struct {
		uint32 pOverflowErr: 16; // 0
		uint32 pUnderflowErr: 16; // 16
	};
	uint32 val;
};

// PCIE_P_CNTL
union PciePCntl {
	struct {
		uint32 pPwrdnEn: 1; // 0
		uint32 pSymalignMode: 1; // 1
		uint32 pSymalignHwDebug: 1; // 2
		uint32 pElastdeskewHwDebug: 1; // 3
		uint32 pIgnoreCrcErr: 1; // 4
		uint32 pIgnoreLenErr: 1; // 5
		uint32 pIgnoreEdbErr: 1; // 6
		uint32 pIgnoreIdlErr: 1; // 7
		uint32 pIgnoreTokErr: 1; // 8
		uint32 unknown1: 3;
		uint32 pBlkLockMode: 1; // 12
		uint32 pAlwaysUseFastTxclk: 1; // 13
		uint32 pElecIdleMode: 2; // 14
		uint32 unknown2: 16;
	};
	uint32 val;
};

// PCIE_P_DECODER_STATUS
union PciePDecoderStatus {
	struct {
		uint32 pDecodeErr: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PCIE_P_MISC_STATUS
union PciePMiscStatus {
	struct {
		uint32 pDeskewErr: 8; // 0
		uint32 unknown1: 8;
		uint32 pSymunlockErr: 16; // 16
	};
	uint32 val;
};

// PCIE_P_PORT_LANE_STATUS
union PciePPortLaneStatus {
	struct {
		uint32 portLaneReversal: 1; // 0
		uint32 phyLinkWidth: 6; // 1
		uint32 unknown1: 25;
	};
	uint32 val;
};

// PCIE_P_RCV_L0S_FTS_DET
union PciePRcvL0sFtsDet {
	struct {
		uint32 pRcvL0sFtsDetMin: 8; // 0
		uint32 pRcvL0sFtsDetMax: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PCIE_RESERVED
union PcieReserved {
	struct {
		uint32 pcieReserved: 32; // 0
	};
	uint32 val;
};

// PCIE_RX_CNTL
union PcieRxCntl {
	struct {
		uint32 rxIgnoreIoErr: 1; // 0
		uint32 rxIgnoreBeErr: 1; // 1
		uint32 rxIgnoreMsgErr: 1; // 2
		uint32 rxIgnoreCrcErr: 1; // 3
		uint32 rxIgnoreCfgErr: 1; // 4
		uint32 rxIgnoreCplErr: 1; // 5
		uint32 rxIgnoreEpErr: 1; // 6
		uint32 rxIgnoreLenMismatchErr: 1; // 7
		uint32 rxIgnoreMaxPayloadErr: 1; // 8
		uint32 rxIgnoreTcErr: 1; // 9
		uint32 rxIgnoreCfgUr: 1; // 10
		uint32 rxIgnoreIoUr: 1; // 11
		uint32 rxIgnoreAtErr: 1; // 12
		uint32 rxNakIfFifoFull: 1; // 13
		uint32 rxGenOneNak: 1; // 14
		uint32 rxFcInitFromReg: 1; // 15
		uint32 rxRcbCplTimeout: 3; // 16
		uint32 rxRcbCplTimeoutMode: 1; // 19
		uint32 rxPcieCplTimeoutDis: 1; // 20
		uint32 rxIgnoreShortprefixErr: 1; // 21
		uint32 rxIgnoreMaxprefixErr: 1; // 22
		uint32 rxIgnoreCplprefixErr: 1; // 23
		uint32 rxIgnoreInvalidpasidErr: 1; // 24
		uint32 rxIgnoreNotPasidUr: 1; // 25
		uint32 unknown1: 6;
	};
	uint32 val;
};

// PCIE_RX_CNTL2
union PcieRxCntl2 {
	struct {
		uint32 rxIgnoreEpInvalidpasidUr: 1; // 0
		uint32 rxIgnoreEpTransmrdUr: 1; // 1
		uint32 rxIgnoreEpTransmwrUr: 1; // 2
		uint32 rxIgnoreEpAtstransreqUr: 1; // 3
		uint32 rxIgnoreEpPagereqmsgUr: 1; // 4
		uint32 rxIgnoreEpInvcplUr: 1; // 5
		uint32 unknown1: 26;
	};
	uint32 val;
};

// PCIE_RX_CNTL3
union PcieRxCntl3 {
	struct {
		uint32 rxIgnoreRcTransmrdpasidUr: 1; // 0
		uint32 rxIgnoreRcTransmwrpasidUr: 1; // 1
		uint32 rxIgnoreRcPrgrespmsgUr: 1; // 2
		uint32 rxIgnoreRcInvreqUr: 1; // 3
		uint32 rxIgnoreRcInvcplpasidUr: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// PCIE_RX_CREDITS_ALLOCATED_CPL
union PcieRxCreditsAllocatedCpl {
	struct {
		uint32 rxCreditsAllocatedCpld: 12; // 0
		uint32 unknown1: 4;
		uint32 rxCreditsAllocatedCplh: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PCIE_RX_CREDITS_ALLOCATED_NP
union PcieRxCreditsAllocatedNp {
	struct {
		uint32 rxCreditsAllocatedNpd: 12; // 0
		uint32 unknown1: 4;
		uint32 rxCreditsAllocatedNph: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PCIE_RX_CREDITS_ALLOCATED_P
union PcieRxCreditsAllocatedP {
	struct {
		uint32 rxCreditsAllocatedPd: 12; // 0
		uint32 unknown1: 4;
		uint32 rxCreditsAllocatedPh: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PCIE_RX_EXPECTED_SEQNUM
union PcieRxExpectedSeqnum {
	struct {
		uint32 rxExpectedSeqnum: 12; // 0
		uint32 unknown1: 20;
	};
	uint32 val;
};

// PCIE_RX_LAST_TLP0
union PcieRxLastTlp0 {
	struct {
		uint32 rxLastTlp0: 32; // 0
	};
	uint32 val;
};

// PCIE_RX_LAST_TLP1
union PcieRxLastTlp1 {
	struct {
		uint32 rxLastTlp1: 32; // 0
	};
	uint32 val;
};

// PCIE_RX_LAST_TLP2
union PcieRxLastTlp2 {
	struct {
		uint32 rxLastTlp2: 32; // 0
	};
	uint32 val;
};

// PCIE_RX_LAST_TLP3
union PcieRxLastTlp3 {
	struct {
		uint32 rxLastTlp3: 32; // 0
	};
	uint32 val;
};

// PCIE_RX_NUM_NAK
union PcieRxNumNak {
	struct {
		uint32 rxNumNak: 32; // 0
	};
	uint32 val;
};

// PCIE_RX_NUM_NAK_GENERATED
union PcieRxNumNakGenerated {
	struct {
		uint32 rxNumNakGenerated: 32; // 0
	};
	uint32 val;
};

// PCIE_RX_VENDOR_SPECIFIC
union PcieRxVendorSpecific {
	struct {
		uint32 rxVendorData: 24; // 0
		uint32 rxVendorStatus: 1; // 24
		uint32 unknown1: 7;
	};
	uint32 val;
};

// PCIE_SCRATCH
union PcieScratch {
	struct {
		uint32 pcieScratch: 32; // 0
	};
	uint32 val;
};

// PCIE_STRAP_F0
union PcieStrapF0 {
	struct {
		uint32 strapF0En: 1; // 0
		uint32 strapF0LegacyDeviceTypeEn: 1; // 1
		uint32 strapF0MsiEn: 1; // 2
		uint32 strapF0VcEn: 1; // 3
		uint32 strapF0DsnEn: 1; // 4
		uint32 strapF0AerEn: 1; // 5
		uint32 strapF0AcsEn: 1; // 6
		uint32 strapF0BarEn: 1; // 7
		uint32 strapF0PwrEn: 1; // 8
		uint32 strapF0DpaEn: 1; // 9
		uint32 strapF0AtsEn: 1; // 10
		uint32 strapF0PageReqEn: 1; // 11
		uint32 strapF0PasidEn: 1; // 12
		uint32 unknown1: 19;
	};
	uint32 val;
};

// PCIE_STRAP_F1
union PcieStrapF1 {
	struct {
		uint32 strapF1En: 1; // 0
		uint32 strapF1LegacyDeviceTypeEn: 1; // 1
		uint32 strapF1MsiEn: 1; // 2
		uint32 strapF1VcEn: 1; // 3
		uint32 strapF1DsnEn: 1; // 4
		uint32 strapF1AerEn: 1; // 5
		uint32 strapF1AcsEn: 1; // 6
		uint32 strapF1BarEn: 1; // 7
		uint32 strapF1PwrEn: 1; // 8
		uint32 strapF1DpaEn: 1; // 9
		uint32 strapF1AtsEn: 1; // 10
		uint32 strapF1PageReqEn: 1; // 11
		uint32 strapF1PasidEn: 1; // 12
		uint32 unknown1: 19;
	};
	uint32 val;
};

// PCIE_STRAP_F2
union PcieStrapF2 {
	struct {
		uint32 strapF2En: 1; // 0
		uint32 strapF2LegacyDeviceTypeEn: 1; // 1
		uint32 strapF2MsiEn: 1; // 2
		uint32 strapF2VcEn: 1; // 3
		uint32 strapF2DsnEn: 1; // 4
		uint32 strapF2AerEn: 1; // 5
		uint32 strapF2AcsEn: 1; // 6
		uint32 strapF2BarEn: 1; // 7
		uint32 strapF2PwrEn: 1; // 8
		uint32 strapF2DpaEn: 1; // 9
		uint32 strapF2AtsEn: 1; // 10
		uint32 strapF2PageReqEn: 1; // 11
		uint32 strapF2PasidEn: 1; // 12
		uint32 unknown1: 19;
	};
	uint32 val;
};

// PCIE_STRAP_F3
union PcieStrapF3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// PCIE_STRAP_F4
union PcieStrapF4 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// PCIE_STRAP_F5
union PcieStrapF5 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// PCIE_STRAP_F6
union PcieStrapF6 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// PCIE_STRAP_F7
union PcieStrapF7 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// PCIE_STRAP_I2C_BD
union PcieStrapI2cBd {
	struct {
		uint32 strapBifI2cSlvAdr: 7; // 0
		uint32 strapBifDbgI2cEn: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PCIE_STRAP_MISC
union PcieStrapMisc {
	struct {
		uint32 strapLinkConfig: 4; // 0
		uint32 unknown1: 4;
		uint32 strapMaxPasidWidth: 5; // 8
		uint32 strapPasidExePermissionSupported: 1; // 13
		uint32 strapPasidPrivModeSupported: 1; // 14
		uint32 strapPasidGlobalInvalidateSupported: 1; // 15
		uint32 unknown2: 8;
		uint32 strapClkPmEn: 1; // 24
		uint32 strapEcn1p1En: 1; // 25
		uint32 strapExtVcCount: 1; // 26
		uint32 unknown3: 1;
		uint32 strapReverseAll: 1; // 28
		uint32 strapMstAdr64En: 1; // 29
		uint32 strapFlrEn: 1; // 30
		uint32 unknown4: 1;
	};
	uint32 val;
};

// PCIE_STRAP_MISC2
union PcieStrapMisc2 {
	struct {
		uint32 unknown1: 1;
		uint32 strapGen2Compliance: 1; // 1
		uint32 strapMstcplTimeoutEn: 1; // 2
		uint32 strapGen3Compliance: 1; // 3
		uint32 unknown2: 28;
	};
	uint32 val;
};

// PCIE_STRAP_PI
union PcieStrapPi {
	struct {
		uint32 strapQuicksimStart: 1; // 0
		uint32 unknown1: 27;
		uint32 strapTestTogglePattern: 1; // 28
		uint32 strapTestToggleMode: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// PCIE_TX_ACK_LATENCY_LIMIT
union PcieTxAckLatencyLimit {
	struct {
		uint32 txAckLatencyLimit: 12; // 0
		uint32 txAckLatencyLimitOverwrite: 1; // 12
		uint32 unknown1: 19;
	};
	uint32 val;
};

// PCIE_TX_CNTL
union PcieTxCntl {
	struct {
		uint32 unknown1: 10;
		uint32 txSnrOverride: 2; // 10
		uint32 txRoOverride: 2; // 12
		uint32 txPackPacketDis: 1; // 14
		uint32 txFlushTlpDis: 1; // 15
		uint32 unknown2: 4;
		uint32 txCplPassP: 1; // 20
		uint32 txNpPassP: 1; // 21
		uint32 txClearExtraPmReqs: 1; // 22
		uint32 txFcUpdateTimeoutDis: 1; // 23
		uint32 unknown3: 8;
	};
	uint32 val;
};

// PCIE_TX_CREDITS_ADVT_CPL
union PcieTxCreditsAdvtCpl {
	struct {
		uint32 txCreditsAdvtCpld: 12; // 0
		uint32 unknown1: 4;
		uint32 txCreditsAdvtCplh: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PCIE_TX_CREDITS_ADVT_NP
union PcieTxCreditsAdvtNp {
	struct {
		uint32 txCreditsAdvtNpd: 12; // 0
		uint32 unknown1: 4;
		uint32 txCreditsAdvtNph: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PCIE_TX_CREDITS_ADVT_P
union PcieTxCreditsAdvtP {
	struct {
		uint32 txCreditsAdvtPd: 12; // 0
		uint32 unknown1: 4;
		uint32 txCreditsAdvtPh: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PCIE_TX_CREDITS_FCU_THRESHOLD
union PcieTxCreditsFcuThreshold {
	struct {
		uint32 txFcuThresholdPVc0: 3; // 0
		uint32 unknown1: 1;
		uint32 txFcuThresholdNpVc0: 3; // 4
		uint32 unknown2: 1;
		uint32 txFcuThresholdCplVc0: 3; // 8
		uint32 unknown3: 5;
		uint32 txFcuThresholdPVc1: 3; // 16
		uint32 unknown4: 1;
		uint32 txFcuThresholdNpVc1: 3; // 20
		uint32 unknown5: 1;
		uint32 txFcuThresholdCplVc1: 3; // 24
		uint32 unknown6: 5;
	};
	uint32 val;
};

// PCIE_TX_CREDITS_INIT_CPL
union PcieTxCreditsInitCpl {
	struct {
		uint32 txCreditsInitCpld: 12; // 0
		uint32 unknown1: 4;
		uint32 txCreditsInitCplh: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PCIE_TX_CREDITS_INIT_NP
union PcieTxCreditsInitNp {
	struct {
		uint32 txCreditsInitNpd: 12; // 0
		uint32 unknown1: 4;
		uint32 txCreditsInitNph: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PCIE_TX_CREDITS_INIT_P
union PcieTxCreditsInitP {
	struct {
		uint32 txCreditsInitPd: 12; // 0
		uint32 unknown1: 4;
		uint32 txCreditsInitPh: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PCIE_TX_CREDITS_STATUS
union PcieTxCreditsStatus {
	struct {
		uint32 txCreditsErrPd: 1; // 0
		uint32 txCreditsErrPh: 1; // 1
		uint32 txCreditsErrNpd: 1; // 2
		uint32 txCreditsErrNph: 1; // 3
		uint32 txCreditsErrCpld: 1; // 4
		uint32 txCreditsErrCplh: 1; // 5
		uint32 unknown1: 10;
		uint32 txCreditsCurStatusPd: 1; // 16
		uint32 txCreditsCurStatusPh: 1; // 17
		uint32 txCreditsCurStatusNpd: 1; // 18
		uint32 txCreditsCurStatusNph: 1; // 19
		uint32 txCreditsCurStatusCpld: 1; // 20
		uint32 txCreditsCurStatusCplh: 1; // 21
		uint32 unknown2: 10;
	};
	uint32 val;
};

// PCIE_TX_LAST_TLP0
union PcieTxLastTlp0 {
	struct {
		uint32 txLastTlp0: 32; // 0
	};
	uint32 val;
};

// PCIE_TX_LAST_TLP1
union PcieTxLastTlp1 {
	struct {
		uint32 txLastTlp1: 32; // 0
	};
	uint32 val;
};

// PCIE_TX_LAST_TLP2
union PcieTxLastTlp2 {
	struct {
		uint32 txLastTlp2: 32; // 0
	};
	uint32 val;
};

// PCIE_TX_LAST_TLP3
union PcieTxLastTlp3 {
	struct {
		uint32 txLastTlp3: 32; // 0
	};
	uint32 val;
};

// PCIE_TX_REPLAY
union PcieTxReplay {
	struct {
		uint32 txReplayNum: 3; // 0
		uint32 unknown1: 12;
		uint32 txReplayTimerOverwrite: 1; // 15
		uint32 txReplayTimer: 16; // 16
	};
	uint32 val;
};

// PCIE_TX_REQUESTER_ID
union PcieTxRequesterId {
	struct {
		uint32 txRequesterIdFunction: 3; // 0
		uint32 txRequesterIdDevice: 5; // 3
		uint32 txRequesterIdBus: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PCIE_TX_REQUEST_NUM_CNTL
union PcieTxRequestNumCntl {
	struct {
		uint32 unknown1: 24;
		uint32 txNumOutstandingNp: 6; // 24
		uint32 txNumOutstandingNpVc1En: 1; // 30
		uint32 txNumOutstandingNpEn: 1; // 31
	};
	uint32 val;
};

// PCIE_TX_SEQ
union PcieTxSeq {
	struct {
		uint32 txNextTransmitSeq: 12; // 0
		uint32 unknown1: 4;
		uint32 txAckdSeq: 12; // 16
		uint32 unknown2: 4;
	};
	uint32 val;
};

// PCIE_TX_VENDOR_SPECIFIC
union PcieTxVendorSpecific {
	struct {
		uint32 txVendorData: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// PCIE_WPR_CNTL
union PcieWprCntl {
	struct {
		uint32 wprResetHotRstEn: 1; // 0
		uint32 wprResetLnkDwnEn: 1; // 1
		uint32 wprResetLnkDisEn: 1; // 2
		uint32 wprResetCorEn: 1; // 3
		uint32 wprResetRegEn: 1; // 4
		uint32 wprResetStyEn: 1; // 5
		uint32 wprResetPhyEn: 1; // 6
		uint32 unknown1: 25;
	};
	uint32 val;
};

// PEER0_FB_OFFSET_HI
union Peer0FbOffsetHi {
	struct {
		uint32 peer0FbOffsetHi: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// PEER0_FB_OFFSET_LO
union Peer0FbOffsetLo {
	struct {
		uint32 peer0FbOffsetLo: 20; // 0
		uint32 unknown1: 11;
		uint32 peer0FbEn: 1; // 31
	};
	uint32 val;
};

// PEER1_FB_OFFSET_HI
union Peer1FbOffsetHi {
	struct {
		uint32 peer1FbOffsetHi: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// PEER1_FB_OFFSET_LO
union Peer1FbOffsetLo {
	struct {
		uint32 peer1FbOffsetLo: 20; // 0
		uint32 unknown1: 11;
		uint32 peer1FbEn: 1; // 31
	};
	uint32 val;
};

// PEER2_FB_OFFSET_HI
union Peer2FbOffsetHi {
	struct {
		uint32 peer2FbOffsetHi: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// PEER2_FB_OFFSET_LO
union Peer2FbOffsetLo {
	struct {
		uint32 peer2FbOffsetLo: 20; // 0
		uint32 unknown1: 11;
		uint32 peer2FbEn: 1; // 31
	};
	uint32 val;
};

// PEER3_FB_OFFSET_HI
union Peer3FbOffsetHi {
	struct {
		uint32 peer3FbOffsetHi: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// PEER3_FB_OFFSET_LO
union Peer3FbOffsetLo {
	struct {
		uint32 peer3FbOffsetLo: 20; // 0
		uint32 unknown1: 11;
		uint32 peer3FbEn: 1; // 31
	};
	uint32 val;
};

// PEER_REG_RANGE0
union PeerRegRange0 {
	struct {
		uint32 startAddr: 16; // 0
		uint32 endAddr: 16; // 16
	};
	uint32 val;
};

// PEER_REG_RANGE1
union PeerRegRange1 {
	struct {
		uint32 startAddr: 16; // 0
		uint32 endAddr: 16; // 16
	};
	uint32 val;
};

// SLAVE_HANG_ERROR
union SlaveHangError {
	struct {
		uint32 srbmHangError: 1; // 0
		uint32 hdpHangError: 1; // 1
		uint32 vgaHangError: 1; // 2
		uint32 romHangError: 1; // 3
		uint32 audioHangError: 1; // 4
		uint32 cecHangError: 1; // 5
		uint32 unknown1: 26;
	};
	uint32 val;
};

// SLAVE_HANG_PROTECTION_CNTL
union SlaveHangProtectionCntl {
	struct {
		uint32 unknown1: 1;
		uint32 hangProtectionTimerSel: 3; // 1
		uint32 unknown2: 28;
	};
	uint32 val;
};

// SLAVE_REQ_CREDIT_CNTL
union SlaveReqCreditCntl {
	struct {
		uint32 bifSrbmReqCredit: 5; // 0
		uint32 bifVgaReqCredit: 4; // 5
		uint32 unknown1: 1;
		uint32 bifHdpReqCredit: 5; // 10
		uint32 bifRomReqCredit: 1; // 15
		uint32 unknown2: 4;
		uint32 bifAzReqCredit: 1; // 20
		uint32 unknown3: 4;
		uint32 bifXdmaReqCredit: 6; // 25
		uint32 unknown4: 1;
	};
	uint32 val;
};

// SMBCLK_PAD_CNTL
union SmbclkPadCntl {
	struct {
		uint32 smbclkPadA: 1; // 0
		uint32 smbclkPadSel: 1; // 1
		uint32 smbclkPadMode: 1; // 2
		uint32 smbclkPadSpare: 2; // 3
		uint32 smbclkPadSn0: 1; // 5
		uint32 smbclkPadSn1: 1; // 6
		uint32 smbclkPadSn2: 1; // 7
		uint32 smbclkPadSn3: 1; // 8
		uint32 smbclkPadSlewn: 1; // 9
		uint32 smbclkPadWake: 1; // 10
		uint32 smbclkPadSchmen: 1; // 11
		uint32 smbclkPadCntlEn: 1; // 12
		uint32 unknown1: 19;
	};
	uint32 val;
};

// SMBDAT_PAD_CNTL
union SmbdatPadCntl {
	struct {
		uint32 smbdatPadA: 1; // 0
		uint32 smbdatPadSel: 1; // 1
		uint32 smbdatPadMode: 1; // 2
		uint32 smbdatPadSpare: 2; // 3
		uint32 smbdatPadSn0: 1; // 5
		uint32 smbdatPadSn1: 1; // 6
		uint32 smbdatPadSn2: 1; // 7
		uint32 smbdatPadSn3: 1; // 8
		uint32 smbdatPadSlewn: 1; // 9
		uint32 smbdatPadWake: 1; // 10
		uint32 smbdatPadSchmen: 1; // 11
		uint32 smbdatPadCntlEn: 1; // 12
		uint32 unknown1: 19;
	};
	uint32 val;
};

// SMBUS_BACO_DUMMY
union SmbusBacoDummy {
	struct {
		uint32 smbusBacoDummyData: 32; // 0
	};
	uint32 val;
};

