#pragma once
#include <SupportDefs.h>

// ATC_ATS_CNTL
union AtcAtsCntl {
	struct {
		uint32 disableAtc: 1; // 0
		uint32 disablePri: 1; // 1
		uint32 disablePasid: 1; // 2
		uint32 unknown1: 5;
		uint32 creditsAtsRpb: 6; // 8
		uint32 unknown2: 2;
		uint32 debugEco: 4; // 16
		uint32 unknown3: 12;
	};
	uint32 val;
};

// ATC_ATS_DEBUG
union AtcAtsDebug {
	struct {
		uint32 invalidateAll: 1; // 0
		uint32 identReturn: 1; // 1
		uint32 addressTranslationRequestWritePerms: 1; // 2
		uint32 unknown1: 2;
		uint32 pageRequestsUseRelaxedOrdering: 1; // 5
		uint32 privBit: 1; // 6
		uint32 exeBit: 1; // 7
		uint32 pageRequestPerms: 1; // 8
		uint32 untranslatedOnlyRequestsCarrySize: 1; // 9
		uint32 numRequestsAtErr: 4; // 10
		uint32 disallowErrToDone: 1; // 14
		uint32 ignoreFed: 1; // 15
		uint32 invalidationRequestsDisallowedWhenAtcIsDisabled: 1; // 16
		uint32 unknown2: 15;
	};
	uint32 val;
};

// ATC_ATS_DEFAULT_PAGE_CNTL
union AtcAtsDefaultPageCntl {
	struct {
		uint32 sendDefaultPage: 1; // 0
		uint32 unknown1: 1;
		uint32 defaultPageHigh: 4; // 2
		uint32 unknown2: 26;
	};
	uint32 val;
};

// ATC_ATS_DEFAULT_PAGE_LOW
union AtcAtsDefaultPageLow {
	struct {
		uint32 defaultPage: 32; // 0
	};
	uint32 val;
};

// ATC_ATS_FAULT_CNTL
union AtcAtsFaultCntl {
	struct {
		uint32 faultRegisterLog: 6; // 0
		uint32 unknown1: 4;
		uint32 faultInterruptTable: 6; // 10
		uint32 unknown2: 4;
		uint32 faultCrashTable: 6; // 20
		uint32 unknown3: 6;
	};
	uint32 val;
};

