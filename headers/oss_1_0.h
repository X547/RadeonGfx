#pragma once
#include <SupportDefs.h>

// CC_DRM_ID_STRAPS
union CcDrmIdStraps {
	struct {
		uint32 unknown1: 4;
		uint32 deviceId: 16; // 4
		uint32 majorRevId: 4; // 20
		uint32 minorRevId: 4; // 24
		uint32 atiRevId: 4; // 28
	};
	uint32 val;
};

// CC_SYS_RB_BACKEND_DISABLE
union CcSysRbBackendDisable {
	struct {
		uint32 unknown1: 16;
		uint32 backendDisable: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// CLIENT0_BM
union Client0Bm {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_CD0
union Client0Cd0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_CD1
union Client0Cd1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_CD2
union Client0Cd2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_CD3
union Client0Cd3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_CK0
union Client0Ck0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_CK1
union Client0Ck1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_CK2
union Client0Ck2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_CK3
union Client0Ck3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_K0
union Client0K0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_K1
union Client0K1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_K2
union Client0K2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_K3
union Client0K3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_OFFSET
union Client0Offset {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_OFFSET_HI
union Client0OffsetHi {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT0_STATUS
union Client0Status {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_BM
union Client1Bm {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_CD0
union Client1Cd0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_CD1
union Client1Cd1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_CD2
union Client1Cd2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_CD3
union Client1Cd3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_CK0
union Client1Ck0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_CK1
union Client1Ck1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_CK2
union Client1Ck2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_CK3
union Client1Ck3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_K0
union Client1K0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_K1
union Client1K1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_K2
union Client1K2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_K3
union Client1K3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_OFFSET
union Client1Offset {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_OFFSET_HI
union Client1OffsetHi {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT1_PORT_STATUS
union Client1PortStatus {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_BM
union Client2Bm {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_CD0
union Client2Cd0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_CD1
union Client2Cd1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_CD2
union Client2Cd2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_CD3
union Client2Cd3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_CK0
union Client2Ck0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_CK1
union Client2Ck1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_CK2
union Client2Ck2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_CK3
union Client2Ck3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_K0
union Client2K0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_K1
union Client2K1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_K2
union Client2K2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_K3
union Client2K3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_OFFSET
union Client2Offset {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_OFFSET_HI
union Client2OffsetHi {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT2_STATUS
union Client2Status {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_BM
union Client3Bm {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_CD0
union Client3Cd0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_CD1
union Client3Cd1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_CD2
union Client3Cd2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_CD3
union Client3Cd3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_CK0
union Client3Ck0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_CK1
union Client3Ck1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_CK2
union Client3Ck2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_CK3
union Client3Ck3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_K0
union Client3K0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_K1
union Client3K1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_K2
union Client3K2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_K3
union Client3K3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_OFFSET
union Client3Offset {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_OFFSET_HI
union Client3OffsetHi {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CLIENT3_STATUS
union Client3Status {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// CP_CONFIG
union CpConfig {
	struct {
		uint32 unknown1: 8;
		uint32 cpRdreqUrg: 4; // 8
		uint32 unknown2: 4;
		uint32 cpReqTran: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// DC_TEST_DEBUG_DATA
union DcTestDebugData {
	struct {
		uint32 dcTestDebugData: 32; // 0
	};
	uint32 val;
};

// DC_TEST_DEBUG_INDEX
union DcTestDebugIndex {
	struct {
		uint32 dcTestDebugIndex: 8; // 0
		uint32 dcTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// DH_TEST
union DhTest {
	struct {
		uint32 dhTest: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// EXP0
union Exp0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// EXP1
union Exp1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// EXP2
union Exp2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// EXP3
union Exp3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// EXP4
union Exp4 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// EXP5
union Exp5 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// EXP6
union Exp6 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// EXP7
union Exp7 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// GC_USER_SYS_RB_BACKEND_DISABLE
union GcUserSysRbBackendDisable {
	struct {
		uint32 unknown1: 16;
		uint32 backendDisable: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// HDP_ADDR_CONFIG
union HdpAddrConfig {
	struct {
		uint32 numPipes: 3; // 0
		uint32 unknown1: 1;
		uint32 pipeInterleaveSize: 3; // 4
		uint32 unknown2: 1;
		uint32 bankInterleaveSize: 3; // 8
		uint32 unknown3: 1;
		uint32 numShaderEngines: 2; // 12
		uint32 unknown4: 2;
		uint32 shaderEngineTileSize: 3; // 16
		uint32 unknown5: 1;
		uint32 numGpus: 3; // 20
		uint32 unknown6: 1;
		uint32 multiGpuTileSize: 2; // 24
		uint32 unknown7: 2;
		uint32 rowSize: 2; // 28
		uint32 numLowerPipes: 1; // 30
		uint32 unknown8: 1;
	};
	uint32 val;
};

// HDP_DEBUG0
union HdpDebug0 {
	struct {
		uint32 unknown1: 32;
	};
	uint32 val;
};

// HDP_DEBUG1
union HdpDebug1 {
	struct {
		uint32 unknown1: 32;
	};
	uint32 val;
};

// HDP_HOST_PATH_CNTL
union HdpHostPathCntl {
	struct {
		uint32 bifRdretCredit: 3; // 0
		uint32 mcWrreqCredit: 6; // 3
		uint32 wrStallTimer: 2; // 9
		uint32 rdStallTimer: 2; // 11
		uint32 unknown1: 6;
		uint32 writeCombineTimer: 2; // 19
		uint32 writeCombineEn: 1; // 21
		uint32 cacheInvalidate: 1; // 22
		uint32 clockGatingDis: 1; // 23
		uint32 regClkEnableCount: 4; // 24
		uint32 unknown2: 1;
		uint32 allSurfacesDis: 1; // 29
		uint32 writeThroughCacheDis: 1; // 30
		uint32 linRdCacheDis: 1; // 31
	};
	uint32 val;
};

// HDP_LAST_SURFACE_HIT
union HdpLastSurfaceHit {
	struct {
		uint32 lastSurfaceHit: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// HDP_MEMIO_ADDR
union HdpMemioAddr {
	struct {
		uint32 memioAddrLower: 32; // 0
	};
	uint32 val;
};

// HDP_MEMIO_CNTL
union HdpMemioCntl {
	struct {
		uint32 memioSend: 1; // 0
		uint32 memioOp: 1; // 1
		uint32 memioBe: 4; // 2
		uint32 memioWrStrobe: 1; // 6
		uint32 memioRdStrobe: 1; // 7
		uint32 memioAddrUpper: 6; // 8
		uint32 memioClrWrError: 1; // 14
		uint32 memioClrRdError: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// HDP_MEMIO_RD_DATA
union HdpMemioRdData {
	struct {
		uint32 memioRdData: 32; // 0
	};
	uint32 val;
};

// HDP_MEMIO_STATUS
union HdpMemioStatus {
	struct {
		uint32 memioWrStatus: 1; // 0
		uint32 memioRdStatus: 1; // 1
		uint32 memioWrError: 1; // 2
		uint32 memioRdError: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// HDP_MEMIO_WR_DATA
union HdpMemioWrData {
	struct {
		uint32 memioWrData: 32; // 0
	};
	uint32 val;
};

// HDP_MEM_POWER_LS
union HdpMemPowerLs {
	struct {
		uint32 lsEnable: 1; // 0
		uint32 lsSetup: 6; // 1
		uint32 lsHold: 6; // 7
		uint32 unknown1: 19;
	};
	uint32 val;
};

// HDP_MISC_CNTL
union HdpMiscCntl {
	struct {
		uint32 flushInvalidateCache: 1; // 0
		uint32 vmId: 4; // 1
		uint32 outstandingWriteCount1024: 1; // 5
		uint32 multipleReads: 1; // 6
		uint32 hdpBifRdretCredit: 4; // 7
		uint32 simultaneousReadsWrites: 1; // 11
		uint32 noSplitArrayLinear: 1; // 12
		uint32 mcRdreqCredit: 6; // 13
		uint32 readCacheInvalidate: 1; // 19
		uint32 addrlibLinearBypass: 1; // 20
		uint32 fedEnable: 1; // 21
		uint32 unknown1: 10;
	};
	uint32 val;
};

// HDP_NONSURFACE_BASE
union HdpNonsurfaceBase {
	struct {
		uint32 nonsurfBase: 32; // 0
	};
	uint32 val;
};

// HDP_NONSURFACE_INFO
union HdpNonsurfaceInfo {
	struct {
		uint32 nonsurfAddrType: 1; // 0
		uint32 nonsurfArrayMode: 4; // 1
		uint32 nonsurfEndian: 2; // 5
		uint32 nonsurfPixelSize: 3; // 7
		uint32 nonsurfSampleNum: 3; // 10
		uint32 nonsurfSampleSize: 2; // 13
		uint32 nonsurfPriv: 1; // 15
		uint32 nonsurfTileCompact: 1; // 16
		uint32 nonsurfTileSplit: 3; // 17
		uint32 nonsurfNumBanks: 2; // 20
		uint32 nonsurfBankWidth: 2; // 22
		uint32 nonsurfBankHeight: 2; // 24
		uint32 nonsurfMacroTileAspect: 2; // 26
		uint32 nonsurfMicroTileMode: 2; // 28
		uint32 nonsurfSliceTileMaxMsb: 1; // 30
		uint32 unknown1: 1;
	};
	uint32 val;
};

// HDP_NONSURFACE_PREFETCH
union HdpNonsurfacePrefetch {
	struct {
		uint32 nonsurfPrefetchPri: 3; // 0
		uint32 nonsurfPrefetchDir: 3; // 3
		uint32 nonsurfPrefetchNum: 3; // 6
		uint32 nonsurfPrefetchMaxZ: 11; // 9
		uint32 unknown1: 7;
		uint32 nonsurfPipeConfig: 5; // 27
	};
	uint32 val;
};

// HDP_NONSURFACE_SIZE
union HdpNonsurfaceSize {
	struct {
		uint32 nonsurfPitchTileMax: 11; // 0
		uint32 nonsurfSliceTileMax: 21; // 11
	};
	uint32 val;
};

// HDP_NONSURF_FLAGS
union HdpNonsurfFlags {
	struct {
		uint32 nonsurfWriteFlag: 1; // 0
		uint32 nonsurfReadFlag: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// HDP_NONSURF_FLAGS_CLR
union HdpNonsurfFlagsClr {
	struct {
		uint32 nonsurfWriteFlagClr: 1; // 0
		uint32 nonsurfReadFlagClr: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// HDP_OUTSTANDING_REQ
union HdpOutstandingReq {
	struct {
		uint32 writeReq: 8; // 0
		uint32 readReq: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// HDP_SC_MULTI_CHIP_CNTL
union HdpScMultiChipCntl {
	struct {
		uint32 log2NumChips: 3; // 0
		uint32 multiChipTileSize: 2; // 3
		uint32 unknown1: 27;
	};
	uint32 val;
};

// HDP_SW_SEMAPHORE
union HdpSwSemaphore {
	struct {
		uint32 swSemaphore: 32; // 0
	};
	uint32 val;
};

// HDP_TILING_CONFIG
union HdpTilingConfig {
	struct {
		uint32 unknown1: 1;
		uint32 pipeTiling: 3; // 1
		uint32 bankTiling: 2; // 4
		uint32 groupSize: 2; // 6
		uint32 rowTiling: 3; // 8
		uint32 bankSwaps: 3; // 11
		uint32 sampleSplit: 2; // 14
		uint32 unknown2: 16;
	};
	uint32 val;
};

// HDP_XDP_BARS_ADDR_39_36
union HdpXdpBarsAddr39_36 {
	struct {
		uint32 bar0Addr39_36: 4; // 0
		uint32 bar1Addr39_36: 4; // 4
		uint32 bar2Addr39_36: 4; // 8
		uint32 bar3Addr39_36: 4; // 12
		uint32 bar4Addr39_36: 4; // 16
		uint32 bar5Addr39_36: 4; // 20
		uint32 bar6Addr39_36: 4; // 24
		uint32 bar7Addr39_36: 4; // 28
	};
	uint32 val;
};

// HDP_XDP_BUSY_STS
union HdpXdpBusySts {
	struct {
		uint32 busyBits: 18; // 0
		uint32 unknown1: 14;
	};
	uint32 val;
};

// HDP_XDP_CGTT_BLK_CTRL
union HdpXdpCgttBlkCtrl {
	struct {
		uint32 cgttBlkCtrl0OnDelay: 4; // 0
		uint32 cgttBlkCtrl1OffDelay: 8; // 4
		uint32 cgttBlkCtrl2Rsvd: 18; // 12
		uint32 cgttBlkCtrl3SoftCoreOverride: 1; // 30
		uint32 cgttBlkCtrl4SoftRegOverride: 1; // 31
	};
	uint32 val;
};

// HDP_XDP_CHKN
union HdpXdpChkn {
	struct {
		uint32 chkn0Rsvd: 8; // 0
		uint32 chkn1Rsvd: 8; // 8
		uint32 chkn2Rsvd: 8; // 16
		uint32 chkn3Rsvd: 8; // 24
	};
	uint32 val;
};

// HDP_XDP_D2H_BAR_UPDATE
union HdpXdpD2hBarUpdate {
	struct {
		uint32 d2hBarUpdateAddr: 16; // 0
		uint32 d2hBarUpdateFlushNum: 4; // 16
		uint32 d2hBarUpdateBarNum: 3; // 20
		uint32 unknown1: 9;
	};
	uint32 val;
};

// HDP_XDP_D2H_FLUSH
union HdpXdpD2hFlush {
	struct {
		uint32 d2hFlushFlushNum: 4; // 0
		uint32 d2hFlushMbxEncData: 4; // 4
		uint32 d2hFlushMbxAddrSel: 3; // 8
		uint32 d2hFlushXpbClg: 5; // 11
		uint32 d2hFlushSendHost: 1; // 16
		uint32 d2hFlushSendSide: 1; // 17
		uint32 d2hFlushAlterFlushNum: 1; // 18
		uint32 d2hFlushRsvd0: 1; // 19
		uint32 d2hFlushRsvd1: 1; // 20
		uint32 unknown1: 11;
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_10
union HdpXdpD2hRsvd10 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_11
union HdpXdpD2hRsvd11 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_12
union HdpXdpD2hRsvd12 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_13
union HdpXdpD2hRsvd13 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_14
union HdpXdpD2hRsvd14 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_15
union HdpXdpD2hRsvd15 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_16
union HdpXdpD2hRsvd16 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_17
union HdpXdpD2hRsvd17 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_18
union HdpXdpD2hRsvd18 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_19
union HdpXdpD2hRsvd19 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_20
union HdpXdpD2hRsvd20 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_21
union HdpXdpD2hRsvd21 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_22
union HdpXdpD2hRsvd22 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_23
union HdpXdpD2hRsvd23 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_24
union HdpXdpD2hRsvd24 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_25
union HdpXdpD2hRsvd25 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_26
union HdpXdpD2hRsvd26 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_27
union HdpXdpD2hRsvd27 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_28
union HdpXdpD2hRsvd28 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_29
union HdpXdpD2hRsvd29 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_3
union HdpXdpD2hRsvd3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_30
union HdpXdpD2hRsvd30 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_31
union HdpXdpD2hRsvd31 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_32
union HdpXdpD2hRsvd32 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_33
union HdpXdpD2hRsvd33 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_34
union HdpXdpD2hRsvd34 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_4
union HdpXdpD2hRsvd4 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_5
union HdpXdpD2hRsvd5 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_6
union HdpXdpD2hRsvd6 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_7
union HdpXdpD2hRsvd7 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_8
union HdpXdpD2hRsvd8 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_D2H_RSVD_9
union HdpXdpD2hRsvd9 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_DBG_ADDR
union HdpXdpDbgAddr {
	struct {
		uint32 sts: 16; // 0
		uint32 ctrl: 16; // 16
	};
	uint32 val;
};

// HDP_XDP_DBG_DATA
union HdpXdpDbgData {
	struct {
		uint32 sts: 16; // 0
		uint32 ctrl: 16; // 16
	};
	uint32 val;
};

// HDP_XDP_DBG_MASK
union HdpXdpDbgMask {
	struct {
		uint32 sts: 16; // 0
		uint32 ctrl: 16; // 16
	};
	uint32 val;
};

// HDP_XDP_DIRECT2HDP_FIRST
union HdpXdpDirect2hdpFirst {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_DIRECT2HDP_LAST
union HdpXdpDirect2hdpLast {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_FLUSH_ARMED_STS
union HdpXdpFlushArmedSts {
	struct {
		uint32 flushArmedSts: 32; // 0
	};
	uint32 val;
};

// HDP_XDP_FLUSH_CNTR0_STS
union HdpXdpFlushCntr0Sts {
	struct {
		uint32 flushCntr0Sts: 26; // 0
		uint32 unknown1: 6;
	};
	uint32 val;
};

// HDP_XDP_HDP_IPH_CFG
union HdpXdpHdpIphCfg {
	struct {
		uint32 hdpIphCfgSysFifoDepthOverride: 6; // 0
		uint32 hdpIphCfgXdpFifoDepthOverride: 6; // 6
		uint32 hdpIphCfgInversePeerTagMatching: 1; // 12
		uint32 hdpIphCfgP2pRdEn: 1; // 13
		uint32 unknown1: 18;
	};
	uint32 val;
};

// HDP_XDP_HDP_MBX_MC_CFG
union HdpXdpHdpMbxMcCfg {
	struct {
		uint32 hdpMbxMcCfgTapWrreqPriv: 1; // 0
		uint32 hdpMbxMcCfgTapWrreqSwap: 2; // 1
		uint32 hdpMbxMcCfgTapWrreqTran: 1; // 3
		uint32 hdpMbxMcCfgTapWrreqVmid: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// HDP_XDP_HDP_MC_CFG
union HdpXdpHdpMcCfg {
	struct {
		uint32 hdpMcCfgHstTapWrreqPriv: 1; // 0
		uint32 hdpMcCfgHstTapWrreqSwap: 2; // 1
		uint32 hdpMcCfgHstTapWrreqTran: 1; // 3
		uint32 hdpMcCfgSidTapWrreqPriv: 1; // 4
		uint32 hdpMcCfgSidTapWrreqSwap: 2; // 5
		uint32 hdpMcCfgSidTapWrreqTran: 1; // 7
		uint32 hdpMcCfgXl8rWrreqCrdOverride: 6; // 8
		uint32 hdpMcCfgXdpHigherPriThresh: 6; // 14
		uint32 hdpMcCfgMcStallOnBufFullMask: 3; // 20
		uint32 hdpMcCfgHstTapWrreqVmid: 4; // 23
		uint32 hdpMcCfgSidTapWrreqVmid: 4; // 27
		uint32 unknown1: 1;
	};
	uint32 val;
};

// HDP_XDP_HST_CFG
union HdpXdpHstCfg {
	struct {
		uint32 hstCfgWrCombineEn: 1; // 0
		uint32 hstCfgWrCombineTimer: 2; // 1
		uint32 unknown1: 29;
	};
	uint32 val;
};

// HDP_XDP_P2P_BAR0
union HdpXdpP2pBar0 {
	struct {
		uint32 addr: 16; // 0
		uint32 flush: 4; // 16
		uint32 valid: 1; // 20
		uint32 unknown1: 11;
	};
	uint32 val;
};

// HDP_XDP_P2P_BAR1
union HdpXdpP2pBar1 {
	struct {
		uint32 addr: 16; // 0
		uint32 flush: 4; // 16
		uint32 valid: 1; // 20
		uint32 unknown1: 11;
	};
	uint32 val;
};

// HDP_XDP_P2P_BAR2
union HdpXdpP2pBar2 {
	struct {
		uint32 addr: 16; // 0
		uint32 flush: 4; // 16
		uint32 valid: 1; // 20
		uint32 unknown1: 11;
	};
	uint32 val;
};

// HDP_XDP_P2P_BAR3
union HdpXdpP2pBar3 {
	struct {
		uint32 addr: 16; // 0
		uint32 flush: 4; // 16
		uint32 valid: 1; // 20
		uint32 unknown1: 11;
	};
	uint32 val;
};

// HDP_XDP_P2P_BAR4
union HdpXdpP2pBar4 {
	struct {
		uint32 addr: 16; // 0
		uint32 flush: 4; // 16
		uint32 valid: 1; // 20
		uint32 unknown1: 11;
	};
	uint32 val;
};

// HDP_XDP_P2P_BAR5
union HdpXdpP2pBar5 {
	struct {
		uint32 addr: 16; // 0
		uint32 flush: 4; // 16
		uint32 valid: 1; // 20
		uint32 unknown1: 11;
	};
	uint32 val;
};

// HDP_XDP_P2P_BAR6
union HdpXdpP2pBar6 {
	struct {
		uint32 addr: 16; // 0
		uint32 flush: 4; // 16
		uint32 valid: 1; // 20
		uint32 unknown1: 11;
	};
	uint32 val;
};

// HDP_XDP_P2P_BAR7
union HdpXdpP2pBar7 {
	struct {
		uint32 addr: 16; // 0
		uint32 flush: 4; // 16
		uint32 valid: 1; // 20
		uint32 unknown1: 11;
	};
	uint32 val;
};

// HDP_XDP_P2P_BAR_CFG
union HdpXdpP2pBarCfg {
	struct {
		uint32 p2pBarCfgAddrSize: 4; // 0
		uint32 p2pBarCfgBarFrom: 2; // 4
		uint32 unknown1: 26;
	};
	uint32 val;
};

// HDP_XDP_P2P_MBX_ADDR0
union HdpXdpP2pMbxAddr0 {
	struct {
		uint32 valid: 1; // 0
		uint32 addr: 20; // 1
		uint32 addr39_36: 4; // 21
		uint32 unknown1: 7;
	};
	uint32 val;
};

// HDP_XDP_P2P_MBX_ADDR1
union HdpXdpP2pMbxAddr1 {
	struct {
		uint32 valid: 1; // 0
		uint32 addr: 20; // 1
		uint32 addr39_36: 4; // 21
		uint32 unknown1: 7;
	};
	uint32 val;
};

// HDP_XDP_P2P_MBX_ADDR2
union HdpXdpP2pMbxAddr2 {
	struct {
		uint32 valid: 1; // 0
		uint32 addr: 20; // 1
		uint32 addr39_36: 4; // 21
		uint32 unknown1: 7;
	};
	uint32 val;
};

// HDP_XDP_P2P_MBX_ADDR3
union HdpXdpP2pMbxAddr3 {
	struct {
		uint32 valid: 1; // 0
		uint32 addr: 20; // 1
		uint32 addr39_36: 4; // 21
		uint32 unknown1: 7;
	};
	uint32 val;
};

// HDP_XDP_P2P_MBX_ADDR4
union HdpXdpP2pMbxAddr4 {
	struct {
		uint32 valid: 1; // 0
		uint32 addr: 20; // 1
		uint32 addr39_36: 4; // 21
		uint32 unknown1: 7;
	};
	uint32 val;
};

// HDP_XDP_P2P_MBX_ADDR5
union HdpXdpP2pMbxAddr5 {
	struct {
		uint32 valid: 1; // 0
		uint32 addr: 20; // 1
		uint32 addr39_36: 4; // 21
		uint32 unknown1: 7;
	};
	uint32 val;
};

// HDP_XDP_P2P_MBX_ADDR6
union HdpXdpP2pMbxAddr6 {
	struct {
		uint32 valid: 1; // 0
		uint32 addr: 20; // 1
		uint32 addr39_36: 4; // 21
		uint32 unknown1: 7;
	};
	uint32 val;
};

// HDP_XDP_P2P_MBX_OFFSET
union HdpXdpP2pMbxOffset {
	struct {
		uint32 p2pMbxOffset: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// HDP_XDP_SID_CFG
union HdpXdpSidCfg {
	struct {
		uint32 sidCfgWrCombineEn: 1; // 0
		uint32 sidCfgWrCombineTimer: 2; // 1
		uint32 sidCfgFlnumMsbSel: 2; // 3
		uint32 unknown1: 27;
	};
	uint32 val;
};

// HDP_XDP_SRBM_CFG
union HdpXdpSrbmCfg {
	struct {
		uint32 srbmCfgRegClkEnableCount: 6; // 0
		uint32 srbmCfgRegClkGatingDis: 1; // 6
		uint32 srbmCfgWakeDynClk: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// HDP_XDP_STICKY
union HdpXdpSticky {
	struct {
		uint32 stickySts: 16; // 0
		uint32 stickyW1c: 16; // 16
	};
	uint32 val;
};

// HFS_SEED0
union HfsSeed0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HFS_SEED1
union HfsSeed1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HFS_SEED2
union HfsSeed2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// HFS_SEED3
union HfsSeed3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// IH_ADVFAULT_CNTL
union IhAdvfaultCntl {
	struct {
		uint32 watermark: 3; // 0
		uint32 watermarkEnable: 1; // 3
		uint32 watermarkReached: 1; // 4
		uint32 unknown1: 3;
		uint32 numFaultsDropped: 8; // 8
		uint32 waitTimer: 14; // 16
		uint32 unknown2: 2;
	};
	uint32 val;
};

// IH_CNTL
union IhCntl {
	struct {
		uint32 enableIntr: 1; // 0
		uint32 mcSwap: 2; // 1
		uint32 mcTran: 1; // 3
		uint32 rptrRearm: 1; // 4
		uint32 unknown1: 3;
		uint32 clientFifoHighwater: 2; // 8
		uint32 mcFifoHighwater: 5; // 10
		uint32 mcWrreqCredit: 5; // 15
		uint32 mcWrCleanCnt: 5; // 20
		uint32 mcVmid: 4; // 25
		uint32 unknown2: 3;
	};
	uint32 val;
};

// IH_LEVEL_STATUS
union IhLevelStatus {
	struct {
		uint32 dcStatus: 1; // 0
		uint32 unknown1: 1;
		uint32 romStatus: 1; // 2
		uint32 srbmStatus: 1; // 3
		uint32 bifStatus: 1; // 4
		uint32 xdmaStatus: 1; // 5
		uint32 unknown2: 26;
	};
	uint32 val;
};

// IH_PERFCOUNTER0_RESULT
union IhPerfcounter0Result {
	struct {
		uint32 perfCount: 32; // 0
	};
	uint32 val;
};

// IH_PERFCOUNTER1_RESULT
union IhPerfcounter1Result {
	struct {
		uint32 perfCount: 32; // 0
	};
	uint32 val;
};

// IH_PERFMON_CNTL
union IhPerfmonCntl {
	struct {
		uint32 enable0: 1; // 0
		uint32 clear0: 1; // 1
		uint32 perfSel0: 6; // 2
		uint32 enable1: 1; // 8
		uint32 clear1: 1; // 9
		uint32 perfSel1: 6; // 10
		uint32 unknown1: 16;
	};
	uint32 val;
};

// IH_RB_BASE
union IhRbBase {
	struct {
		uint32 addr: 32; // 0
	};
	uint32 val;
};

// IH_RB_CNTL
union IhRbCntl {
	struct {
		uint32 rbEnable: 1; // 0
		uint32 rbSize: 5; // 1
		uint32 rbFullDrainEnable: 1; // 6
		uint32 rbGpuTsEnable: 1; // 7
		uint32 wptrWritebackEnable: 1; // 8
		uint32 wptrWritebackTimer: 5; // 9
		uint32 unknown1: 2;
		uint32 wptrOverflowEnable: 1; // 16
		uint32 unknown2: 14;
		uint32 wptrOverflowClear: 1; // 31
	};
	uint32 val;
};

// IH_RB_RPTR
union IhRbRptr {
	struct {
		uint32 unknown1: 2;
		uint32 offset: 16; // 2
		uint32 unknown2: 14;
	};
	uint32 val;
};

// IH_RB_WPTR
union IhRbWptr {
	struct {
		uint32 rbOverflow: 1; // 0
		uint32 unknown1: 1;
		uint32 offset: 16; // 2
		uint32 unknown2: 14;
	};
	uint32 val;
};

// IH_RB_WPTR_ADDR_HI
union IhRbWptrAddrHi {
	struct {
		uint32 addr: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// IH_RB_WPTR_ADDR_LO
union IhRbWptrAddrLo {
	struct {
		uint32 unknown1: 2;
		uint32 addr: 30; // 2
	};
	uint32 val;
};

// IH_STATUS
union IhStatus {
	struct {
		uint32 idle: 1; // 0
		uint32 inputIdle: 1; // 1
		uint32 rbIdle: 1; // 2
		uint32 rbFull: 1; // 3
		uint32 rbFullDrain: 1; // 4
		uint32 rbOverflow: 1; // 5
		uint32 mcWrIdle: 1; // 6
		uint32 mcWrStall: 1; // 7
		uint32 mcWrCleanPending: 1; // 8
		uint32 mcWrCleanStall: 1; // 9
		uint32 bifInterruptLine: 1; // 10
		uint32 unknown1: 21;
	};
	uint32 val;
};

// KEFUSE0
union Kefuse0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KEFUSE1
union Kefuse1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KEFUSE2
union Kefuse2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KEFUSE3
union Kefuse3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KHFS0
union Khfs0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KHFS1
union Khfs1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KHFS2
union Khfs2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KHFS3
union Khfs3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KSESSION0
union Ksession0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KSESSION1
union Ksession1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KSESSION2
union Ksession2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KSESSION3
union Ksession3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KSIG0
union Ksig0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KSIG1
union Ksig1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KSIG2
union Ksig2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// KSIG3
union Ksig3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// LX0
union Lx0 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// LX1
union Lx1 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// LX2
union Lx2 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// LX3
union Lx3 {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// RINGOSC_MASK
union RingoscMask {
	struct {
		uint32 mask: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SEM_MAILBOX
union SemMailbox {
	struct {
		uint32 sideport: 8; // 0
		uint32 hostport: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SEM_MAILBOX_CLIENTCONFIG
union SemMailboxClientconfig {
	struct {
		uint32 cpClient0: 3; // 0
		uint32 cpClient1: 3; // 3
		uint32 cpClient2: 3; // 6
		uint32 cpClient3: 3; // 9
		uint32 unknown1: 3;
		uint32 uvdClient0: 3; // 15
		uint32 unknown2: 3;
		uint32 vceClient0: 3; // 21
		uint32 unknown3: 8;
	};
	uint32 val;
};

// SEM_MAILBOX_CONTROL
union SemMailboxControl {
	struct {
		uint32 sideportEnable: 8; // 0
		uint32 hostportEnable: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SEM_MCIF_CONFIG
union SemMcifConfig {
	struct {
		uint32 mcReqSwap: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// SPU_PORT_STATUS
union SpuPortStatus {
	struct {
		uint32 reserved: 32; // 0
	};
	uint32 val;
};

// SRBM_CAM_DATA
union SrbmCamData {
	struct {
		uint32 camAddr: 16; // 0
		uint32 camRemapaddr: 16; // 16
	};
	uint32 val;
};

// SRBM_CAM_INDEX
union SrbmCamIndex {
	struct {
		uint32 camIndex: 3; // 0
		uint32 unknown1: 29;
	};
	uint32 val;
};

// SRBM_CHIP_REVISION
union SrbmChipRevision {
	struct {
		uint32 chipRevision: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SRBM_CNTL
union SrbmCntl {
	struct {
		uint32 readTimeout: 10; // 0
		uint32 unknown1: 6;
		uint32 pwrRequestHalt: 1; // 16
		uint32 combineSystemMc: 1; // 17
		uint32 unknown2: 14;
	};
	uint32 val;
};

// SRBM_DEBUG
union SrbmDebug {
	struct {
		uint32 ignoreRdy: 1; // 0
		uint32 disableReadTimeout: 1; // 1
		uint32 snapshotFreeCntrs: 1; // 2
		uint32 unknown1: 1;
		uint32 sysClockDomainOverride: 1; // 4
		uint32 vceClockDomainOverride: 1; // 5
		uint32 uvdClockDomainOverride: 1; // 6
		uint32 unknown2: 1;
		uint32 mcClockDomainOverride: 1; // 8
		uint32 unknown3: 23;
	};
	uint32 val;
};

// SRBM_DEBUG_CNTL
union SrbmDebugCntl {
	struct {
		uint32 srbmDebugIndex: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// SRBM_DEBUG_DATA
union SrbmDebugData {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SRBM_DEBUG_SNAPSHOT
union SrbmDebugSnapshot {
	struct {
		uint32 mcbRdy: 1; // 0
		uint32 unknown1: 4;
		uint32 grbmRdy: 1; // 5
		uint32 dcRdy: 1; // 6
		uint32 bifRdy: 1; // 7
		uint32 xdmaRdy: 1; // 8
		uint32 uvdRdy: 1; // 9
		uint32 xspRdy: 1; // 10
		uint32 regbbRdy: 1; // 11
		uint32 orbRdy: 1; // 12
		uint32 mcd7Rdy: 1; // 13
		uint32 mcd6Rdy: 1; // 14
		uint32 mcd5Rdy: 1; // 15
		uint32 mcd4Rdy: 1; // 16
		uint32 mcd3Rdy: 1; // 17
		uint32 mcd2Rdy: 1; // 18
		uint32 mcd1Rdy: 1; // 19
		uint32 mcd0Rdy: 1; // 20
		uint32 mcc7Rdy: 1; // 21
		uint32 mcc6Rdy: 1; // 22
		uint32 mcc5Rdy: 1; // 23
		uint32 mcc4Rdy: 1; // 24
		uint32 mcc3Rdy: 1; // 25
		uint32 mcc2Rdy: 1; // 26
		uint32 mcc1Rdy: 1; // 27
		uint32 mcc0Rdy: 1; // 28
		uint32 vceRdy: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// SRBM_GFX_CNTL
union SrbmGfxCntl {
	struct {
		uint32 unknown1: 4;
		uint32 vmid: 4; // 4
		uint32 unknown2: 24;
	};
	uint32 val;
};

// SRBM_INT_ACK
union SrbmIntAck {
	struct {
		uint32 rderrIntAck: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// SRBM_INT_CNTL
union SrbmIntCntl {
	struct {
		uint32 rderrIntMask: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// SRBM_INT_STATUS
union SrbmIntStatus {
	struct {
		uint32 rderrIntStat: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// SRBM_MC_CLKEN_CNTL
union SrbmMcClkenCntl {
	struct {
		uint32 prefixDelayCnt: 4; // 0
		uint32 unknown1: 4;
		uint32 postDelayCnt: 5; // 8
		uint32 unknown2: 19;
	};
	uint32 val;
};

// SRBM_PERFCOUNTER0_HI
union SrbmPerfcounter0Hi {
	struct {
		uint32 perfCount0Hi: 32; // 0
	};
	uint32 val;
};

// SRBM_PERFCOUNTER0_LO
union SrbmPerfcounter0Lo {
	struct {
		uint32 perfCount0Lo: 32; // 0
	};
	uint32 val;
};

// SRBM_PERFCOUNTER0_SELECT
union SrbmPerfcounter0Select {
	struct {
		uint32 perfSel: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// SRBM_PERFCOUNTER1_HI
union SrbmPerfcounter1Hi {
	struct {
		uint32 perfCount1Hi: 32; // 0
	};
	uint32 val;
};

// SRBM_PERFCOUNTER1_LO
union SrbmPerfcounter1Lo {
	struct {
		uint32 perfCount1Lo: 32; // 0
	};
	uint32 val;
};

// SRBM_PERFCOUNTER1_SELECT
union SrbmPerfcounter1Select {
	struct {
		uint32 perfSel: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// SRBM_PERFMON_CNTL
union SrbmPerfmonCntl {
	struct {
		uint32 perfmonState: 4; // 0
		uint32 unknown1: 4;
		uint32 perfmonEnableMode: 2; // 8
		uint32 perfmonSampleEnable: 1; // 10
		uint32 unknown2: 21;
	};
	uint32 val;
};

// SRBM_READ_ERROR
union SrbmReadError {
	struct {
		uint32 unknown1: 2;
		uint32 readAddress: 16; // 2
		uint32 unknown2: 2;
		uint32 readRequesterVce: 1; // 20
		uint32 unknown3: 1;
		uint32 readRequesterTst: 1; // 22
		uint32 unknown4: 1;
		uint32 readRequesterHi: 1; // 24
		uint32 readRequesterGrbm: 1; // 25
		uint32 readRequesterSmu: 1; // 26
		uint32 unknown5: 2;
		uint32 readRequesterUvd: 1; // 29
		uint32 unknown6: 1;
		uint32 readError: 1; // 31
	};
	uint32 val;
};

// SRBM_SOFT_RESET
union SrbmSoftReset {
	struct {
		uint32 unknown1: 1;
		uint32 softResetBif: 1; // 1
		uint32 unknown2: 3;
		uint32 softResetDc: 1; // 5
		uint32 unknown3: 2;
		uint32 softResetGrbm: 1; // 8
		uint32 softResetHdp: 1; // 9
		uint32 softResetIh: 1; // 10
		uint32 softResetMc: 1; // 11
		uint32 unknown4: 2;
		uint32 softResetRom: 1; // 14
		uint32 softResetSem: 1; // 15
		uint32 unknown5: 1;
		uint32 softResetVmc: 1; // 17
		uint32 softResetUvd: 1; // 18
		uint32 softResetXsp: 1; // 19
		uint32 unknown6: 1;
		uint32 softResetTst: 1; // 21
		uint32 softResetRegbb: 1; // 22
		uint32 softResetOrb: 1; // 23
		uint32 softResetVce: 1; // 24
		uint32 softResetXdma: 1; // 25
		uint32 unknown7: 6;
	};
	uint32 val;
};

// SRBM_STATUS
union SrbmStatus {
	struct {
		uint32 unknown1: 1;
		uint32 uvdRqPending: 1; // 1
		uint32 unknown2: 2;
		uint32 smuRqPending: 1; // 4
		uint32 grbmRqPending: 1; // 5
		uint32 hiRqPending: 1; // 6
		uint32 ioExternSignal: 1; // 7
		uint32 vmcBusy: 1; // 8
		uint32 mcbBusy: 1; // 9
		uint32 mcbNonDisplayBusy: 1; // 10
		uint32 mccBusy: 1; // 11
		uint32 mcdBusy: 1; // 12
		uint32 unknown3: 1;
		uint32 semBusy: 1; // 14
		uint32 unknown4: 2;
		uint32 ihBusy: 1; // 17
		uint32 unknown5: 1;
		uint32 uvdBusy: 1; // 19
		uint32 unknown6: 9;
		uint32 bifBusy: 1; // 29
		uint32 unknown7: 2;
	};
	uint32 val;
};

// SRBM_STATUS2
union SrbmStatus2 {
	struct {
		uint32 unknown1: 1;
		uint32 tstRqPending: 1; // 1
		uint32 unknown2: 1;
		uint32 vceRqPending: 1; // 3
		uint32 xspBusy: 1; // 4
		uint32 unknown3: 2;
		uint32 vceBusy: 1; // 7
		uint32 xdmaBusy: 1; // 8
		uint32 unknown4: 23;
	};
	uint32 val;
};

// SRBM_SYS_CLKEN_CNTL
union SrbmSysClkenCntl {
	struct {
		uint32 prefixDelayCnt: 4; // 0
		uint32 unknown1: 4;
		uint32 postDelayCnt: 5; // 8
		uint32 unknown2: 19;
	};
	uint32 val;
};

// SRBM_UVD_CLKEN_CNTL
union SrbmUvdClkenCntl {
	struct {
		uint32 prefixDelayCnt: 4; // 0
		uint32 unknown1: 4;
		uint32 postDelayCnt: 5; // 8
		uint32 unknown2: 19;
	};
	uint32 val;
};

// SRBM_VCE_CLKEN_CNTL
union SrbmVceClkenCntl {
	struct {
		uint32 prefixDelayCnt: 4; // 0
		uint32 unknown1: 4;
		uint32 postDelayCnt: 5; // 8
		uint32 unknown2: 19;
	};
	uint32 val;
};

// UVD_CONFIG
union UvdConfig {
	struct {
		uint32 unknown1: 8;
		uint32 uvdRdreqUrg: 4; // 8
		uint32 unknown2: 4;
		uint32 uvdReqTran: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// VCE_CONFIG
union VceConfig {
	struct {
		uint32 unknown1: 8;
		uint32 vceRdreqUrg: 4; // 8
		uint32 unknown2: 4;
		uint32 vceReqTran: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// XDMA_MSTR_MEM_OVERFLOW_CNTL
union XdmaMstrMemOverflowCntl {
	struct {
		uint32 xdmaMstrOverflowCount: 16; // 0
		uint32 xdmaMstrOverflowThreshold: 14; // 16
		uint32 unknown1: 1;
		uint32 xdmaMstrOverflowCountEnable: 1; // 31
	};
	uint32 val;
};