// ATC_ATS_FAULT_DEBUG
union AtcAtsFaultDebug {
	struct {
		uint32 creditsAtsIh: 5; // 0
		uint32 unknown1: 3;
		uint32 allowSubsequentFaultStatusAddrUpdates: 1; // 8
		uint32 unknown2: 7;
		uint32 clearFaultStatusAddr: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// ATC_ATS_FAULT_STATUS_ADDR
union AtcAtsFaultStatusAddr {
	struct {
		uint32 pageAddr: 32; // 0
	};
	uint32 val;
};

// ATC_ATS_FAULT_STATUS_INFO
union AtcAtsFaultStatusInfo {
	struct {
		uint32 faultType: 6; // 0
		uint32 unknown1: 4;
		uint32 vmid: 5; // 10
		uint32 extraInfo: 1; // 15
		uint32 extraInfo2: 1; // 16
		uint32 invalidation: 1; // 17
		uint32 pageRequest: 1; // 18
		uint32 status: 5; // 19
		uint32 pageAddrHigh: 4; // 24
		uint32 unknown2: 4;
	};
	uint32 val;
};

// ATC_ATS_STATUS
union AtcAtsStatus {
	struct {
		uint32 busy: 1; // 0
		uint32 crashed: 1; // 1
		uint32 deadlockDetection: 1; // 2
		uint32 unknown1: 29;
	};
	uint32 val;
};

// ATC_L1RD_DEBUG_TLB
union AtcL1rdDebugTlb {
	struct {
		uint32 disableFragments: 1; // 0
		uint32 unknown1: 3;
		uint32 effectiveCamSize: 4; // 4
		uint32 effectiveWorkQueueSize: 3; // 8
		uint32 unknown2: 1;
		uint32 creditsL1L2: 6; // 12
		uint32 unknown3: 2;
		uint32 creditsL1Rpb: 8; // 20
		uint32 debugEco: 2; // 28
		uint32 invalidateAll: 1; // 30
		uint32 unknown4: 1;
	};
	uint32 val;
};

// ATC_L1RD_STATUS
union AtcL1rdStatus {
	struct {
		uint32 busy: 1; // 0
		uint32 deadlockDetection: 1; // 1
		uint32 unknown1: 6;
		uint32 badNeedAts: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// ATC_L1WR_DEBUG_TLB
union AtcL1wrDebugTlb {
	struct {
		uint32 disableFragments: 1; // 0
		uint32 unknown1: 3;
		uint32 effectiveCamSize: 4; // 4
		uint32 effectiveWorkQueueSize: 3; // 8
		uint32 unknown2: 1;
		uint32 creditsL1L2: 6; // 12
		uint32 unknown3: 2;
		uint32 creditsL1Rpb: 8; // 20
		uint32 debugEco: 2; // 28
		uint32 invalidateAll: 1; // 30
		uint32 unknown4: 1;
	};
	uint32 val;
};

// ATC_L1WR_STATUS
union AtcL1wrStatus {
	struct {
		uint32 busy: 1; // 0
		uint32 deadlockDetection: 1; // 1
		uint32 unknown1: 6;
		uint32 badNeedAts: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// ATC_L1_ADDRESS_OFFSET
union AtcL1AddressOffset {
	struct {
		uint32 logicalAddress: 32; // 0
	};
	uint32 val;
};

// ATC_L1_CNTL
union AtcL1Cntl {
	struct {
		uint32 dontNeedAtsBehavior: 2; // 0
		uint32 needAtsBehavior: 1; // 2
		uint32 unknown1: 1;
		uint32 needAtsSnoopDefault: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// ATC_L2_CNTL
union AtcL2Cntl {
	struct {
		uint32 numberOfTranslationReadRequests: 2; // 0
		uint32 unknown1: 2;
		uint32 numberOfTranslationWriteRequests: 2; // 4
		uint32 unknown2: 4;
		uint32 numberOfTranslationReadsDependsOnAddrMod: 1; // 10
		uint32 numberOfTranslationWritesDependsOnAddrMod: 1; // 11
		uint32 unknown3: 20;
	};
	uint32 val;
};

// ATC_L2_DEBUG
union AtcL2Debug {
	struct {
		uint32 creditsL2Ats: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATC_MISC_CG
union AtcMiscCg {
	struct {
		uint32 unknown1: 6;
		uint32 offdly: 6; // 6
		uint32 unknown2: 6;
		uint32 enable: 1; // 18
		uint32 memLsEnable: 1; // 19
		uint32 unknown3: 12;
	};
	uint32 val;
};

// ATC_VMID0_PASID_MAPPING
union AtcVmid0PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID10_PASID_MAPPING
union AtcVmid10PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID11_PASID_MAPPING
union AtcVmid11PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID12_PASID_MAPPING
union AtcVmid12PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID13_PASID_MAPPING
union AtcVmid13PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID14_PASID_MAPPING
union AtcVmid14PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID15_PASID_MAPPING
union AtcVmid15PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID1_PASID_MAPPING
union AtcVmid1PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID2_PASID_MAPPING
union AtcVmid2PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID3_PASID_MAPPING
union AtcVmid3PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID4_PASID_MAPPING
union AtcVmid4PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID5_PASID_MAPPING
union AtcVmid5PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID6_PASID_MAPPING
union AtcVmid6PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID7_PASID_MAPPING
union AtcVmid7PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID8_PASID_MAPPING
union AtcVmid8PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID9_PASID_MAPPING
union AtcVmid9PasidMapping {
	struct {
		uint32 pasid: 16; // 0
		uint32 unknown1: 15;
		uint32 valid: 1; // 31
	};
	uint32 val;
};

// ATC_VMID_PASID_MAPPING_UPDATE_STATUS
union AtcVmidPasidMappingUpdateStatus {
	struct {
		uint32 vmid0RemappingFinished: 1; // 0
		uint32 vmid1RemappingFinished: 1; // 1
		uint32 vmid2RemappingFinished: 1; // 2
		uint32 vmid3RemappingFinished: 1; // 3
		uint32 vmid4RemappingFinished: 1; // 4
		uint32 vmid5RemappingFinished: 1; // 5
		uint32 vmid6RemappingFinished: 1; // 6
		uint32 vmid7RemappingFinished: 1; // 7
		uint32 vmid8RemappingFinished: 1; // 8
		uint32 vmid9RemappingFinished: 1; // 9
		uint32 vmid10RemappingFinished: 1; // 10
		uint32 vmid11RemappingFinished: 1; // 11
		uint32 vmid12RemappingFinished: 1; // 12
		uint32 vmid13RemappingFinished: 1; // 13
		uint32 vmid14RemappingFinished: 1; // 14
		uint32 vmid15RemappingFinished: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// ATC_VM_APERTURE0_CNTL
union AtcVmAperture0Cntl {
	struct {
		uint32 atsAccessMode: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// ATC_VM_APERTURE0_CNTL2
union AtcVmAperture0Cntl2 {
	struct {
		uint32 vmidsUsingRange: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// ATC_VM_APERTURE0_HIGH_ADDR
union AtcVmAperture0HighAddr {
	struct {
		uint32 virtualPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// ATC_VM_APERTURE0_LOW_ADDR
union AtcVmAperture0LowAddr {
	struct {
		uint32 virtualPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// ATC_VM_APERTURE1_CNTL
union AtcVmAperture1Cntl {
	struct {
		uint32 atsAccessMode: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// ATC_VM_APERTURE1_CNTL2
union AtcVmAperture1Cntl2 {
	struct {
		uint32 vmidsUsingRange: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// ATC_VM_APERTURE1_HIGH_ADDR
union AtcVmAperture1HighAddr {
	struct {
		uint32 virtualPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// ATC_VM_APERTURE1_LOW_ADDR
union AtcVmAperture1LowAddr {
	struct {
		uint32 virtualPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// CC_MC_MAX_CHANNEL
union CcMcMaxChannel {
	struct {
		uint32 unknown1: 1;
		uint32 noofchan: 4; // 1
		uint32 unknown2: 27;
	};
	uint32 val;
};

// DLL_CNTL
union DllCntl {
	struct {
		uint32 dllResetTime: 10; // 0
		uint32 unknown1: 2;
		uint32 dllLockTime: 10; // 12
		uint32 unknown2: 2;
		uint32 mrdck0Bypass: 1; // 24
		uint32 mrdck1Bypass: 1; // 25
		uint32 pwr2Mode: 1; // 26
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GMCON_DEBUG
union GmconDebug {
	struct {
		uint32 gfxStall: 1; // 0
		uint32 gfxClear: 1; // 1
		uint32 miscFlags: 28; // 2
		uint32 unknown1: 2;
	};
	uint32 val;
};

// GMCON_MISC
union GmconMisc {
	struct {
		uint32 unknown1: 10;
		uint32 rengExecuteNowMode: 1; // 10
		uint32 rengExecuteOnRegUpdate: 1; // 11
		uint32 rengSrbmCreditsMcd: 4; // 12
		uint32 stctrlStutterEn: 1; // 16
		uint32 stctrlGmcIdleThreshold: 2; // 17
		uint32 stctrlSrbmIdleThreshold: 2; // 19
		uint32 stctrlIgnorePreSr: 1; // 21
		uint32 stctrlIgnoreAllowStop: 1; // 22
		uint32 stctrlIgnoreSrCommit: 1; // 23
		uint32 stctrlIgnoreProtectionFault: 1; // 24
		uint32 stctrlDisableAllowSr: 1; // 25
		uint32 stctrlDisableGmcOffline: 1; // 26
		uint32 criticalRegsLock: 1; // 27
		uint32 allowDeepSleepMode: 2; // 28
		uint32 stctrlForceAllowSr: 1; // 30
		uint32 unknown2: 1;
	};
	uint32 val;
};

// GMCON_MISC2
union GmconMisc2 {
	struct {
		uint32 rengMemPowerCtrlOverride0: 3; // 0
		uint32 rengMemPowerCtrlOverride1: 3; // 3
		uint32 unknown1: 4;
		uint32 rengSrHoldThreshold: 6; // 10
		uint32 stctrlLptTarget: 12; // 16
		uint32 stctrlIgnoreArbBusy: 1; // 28
		uint32 stctrlExtendGmcOffline: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// GMCON_MISC3
union GmconMisc3 {
	struct {
		uint32 rengDisableMcc: 6; // 0
		uint32 rengDisableMcd: 6; // 6
		uint32 stctrlForcePgfsmCmdDone: 12; // 12
		uint32 unknown1: 8;
	};
	uint32 val;
};

// GMCON_PERF_MON_CNTL0
union GmconPerfMonCntl0 {
	struct {
		uint32 startThresh: 12; // 0
		uint32 stopThresh: 12; // 12
		uint32 startMode: 2; // 24
		uint32 stopMode: 2; // 26
		uint32 allowWrap: 1; // 28
		uint32 unknown1: 3;
	};
	uint32 val;
};

// GMCON_PERF_MON_CNTL1
union GmconPerfMonCntl1 {
	struct {
		uint32 threshCntrId: 6; // 0
		uint32 startTrigId: 6; // 6
		uint32 stopTrigId: 6; // 12
		uint32 mon0Id: 6; // 18
		uint32 mon1Id: 6; // 24
		uint32 unknown1: 2;
	};
	uint32 val;
};

// GMCON_PERF_MON_RSLT0
union GmconPerfMonRslt0 {
	struct {
		uint32 count: 32; // 0
	};
	uint32 val;
};

// GMCON_PERF_MON_RSLT1
union GmconPerfMonRslt1 {
	struct {
		uint32 count: 32; // 0
	};
	uint32 val;
};

// GMCON_PGFSM_CONFIG
union GmconPgfsmConfig {
	struct {
		uint32 fsmAddr: 8; // 0
		uint32 powerDown: 1; // 8
		uint32 powerUp: 1; // 9
		uint32 p1Select: 1; // 10
		uint32 p2Select: 1; // 11
		uint32 write: 1; // 12
		uint32 read: 1; // 13
		uint32 rsrvd: 13; // 14
		uint32 srbmOverride: 1; // 27
		uint32 regAddr: 4; // 28
	};
	uint32 val;
};

// GMCON_PGFSM_READ
union GmconPgfsmRead {
	struct {
		uint32 readValue: 24; // 0
		uint32 pgfsmSelect: 4; // 24
		uint32 serdesMasterBusy: 1; // 28
		uint32 unknown1: 3;
	};
	uint32 val;
};

// GMCON_PGFSM_WRITE
union GmconPgfsmWrite {
	struct {
		uint32 writeValue: 32; // 0
	};
	uint32 val;
};

// GMCON_RENG_EXECUTE
union GmconRengExecute {
	struct {
		uint32 rengExecuteOnPwrUp: 1; // 0
		uint32 rengExecuteNow: 1; // 1
		uint32 rengExecuteNowStartPtr: 10; // 2
		uint32 rengExecuteDspEndPtr: 10; // 12
		uint32 rengExecuteEndPtr: 10; // 22
	};
	uint32 val;
};

// GMCON_RENG_RAM_DATA
union GmconRengRamData {
	struct {
		uint32 rengRamData: 32; // 0
	};
	uint32 val;
};

// GMCON_RENG_RAM_INDEX
union GmconRengRamIndex {
	struct {
		uint32 rengRamIndex: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// GMCON_STCTRL_REGISTER_SAVE_EXCL_SET0
union GmconStctrlRegisterSaveExclSet0 {
	struct {
		uint32 stctrlRegisterSaveExcl0: 16; // 0
		uint32 stctrlRegisterSaveExcl1: 16; // 16
	};
	uint32 val;
};

// GMCON_STCTRL_REGISTER_SAVE_EXCL_SET1
union GmconStctrlRegisterSaveExclSet1 {
	struct {
		uint32 stctrlRegisterSaveExcl2: 16; // 0
		uint32 stctrlRegisterSaveExcl3: 16; // 16
	};
	uint32 val;
};

// GMCON_STCTRL_REGISTER_SAVE_RANGE0
union GmconStctrlRegisterSaveRange0 {
	struct {
		uint32 stctrlRegisterSaveBase0: 16; // 0
		uint32 stctrlRegisterSaveLimit0: 16; // 16
	};
	uint32 val;
};

// GMCON_STCTRL_REGISTER_SAVE_RANGE1
union GmconStctrlRegisterSaveRange1 {
	struct {
		uint32 stctrlRegisterSaveBase1: 16; // 0
		uint32 stctrlRegisterSaveLimit1: 16; // 16
	};
	uint32 val;
};

// GMCON_STCTRL_REGISTER_SAVE_RANGE2
union GmconStctrlRegisterSaveRange2 {
	struct {
		uint32 stctrlRegisterSaveBase2: 16; // 0
		uint32 stctrlRegisterSaveLimit2: 16; // 16
	};
	uint32 val;
};

// MCLK_PWRMGT_CNTL
union MclkPwrmgtCntl {
	struct {
		uint32 dllSpeed: 5; // 0
		uint32 unknown1: 1;
		uint32 dllReady: 1; // 6
		uint32 mcIntCntl: 1; // 7
		uint32 mrdck0Pdnb: 1; // 8
		uint32 mrdck1Pdnb: 1; // 9
		uint32 unknown2: 6;
		uint32 mrdck0Reset: 1; // 16
		uint32 mrdck1Reset: 1; // 17
		uint32 unknown3: 6;
		uint32 dllReadyRead: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// MC_ARB_ADDR_HASH
union McArbAddrHash {
	struct {
		uint32 bankXorEnable: 4; // 0
		uint32 colXor: 8; // 4
		uint32 rowXor: 16; // 12
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_ARB_AGE_RD
union McArbAgeRd {
	struct {
		uint32 rateGroup0: 2; // 0
		uint32 rateGroup1: 2; // 2
		uint32 rateGroup2: 2; // 4
		uint32 rateGroup3: 2; // 6
		uint32 rateGroup4: 2; // 8
		uint32 rateGroup5: 2; // 10
		uint32 rateGroup6: 2; // 12
		uint32 rateGroup7: 2; // 14
		uint32 enableGroup0: 1; // 16
		uint32 enableGroup1: 1; // 17
		uint32 enableGroup2: 1; // 18
		uint32 enableGroup3: 1; // 19
		uint32 enableGroup4: 1; // 20
		uint32 enableGroup5: 1; // 21
		uint32 enableGroup6: 1; // 22
		uint32 enableGroup7: 1; // 23
		uint32 divideGroup0: 1; // 24
		uint32 divideGroup1: 1; // 25
		uint32 divideGroup2: 1; // 26
		uint32 divideGroup3: 1; // 27
		uint32 divideGroup4: 1; // 28
		uint32 divideGroup5: 1; // 29
		uint32 divideGroup6: 1; // 30
		uint32 divideGroup7: 1; // 31
	};
	uint32 val;
};

// MC_ARB_AGE_WR
union McArbAgeWr {
	struct {
		uint32 rateGroup0: 2; // 0
		uint32 rateGroup1: 2; // 2
		uint32 rateGroup2: 2; // 4
		uint32 rateGroup3: 2; // 6
		uint32 rateGroup4: 2; // 8
		uint32 rateGroup5: 2; // 10
		uint32 rateGroup6: 2; // 12
		uint32 rateGroup7: 2; // 14
		uint32 enableGroup0: 1; // 16
		uint32 enableGroup1: 1; // 17
		uint32 enableGroup2: 1; // 18
		uint32 enableGroup3: 1; // 19
		uint32 enableGroup4: 1; // 20
		uint32 enableGroup5: 1; // 21
		uint32 enableGroup6: 1; // 22
		uint32 enableGroup7: 1; // 23
		uint32 divideGroup0: 1; // 24
		uint32 divideGroup1: 1; // 25
		uint32 divideGroup2: 1; // 26
		uint32 divideGroup3: 1; // 27
		uint32 divideGroup4: 1; // 28
		uint32 divideGroup5: 1; // 29
		uint32 divideGroup6: 1; // 30
		uint32 divideGroup7: 1; // 31
	};
	uint32 val;
};

// MC_ARB_BANKMAP
union McArbBankmap {
	struct {
		uint32 bank0: 4; // 0
		uint32 bank1: 4; // 4
		uint32 bank2: 4; // 8
		uint32 bank3: 4; // 12
		uint32 rank: 4; // 16
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_ARB_BURST_TIME
union McArbBurstTime {
	struct {
		uint32 state0: 5; // 0
		uint32 state1: 5; // 5
		uint32 state2: 5; // 10
		uint32 state3: 5; // 15
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_ARB_CAC_CNTL
union McArbCacCntl {
	struct {
		uint32 enable: 1; // 0
		uint32 readWeight: 6; // 1
		uint32 writeWeight: 6; // 7
		uint32 allowOverflow: 1; // 13
		uint32 unknown1: 18;
	};
	uint32 val;
};

// MC_ARB_CG
union McArbCg {
	struct {
		uint32 cgArbReq: 8; // 0
		uint32 cgArbResp: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_ARB_DRAM_TIMING
union McArbDramTiming {
	struct {
		uint32 actrd: 8; // 0
		uint32 actwr: 8; // 8
		uint32 rasmactrd: 8; // 16
		uint32 rasmactwr: 8; // 24
	};
	uint32 val;
};

// MC_ARB_DRAM_TIMING2
union McArbDramTiming2 {
	struct {
		uint32 ras2ras: 8; // 0
		uint32 rp: 8; // 8
		uint32 wrplusrp: 8; // 16
		uint32 busTurn: 5; // 24
		uint32 unknown1: 3;
	};
	uint32 val;
};

// MC_ARB_DRAM_TIMING2_1
union McArbDramTiming2_1 {
	struct {
		uint32 ras2ras: 8; // 0
		uint32 rp: 8; // 8
		uint32 wrplusrp: 8; // 16
		uint32 busTurn: 5; // 24
		uint32 unknown1: 3;
	};
	uint32 val;
};

// MC_ARB_DRAM_TIMING_1
union McArbDramTiming1 {
	struct {
		uint32 actrd: 8; // 0
		uint32 actwr: 8; // 8
		uint32 rasmactrd: 8; // 16
		uint32 rasmactwr: 8; // 24
	};
	uint32 val;
};

// MC_ARB_FED_CNTL
union McArbFedCntl {
	struct {
		uint32 mode: 2; // 0
		uint32 wrErr: 2; // 2
		uint32 keepPoisonInPage: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// MC_ARB_GDEC_RD_CNTL
union McArbGdecRdCntl {
	struct {
		uint32 pagebit0: 4; // 0
		uint32 pagebit1: 4; // 4
		uint32 useRank: 1; // 8
		uint32 useRsno: 1; // 9
		uint32 remDefaultGrp: 4; // 10
		uint32 unknown1: 18;
	};
	uint32 val;
};

// MC_ARB_GDEC_WR_CNTL
union McArbGdecWrCntl {
	struct {
		uint32 pagebit0: 4; // 0
		uint32 pagebit1: 4; // 4
		uint32 useRank: 1; // 8
		uint32 useRsno: 1; // 9
		uint32 remDefaultGrp: 4; // 10
		uint32 unknown1: 18;
	};
	uint32 val;
};

// MC_ARB_GECC2
union McArbGecc2 {
	struct {
		uint32 enable: 1; // 0
		uint32 eccMode: 2; // 1
		uint32 pageBit0: 2; // 3
		uint32 exorBankSel: 2; // 5
		uint32 noGeccCli: 4; // 7
		uint32 readErr: 3; // 11
		uint32 closeBankRmw: 1; // 14
		uint32 colfifoWater: 6; // 15
		uint32 unknown1: 11;
	};
	uint32 val;
};

// MC_ARB_GECC2_CLI
union McArbGecc2Cli {
	struct {
		uint32 noGeccCli0: 8; // 0
		uint32 noGeccCli1: 8; // 8
		uint32 noGeccCli2: 8; // 16
		uint32 noGeccCli3: 8; // 24
	};
	uint32 val;
};

// MC_ARB_GECC2_DEBUG
union McArbGecc2Debug {
	struct {
		uint32 numErrBits: 2; // 0
		uint32 direction: 1; // 2
		uint32 dataField: 2; // 3
		uint32 swInjection: 1; // 5
		uint32 unknown1: 26;
	};
	uint32 val;
};

// MC_ARB_GECC2_DEBUG2
union McArbGecc2Debug2 {
	struct {
		uint32 period: 8; // 0
		uint32 err0Start: 8; // 8
		uint32 err1Start: 8; // 16
		uint32 err2Start: 8; // 24
	};
	uint32 val;
};

// MC_ARB_GECC2_MISC
union McArbGecc2Misc {
	struct {
		uint32 streakBreak: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// MC_ARB_GECC2_STATUS
union McArbGecc2Status {
	struct {
		uint32 corrSts0: 1; // 0
		uint32 uncorrSts0: 1; // 1
		uint32 fedSts0: 1; // 2
		uint32 rsvd0: 1; // 3
		uint32 corrSts1: 1; // 4
		uint32 uncorrSts1: 1; // 5
		uint32 fedSts1: 1; // 6
		uint32 rsvd1: 1; // 7
		uint32 corrClear0: 1; // 8
		uint32 uncorrClear0: 1; // 9
		uint32 fedClear0: 1; // 10
		uint32 rsvd2: 1; // 11
		uint32 corrClear1: 1; // 12
		uint32 uncorrClear1: 1; // 13
		uint32 fedClear1: 1; // 14
		uint32 unknown1: 17;
	};
	uint32 val;
};

// MC_ARB_LAZY0_RD
union McArbLazy0Rd {
	struct {
		uint32 group0: 8; // 0
		uint32 group1: 8; // 8
		uint32 group2: 8; // 16
		uint32 group3: 8; // 24
	};
	uint32 val;
};

// MC_ARB_LAZY0_WR
union McArbLazy0Wr {
	struct {
		uint32 group0: 8; // 0
		uint32 group1: 8; // 8
		uint32 group2: 8; // 16
		uint32 group3: 8; // 24
	};
	uint32 val;
};

// MC_ARB_LAZY1_RD
union McArbLazy1Rd {
	struct {
		uint32 group4: 8; // 0
		uint32 group5: 8; // 8
		uint32 group6: 8; // 16
		uint32 group7: 8; // 24
	};
	uint32 val;
};

// MC_ARB_LAZY1_WR
union McArbLazy1Wr {
	struct {
		uint32 group4: 8; // 0
		uint32 group5: 8; // 8
		uint32 group6: 8; // 16
		uint32 group7: 8; // 24
	};
	uint32 val;
};

// MC_ARB_LM_RD
union McArbLmRd {
	struct {
		uint32 streakLimit: 8; // 0
		uint32 streakLimitUber: 8; // 8
		uint32 streakBreak: 1; // 16
		uint32 streakUber: 1; // 17
		uint32 enableTwoList: 1; // 18
		uint32 popidleRstTwolist: 1; // 19
		uint32 skid1RstTwolist: 1; // 20
		uint32 bankgroupConfig: 3; // 21
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_ARB_LM_WR
union McArbLmWr {
	struct {
		uint32 streakLimit: 8; // 0
		uint32 streakLimitUber: 8; // 8
		uint32 streakBreak: 1; // 16
		uint32 streakUber: 1; // 17
		uint32 enableTwoList: 1; // 18
		uint32 popidleRstTwolist: 1; // 19
		uint32 skid1RstTwolist: 1; // 20
		uint32 bankgroupConfig: 3; // 21
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_ARB_MINCLKS
union McArbMinclks {
	struct {
		uint32 readClks: 8; // 0
		uint32 writeClks: 8; // 8
		uint32 arbRwSwitch: 1; // 16
		uint32 unknown1: 15;
	};
	uint32 val;
};

// MC_ARB_MISC
union McArbMisc {
	struct {
		uint32 stickyRfsh: 1; // 0
		uint32 idleRfsh: 1; // 1
		uint32 stutterRfsh: 1; // 2
		uint32 chanCouple: 8; // 3
		uint32 harshness: 8; // 11
		uint32 smartRdwrSw: 1; // 19
		uint32 caliEnable: 1; // 20
		uint32 caliRates: 2; // 21
		uint32 dispurgvldNowrt: 1; // 23
		uint32 dispurgNosw2wr: 1; // 24
		uint32 dispurgStall: 1; // 25
		uint32 dispurgThrottle: 4; // 26
		uint32 unknown1: 2;
	};
	uint32 val;
};

// MC_ARB_MISC2
union McArbMisc2 {
	struct {
		uint32 unknown1: 5;
		uint32 tccdl4Bankbit3XorEnable: 1; // 5
		uint32 tccdl4Bankbit3XorColbit4: 1; // 6
		uint32 tccdl4Bankbit3XorColbit5: 1; // 7
		uint32 tccdl4Bankbit3XorColbit6: 1; // 8
		uint32 tccdl4Bankbit3XorColbit7: 1; // 9
		uint32 tccdl4Bankbit3XorColbit8: 1; // 10
		uint32 popIdleReplay: 1; // 11
		uint32 rdretNoReordering: 1; // 12
		uint32 rdretNoBp: 1; // 13
		uint32 rdretSeqSkid: 4; // 14
		uint32 gecc: 1; // 18
		uint32 geccRst: 1; // 19
		uint32 geccStatus: 1; // 20
		uint32 tagfifoThreshold: 4; // 21
		uint32 wcdrReplayMaskcnt: 3; // 25
		uint32 replayDebug: 1; // 28
		uint32 arbDebug29: 1; // 29
		uint32 seqRdyPopIdle: 1; // 30
		uint32 tccdl4ReplayEob: 1; // 31
	};
	uint32 val;
};

// MC_ARB_PM_CNTL
union McArbPmCntl {
	struct {
		uint32 overrideCgstate: 2; // 0
		uint32 ovrrCgrfsh: 1; // 2
		uint32 ovrrCgsqm: 1; // 3
		uint32 srfshOnD1: 1; // 4
		uint32 blkoutOnD1: 1; // 5
		uint32 idleOnD1: 1; // 6
		uint32 ovrrPm: 1; // 7
		uint32 ovrrPmState: 2; // 8
		uint32 ovrrRd: 1; // 10
		uint32 ovrrRdState: 1; // 11
		uint32 ovrrWr: 1; // 12
		uint32 ovrrWrState: 1; // 13
		uint32 ovrrRfsh: 1; // 14
		uint32 ovrrRfshState: 1; // 15
		uint32 unknown1: 2;
		uint32 idleOnD2: 1; // 18
		uint32 idleOnD3: 1; // 19
		uint32 idleCnt: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// MC_ARB_POP
union McArbPop {
	struct {
		uint32 enableArb: 1; // 0
		uint32 specOpen: 1; // 1
		uint32 popDepth: 4; // 2
		uint32 wrdataindexDepth: 6; // 6
		uint32 skidDepth: 3; // 12
		uint32 waitAfterRfsh: 2; // 15
		uint32 quickStop: 1; // 17
		uint32 enableTwoPage: 1; // 18
		uint32 allowEobByWrretStall: 1; // 19
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_ARB_RAMCFG
union McArbRamcfg {
	struct {
		uint32 noofbank: 2; // 0
		uint32 noofranks: 1; // 2
		uint32 noofrows: 3; // 3
		uint32 noofcols: 2; // 6
		uint32 chansize: 1; // 8
		uint32 unknown1: 3;
		uint32 noofgroups: 1; // 12
		uint32 unknown2: 19;
	};
	uint32 val;
};

// MC_ARB_REMREQ
union McArbRemreq {
	struct {
		uint32 rdWater: 8; // 0
		uint32 wrWater: 8; // 8
		uint32 wrMaxburstSize: 4; // 16
		uint32 wrLazyTimer: 4; // 20
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_ARB_REPLAY
union McArbReplay {
	struct {
		uint32 enableRd: 1; // 0
		uint32 enableWr: 1; // 1
		uint32 wrackMode: 1; // 2
		uint32 wawEnable: 1; // 3
		uint32 rawEnable: 1; // 4
		uint32 ignoreWrCdc: 1; // 5
		uint32 breakOnStall: 1; // 6
		uint32 bosEnableWaitCyc: 1; // 7
		uint32 bosWaitCyc: 7; // 8
		uint32 unknown1: 17;
	};
	uint32 val;
};

// MC_ARB_RET_CREDITS_RD
union McArbRetCreditsRd {
	struct {
		uint32 lcl: 8; // 0
		uint32 hub: 8; // 8
		uint32 disp: 8; // 16
		uint32 returnCredit: 8; // 24
	};
	uint32 val;
};

// MC_ARB_RET_CREDITS_WR
union McArbRetCreditsWr {
	struct {
		uint32 lcl: 8; // 0
		uint32 hub: 8; // 8
		uint32 returnCredit: 8; // 16
		uint32 wrretSeqSkid: 4; // 24
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_ARB_RFSH_CNTL
union McArbRfshCntl {
	struct {
		uint32 enable: 1; // 0
		uint32 urg0: 5; // 1
		uint32 urg1: 5; // 6
		uint32 accum: 1; // 11
		uint32 unknown1: 20;
	};
	uint32 val;
};

// MC_ARB_RFSH_RATE
union McArbRfshRate {
	struct {
		uint32 powermode0: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_ARB_RTT_CNTL0
union McArbRttCntl0 {
	struct {
		uint32 enable: 1; // 0
		uint32 startIdle: 1; // 1
		uint32 startR2w: 2; // 2
		uint32 flushOnEnter: 1; // 4
		uint32 harshStart: 1; // 5
		uint32 tpsHarshPriority: 1; // 6
		uint32 twrtHarshPriority: 1; // 7
		uint32 breakOnHarsh: 1; // 8
		uint32 breakOnUrgentrd: 1; // 9
		uint32 breakOnUrgentwr: 1; // 10
		uint32 trainPeriod: 3; // 11
		uint32 startR2wRfsh: 1; // 14
		uint32 debugRsv0: 1; // 15
		uint32 debugRsv1: 1; // 16
		uint32 debugRsv2: 1; // 17
		uint32 debugRsv3: 1; // 18
		uint32 debugRsv4: 1; // 19
		uint32 debugRsv5: 1; // 20
		uint32 debugRsv6: 1; // 21
		uint32 debugRsv7: 1; // 22
		uint32 debugRsv8: 1; // 23
		uint32 dataCntl: 1; // 24
		uint32 neighborBit: 1; // 25
		uint32 unknown1: 6;
	};
	uint32 val;
};

// MC_ARB_RTT_CNTL1
union McArbRttCntl1 {
	struct {
		uint32 windowSize: 5; // 0
		uint32 windowUpdate: 1; // 5
		uint32 windowIncThreshold: 7; // 6
		uint32 windowDecThreshold: 7; // 13
		uint32 windowSizeMax: 5; // 20
		uint32 windowSizeMin: 5; // 25
		uint32 windowUpdateCount: 2; // 30
	};
	uint32 val;
};

// MC_ARB_RTT_CNTL2
union McArbRttCntl2 {
	struct {
		uint32 sampleCnt: 6; // 0
		uint32 phaseAdjustThreshold: 6; // 6
		uint32 phaseAdjustSize: 1; // 12
		uint32 filterCntl: 1; // 13
		uint32 unknown1: 18;
	};
	uint32 val;
};

// MC_ARB_RTT_DATA
union McArbRttData {
	struct {
		uint32 pattern: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_ARB_RTT_DEBUG
union McArbRttDebug {
	struct {
		uint32 debugByteCh0: 2; // 0
		uint32 debugByteCh1: 2; // 2
		uint32 shiftedPhaseCh0: 8; // 4
		uint32 windowSizeCh0: 5; // 12
		uint32 shiftedPhaseCh1: 8; // 17
		uint32 windowSizeCh1: 5; // 25
		uint32 unknown1: 2;
	};
	uint32 val;
};

// MC_ARB_SQM_CNTL
union McArbSqmCntl {
	struct {
		uint32 minPenal: 8; // 0
		uint32 dynSqmEnable: 1; // 8
		uint32 sqmReserve: 7; // 9
		uint32 ratio: 8; // 16
		uint32 ratioDebug: 8; // 24
	};
	uint32 val;
};

// MC_ARB_TM_CNTL_RD
union McArbTmCntlRd {
	struct {
		uint32 groupbyRank: 1; // 0
		uint32 bankSelect: 2; // 1
		uint32 matchRank: 1; // 3
		uint32 matchBank: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// MC_ARB_TM_CNTL_WR
union McArbTmCntlWr {
	struct {
		uint32 groupbyRank: 1; // 0
		uint32 bankSelect: 2; // 1
		uint32 matchRank: 1; // 3
		uint32 matchBank: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// MC_ARB_WCDR
union McArbWcdr {
	struct {
		uint32 idleEnable: 1; // 0
		uint32 seqIdle: 1; // 1
		uint32 idlePeriod: 5; // 2
		uint32 idleBurst: 6; // 7
		uint32 idleBurstMode: 1; // 13
		uint32 idleWakeup: 2; // 14
		uint32 idleDeglitchEnable: 1; // 16
		uint32 wpreEnable: 1; // 17
		uint32 wpreThreshold: 4; // 18
		uint32 wpreMaxBurst: 3; // 22
		uint32 wpreIncRead: 1; // 25
		uint32 wpreIncSkididle: 1; // 26
		uint32 wpreIncSeqidle: 1; // 27
		uint32 wpreTwopage: 1; // 28
		uint32 unknown1: 3;
	};
	uint32 val;
};

// MC_ARB_WCDR_2
union McArbWcdr2 {
	struct {
		uint32 wpreIncStep: 4; // 0
		uint32 wpreMinThreshold: 5; // 4
		uint32 debug0: 1; // 9
		uint32 debug1: 1; // 10
		uint32 debug2: 1; // 11
		uint32 debug3: 1; // 12
		uint32 debug4: 1; // 13
		uint32 debug5: 1; // 14
		uint32 unknown1: 17;
	};
	uint32 val;
};

// MC_ARB_WTM_CNTL_RD
union McArbWtmCntlRd {
	struct {
		uint32 wtmode: 2; // 0
		uint32 harshPri: 1; // 2
		uint32 allowStutterGrp0: 1; // 3
		uint32 allowStutterGrp1: 1; // 4
		uint32 allowStutterGrp2: 1; // 5
		uint32 allowStutterGrp3: 1; // 6
		uint32 allowStutterGrp4: 1; // 7
		uint32 allowStutterGrp5: 1; // 8
		uint32 allowStutterGrp6: 1; // 9
		uint32 allowStutterGrp7: 1; // 10
		uint32 unknown1: 21;
	};
	uint32 val;
};

// MC_ARB_WTM_CNTL_WR
union McArbWtmCntlWr {
	struct {
		uint32 wtmode: 2; // 0
		uint32 harshPri: 1; // 2
		uint32 allowStutterGrp0: 1; // 3
		uint32 allowStutterGrp1: 1; // 4
		uint32 allowStutterGrp2: 1; // 5
		uint32 allowStutterGrp3: 1; // 6
		uint32 allowStutterGrp4: 1; // 7
		uint32 allowStutterGrp5: 1; // 8
		uint32 allowStutterGrp6: 1; // 9
		uint32 allowStutterGrp7: 1; // 10
		uint32 unknown1: 21;
	};
	uint32 val;
};

// MC_ARB_WTM_GRPWT_RD
union McArbWtmGrpwtRd {
	struct {
		uint32 grp0: 2; // 0
		uint32 grp1: 2; // 2
		uint32 grp2: 2; // 4
		uint32 grp3: 2; // 6
		uint32 grp4: 2; // 8
		uint32 grp5: 2; // 10
		uint32 grp6: 2; // 12
		uint32 grp7: 2; // 14
		uint32 grpExt: 8; // 16
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_ARB_WTM_GRPWT_WR
union McArbWtmGrpwtWr {
	struct {
		uint32 grp0: 2; // 0
		uint32 grp1: 2; // 2
		uint32 grp2: 2; // 4
		uint32 grp3: 2; // 6
		uint32 grp4: 2; // 8
		uint32 grp5: 2; // 10
		uint32 grp6: 2; // 12
		uint32 grp7: 2; // 14
		uint32 grpExt: 8; // 16
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_BIST_AUTO_CNTL
union McBistAutoCntl {
	struct {
		uint32 mop: 2; // 0
		uint32 unknown1: 2;
		uint32 adrGen: 4; // 4
		uint32 lfsrKey: 16; // 8
		uint32 lfsrReset: 1; // 24
		uint32 adrReset: 1; // 25
		uint32 unknown2: 6;
	};
	uint32 val;
};

// MC_BIST_CMD_CNTL
union McBistCmdCntl {
	struct {
		uint32 reset: 1; // 0
		uint32 cmdIssueMode: 1; // 1
		uint32 cmdIssueLoop: 1; // 2
		uint32 loopEndCondition: 1; // 3
		uint32 loopCntMax: 12; // 4
		uint32 cmdIssueModeU: 1; // 16
		uint32 cmdIssueRun: 1; // 17
		uint32 loopCntRd: 10; // 18
		uint32 enableD0: 1; // 28
		uint32 enableD1: 1; // 29
		uint32 statusCh: 1; // 30
		uint32 done: 1; // 31
	};
	uint32 val;
};

// MC_BIST_CMP_CNTL
union McBistCmpCntl {
	struct {
		uint32 cmpMaskByte: 4; // 0
		uint32 cmpMaskBit: 8; // 4
		uint32 loadRtedc: 1; // 12
		uint32 dataStoreSel: 1; // 13
		uint32 edcStoreSel: 1; // 14
		uint32 enableCmdFifo: 1; // 15
		uint32 cmp: 2; // 16
		uint32 datMode: 1; // 18
		uint32 edcStoreMode: 1; // 19
		uint32 dataStoreMode: 2; // 20
		uint32 mismatchCnt: 10; // 22
	};
	uint32 val;
};

// MC_BIST_CMP_CNTL_2
union McBistCmpCntl2 {
	struct {
		uint32 dataStoreCnt: 5; // 0
		uint32 unknown1: 3;
		uint32 dataStoreCntRst: 1; // 8
		uint32 unknown2: 3;
		uint32 edcStoreCnt: 5; // 12
		uint32 unknown3: 3;
		uint32 edcStoreCntRst: 1; // 20
		uint32 unknown4: 11;
	};
	uint32 val;
};

// MC_BIST_CNTL
union McBistCntl {
	struct {
		uint32 reset: 1; // 0
		uint32 run: 1; // 1
		uint32 ptrRstD0: 1; // 2
		uint32 ptrRstD1: 1; // 3
		uint32 mopMode: 1; // 4
		uint32 adrMode: 1; // 5
		uint32 datMode: 1; // 6
		uint32 unknown1: 3;
		uint32 loop: 2; // 10
		uint32 enableD0: 1; // 12
		uint32 enableD1: 1; // 13
		uint32 loadRtdataCh: 1; // 14
		uint32 unknown2: 1;
		uint32 loopCnt: 12; // 16
		uint32 unknown3: 2;
		uint32 done: 1; // 30
		uint32 loadRtdata: 1; // 31
	};
	uint32 val;
};

// MC_BIST_DATA_MASK
union McBistDataMask {
	struct {
		uint32 mask: 32; // 0
	};
	uint32 val;
};

// MC_BIST_DATA_WORD0
union McBistDataWord0 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_BIST_DATA_WORD1
union McBistDataWord1 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_BIST_DATA_WORD2
union McBistDataWord2 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_BIST_DATA_WORD3
union McBistDataWord3 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_BIST_DATA_WORD4
union McBistDataWord4 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_BIST_DATA_WORD5
union McBistDataWord5 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_BIST_DATA_WORD6
union McBistDataWord6 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_BIST_DATA_WORD7
union McBistDataWord7 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_BIST_DIR_CNTL
union McBistDirCntl {
	struct {
		uint32 mop: 3; // 0
		uint32 eob: 1; // 3
		uint32 mopLoad: 1; // 4
		uint32 dataLoad: 1; // 5
		uint32 cmdRtrD0: 1; // 6
		uint32 datRtrD0: 1; // 7
		uint32 cmdRtrD1: 1; // 8
		uint32 datRtrD1: 1; // 9
		uint32 mop3: 1; // 10
		uint32 unknown1: 21;
	};
	uint32 val;
};

// MC_BIST_EADDR
union McBistEaddr {
	struct {
		uint32 col: 10; // 0
		uint32 row: 14; // 10
		uint32 bank: 4; // 24
		uint32 rank: 1; // 28
		uint32 colh: 1; // 29
		uint32 rowh: 2; // 30
	};
	uint32 val;
};

// MC_BIST_MISMATCH_ADDR
union McBistMismatchAddr {
	struct {
		uint32 col: 10; // 0
		uint32 row: 14; // 10
		uint32 bank: 4; // 24
		uint32 rank: 1; // 28
		uint32 colh: 1; // 29
		uint32 rowh: 2; // 30
	};
	uint32 val;
};

// MC_BIST_RDATA_EDC
union McBistRdataEdc {
	struct {
		uint32 edc: 32; // 0
	};
	uint32 val;
};

// MC_BIST_RDATA_MASK
union McBistRdataMask {
	struct {
		uint32 mask: 32; // 0
	};
	uint32 val;
};

// MC_BIST_RDATA_WORD0
union McBistRdataWord0 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_BIST_RDATA_WORD1
union McBistRdataWord1 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_BIST_RDATA_WORD2
union McBistRdataWord2 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_BIST_RDATA_WORD3
union McBistRdataWord3 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_BIST_RDATA_WORD4
union McBistRdataWord4 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_BIST_RDATA_WORD5
union McBistRdataWord5 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_BIST_RDATA_WORD6
union McBistRdataWord6 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_BIST_RDATA_WORD7
union McBistRdataWord7 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_BIST_SADDR
union McBistSaddr {
	struct {
		uint32 col: 10; // 0
		uint32 row: 14; // 10
		uint32 bank: 4; // 24
		uint32 rank: 1; // 28
		uint32 colh: 1; // 29
		uint32 rowh: 2; // 30
	};
	uint32 val;
};

// MC_CG_CONFIG
union McCgConfig {
	struct {
		uint32 mcdwWrEnable: 1; // 0
		uint32 mcdxWrEnable: 1; // 1
		uint32 mcdyWrEnable: 1; // 2
		uint32 mcdzWrEnable: 1; // 3
		uint32 mcRdEnable: 2; // 4
		uint32 index: 16; // 6
		uint32 unknown1: 10;
	};
	uint32 val;
};

// MC_CG_CONFIG_MCD
union McCgConfigMcd {
	struct {
		uint32 mcd0WrEnable: 1; // 0
		uint32 mcd1WrEnable: 1; // 1
		uint32 mcd2WrEnable: 1; // 2
		uint32 mcd3WrEnable: 1; // 3
		uint32 mcd4WrEnable: 1; // 4
		uint32 mcd5WrEnable: 1; // 5
		uint32 unknown1: 2;
		uint32 mcRdEnable: 3; // 8
		uint32 unknown2: 2;
		uint32 index: 16; // 13
		uint32 unknown3: 3;
	};
	uint32 val;
};

// MC_CG_DATAPORT
union McCgDataport {
	struct {
		uint32 dataField: 32; // 0
	};
	uint32 val;
};

// MC_CITF_CNTL
union McCitfCntl {
	struct {
		uint32 unknown1: 2;
		uint32 ignorepm: 1; // 2
		uint32 exemptpm: 1; // 3
		uint32 gfxIdleOverride: 2; // 4
		uint32 mcdSrbmMaskEnable: 1; // 6
		uint32 unknown2: 25;
	};
	uint32 val;
};

// MC_CITF_CREDITS_ARB_RD
union McCitfCreditsArbRd {
	struct {
		uint32 readLcl: 8; // 0
		uint32 readHub: 8; // 8
		uint32 readPri: 8; // 16
		uint32 lclPri: 1; // 24
		uint32 hubPri: 1; // 25
		uint32 unknown1: 6;
	};
	uint32 val;
};

// MC_CITF_CREDITS_ARB_WR
union McCitfCreditsArbWr {
	struct {
		uint32 writeLcl: 8; // 0
		uint32 writeHub: 8; // 8
		uint32 hubPri: 1; // 16
		uint32 lclPri: 1; // 17
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_CITF_CREDITS_VM
union McCitfCreditsVm {
	struct {
		uint32 readAll: 6; // 0
		uint32 writeAll: 6; // 6
		uint32 unknown1: 20;
	};
	uint32 val;
};

// MC_CITF_CREDITS_XBAR
union McCitfCreditsXbar {
	struct {
		uint32 readLcl: 8; // 0
		uint32 writeLcl: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_CITF_DAGB_CNTL
union McCitfDagbCntl {
	struct {
		uint32 jumpAhead: 1; // 0
		uint32 centerRdMaxBurst: 4; // 1
		uint32 disableSelfInit: 1; // 5
		uint32 centerWrMaxBurst: 4; // 6
		uint32 unknown1: 22;
	};
	uint32 val;
};

// MC_CITF_DAGB_DLY
union McCitfDagbDly {
	struct {
		uint32 dly: 5; // 0
		uint32 unknown1: 11;
		uint32 cli: 5; // 16
		uint32 unknown2: 3;
		uint32 pos: 5; // 24
		uint32 unknown3: 3;
	};
	uint32 val;
};

// MC_CITF_INT_CREDITS
union McCitfIntCredits {
	struct {
		uint32 remrdret: 6; // 0
		uint32 unknown1: 6;
		uint32 cntrRdHubLp: 6; // 12
		uint32 cntrRdHubHp: 6; // 18
		uint32 cntrRdLcl: 6; // 24
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_CITF_INT_CREDITS_WR
union McCitfIntCreditsWr {
	struct {
		uint32 cntrWrHub: 6; // 0
		uint32 cntrWrLcl: 6; // 6
		uint32 unknown1: 20;
	};
	uint32 val;
};

// MC_CITF_MISC_RD_CG
union McCitfMiscRdCg {
	struct {
		uint32 ondly: 6; // 0
		uint32 offdly: 6; // 6
		uint32 rdydly: 6; // 12
		uint32 enable: 1; // 18
		uint32 memLsEnable: 1; // 19
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_CITF_MISC_VM_CG
union McCitfMiscVmCg {
	struct {
		uint32 ondly: 6; // 0
		uint32 offdly: 6; // 6
		uint32 rdydly: 6; // 12
		uint32 enable: 1; // 18
		uint32 memLsEnable: 1; // 19
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_CITF_MISC_WR_CG
union McCitfMiscWrCg {
	struct {
		uint32 ondly: 6; // 0
		uint32 offdly: 6; // 6
		uint32 rdydly: 6; // 12
		uint32 enable: 1; // 18
		uint32 memLsEnable: 1; // 19
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_CITF_PERF_MON_CNTL2
union McCitfPerfMonCntl2 {
	struct {
		uint32 cid: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// MC_CITF_PERF_MON_RSLT2
union McCitfPerfMonRslt2 {
	struct {
		uint32 unknown1: 6;
		uint32 cbRdBusy: 1; // 6
		uint32 dbRdBusy: 1; // 7
		uint32 tc0RdBusy: 1; // 8
		uint32 vc0RdBusy: 1; // 9
		uint32 tc1RdBusy: 1; // 10
		uint32 vc1RdBusy: 1; // 11
		uint32 cbWrBusy: 1; // 12
		uint32 dbWrBusy: 1; // 13
		uint32 sxWrBusy: 1; // 14
		uint32 tc2RdBusy: 1; // 15
		uint32 tc0WrBusy: 1; // 16
		uint32 tc1WrBusy: 1; // 17
		uint32 tc2WrBusy: 1; // 18
		uint32 unknown2: 13;
	};
	uint32 val;
};

// MC_CITF_REMREQ
union McCitfRemreq {
	struct {
		uint32 readCredits: 7; // 0
		uint32 writeCredits: 7; // 7
		uint32 creditsEnable: 1; // 14
		uint32 unknown1: 17;
	};
	uint32 val;
};

// MC_CITF_RET_MODE
union McCitfRetMode {
	struct {
		uint32 inorderRd: 1; // 0
		uint32 inorderWr: 1; // 1
		uint32 rempriRd: 1; // 2
		uint32 rempriWr: 1; // 3
		uint32 lclpriRd: 1; // 4
		uint32 lclpriWr: 1; // 5
		uint32 unknown1: 26;
	};
	uint32 val;
};

// MC_CITF_WTM_RD_CNTL
union McCitfWtmRdCntl {
	struct {
		uint32 group0Decrement: 3; // 0
		uint32 group1Decrement: 3; // 3
		uint32 group2Decrement: 3; // 6
		uint32 group3Decrement: 3; // 9
		uint32 group4Decrement: 3; // 12
		uint32 group5Decrement: 3; // 15
		uint32 group6Decrement: 3; // 18
		uint32 group7Decrement: 3; // 21
		uint32 disableRemote: 1; // 24
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_CITF_WTM_WR_CNTL
union McCitfWtmWrCntl {
	struct {
		uint32 group0Decrement: 3; // 0
		uint32 group1Decrement: 3; // 3
		uint32 group2Decrement: 3; // 6
		uint32 group3Decrement: 3; // 9
		uint32 group4Decrement: 3; // 12
		uint32 group5Decrement: 3; // 15
		uint32 group6Decrement: 3; // 18
		uint32 group7Decrement: 3; // 21
		uint32 disableRemote: 1; // 24
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_CITF_XTRA_ENABLE
union McCitfXtraEnable {
	struct {
		uint32 cb1Rd: 1; // 0
		uint32 cb1Wr: 1; // 1
		uint32 db1Rd: 1; // 2
		uint32 db1Wr: 1; // 3
		uint32 tc2Rd: 1; // 4
		uint32 unknown1: 3;
		uint32 arbDbg: 4; // 8
		uint32 tc2Wr: 1; // 12
		uint32 unknown2: 19;
	};
	uint32 val;
};

// MC_CONFIG
union McConfig {
	struct {
		uint32 mcdwWrEnable: 1; // 0
		uint32 mcdxWrEnable: 1; // 1
		uint32 mcdyWrEnable: 1; // 2
		uint32 mcdzWrEnable: 1; // 3
		uint32 mcRdEnable: 2; // 4
		uint32 unknown1: 25;
		uint32 mccIndexModeEnable: 1; // 31
	};
	uint32 val;
};

// MC_CONFIG_MCD
union McConfigMcd {
	struct {
		uint32 mcd0WrEnable: 1; // 0
		uint32 mcd1WrEnable: 1; // 1
		uint32 mcd2WrEnable: 1; // 2
		uint32 mcd3WrEnable: 1; // 3
		uint32 mcd4WrEnable: 1; // 4
		uint32 mcd5WrEnable: 1; // 5
		uint32 unknown1: 2;
		uint32 mcRdEnable: 3; // 8
		uint32 unknown2: 20;
		uint32 mcdIndexModeEnable: 1; // 31
	};
	uint32 val;
};

// MC_HUB_MISC_DBG
union McHubMiscDbg {
	struct {
		uint32 select0: 4; // 0
		uint32 select1: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_HUB_MISC_FRAMING
union McHubMiscFraming {
	struct {
		uint32 bits: 32; // 0
	};
	uint32 val;
};

// MC_HUB_MISC_HUB_CG
union McHubMiscHubCg {
	struct {
		uint32 ondly: 6; // 0
		uint32 offdly: 6; // 6
		uint32 rdydly: 6; // 12
		uint32 enable: 1; // 18
		uint32 memLsEnable: 1; // 19
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_HUB_MISC_IDLE_STATUS
union McHubMiscIdleStatus {
	struct {
		uint32 outstandingCpRead: 1; // 0
		uint32 outstandingCpWrite: 1; // 1
		uint32 outstandingGfxRead: 1; // 2
		uint32 outstandingGfxWrite: 1; // 3
		uint32 unknown1: 2;
		uint32 outstandingRlcRead: 1; // 6
		uint32 outstandingRlcWrite: 1; // 7
		uint32 unknown2: 2;
		uint32 outstandingDispRead: 1; // 10
		uint32 outstandingDispWrite: 1; // 11
		uint32 outstandingUvdRead: 1; // 12
		uint32 outstandingUvdWrite: 1; // 13
		uint32 outstandingSmuRead: 1; // 14
		uint32 outstandingSmuWrite: 1; // 15
		uint32 outstandingHdpRead: 1; // 16
		uint32 outstandingHdpWrite: 1; // 17
		uint32 outstandingOthRead: 1; // 18
		uint32 outstandingOthWrite: 1; // 19
		uint32 outstandingVmcRead: 1; // 20
		uint32 outstandingVmcWrite: 1; // 21
		uint32 unknown3: 2;
		uint32 outstandingVceRead: 1; // 24
		uint32 outstandingVceWrite: 1; // 25
		uint32 unknown4: 6;
	};
	uint32 val;
};

// MC_HUB_MISC_OVERRIDE
union McHubMiscOverride {
	struct {
		uint32 idle: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// MC_HUB_MISC_POWER
union McHubMiscPower {
	struct {
		uint32 unknown1: 2;
		uint32 srbmGateOverride: 1; // 2
		uint32 pmBlackoutCntl: 2; // 3
		uint32 unknown2: 27;
	};
	uint32 val;
};

// MC_HUB_MISC_SIP_CG
union McHubMiscSipCg {
	struct {
		uint32 ondly: 6; // 0
		uint32 offdly: 6; // 6
		uint32 rdydly: 6; // 12
		uint32 enable: 1; // 18
		uint32 memLsEnable: 1; // 19
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_HUB_MISC_STATUS
union McHubMiscStatus {
	struct {
		uint32 outstandingRead: 1; // 0
		uint32 outstandingWrite: 1; // 1
		uint32 outstandingHubRdreq: 1; // 2
		uint32 outstandingHubRdret: 1; // 3
		uint32 outstandingHubWrreq: 1; // 4
		uint32 outstandingHubWrret: 1; // 5
		uint32 outstandingRpbRead: 1; // 6
		uint32 outstandingRpbWrite: 1; // 7
		uint32 outstandingMcdRead: 1; // 8
		uint32 outstandingMcdWrite: 1; // 9
		uint32 rpbBusy: 1; // 10
		uint32 writeDeadlockWarning: 1; // 11
		uint32 readDeadlockWarning: 1; // 12
		uint32 gfxBusy: 1; // 13
		uint32 unknown1: 18;
	};
	uint32 val;
};

// MC_HUB_MISC_VM_CG
union McHubMiscVmCg {
	struct {
		uint32 ondly: 6; // 0
		uint32 offdly: 6; // 6
		uint32 rdydly: 6; // 12
		uint32 enable: 1; // 18
		uint32 memLsEnable: 1; // 19
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_HUB_RDREQ_CNTL
union McHubRdreqCntl {
	struct {
		uint32 remoteBlackout: 1; // 0
		uint32 unknown1: 1;
		uint32 jumpaheadGbl0: 1; // 2
		uint32 jumpaheadGbl1: 1; // 3
		uint32 overrideStallEnable: 1; // 4
		uint32 mcdwStallMode: 1; // 5
		uint32 mcdxStallMode: 1; // 6
		uint32 mcdyStallMode: 1; // 7
		uint32 mcdzStallMode: 1; // 8
		uint32 breakHdpDeadlock: 1; // 9
		uint32 debugReg: 7; // 10
		uint32 disableSelfInitGbl0: 1; // 17
		uint32 disableSelfInitGbl1: 1; // 18
		uint32 pwrxpressMode: 1; // 19
		uint32 unknown2: 12;
	};
	uint32 val;
};

// MC_HUB_RDREQ_CREDITS
union McHubRdreqCredits {
	struct {
		uint32 vm0: 8; // 0
		uint32 vm1: 8; // 8
		uint32 stor0: 8; // 16
		uint32 stor1: 8; // 24
	};
	uint32 val;
};

// MC_HUB_RDREQ_CREDITS2
union McHubRdreqCredits2 {
	struct {
		uint32 stor1Pri: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_HUB_RDREQ_DMIF
union McHubRdreqDmif {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_RDREQ_DMIF_LIMIT
union McHubRdreqDmifLimit {
	struct {
		uint32 enable: 2; // 0
		uint32 limitCount: 5; // 2
		uint32 unknown1: 25;
	};
	uint32 val;
};

// MC_HUB_RDREQ_GBL0
union McHubRdreqGbl0 {
	struct {
		uint32 stallThreshold: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_HUB_RDREQ_GBL1
union McHubRdreqGbl1 {
	struct {
		uint32 stallThreshold: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_HUB_RDREQ_HDP
union McHubRdreqHdp {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_RDREQ_MCDW
union McHubRdreqMcdw {
	struct {
		uint32 enable: 1; // 0
		uint32 blackoutExempt: 1; // 1
		uint32 bus: 1; // 2
		uint32 maxburst: 4; // 3
		uint32 lazyTimer: 4; // 7
		uint32 askCredits: 7; // 11
		uint32 displayCredits: 7; // 18
		uint32 stallThreshold: 7; // 25
	};
	uint32 val;
};

// MC_HUB_RDREQ_MCDX
union McHubRdreqMcdx {
	struct {
		uint32 enable: 1; // 0
		uint32 blackoutExempt: 1; // 1
		uint32 bus: 1; // 2
		uint32 maxburst: 4; // 3
		uint32 lazyTimer: 4; // 7
		uint32 askCredits: 7; // 11
		uint32 displayCredits: 7; // 18
		uint32 stallThreshold: 7; // 25
	};
	uint32 val;
};

// MC_HUB_RDREQ_MCDY
union McHubRdreqMcdy {
	struct {
		uint32 enable: 1; // 0
		uint32 blackoutExempt: 1; // 1
		uint32 bus: 1; // 2
		uint32 maxburst: 4; // 3
		uint32 lazyTimer: 4; // 7
		uint32 askCredits: 7; // 11
		uint32 displayCredits: 7; // 18
		uint32 stallThreshold: 7; // 25
	};
	uint32 val;
};

// MC_HUB_RDREQ_MCDZ
union McHubRdreqMcdz {
	struct {
		uint32 enable: 1; // 0
		uint32 blackoutExempt: 1; // 1
		uint32 bus: 1; // 2
		uint32 maxburst: 4; // 3
		uint32 lazyTimer: 4; // 7
		uint32 askCredits: 7; // 11
		uint32 displayCredits: 7; // 18
		uint32 stallThreshold: 7; // 25
	};
	uint32 val;
};

// MC_HUB_RDREQ_MCIF
union McHubRdreqMcif {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_RDREQ_RLC
union McHubRdreqRlc {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_RDREQ_SEM
union McHubRdreqSem {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_RDREQ_SIP
union McHubRdreqSip {
	struct {
		uint32 askCredits: 7; // 0
		uint32 dummy: 1; // 7
		uint32 displayCredits: 7; // 8
		uint32 unknown1: 17;
	};
	uint32 val;
};

// MC_HUB_RDREQ_SMU
union McHubRdreqSmu {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_RDREQ_STATUS
union McHubRdreqStatus {
	struct {
		uint32 sipAvail: 1; // 0
		uint32 mcdwRdAvail: 1; // 1
		uint32 mcdxRdAvail: 1; // 2
		uint32 mcdyRdAvail: 1; // 3
		uint32 mcdzRdAvail: 1; // 4
		uint32 gbl0VmFull: 1; // 5
		uint32 gbl0StorFull: 1; // 6
		uint32 gbl0BypassStorFull: 1; // 7
		uint32 gbl1VmFull: 1; // 8
		uint32 gbl1StorFull: 1; // 9
		uint32 gbl1BypassStorFull: 1; // 10
		uint32 pwrxpressErr: 1; // 11
		uint32 unknown1: 20;
	};
	uint32 val;
};

// MC_HUB_RDREQ_UMC
union McHubRdreqUmc {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_RDREQ_UVD
union McHubRdreqUvd {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 vmBypass: 1; // 16
		uint32 unknown1: 15;
	};
	uint32 val;
};

// MC_HUB_RDREQ_VCE
union McHubRdreqVce {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_RDREQ_VCEU
union McHubRdreqVceu {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_RDREQ_VMC
union McHubRdreqVmc {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_RDREQ_WTM_CNTL
union McHubRdreqWtmCntl {
	struct {
		uint32 group0Decrement: 3; // 0
		uint32 group1Decrement: 3; // 3
		uint32 group2Decrement: 3; // 6
		uint32 group3Decrement: 3; // 9
		uint32 group4Decrement: 3; // 12
		uint32 group5Decrement: 3; // 15
		uint32 group6Decrement: 3; // 18
		uint32 group7Decrement: 3; // 21
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_HUB_RDREQ_XDMAM
union McHubRdreqXdmam {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_SHARED_DAGB_DLY
union McHubSharedDagbDly {
	struct {
		uint32 dly: 6; // 0
		uint32 unknown1: 10;
		uint32 cli: 5; // 16
		uint32 unknown2: 3;
		uint32 pos: 5; // 24
		uint32 unknown3: 3;
	};
	uint32 val;
};

// MC_HUB_WDP_BP
union McHubWdpBp {
	struct {
		uint32 enable: 1; // 0
		uint32 rdret: 17; // 1
		uint32 wrreq: 12; // 18
		uint32 unknown1: 2;
	};
	uint32 val;
};

// MC_HUB_WDP_CNTL
union McHubWdpCntl {
	struct {
		uint32 unknown1: 1;
		uint32 jumpaheadGbl0: 1; // 1
		uint32 jumpaheadGbl1: 1; // 2
		uint32 jumpaheadInternal: 1; // 3
		uint32 overrideStallEnable: 1; // 4
		uint32 debugReg: 8; // 5
		uint32 disableSelfInitGbl0: 1; // 13
		uint32 disableSelfInitGbl1: 1; // 14
		uint32 disableSelfInitInternal: 1; // 15
		uint32 fairChSw: 1; // 16
		uint32 lclwrreqBypass: 1; // 17
		uint32 dispWaitEop: 1; // 18
		uint32 mcdWaitEop: 1; // 19
		uint32 sipWaitEop: 1; // 20
		uint32 unknown2: 11;
	};
	uint32 val;
};

// MC_HUB_WDP_CREDITS
union McHubWdpCredits {
	struct {
		uint32 vm0: 8; // 0
		uint32 vm1: 8; // 8
		uint32 stor0: 8; // 16
		uint32 stor1: 8; // 24
	};
	uint32 val;
};

// MC_HUB_WDP_ERR
union McHubWdpErr {
	struct {
		uint32 mgpu1TargSys: 1; // 0
		uint32 mgpu2TargSys: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// MC_HUB_WDP_GBL0
union McHubWdpGbl0 {
	struct {
		uint32 maxburst: 4; // 0
		uint32 lazyTimer: 4; // 4
		uint32 stallThreshold: 8; // 8
		uint32 stallMode: 1; // 16
		uint32 unknown1: 15;
	};
	uint32 val;
};

// MC_HUB_WDP_GBL1
union McHubWdpGbl1 {
	struct {
		uint32 maxburst: 4; // 0
		uint32 lazyTimer: 4; // 4
		uint32 stallThreshold: 8; // 8
		uint32 stallMode: 1; // 16
		uint32 unknown1: 15;
	};
	uint32 val;
};

// MC_HUB_WDP_HDP
union McHubWdpHdp {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_WDP_IH
union McHubWdpIh {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_WDP_MCDW
union McHubWdpMcdw {
	struct {
		uint32 enable: 1; // 0
		uint32 blackoutExempt: 1; // 1
		uint32 stallMode: 1; // 2
		uint32 maxburst: 4; // 3
		uint32 askCredits: 6; // 7
		uint32 lazyTimer: 4; // 13
		uint32 stallThreshold: 7; // 17
		uint32 askCreditsW: 7; // 24
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_HUB_WDP_MCDX
union McHubWdpMcdx {
	struct {
		uint32 enable: 1; // 0
		uint32 blackoutExempt: 1; // 1
		uint32 stallMode: 1; // 2
		uint32 maxburst: 4; // 3
		uint32 askCredits: 6; // 7
		uint32 lazyTimer: 4; // 13
		uint32 stallThreshold: 7; // 17
		uint32 askCreditsW: 7; // 24
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_HUB_WDP_MCDY
union McHubWdpMcdy {
	struct {
		uint32 enable: 1; // 0
		uint32 blackoutExempt: 1; // 1
		uint32 stallMode: 1; // 2
		uint32 maxburst: 4; // 3
		uint32 askCredits: 6; // 7
		uint32 lazyTimer: 4; // 13
		uint32 stallThreshold: 7; // 17
		uint32 askCreditsW: 7; // 24
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_HUB_WDP_MCDZ
union McHubWdpMcdz {
	struct {
		uint32 enable: 1; // 0
		uint32 blackoutExempt: 1; // 1
		uint32 stallMode: 1; // 2
		uint32 maxburst: 4; // 3
		uint32 askCredits: 6; // 7
		uint32 lazyTimer: 4; // 13
		uint32 stallThreshold: 7; // 17
		uint32 askCreditsW: 7; // 24
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_HUB_WDP_MCIF
union McHubWdpMcif {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_WDP_MGPU
union McHubWdpMgpu {
	struct {
		uint32 stor: 8; // 0
		uint32 cid: 8; // 8
		uint32 mgpuPriorityTime: 7; // 16
		uint32 enable: 1; // 23
		uint32 othPriorityTime: 7; // 24
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_HUB_WDP_MGPU2
union McHubWdpMgpu2 {
	struct {
		uint32 cid2: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_HUB_WDP_RLC
union McHubWdpRlc {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_WDP_SEM
union McHubWdpSem {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_WDP_SH0
union McHubWdpSh0 {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_WDP_SH1
union McHubWdpSh1 {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_WDP_SIP
union McHubWdpSip {
	struct {
		uint32 stallMode: 2; // 0
		uint32 askCredits: 7; // 2
		uint32 unknown1: 23;
	};
	uint32 val;
};

// MC_HUB_WDP_SMU
union McHubWdpSmu {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_WDP_STATUS
union McHubWdpStatus {
	struct {
		uint32 sipAvail: 1; // 0
		uint32 mcdwRdAvail: 1; // 1
		uint32 mcdxRdAvail: 1; // 2
		uint32 mcdyRdAvail: 1; // 3
		uint32 mcdzRdAvail: 1; // 4
		uint32 gbl0VmFull: 1; // 5
		uint32 gbl0StorFull: 1; // 6
		uint32 gbl0BypassStorFull: 1; // 7
		uint32 gbl1VmFull: 1; // 8
		uint32 gbl1StorFull: 1; // 9
		uint32 gbl1BypassStorFull: 1; // 10
		uint32 mcdwWrAvail: 1; // 11
		uint32 mcdxWrAvail: 1; // 12
		uint32 mcdyWrAvail: 1; // 13
		uint32 mcdzWrAvail: 1; // 14
		uint32 unknown1: 17;
	};
	uint32 val;
};

// MC_HUB_WDP_UMC
union McHubWdpUmc {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_WDP_UVD
union McHubWdpUvd {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 vmBypass: 1; // 16
		uint32 unknown1: 15;
	};
	uint32 val;
};

// MC_HUB_WDP_VCE
union McHubWdpVce {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_WDP_VCEU
union McHubWdpVceu {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_WDP_WTM_CNTL
union McHubWdpWtmCntl {
	struct {
		uint32 group0Decrement: 3; // 0
		uint32 group1Decrement: 3; // 3
		uint32 group2Decrement: 3; // 6
		uint32 group3Decrement: 3; // 9
		uint32 group4Decrement: 3; // 12
		uint32 group5Decrement: 3; // 15
		uint32 group6Decrement: 3; // 18
		uint32 group7Decrement: 3; // 21
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_HUB_WDP_XDMA
union McHubWdpXdma {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 bypassAvailOverride: 1; // 16
		uint32 unknown1: 15;
	};
	uint32 val;
};

// MC_HUB_WDP_XDMAM
union McHubWdpXdmam {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 bypassAvailOverride: 1; // 16
		uint32 unknown1: 15;
	};
	uint32 val;
};

// MC_HUB_WDP_XDP
union McHubWdpXdp {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxburst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_HUB_WRRET_CNTL
union McHubWrretCntl {
	struct {
		uint32 jumpahead: 1; // 0
		uint32 bp: 20; // 1
		uint32 bpEnable: 1; // 21
		uint32 debugReg: 8; // 22
		uint32 disableSelfInit: 1; // 30
		uint32 fairChSw: 1; // 31
	};
	uint32 val;
};

// MC_HUB_WRRET_MCDW
union McHubWrretMcdw {
	struct {
		uint32 stallMode: 1; // 0
		uint32 creditCount: 7; // 1
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_HUB_WRRET_MCDX
union McHubWrretMcdx {
	struct {
		uint32 stallMode: 1; // 0
		uint32 creditCount: 7; // 1
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_HUB_WRRET_MCDY
union McHubWrretMcdy {
	struct {
		uint32 stallMode: 1; // 0
		uint32 creditCount: 7; // 1
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_HUB_WRRET_MCDZ
union McHubWrretMcdz {
	struct {
		uint32 stallMode: 1; // 0
		uint32 creditCount: 7; // 1
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_HUB_WRRET_STATUS
union McHubWrretStatus {
	struct {
		uint32 mcdwAvail: 1; // 0
		uint32 mcdxAvail: 1; // 1
		uint32 mcdyAvail: 1; // 2
		uint32 mcdzAvail: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// MC_IMP_CNTL
union McImpCntl {
	struct {
		uint32 memIoUpdateRate: 5; // 0
		uint32 calVrefSel: 1; // 5
		uint32 calVrefmode: 1; // 6
		uint32 unknown1: 1;
		uint32 timeoutErr: 1; // 8
		uint32 clearTimeoutErr: 1; // 9
		uint32 unknown2: 3;
		uint32 memIoSampleCnt: 3; // 13
		uint32 calVref: 7; // 16
		uint32 unknown3: 6;
		uint32 calWhenIdle: 1; // 29
		uint32 calWhenRefresh: 1; // 30
		uint32 calPwron: 1; // 31
	};
	uint32 val;
};

// MC_IMP_DEBUG
union McImpDebug {
	struct {
		uint32 tstartupCntr: 8; // 0
		uint32 timeoutCntr: 8; // 8
		uint32 pmvcalReserved: 12; // 16
		uint32 debugCalEn: 1; // 28
		uint32 debugCalStart: 1; // 29
		uint32 debugCalIntr: 1; // 30
		uint32 debugCalDone: 1; // 31
	};
	uint32 val;
};

// MC_IMP_DQ_STATUS
union McImpDqStatus {
	struct {
		uint32 ch0DqPstr: 8; // 0
		uint32 ch0DqNstr: 8; // 8
		uint32 ch1DqPstr: 8; // 16
		uint32 ch1DqNstr: 8; // 24
	};
	uint32 val;
};

// MC_IMP_STATUS
union McImpStatus {
	struct {
		uint32 pstrCal: 8; // 0
		uint32 pstrAccumVal: 8; // 8
		uint32 nstrCal: 8; // 16
		uint32 nstrAccumVal: 8; // 24
	};
	uint32 val;
};

// MC_IO_APHY_STR_CNTL_D0
union McIoAphyStrCntlD0 {
	struct {
		uint32 pstrOffA: 6; // 0
		uint32 nstrOffA: 6; // 6
		uint32 pstrOffDRd: 6; // 12
		uint32 unknown1: 6;
		uint32 useACal: 1; // 24
		uint32 useDRdCal: 1; // 25
		uint32 calSel: 2; // 26
		uint32 loadAStr: 1; // 28
		uint32 loadDRdStr: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_IO_APHY_STR_CNTL_D1
union McIoAphyStrCntlD1 {
	struct {
		uint32 pstrOffA: 6; // 0
		uint32 nstrOffA: 6; // 6
		uint32 pstrOffDRd: 6; // 12
		uint32 unknown1: 6;
		uint32 useACal: 1; // 24
		uint32 useDRdCal: 1; // 25
		uint32 calSel: 2; // 26
		uint32 loadAStr: 1; // 28
		uint32 loadDRdStr: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_IO_CDRCNTL1_D0
union McIoCdrcntl1D0 {
	struct {
		uint32 dqRxphaseB0: 8; // 0
		uint32 dqRxphaseB1: 8; // 8
		uint32 wcdrTxphaseB0: 8; // 16
		uint32 wcdrTxphaseB1: 8; // 24
	};
	uint32 val;
};

// MC_IO_CDRCNTL1_D1
union McIoCdrcntl1D1 {
	struct {
		uint32 dqRxphaseB0: 8; // 0
		uint32 dqRxphaseB1: 8; // 8
		uint32 wcdrTxphaseB0: 8; // 16
		uint32 wcdrTxphaseB1: 8; // 24
	};
	uint32 val;
};

// MC_IO_CDRCNTL2_D0
union McIoCdrcntl2D0 {
	struct {
		uint32 cdrFbSel0: 1; // 0
		uint32 cdrFbSel1: 1; // 1
		uint32 edcRxenOvr0: 1; // 2
		uint32 edcRxenOvr1: 1; // 3
		uint32 txcdrbypass0: 1; // 4
		uint32 txcdrbypass1: 1; // 5
		uint32 wckRxenOvr0: 1; // 6
		uint32 wckRxenOvr1: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_IO_CDRCNTL2_D1
union McIoCdrcntl2D1 {
	struct {
		uint32 cdrFbSel0: 1; // 0
		uint32 cdrFbSel1: 1; // 1
		uint32 edcRxenOvr0: 1; // 2
		uint32 edcRxenOvr1: 1; // 3
		uint32 txcdrbypass0: 1; // 4
		uint32 txcdrbypass1: 1; // 5
		uint32 wckRxenOvr0: 1; // 6
		uint32 wckRxenOvr1: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_IO_CDRCNTL_D0
union McIoCdrcntlD0 {
	struct {
		uint32 rxphaseB01: 4; // 0
		uint32 rxphaseB23: 4; // 4
		uint32 rxcdrenB01: 1; // 8
		uint32 rxcdrenB23: 1; // 9
		uint32 rxcdrbypassB01: 1; // 10
		uint32 rxcdrbypassB23: 1; // 11
		uint32 rxphase1B01: 4; // 12
		uint32 rxphase1B23: 4; // 16
		uint32 dqtxcdrenB0: 1; // 20
		uint32 dqtxcdrenB1: 1; // 21
		uint32 dqrxcdrenB0: 1; // 22
		uint32 dqrxcdrenB1: 1; // 23
		uint32 wcdrrxcdrenB0: 1; // 24
		uint32 wcdrrxcdrenB1: 1; // 25
		uint32 wcdredcB0: 1; // 26
		uint32 wcdredcB1: 1; // 27
		uint32 dqrxselB0: 1; // 28
		uint32 dqrxselB1: 1; // 29
		uint32 dqtxselB0: 1; // 30
		uint32 dqtxselB1: 1; // 31
	};
	uint32 val;
};

// MC_IO_CDRCNTL_D1
union McIoCdrcntlD1 {
	struct {
		uint32 rxphaseB01: 4; // 0
		uint32 rxphaseB23: 4; // 4
		uint32 rxcdrenB01: 1; // 8
		uint32 rxcdrenB23: 1; // 9
		uint32 rxcdrbypassB01: 1; // 10
		uint32 rxcdrbypassB23: 1; // 11
		uint32 rxphase1B01: 4; // 12
		uint32 rxphase1B23: 4; // 16
		uint32 dqtxcdrenB0: 1; // 20
		uint32 dqtxcdrenB1: 1; // 21
		uint32 dqrxcdrenB0: 1; // 22
		uint32 dqrxcdrenB1: 1; // 23
		uint32 wcdrrxcdrenB0: 1; // 24
		uint32 wcdrrxcdrenB1: 1; // 25
		uint32 wcdredcB0: 1; // 26
		uint32 wcdredcB1: 1; // 27
		uint32 dqrxselB0: 1; // 28
		uint32 dqrxselB1: 1; // 29
		uint32 dqtxselB0: 1; // 30
		uint32 dqtxselB1: 1; // 31
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_CLKSEL_D0
union McIoDebugAcmdClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_CLKSEL_D1
union McIoDebugAcmdClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_MISC_D0
union McIoDebugAcmdMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_MISC_D1
union McIoDebugAcmdMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_OFSCAL_D0
union McIoDebugAcmdOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_OFSCAL_D1
union McIoDebugAcmdOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_RXPHASE_D0
union McIoDebugAcmdRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_RXPHASE_D1
union McIoDebugAcmdRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_TXBST_PD_D0
union McIoDebugAcmdTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_TXBST_PD_D1
union McIoDebugAcmdTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_TXBST_PU_D0
union McIoDebugAcmdTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_TXBST_PU_D1
union McIoDebugAcmdTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_TXPHASE_D0
union McIoDebugAcmdTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_TXPHASE_D1
union McIoDebugAcmdTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_TXSLF_D0
union McIoDebugAcmdTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ACMD_TXSLF_D1
union McIoDebugAcmdTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_CLKSEL_D0
union McIoDebugAddrhClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_CLKSEL_D1
union McIoDebugAddrhClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_MISC_D0
union McIoDebugAddrhMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_MISC_D1
union McIoDebugAddrhMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_RXPHASE_D0
union McIoDebugAddrhRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_RXPHASE_D1
union McIoDebugAddrhRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_TXBST_PD_D0
union McIoDebugAddrhTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_TXBST_PD_D1
union McIoDebugAddrhTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_TXBST_PU_D0
union McIoDebugAddrhTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_TXBST_PU_D1
union McIoDebugAddrhTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_TXPHASE_D0
union McIoDebugAddrhTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_TXPHASE_D1
union McIoDebugAddrhTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_TXSLF_D0
union McIoDebugAddrhTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRH_TXSLF_D1
union McIoDebugAddrhTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_CLKSEL_D0
union McIoDebugAddrlClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_CLKSEL_D1
union McIoDebugAddrlClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_MISC_D0
union McIoDebugAddrlMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_MISC_D1
union McIoDebugAddrlMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_RXPHASE_D0
union McIoDebugAddrlRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_RXPHASE_D1
union McIoDebugAddrlRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_TXBST_PD_D0
union McIoDebugAddrlTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_TXBST_PD_D1
union McIoDebugAddrlTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_TXBST_PU_D0
union McIoDebugAddrlTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_TXBST_PU_D1
union McIoDebugAddrlTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_TXPHASE_D0
union McIoDebugAddrlTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_TXPHASE_D1
union McIoDebugAddrlTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_TXSLF_D0
union McIoDebugAddrlTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_ADDRL_TXSLF_D1
union McIoDebugAddrlTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_CLKSEL_D0
union McIoDebugCkClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_CLKSEL_D1
union McIoDebugCkClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_MISC_D0
union McIoDebugCkMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_MISC_D1
union McIoDebugCkMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_RXPHASE_D0
union McIoDebugCkRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_RXPHASE_D1
union McIoDebugCkRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_TXBST_PD_D0
union McIoDebugCkTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_TXBST_PD_D1
union McIoDebugCkTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_TXBST_PU_D0
union McIoDebugCkTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_TXBST_PU_D1
union McIoDebugCkTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_TXPHASE_D0
union McIoDebugCkTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_TXPHASE_D1
union McIoDebugCkTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_TXSLF_D0
union McIoDebugCkTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CK_TXSLF_D1
union McIoDebugCkTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_CLKSEL_D0
union McIoDebugCmdClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_CLKSEL_D1
union McIoDebugCmdClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_MISC_D0
union McIoDebugCmdMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_MISC_D1
union McIoDebugCmdMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_OFSCAL_D0
union McIoDebugCmdOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_OFSCAL_D1
union McIoDebugCmdOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_RXPHASE_D0
union McIoDebugCmdRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_RXPHASE_D1
union McIoDebugCmdRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_RX_EQ_D0
union McIoDebugCmdRxEqD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_RX_EQ_D1
union McIoDebugCmdRxEqD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_TXBST_PD_D0
union McIoDebugCmdTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_TXBST_PD_D1
union McIoDebugCmdTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_TXBST_PU_D0
union McIoDebugCmdTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_TXBST_PU_D1
union McIoDebugCmdTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_TXPHASE_D0
union McIoDebugCmdTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_TXPHASE_D1
union McIoDebugCmdTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_TXSLF_D0
union McIoDebugCmdTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_CMD_TXSLF_D1
union McIoDebugCmdTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_CDR_PHSIZE_D0
union McIoDebugDbiCdrPhsizeD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_CDR_PHSIZE_D1
union McIoDebugDbiCdrPhsizeD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_CLKSEL_D0
union McIoDebugDbiClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_CLKSEL_D1
union McIoDebugDbiClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_MISC_D0
union McIoDebugDbiMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_MISC_D1
union McIoDebugDbiMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_OFSCAL_D0
union McIoDebugDbiOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_OFSCAL_D1
union McIoDebugDbiOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_RXPHASE_D0
union McIoDebugDbiRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_RXPHASE_D1
union McIoDebugDbiRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_RX_EQ_D0
union McIoDebugDbiRxEqD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_RX_EQ_D1
union McIoDebugDbiRxEqD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_RX_VREF_CAL_D0
union McIoDebugDbiRxVrefCalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_RX_VREF_CAL_D1
union McIoDebugDbiRxVrefCalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_TXBST_PD_D0
union McIoDebugDbiTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_TXBST_PD_D1
union McIoDebugDbiTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_TXBST_PU_D0
union McIoDebugDbiTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_TXBST_PU_D1
union McIoDebugDbiTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_TXPHASE_D0
union McIoDebugDbiTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_TXPHASE_D1
union McIoDebugDbiTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_TXSLF_D0
union McIoDebugDbiTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DBI_TXSLF_D1
union McIoDebugDbiTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQ0_RX_DYN_PM_D0
union McIoDebugDq0RxDynPmD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQ0_RX_DYN_PM_D1
union McIoDebugDq0RxDynPmD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQ0_RX_EQ_PM_D0
union McIoDebugDq0RxEqPmD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQ0_RX_EQ_PM_D1
union McIoDebugDq0RxEqPmD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQ1_RX_DYN_PM_D0
union McIoDebugDq1RxDynPmD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQ1_RX_DYN_PM_D1
union McIoDebugDq1RxDynPmD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQ1_RX_EQ_PM_D0
union McIoDebugDq1RxEqPmD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQ1_RX_EQ_PM_D1
union McIoDebugDq1RxEqPmD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_CLKSEL_D0
union McIoDebugDqb0hClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_CLKSEL_D1
union McIoDebugDqb0hClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_MISC_D0
union McIoDebugDqb0hMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_MISC_D1
union McIoDebugDqb0hMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_OFSCAL_D0
union McIoDebugDqb0hOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_OFSCAL_D1
union McIoDebugDqb0hOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_RXPHASE_D0
union McIoDebugDqb0hRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_RXPHASE_D1
union McIoDebugDqb0hRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_RX_EQ_D0
union McIoDebugDqb0hRxEqD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_RX_EQ_D1
union McIoDebugDqb0hRxEqD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_RX_VREF_CAL_D0
union McIoDebugDqb0hRxVrefCalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_RX_VREF_CAL_D1
union McIoDebugDqb0hRxVrefCalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_TXBST_PD_D0
union McIoDebugDqb0hTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_TXBST_PD_D1
union McIoDebugDqb0hTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_TXBST_PU_D0
union McIoDebugDqb0hTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_TXBST_PU_D1
union McIoDebugDqb0hTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_TXPHASE_D0
union McIoDebugDqb0hTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_TXPHASE_D1
union McIoDebugDqb0hTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_TXSLF_D0
union McIoDebugDqb0hTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0H_TXSLF_D1
union McIoDebugDqb0hTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_CLKSEL_D0
union McIoDebugDqb0lClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_CLKSEL_D1
union McIoDebugDqb0lClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_MISC_D0
union McIoDebugDqb0lMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_MISC_D1
union McIoDebugDqb0lMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_OFSCAL_D0
union McIoDebugDqb0lOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_OFSCAL_D1
union McIoDebugDqb0lOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_RXPHASE_D0
union McIoDebugDqb0lRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_RXPHASE_D1
union McIoDebugDqb0lRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_RX_EQ_D0
union McIoDebugDqb0lRxEqD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_RX_EQ_D1
union McIoDebugDqb0lRxEqD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_RX_VREF_CAL_D0
union McIoDebugDqb0lRxVrefCalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_RX_VREF_CAL_D1
union McIoDebugDqb0lRxVrefCalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_TXBST_PD_D0
union McIoDebugDqb0lTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_TXBST_PD_D1
union McIoDebugDqb0lTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_TXBST_PU_D0
union McIoDebugDqb0lTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_TXBST_PU_D1
union McIoDebugDqb0lTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_TXPHASE_D0
union McIoDebugDqb0lTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_TXPHASE_D1
union McIoDebugDqb0lTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_TXSLF_D0
union McIoDebugDqb0lTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0L_TXSLF_D1
union McIoDebugDqb0lTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0_CDR_PHSIZE_D0
union McIoDebugDqb0CdrPhsizeD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB0_CDR_PHSIZE_D1
union McIoDebugDqb0CdrPhsizeD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_CLKSEL_D0
union McIoDebugDqb1hClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_CLKSEL_D1
union McIoDebugDqb1hClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_MISC_D0
union McIoDebugDqb1hMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_MISC_D1
union McIoDebugDqb1hMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_OFSCAL_D0
union McIoDebugDqb1hOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_OFSCAL_D1
union McIoDebugDqb1hOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_RXPHASE_D0
union McIoDebugDqb1hRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_RXPHASE_D1
union McIoDebugDqb1hRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_RX_EQ_D0
union McIoDebugDqb1hRxEqD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_RX_EQ_D1
union McIoDebugDqb1hRxEqD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_RX_VREF_CAL_D0
union McIoDebugDqb1hRxVrefCalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_RX_VREF_CAL_D1
union McIoDebugDqb1hRxVrefCalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_TXBST_PD_D0
union McIoDebugDqb1hTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_TXBST_PD_D1
union McIoDebugDqb1hTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_TXBST_PU_D0
union McIoDebugDqb1hTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_TXBST_PU_D1
union McIoDebugDqb1hTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_TXPHASE_D0
union McIoDebugDqb1hTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_TXPHASE_D1
union McIoDebugDqb1hTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_TXSLF_D0
union McIoDebugDqb1hTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1H_TXSLF_D1
union McIoDebugDqb1hTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_CLKSEL_D0
union McIoDebugDqb1lClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_CLKSEL_D1
union McIoDebugDqb1lClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_MISC_D0
union McIoDebugDqb1lMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_MISC_D1
union McIoDebugDqb1lMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_OFSCAL_D0
union McIoDebugDqb1lOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_OFSCAL_D1
union McIoDebugDqb1lOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_RXPHASE_D0
union McIoDebugDqb1lRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_RXPHASE_D1
union McIoDebugDqb1lRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_RX_EQ_D0
union McIoDebugDqb1lRxEqD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_RX_EQ_D1
union McIoDebugDqb1lRxEqD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_RX_VREF_CAL_D0
union McIoDebugDqb1lRxVrefCalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_RX_VREF_CAL_D1
union McIoDebugDqb1lRxVrefCalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_TXBST_PD_D0
union McIoDebugDqb1lTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_TXBST_PD_D1
union McIoDebugDqb1lTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_TXBST_PU_D0
union McIoDebugDqb1lTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_TXBST_PU_D1
union McIoDebugDqb1lTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_TXPHASE_D0
union McIoDebugDqb1lTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_TXPHASE_D1
union McIoDebugDqb1lTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_TXSLF_D0
union McIoDebugDqb1lTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1L_TXSLF_D1
union McIoDebugDqb1lTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1_CDR_PHSIZE_D0
union McIoDebugDqb1CdrPhsizeD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB1_CDR_PHSIZE_D1
union McIoDebugDqb1CdrPhsizeD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_CLKSEL_D0
union McIoDebugDqb2hClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_CLKSEL_D1
union McIoDebugDqb2hClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_MISC_D0
union McIoDebugDqb2hMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_MISC_D1
union McIoDebugDqb2hMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_OFSCAL_D0
union McIoDebugDqb2hOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_OFSCAL_D1
union McIoDebugDqb2hOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_RXPHASE_D0
union McIoDebugDqb2hRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_RXPHASE_D1
union McIoDebugDqb2hRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_RX_EQ_D0
union McIoDebugDqb2hRxEqD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_RX_EQ_D1
union McIoDebugDqb2hRxEqD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_RX_VREF_CAL_D0
union McIoDebugDqb2hRxVrefCalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_RX_VREF_CAL_D1
union McIoDebugDqb2hRxVrefCalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_TXBST_PD_D0
union McIoDebugDqb2hTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_TXBST_PD_D1
union McIoDebugDqb2hTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_TXBST_PU_D0
union McIoDebugDqb2hTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_TXBST_PU_D1
union McIoDebugDqb2hTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_TXPHASE_D0
union McIoDebugDqb2hTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_TXPHASE_D1
union McIoDebugDqb2hTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_TXSLF_D0
union McIoDebugDqb2hTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2H_TXSLF_D1
union McIoDebugDqb2hTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_CLKSEL_D0
union McIoDebugDqb2lClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_CLKSEL_D1
union McIoDebugDqb2lClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_MISC_D0
union McIoDebugDqb2lMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_MISC_D1
union McIoDebugDqb2lMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_OFSCAL_D0
union McIoDebugDqb2lOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_OFSCAL_D1
union McIoDebugDqb2lOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_RXPHASE_D0
union McIoDebugDqb2lRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_RXPHASE_D1
union McIoDebugDqb2lRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_RX_EQ_D0
union McIoDebugDqb2lRxEqD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_RX_EQ_D1
union McIoDebugDqb2lRxEqD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_RX_VREF_CAL_D0
union McIoDebugDqb2lRxVrefCalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_RX_VREF_CAL_D1
union McIoDebugDqb2lRxVrefCalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_TXBST_PD_D0
union McIoDebugDqb2lTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_TXBST_PD_D1
union McIoDebugDqb2lTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_TXBST_PU_D0
union McIoDebugDqb2lTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_TXBST_PU_D1
union McIoDebugDqb2lTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_TXPHASE_D0
union McIoDebugDqb2lTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_TXPHASE_D1
union McIoDebugDqb2lTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_TXSLF_D0
union McIoDebugDqb2lTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2L_TXSLF_D1
union McIoDebugDqb2lTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2_CDR_PHSIZE_D0
union McIoDebugDqb2CdrPhsizeD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB2_CDR_PHSIZE_D1
union McIoDebugDqb2CdrPhsizeD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_CLKSEL_D0
union McIoDebugDqb3hClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_CLKSEL_D1
union McIoDebugDqb3hClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_MISC_D0
union McIoDebugDqb3hMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_MISC_D1
union McIoDebugDqb3hMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_OFSCAL_D0
union McIoDebugDqb3hOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_OFSCAL_D1
union McIoDebugDqb3hOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_RXPHASE_D0
union McIoDebugDqb3hRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_RXPHASE_D1
union McIoDebugDqb3hRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_RX_EQ_D0
union McIoDebugDqb3hRxEqD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_RX_EQ_D1
union McIoDebugDqb3hRxEqD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_RX_VREF_CAL_D0
union McIoDebugDqb3hRxVrefCalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_RX_VREF_CAL_D1
union McIoDebugDqb3hRxVrefCalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_TXBST_PD_D0
union McIoDebugDqb3hTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_TXBST_PD_D1
union McIoDebugDqb3hTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_TXBST_PU_D0
union McIoDebugDqb3hTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_TXBST_PU_D1
union McIoDebugDqb3hTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_TXPHASE_D0
union McIoDebugDqb3hTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_TXPHASE_D1
union McIoDebugDqb3hTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_TXSLF_D0
union McIoDebugDqb3hTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3H_TXSLF_D1
union McIoDebugDqb3hTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_CLKSEL_D0
union McIoDebugDqb3lClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_CLKSEL_D1
union McIoDebugDqb3lClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_MISC_D0
union McIoDebugDqb3lMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_MISC_D1
union McIoDebugDqb3lMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_OFSCAL_D0
union McIoDebugDqb3lOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_OFSCAL_D1
union McIoDebugDqb3lOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_RXPHASE_D0
union McIoDebugDqb3lRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_RXPHASE_D1
union McIoDebugDqb3lRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_RX_EQ_D0
union McIoDebugDqb3lRxEqD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_RX_EQ_D1
union McIoDebugDqb3lRxEqD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_RX_VREF_CAL_D0
union McIoDebugDqb3lRxVrefCalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_RX_VREF_CAL_D1
union McIoDebugDqb3lRxVrefCalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_TXBST_PD_D0
union McIoDebugDqb3lTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_TXBST_PD_D1
union McIoDebugDqb3lTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_TXBST_PU_D0
union McIoDebugDqb3lTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_TXBST_PU_D1
union McIoDebugDqb3lTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_TXPHASE_D0
union McIoDebugDqb3lTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_TXPHASE_D1
union McIoDebugDqb3lTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_TXSLF_D0
union McIoDebugDqb3lTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3L_TXSLF_D1
union McIoDebugDqb3lTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3_CDR_PHSIZE_D0
union McIoDebugDqb3CdrPhsizeD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_DQB3_CDR_PHSIZE_D1
union McIoDebugDqb3CdrPhsizeD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_CDR_PHSIZE_D0
union McIoDebugEdcCdrPhsizeD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_CDR_PHSIZE_D1
union McIoDebugEdcCdrPhsizeD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_CLKSEL_D0
union McIoDebugEdcClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_CLKSEL_D1
union McIoDebugEdcClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_MISC_D0
union McIoDebugEdcMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_MISC_D1
union McIoDebugEdcMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_OFSCAL_D0
union McIoDebugEdcOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_OFSCAL_D1
union McIoDebugEdcOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_RXPHASE_D0
union McIoDebugEdcRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_RXPHASE_D1
union McIoDebugEdcRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_RX_DYN_PM_D0
union McIoDebugEdcRxDynPmD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_RX_DYN_PM_D1
union McIoDebugEdcRxDynPmD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_RX_EQ_D0
union McIoDebugEdcRxEqD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_RX_EQ_D1
union McIoDebugEdcRxEqD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_RX_EQ_PM_D0
union McIoDebugEdcRxEqPmD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_RX_EQ_PM_D1
union McIoDebugEdcRxEqPmD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_RX_VREF_CAL_D0
union McIoDebugEdcRxVrefCalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_RX_VREF_CAL_D1
union McIoDebugEdcRxVrefCalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_TXBST_PD_D0
union McIoDebugEdcTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_TXBST_PD_D1
union McIoDebugEdcTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_TXBST_PU_D0
union McIoDebugEdcTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_TXBST_PU_D1
union McIoDebugEdcTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_TXPHASE_D0
union McIoDebugEdcTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_TXPHASE_D1
union McIoDebugEdcTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_TXSLF_D0
union McIoDebugEdcTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_EDC_TXSLF_D1
union McIoDebugEdcTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_0
union McIoDebugUp0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_1
union McIoDebugUp1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_10
union McIoDebugUp10 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_100
union McIoDebugUp100 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_101
union McIoDebugUp101 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_102
union McIoDebugUp102 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_103
union McIoDebugUp103 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_104
union McIoDebugUp104 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_105
union McIoDebugUp105 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_106
union McIoDebugUp106 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_107
union McIoDebugUp107 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_108
union McIoDebugUp108 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_109
union McIoDebugUp109 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_11
union McIoDebugUp11 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_110
union McIoDebugUp110 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_111
union McIoDebugUp111 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_112
union McIoDebugUp112 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_113
union McIoDebugUp113 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_114
union McIoDebugUp114 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_115
union McIoDebugUp115 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_116
union McIoDebugUp116 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_117
union McIoDebugUp117 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_118
union McIoDebugUp118 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_119
union McIoDebugUp119 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_12
union McIoDebugUp12 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_120
union McIoDebugUp120 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_121
union McIoDebugUp121 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_122
union McIoDebugUp122 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_123
union McIoDebugUp123 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_124
union McIoDebugUp124 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_125
union McIoDebugUp125 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_126
union McIoDebugUp126 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_127
union McIoDebugUp127 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_128
union McIoDebugUp128 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_129
union McIoDebugUp129 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_13
union McIoDebugUp13 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_130
union McIoDebugUp130 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_131
union McIoDebugUp131 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_132
union McIoDebugUp132 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_133
union McIoDebugUp133 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_134
union McIoDebugUp134 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_135
union McIoDebugUp135 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_136
union McIoDebugUp136 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_137
union McIoDebugUp137 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_138
union McIoDebugUp138 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_139
union McIoDebugUp139 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_14
union McIoDebugUp14 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_140
union McIoDebugUp140 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_141
union McIoDebugUp141 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_142
union McIoDebugUp142 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_143
union McIoDebugUp143 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_144
union McIoDebugUp144 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_145
union McIoDebugUp145 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_146
union McIoDebugUp146 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_147
union McIoDebugUp147 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_148
union McIoDebugUp148 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_149
union McIoDebugUp149 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_15
union McIoDebugUp15 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_150
union McIoDebugUp150 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_151
union McIoDebugUp151 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_152
union McIoDebugUp152 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_153
union McIoDebugUp153 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_154
union McIoDebugUp154 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_155
union McIoDebugUp155 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_156
union McIoDebugUp156 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_157
union McIoDebugUp157 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_158
union McIoDebugUp158 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_159
union McIoDebugUp159 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_16
union McIoDebugUp16 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_17
union McIoDebugUp17 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_18
union McIoDebugUp18 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_19
union McIoDebugUp19 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_2
union McIoDebugUp2 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_20
union McIoDebugUp20 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_21
union McIoDebugUp21 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_22
union McIoDebugUp22 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_23
union McIoDebugUp23 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_24
union McIoDebugUp24 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_25
union McIoDebugUp25 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_26
union McIoDebugUp26 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_27
union McIoDebugUp27 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_28
union McIoDebugUp28 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_29
union McIoDebugUp29 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_3
union McIoDebugUp3 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_30
union McIoDebugUp30 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_31
union McIoDebugUp31 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_32
union McIoDebugUp32 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_33
union McIoDebugUp33 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_34
union McIoDebugUp34 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_35
union McIoDebugUp35 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_36
union McIoDebugUp36 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_37
union McIoDebugUp37 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_38
union McIoDebugUp38 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_39
union McIoDebugUp39 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_4
union McIoDebugUp4 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_40
union McIoDebugUp40 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_41
union McIoDebugUp41 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_42
union McIoDebugUp42 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_43
union McIoDebugUp43 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_44
union McIoDebugUp44 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_45
union McIoDebugUp45 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_46
union McIoDebugUp46 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_47
union McIoDebugUp47 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_48
union McIoDebugUp48 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_49
union McIoDebugUp49 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_5
union McIoDebugUp5 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_50
union McIoDebugUp50 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_51
union McIoDebugUp51 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_52
union McIoDebugUp52 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_53
union McIoDebugUp53 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_54
union McIoDebugUp54 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_55
union McIoDebugUp55 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_56
union McIoDebugUp56 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_57
union McIoDebugUp57 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_58
union McIoDebugUp58 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_59
union McIoDebugUp59 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_6
union McIoDebugUp6 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_60
union McIoDebugUp60 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_61
union McIoDebugUp61 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_62
union McIoDebugUp62 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_63
union McIoDebugUp63 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_64
union McIoDebugUp64 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_65
union McIoDebugUp65 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_66
union McIoDebugUp66 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_67
union McIoDebugUp67 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_68
union McIoDebugUp68 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_69
union McIoDebugUp69 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_7
union McIoDebugUp7 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_70
union McIoDebugUp70 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_71
union McIoDebugUp71 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_72
union McIoDebugUp72 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_73
union McIoDebugUp73 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_74
union McIoDebugUp74 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_75
union McIoDebugUp75 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_76
union McIoDebugUp76 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_77
union McIoDebugUp77 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_78
union McIoDebugUp78 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_79
union McIoDebugUp79 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_8
union McIoDebugUp8 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_80
union McIoDebugUp80 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_81
union McIoDebugUp81 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_82
union McIoDebugUp82 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_83
union McIoDebugUp83 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_84
union McIoDebugUp84 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_85
union McIoDebugUp85 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_86
union McIoDebugUp86 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_87
union McIoDebugUp87 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_88
union McIoDebugUp88 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_89
union McIoDebugUp89 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_9
union McIoDebugUp9 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_90
union McIoDebugUp90 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_91
union McIoDebugUp91 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_92
union McIoDebugUp92 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_93
union McIoDebugUp93 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_94
union McIoDebugUp94 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_95
union McIoDebugUp95 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_96
union McIoDebugUp96 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_97
union McIoDebugUp97 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_98
union McIoDebugUp98 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_UP_99
union McIoDebugUp99 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_CDR_PHSIZE_D0
union McIoDebugWcdrCdrPhsizeD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_CDR_PHSIZE_D1
union McIoDebugWcdrCdrPhsizeD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_CLKSEL_D0
union McIoDebugWcdrClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_CLKSEL_D1
union McIoDebugWcdrClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_MISC_D0
union McIoDebugWcdrMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_MISC_D1
union McIoDebugWcdrMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_OFSCAL_D0
union McIoDebugWcdrOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_OFSCAL_D1
union McIoDebugWcdrOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_RXPHASE_D0
union McIoDebugWcdrRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_RXPHASE_D1
union McIoDebugWcdrRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_RX_DYN_PM_D0
union McIoDebugWcdrRxDynPmD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_RX_DYN_PM_D1
union McIoDebugWcdrRxDynPmD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_RX_EQ_D0
union McIoDebugWcdrRxEqD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_RX_EQ_D1
union McIoDebugWcdrRxEqD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_RX_EQ_PM_D0
union McIoDebugWcdrRxEqPmD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_RX_EQ_PM_D1
union McIoDebugWcdrRxEqPmD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_RX_VREF_CAL_D0
union McIoDebugWcdrRxVrefCalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_RX_VREF_CAL_D1
union McIoDebugWcdrRxVrefCalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_TXBST_PD_D0
union McIoDebugWcdrTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_TXBST_PD_D1
union McIoDebugWcdrTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_TXBST_PU_D0
union McIoDebugWcdrTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_TXBST_PU_D1
union McIoDebugWcdrTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_TXPHASE_D0
union McIoDebugWcdrTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_TXPHASE_D1
union McIoDebugWcdrTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_TXSLF_D0
union McIoDebugWcdrTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCDR_TXSLF_D1
union McIoDebugWcdrTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_CLKSEL_D0
union McIoDebugWckClkselD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_CLKSEL_D1
union McIoDebugWckClkselD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_MISC_D0
union McIoDebugWckMiscD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_MISC_D1
union McIoDebugWckMiscD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_OFSCAL_D0
union McIoDebugWckOfscalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_OFSCAL_D1
union McIoDebugWckOfscalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_RXPHASE_D0
union McIoDebugWckRxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_RXPHASE_D1
union McIoDebugWckRxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_RX_EQ_D0
union McIoDebugWckRxEqD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_RX_EQ_D1
union McIoDebugWckRxEqD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_RX_VREF_CAL_D0
union McIoDebugWckRxVrefCalD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_RX_VREF_CAL_D1
union McIoDebugWckRxVrefCalD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_TXBST_PD_D0
union McIoDebugWckTxbstPdD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_TXBST_PD_D1
union McIoDebugWckTxbstPdD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_TXBST_PU_D0
union McIoDebugWckTxbstPuD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_TXBST_PU_D1
union McIoDebugWckTxbstPuD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_TXPHASE_D0
union McIoDebugWckTxphaseD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_TXPHASE_D1
union McIoDebugWckTxphaseD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_TXSLF_D0
union McIoDebugWckTxslfD0 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DEBUG_WCK_TXSLF_D1
union McIoDebugWckTxslfD1 {
	struct {
		uint32 value0: 8; // 0
		uint32 value1: 8; // 8
		uint32 value2: 8; // 16
		uint32 value3: 8; // 24
	};
	uint32 val;
};

// MC_IO_DPHY_STR_CNTL_D0
union McIoDphyStrCntlD0 {
	struct {
		uint32 pstrOffD: 6; // 0
		uint32 nstrOffD: 6; // 6
		uint32 pstrOffS: 6; // 12
		uint32 nstrOffS: 6; // 18
		uint32 useDCal: 1; // 24
		uint32 useSCal: 1; // 25
		uint32 calSel: 2; // 26
		uint32 loadDStr: 1; // 28
		uint32 loadSStr: 1; // 29
		uint32 unknown1: 2;
	};
	uint32 val;
};

// MC_IO_DPHY_STR_CNTL_D1
union McIoDphyStrCntlD1 {
	struct {
		uint32 pstrOffD: 6; // 0
		uint32 nstrOffD: 6; // 6
		uint32 pstrOffS: 6; // 12
		uint32 nstrOffS: 6; // 18
		uint32 useDCal: 1; // 24
		uint32 useSCal: 1; // 25
		uint32 calSel: 2; // 26
		uint32 loadDStr: 1; // 28
		uint32 loadSStr: 1; // 29
		uint32 unknown1: 2;
	};
	uint32 val;
};

// MC_IO_PAD_CNTL
union McIoPadCntl {
	struct {
		uint32 memIoImpMin: 8; // 0
		uint32 memIoImpMax: 8; // 8
		uint32 txphaseGray: 1; // 16
		uint32 rxphaseGray: 1; // 17
		uint32 ovlYclkonD0: 1; // 18
		uint32 ovlYclkonD1: 1; // 19
		uint32 atbsel: 4; // 20
		uint32 atben: 6; // 24
		uint32 atbselD1: 1; // 30
		uint32 atbselD0: 1; // 31
	};
	uint32 val;
};

// MC_IO_PAD_CNTL_D0
union McIoPadCntlD0 {
	struct {
		uint32 unknown1: 2;
		uint32 delayClkSync: 1; // 2
		uint32 delayCmdSync: 1; // 3
		uint32 delayAdrSync: 1; // 4
		uint32 unknown2: 2;
		uint32 memFallOutClk: 1; // 7
		uint32 memFallOutCmd: 1; // 8
		uint32 memFallOutAdr: 1; // 9
		uint32 forceEnRdStr: 1; // 10
		uint32 enRdStrDly: 1; // 11
		uint32 disableCmd: 1; // 12
		uint32 disableAdr: 1; // 13
		uint32 vrefiEn: 1; // 14
		uint32 vrefiSel: 5; // 15
		uint32 ckAutoEn: 1; // 20
		uint32 ckDelaySel: 1; // 21
		uint32 ckDelayN: 2; // 22
		uint32 ckDelayP: 2; // 24
		uint32 unknown3: 1;
		uint32 txpwroffCke: 1; // 27
		uint32 uniStr: 1; // 28
		uint32 diffStr: 1; // 29
		uint32 gddrPwron: 1; // 30
		uint32 txpwroffClk: 1; // 31
	};
	uint32 val;
};

// MC_IO_PAD_CNTL_D1
union McIoPadCntlD1 {
	struct {
		uint32 delayDataSync: 1; // 0
		uint32 delayStrSync: 1; // 1
		uint32 delayClkSync: 1; // 2
		uint32 delayCmdSync: 1; // 3
		uint32 delayAdrSync: 1; // 4
		uint32 memFallOutData: 1; // 5
		uint32 memFallOutStr: 1; // 6
		uint32 memFallOutClk: 1; // 7
		uint32 memFallOutCmd: 1; // 8
		uint32 memFallOutAdr: 1; // 9
		uint32 forceEnRdStr: 1; // 10
		uint32 enRdStrDly: 1; // 11
		uint32 disableCmd: 1; // 12
		uint32 disableAdr: 1; // 13
		uint32 vrefiEn: 1; // 14
		uint32 vrefiSel: 5; // 15
		uint32 ckAutoEn: 1; // 20
		uint32 ckDelaySel: 1; // 21
		uint32 ckDelayN: 2; // 22
		uint32 ckDelayP: 2; // 24
		uint32 unknown1: 1;
		uint32 txpwroffCke: 1; // 27
		uint32 uniStr: 1; // 28
		uint32 diffStr: 1; // 29
		uint32 gddrPwron: 1; // 30
		uint32 txpwroffClk: 1; // 31
	};
	uint32 val;
};

// MC_IO_RXCNTL1_DPHY0_D0
union McIoRxcntl1Dphy0D0 {
	struct {
		uint32 vrefcal1Msb: 4; // 0
		uint32 vrefcal2Msb: 4; // 4
		uint32 vrefcal3: 8; // 8
		uint32 vrefsel2: 1; // 16
		uint32 vrefsel3: 1; // 17
		uint32 vrefpdnb1: 1; // 18
		uint32 unknown1: 6;
		uint32 pmdLoopback: 3; // 25
		uint32 dllRsv: 4; // 28
	};
	uint32 val;
};

// MC_IO_RXCNTL1_DPHY0_D1
union McIoRxcntl1Dphy0D1 {
	struct {
		uint32 vrefcal1Msb: 4; // 0
		uint32 vrefcal2Msb: 4; // 4
		uint32 vrefcal3: 8; // 8
		uint32 vrefsel2: 1; // 16
		uint32 vrefsel3: 1; // 17
		uint32 vrefpdnb1: 1; // 18
		uint32 unknown1: 6;
		uint32 pmdLoopback: 3; // 25
		uint32 dllRsv: 4; // 28
	};
	uint32 val;
};

// MC_IO_RXCNTL1_DPHY1_D0
union McIoRxcntl1Dphy1D0 {
	struct {
		uint32 vrefcal1Msb: 4; // 0
		uint32 vrefcal2Msb: 4; // 4
		uint32 vrefcal3: 8; // 8
		uint32 vrefsel2: 1; // 16
		uint32 vrefsel3: 1; // 17
		uint32 vrefpdnb1: 1; // 18
		uint32 unknown1: 6;
		uint32 pmdLoopback: 3; // 25
		uint32 dllRsv: 4; // 28
	};
	uint32 val;
};

// MC_IO_RXCNTL1_DPHY1_D1
union McIoRxcntl1Dphy1D1 {
	struct {
		uint32 vrefcal1Msb: 4; // 0
		uint32 vrefcal2Msb: 4; // 4
		uint32 vrefcal3: 8; // 8
		uint32 vrefsel2: 1; // 16
		uint32 vrefsel3: 1; // 17
		uint32 vrefpdnb1: 1; // 18
		uint32 unknown1: 6;
		uint32 pmdLoopback: 3; // 25
		uint32 dllRsv: 4; // 28
	};
	uint32 val;
};

// MC_IO_RXCNTL_DPHY0_D0
union McIoRxcntlDphy0D0 {
	struct {
		uint32 rxbiassel: 2; // 0
		uint32 rcvsel: 1; // 2
		uint32 vrefpdnb: 1; // 3
		uint32 rxdpwronDly: 2; // 4
		uint32 rxpdnb: 1; // 6
		uint32 rxlp: 1; // 7
		uint32 vrefcal: 4; // 8
		uint32 vrefcalStr: 4; // 12
		uint32 vrefsel: 1; // 16
		uint32 unknown1: 1;
		uint32 rxPeaksel: 2; // 18
		uint32 dllAdjB0: 3; // 20
		uint32 unknown2: 1;
		uint32 dllAdjB1: 3; // 24
		uint32 unknown3: 1;
		uint32 dllAdjM: 1; // 28
		uint32 refclkPwron: 1; // 29
		uint32 dllBwCtrl: 2; // 30
	};
	uint32 val;
};

// MC_IO_RXCNTL_DPHY0_D1
union McIoRxcntlDphy0D1 {
	struct {
		uint32 rxbiassel: 2; // 0
		uint32 rcvsel: 1; // 2
		uint32 vrefpdnb: 1; // 3
		uint32 rxdpwronDly: 2; // 4
		uint32 rxpdnb: 1; // 6
		uint32 rxlp: 1; // 7
		uint32 vrefcal: 4; // 8
		uint32 vrefcalStr: 4; // 12
		uint32 vrefsel: 1; // 16
		uint32 unknown1: 1;
		uint32 rxPeaksel: 2; // 18
		uint32 dllAdjB0: 3; // 20
		uint32 unknown2: 1;
		uint32 dllAdjB1: 3; // 24
		uint32 unknown3: 1;
		uint32 dllAdjM: 1; // 28
		uint32 refclkPwron: 1; // 29
		uint32 dllBwCtrl: 2; // 30
	};
	uint32 val;
};

// MC_IO_RXCNTL_DPHY1_D0
union McIoRxcntlDphy1D0 {
	struct {
		uint32 rxbiassel: 2; // 0
		uint32 rcvsel: 1; // 2
		uint32 vrefpdnb: 1; // 3
		uint32 rxdpwronDly: 2; // 4
		uint32 rxpdnb: 1; // 6
		uint32 rxlp: 1; // 7
		uint32 vrefcal: 4; // 8
		uint32 vrefcalStr: 4; // 12
		uint32 vrefsel: 1; // 16
		uint32 unknown1: 1;
		uint32 rxPeaksel: 2; // 18
		uint32 dllAdjB0: 3; // 20
		uint32 unknown2: 1;
		uint32 dllAdjB1: 3; // 24
		uint32 unknown3: 1;
		uint32 dllAdjM: 1; // 28
		uint32 refclkPwron: 1; // 29
		uint32 dllBwCtrl: 2; // 30
	};
	uint32 val;
};

// MC_IO_RXCNTL_DPHY1_D1
union McIoRxcntlDphy1D1 {
	struct {
		uint32 rxbiassel: 2; // 0
		uint32 rcvsel: 1; // 2
		uint32 vrefpdnb: 1; // 3
		uint32 rxdpwronDly: 2; // 4
		uint32 rxpdnb: 1; // 6
		uint32 rxlp: 1; // 7
		uint32 vrefcal: 4; // 8
		uint32 vrefcalStr: 4; // 12
		uint32 vrefsel: 1; // 16
		uint32 unknown1: 1;
		uint32 rxPeaksel: 2; // 18
		uint32 dllAdjB0: 3; // 20
		uint32 unknown2: 1;
		uint32 dllAdjB1: 3; // 24
		uint32 unknown3: 1;
		uint32 dllAdjM: 1; // 28
		uint32 refclkPwron: 1; // 29
		uint32 dllBwCtrl: 2; // 30
	};
	uint32 val;
};

// MC_IO_TXCNTL_APHY_D0
union McIoTxcntlAphyD0 {
	struct {
		uint32 biassel: 2; // 0
		uint32 drvduty: 2; // 2
		uint32 lowcmen: 1; // 4
		uint32 qdr: 1; // 5
		uint32 emph: 1; // 6
		uint32 txpd: 1; // 7
		uint32 pterm: 4; // 8
		uint32 txbpassSel: 1; // 12
		uint32 pmaLoopback: 3; // 13
		uint32 pdrv: 4; // 16
		uint32 ndrv: 3; // 20
		uint32 yclkon: 1; // 23
		uint32 tsten: 1; // 24
		uint32 txreset: 1; // 25
		uint32 txbypass: 1; // 26
		uint32 txbypassData: 3; // 27
		uint32 ckeBit: 1; // 30
		uint32 ckeSel: 1; // 31
	};
	uint32 val;
};

// MC_IO_TXCNTL_APHY_D1
union McIoTxcntlAphyD1 {
	struct {
		uint32 biassel: 2; // 0
		uint32 drvduty: 2; // 2
		uint32 lowcmen: 1; // 4
		uint32 qdr: 1; // 5
		uint32 emph: 1; // 6
		uint32 txpd: 1; // 7
		uint32 pterm: 4; // 8
		uint32 txbpassSel: 1; // 12
		uint32 pmaLoopback: 3; // 13
		uint32 pdrv: 4; // 16
		uint32 ndrv: 3; // 20
		uint32 yclkon: 1; // 23
		uint32 tsten: 1; // 24
		uint32 txreset: 1; // 25
		uint32 txbypass: 1; // 26
		uint32 txbypassData: 3; // 27
		uint32 ckeBit: 1; // 30
		uint32 ckeSel: 1; // 31
	};
	uint32 val;
};

// MC_IO_TXCNTL_DPHY0_D0
union McIoTxcntlDphy0D0 {
	struct {
		uint32 biassel: 2; // 0
		uint32 drvduty: 2; // 2
		uint32 lowcmen: 1; // 4
		uint32 qdr: 1; // 5
		uint32 emph: 1; // 6
		uint32 txpd: 1; // 7
		uint32 pterm: 4; // 8
		uint32 nterm: 4; // 12
		uint32 pdrv: 4; // 16
		uint32 ndrv: 4; // 20
		uint32 tsten: 1; // 24
		uint32 edctxClkgateEn: 1; // 25
		uint32 txbypass: 1; // 26
		uint32 pllLoopbck: 1; // 27
		uint32 txbypassData: 4; // 28
	};
	uint32 val;
};

// MC_IO_TXCNTL_DPHY0_D1
union McIoTxcntlDphy0D1 {
	struct {
		uint32 biassel: 2; // 0
		uint32 drvduty: 2; // 2
		uint32 lowcmen: 1; // 4
		uint32 qdr: 1; // 5
		uint32 emph: 1; // 6
		uint32 txpd: 1; // 7
		uint32 pterm: 4; // 8
		uint32 nterm: 4; // 12
		uint32 pdrv: 4; // 16
		uint32 ndrv: 4; // 20
		uint32 tsten: 1; // 24
		uint32 edctxClkgateEn: 1; // 25
		uint32 txbypass: 1; // 26
		uint32 pllLoopbck: 1; // 27
		uint32 txbypassData: 4; // 28
	};
	uint32 val;
};

// MC_IO_TXCNTL_DPHY1_D0
union McIoTxcntlDphy1D0 {
	struct {
		uint32 biassel: 2; // 0
		uint32 drvduty: 2; // 2
		uint32 lowcmen: 1; // 4
		uint32 qdr: 1; // 5
		uint32 emph: 1; // 6
		uint32 txpd: 1; // 7
		uint32 pterm: 4; // 8
		uint32 nterm: 4; // 12
		uint32 pdrv: 4; // 16
		uint32 ndrv: 4; // 20
		uint32 tsten: 1; // 24
		uint32 edctxClkgateEn: 1; // 25
		uint32 txbypass: 1; // 26
		uint32 pllLoopbck: 1; // 27
		uint32 txbypassData: 4; // 28
	};
	uint32 val;
};

// MC_IO_TXCNTL_DPHY1_D1
union McIoTxcntlDphy1D1 {
	struct {
		uint32 biassel: 2; // 0
		uint32 drvduty: 2; // 2
		uint32 lowcmen: 1; // 4
		uint32 qdr: 1; // 5
		uint32 emph: 1; // 6
		uint32 txpd: 1; // 7
		uint32 pterm: 4; // 8
		uint32 nterm: 4; // 12
		uint32 pdrv: 4; // 16
		uint32 ndrv: 4; // 20
		uint32 tsten: 1; // 24
		uint32 edctxClkgateEn: 1; // 25
		uint32 txbypass: 1; // 26
		uint32 pllLoopbck: 1; // 27
		uint32 txbypassData: 4; // 28
	};
	uint32 val;
};

// MC_MEM_POWER_LS
union McMemPowerLs {
	struct {
		uint32 lsSetup: 6; // 0
		uint32 lsHold: 6; // 6
		uint32 unknown1: 20;
	};
	uint32 val;
};

// MC_NPL_STATUS
union McNplStatus {
	struct {
		uint32 d0Pdelay: 2; // 0
		uint32 d0Ndelay: 2; // 2
		uint32 d0Pearly: 1; // 4
		uint32 d0Nearly: 1; // 5
		uint32 d1Pdelay: 2; // 6
		uint32 d1Ndelay: 2; // 8
		uint32 d1Pearly: 1; // 10
		uint32 d1Nearly: 1; // 11
		uint32 unknown1: 20;
	};
	uint32 val;
};

// MC_PHY_TIMING_2
union McPhyTiming2 {
	struct {
		uint32 indLdCnt: 7; // 0
		uint32 unknown1: 1;
		uint32 rxc0Inv: 1; // 8
		uint32 rxc1Inv: 1; // 9
		uint32 txc0Inv: 1; // 10
		uint32 txc1Inv: 1; // 11
		uint32 rxc0Frc: 1; // 12
		uint32 rxc1Frc: 1; // 13
		uint32 txc0Frc: 1; // 14
		uint32 txc1Frc: 1; // 15
		uint32 txCdrenD0: 1; // 16
		uint32 txCdrenD1: 1; // 17
		uint32 adrClkenD0: 1; // 18
		uint32 adrClkenD1: 1; // 19
		uint32 wrDly: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// MC_PHY_TIMING_D0
union McPhyTimingD0 {
	struct {
		uint32 rxc0Dly: 4; // 0
		uint32 rxc0Ext: 4; // 4
		uint32 rxc1Dly: 4; // 8
		uint32 rxc1Ext: 4; // 12
		uint32 txc0Dly: 3; // 16
		uint32 unknown1: 1;
		uint32 txc0Ext: 4; // 20
		uint32 txc1Dly: 3; // 24
		uint32 unknown2: 1;
		uint32 txc1Ext: 4; // 28
	};
	uint32 val;
};

// MC_PHY_TIMING_D1
union McPhyTimingD1 {
	struct {
		uint32 rxc0Dly: 4; // 0
		uint32 rxc0Ext: 4; // 4
		uint32 rxc1Dly: 4; // 8
		uint32 rxc1Ext: 4; // 12
		uint32 txc0Dly: 3; // 16
		uint32 unknown1: 1;
		uint32 txc0Ext: 4; // 20
		uint32 txc1Dly: 3; // 24
		uint32 unknown2: 1;
		uint32 txc1Ext: 4; // 28
	};
	uint32 val;
};

// MC_PMG_AUTO_CFG
union McPmgAutoCfg {
	struct {
		uint32 sycClk: 1; // 0
		uint32 rstMrs: 1; // 1
		uint32 triMio: 1; // 2
		uint32 unknown1: 1;
		uint32 xsrTmr: 4; // 4
		uint32 ssAlwaysSlf: 1; // 8
		uint32 ssSSlf: 1; // 9
		uint32 scdsMode: 1; // 10
		uint32 exitAllowStop: 1; // 11
		uint32 rfsSrx: 1; // 12
		uint32 preaSrx: 1; // 13
		uint32 stutterEn: 1; // 14
		uint32 selfrefrCommit0: 1; // 15
		uint32 mrsWaitCnt: 4; // 16
		uint32 writeDuringDlock: 1; // 20
		uint32 yclkOn: 1; // 21
		uint32 rxpdnb: 1; // 22
		uint32 selfrefrCommit1: 1; // 23
		uint32 dllCnt: 8; // 24
	};
	uint32 val;
};

// MC_PMG_AUTO_CMD
union McPmgAutoCmd {
	struct {
		uint32 adr: 17; // 0
		uint32 unknown1: 11;
		uint32 adrMsb1: 1; // 28
		uint32 adrMsb0: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_PMG_CFG
union McPmgCfg {
	struct {
		uint32 sycClk: 1; // 0
		uint32 rstMrs: 1; // 1
		uint32 rstEmrs: 1; // 2
		uint32 triMio: 1; // 3
		uint32 xsrTmr: 4; // 4
		uint32 rstMrs1: 1; // 8
		uint32 rstMrs2: 1; // 9
		uint32 dpmWake: 1; // 10
		uint32 unknown1: 1;
		uint32 rfsSrx: 1; // 12
		uint32 preaSrx: 1; // 13
		uint32 unknown2: 2;
		uint32 mrsWaitCnt: 4; // 16
		uint32 writeDuringDlock: 1; // 20
		uint32 yclkOn: 1; // 21
		uint32 earlyAckAcpi: 1; // 22
		uint32 unknown3: 2;
		uint32 rxpdnb: 1; // 25
		uint32 zqclSend: 2; // 26
		uint32 unknown4: 4;
	};
	uint32 val;
};

// MC_PMG_CMD_EMRS
union McPmgCmdEmrs {
	struct {
		uint32 adr: 16; // 0
		uint32 mop: 3; // 16
		uint32 bnkMsb: 1; // 19
		uint32 end: 1; // 20
		uint32 csb: 2; // 21
		uint32 unknown1: 5;
		uint32 adrMsb1: 1; // 28
		uint32 adrMsb0: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_PMG_CMD_MRS
union McPmgCmdMrs {
	struct {
		uint32 adr: 16; // 0
		uint32 mop: 3; // 16
		uint32 bnkMsb: 1; // 19
		uint32 end: 1; // 20
		uint32 csb: 2; // 21
		uint32 unknown1: 5;
		uint32 adrMsb1: 1; // 28
		uint32 adrMsb0: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_PMG_CMD_MRS1
union McPmgCmdMrs1 {
	struct {
		uint32 adr: 16; // 0
		uint32 mop: 3; // 16
		uint32 bnkMsb: 1; // 19
		uint32 end: 1; // 20
		uint32 csb: 2; // 21
		uint32 unknown1: 5;
		uint32 adrMsb1: 1; // 28
		uint32 adrMsb0: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_PMG_CMD_MRS2
union McPmgCmdMrs2 {
	struct {
		uint32 adr: 16; // 0
		uint32 mop: 3; // 16
		uint32 bnkMsb: 1; // 19
		uint32 end: 1; // 20
		uint32 csb: 2; // 21
		uint32 unknown1: 5;
		uint32 adrMsb1: 1; // 28
		uint32 adrMsb0: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_RD_CB
union McRdCb {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxBurst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_RD_DB
union McRdDb {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxBurst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_RD_GRP_EXT
union McRdGrpExt {
	struct {
		uint32 dbsten0: 4; // 0
		uint32 tc0: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_RD_GRP_GFX
union McRdGrpGfx {
	struct {
		uint32 cp: 4; // 0
		uint32 unknown1: 12;
		uint32 xdmam: 4; // 16
		uint32 unknown2: 12;
	};
	uint32 val;
};

// MC_RD_GRP_LCL
union McRdGrpLcl {
	struct {
		uint32 unknown1: 12;
		uint32 cb0: 4; // 12
		uint32 cbcmask0: 4; // 16
		uint32 cbfmask0: 4; // 20
		uint32 db0: 4; // 24
		uint32 dbhtile0: 4; // 28
	};
	uint32 val;
};

// MC_RD_GRP_OTH
union McRdGrpOth {
	struct {
		uint32 uvdExt0: 4; // 0
		uint32 unknown1: 4;
		uint32 hdp: 4; // 8
		uint32 sem: 4; // 12
		uint32 umc: 4; // 16
		uint32 uvd: 4; // 20
		uint32 uvdExt1: 4; // 24
		uint32 unknown2: 4;
	};
	uint32 val;
};

// MC_RD_GRP_SYS
union McRdGrpSys {
	struct {
		uint32 rlc: 4; // 0
		uint32 vmc: 4; // 4
		uint32 unknown1: 4;
		uint32 dmif: 4; // 12
		uint32 mcif: 4; // 16
		uint32 smu: 4; // 20
		uint32 vce: 4; // 24
		uint32 vceu: 4; // 28
	};
	uint32 val;
};

// MC_RD_HUB
union McRdHub {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxBurst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_RD_TC0
union McRdTc0 {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxBurst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_RD_TC1
union McRdTc1 {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxBurst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_RPB_ARB_CNTL
union McRpbArbCntl {
	struct {
		uint32 wrSwitchNum: 8; // 0
		uint32 rdSwitchNum: 8; // 8
		uint32 atcSwitchNum: 8; // 16
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_RPB_BIF_CNTL
union McRpbBifCntl {
	struct {
		uint32 arbSwitchNum: 8; // 0
		uint32 xpbSwitchNum: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_RPB_CID_QUEUE_EX
union McRpbCidQueueEx {
	struct {
		uint32 start: 1; // 0
		uint32 offset: 5; // 1
		uint32 unknown1: 26;
	};
	uint32 val;
};

// MC_RPB_CID_QUEUE_EX_DATA
union McRpbCidQueueExData {
	struct {
		uint32 writeEntries: 16; // 0
		uint32 readEntries: 16; // 16
	};
	uint32 val;
};

// MC_RPB_CID_QUEUE_RD
union McRpbCidQueueRd {
	struct {
		uint32 clientId: 8; // 0
		uint32 writeQueue: 2; // 8
		uint32 readQueue: 2; // 10
		uint32 unknown1: 20;
	};
	uint32 val;
};

// MC_RPB_CID_QUEUE_WR
union McRpbCidQueueWr {
	struct {
		uint32 clientId: 8; // 0
		uint32 updateMode: 1; // 8
		uint32 writeQueue: 2; // 9
		uint32 readQueue: 2; // 11
		uint32 update: 1; // 13
		uint32 unknown1: 18;
	};
	uint32 val;
};

// MC_RPB_CONF
union McRpbConf {
	struct {
		uint32 unknown1: 15;
		uint32 xpbPcieOrder: 1; // 15
		uint32 rpbRdPcieOrder: 1; // 16
		uint32 rpbWrPcieOrder: 1; // 17
		uint32 unknown2: 14;
	};
	uint32 val;
};

// MC_RPB_DBG1
union McRpbDbg1 {
	struct {
		uint32 rpbBifOutstandingRd: 8; // 0
		uint32 rpbBifOutstandingRd32b: 12; // 8
		uint32 debugBits: 12; // 20
	};
	uint32 val;
};

// MC_RPB_EFF_CNTL
union McRpbEffCntl {
	struct {
		uint32 wrLazyTimer: 8; // 0
		uint32 rdLazyTimer: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_RPB_IF_CONF
union McRpbIfConf {
	struct {
		uint32 rpbBifCredits: 8; // 0
		uint32 outstandingWrretAsk: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_RPB_PERF_COUNTER_CNTL
union McRpbPerfCounterCntl {
	struct {
		uint32 perfCounterSelect: 2; // 0
		uint32 clearSelectedPerfCounter: 1; // 2
		uint32 clearAllPerfCounters: 1; // 3
		uint32 stopOnCounterSaturation: 1; // 4
		uint32 enablePerfCounters: 4; // 5
		uint32 perfCounterAssign0: 5; // 9
		uint32 perfCounterAssign1: 5; // 14
		uint32 perfCounterAssign2: 5; // 19
		uint32 perfCounterAssign3: 5; // 24
		uint32 unknown1: 3;
	};
	uint32 val;
};

// MC_RPB_PERF_COUNTER_STATUS
union McRpbPerfCounterStatus {
	struct {
		uint32 performanceCounterValue: 32; // 0
	};
	uint32 val;
};

// MC_RPB_RD_SWITCH_CNTL
union McRpbRdSwitchCntl {
	struct {
		uint32 queue0SwitchNum: 8; // 0
		uint32 queue1SwitchNum: 8; // 8
		uint32 queue2SwitchNum: 8; // 16
		uint32 queue3SwitchNum: 8; // 24
	};
	uint32 val;
};

// MC_RPB_WR_COMBINE_CNTL
union McRpbWrCombineCntl {
	struct {
		uint32 wcEnable: 1; // 0
		uint32 wcMaxPacketSize: 2; // 1
		uint32 wcFlushTimer: 4; // 3
		uint32 wcAlign: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_RPB_WR_SWITCH_CNTL
union McRpbWrSwitchCntl {
	struct {
		uint32 queue0SwitchNum: 8; // 0
		uint32 queue1SwitchNum: 8; // 8
		uint32 queue2SwitchNum: 8; // 16
		uint32 queue3SwitchNum: 8; // 24
	};
	uint32 val;
};

// MC_SEQ_BIT_REMAP_B0_D0
union McSeqBitRemapB0D0 {
	struct {
		uint32 bit0: 3; // 0
		uint32 bit1: 3; // 3
		uint32 bit2: 3; // 6
		uint32 bit3: 3; // 9
		uint32 bit4: 3; // 12
		uint32 bit5: 3; // 15
		uint32 bit6: 3; // 18
		uint32 bit7: 3; // 21
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_SEQ_BIT_REMAP_B0_D1
union McSeqBitRemapB0D1 {
	struct {
		uint32 bit0: 3; // 0
		uint32 bit1: 3; // 3
		uint32 bit2: 3; // 6
		uint32 bit3: 3; // 9
		uint32 bit4: 3; // 12
		uint32 bit5: 3; // 15
		uint32 bit6: 3; // 18
		uint32 bit7: 3; // 21
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_SEQ_BIT_REMAP_B1_D0
union McSeqBitRemapB1D0 {
	struct {
		uint32 bit0: 3; // 0
		uint32 bit1: 3; // 3
		uint32 bit2: 3; // 6
		uint32 bit3: 3; // 9
		uint32 bit4: 3; // 12
		uint32 bit5: 3; // 15
		uint32 bit6: 3; // 18
		uint32 bit7: 3; // 21
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_SEQ_BIT_REMAP_B1_D1
union McSeqBitRemapB1D1 {
	struct {
		uint32 bit0: 3; // 0
		uint32 bit1: 3; // 3
		uint32 bit2: 3; // 6
		uint32 bit3: 3; // 9
		uint32 bit4: 3; // 12
		uint32 bit5: 3; // 15
		uint32 bit6: 3; // 18
		uint32 bit7: 3; // 21
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_SEQ_BIT_REMAP_B2_D0
union McSeqBitRemapB2D0 {
	struct {
		uint32 bit0: 3; // 0
		uint32 bit1: 3; // 3
		uint32 bit2: 3; // 6
		uint32 bit3: 3; // 9
		uint32 bit4: 3; // 12
		uint32 bit5: 3; // 15
		uint32 bit6: 3; // 18
		uint32 bit7: 3; // 21
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_SEQ_BIT_REMAP_B2_D1
union McSeqBitRemapB2D1 {
	struct {
		uint32 bit0: 3; // 0
		uint32 bit1: 3; // 3
		uint32 bit2: 3; // 6
		uint32 bit3: 3; // 9
		uint32 bit4: 3; // 12
		uint32 bit5: 3; // 15
		uint32 bit6: 3; // 18
		uint32 bit7: 3; // 21
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_SEQ_BIT_REMAP_B3_D0
union McSeqBitRemapB3D0 {
	struct {
		uint32 bit0: 3; // 0
		uint32 bit1: 3; // 3
		uint32 bit2: 3; // 6
		uint32 bit3: 3; // 9
		uint32 bit4: 3; // 12
		uint32 bit5: 3; // 15
		uint32 bit6: 3; // 18
		uint32 bit7: 3; // 21
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_SEQ_BIT_REMAP_B3_D1
union McSeqBitRemapB3D1 {
	struct {
		uint32 bit0: 3; // 0
		uint32 bit1: 3; // 3
		uint32 bit2: 3; // 6
		uint32 bit3: 3; // 9
		uint32 bit4: 3; // 12
		uint32 bit5: 3; // 15
		uint32 bit6: 3; // 18
		uint32 bit7: 3; // 21
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_SEQ_BYTE_REMAP_D0
union McSeqByteRemapD0 {
	struct {
		uint32 byte0: 2; // 0
		uint32 byte1: 2; // 2
		uint32 byte2: 2; // 4
		uint32 byte3: 2; // 6
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_SEQ_BYTE_REMAP_D1
union McSeqByteRemapD1 {
	struct {
		uint32 byte0: 2; // 0
		uint32 byte1: 2; // 2
		uint32 byte2: 2; // 4
		uint32 byte3: 2; // 6
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_SEQ_CAS_TIMING
union McSeqCasTiming {
	struct {
		uint32 tnopw: 2; // 0
		uint32 tnopr: 2; // 2
		uint32 tr2w: 5; // 4
		uint32 tccdl: 3; // 9
		uint32 tr2r: 4; // 12
		uint32 tw2r: 5; // 16
		uint32 unknown1: 3;
		uint32 tcl: 5; // 24
		uint32 unknown2: 3;
	};
	uint32 val;
};

// MC_SEQ_CAS_TIMING_LP
union McSeqCasTimingLp {
	struct {
		uint32 tnopw: 2; // 0
		uint32 tnopr: 2; // 2
		uint32 tr2w: 5; // 4
		uint32 tccdl: 3; // 9
		uint32 tr2r: 4; // 12
		uint32 tw2r: 5; // 16
		uint32 unknown1: 3;
		uint32 tcl: 5; // 24
		uint32 unknown2: 3;
	};
	uint32 val;
};

// MC_SEQ_CG
union McSeqCg {
	struct {
		uint32 cgSeqReq: 8; // 0
		uint32 cgSeqResp: 8; // 8
		uint32 seqCgReq: 8; // 16
		uint32 seqCgResp: 8; // 24
	};
	uint32 val;
};

// MC_SEQ_CMD
union McSeqCmd {
	struct {
		uint32 adr: 16; // 0
		uint32 mop: 4; // 16
		uint32 end: 1; // 20
		uint32 csb: 2; // 21
		uint32 unknown1: 1;
		uint32 chan0: 1; // 24
		uint32 chan1: 1; // 25
		uint32 unknown2: 2;
		uint32 adrMsb1: 1; // 28
		uint32 adrMsb0: 1; // 29
		uint32 unknown3: 2;
	};
	uint32 val;
};

// MC_SEQ_CNTL
union McSeqCntl {
	struct {
		uint32 memAddrMapCols: 2; // 0
		uint32 memAddrMapBank: 2; // 2
		uint32 safeMode: 2; // 4
		uint32 datInv: 1; // 6
		uint32 mskDf1: 1; // 7
		uint32 channelDisable: 2; // 8
		uint32 unknown1: 4;
		uint32 mskoffDatTl: 1; // 14
		uint32 mskoffDatTh: 1; // 15
		uint32 retHoldEop: 1; // 16
		uint32 bankgroupSize: 1; // 17
		uint32 bankgroupEnb: 1; // 18
		uint32 rtrOverride: 1; // 19
		uint32 arbReqcmdWmk: 4; // 20
		uint32 arbReqdatWmk: 4; // 24
		uint32 arbRtdatWmk: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_CNTL_2
union McSeqCntl2 {
	struct {
		uint32 unknown1: 8;
		uint32 arbRtdatWmkMsb: 2; // 8
		uint32 drstNstr: 6; // 10
		uint32 drstPstr: 6; // 16
		uint32 pllTxPwronD0: 1; // 22
		uint32 pllTxPwronD1: 1; // 23
		uint32 pllRxPwronD0: 4; // 24
		uint32 pllRxPwronD1: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_DRAM
union McSeqDram {
	struct {
		uint32 adr2ck: 1; // 0
		uint32 adrMux: 1; // 1
		uint32 adrDf1: 1; // 2
		uint32 ap8: 1; // 3
		uint32 datDf1: 1; // 4
		uint32 dqsDf1: 1; // 5
		uint32 dqmDf1: 1; // 6
		uint32 dqmAct: 1; // 7
		uint32 stbCnt: 4; // 8
		uint32 ckeDyn: 1; // 12
		uint32 ckeAct: 1; // 13
		uint32 bo4: 1; // 14
		uint32 dllClr: 1; // 15
		uint32 dllCnt: 8; // 16
		uint32 datInv: 1; // 24
		uint32 invAcm: 1; // 25
		uint32 odtEnb: 1; // 26
		uint32 odtAct: 1; // 27
		uint32 rstCtl: 1; // 28
		uint32 triMioDyn: 1; // 29
		uint32 triCke: 1; // 30
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_SEQ_DRAM_2
union McSeqDram2 {
	struct {
		uint32 adrDdr: 1; // 0
		uint32 adrDbi: 1; // 1
		uint32 adrDbiAcm: 1; // 2
		uint32 cmdQdr: 1; // 3
		uint32 datQdr: 1; // 4
		uint32 wdatEdc: 1; // 5
		uint32 rdatEdc: 1; // 6
		uint32 dqmEst: 1; // 7
		uint32 rdDqs: 1; // 8
		uint32 wrDqs: 1; // 9
		uint32 pllEst: 1; // 10
		uint32 pllClr: 1; // 11
		uint32 dllEst: 1; // 12
		uint32 bnkMrs: 1; // 13
		uint32 dbiOvr: 1; // 14
		uint32 triClk: 1; // 15
		uint32 pllCnt: 8; // 16
		uint32 pchBnk: 1; // 24
		uint32 adbiDf1: 1; // 25
		uint32 adbiAct: 1; // 26
		uint32 dbiDf1: 1; // 27
		uint32 dbiAct: 1; // 28
		uint32 dbiEdcDf1: 1; // 29
		uint32 testchipEn: 1; // 30
		uint32 csBy16: 1; // 31
	};
	uint32 val;
};

// MC_SEQ_DRAM_ERROR_INSERTION
union McSeqDramErrorInsertion {
	struct {
		uint32 tx: 16; // 0
		uint32 rx: 16; // 16
	};
	uint32 val;
};

// MC_SEQ_FIFO_CTL
union McSeqFifoCtl {
	struct {
		uint32 wLdInitD0: 2; // 0
		uint32 wSycSel: 2; // 2
		uint32 rLdInit: 2; // 4
		uint32 rSycSel: 2; // 6
		uint32 cgDisD0: 1; // 8
		uint32 cgDisD1: 1; // 9
		uint32 wLdInitD1: 2; // 10
		uint32 sycDly: 3; // 12
		uint32 unknown1: 1;
		uint32 wAsycExt: 2; // 16
		uint32 wDsycExt: 2; // 18
		uint32 unknown2: 12;
	};
	uint32 val;
};

// MC_SEQ_IO_DEBUG_DATA
union McSeqIoDebugData {
	struct {
		uint32 ioDebugData: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_IO_DEBUG_INDEX
union McSeqIoDebugIndex {
	struct {
		uint32 ioDebugIndex: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// MC_SEQ_IO_RDBI
union McSeqIoRdbi {
	struct {
		uint32 mask: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_IO_REDC
union McSeqIoRedc {
	struct {
		uint32 edc: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_IO_RESERVE_D0
union McSeqIoReserveD0 {
	struct {
		uint32 dphy0Rsv: 12; // 0
		uint32 dphy1Rsv: 12; // 12
		uint32 aphyRsv: 8; // 24
	};
	uint32 val;
};

// MC_SEQ_IO_RESERVE_D1
union McSeqIoReserveD1 {
	struct {
		uint32 dphy0Rsv: 12; // 0
		uint32 dphy1Rsv: 12; // 12
		uint32 aphyRsv: 8; // 24
	};
	uint32 val;
};

// MC_SEQ_IO_RWORD0
union McSeqIoRword0 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_IO_RWORD1
union McSeqIoRword1 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_IO_RWORD2
union McSeqIoRword2 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_IO_RWORD3
union McSeqIoRword3 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_IO_RWORD4
union McSeqIoRword4 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_IO_RWORD5
union McSeqIoRword5 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_IO_RWORD6
union McSeqIoRword6 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_IO_RWORD7
union McSeqIoRword7 {
	struct {
		uint32 rdata: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_MISC0
union McSeqMisc0 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_MISC1
union McSeqMisc1 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_MISC3
union McSeqMisc3 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_MISC4
union McSeqMisc4 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_MISC5
union McSeqMisc5 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_MISC6
union McSeqMisc6 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_MISC7
union McSeqMisc7 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_MISC8
union McSeqMisc8 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_MISC9
union McSeqMisc9 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_MISC_TIMING
union McSeqMiscTiming {
	struct {
		uint32 trpWra: 6; // 0
		uint32 unknown1: 2;
		uint32 trpRda: 6; // 8
		uint32 unknown2: 1;
		uint32 trp: 5; // 15
		uint32 trfc: 9; // 20
		uint32 unknown3: 3;
	};
	uint32 val;
};

// MC_SEQ_MISC_TIMING2
union McSeqMiscTiming2 {
	struct {
		uint32 pa2rdata: 3; // 0
		uint32 unknown1: 1;
		uint32 pa2wdata: 3; // 4
		uint32 unknown2: 1;
		uint32 faw: 5; // 8
		uint32 tredc: 3; // 13
		uint32 twedc: 5; // 16
		uint32 t32aw: 4; // 21
		uint32 unknown3: 3;
		uint32 twdatatr: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_MISC_TIMING2_LP
union McSeqMiscTiming2Lp {
	struct {
		uint32 pa2rdata: 3; // 0
		uint32 unknown1: 1;
		uint32 pa2wdata: 3; // 4
		uint32 unknown2: 1;
		uint32 faw: 5; // 8
		uint32 tredc: 3; // 13
		uint32 twedc: 5; // 16
		uint32 tadr: 3; // 21
		uint32 tfcktr: 4; // 24
		uint32 twdatatr: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_MISC_TIMING_LP
union McSeqMiscTimingLp {
	struct {
		uint32 trpWra: 6; // 0
		uint32 unknown1: 2;
		uint32 trpRda: 6; // 8
		uint32 unknown2: 1;
		uint32 trp: 5; // 15
		uint32 trfc: 9; // 20
		uint32 unknown3: 3;
	};
	uint32 val;
};

// MC_SEQ_MPLL_OVERRIDE
union McSeqMpllOverride {
	struct {
		uint32 adPllResetOverride: 1; // 0
		uint32 dq0_0PllResetOverride: 1; // 1
		uint32 dq0_1PllResetOverride: 1; // 2
		uint32 dq1_0PllResetOverride: 1; // 3
		uint32 dq1_1PllResetOverride: 1; // 4
		uint32 atgmClkSelOverride: 1; // 5
		uint32 testBypassClkEnOverride: 1; // 6
		uint32 testBypassClkSelOverride: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_SEQ_PERF_CNTL
union McSeqPerfCntl {
	struct {
		uint32 monitorPeriod: 30; // 0
		uint32 cntl: 2; // 30
	};
	uint32 val;
};

// MC_SEQ_PERF_CNTL_1
union McSeqPerfCntl1 {
	struct {
		uint32 pause: 1; // 0
		uint32 unknown1: 7;
		uint32 selAMsb: 1; // 8
		uint32 selBMsb: 1; // 9
		uint32 selCh0CMsb: 1; // 10
		uint32 selCh0DMsb: 1; // 11
		uint32 selCh1AMsb: 1; // 12
		uint32 selCh1BMsb: 1; // 13
		uint32 selCh1CMsb: 1; // 14
		uint32 selCh1DMsb: 1; // 15
		uint32 unknown2: 16;
	};
	uint32 val;
};

// MC_SEQ_PERF_SEQ_CNT_A_I0
union McSeqPerfSeqCntAI0 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_PERF_SEQ_CNT_A_I1
union McSeqPerfSeqCntAI1 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_PERF_SEQ_CNT_B_I0
union McSeqPerfSeqCntBI0 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_PERF_SEQ_CNT_B_I1
union McSeqPerfSeqCntBI1 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_PERF_SEQ_CNT_C_I0
union McSeqPerfSeqCntCI0 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_PERF_SEQ_CNT_C_I1
union McSeqPerfSeqCntCI1 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_PERF_SEQ_CNT_D_I0
union McSeqPerfSeqCntDI0 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_PERF_SEQ_CNT_D_I1
union McSeqPerfSeqCntDI1 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_PERF_SEQ_CTL
union McSeqPerfSeqCtl {
	struct {
		uint32 selA: 4; // 0
		uint32 selB: 4; // 4
		uint32 selCh0C: 4; // 8
		uint32 selCh0D: 4; // 12
		uint32 selCh1A: 4; // 16
		uint32 selCh1B: 4; // 20
		uint32 selCh1C: 4; // 24
		uint32 selCh1D: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_PMG_CMD_EMRS_LP
union McSeqPmgCmdEmrsLp {
	struct {
		uint32 adr: 16; // 0
		uint32 mop: 3; // 16
		uint32 bnkMsb: 1; // 19
		uint32 end: 1; // 20
		uint32 csb: 2; // 21
		uint32 unknown1: 5;
		uint32 adrMsb1: 1; // 28
		uint32 adrMsb0: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_SEQ_PMG_CMD_MRS1_LP
union McSeqPmgCmdMrs1Lp {
	struct {
		uint32 adr: 16; // 0
		uint32 mop: 3; // 16
		uint32 bnkMsb: 1; // 19
		uint32 end: 1; // 20
		uint32 csb: 2; // 21
		uint32 unknown1: 5;
		uint32 adrMsb1: 1; // 28
		uint32 adrMsb0: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_SEQ_PMG_CMD_MRS2_LP
union McSeqPmgCmdMrs2Lp {
	struct {
		uint32 adr: 16; // 0
		uint32 mop: 3; // 16
		uint32 bnkMsb: 1; // 19
		uint32 end: 1; // 20
		uint32 csb: 2; // 21
		uint32 unknown1: 5;
		uint32 adrMsb1: 1; // 28
		uint32 adrMsb0: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_SEQ_PMG_CMD_MRS_LP
union McSeqPmgCmdMrsLp {
	struct {
		uint32 adr: 16; // 0
		uint32 mop: 3; // 16
		uint32 bnkMsb: 1; // 19
		uint32 end: 1; // 20
		uint32 csb: 2; // 21
		uint32 unknown1: 5;
		uint32 adrMsb1: 1; // 28
		uint32 adrMsb0: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_SEQ_PMG_PG_HWCNTL
union McSeqPmgPgHwcntl {
	struct {
		uint32 pwrgateEn: 1; // 0
		uint32 staggerEn: 1; // 1
		uint32 tpgcg: 4; // 2
		uint32 dDly: 2; // 6
		uint32 acDly: 2; // 8
		uint32 gDly: 4; // 10
		uint32 unknown1: 2;
		uint32 txao: 1; // 16
		uint32 rxao: 1; // 17
		uint32 acao: 1; // 18
		uint32 unknown2: 13;
	};
	uint32 val;
};

// MC_SEQ_PMG_PG_SWCNTL_0
union McSeqPmgPgSwcntl0 {
	struct {
		uint32 pmd0DqTxEnb: 1; // 0
		uint32 pmd0DbiTxEnb: 1; // 1
		uint32 pmd0EdcTxEnb: 1; // 2
		uint32 pmd0WclkxTxEnb: 1; // 3
		uint32 pmd0DqRxEnb: 1; // 4
		uint32 pmd0DbiRxEnb: 1; // 5
		uint32 pmd0EdcRxEnb: 1; // 6
		uint32 pmd0WclkxRxEnb: 1; // 7
		uint32 pmd1DqTxEnb: 1; // 8
		uint32 pmd1DbiTxEnb: 1; // 9
		uint32 pmd1EdcTxEnb: 1; // 10
		uint32 pmd1WclkxTxEnb: 1; // 11
		uint32 pmd1DqRxEnb: 1; // 12
		uint32 pmd1DbiRxEnb: 1; // 13
		uint32 pmd1EdcRxEnb: 1; // 14
		uint32 pmd1WclkxRxEnb: 1; // 15
		uint32 pma0AcEnb: 1; // 16
		uint32 unknown1: 14;
		uint32 gmconSrCommit: 1; // 31
	};
	uint32 val;
};

// MC_SEQ_PMG_PG_SWCNTL_1
union McSeqPmgPgSwcntl1 {
	struct {
		uint32 pmd2DqTxEnb: 1; // 0
		uint32 pmd2DbiTxEnb: 1; // 1
		uint32 pmd2EdcTxEnb: 1; // 2
		uint32 pmd2WclkxTxEnb: 1; // 3
		uint32 pmd2DqRxEnb: 1; // 4
		uint32 pmd2DbiRxEnb: 1; // 5
		uint32 pmd2EdcRxEnb: 1; // 6
		uint32 pmd2WclkxRxEnb: 1; // 7
		uint32 pmd3DqTxEnb: 1; // 8
		uint32 pmd3DbiTxEnb: 1; // 9
		uint32 pmd3EdcTxEnb: 1; // 10
		uint32 pmd3WclkxTxEnb: 1; // 11
		uint32 pmd3DqRxEnb: 1; // 12
		uint32 pmd3DbiRxEnb: 1; // 13
		uint32 pmd3EdcRxEnb: 1; // 14
		uint32 pmd3WclkxRxEnb: 1; // 15
		uint32 pma1AcEnb: 1; // 16
		uint32 unknown1: 14;
		uint32 gmconSrCommit: 1; // 31
	};
	uint32 val;
};

// MC_SEQ_PMG_TIMING
union McSeqPmgTiming {
	struct {
		uint32 tcksre: 3; // 0
		uint32 unknown1: 1;
		uint32 tcksrx: 3; // 4
		uint32 unknown2: 1;
		uint32 tckePulse: 4; // 8
		uint32 tcke: 6; // 12
		uint32 seqIdle: 3; // 18
		uint32 unknown3: 2;
		uint32 tckePulseMsb: 1; // 23
		uint32 seqIdleSs: 8; // 24
	};
	uint32 val;
};

// MC_SEQ_PMG_TIMING_LP
union McSeqPmgTimingLp {
	struct {
		uint32 tcksre: 3; // 0
		uint32 unknown1: 1;
		uint32 tcksrx: 3; // 4
		uint32 unknown2: 1;
		uint32 tckePulse: 4; // 8
		uint32 tcke: 6; // 12
		uint32 seqIdle: 3; // 18
		uint32 unknown3: 2;
		uint32 tckePulseMsb: 1; // 23
		uint32 seqIdleSs: 8; // 24
	};
	uint32 val;
};

// MC_SEQ_RAS_TIMING
union McSeqRasTiming {
	struct {
		uint32 trcdw: 5; // 0
		uint32 trcdwa: 5; // 5
		uint32 trcdr: 5; // 10
		uint32 trcdra: 5; // 15
		uint32 trrd: 4; // 20
		uint32 trc: 7; // 24
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_SEQ_RAS_TIMING_LP
union McSeqRasTimingLp {
	struct {
		uint32 trcdw: 5; // 0
		uint32 trcdwa: 5; // 5
		uint32 trcdr: 5; // 10
		uint32 trcdra: 5; // 15
		uint32 trrd: 4; // 20
		uint32 trc: 7; // 24
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_SEQ_RD_CTL_D0
union McSeqRdCtlD0 {
	struct {
		uint32 rcvDly: 3; // 0
		uint32 rcvExt: 5; // 3
		uint32 rstSel: 2; // 8
		uint32 rxdpwronDly: 2; // 10
		uint32 rstHld: 4; // 12
		uint32 strPre: 1; // 16
		uint32 strPst: 1; // 17
		uint32 unknown1: 2;
		uint32 rbsDly: 5; // 20
		uint32 rbsWedcDly: 5; // 25
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_SEQ_RD_CTL_D0_LP
union McSeqRdCtlD0Lp {
	struct {
		uint32 rcvDly: 3; // 0
		uint32 rcvExt: 5; // 3
		uint32 rstSel: 2; // 8
		uint32 rxdpwronDly: 2; // 10
		uint32 rstHld: 4; // 12
		uint32 strPre: 1; // 16
		uint32 strPst: 1; // 17
		uint32 unknown1: 2;
		uint32 rbsDly: 5; // 20
		uint32 rbsWedcDly: 5; // 25
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_SEQ_RD_CTL_D1
union McSeqRdCtlD1 {
	struct {
		uint32 rcvDly: 3; // 0
		uint32 rcvExt: 5; // 3
		uint32 rstSel: 2; // 8
		uint32 rxdpwronDly: 2; // 10
		uint32 rstHld: 4; // 12
		uint32 strPre: 1; // 16
		uint32 strPst: 1; // 17
		uint32 unknown1: 2;
		uint32 rbsDly: 5; // 20
		uint32 rbsWedcDly: 5; // 25
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_SEQ_RD_CTL_D1_LP
union McSeqRdCtlD1Lp {
	struct {
		uint32 rcvDly: 3; // 0
		uint32 rcvExt: 5; // 3
		uint32 rstSel: 2; // 8
		uint32 rxdpwronDly: 2; // 10
		uint32 rstHld: 4; // 12
		uint32 strPre: 1; // 16
		uint32 strPst: 1; // 17
		uint32 unknown1: 2;
		uint32 rbsDly: 5; // 20
		uint32 rbsWedcDly: 5; // 25
		uint32 unknown2: 2;
	};
	uint32 val;
};

// MC_SEQ_RESERVE_0_S
union McSeqReserve0S {
	struct {
		uint32 sclkField: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_RESERVE_1_S
union McSeqReserve1S {
	struct {
		uint32 sclkField: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_RESERVE_M
union McSeqReserveM {
	struct {
		uint32 mclkField: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_RXFRAMING_BYTE0_D0
union McSeqRxframingByte0D0 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_RXFRAMING_BYTE0_D1
union McSeqRxframingByte0D1 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_RXFRAMING_BYTE1_D0
union McSeqRxframingByte1D0 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_RXFRAMING_BYTE1_D1
union McSeqRxframingByte1D1 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_RXFRAMING_BYTE2_D0
union McSeqRxframingByte2D0 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_RXFRAMING_BYTE2_D1
union McSeqRxframingByte2D1 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_RXFRAMING_BYTE3_D0
union McSeqRxframingByte3D0 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_RXFRAMING_BYTE3_D1
union McSeqRxframingByte3D1 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_RXFRAMING_DBI_D0
union McSeqRxframingDbiD0 {
	struct {
		uint32 dbi0: 4; // 0
		uint32 dbi1: 4; // 4
		uint32 dbi2: 4; // 8
		uint32 dbi3: 4; // 12
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_SEQ_RXFRAMING_DBI_D1
union McSeqRxframingDbiD1 {
	struct {
		uint32 dbi0: 4; // 0
		uint32 dbi1: 4; // 4
		uint32 dbi2: 4; // 8
		uint32 dbi3: 4; // 12
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_SEQ_RXFRAMING_EDC_D0
union McSeqRxframingEdcD0 {
	struct {
		uint32 edc0: 4; // 0
		uint32 edc1: 4; // 4
		uint32 edc2: 4; // 8
		uint32 edc3: 4; // 12
		uint32 wcdr0: 4; // 16
		uint32 wcdr1: 4; // 20
		uint32 wcdr2: 4; // 24
		uint32 wcdr3: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_RXFRAMING_EDC_D1
union McSeqRxframingEdcD1 {
	struct {
		uint32 edc0: 4; // 0
		uint32 edc1: 4; // 4
		uint32 edc2: 4; // 8
		uint32 edc3: 4; // 12
		uint32 wcdr0: 4; // 16
		uint32 wcdr1: 4; // 20
		uint32 wcdr2: 4; // 24
		uint32 wcdr3: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_STATUS_M
union McSeqStatusM {
	struct {
		uint32 pwrupComplD0: 1; // 0
		uint32 pwrupComplD1: 1; // 1
		uint32 cmdRdyD0: 1; // 2
		uint32 cmdRdyD1: 1; // 3
		uint32 slfD0: 1; // 4
		uint32 slfD1: 1; // 5
		uint32 ssSlfD0: 1; // 6
		uint32 ssSlfD1: 1; // 7
		uint32 seq0ArbCmdFifoEmpty: 1; // 8
		uint32 seq1ArbCmdFifoEmpty: 1; // 9
		uint32 unknown1: 2;
		uint32 seq0RsDataFifoFull: 1; // 12
		uint32 seq1RsDataFifoFull: 1; // 13
		uint32 seq0Busy: 1; // 14
		uint32 seq1Busy: 1; // 15
		uint32 pmgPwrstate: 1; // 16
		uint32 unknown2: 3;
		uint32 pmgFsmstate: 5; // 20
		uint32 seq0BusyHys: 1; // 25
		uint32 seq1BusyHys: 1; // 26
		uint32 unknown3: 5;
	};
	uint32 val;
};

// MC_SEQ_STATUS_S
union McSeqStatusS {
	struct {
		uint32 seq0ArbDataFifoFull: 1; // 0
		uint32 seq1ArbDataFifoFull: 1; // 1
		uint32 unknown1: 2;
		uint32 seq0ArbCmdFifoFull: 1; // 4
		uint32 seq1ArbCmdFifoFull: 1; // 5
		uint32 unknown2: 2;
		uint32 seq0RsDataFifoEmpty: 1; // 8
		uint32 seq1RsDataFifoEmpty: 1; // 9
		uint32 unknown3: 22;
	};
	uint32 val;
};

// MC_SEQ_SUP_CNTL
union McSeqSupCntl {
	struct {
		uint32 run: 1; // 0
		uint32 singleStep: 1; // 1
		uint32 swWake: 1; // 2
		uint32 resetPc: 1; // 3
		uint32 pgmWrite: 1; // 4
		uint32 pgmRead: 1; // 5
		uint32 fastWrite: 1; // 6
		uint32 bkptClear: 1; // 7
		uint32 unknown1: 15;
		uint32 pgmChksum: 9; // 23
	};
	uint32 val;
};

// MC_SEQ_SUP_DEC_STAT
union McSeqSupDecStat {
	struct {
		uint32 status: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_SUP_GP0_STAT
union McSeqSupGp0Stat {
	struct {
		uint32 status: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_SUP_GP1_STAT
union McSeqSupGp1Stat {
	struct {
		uint32 status: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_SUP_GP2_STAT
union McSeqSupGp2Stat {
	struct {
		uint32 status: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_SUP_GP3_STAT
union McSeqSupGp3Stat {
	struct {
		uint32 status: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_SUP_IR_STAT
union McSeqSupIrStat {
	struct {
		uint32 status: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_SUP_PGM
union McSeqSupPgm {
	struct {
		uint32 cntl: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_SUP_PGM_STAT
union McSeqSupPgmStat {
	struct {
		uint32 status: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_SUP_R_PGM
union McSeqSupRPgm {
	struct {
		uint32 pgm: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_TCG_CNTL
union McSeqTcgCntl {
	struct {
		uint32 reset: 1; // 0
		uint32 enableD0: 1; // 1
		uint32 enableD1: 1; // 2
		uint32 start: 1; // 3
		uint32 nfifo: 3; // 4
		uint32 infiniteCmd: 1; // 7
		uint32 mop: 4; // 8
		uint32 dataCnt: 4; // 12
		uint32 loadFifo: 1; // 16
		uint32 shortLdff: 1; // 17
		uint32 frameTrain: 1; // 18
		uint32 burstNum: 3; // 19
		uint32 issueAref: 1; // 22
		uint32 txdbiCntl: 1; // 23
		uint32 vptrMask: 1; // 24
		uint32 arefLast: 1; // 25
		uint32 arefBoth: 1; // 26
		uint32 unknown1: 4;
		uint32 done: 1; // 31
	};
	uint32 val;
};

// MC_SEQ_TIMER_RD
union McSeqTimerRd {
	struct {
		uint32 counter: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_TIMER_WR
union McSeqTimerWr {
	struct {
		uint32 counter: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_TRAIN_CAPTURE
union McSeqTrainCapture {
	struct {
		uint32 d0ArfWakeup: 1; // 0
		uint32 d1ArfWakeup: 1; // 1
		uint32 d0RedcWakeup: 1; // 2
		uint32 d1RedcWakeup: 1; // 3
		uint32 d0WedcWakeup: 1; // 4
		uint32 d1WedcWakeup: 1; // 5
		uint32 mclkFreqChangeWakeup: 1; // 6
		uint32 sclkSrbmReadyWakeup: 1; // 7
		uint32 d0CmdFifoReadyWakeup: 1; // 8
		uint32 d1CmdFifoReadyWakeup: 1; // 9
		uint32 d0DataFifoReadyWakeup: 1; // 10
		uint32 d1DataFifoReadyWakeup: 1; // 11
		uint32 softwareWakeupWakeup: 1; // 12
		uint32 reserve0Wakeup: 1; // 13
		uint32 tsmDoneWakeup: 1; // 14
		uint32 timerDoneWakeup: 1; // 15
		uint32 unknown1: 1;
		uint32 tcgDoneWakeup: 1; // 17
		uint32 allowstop0Wakeup: 1; // 18
		uint32 allowstop1Wakeup: 1; // 19
		uint32 dpmWakeup: 1; // 20
		uint32 allowstopb0Wakeup: 1; // 21
		uint32 allowstopb1Wakeup: 1; // 22
		uint32 dpmLptWakeup: 1; // 23
		uint32 d0IdlehWakeup: 1; // 24
		uint32 d1IdlehWakeup: 1; // 25
		uint32 phyPgWakeup: 1; // 26
		uint32 unknown2: 5;
	};
	uint32 val;
};

// MC_SEQ_TRAIN_EDC_THRESHOLD
union McSeqTrainEdcThreshold {
	struct {
		uint32 writeEdcThreshold: 16; // 0
		uint32 readEdcThreshold: 16; // 16
	};
	uint32 val;
};

// MC_SEQ_TRAIN_EDC_THRESHOLD2
union McSeqTrainEdcThreshold2 {
	struct {
		uint32 thresholdPeriod: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_TRAIN_EDC_THRESHOLD3
union McSeqTrainEdcThreshold3 {
	struct {
		uint32 ch0LinkRetrainStatus: 1; // 0
		uint32 ch1LinkRetrainStatus: 1; // 1
		uint32 clearRetrainStatus: 1; // 2
		uint32 retrainVbi: 1; // 3
		uint32 retrainMonitor: 2; // 4
		uint32 unknown1: 2;
		uint32 ch0LinkRetrainInProgress: 1; // 8
		uint32 ch1LinkRetrainInProgress: 1; // 9
		uint32 unknown2: 22;
	};
	uint32 val;
};

// MC_SEQ_TRAIN_TIMING
union McSeqTrainTiming {
	struct {
		uint32 twt2rt: 5; // 0
		uint32 tarf2t: 5; // 5
		uint32 tt2row: 5; // 10
		uint32 tld2ld: 5; // 15
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_SEQ_TRAIN_WAKEUP_CLEAR
union McSeqTrainWakeupClear {
	struct {
		uint32 d0ArfWakeup: 1; // 0
		uint32 d1ArfWakeup: 1; // 1
		uint32 d0RedcWakeup: 1; // 2
		uint32 d1RedcWakeup: 1; // 3
		uint32 d0WedcWakeup: 1; // 4
		uint32 d1WedcWakeup: 1; // 5
		uint32 mclkFreqChangeWakeup: 1; // 6
		uint32 sclkSrbmReadyWakeup: 1; // 7
		uint32 d0CmdFifoReadyWakeup: 1; // 8
		uint32 d1CmdFifoReadyWakeup: 1; // 9
		uint32 d0DataFifoReadyWakeup: 1; // 10
		uint32 d1DataFifoReadyWakeup: 1; // 11
		uint32 softwareWakeupWakeup: 1; // 12
		uint32 reserve0Wakeup: 1; // 13
		uint32 tsmDoneWakeup: 1; // 14
		uint32 timerDoneWakeup: 1; // 15
		uint32 clearall: 1; // 16
		uint32 tcgDoneWakeup: 1; // 17
		uint32 allowstop0Wakeup: 1; // 18
		uint32 allowstop1Wakeup: 1; // 19
		uint32 dpmWakeup: 1; // 20
		uint32 allowstopb0Wakeup: 1; // 21
		uint32 allowstopb1Wakeup: 1; // 22
		uint32 dpmLptWakeup: 1; // 23
		uint32 d0IdlehWakeup: 1; // 24
		uint32 d1IdlehWakeup: 1; // 25
		uint32 phyPgWakeup: 1; // 26
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_SEQ_TRAIN_WAKEUP_CNTL
union McSeqTrainWakeupCntl {
	struct {
		uint32 bootUpAddrTrain: 1; // 0
		uint32 bootUpWckTrain: 1; // 1
		uint32 bootUpReadTrain: 1; // 2
		uint32 bootUpWriteTrain: 1; // 3
		uint32 selfRefreshAddrTrain: 1; // 4
		uint32 selfRefreshWckTrain: 1; // 5
		uint32 selfRefreshReadTrain: 1; // 6
		uint32 selfRefreshWriteTrain: 1; // 7
		uint32 autoRefreshAddrTrain: 1; // 8
		uint32 autoRefreshWckTrain: 1; // 9
		uint32 autoRefreshReadTrain: 1; // 10
		uint32 autoRefreshWriteTrain: 1; // 11
		uint32 writeEccAddrTrain: 1; // 12
		uint32 writeEccWckTrain: 1; // 13
		uint32 writeEccReadTrain: 1; // 14
		uint32 writeEccWriteTrain: 1; // 15
		uint32 readEccAddrTrain: 1; // 16
		uint32 readEccWckTrain: 1; // 17
		uint32 readEccReadTrain: 1; // 18
		uint32 readEccWriteTrain: 1; // 19
		uint32 autoRefreshWakeupEarly: 1; // 20
		uint32 stopWckD0: 1; // 21
		uint32 stopWckD1: 1; // 22
		uint32 unknown1: 1;
		uint32 blockArbRdD0: 1; // 24
		uint32 blockArbWrD0: 1; // 25
		uint32 blockArbRdD1: 1; // 26
		uint32 blockArbWrD1: 1; // 27
		uint32 swWakeup: 1; // 28
		uint32 dispAstopWakeup: 1; // 29
		uint32 trainDoneD0: 1; // 30
		uint32 trainDoneD1: 1; // 31
	};
	uint32 val;
};

// MC_SEQ_TRAIN_WAKEUP_EDGE
union McSeqTrainWakeupEdge {
	struct {
		uint32 d0ArfWakeup: 1; // 0
		uint32 d1ArfWakeup: 1; // 1
		uint32 d0RedcWakeup: 1; // 2
		uint32 d1RedcWakeup: 1; // 3
		uint32 d0WedcWakeup: 1; // 4
		uint32 d1WedcWakeup: 1; // 5
		uint32 mclkFreqChangeWakeup: 1; // 6
		uint32 sclkSrbmReadyWakeup: 1; // 7
		uint32 d0CmdFifoReadyWakeup: 1; // 8
		uint32 d1CmdFifoReadyWakeup: 1; // 9
		uint32 d0DataFifoReadyWakeup: 1; // 10
		uint32 d1DataFifoReadyWakeup: 1; // 11
		uint32 softwareWakeupWakeup: 1; // 12
		uint32 reserve0Wakeup: 1; // 13
		uint32 tsmDoneWakeup: 1; // 14
		uint32 timerDoneWakeup: 1; // 15
		uint32 unknown1: 1;
		uint32 tcgDoneWakeup: 1; // 17
		uint32 allowstop0Wakeup: 1; // 18
		uint32 allowstop1Wakeup: 1; // 19
		uint32 dpmWakeup: 1; // 20
		uint32 allowstopb0Wakeup: 1; // 21
		uint32 allowstopb1Wakeup: 1; // 22
		uint32 dpmLptWakeup: 1; // 23
		uint32 d0IdlehWakeup: 1; // 24
		uint32 d1IdlehWakeup: 1; // 25
		uint32 phyPgWakeup: 1; // 26
		uint32 unknown2: 5;
	};
	uint32 val;
};

// MC_SEQ_TRAIN_WAKEUP_MASK
union McSeqTrainWakeupMask {
	struct {
		uint32 d0ArfWakeup: 1; // 0
		uint32 d1ArfWakeup: 1; // 1
		uint32 d0RedcWakeup: 1; // 2
		uint32 d1RedcWakeup: 1; // 3
		uint32 d0WedcWakeup: 1; // 4
		uint32 d1WedcWakeup: 1; // 5
		uint32 mclkFreqChangeWakeup: 1; // 6
		uint32 sclkSrbmReadyWakeup: 1; // 7
		uint32 d0CmdFifoReadyWakeup: 1; // 8
		uint32 d1CmdFifoReadyWakeup: 1; // 9
		uint32 d0DataFifoReadyWakeup: 1; // 10
		uint32 d1DataFifoReadyWakeup: 1; // 11
		uint32 softwareWakeupWakeup: 1; // 12
		uint32 reserve0Wakeup: 1; // 13
		uint32 tsmDoneWakeup: 1; // 14
		uint32 timerDoneWakeup: 1; // 15
		uint32 unknown1: 1;
		uint32 tcgDoneWakeup: 1; // 17
		uint32 allowstop0Wakeup: 1; // 18
		uint32 allowstop1Wakeup: 1; // 19
		uint32 dpmWakeup: 1; // 20
		uint32 allowstopb0Wakeup: 1; // 21
		uint32 allowstopb1Wakeup: 1; // 22
		uint32 dpmLptWakeup: 1; // 23
		uint32 d0IdlehWakeup: 1; // 24
		uint32 d1IdlehWakeup: 1; // 25
		uint32 phyPgWakeup: 1; // 26
		uint32 unknown2: 5;
	};
	uint32 val;
};

// MC_SEQ_TSM_BCNT
union McSeqTsmBcnt {
	struct {
		uint32 trueAct: 4; // 0
		uint32 falseAct: 4; // 4
		uint32 bcntTests: 8; // 8
		uint32 compValue: 8; // 16
		uint32 doneTests: 8; // 24
	};
	uint32 val;
};

// MC_SEQ_TSM_CTRL
union McSeqTsmCtrl {
	struct {
		uint32 start: 1; // 0
		uint32 captureStart: 1; // 1
		uint32 done: 1; // 2
		uint32 err: 1; // 3
		uint32 step: 1; // 4
		uint32 direction: 1; // 5
		uint32 invert: 1; // 6
		uint32 maskBits: 1; // 7
		uint32 updateLoop: 2; // 8
		uint32 rotInv: 1; // 10
		uint32 unknown1: 5;
		uint32 pointer: 16; // 16
	};
	uint32 val;
};

// MC_SEQ_TSM_DBI
union McSeqTsmDbi {
	struct {
		uint32 dbi: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_TSM_DEBUG_DATA
union McSeqTsmDebugData {
	struct {
		uint32 tsmDebugData: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_TSM_DEBUG_INDEX
union McSeqTsmDebugIndex {
	struct {
		uint32 tsmDebugIndex: 5; // 0
		uint32 unknown1: 27;
	};
	uint32 val;
};

// MC_SEQ_TSM_EDC
union McSeqTsmEdc {
	struct {
		uint32 edc: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_TSM_FLAG
union McSeqTsmFlag {
	struct {
		uint32 trueAct: 4; // 0
		uint32 falseAct: 4; // 4
		uint32 flagTests: 8; // 8
		uint32 nbblMask: 4; // 16
		uint32 unknown1: 4;
		uint32 errorTests: 8; // 24
	};
	uint32 val;
};

// MC_SEQ_TSM_GCNT
union McSeqTsmGcnt {
	struct {
		uint32 trueAct: 4; // 0
		uint32 falseAct: 4; // 4
		uint32 tests: 8; // 8
		uint32 compValue: 16; // 16
	};
	uint32 val;
};

// MC_SEQ_TSM_MISC
union McSeqTsmMisc {
	struct {
		uint32 wcdrPtr: 16; // 0
		uint32 wcdrMask: 4; // 16
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_SEQ_TSM_NCNT
union McSeqTsmNcnt {
	struct {
		uint32 trueAct: 4; // 0
		uint32 falseAct: 4; // 4
		uint32 tests: 8; // 8
		uint32 rangeLow: 4; // 16
		uint32 rangeHigh: 4; // 20
		uint32 nibbleSkip: 4; // 24
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_SEQ_TSM_OCNT
union McSeqTsmOcnt {
	struct {
		uint32 trueAct: 4; // 0
		uint32 falseAct: 4; // 4
		uint32 tests: 8; // 8
		uint32 cmpValue: 16; // 16
	};
	uint32 val;
};

// MC_SEQ_TSM_UPDATE
union McSeqTsmUpdate {
	struct {
		uint32 trueAct: 4; // 0
		uint32 falseAct: 4; // 4
		uint32 updtTests: 8; // 8
		uint32 arefCount: 8; // 16
		uint32 captrTests: 8; // 24
	};
	uint32 val;
};

// MC_SEQ_TSM_WCDR
union McSeqTsmWcdr {
	struct {
		uint32 wcdr: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_BYTE0_D0
union McSeqTxframingByte0D0 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_BYTE0_D1
union McSeqTxframingByte0D1 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_BYTE1_D0
union McSeqTxframingByte1D0 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_BYTE1_D1
union McSeqTxframingByte1D1 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_BYTE2_D0
union McSeqTxframingByte2D0 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_BYTE2_D1
union McSeqTxframingByte2D1 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_BYTE3_D0
union McSeqTxframingByte3D0 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_BYTE3_D1
union McSeqTxframingByte3D1 {
	struct {
		uint32 dq0: 4; // 0
		uint32 dq1: 4; // 4
		uint32 dq2: 4; // 8
		uint32 dq3: 4; // 12
		uint32 dq4: 4; // 16
		uint32 dq5: 4; // 20
		uint32 dq6: 4; // 24
		uint32 dq7: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_DBI_D0
union McSeqTxframingDbiD0 {
	struct {
		uint32 dbi0: 4; // 0
		uint32 dbi1: 4; // 4
		uint32 dbi2: 4; // 8
		uint32 dbi3: 4; // 12
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_DBI_D1
union McSeqTxframingDbiD1 {
	struct {
		uint32 dbi0: 4; // 0
		uint32 dbi1: 4; // 4
		uint32 dbi2: 4; // 8
		uint32 dbi3: 4; // 12
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_EDC_D0
union McSeqTxframingEdcD0 {
	struct {
		uint32 edc0: 4; // 0
		uint32 edc1: 4; // 4
		uint32 edc2: 4; // 8
		uint32 edc3: 4; // 12
		uint32 wcdr0: 4; // 16
		uint32 wcdr1: 4; // 20
		uint32 wcdr2: 4; // 24
		uint32 wcdr3: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_EDC_D1
union McSeqTxframingEdcD1 {
	struct {
		uint32 edc0: 4; // 0
		uint32 edc1: 4; // 4
		uint32 edc2: 4; // 8
		uint32 edc3: 4; // 12
		uint32 wcdr0: 4; // 16
		uint32 wcdr1: 4; // 20
		uint32 wcdr2: 4; // 24
		uint32 wcdr3: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_FCK_D0
union McSeqTxframingFckD0 {
	struct {
		uint32 fck0: 4; // 0
		uint32 fck1: 4; // 4
		uint32 fck2: 4; // 8
		uint32 fck3: 4; // 12
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_SEQ_TXFRAMING_FCK_D1
union McSeqTxframingFckD1 {
	struct {
		uint32 fck0: 4; // 0
		uint32 fck1: 4; // 4
		uint32 fck2: 4; // 8
		uint32 fck3: 4; // 12
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_SEQ_VENDOR_ID_I0
union McSeqVendorIdI0 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_VENDOR_ID_I1
union McSeqVendorIdI1 {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// MC_SEQ_WCDR_CTRL
union McSeqWcdrCtrl {
	struct {
		uint32 wcdrPre: 8; // 0
		uint32 wcdrTim: 4; // 8
		uint32 wrEn: 1; // 12
		uint32 rdEn: 1; // 13
		uint32 arefEn: 1; // 14
		uint32 trainEn: 1; // 15
		uint32 twcdrl: 4; // 16
		uint32 prbsEn: 1; // 20
		uint32 prbsRst: 1; // 21
		uint32 unknown1: 2;
		uint32 preamble: 4; // 24
		uint32 preMask: 4; // 28
	};
	uint32 val;
};

// MC_SEQ_WR_CTL_2
union McSeqWrCtl2 {
	struct {
		uint32 datDlyHD0: 1; // 0
		uint32 dqsDlyHD0: 1; // 1
		uint32 oenDlyHD0: 1; // 2
		uint32 datDlyHD1: 1; // 3
		uint32 dqsDlyHD1: 1; // 4
		uint32 oenDlyHD1: 1; // 5
		uint32 wcdrEn: 1; // 6
		uint32 unknown1: 25;
	};
	uint32 val;
};

// MC_SEQ_WR_CTL_2_LP
union McSeqWrCtl2Lp {
	struct {
		uint32 datDlyHD0: 1; // 0
		uint32 dqsDlyHD0: 1; // 1
		uint32 oenDlyHD0: 1; // 2
		uint32 datDlyHD1: 1; // 3
		uint32 dqsDlyHD1: 1; // 4
		uint32 oenDlyHD1: 1; // 5
		uint32 wcdrEn: 1; // 6
		uint32 unknown1: 25;
	};
	uint32 val;
};

// MC_SEQ_WR_CTL_D0
union McSeqWrCtlD0 {
	struct {
		uint32 datDly: 4; // 0
		uint32 dqsDly: 4; // 4
		uint32 dqsXtr: 1; // 8
		uint32 dat2yDly: 1; // 9
		uint32 adr2yDly: 1; // 10
		uint32 cmd2yDly: 1; // 11
		uint32 oenDly: 4; // 12
		uint32 oenExt: 4; // 16
		uint32 oenSel: 2; // 20
		uint32 unknown1: 2;
		uint32 odtDly: 4; // 24
		uint32 odtExt: 1; // 28
		uint32 adrDly: 1; // 29
		uint32 cmdDly: 1; // 30
		uint32 unknown2: 1;
	};
	uint32 val;
};

// MC_SEQ_WR_CTL_D0_LP
union McSeqWrCtlD0Lp {
	struct {
		uint32 datDly: 4; // 0
		uint32 dqsDly: 4; // 4
		uint32 dqsXtr: 1; // 8
		uint32 dat2yDly: 1; // 9
		uint32 adr2yDly: 1; // 10
		uint32 cmd2yDly: 1; // 11
		uint32 oenDly: 4; // 12
		uint32 oenExt: 4; // 16
		uint32 oenSel: 2; // 20
		uint32 unknown1: 2;
		uint32 odtDly: 4; // 24
		uint32 odtExt: 1; // 28
		uint32 adrDly: 1; // 29
		uint32 cmdDly: 1; // 30
		uint32 unknown2: 1;
	};
	uint32 val;
};

// MC_SEQ_WR_CTL_D1
union McSeqWrCtlD1 {
	struct {
		uint32 datDly: 4; // 0
		uint32 dqsDly: 4; // 4
		uint32 dqsXtr: 1; // 8
		uint32 dat2yDly: 1; // 9
		uint32 adr2yDly: 1; // 10
		uint32 cmd2yDly: 1; // 11
		uint32 oenDly: 4; // 12
		uint32 oenExt: 4; // 16
		uint32 oenSel: 2; // 20
		uint32 unknown1: 2;
		uint32 odtDly: 4; // 24
		uint32 odtExt: 1; // 28
		uint32 adrDly: 1; // 29
		uint32 cmdDly: 1; // 30
		uint32 unknown2: 1;
	};
	uint32 val;
};

// MC_SEQ_WR_CTL_D1_LP
union McSeqWrCtlD1Lp {
	struct {
		uint32 datDly: 4; // 0
		uint32 dqsDly: 4; // 4
		uint32 dqsXtr: 1; // 8
		uint32 dat2yDly: 1; // 9
		uint32 adr2yDly: 1; // 10
		uint32 cmd2yDly: 1; // 11
		uint32 oenDly: 4; // 12
		uint32 oenExt: 4; // 16
		uint32 oenSel: 2; // 20
		uint32 unknown1: 2;
		uint32 odtDly: 4; // 24
		uint32 odtExt: 1; // 28
		uint32 adrDly: 1; // 29
		uint32 cmdDly: 1; // 30
		uint32 unknown2: 1;
	};
	uint32 val;
};

// MC_SHARED_BLACKOUT_CNTL
union McSharedBlackoutCntl {
	struct {
		uint32 blackoutMode: 3; // 0
		uint32 unknown1: 29;
	};
	uint32 val;
};

// MC_SHARED_CHMAP
union McSharedChmap {
	struct {
		uint32 chan0: 4; // 0
		uint32 chan1: 4; // 4
		uint32 chan2: 4; // 8
		uint32 noofchan: 4; // 12
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_SHARED_CHREMAP
union McSharedChremap {
	struct {
		uint32 chan0: 3; // 0
		uint32 chan1: 3; // 3
		uint32 chan2: 3; // 6
		uint32 chan3: 3; // 9
		uint32 chan4: 3; // 12
		uint32 chan5: 3; // 15
		uint32 chan6: 3; // 18
		uint32 chan7: 3; // 21
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_TRAIN_EDCCDR_R_D0
union McTrainEdccdrRD0 {
	struct {
		uint32 edc0: 8; // 0
		uint32 edc1: 8; // 8
		uint32 edc2: 8; // 16
		uint32 edc3: 8; // 24
	};
	uint32 val;
};

// MC_TRAIN_EDCCDR_R_D1
union McTrainEdccdrRD1 {
	struct {
		uint32 edc0: 8; // 0
		uint32 edc1: 8; // 8
		uint32 edc2: 8; // 16
		uint32 edc3: 8; // 24
	};
	uint32 val;
};

// MC_TRAIN_EDC_STATUS_D0
union McTrainEdcStatusD0 {
	struct {
		uint32 wedcCnt: 16; // 0
		uint32 redcCnt: 16; // 16
	};
	uint32 val;
};

// MC_TRAIN_EDC_STATUS_D1
union McTrainEdcStatusD1 {
	struct {
		uint32 wedcCnt: 16; // 0
		uint32 redcCnt: 16; // 16
	};
	uint32 val;
};

// MC_TRAIN_PRBSERR_0_D0
union McTrainPrbserr0D0 {
	struct {
		uint32 dqStatus: 32; // 0
	};
	uint32 val;
};

// MC_TRAIN_PRBSERR_0_D1
union McTrainPrbserr0D1 {
	struct {
		uint32 dqStatus: 32; // 0
	};
	uint32 val;
};

// MC_TRAIN_PRBSERR_1_D0
union McTrainPrbserr1D0 {
	struct {
		uint32 dbiStatus: 4; // 0
		uint32 edcStatus: 4; // 4
		uint32 wckStatus: 4; // 8
		uint32 wcdrStatus: 4; // 12
		uint32 unknown1: 12;
		uint32 pmaPrbsclr: 1; // 28
		uint32 pmd0Prbsclr: 1; // 29
		uint32 pmd1Prbsclr: 1; // 30
		uint32 unknown2: 1;
	};
	uint32 val;
};

// MC_TRAIN_PRBSERR_1_D1
union McTrainPrbserr1D1 {
	struct {
		uint32 dbiStatus: 4; // 0
		uint32 edcStatus: 4; // 4
		uint32 wckStatus: 4; // 8
		uint32 wcdrStatus: 4; // 12
		uint32 unknown1: 12;
		uint32 pmaPrbsclr: 1; // 28
		uint32 pmd0Prbsclr: 1; // 29
		uint32 pmd1Prbsclr: 1; // 30
		uint32 unknown2: 1;
	};
	uint32 val;
};

// MC_TRAIN_PRBSERR_2_D0
union McTrainPrbserr2D0 {
	struct {
		uint32 ckStatus: 1; // 0
		uint32 ckbStatus: 1; // 1
		uint32 unknown1: 2;
		uint32 csStatus: 2; // 4
		uint32 unknown2: 2;
		uint32 ckeStatus: 1; // 8
		uint32 rasStatus: 1; // 9
		uint32 casStatus: 1; // 10
		uint32 weStatus: 1; // 11
		uint32 unknown3: 4;
		uint32 addrStatus: 10; // 16
		uint32 unknown4: 2;
		uint32 abiStatus: 1; // 28
		uint32 unknown5: 3;
	};
	uint32 val;
};

// MC_TRAIN_PRBSERR_2_D1
union McTrainPrbserr2D1 {
	struct {
		uint32 ckStatus: 1; // 0
		uint32 ckbStatus: 1; // 1
		uint32 unknown1: 2;
		uint32 csStatus: 2; // 4
		uint32 unknown2: 2;
		uint32 ckeStatus: 1; // 8
		uint32 rasStatus: 1; // 9
		uint32 casStatus: 1; // 10
		uint32 weStatus: 1; // 11
		uint32 unknown3: 4;
		uint32 addrStatus: 10; // 16
		uint32 unknown4: 2;
		uint32 abiStatus: 1; // 28
		uint32 unknown5: 3;
	};
	uint32 val;
};

// MC_TSM_DEBUG_BCNT0
union McTsmDebugBcnt0 {
	struct {
		uint32 byte0: 8; // 0
		uint32 byte1: 8; // 8
		uint32 byte2: 8; // 16
		uint32 byte3: 8; // 24
	};
	uint32 val;
};

// MC_TSM_DEBUG_BCNT1
union McTsmDebugBcnt1 {
	struct {
		uint32 byte0: 8; // 0
		uint32 byte1: 8; // 8
		uint32 byte2: 8; // 16
		uint32 byte3: 8; // 24
	};
	uint32 val;
};

// MC_TSM_DEBUG_BCNT10
union McTsmDebugBcnt10 {
	struct {
		uint32 byte0: 8; // 0
		uint32 byte1: 8; // 8
		uint32 byte2: 8; // 16
		uint32 byte3: 8; // 24
	};
	uint32 val;
};

// MC_TSM_DEBUG_BCNT2
union McTsmDebugBcnt2 {
	struct {
		uint32 byte0: 8; // 0
		uint32 byte1: 8; // 8
		uint32 byte2: 8; // 16
		uint32 byte3: 8; // 24
	};
	uint32 val;
};

// MC_TSM_DEBUG_BCNT3
union McTsmDebugBcnt3 {
	struct {
		uint32 byte0: 8; // 0
		uint32 byte1: 8; // 8
		uint32 byte2: 8; // 16
		uint32 byte3: 8; // 24
	};
	uint32 val;
};

// MC_TSM_DEBUG_BCNT4
union McTsmDebugBcnt4 {
	struct {
		uint32 byte0: 8; // 0
		uint32 byte1: 8; // 8
		uint32 byte2: 8; // 16
		uint32 byte3: 8; // 24
	};
	uint32 val;
};

// MC_TSM_DEBUG_BCNT5
union McTsmDebugBcnt5 {
	struct {
		uint32 byte0: 8; // 0
		uint32 byte1: 8; // 8
		uint32 byte2: 8; // 16
		uint32 byte3: 8; // 24
	};
	uint32 val;
};

// MC_TSM_DEBUG_BCNT6
union McTsmDebugBcnt6 {
	struct {
		uint32 byte0: 8; // 0
		uint32 byte1: 8; // 8
		uint32 byte2: 8; // 16
		uint32 byte3: 8; // 24
	};
	uint32 val;
};

// MC_TSM_DEBUG_BCNT7
union McTsmDebugBcnt7 {
	struct {
		uint32 byte0: 8; // 0
		uint32 byte1: 8; // 8
		uint32 byte2: 8; // 16
		uint32 byte3: 8; // 24
	};
	uint32 val;
};

// MC_TSM_DEBUG_BCNT8
union McTsmDebugBcnt8 {
	struct {
		uint32 byte0: 8; // 0
		uint32 byte1: 8; // 8
		uint32 byte2: 8; // 16
		uint32 byte3: 8; // 24
	};
	uint32 val;
};

// MC_TSM_DEBUG_BCNT9
union McTsmDebugBcnt9 {
	struct {
		uint32 byte0: 8; // 0
		uint32 byte1: 8; // 8
		uint32 byte2: 8; // 16
		uint32 byte3: 8; // 24
	};
	uint32 val;
};

// MC_TSM_DEBUG_BKPT
union McTsmDebugBkpt {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_TSM_DEBUG_FLAG
union McTsmDebugFlag {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_TSM_DEBUG_GCNT
union McTsmDebugGcnt {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_TSM_DEBUG_MISC
union McTsmDebugMisc {
	struct {
		uint32 flag: 8; // 0
		uint32 ncntRd: 4; // 8
		uint32 ncntWr: 4; // 12
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_TSM_DEBUG_ST01
union McTsmDebugSt01 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_TSM_DEBUG_ST23
union McTsmDebugSt23 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_TSM_DEBUG_ST45
union McTsmDebugSt45 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// MC_VM_AGP_BASE
union McVmAgpBase {
	struct {
		uint32 agpBase: 18; // 0
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_VM_AGP_BOT
union McVmAgpBot {
	struct {
		uint32 agpBot: 18; // 0
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_VM_AGP_TOP
union McVmAgpTop {
	struct {
		uint32 agpTop: 18; // 0
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_VM_DC_WRITE_CNTL
union McVmDcWriteCntl {
	struct {
		uint32 dcWriteHitRegion0Mode: 2; // 0
		uint32 dcWriteHitRegion1Mode: 2; // 2
		uint32 dcWriteHitRegion2Mode: 2; // 4
		uint32 dcWriteHitRegion3Mode: 2; // 6
		uint32 dcMemoryWriteLocal: 1; // 8
		uint32 dcMemoryWriteSystem: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// MC_VM_DC_WRITE_HIT_REGION_0_HIGH_ADDR
union McVmDcWriteHitRegion0HighAddr {
	struct {
		uint32 physicalAddress: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_VM_DC_WRITE_HIT_REGION_0_LOW_ADDR
union McVmDcWriteHitRegion0LowAddr {
	struct {
		uint32 physicalAddress: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_VM_DC_WRITE_HIT_REGION_1_HIGH_ADDR
union McVmDcWriteHitRegion1HighAddr {
	struct {
		uint32 physicalAddress: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_VM_DC_WRITE_HIT_REGION_1_LOW_ADDR
union McVmDcWriteHitRegion1LowAddr {
	struct {
		uint32 physicalAddress: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_VM_DC_WRITE_HIT_REGION_2_HIGH_ADDR
union McVmDcWriteHitRegion2HighAddr {
	struct {
		uint32 physicalAddress: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_VM_DC_WRITE_HIT_REGION_2_LOW_ADDR
union McVmDcWriteHitRegion2LowAddr {
	struct {
		uint32 physicalAddress: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_VM_DC_WRITE_HIT_REGION_3_HIGH_ADDR
union McVmDcWriteHitRegion3HighAddr {
	struct {
		uint32 physicalAddress: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_VM_DC_WRITE_HIT_REGION_3_LOW_ADDR
union McVmDcWriteHitRegion3LowAddr {
	struct {
		uint32 physicalAddress: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_VM_FB_LOCATION
union McVmFbLocation {
	struct {
		uint32 fbBase: 16; // 0
		uint32 fbTop: 16; // 16
	};
	uint32 val;
};

// MC_VM_FB_OFFSET
union McVmFbOffset {
	struct {
		uint32 fbOffset: 18; // 0
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_VM_MB_L1_TLB0_DEBUG
union McVmMbL1Tlb0Debug {
	struct {
		uint32 invalidateL1Tlb: 1; // 0
		uint32 unknown1: 7;
		uint32 sendFreeAtRtn: 1; // 8
		uint32 effectiveL1TlbSize: 3; // 9
		uint32 effectiveL1QueueSize: 3; // 12
		uint32 l1TlbDebug: 4; // 15
		uint32 unknown2: 13;
	};
	uint32 val;
};

// MC_VM_MB_L1_TLB0_STATUS
union McVmMbL1Tlb0Status {
	struct {
		uint32 busy: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// MC_VM_MB_L1_TLB1_STATUS
union McVmMbL1Tlb1Status {
	struct {
		uint32 busy: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// MC_VM_MB_L1_TLB2_DEBUG
union McVmMbL1Tlb2Debug {
	struct {
		uint32 invalidateL1Tlb: 1; // 0
		uint32 unknown1: 7;
		uint32 sendFreeAtRtn: 1; // 8
		uint32 effectiveL1TlbSize: 3; // 9
		uint32 effectiveL1QueueSize: 3; // 12
		uint32 l1TlbDebug: 4; // 15
		uint32 unknown2: 13;
	};
	uint32 val;
};

// MC_VM_MB_L1_TLB2_STATUS
union McVmMbL1Tlb2Status {
	struct {
		uint32 busy: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// MC_VM_MB_L1_TLB3_DEBUG
union McVmMbL1Tlb3Debug {
	struct {
		uint32 invalidateL1Tlb: 1; // 0
		uint32 unknown1: 7;
		uint32 sendFreeAtRtn: 1; // 8
		uint32 effectiveL1TlbSize: 3; // 9
		uint32 effectiveL1QueueSize: 3; // 12
		uint32 l1TlbDebug: 4; // 15
		uint32 unknown2: 13;
	};
	uint32 val;
};

// MC_VM_MB_L1_TLB3_STATUS
union McVmMbL1Tlb3Status {
	struct {
		uint32 busy: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// MC_VM_MB_L2ARBITER_L2_CREDITS
union McVmMbL2arbiterL2Credits {
	struct {
		uint32 l2IfCredits: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// MC_VM_MD_L1_TLB0_DEBUG
union McVmMdL1Tlb0Debug {
	struct {
		uint32 invalidateL1Tlb: 1; // 0
		uint32 unknown1: 7;
		uint32 sendFreeAtRtn: 1; // 8
		uint32 effectiveL1TlbSize: 3; // 9
		uint32 effectiveL1QueueSize: 3; // 12
		uint32 l1TlbDebug: 4; // 15
		uint32 unknown2: 13;
	};
	uint32 val;
};

// MC_VM_MD_L1_TLB0_STATUS
union McVmMdL1Tlb0Status {
	struct {
		uint32 busy: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// MC_VM_MD_L1_TLB1_DEBUG
union McVmMdL1Tlb1Debug {
	struct {
		uint32 invalidateL1Tlb: 1; // 0
		uint32 unknown1: 7;
		uint32 sendFreeAtRtn: 1; // 8
		uint32 effectiveL1TlbSize: 3; // 9
		uint32 effectiveL1QueueSize: 3; // 12
		uint32 l1TlbDebug: 4; // 15
		uint32 unknown2: 13;
	};
	uint32 val;
};

// MC_VM_MD_L1_TLB1_STATUS
union McVmMdL1Tlb1Status {
	struct {
		uint32 busy: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// MC_VM_MD_L1_TLB2_DEBUG
union McVmMdL1Tlb2Debug {
	struct {
		uint32 invalidateL1Tlb: 1; // 0
		uint32 unknown1: 7;
		uint32 sendFreeAtRtn: 1; // 8
		uint32 effectiveL1TlbSize: 3; // 9
		uint32 effectiveL1QueueSize: 3; // 12
		uint32 l1TlbDebug: 4; // 15
		uint32 unknown2: 13;
	};
	uint32 val;
};

// MC_VM_MD_L1_TLB2_STATUS
union McVmMdL1Tlb2Status {
	struct {
		uint32 busy: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// MC_VM_MD_L1_TLB3_DEBUG
union McVmMdL1Tlb3Debug {
	struct {
		uint32 invalidateL1Tlb: 1; // 0
		uint32 unknown1: 7;
		uint32 sendFreeAtRtn: 1; // 8
		uint32 effectiveL1TlbSize: 3; // 9
		uint32 effectiveL1QueueSize: 3; // 12
		uint32 l1TlbDebug: 4; // 15
		uint32 unknown2: 13;
	};
	uint32 val;
};

// MC_VM_MD_L1_TLB3_STATUS
union McVmMdL1Tlb3Status {
	struct {
		uint32 busy: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// MC_VM_MD_L2ARBITER_L2_CREDITS
union McVmMdL2arbiterL2Credits {
	struct {
		uint32 l2IfCredits: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// MC_VM_MX_L1_TLB_CNTL
union McVmMxL1TlbCntl {
	struct {
		uint32 enableL1Tlb: 1; // 0
		uint32 enableL1FragmentProcessing: 1; // 1
		uint32 unknown1: 1;
		uint32 systemAccessMode: 2; // 3
		uint32 systemApertureUnmappedAccess: 1; // 5
		uint32 enableAdvancedDriverModel: 1; // 6
		uint32 ecoBits: 4; // 7
		uint32 unknown2: 21;
	};
	uint32 val;
};

// MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR
union McVmSystemApertureDefaultAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_VM_SYSTEM_APERTURE_HIGH_ADDR
union McVmSystemApertureHighAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_VM_SYSTEM_APERTURE_LOW_ADDR
union McVmSystemApertureLowAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_WR_CB
union McWrCb {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxBurst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_WR_DB
union McWrDb {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxBurst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_WR_GRP_EXT
union McWrGrpExt {
	struct {
		uint32 dbsten0: 4; // 0
		uint32 tc0: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_WR_GRP_GFX
union McWrGrpGfx {
	struct {
		uint32 cp: 4; // 0
		uint32 unknown1: 8;
		uint32 xdma: 4; // 12
		uint32 xdmam: 4; // 16
		uint32 unknown2: 12;
	};
	uint32 val;
};

// MC_WR_GRP_LCL
union McWrGrpLcl {
	struct {
		uint32 cb0: 4; // 0
		uint32 cbcmask0: 4; // 4
		uint32 cbfmask0: 4; // 8
		uint32 db0: 4; // 12
		uint32 dbhtile0: 4; // 16
		uint32 sx0: 4; // 20
		uint32 unknown1: 4;
		uint32 cbimmed0: 4; // 28
	};
	uint32 val;
};

// MC_WR_GRP_OTH
union McWrGrpOth {
	struct {
		uint32 uvdExt0: 4; // 0
		uint32 unknown1: 4;
		uint32 hdp: 4; // 8
		uint32 sem: 4; // 12
		uint32 umc: 4; // 16
		uint32 uvd: 4; // 20
		uint32 xdp: 4; // 24
		uint32 uvdExt1: 4; // 28
	};
	uint32 val;
};

// MC_WR_GRP_SYS
union McWrGrpSys {
	struct {
		uint32 ih: 4; // 0
		uint32 mcif: 4; // 4
		uint32 rlc: 4; // 8
		uint32 unknown1: 8;
		uint32 smu: 4; // 20
		uint32 vce: 4; // 24
		uint32 vceu: 4; // 28
	};
	uint32 val;
};

// MC_WR_HUB
union McWrHub {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxBurst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_WR_TC0
union McWrTc0 {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxBurst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_WR_TC1
union McWrTc1 {
	struct {
		uint32 enable: 1; // 0
		uint32 prescale: 2; // 1
		uint32 blackoutExempt: 1; // 3
		uint32 stallMode: 2; // 4
		uint32 stallOverride: 1; // 6
		uint32 maxBurst: 4; // 7
		uint32 lazyTimer: 4; // 11
		uint32 stallOverrideWtm: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_XBAR_ADDR_DEC
union McXbarAddrDec {
	struct {
		uint32 noDivBy3: 1; // 0
		uint32 gecc: 1; // 1
		uint32 rbSplit: 1; // 2
		uint32 rbSplitColhi: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// MC_XBAR_ARB
union McXbarArb {
	struct {
		uint32 hubrdHighest: 1; // 0
		uint32 disableHubStallHighest: 1; // 1
		uint32 breakBurstCidChange: 1; // 2
		uint32 unknown1: 29;
	};
	uint32 val;
};

// MC_XBAR_ARB_MAX_BURST
union McXbarArbMaxBurst {
	struct {
		uint32 rdPort0: 4; // 0
		uint32 rdPort1: 4; // 4
		uint32 rdPort2: 4; // 8
		uint32 rdPort3: 4; // 12
		uint32 wrPort0: 4; // 16
		uint32 wrPort1: 4; // 20
		uint32 wrPort2: 4; // 24
		uint32 wrPort3: 4; // 28
	};
	uint32 val;
};

// MC_XBAR_CHTRIREMAP
union McXbarChtriremap {
	struct {
		uint32 ch0: 2; // 0
		uint32 ch1: 2; // 2
		uint32 ch2: 2; // 4
		uint32 unknown1: 26;
	};
	uint32 val;
};

// MC_XBAR_PERF_MON_CNTL0
union McXbarPerfMonCntl0 {
	struct {
		uint32 startThresh: 12; // 0
		uint32 stopThresh: 12; // 12
		uint32 startMode: 2; // 24
		uint32 stopMode: 2; // 26
		uint32 allowWrap: 1; // 28
		uint32 unknown1: 3;
	};
	uint32 val;
};

// MC_XBAR_PERF_MON_CNTL1
union McXbarPerfMonCntl1 {
	struct {
		uint32 threshCntrId: 8; // 0
		uint32 startTrigId: 8; // 8
		uint32 stopTrigId: 8; // 16
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_XBAR_PERF_MON_CNTL2
union McXbarPerfMonCntl2 {
	struct {
		uint32 mon0Id: 8; // 0
		uint32 mon1Id: 8; // 8
		uint32 mon2Id: 8; // 16
		uint32 mon3Id: 8; // 24
	};
	uint32 val;
};

// MC_XBAR_PERF_MON_MAX_THSH
union McXbarPerfMonMaxThsh {
	struct {
		uint32 mon0: 8; // 0
		uint32 mon1: 8; // 8
		uint32 mon2: 8; // 16
		uint32 mon3: 8; // 24
	};
	uint32 val;
};

// MC_XBAR_PERF_MON_RSLT0
union McXbarPerfMonRslt0 {
	struct {
		uint32 count: 32; // 0
	};
	uint32 val;
};

// MC_XBAR_PERF_MON_RSLT1
union McXbarPerfMonRslt1 {
	struct {
		uint32 count: 32; // 0
	};
	uint32 val;
};

// MC_XBAR_PERF_MON_RSLT2
union McXbarPerfMonRslt2 {
	struct {
		uint32 count: 32; // 0
	};
	uint32 val;
};

// MC_XBAR_PERF_MON_RSLT3
union McXbarPerfMonRslt3 {
	struct {
		uint32 count: 32; // 0
	};
	uint32 val;
};

// MC_XBAR_RDREQ_CREDIT
union McXbarRdreqCredit {
	struct {
		uint32 out0: 8; // 0
		uint32 out1: 8; // 8
		uint32 out2: 8; // 16
		uint32 out3: 8; // 24
	};
	uint32 val;
};

// MC_XBAR_RDREQ_PRI_CREDIT
union McXbarRdreqPriCredit {
	struct {
		uint32 out0: 8; // 0
		uint32 out1: 8; // 8
		uint32 out2: 8; // 16
		uint32 out3: 8; // 24
	};
	uint32 val;
};

// MC_XBAR_RDRET_CREDIT1
union McXbarRdretCredit1 {
	struct {
		uint32 out0: 8; // 0
		uint32 out1: 8; // 8
		uint32 out2: 8; // 16
		uint32 out3: 8; // 24
	};
	uint32 val;
};

// MC_XBAR_RDRET_CREDIT2
union McXbarRdretCredit2 {
	struct {
		uint32 out4: 8; // 0
		uint32 out5: 8; // 8
		uint32 hubLpRdretSkid: 8; // 16
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MC_XBAR_RDRET_PRI_CREDIT1
union McXbarRdretPriCredit1 {
	struct {
		uint32 out0: 8; // 0
		uint32 out1: 8; // 8
		uint32 out2: 8; // 16
		uint32 out3: 8; // 24
	};
	uint32 val;
};

// MC_XBAR_RDRET_PRI_CREDIT2
union McXbarRdretPriCredit2 {
	struct {
		uint32 out4: 8; // 0
		uint32 out5: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_XBAR_REMOTE
union McXbarRemote {
	struct {
		uint32 wrreqEnGoq: 1; // 0
		uint32 rdreqEnGoq: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// MC_XBAR_SPARE0
union McXbarSpare0 {
	struct {
		uint32 bit: 32; // 0
	};
	uint32 val;
};

// MC_XBAR_SPARE1
union McXbarSpare1 {
	struct {
		uint32 bit: 32; // 0
	};
	uint32 val;
};

// MC_XBAR_TWOCHAN
union McXbarTwochan {
	struct {
		uint32 disableOneport: 1; // 0
		uint32 ch0: 2; // 1
		uint32 ch1: 2; // 3
		uint32 unknown1: 27;
	};
	uint32 val;
};

// MC_XBAR_WRREQ_CREDIT
union McXbarWrreqCredit {
	struct {
		uint32 out0: 8; // 0
		uint32 out1: 8; // 8
		uint32 out2: 8; // 16
		uint32 out3: 8; // 24
	};
	uint32 val;
};

// MC_XBAR_WRRET_CREDIT1
union McXbarWrretCredit1 {
	struct {
		uint32 out0: 8; // 0
		uint32 out1: 8; // 8
		uint32 out2: 8; // 16
		uint32 out3: 8; // 24
	};
	uint32 val;
};

// MC_XBAR_WRRET_CREDIT2
union McXbarWrretCredit2 {
	struct {
		uint32 out4: 8; // 0
		uint32 out5: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG0
union McXpbClgCfg0 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG1
union McXpbClgCfg1 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG10
union McXpbClgCfg10 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG11
union McXpbClgCfg11 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG12
union McXpbClgCfg12 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG13
union McXpbClgCfg13 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG14
union McXpbClgCfg14 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG15
union McXpbClgCfg15 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG16
union McXpbClgCfg16 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG17
union McXpbClgCfg17 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG18
union McXpbClgCfg18 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG19
union McXpbClgCfg19 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG2
union McXpbClgCfg2 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG20
union McXpbClgCfg20 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG21
union McXpbClgCfg21 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG22
union McXpbClgCfg22 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG23
union McXpbClgCfg23 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG24
union McXpbClgCfg24 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG25
union McXpbClgCfg25 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG26
union McXpbClgCfg26 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG27
union McXpbClgCfg27 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG28
union McXpbClgCfg28 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG29
union McXpbClgCfg29 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG3
union McXpbClgCfg3 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG30
union McXpbClgCfg30 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG31
union McXpbClgCfg31 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG32
union McXpbClgCfg32 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG33
union McXpbClgCfg33 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG34
union McXpbClgCfg34 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG35
union McXpbClgCfg35 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG36
union McXpbClgCfg36 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG4
union McXpbClgCfg4 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG5
union McXpbClgCfg5 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG6
union McXpbClgCfg6 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG7
union McXpbClgCfg7 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG8
union McXpbClgCfg8 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_CFG9
union McXpbClgCfg9 {
	struct {
		uint32 wcbNum: 4; // 0
		uint32 lbType: 3; // 4
		uint32 p2pBar: 3; // 7
		uint32 hostFlush: 4; // 10
		uint32 sideFlush: 4; // 14
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_CLG_EXTRA
union McXpbClgExtra {
	struct {
		uint32 cmp0: 8; // 0
		uint32 msk0: 8; // 8
		uint32 vld0: 1; // 16
		uint32 cmp1: 8; // 17
		uint32 vld1: 1; // 25
		uint32 unknown1: 6;
	};
	uint32 val;
};

// MC_XPB_CLG_EXTRA_RD
union McXpbClgExtraRd {
	struct {
		uint32 cmp0: 8; // 0
		uint32 msk0: 8; // 8
		uint32 vld0: 1; // 16
		uint32 cmp1: 8; // 17
		uint32 vld1: 1; // 25
		uint32 unknown1: 6;
	};
	uint32 val;
};

// MC_XPB_CLK_GAT
union McXpbClkGat {
	struct {
		uint32 ondly: 6; // 0
		uint32 offdly: 6; // 6
		uint32 rdydly: 6; // 12
		uint32 enable: 1; // 18
		uint32 memLsEnable: 1; // 19
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_XPB_INTF_CFG
union McXpbIntfCfg {
	struct {
		uint32 rpbWrreqCrd: 8; // 0
		uint32 mcWrretAsk: 8; // 8
		uint32 xspReqCrd: 7; // 16
		uint32 bifRegSnoopSel: 1; // 23
		uint32 bifRegSnoopVal: 1; // 24
		uint32 bifMemSnoopSel: 1; // 25
		uint32 bifMemSnoopVal: 1; // 26
		uint32 xspSnoopSel: 2; // 27
		uint32 xspSnoopVal: 1; // 29
		uint32 xspOrderingSel: 1; // 30
		uint32 xspOrderingVal: 1; // 31
	};
	uint32 val;
};

// MC_XPB_INTF_CFG2
union McXpbIntfCfg2 {
	struct {
		uint32 rpbRdreqCrd: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MC_XPB_INTF_STS
union McXpbIntfSts {
	struct {
		uint32 rpbWrreqCrd: 8; // 0
		uint32 xspReqCrd: 7; // 8
		uint32 hopDataBufFull: 1; // 15
		uint32 hopAttrBufFull: 1; // 16
		uint32 cnsBufFull: 1; // 17
		uint32 cnsBufBusy: 1; // 18
		uint32 rpbRdreqCrd: 8; // 19
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_LB_ADDR
union McXpbLbAddr {
	struct {
		uint32 cmp0: 10; // 0
		uint32 mask0: 10; // 10
		uint32 cmp1: 6; // 20
		uint32 mask1: 6; // 26
	};
	uint32 val;
};

// MC_XPB_MAP_INVERT_FLUSH_NUM_LSB
union McXpbMapInvertFlushNumLsb {
	struct {
		uint32 alterFlushNum: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_XPB_MISC_CFG
union McXpbMiscCfg {
	struct {
		uint32 fieldname0: 8; // 0
		uint32 fieldname1: 8; // 8
		uint32 fieldname2: 8; // 16
		uint32 fieldname3: 7; // 24
		uint32 triggername: 1; // 31
	};
	uint32 val;
};

// MC_XPB_P2P_BAR0
union McXpbP2pBar0 {
	struct {
		uint32 hostFlush: 4; // 0
		uint32 regSysBar: 4; // 4
		uint32 memSysBar: 4; // 8
		uint32 valid: 1; // 12
		uint32 sendDis: 1; // 13
		uint32 compressDis: 1; // 14
		uint32 reserved: 1; // 15
		uint32 address: 16; // 16
	};
	uint32 val;
};

// MC_XPB_P2P_BAR1
union McXpbP2pBar1 {
	struct {
		uint32 hostFlush: 4; // 0
		uint32 regSysBar: 4; // 4
		uint32 memSysBar: 4; // 8
		uint32 valid: 1; // 12
		uint32 sendDis: 1; // 13
		uint32 compressDis: 1; // 14
		uint32 reserved: 1; // 15
		uint32 address: 16; // 16
	};
	uint32 val;
};

// MC_XPB_P2P_BAR2
union McXpbP2pBar2 {
	struct {
		uint32 hostFlush: 4; // 0
		uint32 regSysBar: 4; // 4
		uint32 memSysBar: 4; // 8
		uint32 valid: 1; // 12
		uint32 sendDis: 1; // 13
		uint32 compressDis: 1; // 14
		uint32 reserved: 1; // 15
		uint32 address: 16; // 16
	};
	uint32 val;
};

// MC_XPB_P2P_BAR3
union McXpbP2pBar3 {
	struct {
		uint32 hostFlush: 4; // 0
		uint32 regSysBar: 4; // 4
		uint32 memSysBar: 4; // 8
		uint32 valid: 1; // 12
		uint32 sendDis: 1; // 13
		uint32 compressDis: 1; // 14
		uint32 reserved: 1; // 15
		uint32 address: 16; // 16
	};
	uint32 val;
};

// MC_XPB_P2P_BAR4
union McXpbP2pBar4 {
	struct {
		uint32 hostFlush: 4; // 0
		uint32 regSysBar: 4; // 4
		uint32 memSysBar: 4; // 8
		uint32 valid: 1; // 12
		uint32 sendDis: 1; // 13
		uint32 compressDis: 1; // 14
		uint32 reserved: 1; // 15
		uint32 address: 16; // 16
	};
	uint32 val;
};

// MC_XPB_P2P_BAR5
union McXpbP2pBar5 {
	struct {
		uint32 hostFlush: 4; // 0
		uint32 regSysBar: 4; // 4
		uint32 memSysBar: 4; // 8
		uint32 valid: 1; // 12
		uint32 sendDis: 1; // 13
		uint32 compressDis: 1; // 14
		uint32 reserved: 1; // 15
		uint32 address: 16; // 16
	};
	uint32 val;
};

// MC_XPB_P2P_BAR6
union McXpbP2pBar6 {
	struct {
		uint32 hostFlush: 4; // 0
		uint32 regSysBar: 4; // 4
		uint32 memSysBar: 4; // 8
		uint32 valid: 1; // 12
		uint32 sendDis: 1; // 13
		uint32 compressDis: 1; // 14
		uint32 reserved: 1; // 15
		uint32 address: 16; // 16
	};
	uint32 val;
};

// MC_XPB_P2P_BAR7
union McXpbP2pBar7 {
	struct {
		uint32 hostFlush: 4; // 0
		uint32 regSysBar: 4; // 4
		uint32 memSysBar: 4; // 8
		uint32 valid: 1; // 12
		uint32 sendDis: 1; // 13
		uint32 compressDis: 1; // 14
		uint32 reserved: 1; // 15
		uint32 address: 16; // 16
	};
	uint32 val;
};

// MC_XPB_P2P_BAR_CFG
union McXpbP2pBarCfg {
	struct {
		uint32 addrSize: 4; // 0
		uint32 sendBar: 2; // 4
		uint32 snoop: 1; // 6
		uint32 sendDis: 1; // 7
		uint32 compressDis: 1; // 8
		uint32 updateDis: 1; // 9
		uint32 regbarFromSysbar: 1; // 10
		uint32 rdEn: 1; // 11
		uint32 atcTranslated: 1; // 12
		uint32 unknown1: 19;
	};
	uint32 val;
};

// MC_XPB_P2P_BAR_DEBUG
union McXpbP2pBarDebug {
	struct {
		uint32 sel: 8; // 0
		uint32 hostFlush: 4; // 8
		uint32 memSysBar: 4; // 12
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_XPB_P2P_BAR_DELTA_ABOVE
union McXpbP2pBarDeltaAbove {
	struct {
		uint32 en: 8; // 0
		uint32 delta: 20; // 8
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_XPB_P2P_BAR_DELTA_BELOW
union McXpbP2pBarDeltaBelow {
	struct {
		uint32 en: 8; // 0
		uint32 delta: 20; // 8
		uint32 unknown1: 4;
	};
	uint32 val;
};

// MC_XPB_P2P_BAR_SETUP
union McXpbP2pBarSetup {
	struct {
		uint32 sel: 8; // 0
		uint32 regSysBar: 4; // 8
		uint32 valid: 1; // 12
		uint32 sendDis: 1; // 13
		uint32 compressDis: 1; // 14
		uint32 reserved: 1; // 15
		uint32 address: 16; // 16
	};
	uint32 val;
};

// MC_XPB_PEER_SYS_BAR0
union McXpbPeerSysBar0 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_PEER_SYS_BAR1
union McXpbPeerSysBar1 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_PEER_SYS_BAR2
union McXpbPeerSysBar2 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_PEER_SYS_BAR3
union McXpbPeerSysBar3 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_PEER_SYS_BAR4
union McXpbPeerSysBar4 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_PEER_SYS_BAR5
union McXpbPeerSysBar5 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_PEER_SYS_BAR6
union McXpbPeerSysBar6 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_PEER_SYS_BAR7
union McXpbPeerSysBar7 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_PEER_SYS_BAR8
union McXpbPeerSysBar8 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_PEER_SYS_BAR9
union McXpbPeerSysBar9 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_PERF_KNOBS
union McXpbPerfKnobs {
	struct {
		uint32 cnsFifoDepth: 6; // 0
		uint32 wcbHstFifoDepth: 6; // 6
		uint32 wcbSidFifoDepth: 6; // 12
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_PIPE_STS
union McXpbPipeSts {
	struct {
		uint32 wcbAnyPbuf: 1; // 0
		uint32 wcbHstDataBufCnt: 7; // 1
		uint32 wcbSidDataBufCnt: 7; // 8
		uint32 wcbHstRdPtrBufFull: 1; // 15
		uint32 wcbSidRdPtrBufFull: 1; // 16
		uint32 wcbHstReqFifoFull: 1; // 17
		uint32 wcbSidReqFifoFull: 1; // 18
		uint32 wcbHstReqObufFull: 1; // 19
		uint32 wcbSidReqObufFull: 1; // 20
		uint32 wcbHstDataObufFull: 1; // 21
		uint32 wcbSidDataObufFull: 1; // 22
		uint32 retBufFull: 1; // 23
		uint32 xpbClkBusyBits: 8; // 24
	};
	uint32 val;
};

// MC_XPB_RTR_DEST_MAP0
union McXpbRtrDestMap0 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_RTR_DEST_MAP1
union McXpbRtrDestMap1 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_RTR_DEST_MAP2
union McXpbRtrDestMap2 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_RTR_DEST_MAP3
union McXpbRtrDestMap3 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_RTR_DEST_MAP4
union McXpbRtrDestMap4 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_RTR_DEST_MAP5
union McXpbRtrDestMap5 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_RTR_DEST_MAP6
union McXpbRtrDestMap6 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_RTR_DEST_MAP7
union McXpbRtrDestMap7 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_RTR_DEST_MAP8
union McXpbRtrDestMap8 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_RTR_DEST_MAP9
union McXpbRtrDestMap9 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_RTR_SRC_APRTR0
union McXpbRtrSrcAprtr0 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_XPB_RTR_SRC_APRTR1
union McXpbRtrSrcAprtr1 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_XPB_RTR_SRC_APRTR2
union McXpbRtrSrcAprtr2 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_XPB_RTR_SRC_APRTR3
union McXpbRtrSrcAprtr3 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_XPB_RTR_SRC_APRTR4
union McXpbRtrSrcAprtr4 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_XPB_RTR_SRC_APRTR5
union McXpbRtrSrcAprtr5 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_XPB_RTR_SRC_APRTR6
union McXpbRtrSrcAprtr6 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_XPB_RTR_SRC_APRTR7
union McXpbRtrSrcAprtr7 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_XPB_RTR_SRC_APRTR8
union McXpbRtrSrcAprtr8 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_XPB_RTR_SRC_APRTR9
union McXpbRtrSrcAprtr9 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_XPB_STICKY
union McXpbSticky {
	struct {
		uint32 bits: 32; // 0
	};
	uint32 val;
};

// MC_XPB_STICKY_W1C
union McXpbStickyW1c {
	struct {
		uint32 bits: 32; // 0
	};
	uint32 val;
};

// MC_XPB_SUB_CTRL
union McXpbSubCtrl {
	struct {
		uint32 wrreqBypassXpb: 1; // 0
		uint32 stallCnsRtrReq: 1; // 1
		uint32 stallRtrRpbWrreq: 1; // 2
		uint32 stallRtrMapReq: 1; // 3
		uint32 stallMapWcbReq: 1; // 4
		uint32 stallWcbSidReq: 1; // 5
		uint32 stallMcXspReqSend: 1; // 6
		uint32 stallWcbHstReq: 1; // 7
		uint32 stallHstHopReq: 1; // 8
		uint32 stallXpbRpbReqAttr: 1; // 9
		uint32 resetCns: 1; // 10
		uint32 resetRtr: 1; // 11
		uint32 resetRet: 1; // 12
		uint32 resetMap: 1; // 13
		uint32 resetWcb: 1; // 14
		uint32 resetHst: 1; // 15
		uint32 resetHop: 1; // 16
		uint32 resetSid: 1; // 17
		uint32 resetSrb: 1; // 18
		uint32 resetCgr: 1; // 19
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_XPB_UNC_THRESH_HST
union McXpbUncThreshHst {
	struct {
		uint32 changePref: 6; // 0
		uint32 strongPref: 6; // 6
		uint32 useUnfull: 6; // 12
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_UNC_THRESH_SID
union McXpbUncThreshSid {
	struct {
		uint32 changePref: 6; // 0
		uint32 strongPref: 6; // 6
		uint32 useUnfull: 6; // 12
		uint32 unknown1: 14;
	};
	uint32 val;
};

// MC_XPB_WCB_CFG
union McXpbWcbCfg {
	struct {
		uint32 timeout: 16; // 0
		uint32 hstMax: 2; // 16
		uint32 sidMax: 2; // 18
		uint32 unknown1: 12;
	};
	uint32 val;
};

// MC_XPB_WCB_STS
union McXpbWcbSts {
	struct {
		uint32 pbufVld: 16; // 0
		uint32 wcbHstDataBufCnt: 7; // 16
		uint32 wcbSidDataBufCnt: 7; // 23
		uint32 unknown1: 2;
	};
	uint32 val;
};

// MC_XPB_XDMA_PEER_SYS_BAR0
union McXpbXdmaPeerSysBar0 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_XDMA_PEER_SYS_BAR1
union McXpbXdmaPeerSysBar1 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_XDMA_PEER_SYS_BAR2
union McXpbXdmaPeerSysBar2 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_XDMA_PEER_SYS_BAR3
union McXpbXdmaPeerSysBar3 {
	struct {
		uint32 valid: 1; // 0
		uint32 sideOk: 1; // 1
		uint32 addr: 25; // 2
		uint32 unknown1: 5;
	};
	uint32 val;
};

// MC_XPB_XDMA_RTR_DEST_MAP0
union McXpbXdmaRtrDestMap0 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_XDMA_RTR_DEST_MAP1
union McXpbXdmaRtrDestMap1 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_XDMA_RTR_DEST_MAP2
union McXpbXdmaRtrDestMap2 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_XDMA_RTR_DEST_MAP3
union McXpbXdmaRtrDestMap3 {
	struct {
		uint32 nmr: 1; // 0
		uint32 destOffset: 19; // 1
		uint32 destSel: 4; // 20
		uint32 destSelRpb: 1; // 24
		uint32 sideOk: 1; // 25
		uint32 aprtrSize: 5; // 26
		uint32 unknown1: 1;
	};
	uint32 val;
};

// MC_XPB_XDMA_RTR_SRC_APRTR0
union McXpbXdmaRtrSrcAprtr0 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_XPB_XDMA_RTR_SRC_APRTR1
union McXpbXdmaRtrSrcAprtr1 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_XPB_XDMA_RTR_SRC_APRTR2
union McXpbXdmaRtrSrcAprtr2 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MC_XPB_XDMA_RTR_SRC_APRTR3
union McXpbXdmaRtrSrcAprtr3 {
	struct {
		uint32 baseAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MPLL_AD_FUNC_CNTL
union MpllAdFuncCntl {
	struct {
		uint32 yclkPostDiv: 3; // 0
		uint32 spare: 29; // 3
	};
	uint32 val;
};

// MPLL_AD_STATUS
union MpllAdStatus {
	struct {
		uint32 vctrladc: 3; // 0
		uint32 unknown1: 1;
		uint32 testFbdivFrac: 3; // 4
		uint32 testFbdivInt: 10; // 7
		uint32 ointReset: 1; // 17
		uint32 freqLock: 1; // 18
		uint32 freqUnlockSticky: 1; // 19
		uint32 unknown2: 12;
	};
	uint32 val;
};

// MPLL_CNTL_MODE
union MpllCntlMode {
	struct {
		uint32 instrDelay: 8; // 0
		uint32 mpllSwDirControl: 1; // 8
		uint32 unknown1: 2;
		uint32 mpllMclkSel: 1; // 11
		uint32 spare1: 1; // 12
		uint32 qdr: 1; // 13
		uint32 mpllCtlreq: 1; // 14
		uint32 unknown2: 1;
		uint32 mpllChgStatus: 1; // 16
		uint32 forceTestmode: 1; // 17
		uint32 unknown3: 2;
		uint32 fastLockEn: 1; // 20
		uint32 fastLockCntrl: 2; // 21
		uint32 spare2: 1; // 23
		uint32 ssSsen: 2; // 24
		uint32 ssDsmodeEn: 1; // 26
		uint32 vtoiBiasCntrl: 1; // 27
		uint32 spare3: 3; // 28
		uint32 globalMpllReset: 1; // 31
	};
	uint32 val;
};

// MPLL_CONTROL
union MpllControl {
	struct {
		uint32 gddrPwron: 1; // 0
		uint32 refclkPwron: 1; // 1
		uint32 pllBufPwronTx: 1; // 2
		uint32 unknown1: 9;
		uint32 adBgPwron: 1; // 12
		uint32 adPllPwron: 1; // 13
		uint32 adPllReset: 1; // 14
		uint32 spareAd0: 1; // 15
		uint32 dq0_0BgPwron: 1; // 16
		uint32 dq0_0PllPwron: 1; // 17
		uint32 dq0_0PllReset: 1; // 18
		uint32 spareDq0_0: 1; // 19
		uint32 dq0_1BgPwron: 1; // 20
		uint32 dq0_1PllPwron: 1; // 21
		uint32 dq0_1PllReset: 1; // 22
		uint32 spareDq0_1: 1; // 23
		uint32 dq1_0BgPwron: 1; // 24
		uint32 dq1_0PllPwron: 1; // 25
		uint32 dq1_0PllReset: 1; // 26
		uint32 spareDq1_0: 1; // 27
		uint32 dq1_1BgPwron: 1; // 28
		uint32 dq1_1PllPwron: 1; // 29
		uint32 dq1_1PllReset: 1; // 30
		uint32 spareDq1_1: 1; // 31
	};
	uint32 val;
};

// MPLL_DQ_0_0_STATUS
union MpllDq0_0Status {
	struct {
		uint32 vctrladc: 3; // 0
		uint32 unknown1: 1;
		uint32 testFbdivFrac: 3; // 4
		uint32 testFbdivInt: 10; // 7
		uint32 ointReset: 1; // 17
		uint32 freqLock: 1; // 18
		uint32 freqUnlockSticky: 1; // 19
		uint32 unknown2: 12;
	};
	uint32 val;
};

// MPLL_DQ_0_1_STATUS
union MpllDq0_1Status {
	struct {
		uint32 vctrladc: 3; // 0
		uint32 unknown1: 1;
		uint32 testFbdivFrac: 3; // 4
		uint32 testFbdivInt: 10; // 7
		uint32 ointReset: 1; // 17
		uint32 freqLock: 1; // 18
		uint32 freqUnlockSticky: 1; // 19
		uint32 unknown2: 12;
	};
	uint32 val;
};

// MPLL_DQ_1_0_STATUS
union MpllDq1_0Status {
	struct {
		uint32 vctrladc: 3; // 0
		uint32 unknown1: 1;
		uint32 testFbdivFrac: 3; // 4
		uint32 testFbdivInt: 10; // 7
		uint32 ointReset: 1; // 17
		uint32 freqLock: 1; // 18
		uint32 freqUnlockSticky: 1; // 19
		uint32 unknown2: 12;
	};
	uint32 val;
};

// MPLL_DQ_1_1_STATUS
union MpllDq1_1Status {
	struct {
		uint32 vctrladc: 3; // 0
		uint32 unknown1: 1;
		uint32 testFbdivFrac: 3; // 4
		uint32 testFbdivInt: 10; // 7
		uint32 ointReset: 1; // 17
		uint32 freqLock: 1; // 18
		uint32 freqUnlockSticky: 1; // 19
		uint32 unknown2: 12;
	};
	uint32 val;
};

// MPLL_DQ_FUNC_CNTL
union MpllDqFuncCntl {
	struct {
		uint32 yclkPostDiv: 3; // 0
		uint32 spare0: 1; // 3
		uint32 yclkSel: 1; // 4
		uint32 spare: 27; // 5
	};
	uint32 val;
};

// MPLL_FUNC_CNTL
union MpllFuncCntl {
	struct {
		uint32 unknown1: 5;
		uint32 spare0: 1; // 5
		uint32 unknown2: 2;
		uint32 bg100adj: 4; // 8
		uint32 unknown3: 4;
		uint32 bg135adj: 4; // 16
		uint32 bwctrl: 8; // 20
		uint32 unknown4: 2;
		uint32 regBias: 2; // 30
	};
	uint32 val;
};

// MPLL_FUNC_CNTL_1
union MpllFuncCntl1 {
	struct {
		uint32 vcoMode: 2; // 0
		uint32 spare0: 2; // 2
		uint32 clkfrac: 12; // 4
		uint32 clkf: 12; // 16
		uint32 spare1: 4; // 28
	};
	uint32 val;
};

// MPLL_FUNC_CNTL_2
union MpllFuncCntl2 {
	struct {
		uint32 vctrladcEn: 1; // 0
		uint32 testVctlEn: 1; // 1
		uint32 resetEn: 1; // 2
		uint32 testBypclkEn: 1; // 3
		uint32 testBypclkSrc: 1; // 4
		uint32 testFbdivFracBypass: 1; // 5
		uint32 testBypmclk: 1; // 6
		uint32 mpllUnlockClear: 1; // 7
		uint32 testVctlCntrl: 1; // 8
		uint32 testFbdivSscBypass: 1; // 9
		uint32 resetTimer: 2; // 10
		uint32 pfdResetCntrl: 2; // 12
		uint32 unknown1: 3;
		uint32 backup2: 3; // 17
		uint32 lfCntrl: 7; // 20
		uint32 backup: 5; // 27
	};
	uint32 val;
};

// MPLL_SEQ_UCODE_1
union MpllSeqUcode1 {
	struct {
		uint32 instr0: 4; // 0
		uint32 instr1: 4; // 4
		uint32 instr2: 4; // 8
		uint32 instr3: 4; // 12
		uint32 instr4: 4; // 16
		uint32 instr5: 4; // 20
		uint32 instr6: 4; // 24
		uint32 instr7: 4; // 28
	};
	uint32 val;
};

// MPLL_SEQ_UCODE_2
union MpllSeqUcode2 {
	struct {
		uint32 instr8: 4; // 0
		uint32 instr9: 4; // 4
		uint32 instr10: 4; // 8
		uint32 instr11: 4; // 12
		uint32 instr12: 4; // 16
		uint32 instr13: 4; // 20
		uint32 instr14: 4; // 24
		uint32 instr15: 4; // 28
	};
	uint32 val;
};

// MPLL_SS1
union MpllSs1 {
	struct {
		uint32 clkv: 26; // 0
		uint32 spare: 6; // 26
	};
	uint32 val;
};

// MPLL_SS2
union MpllSs2 {
	struct {
		uint32 clks: 12; // 0
		uint32 spare: 20; // 12
	};
	uint32 val;
};

// MPLL_TIME
union MpllTime {
	struct {
		uint32 mpllLockTime: 16; // 0
		uint32 mpllResetTime: 16; // 16
	};
	uint32 val;
};

// VM_CONTEXT0_CNTL
union VmContext0Cntl {
	struct {
		uint32 enableContext: 1; // 0
		uint32 pageTableDepth: 2; // 1
		uint32 rangeProtectionFaultEnableInterrupt: 1; // 3
		uint32 rangeProtectionFaultEnableDefault: 1; // 4
		uint32 unknown1: 1;
		uint32 dummyPageProtectionFaultEnableInterrupt: 1; // 6
		uint32 dummyPageProtectionFaultEnableDefault: 1; // 7
		uint32 unknown2: 1;
		uint32 pde0ProtectionFaultEnableInterrupt: 1; // 9
		uint32 pde0ProtectionFaultEnableDefault: 1; // 10
		uint32 pde0ProtectionFaultEnableSave: 1; // 11
		uint32 validProtectionFaultEnableInterrupt: 1; // 12
		uint32 validProtectionFaultEnableDefault: 1; // 13
		uint32 validProtectionFaultEnableSave: 1; // 14
		uint32 readProtectionFaultEnableInterrupt: 1; // 15
		uint32 readProtectionFaultEnableDefault: 1; // 16
		uint32 readProtectionFaultEnableSave: 1; // 17
		uint32 writeProtectionFaultEnableInterrupt: 1; // 18
		uint32 writeProtectionFaultEnableDefault: 1; // 19
		uint32 writeProtectionFaultEnableSave: 1; // 20
		uint32 privilegedProtectionFaultEnableInterrupt: 1; // 21
		uint32 privilegedProtectionFaultEnableDefault: 1; // 22
		uint32 privilegedProtectionFaultEnableSave: 1; // 23
		uint32 pageTableBlockSize: 4; // 24
		uint32 unknown3: 4;
	};
	uint32 val;
};

// VM_CONTEXT0_CNTL2
union VmContext0Cntl2 {
	struct {
		uint32 clearProtectionFaultStatusAddr: 1; // 0
		uint32 enableClearProtectionFaultStatusAddrWhenInvalidateContext: 1; // 1
		uint32 enableInterruptProcessingForSubsequentFaultsPerContext: 1; // 2
		uint32 allowSubsequentProtectionFaultStatusAddrUpdates: 1; // 3
		uint32 waitForIdleWhenInvalidate: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// VM_CONTEXT0_PAGE_TABLE_BASE_ADDR
union VmContext0PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT0_PAGE_TABLE_END_ADDR
union VmContext0PageTableEndAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT0_PAGE_TABLE_START_ADDR
union VmContext0PageTableStartAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT0_PROTECTION_FAULT_ADDR
union VmContext0ProtectionFaultAddr {
	struct {
		uint32 logicalPageAddr: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR
union VmContext0ProtectionFaultDefaultAddr {
	struct {
		uint32 physicalPageAddr: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT0_PROTECTION_FAULT_STATUS
union VmContext0ProtectionFaultStatus {
	struct {
		uint32 protections: 8; // 0
		uint32 unknown1: 4;
		uint32 memoryClientId: 8; // 12
		uint32 unknown2: 4;
		uint32 memoryClientRw: 1; // 24
		uint32 vmid: 4; // 25
		uint32 unknown3: 3;
	};
	uint32 val;
};

// VM_CONTEXT10_PAGE_TABLE_BASE_ADDR
union VmContext10PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT11_PAGE_TABLE_BASE_ADDR
union VmContext11PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT12_PAGE_TABLE_BASE_ADDR
union VmContext12PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT13_PAGE_TABLE_BASE_ADDR
union VmContext13PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT14_PAGE_TABLE_BASE_ADDR
union VmContext14PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT15_PAGE_TABLE_BASE_ADDR
union VmContext15PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT1_CNTL
union VmContext1Cntl {
	struct {
		uint32 enableContext: 1; // 0
		uint32 pageTableDepth: 2; // 1
		uint32 rangeProtectionFaultEnableInterrupt: 1; // 3
		uint32 rangeProtectionFaultEnableDefault: 1; // 4
		uint32 unknown1: 1;
		uint32 dummyPageProtectionFaultEnableInterrupt: 1; // 6
		uint32 dummyPageProtectionFaultEnableDefault: 1; // 7
		uint32 unknown2: 1;
		uint32 pde0ProtectionFaultEnableInterrupt: 1; // 9
		uint32 pde0ProtectionFaultEnableDefault: 1; // 10
		uint32 pde0ProtectionFaultEnableSave: 1; // 11
		uint32 validProtectionFaultEnableInterrupt: 1; // 12
		uint32 validProtectionFaultEnableDefault: 1; // 13
		uint32 validProtectionFaultEnableSave: 1; // 14
		uint32 readProtectionFaultEnableInterrupt: 1; // 15
		uint32 readProtectionFaultEnableDefault: 1; // 16
		uint32 readProtectionFaultEnableSave: 1; // 17
		uint32 writeProtectionFaultEnableInterrupt: 1; // 18
		uint32 writeProtectionFaultEnableDefault: 1; // 19
		uint32 writeProtectionFaultEnableSave: 1; // 20
		uint32 privilegedProtectionFaultEnableInterrupt: 1; // 21
		uint32 privilegedProtectionFaultEnableDefault: 1; // 22
		uint32 privilegedProtectionFaultEnableSave: 1; // 23
		uint32 pageTableBlockSize: 4; // 24
		uint32 unknown3: 4;
	};
	uint32 val;
};

// VM_CONTEXT1_CNTL2
union VmContext1Cntl2 {
	struct {
		uint32 clearProtectionFaultStatusAddr: 1; // 0
		uint32 enableClearProtectionFaultStatusAddrWhenInvalidateContext: 1; // 1
		uint32 enableInterruptProcessingForSubsequentFaultsPerContext: 1; // 2
		uint32 allowSubsequentProtectionFaultStatusAddrUpdates: 1; // 3
		uint32 waitForIdleWhenInvalidate: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// VM_CONTEXT1_PAGE_TABLE_BASE_ADDR
union VmContext1PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT1_PAGE_TABLE_END_ADDR
union VmContext1PageTableEndAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT1_PAGE_TABLE_START_ADDR
union VmContext1PageTableStartAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT1_PROTECTION_FAULT_ADDR
union VmContext1ProtectionFaultAddr {
	struct {
		uint32 logicalPageAddr: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT1_PROTECTION_FAULT_DEFAULT_ADDR
union VmContext1ProtectionFaultDefaultAddr {
	struct {
		uint32 physicalPageAddr: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT1_PROTECTION_FAULT_STATUS
union VmContext1ProtectionFaultStatus {
	struct {
		uint32 protections: 8; // 0
		uint32 unknown1: 4;
		uint32 memoryClientId: 8; // 12
		uint32 unknown2: 4;
		uint32 memoryClientRw: 1; // 24
		uint32 vmid: 4; // 25
		uint32 unknown3: 3;
	};
	uint32 val;
};

// VM_CONTEXT2_PAGE_TABLE_BASE_ADDR
union VmContext2PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT3_PAGE_TABLE_BASE_ADDR
union VmContext3PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT4_PAGE_TABLE_BASE_ADDR
union VmContext4PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT5_PAGE_TABLE_BASE_ADDR
union VmContext5PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT6_PAGE_TABLE_BASE_ADDR
union VmContext6PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT7_PAGE_TABLE_BASE_ADDR
union VmContext7PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT8_PAGE_TABLE_BASE_ADDR
union VmContext8PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXT9_PAGE_TABLE_BASE_ADDR
union VmContext9PageTableBaseAddr {
	struct {
		uint32 physicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_CONTEXTS_DISABLE
union VmContextsDisable {
	struct {
		uint32 disableContext0: 1; // 0
		uint32 disableContext1: 1; // 1
		uint32 disableContext2: 1; // 2
		uint32 disableContext3: 1; // 3
		uint32 disableContext4: 1; // 4
		uint32 disableContext5: 1; // 5
		uint32 disableContext6: 1; // 6
		uint32 disableContext7: 1; // 7
		uint32 disableContext8: 1; // 8
		uint32 disableContext9: 1; // 9
		uint32 disableContext10: 1; // 10
		uint32 disableContext11: 1; // 11
		uint32 disableContext12: 1; // 12
		uint32 disableContext13: 1; // 13
		uint32 disableContext14: 1; // 14
		uint32 disableContext15: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// VM_DEBUG
union VmDebug {
	struct {
		uint32 flags: 32; // 0
	};
	uint32 val;
};

// VM_DUMMY_PAGE_FAULT_ADDR
union VmDummyPageFaultAddr {
	struct {
		uint32 dummyPageAddr: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_DUMMY_PAGE_FAULT_CNTL
union VmDummyPageFaultCntl {
	struct {
		uint32 dummyPageFaultEnable: 1; // 0
		uint32 dummyPageAddressLogical: 1; // 1
		uint32 dummyPageCompareMask: 2; // 2
		uint32 unknown1: 28;
	};
	uint32 val;
};

// VM_FAULT_CLIENT_ID
union VmFaultClientId {
	struct {
		uint32 memoryClient: 9; // 0
		uint32 memoryClientMask: 9; // 9
		uint32 unknown1: 14;
	};
	uint32 val;
};

// VM_INVALIDATE_REQUEST
union VmInvalidateRequest {
	struct {
		uint32 invalidateDomain0: 1; // 0
		uint32 invalidateDomain1: 1; // 1
		uint32 invalidateDomain2: 1; // 2
		uint32 invalidateDomain3: 1; // 3
		uint32 invalidateDomain4: 1; // 4
		uint32 invalidateDomain5: 1; // 5
		uint32 invalidateDomain6: 1; // 6
		uint32 invalidateDomain7: 1; // 7
		uint32 invalidateDomain8: 1; // 8
		uint32 invalidateDomain9: 1; // 9
		uint32 invalidateDomain10: 1; // 10
		uint32 invalidateDomain11: 1; // 11
		uint32 invalidateDomain12: 1; // 12
		uint32 invalidateDomain13: 1; // 13
		uint32 invalidateDomain14: 1; // 14
		uint32 invalidateDomain15: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// VM_INVALIDATE_RESPONSE
union VmInvalidateResponse {
	struct {
		uint32 domainInvalidated0: 1; // 0
		uint32 domainInvalidated1: 1; // 1
		uint32 domainInvalidated2: 1; // 2
		uint32 domainInvalidated3: 1; // 3
		uint32 domainInvalidated4: 1; // 4
		uint32 domainInvalidated5: 1; // 5
		uint32 domainInvalidated6: 1; // 6
		uint32 domainInvalidated7: 1; // 7
		uint32 domainInvalidated8: 1; // 8
		uint32 domainInvalidated9: 1; // 9
		uint32 domainInvalidated10: 1; // 10
		uint32 domainInvalidated11: 1; // 11
		uint32 domainInvalidated12: 1; // 12
		uint32 domainInvalidated13: 1; // 13
		uint32 domainInvalidated14: 1; // 14
		uint32 domainInvalidated15: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// VM_L2_BANK_SELECT_MASKA
union VmL2BankSelectMaska {
	struct {
		uint32 bankSelectMask: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_L2_BANK_SELECT_MASKB
union VmL2BankSelectMaskb {
	struct {
		uint32 bankSelectMask: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// VM_L2_CG
union VmL2Cg {
	struct {
		uint32 unknown1: 6;
		uint32 offdly: 6; // 6
		uint32 unknown2: 6;
		uint32 enable: 1; // 18
		uint32 memLsEnable: 1; // 19
		uint32 unknown3: 12;
	};
	uint32 val;
};

// VM_L2_CNTL
union VmL2Cntl {
	struct {
		uint32 enableL2Cache: 1; // 0
		uint32 enableL2FragmentProcessing: 1; // 1
		uint32 l2CachePteEndianSwapMode: 2; // 2
		uint32 l2CachePdeEndianSwapMode: 2; // 4
		uint32 unknown1: 2;
		uint32 l2Pde0CacheTagGenerationMode: 1; // 8
		uint32 enableL2PteCacheLruUpdateByWrite: 1; // 9
		uint32 enableL2Pde0CacheLruUpdateByWrite: 1; // 10
		uint32 unknown2: 1;
		uint32 l2Pde0CacheSplitMode: 3; // 12
		uint32 effectiveL2QueueSize: 3; // 15
		uint32 pdeFaultClassification: 1; // 18
		uint32 context1IdentityAccessMode: 2; // 19
		uint32 identityModeFragmentSize: 5; // 21
		uint32 l2Cache4kSwapTagIndexLsbs: 2; // 26
		uint32 l2CacheBigkSwapTagIndexLsbs: 3; // 28
		uint32 unknown3: 1;
	};
	uint32 val;
};

// VM_L2_CNTL2
union VmL2Cntl2 {
	struct {
		uint32 invalidateAllL1Tlbs: 1; // 0
		uint32 invalidateL2Cache: 1; // 1
		uint32 unknown1: 19;
		uint32 disableInvalidatePerDomain: 1; // 21
		uint32 disableBigkCacheOptimization: 1; // 22
		uint32 l2CacheBigkVmidMode: 3; // 23
		uint32 invalidateCacheMode: 2; // 26
		uint32 unknown2: 4;
	};
	uint32 val;
};

// VM_L2_CNTL3
union VmL2Cntl3 {
	struct {
		uint32 bankSelect: 6; // 0
		uint32 l2CacheUpdateMode: 2; // 6
		uint32 l2CacheUpdateWildcardReferenceValue: 5; // 8
		uint32 unknown1: 2;
		uint32 l2CacheBigkFragmentSize: 5; // 15
		uint32 l2CacheBigkAssociativity: 1; // 20
		uint32 l2Cache4kEffectiveSize: 3; // 21
		uint32 l2CacheBigkEffectiveSize: 4; // 24
		uint32 l2Cache4kForceMiss: 1; // 28
		uint32 l2CacheBigkForceMiss: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// VM_L2_CONTEXT1_IDENTITY_APERTURE_HIGH_ADDR
union VmL2Context1IdentityApertureHighAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_L2_CONTEXT1_IDENTITY_APERTURE_LOW_ADDR
union VmL2Context1IdentityApertureLowAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_L2_CONTEXT_IDENTITY_PHYSICAL_OFFSET
union VmL2ContextIdentityPhysicalOffset {
	struct {
		uint32 physicalPageOffset: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_L2_STATUS
union VmL2Status {
	struct {
		uint32 l2Busy: 1; // 0
		uint32 contextDomainBusy: 16; // 1
		uint32 unknown1: 15;
	};
	uint32 val;
};

// VM_PRT_APERTURE0_HIGH_ADDR
union VmPrtAperture0HighAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_PRT_APERTURE0_LOW_ADDR
union VmPrtAperture0LowAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_PRT_APERTURE1_HIGH_ADDR
union VmPrtAperture1HighAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_PRT_APERTURE1_LOW_ADDR
union VmPrtAperture1LowAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_PRT_APERTURE2_HIGH_ADDR
union VmPrtAperture2HighAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_PRT_APERTURE2_LOW_ADDR
union VmPrtAperture2LowAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_PRT_APERTURE3_HIGH_ADDR
union VmPrtAperture3HighAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_PRT_APERTURE3_LOW_ADDR
union VmPrtAperture3LowAddr {
	struct {
		uint32 logicalPageNumber: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VM_PRT_CNTL
union VmPrtCntl {
	struct {
		uint32 cbDisableFaultOnUnmappedAccess: 1; // 0
		uint32 tcDisableFaultOnUnmappedAccess: 1; // 1
		uint32 l2CacheStoreInvalidEntries: 1; // 2
		uint32 l1TlbStoreInvalidEntries: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

