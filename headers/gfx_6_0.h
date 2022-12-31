#pragma once
#include <SupportDefs.h>

// BCI_DEBUG_READ
union BciDebugRead {
	struct {
		uint32 data: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// CB_BLEND0_CONTROL
union CbBlend0Control {
	struct {
		uint32 colorSrcblend: 5; // 0
		uint32 colorCombFcn: 3; // 5
		uint32 colorDestblend: 5; // 8
		uint32 unknown1: 3;
		uint32 alphaSrcblend: 5; // 16
		uint32 alphaCombFcn: 3; // 21
		uint32 alphaDestblend: 5; // 24
		uint32 separateAlphaBlend: 1; // 29
		uint32 enable: 1; // 30
		uint32 disableRop3: 1; // 31
	};
	uint32 val;
};

// CB_BLEND1_CONTROL
union CbBlend1Control {
	struct {
		uint32 colorSrcblend: 5; // 0
		uint32 colorCombFcn: 3; // 5
		uint32 colorDestblend: 5; // 8
		uint32 unknown1: 3;
		uint32 alphaSrcblend: 5; // 16
		uint32 alphaCombFcn: 3; // 21
		uint32 alphaDestblend: 5; // 24
		uint32 separateAlphaBlend: 1; // 29
		uint32 enable: 1; // 30
		uint32 disableRop3: 1; // 31
	};
	uint32 val;
};

// CB_BLEND2_CONTROL
union CbBlend2Control {
	struct {
		uint32 colorSrcblend: 5; // 0
		uint32 colorCombFcn: 3; // 5
		uint32 colorDestblend: 5; // 8
		uint32 unknown1: 3;
		uint32 alphaSrcblend: 5; // 16
		uint32 alphaCombFcn: 3; // 21
		uint32 alphaDestblend: 5; // 24
		uint32 separateAlphaBlend: 1; // 29
		uint32 enable: 1; // 30
		uint32 disableRop3: 1; // 31
	};
	uint32 val;
};

// CB_BLEND3_CONTROL
union CbBlend3Control {
	struct {
		uint32 colorSrcblend: 5; // 0
		uint32 colorCombFcn: 3; // 5
		uint32 colorDestblend: 5; // 8
		uint32 unknown1: 3;
		uint32 alphaSrcblend: 5; // 16
		uint32 alphaCombFcn: 3; // 21
		uint32 alphaDestblend: 5; // 24
		uint32 separateAlphaBlend: 1; // 29
		uint32 enable: 1; // 30
		uint32 disableRop3: 1; // 31
	};
	uint32 val;
};

// CB_BLEND4_CONTROL
union CbBlend4Control {
	struct {
		uint32 colorSrcblend: 5; // 0
		uint32 colorCombFcn: 3; // 5
		uint32 colorDestblend: 5; // 8
		uint32 unknown1: 3;
		uint32 alphaSrcblend: 5; // 16
		uint32 alphaCombFcn: 3; // 21
		uint32 alphaDestblend: 5; // 24
		uint32 separateAlphaBlend: 1; // 29
		uint32 enable: 1; // 30
		uint32 disableRop3: 1; // 31
	};
	uint32 val;
};

// CB_BLEND5_CONTROL
union CbBlend5Control {
	struct {
		uint32 colorSrcblend: 5; // 0
		uint32 colorCombFcn: 3; // 5
		uint32 colorDestblend: 5; // 8
		uint32 unknown1: 3;
		uint32 alphaSrcblend: 5; // 16
		uint32 alphaCombFcn: 3; // 21
		uint32 alphaDestblend: 5; // 24
		uint32 separateAlphaBlend: 1; // 29
		uint32 enable: 1; // 30
		uint32 disableRop3: 1; // 31
	};
	uint32 val;
};

// CB_BLEND6_CONTROL
union CbBlend6Control {
	struct {
		uint32 colorSrcblend: 5; // 0
		uint32 colorCombFcn: 3; // 5
		uint32 colorDestblend: 5; // 8
		uint32 unknown1: 3;
		uint32 alphaSrcblend: 5; // 16
		uint32 alphaCombFcn: 3; // 21
		uint32 alphaDestblend: 5; // 24
		uint32 separateAlphaBlend: 1; // 29
		uint32 enable: 1; // 30
		uint32 disableRop3: 1; // 31
	};
	uint32 val;
};

// CB_BLEND7_CONTROL
union CbBlend7Control {
	struct {
		uint32 colorSrcblend: 5; // 0
		uint32 colorCombFcn: 3; // 5
		uint32 colorDestblend: 5; // 8
		uint32 unknown1: 3;
		uint32 alphaSrcblend: 5; // 16
		uint32 alphaCombFcn: 3; // 21
		uint32 alphaDestblend: 5; // 24
		uint32 separateAlphaBlend: 1; // 29
		uint32 enable: 1; // 30
		uint32 disableRop3: 1; // 31
	};
	uint32 val;
};

// CB_BLEND_ALPHA
union CbBlendAlpha {
	struct {
		uint32 blendAlpha: 32; // 0
	};
	uint32 val;
};

// CB_BLEND_BLUE
union CbBlendBlue {
	struct {
		uint32 blendBlue: 32; // 0
	};
	uint32 val;
};

// CB_BLEND_GREEN
union CbBlendGreen {
	struct {
		uint32 blendGreen: 32; // 0
	};
	uint32 val;
};

// CB_BLEND_RED
union CbBlendRed {
	struct {
		uint32 blendRed: 32; // 0
	};
	uint32 val;
};

// CB_CGTT_SCLK_CTRL
union CbCgttSclkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 12;
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// CB_COLOR0_ATTRIB
union CbColor0Attrib {
	struct {
		uint32 tileModeIndex: 5; // 0
		uint32 fmaskTileModeIndex: 5; // 5
		uint32 fmaskBankHeight: 2; // 10
		uint32 numSamples: 3; // 12
		uint32 numFragments: 2; // 15
		uint32 forceDstAlpha1: 1; // 17
		uint32 unknown1: 14;
	};
	uint32 val;
};

// CB_COLOR0_BASE
union CbColor0Base {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR0_CLEAR_WORD0
union CbColor0ClearWord0 {
	struct {
		uint32 clearWord0: 32; // 0
	};
	uint32 val;
};

// CB_COLOR0_CLEAR_WORD1
union CbColor0ClearWord1 {
	struct {
		uint32 clearWord1: 32; // 0
	};
	uint32 val;
};

// CB_COLOR0_CMASK
union CbColor0Cmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR0_CMASK_SLICE
union CbColor0CmaskSlice {
	struct {
		uint32 tileMax: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// CB_COLOR0_FMASK
union CbColor0Fmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR0_FMASK_SLICE
union CbColor0FmaskSlice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR0_INFO
union CbColor0Info {
	struct {
		uint32 endian: 2; // 0
		uint32 format: 5; // 2
		uint32 linearGeneral: 1; // 7
		uint32 numberType: 3; // 8
		uint32 compSwap: 2; // 11
		uint32 fastClear: 1; // 13
		uint32 compression: 1; // 14
		uint32 blendClamp: 1; // 15
		uint32 blendBypass: 1; // 16
		uint32 simpleFloat: 1; // 17
		uint32 roundMode: 1; // 18
		uint32 cmaskIsLinear: 1; // 19
		uint32 blendOptDontRdDst: 3; // 20
		uint32 blendOptDiscardPixel: 3; // 23
		uint32 fmaskCompressionDisable: 1; // 26
		uint32 unknown1: 5;
	};
	uint32 val;
};

// CB_COLOR0_PITCH
union CbColor0Pitch {
	struct {
		uint32 tileMax: 11; // 0
		uint32 unknown1: 9;
		uint32 fmaskTileMax: 11; // 20
		uint32 unknown2: 1;
	};
	uint32 val;
};

// CB_COLOR0_SLICE
union CbColor0Slice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR0_VIEW
union CbColor0View {
	struct {
		uint32 sliceStart: 11; // 0
		uint32 unknown1: 2;
		uint32 sliceMax: 11; // 13
		uint32 unknown2: 8;
	};
	uint32 val;
};

// CB_COLOR1_ATTRIB
union CbColor1Attrib {
	struct {
		uint32 tileModeIndex: 5; // 0
		uint32 fmaskTileModeIndex: 5; // 5
		uint32 fmaskBankHeight: 2; // 10
		uint32 numSamples: 3; // 12
		uint32 numFragments: 2; // 15
		uint32 forceDstAlpha1: 1; // 17
		uint32 unknown1: 14;
	};
	uint32 val;
};

// CB_COLOR1_BASE
union CbColor1Base {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR1_CLEAR_WORD0
union CbColor1ClearWord0 {
	struct {
		uint32 clearWord0: 32; // 0
	};
	uint32 val;
};

// CB_COLOR1_CLEAR_WORD1
union CbColor1ClearWord1 {
	struct {
		uint32 clearWord1: 32; // 0
	};
	uint32 val;
};

// CB_COLOR1_CMASK
union CbColor1Cmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR1_CMASK_SLICE
union CbColor1CmaskSlice {
	struct {
		uint32 tileMax: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// CB_COLOR1_FMASK
union CbColor1Fmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR1_FMASK_SLICE
union CbColor1FmaskSlice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR1_INFO
union CbColor1Info {
	struct {
		uint32 endian: 2; // 0
		uint32 format: 5; // 2
		uint32 linearGeneral: 1; // 7
		uint32 numberType: 3; // 8
		uint32 compSwap: 2; // 11
		uint32 fastClear: 1; // 13
		uint32 compression: 1; // 14
		uint32 blendClamp: 1; // 15
		uint32 blendBypass: 1; // 16
		uint32 simpleFloat: 1; // 17
		uint32 roundMode: 1; // 18
		uint32 cmaskIsLinear: 1; // 19
		uint32 blendOptDontRdDst: 3; // 20
		uint32 blendOptDiscardPixel: 3; // 23
		uint32 fmaskCompressionDisable: 1; // 26
		uint32 unknown1: 5;
	};
	uint32 val;
};

// CB_COLOR1_PITCH
union CbColor1Pitch {
	struct {
		uint32 tileMax: 11; // 0
		uint32 unknown1: 9;
		uint32 fmaskTileMax: 11; // 20
		uint32 unknown2: 1;
	};
	uint32 val;
};

// CB_COLOR1_SLICE
union CbColor1Slice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR1_VIEW
union CbColor1View {
	struct {
		uint32 sliceStart: 11; // 0
		uint32 unknown1: 2;
		uint32 sliceMax: 11; // 13
		uint32 unknown2: 8;
	};
	uint32 val;
};

// CB_COLOR2_ATTRIB
union CbColor2Attrib {
	struct {
		uint32 tileModeIndex: 5; // 0
		uint32 fmaskTileModeIndex: 5; // 5
		uint32 fmaskBankHeight: 2; // 10
		uint32 numSamples: 3; // 12
		uint32 numFragments: 2; // 15
		uint32 forceDstAlpha1: 1; // 17
		uint32 unknown1: 14;
	};
	uint32 val;
};

// CB_COLOR2_BASE
union CbColor2Base {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR2_CLEAR_WORD0
union CbColor2ClearWord0 {
	struct {
		uint32 clearWord0: 32; // 0
	};
	uint32 val;
};

// CB_COLOR2_CLEAR_WORD1
union CbColor2ClearWord1 {
	struct {
		uint32 clearWord1: 32; // 0
	};
	uint32 val;
};

// CB_COLOR2_CMASK
union CbColor2Cmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR2_CMASK_SLICE
union CbColor2CmaskSlice {
	struct {
		uint32 tileMax: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// CB_COLOR2_FMASK
union CbColor2Fmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR2_FMASK_SLICE
union CbColor2FmaskSlice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR2_INFO
union CbColor2Info {
	struct {
		uint32 endian: 2; // 0
		uint32 format: 5; // 2
		uint32 linearGeneral: 1; // 7
		uint32 numberType: 3; // 8
		uint32 compSwap: 2; // 11
		uint32 fastClear: 1; // 13
		uint32 compression: 1; // 14
		uint32 blendClamp: 1; // 15
		uint32 blendBypass: 1; // 16
		uint32 simpleFloat: 1; // 17
		uint32 roundMode: 1; // 18
		uint32 cmaskIsLinear: 1; // 19
		uint32 blendOptDontRdDst: 3; // 20
		uint32 blendOptDiscardPixel: 3; // 23
		uint32 fmaskCompressionDisable: 1; // 26
		uint32 unknown1: 5;
	};
	uint32 val;
};

// CB_COLOR2_PITCH
union CbColor2Pitch {
	struct {
		uint32 tileMax: 11; // 0
		uint32 unknown1: 9;
		uint32 fmaskTileMax: 11; // 20
		uint32 unknown2: 1;
	};
	uint32 val;
};

// CB_COLOR2_SLICE
union CbColor2Slice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR2_VIEW
union CbColor2View {
	struct {
		uint32 sliceStart: 11; // 0
		uint32 unknown1: 2;
		uint32 sliceMax: 11; // 13
		uint32 unknown2: 8;
	};
	uint32 val;
};

// CB_COLOR3_ATTRIB
union CbColor3Attrib {
	struct {
		uint32 tileModeIndex: 5; // 0
		uint32 fmaskTileModeIndex: 5; // 5
		uint32 fmaskBankHeight: 2; // 10
		uint32 numSamples: 3; // 12
		uint32 numFragments: 2; // 15
		uint32 forceDstAlpha1: 1; // 17
		uint32 unknown1: 14;
	};
	uint32 val;
};

// CB_COLOR3_BASE
union CbColor3Base {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR3_CLEAR_WORD0
union CbColor3ClearWord0 {
	struct {
		uint32 clearWord0: 32; // 0
	};
	uint32 val;
};

// CB_COLOR3_CLEAR_WORD1
union CbColor3ClearWord1 {
	struct {
		uint32 clearWord1: 32; // 0
	};
	uint32 val;
};

// CB_COLOR3_CMASK
union CbColor3Cmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR3_CMASK_SLICE
union CbColor3CmaskSlice {
	struct {
		uint32 tileMax: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// CB_COLOR3_FMASK
union CbColor3Fmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR3_FMASK_SLICE
union CbColor3FmaskSlice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR3_INFO
union CbColor3Info {
	struct {
		uint32 endian: 2; // 0
		uint32 format: 5; // 2
		uint32 linearGeneral: 1; // 7
		uint32 numberType: 3; // 8
		uint32 compSwap: 2; // 11
		uint32 fastClear: 1; // 13
		uint32 compression: 1; // 14
		uint32 blendClamp: 1; // 15
		uint32 blendBypass: 1; // 16
		uint32 simpleFloat: 1; // 17
		uint32 roundMode: 1; // 18
		uint32 cmaskIsLinear: 1; // 19
		uint32 blendOptDontRdDst: 3; // 20
		uint32 blendOptDiscardPixel: 3; // 23
		uint32 fmaskCompressionDisable: 1; // 26
		uint32 unknown1: 5;
	};
	uint32 val;
};

// CB_COLOR3_PITCH
union CbColor3Pitch {
	struct {
		uint32 tileMax: 11; // 0
		uint32 unknown1: 9;
		uint32 fmaskTileMax: 11; // 20
		uint32 unknown2: 1;
	};
	uint32 val;
};

// CB_COLOR3_SLICE
union CbColor3Slice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR3_VIEW
union CbColor3View {
	struct {
		uint32 sliceStart: 11; // 0
		uint32 unknown1: 2;
		uint32 sliceMax: 11; // 13
		uint32 unknown2: 8;
	};
	uint32 val;
};

// CB_COLOR4_ATTRIB
union CbColor4Attrib {
	struct {
		uint32 tileModeIndex: 5; // 0
		uint32 fmaskTileModeIndex: 5; // 5
		uint32 fmaskBankHeight: 2; // 10
		uint32 numSamples: 3; // 12
		uint32 numFragments: 2; // 15
		uint32 forceDstAlpha1: 1; // 17
		uint32 unknown1: 14;
	};
	uint32 val;
};

// CB_COLOR4_BASE
union CbColor4Base {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR4_CLEAR_WORD0
union CbColor4ClearWord0 {
	struct {
		uint32 clearWord0: 32; // 0
	};
	uint32 val;
};

// CB_COLOR4_CLEAR_WORD1
union CbColor4ClearWord1 {
	struct {
		uint32 clearWord1: 32; // 0
	};
	uint32 val;
};

// CB_COLOR4_CMASK
union CbColor4Cmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR4_CMASK_SLICE
union CbColor4CmaskSlice {
	struct {
		uint32 tileMax: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// CB_COLOR4_FMASK
union CbColor4Fmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR4_FMASK_SLICE
union CbColor4FmaskSlice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR4_INFO
union CbColor4Info {
	struct {
		uint32 endian: 2; // 0
		uint32 format: 5; // 2
		uint32 linearGeneral: 1; // 7
		uint32 numberType: 3; // 8
		uint32 compSwap: 2; // 11
		uint32 fastClear: 1; // 13
		uint32 compression: 1; // 14
		uint32 blendClamp: 1; // 15
		uint32 blendBypass: 1; // 16
		uint32 simpleFloat: 1; // 17
		uint32 roundMode: 1; // 18
		uint32 cmaskIsLinear: 1; // 19
		uint32 blendOptDontRdDst: 3; // 20
		uint32 blendOptDiscardPixel: 3; // 23
		uint32 fmaskCompressionDisable: 1; // 26
		uint32 unknown1: 5;
	};
	uint32 val;
};

// CB_COLOR4_PITCH
union CbColor4Pitch {
	struct {
		uint32 tileMax: 11; // 0
		uint32 unknown1: 9;
		uint32 fmaskTileMax: 11; // 20
		uint32 unknown2: 1;
	};
	uint32 val;
};

// CB_COLOR4_SLICE
union CbColor4Slice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR4_VIEW
union CbColor4View {
	struct {
		uint32 sliceStart: 11; // 0
		uint32 unknown1: 2;
		uint32 sliceMax: 11; // 13
		uint32 unknown2: 8;
	};
	uint32 val;
};

// CB_COLOR5_ATTRIB
union CbColor5Attrib {
	struct {
		uint32 tileModeIndex: 5; // 0
		uint32 fmaskTileModeIndex: 5; // 5
		uint32 fmaskBankHeight: 2; // 10
		uint32 numSamples: 3; // 12
		uint32 numFragments: 2; // 15
		uint32 forceDstAlpha1: 1; // 17
		uint32 unknown1: 14;
	};
	uint32 val;
};

// CB_COLOR5_BASE
union CbColor5Base {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR5_CLEAR_WORD0
union CbColor5ClearWord0 {
	struct {
		uint32 clearWord0: 32; // 0
	};
	uint32 val;
};

// CB_COLOR5_CLEAR_WORD1
union CbColor5ClearWord1 {
	struct {
		uint32 clearWord1: 32; // 0
	};
	uint32 val;
};

// CB_COLOR5_CMASK
union CbColor5Cmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR5_CMASK_SLICE
union CbColor5CmaskSlice {
	struct {
		uint32 tileMax: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// CB_COLOR5_FMASK
union CbColor5Fmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR5_FMASK_SLICE
union CbColor5FmaskSlice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR5_INFO
union CbColor5Info {
	struct {
		uint32 endian: 2; // 0
		uint32 format: 5; // 2
		uint32 linearGeneral: 1; // 7
		uint32 numberType: 3; // 8
		uint32 compSwap: 2; // 11
		uint32 fastClear: 1; // 13
		uint32 compression: 1; // 14
		uint32 blendClamp: 1; // 15
		uint32 blendBypass: 1; // 16
		uint32 simpleFloat: 1; // 17
		uint32 roundMode: 1; // 18
		uint32 cmaskIsLinear: 1; // 19
		uint32 blendOptDontRdDst: 3; // 20
		uint32 blendOptDiscardPixel: 3; // 23
		uint32 fmaskCompressionDisable: 1; // 26
		uint32 unknown1: 5;
	};
	uint32 val;
};

// CB_COLOR5_PITCH
union CbColor5Pitch {
	struct {
		uint32 tileMax: 11; // 0
		uint32 unknown1: 9;
		uint32 fmaskTileMax: 11; // 20
		uint32 unknown2: 1;
	};
	uint32 val;
};

// CB_COLOR5_SLICE
union CbColor5Slice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR5_VIEW
union CbColor5View {
	struct {
		uint32 sliceStart: 11; // 0
		uint32 unknown1: 2;
		uint32 sliceMax: 11; // 13
		uint32 unknown2: 8;
	};
	uint32 val;
};

// CB_COLOR6_ATTRIB
union CbColor6Attrib {
	struct {
		uint32 tileModeIndex: 5; // 0
		uint32 fmaskTileModeIndex: 5; // 5
		uint32 fmaskBankHeight: 2; // 10
		uint32 numSamples: 3; // 12
		uint32 numFragments: 2; // 15
		uint32 forceDstAlpha1: 1; // 17
		uint32 unknown1: 14;
	};
	uint32 val;
};

// CB_COLOR6_BASE
union CbColor6Base {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR6_CLEAR_WORD0
union CbColor6ClearWord0 {
	struct {
		uint32 clearWord0: 32; // 0
	};
	uint32 val;
};

// CB_COLOR6_CLEAR_WORD1
union CbColor6ClearWord1 {
	struct {
		uint32 clearWord1: 32; // 0
	};
	uint32 val;
};

// CB_COLOR6_CMASK
union CbColor6Cmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR6_CMASK_SLICE
union CbColor6CmaskSlice {
	struct {
		uint32 tileMax: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// CB_COLOR6_FMASK
union CbColor6Fmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR6_FMASK_SLICE
union CbColor6FmaskSlice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR6_INFO
union CbColor6Info {
	struct {
		uint32 endian: 2; // 0
		uint32 format: 5; // 2
		uint32 linearGeneral: 1; // 7
		uint32 numberType: 3; // 8
		uint32 compSwap: 2; // 11
		uint32 fastClear: 1; // 13
		uint32 compression: 1; // 14
		uint32 blendClamp: 1; // 15
		uint32 blendBypass: 1; // 16
		uint32 simpleFloat: 1; // 17
		uint32 roundMode: 1; // 18
		uint32 cmaskIsLinear: 1; // 19
		uint32 blendOptDontRdDst: 3; // 20
		uint32 blendOptDiscardPixel: 3; // 23
		uint32 fmaskCompressionDisable: 1; // 26
		uint32 unknown1: 5;
	};
	uint32 val;
};

// CB_COLOR6_PITCH
union CbColor6Pitch {
	struct {
		uint32 tileMax: 11; // 0
		uint32 unknown1: 9;
		uint32 fmaskTileMax: 11; // 20
		uint32 unknown2: 1;
	};
	uint32 val;
};

// CB_COLOR6_SLICE
union CbColor6Slice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR6_VIEW
union CbColor6View {
	struct {
		uint32 sliceStart: 11; // 0
		uint32 unknown1: 2;
		uint32 sliceMax: 11; // 13
		uint32 unknown2: 8;
	};
	uint32 val;
};

// CB_COLOR7_ATTRIB
union CbColor7Attrib {
	struct {
		uint32 tileModeIndex: 5; // 0
		uint32 fmaskTileModeIndex: 5; // 5
		uint32 fmaskBankHeight: 2; // 10
		uint32 numSamples: 3; // 12
		uint32 numFragments: 2; // 15
		uint32 forceDstAlpha1: 1; // 17
		uint32 unknown1: 14;
	};
	uint32 val;
};

// CB_COLOR7_BASE
union CbColor7Base {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR7_CLEAR_WORD0
union CbColor7ClearWord0 {
	struct {
		uint32 clearWord0: 32; // 0
	};
	uint32 val;
};

// CB_COLOR7_CLEAR_WORD1
union CbColor7ClearWord1 {
	struct {
		uint32 clearWord1: 32; // 0
	};
	uint32 val;
};

// CB_COLOR7_CMASK
union CbColor7Cmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR7_CMASK_SLICE
union CbColor7CmaskSlice {
	struct {
		uint32 tileMax: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// CB_COLOR7_FMASK
union CbColor7Fmask {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// CB_COLOR7_FMASK_SLICE
union CbColor7FmaskSlice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR7_INFO
union CbColor7Info {
	struct {
		uint32 endian: 2; // 0
		uint32 format: 5; // 2
		uint32 linearGeneral: 1; // 7
		uint32 numberType: 3; // 8
		uint32 compSwap: 2; // 11
		uint32 fastClear: 1; // 13
		uint32 compression: 1; // 14
		uint32 blendClamp: 1; // 15
		uint32 blendBypass: 1; // 16
		uint32 simpleFloat: 1; // 17
		uint32 roundMode: 1; // 18
		uint32 cmaskIsLinear: 1; // 19
		uint32 blendOptDontRdDst: 3; // 20
		uint32 blendOptDiscardPixel: 3; // 23
		uint32 fmaskCompressionDisable: 1; // 26
		uint32 unknown1: 5;
	};
	uint32 val;
};

// CB_COLOR7_PITCH
union CbColor7Pitch {
	struct {
		uint32 tileMax: 11; // 0
		uint32 unknown1: 9;
		uint32 fmaskTileMax: 11; // 20
		uint32 unknown2: 1;
	};
	uint32 val;
};

// CB_COLOR7_SLICE
union CbColor7Slice {
	struct {
		uint32 tileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CB_COLOR7_VIEW
union CbColor7View {
	struct {
		uint32 sliceStart: 11; // 0
		uint32 unknown1: 2;
		uint32 sliceMax: 11; // 13
		uint32 unknown2: 8;
	};
	uint32 val;
};

// CB_COLOR_CONTROL
union CbColorControl {
	struct {
		uint32 unknown1: 3;
		uint32 degammaEnable: 1; // 3
		uint32 mode: 3; // 4
		uint32 unknown2: 9;
		uint32 rop3: 8; // 16
		uint32 unknown3: 8;
	};
	uint32 val;
};

// CB_DEBUG_BUS_13
union CbDebugBus13 {
	struct {
		uint32 tileIntfcBusy: 1; // 0
		uint32 muBusy: 1; // 1
		uint32 tqBusy: 1; // 2
		uint32 acBusy: 1; // 3
		uint32 crwBusy: 1; // 4
		uint32 cacheCtrlBusy: 1; // 5
		uint32 mcWrPending: 1; // 6
		uint32 fcWrPending: 1; // 7
		uint32 fcRdPending: 1; // 8
		uint32 evictPending: 1; // 9
		uint32 lastRdArbWinner: 1; // 10
		uint32 muState: 8; // 11
		uint32 unknown1: 13;
	};
	uint32 val;
};

// CB_DEBUG_BUS_14
union CbDebugBus14 {
	struct {
		uint32 tileRetirementBusy: 1; // 0
		uint32 fopBusy: 1; // 1
		uint32 latBusy: 1; // 2
		uint32 cacheCtlBusy: 1; // 3
		uint32 addrBusy: 1; // 4
		uint32 mergeBusy: 1; // 5
		uint32 quadBusy: 1; // 6
		uint32 tileBusy: 1; // 7
		uint32 clearBusy: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// CB_DEBUG_BUS_15
union CbDebugBus15 {
	struct {
		uint32 surfSyncState: 2; // 0
		uint32 surfSyncStart: 1; // 2
		uint32 sfBusy: 1; // 3
		uint32 csBusy: 1; // 4
		uint32 rbBusy: 1; // 5
		uint32 dsBusy: 1; // 6
		uint32 tbBusy: 1; // 7
		uint32 ibBusy: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// CB_DEBUG_BUS_16
union CbDebugBus16 {
	struct {
		uint32 mcRdreqCredits: 6; // 0
		uint32 lastRdGrantVec: 4; // 6
		uint32 mcWrreqCredits: 6; // 10
		uint32 lastWrGrantVec: 4; // 16
		uint32 ccWrreqFifoEmpty: 1; // 20
		uint32 fcWrreqFifoEmpty: 1; // 21
		uint32 cmWrreqFifoEmpty: 1; // 22
		uint32 unknown1: 9;
	};
	uint32 val;
};

// CB_DEBUG_BUS_17
union CbDebugBus17 {
	struct {
		uint32 cmBusy: 1; // 0
		uint32 fcBusy: 1; // 1
		uint32 ccBusy: 1; // 2
		uint32 bbBusy: 1; // 3
		uint32 maBusy: 1; // 4
		uint32 coreSclkVld: 1; // 5
		uint32 regSclk1Vld: 1; // 6
		uint32 regSclk0Vld: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CB_DEBUG_BUS_18
union CbDebugBus18 {
	struct {
		uint32 notUsed: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// CB_HW_CONTROL
union CbHwControl {
	struct {
		uint32 cmCacheEvictPoint: 4; // 0
		uint32 unknown1: 2;
		uint32 fcCacheEvictPoint: 4; // 6
		uint32 unknown2: 2;
		uint32 ccCacheEvictPoint: 4; // 12
		uint32 allowMrtWithDualSource: 1; // 16
		uint32 unknown3: 1;
		uint32 disableIntnormLe11bpcClamping: 1; // 18
		uint32 forceNeedsDst: 1; // 19
		uint32 forceAlwaysToggle: 1; // 20
		uint32 disableBlendOptResultEqDest: 1; // 21
		uint32 disableFullWriteMask: 1; // 22
		uint32 disableResolveOptForSingleFrag: 1; // 23
		uint32 disableBlendOptDontRdDst: 1; // 24
		uint32 disableBlendOptBypass: 1; // 25
		uint32 disableBlendOptDiscardPixel: 1; // 26
		uint32 disableBlendOptWhenDisabledSrcalphaIsUsed: 1; // 27
		uint32 prioritizeFcWrOverFcRdOnCmaskConflict: 1; // 28
		uint32 prioritizeFcEvictOverFopRdOnBankConflict: 1; // 29
		uint32 disableCcIbSerializerStateOpt: 1; // 30
		uint32 disablePixelInQuadFixForLinearSurface: 1; // 31
	};
	uint32 val;
};

// CB_HW_CONTROL_1
union CbHwControl1 {
	struct {
		uint32 cmCacheNumTags: 5; // 0
		uint32 fcCacheNumTags: 6; // 5
		uint32 ccCacheNumTags: 6; // 11
		uint32 cmTileFifoDepth: 9; // 17
		uint32 chickenBits: 6; // 26
	};
	uint32 val;
};

// CB_HW_CONTROL_2
union CbHwControl2 {
	struct {
		uint32 ccEvenOddFifoDepth: 8; // 0
		uint32 fcRdlatTileFifoDepth: 7; // 8
		uint32 fcRdlatQuadFifoDepth: 8; // 15
		uint32 chickenBits: 9; // 23
	};
	uint32 val;
};

// CB_HW_CONTROL_3
union CbHwControl3 {
	struct {
		uint32 disableSlowModeEmptyHalfQuadKill: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CB_PERFCOUNTER0_HI
union CbPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// CB_PERFCOUNTER0_LO
union CbPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// CB_PERFCOUNTER0_SELECT1
union CbPerfcounter0Select1 {
	struct {
		uint32 perfSel2: 9; // 0
		uint32 unknown1: 1;
		uint32 perfSel3: 9; // 10
		uint32 unknown2: 5;
		uint32 perfMode3: 4; // 24
		uint32 perfMode2: 4; // 28
	};
	uint32 val;
};

// CB_PERFCOUNTER1_HI
union CbPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// CB_PERFCOUNTER1_LO
union CbPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// CB_PERFCOUNTER2_HI
union CbPerfcounter2Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// CB_PERFCOUNTER2_LO
union CbPerfcounter2Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// CB_PERFCOUNTER3_HI
union CbPerfcounter3Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// CB_PERFCOUNTER3_LO
union CbPerfcounter3Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// CB_SHADER_MASK
union CbShaderMask {
	struct {
		uint32 output0Enable: 4; // 0
		uint32 output1Enable: 4; // 4
		uint32 output2Enable: 4; // 8
		uint32 output3Enable: 4; // 12
		uint32 output4Enable: 4; // 16
		uint32 output5Enable: 4; // 20
		uint32 output6Enable: 4; // 24
		uint32 output7Enable: 4; // 28
	};
	uint32 val;
};

// CB_TARGET_MASK
union CbTargetMask {
	struct {
		uint32 target0Enable: 4; // 0
		uint32 target1Enable: 4; // 4
		uint32 target2Enable: 4; // 8
		uint32 target3Enable: 4; // 12
		uint32 target4Enable: 4; // 16
		uint32 target5Enable: 4; // 20
		uint32 target6Enable: 4; // 24
		uint32 target7Enable: 4; // 28
	};
	uint32 val;
};

// CC_GC_SHADER_ARRAY_CONFIG
union CcGcShaderArrayConfig {
	struct {
		uint32 unknown1: 1;
		uint32 dpfpRate: 2; // 1
		uint32 sqcBalanceDisable: 1; // 3
		uint32 halfLds: 1; // 4
		uint32 unknown2: 11;
		uint32 inactiveCus: 16; // 16
	};
	uint32 val;
};

// CC_RB_BACKEND_DISABLE
union CcRbBackendDisable {
	struct {
		uint32 unknown1: 16;
		uint32 backendDisable: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// CC_RB_DAISY_CHAIN
union CcRbDaisyChain {
	struct {
		uint32 rb0: 4; // 0
		uint32 rb1: 4; // 4
		uint32 rb2: 4; // 8
		uint32 rb3: 4; // 12
		uint32 rb4: 4; // 16
		uint32 rb5: 4; // 20
		uint32 rb6: 4; // 24
		uint32 rb7: 4; // 28
	};
	uint32 val;
};

// CC_RB_REDUNDANCY
union CcRbRedundancy {
	struct {
		uint32 unknown1: 8;
		uint32 failedRb0: 4; // 8
		uint32 enRedundancy0: 1; // 12
		uint32 unknown2: 3;
		uint32 failedRb1: 4; // 16
		uint32 enRedundancy1: 1; // 20
		uint32 unknown3: 11;
	};
	uint32 val;
};

// CC_SQC_BANK_DISABLE
union CcSqcBankDisable {
	struct {
		uint32 unknown1: 16;
		uint32 sqc0BankDisable: 4; // 16
		uint32 sqc1BankDisable: 4; // 20
		uint32 sqc2BankDisable: 4; // 24
		uint32 sqc3BankDisable: 4; // 28
	};
	uint32 val;
};

// CGTS_RD_CTRL_REG
union CgtsRdCtrlReg {
	struct {
		uint32 rowMuxSel: 5; // 0
		uint32 unknown1: 3;
		uint32 regMuxSel: 5; // 8
		uint32 unknown2: 19;
	};
	uint32 val;
};

// CGTS_RD_REG
union CgtsRdReg {
	struct {
		uint32 readData: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// CGTS_SM_CTRL_REG
union CgtsSmCtrlReg {
	struct {
		uint32 onSeqDelay: 4; // 0
		uint32 offSeqDelay: 8; // 4
		uint32 mgcgEnabled: 1; // 12
		uint32 unknown1: 3;
		uint32 baseMode: 1; // 16
		uint32 smMode: 3; // 17
		uint32 smModeEnable: 1; // 20
		uint32 override: 1; // 21
		uint32 lsOverride: 1; // 22
		uint32 onMonitorAddEn: 1; // 23
		uint32 onMonitorAdd: 8; // 24
	};
	uint32 val;
};

// CGTS_TCC_DISABLE
union CgtsTccDisable {
	struct {
		uint32 unknown1: 16;
		uint32 tccDisable: 16; // 16
	};
	uint32 val;
};

// CGTS_USER_TCC_DISABLE
union CgtsUserTccDisable {
	struct {
		uint32 unknown1: 16;
		uint32 tccDisable: 16; // 16
	};
	uint32 val;
};

// CGTT_BCI_CLK_CTRL
union CgttBciClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 reserved: 12; // 12
		uint32 core6Override: 1; // 24
		uint32 core5Override: 1; // 25
		uint32 core4Override: 1; // 26
		uint32 core3Override: 1; // 27
		uint32 core2Override: 1; // 28
		uint32 core1Override: 1; // 29
		uint32 core0Override: 1; // 30
		uint32 regOverride: 1; // 31
	};
	uint32 val;
};

// CGTT_CP_CLK_CTRL
union CgttCpClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 18;
		uint32 softOverrideDyn: 1; // 30
		uint32 softOverrideReg: 1; // 31
	};
	uint32 val;
};

// CGTT_GDS_CLK_CTRL
union CgttGdsClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 12;
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// CGTT_IA_CLK_CTRL
union CgttIaClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 12;
		uint32 softOverride7: 1; // 24
		uint32 perfEnable: 1; // 25
		uint32 dbgEnable: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 coreOverride: 1; // 29
		uint32 unknown2: 1;
		uint32 regOverride: 1; // 31
	};
	uint32 val;
};

// CGTT_PA_CLK_CTRL
union CgttPaClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 12;
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 suClkOverride: 1; // 29
		uint32 clClkOverride: 1; // 30
		uint32 regClkOverride: 1; // 31
	};
	uint32 val;
};

// CGTT_PC_CLK_CTRL
union CgttPcClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 6;
		uint32 grp5CgOffHyst: 6; // 18
		uint32 grp5CgOverride: 1; // 24
		uint32 backClkOnOverride: 1; // 25
		uint32 frontClkOnOverride: 1; // 26
		uint32 core3Override: 1; // 27
		uint32 core2Override: 1; // 28
		uint32 core1Override: 1; // 29
		uint32 core0Override: 1; // 30
		uint32 regOverride: 1; // 31
	};
	uint32 val;
};

// CGTT_RLC_CLK_CTRL
union CgttRlcClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 18;
		uint32 softOverrideDyn: 1; // 30
		uint32 softOverrideReg: 1; // 31
	};
	uint32 val;
};

// CGTT_SC_CLK_CTRL
union CgttScClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 12;
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// CGTT_SPI_CLK_CTRL
union CgttSpiClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 6;
		uint32 grp5CgOffHyst: 6; // 18
		uint32 grp5CgOverride: 1; // 24
		uint32 unknown2: 1;
		uint32 allClkOnOverride: 1; // 26
		uint32 grp3Override: 1; // 27
		uint32 grp2Override: 1; // 28
		uint32 grp1Override: 1; // 29
		uint32 grp0Override: 1; // 30
		uint32 regOverride: 1; // 31
	};
	uint32 val;
};

// CGTT_SQG_CLK_CTRL
union CgttSqgClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 18;
		uint32 coreOverride: 1; // 30
		uint32 regOverride: 1; // 31
	};
	uint32 val;
};

// CGTT_SQ_CLK_CTRL
union CgttSqClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 18;
		uint32 coreOverride: 1; // 30
		uint32 regOverride: 1; // 31
	};
	uint32 val;
};

// CGTT_SX_CLK_CTRL0
union CgttSxClkCtrl0 {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 reserved: 12; // 12
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// CGTT_SX_CLK_CTRL1
union CgttSxClkCtrl1 {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 reserved: 12; // 12
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// CGTT_SX_CLK_CTRL2
union CgttSxClkCtrl2 {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 reserved: 12; // 12
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// CGTT_SX_CLK_CTRL3
union CgttSxClkCtrl3 {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 reserved: 12; // 12
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// CGTT_SX_CLK_CTRL4
union CgttSxClkCtrl4 {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 reserved: 12; // 12
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// CGTT_TCI_CLK_CTRL
union CgttTciClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 12;
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// CGTT_TCP_CLK_CTRL
union CgttTcpClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 12;
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// CGTT_VGT_CLK_CTRL
union CgttVgtClkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 12;
		uint32 softOverride7: 1; // 24
		uint32 perfEnable: 1; // 25
		uint32 dbgEnable: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 gsOverride: 1; // 29
		uint32 coreOverride: 1; // 30
		uint32 regOverride: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG00
union ClipperDebugReg00 {
	struct {
		uint32 alwaysZero: 8; // 0
		uint32 clipGaBcFifoWrite: 1; // 8
		uint32 suClipBarycFree: 2; // 9
		uint32 clipToGaFifoWrite: 1; // 11
		uint32 clipToGaFifoFull: 1; // 12
		uint32 primicToClprimFifoEmpty: 1; // 13
		uint32 primicToClprimFifoFull: 1; // 14
		uint32 clipToOutsmFifoEmpty: 1; // 15
		uint32 clipToOutsmFifoFull: 1; // 16
		uint32 vgtToClippFifoEmpty: 1; // 17
		uint32 vgtToClippFifoFull: 1; // 18
		uint32 vgtToClipsFifoEmpty: 1; // 19
		uint32 vgtToClipsFifoFull: 1; // 20
		uint32 clipcodeFifoFifoEmpty: 1; // 21
		uint32 clipcodeFifoFull: 1; // 22
		uint32 vteOutClipFifoFifoEmpty: 1; // 23
		uint32 vteOutClipFifoFifoFull: 1; // 24
		uint32 vteOutOrigFifoFifoEmpty: 1; // 25
		uint32 vteOutOrigFifoFifoFull: 1; // 26
		uint32 ccgenToClipccFifoEmpty: 1; // 27
		uint32 ccgenToClipccFifoFull: 1; // 28
		uint32 clipToOutsmFifoWrite: 1; // 29
		uint32 vteOutOrigFifoFifoWrite: 1; // 30
		uint32 vgtToClippFifoWrite: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG01
union ClipperDebugReg01 {
	struct {
		uint32 alwaysZero: 8; // 0
		uint32 clipExtraBcValid: 3; // 8
		uint32 clipVertVteValid: 3; // 11
		uint32 clipToOutsmVertexDeallocate: 3; // 14
		uint32 clipToOutsmDeallocateSlot: 3; // 17
		uint32 clipToOutsmNullPrimitive: 1; // 20
		uint32 vtePositionsVteClipVteNaninfKill2: 1; // 21
		uint32 vtePositionsVteClipVteNaninfKill1: 1; // 22
		uint32 vtePositionsVteClipVteNaninfKill0: 1; // 23
		uint32 vteOutClipRdExtraBcValid: 1; // 24
		uint32 vteOutClipRdVteNaninfKill: 1; // 25
		uint32 vteOutClipRdVertexStoreIndx: 2; // 26
		uint32 clipGaBcFifoWrite: 1; // 28
		uint32 clipToGaFifoWrite: 1; // 29
		uint32 vteOutClipFifoFifoAdvanceread: 1; // 30
		uint32 vteOutClipFifoFifoEmpty: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG02
union ClipperDebugReg02 {
	struct {
		uint32 clipExtraBcValid: 3; // 0
		uint32 clipVertVteValid: 3; // 3
		uint32 clipToOutsmClipSeqIndx: 2; // 6
		uint32 clipToOutsmVertexStoreIndx2: 4; // 8
		uint32 clipToOutsmVertexStoreIndx1: 4; // 12
		uint32 clipToOutsmVertexStoreIndx0: 4; // 16
		uint32 clipToClipgaExtraBcCoords: 1; // 20
		uint32 clipToClipgaVteNaninfKill: 1; // 21
		uint32 clipToOutsmEndOfPacket: 1; // 22
		uint32 clipToOutsmFirstPrimOfSlot: 1; // 23
		uint32 clipToOutsmClippedPrim: 1; // 24
		uint32 clipToOutsmNullPrimitive: 1; // 25
		uint32 clipGaBcFifoFull: 1; // 26
		uint32 clipToGaFifoFull: 1; // 27
		uint32 clipGaBcFifoWrite: 1; // 28
		uint32 clipToGaFifoWrite: 1; // 29
		uint32 clipToOutsmFifoAdvanceread: 1; // 30
		uint32 clipToOutsmFifoEmpty: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG03
union ClipperDebugReg03 {
	struct {
		uint32 clipsm0ClprimToClipClipCodeOr: 14; // 0
		uint32 clipsm0ClprimToClipEventId: 6; // 14
		uint32 clipsm0ClprimToClipStateVarIndx: 3; // 20
		uint32 clipsm0ClprimToClipClipPrimitive: 1; // 23
		uint32 clipsm0ClprimToClipDeallocateSlot: 3; // 24
		uint32 clipsm0ClprimToClipFirstPrimOfSlot: 1; // 27
		uint32 clipsm0ClprimToClipEndOfPacket: 1; // 28
		uint32 clipsm0ClprimToClipEvent: 1; // 29
		uint32 clipsm0ClprimToClipNullPrimitive: 1; // 30
		uint32 clipsm0ClprimToClipPrimValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG04
union ClipperDebugReg04 {
	struct {
		uint32 unknown1: 1;
		uint32 clipsm0ClprimToClipParamCacheIndx0: 10; // 1
		uint32 clipsm0ClprimToClipVertexStoreIndx2: 6; // 11
		uint32 clipsm0ClprimToClipVertexStoreIndx1: 6; // 17
		uint32 clipsm0ClprimToClipVertexStoreIndx0: 6; // 23
		uint32 clipsm0ClprimToClipEvent: 1; // 29
		uint32 clipsm0ClprimToClipNullPrimitive: 1; // 30
		uint32 clipsm0ClprimToClipPrimValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG05
union ClipperDebugReg05 {
	struct {
		uint32 clipsm1ClprimToClipClipCodeOr: 14; // 0
		uint32 clipsm1ClprimToClipEventId: 6; // 14
		uint32 clipsm1ClprimToClipStateVarIndx: 3; // 20
		uint32 clipsm1ClprimToClipClipPrimitive: 1; // 23
		uint32 clipsm1ClprimToClipDeallocateSlot: 3; // 24
		uint32 clipsm1ClprimToClipFirstPrimOfSlot: 1; // 27
		uint32 clipsm1ClprimToClipEndOfPacket: 1; // 28
		uint32 clipsm1ClprimToClipEvent: 1; // 29
		uint32 clipsm1ClprimToClipNullPrimitive: 1; // 30
		uint32 clipsm1ClprimToClipPrimValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG06
union ClipperDebugReg06 {
	struct {
		uint32 unknown1: 1;
		uint32 clipsm1ClprimToClipParamCacheIndx0: 10; // 1
		uint32 clipsm1ClprimToClipVertexStoreIndx2: 6; // 11
		uint32 clipsm1ClprimToClipVertexStoreIndx1: 6; // 17
		uint32 clipsm1ClprimToClipVertexStoreIndx0: 6; // 23
		uint32 clipsm1ClprimToClipEvent: 1; // 29
		uint32 clipsm1ClprimToClipNullPrimitive: 1; // 30
		uint32 clipsm1ClprimToClipPrimValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG07
union ClipperDebugReg07 {
	struct {
		uint32 clipsm2ClprimToClipClipCodeOr: 14; // 0
		uint32 clipsm2ClprimToClipEventId: 6; // 14
		uint32 clipsm2ClprimToClipStateVarIndx: 3; // 20
		uint32 clipsm2ClprimToClipClipPrimitive: 1; // 23
		uint32 clipsm2ClprimToClipDeallocateSlot: 3; // 24
		uint32 clipsm2ClprimToClipFirstPrimOfSlot: 1; // 27
		uint32 clipsm2ClprimToClipEndOfPacket: 1; // 28
		uint32 clipsm2ClprimToClipEvent: 1; // 29
		uint32 clipsm2ClprimToClipNullPrimitive: 1; // 30
		uint32 clipsm2ClprimToClipPrimValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG08
union ClipperDebugReg08 {
	struct {
		uint32 unknown1: 1;
		uint32 clipsm2ClprimToClipParamCacheIndx0: 10; // 1
		uint32 clipsm2ClprimToClipVertexStoreIndx2: 6; // 11
		uint32 clipsm2ClprimToClipVertexStoreIndx1: 6; // 17
		uint32 clipsm2ClprimToClipVertexStoreIndx0: 6; // 23
		uint32 clipsm2ClprimToClipEvent: 1; // 29
		uint32 clipsm2ClprimToClipNullPrimitive: 1; // 30
		uint32 clipsm2ClprimToClipPrimValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG09
union ClipperDebugReg09 {
	struct {
		uint32 clipsm3ClprimToClipClipCodeOr: 14; // 0
		uint32 clipsm3ClprimToClipEventId: 6; // 14
		uint32 clipsm3ClprimToClipStateVarIndx: 3; // 20
		uint32 clipsm3ClprimToClipClipPrimitive: 1; // 23
		uint32 clipsm3ClprimToClipDeallocateSlot: 3; // 24
		uint32 clipsm3ClprimToClipFirstPrimOfSlot: 1; // 27
		uint32 clipsm3ClprimToClipEndOfPacket: 1; // 28
		uint32 clipsm3ClprimToClipEvent: 1; // 29
		uint32 clipsm3ClprimToClipNullPrimitive: 1; // 30
		uint32 clipsm3ClprimToClipPrimValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG10
union ClipperDebugReg10 {
	struct {
		uint32 unknown1: 1;
		uint32 clipsm3ClprimToClipParamCacheIndx0: 10; // 1
		uint32 clipsm3ClprimToClipVertexStoreIndx2: 6; // 11
		uint32 clipsm3ClprimToClipVertexStoreIndx1: 6; // 17
		uint32 clipsm3ClprimToClipVertexStoreIndx0: 6; // 23
		uint32 clipsm3ClprimToClipEvent: 1; // 29
		uint32 clipsm3ClprimToClipNullPrimitive: 1; // 30
		uint32 clipsm3ClprimToClipPrimValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG11
union ClipperDebugReg11 {
	struct {
		uint32 clipsm3ClipToClipgaEvent: 1; // 0
		uint32 clipsm2ClipToClipgaEvent: 1; // 1
		uint32 clipsm1ClipToClipgaEvent: 1; // 2
		uint32 clipsm0ClipToClipgaEvent: 1; // 3
		uint32 clipsm3ClipToClipgaClipPrimitive: 1; // 4
		uint32 clipsm2ClipToClipgaClipPrimitive: 1; // 5
		uint32 clipsm1ClipToClipgaClipPrimitive: 1; // 6
		uint32 clipsm0ClipToClipgaClipPrimitive: 1; // 7
		uint32 clipsm3ClipToClipgaClipToOutsmCnt: 4; // 8
		uint32 clipsm2ClipToClipgaClipToOutsmCnt: 4; // 12
		uint32 clipsm1ClipToClipgaClipToOutsmCnt: 4; // 16
		uint32 clipsm0ClipToClipgaClipToOutsmCnt: 4; // 20
		uint32 clipsm3ClipToClipgaPrimValid: 1; // 24
		uint32 clipsm2ClipToClipgaPrimValid: 1; // 25
		uint32 clipsm1ClipToClipgaPrimValid: 1; // 26
		uint32 clipsm0ClipToClipgaPrimValid: 1; // 27
		uint32 clipsm3IncClipToClipgaClipToOutsmCnt: 1; // 28
		uint32 clipsm2IncClipToClipgaClipToOutsmCnt: 1; // 29
		uint32 clipsm1IncClipToClipgaClipToOutsmCnt: 1; // 30
		uint32 clipsm0IncClipToClipgaClipToOutsmCnt: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG12
union ClipperDebugReg12 {
	struct {
		uint32 alwaysZero: 8; // 0
		uint32 clipPriorityAvailableVteOutClip: 5; // 8
		uint32 clipPriorityAvailableClipVerts: 5; // 13
		uint32 clipPrioritySeqIndxOut: 2; // 18
		uint32 clipPrioritySeqIndxVert: 2; // 20
		uint32 clipPrioritySeqIndxLoad: 2; // 22
		uint32 clipsm3ClprimToClipClipPrimitive: 1; // 24
		uint32 clipsm3ClprimToClipPrimValid: 1; // 25
		uint32 clipsm2ClprimToClipClipPrimitive: 1; // 26
		uint32 clipsm2ClprimToClipPrimValid: 1; // 27
		uint32 clipsm1ClprimToClipClipPrimitive: 1; // 28
		uint32 clipsm1ClprimToClipPrimValid: 1; // 29
		uint32 clipsm0ClprimToClipClipPrimitive: 1; // 30
		uint32 clipsm0ClprimToClipPrimValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG13
union ClipperDebugReg13 {
	struct {
		uint32 clprimInBackStateVarIndx: 3; // 0
		uint32 pointClipCandidate: 1; // 3
		uint32 primNanKill: 1; // 4
		uint32 clprimClipPrimitive: 1; // 5
		uint32 clprimCullPrimitive: 1; // 6
		uint32 primBackValid: 1; // 7
		uint32 vertvalBitsVertexCcNextValid: 4; // 8
		uint32 clipccVertexStoreIndx: 2; // 12
		uint32 vteOutOrigFifoFifoEmpty: 1; // 14
		uint32 clipcodeFifoFifoEmpty: 1; // 15
		uint32 ccgenToClipccFifoEmpty: 1; // 16
		uint32 clipPrioritySeqIndxOutCnt: 4; // 17
		uint32 outsmClrRdOrigVertices: 2; // 21
		uint32 outsmClrRdClipsmWait: 1; // 23
		uint32 outsmClrFifoContents: 5; // 24
		uint32 outsmClrFifoFull: 1; // 29
		uint32 outsmClrFifoAdvanceread: 1; // 30
		uint32 outsmClrFifoWrite: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG14
union ClipperDebugReg14 {
	struct {
		uint32 clprimInBackVertexStoreIndx2: 6; // 0
		uint32 clprimInBackVertexStoreIndx1: 6; // 6
		uint32 clprimInBackVertexStoreIndx0: 6; // 12
		uint32 outputclprimtoclipNullPrimitive: 1; // 18
		uint32 clprimInBackEndOfPacket: 1; // 19
		uint32 clprimInBackFirstPrimOfSlot: 1; // 20
		uint32 clprimInBackDeallocateSlot: 3; // 21
		uint32 clprimInBackEventId: 6; // 24
		uint32 clprimInBackEvent: 1; // 30
		uint32 primBackValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG15
union ClipperDebugReg15 {
	struct {
		uint32 vertvalBitsVertexVertexStoreMsb: 16; // 0
		uint32 primicToClprimFifoVertexStoreIndx2: 5; // 16
		uint32 primicToClprimFifoVertexStoreIndx1: 5; // 21
		uint32 primicToClprimFifoVertexStoreIndx0: 5; // 26
		uint32 primicToClprimValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG16
union ClipperDebugReg16 {
	struct {
		uint32 sm0PrimEndState: 7; // 0
		uint32 sm0PsExpand: 1; // 7
		uint32 sm0ClipVertCnt: 5; // 8
		uint32 sm0VertexClipCnt: 5; // 13
		uint32 sm0InvToClipDataValid1: 1; // 18
		uint32 sm0InvToClipDataValid0: 1; // 19
		uint32 sm0CurrentState: 7; // 20
		uint32 sm0ClipToClipgaClipToOutsmCntEq0: 1; // 27
		uint32 sm0ClipToOutsmFifoFull: 1; // 28
		uint32 sm0HighestPrioritySeq: 1; // 29
		uint32 sm0Outputcliptoclipga0: 1; // 30
		uint32 sm0ClprimToClipPrimValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG17
union ClipperDebugReg17 {
	struct {
		uint32 sm1PrimEndState: 7; // 0
		uint32 sm1PsExpand: 1; // 7
		uint32 sm1ClipVertCnt: 5; // 8
		uint32 sm1VertexClipCnt: 5; // 13
		uint32 sm1InvToClipDataValid1: 1; // 18
		uint32 sm1InvToClipDataValid0: 1; // 19
		uint32 sm1CurrentState: 7; // 20
		uint32 sm1ClipToClipgaClipToOutsmCntEq0: 1; // 27
		uint32 sm1ClipToOutsmFifoFull: 1; // 28
		uint32 sm1HighestPrioritySeq: 1; // 29
		uint32 sm1Outputcliptoclipga0: 1; // 30
		uint32 sm1ClprimToClipPrimValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG18
union ClipperDebugReg18 {
	struct {
		uint32 sm2PrimEndState: 7; // 0
		uint32 sm2PsExpand: 1; // 7
		uint32 sm2ClipVertCnt: 5; // 8
		uint32 sm2VertexClipCnt: 5; // 13
		uint32 sm2InvToClipDataValid1: 1; // 18
		uint32 sm2InvToClipDataValid0: 1; // 19
		uint32 sm2CurrentState: 7; // 20
		uint32 sm2ClipToClipgaClipToOutsmCntEq0: 1; // 27
		uint32 sm2ClipToOutsmFifoFull: 1; // 28
		uint32 sm2HighestPrioritySeq: 1; // 29
		uint32 sm2Outputcliptoclipga0: 1; // 30
		uint32 sm2ClprimToClipPrimValid: 1; // 31
	};
	uint32 val;
};

// CLIPPER_DEBUG_REG19
union ClipperDebugReg19 {
	struct {
		uint32 sm3PrimEndState: 7; // 0
		uint32 sm3PsExpand: 1; // 7
		uint32 sm3ClipVertCnt: 5; // 8
		uint32 sm3VertexClipCnt: 5; // 13
		uint32 sm3InvToClipDataValid1: 1; // 18
		uint32 sm3InvToClipDataValid0: 1; // 19
		uint32 sm3CurrentState: 7; // 20
		uint32 sm3ClipToClipgaClipToOutsmCntEq0: 1; // 27
		uint32 sm3ClipToOutsmFifoFull: 1; // 28
		uint32 sm3HighestPrioritySeq: 1; // 29
		uint32 sm3Outputcliptoclipga0: 1; // 30
		uint32 sm3ClprimToClipPrimValid: 1; // 31
	};
	uint32 val;
};

// COHER_DEST_BASE_0
union CoherDestBase0 {
	struct {
		uint32 destBase256b: 32; // 0
	};
	uint32 val;
};

// COHER_DEST_BASE_1
union CoherDestBase1 {
	struct {
		uint32 destBase256b: 32; // 0
	};
	uint32 val;
};

// COHER_DEST_BASE_2
union CoherDestBase2 {
	struct {
		uint32 destBase256b: 32; // 0
	};
	uint32 val;
};

// COHER_DEST_BASE_3
union CoherDestBase3 {
	struct {
		uint32 destBase256b: 32; // 0
	};
	uint32 val;
};

// COMPUTE_DIM_X
union ComputeDimX {
	struct {
		uint32 size: 32; // 0
	};
	uint32 val;
};

// COMPUTE_DIM_Y
union ComputeDimY {
	struct {
		uint32 size: 32; // 0
	};
	uint32 val;
};

// COMPUTE_DIM_Z
union ComputeDimZ {
	struct {
		uint32 size: 32; // 0
	};
	uint32 val;
};

// COMPUTE_DISPATCH_INITIATOR
union ComputeDispatchInitiator {
	struct {
		uint32 computeShaderEn: 1; // 0
		uint32 partialTgEn: 1; // 1
		uint32 forceStartAt000: 1; // 2
		uint32 orderedAppendEnbl: 1; // 3
		uint32 orderedAppendMode: 1; // 4
		uint32 useThreadDimensions: 1; // 5
		uint32 orderMode: 1; // 6
		uint32 dispatchCacheCntl: 3; // 7
		uint32 scalarL1InvVol: 1; // 10
		uint32 vectorL1InvVol: 1; // 11
		uint32 dataAtc: 1; // 12
		uint32 unknown1: 1;
		uint32 restore: 1; // 14
		uint32 unknown2: 17;
	};
	uint32 val;
};

// COMPUTE_NUM_THREAD_X
union ComputeNumThreadX {
	struct {
		uint32 numThreadFull: 16; // 0
		uint32 numThreadPartial: 16; // 16
	};
	uint32 val;
};

// COMPUTE_NUM_THREAD_Y
union ComputeNumThreadY {
	struct {
		uint32 numThreadFull: 16; // 0
		uint32 numThreadPartial: 16; // 16
	};
	uint32 val;
};

// COMPUTE_NUM_THREAD_Z
union ComputeNumThreadZ {
	struct {
		uint32 numThreadFull: 16; // 0
		uint32 numThreadPartial: 16; // 16
	};
	uint32 val;
};

// COMPUTE_PGM_HI
union ComputePgmHi {
	struct {
		uint32 data: 8; // 0
		uint32 instAtc: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// COMPUTE_PGM_LO
union ComputePgmLo {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_PGM_RSRC1
union ComputePgmRsrc1 {
	struct {
		uint32 vgprs: 6; // 0
		uint32 sgprs: 4; // 6
		uint32 priority: 2; // 10
		uint32 floatMode: 8; // 12
		uint32 priv: 1; // 20
		uint32 dx10Clamp: 1; // 21
		uint32 debugMode: 1; // 22
		uint32 ieeeMode: 1; // 23
		uint32 bulky: 1; // 24
		uint32 cdbgUser: 1; // 25
		uint32 unknown1: 6;
	};
	uint32 val;
};

// COMPUTE_PGM_RSRC2
union ComputePgmRsrc2 {
	struct {
		uint32 scratchEn: 1; // 0
		uint32 userSgpr: 5; // 1
		uint32 trapPresent: 1; // 6
		uint32 tgidXEn: 1; // 7
		uint32 tgidYEn: 1; // 8
		uint32 tgidZEn: 1; // 9
		uint32 tgSizeEn: 1; // 10
		uint32 tidigCompCnt: 2; // 11
		uint32 excpEnMsb: 2; // 13
		uint32 ldsSize: 9; // 15
		uint32 excpEn: 7; // 24
		uint32 unknown1: 1;
	};
	uint32 val;
};

// COMPUTE_RESOURCE_LIMITS
union ComputeResourceLimits {
	struct {
		uint32 wavesPerSh: 6; // 0
		uint32 unknown1: 6;
		uint32 tgPerCu: 4; // 12
		uint32 lockThreshold: 6; // 16
		uint32 simdDestCntl: 1; // 22
		uint32 forceSimdDist: 1; // 23
		uint32 cuGroupCount: 3; // 24
		uint32 unknown2: 5;
	};
	uint32 val;
};

// COMPUTE_START_X
union ComputeStartX {
	struct {
		uint32 start: 32; // 0
	};
	uint32 val;
};

// COMPUTE_START_Y
union ComputeStartY {
	struct {
		uint32 start: 32; // 0
	};
	uint32 val;
};

// COMPUTE_START_Z
union ComputeStartZ {
	struct {
		uint32 start: 32; // 0
	};
	uint32 val;
};

// COMPUTE_STATIC_THREAD_MGMT_SE0
union ComputeStaticThreadMgmtSe0 {
	struct {
		uint32 sh0CuEn: 16; // 0
		uint32 sh1CuEn: 16; // 16
	};
	uint32 val;
};

// COMPUTE_STATIC_THREAD_MGMT_SE1
union ComputeStaticThreadMgmtSe1 {
	struct {
		uint32 sh0CuEn: 16; // 0
		uint32 sh1CuEn: 16; // 16
	};
	uint32 val;
};

// COMPUTE_TBA_HI
union ComputeTbaHi {
	struct {
		uint32 data: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// COMPUTE_TBA_LO
union ComputeTbaLo {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_TMA_HI
union ComputeTmaHi {
	struct {
		uint32 data: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// COMPUTE_TMA_LO
union ComputeTmaLo {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_TMPRING_SIZE
union ComputeTmpringSize {
	struct {
		uint32 waves: 12; // 0
		uint32 wavesize: 13; // 12
		uint32 unknown1: 7;
	};
	uint32 val;
};

// COMPUTE_USER_DATA_0
union ComputeUserData0 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_1
union ComputeUserData1 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_10
union ComputeUserData10 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_11
union ComputeUserData11 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_12
union ComputeUserData12 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_13
union ComputeUserData13 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_14
union ComputeUserData14 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_15
union ComputeUserData15 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_2
union ComputeUserData2 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_3
union ComputeUserData3 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_4
union ComputeUserData4 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_5
union ComputeUserData5 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_6
union ComputeUserData6 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_7
union ComputeUserData7 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_8
union ComputeUserData8 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_USER_DATA_9
union ComputeUserData9 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// COMPUTE_VMID
union ComputeVmid {
	struct {
		uint32 data: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// CP_APPEND_ADDR_HI
union CpAppendAddrHi {
	struct {
		uint32 memAddrHi: 8; // 0
		uint32 unknown1: 8;
		uint32 csPsSel: 2; // 16
		uint32 unknown2: 11;
		uint32 command: 3; // 29
	};
	uint32 val;
};

// CP_APPEND_ADDR_LO
union CpAppendAddrLo {
	struct {
		uint32 unknown1: 2;
		uint32 memAddrLo: 30; // 2
	};
	uint32 val;
};

// CP_APPEND_DATA
union CpAppendData {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// CP_APPEND_LAST_CS_FENCE
union CpAppendLastCsFence {
	struct {
		uint32 lastFence: 32; // 0
	};
	uint32 val;
};

// CP_APPEND_LAST_PS_FENCE
union CpAppendLastPsFence {
	struct {
		uint32 lastFence: 32; // 0
	};
	uint32 val;
};

// CP_ATOMIC_PREOP_HI
union CpAtomicPreopHi {
	struct {
		uint32 atomicPreopHi: 32; // 0
	};
	uint32 val;
};

// CP_ATOMIC_PREOP_LO
union CpAtomicPreopLo {
	struct {
		uint32 atomicPreopLo: 32; // 0
	};
	uint32 val;
};

// CP_BUSY_STAT
union CpBusyStat {
	struct {
		uint32 regBusFifoBusy: 1; // 0
		uint32 unknown1: 5;
		uint32 coherCntNeqZero: 1; // 6
		uint32 pfpParsingPackets: 1; // 7
		uint32 meParsingPackets: 1; // 8
		uint32 rciuPfpBusy: 1; // 9
		uint32 rciuMeBusy: 1; // 10
		uint32 unknown2: 1;
		uint32 semCmdfifoNotEmpty: 1; // 12
		uint32 semFailedAndHolding: 1; // 13
		uint32 semPollingForPass: 1; // 14
		uint32 gfxContextBusy: 1; // 15
		uint32 unknown3: 1;
		uint32 meParserBusy: 1; // 17
		uint32 eopDoneBusy: 1; // 18
		uint32 strmOutBusy: 1; // 19
		uint32 pipeStatsBusy: 1; // 20
		uint32 rciuCeBusy: 1; // 21
		uint32 ceParsingPackets: 1; // 22
		uint32 unknown4: 9;
	};
	uint32 val;
};

// CP_CEQ1_AVAIL
union CpCeq1Avail {
	struct {
		uint32 ceqCntRing: 11; // 0
		uint32 unknown1: 5;
		uint32 ceqCntIb1: 11; // 16
		uint32 unknown2: 5;
	};
	uint32 val;
};

// CP_CEQ2_AVAIL
union CpCeq2Avail {
	struct {
		uint32 ceqCntIb2: 11; // 0
		uint32 unknown1: 21;
	};
	uint32 val;
};

// CP_CE_HEADER_DUMP
union CpCeHeaderDump {
	struct {
		uint32 ceHeaderDump: 32; // 0
	};
	uint32 val;
};

// CP_CE_IB1_BASE_HI
union CpCeIb1BaseHi {
	struct {
		uint32 ib1BaseHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_CE_IB1_BASE_LO
union CpCeIb1BaseLo {
	struct {
		uint32 unknown1: 2;
		uint32 ib1BaseLo: 30; // 2
	};
	uint32 val;
};

// CP_CE_IB1_BUFSZ
union CpCeIb1Bufsz {
	struct {
		uint32 ib1Bufsz: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_CE_IB2_BASE_HI
union CpCeIb2BaseHi {
	struct {
		uint32 ib2BaseHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_CE_IB2_BASE_LO
union CpCeIb2BaseLo {
	struct {
		uint32 unknown1: 2;
		uint32 ib2BaseLo: 30; // 2
	};
	uint32 val;
};

// CP_CE_IB2_BUFSZ
union CpCeIb2Bufsz {
	struct {
		uint32 ib2Bufsz: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_CE_INIT_BASE_HI
union CpCeInitBaseHi {
	struct {
		uint32 initBaseHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_CE_INIT_BASE_LO
union CpCeInitBaseLo {
	struct {
		uint32 unknown1: 5;
		uint32 initBaseLo: 27; // 5
	};
	uint32 val;
};

// CP_CE_INIT_BUFSZ
union CpCeInitBufsz {
	struct {
		uint32 initBufsz: 12; // 0
		uint32 unknown1: 20;
	};
	uint32 val;
};

// CP_CE_ROQ_IB1_STAT
union CpCeRoqIb1Stat {
	struct {
		uint32 ceqRptrIndirect1: 10; // 0
		uint32 unknown1: 6;
		uint32 ceqWptrIndirect1: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// CP_CE_ROQ_IB2_STAT
union CpCeRoqIb2Stat {
	struct {
		uint32 ceqRptrIndirect2: 10; // 0
		uint32 unknown1: 6;
		uint32 ceqWptrIndirect2: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// CP_CE_ROQ_RB_STAT
union CpCeRoqRbStat {
	struct {
		uint32 ceqRptrPrimary: 10; // 0
		uint32 unknown1: 6;
		uint32 ceqWptrPrimary: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// CP_CE_UCODE_ADDR
union CpCeUcodeAddr {
	struct {
		uint32 ucodeAddr: 12; // 0
		uint32 unknown1: 20;
	};
	uint32 val;
};

// CP_CE_UCODE_DATA
union CpCeUcodeData {
	struct {
		uint32 ucodeData: 32; // 0
	};
	uint32 val;
};

// CP_CMD_DATA
union CpCmdData {
	struct {
		uint32 cmdData: 32; // 0
	};
	uint32 val;
};

// CP_CMD_INDEX
union CpCmdIndex {
	struct {
		uint32 cmdIndex: 11; // 0
		uint32 unknown1: 1;
		uint32 cmdMeSel: 2; // 12
		uint32 unknown2: 2;
		uint32 cmdQueueSel: 2; // 16
		uint32 unknown3: 14;
	};
	uint32 val;
};

// CP_CNTX_STAT
union CpCntxStat {
	struct {
		uint32 activeHp3dContexts: 8; // 0
		uint32 currentHp3dContext: 3; // 8
		uint32 unknown1: 9;
		uint32 activeGfxContexts: 8; // 20
		uint32 currentGfxContext: 3; // 28
		uint32 unknown2: 1;
	};
	uint32 val;
};

// CP_COHER_BASE
union CpCoherBase {
	struct {
		uint32 coherBase256b: 32; // 0
	};
	uint32 val;
};

// CP_COHER_BASE_HI
union CpCoherBaseHi {
	struct {
		uint32 coherBaseHi256b: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_COHER_CNTL
union CpCoherCntl {
	struct {
		uint32 destBase0Ena: 1; // 0
		uint32 destBase1Ena: 1; // 1
		uint32 unknown1: 4;
		uint32 cb0DestBaseEna: 1; // 6
		uint32 cb1DestBaseEna: 1; // 7
		uint32 cb2DestBaseEna: 1; // 8
		uint32 cb3DestBaseEna: 1; // 9
		uint32 cb4DestBaseEna: 1; // 10
		uint32 cb5DestBaseEna: 1; // 11
		uint32 cb6DestBaseEna: 1; // 12
		uint32 cb7DestBaseEna: 1; // 13
		uint32 dbDestBaseEna: 1; // 14
		uint32 tcl1VolActionEna: 1; // 15
		uint32 tcVolActionEna: 1; // 16
		uint32 unknown2: 1;
		uint32 tcWbActionEna: 1; // 18
		uint32 destBase2Ena: 1; // 19
		uint32 unknown3: 1;
		uint32 destBase3Ena: 1; // 21
		uint32 tcl1ActionEna: 1; // 22
		uint32 tcActionEna: 1; // 23
		uint32 unknown4: 1;
		uint32 cbActionEna: 1; // 25
		uint32 dbActionEna: 1; // 26
		uint32 shKcacheActionEna: 1; // 27
		uint32 shKcacheVolActionEna: 1; // 28
		uint32 shIcacheActionEna: 1; // 29
		uint32 unknown5: 2;
	};
	uint32 val;
};

// CP_COHER_SIZE
union CpCoherSize {
	struct {
		uint32 coherSize256b: 32; // 0
	};
	uint32 val;
};

// CP_COHER_SIZE_HI
union CpCoherSizeHi {
	struct {
		uint32 coherSizeHi256b: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_COHER_START_DELAY
union CpCoherStartDelay {
	struct {
		uint32 startDelayCount: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// CP_COHER_STATUS
union CpCoherStatus {
	struct {
		uint32 matchingGfxCntx: 8; // 0
		uint32 unknown1: 16;
		uint32 meid: 2; // 24
		uint32 unknown2: 4;
		uint32 phase1Status: 1; // 30
		uint32 status: 1; // 31
	};
	uint32 val;
};

// CP_CSF_CNTL
union CpCsfCntl {
	struct {
		uint32 fetchBufferDepth: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// CP_CSF_STAT
union CpCsfStat {
	struct {
		uint32 bufferSlotsAllocated: 4; // 0
		uint32 unknown1: 4;
		uint32 bufferRequestCount: 6; // 8
		uint32 unknown2: 18;
	};
	uint32 val;
};

// CP_DMA_CNTL
union CpDmaCntl {
	struct {
		uint32 unknown1: 4;
		uint32 minAvailsz: 2; // 4
		uint32 unknown2: 10;
		uint32 bufferDepth: 4; // 16
		uint32 unknown3: 8;
		uint32 pioFifoEmpty: 1; // 28
		uint32 pioFifoFull: 1; // 29
		uint32 pioCount: 2; // 30
	};
	uint32 val;
};

// CP_DMA_ME_COMMAND
union CpDmaMeCommand {
	struct {
		uint32 byteCount: 21; // 0
		uint32 disWc: 1; // 21
		uint32 srcSwap: 2; // 22
		uint32 dstSwap: 2; // 24
		uint32 sas: 1; // 26
		uint32 das: 1; // 27
		uint32 saic: 1; // 28
		uint32 daic: 1; // 29
		uint32 rawWait: 1; // 30
		uint32 unknown1: 1;
	};
	uint32 val;
};

// CP_DMA_ME_DST_ADDR
union CpDmaMeDstAddr {
	struct {
		uint32 dstAddr: 32; // 0
	};
	uint32 val;
};

// CP_DMA_ME_DST_ADDR_HI
union CpDmaMeDstAddrHi {
	struct {
		uint32 dstAddrHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_DMA_ME_SRC_ADDR
union CpDmaMeSrcAddr {
	struct {
		uint32 srcAddr: 32; // 0
	};
	uint32 val;
};

// CP_DMA_ME_SRC_ADDR_HI
union CpDmaMeSrcAddrHi {
	struct {
		uint32 srcAddrHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_DMA_PFP_COMMAND
union CpDmaPfpCommand {
	struct {
		uint32 byteCount: 21; // 0
		uint32 disWc: 1; // 21
		uint32 srcSwap: 2; // 22
		uint32 dstSwap: 2; // 24
		uint32 sas: 1; // 26
		uint32 das: 1; // 27
		uint32 saic: 1; // 28
		uint32 daic: 1; // 29
		uint32 rawWait: 1; // 30
		uint32 unknown1: 1;
	};
	uint32 val;
};

// CP_DMA_PFP_DST_ADDR
union CpDmaPfpDstAddr {
	struct {
		uint32 dstAddr: 32; // 0
	};
	uint32 val;
};

// CP_DMA_PFP_DST_ADDR_HI
union CpDmaPfpDstAddrHi {
	struct {
		uint32 dstAddrHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_DMA_PFP_SRC_ADDR
union CpDmaPfpSrcAddr {
	struct {
		uint32 srcAddr: 32; // 0
	};
	uint32 val;
};

// CP_DMA_PFP_SRC_ADDR_HI
union CpDmaPfpSrcAddrHi {
	struct {
		uint32 srcAddrHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_DMA_READ_TAGS
union CpDmaReadTags {
	struct {
		uint32 dmaReadTag: 26; // 0
		uint32 unknown1: 2;
		uint32 dmaReadTagValid: 1; // 28
		uint32 unknown2: 3;
	};
	uint32 val;
};

// CP_ECC_FIRSTOCCURRENCE
union CpEccFirstoccurrence {
	struct {
		uint32 interface: 2; // 0
		uint32 unknown1: 2;
		uint32 requestClient: 4; // 4
		uint32 unknown2: 2;
		uint32 ringId: 4; // 10
		uint32 unknown3: 2;
		uint32 vmid: 4; // 16
		uint32 unknown4: 12;
	};
	uint32 val;
};

// CP_ECC_FIRSTOCCURRENCE_RING0
union CpEccFirstoccurrenceRing0 {
	struct {
		uint32 interface: 2; // 0
		uint32 unknown1: 2;
		uint32 requestClient: 4; // 4
		uint32 unknown2: 2;
		uint32 ringId: 4; // 10
		uint32 unknown3: 2;
		uint32 vmid: 4; // 16
		uint32 unknown4: 12;
	};
	uint32 val;
};

// CP_ECC_FIRSTOCCURRENCE_RING1
union CpEccFirstoccurrenceRing1 {
	struct {
		uint32 interface: 2; // 0
		uint32 unknown1: 2;
		uint32 requestClient: 4; // 4
		uint32 unknown2: 2;
		uint32 ringId: 4; // 10
		uint32 unknown3: 2;
		uint32 vmid: 4; // 16
		uint32 unknown4: 12;
	};
	uint32 val;
};

// CP_ECC_FIRSTOCCURRENCE_RING2
union CpEccFirstoccurrenceRing2 {
	struct {
		uint32 interface: 2; // 0
		uint32 unknown1: 2;
		uint32 requestClient: 4; // 4
		uint32 unknown2: 2;
		uint32 ringId: 4; // 10
		uint32 unknown3: 2;
		uint32 vmid: 4; // 16
		uint32 unknown4: 12;
	};
	uint32 val;
};

// CP_EOP_DONE_ADDR_HI
union CpEopDoneAddrHi {
	struct {
		uint32 addrHi: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// CP_EOP_DONE_ADDR_LO
union CpEopDoneAddrLo {
	struct {
		uint32 addrSwap: 2; // 0
		uint32 addrLo: 30; // 2
	};
	uint32 val;
};

// CP_EOP_DONE_DATA_CNTL
union CpEopDoneDataCntl {
	struct {
		uint32 cntxId: 16; // 0
		uint32 dstSel: 2; // 16
		uint32 unknown1: 6;
		uint32 intSel: 3; // 24
		uint32 unknown2: 2;
		uint32 dataSel: 3; // 29
	};
	uint32 val;
};

// CP_EOP_DONE_DATA_HI
union CpEopDoneDataHi {
	struct {
		uint32 dataHi: 32; // 0
	};
	uint32 val;
};

// CP_EOP_DONE_DATA_LO
union CpEopDoneDataLo {
	struct {
		uint32 dataLo: 32; // 0
	};
	uint32 val;
};

// CP_EOP_LAST_FENCE_HI
union CpEopLastFenceHi {
	struct {
		uint32 lastFenceHi: 32; // 0
	};
	uint32 val;
};

// CP_EOP_LAST_FENCE_LO
union CpEopLastFenceLo {
	struct {
		uint32 lastFenceLo: 32; // 0
	};
	uint32 val;
};

// CP_GDS_ATOMIC0_PREOP_HI
union CpGdsAtomic0PreopHi {
	struct {
		uint32 gdsAtomic0PreopHi: 32; // 0
	};
	uint32 val;
};

// CP_GDS_ATOMIC0_PREOP_LO
union CpGdsAtomic0PreopLo {
	struct {
		uint32 gdsAtomic0PreopLo: 32; // 0
	};
	uint32 val;
};

// CP_GDS_ATOMIC1_PREOP_HI
union CpGdsAtomic1PreopHi {
	struct {
		uint32 gdsAtomic1PreopHi: 32; // 0
	};
	uint32 val;
};

// CP_GDS_ATOMIC1_PREOP_LO
union CpGdsAtomic1PreopLo {
	struct {
		uint32 gdsAtomic1PreopLo: 32; // 0
	};
	uint32 val;
};

// CP_GRBM_FREE_COUNT
union CpGrbmFreeCount {
	struct {
		uint32 freeCount: 6; // 0
		uint32 unknown1: 2;
		uint32 freeCountGds: 6; // 8
		uint32 unknown2: 2;
		uint32 freeCountPfp: 6; // 16
		uint32 unknown3: 10;
	};
	uint32 val;
};

// CP_IB1_BASE_HI
union CpIb1BaseHi {
	struct {
		uint32 ib1BaseHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_IB1_BASE_LO
union CpIb1BaseLo {
	struct {
		uint32 unknown1: 2;
		uint32 ib1BaseLo: 30; // 2
	};
	uint32 val;
};

// CP_IB1_BUFSZ
union CpIb1Bufsz {
	struct {
		uint32 ib1Bufsz: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_IB1_OFFSET
union CpIb1Offset {
	struct {
		uint32 ib1Offset: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_IB1_PREAMBLE_BEGIN
union CpIb1PreambleBegin {
	struct {
		uint32 ib1PreambleBegin: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_IB1_PREAMBLE_END
union CpIb1PreambleEnd {
	struct {
		uint32 ib1PreambleEnd: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_IB2_BASE_HI
union CpIb2BaseHi {
	struct {
		uint32 ib2BaseHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_IB2_BASE_LO
union CpIb2BaseLo {
	struct {
		uint32 unknown1: 2;
		uint32 ib2BaseLo: 30; // 2
	};
	uint32 val;
};

// CP_IB2_BUFSZ
union CpIb2Bufsz {
	struct {
		uint32 ib2Bufsz: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_IB2_OFFSET
union CpIb2Offset {
	struct {
		uint32 ib2Offset: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_IB2_PREAMBLE_BEGIN
union CpIb2PreambleBegin {
	struct {
		uint32 ib2PreambleBegin: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_IB2_PREAMBLE_END
union CpIb2PreambleEnd {
	struct {
		uint32 ib2PreambleEnd: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_INT_CNTL
union CpIntCntl {
	struct {
		uint32 unknown1: 14;
		uint32 cpEccErrorIntEnable: 1; // 14
		uint32 unknown2: 2;
		uint32 wrmPollTimeoutIntEnable: 1; // 17
		uint32 unknown3: 1;
		uint32 cntxBusyIntEnable: 1; // 19
		uint32 cntxEmptyIntEnable: 1; // 20
		uint32 unknown4: 1;
		uint32 privInstrIntEnable: 1; // 22
		uint32 privRegIntEnable: 1; // 23
		uint32 opcodeErrorIntEnable: 1; // 24
		uint32 unknown5: 1;
		uint32 timeStampIntEnable: 1; // 26
		uint32 reservedBitErrorIntEnable: 1; // 27
		uint32 unknown6: 1;
		uint32 generic2IntEnable: 1; // 29
		uint32 generic1IntEnable: 1; // 30
		uint32 generic0IntEnable: 1; // 31
	};
	uint32 val;
};

// CP_INT_CNTL_RING0
union CpIntCntlRing0 {
	struct {
		uint32 unknown1: 14;
		uint32 cpEccErrorIntEnable: 1; // 14
		uint32 unknown2: 2;
		uint32 wrmPollTimeoutIntEnable: 1; // 17
		uint32 unknown3: 1;
		uint32 cntxBusyIntEnable: 1; // 19
		uint32 cntxEmptyIntEnable: 1; // 20
		uint32 unknown4: 1;
		uint32 privInstrIntEnable: 1; // 22
		uint32 privRegIntEnable: 1; // 23
		uint32 opcodeErrorIntEnable: 1; // 24
		uint32 unknown5: 1;
		uint32 timeStampIntEnable: 1; // 26
		uint32 reservedBitErrorIntEnable: 1; // 27
		uint32 unknown6: 1;
		uint32 generic2IntEnable: 1; // 29
		uint32 generic1IntEnable: 1; // 30
		uint32 generic0IntEnable: 1; // 31
	};
	uint32 val;
};

// CP_INT_CNTL_RING1
union CpIntCntlRing1 {
	struct {
		uint32 unknown1: 14;
		uint32 cpEccErrorIntEnable: 1; // 14
		uint32 unknown2: 2;
		uint32 wrmPollTimeoutIntEnable: 1; // 17
		uint32 unknown3: 1;
		uint32 cntxBusyIntEnable: 1; // 19
		uint32 cntxEmptyIntEnable: 1; // 20
		uint32 unknown4: 1;
		uint32 privInstrIntEnable: 1; // 22
		uint32 privRegIntEnable: 1; // 23
		uint32 opcodeErrorIntEnable: 1; // 24
		uint32 unknown5: 1;
		uint32 timeStampIntEnable: 1; // 26
		uint32 reservedBitErrorIntEnable: 1; // 27
		uint32 unknown6: 1;
		uint32 generic2IntEnable: 1; // 29
		uint32 generic1IntEnable: 1; // 30
		uint32 generic0IntEnable: 1; // 31
	};
	uint32 val;
};

// CP_INT_CNTL_RING2
union CpIntCntlRing2 {
	struct {
		uint32 unknown1: 14;
		uint32 cpEccErrorIntEnable: 1; // 14
		uint32 unknown2: 2;
		uint32 wrmPollTimeoutIntEnable: 1; // 17
		uint32 unknown3: 1;
		uint32 cntxBusyIntEnable: 1; // 19
		uint32 cntxEmptyIntEnable: 1; // 20
		uint32 unknown4: 1;
		uint32 privInstrIntEnable: 1; // 22
		uint32 privRegIntEnable: 1; // 23
		uint32 opcodeErrorIntEnable: 1; // 24
		uint32 unknown5: 1;
		uint32 timeStampIntEnable: 1; // 26
		uint32 reservedBitErrorIntEnable: 1; // 27
		uint32 unknown6: 1;
		uint32 generic2IntEnable: 1; // 29
		uint32 generic1IntEnable: 1; // 30
		uint32 generic0IntEnable: 1; // 31
	};
	uint32 val;
};

// CP_INT_STATUS
union CpIntStatus {
	struct {
		uint32 unknown1: 14;
		uint32 cpEccErrorIntStat: 1; // 14
		uint32 unknown2: 2;
		uint32 wrmPollTimeoutIntStat: 1; // 17
		uint32 unknown3: 1;
		uint32 cntxBusyIntStat: 1; // 19
		uint32 cntxEmptyIntStat: 1; // 20
		uint32 unknown4: 1;
		uint32 privInstrIntStat: 1; // 22
		uint32 privRegIntStat: 1; // 23
		uint32 opcodeErrorIntStat: 1; // 24
		uint32 unknown5: 1;
		uint32 timeStampIntStat: 1; // 26
		uint32 reservedBitErrorIntStat: 1; // 27
		uint32 unknown6: 1;
		uint32 generic2IntStat: 1; // 29
		uint32 generic1IntStat: 1; // 30
		uint32 generic0IntStat: 1; // 31
	};
	uint32 val;
};

// CP_INT_STATUS_RING0
union CpIntStatusRing0 {
	struct {
		uint32 unknown1: 14;
		uint32 cpEccErrorIntStat: 1; // 14
		uint32 unknown2: 2;
		uint32 wrmPollTimeoutIntStat: 1; // 17
		uint32 unknown3: 1;
		uint32 cntxBusyIntStat: 1; // 19
		uint32 cntxEmptyIntStat: 1; // 20
		uint32 unknown4: 1;
		uint32 privInstrIntStat: 1; // 22
		uint32 privRegIntStat: 1; // 23
		uint32 opcodeErrorIntStat: 1; // 24
		uint32 unknown5: 1;
		uint32 timeStampIntStat: 1; // 26
		uint32 reservedBitErrorIntStat: 1; // 27
		uint32 unknown6: 1;
		uint32 generic2IntStat: 1; // 29
		uint32 generic1IntStat: 1; // 30
		uint32 generic0IntStat: 1; // 31
	};
	uint32 val;
};

// CP_INT_STATUS_RING1
union CpIntStatusRing1 {
	struct {
		uint32 unknown1: 14;
		uint32 cpEccErrorIntStat: 1; // 14
		uint32 unknown2: 2;
		uint32 wrmPollTimeoutIntStat: 1; // 17
		uint32 unknown3: 1;
		uint32 cntxBusyIntStat: 1; // 19
		uint32 cntxEmptyIntStat: 1; // 20
		uint32 unknown4: 1;
		uint32 privInstrIntStat: 1; // 22
		uint32 privRegIntStat: 1; // 23
		uint32 opcodeErrorIntStat: 1; // 24
		uint32 unknown5: 1;
		uint32 timeStampIntStat: 1; // 26
		uint32 reservedBitErrorIntStat: 1; // 27
		uint32 unknown6: 1;
		uint32 generic2IntStat: 1; // 29
		uint32 generic1IntStat: 1; // 30
		uint32 generic0IntStat: 1; // 31
	};
	uint32 val;
};

// CP_INT_STATUS_RING2
union CpIntStatusRing2 {
	struct {
		uint32 unknown1: 14;
		uint32 cpEccErrorIntStat: 1; // 14
		uint32 unknown2: 2;
		uint32 wrmPollTimeoutIntStat: 1; // 17
		uint32 unknown3: 1;
		uint32 cntxBusyIntStat: 1; // 19
		uint32 cntxEmptyIntStat: 1; // 20
		uint32 unknown4: 1;
		uint32 privInstrIntStat: 1; // 22
		uint32 privRegIntStat: 1; // 23
		uint32 opcodeErrorIntStat: 1; // 24
		uint32 unknown5: 1;
		uint32 timeStampIntStat: 1; // 26
		uint32 reservedBitErrorIntStat: 1; // 27
		uint32 unknown6: 1;
		uint32 generic2IntStat: 1; // 29
		uint32 generic1IntStat: 1; // 30
		uint32 generic0IntStat: 1; // 31
	};
	uint32 val;
};

// CP_INT_STAT_DEBUG
union CpIntStatDebug {
	struct {
		uint32 unknown1: 14;
		uint32 cpEccErrorIntAsserted: 1; // 14
		uint32 unknown2: 2;
		uint32 wrmPollTimeoutIntAsserted: 1; // 17
		uint32 unknown3: 1;
		uint32 cntxBusyIntAsserted: 1; // 19
		uint32 cntxEmptyIntAsserted: 1; // 20
		uint32 unknown4: 1;
		uint32 privInstrIntAsserted: 1; // 22
		uint32 privRegIntAsserted: 1; // 23
		uint32 opcodeErrorIntAsserted: 1; // 24
		uint32 unknown5: 1;
		uint32 timeStampIntAsserted: 1; // 26
		uint32 reservedBitErrorIntAsserted: 1; // 27
		uint32 unknown6: 1;
		uint32 generic2IntAsserted: 1; // 29
		uint32 generic1IntAsserted: 1; // 30
		uint32 generic0IntAsserted: 1; // 31
	};
	uint32 val;
};

// CP_MC_PACK_DELAY_CNT
union CpMcPackDelayCnt {
	struct {
		uint32 packDelayCnt: 5; // 0
		uint32 unknown1: 27;
	};
	uint32 val;
};

// CP_MEM_SLP_CNTL
union CpMemSlpCntl {
	struct {
		uint32 cpMemLsEn: 1; // 0
		uint32 cpMemDsEn: 1; // 1
		uint32 reserved: 6; // 2
		uint32 cpMemLsOnDelay: 8; // 8
		uint32 cpMemLsOffDelay: 8; // 16
		uint32 reserved1: 8; // 24
	};
	uint32 val;
};

// CP_MEQ_AVAIL
union CpMeqAvail {
	struct {
		uint32 meqCnt: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// CP_MEQ_STAT
union CpMeqStat {
	struct {
		uint32 meqRptr: 10; // 0
		uint32 unknown1: 6;
		uint32 meqWptr: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// CP_MEQ_THRESHOLDS
union CpMeqThresholds {
	struct {
		uint32 meq1Start: 8; // 0
		uint32 meq2Start: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// CP_ME_CNTL
union CpMeCntl {
	struct {
		uint32 unknown1: 4;
		uint32 ceInvalidateIcache: 1; // 4
		uint32 unknown2: 1;
		uint32 pfpInvalidateIcache: 1; // 6
		uint32 unknown3: 1;
		uint32 meInvalidateIcache: 1; // 8
		uint32 unknown4: 15;
		uint32 ceHalt: 1; // 24
		uint32 ceStep: 1; // 25
		uint32 pfpHalt: 1; // 26
		uint32 pfpStep: 1; // 27
		uint32 meHalt: 1; // 28
		uint32 meStep: 1; // 29
		uint32 unknown5: 2;
	};
	uint32 val;
};

// CP_ME_HEADER_DUMP
union CpMeHeaderDump {
	struct {
		uint32 meHeaderDump: 32; // 0
	};
	uint32 val;
};

// CP_ME_MC_RADDR_HI
union CpMeMcRaddrHi {
	struct {
		uint32 meMcRaddrHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_ME_MC_RADDR_LO
union CpMeMcRaddrLo {
	struct {
		uint32 meMcRaddrSwap: 2; // 0
		uint32 meMcRaddrLo: 30; // 2
	};
	uint32 val;
};

// CP_ME_MC_WADDR_HI
union CpMeMcWaddrHi {
	struct {
		uint32 meMcWaddrHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_ME_MC_WADDR_LO
union CpMeMcWaddrLo {
	struct {
		uint32 meMcWaddrSwap: 2; // 0
		uint32 meMcWaddrLo: 30; // 2
	};
	uint32 val;
};

// CP_ME_MC_WDATA_HI
union CpMeMcWdataHi {
	struct {
		uint32 meMcWdataHi: 32; // 0
	};
	uint32 val;
};

// CP_ME_MC_WDATA_LO
union CpMeMcWdataLo {
	struct {
		uint32 meMcWdataLo: 32; // 0
	};
	uint32 val;
};

// CP_ME_PREEMPTION
union CpMePreemption {
	struct {
		uint32 meCntxswPreemption: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CP_ME_RAM_DATA
union CpMeRamData {
	struct {
		uint32 meRamData: 32; // 0
	};
	uint32 val;
};

// CP_ME_RAM_RADDR
union CpMeRamRaddr {
	struct {
		uint32 meRamRaddr: 12; // 0
		uint32 unknown1: 20;
	};
	uint32 val;
};

// CP_ME_RAM_WADDR
union CpMeRamWaddr {
	struct {
		uint32 meRamWaddr: 12; // 0
		uint32 unknown1: 20;
	};
	uint32 val;
};

// CP_NUM_PRIM_NEEDED_COUNT0_HI
union CpNumPrimNeededCount0Hi {
	struct {
		uint32 numPrimNeededCnt0Hi: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_NEEDED_COUNT0_LO
union CpNumPrimNeededCount0Lo {
	struct {
		uint32 numPrimNeededCnt0Lo: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_NEEDED_COUNT1_HI
union CpNumPrimNeededCount1Hi {
	struct {
		uint32 numPrimNeededCnt1Hi: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_NEEDED_COUNT1_LO
union CpNumPrimNeededCount1Lo {
	struct {
		uint32 numPrimNeededCnt1Lo: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_NEEDED_COUNT2_HI
union CpNumPrimNeededCount2Hi {
	struct {
		uint32 numPrimNeededCnt2Hi: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_NEEDED_COUNT2_LO
union CpNumPrimNeededCount2Lo {
	struct {
		uint32 numPrimNeededCnt2Lo: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_NEEDED_COUNT3_HI
union CpNumPrimNeededCount3Hi {
	struct {
		uint32 numPrimNeededCnt3Hi: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_NEEDED_COUNT3_LO
union CpNumPrimNeededCount3Lo {
	struct {
		uint32 numPrimNeededCnt3Lo: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_WRITTEN_COUNT0_HI
union CpNumPrimWrittenCount0Hi {
	struct {
		uint32 numPrimWrittenCnt0Hi: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_WRITTEN_COUNT0_LO
union CpNumPrimWrittenCount0Lo {
	struct {
		uint32 numPrimWrittenCnt0Lo: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_WRITTEN_COUNT1_HI
union CpNumPrimWrittenCount1Hi {
	struct {
		uint32 numPrimWrittenCnt1Hi: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_WRITTEN_COUNT1_LO
union CpNumPrimWrittenCount1Lo {
	struct {
		uint32 numPrimWrittenCnt1Lo: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_WRITTEN_COUNT2_HI
union CpNumPrimWrittenCount2Hi {
	struct {
		uint32 numPrimWrittenCnt2Hi: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_WRITTEN_COUNT2_LO
union CpNumPrimWrittenCount2Lo {
	struct {
		uint32 numPrimWrittenCnt2Lo: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_WRITTEN_COUNT3_HI
union CpNumPrimWrittenCount3Hi {
	struct {
		uint32 numPrimWrittenCnt3Hi: 32; // 0
	};
	uint32 val;
};

// CP_NUM_PRIM_WRITTEN_COUNT3_LO
union CpNumPrimWrittenCount3Lo {
	struct {
		uint32 numPrimWrittenCnt3Lo: 32; // 0
	};
	uint32 val;
};

// CP_PA_CINVOC_COUNT_HI
union CpPaCinvocCountHi {
	struct {
		uint32 cinvocCountHi: 32; // 0
	};
	uint32 val;
};

// CP_PA_CINVOC_COUNT_LO
union CpPaCinvocCountLo {
	struct {
		uint32 cinvocCountLo: 32; // 0
	};
	uint32 val;
};

// CP_PA_CPRIM_COUNT_HI
union CpPaCprimCountHi {
	struct {
		uint32 cprimCountHi: 32; // 0
	};
	uint32 val;
};

// CP_PA_CPRIM_COUNT_LO
union CpPaCprimCountLo {
	struct {
		uint32 cprimCountLo: 32; // 0
	};
	uint32 val;
};

// CP_PERFMON_CNTL
union CpPerfmonCntl {
	struct {
		uint32 perfmonState: 4; // 0
		uint32 spmPerfmonState: 4; // 4
		uint32 perfmonEnableMode: 2; // 8
		uint32 perfmonSampleEnable: 1; // 10
		uint32 unknown1: 21;
	};
	uint32 val;
};

// CP_PERFMON_CNTX_CNTL
union CpPerfmonCntxCntl {
	struct {
		uint32 unknown1: 31;
		uint32 perfmonEnable: 1; // 31
	};
	uint32 val;
};

// CP_PFP_HEADER_DUMP
union CpPfpHeaderDump {
	struct {
		uint32 pfpHeaderDump: 32; // 0
	};
	uint32 val;
};

// CP_PFP_IB_CONTROL
union CpPfpIbControl {
	struct {
		uint32 ibEn: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CP_PFP_LOAD_CONTROL
union CpPfpLoadControl {
	struct {
		uint32 configRegEn: 1; // 0
		uint32 cntxRegEn: 1; // 1
		uint32 unknown1: 13;
		uint32 uconfigRegEn: 1; // 15
		uint32 shGfxRegEn: 1; // 16
		uint32 unknown2: 7;
		uint32 shCsRegEn: 1; // 24
		uint32 unknown3: 7;
	};
	uint32 val;
};

// CP_PFP_UCODE_ADDR
union CpPfpUcodeAddr {
	struct {
		uint32 ucodeAddr: 12; // 0
		uint32 unknown1: 20;
	};
	uint32 val;
};

// CP_PFP_UCODE_DATA
union CpPfpUcodeData {
	struct {
		uint32 ucodeData: 32; // 0
	};
	uint32 val;
};

// CP_PIPE_STATS_ADDR_HI
union CpPipeStatsAddrHi {
	struct {
		uint32 pipeStatsAddrHi: 32; // 0
	};
	uint32 val;
};

// CP_PIPE_STATS_ADDR_LO
union CpPipeStatsAddrLo {
	struct {
		uint32 pipeStatsAddrSwap: 2; // 0
		uint32 pipeStatsAddrLo: 30; // 2
	};
	uint32 val;
};

// CP_PWR_CNTL
union CpPwrCntl {
	struct {
		uint32 gfxClkHalt: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CP_QUEUE_THRESHOLDS
union CpQueueThresholds {
	struct {
		uint32 roqIb1Start: 6; // 0
		uint32 unknown1: 2;
		uint32 roqIb2Start: 6; // 8
		uint32 unknown2: 18;
	};
	uint32 val;
};

// CP_RB0_BASE
union CpRb0Base {
	struct {
		uint32 rbBase: 32; // 0
	};
	uint32 val;
};

// CP_RB0_BASE_HI
union CpRb0BaseHi {
	struct {
		uint32 rbBaseHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_RB0_CNTL
union CpRb0Cntl {
	struct {
		uint32 rbBufsz: 6; // 0
		uint32 unknown1: 2;
		uint32 rbBlksz: 6; // 8
		uint32 unknown2: 2;
		uint32 bufSwap: 2; // 16
		uint32 unknown3: 2;
		uint32 minAvailsz: 2; // 20
		uint32 minIbAvailsz: 2; // 22
		uint32 cachePolicy: 2; // 24
		uint32 rbVolatile: 1; // 26
		uint32 rbNoUpdate: 1; // 27
		uint32 unknown4: 3;
		uint32 rbRptrWrEna: 1; // 31
	};
	uint32 val;
};

// CP_RB0_RPTR
union CpRb0Rptr {
	struct {
		uint32 rbRptr: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_RB0_RPTR_ADDR
union CpRb0RptrAddr {
	struct {
		uint32 rbRptrSwap: 2; // 0
		uint32 rbRptrAddr: 30; // 2
	};
	uint32 val;
};

// CP_RB0_RPTR_ADDR_HI
union CpRb0RptrAddrHi {
	struct {
		uint32 rbRptrAddrHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_RB0_WPTR
union CpRb0Wptr {
	struct {
		uint32 rbWptr: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_RB1_BASE
union CpRb1Base {
	struct {
		uint32 rbBase: 32; // 0
	};
	uint32 val;
};

// CP_RB1_BASE_HI
union CpRb1BaseHi {
	struct {
		uint32 rbBaseHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_RB1_CNTL
union CpRb1Cntl {
	struct {
		uint32 rbBufsz: 6; // 0
		uint32 unknown1: 2;
		uint32 rbBlksz: 6; // 8
		uint32 unknown2: 6;
		uint32 minAvailsz: 2; // 20
		uint32 minIbAvailsz: 2; // 22
		uint32 cachePolicy: 2; // 24
		uint32 rbVolatile: 1; // 26
		uint32 rbNoUpdate: 1; // 27
		uint32 unknown3: 3;
		uint32 rbRptrWrEna: 1; // 31
	};
	uint32 val;
};

// CP_RB1_RPTR
union CpRb1Rptr {
	struct {
		uint32 rbRptr: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_RB1_RPTR_ADDR
union CpRb1RptrAddr {
	struct {
		uint32 rbRptrSwap: 2; // 0
		uint32 rbRptrAddr: 30; // 2
	};
	uint32 val;
};

// CP_RB1_RPTR_ADDR_HI
union CpRb1RptrAddrHi {
	struct {
		uint32 rbRptrAddrHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_RB1_WPTR
union CpRb1Wptr {
	struct {
		uint32 rbWptr: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_RB2_BASE
union CpRb2Base {
	struct {
		uint32 rbBase: 32; // 0
	};
	uint32 val;
};

// CP_RB2_CNTL
union CpRb2Cntl {
	struct {
		uint32 rbBufsz: 6; // 0
		uint32 unknown1: 2;
		uint32 rbBlksz: 6; // 8
		uint32 unknown2: 6;
		uint32 minAvailsz: 2; // 20
		uint32 minIbAvailsz: 2; // 22
		uint32 cachePolicy: 2; // 24
		uint32 rbVolatile: 1; // 26
		uint32 rbNoUpdate: 1; // 27
		uint32 unknown3: 3;
		uint32 rbRptrWrEna: 1; // 31
	};
	uint32 val;
};

// CP_RB2_RPTR
union CpRb2Rptr {
	struct {
		uint32 rbRptr: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_RB2_RPTR_ADDR
union CpRb2RptrAddr {
	struct {
		uint32 rbRptrSwap: 2; // 0
		uint32 rbRptrAddr: 30; // 2
	};
	uint32 val;
};

// CP_RB2_RPTR_ADDR_HI
union CpRb2RptrAddrHi {
	struct {
		uint32 rbRptrAddrHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_RB2_WPTR
union CpRb2Wptr {
	struct {
		uint32 rbWptr: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_RB_BASE
union CpRbBase {
	struct {
		uint32 rbBase: 32; // 0
	};
	uint32 val;
};

// CP_RB_CNTL
union CpRbCntl {
	struct {
		uint32 rbBufsz: 6; // 0
		uint32 unknown1: 2;
		uint32 rbBlksz: 6; // 8
		uint32 unknown2: 2;
		uint32 bufSwap: 2; // 16
		uint32 unknown3: 2;
		uint32 minAvailsz: 2; // 20
		uint32 minIbAvailsz: 2; // 22
		uint32 cachePolicy: 2; // 24
		uint32 rbVolatile: 1; // 26
		uint32 rbNoUpdate: 1; // 27
		uint32 unknown4: 3;
		uint32 rbRptrWrEna: 1; // 31
	};
	uint32 val;
};

// CP_RB_OFFSET
union CpRbOffset {
	struct {
		uint32 rbOffset: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_RB_RPTR
union CpRbRptr {
	struct {
		uint32 rbRptr: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_RB_RPTR_ADDR
union CpRbRptrAddr {
	struct {
		uint32 rbRptrSwap: 2; // 0
		uint32 rbRptrAddr: 30; // 2
	};
	uint32 val;
};

// CP_RB_RPTR_ADDR_HI
union CpRbRptrAddrHi {
	struct {
		uint32 rbRptrAddrHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_RB_RPTR_WR
union CpRbRptrWr {
	struct {
		uint32 rbRptrWr: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_RB_VMID
union CpRbVmid {
	struct {
		uint32 rb0Vmid: 4; // 0
		uint32 unknown1: 4;
		uint32 rb1Vmid: 4; // 8
		uint32 unknown2: 4;
		uint32 rb2Vmid: 4; // 16
		uint32 unknown3: 12;
	};
	uint32 val;
};

// CP_RB_WPTR
union CpRbWptr {
	struct {
		uint32 rbWptr: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_RB_WPTR_DELAY
union CpRbWptrDelay {
	struct {
		uint32 preWriteTimer: 28; // 0
		uint32 preWriteLimit: 4; // 28
	};
	uint32 val;
};

// CP_RB_WPTR_POLL_ADDR_HI
union CpRbWptrPollAddrHi {
	struct {
		uint32 obsolete: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_RB_WPTR_POLL_ADDR_LO
union CpRbWptrPollAddrLo {
	struct {
		uint32 unknown1: 2;
		uint32 obsolete: 30; // 2
	};
	uint32 val;
};

// CP_RB_WPTR_POLL_CNTL
union CpRbWptrPollCntl {
	struct {
		uint32 pollFrequency: 16; // 0
		uint32 idlePollCount: 16; // 16
	};
	uint32 val;
};

// CP_RING0_PRIORITY
union CpRing0Priority {
	struct {
		uint32 priority: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// CP_RING1_PRIORITY
union CpRing1Priority {
	struct {
		uint32 priority: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// CP_RING2_PRIORITY
union CpRing2Priority {
	struct {
		uint32 priority: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// CP_RINGID
union CpRingid {
	struct {
		uint32 ringid: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// CP_RING_PRIORITY_CNTS
union CpRingPriorityCnts {
	struct {
		uint32 priority1Cnt: 8; // 0
		uint32 priority2aCnt: 8; // 8
		uint32 priority2bCnt: 8; // 16
		uint32 priority3Cnt: 8; // 24
	};
	uint32 val;
};

// CP_ROQ1_THRESHOLDS
union CpRoq1Thresholds {
	struct {
		uint32 rb1Start: 8; // 0
		uint32 rb2Start: 8; // 8
		uint32 r0Ib1Start: 8; // 16
		uint32 r1Ib1Start: 8; // 24
	};
	uint32 val;
};

// CP_ROQ2_AVAIL
union CpRoq2Avail {
	struct {
		uint32 roqCntIb2: 11; // 0
		uint32 unknown1: 21;
	};
	uint32 val;
};

// CP_ROQ2_THRESHOLDS
union CpRoq2Thresholds {
	struct {
		uint32 r2Ib1Start: 8; // 0
		uint32 r0Ib2Start: 8; // 8
		uint32 r1Ib2Start: 8; // 16
		uint32 r2Ib2Start: 8; // 24
	};
	uint32 val;
};

// CP_ROQ_AVAIL
union CpRoqAvail {
	struct {
		uint32 roqCntRing: 11; // 0
		uint32 unknown1: 5;
		uint32 roqCntIb1: 11; // 16
		uint32 unknown2: 5;
	};
	uint32 val;
};

// CP_ROQ_IB1_STAT
union CpRoqIb1Stat {
	struct {
		uint32 roqRptrIndirect1: 10; // 0
		uint32 unknown1: 6;
		uint32 roqWptrIndirect1: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// CP_ROQ_IB2_STAT
union CpRoqIb2Stat {
	struct {
		uint32 roqRptrIndirect2: 10; // 0
		uint32 unknown1: 6;
		uint32 roqWptrIndirect2: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// CP_ROQ_RB_STAT
union CpRoqRbStat {
	struct {
		uint32 roqRptrPrimary: 10; // 0
		uint32 unknown1: 6;
		uint32 roqWptrPrimary: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// CP_SCRATCH_DATA
union CpScratchData {
	struct {
		uint32 scratchData: 32; // 0
	};
	uint32 val;
};

// CP_SCRATCH_INDEX
union CpScratchIndex {
	struct {
		uint32 scratchIndex: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_SC_PSINVOC_COUNT0_HI
union CpScPsinvocCount0Hi {
	struct {
		uint32 psinvocCount0Hi: 32; // 0
	};
	uint32 val;
};

// CP_SC_PSINVOC_COUNT0_LO
union CpScPsinvocCount0Lo {
	struct {
		uint32 psinvocCount0Lo: 32; // 0
	};
	uint32 val;
};

// CP_SC_PSINVOC_COUNT1_HI
union CpScPsinvocCount1Hi {
	struct {
		uint32 obsolete: 32; // 0
	};
	uint32 val;
};

// CP_SC_PSINVOC_COUNT1_LO
union CpScPsinvocCount1Lo {
	struct {
		uint32 obsolete: 32; // 0
	};
	uint32 val;
};

// CP_SEM_WAIT_TIMER
union CpSemWaitTimer {
	struct {
		uint32 semWaitTimer: 32; // 0
	};
	uint32 val;
};

// CP_SIG_SEM_ADDR_HI
union CpSigSemAddrHi {
	struct {
		uint32 semAddrHi: 8; // 0
		uint32 unknown1: 8;
		uint32 semUseMailbox: 1; // 16
		uint32 unknown2: 3;
		uint32 semSignalType: 1; // 20
		uint32 unknown3: 3;
		uint32 semClientCode: 2; // 24
		uint32 unknown4: 3;
		uint32 semSelect: 3; // 29
	};
	uint32 val;
};

// CP_SIG_SEM_ADDR_LO
union CpSigSemAddrLo {
	struct {
		uint32 semAddrSwap: 2; // 0
		uint32 unknown1: 1;
		uint32 semAddrLo: 29; // 3
	};
	uint32 val;
};

// CP_STALLED_STAT1
union CpStalledStat1 {
	struct {
		uint32 rbiuToDmaNotRdyToRcv: 1; // 0
		uint32 unknown1: 1;
		uint32 rbiuToSemNotRdyToRcv: 1; // 2
		uint32 unknown2: 1;
		uint32 rbiuToMemwrNotRdyToRcv: 1; // 4
		uint32 unknown3: 5;
		uint32 meHasActiveCeBufferFlag: 1; // 10
		uint32 meHasActiveDeBufferFlag: 1; // 11
		uint32 meStalledOnTcWrConfirm: 1; // 12
		uint32 meStalledOnAtomicRtnData: 1; // 13
		uint32 meWaitingOnMcReadData: 1; // 14
		uint32 meWaitingOnRegReadData: 1; // 15
		uint32 miuWaitingOnRdreqFree: 1; // 16
		uint32 miuWaitingOnWrreqFree: 1; // 17
		uint32 unknown4: 5;
		uint32 rciuWaitingOnGdsFree: 1; // 23
		uint32 rciuWaitingOnGrbmFree: 1; // 24
		uint32 rciuWaitingOnVgtFree: 1; // 25
		uint32 rciuStalledOnMeRead: 1; // 26
		uint32 rciuStalledOnDmaRead: 1; // 27
		uint32 rciuHaltedByRegViolation: 1; // 28
		uint32 unknown5: 3;
	};
	uint32 val;
};

// CP_STALLED_STAT2
union CpStalledStat2 {
	struct {
		uint32 pfpToCsfNotRdyToRcv: 1; // 0
		uint32 pfpToMeqNotRdyToRcv: 1; // 1
		uint32 pfpToRciuNotRdyToRcv: 1; // 2
		uint32 unknown1: 1;
		uint32 pfpToVgtWritesPending: 1; // 4
		uint32 pfpRciuReadPending: 1; // 5
		uint32 pfpMiuReadPending: 1; // 6
		uint32 pfpToMiuWriteNotRdyToRcv: 1; // 7
		uint32 pfpWaitingOnBufferData: 1; // 8
		uint32 meWaitOnCeCounter: 1; // 9
		uint32 meWaitOnAvailBuffer: 1; // 10
		uint32 gfxCntxNotAvailToMe: 1; // 11
		uint32 meRciuNotRdyToRcv: 1; // 12
		uint32 meToConstNotRdyToRcv: 1; // 13
		uint32 meWaitingDataFromPfp: 1; // 14
		uint32 meWaitingOnPartialFlush: 1; // 15
		uint32 meqToMeNotRdyToRcv: 1; // 16
		uint32 stqToMeNotRdyToRcv: 1; // 17
		uint32 meWaitingDataFromStq: 1; // 18
		uint32 pfpStalledOnTcWrConfirm: 1; // 19
		uint32 pfpStalledOnAtomicRtnData: 1; // 20
		uint32 eopdFifoNeedsScEopDone: 1; // 21
		uint32 eopdFifoNeedsWrConfirm: 1; // 22
		uint32 strmoWrOfPrimDataPending: 1; // 23
		uint32 pipeStatsWrDataPending: 1; // 24
		uint32 appendRdyWaitOnCsDone: 1; // 25
		uint32 appendRdyWaitOnPsDone: 1; // 26
		uint32 appendWaitOnWrConfirm: 1; // 27
		uint32 appendActivePartition: 1; // 28
		uint32 appendWaitingToSendMemwrite: 1; // 29
		uint32 surfSyncNeedsIdleCntxs: 1; // 30
		uint32 surfSyncNeedsAllClean: 1; // 31
	};
	uint32 val;
};

// CP_STALLED_STAT3
union CpStalledStat3 {
	struct {
		uint32 ceToCsfNotRdyToRcv: 1; // 0
		uint32 ceToRamInitFetcherNotRdyToRcv: 1; // 1
		uint32 ceWaitingOnDataFromRamInitFetcher: 1; // 2
		uint32 ceToRamInitNotRdy: 1; // 3
		uint32 ceToRamDumpNotRdy: 1; // 4
		uint32 ceToRamWriteNotRdy: 1; // 5
		uint32 ceToIncFifoNotRdyToRcv: 1; // 6
		uint32 ceToWrFifoNotRdyToRcv: 1; // 7
		uint32 ceToMiuWriteNotRdyToRcv: 1; // 8
		uint32 unknown1: 1;
		uint32 ceWaitingOnBufferData: 1; // 10
		uint32 ceWaitingOnCeBufferFlag: 1; // 11
		uint32 ceWaitingOnDeCounter: 1; // 12
		uint32 ceWaitingOnDeCounterUnderflow: 1; // 13
		uint32 tciuWaitingOnFree: 1; // 14
		uint32 tciuWaitingOnTags: 1; // 15
		uint32 unknown2: 16;
	};
	uint32 val;
};

// CP_STAT
union CpStat {
	struct {
		uint32 unknown1: 7;
		uint32 miuRdreqBusy: 1; // 7
		uint32 miuWrreqBusy: 1; // 8
		uint32 roqRingBusy: 1; // 9
		uint32 roqIndirect1Busy: 1; // 10
		uint32 roqIndirect2Busy: 1; // 11
		uint32 roqStateBusy: 1; // 12
		uint32 dcBusy: 1; // 13
		uint32 unknown2: 1;
		uint32 pfpBusy: 1; // 15
		uint32 meqBusy: 1; // 16
		uint32 meBusy: 1; // 17
		uint32 queryBusy: 1; // 18
		uint32 semaphoreBusy: 1; // 19
		uint32 interruptBusy: 1; // 20
		uint32 surfaceSyncBusy: 1; // 21
		uint32 dmaBusy: 1; // 22
		uint32 rciuBusy: 1; // 23
		uint32 scratchRamBusy: 1; // 24
		uint32 cpcCpgBusy: 1; // 25
		uint32 ceBusy: 1; // 26
		uint32 tciuBusy: 1; // 27
		uint32 roqCeRingBusy: 1; // 28
		uint32 roqCeIndirect1Busy: 1; // 29
		uint32 roqCeIndirect2Busy: 1; // 30
		uint32 cpBusy: 1; // 31
	};
	uint32 val;
};

// CP_STQ_AVAIL
union CpStqAvail {
	struct {
		uint32 stqCnt: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// CP_STQ_STAT
union CpStqStat {
	struct {
		uint32 stqRptr: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// CP_STQ_THRESHOLDS
union CpStqThresholds {
	struct {
		uint32 stq0Start: 8; // 0
		uint32 stq1Start: 8; // 8
		uint32 stq2Start: 8; // 16
		uint32 unknown1: 8;
	};
	uint32 val;
};

// CP_STREAM_OUT_ADDR_HI
union CpStreamOutAddrHi {
	struct {
		uint32 streamOutAddrHi: 32; // 0
	};
	uint32 val;
};

// CP_STREAM_OUT_ADDR_LO
union CpStreamOutAddrLo {
	struct {
		uint32 streamOutAddrSwap: 2; // 0
		uint32 streamOutAddrLo: 30; // 2
	};
	uint32 val;
};

// CP_STRMOUT_CNTL
union CpStrmoutCntl {
	struct {
		uint32 offsetUpdateDone: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CP_ST_BASE_HI
union CpStBaseHi {
	struct {
		uint32 stBaseHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CP_ST_BASE_LO
union CpStBaseLo {
	struct {
		uint32 unknown1: 2;
		uint32 stBaseLo: 30; // 2
	};
	uint32 val;
};

// CP_ST_BUFSZ
union CpStBufsz {
	struct {
		uint32 stBufsz: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// CP_VGT_CSINVOC_COUNT_HI
union CpVgtCsinvocCountHi {
	struct {
		uint32 csinvocCountHi: 32; // 0
	};
	uint32 val;
};

// CP_VGT_CSINVOC_COUNT_LO
union CpVgtCsinvocCountLo {
	struct {
		uint32 csinvocCountLo: 32; // 0
	};
	uint32 val;
};

// CP_VGT_DSINVOC_COUNT_HI
union CpVgtDsinvocCountHi {
	struct {
		uint32 dsinvocCountHi: 32; // 0
	};
	uint32 val;
};

// CP_VGT_DSINVOC_COUNT_LO
union CpVgtDsinvocCountLo {
	struct {
		uint32 dsinvocCountLo: 32; // 0
	};
	uint32 val;
};

// CP_VGT_GSINVOC_COUNT_HI
union CpVgtGsinvocCountHi {
	struct {
		uint32 gsinvocCountHi: 32; // 0
	};
	uint32 val;
};

// CP_VGT_GSINVOC_COUNT_LO
union CpVgtGsinvocCountLo {
	struct {
		uint32 gsinvocCountLo: 32; // 0
	};
	uint32 val;
};

// CP_VGT_GSPRIM_COUNT_HI
union CpVgtGsprimCountHi {
	struct {
		uint32 gsprimCountHi: 32; // 0
	};
	uint32 val;
};

// CP_VGT_GSPRIM_COUNT_LO
union CpVgtGsprimCountLo {
	struct {
		uint32 gsprimCountLo: 32; // 0
	};
	uint32 val;
};

// CP_VGT_HSINVOC_COUNT_HI
union CpVgtHsinvocCountHi {
	struct {
		uint32 hsinvocCountHi: 32; // 0
	};
	uint32 val;
};

// CP_VGT_HSINVOC_COUNT_LO
union CpVgtHsinvocCountLo {
	struct {
		uint32 hsinvocCountLo: 32; // 0
	};
	uint32 val;
};

// CP_VGT_IAPRIM_COUNT_HI
union CpVgtIaprimCountHi {
	struct {
		uint32 iaprimCountHi: 32; // 0
	};
	uint32 val;
};

// CP_VGT_IAPRIM_COUNT_LO
union CpVgtIaprimCountLo {
	struct {
		uint32 iaprimCountLo: 32; // 0
	};
	uint32 val;
};

// CP_VGT_IAVERT_COUNT_HI
union CpVgtIavertCountHi {
	struct {
		uint32 iavertCountHi: 32; // 0
	};
	uint32 val;
};

// CP_VGT_IAVERT_COUNT_LO
union CpVgtIavertCountLo {
	struct {
		uint32 iavertCountLo: 32; // 0
	};
	uint32 val;
};

// CP_VGT_VSINVOC_COUNT_HI
union CpVgtVsinvocCountHi {
	struct {
		uint32 vsinvocCountHi: 32; // 0
	};
	uint32 val;
};

// CP_VGT_VSINVOC_COUNT_LO
union CpVgtVsinvocCountLo {
	struct {
		uint32 vsinvocCountLo: 32; // 0
	};
	uint32 val;
};

// CP_VMID
union CpVmid {
	struct {
		uint32 vmid: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// CP_VMID_PREEMPT
union CpVmidPreempt {
	struct {
		uint32 preemptRequest: 16; // 0
		uint32 preemptStatus: 16; // 16
	};
	uint32 val;
};

// CP_VMID_RESET
union CpVmidReset {
	struct {
		uint32 resetRequest: 16; // 0
		uint32 resetStatus: 16; // 16
	};
	uint32 val;
};

// CP_WAIT_REG_MEM_TIMEOUT
union CpWaitRegMemTimeout {
	struct {
		uint32 waitRegMemTimeout: 32; // 0
	};
	uint32 val;
};

// CP_WAIT_SEM_ADDR_HI
union CpWaitSemAddrHi {
	struct {
		uint32 semAddrHi: 8; // 0
		uint32 unknown1: 8;
		uint32 semUseMailbox: 1; // 16
		uint32 unknown2: 3;
		uint32 semSignalType: 1; // 20
		uint32 unknown3: 3;
		uint32 semClientCode: 2; // 24
		uint32 unknown4: 3;
		uint32 semSelect: 3; // 29
	};
	uint32 val;
};

// CP_WAIT_SEM_ADDR_LO
union CpWaitSemAddrLo {
	struct {
		uint32 semAddrSwap: 2; // 0
		uint32 unknown1: 1;
		uint32 semAddrLo: 29; // 3
	};
	uint32 val;
};

// CS_COPY_STATE
union CsCopyState {
	struct {
		uint32 srcStateId: 3; // 0
		uint32 unknown1: 29;
	};
	uint32 val;
};

// DB_ALPHA_TO_MASK
union DbAlphaToMask {
	struct {
		uint32 alphaToMaskEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 alphaToMaskOffset0: 2; // 8
		uint32 alphaToMaskOffset1: 2; // 10
		uint32 alphaToMaskOffset2: 2; // 12
		uint32 alphaToMaskOffset3: 2; // 14
		uint32 offsetRound: 1; // 16
		uint32 unknown2: 15;
	};
	uint32 val;
};

// DB_CGTT_CLK_CTRL_0
union DbCgttClkCtrl0 {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 reserved: 12; // 12
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// DB_COUNT_CONTROL
union DbCountControl {
	struct {
		uint32 zpassIncrementDisable: 1; // 0
		uint32 perfectZpassCounts: 1; // 1
		uint32 unknown1: 2;
		uint32 sampleRate: 3; // 4
		uint32 unknown2: 1;
		uint32 zpassEnable: 4; // 8
		uint32 zfailEnable: 4; // 12
		uint32 sfailEnable: 4; // 16
		uint32 dbfailEnable: 4; // 20
		uint32 sliceEvenEnable: 4; // 24
		uint32 sliceOddEnable: 4; // 28
	};
	uint32 val;
};

// DB_CREDIT_LIMIT
union DbCreditLimit {
	struct {
		uint32 dbScTileCredits: 5; // 0
		uint32 dbScQuadCredits: 5; // 5
		uint32 dbCbLquadCredits: 3; // 10
		uint32 unknown1: 11;
		uint32 dbCbTileCredits: 7; // 24
		uint32 unknown2: 1;
	};
	uint32 val;
};

// DB_DEBUG
union DbDebug {
	struct {
		uint32 debugStencilCompressDisable: 1; // 0
		uint32 debugDepthCompressDisable: 1; // 1
		uint32 fetchFullZTile: 1; // 2
		uint32 fetchFullStencilTile: 1; // 3
		uint32 forceZMode: 2; // 4
		uint32 debugForceDepthRead: 1; // 6
		uint32 debugForceStencilRead: 1; // 7
		uint32 debugForceHizEnable: 2; // 8
		uint32 debugForceHisEnable0: 2; // 10
		uint32 debugForceHisEnable1: 2; // 12
		uint32 debugFastZDisable: 1; // 14
		uint32 debugFastStencilDisable: 1; // 15
		uint32 debugNoopCullDisable: 1; // 16
		uint32 disableSummSquads: 1; // 17
		uint32 depthCacheForceMiss: 1; // 18
		uint32 debugForceFullZRange: 2; // 19
		uint32 neverFreeZOnly: 1; // 21
		uint32 zpassCountsLookAtPipeStatEvents: 1; // 22
		uint32 disableVportZplaneOptimization: 1; // 23
		uint32 decompressAfterNZplanes: 4; // 24
		uint32 oneFreeInFlight: 1; // 28
		uint32 forceMissIfNotInflight: 1; // 29
		uint32 disableDepthSurfaceSync: 1; // 30
		uint32 disableHtileSurfaceSync: 1; // 31
	};
	uint32 val;
};

// DB_DEBUG2
union DbDebug2 {
	struct {
		uint32 allowCompzByteMasking: 1; // 0
		uint32 disableTcZrangeL0Cache: 1; // 1
		uint32 disableTcMaskL0Cache: 1; // 2
		uint32 dtrRoundRobinArb: 1; // 3
		uint32 dtrPrezStallsForEtfRoom: 1; // 4
		uint32 disablePrezlLpfStall: 1; // 5
		uint32 enablePrezlCbStall: 1; // 6
		uint32 disablePrezlLpfStallRez: 1; // 7
		uint32 disablePrezlCbStallRez: 1; // 8
		uint32 clkOffDelay: 5; // 9
		uint32 disableTileCoveredForPsIter: 1; // 14
		uint32 enableSubtileGrouping: 1; // 15
		uint32 disableHtilePairedPipes: 1; // 16
		uint32 disableNullEotForwarding: 1; // 17
		uint32 disableDttDataForwarding: 1; // 18
		uint32 disableQuadCoherencyStall: 1; // 19
		uint32 unknown1: 8;
		uint32 enablePrezOfRezSumm: 1; // 28
		uint32 disablePrezlViewportStall: 1; // 29
		uint32 unknown2: 1;
		uint32 disableSingleStencilQuadSumm: 1; // 31
	};
	uint32 val;
};

// DB_DEBUG3
union DbDebug3 {
	struct {
		uint32 unknown1: 2;
		uint32 forceDbIsGood: 1; // 2
		uint32 disableTlSsoNullSuppression: 1; // 3
		uint32 disableHizOnVportClamp: 1; // 4
		uint32 eqaaInterpolateCompZ: 1; // 5
		uint32 eqaaInterpolateSrcZ: 1; // 6
		uint32 disableTcpCamBypass: 1; // 7
		uint32 disableZcmpDirtySuppression: 1; // 8
		uint32 unknown2: 1;
		uint32 disableRedundantPlaneFlushesOpt: 1; // 10
		uint32 disableRecompTo1zplaneWithoutFastop: 1; // 11
		uint32 enableIncoherentEqaaReads: 1; // 12
		uint32 disableOpZDataForwarding: 1; // 13
		uint32 disableOpDfBypass: 1; // 14
		uint32 disableOpDfWriteCombine: 1; // 15
		uint32 disableOpDfDirectFeedback: 1; // 16
		uint32 allowRf2pRwCollision: 1; // 17
		uint32 slowPrezToA2mOmaskRate: 1; // 18
		uint32 disableOpSDataForwarding: 1; // 19
		uint32 disableTcUpdateWriteCombine: 1; // 20
		uint32 disableHzTcWriteCombine: 1; // 21
		uint32 enableRecompZdirtySuppressionOpt: 1; // 22
		uint32 disableRamReadSuppresionOnFwd: 1; // 23
		uint32 disableEqaaA2mPerfOpt: 1; // 24
		uint32 disableDiDtStall: 1; // 25
		uint32 dbExtraDebug3: 6; // 26
		// uint32 unknown3: -5;
		// uint32 disableOverrasterizationFix: 1;
		// uint32 unknown4: -4;
		// uint32 dontInsertContextSuspend: 1;
		// uint32 unknown5: -3;
		// uint32 dontDeleteContextSuspend: 1;
	};
	uint32 val;
};

// DB_DEBUG4
union DbDebug4 {
	struct {
		uint32 disableQcZMaskSummation: 1; // 0
		uint32 disableQcStencilMaskSummation: 1; // 1
		uint32 disableResummToSingleStencil: 1; // 2
		uint32 unknown1: 2;
		uint32 disablePrezPostzDtileConflictStall: 1; // 5
		uint32 dbExtraDebug4: 26; // 6
	};
	uint32 val;
};

// DB_DEPTH_BOUNDS_MAX
union DbDepthBoundsMax {
	struct {
		uint32 max: 32; // 0
	};
	uint32 val;
};

// DB_DEPTH_BOUNDS_MIN
union DbDepthBoundsMin {
	struct {
		uint32 min: 32; // 0
	};
	uint32 val;
};

// DB_DEPTH_CLEAR
union DbDepthClear {
	struct {
		uint32 depthClear: 32; // 0
	};
	uint32 val;
};

// DB_DEPTH_CONTROL
union DbDepthControl {
	struct {
		uint32 stencilEnable: 1; // 0
		uint32 zEnable: 1; // 1
		uint32 zWriteEnable: 1; // 2
		uint32 depthBoundsEnable: 1; // 3
		uint32 zfunc: 3; // 4
		uint32 backfaceEnable: 1; // 7
		uint32 stencilfunc: 3; // 8
		uint32 unknown1: 9;
		uint32 stencilfuncBf: 3; // 20
		uint32 unknown2: 7;
		uint32 enableColorWritesOnDepthFail: 1; // 30
		uint32 disableColorWritesOnDepthPass: 1; // 31
	};
	uint32 val;
};

// DB_DEPTH_INFO
union DbDepthInfo {
	struct {
		uint32 addr5SwizzleMask: 4; // 0
		uint32 arrayMode: 4; // 4
		uint32 pipeConfig: 5; // 8
		uint32 bankWidth: 2; // 13
		uint32 bankHeight: 2; // 15
		uint32 macroTileAspect: 2; // 17
		uint32 numBanks: 2; // 19
		uint32 unknown1: 11;
	};
	uint32 val;
};

// DB_DEPTH_SIZE
union DbDepthSize {
	struct {
		uint32 pitchTileMax: 11; // 0
		uint32 heightTileMax: 11; // 11
		uint32 unknown1: 10;
	};
	uint32 val;
};

// DB_DEPTH_SLICE
union DbDepthSlice {
	struct {
		uint32 sliceTileMax: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// DB_DEPTH_VIEW
union DbDepthView {
	struct {
		uint32 sliceStart: 11; // 0
		uint32 unknown1: 2;
		uint32 sliceMax: 11; // 13
		uint32 zReadOnly: 1; // 24
		uint32 stencilReadOnly: 1; // 25
		uint32 unknown2: 6;
	};
	uint32 val;
};

// DB_EQAA
union DbEqaa {
	struct {
		uint32 maxAnchorSamples: 3; // 0
		uint32 unknown1: 1;
		uint32 psIterSamples: 3; // 4
		uint32 unknown2: 1;
		uint32 maskExportNumSamples: 3; // 8
		uint32 unknown3: 1;
		uint32 alphaToMaskNumSamples: 3; // 12
		uint32 unknown4: 1;
		uint32 highQualityIntersections: 1; // 16
		uint32 incoherentEqaaReads: 1; // 17
		uint32 interpolateCompZ: 1; // 18
		uint32 interpolateSrcZ: 1; // 19
		uint32 staticAnchorAssociations: 1; // 20
		uint32 alphaToMaskEqaaDisable: 1; // 21
		uint32 unknown5: 2;
		uint32 overrasterizationAmount: 3; // 24
		uint32 enablePostzOverrasterization: 1; // 27
		uint32 unknown6: 4;
	};
	uint32 val;
};

// DB_FIFO_DEPTH1
union DbFifoDepth1 {
	struct {
		uint32 miRdreqFifoDepth: 5; // 0
		uint32 miWrreqFifoDepth: 5; // 5
		uint32 mccDepth: 6; // 10
		uint32 qcDepth: 5; // 16
		uint32 ltileProbeFifoDepth: 8; // 21
		uint32 unknown1: 3;
	};
	uint32 val;
};

// DB_FIFO_DEPTH2
union DbFifoDepth2 {
	struct {
		uint32 equadFifoDepth: 8; // 0
		uint32 etileOpFifoDepth: 7; // 8
		uint32 lquadFifoDepth: 10; // 15
		uint32 ltileOpFifoDepth: 7; // 25
	};
	uint32 val;
};

// DB_FREE_CACHELINES
union DbFreeCachelines {
	struct {
		uint32 freeDtileDepth: 7; // 0
		uint32 freePlaneDepth: 7; // 7
		uint32 freeZDepth: 7; // 14
		uint32 freeHtileDepth: 4; // 21
		uint32 quadReadReqs: 7; // 25
	};
	uint32 val;
};

// DB_HTILE_DATA_BASE
union DbHtileDataBase {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// DB_HTILE_SURFACE
union DbHtileSurface {
	struct {
		uint32 linear: 1; // 0
		uint32 fullCache: 1; // 1
		uint32 htileUsesPreloadWin: 1; // 2
		uint32 preload: 1; // 3
		uint32 prefetchWidth: 6; // 4
		uint32 prefetchHeight: 6; // 10
		uint32 dstOutsideZeroToOne: 1; // 16
		uint32 unknown1: 15;
	};
	uint32 val;
};

// DB_PERFCOUNTER0_HI
union DbPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// DB_PERFCOUNTER0_LO
union DbPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// DB_PERFCOUNTER0_SELECT
union DbPerfcounter0Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// DB_PERFCOUNTER0_SELECT1
union DbPerfcounter0Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 4;
		uint32 perfMode3: 4; // 24
		uint32 perfMode2: 4; // 28
	};
	uint32 val;
};

// DB_PERFCOUNTER1_HI
union DbPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// DB_PERFCOUNTER1_LO
union DbPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// DB_PERFCOUNTER1_SELECT
union DbPerfcounter1Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// DB_PERFCOUNTER1_SELECT1
union DbPerfcounter1Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 4;
		uint32 perfMode3: 4; // 24
		uint32 perfMode2: 4; // 28
	};
	uint32 val;
};

// DB_PERFCOUNTER2_HI
union DbPerfcounter2Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// DB_PERFCOUNTER2_LO
union DbPerfcounter2Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// DB_PERFCOUNTER2_SELECT
union DbPerfcounter2Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// DB_PERFCOUNTER3_HI
union DbPerfcounter3Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// DB_PERFCOUNTER3_LO
union DbPerfcounter3Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// DB_PERFCOUNTER3_SELECT
union DbPerfcounter3Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// DB_PRELOAD_CONTROL
union DbPreloadControl {
	struct {
		uint32 startX: 8; // 0
		uint32 startY: 8; // 8
		uint32 maxX: 8; // 16
		uint32 maxY: 8; // 24
	};
	uint32 val;
};

// DB_READ_DEBUG_0
union DbReadDebug0 {
	struct {
		uint32 busyData0: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_1
union DbReadDebug1 {
	struct {
		uint32 busyData1: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_2
union DbReadDebug2 {
	struct {
		uint32 busyData2: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_3
union DbReadDebug3 {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_4
union DbReadDebug4 {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_5
union DbReadDebug5 {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_6
union DbReadDebug6 {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_7
union DbReadDebug7 {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_8
union DbReadDebug8 {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_9
union DbReadDebug9 {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_A
union DbReadDebugA {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_B
union DbReadDebugB {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_C
union DbReadDebugC {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_D
union DbReadDebugD {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_E
union DbReadDebugE {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DB_READ_DEBUG_F
union DbReadDebugF {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DB_RENDER_CONTROL
union DbRenderControl {
	struct {
		uint32 depthClearEnable: 1; // 0
		uint32 stencilClearEnable: 1; // 1
		uint32 depthCopy: 1; // 2
		uint32 stencilCopy: 1; // 3
		uint32 resummarizeEnable: 1; // 4
		uint32 stencilCompressDisable: 1; // 5
		uint32 depthCompressDisable: 1; // 6
		uint32 copyCentroid: 1; // 7
		uint32 copySample: 4; // 8
		uint32 unknown1: 20;
	};
	uint32 val;
};

// DB_RENDER_OVERRIDE
union DbRenderOverride {
	struct {
		uint32 forceHizEnable: 2; // 0
		uint32 forceHisEnable0: 2; // 2
		uint32 forceHisEnable1: 2; // 4
		uint32 forceShaderZOrder: 1; // 6
		uint32 fastZDisable: 1; // 7
		uint32 fastStencilDisable: 1; // 8
		uint32 noopCullDisable: 1; // 9
		uint32 forceColorKill: 1; // 10
		uint32 forceZRead: 1; // 11
		uint32 forceStencilRead: 1; // 12
		uint32 forceFullZRange: 2; // 13
		uint32 forceQcSmaskConflict: 1; // 15
		uint32 disableViewportClamp: 1; // 16
		uint32 ignoreScZrange: 1; // 17
		uint32 disableFullyCovered: 1; // 18
		uint32 forceZLimitSumm: 2; // 19
		uint32 maxTilesInDtt: 5; // 21
		uint32 disableTileRateTiles: 1; // 26
		uint32 forceZDirty: 1; // 27
		uint32 forceStencilDirty: 1; // 28
		uint32 forceZValid: 1; // 29
		uint32 forceStencilValid: 1; // 30
		uint32 preserveCompression: 1; // 31
	};
	uint32 val;
};

// DB_RENDER_OVERRIDE2
union DbRenderOverride2 {
	struct {
		uint32 partialSquadLaunchControl: 2; // 0
		uint32 partialSquadLaunchCountdown: 3; // 2
		uint32 disableZmaskExpclearOptimization: 1; // 5
		uint32 disableSmemExpclearOptimization: 1; // 6
		uint32 disableColorOnValidation: 1; // 7
		uint32 decompressZOnFlush: 1; // 8
		uint32 disableRegSnoop: 1; // 9
		uint32 depthBoundsHierDepthDisable: 1; // 10
		uint32 separateHizsFuncEnable: 1; // 11
		uint32 hizZfunc: 3; // 12
		uint32 hisSfuncFf: 3; // 15
		uint32 hisSfuncBf: 3; // 18
		uint32 preserveZrange: 1; // 21
		uint32 preserveSresults: 1; // 22
		uint32 disableFastPass: 1; // 23
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DB_SHADER_CONTROL
union DbShaderControl {
	struct {
		uint32 zExportEnable: 1; // 0
		uint32 stencilTestValExportEnable: 1; // 1
		uint32 stencilOpValExportEnable: 1; // 2
		uint32 unknown1: 1;
		uint32 zOrder: 2; // 4
		uint32 killEnable: 1; // 6
		uint32 coverageToMaskEnable: 1; // 7
		uint32 maskExportEnable: 1; // 8
		uint32 execOnHierFail: 1; // 9
		uint32 execOnNoop: 1; // 10
		uint32 alphaToMaskDisable: 1; // 11
		uint32 depthBeforeShader: 1; // 12
		uint32 conservativeZExport: 2; // 13
		uint32 unknown2: 17;
	};
	uint32 val;
};

// DB_SRESULTS_COMPARE_STATE0
union DbSresultsCompareState0 {
	struct {
		uint32 comparefunc0: 3; // 0
		uint32 unknown1: 1;
		uint32 comparevalue0: 8; // 4
		uint32 comparemask0: 8; // 12
		uint32 unknown2: 4;
		uint32 enable0: 1; // 24
		uint32 unknown3: 7;
	};
	uint32 val;
};

// DB_SRESULTS_COMPARE_STATE1
union DbSresultsCompareState1 {
	struct {
		uint32 comparefunc1: 3; // 0
		uint32 unknown1: 1;
		uint32 comparevalue1: 8; // 4
		uint32 comparemask1: 8; // 12
		uint32 unknown2: 4;
		uint32 enable1: 1; // 24
		uint32 unknown3: 7;
	};
	uint32 val;
};

// DB_STENCILREFMASK
union DbStencilrefmask {
	struct {
		uint32 stenciltestval: 8; // 0
		uint32 stencilmask: 8; // 8
		uint32 stencilwritemask: 8; // 16
		uint32 stencilopval: 8; // 24
	};
	uint32 val;
};

// DB_STENCILREFMASK_BF
union DbStencilrefmaskBf {
	struct {
		uint32 stenciltestvalBf: 8; // 0
		uint32 stencilmaskBf: 8; // 8
		uint32 stencilwritemaskBf: 8; // 16
		uint32 stencilopvalBf: 8; // 24
	};
	uint32 val;
};

// DB_STENCIL_CLEAR
union DbStencilClear {
	struct {
		uint32 clear: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// DB_STENCIL_CONTROL
union DbStencilControl {
	struct {
		uint32 stencilfail: 4; // 0
		uint32 stencilzpass: 4; // 4
		uint32 stencilzfail: 4; // 8
		uint32 stencilfailBf: 4; // 12
		uint32 stencilzpassBf: 4; // 16
		uint32 stencilzfailBf: 4; // 20
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DB_STENCIL_INFO
union DbStencilInfo {
	struct {
		uint32 format: 1; // 0
		uint32 unknown1: 12;
		uint32 tileSplit: 3; // 13
		uint32 unknown2: 4;
		uint32 tileModeIndex: 3; // 20
		uint32 unknown3: 4;
		uint32 allowExpclear: 1; // 27
		uint32 unknown4: 1;
		uint32 tileStencilDisable: 1; // 29
		uint32 unknown5: 2;
	};
	uint32 val;
};

// DB_STENCIL_READ_BASE
union DbStencilReadBase {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// DB_STENCIL_WRITE_BASE
union DbStencilWriteBase {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// DB_SUBTILE_CONTROL
union DbSubtileControl {
	struct {
		uint32 msaa1X: 2; // 0
		uint32 msaa1Y: 2; // 2
		uint32 msaa2X: 2; // 4
		uint32 msaa2Y: 2; // 6
		uint32 msaa4X: 2; // 8
		uint32 msaa4Y: 2; // 10
		uint32 msaa8X: 2; // 12
		uint32 msaa8Y: 2; // 14
		uint32 msaa16X: 2; // 16
		uint32 msaa16Y: 2; // 18
		uint32 unknown1: 12;
	};
	uint32 val;
};

// DB_WATERMARKS
union DbWatermarks {
	struct {
		uint32 depthFree: 5; // 0
		uint32 depthFlush: 6; // 5
		uint32 forceSummarize: 4; // 11
		uint32 depthPendingFree: 5; // 15
		uint32 depthCachelineFree: 7; // 20
		uint32 earlyZPanicDisable: 1; // 27
		uint32 lateZPanicDisable: 1; // 28
		uint32 reZPanicDisable: 1; // 29
		uint32 autoFlushHtile: 1; // 30
		uint32 autoFlushQuad: 1; // 31
	};
	uint32 val;
};

// DB_ZPASS_COUNT_HI
union DbZpassCountHi {
	struct {
		uint32 countHi: 31; // 0
		uint32 unknown1: 1;
	};
	uint32 val;
};

// DB_ZPASS_COUNT_LOW
union DbZpassCountLow {
	struct {
		uint32 countLow: 32; // 0
	};
	uint32 val;
};

// DB_Z_INFO
union DbZInfo {
	struct {
		uint32 format: 2; // 0
		uint32 numSamples: 2; // 2
		uint32 unknown1: 9;
		uint32 tileSplit: 3; // 13
		uint32 unknown2: 4;
		uint32 tileModeIndex: 3; // 20
		uint32 unknown3: 4;
		uint32 allowExpclear: 1; // 27
		uint32 readSize: 1; // 28
		uint32 tileSurfaceEnable: 1; // 29
		uint32 unknown4: 1;
		uint32 zrangePrecision: 1; // 31
	};
	uint32 val;
};

// DB_Z_READ_BASE
union DbZReadBase {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// DB_Z_WRITE_BASE
union DbZWriteBase {
	struct {
		uint32 base256b: 32; // 0
	};
	uint32 val;
};

// DEBUG_DATA
union DebugData {
	struct {
		uint32 debugData: 32; // 0
	};
	uint32 val;
};

// DEBUG_INDEX
union DebugIndex {
	struct {
		uint32 debugIndex: 18; // 0
		uint32 unknown1: 14;
	};
	uint32 val;
};

// GB_ADDR_CONFIG
union GbAddrConfig {
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

// GB_BACKEND_MAP
union GbBackendMap {
	struct {
		uint32 backendMap: 32; // 0
	};
	uint32 val;
};

// GB_EDC_MODE
union GbEdcMode {
	struct {
		uint32 unknown1: 16;
		uint32 forceSecOnDed: 1; // 16
		uint32 unknown2: 3;
		uint32 dedMode: 2; // 20
		uint32 unknown3: 7;
		uint32 propFed: 1; // 29
		uint32 unknown4: 1;
		uint32 bypass: 1; // 31
	};
	uint32 val;
};

// GB_GPU_ID
union GbGpuId {
	struct {
		uint32 gpuId: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// GB_TILE_MODE0
union GbTileMode0 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE1
union GbTileMode1 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE10
union GbTileMode10 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE11
union GbTileMode11 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE12
union GbTileMode12 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE13
union GbTileMode13 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE14
union GbTileMode14 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE15
union GbTileMode15 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE16
union GbTileMode16 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE17
union GbTileMode17 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE18
union GbTileMode18 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE19
union GbTileMode19 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE2
union GbTileMode2 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE20
union GbTileMode20 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE21
union GbTileMode21 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE22
union GbTileMode22 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE23
union GbTileMode23 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE24
union GbTileMode24 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE25
union GbTileMode25 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE26
union GbTileMode26 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE27
union GbTileMode27 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE28
union GbTileMode28 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE29
union GbTileMode29 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE3
union GbTileMode3 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE30
union GbTileMode30 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE31
union GbTileMode31 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE4
union GbTileMode4 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE5
union GbTileMode5 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE6
union GbTileMode6 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE7
union GbTileMode7 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE8
union GbTileMode8 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GB_TILE_MODE9
union GbTileMode9 {
	struct {
		uint32 unknown1: 2;
		uint32 arrayMode: 4; // 2
		uint32 pipeConfig: 5; // 6
		uint32 tileSplit: 3; // 11
		uint32 unknown2: 8;
		uint32 microTileModeNew: 3; // 22
		uint32 sampleSplit: 2; // 25
		uint32 unknown3: 5;
	};
	uint32 val;
};

// GC_USER_RB_BACKEND_DISABLE
union GcUserRbBackendDisable {
	struct {
		uint32 unknown1: 16;
		uint32 backendDisable: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// GC_USER_SHADER_ARRAY_CONFIG
union GcUserShaderArrayConfig {
	struct {
		uint32 unknown1: 1;
		uint32 dpfpRate: 2; // 1
		uint32 sqcBalanceDisable: 1; // 3
		uint32 halfLds: 1; // 4
		uint32 unknown2: 11;
		uint32 inactiveCus: 16; // 16
	};
	uint32 val;
};

// GDS_ATOM_BASE
union GdsAtomBase {
	struct {
		uint32 base: 16; // 0
		uint32 unused: 16; // 16
	};
	uint32 val;
};

// GDS_ATOM_CNTL
union GdsAtomCntl {
	struct {
		uint32 ainc: 6; // 0
		uint32 unused1: 2; // 6
		uint32 dmode: 1; // 8
		uint32 unused2: 23; // 9
	};
	uint32 val;
};

// GDS_ATOM_COMPLETE
union GdsAtomComplete {
	struct {
		uint32 complete: 1; // 0
		uint32 unused: 31; // 1
	};
	uint32 val;
};

// GDS_ATOM_DST
union GdsAtomDst {
	struct {
		uint32 dst: 32; // 0
	};
	uint32 val;
};

// GDS_ATOM_OFFSET0
union GdsAtomOffset0 {
	struct {
		uint32 offset0: 8; // 0
		uint32 unused: 24; // 8
	};
	uint32 val;
};

// GDS_ATOM_OFFSET1
union GdsAtomOffset1 {
	struct {
		uint32 offset1: 8; // 0
		uint32 unused: 24; // 8
	};
	uint32 val;
};

// GDS_ATOM_OP
union GdsAtomOp {
	struct {
		uint32 op: 8; // 0
		uint32 unused: 24; // 8
	};
	uint32 val;
};

// GDS_ATOM_READ0
union GdsAtomRead0 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// GDS_ATOM_READ0_U
union GdsAtomRead0U {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// GDS_ATOM_READ1
union GdsAtomRead1 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// GDS_ATOM_READ1_U
union GdsAtomRead1U {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// GDS_ATOM_SIZE
union GdsAtomSize {
	struct {
		uint32 size: 16; // 0
		uint32 unused: 16; // 16
	};
	uint32 val;
};

// GDS_ATOM_SRC0
union GdsAtomSrc0 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// GDS_ATOM_SRC0_U
union GdsAtomSrc0U {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// GDS_ATOM_SRC1
union GdsAtomSrc1 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// GDS_ATOM_SRC1_U
union GdsAtomSrc1U {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// GDS_CNTL_STATUS
union GdsCntlStatus {
	struct {
		uint32 gdsBusy: 1; // 0
		uint32 grbmWbufBusy: 1; // 1
		uint32 ordAppBusy: 1; // 2
		uint32 dsBankConflict: 1; // 3
		uint32 dsAddrConflict: 1; // 4
		uint32 dsWrClamp: 1; // 5
		uint32 dsRdClamp: 1; // 6
		uint32 unknown1: 25;
	};
	uint32 val;
};

// GDS_CONFIG
union GdsConfig {
	struct {
		uint32 unknown1: 1;
		uint32 sh0GprPhaseSel: 2; // 1
		uint32 sh1GprPhaseSel: 2; // 3
		uint32 sh2GprPhaseSel: 2; // 5
		uint32 sh3GprPhaseSel: 2; // 7
		uint32 unknown2: 23;
	};
	uint32 val;
};

// GDS_DEBUG_CNTL
union GdsDebugCntl {
	struct {
		uint32 gdsDebugIndx: 5; // 0
		uint32 unused: 27; // 5
	};
	uint32 val;
};

// GDS_DEBUG_DATA
union GdsDebugData {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// GDS_DEBUG_REG0
union GdsDebugReg0 {
	struct {
		uint32 spare1: 1; // 0
		uint32 unknown1: 5;
		uint32 writeBuffValid: 1; // 6
		uint32 wrPixelNxtPtr: 5; // 7
		uint32 lastPixelPtr: 1; // 12
		uint32 cstate: 4; // 13
		uint32 buffWrite: 1; // 17
		uint32 flushRequest: 1; // 18
		uint32 wrBufferWrComplete: 1; // 19
		uint32 wbufFifoEmpty: 1; // 20
		uint32 wbufFifoFull: 1; // 21
		uint32 unknown2: 2;
		uint32 spare: 8; // 24
	};
	uint32 val;
};

// GDS_DEBUG_REG1
union GdsDebugReg1 {
	struct {
		uint32 tagHit: 1; // 0
		uint32 tagMiss: 1; // 1
		uint32 pixelAddr: 15; // 2
		uint32 pixelVld: 1; // 17
		uint32 dataReady: 1; // 18
		uint32 awaitingData: 1; // 19
		uint32 addrFifoFull: 1; // 20
		uint32 addrFifoEmpty: 1; // 21
		uint32 bufferLoaded: 1; // 22
		uint32 bufferInvalid: 1; // 23
		uint32 spare: 8; // 24
	};
	uint32 val;
};

// GDS_DEBUG_REG2
union GdsDebugReg2 {
	struct {
		uint32 dsFull: 1; // 0
		uint32 dsCreditAvail: 1; // 1
		uint32 ordIdxFree: 1; // 2
		uint32 cmdWrite: 1; // 3
		uint32 appSel: 4; // 4
		uint32 req: 15; // 8
		uint32 unknown1: 1;
		uint32 spare: 8; // 24
	};
	uint32 val;
};

// GDS_DEBUG_REG3
union GdsDebugReg3 {
	struct {
		uint32 pipeNumBusy: 11; // 0
		uint32 pipe0BusyNum: 4; // 11
		uint32 unknown1: 9;
		uint32 spare: 8; // 24
	};
	uint32 val;
};

// GDS_DEBUG_REG4
union GdsDebugReg4 {
	struct {
		uint32 gwsBusy: 1; // 0
		uint32 gwsReq: 1; // 1
		uint32 gwsOutStall: 1; // 2
		uint32 curReso: 6; // 3
		uint32 curResoHeadValid: 1; // 9
		uint32 curResoHeadDirty: 1; // 10
		uint32 curResoHeadFlag: 1; // 11
		uint32 curResoFed: 1; // 12
		uint32 curResoBarrier: 1; // 13
		uint32 curResoFlag: 1; // 14
		uint32 curResoCntGt0: 1; // 15
		uint32 creditCntGt0: 1; // 16
		uint32 cmdWrite: 1; // 17
		uint32 grbmGwsResoWr: 1; // 18
		uint32 grbmGwsResoRd: 1; // 19
		uint32 ramReadBusy: 1; // 20
		uint32 gwsBulkfree: 1; // 21
		uint32 ramGwsRe: 1; // 22
		uint32 ramGwsWe: 1; // 23
		uint32 spare: 8; // 24
	};
	uint32 val;
};

// GDS_DEBUG_REG5
union GdsDebugReg5 {
	struct {
		uint32 writeDis: 1; // 0
		uint32 decError: 1; // 1
		uint32 allocOpcoError: 1; // 2
		uint32 deallocOpcoError: 1; // 3
		uint32 wrapOpcoError: 1; // 4
		uint32 unknown1: 3;
		uint32 errorDsAddress: 14; // 8
		uint32 spare1: 10; // 22
		// uint32 unknown2: -8;
		// uint32 spare: 8;
	};
	uint32 val;
};

// GDS_DEBUG_REG6
union GdsDebugReg6 {
	struct {
		uint32 oaBusy: 1; // 0
		uint32 countersEnabled: 4; // 1
		uint32 countersBusy: 16; // 5
		uint32 unknown1: 3;
		uint32 spare: 8; // 24
	};
	uint32 val;
};

// GDS_ENHANCE
union GdsEnhance {
	struct {
		uint32 misc: 16; // 0
		uint32 autoIncIndex: 1; // 16
		uint32 unknown1: 15;
	};
	uint32 val;
};

// GDS_GRBM_SECDED_CNT
union GdsGrbmSecdedCnt {
	struct {
		uint32 sec: 16; // 0
		uint32 ded: 16; // 16
	};
	uint32 val;
};

// GDS_GWS_RESOURCE
union GdsGwsResource {
	struct {
		uint32 flag: 1; // 0
		uint32 counter: 12; // 1
		uint32 type: 1; // 13
		uint32 ded: 1; // 14
		uint32 releaseAll: 1; // 15
		uint32 headQueue: 11; // 16
		uint32 headValid: 1; // 27
		uint32 headFlag: 1; // 28
		uint32 unused1: 3; // 29
	};
	uint32 val;
};

// GDS_GWS_RESOURCE_CNT
union GdsGwsResourceCnt {
	struct {
		uint32 resourceCnt: 16; // 0
		uint32 unused: 16; // 16
	};
	uint32 val;
};

// GDS_GWS_RESOURCE_CNTL
union GdsGwsResourceCntl {
	struct {
		uint32 index: 6; // 0
		uint32 unused: 26; // 6
	};
	uint32 val;
};

// GDS_GWS_RESOURCE_RESET
union GdsGwsResourceReset {
	struct {
		uint32 reset: 1; // 0
		uint32 unknown1: 7;
		uint32 resourceId: 8; // 8
		uint32 unknown2: 16;
	};
	uint32 val;
};

// GDS_OA_DED
union GdsOaDed {
	struct {
		uint32 me0Gfxhp3dPixDed: 1; // 0
		uint32 me0Gfxhp3dVtxDed: 1; // 1
		uint32 me0CsDed: 1; // 2
		uint32 unused0: 1; // 3
		uint32 me1Pipe0Ded: 1; // 4
		uint32 me1Pipe1Ded: 1; // 5
		uint32 me1Pipe2Ded: 1; // 6
		uint32 me1Pipe3Ded: 1; // 7
		uint32 me2Pipe0Ded: 1; // 8
		uint32 me2Pipe1Ded: 1; // 9
		uint32 me2Pipe2Ded: 1; // 10
		uint32 me2Pipe3Ded: 1; // 11
		uint32 unused1: 20; // 12
	};
	uint32 val;
};

// GDS_PERFCOUNTER0_HI
union GdsPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// GDS_PERFCOUNTER0_LO
union GdsPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// GDS_PERFCOUNTER0_SELECT
union GdsPerfcounter0Select {
	struct {
		uint32 perfcounterSelect: 8; // 0
		uint32 unknown1: 2;
		uint32 perfcounterSelect1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// GDS_PERFCOUNTER0_SELECT1
union GdsPerfcounter0Select1 {
	struct {
		uint32 perfcounterSelect2: 10; // 0
		uint32 perfcounterSelect3: 10; // 10
		uint32 unknown1: 12;
	};
	uint32 val;
};

// GDS_PERFCOUNTER1_HI
union GdsPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// GDS_PERFCOUNTER1_LO
union GdsPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// GDS_PERFCOUNTER1_SELECT
union GdsPerfcounter1Select {
	struct {
		uint32 perfcounterSelect: 8; // 0
		uint32 unknown1: 2;
		uint32 perfcounterSelect1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// GDS_PERFCOUNTER2_HI
union GdsPerfcounter2Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// GDS_PERFCOUNTER2_LO
union GdsPerfcounter2Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// GDS_PERFCOUNTER2_SELECT
union GdsPerfcounter2Select {
	struct {
		uint32 perfcounterSelect: 8; // 0
		uint32 unknown1: 2;
		uint32 perfcounterSelect1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// GDS_PERFCOUNTER3_HI
union GdsPerfcounter3Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// GDS_PERFCOUNTER3_LO
union GdsPerfcounter3Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// GDS_PERFCOUNTER3_SELECT
union GdsPerfcounter3Select {
	struct {
		uint32 perfcounterSelect: 8; // 0
		uint32 unknown1: 2;
		uint32 perfcounterSelect1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// GDS_RD_ADDR
union GdsRdAddr {
	struct {
		uint32 readAddr: 32; // 0
	};
	uint32 val;
};

// GDS_RD_BURST_ADDR
union GdsRdBurstAddr {
	struct {
		uint32 burstAddr: 32; // 0
	};
	uint32 val;
};

// GDS_RD_BURST_COUNT
union GdsRdBurstCount {
	struct {
		uint32 burstCount: 32; // 0
	};
	uint32 val;
};

// GDS_RD_BURST_DATA
union GdsRdBurstData {
	struct {
		uint32 burstData: 32; // 0
	};
	uint32 val;
};

// GDS_RD_DATA
union GdsRdData {
	struct {
		uint32 readData: 32; // 0
	};
	uint32 val;
};

// GDS_SECDED_CNT
union GdsSecdedCnt {
	struct {
		uint32 sec: 16; // 0
		uint32 ded: 16; // 16
	};
	uint32 val;
};

// GDS_WRITE_COMPLETE
union GdsWriteComplete {
	struct {
		uint32 writeComplete: 32; // 0
	};
	uint32 val;
};

// GDS_WR_ADDR
union GdsWrAddr {
	struct {
		uint32 writeAddr: 32; // 0
	};
	uint32 val;
};

// GDS_WR_BURST_ADDR
union GdsWrBurstAddr {
	struct {
		uint32 writeAddr: 32; // 0
	};
	uint32 val;
};

// GDS_WR_BURST_DATA
union GdsWrBurstData {
	struct {
		uint32 writeData: 32; // 0
	};
	uint32 val;
};

// GDS_WR_DATA
union GdsWrData {
	struct {
		uint32 writeData: 32; // 0
	};
	uint32 val;
};

// GFX_COPY_STATE
union GfxCopyState {
	struct {
		uint32 srcStateId: 3; // 0
		uint32 unknown1: 29;
	};
	uint32 val;
};

// GRBM_CAM_DATA
union GrbmCamData {
	struct {
		uint32 camAddr: 16; // 0
		uint32 camRemapaddr: 16; // 16
	};
	uint32 val;
};

// GRBM_CAM_INDEX
union GrbmCamIndex {
	struct {
		uint32 camIndex: 3; // 0
		uint32 unknown1: 29;
	};
	uint32 val;
};

// GRBM_CNTL
union GrbmCntl {
	struct {
		uint32 readTimeout: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// GRBM_DEBUG
union GrbmDebug {
	struct {
		uint32 unknown1: 1;
		uint32 ignoreRdy: 1; // 1
		uint32 unknown2: 3;
		uint32 ignoreFao: 1; // 5
		uint32 disableReadTimeout: 1; // 6
		uint32 snapshotFreeCntrs: 1; // 7
		uint32 hysteresisGuiActive: 4; // 8
		uint32 gfxClockDomainOverride: 1; // 12
		uint32 unknown3: 19;
	};
	uint32 val;
};

// GRBM_DEBUG_CNTL
union GrbmDebugCntl {
	struct {
		uint32 grbmDebugIndex: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// GRBM_DEBUG_DATA
union GrbmDebugData {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// GRBM_DEBUG_SNAPSHOT
union GrbmDebugSnapshot {
	struct {
		uint32 cpfRdy: 1; // 0
		uint32 cpgRdy: 1; // 1
		uint32 unknown1: 1;
		uint32 wdMe0pipe0Rdy: 1; // 3
		uint32 wdMe0pipe1Rdy: 1; // 4
		uint32 unknown2: 1;
		uint32 se0spiMe0pipe0Rdy0: 1; // 6
		uint32 se0spiMe0pipe1Rdy0: 1; // 7
		uint32 se1spiMe0pipe0Rdy0: 1; // 8
		uint32 gdsRdy: 1; // 9
		uint32 se2spiMe0pipe0Rdy0: 1; // 10
		uint32 se2spiMe0pipe1Rdy0: 1; // 11
		uint32 se3spiMe0pipe0Rdy0: 1; // 12
		uint32 se3spiMe0pipe1Rdy0: 1; // 13
		uint32 se0spiMe0pipe0Rdy1: 1; // 14
		uint32 se0spiMe0pipe1Rdy1: 1; // 15
		uint32 se1spiMe0pipe0Rdy1: 1; // 16
		uint32 se1spiMe0pipe1Rdy1: 1; // 17
		uint32 se2spiMe0pipe0Rdy1: 1; // 18
		uint32 se2spiMe0pipe1Rdy1: 1; // 19
		uint32 se3spiMe0pipe0Rdy1: 1; // 20
		uint32 se3spiMe0pipe1Rdy1: 1; // 21
		uint32 unknown3: 10;
	};
	uint32 val;
};

// GRBM_GFX_CLKEN_CNTL
union GrbmGfxClkenCntl {
	struct {
		uint32 prefixDelayCnt: 4; // 0
		uint32 unknown1: 4;
		uint32 postDelayCnt: 5; // 8
		uint32 unknown2: 19;
	};
	uint32 val;
};

// GRBM_GFX_INDEX
union GrbmGfxIndex {
	struct {
		uint32 instanceIndex: 8; // 0
		uint32 shIndex: 8; // 8
		uint32 seIndex: 8; // 16
		uint32 unknown1: 5;
		uint32 shBroadcastWrites: 1; // 29
		uint32 instanceBroadcastWrites: 1; // 30
		uint32 seBroadcastWrites: 1; // 31
	};
	uint32 val;
};

// GRBM_INT_CNTL
union GrbmIntCntl {
	struct {
		uint32 rderrIntEnable: 1; // 0
		uint32 unknown1: 18;
		uint32 guiIdleIntEnable: 1; // 19
		uint32 unknown2: 12;
	};
	uint32 val;
};

// GRBM_NOWHERE
union GrbmNowhere {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// GRBM_PERFCOUNTER0_HI
union GrbmPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// GRBM_PERFCOUNTER0_LO
union GrbmPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// GRBM_PERFCOUNTER0_SELECT
union GrbmPerfcounter0Select {
	struct {
		uint32 perfSel: 6; // 0
		uint32 unknown1: 4;
		uint32 dbCleanUserDefinedMask: 1; // 10
		uint32 cbCleanUserDefinedMask: 1; // 11
		uint32 vgtBusyUserDefinedMask: 1; // 12
		uint32 taBusyUserDefinedMask: 1; // 13
		uint32 sxBusyUserDefinedMask: 1; // 14
		uint32 unknown2: 1;
		uint32 spiBusyUserDefinedMask: 1; // 16
		uint32 scBusyUserDefinedMask: 1; // 17
		uint32 paBusyUserDefinedMask: 1; // 18
		uint32 grbmBusyUserDefinedMask: 1; // 19
		uint32 dbBusyUserDefinedMask: 1; // 20
		uint32 cbBusyUserDefinedMask: 1; // 21
		uint32 cpBusyUserDefinedMask: 1; // 22
		uint32 iaBusyUserDefinedMask: 1; // 23
		uint32 gdsBusyUserDefinedMask: 1; // 24
		uint32 bciBusyUserDefinedMask: 1; // 25
		uint32 rlcBusyUserDefinedMask: 1; // 26
		uint32 tcBusyUserDefinedMask: 1; // 27
		uint32 wdBusyUserDefinedMask: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// GRBM_PERFCOUNTER1_HI
union GrbmPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// GRBM_PERFCOUNTER1_LO
union GrbmPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// GRBM_PERFCOUNTER1_SELECT
union GrbmPerfcounter1Select {
	struct {
		uint32 perfSel: 6; // 0
		uint32 unknown1: 4;
		uint32 dbCleanUserDefinedMask: 1; // 10
		uint32 cbCleanUserDefinedMask: 1; // 11
		uint32 vgtBusyUserDefinedMask: 1; // 12
		uint32 taBusyUserDefinedMask: 1; // 13
		uint32 sxBusyUserDefinedMask: 1; // 14
		uint32 unknown2: 1;
		uint32 spiBusyUserDefinedMask: 1; // 16
		uint32 scBusyUserDefinedMask: 1; // 17
		uint32 paBusyUserDefinedMask: 1; // 18
		uint32 grbmBusyUserDefinedMask: 1; // 19
		uint32 dbBusyUserDefinedMask: 1; // 20
		uint32 cbBusyUserDefinedMask: 1; // 21
		uint32 cpBusyUserDefinedMask: 1; // 22
		uint32 iaBusyUserDefinedMask: 1; // 23
		uint32 gdsBusyUserDefinedMask: 1; // 24
		uint32 bciBusyUserDefinedMask: 1; // 25
		uint32 rlcBusyUserDefinedMask: 1; // 26
		uint32 tcBusyUserDefinedMask: 1; // 27
		uint32 wdBusyUserDefinedMask: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// GRBM_PWR_CNTL
union GrbmPwrCntl {
	struct {
		uint32 reqType: 4; // 0
		uint32 rspType: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// GRBM_READ_ERROR
union GrbmReadError {
	struct {
		uint32 unknown1: 2;
		uint32 readAddress: 16; // 2
		uint32 unknown2: 2;
		uint32 readPipeid: 2; // 20
		uint32 readMeid: 2; // 22
		uint32 unknown3: 7;
		uint32 readError: 1; // 31
	};
	uint32 val;
};

// GRBM_READ_ERROR2
union GrbmReadError2 {
	struct {
		uint32 unknown1: 17;
		uint32 readRequesterSrbm: 1; // 17
		uint32 readRequesterRlc: 1; // 18
		uint32 readRequesterGdsDma: 1; // 19
		uint32 readRequesterMe0pipe0Cf: 1; // 20
		uint32 readRequesterMe0pipe0Pf: 1; // 21
		uint32 readRequesterMe0pipe1Cf: 1; // 22
		uint32 readRequesterMe0pipe1Pf: 1; // 23
		uint32 readRequesterMe1pipe0: 1; // 24
		uint32 readRequesterMe1pipe1: 1; // 25
		uint32 readRequesterMe1pipe2: 1; // 26
		uint32 readRequesterMe1pipe3: 1; // 27
		uint32 readRequesterMe2pipe0: 1; // 28
		uint32 readRequesterMe2pipe1: 1; // 29
		uint32 readRequesterMe2pipe2: 1; // 30
		uint32 readRequesterMe2pipe3: 1; // 31
	};
	uint32 val;
};

// GRBM_SCRATCH_REG0
union GrbmScratchReg0 {
	struct {
		uint32 scratchReg0: 32; // 0
	};
	uint32 val;
};

// GRBM_SCRATCH_REG1
union GrbmScratchReg1 {
	struct {
		uint32 scratchReg1: 32; // 0
	};
	uint32 val;
};

// GRBM_SCRATCH_REG2
union GrbmScratchReg2 {
	struct {
		uint32 scratchReg2: 32; // 0
	};
	uint32 val;
};

// GRBM_SCRATCH_REG3
union GrbmScratchReg3 {
	struct {
		uint32 scratchReg3: 32; // 0
	};
	uint32 val;
};

// GRBM_SCRATCH_REG4
union GrbmScratchReg4 {
	struct {
		uint32 scratchReg4: 32; // 0
	};
	uint32 val;
};

// GRBM_SCRATCH_REG5
union GrbmScratchReg5 {
	struct {
		uint32 scratchReg5: 32; // 0
	};
	uint32 val;
};

// GRBM_SCRATCH_REG6
union GrbmScratchReg6 {
	struct {
		uint32 scratchReg6: 32; // 0
	};
	uint32 val;
};

// GRBM_SCRATCH_REG7
union GrbmScratchReg7 {
	struct {
		uint32 scratchReg7: 32; // 0
	};
	uint32 val;
};

// GRBM_SE0_PERFCOUNTER_HI
union GrbmSe0PerfcounterHi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// GRBM_SE0_PERFCOUNTER_LO
union GrbmSe0PerfcounterLo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// GRBM_SE0_PERFCOUNTER_SELECT
union GrbmSe0PerfcounterSelect {
	struct {
		uint32 perfSel: 6; // 0
		uint32 unknown1: 4;
		uint32 dbCleanUserDefinedMask: 1; // 10
		uint32 cbCleanUserDefinedMask: 1; // 11
		uint32 taBusyUserDefinedMask: 1; // 12
		uint32 sxBusyUserDefinedMask: 1; // 13
		uint32 unknown2: 1;
		uint32 spiBusyUserDefinedMask: 1; // 15
		uint32 scBusyUserDefinedMask: 1; // 16
		uint32 dbBusyUserDefinedMask: 1; // 17
		uint32 cbBusyUserDefinedMask: 1; // 18
		uint32 vgtBusyUserDefinedMask: 1; // 19
		uint32 paBusyUserDefinedMask: 1; // 20
		uint32 bciBusyUserDefinedMask: 1; // 21
		uint32 unknown3: 10;
	};
	uint32 val;
};

// GRBM_SE1_PERFCOUNTER_HI
union GrbmSe1PerfcounterHi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// GRBM_SE1_PERFCOUNTER_LO
union GrbmSe1PerfcounterLo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// GRBM_SE1_PERFCOUNTER_SELECT
union GrbmSe1PerfcounterSelect {
	struct {
		uint32 perfSel: 6; // 0
		uint32 unknown1: 4;
		uint32 dbCleanUserDefinedMask: 1; // 10
		uint32 cbCleanUserDefinedMask: 1; // 11
		uint32 taBusyUserDefinedMask: 1; // 12
		uint32 sxBusyUserDefinedMask: 1; // 13
		uint32 unknown2: 1;
		uint32 spiBusyUserDefinedMask: 1; // 15
		uint32 scBusyUserDefinedMask: 1; // 16
		uint32 dbBusyUserDefinedMask: 1; // 17
		uint32 cbBusyUserDefinedMask: 1; // 18
		uint32 vgtBusyUserDefinedMask: 1; // 19
		uint32 paBusyUserDefinedMask: 1; // 20
		uint32 bciBusyUserDefinedMask: 1; // 21
		uint32 unknown3: 10;
	};
	uint32 val;
};

// GRBM_SKEW_CNTL
union GrbmSkewCntl {
	struct {
		uint32 skewTopThreshold: 6; // 0
		uint32 skewCount: 6; // 6
		uint32 unknown1: 20;
	};
	uint32 val;
};

// GRBM_SOFT_RESET
union GrbmSoftReset {
	struct {
		uint32 softResetCp: 1; // 0
		uint32 unknown1: 1;
		uint32 softResetRlc: 1; // 2
		uint32 unknown2: 13;
		uint32 softResetGfx: 1; // 16
		uint32 softResetCpf: 1; // 17
		uint32 softResetCpc: 1; // 18
		uint32 softResetCpg: 1; // 19
		uint32 unknown3: 12;
	};
	uint32 val;
};

// GRBM_STATUS
union GrbmStatus {
	struct {
		uint32 me0pipe0CmdfifoAvail: 4; // 0
		uint32 unknown1: 1;
		uint32 srbmRqPending: 1; // 5
		uint32 unknown2: 1;
		uint32 me0pipe0CfRqPending: 1; // 7
		uint32 me0pipe0PfRqPending: 1; // 8
		uint32 gdsDmaRqPending: 1; // 9
		uint32 unknown3: 2;
		uint32 dbClean: 1; // 12
		uint32 cbClean: 1; // 13
		uint32 taBusy: 1; // 14
		uint32 gdsBusy: 1; // 15
		uint32 wdBusyNoDma: 1; // 16
		uint32 vgtBusy: 1; // 17
		uint32 iaBusyNoDma: 1; // 18
		uint32 iaBusy: 1; // 19
		uint32 sxBusy: 1; // 20
		uint32 wdBusy: 1; // 21
		uint32 spiBusy: 1; // 22
		uint32 bciBusy: 1; // 23
		uint32 scBusy: 1; // 24
		uint32 paBusy: 1; // 25
		uint32 dbBusy: 1; // 26
		uint32 unknown4: 1;
		uint32 cpCoherencyBusy: 1; // 28
		uint32 cpBusy: 1; // 29
		uint32 cbBusy: 1; // 30
		uint32 guiActive: 1; // 31
	};
	uint32 val;
};

// GRBM_STATUS2
union GrbmStatus2 {
	struct {
		uint32 me0pipe1CmdfifoAvail: 4; // 0
		uint32 me0pipe1CfRqPending: 1; // 4
		uint32 me0pipe1PfRqPending: 1; // 5
		uint32 me1pipe0RqPending: 1; // 6
		uint32 me1pipe1RqPending: 1; // 7
		uint32 me1pipe2RqPending: 1; // 8
		uint32 me1pipe3RqPending: 1; // 9
		uint32 me2pipe0RqPending: 1; // 10
		uint32 me2pipe1RqPending: 1; // 11
		uint32 me2pipe2RqPending: 1; // 12
		uint32 me2pipe3RqPending: 1; // 13
		uint32 unknown1: 14;
		uint32 cpfBusy: 1; // 28
		uint32 cpcBusy: 1; // 29
		uint32 cpgBusy: 1; // 30
		uint32 unknown2: 1;
	};
	uint32 val;
};

// GRBM_STATUS_SE0
union GrbmStatusSe0 {
	struct {
		uint32 unknown1: 1;
		uint32 dbClean: 1; // 1
		uint32 cbClean: 1; // 2
		uint32 unknown2: 19;
		uint32 bciBusy: 1; // 22
		uint32 vgtBusy: 1; // 23
		uint32 paBusy: 1; // 24
		uint32 taBusy: 1; // 25
		uint32 sxBusy: 1; // 26
		uint32 spiBusy: 1; // 27
		uint32 unknown3: 1;
		uint32 scBusy: 1; // 29
		uint32 dbBusy: 1; // 30
		uint32 cbBusy: 1; // 31
	};
	uint32 val;
};

// GRBM_STATUS_SE1
union GrbmStatusSe1 {
	struct {
		uint32 unknown1: 1;
		uint32 dbClean: 1; // 1
		uint32 cbClean: 1; // 2
		uint32 unknown2: 19;
		uint32 bciBusy: 1; // 22
		uint32 vgtBusy: 1; // 23
		uint32 paBusy: 1; // 24
		uint32 taBusy: 1; // 25
		uint32 sxBusy: 1; // 26
		uint32 spiBusy: 1; // 27
		uint32 unknown3: 1;
		uint32 scBusy: 1; // 29
		uint32 dbBusy: 1; // 30
		uint32 cbBusy: 1; // 31
	};
	uint32 val;
};

// GRBM_STATUS_SE2
union GrbmStatusSe2 {
	struct {
		uint32 unknown1: 1;
		uint32 dbClean: 1; // 1
		uint32 cbClean: 1; // 2
		uint32 unknown2: 19;
		uint32 bciBusy: 1; // 22
		uint32 vgtBusy: 1; // 23
		uint32 paBusy: 1; // 24
		uint32 taBusy: 1; // 25
		uint32 sxBusy: 1; // 26
		uint32 spiBusy: 1; // 27
		uint32 unknown3: 1;
		uint32 scBusy: 1; // 29
		uint32 dbBusy: 1; // 30
		uint32 cbBusy: 1; // 31
	};
	uint32 val;
};

// GRBM_STATUS_SE3
union GrbmStatusSe3 {
	struct {
		uint32 unknown1: 1;
		uint32 dbClean: 1; // 1
		uint32 cbClean: 1; // 2
		uint32 unknown2: 19;
		uint32 bciBusy: 1; // 22
		uint32 vgtBusy: 1; // 23
		uint32 paBusy: 1; // 24
		uint32 taBusy: 1; // 25
		uint32 sxBusy: 1; // 26
		uint32 spiBusy: 1; // 27
		uint32 unknown3: 1;
		uint32 scBusy: 1; // 29
		uint32 dbBusy: 1; // 30
		uint32 cbBusy: 1; // 31
	};
	uint32 val;
};

// GRBM_WAIT_IDLE_CLOCKS
union GrbmWaitIdleClocks {
	struct {
		uint32 waitIdleClocks: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// IA_CNTL_STATUS
union IaCntlStatus {
	struct {
		uint32 iaBusy: 1; // 0
		uint32 iaDmaBusy: 1; // 1
		uint32 iaDmaReqBusy: 1; // 2
		uint32 iaGrpBusy: 1; // 3
		uint32 iaAdcBusy: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// IA_DEBUG_CNTL
union IaDebugCntl {
	struct {
		uint32 iaDebugIndx: 6; // 0
		uint32 iaDebugSelBusB: 1; // 6
		uint32 unknown1: 25;
	};
	uint32 val;
};

// IA_DEBUG_DATA
union IaDebugData {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// IA_DEBUG_REG0
union IaDebugReg0 {
	struct {
		uint32 iaBusyExtended: 1; // 0
		uint32 iaNodmaBusyExtended: 1; // 1
		uint32 iaBusy: 1; // 2
		uint32 iaNodmaBusy: 1; // 3
		uint32 spare0: 1; // 4
		uint32 dmaReqBusy: 1; // 5
		uint32 dmaBusy: 1; // 6
		uint32 mcXl8rBusy: 1; // 7
		uint32 grpBusy: 1; // 8
		uint32 spare1: 1; // 9
		uint32 dmaGrpValid: 1; // 10
		uint32 grpDmaRead: 1; // 11
		uint32 dmaGrpHpValid: 1; // 12
		uint32 grpDmaHpRead: 1; // 13
		uint32 spare2: 10; // 14
		// uint32 unknown1: -4;
		// uint32 spare3: 1;
		uint32 regClkBusy: 1; // 24
		uint32 unknown2: 1;
		uint32 coreClkBusy: 1; // 26
		uint32 spare4: 1; // 27
		uint32 sclkRegVld: 1; // 28
		uint32 sclkCoreVld: 1; // 29
		uint32 spare5: 1; // 30
		uint32 spare6: 1; // 31
	};
	uint32 val;
};

// IA_DEBUG_REG1
union IaDebugReg1 {
	struct {
		uint32 dmaInputFifoEmpty: 1; // 0
		uint32 dmaInputFifoFull: 1; // 1
		uint32 startNewPacket: 1; // 2
		uint32 dmaRdreqDrQ: 1; // 3
		uint32 dmaZeroIndicesQ: 1; // 4
		uint32 dmaBufTypeQ: 2; // 5
		uint32 dmaReqPathQ: 1; // 7
		uint32 discard1stChunk: 1; // 8
		uint32 discard2ndChunk: 1; // 9
		uint32 secondTcRetDataQ: 1; // 10
		uint32 dmaTcRetSelQ: 1; // 11
		uint32 lastRdreqInDmaOp: 1; // 12
		uint32 dmaMaskFifoEmpty: 1; // 13
		uint32 dmaDataFifoEmptyQ: 1; // 14
		uint32 dmaDataFifoFull: 1; // 15
		uint32 dmaReqFifoEmpty: 1; // 16
		uint32 dmaReqFifoFull: 1; // 17
		uint32 stage2Dr: 1; // 18
		uint32 stage2Rtr: 1; // 19
		uint32 stage3Dr: 1; // 20
		uint32 stage3Rtr: 1; // 21
		uint32 stage4Dr: 1; // 22
		uint32 stage4Rtr: 1; // 23
		uint32 dmaSkidFifoEmpty: 1; // 24
		uint32 dmaSkidFifoFull: 1; // 25
		uint32 dmaGrpValid: 1; // 26
		uint32 grpDmaRead: 1; // 27
		uint32 currentDataValid: 1; // 28
		uint32 outOfRangeR2Q: 1; // 29
		uint32 dmaMaskFifoWe: 1; // 30
		uint32 dmaRetDataWeQ: 1; // 31
	};
	uint32 val;
};

// IA_DEBUG_REG2
union IaDebugReg2 {
	struct {
		uint32 hpDmaInputFifoEmpty: 1; // 0
		uint32 hpDmaInputFifoFull: 1; // 1
		uint32 hpStartNewPacket: 1; // 2
		uint32 hpDmaRdreqDrQ: 1; // 3
		uint32 hpDmaZeroIndicesQ: 1; // 4
		uint32 hpDmaBufTypeQ: 2; // 5
		uint32 hpDmaReqPathQ: 1; // 7
		uint32 hpDiscard1stChunk: 1; // 8
		uint32 hpDiscard2ndChunk: 1; // 9
		uint32 hpSecondTcRetDataQ: 1; // 10
		uint32 hpDmaTcRetSelQ: 1; // 11
		uint32 hpLastRdreqInDmaOp: 1; // 12
		uint32 hpDmaMaskFifoEmpty: 1; // 13
		uint32 hpDmaDataFifoEmptyQ: 1; // 14
		uint32 hpDmaDataFifoFull: 1; // 15
		uint32 hpDmaReqFifoEmpty: 1; // 16
		uint32 hpDmaReqFifoFull: 1; // 17
		uint32 hpStage2Dr: 1; // 18
		uint32 hpStage2Rtr: 1; // 19
		uint32 hpStage3Dr: 1; // 20
		uint32 hpStage3Rtr: 1; // 21
		uint32 hpStage4Dr: 1; // 22
		uint32 hpStage4Rtr: 1; // 23
		uint32 hpDmaSkidFifoEmpty: 1; // 24
		uint32 hpDmaSkidFifoFull: 1; // 25
		uint32 hpDmaGrpValid: 1; // 26
		uint32 hpGrpDmaRead: 1; // 27
		uint32 hpCurrentDataValid: 1; // 28
		uint32 hpOutOfRangeR2Q: 1; // 29
		uint32 hpDmaMaskFifoWe: 1; // 30
		uint32 hpDmaRetDataWeQ: 1; // 31
	};
	uint32 val;
};

// IA_DEBUG_REG3
union IaDebugReg3 {
	struct {
		uint32 dmaPipe0RdreqValid: 1; // 0
		uint32 dmaPipe0RdreqRead: 1; // 1
		uint32 dmaPipe0RdreqNullOut: 1; // 2
		uint32 dmaPipe0RdreqEopOut: 1; // 3
		uint32 dmaPipe0RdreqUseTcOut: 1; // 4
		uint32 grpDmaDrawIsPipe0: 1; // 5
		uint32 mustServicePipe0Req: 1; // 6
		uint32 sendPipe1Req: 1; // 7
		uint32 dmaPipe1RdreqValid: 1; // 8
		uint32 dmaPipe1RdreqRead: 1; // 9
		uint32 dmaPipe1RdreqNullOut: 1; // 10
		uint32 dmaPipe1RdreqEopOut: 1; // 11
		uint32 dmaPipe1RdreqUseTcOut: 1; // 12
		uint32 iaMcRdreqRtrQ: 1; // 13
		uint32 mcOutRtr: 1; // 14
		uint32 dmaRdreqSendOut: 1; // 15
		uint32 pipe0Dr: 1; // 16
		uint32 pipe0Rtr: 1; // 17
		uint32 iaTcRdreqRtrQ: 1; // 18
		uint32 tcOutRtr: 1; // 19
		uint32 pair0ValidP1: 1; // 20
		uint32 pair1ValidP1: 1; // 21
		uint32 pair2ValidP1: 1; // 22
		uint32 pair3ValidP1: 1; // 23
		uint32 tcReqCountQ: 2; // 24
		uint32 discard1stChunk: 1; // 26
		uint32 discard2ndChunk: 1; // 27
		uint32 lastTcReqP1: 1; // 28
		uint32 iaTcRdreqSendOut: 1; // 29
		uint32 tcIaRdretValidIn: 1; // 30
		uint32 tapIaRdretVldIn: 1; // 31
	};
	uint32 val;
};

// IA_DEBUG_REG4
union IaDebugReg4 {
	struct {
		uint32 pipe0Dr: 1; // 0
		uint32 pipe1Dr: 1; // 1
		uint32 pipe2Dr: 1; // 2
		uint32 pipe3Dr: 1; // 3
		uint32 pipe4Dr: 1; // 4
		uint32 pipe5Dr: 1; // 5
		uint32 grpSe0FifoEmpty: 1; // 6
		uint32 grpSe0FifoFull: 1; // 7
		uint32 pipe0Rtr: 1; // 8
		uint32 pipe1Rtr: 1; // 9
		uint32 pipe2Rtr: 1; // 10
		uint32 pipe3Rtr: 1; // 11
		uint32 pipe4Rtr: 1; // 12
		uint32 pipe5Rtr: 1; // 13
		uint32 iaVgtPrimRtrQ: 1; // 14
		uint32 iaSe1vgtPrimRtrQ: 1; // 15
		uint32 diMajorModeP1Q: 1; // 16
		uint32 gsModeP1Q: 3; // 17
		uint32 diEventFlagP1Q: 1; // 20
		uint32 diStateSelP1Q: 3; // 21
		uint32 drawOpaqEnP1Q: 1; // 24
		uint32 drawOpaqActiveQ: 1; // 25
		uint32 diSourceSelectP1Q: 2; // 26
		uint32 readyToReadDi: 1; // 28
		uint32 diFirstGroupOfDrawQ: 1; // 29
		uint32 lastShiftOfDraw: 1; // 30
		uint32 currentShiftIsVect1Q: 1; // 31
	};
	uint32 val;
};

// IA_DEBUG_REG5
union IaDebugReg5 {
	struct {
		uint32 diIndexCounterQ15_0: 16; // 0
		uint32 instanceid13_0: 14; // 16
		uint32 drawInputFifoFull: 1; // 30
		uint32 drawInputFifoEmpty: 1; // 31
	};
	uint32 val;
};

// IA_DEBUG_REG6
union IaDebugReg6 {
	struct {
		uint32 currentShiftQ: 4; // 0
		uint32 currentStridePre: 4; // 4
		uint32 currentStrideQ: 5; // 8
		uint32 firstGroupPartial: 1; // 13
		uint32 secondGroupPartial: 1; // 14
		uint32 currPrimPartial: 1; // 15
		uint32 nextStrideQ: 5; // 16
		uint32 nextGroupPartial: 1; // 21
		uint32 afterGroupPartial: 1; // 22
		uint32 extractGroup: 1; // 23
		uint32 grpShiftDebugData: 8; // 24
	};
	uint32 val;
};

// IA_DEBUG_REG7
union IaDebugReg7 {
	struct {
		uint32 resetIndxStateQ: 4; // 0
		uint32 shiftVectValidP2Q: 4; // 4
		uint32 shiftVect1ValidP2Q: 4; // 8
		uint32 shiftVect0ResetMatchP2Q: 4; // 12
		uint32 shiftVect1ResetMatchP2Q: 4; // 16
		uint32 numIndxInGroupP2Q: 3; // 20
		uint32 lastGroupOfDrawP2Q: 1; // 23
		uint32 shiftEventFlagP2Q: 1; // 24
		uint32 indxShiftIsOneP2Q: 1; // 25
		uint32 indxShiftIsTwoP2Q: 1; // 26
		uint32 indxStrideIsFourP2Q: 1; // 27
		uint32 shiftPrim1ResetP3Q: 1; // 28
		uint32 shiftPrim1PartialP3Q: 1; // 29
		uint32 shiftPrim0ResetP3Q: 1; // 30
		uint32 shiftPrim0PartialP3Q: 1; // 31
	};
	uint32 val;
};

// IA_DEBUG_REG8
union IaDebugReg8 {
	struct {
		uint32 diPrimTypeP1Q: 5; // 0
		uint32 twoCycleXferP1Q: 1; // 5
		uint32 twoPrimInputP1Q: 1; // 6
		uint32 shiftVectEndOfPacketP5Q: 1; // 7
		uint32 lastGroupOfInstP5Q: 1; // 8
		uint32 shiftPrim1NullFlagP5Q: 1; // 9
		uint32 shiftPrim0NullFlagP5Q: 1; // 10
		uint32 grpContinued: 1; // 11
		uint32 grpStateSel: 3; // 12
		uint32 grpSubPrimType: 6; // 15
		uint32 grpOutputPath: 3; // 21
		uint32 grpNullPrimitive: 1; // 24
		uint32 grpEop: 1; // 25
		uint32 grpEopg: 1; // 26
		uint32 grpEventFlag: 1; // 27
		uint32 grpComponentsValid: 4; // 28
	};
	uint32 val;
};

// IA_DEBUG_REG9
union IaDebugReg9 {
	struct {
		uint32 sendToSe1P6: 1; // 0
		uint32 gfxSeSwitchP6: 1; // 1
		uint32 nullEoiXferPrim1P6: 1; // 2
		uint32 nullEoiXferPrim0P6: 1; // 3
		uint32 prim1EoiP6: 1; // 4
		uint32 prim0EoiP6: 1; // 5
		uint32 prim1ValidEopgP6: 1; // 6
		uint32 prim0ValidEopgP6: 1; // 7
		uint32 prim1ToOtherSeP6: 1; // 8
		uint32 eopgOnLastPrimP6: 1; // 9
		uint32 eopgBetweenPrimsP6: 1; // 10
		uint32 primCountEqGroupSizeP6: 1; // 11
		uint32 primCountGtGroupSizeP6: 1; // 12
		uint32 twoPrimOutputP5Q: 1; // 13
		uint32 spare0: 1; // 14
		uint32 spare1: 1; // 15
		uint32 shiftVectEndOfPacketP5Q: 1; // 16
		uint32 prim1XferP6: 1; // 17
		uint32 grpSe1FifoEmpty: 1; // 18
		uint32 grpSe1FifoFull: 1; // 19
		uint32 unknown1: 12;
	};
	uint32 val;
};

// IA_ENHANCE
union IaEnhance {
	struct {
		uint32 misc: 32; // 0
	};
	uint32 val;
};

// IA_MULTI_VGT_PARAM
union IaMultiVgtParam {
	struct {
		uint32 primgroupSize: 16; // 0
		uint32 partialVsWaveOn: 1; // 16
		uint32 switchOnEop: 1; // 17
		uint32 partialEsWaveOn: 1; // 18
		uint32 switchOnEoi: 1; // 19
		uint32 wdSwitchOnEop: 1; // 20
		uint32 unknown1: 11;
	};
	uint32 val;
};

// IA_PERFCOUNTER0_HI
union IaPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// IA_PERFCOUNTER0_LO
union IaPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// IA_PERFCOUNTER0_SELECT
union IaPerfcounter0Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// IA_PERFCOUNTER0_SELECT1
union IaPerfcounter0Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 4;
		uint32 perfMode3: 4; // 24
		uint32 perfMode2: 4; // 28
	};
	uint32 val;
};

// IA_PERFCOUNTER1_HI
union IaPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// IA_PERFCOUNTER1_LO
union IaPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// IA_PERFCOUNTER1_SELECT
union IaPerfcounter1Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 20;
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// IA_PERFCOUNTER2_HI
union IaPerfcounter2Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// IA_PERFCOUNTER2_LO
union IaPerfcounter2Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// IA_PERFCOUNTER2_SELECT
union IaPerfcounter2Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 20;
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// IA_PERFCOUNTER3_HI
union IaPerfcounter3Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// IA_PERFCOUNTER3_LO
union IaPerfcounter3Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// IA_PERFCOUNTER3_SELECT
union IaPerfcounter3Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 20;
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// IA_VMID_OVERRIDE
union IaVmidOverride {
	struct {
		uint32 enable: 1; // 0
		uint32 vmid: 4; // 1
		uint32 unknown1: 27;
	};
	uint32 val;
};

// PA_CL_CLIP_CNTL
union PaClClipCntl {
	struct {
		uint32 ucpEna0: 1; // 0
		uint32 ucpEna1: 1; // 1
		uint32 ucpEna2: 1; // 2
		uint32 ucpEna3: 1; // 3
		uint32 ucpEna4: 1; // 4
		uint32 ucpEna5: 1; // 5
		uint32 unknown1: 7;
		uint32 psUcpYScaleNeg: 1; // 13
		uint32 psUcpMode: 2; // 14
		uint32 clipDisable: 1; // 16
		uint32 ucpCullOnlyEna: 1; // 17
		uint32 boundaryEdgeFlagEna: 1; // 18
		uint32 dxClipSpaceDef: 1; // 19
		uint32 disClipErrDetect: 1; // 20
		uint32 vtxKillOr: 1; // 21
		uint32 dxRasterizationKill: 1; // 22
		uint32 unknown2: 1;
		uint32 dxLinearAttrClipEna: 1; // 24
		uint32 vteVportProvokeDisable: 1; // 25
		uint32 zclipNearDisable: 1; // 26
		uint32 zclipFarDisable: 1; // 27
		uint32 unknown3: 4;
	};
	uint32 val;
};

// PA_CL_CNTL_STATUS
union PaClCntlStatus {
	struct {
		uint32 unknown1: 31;
		uint32 clBusy: 1; // 31
	};
	uint32 val;
};

// PA_CL_ENHANCE
union PaClEnhance {
	struct {
		uint32 clipVtxReorderEna: 1; // 0
		uint32 numClipSeq: 2; // 1
		uint32 clippedPrimSeqStall: 1; // 3
		uint32 veNanProcDisable: 1; // 4
		uint32 xtraDebugRegSel: 1; // 5
		uint32 unknown1: 22;
		uint32 ecoSpare3: 1; // 28
		uint32 ecoSpare2: 1; // 29
		uint32 ecoSpare1: 1; // 30
		uint32 ecoSpare0: 1; // 31
	};
	uint32 val;
};

// PA_CL_GB_HORZ_CLIP_ADJ
union PaClGbHorzClipAdj {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_GB_HORZ_DISC_ADJ
union PaClGbHorzDiscAdj {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_GB_VERT_CLIP_ADJ
union PaClGbVertClipAdj {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_GB_VERT_DISC_ADJ
union PaClGbVertDiscAdj {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_NANINF_CNTL
union PaClNaninfCntl {
	struct {
		uint32 vteXyInfDiscard: 1; // 0
		uint32 vteZInfDiscard: 1; // 1
		uint32 vteWInfDiscard: 1; // 2
		uint32 vte0xnaninfIs0: 1; // 3
		uint32 vteXyNanRetain: 1; // 4
		uint32 vteZNanRetain: 1; // 5
		uint32 vteWNanRetain: 1; // 6
		uint32 vteWRecipNanIs0: 1; // 7
		uint32 vsXyNanToInf: 1; // 8
		uint32 vsXyInfRetain: 1; // 9
		uint32 vsZNanToInf: 1; // 10
		uint32 vsZInfRetain: 1; // 11
		uint32 vsWNanToInf: 1; // 12
		uint32 vsWInfRetain: 1; // 13
		uint32 vsClipDistInfDiscard: 1; // 14
		uint32 unknown1: 5;
		uint32 vteNoOutputNeg0: 1; // 20
		uint32 unknown2: 11;
	};
	uint32 val;
};

// PA_CL_POINT_CULL_RAD
union PaClPointCullRad {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_POINT_SIZE
union PaClPointSize {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_POINT_X_RAD
union PaClPointXRad {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_POINT_Y_RAD
union PaClPointYRad {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_0_W
union PaClUcp0W {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_0_X
union PaClUcp0X {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_0_Y
union PaClUcp0Y {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_0_Z
union PaClUcp0Z {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_1_W
union PaClUcp1W {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_1_X
union PaClUcp1X {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_1_Y
union PaClUcp1Y {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_1_Z
union PaClUcp1Z {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_2_W
union PaClUcp2W {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_2_X
union PaClUcp2X {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_2_Y
union PaClUcp2Y {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_2_Z
union PaClUcp2Z {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_3_W
union PaClUcp3W {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_3_X
union PaClUcp3X {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_3_Y
union PaClUcp3Y {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_3_Z
union PaClUcp3Z {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_4_W
union PaClUcp4W {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_4_X
union PaClUcp4X {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_4_Y
union PaClUcp4Y {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_4_Z
union PaClUcp4Z {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_5_W
union PaClUcp5W {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_5_X
union PaClUcp5X {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_5_Y
union PaClUcp5Y {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_UCP_5_Z
union PaClUcp5Z {
	struct {
		uint32 dataRegister: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET
union PaClVportXoffset {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_1
union PaClVportXoffset1 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_10
union PaClVportXoffset10 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_11
union PaClVportXoffset11 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_12
union PaClVportXoffset12 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_13
union PaClVportXoffset13 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_14
union PaClVportXoffset14 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_15
union PaClVportXoffset15 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_2
union PaClVportXoffset2 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_3
union PaClVportXoffset3 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_4
union PaClVportXoffset4 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_5
union PaClVportXoffset5 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_6
union PaClVportXoffset6 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_7
union PaClVportXoffset7 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_8
union PaClVportXoffset8 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XOFFSET_9
union PaClVportXoffset9 {
	struct {
		uint32 vportXoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE
union PaClVportXscale {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_1
union PaClVportXscale1 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_10
union PaClVportXscale10 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_11
union PaClVportXscale11 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_12
union PaClVportXscale12 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_13
union PaClVportXscale13 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_14
union PaClVportXscale14 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_15
union PaClVportXscale15 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_2
union PaClVportXscale2 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_3
union PaClVportXscale3 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_4
union PaClVportXscale4 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_5
union PaClVportXscale5 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_6
union PaClVportXscale6 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_7
union PaClVportXscale7 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_8
union PaClVportXscale8 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_XSCALE_9
union PaClVportXscale9 {
	struct {
		uint32 vportXscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET
union PaClVportYoffset {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_1
union PaClVportYoffset1 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_10
union PaClVportYoffset10 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_11
union PaClVportYoffset11 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_12
union PaClVportYoffset12 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_13
union PaClVportYoffset13 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_14
union PaClVportYoffset14 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_15
union PaClVportYoffset15 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_2
union PaClVportYoffset2 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_3
union PaClVportYoffset3 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_4
union PaClVportYoffset4 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_5
union PaClVportYoffset5 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_6
union PaClVportYoffset6 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_7
union PaClVportYoffset7 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_8
union PaClVportYoffset8 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YOFFSET_9
union PaClVportYoffset9 {
	struct {
		uint32 vportYoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE
union PaClVportYscale {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_1
union PaClVportYscale1 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_10
union PaClVportYscale10 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_11
union PaClVportYscale11 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_12
union PaClVportYscale12 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_13
union PaClVportYscale13 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_14
union PaClVportYscale14 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_15
union PaClVportYscale15 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_2
union PaClVportYscale2 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_3
union PaClVportYscale3 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_4
union PaClVportYscale4 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_5
union PaClVportYscale5 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_6
union PaClVportYscale6 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_7
union PaClVportYscale7 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_8
union PaClVportYscale8 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_YSCALE_9
union PaClVportYscale9 {
	struct {
		uint32 vportYscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET
union PaClVportZoffset {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_1
union PaClVportZoffset1 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_10
union PaClVportZoffset10 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_11
union PaClVportZoffset11 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_12
union PaClVportZoffset12 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_13
union PaClVportZoffset13 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_14
union PaClVportZoffset14 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_15
union PaClVportZoffset15 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_2
union PaClVportZoffset2 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_3
union PaClVportZoffset3 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_4
union PaClVportZoffset4 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_5
union PaClVportZoffset5 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_6
union PaClVportZoffset6 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_7
union PaClVportZoffset7 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_8
union PaClVportZoffset8 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZOFFSET_9
union PaClVportZoffset9 {
	struct {
		uint32 vportZoffset: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE
union PaClVportZscale {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_1
union PaClVportZscale1 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_10
union PaClVportZscale10 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_11
union PaClVportZscale11 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_12
union PaClVportZscale12 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_13
union PaClVportZscale13 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_14
union PaClVportZscale14 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_15
union PaClVportZscale15 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_2
union PaClVportZscale2 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_3
union PaClVportZscale3 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_4
union PaClVportZscale4 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_5
union PaClVportZscale5 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_6
union PaClVportZscale6 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_7
union PaClVportZscale7 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_8
union PaClVportZscale8 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VPORT_ZSCALE_9
union PaClVportZscale9 {
	struct {
		uint32 vportZscale: 32; // 0
	};
	uint32 val;
};

// PA_CL_VS_OUT_CNTL
union PaClVsOutCntl {
	struct {
		uint32 clipDistEna0: 1; // 0
		uint32 clipDistEna1: 1; // 1
		uint32 clipDistEna2: 1; // 2
		uint32 clipDistEna3: 1; // 3
		uint32 clipDistEna4: 1; // 4
		uint32 clipDistEna5: 1; // 5
		uint32 clipDistEna6: 1; // 6
		uint32 clipDistEna7: 1; // 7
		uint32 cullDistEna0: 1; // 8
		uint32 cullDistEna1: 1; // 9
		uint32 cullDistEna2: 1; // 10
		uint32 cullDistEna3: 1; // 11
		uint32 cullDistEna4: 1; // 12
		uint32 cullDistEna5: 1; // 13
		uint32 cullDistEna6: 1; // 14
		uint32 cullDistEna7: 1; // 15
		uint32 useVtxPointSize: 1; // 16
		uint32 useVtxEdgeFlag: 1; // 17
		uint32 useVtxRenderTargetIndx: 1; // 18
		uint32 useVtxViewportIndx: 1; // 19
		uint32 useVtxKillFlag: 1; // 20
		uint32 vsOutMiscVecEna: 1; // 21
		uint32 vsOutCcdist0VecEna: 1; // 22
		uint32 vsOutCcdist1VecEna: 1; // 23
		uint32 vsOutMiscSideBusEna: 1; // 24
		uint32 useVtxGsCutFlag: 1; // 25
		uint32 unknown1: 6;
	};
	uint32 val;
};

// PA_CL_VTE_CNTL
union PaClVteCntl {
	struct {
		uint32 vportXScaleEna: 1; // 0
		uint32 vportXOffsetEna: 1; // 1
		uint32 vportYScaleEna: 1; // 2
		uint32 vportYOffsetEna: 1; // 3
		uint32 vportZScaleEna: 1; // 4
		uint32 vportZOffsetEna: 1; // 5
		uint32 unknown1: 2;
		uint32 vtxXyFmt: 1; // 8
		uint32 vtxZFmt: 1; // 9
		uint32 vtxW0Fmt: 1; // 10
		uint32 perfcounterRef: 1; // 11
		uint32 unknown2: 20;
	};
	uint32 val;
};

// PA_SC_AA_CONFIG
union PaScAaConfig {
	struct {
		uint32 msaaNumSamples: 3; // 0
		uint32 unknown1: 1;
		uint32 aaMaskCentroidDtmn: 1; // 4
		uint32 unknown2: 8;
		uint32 maxSampleDist: 4; // 13
		uint32 unknown3: 3;
		uint32 msaaExposedSamples: 3; // 20
		uint32 unknown4: 1;
		uint32 detailToExposedMode: 2; // 24
		uint32 unknown5: 6;
	};
	uint32 val;
};

// PA_SC_AA_MASK_X0Y0_X1Y0
union PaScAaMaskX0y0X1y0 {
	struct {
		uint32 aaMaskX0y0: 16; // 0
		uint32 aaMaskX1y0: 16; // 16
	};
	uint32 val;
};

// PA_SC_AA_MASK_X0Y1_X1Y1
union PaScAaMaskX0y1X1y1 {
	struct {
		uint32 aaMaskX0y1: 16; // 0
		uint32 aaMaskX1y1: 16; // 16
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X0Y0_0
union PaScAaSampleLocsPixelX0y0_0 {
	struct {
		uint32 s0X: 4; // 0
		uint32 s0Y: 4; // 4
		uint32 s1X: 4; // 8
		uint32 s1Y: 4; // 12
		uint32 s2X: 4; // 16
		uint32 s2Y: 4; // 20
		uint32 s3X: 4; // 24
		uint32 s3Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X0Y0_1
union PaScAaSampleLocsPixelX0y0_1 {
	struct {
		uint32 s4X: 4; // 0
		uint32 s4Y: 4; // 4
		uint32 s5X: 4; // 8
		uint32 s5Y: 4; // 12
		uint32 s6X: 4; // 16
		uint32 s6Y: 4; // 20
		uint32 s7X: 4; // 24
		uint32 s7Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X0Y0_2
union PaScAaSampleLocsPixelX0y0_2 {
	struct {
		uint32 s8X: 4; // 0
		uint32 s8Y: 4; // 4
		uint32 s9X: 4; // 8
		uint32 s9Y: 4; // 12
		uint32 s10X: 4; // 16
		uint32 s10Y: 4; // 20
		uint32 s11X: 4; // 24
		uint32 s11Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X0Y0_3
union PaScAaSampleLocsPixelX0y0_3 {
	struct {
		uint32 s12X: 4; // 0
		uint32 s12Y: 4; // 4
		uint32 s13X: 4; // 8
		uint32 s13Y: 4; // 12
		uint32 s14X: 4; // 16
		uint32 s14Y: 4; // 20
		uint32 s15X: 4; // 24
		uint32 s15Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X0Y1_0
union PaScAaSampleLocsPixelX0y1_0 {
	struct {
		uint32 s0X: 4; // 0
		uint32 s0Y: 4; // 4
		uint32 s1X: 4; // 8
		uint32 s1Y: 4; // 12
		uint32 s2X: 4; // 16
		uint32 s2Y: 4; // 20
		uint32 s3X: 4; // 24
		uint32 s3Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X0Y1_1
union PaScAaSampleLocsPixelX0y1_1 {
	struct {
		uint32 s4X: 4; // 0
		uint32 s4Y: 4; // 4
		uint32 s5X: 4; // 8
		uint32 s5Y: 4; // 12
		uint32 s6X: 4; // 16
		uint32 s6Y: 4; // 20
		uint32 s7X: 4; // 24
		uint32 s7Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X0Y1_2
union PaScAaSampleLocsPixelX0y1_2 {
	struct {
		uint32 s8X: 4; // 0
		uint32 s8Y: 4; // 4
		uint32 s9X: 4; // 8
		uint32 s9Y: 4; // 12
		uint32 s10X: 4; // 16
		uint32 s10Y: 4; // 20
		uint32 s11X: 4; // 24
		uint32 s11Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X0Y1_3
union PaScAaSampleLocsPixelX0y1_3 {
	struct {
		uint32 s12X: 4; // 0
		uint32 s12Y: 4; // 4
		uint32 s13X: 4; // 8
		uint32 s13Y: 4; // 12
		uint32 s14X: 4; // 16
		uint32 s14Y: 4; // 20
		uint32 s15X: 4; // 24
		uint32 s15Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X1Y0_0
union PaScAaSampleLocsPixelX1y0_0 {
	struct {
		uint32 s0X: 4; // 0
		uint32 s0Y: 4; // 4
		uint32 s1X: 4; // 8
		uint32 s1Y: 4; // 12
		uint32 s2X: 4; // 16
		uint32 s2Y: 4; // 20
		uint32 s3X: 4; // 24
		uint32 s3Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X1Y0_1
union PaScAaSampleLocsPixelX1y0_1 {
	struct {
		uint32 s4X: 4; // 0
		uint32 s4Y: 4; // 4
		uint32 s5X: 4; // 8
		uint32 s5Y: 4; // 12
		uint32 s6X: 4; // 16
		uint32 s6Y: 4; // 20
		uint32 s7X: 4; // 24
		uint32 s7Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X1Y0_2
union PaScAaSampleLocsPixelX1y0_2 {
	struct {
		uint32 s8X: 4; // 0
		uint32 s8Y: 4; // 4
		uint32 s9X: 4; // 8
		uint32 s9Y: 4; // 12
		uint32 s10X: 4; // 16
		uint32 s10Y: 4; // 20
		uint32 s11X: 4; // 24
		uint32 s11Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X1Y0_3
union PaScAaSampleLocsPixelX1y0_3 {
	struct {
		uint32 s12X: 4; // 0
		uint32 s12Y: 4; // 4
		uint32 s13X: 4; // 8
		uint32 s13Y: 4; // 12
		uint32 s14X: 4; // 16
		uint32 s14Y: 4; // 20
		uint32 s15X: 4; // 24
		uint32 s15Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X1Y1_0
union PaScAaSampleLocsPixelX1y1_0 {
	struct {
		uint32 s0X: 4; // 0
		uint32 s0Y: 4; // 4
		uint32 s1X: 4; // 8
		uint32 s1Y: 4; // 12
		uint32 s2X: 4; // 16
		uint32 s2Y: 4; // 20
		uint32 s3X: 4; // 24
		uint32 s3Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X1Y1_1
union PaScAaSampleLocsPixelX1y1_1 {
	struct {
		uint32 s4X: 4; // 0
		uint32 s4Y: 4; // 4
		uint32 s5X: 4; // 8
		uint32 s5Y: 4; // 12
		uint32 s6X: 4; // 16
		uint32 s6Y: 4; // 20
		uint32 s7X: 4; // 24
		uint32 s7Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X1Y1_2
union PaScAaSampleLocsPixelX1y1_2 {
	struct {
		uint32 s8X: 4; // 0
		uint32 s8Y: 4; // 4
		uint32 s9X: 4; // 8
		uint32 s9Y: 4; // 12
		uint32 s10X: 4; // 16
		uint32 s10Y: 4; // 20
		uint32 s11X: 4; // 24
		uint32 s11Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_AA_SAMPLE_LOCS_PIXEL_X1Y1_3
union PaScAaSampleLocsPixelX1y1_3 {
	struct {
		uint32 s12X: 4; // 0
		uint32 s12Y: 4; // 4
		uint32 s13X: 4; // 8
		uint32 s13Y: 4; // 12
		uint32 s14X: 4; // 16
		uint32 s14Y: 4; // 20
		uint32 s15X: 4; // 24
		uint32 s15Y: 4; // 28
	};
	uint32 val;
};

// PA_SC_CENTROID_PRIORITY_0
union PaScCentroidPriority0 {
	struct {
		uint32 distance0: 4; // 0
		uint32 distance1: 4; // 4
		uint32 distance2: 4; // 8
		uint32 distance3: 4; // 12
		uint32 distance4: 4; // 16
		uint32 distance5: 4; // 20
		uint32 distance6: 4; // 24
		uint32 distance7: 4; // 28
	};
	uint32 val;
};

// PA_SC_CENTROID_PRIORITY_1
union PaScCentroidPriority1 {
	struct {
		uint32 distance8: 4; // 0
		uint32 distance9: 4; // 4
		uint32 distance10: 4; // 8
		uint32 distance11: 4; // 12
		uint32 distance12: 4; // 16
		uint32 distance13: 4; // 20
		uint32 distance14: 4; // 24
		uint32 distance15: 4; // 28
	};
	uint32 val;
};

// PA_SC_CLIPRECT_0_BR
union PaScCliprect0Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_CLIPRECT_0_TL
union PaScCliprect0Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_CLIPRECT_1_BR
union PaScCliprect1Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_CLIPRECT_1_TL
union PaScCliprect1Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_CLIPRECT_2_BR
union PaScCliprect2Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_CLIPRECT_2_TL
union PaScCliprect2Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_CLIPRECT_3_BR
union PaScCliprect3Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_CLIPRECT_3_TL
union PaScCliprect3Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_CLIPRECT_RULE
union PaScCliprectRule {
	struct {
		uint32 clipRule: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PA_SC_DEBUG_CNTL
union PaScDebugCntl {
	struct {
		uint32 scDebugIndx: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// PA_SC_DEBUG_DATA
union PaScDebugData {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// PA_SC_DEBUG_REG0
union PaScDebugReg0 {
	struct {
		uint32 reg0Field0: 2; // 0
		uint32 reg0Field1: 2; // 2
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PA_SC_DEBUG_REG1
union PaScDebugReg1 {
	struct {
		uint32 reg1Field0: 2; // 0
		uint32 reg1Field1: 2; // 2
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PA_SC_EDGERULE
union PaScEdgerule {
	struct {
		uint32 erTri: 4; // 0
		uint32 erPoint: 4; // 4
		uint32 erRect: 4; // 8
		uint32 erLineLr: 6; // 12
		uint32 erLineRl: 6; // 18
		uint32 erLineTb: 4; // 24
		uint32 erLineBt: 4; // 28
	};
	uint32 val;
};

// PA_SC_ENHANCE
union PaScEnhance {
	struct {
		uint32 enablePaScOutOfOrder: 1; // 0
		uint32 disableScDbTileFix: 1; // 1
		uint32 disableAaMaskFullFix: 1; // 2
		uint32 enable1xmsaaSampleLocations: 1; // 3
		uint32 enable1xmsaaSampleLocCentroid: 1; // 4
		uint32 disableScissorFix: 1; // 5
		uint32 disablePwBubbleCollapse: 2; // 6
		uint32 sendUnlitStilesToPacker: 1; // 8
		uint32 disableDualgradPerfOptimization: 1; // 9
		uint32 disableScProcessResetPrim: 1; // 10
		uint32 disableScProcessResetSupertile: 1; // 11
		uint32 disableScProcessResetTile: 1; // 12
		uint32 disablePaScGuidance: 1; // 13
		uint32 disableEovAllCtrlOnlyCombinations: 1; // 14
		uint32 enableMulticycleBubbleFreeze: 1; // 15
		uint32 disableOutOfOrderPaScGuidance: 1; // 16
		uint32 enableOutOfOrderPolyMode: 1; // 17
		uint32 disableOutOfOrderEopSyncNullPrimsLast: 1; // 18
		uint32 disableOutOfOrderThresholdSwitching: 1; // 19
		uint32 enableOutOfOrderThresholdSwitchAtEopgOnly: 1; // 20
		uint32 disableOutOfOrderDesiredFifoEmptySwitching: 1; // 21
		uint32 disableOutOfOrderSelectedFifoEmptySwitching: 1; // 22
		uint32 disableOutOfOrderEmptySwitchingHysterysis: 1; // 23
		uint32 enableOutOfOrderDesiredFifoIsNextFeid: 1; // 24
		uint32 unknown1: 5;
		uint32 ecoSpare1: 1; // 30
		uint32 ecoSpare0: 1; // 31
	};
	uint32 val;
};

// PA_SC_FIFO_DEPTH_CNTL
union PaScFifoDepthCntl {
	struct {
		uint32 depth: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// PA_SC_FIFO_SIZE
union PaScFifoSize {
	struct {
		uint32 scFrontendPrimFifoSize: 6; // 0
		uint32 scBackendPrimFifoSize: 9; // 6
		uint32 scHizTileFifoSize: 6; // 15
		uint32 unknown1: 2;
		uint32 scEarlyzTileFifoSize: 9; // 23
	};
	uint32 val;
};

// PA_SC_FORCE_EOV_MAX_CNTS
union PaScForceEovMaxCnts {
	struct {
		uint32 forceEovMaxClkCnt: 16; // 0
		uint32 forceEovMaxRezCnt: 16; // 16
	};
	uint32 val;
};

// PA_SC_GENERIC_SCISSOR_BR
union PaScGenericScissorBr {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_GENERIC_SCISSOR_TL
union PaScGenericScissorTl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_IF_FIFO_SIZE
union PaScIfFifoSize {
	struct {
		uint32 scDbTileIfFifoSize: 6; // 0
		uint32 scDbQuadIfFifoSize: 6; // 6
		uint32 scSpiIfFifoSize: 6; // 12
		uint32 scBciIfFifoSize: 6; // 18
		uint32 unknown1: 8;
	};
	uint32 val;
};

// PA_SC_LINE_CNTL
union PaScLineCntl {
	struct {
		uint32 unknown1: 9;
		uint32 expandLineWidth: 1; // 9
		uint32 lastPixel: 1; // 10
		uint32 perpendicularEndcapEna: 1; // 11
		uint32 dx10DiamondTestEna: 1; // 12
		uint32 unknown2: 19;
	};
	uint32 val;
};

// PA_SC_LINE_STIPPLE
union PaScLineStipple {
	struct {
		uint32 linePattern: 16; // 0
		uint32 repeatCount: 8; // 16
		uint32 unknown1: 4;
		uint32 patternBitOrder: 1; // 28
		uint32 autoResetCntl: 2; // 29
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_LINE_STIPPLE_STATE
union PaScLineStippleState {
	struct {
		uint32 currentPtr: 4; // 0
		uint32 unknown1: 4;
		uint32 currentCount: 8; // 8
		uint32 unknown2: 16;
	};
	uint32 val;
};

// PA_SC_MODE_CNTL_0
union PaScModeCntl0 {
	struct {
		uint32 msaaEnable: 1; // 0
		uint32 vportScissorEnable: 1; // 1
		uint32 lineStippleEnable: 1; // 2
		uint32 sendUnlitStilesToPkr: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// PA_SC_MODE_CNTL_1
union PaScModeCntl1 {
	struct {
		uint32 walkSize: 1; // 0
		uint32 walkAlignment: 1; // 1
		uint32 walkAlign8PrimFitsSt: 1; // 2
		uint32 walkFenceEnable: 1; // 3
		uint32 walkFenceSize: 3; // 4
		uint32 supertileWalkOrderEnable: 1; // 7
		uint32 tileWalkOrderEnable: 1; // 8
		uint32 tileCoverDisable: 1; // 9
		uint32 tileCoverNoScissor: 1; // 10
		uint32 zmmLineExtent: 1; // 11
		uint32 zmmLineOffset: 1; // 12
		uint32 zmmRectExtent: 1; // 13
		uint32 killPixPostHiZ: 1; // 14
		uint32 killPixPostDetailMask: 1; // 15
		uint32 psIterSample: 1; // 16
		uint32 multiShaderEnginePrimDiscardEnable: 1; // 17
		uint32 multiGpuSupertileEnable: 1; // 18
		uint32 gpuIdOverrideEnable: 1; // 19
		uint32 gpuIdOverride: 4; // 20
		uint32 multiGpuPrimDiscardEnable: 1; // 24
		uint32 forceEovCntdwnEnable: 1; // 25
		uint32 forceEovRezEnable: 1; // 26
		uint32 outOfOrderPrimitiveEnable: 1; // 27
		uint32 outOfOrderWaterMark: 3; // 28
		uint32 unknown1: 1;
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER0_HI
union PaScPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER0_LO
union PaScPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER0_SELECT
union PaScPerfcounter0Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 1;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER0_SELECT1
union PaScPerfcounter0Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 12;
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER1_HI
union PaScPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER1_LO
union PaScPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER1_SELECT
union PaScPerfcounter1Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER2_HI
union PaScPerfcounter2Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER2_LO
union PaScPerfcounter2Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER2_SELECT
union PaScPerfcounter2Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER3_HI
union PaScPerfcounter3Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER3_LO
union PaScPerfcounter3Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER3_SELECT
union PaScPerfcounter3Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER4_HI
union PaScPerfcounter4Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER4_LO
union PaScPerfcounter4Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER4_SELECT
union PaScPerfcounter4Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER5_HI
union PaScPerfcounter5Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER5_LO
union PaScPerfcounter5Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER5_SELECT
union PaScPerfcounter5Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER6_HI
union PaScPerfcounter6Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER6_LO
union PaScPerfcounter6Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER6_SELECT
union PaScPerfcounter6Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER7_HI
union PaScPerfcounter7Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER7_LO
union PaScPerfcounter7Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// PA_SC_PERFCOUNTER7_SELECT
union PaScPerfcounter7Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// PA_SC_RASTER_CONFIG
union PaScRasterConfig {
	struct {
		uint32 rbMapPkr0: 2; // 0
		uint32 rbMapPkr1: 2; // 2
		uint32 rbXsel2: 2; // 4
		uint32 rbXsel: 1; // 6
		uint32 rbYsel: 1; // 7
		uint32 pkrMap: 2; // 8
		uint32 pkrXsel: 2; // 10
		uint32 pkrYsel: 2; // 12
		uint32 pkrXsel2: 2; // 14
		uint32 scMap: 2; // 16
		uint32 scXsel: 2; // 18
		uint32 scYsel: 2; // 20
		uint32 unknown1: 2;
		uint32 seMap: 2; // 24
		uint32 seXsel: 2; // 26
		uint32 seYsel: 2; // 28
		uint32 unknown2: 2;
	};
	uint32 val;
};

// PA_SC_RASTER_CONFIG_1
union PaScRasterConfig1 {
	struct {
		uint32 sePairMap: 2; // 0
		uint32 sePairXsel: 2; // 2
		uint32 sePairYsel: 2; // 4
		uint32 unknown1: 26;
	};
	uint32 val;
};

// PA_SC_SCREEN_SCISSOR_BR
union PaScScreenScissorBr {
	struct {
		uint32 brX: 16; // 0
		uint32 brY: 16; // 16
	};
	uint32 val;
};

// PA_SC_SCREEN_SCISSOR_TL
union PaScScreenScissorTl {
	struct {
		uint32 tlX: 16; // 0
		uint32 tlY: 16; // 16
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_0_BR
union PaScVportScissor0Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_0_TL
union PaScVportScissor0Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_10_BR
union PaScVportScissor10Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_10_TL
union PaScVportScissor10Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_11_BR
union PaScVportScissor11Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_11_TL
union PaScVportScissor11Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_12_BR
union PaScVportScissor12Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_12_TL
union PaScVportScissor12Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_13_BR
union PaScVportScissor13Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_13_TL
union PaScVportScissor13Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_14_BR
union PaScVportScissor14Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_14_TL
union PaScVportScissor14Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_15_BR
union PaScVportScissor15Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_15_TL
union PaScVportScissor15Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_1_BR
union PaScVportScissor1Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_1_TL
union PaScVportScissor1Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_2_BR
union PaScVportScissor2Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_2_TL
union PaScVportScissor2Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_3_BR
union PaScVportScissor3Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_3_TL
union PaScVportScissor3Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_4_BR
union PaScVportScissor4Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_4_TL
union PaScVportScissor4Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_5_BR
union PaScVportScissor5Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_5_TL
union PaScVportScissor5Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_6_BR
union PaScVportScissor6Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_6_TL
union PaScVportScissor6Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_7_BR
union PaScVportScissor7Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_7_TL
union PaScVportScissor7Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_8_BR
union PaScVportScissor8Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_8_TL
union PaScVportScissor8Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_9_BR
union PaScVportScissor9Br {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_VPORT_SCISSOR_9_TL
union PaScVportScissor9Tl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_0
union PaScVportZmax0 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_1
union PaScVportZmax1 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_10
union PaScVportZmax10 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_11
union PaScVportZmax11 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_12
union PaScVportZmax12 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_13
union PaScVportZmax13 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_14
union PaScVportZmax14 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_15
union PaScVportZmax15 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_2
union PaScVportZmax2 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_3
union PaScVportZmax3 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_4
union PaScVportZmax4 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_5
union PaScVportZmax5 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_6
union PaScVportZmax6 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_7
union PaScVportZmax7 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_8
union PaScVportZmax8 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMAX_9
union PaScVportZmax9 {
	struct {
		uint32 vportZmax: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_0
union PaScVportZmin0 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_1
union PaScVportZmin1 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_10
union PaScVportZmin10 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_11
union PaScVportZmin11 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_12
union PaScVportZmin12 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_13
union PaScVportZmin13 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_14
union PaScVportZmin14 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_15
union PaScVportZmin15 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_2
union PaScVportZmin2 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_3
union PaScVportZmin3 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_4
union PaScVportZmin4 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_5
union PaScVportZmin5 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_6
union PaScVportZmin6 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_7
union PaScVportZmin7 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_8
union PaScVportZmin8 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_VPORT_ZMIN_9
union PaScVportZmin9 {
	struct {
		uint32 vportZmin: 32; // 0
	};
	uint32 val;
};

// PA_SC_WINDOW_OFFSET
union PaScWindowOffset {
	struct {
		uint32 windowXOffset: 16; // 0
		uint32 windowYOffset: 16; // 16
	};
	uint32 val;
};

// PA_SC_WINDOW_SCISSOR_BR
union PaScWindowScissorBr {
	struct {
		uint32 brX: 15; // 0
		uint32 unknown1: 1;
		uint32 brY: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// PA_SC_WINDOW_SCISSOR_TL
union PaScWindowScissorTl {
	struct {
		uint32 tlX: 15; // 0
		uint32 unknown1: 1;
		uint32 tlY: 15; // 16
		uint32 windowOffsetDisable: 1; // 31
	};
	uint32 val;
};

// PA_SU_CNTL_STATUS
union PaSuCntlStatus {
	struct {
		uint32 unknown1: 31;
		uint32 suBusy: 1; // 31
	};
	uint32 val;
};

// PA_SU_DEBUG_CNTL
union PaSuDebugCntl {
	struct {
		uint32 suDebugIndx: 5; // 0
		uint32 unknown1: 27;
	};
	uint32 val;
};

// PA_SU_DEBUG_DATA
union PaSuDebugData {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// PA_SU_HARDWARE_SCREEN_OFFSET
union PaSuHardwareScreenOffset {
	struct {
		uint32 hwScreenOffsetX: 9; // 0
		uint32 unknown1: 7;
		uint32 hwScreenOffsetY: 9; // 16
		uint32 unknown2: 7;
	};
	uint32 val;
};

// PA_SU_LINE_CNTL
union PaSuLineCntl {
	struct {
		uint32 width: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PA_SU_LINE_STIPPLE_CNTL
union PaSuLineStippleCntl {
	struct {
		uint32 lineStippleReset: 2; // 0
		uint32 expandFullLength: 1; // 2
		uint32 fractionalAccum: 1; // 3
		uint32 diamondAdjust: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// PA_SU_LINE_STIPPLE_SCALE
union PaSuLineStippleScale {
	struct {
		uint32 lineStippleScale: 32; // 0
	};
	uint32 val;
};

// PA_SU_LINE_STIPPLE_VALUE
union PaSuLineStippleValue {
	struct {
		uint32 lineStippleValue: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER0_HI
union PaSuPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER0_LO
union PaSuPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER0_SELECT
union PaSuPerfcounter0Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER0_SELECT1
union PaSuPerfcounter0Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 12;
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER1_HI
union PaSuPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER1_LO
union PaSuPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER1_SELECT
union PaSuPerfcounter1Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER1_SELECT1
union PaSuPerfcounter1Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 12;
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER2_HI
union PaSuPerfcounter2Hi {
	struct {
		uint32 perfcounterHi: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER2_LO
union PaSuPerfcounter2Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER2_SELECT
union PaSuPerfcounter2Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 12;
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER3_HI
union PaSuPerfcounter3Hi {
	struct {
		uint32 perfcounterHi: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER3_LO
union PaSuPerfcounter3Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// PA_SU_PERFCOUNTER3_SELECT
union PaSuPerfcounter3Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 12;
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// PA_SU_POINT_MINMAX
union PaSuPointMinmax {
	struct {
		uint32 minSize: 16; // 0
		uint32 maxSize: 16; // 16
	};
	uint32 val;
};

// PA_SU_POINT_SIZE
union PaSuPointSize {
	struct {
		uint32 height: 16; // 0
		uint32 width: 16; // 16
	};
	uint32 val;
};

// PA_SU_POLY_OFFSET_BACK_OFFSET
union PaSuPolyOffsetBackOffset {
	struct {
		uint32 offset: 32; // 0
	};
	uint32 val;
};

// PA_SU_POLY_OFFSET_BACK_SCALE
union PaSuPolyOffsetBackScale {
	struct {
		uint32 scale: 32; // 0
	};
	uint32 val;
};

// PA_SU_POLY_OFFSET_CLAMP
union PaSuPolyOffsetClamp {
	struct {
		uint32 clamp: 32; // 0
	};
	uint32 val;
};

// PA_SU_POLY_OFFSET_DB_FMT_CNTL
union PaSuPolyOffsetDbFmtCntl {
	struct {
		uint32 polyOffsetNegNumDbBits: 8; // 0
		uint32 polyOffsetDbIsFloatFmt: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// PA_SU_POLY_OFFSET_FRONT_OFFSET
union PaSuPolyOffsetFrontOffset {
	struct {
		uint32 offset: 32; // 0
	};
	uint32 val;
};

// PA_SU_POLY_OFFSET_FRONT_SCALE
union PaSuPolyOffsetFrontScale {
	struct {
		uint32 scale: 32; // 0
	};
	uint32 val;
};

// PA_SU_PRIM_FILTER_CNTL
union PaSuPrimFilterCntl {
	struct {
		uint32 triangleFilterDisable: 1; // 0
		uint32 lineFilterDisable: 1; // 1
		uint32 pointFilterDisable: 1; // 2
		uint32 rectangleFilterDisable: 1; // 3
		uint32 triangleExpandEna: 1; // 4
		uint32 lineExpandEna: 1; // 5
		uint32 pointExpandEna: 1; // 6
		uint32 rectangleExpandEna: 1; // 7
		uint32 primExpandConstant: 8; // 8
		uint32 unknown1: 14;
		uint32 xmaxRightExclusion: 1; // 30
		uint32 ymaxBottomExclusion: 1; // 31
	};
	uint32 val;
};

// PA_SU_SC_MODE_CNTL
union PaSuScModeCntl {
	struct {
		uint32 cullFront: 1; // 0
		uint32 cullBack: 1; // 1
		uint32 face: 1; // 2
		uint32 polyMode: 2; // 3
		uint32 polymodeFrontPtype: 3; // 5
		uint32 polymodeBackPtype: 3; // 8
		uint32 polyOffsetFrontEnable: 1; // 11
		uint32 polyOffsetBackEnable: 1; // 12
		uint32 polyOffsetParaEnable: 1; // 13
		uint32 unknown1: 2;
		uint32 vtxWindowOffsetEnable: 1; // 16
		uint32 unknown2: 2;
		uint32 provokingVtxLast: 1; // 19
		uint32 perspCorrDis: 1; // 20
		uint32 multiPrimIbEna: 1; // 21
		uint32 unknown3: 10;
	};
	uint32 val;
};

// PA_SU_VTX_CNTL
union PaSuVtxCntl {
	struct {
		uint32 pixCenter: 1; // 0
		uint32 roundMode: 2; // 1
		uint32 quantMode: 3; // 3
		uint32 unknown1: 26;
	};
	uint32 val;
};

// RAS_BCI_SIGNATURE0
union RasBciSignature0 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_BCI_SIGNATURE1
union RasBciSignature1 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_CB_SIGNATURE0
union RasCbSignature0 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_DB_SIGNATURE0
union RasDbSignature0 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_IA_SIGNATURE0
union RasIaSignature0 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_IA_SIGNATURE1
union RasIaSignature1 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_PA_SIGNATURE0
union RasPaSignature0 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SC_SIGNATURE0
union RasScSignature0 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SC_SIGNATURE1
union RasScSignature1 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SC_SIGNATURE2
union RasScSignature2 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SC_SIGNATURE3
union RasScSignature3 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SC_SIGNATURE4
union RasScSignature4 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SC_SIGNATURE5
union RasScSignature5 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SC_SIGNATURE6
union RasScSignature6 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SC_SIGNATURE7
union RasScSignature7 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SIGNATURE_CONTROL
union RasSignatureControl {
	struct {
		uint32 enable: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// RAS_SIGNATURE_MASK
union RasSignatureMask {
	struct {
		uint32 inputBusMask: 32; // 0
	};
	uint32 val;
};

// RAS_SPI_SIGNATURE0
union RasSpiSignature0 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SPI_SIGNATURE1
union RasSpiSignature1 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SQ_SIGNATURE0
union RasSqSignature0 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SX_SIGNATURE0
union RasSxSignature0 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SX_SIGNATURE1
union RasSxSignature1 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SX_SIGNATURE2
union RasSxSignature2 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_SX_SIGNATURE3
union RasSxSignature3 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_TA_SIGNATURE0
union RasTaSignature0 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_TD_SIGNATURE0
union RasTdSignature0 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RAS_VGT_SIGNATURE0
union RasVgtSignature0 {
	struct {
		uint32 signature: 32; // 0
	};
	uint32 val;
};

// RLC_AUTO_PG_CTRL
union RlcAutoPgCtrl {
	struct {
		uint32 autoPgEn: 1; // 0
		uint32 autoGrbmRegSaveOnIdleEn: 1; // 1
		uint32 autoWakeUpEn: 1; // 2
		uint32 grbmRegSaveGfxIdleThreshold: 16; // 3
		uint32 pgAfterGrbmRegSaveThreshold: 13; // 19
	};
	uint32 val;
};

// RLC_CAPTURE_GPU_CLOCK_COUNT
union RlcCaptureGpuClockCount {
	struct {
		uint32 capture: 1; // 0
		uint32 reserved: 31; // 1
	};
	uint32 val;
};

// RLC_CGCG_CGLS_CTRL
union RlcCgcgCglsCtrl {
	struct {
		uint32 cgcgEn: 1; // 0
		uint32 cglsEn: 1; // 1
		uint32 cglsRepCompansatDelay: 6; // 2
		uint32 cgcgGfxIdleThreshold: 8; // 8
		uint32 unknown1: 11;
		uint32 cgcgController: 1; // 27
		uint32 cgcgRegCtrl: 1; // 28
		uint32 sleepMode: 2; // 29
		uint32 spare: 1; // 31
	};
	uint32 val;
};

// RLC_CGCG_RAMP_CTRL
union RlcCgcgRampCtrl {
	struct {
		uint32 downDivStartUnit: 4; // 0
		uint32 downDivStepUnit: 4; // 4
		uint32 upDivStartUnit: 4; // 8
		uint32 upDivStepUnit: 4; // 12
		uint32 stepDelayCnt: 12; // 16
		uint32 stepDelayUnit: 4; // 28
	};
	uint32 val;
};

// RLC_CGTT_MGCG_OVERRIDE
union RlcCgttMgcgOverride {
	struct {
		uint32 override: 32; // 0
	};
	uint32 val;
};

// RLC_CNTL
union RlcCntl {
	struct {
		uint32 rlcEnableF32: 1; // 0
		uint32 forceRetry: 1; // 1
		uint32 readCacheDisable: 1; // 2
		uint32 rlcStepF32: 1; // 3
		uint32 softResetDebugMode: 1; // 4
		uint32 unknown1: 3;
		uint32 reserved: 24; // 8
	};
	uint32 val;
};

// RLC_CU_STATUS
union RlcCuStatus {
	struct {
		uint32 workPending: 32; // 0
	};
	uint32 val;
};

// RLC_DEBUG
union RlcDebug {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// RLC_DEBUG_SELECT
union RlcDebugSelect {
	struct {
		uint32 select: 8; // 0
		uint32 unknown1: 7;
		uint32 reserved: 17; // 15
	};
	uint32 val;
};

// RLC_DRIVER_CPDMA_STATUS
union RlcDriverCpdmaStatus {
	struct {
		uint32 driverRequest: 1; // 0
		uint32 reserved1: 3; // 1
		uint32 driverAck: 1; // 4
		uint32 reserved: 27; // 5
	};
	uint32 val;
};

// RLC_DYN_PG_REQUEST
union RlcDynPgRequest {
	struct {
		uint32 pgRequestCuMask: 32; // 0
	};
	uint32 val;
};

// RLC_DYN_PG_STATUS
union RlcDynPgStatus {
	struct {
		uint32 pgStatusCuMask: 32; // 0
	};
	uint32 val;
};

// RLC_GPM_SCRATCH_ADDR
union RlcGpmScratchAddr {
	struct {
		uint32 addr: 9; // 0
		uint32 reserved: 23; // 9
	};
	uint32 val;
};

// RLC_GPU_CLOCK_32
union RlcGpuClock32 {
	struct {
		uint32 gpuClock32: 32; // 0
	};
	uint32 val;
};

// RLC_GPU_CLOCK_32_RES_SEL
union RlcGpuClock32ResSel {
	struct {
		uint32 resSel: 6; // 0
		uint32 reserved: 26; // 6
	};
	uint32 val;
};

// RLC_GPU_CLOCK_COUNT_LSB
union RlcGpuClockCountLsb {
	struct {
		uint32 gpuClocksLsb: 32; // 0
	};
	uint32 val;
};

// RLC_GPU_CLOCK_COUNT_MSB
union RlcGpuClockCountMsb {
	struct {
		uint32 gpuClocksMsb: 32; // 0
	};
	uint32 val;
};

// RLC_LB_ALWAYS_ACTIVE_CU_MASK
union RlcLbAlwaysActiveCuMask {
	struct {
		uint32 alwaysActiveCuMask: 32; // 0
	};
	uint32 val;
};

// RLC_LB_CNTL
union RlcLbCntl {
	struct {
		uint32 loadBalanceEnable: 1; // 0
		uint32 lbCntCpBusy: 1; // 1
		uint32 lbCntSpimActive: 1; // 2
		uint32 lbCntRegInc: 1; // 3
		uint32 cuMaskUsedOffHyst: 8; // 4
		uint32 unknown1: 20;
	};
	uint32 val;
};

// RLC_LB_CNTR_INIT
union RlcLbCntrInit {
	struct {
		uint32 lbCntrInit: 32; // 0
	};
	uint32 val;
};

// RLC_LB_CNTR_MAX
union RlcLbCntrMax {
	struct {
		uint32 lbCntrMax: 32; // 0
	};
	uint32 val;
};

// RLC_LB_INIT_CU_MASK
union RlcLbInitCuMask {
	struct {
		uint32 initCuMask: 32; // 0
	};
	uint32 val;
};

// RLC_LB_PARAMS
union RlcLbParams {
	struct {
		uint32 skipL2Check: 1; // 0
		uint32 fifoSamples: 7; // 1
		uint32 pgIdleSamples: 8; // 8
		uint32 pgIdleSampleInterval: 16; // 16
	};
	uint32 val;
};

// RLC_LOAD_BALANCE_CNTR
union RlcLoadBalanceCntr {
	struct {
		uint32 rlcLoadBalanceCntr: 32; // 0
	};
	uint32 val;
};

// RLC_MAX_PG_CU
union RlcMaxPgCu {
	struct {
		uint32 maxPoweredUpCu: 8; // 0
		uint32 spare: 24; // 8
	};
	uint32 val;
};

// RLC_MC_CNTL
union RlcMcCntl {
	struct {
		uint32 wrreqSwap: 2; // 0
		uint32 wrreqTran: 1; // 2
		uint32 wrreqPriv: 1; // 3
		uint32 wrnfoStall: 1; // 4
		uint32 wrnfoUrg: 4; // 5
		uint32 wrreqDwImask: 4; // 9
		uint32 reservedB: 7; // 13
		uint32 rdnfoUrg: 4; // 20
		uint32 rdreqSwap: 2; // 24
		uint32 rdreqTran: 1; // 26
		uint32 rdreqPriv: 1; // 27
		uint32 rdnfoStall: 1; // 28
		uint32 reserved: 3; // 29
	};
	uint32 val;
};

// RLC_MEM_SLP_CNTL
union RlcMemSlpCntl {
	struct {
		uint32 rlcMemLsEn: 1; // 0
		uint32 rlcMemDsEn: 1; // 1
		uint32 reserved: 6; // 2
		uint32 rlcMemLsOnDelay: 8; // 8
		uint32 rlcMemLsOffDelay: 8; // 16
		uint32 reserved1: 8; // 24
	};
	uint32 val;
};

// RLC_PERFCOUNTER0_HI
union RlcPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// RLC_PERFCOUNTER0_LO
union RlcPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// RLC_PERFCOUNTER0_SELECT
union RlcPerfcounter0Select {
	struct {
		uint32 perfcounterSelect: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// RLC_PERFCOUNTER1_HI
union RlcPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// RLC_PERFCOUNTER1_LO
union RlcPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// RLC_PERFCOUNTER1_SELECT
union RlcPerfcounter1Select {
	struct {
		uint32 perfcounterSelect: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// RLC_PERFMON_CNTL
union RlcPerfmonCntl {
	struct {
		uint32 perfmonState: 3; // 0
		uint32 unknown1: 7;
		uint32 perfmonSampleEnable: 1; // 10
		uint32 unknown2: 21;
	};
	uint32 val;
};

// RLC_PG_ALWAYS_ON_CU_MASK
union RlcPgAlwaysOnCuMask {
	struct {
		uint32 aonCuMask: 32; // 0
	};
	uint32 val;
};

// RLC_PG_CNTL
union RlcPgCntl {
	struct {
		uint32 gfxPowerGatingEnable: 1; // 0
		uint32 gfxPowerGatingSrc: 1; // 1
		uint32 dynPerCuPgEnable: 1; // 2
		uint32 staticPerCuPgEnable: 1; // 3
		uint32 reserved: 28; // 4
		// uint32 unknown1: -16;
		// uint32 chubHandshakeEnable: 1;
		// uint32 unknown2: -15;
		// uint32 smuClkSlowdownOnPuEnable: 1;
		// uint32 unknown3: -14;
		// uint32 smuClkSlowdownOnPdEnable: 1;
		// uint32 unknown4: -13;
		// uint32 reserved1: 5;
		// uint32 unknown5: -8;
		// uint32 pgErrorStatus: 8;
	};
	uint32 val;
};

// RLC_SAVE_AND_RESTORE_BASE
union RlcSaveAndRestoreBase {
	struct {
		uint32 base: 32; // 0
	};
	uint32 val;
};

// RLC_SERDES_RD_DATA_0
union RlcSerdesRdData0 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// RLC_SERDES_RD_DATA_1
union RlcSerdesRdData1 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// RLC_SERDES_RD_DATA_2
union RlcSerdesRdData2 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// RLC_SERDES_RD_MASTER_INDEX
union RlcSerdesRdMasterIndex {
	struct {
		uint32 cuId: 4; // 0
		uint32 shId: 2; // 4
		uint32 seId: 3; // 6
		uint32 seNoncuId: 1; // 9
		uint32 seNoncu: 1; // 10
		uint32 nonSe: 3; // 11
		uint32 dataRegId: 2; // 14
		uint32 unknown1: 16;
	};
	uint32 val;
};

// RLC_SERDES_WR_CTRL
union RlcSerdesWrCtrl {
	struct {
		uint32 bpmAddr: 8; // 0
		uint32 powerDown: 1; // 8
		uint32 powerUp: 1; // 9
		uint32 p1Select: 1; // 10
		uint32 p2Select: 1; // 11
		uint32 writeCommand: 1; // 12
		uint32 readCommand: 1; // 13
		uint32 reserved1: 2; // 14
		uint32 cglsEnable: 1; // 16
		uint32 cglsDisable: 1; // 17
		uint32 cglsOn: 1; // 18
		uint32 cglsOff: 1; // 19
		uint32 cgcgOverride0: 1; // 20
		uint32 cgcgOverride1: 1; // 21
		uint32 mgcgOverride0: 1; // 22
		uint32 mgcgOverride1: 1; // 23
		uint32 reserved2: 4; // 24
		uint32 regAddr: 4; // 28
	};
	uint32 val;
};

// RLC_SERDES_WR_DATA
union RlcSerdesWrData {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// RLC_SMU_GRBM_REG_SAVE_CTRL
union RlcSmuGrbmRegSaveCtrl {
	struct {
		uint32 startGrbmRegSave: 1; // 0
		uint32 spare: 31; // 1
	};
	uint32 val;
};

// RLC_SMU_PG_CTRL
union RlcSmuPgCtrl {
	struct {
		uint32 startPg: 1; // 0
		uint32 spare: 31; // 1
	};
	uint32 val;
};

// RLC_SMU_PG_WAKE_UP_CTRL
union RlcSmuPgWakeUpCtrl {
	struct {
		uint32 startPgWakeUp: 1; // 0
		uint32 spare: 31; // 1
	};
	uint32 val;
};

// RLC_SOFT_RESET_GPU
union RlcSoftResetGpu {
	struct {
		uint32 softResetGpu: 1; // 0
		uint32 reserved: 31; // 1
	};
	uint32 val;
};

// RLC_STAT
union RlcStat {
	struct {
		uint32 rlcBusy: 1; // 0
		uint32 rlcGpmBusy: 1; // 1
		uint32 rlcSpmBusy: 1; // 2
		uint32 unknown1: 1;
		uint32 reserved: 28; // 4
	};
	uint32 val;
};

// RLC_STATIC_PG_STATUS
union RlcStaticPgStatus {
	struct {
		uint32 pgStatusCuMask: 32; // 0
	};
	uint32 val;
};

// RLC_THREAD1_DELAY
union RlcThread1Delay {
	struct {
		uint32 cuIdelDelay: 8; // 0
		uint32 lbpwInnerLoopDelay: 8; // 8
		uint32 lbpwOuterLoopDelay: 8; // 16
		uint32 spare: 8; // 24
	};
	uint32 val;
};

// RLC_UCODE_CNTL
union RlcUcodeCntl {
	struct {
		uint32 rlcUcodeFlags: 32; // 0
	};
	uint32 val;
};

// SCRATCH_ADDR
union ScratchAddr {
	struct {
		uint32 obsoleteAddr: 32; // 0
	};
	uint32 val;
};

// SCRATCH_REG0
union ScratchReg0 {
	struct {
		uint32 scratchReg0: 32; // 0
	};
	uint32 val;
};

// SCRATCH_REG1
union ScratchReg1 {
	struct {
		uint32 scratchReg1: 32; // 0
	};
	uint32 val;
};

// SCRATCH_REG2
union ScratchReg2 {
	struct {
		uint32 scratchReg2: 32; // 0
	};
	uint32 val;
};

// SCRATCH_REG3
union ScratchReg3 {
	struct {
		uint32 scratchReg3: 32; // 0
	};
	uint32 val;
};

// SCRATCH_REG4
union ScratchReg4 {
	struct {
		uint32 scratchReg4: 32; // 0
	};
	uint32 val;
};

// SCRATCH_REG5
union ScratchReg5 {
	struct {
		uint32 scratchReg5: 32; // 0
	};
	uint32 val;
};

// SCRATCH_REG6
union ScratchReg6 {
	struct {
		uint32 scratchReg6: 32; // 0
	};
	uint32 val;
};

// SCRATCH_REG7
union ScratchReg7 {
	struct {
		uint32 scratchReg7: 32; // 0
	};
	uint32 val;
};

// SCRATCH_UMSK
union ScratchUmsk {
	struct {
		uint32 obsoleteUmsk: 8; // 0
		uint32 unknown1: 8;
		uint32 obsoleteSwap: 2; // 16
		uint32 unknown2: 14;
	};
	uint32 val;
};

// SETUP_DEBUG_REG0
union SetupDebugReg0 {
	struct {
		uint32 suBarycCntlState: 2; // 0
		uint32 suCntlState: 4; // 2
		uint32 unknown1: 2;
		uint32 pmodeState: 6; // 8
		uint32 geStallb: 1; // 14
		uint32 geomEnable: 1; // 15
		uint32 suClipBarycFree: 2; // 16
		uint32 suClipRtr: 1; // 18
		uint32 pfifoBusy: 1; // 19
		uint32 suCntlBusy: 1; // 20
		uint32 geomBusy: 1; // 21
		uint32 eventIdGated: 6; // 22
		uint32 eventGated: 1; // 28
		uint32 pmodePrimGated: 1; // 29
		uint32 suDynSclkVld: 1; // 30
		uint32 clDynSclkVld: 1; // 31
	};
	uint32 val;
};

// SETUP_DEBUG_REG1
union SetupDebugReg1 {
	struct {
		uint32 ySort0Gated23_8: 16; // 0
		uint32 xSort0Gated23_8: 16; // 16
	};
	uint32 val;
};

// SETUP_DEBUG_REG2
union SetupDebugReg2 {
	struct {
		uint32 ySort1Gated23_8: 16; // 0
		uint32 xSort1Gated23_8: 16; // 16
	};
	uint32 val;
};

// SETUP_DEBUG_REG3
union SetupDebugReg3 {
	struct {
		uint32 ySort2Gated23_8: 16; // 0
		uint32 xSort2Gated23_8: 16; // 16
	};
	uint32 val;
};

// SETUP_DEBUG_REG4
union SetupDebugReg4 {
	struct {
		uint32 attrIndxSort0Gated: 14; // 0
		uint32 nullPrimGated: 1; // 14
		uint32 backfacingGated: 1; // 15
		uint32 stIndxGated: 3; // 16
		uint32 clippedGated: 1; // 19
		uint32 deallocSlotGated: 3; // 20
		uint32 xmajorGated: 1; // 23
		uint32 diamondRuleGated: 2; // 24
		uint32 typeGated: 3; // 26
		uint32 fpovGated: 2; // 29
		uint32 eopGated: 1; // 31
	};
	uint32 val;
};

// SETUP_DEBUG_REG5
union SetupDebugReg5 {
	struct {
		uint32 attrIndxSort2Gated: 14; // 0
		uint32 attrIndxSort1Gated: 14; // 14
		uint32 provokingVtxGated: 2; // 28
		uint32 validPrimGated: 1; // 30
		uint32 paRegSclkVld: 1; // 31
	};
	uint32 val;
};

// SPI_ARB_CYCLES_0
union SpiArbCycles0 {
	struct {
		uint32 ts0Duration: 16; // 0
		uint32 ts1Duration: 16; // 16
	};
	uint32 val;
};

// SPI_ARB_CYCLES_1
union SpiArbCycles1 {
	struct {
		uint32 ts2Duration: 16; // 0
		uint32 ts3Duration: 16; // 16
	};
	uint32 val;
};

// SPI_ARB_PRIORITY
union SpiArbPriority {
	struct {
		uint32 pipeOrderTs0: 3; // 0
		uint32 pipeOrderTs1: 3; // 3
		uint32 pipeOrderTs2: 3; // 6
		uint32 pipeOrderTs3: 3; // 9
		uint32 ts0DurMult: 2; // 12
		uint32 ts1DurMult: 2; // 14
		uint32 ts2DurMult: 2; // 16
		uint32 ts3DurMult: 2; // 18
		uint32 unknown1: 12;
	};
	uint32 val;
};

// SPI_BARYC_CNTL
union SpiBarycCntl {
	struct {
		uint32 perspCenterCntl: 1; // 0
		uint32 unknown1: 3;
		uint32 perspCentroidCntl: 1; // 4
		uint32 unknown2: 3;
		uint32 linearCenterCntl: 1; // 8
		uint32 unknown3: 3;
		uint32 linearCentroidCntl: 1; // 12
		uint32 unknown4: 3;
		uint32 posFloatLocation: 2; // 16
		uint32 unknown5: 2;
		uint32 posFloatUlc: 1; // 20
		uint32 unknown6: 3;
		uint32 frontFaceAllBits: 1; // 24
		uint32 unknown7: 7;
	};
	uint32 val;
};

// SPI_CONFIG_CNTL
union SpiConfigCntl {
	struct {
		uint32 gprWritePriority: 21; // 0
		uint32 expPriorityOrder: 3; // 21
		uint32 enableSqgTopEvents: 1; // 24
		uint32 enableSqgBopEvents: 1; // 25
		uint32 rsrcMgmtReset: 1; // 26
		uint32 ttraceStallAll: 1; // 27
		uint32 unknown1: 4;
	};
	uint32 val;
};

// SPI_CONFIG_CNTL_1
union SpiConfigCntl1 {
	struct {
		uint32 vtxDoneDelay: 4; // 0
		uint32 interpOnePrimPerRow: 1; // 4
		uint32 unknown1: 1;
		uint32 pcLimitEnable: 1; // 6
		uint32 pcLimitStrict: 1; // 7
		uint32 crcSimdIdWaddrDisable: 1; // 8
		uint32 lbpwCuChkMode: 1; // 9
		uint32 lbpwCuChkCnt: 4; // 10
		uint32 unknown2: 2;
		uint32 pcLimitSize: 16; // 16
	};
	uint32 val;
};

// SPI_DEBUG_BUSY
union SpiDebugBusy {
	struct {
		uint32 lsBusy: 1; // 0
		uint32 hsBusy: 1; // 1
		uint32 esBusy: 1; // 2
		uint32 gsBusy: 1; // 3
		uint32 vsBusy: 1; // 4
		uint32 ps0Busy: 1; // 5
		uint32 ps1Busy: 1; // 6
		uint32 cs0Busy: 1; // 7
		uint32 cs1Busy: 1; // 8
		uint32 cs2Busy: 1; // 9
		uint32 ldsWrCtl0Busy: 1; // 10
		uint32 cs3Busy: 1; // 11
		uint32 cs4Busy: 1; // 12
		uint32 cs5Busy: 1; // 13
		uint32 cs6Busy: 1; // 14
		uint32 cs7Busy: 1; // 15
		uint32 grbmBusy: 1; // 16
		uint32 spisBusy: 1; // 17
		uint32 unknown1: 2;
		uint32 pcDeallocBusy: 1; // 20
		uint32 unknown2: 11;
	};
	uint32 val;
};

// SPI_DEBUG_CNTL
union SpiDebugCntl {
	struct {
		uint32 debugGrbmOverride: 1; // 0
		uint32 debugThreadTypeSel: 4; // 1
		uint32 debugGroupSel: 5; // 5
		uint32 debugSimdSel: 6; // 10
		uint32 debugShSel: 1; // 16
		uint32 spiEcoSpare0: 1; // 17
		uint32 spiEcoSpare1: 1; // 18
		uint32 spiEcoSpare2: 1; // 19
		uint32 spiEcoSpare3: 1; // 20
		uint32 spiEcoSpare4: 1; // 21
		uint32 spiEcoSpare5: 1; // 22
		uint32 spiEcoSpare6: 1; // 23
		uint32 spiEcoSpare7: 1; // 24
		uint32 debugPipeSel: 3; // 25
		uint32 unknown1: 3;
		uint32 debugRegEn: 1; // 31
	};
	uint32 val;
};

// SPI_DEBUG_READ
union SpiDebugRead {
	struct {
		uint32 data: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// SPI_GDS_CREDITS
union SpiGdsCredits {
	struct {
		uint32 dsDataCredits: 8; // 0
		uint32 dsCmdCredits: 8; // 8
		uint32 unused: 16; // 16
	};
	uint32 val;
};

// SPI_INTERP_CONTROL_0
union SpiInterpControl0 {
	struct {
		uint32 flatShadeEna: 1; // 0
		uint32 pntSpriteEna: 1; // 1
		uint32 pntSpriteOvrdX: 3; // 2
		uint32 pntSpriteOvrdY: 3; // 5
		uint32 pntSpriteOvrdZ: 3; // 8
		uint32 pntSpriteOvrdW: 3; // 11
		uint32 pntSpriteTop1: 1; // 14
		uint32 unknown1: 17;
	};
	uint32 val;
};

// SPI_LB_CTR_CTRL
union SpiLbCtrCtrl {
	struct {
		uint32 load: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// SPI_LB_CU_MASK
union SpiLbCuMask {
	struct {
		uint32 cuMask: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SPI_LB_DATA_REG
union SpiLbDataReg {
	struct {
		uint32 cntData: 32; // 0
	};
	uint32 val;
};

// SPI_PERFCOUNTER0_HI
union SpiPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SPI_PERFCOUNTER0_LO
union SpiPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SPI_PERFCOUNTER0_SELECT
union SpiPerfcounter0Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// SPI_PERFCOUNTER0_SELECT1
union SpiPerfcounter0Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 12;
	};
	uint32 val;
};

// SPI_PERFCOUNTER1_HI
union SpiPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SPI_PERFCOUNTER1_LO
union SpiPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SPI_PERFCOUNTER1_SELECT
union SpiPerfcounter1Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// SPI_PERFCOUNTER1_SELECT1
union SpiPerfcounter1Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 12;
	};
	uint32 val;
};

// SPI_PERFCOUNTER2_HI
union SpiPerfcounter2Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SPI_PERFCOUNTER2_LO
union SpiPerfcounter2Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SPI_PERFCOUNTER2_SELECT
union SpiPerfcounter2Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// SPI_PERFCOUNTER2_SELECT1
union SpiPerfcounter2Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 12;
	};
	uint32 val;
};

// SPI_PERFCOUNTER3_HI
union SpiPerfcounter3Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SPI_PERFCOUNTER3_LO
union SpiPerfcounter3Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SPI_PERFCOUNTER3_SELECT
union SpiPerfcounter3Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// SPI_PERFCOUNTER3_SELECT1
union SpiPerfcounter3Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 12;
	};
	uint32 val;
};

// SPI_PERFCOUNTER_BINS
union SpiPerfcounterBins {
	struct {
		uint32 bin0Min: 4; // 0
		uint32 bin0Max: 4; // 4
		uint32 bin1Min: 4; // 8
		uint32 bin1Max: 4; // 12
		uint32 bin2Min: 4; // 16
		uint32 bin2Max: 4; // 20
		uint32 bin3Min: 4; // 24
		uint32 bin3Max: 4; // 28
	};
	uint32 val;
};

// SPI_PG_ENABLE_STATIC_CU_MASK
union SpiPgEnableStaticCuMask {
	struct {
		uint32 cuMask: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SPI_PS_INPUT_ADDR
union SpiPsInputAddr {
	struct {
		uint32 perspSampleEna: 1; // 0
		uint32 perspCenterEna: 1; // 1
		uint32 perspCentroidEna: 1; // 2
		uint32 perspPullModelEna: 1; // 3
		uint32 linearSampleEna: 1; // 4
		uint32 linearCenterEna: 1; // 5
		uint32 linearCentroidEna: 1; // 6
		uint32 lineStippleTexEna: 1; // 7
		uint32 posXFloatEna: 1; // 8
		uint32 posYFloatEna: 1; // 9
		uint32 posZFloatEna: 1; // 10
		uint32 posWFloatEna: 1; // 11
		uint32 frontFaceEna: 1; // 12
		uint32 ancillaryEna: 1; // 13
		uint32 sampleCoverageEna: 1; // 14
		uint32 posFixedPtEna: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_0
union SpiPsInputCntl0 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_1
union SpiPsInputCntl1 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_10
union SpiPsInputCntl10 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_11
union SpiPsInputCntl11 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_12
union SpiPsInputCntl12 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_13
union SpiPsInputCntl13 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_14
union SpiPsInputCntl14 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_15
union SpiPsInputCntl15 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_16
union SpiPsInputCntl16 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_17
union SpiPsInputCntl17 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_18
union SpiPsInputCntl18 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_19
union SpiPsInputCntl19 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_2
union SpiPsInputCntl2 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_20
union SpiPsInputCntl20 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 7;
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_21
union SpiPsInputCntl21 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 7;
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_22
union SpiPsInputCntl22 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 7;
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_23
union SpiPsInputCntl23 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 7;
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_24
union SpiPsInputCntl24 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 7;
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_25
union SpiPsInputCntl25 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 7;
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_26
union SpiPsInputCntl26 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 7;
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_27
union SpiPsInputCntl27 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 7;
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_28
union SpiPsInputCntl28 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 7;
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_29
union SpiPsInputCntl29 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 7;
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_3
union SpiPsInputCntl3 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_30
union SpiPsInputCntl30 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 7;
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_31
union SpiPsInputCntl31 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 7;
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_4
union SpiPsInputCntl4 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_5
union SpiPsInputCntl5 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_6
union SpiPsInputCntl6 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_7
union SpiPsInputCntl7 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_8
union SpiPsInputCntl8 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_CNTL_9
union SpiPsInputCntl9 {
	struct {
		uint32 offset: 6; // 0
		uint32 unknown1: 2;
		uint32 defaultVal: 2; // 8
		uint32 flatShade: 1; // 10
		uint32 unknown2: 2;
		uint32 cylWrap: 4; // 13
		uint32 ptSpriteTex: 1; // 17
		uint32 dup: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// SPI_PS_INPUT_ENA
union SpiPsInputEna {
	struct {
		uint32 perspSampleEna: 1; // 0
		uint32 perspCenterEna: 1; // 1
		uint32 perspCentroidEna: 1; // 2
		uint32 perspPullModelEna: 1; // 3
		uint32 linearSampleEna: 1; // 4
		uint32 linearCenterEna: 1; // 5
		uint32 linearCentroidEna: 1; // 6
		uint32 lineStippleTexEna: 1; // 7
		uint32 posXFloatEna: 1; // 8
		uint32 posYFloatEna: 1; // 9
		uint32 posZFloatEna: 1; // 10
		uint32 posWFloatEna: 1; // 11
		uint32 frontFaceEna: 1; // 12
		uint32 ancillaryEna: 1; // 13
		uint32 sampleCoverageEna: 1; // 14
		uint32 posFixedPtEna: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SPI_PS_IN_CONTROL
union SpiPsInControl {
	struct {
		uint32 numInterp: 6; // 0
		uint32 paramGen: 1; // 6
		uint32 unknown1: 7;
		uint32 bcOptimizeDisable: 1; // 14
		uint32 unknown2: 17;
	};
	uint32 val;
};

// SPI_PS_MAX_WAVE_ID
union SpiPsMaxWaveId {
	struct {
		uint32 maxWaveId: 12; // 0
		uint32 unknown1: 20;
	};
	uint32 val;
};

// SPI_SHADER_COL_FORMAT
union SpiShaderColFormat {
	struct {
		uint32 col0ExportFormat: 4; // 0
		uint32 col1ExportFormat: 4; // 4
		uint32 col2ExportFormat: 4; // 8
		uint32 col3ExportFormat: 4; // 12
		uint32 col4ExportFormat: 4; // 16
		uint32 col5ExportFormat: 4; // 20
		uint32 col6ExportFormat: 4; // 24
		uint32 col7ExportFormat: 4; // 28
	};
	uint32 val;
};

// SPI_SHADER_PGM_HI_ES
union SpiShaderPgmHiEs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_PGM_HI_GS
union SpiShaderPgmHiGs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_PGM_HI_HS
union SpiShaderPgmHiHs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_PGM_HI_LS
union SpiShaderPgmHiLs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_PGM_HI_PS
union SpiShaderPgmHiPs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_PGM_HI_VS
union SpiShaderPgmHiVs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_PGM_LO_ES
union SpiShaderPgmLoEs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_PGM_LO_GS
union SpiShaderPgmLoGs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_PGM_LO_HS
union SpiShaderPgmLoHs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_PGM_LO_LS
union SpiShaderPgmLoLs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_PGM_LO_PS
union SpiShaderPgmLoPs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_PGM_LO_VS
union SpiShaderPgmLoVs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC1_ES
union SpiShaderPgmRsrc1Es {
	struct {
		uint32 vgprs: 6; // 0
		uint32 sgprs: 4; // 6
		uint32 priority: 2; // 10
		uint32 floatMode: 8; // 12
		uint32 priv: 1; // 20
		uint32 dx10Clamp: 1; // 21
		uint32 debugMode: 1; // 22
		uint32 ieeeMode: 1; // 23
		uint32 vgprCompCnt: 2; // 24
		uint32 cuGroupEnable: 1; // 26
		uint32 cacheCtl: 3; // 27
		uint32 cdbgUser: 1; // 30
		uint32 unknown1: 1;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC1_GS
union SpiShaderPgmRsrc1Gs {
	struct {
		uint32 vgprs: 6; // 0
		uint32 sgprs: 4; // 6
		uint32 priority: 2; // 10
		uint32 floatMode: 8; // 12
		uint32 priv: 1; // 20
		uint32 dx10Clamp: 1; // 21
		uint32 debugMode: 1; // 22
		uint32 ieeeMode: 1; // 23
		uint32 cuGroupEnable: 1; // 24
		uint32 cacheCtl: 3; // 25
		uint32 cdbgUser: 1; // 28
		uint32 unknown1: 3;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC1_HS
union SpiShaderPgmRsrc1Hs {
	struct {
		uint32 vgprs: 6; // 0
		uint32 sgprs: 4; // 6
		uint32 priority: 2; // 10
		uint32 floatMode: 8; // 12
		uint32 priv: 1; // 20
		uint32 dx10Clamp: 1; // 21
		uint32 debugMode: 1; // 22
		uint32 ieeeMode: 1; // 23
		uint32 cacheCtl: 3; // 24
		uint32 cdbgUser: 1; // 27
		uint32 unknown1: 4;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC1_LS
union SpiShaderPgmRsrc1Ls {
	struct {
		uint32 vgprs: 6; // 0
		uint32 sgprs: 4; // 6
		uint32 priority: 2; // 10
		uint32 floatMode: 8; // 12
		uint32 priv: 1; // 20
		uint32 dx10Clamp: 1; // 21
		uint32 debugMode: 1; // 22
		uint32 ieeeMode: 1; // 23
		uint32 vgprCompCnt: 2; // 24
		uint32 cacheCtl: 3; // 26
		uint32 cdbgUser: 1; // 29
		uint32 unknown1: 2;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC1_PS
union SpiShaderPgmRsrc1Ps {
	struct {
		uint32 vgprs: 6; // 0
		uint32 sgprs: 4; // 6
		uint32 priority: 2; // 10
		uint32 floatMode: 8; // 12
		uint32 priv: 1; // 20
		uint32 dx10Clamp: 1; // 21
		uint32 debugMode: 1; // 22
		uint32 ieeeMode: 1; // 23
		uint32 cuGroupDisable: 1; // 24
		uint32 cacheCtl: 3; // 25
		uint32 cdbgUser: 1; // 28
		uint32 unknown1: 3;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC1_VS
union SpiShaderPgmRsrc1Vs {
	struct {
		uint32 vgprs: 6; // 0
		uint32 sgprs: 4; // 6
		uint32 priority: 2; // 10
		uint32 floatMode: 8; // 12
		uint32 priv: 1; // 20
		uint32 dx10Clamp: 1; // 21
		uint32 debugMode: 1; // 22
		uint32 ieeeMode: 1; // 23
		uint32 vgprCompCnt: 2; // 24
		uint32 cuGroupEnable: 1; // 26
		uint32 cacheCtl: 3; // 27
		uint32 cdbgUser: 1; // 30
		uint32 unknown1: 1;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC2_ES
union SpiShaderPgmRsrc2Es {
	struct {
		uint32 scratchEn: 1; // 0
		uint32 userSgpr: 5; // 1
		uint32 trapPresent: 1; // 6
		uint32 ocLdsEn: 1; // 7
		uint32 excpEn: 7; // 8
		uint32 unknown1: 5;
		uint32 ldsSize: 9; // 20
		uint32 unknown2: 3;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC2_ES_GS
union SpiShaderPgmRsrc2EsGs {
	struct {
		uint32 scratchEn: 1; // 0
		uint32 userSgpr: 5; // 1
		uint32 trapPresent: 1; // 6
		uint32 ocLdsEn: 1; // 7
		uint32 excpEn: 9; // 8
		uint32 unknown1: 3;
		uint32 ldsSize: 9; // 20
		uint32 unknown2: 3;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC2_ES_VS
union SpiShaderPgmRsrc2EsVs {
	struct {
		uint32 scratchEn: 1; // 0
		uint32 userSgpr: 5; // 1
		uint32 trapPresent: 1; // 6
		uint32 ocLdsEn: 1; // 7
		uint32 excpEn: 9; // 8
		uint32 unknown1: 3;
		uint32 ldsSize: 9; // 20
		uint32 unknown2: 3;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC2_GS
union SpiShaderPgmRsrc2Gs {
	struct {
		uint32 scratchEn: 1; // 0
		uint32 userSgpr: 5; // 1
		uint32 trapPresent: 1; // 6
		uint32 excpEn: 7; // 7
		uint32 unknown1: 18;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC2_HS
union SpiShaderPgmRsrc2Hs {
	struct {
		uint32 scratchEn: 1; // 0
		uint32 userSgpr: 5; // 1
		uint32 trapPresent: 1; // 6
		uint32 ocLdsEn: 1; // 7
		uint32 tgSizeEn: 1; // 8
		uint32 excpEn: 7; // 9
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC2_LS
union SpiShaderPgmRsrc2Ls {
	struct {
		uint32 scratchEn: 1; // 0
		uint32 userSgpr: 5; // 1
		uint32 trapPresent: 1; // 6
		uint32 ldsSize: 9; // 7
		uint32 excpEn: 7; // 16
		uint32 unknown1: 9;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC2_LS_ES
union SpiShaderPgmRsrc2LsEs {
	struct {
		uint32 scratchEn: 1; // 0
		uint32 userSgpr: 5; // 1
		uint32 trapPresent: 1; // 6
		uint32 ldsSize: 9; // 7
		uint32 excpEn: 9; // 16
		uint32 unknown1: 7;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC2_LS_HS
union SpiShaderPgmRsrc2LsHs {
	struct {
		uint32 scratchEn: 1; // 0
		uint32 userSgpr: 5; // 1
		uint32 trapPresent: 1; // 6
		uint32 ldsSize: 9; // 7
		uint32 excpEn: 9; // 16
		uint32 unknown1: 7;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC2_LS_VS
union SpiShaderPgmRsrc2LsVs {
	struct {
		uint32 scratchEn: 1; // 0
		uint32 userSgpr: 5; // 1
		uint32 trapPresent: 1; // 6
		uint32 ldsSize: 9; // 7
		uint32 excpEn: 9; // 16
		uint32 unknown1: 7;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC2_PS
union SpiShaderPgmRsrc2Ps {
	struct {
		uint32 scratchEn: 1; // 0
		uint32 userSgpr: 5; // 1
		uint32 trapPresent: 1; // 6
		uint32 waveCntEn: 1; // 7
		uint32 extraLdsSize: 8; // 8
		uint32 excpEn: 7; // 16
		uint32 unknown1: 9;
	};
	uint32 val;
};

// SPI_SHADER_PGM_RSRC2_VS
union SpiShaderPgmRsrc2Vs {
	struct {
		uint32 scratchEn: 1; // 0
		uint32 userSgpr: 5; // 1
		uint32 trapPresent: 1; // 6
		uint32 ocLdsEn: 1; // 7
		uint32 soBase0En: 1; // 8
		uint32 soBase1En: 1; // 9
		uint32 soBase2En: 1; // 10
		uint32 soBase3En: 1; // 11
		uint32 soEn: 1; // 12
		uint32 excpEn: 7; // 13
		uint32 unknown1: 12;
	};
	uint32 val;
};

// SPI_SHADER_POS_FORMAT
union SpiShaderPosFormat {
	struct {
		uint32 pos0ExportFormat: 4; // 0
		uint32 pos1ExportFormat: 4; // 4
		uint32 pos2ExportFormat: 4; // 8
		uint32 pos3ExportFormat: 4; // 12
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SPI_SHADER_TBA_HI_ES
union SpiShaderTbaHiEs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_TBA_HI_GS
union SpiShaderTbaHiGs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_TBA_HI_HS
union SpiShaderTbaHiHs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_TBA_HI_LS
union SpiShaderTbaHiLs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_TBA_HI_PS
union SpiShaderTbaHiPs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_TBA_HI_VS
union SpiShaderTbaHiVs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_TBA_LO_ES
union SpiShaderTbaLoEs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_TBA_LO_GS
union SpiShaderTbaLoGs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_TBA_LO_HS
union SpiShaderTbaLoHs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_TBA_LO_LS
union SpiShaderTbaLoLs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_TBA_LO_PS
union SpiShaderTbaLoPs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_TBA_LO_VS
union SpiShaderTbaLoVs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_TMA_HI_ES
union SpiShaderTmaHiEs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_TMA_HI_GS
union SpiShaderTmaHiGs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_TMA_HI_HS
union SpiShaderTmaHiHs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_TMA_HI_LS
union SpiShaderTmaHiLs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_TMA_HI_PS
union SpiShaderTmaHiPs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_TMA_HI_VS
union SpiShaderTmaHiVs {
	struct {
		uint32 memBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SPI_SHADER_TMA_LO_ES
union SpiShaderTmaLoEs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_TMA_LO_GS
union SpiShaderTmaLoGs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_TMA_LO_HS
union SpiShaderTmaLoHs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_TMA_LO_LS
union SpiShaderTmaLoLs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_TMA_LO_PS
union SpiShaderTmaLoPs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_TMA_LO_VS
union SpiShaderTmaLoVs {
	struct {
		uint32 memBase: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_0
union SpiShaderUserDataEs0 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_1
union SpiShaderUserDataEs1 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_10
union SpiShaderUserDataEs10 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_11
union SpiShaderUserDataEs11 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_12
union SpiShaderUserDataEs12 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_13
union SpiShaderUserDataEs13 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_14
union SpiShaderUserDataEs14 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_15
union SpiShaderUserDataEs15 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_2
union SpiShaderUserDataEs2 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_3
union SpiShaderUserDataEs3 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_4
union SpiShaderUserDataEs4 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_5
union SpiShaderUserDataEs5 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_6
union SpiShaderUserDataEs6 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_7
union SpiShaderUserDataEs7 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_8
union SpiShaderUserDataEs8 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_ES_9
union SpiShaderUserDataEs9 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_0
union SpiShaderUserDataGs0 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_1
union SpiShaderUserDataGs1 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_10
union SpiShaderUserDataGs10 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_11
union SpiShaderUserDataGs11 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_12
union SpiShaderUserDataGs12 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_13
union SpiShaderUserDataGs13 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_14
union SpiShaderUserDataGs14 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_15
union SpiShaderUserDataGs15 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_2
union SpiShaderUserDataGs2 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_3
union SpiShaderUserDataGs3 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_4
union SpiShaderUserDataGs4 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_5
union SpiShaderUserDataGs5 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_6
union SpiShaderUserDataGs6 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_7
union SpiShaderUserDataGs7 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_8
union SpiShaderUserDataGs8 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_GS_9
union SpiShaderUserDataGs9 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_0
union SpiShaderUserDataHs0 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_1
union SpiShaderUserDataHs1 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_10
union SpiShaderUserDataHs10 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_11
union SpiShaderUserDataHs11 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_12
union SpiShaderUserDataHs12 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_13
union SpiShaderUserDataHs13 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_14
union SpiShaderUserDataHs14 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_15
union SpiShaderUserDataHs15 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_2
union SpiShaderUserDataHs2 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_3
union SpiShaderUserDataHs3 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_4
union SpiShaderUserDataHs4 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_5
union SpiShaderUserDataHs5 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_6
union SpiShaderUserDataHs6 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_7
union SpiShaderUserDataHs7 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_8
union SpiShaderUserDataHs8 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_HS_9
union SpiShaderUserDataHs9 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_0
union SpiShaderUserDataLs0 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_1
union SpiShaderUserDataLs1 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_10
union SpiShaderUserDataLs10 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_11
union SpiShaderUserDataLs11 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_12
union SpiShaderUserDataLs12 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_13
union SpiShaderUserDataLs13 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_14
union SpiShaderUserDataLs14 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_15
union SpiShaderUserDataLs15 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_2
union SpiShaderUserDataLs2 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_3
union SpiShaderUserDataLs3 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_4
union SpiShaderUserDataLs4 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_5
union SpiShaderUserDataLs5 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_6
union SpiShaderUserDataLs6 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_7
union SpiShaderUserDataLs7 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_8
union SpiShaderUserDataLs8 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_LS_9
union SpiShaderUserDataLs9 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_0
union SpiShaderUserDataPs0 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_1
union SpiShaderUserDataPs1 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_10
union SpiShaderUserDataPs10 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_11
union SpiShaderUserDataPs11 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_12
union SpiShaderUserDataPs12 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_13
union SpiShaderUserDataPs13 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_14
union SpiShaderUserDataPs14 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_15
union SpiShaderUserDataPs15 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_2
union SpiShaderUserDataPs2 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_3
union SpiShaderUserDataPs3 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_4
union SpiShaderUserDataPs4 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_5
union SpiShaderUserDataPs5 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_6
union SpiShaderUserDataPs6 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_7
union SpiShaderUserDataPs7 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_8
union SpiShaderUserDataPs8 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_PS_9
union SpiShaderUserDataPs9 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_0
union SpiShaderUserDataVs0 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_1
union SpiShaderUserDataVs1 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_10
union SpiShaderUserDataVs10 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_11
union SpiShaderUserDataVs11 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_12
union SpiShaderUserDataVs12 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_13
union SpiShaderUserDataVs13 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_14
union SpiShaderUserDataVs14 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_15
union SpiShaderUserDataVs15 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_2
union SpiShaderUserDataVs2 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_3
union SpiShaderUserDataVs3 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_4
union SpiShaderUserDataVs4 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_5
union SpiShaderUserDataVs5 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_6
union SpiShaderUserDataVs6 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_7
union SpiShaderUserDataVs7 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_8
union SpiShaderUserDataVs8 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_USER_DATA_VS_9
union SpiShaderUserDataVs9 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SPI_SHADER_Z_FORMAT
union SpiShaderZFormat {
	struct {
		uint32 zExportFormat: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// SPI_SLAVE_DEBUG_BUSY
union SpiSlaveDebugBusy {
	struct {
		uint32 lsVtxBusy: 1; // 0
		uint32 hsVtxBusy: 1; // 1
		uint32 esVtxBusy: 1; // 2
		uint32 gsVtxBusy: 1; // 3
		uint32 vsVtxBusy: 1; // 4
		uint32 vgprWc00Busy: 1; // 5
		uint32 vgprWc01Busy: 1; // 6
		uint32 vgprWc10Busy: 1; // 7
		uint32 vgprWc11Busy: 1; // 8
		uint32 sgprWc00Busy: 1; // 9
		uint32 sgprWc01Busy: 1; // 10
		uint32 sgprWc02Busy: 1; // 11
		uint32 sgprWc03Busy: 1; // 12
		uint32 sgprWc10Busy: 1; // 13
		uint32 sgprWc11Busy: 1; // 14
		uint32 sgprWc12Busy: 1; // 15
		uint32 sgprWc13Busy: 1; // 16
		uint32 wavebuffer0Busy: 1; // 17
		uint32 wavebuffer1Busy: 1; // 18
		uint32 waveWc0Busy: 1; // 19
		uint32 waveWc1Busy: 1; // 20
		uint32 eventCntlBusy: 1; // 21
		uint32 unknown1: 10;
	};
	uint32 val;
};

// SPI_SX_EXPORT_BUFFER_SIZES
union SpiSxExportBufferSizes {
	struct {
		uint32 colorBufferSize: 16; // 0
		uint32 positionBufferSize: 16; // 16
	};
	uint32 val;
};

// SPI_SX_SCOREBOARD_BUFFER_SIZES
union SpiSxScoreboardBufferSizes {
	struct {
		uint32 colorScoreboardSize: 16; // 0
		uint32 positionScoreboardSize: 16; // 16
	};
	uint32 val;
};

// SPI_TMPRING_SIZE
union SpiTmpringSize {
	struct {
		uint32 waves: 12; // 0
		uint32 wavesize: 13; // 12
		uint32 unknown1: 7;
	};
	uint32 val;
};

// SPI_VS_OUT_CONFIG
union SpiVsOutConfig {
	struct {
		uint32 unknown1: 1;
		uint32 vsExportCount: 5; // 1
		uint32 vsHalfPack: 1; // 6
		uint32 unknown2: 25;
	};
	uint32 val;
};

// SQC_CACHES
union SqcCaches {
	struct {
		uint32 instInvalidate: 1; // 0
		uint32 dataInvalidate: 1; // 1
		uint32 invalidateVolatile: 1; // 2
		uint32 unknown1: 29;
	};
	uint32 val;
};

// SQC_CONFIG
union SqcConfig {
	struct {
		uint32 instCacheSize: 2; // 0
		uint32 dataCacheSize: 2; // 2
		uint32 missFifoDepth: 2; // 4
		uint32 hitFifoDepth: 1; // 6
		uint32 forceAlwaysMiss: 1; // 7
		uint32 forceInOrder: 1; // 8
		uint32 identityHashBank: 1; // 9
		uint32 identityHashSet: 1; // 10
		uint32 perVmidInvDisable: 1; // 11
		uint32 unknown1: 20;
	};
	uint32 val;
};

// SQC_SECDED_CNT
union SqcSecdedCnt {
	struct {
		uint32 instSec: 8; // 0
		uint32 instDed: 8; // 8
		uint32 dataSec: 8; // 16
		uint32 dataDed: 8; // 24
	};
	uint32 val;
};

// SQ_ALU_CLK_CTRL
union SqAluClkCtrl {
	struct {
		uint32 forceCuOnSh0: 16; // 0
		uint32 forceCuOnSh1: 16; // 16
	};
	uint32 val;
};

// SQ_BUF_RSRC_WORD0
union SqBufRsrcWord0 {
	struct {
		uint32 baseAddress: 32; // 0
	};
	uint32 val;
};

// SQ_BUF_RSRC_WORD1
union SqBufRsrcWord1 {
	struct {
		uint32 baseAddressHi: 16; // 0
		uint32 stride: 14; // 16
		uint32 cacheSwizzle: 1; // 30
		uint32 swizzleEnable: 1; // 31
	};
	uint32 val;
};

// SQ_BUF_RSRC_WORD2
union SqBufRsrcWord2 {
	struct {
		uint32 numRecords: 32; // 0
	};
	uint32 val;
};

// SQ_BUF_RSRC_WORD3
union SqBufRsrcWord3 {
	struct {
		uint32 dstSelX: 3; // 0
		uint32 dstSelY: 3; // 3
		uint32 dstSelZ: 3; // 6
		uint32 dstSelW: 3; // 9
		uint32 numFormat: 3; // 12
		uint32 dataFormat: 4; // 15
		uint32 elementSize: 2; // 19
		uint32 indexStride: 2; // 21
		uint32 addTidEnable: 1; // 23
		uint32 atc: 1; // 24
		uint32 hashEnable: 1; // 25
		uint32 heap: 1; // 26
		uint32 mtype: 3; // 27
		uint32 type: 2; // 30
	};
	uint32 val;
};

// SQ_CONFIG
union SqConfig {
	struct {
		uint32 unused: 8; // 0
		uint32 debugEn: 1; // 8
		uint32 disableScaBypass: 1; // 9
		uint32 disableIbDepCheck: 1; // 10
		uint32 enableSoftClause: 1; // 11
		uint32 earlyTaDoneDisable: 1; // 12
		uint32 duaFlatLockEnable: 1; // 13
		uint32 duaLdsBypassDisable: 1; // 14
		uint32 duaFlatLdsPingpongDisable: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SQ_DEBUG_CTRL_LOCAL
union SqDebugCtrlLocal {
	struct {
		uint32 unused: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SQ_DEBUG_STS_GLOBAL
union SqDebugStsGlobal {
	struct {
		uint32 busy: 1; // 0
		uint32 interruptMsgBusy: 1; // 1
		uint32 unknown1: 2;
		uint32 waveLevelSh0: 12; // 4
		uint32 waveLevelSh1: 12; // 16
		uint32 unknown2: 4;
	};
	uint32 val;
};

// SQ_DEBUG_STS_GLOBAL2
union SqDebugStsGlobal2 {
	struct {
		uint32 fifoLevelGfx0: 8; // 0
		uint32 fifoLevelGfx1: 8; // 8
		uint32 fifoLevelImmed: 8; // 16
		uint32 fifoLevelHost: 8; // 24
	};
	uint32 val;
};

// SQ_DEBUG_STS_GLOBAL3
union SqDebugStsGlobal3 {
	struct {
		uint32 fifoLevelHostCmd: 4; // 0
		uint32 fifoLevelHostReg: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SQ_DEBUG_STS_LOCAL
union SqDebugStsLocal {
	struct {
		uint32 busy: 1; // 0
		uint32 unknown1: 3;
		uint32 waveLevel: 6; // 4
		uint32 unknown2: 22;
	};
	uint32 val;
};

// SQ_DED_CNT
union SqDedCnt {
	struct {
		uint32 ldsDed: 6; // 0
		uint32 unknown1: 2;
		uint32 sgprDed: 5; // 8
		uint32 unknown2: 3;
		uint32 vgprDed: 9; // 16
		uint32 unknown3: 7;
	};
	uint32 val;
};

// SQ_DED_INFO
union SqDedInfo {
	struct {
		uint32 waveId: 4; // 0
		uint32 simdId: 2; // 4
		uint32 source: 3; // 6
		uint32 vmId: 4; // 9
		uint32 unknown1: 19;
	};
	uint32 val;
};

// SQ_DS_0
union SqDs0 {
	struct {
		uint32 offset0: 8; // 0
		uint32 offset1: 8; // 8
		uint32 unknown1: 1;
		uint32 gds: 1; // 17
		uint32 op: 8; // 18
		uint32 encoding: 6; // 26
	};
	uint32 val;
};

// SQ_DS_1
union SqDs1 {
	struct {
		uint32 addr: 8; // 0
		uint32 data0: 8; // 8
		uint32 data1: 8; // 16
		uint32 vdst: 8; // 24
	};
	uint32 val;
};

// SQ_EXP_0
union SqExp0 {
	struct {
		uint32 en: 4; // 0
		uint32 tgt: 6; // 4
		uint32 compr: 1; // 10
		uint32 done: 1; // 11
		uint32 vm: 1; // 12
		uint32 unknown1: 13;
		uint32 encoding: 6; // 26
	};
	uint32 val;
};

// SQ_EXP_1
union SqExp1 {
	struct {
		uint32 vsrc0: 8; // 0
		uint32 vsrc1: 8; // 8
		uint32 vsrc2: 8; // 16
		uint32 vsrc3: 8; // 24
	};
	uint32 val;
};

// SQ_FIFO_SIZES
union SqFifoSizes {
	struct {
		uint32 interruptFifoSize: 4; // 0
		uint32 unknown1: 4;
		uint32 ttraceFifoSize: 4; // 8
		uint32 unknown2: 4;
		uint32 exportBufSize: 2; // 16
		uint32 vmemDataFifoSize: 2; // 18
		uint32 unknown3: 12;
	};
	uint32 val;
};

// SQ_IMG_RSRC_WORD0
union SqImgRsrcWord0 {
	struct {
		uint32 baseAddress: 32; // 0
	};
	uint32 val;
};

// SQ_IMG_RSRC_WORD1
union SqImgRsrcWord1 {
	struct {
		uint32 baseAddressHi: 8; // 0
		uint32 minLod: 12; // 8
		uint32 dataFormat: 6; // 20
		uint32 numFormat: 4; // 26
		uint32 mtype: 2; // 30
	};
	uint32 val;
};

// SQ_IMG_RSRC_WORD2
union SqImgRsrcWord2 {
	struct {
		uint32 width: 14; // 0
		uint32 height: 14; // 14
		uint32 perfMod: 3; // 28
		uint32 interlaced: 1; // 31
	};
	uint32 val;
};

// SQ_IMG_RSRC_WORD3
union SqImgRsrcWord3 {
	struct {
		uint32 dstSelX: 3; // 0
		uint32 dstSelY: 3; // 3
		uint32 dstSelZ: 3; // 6
		uint32 dstSelW: 3; // 9
		uint32 baseLevel: 4; // 12
		uint32 lastLevel: 4; // 16
		uint32 tilingIndex: 5; // 20
		uint32 pow2Pad: 1; // 25
		uint32 mtype: 1; // 26
		uint32 atc: 1; // 27
		uint32 type: 4; // 28
	};
	uint32 val;
};

// SQ_IMG_RSRC_WORD4
union SqImgRsrcWord4 {
	struct {
		uint32 depth: 13; // 0
		uint32 pitch: 14; // 13
		uint32 unknown1: 5;
	};
	uint32 val;
};

// SQ_IMG_RSRC_WORD5
union SqImgRsrcWord5 {
	struct {
		uint32 baseArray: 13; // 0
		uint32 lastArray: 13; // 13
		uint32 unknown1: 6;
	};
	uint32 val;
};

// SQ_IMG_RSRC_WORD6
union SqImgRsrcWord6 {
	struct {
		uint32 minLodWarn: 12; // 0
		uint32 counterBankId: 8; // 12
		uint32 lodHdwCntEn: 1; // 20
		uint32 ununsed: 11; // 21
	};
	uint32 val;
};

// SQ_IMG_RSRC_WORD7
union SqImgRsrcWord7 {
	struct {
		uint32 ununsed: 32; // 0
	};
	uint32 val;
};

// SQ_IMG_SAMP_WORD0
union SqImgSampWord0 {
	struct {
		uint32 clampX: 3; // 0
		uint32 clampY: 3; // 3
		uint32 clampZ: 3; // 6
		uint32 maxAnisoRatio: 3; // 9
		uint32 depthCompareFunc: 3; // 12
		uint32 forceUnnormalized: 1; // 15
		uint32 anisoThreshold: 3; // 16
		uint32 mcCoordTrunc: 1; // 19
		uint32 forceDegamma: 1; // 20
		uint32 anisoBias: 6; // 21
		uint32 truncCoord: 1; // 27
		uint32 disableCubeWrap: 1; // 28
		uint32 filterMode: 2; // 29
		uint32 unknown1: 1;
	};
	uint32 val;
};

// SQ_IMG_SAMP_WORD1
union SqImgSampWord1 {
	struct {
		uint32 minLod: 12; // 0
		uint32 maxLod: 12; // 12
		uint32 perfMip: 4; // 24
		uint32 perfZ: 4; // 28
	};
	uint32 val;
};

// SQ_IMG_SAMP_WORD2
union SqImgSampWord2 {
	struct {
		uint32 lodBias: 14; // 0
		uint32 lodBiasSec: 6; // 14
		uint32 xyMagFilter: 2; // 20
		uint32 xyMinFilter: 2; // 22
		uint32 zFilter: 2; // 24
		uint32 mipFilter: 2; // 26
		uint32 mipPointPreclamp: 1; // 28
		uint32 disableLsbCeil: 1; // 29
		uint32 filterPrecFix: 1; // 30
		uint32 unknown1: 1;
	};
	uint32 val;
};

// SQ_IMG_SAMP_WORD3
union SqImgSampWord3 {
	struct {
		uint32 borderColorPtr: 12; // 0
		uint32 unknown1: 18;
		uint32 borderColorType: 2; // 30
	};
	uint32 val;
};

// SQ_IND_DATA
union SqIndData {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_IND_INDEX
union SqIndIndex {
	struct {
		uint32 waveId: 4; // 0
		uint32 simdId: 2; // 4
		uint32 threadId: 6; // 6
		uint32 autoIncr: 1; // 12
		uint32 forceRead: 1; // 13
		uint32 readTimeout: 1; // 14
		uint32 unindexed: 1; // 15
		uint32 index: 16; // 16
	};
	uint32 val;
};

// SQ_INST
union SqInst {
	struct {
		uint32 encoding: 32; // 0
	};
	uint32 val;
};

// SQ_INTERRUPT_WORD_AUTO
union SqInterruptWordAuto {
	struct {
		uint32 threadTrace: 1; // 0
		uint32 wlt: 1; // 1
		uint32 threadTraceBufFull: 1; // 2
		uint32 regTimestamp: 1; // 3
		uint32 cmdTimestamp: 1; // 4
		uint32 hostCmdOverflow: 1; // 5
		uint32 hostRegOverflow: 1; // 6
		uint32 immedOverflow: 1; // 7
		uint32 unknown1: 17;
		uint32 seId: 1; // 25
		uint32 encoding: 2; // 26
		uint32 unknown2: 4;
	};
	uint32 val;
};

// SQ_INTERRUPT_WORD_CMN
union SqInterruptWordCmn {
	struct {
		uint32 unknown1: 25;
		uint32 seId: 1; // 25
		uint32 encoding: 2; // 26
		uint32 unknown2: 4;
	};
	uint32 val;
};

// SQ_INTERRUPT_WORD_WAVE
union SqInterruptWordWave {
	struct {
		uint32 data: 8; // 0
		uint32 unknown1: 1;
		uint32 priv: 1; // 9
		uint32 vmId: 4; // 10
		uint32 waveId: 4; // 14
		uint32 simdId: 2; // 18
		uint32 cuId: 4; // 20
		uint32 shId: 1; // 24
		uint32 seId: 1; // 25
		uint32 encoding: 2; // 26
		uint32 unknown2: 4;
	};
	uint32 val;
};

// SQ_LB_CTR_CTRL
union SqLbCtrCtrl {
	struct {
		uint32 start: 1; // 0
		uint32 load: 1; // 1
		uint32 clear: 1; // 2
		uint32 unknown1: 29;
	};
	uint32 val;
};

// SQ_LB_DATA_ALU_CYCLES
union SqLbDataAluCycles {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_LB_DATA_ALU_STALLS
union SqLbDataAluStalls {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_LB_DATA_TEX_CYCLES
union SqLbDataTexCycles {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_LB_DATA_TEX_STALLS
union SqLbDataTexStalls {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_MIMG_0
union SqMimg0 {
	struct {
		uint32 unknown1: 8;
		uint32 dmask: 4; // 8
		uint32 unorm: 1; // 12
		uint32 glc: 1; // 13
		uint32 da: 1; // 14
		uint32 r128: 1; // 15
		uint32 tfe: 1; // 16
		uint32 lwe: 1; // 17
		uint32 op: 7; // 18
		uint32 slc: 1; // 25
		uint32 encoding: 6; // 26
	};
	uint32 val;
};

// SQ_MIMG_1
union SqMimg1 {
	struct {
		uint32 vaddr: 8; // 0
		uint32 vdata: 8; // 8
		uint32 srsrc: 5; // 16
		uint32 ssamp: 5; // 21
		uint32 unknown1: 6;
	};
	uint32 val;
};

// SQ_MTBUF_0
union SqMtbuf0 {
	struct {
		uint32 offset: 12; // 0
		uint32 offen: 1; // 12
		uint32 idxen: 1; // 13
		uint32 glc: 1; // 14
		uint32 addr64: 1; // 15
		uint32 op: 3; // 16
		uint32 dfmt: 4; // 19
		uint32 nfmt: 3; // 23
		uint32 encoding: 6; // 26
	};
	uint32 val;
};

// SQ_MTBUF_1
union SqMtbuf1 {
	struct {
		uint32 vaddr: 8; // 0
		uint32 vdata: 8; // 8
		uint32 srsrc: 5; // 16
		uint32 unknown1: 1;
		uint32 slc: 1; // 22
		uint32 tfe: 1; // 23
		uint32 soffset: 8; // 24
	};
	uint32 val;
};

// SQ_MUBUF_0
union SqMubuf0 {
	struct {
		uint32 offset: 12; // 0
		uint32 offen: 1; // 12
		uint32 idxen: 1; // 13
		uint32 glc: 1; // 14
		uint32 addr64: 1; // 15
		uint32 lds: 1; // 16
		uint32 unknown1: 1;
		uint32 op: 7; // 18
		uint32 unknown2: 1;
		uint32 encoding: 6; // 26
	};
	uint32 val;
};

// SQ_MUBUF_1
union SqMubuf1 {
	struct {
		uint32 vaddr: 8; // 0
		uint32 vdata: 8; // 8
		uint32 srsrc: 5; // 16
		uint32 unknown1: 1;
		uint32 slc: 1; // 22
		uint32 tfe: 1; // 23
		uint32 soffset: 8; // 24
	};
	uint32 val;
};

// SQ_PERFCOUNTER0_HI
union SqPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER0_LO
union SqPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER0_SELECT
union SqPerfcounter0Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER10_HI
union SqPerfcounter10Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER10_LO
union SqPerfcounter10Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER10_SELECT
union SqPerfcounter10Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER11_HI
union SqPerfcounter11Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER11_LO
union SqPerfcounter11Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER11_SELECT
union SqPerfcounter11Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER12_HI
union SqPerfcounter12Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER12_LO
union SqPerfcounter12Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER12_SELECT
union SqPerfcounter12Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER13_HI
union SqPerfcounter13Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER13_LO
union SqPerfcounter13Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER13_SELECT
union SqPerfcounter13Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER14_HI
union SqPerfcounter14Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER14_LO
union SqPerfcounter14Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER14_SELECT
union SqPerfcounter14Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER15_HI
union SqPerfcounter15Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER15_LO
union SqPerfcounter15Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER15_SELECT
union SqPerfcounter15Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER1_HI
union SqPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER1_LO
union SqPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER1_SELECT
union SqPerfcounter1Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER2_HI
union SqPerfcounter2Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER2_LO
union SqPerfcounter2Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER2_SELECT
union SqPerfcounter2Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER3_HI
union SqPerfcounter3Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER3_LO
union SqPerfcounter3Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER3_SELECT
union SqPerfcounter3Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER4_HI
union SqPerfcounter4Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER4_LO
union SqPerfcounter4Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER4_SELECT
union SqPerfcounter4Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER5_HI
union SqPerfcounter5Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER5_LO
union SqPerfcounter5Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER5_SELECT
union SqPerfcounter5Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER6_HI
union SqPerfcounter6Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER6_LO
union SqPerfcounter6Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER6_SELECT
union SqPerfcounter6Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER7_HI
union SqPerfcounter7Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER7_LO
union SqPerfcounter7Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER7_SELECT
union SqPerfcounter7Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER8_HI
union SqPerfcounter8Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER8_LO
union SqPerfcounter8Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER8_SELECT
union SqPerfcounter8Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER9_HI
union SqPerfcounter9Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER9_LO
union SqPerfcounter9Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SQ_PERFCOUNTER9_SELECT
union SqPerfcounter9Select {
	struct {
		uint32 perfSel: 9; // 0
		uint32 unknown1: 3;
		uint32 sqcBankMask: 4; // 12
		uint32 sqcClientMask: 4; // 16
		uint32 spmMode: 4; // 20
		uint32 simdMask: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// SQ_PERFCOUNTER_CTRL
union SqPerfcounterCtrl {
	struct {
		uint32 psEn: 1; // 0
		uint32 vsEn: 1; // 1
		uint32 gsEn: 1; // 2
		uint32 esEn: 1; // 3
		uint32 hsEn: 1; // 4
		uint32 lsEn: 1; // 5
		uint32 csEn: 1; // 6
		uint32 unknown1: 1;
		uint32 cntrRate: 5; // 8
		uint32 disableFlush: 1; // 13
		uint32 unknown2: 18;
	};
	uint32 val;
};

// SQ_PERFCOUNTER_CTRL2
union SqPerfcounterCtrl2 {
	struct {
		uint32 forceEn: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// SQ_POWER_THROTTLE
union SqPowerThrottle {
	struct {
		uint32 minPower: 14; // 0
		uint32 unknown1: 2;
		uint32 maxPower: 14; // 16
		uint32 phaseOffset: 2; // 30
	};
	uint32 val;
};

// SQ_POWER_THROTTLE2
union SqPowerThrottle2 {
	struct {
		uint32 maxPowerDelta: 14; // 0
		uint32 unknown1: 2;
		uint32 shortTermIntervalSize: 10; // 16
		uint32 unknown2: 1;
		uint32 longTermIntervalRatio: 4; // 27
		uint32 useRefClock: 1; // 31
	};
	uint32 val;
};

// SQ_RANDOM_WAVE_PRI
union SqRandomWavePri {
	struct {
		uint32 ret: 7; // 0
		uint32 rui: 3; // 7
		uint32 rng: 11; // 10
		uint32 unknown1: 11;
	};
	uint32 val;
};

// SQ_REG_CREDITS
union SqRegCredits {
	struct {
		uint32 srbmCredits: 6; // 0
		uint32 unknown1: 2;
		uint32 cmdCredits: 4; // 8
		uint32 unknown2: 16;
		uint32 regBusy: 1; // 28
		uint32 srbmOverflow: 1; // 29
		uint32 immedOverflow: 1; // 30
		uint32 cmdOverflow: 1; // 31
	};
	uint32 val;
};

// SQ_SEC_CNT
union SqSecCnt {
	struct {
		uint32 ldsSec: 6; // 0
		uint32 unknown1: 2;
		uint32 sgprSec: 5; // 8
		uint32 unknown2: 3;
		uint32 vgprSec: 9; // 16
		uint32 unknown3: 7;
	};
	uint32 val;
};

// SQ_SMRD
union SqSmrd {
	struct {
		uint32 offset: 8; // 0
		uint32 imm: 1; // 8
		uint32 sbase: 6; // 9
		uint32 sdst: 7; // 15
		uint32 op: 5; // 22
		uint32 encoding: 5; // 27
	};
	uint32 val;
};

// SQ_SOP1
union SqSop1 {
	struct {
		uint32 ssrc0: 8; // 0
		uint32 op: 8; // 8
		uint32 sdst: 7; // 16
		uint32 encoding: 9; // 23
	};
	uint32 val;
};

// SQ_SOP2
union SqSop2 {
	struct {
		uint32 ssrc0: 8; // 0
		uint32 ssrc1: 8; // 8
		uint32 sdst: 7; // 16
		uint32 op: 7; // 23
		uint32 encoding: 2; // 30
	};
	uint32 val;
};

// SQ_SOPC
union SqSopc {
	struct {
		uint32 ssrc0: 8; // 0
		uint32 ssrc1: 8; // 8
		uint32 op: 7; // 16
		uint32 encoding: 9; // 23
	};
	uint32 val;
};

// SQ_SOPK
union SqSopk {
	struct {
		uint32 simm16: 16; // 0
		uint32 sdst: 7; // 16
		uint32 op: 5; // 23
		uint32 encoding: 4; // 28
	};
	uint32 val;
};

// SQ_SOPP
union SqSopp {
	struct {
		uint32 simm16: 16; // 0
		uint32 op: 7; // 16
		uint32 encoding: 9; // 23
	};
	uint32 val;
};

// SQ_TEX_CLK_CTRL
union SqTexClkCtrl {
	struct {
		uint32 forceCuOnSh0: 16; // 0
		uint32 forceCuOnSh1: 16; // 16
	};
	uint32 val;
};

// SQ_THREAD_TRACE_BASE
union SqThreadTraceBase {
	struct {
		uint32 addr: 32; // 0
	};
	uint32 val;
};

// SQ_THREAD_TRACE_BASE2
union SqThreadTraceBase2 {
	struct {
		uint32 addrHi: 4; // 0
		uint32 atc: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// SQ_THREAD_TRACE_CNTR
union SqThreadTraceCntr {
	struct {
		uint32 cntr: 32; // 0
	};
	uint32 val;
};

// SQ_THREAD_TRACE_CTRL
union SqThreadTraceCtrl {
	struct {
		uint32 unknown1: 31;
		uint32 resetBuffer: 1; // 31
	};
	uint32 val;
};

// SQ_THREAD_TRACE_HIWATER
union SqThreadTraceHiwater {
	struct {
		uint32 hiwater: 3; // 0
		uint32 unknown1: 29;
	};
	uint32 val;
};

// SQ_THREAD_TRACE_MASK
union SqThreadTraceMask {
	struct {
		uint32 cuSel: 5; // 0
		uint32 shSel: 1; // 5
		uint32 unknown1: 1;
		uint32 regStallEn: 1; // 7
		uint32 unknown2: 4;
		uint32 vmIdMask: 2; // 12
		uint32 spiStallEn: 1; // 14
		uint32 sqStallEn: 1; // 15
		uint32 randomSeed: 16; // 16
	};
	uint32 val;
};

// SQ_THREAD_TRACE_MODE
union SqThreadTraceMode {
	struct {
		uint32 maskPs: 3; // 0
		uint32 maskVs: 3; // 3
		uint32 maskGs: 3; // 6
		uint32 maskEs: 3; // 9
		uint32 maskHs: 3; // 12
		uint32 maskLs: 3; // 15
		uint32 maskCs: 3; // 18
		uint32 mode: 2; // 21
		uint32 captureMode: 2; // 23
		uint32 autoflushEn: 1; // 25
		uint32 priv: 1; // 26
		uint32 issueMask: 2; // 27
		uint32 testMode: 1; // 29
		uint32 interruptEn: 1; // 30
		uint32 wrap: 1; // 31
	};
	uint32 val;
};

// SQ_THREAD_TRACE_PERF_MASK
union SqThreadTracePerfMask {
	struct {
		uint32 sh0Mask: 16; // 0
		uint32 sh1Mask: 16; // 16
	};
	uint32 val;
};

// SQ_THREAD_TRACE_SIZE
union SqThreadTraceSize {
	struct {
		uint32 size: 22; // 0
		uint32 unknown1: 10;
	};
	uint32 val;
};

// SQ_THREAD_TRACE_STATUS
union SqThreadTraceStatus {
	struct {
		uint32 finishPending: 3; // 0
		uint32 unknown1: 13;
		uint32 finishDone: 3; // 16
		uint32 unknown2: 10;
		uint32 newBuf: 1; // 29
		uint32 busy: 1; // 30
		uint32 full: 1; // 31
	};
	uint32 val;
};

// SQ_THREAD_TRACE_TOKEN_MASK
union SqThreadTraceTokenMask {
	struct {
		uint32 tokenMask: 16; // 0
		uint32 regMask: 8; // 16
		uint32 regDropOnStall: 1; // 24
		uint32 unknown1: 7;
	};
	uint32 val;
};

// SQ_THREAD_TRACE_TOKEN_MASK2
union SqThreadTraceTokenMask2 {
	struct {
		uint32 instMask: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SQ_THREAD_TRACE_USERDATA_0
union SqThreadTraceUserdata0 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_THREAD_TRACE_USERDATA_1
union SqThreadTraceUserdata1 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_THREAD_TRACE_USERDATA_2
union SqThreadTraceUserdata2 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_THREAD_TRACE_USERDATA_3
union SqThreadTraceUserdata3 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_CMN
union SqThreadTraceWordCmn {
	struct {
		uint32 tokenType: 4; // 0
		uint32 timeDelta: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_EVENT
union SqThreadTraceWordEvent {
	struct {
		uint32 tokenType: 4; // 0
		uint32 timeDelta: 1; // 4
		uint32 shId: 1; // 5
		uint32 stage: 3; // 6
		uint32 unknown1: 1;
		uint32 eventType: 6; // 10
		uint32 unknown2: 16;
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_INST
union SqThreadTraceWordInst {
	struct {
		uint32 tokenType: 4; // 0
		uint32 timeDelta: 1; // 4
		uint32 waveId: 4; // 5
		uint32 simdId: 2; // 9
		uint32 size: 1; // 11
		uint32 instType: 4; // 12
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_INST_PC_1_OF_2
union SqThreadTraceWordInstPc1Of2 {
	struct {
		uint32 tokenType: 4; // 0
		uint32 timeDelta: 1; // 4
		uint32 waveId: 4; // 5
		uint32 simdId: 2; // 9
		uint32 unknown1: 5;
		uint32 pcLo: 16; // 16
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_INST_PC_2_OF_2
union SqThreadTraceWordInstPc2Of2 {
	struct {
		uint32 pcHi: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_INST_USERDATA_1_OF_2
union SqThreadTraceWordInstUserdata1Of2 {
	struct {
		uint32 tokenType: 4; // 0
		uint32 timeDelta: 1; // 4
		uint32 shId: 1; // 5
		uint32 cuId: 4; // 6
		uint32 waveId: 4; // 10
		uint32 simdId: 2; // 14
		uint32 dataLo: 16; // 16
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_INST_USERDATA_2_OF_2
union SqThreadTraceWordInstUserdata2Of2 {
	struct {
		uint32 dataHi: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_ISSUE
union SqThreadTraceWordIssue {
	struct {
		uint32 tokenType: 4; // 0
		uint32 timeDelta: 1; // 4
		uint32 simdId: 2; // 5
		uint32 unknown1: 1;
		uint32 inst0: 2; // 8
		uint32 inst1: 2; // 10
		uint32 inst2: 2; // 12
		uint32 inst3: 2; // 14
		uint32 inst4: 2; // 16
		uint32 inst5: 2; // 18
		uint32 inst6: 2; // 20
		uint32 inst7: 2; // 22
		uint32 inst8: 2; // 24
		uint32 inst9: 2; // 26
		uint32 unknown2: 4;
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_MISC
union SqThreadTraceWordMisc {
	struct {
		uint32 tokenType: 4; // 0
		uint32 timeDelta: 1; // 4
		uint32 shId: 1; // 5
		uint32 miscTokenType: 2; // 6
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_PERF_1_OF_2
union SqThreadTraceWordPerf1Of2 {
	struct {
		uint32 tokenType: 4; // 0
		uint32 timeDelta: 1; // 4
		uint32 shId: 1; // 5
		uint32 cuId: 4; // 6
		uint32 cntrBank: 2; // 10
		uint32 cntr0: 13; // 12
		uint32 cntr1Lo: 7; // 25
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_PERF_2_OF_2
union SqThreadTraceWordPerf2Of2 {
	struct {
		uint32 cntr1Hi: 6; // 0
		uint32 cntr2: 13; // 6
		uint32 cntr3: 13; // 19
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_REG_1_OF_2
union SqThreadTraceWordReg1Of2 {
	struct {
		uint32 tokenType: 4; // 0
		uint32 timeDelta: 1; // 4
		uint32 pipeId: 2; // 5
		uint32 meId: 2; // 7
		uint32 regDroppedPrev: 1; // 9
		uint32 regType: 3; // 10
		uint32 unknown1: 1;
		uint32 regPriv: 1; // 14
		uint32 regOp: 1; // 15
		uint32 regAddr: 16; // 16
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_REG_2_OF_2
union SqThreadTraceWordReg2Of2 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_TIMESTAMP_1_OF_2
union SqThreadTraceWordTimestamp1Of2 {
	struct {
		uint32 tokenType: 4; // 0
		uint32 unknown1: 12;
		uint32 timeLo: 16; // 16
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_TIMESTAMP_2_OF_2
union SqThreadTraceWordTimestamp2Of2 {
	struct {
		uint32 timeHi: 32; // 0
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_WAVE
union SqThreadTraceWordWave {
	struct {
		uint32 tokenType: 4; // 0
		uint32 timeDelta: 1; // 4
		uint32 shId: 1; // 5
		uint32 cuId: 4; // 6
		uint32 waveId: 4; // 10
		uint32 simdId: 2; // 14
		uint32 unknown1: 16;
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WORD_WAVE_START
union SqThreadTraceWordWaveStart {
	struct {
		uint32 tokenType: 4; // 0
		uint32 timeDelta: 1; // 4
		uint32 shId: 1; // 5
		uint32 cuId: 4; // 6
		uint32 waveId: 4; // 10
		uint32 simdId: 2; // 14
		uint32 dispatcher: 5; // 16
		uint32 vsNoAllocOrGrouped: 1; // 21
		uint32 count: 7; // 22
		uint32 tgId: 3; // 29
	};
	uint32 val;
};

// SQ_THREAD_TRACE_WPTR
union SqThreadTraceWptr {
	struct {
		uint32 wptr: 30; // 0
		uint32 readOffset: 2; // 30
	};
	uint32 val;
};

// SQ_TIME_HI
union SqTimeHi {
	struct {
		uint32 time: 32; // 0
	};
	uint32 val;
};

// SQ_TIME_LO
union SqTimeLo {
	struct {
		uint32 time: 32; // 0
	};
	uint32 val;
};

// SQ_VINTRP
union SqVintrp {
	struct {
		uint32 vsrc: 8; // 0
		uint32 attrchan: 2; // 8
		uint32 attr: 6; // 10
		uint32 op: 2; // 16
		uint32 vdst: 8; // 18
		uint32 encoding: 6; // 26
	};
	uint32 val;
};

// SQ_VOP1
union SqVop1 {
	struct {
		uint32 src0: 9; // 0
		uint32 op: 8; // 9
		uint32 vdst: 8; // 17
		uint32 encoding: 7; // 25
	};
	uint32 val;
};

// SQ_VOP2
union SqVop2 {
	struct {
		uint32 src0: 9; // 0
		uint32 vsrc1: 8; // 9
		uint32 vdst: 8; // 17
		uint32 op: 6; // 25
		uint32 encoding: 1; // 31
	};
	uint32 val;
};

// SQ_VOP3_0
union SqVop3_0 {
	struct {
		uint32 vdst: 8; // 0
		uint32 abs: 3; // 8
		uint32 clamp: 1; // 11
		uint32 unknown1: 5;
		uint32 op: 9; // 17
		uint32 encoding: 6; // 26
	};
	uint32 val;
};

// SQ_VOP3_0_SDST_ENC
union SqVop3_0SdstEnc {
	struct {
		uint32 vdst: 8; // 0
		uint32 sdst: 7; // 8
		uint32 unknown1: 2;
		uint32 op: 9; // 17
		uint32 encoding: 6; // 26
	};
	uint32 val;
};

// SQ_VOP3_1
union SqVop3_1 {
	struct {
		uint32 src0: 9; // 0
		uint32 src1: 9; // 9
		uint32 src2: 9; // 18
		uint32 omod: 2; // 27
		uint32 neg: 3; // 29
	};
	uint32 val;
};

// SQ_VOPC
union SqVopc {
	struct {
		uint32 src0: 9; // 0
		uint32 vsrc1: 8; // 9
		uint32 op: 8; // 17
		uint32 encoding: 7; // 25
	};
	uint32 val;
};

// SQ_WAVE_EXEC_HI
union SqWaveExecHi {
	struct {
		uint32 execHi: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_EXEC_LO
union SqWaveExecLo {
	struct {
		uint32 execLo: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_GPR_ALLOC
union SqWaveGprAlloc {
	struct {
		uint32 vgprBase: 6; // 0
		uint32 unknown1: 2;
		uint32 vgprSize: 6; // 8
		uint32 unknown2: 2;
		uint32 sgprBase: 6; // 16
		uint32 unknown3: 2;
		uint32 sgprSize: 4; // 24
		uint32 unknown4: 4;
	};
	uint32 val;
};

// SQ_WAVE_HW_ID
union SqWaveHwId {
	struct {
		uint32 waveId: 4; // 0
		uint32 simdId: 2; // 4
		uint32 pipeId: 2; // 6
		uint32 cuId: 4; // 8
		uint32 shId: 1; // 12
		uint32 seId: 1; // 13
		uint32 unknown1: 2;
		uint32 tgId: 4; // 16
		uint32 vmId: 4; // 20
		uint32 queueId: 3; // 24
		uint32 stateId: 3; // 27
		uint32 meId: 2; // 30
	};
	uint32 val;
};

// SQ_WAVE_IB_DBG0
union SqWaveIbDbg0 {
	struct {
		uint32 ibufSt: 3; // 0
		uint32 pcInvalid: 1; // 3
		uint32 needNextDw: 1; // 4
		uint32 noPrefetchCnt: 3; // 5
		uint32 ibufRptr: 2; // 8
		uint32 ibufWptr: 2; // 10
		uint32 unknown1: 4;
		uint32 instStrSt: 3; // 16
		uint32 miscCnt: 3; // 19
		uint32 eccSt: 2; // 22
		uint32 isHyb: 1; // 24
		uint32 hybCnt: 2; // 25
		uint32 kill: 1; // 27
		uint32 needKillIfetch: 1; // 28
		uint32 unknown2: 3;
	};
	uint32 val;
};

// SQ_WAVE_IB_STS
union SqWaveIbSts {
	struct {
		uint32 vmCnt: 4; // 0
		uint32 expCnt: 3; // 4
		uint32 unknown1: 1;
		uint32 lgkmCnt: 5; // 8
		uint32 valuCnt: 3; // 13
		uint32 unknown2: 16;
	};
	uint32 val;
};

// SQ_WAVE_INST_DW0
union SqWaveInstDw0 {
	struct {
		uint32 instDw0: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_INST_DW1
union SqWaveInstDw1 {
	struct {
		uint32 instDw1: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_LDS_ALLOC
union SqWaveLdsAlloc {
	struct {
		uint32 ldsBase: 8; // 0
		uint32 unknown1: 4;
		uint32 ldsSize: 9; // 12
		uint32 unknown2: 11;
	};
	uint32 val;
};

// SQ_WAVE_M0
union SqWaveM0 {
	struct {
		uint32 m0: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_MODE
union SqWaveMode {
	struct {
		uint32 fpRound: 4; // 0
		uint32 fpDenorm: 4; // 4
		uint32 dx10Clamp: 1; // 8
		uint32 ieee: 1; // 9
		uint32 lodClamped: 1; // 10
		uint32 debugEn: 1; // 11
		uint32 excpEn: 7; // 12
		uint32 unknown1: 9;
		uint32 vskip: 1; // 28
		uint32 csp: 3; // 29
	};
	uint32 val;
};

// SQ_WAVE_PC_HI
union SqWavePcHi {
	struct {
		uint32 pcHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SQ_WAVE_PC_LO
union SqWavePcLo {
	struct {
		uint32 pcLo: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_STATUS
union SqWaveStatus {
	struct {
		uint32 scc: 1; // 0
		uint32 spiPrio: 2; // 1
		uint32 wavePrio: 2; // 3
		uint32 priv: 1; // 5
		uint32 trapEn: 1; // 6
		uint32 ttraceEn: 1; // 7
		uint32 exportRdy: 1; // 8
		uint32 execz: 1; // 9
		uint32 vccz: 1; // 10
		uint32 inTg: 1; // 11
		uint32 inBarrier: 1; // 12
		uint32 halt: 1; // 13
		uint32 trap: 1; // 14
		uint32 ttraceCuEn: 1; // 15
		uint32 valid: 1; // 16
		uint32 eccErr: 1; // 17
		uint32 skipExport: 1; // 18
		uint32 perfEn: 1; // 19
		uint32 condDbgUser: 1; // 20
		uint32 condDbgSys: 1; // 21
		uint32 dataAtc: 1; // 22
		uint32 instAtc: 1; // 23
		uint32 dispatchCacheCtrl: 3; // 24
		uint32 mustExport: 1; // 27
		uint32 unknown1: 4;
	};
	uint32 val;
};

// SQ_WAVE_TBA_HI
union SqWaveTbaHi {
	struct {
		uint32 addrHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SQ_WAVE_TBA_LO
union SqWaveTbaLo {
	struct {
		uint32 addrLo: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_TMA_HI
union SqWaveTmaHi {
	struct {
		uint32 addrHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SQ_WAVE_TMA_LO
union SqWaveTmaLo {
	struct {
		uint32 addrLo: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_TRAPSTS
union SqWaveTrapsts {
	struct {
		uint32 excp: 7; // 0
		uint32 unknown1: 9;
		uint32 excpCycle: 6; // 16
		uint32 unknown2: 7;
		uint32 dpRate: 3; // 29
	};
	uint32 val;
};

// SQ_WAVE_TTMP0
union SqWaveTtmp0 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_TTMP1
union SqWaveTtmp1 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_TTMP10
union SqWaveTtmp10 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_TTMP11
union SqWaveTtmp11 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_TTMP2
union SqWaveTtmp2 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_TTMP3
union SqWaveTtmp3 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_TTMP4
union SqWaveTtmp4 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_TTMP5
union SqWaveTtmp5 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_TTMP6
union SqWaveTtmp6 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_TTMP7
union SqWaveTtmp7 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_TTMP8
union SqWaveTtmp8 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SQ_WAVE_TTMP9
union SqWaveTtmp9 {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// SXIFCCG_DEBUG_REG0
union SxifccgDebugReg0 {
	struct {
		uint32 positionAddress: 6; // 0
		uint32 pointAddress: 3; // 6
		uint32 sxPendingRdStateVarIndx: 3; // 9
		uint32 sxPendingRdReqMask: 4; // 12
		uint32 sxPendingRdPci: 10; // 16
		uint32 sxPendingRdAuxSel: 2; // 26
		uint32 sxPendingRdSpId: 2; // 28
		uint32 sxPendingRdAuxInc: 1; // 30
		uint32 sxPendingRdAdvance: 1; // 31
	};
	uint32 val;
};

// SXIFCCG_DEBUG_REG1
union SxifccgDebugReg1 {
	struct {
		uint32 availablePositions: 7; // 0
		uint32 sxReceiveIndx: 3; // 7
		uint32 sxPendingFifoContents: 5; // 10
		uint32 statevarBitsVsOutMiscVecEna: 1; // 15
		uint32 statevarBitsDisableSp: 4; // 16
		uint32 auxSel: 2; // 20
		uint32 sxToPaEmpty1: 1; // 22
		uint32 sxToPaEmpty0: 1; // 23
		uint32 pasxReqCnt1: 4; // 24
		uint32 pasxReqCnt0: 4; // 28
	};
	uint32 val;
};

// SXIFCCG_DEBUG_REG2
union SxifccgDebugReg2 {
	struct {
		uint32 paramCacheBase: 7; // 0
		uint32 sxAux: 2; // 7
		uint32 sxRequestIndx: 6; // 9
		uint32 reqActiveVertsLoaded: 1; // 15
		uint32 reqActiveVerts: 7; // 16
		uint32 vgtToCcgenStateVarIndx: 3; // 23
		uint32 vgtToCcgenActiveVerts: 6; // 26
	};
	uint32 val;
};

// SXIFCCG_DEBUG_REG3
union SxifccgDebugReg3 {
	struct {
		uint32 alwaysZero: 8; // 0
		uint32 vertexFifoEntriesavailable: 4; // 8
		uint32 statevarBitsVsOutCcdist1VecEna: 1; // 12
		uint32 statevarBitsVsOutCcdist0VecEna: 1; // 13
		uint32 availablePositions: 7; // 14
		uint32 currentState: 2; // 21
		uint32 vertexFifoEmpty: 1; // 23
		uint32 vertexFifoFull: 1; // 24
		uint32 sx0ReceiveFifoEmpty: 1; // 25
		uint32 sx0ReceiveFifoFull: 1; // 26
		uint32 vgtToCcgenFifoEmpty: 1; // 27
		uint32 vgtToCcgenFifoFull: 1; // 28
		uint32 ccgenToClipccFifoFull: 1; // 29
		uint32 sx0ReceiveFifoWrite: 1; // 30
		uint32 ccgenToClipccWrite: 1; // 31
	};
	uint32 val;
};

// SX_DEBUG_1
union SxDebug1 {
	struct {
		uint32 sxDbQuadCredit: 7; // 0
		uint32 debugData: 25; // 7
	};
	uint32 val;
};

// SX_DEBUG_BUSY
union SxDebugBusy {
	struct {
		uint32 posFreeOrValids: 1; // 0
		uint32 posRequesterBusy: 1; // 1
		uint32 paSxBusy: 1; // 2
		uint32 posScbdBusy: 1; // 3
		uint32 posBank3val3Busy: 1; // 4
		uint32 posBank3val2Busy: 1; // 5
		uint32 posBank3val1Busy: 1; // 6
		uint32 posBank3val0Busy: 1; // 7
		uint32 posBank2val3Busy: 1; // 8
		uint32 posBank2val2Busy: 1; // 9
		uint32 posBank2val1Busy: 1; // 10
		uint32 posBank2val0Busy: 1; // 11
		uint32 posBank1val3Busy: 1; // 12
		uint32 posBank1val2Busy: 1; // 13
		uint32 posBank1val1Busy: 1; // 14
		uint32 posBank1val0Busy: 1; // 15
		uint32 posBank0val3Busy: 1; // 16
		uint32 posBank0val2Busy: 1; // 17
		uint32 posBank0val1Busy: 1; // 18
		uint32 posBank0val0Busy: 1; // 19
		uint32 posInmuxValid: 1; // 20
		uint32 wrctrl1Validq3: 1; // 21
		uint32 wrctrl1Validq2: 1; // 22
		uint32 wrctrl1Validq1: 1; // 23
		uint32 wrctrl0Validq3: 1; // 24
		uint32 wrctrl0Validq2: 1; // 25
		uint32 wrctrl0Validq1: 1; // 26
		uint32 pccmdValid: 1; // 27
		uint32 vdata1Valid: 1; // 28
		uint32 vdata0Valid: 1; // 29
		uint32 cmdBusyorval: 1; // 30
		uint32 addrBusyorval: 1; // 31
	};
	uint32 val;
};

// SX_DEBUG_BUSY_2
union SxDebugBusy2 {
	struct {
		uint32 colScbdBusy: 1; // 0
		uint32 colReq3FreecntNe0: 1; // 1
		uint32 colReq3Idle: 1; // 2
		uint32 colReq3Busy: 1; // 3
		uint32 colReq2FreecntNe0: 1; // 4
		uint32 colReq2Idle: 1; // 5
		uint32 colReq2Busy: 1; // 6
		uint32 colReq1FreecntNe0: 1; // 7
		uint32 colReq1Idle: 1; // 8
		uint32 colReq1Busy: 1; // 9
		uint32 colReq0FreecntNe0: 1; // 10
		uint32 colReq0Idle: 1; // 11
		uint32 colReq0Busy: 1; // 12
		uint32 colDbif3SendfreeBusy: 1; // 13
		uint32 colDbif3FifoBusy: 1; // 14
		uint32 colDbif3ReadValid: 1; // 15
		uint32 colDbif2SendfreeBusy: 1; // 16
		uint32 colDbif2FifoBusy: 1; // 17
		uint32 colDbif2ReadValid: 1; // 18
		uint32 colDbif1SendfreeBusy: 1; // 19
		uint32 colDbif1FifoBusy: 1; // 20
		uint32 colDbif1ReadValid: 1; // 21
		uint32 colDbif0SendfreeBusy: 1; // 22
		uint32 colDbif0FifoBusy: 1; // 23
		uint32 colDbif0ReadValid: 1; // 24
		uint32 colBuff3Bank3Val3Busy: 1; // 25
		uint32 colBuff3Bank3Val2Busy: 1; // 26
		uint32 colBuff3Bank3Val1Busy: 1; // 27
		uint32 colBuff3Bank3Val0Busy: 1; // 28
		uint32 colBuff3Bank2Val3Busy: 1; // 29
		uint32 colBuff3Bank2Val2Busy: 1; // 30
		uint32 colBuff3Bank2Val1Busy: 1; // 31
	};
	uint32 val;
};

// SX_DEBUG_BUSY_3
union SxDebugBusy3 {
	struct {
		uint32 colBuff3Bank2Val0Busy: 1; // 0
		uint32 colBuff3Bank1Val3Busy: 1; // 1
		uint32 colBuff3Bank1Val2Busy: 1; // 2
		uint32 colBuff3Bank1Val1Busy: 1; // 3
		uint32 colBuff3Bank1Val0Busy: 1; // 4
		uint32 colBuff3Bank0Val3Busy: 1; // 5
		uint32 colBuff3Bank0Val2Busy: 1; // 6
		uint32 colBuff3Bank0Val1Busy: 1; // 7
		uint32 colBuff3Bank0Val0Busy: 1; // 8
		uint32 colBuff2Bank3Val3Busy: 1; // 9
		uint32 colBuff2Bank3Val2Busy: 1; // 10
		uint32 colBuff2Bank3Val1Busy: 1; // 11
		uint32 colBuff2Bank3Val0Busy: 1; // 12
		uint32 colBuff2Bank2Val3Busy: 1; // 13
		uint32 colBuff2Bank2Val2Busy: 1; // 14
		uint32 colBuff2Bank2Val1Busy: 1; // 15
		uint32 colBuff2Bank2Val0Busy: 1; // 16
		uint32 colBuff2Bank1Val3Busy: 1; // 17
		uint32 colBuff2Bank1Val2Busy: 1; // 18
		uint32 colBuff2Bank1Val1Busy: 1; // 19
		uint32 colBuff2Bank1Val0Busy: 1; // 20
		uint32 colBuff2Bank0Val3Busy: 1; // 21
		uint32 colBuff2Bank0Val2Busy: 1; // 22
		uint32 colBuff2Bank0Val1Busy: 1; // 23
		uint32 colBuff2Bank0Val0Busy: 1; // 24
		uint32 colBuff1Bank3Val3Busy: 1; // 25
		uint32 colBuff1Bank3Val2Busy: 1; // 26
		uint32 colBuff1Bank3Val1Busy: 1; // 27
		uint32 colBuff1Bank3Val0Busy: 1; // 28
		uint32 colBuff1Bank2Val3Busy: 1; // 29
		uint32 colBuff1Bank2Val2Busy: 1; // 30
		uint32 colBuff1Bank2Val1Busy: 1; // 31
	};
	uint32 val;
};

// SX_DEBUG_BUSY_4
union SxDebugBusy4 {
	struct {
		uint32 colBuff1Bank2Val0Busy: 1; // 0
		uint32 colBuff1Bank1Val3Busy: 1; // 1
		uint32 colBuff1Bank1Val2Busy: 1; // 2
		uint32 colBuff1Bank1Val1Busy: 1; // 3
		uint32 colBuff1Bank1Val0Busy: 1; // 4
		uint32 colBuff1Bank0Val3Busy: 1; // 5
		uint32 colBuff1Bank0Val2Busy: 1; // 6
		uint32 colBuff1Bank0Val1Busy: 1; // 7
		uint32 colBuff1Bank0Val0Busy: 1; // 8
		uint32 colBuff0Bank3Val3Busy: 1; // 9
		uint32 colBuff0Bank3Val2Busy: 1; // 10
		uint32 colBuff0Bank3Val1Busy: 1; // 11
		uint32 colBuff0Bank3Val0Busy: 1; // 12
		uint32 colBuff0Bank2Val3Busy: 1; // 13
		uint32 colBuff0Bank2Val2Busy: 1; // 14
		uint32 colBuff0Bank2Val1Busy: 1; // 15
		uint32 colBuff0Bank2Val0Busy: 1; // 16
		uint32 colBuff0Bank1Val3Busy: 1; // 17
		uint32 colBuff0Bank1Val2Busy: 1; // 18
		uint32 colBuff0Bank1Val1Busy: 1; // 19
		uint32 colBuff0Bank1Val0Busy: 1; // 20
		uint32 colBuff0Bank0Val3Busy: 1; // 21
		uint32 colBuff0Bank0Val2Busy: 1; // 22
		uint32 colBuff0Bank0Val1Busy: 1; // 23
		uint32 colBuff0Bank0Val0Busy: 1; // 24
		uint32 reserved: 7; // 25
	};
	uint32 val;
};

// SX_PERFCOUNTER0_HI
union SxPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SX_PERFCOUNTER0_LO
union SxPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SX_PERFCOUNTER0_SELECT
union SxPerfcounter0Select {
	struct {
		uint32 perfcounterSelect: 8; // 0
		uint32 unknown1: 2;
		uint32 perfcounterSelect1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// SX_PERFCOUNTER0_SELECT1
union SxPerfcounter0Select1 {
	struct {
		uint32 perfcounterSelect2: 10; // 0
		uint32 perfcounterSelect3: 10; // 10
		uint32 unknown1: 12;
	};
	uint32 val;
};

// SX_PERFCOUNTER1_HI
union SxPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SX_PERFCOUNTER1_LO
union SxPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SX_PERFCOUNTER1_SELECT
union SxPerfcounter1Select {
	struct {
		uint32 perfcounterSelect: 8; // 0
		uint32 unknown1: 2;
		uint32 perfcounterSelect1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// SX_PERFCOUNTER1_SELECT1
union SxPerfcounter1Select1 {
	struct {
		uint32 perfcounterSelect2: 10; // 0
		uint32 perfcounterSelect3: 10; // 10
		uint32 unknown1: 12;
	};
	uint32 val;
};

// SX_PERFCOUNTER2_HI
union SxPerfcounter2Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SX_PERFCOUNTER2_LO
union SxPerfcounter2Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SX_PERFCOUNTER2_SELECT
union SxPerfcounter2Select {
	struct {
		uint32 perfcounterSelect: 8; // 0
		uint32 unknown1: 2;
		uint32 perfcounterSelect1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// SX_PERFCOUNTER3_HI
union SxPerfcounter3Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// SX_PERFCOUNTER3_LO
union SxPerfcounter3Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// SX_PERFCOUNTER3_SELECT
union SxPerfcounter3Select {
	struct {
		uint32 perfcounterSelect: 8; // 0
		uint32 unknown1: 2;
		uint32 perfcounterSelect1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// TA_BC_BASE_ADDR
union TaBcBaseAddr {
	struct {
		uint32 address: 32; // 0
	};
	uint32 val;
};

// TA_BC_BASE_ADDR_HI
union TaBcBaseAddrHi {
	struct {
		uint32 address: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// TA_CGTT_CTRL
union TaCgttCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 12;
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// TA_CNTL
union TaCntl {
	struct {
		uint32 unknown1: 13;
		uint32 tcDataCredit: 3; // 13
		uint32 alignerCredit: 5; // 16
		uint32 unknown2: 1;
		uint32 tdFifoCredit: 10; // 22
	};
	uint32 val;
};

// TA_CNTL_AUX
union TaCntlAux {
	struct {
		uint32 unknown1: 16;
		uint32 anisoWeightMode: 1; // 16
		uint32 unknown2: 15;
	};
	uint32 val;
};

// TA_CS_BC_BASE_ADDR
union TaCsBcBaseAddr {
	struct {
		uint32 address: 32; // 0
	};
	uint32 val;
};

// TA_CS_BC_BASE_ADDR_HI
union TaCsBcBaseAddrHi {
	struct {
		uint32 address: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// TA_DEBUG_DATA
union TaDebugData {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// TA_DEBUG_INDEX
union TaDebugIndex {
	struct {
		uint32 index: 5; // 0
		uint32 unknown1: 27;
	};
	uint32 val;
};

// TA_PERFCOUNTER0_HI
union TaPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TA_PERFCOUNTER0_LO
union TaPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TA_PERFCOUNTER0_SELECT
union TaPerfcounter0Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 8; // 10
		uint32 unknown2: 2;
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TA_PERFCOUNTER0_SELECT1
union TaPerfcounter0Select1 {
	struct {
		uint32 perfSel2: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel3: 8; // 10
		uint32 unknown2: 6;
		uint32 perfMode3: 4; // 24
		uint32 perfMode2: 4; // 28
	};
	uint32 val;
};

// TA_PERFCOUNTER1_HI
union TaPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TA_PERFCOUNTER1_LO
union TaPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TA_PERFCOUNTER1_SELECT
union TaPerfcounter1Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 8; // 10
		uint32 unknown2: 2;
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TA_SCRATCH
union TaScratch {
	struct {
		uint32 scratch: 32; // 0
	};
	uint32 val;
};

// TA_STATUS
union TaStatus {
	struct {
		uint32 unknown1: 12;
		uint32 fgPfifoEmptyb: 1; // 12
		uint32 fgLfifoEmptyb: 1; // 13
		uint32 fgSfifoEmptyb: 1; // 14
		uint32 unknown2: 1;
		uint32 flPfifoEmptyb: 1; // 16
		uint32 flLfifoEmptyb: 1; // 17
		uint32 flSfifoEmptyb: 1; // 18
		uint32 unknown3: 1;
		uint32 faPfifoEmptyb: 1; // 20
		uint32 faLfifoEmptyb: 1; // 21
		uint32 faSfifoEmptyb: 1; // 22
		uint32 unknown4: 1;
		uint32 inBusy: 1; // 24
		uint32 fgBusy: 1; // 25
		uint32 laBusy: 1; // 26
		uint32 flBusy: 1; // 27
		uint32 taBusy: 1; // 28
		uint32 faBusy: 1; // 29
		uint32 alBusy: 1; // 30
		uint32 busy: 1; // 31
	};
	uint32 val;
};

// TCA_CGTT_SCLK_CTRL
union TcaCgttSclkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 12;
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// TCA_CTRL
union TcaCtrl {
	struct {
		uint32 holeTimeout: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// TCA_PERFCOUNTER0_HI
union TcaPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TCA_PERFCOUNTER0_LO
union TcaPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TCA_PERFCOUNTER0_SELECT
union TcaPerfcounter0Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TCA_PERFCOUNTER0_SELECT1
union TcaPerfcounter0Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 4;
		uint32 perfMode2: 4; // 24
		uint32 perfMode3: 4; // 28
	};
	uint32 val;
};

// TCA_PERFCOUNTER1_HI
union TcaPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TCA_PERFCOUNTER1_LO
union TcaPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TCA_PERFCOUNTER1_SELECT
union TcaPerfcounter1Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TCA_PERFCOUNTER1_SELECT1
union TcaPerfcounter1Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 4;
		uint32 perfMode2: 4; // 24
		uint32 perfMode3: 4; // 28
	};
	uint32 val;
};

// TCA_PERFCOUNTER2_HI
union TcaPerfcounter2Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TCA_PERFCOUNTER2_LO
union TcaPerfcounter2Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TCA_PERFCOUNTER2_SELECT
union TcaPerfcounter2Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 12;
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 4;
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TCA_PERFCOUNTER3_HI
union TcaPerfcounter3Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TCA_PERFCOUNTER3_LO
union TcaPerfcounter3Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TCA_PERFCOUNTER3_SELECT
union TcaPerfcounter3Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 12;
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 4;
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TCC_CGTT_SCLK_CTRL
union TccCgttSclkCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 12;
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// TCC_CTRL
union TccCtrl {
	struct {
		uint32 cacheSize: 2; // 0
		uint32 rate: 2; // 2
		uint32 writebackMargin: 4; // 4
		uint32 unknown1: 4;
		uint32 srcFifoSize: 4; // 12
		uint32 latencyFifoSize: 4; // 16
		uint32 wbOrInvAllVmids: 1; // 20
		uint32 unknown2: 11;
	};
	uint32 val;
};

// TCC_EDC_COUNTER
union TccEdcCounter {
	struct {
		uint32 secCount: 4; // 0
		uint32 unknown1: 12;
		uint32 dedCount: 4; // 16
		uint32 unknown2: 12;
	};
	uint32 val;
};

// TCC_PERFCOUNTER0_HI
union TccPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TCC_PERFCOUNTER0_LO
union TccPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TCC_PERFCOUNTER0_SELECT
union TccPerfcounter0Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TCC_PERFCOUNTER0_SELECT1
union TccPerfcounter0Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 4;
		uint32 perfMode2: 4; // 24
		uint32 perfMode3: 4; // 28
	};
	uint32 val;
};

// TCC_PERFCOUNTER1_HI
union TccPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TCC_PERFCOUNTER1_LO
union TccPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TCC_PERFCOUNTER1_SELECT
union TccPerfcounter1Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TCC_PERFCOUNTER1_SELECT1
union TccPerfcounter1Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 4;
		uint32 perfMode2: 4; // 24
		uint32 perfMode3: 4; // 28
	};
	uint32 val;
};

// TCC_PERFCOUNTER2_HI
union TccPerfcounter2Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TCC_PERFCOUNTER2_LO
union TccPerfcounter2Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TCC_PERFCOUNTER2_SELECT
union TccPerfcounter2Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 12;
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 4;
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TCC_PERFCOUNTER3_HI
union TccPerfcounter3Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TCC_PERFCOUNTER3_LO
union TccPerfcounter3Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TCC_PERFCOUNTER3_SELECT
union TccPerfcounter3Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 12;
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 4;
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TCI_CNTL_1
union TciCntl1 {
	struct {
		uint32 wbinvl1NumCycles: 16; // 0
		uint32 reqFifoDepth: 8; // 16
		uint32 wdataRamDepth: 8; // 24
	};
	uint32 val;
};

// TCI_CNTL_2
union TciCntl2 {
	struct {
		uint32 l1InvalOnWbinvl2: 1; // 0
		uint32 tcaMaxCredit: 8; // 1
		uint32 unknown1: 23;
	};
	uint32 val;
};

// TCI_STATUS
union TciStatus {
	struct {
		uint32 tciBusy: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// TCP_ADDR_CONFIG
union TcpAddrConfig {
	struct {
		uint32 numTccBanks: 4; // 0
		uint32 numBanks: 2; // 4
		uint32 colhiWidth: 3; // 6
		uint32 rbSplitColhi: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// TCP_BUFFER_ADDR_HASH_CNTL
union TcpBufferAddrHashCntl {
	struct {
		uint32 channelBits: 3; // 0
		uint32 unknown1: 5;
		uint32 bankBits: 3; // 8
		uint32 unknown2: 5;
		uint32 channelXorCount: 3; // 16
		uint32 unknown3: 5;
		uint32 bankXorCount: 3; // 24
		uint32 unknown4: 5;
	};
	uint32 val;
};

// TCP_CHAN_STEER_HI
union TcpChanSteerHi {
	struct {
		uint32 chan8: 4; // 0
		uint32 chan9: 4; // 4
		uint32 chana: 4; // 8
		uint32 chanb: 4; // 12
		uint32 chanc: 4; // 16
		uint32 chand: 4; // 20
		uint32 chane: 4; // 24
		uint32 chanf: 4; // 28
	};
	uint32 val;
};

// TCP_CHAN_STEER_LO
union TcpChanSteerLo {
	struct {
		uint32 chan0: 4; // 0
		uint32 chan1: 4; // 4
		uint32 chan2: 4; // 8
		uint32 chan3: 4; // 12
		uint32 chan4: 4; // 16
		uint32 chan5: 4; // 20
		uint32 chan6: 4; // 24
		uint32 chan7: 4; // 28
	};
	uint32 val;
};

// TCP_CNTL
union TcpCntl {
	struct {
		uint32 forceHit: 1; // 0
		uint32 forceMiss: 1; // 1
		uint32 l1Size: 2; // 2
		uint32 flatBufHashEnable: 1; // 4
		uint32 flatBufCacheSwizzle: 1; // 5
		uint32 unknown1: 9;
		uint32 forceEowTotalCnt: 6; // 15
		uint32 unknown2: 1;
		uint32 forceEowTagramCnt: 6; // 22
		uint32 disableZMap: 1; // 28
		uint32 invAllVmids: 1; // 29
		uint32 unknown3: 2;
	};
	uint32 val;
};

// TCP_CREDIT
union TcpCredit {
	struct {
		uint32 lfifoCredit: 10; // 0
		uint32 unknown1: 6;
		uint32 reqFifoCredit: 7; // 16
		uint32 unknown2: 6;
		uint32 tdCredit: 3; // 29
	};
	uint32 val;
};

// TCP_EDC_COUNTER
union TcpEdcCounter {
	struct {
		uint32 secCount: 4; // 0
		uint32 unknown1: 12;
		uint32 dedCount: 4; // 16
		uint32 unknown2: 12;
	};
	uint32 val;
};

// TCP_INVALIDATE
union TcpInvalidate {
	struct {
		uint32 start: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// TCP_PERFCOUNTER0_HI
union TcpPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TCP_PERFCOUNTER0_LO
union TcpPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TCP_PERFCOUNTER0_SELECT
union TcpPerfcounter0Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TCP_PERFCOUNTER0_SELECT1
union TcpPerfcounter0Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 4;
		uint32 perfMode3: 4; // 24
		uint32 perfMode2: 4; // 28
	};
	uint32 val;
};

// TCP_PERFCOUNTER1_HI
union TcpPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TCP_PERFCOUNTER1_LO
union TcpPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TCP_PERFCOUNTER1_SELECT
union TcpPerfcounter1Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TCP_PERFCOUNTER1_SELECT1
union TcpPerfcounter1Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 4;
		uint32 perfMode3: 4; // 24
		uint32 perfMode2: 4; // 28
	};
	uint32 val;
};

// TCP_PERFCOUNTER2_HI
union TcpPerfcounter2Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TCP_PERFCOUNTER2_LO
union TcpPerfcounter2Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TCP_PERFCOUNTER2_SELECT
union TcpPerfcounter2Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 12;
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 4;
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TCP_PERFCOUNTER3_HI
union TcpPerfcounter3Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TCP_PERFCOUNTER3_LO
union TcpPerfcounter3Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TCP_PERFCOUNTER3_SELECT
union TcpPerfcounter3Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 12;
		uint32 cntrMode: 4; // 20
		uint32 unknown2: 4;
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TCP_STATUS
union TcpStatus {
	struct {
		uint32 tcpBusy: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// TD_CGTT_CTRL
union TdCgttCtrl {
	struct {
		uint32 onDelay: 4; // 0
		uint32 offHysteresis: 8; // 4
		uint32 unknown1: 12;
		uint32 softOverride7: 1; // 24
		uint32 softOverride6: 1; // 25
		uint32 softOverride5: 1; // 26
		uint32 softOverride4: 1; // 27
		uint32 softOverride3: 1; // 28
		uint32 softOverride2: 1; // 29
		uint32 softOverride1: 1; // 30
		uint32 softOverride0: 1; // 31
	};
	uint32 val;
};

// TD_CNTL
union TdCntl {
	struct {
		uint32 syncPhaseSh: 2; // 0
		uint32 unknown1: 2;
		uint32 syncPhaseVcSmx: 2; // 4
		uint32 unknown2: 2;
		uint32 padStallEn: 1; // 8
		uint32 extendLdsStall: 2; // 9
		uint32 ldsStallPhaseAdjust: 2; // 11
		uint32 unknown3: 2;
		uint32 precisionCompatibility: 1; // 15
		uint32 gather4FloatMode: 1; // 16
		uint32 unknown4: 1;
		uint32 ldFloatMode: 1; // 18
		uint32 gather4Dx9Mode: 1; // 19
		uint32 disablePowerThrottle: 1; // 20
		uint32 unknown5: 11;
	};
	uint32 val;
};

// TD_DEBUG_DATA
union TdDebugData {
	struct {
		uint32 data: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// TD_DEBUG_INDEX
union TdDebugIndex {
	struct {
		uint32 index: 5; // 0
		uint32 unknown1: 27;
	};
	uint32 val;
};

// TD_PERFCOUNTER0_HI
union TdPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// TD_PERFCOUNTER0_LO
union TdPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// TD_PERFCOUNTER0_SELECT
union TdPerfcounter0Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 8; // 10
		uint32 unknown2: 2;
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// TD_PERFCOUNTER0_SELECT1
union TdPerfcounter0Select1 {
	struct {
		uint32 perfSel2: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel3: 8; // 10
		uint32 unknown2: 6;
		uint32 perfMode3: 4; // 24
		uint32 perfMode2: 4; // 28
	};
	uint32 val;
};

// TD_SCRATCH
union TdScratch {
	struct {
		uint32 scratch: 32; // 0
	};
	uint32 val;
};

// TD_STATUS
union TdStatus {
	struct {
		uint32 unknown1: 31;
		uint32 busy: 1; // 31
	};
	uint32 val;
};

// USER_SQC_BANK_DISABLE
union UserSqcBankDisable {
	struct {
		uint32 unknown1: 16;
		uint32 sqc0BankDisable: 4; // 16
		uint32 sqc1BankDisable: 4; // 20
		uint32 sqc2BankDisable: 4; // 24
		uint32 sqc3BankDisable: 4; // 28
	};
	uint32 val;
};

// VGT_CACHE_INVALIDATION
union VgtCacheInvalidation {
	struct {
		uint32 cacheInvalidation: 2; // 0
		uint32 unknown1: 3;
		uint32 vsNoExtraBuffer: 1; // 5
		uint32 autoInvldEn: 2; // 6
		uint32 unknown2: 1;
		uint32 useGsDone: 1; // 9
		uint32 unknown3: 1;
		uint32 disRangeFullInvld: 1; // 11
		uint32 gsLateAllocEn: 1; // 12
		uint32 streamoutFullFlush: 1; // 13
		uint32 unknown4: 2;
		uint32 esLimit: 5; // 16
		uint32 unknown5: 11;
	};
	uint32 val;
};

// VGT_CNTL_STATUS
union VgtCntlStatus {
	struct {
		uint32 vgtBusy: 1; // 0
		uint32 vgtOutIndxBusy: 1; // 1
		uint32 vgtOutBusy: 1; // 2
		uint32 vgtPtBusy: 1; // 3
		uint32 vgtTeBusy: 1; // 4
		uint32 vgtVrBusy: 1; // 5
		uint32 vgtPiBusy: 1; // 6
		uint32 vgtGsBusy: 1; // 7
		uint32 vgtHsBusy: 1; // 8
		uint32 vgtTe11Busy: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// VGT_DEBUG_CNTL
union VgtDebugCntl {
	struct {
		uint32 vgtDebugIndx: 6; // 0
		uint32 vgtDebugSelBusB: 1; // 6
		uint32 unknown1: 25;
	};
	uint32 val;
};

// VGT_DEBUG_DATA
union VgtDebugData {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// VGT_DEBUG_REG0
union VgtDebugReg0 {
	struct {
		uint32 vgtBusyExtended: 1; // 0
		uint32 spare9: 1; // 1
		uint32 vgtBusy: 1; // 2
		uint32 spare8: 1; // 3
		uint32 spare7: 1; // 4
		uint32 spare6: 1; // 5
		uint32 spare5: 1; // 6
		uint32 spare4: 1; // 7
		uint32 piBusy: 1; // 8
		uint32 vrPiBusy: 1; // 9
		uint32 ptPiBusy: 1; // 10
		uint32 tePiBusy: 1; // 11
		uint32 gsBusy: 1; // 12
		uint32 rcmBusy: 1; // 13
		uint32 tmBusy: 1; // 14
		uint32 cmBusy: 1; // 15
		uint32 gogBusy: 1; // 16
		uint32 frmtBusy: 1; // 17
		uint32 spare10: 1; // 18
		uint32 te11PiBusy: 1; // 19
		uint32 spare3: 1; // 20
		uint32 combinedOutBusy: 1; // 21
		uint32 spiVsInterfacesBusy: 1; // 22
		uint32 paInterfacesBusy: 1; // 23
		uint32 regClkBusy: 1; // 24
		uint32 spare2: 1; // 25
		uint32 coreClkBusy: 1; // 26
		uint32 gsClkBusy: 1; // 27
		uint32 spare1: 1; // 28
		uint32 sclkCoreVld: 1; // 29
		uint32 sclkGsVld: 1; // 30
		uint32 spare0: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG1
union VgtDebugReg1 {
	struct {
		uint32 spare9: 1; // 0
		uint32 spare8: 1; // 1
		uint32 spare7: 1; // 2
		uint32 spare6: 1; // 3
		uint32 spare5: 1; // 4
		uint32 spare4: 1; // 5
		uint32 spare3: 1; // 6
		uint32 spare2: 1; // 7
		uint32 spare1: 1; // 8
		uint32 spare0: 1; // 9
		uint32 piVrValid: 1; // 10
		uint32 vrPiRead: 1; // 11
		uint32 piPtValid: 1; // 12
		uint32 ptPiRead: 1; // 13
		uint32 piTeValid: 1; // 14
		uint32 teGrpRead: 1; // 15
		uint32 vrOutIndxValid: 1; // 16
		uint32 spare12: 1; // 17
		uint32 vrOutPrimValid: 1; // 18
		uint32 spare11: 1; // 19
		uint32 ptOutIndxValid: 1; // 20
		uint32 spare10: 1; // 21
		uint32 ptOutPrimValid: 1; // 22
		uint32 spare23: 1; // 23
		uint32 teOutDataValid: 1; // 24
		uint32 spare25: 1; // 25
		uint32 piGsValid: 1; // 26
		uint32 gsPiRead: 1; // 27
		uint32 gogOutIndxValid: 1; // 28
		uint32 outIndxRead: 1; // 29
		uint32 gogOutPrimValid: 1; // 30
		uint32 outPrimRead: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG10
union VgtDebugReg10 {
	struct {
		uint32 indexBufferDepthR1Q: 5; // 0
		uint32 eopgR2Q: 1; // 5
		uint32 eotgR2Q: 1; // 6
		uint32 onchipGsEnR0Q: 2; // 7
		uint32 spare2: 2; // 9
		uint32 rcmMemGsprimReQq: 1; // 11
		uint32 rcmMemGsprimReQ: 1; // 12
		uint32 gsRbSpaceAvailR3Q9_0: 10; // 13
		uint32 esRbSpaceAvailR2Q8_0: 9; // 23
	};
	uint32 val;
};

// VGT_DEBUG_REG11
union VgtDebugReg11 {
	struct {
		uint32 tmBusyQ: 1; // 0
		uint32 tmNoifBusyQ: 1; // 1
		uint32 tmOutBusyQ: 1; // 2
		uint32 esRbDeallocFifoBusy: 1; // 3
		uint32 vsDeallocTblBusy: 1; // 4
		uint32 spare1: 1; // 5
		uint32 spiGsthreadFifoBusy: 1; // 6
		uint32 spiEsthreadFifoBusy: 1; // 7
		uint32 holdEswave: 1; // 8
		uint32 esRbRollOverR3: 1; // 9
		uint32 countersBusyR0: 1; // 10
		uint32 countersAvailR0: 1; // 11
		uint32 countersAvailableR0: 1; // 12
		uint32 vsEventFifoRtr: 1; // 13
		uint32 vgtSpiGsthreadRtrQ: 1; // 14
		uint32 vgtSpiEsthreadRtrQ: 1; // 15
		uint32 gsIssueRtr: 1; // 16
		uint32 tmPtEventRtr: 1; // 17
		uint32 spare0: 1; // 18
		uint32 gsR0Rtr: 1; // 19
		uint32 esR0Rtr: 1; // 20
		uint32 gogTmVsEventRtr: 1; // 21
		uint32 tmRcmGsEventRtr: 1; // 22
		uint32 tmRcmGsTblRtr: 1; // 23
		uint32 tmRcmEsTblRtr: 1; // 24
		uint32 vsEventFifoEmpty: 1; // 25
		uint32 vsEventFifoFull: 1; // 26
		uint32 esRbDeallocFifoFull: 1; // 27
		uint32 vsDeallocTblFull: 1; // 28
		uint32 sendEventQ: 1; // 29
		uint32 esTblEmpty: 1; // 30
		uint32 noActiveStatesR0: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG12
union VgtDebugReg12 {
	struct {
		uint32 gsState0R0Q: 3; // 0
		uint32 gsState1R0Q: 3; // 3
		uint32 gsState2R0Q: 3; // 6
		uint32 gsState3R0Q: 3; // 9
		uint32 gsState4R0Q: 3; // 12
		uint32 gsState5R0Q: 3; // 15
		uint32 gsState6R0Q: 3; // 18
		uint32 gsState7R0Q: 3; // 21
		uint32 gsState8R0Q: 3; // 24
		uint32 gsState9R0Q: 3; // 27
		uint32 holdEswaveEop: 1; // 30
		uint32 spare0: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG13
union VgtDebugReg13 {
	struct {
		uint32 gsState10R0Q: 3; // 0
		uint32 gsState11R0Q: 3; // 3
		uint32 gsState12R0Q: 3; // 6
		uint32 gsState13R0Q: 3; // 9
		uint32 gsState14R0Q: 3; // 12
		uint32 gsState15R0Q: 3; // 15
		uint32 gsTblWrptrR0Q3_0: 4; // 18
		uint32 gsfetchDoneFifoCntQNot0: 1; // 22
		uint32 gsfetchDoneCntQNot0: 1; // 23
		uint32 esTblFull: 1; // 24
		uint32 spare1: 1; // 25
		uint32 spare0: 1; // 26
		uint32 activeCmSmR0Q: 5; // 27
	};
	uint32 val;
};

// VGT_DEBUG_REG14
union VgtDebugReg14 {
	struct {
		uint32 spare3: 4; // 0
		uint32 gsfetchDoneFifoFull: 1; // 4
		uint32 gsRbSpaceAvailR0: 1; // 5
		uint32 smxEsDoneCntR0QNot0: 1; // 6
		uint32 spare8: 2; // 7
		uint32 vsDoneCntQNot0: 1; // 9
		uint32 esFlushCntBusyQ: 1; // 10
		uint32 gsTblFullR0: 1; // 11
		uint32 spare2: 9; // 12
		uint32 se1spiGsthreadFifoBusy: 1; // 21
		uint32 spare: 3; // 22
		uint32 vgtSe1spiGsthreadRtrQ: 1; // 25
		uint32 smx1EsDoneCntR0QNot0: 1; // 26
		uint32 se1spiEsthreadFifoBusy: 1; // 27
		uint32 spare1: 1; // 28
		uint32 gsfetchDoneSe1CntQNot0: 1; // 29
		uint32 spare0: 1; // 30
		uint32 vgtSe1spiEsthreadRtrQ: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG15
union VgtDebugReg15 {
	struct {
		uint32 cmBusyQ: 1; // 0
		uint32 countersBusyQ: 1; // 1
		uint32 outputFifoEmpty: 1; // 2
		uint32 outputFifoFull: 1; // 3
		uint32 countersFull: 1; // 4
		uint32 activeSmQ: 5; // 5
		uint32 entryRdptrQ: 5; // 10
		uint32 cntrTblWrptrQ: 5; // 15
		uint32 spare25: 6; // 20
		uint32 stCutModeQ: 2; // 26
		uint32 gsDoneArrayQNot0: 1; // 28
		uint32 spare31: 3; // 29
	};
	uint32 val;
};

// VGT_DEBUG_REG16
union VgtDebugReg16 {
	struct {
		uint32 gogBusy: 1; // 0
		uint32 gogStateQ: 3; // 1
		uint32 r0Rtr: 1; // 4
		uint32 r1Rtr: 1; // 5
		uint32 r1UpstreamRtr: 1; // 6
		uint32 r2VsTblRtr: 1; // 7
		uint32 r2PrimRtr: 1; // 8
		uint32 r2IndxRtr: 1; // 9
		uint32 r2Rtr: 1; // 10
		uint32 gogTmVsEventRtr: 1; // 11
		uint32 r3ForceVsTblWeRtr: 1; // 12
		uint32 indxValidR2Q: 1; // 13
		uint32 primValidR2Q: 1; // 14
		uint32 validR2Q: 1; // 15
		uint32 primValidR1Q: 1; // 16
		uint32 indxValidR1Q: 1; // 17
		uint32 validR1Q: 1; // 18
		uint32 indxValidR0Q: 1; // 19
		uint32 primValidR0Q: 1; // 20
		uint32 validR0Q: 1; // 21
		uint32 sendEventQ: 1; // 22
		uint32 spare24: 2; // 23
		// uint32 unknown1: -1;
		// uint32 vertSeenSinceSopgR2Q: 1;
		uint32 gogOutPrimStateSel: 3; // 25
		uint32 multipleStreamsEnR1Q: 1; // 28
		uint32 vsVertCountR2QNot0: 1; // 29
		uint32 numGsR2QNot0: 1; // 30
		uint32 newVsThreadR2: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG17
union VgtDebugReg17 {
	struct {
		uint32 gogOutPrimRelIndx2_5_0: 6; // 0
		uint32 gogOutPrimRelIndx1_5_0: 6; // 6
		uint32 gogOutPrimRelIndx0_5_0: 6; // 12
		uint32 gogOutIndx13_0: 14; // 18
	};
	uint32 val;
};

// VGT_DEBUG_REG18
union VgtDebugReg18 {
	struct {
		uint32 grpVrValid: 1; // 0
		uint32 pipe0Dr: 1; // 1
		uint32 pipe1Dr: 1; // 2
		uint32 vrGrpRead: 1; // 3
		uint32 pipe0Rtr: 1; // 4
		uint32 pipe1Rtr: 1; // 5
		uint32 outVrIndxRead: 1; // 6
		uint32 outVrPrimRead: 1; // 7
		uint32 indicesToSendQ: 3; // 8
		uint32 validIndices: 1; // 11
		uint32 lastIndxOfPrim: 1; // 12
		uint32 indx0NewD: 1; // 13
		uint32 indx1NewD: 1; // 14
		uint32 indx2NewD: 1; // 15
		uint32 indx2HitD: 1; // 16
		uint32 indx1HitD: 1; // 17
		uint32 indx0HitD: 1; // 18
		uint32 stVertexReuseOffR0Q: 1; // 19
		uint32 lastGroupOfInstanceR0Q: 1; // 20
		uint32 nullPrimitiveR0Q: 1; // 21
		uint32 eopR0Q: 1; // 22
		uint32 ejectVtxVectR1D: 1; // 23
		uint32 subPrimTypeR0Q: 3; // 24
		uint32 gsScenarioAR0Q: 1; // 27
		uint32 gsScenarioBR0Q: 1; // 28
		uint32 componentsValidR0Q: 3; // 29
	};
	uint32 val;
};

// VGT_DEBUG_REG19
union VgtDebugReg19 {
	struct {
		uint32 separateOutBusyQ: 1; // 0
		uint32 separateOutIndxBusyQ: 1; // 1
		uint32 primBufferEmpty: 1; // 2
		uint32 primBufferFull: 1; // 3
		uint32 paClipsFifoBusyQ: 1; // 4
		uint32 paClippFifoBusyQ: 1; // 5
		uint32 vgtPaClipsRtrQ: 1; // 6
		uint32 vgtPaClippRtrQ: 1; // 7
		uint32 spiVsthreadFifoBusyQ: 1; // 8
		uint32 spiVsvertFifoBusyQ: 1; // 9
		uint32 paClipvFifoBusyQ: 1; // 10
		uint32 holdPrim: 1; // 11
		uint32 vgtSpiVsthreadRtrQ: 1; // 12
		uint32 vgtSpiVsvertRtrQ: 1; // 13
		uint32 vgtPaClipvRtrQ: 1; // 14
		uint32 newPacketQ: 1; // 15
		uint32 bufferedPrimEvent: 1; // 16
		uint32 bufferedPrimNullPrimitive: 1; // 17
		uint32 bufferedPrimEop: 1; // 18
		uint32 bufferedPrimEjectVtxVect: 1; // 19
		uint32 bufferedPrimTypeEvent: 6; // 20
		uint32 vgtSe1spiVswaveRtrQ: 1; // 26
		uint32 vgtSe1spiVsvertRtrQ: 1; // 27
		uint32 numNewUniqueRelIndx: 2; // 28
		uint32 nullTerminateVtxVector: 1; // 30
		uint32 filterEvent: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG2
union VgtDebugReg2 {
	struct {
		uint32 spare: 32; // 0
		// uint32 unknown1: -31;
		// uint32 hsNoifBusy: 1;
		// uint32 unknown2: -30;
		// uint32 tfmmisbusy: 1;
		// uint32 unknown3: -29;
		// uint32 lsvertifbusy0: 1;
		// uint32 unknown4: -28;
		// uint32 te11HsTessInputRtr: 1;
		// uint32 unknown5: -27;
		// uint32 lswaveifbusy0: 1;
		// uint32 unknown6: -26;
		// uint32 hsTe11TessInputRts: 1;
		// uint32 unknown7: -25;
		// uint32 grpmodbusy: 1;
		// uint32 unknown8: -24;
		// uint32 lsvertfifoempty: 1;
		// uint32 unknown9: -23;
		// uint32 lswavefifoempty: 1;
		// uint32 unknown10: -22;
		// uint32 hsvertfifoempty: 1;
		// uint32 unknown11: -21;
		// uint32 hswavefifoempty: 1;
		// uint32 unknown12: -20;
		// uint32 hsinputfifoempty: 1;
		// uint32 unknown13: -19;
		// uint32 hstiffifoempty: 1;
		// uint32 unknown14: -18;
		// uint32 lsvertfifofull: 1;
		// uint32 unknown15: -17;
		// uint32 lswavefifofull: 1;
		// uint32 unknown16: -16;
		// uint32 hsvertfifofull: 1;
		// uint32 unknown17: -15;
		// uint32 hswavefifofull: 1;
		// uint32 unknown18: -14;
		// uint32 hsinputfifofull: 1;
		// uint32 unknown19: -13;
		// uint32 hstiffifofull: 1;
		// uint32 unknown20: -12;
		// uint32 p0Rtr: 1;
		// uint32 unknown21: -11;
		// uint32 p1Rtr: 1;
		// uint32 unknown22: -10;
		// uint32 p0Dr: 1;
		// uint32 unknown23: -9;
		// uint32 p1Dr: 1;
		// uint32 unknown24: -8;
		// uint32 p0Rts: 1;
		// uint32 unknown25: -7;
		// uint32 p1Rts: 1;
		// uint32 unknown26: -6;
		// uint32 lsShId: 1;
		// uint32 unknown27: -5;
		// uint32 lsfwaveflag: 1;
		// uint32 unknown28: -4;
		// uint32 lswavesendflush: 1;
	};
	uint32 val;
};

// VGT_DEBUG_REG20
union VgtDebugReg20 {
	struct {
		uint32 dbgVgtSpiVsthreadSovertexindex: 16; // 0
		uint32 dbgVgtSpiVsthreadSovertexcountNot0: 1; // 16
		uint32 spare17: 1; // 17
		uint32 allocCounterQ: 4; // 18
		uint32 currDeallocDistanceQ: 7; // 22
		uint32 newAllocateQ: 1; // 29
		uint32 currSlotInVtxVectQNot0: 1; // 30
		uint32 intVtxCounterQNot0: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG21
union VgtDebugReg21 {
	struct {
		uint32 outIndxFifoEmpty: 1; // 0
		uint32 indxSideFifoEmpty: 1; // 1
		uint32 pipe0Dr: 1; // 2
		uint32 pipe1Dr: 1; // 3
		uint32 pipe2Dr: 1; // 4
		uint32 vsthreadBuffEmpty: 1; // 5
		uint32 outIndxFifoFull: 1; // 6
		uint32 indxSideFifoFull: 1; // 7
		uint32 pipe0Rtr: 1; // 8
		uint32 pipe1Rtr: 1; // 9
		uint32 pipe2Rtr: 1; // 10
		uint32 vsthreadBuffFull: 1; // 11
		uint32 interfacesRtr: 1; // 12
		uint32 indxCountQNot0: 1; // 13
		uint32 waitForExternalEopgQ: 1; // 14
		uint32 fullStateP1Q: 1; // 15
		uint32 indxSideIndxValid: 1; // 16
		uint32 stateidP0Q: 3; // 17
		uint32 isEventP0Q: 1; // 20
		uint32 lshsDeallocP1: 1; // 21
		uint32 streamIdR2Q: 1; // 22
		uint32 vtxVectCounterQNot0: 1; // 23
		uint32 buffFullP1: 1; // 24
		uint32 strmoutValidP1: 1; // 25
		uint32 eotgR2Q: 1; // 26
		uint32 nullR2Q: 1; // 27
		uint32 p0Dr: 1; // 28
		uint32 p0Rtr: 1; // 29
		uint32 eopgP0Q: 1; // 30
		uint32 p0Nobp: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG22
union VgtDebugReg22 {
	struct {
		uint32 cmState16: 2; // 0
		uint32 cmState17: 2; // 2
		uint32 cmState18: 2; // 4
		uint32 cmState19: 2; // 6
		uint32 cmState20: 2; // 8
		uint32 cmState21: 2; // 10
		uint32 cmState22: 2; // 12
		uint32 cmState23: 2; // 14
		uint32 cmState24: 2; // 16
		uint32 cmState25: 2; // 18
		uint32 cmState26: 2; // 20
		uint32 cmState27: 2; // 22
		uint32 cmState28: 2; // 24
		uint32 cmState29: 2; // 26
		uint32 cmState30: 2; // 28
		uint32 cmState31: 2; // 30
	};
	uint32 val;
};

// VGT_DEBUG_REG23
union VgtDebugReg23 {
	struct {
		uint32 frmtBusy: 1; // 0
		uint32 rcmFrmtVertRtr: 1; // 1
		uint32 rcmFrmtPrimRtr: 1; // 2
		uint32 primR3Rtr: 1; // 3
		uint32 primR2Rtr: 1; // 4
		uint32 vertR3Rtr: 1; // 5
		uint32 vertR2Rtr: 1; // 6
		uint32 vertR1Rtr: 1; // 7
		uint32 vertR0Rtr: 1; // 8
		uint32 primFifoEmpty: 1; // 9
		uint32 primFifoFull: 1; // 10
		uint32 vertDrR2Q: 1; // 11
		uint32 primDrR2Q: 1; // 12
		uint32 vertDrR1Q: 1; // 13
		uint32 vertDrR0Q: 1; // 14
		uint32 newVertsR2Q: 2; // 15
		uint32 vertsSentR2Q: 4; // 17
		uint32 primStateSelR2Q: 3; // 21
		uint32 spare: 8; // 24
	};
	uint32 val;
};

// VGT_DEBUG_REG24
union VgtDebugReg24 {
	struct {
		uint32 availEsRbSpaceR0Q23_0: 24; // 0
		uint32 dependentStCutModeQ: 2; // 24
		uint32 spare31: 6; // 26
	};
	uint32 val;
};

// VGT_DEBUG_REG25
union VgtDebugReg25 {
	struct {
		uint32 availGsRbSpaceR0Q25_0: 26; // 0
		uint32 activeSmR0Q: 4; // 26
		uint32 addGsRbSpaceR1Q: 1; // 30
		uint32 addGsRbSpaceR0Q: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG26
union VgtDebugReg26 {
	struct {
		uint32 cmState0: 2; // 0
		uint32 cmState1: 2; // 2
		uint32 cmState2: 2; // 4
		uint32 cmState3: 2; // 6
		uint32 cmState4: 2; // 8
		uint32 cmState5: 2; // 10
		uint32 cmState6: 2; // 12
		uint32 cmState7: 2; // 14
		uint32 cmState8: 2; // 16
		uint32 cmState9: 2; // 18
		uint32 cmState10: 2; // 20
		uint32 cmState11: 2; // 22
		uint32 cmState12: 2; // 24
		uint32 cmState13: 2; // 26
		uint32 cmState14: 2; // 28
		uint32 cmState15: 2; // 30
	};
	uint32 val;
};

// VGT_DEBUG_REG27
union VgtDebugReg27 {
	struct {
		uint32 pipe0Dr: 1; // 0
		uint32 gsc0Dr: 1; // 1
		uint32 pipe1Dr: 1; // 2
		uint32 tmPtEventRtr: 1; // 3
		uint32 pipe0Rtr: 1; // 4
		uint32 gsc0Rtr: 1; // 5
		uint32 pipe1Rtr: 1; // 6
		uint32 lastIndxOfPrimP1Q: 1; // 7
		uint32 indicesToSendP0Q: 2; // 8
		uint32 eventFlagP1Q: 1; // 10
		uint32 eopP1Q: 1; // 11
		uint32 gsOutPrimTypeP0Q: 2; // 12
		uint32 gscNullPrimitiveP0Q: 1; // 14
		uint32 gscEopP0Q: 1; // 15
		uint32 gsc2cycleOutput: 1; // 16
		uint32 gsc2ndCycleP0Q: 1; // 17
		uint32 lastIndxOfVsprim: 1; // 18
		uint32 firstVsprimOfGsprimP0Q: 1; // 19
		uint32 gscIndxCountP0Q: 11; // 20
		uint32 lastVsprimOfGsprim: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG28
union VgtDebugReg28 {
	struct {
		uint32 conStateQ: 4; // 0
		uint32 secondCycleQ: 1; // 4
		uint32 processTriMiddleP0Q: 1; // 5
		uint32 processTri1st2ndHalfP0Q: 1; // 6
		uint32 processTriCenterPolyP0Q: 1; // 7
		uint32 pipe0PatchDr: 1; // 8
		uint32 pipe0EdgeDr: 1; // 9
		uint32 pipe1Dr: 1; // 10
		uint32 pipe0PatchRtr: 1; // 11
		uint32 pipe0EdgeRtr: 1; // 12
		uint32 pipe1Rtr: 1; // 13
		uint32 outerParityP0Q: 1; // 14
		uint32 parallelParityP0Q: 1; // 15
		uint32 firstRingOfPatchP0Q: 1; // 16
		uint32 lastRingOfPatchP0Q: 1; // 17
		uint32 lastEdgeOfOuterRingP0Q: 1; // 18
		uint32 lastPointOfOuterRingP1: 1; // 19
		uint32 lastPointOfInnerRingP1: 1; // 20
		uint32 outerEdgeTfEqOneP0Q: 1; // 21
		uint32 advanceOuterPointP1: 1; // 22
		uint32 advanceInnerPointP1: 1; // 23
		uint32 nextRingIsRectP0Q: 1; // 24
		uint32 pipe1Outer1Rtr: 1; // 25
		uint32 pipe1Outer2Rtr: 1; // 26
		uint32 pipe1Inner1Rtr: 1; // 27
		uint32 pipe1Inner2Rtr: 1; // 28
		uint32 pipe1PatchRtr: 1; // 29
		uint32 pipe1EdgeRtr: 1; // 30
		uint32 useStoredInnerQRing2: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG29
union VgtDebugReg29 {
	struct {
		uint32 conStateQ: 4; // 0
		uint32 secondCycleQ: 1; // 4
		uint32 processTriMiddleP0Q: 1; // 5
		uint32 processTri1st2ndHalfP0Q: 1; // 6
		uint32 processTriCenterPolyP0Q: 1; // 7
		uint32 pipe0PatchDr: 1; // 8
		uint32 pipe0EdgeDr: 1; // 9
		uint32 pipe1Dr: 1; // 10
		uint32 pipe0PatchRtr: 1; // 11
		uint32 pipe0EdgeRtr: 1; // 12
		uint32 pipe1Rtr: 1; // 13
		uint32 outerParityP0Q: 1; // 14
		uint32 parallelParityP0Q: 1; // 15
		uint32 firstRingOfPatchP0Q: 1; // 16
		uint32 lastRingOfPatchP0Q: 1; // 17
		uint32 lastEdgeOfOuterRingP0Q: 1; // 18
		uint32 lastPointOfOuterRingP1: 1; // 19
		uint32 lastPointOfInnerRingP1: 1; // 20
		uint32 outerEdgeTfEqOneP0Q: 1; // 21
		uint32 advanceOuterPointP1: 1; // 22
		uint32 advanceInnerPointP1: 1; // 23
		uint32 nextRingIsRectP0Q: 1; // 24
		uint32 pipe1Outer1Rtr: 1; // 25
		uint32 pipe1Outer2Rtr: 1; // 26
		uint32 pipe1Inner1Rtr: 1; // 27
		uint32 pipe1Inner2Rtr: 1; // 28
		uint32 pipe1PatchRtr: 1; // 29
		uint32 pipe1EdgeRtr: 1; // 30
		uint32 useStoredInnerQRing3: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG3
union VgtDebugReg3 {
	struct {
		uint32 lstgrelind: 12; // 0
		uint32 lswaverelind: 6; // 12
		uint32 lspatchcnt: 8; // 18
		uint32 hswaverelind: 6; // 26
	};
	uint32 val;
};

// VGT_DEBUG_REG30
union VgtDebugReg30 {
	struct {
		uint32 pipe0Dr: 1; // 0
		uint32 pipe0TfDr: 1; // 1
		uint32 pipe2Dr: 1; // 2
		uint32 eventOrNullP0Q: 1; // 3
		uint32 pipe0Rtr: 1; // 4
		uint32 pipe1Rtr: 1; // 5
		uint32 pipe1TfRtr: 1; // 6
		uint32 pipe2Rtr: 1; // 7
		uint32 ttpPatchFifoFull: 1; // 8
		uint32 ttpPatchFifoEmpty: 1; // 9
		uint32 ttpTf0FifoEmpty: 1; // 10
		uint32 ttpTf1FifoEmpty: 1; // 11
		uint32 ttpTf2FifoEmpty: 1; // 12
		uint32 ttpTf3FifoEmpty: 1; // 13
		uint32 ttpTf4FifoEmpty: 1; // 14
		uint32 ttpTf5FifoEmpty: 1; // 15
		uint32 tfFetchStateQ: 3; // 16
		uint32 lastTfOfTg: 1; // 19
		uint32 tfPointerP0Q: 4; // 20
		uint32 dynamicHsP0Q: 1; // 24
		uint32 firstFetchOfTgP0Q: 1; // 25
		uint32 firstDataRetOfReqP0Q: 1; // 26
		uint32 firstDataChunkInvalidP0Q: 1; // 27
		uint32 tfXferCountP2Q: 2; // 28
		uint32 pipe4Dr: 1; // 30
		uint32 pipe4Rtr: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG31
union VgtDebugReg31 {
	struct {
		uint32 pipe0Dr: 1; // 0
		uint32 pipe0Rtr: 1; // 1
		uint32 pipe1OuterDr: 1; // 2
		uint32 pipe1InnerDr: 1; // 3
		uint32 pipe2OuterDr: 1; // 4
		uint32 pipe2InnerDr: 1; // 5
		uint32 pipe3OuterDr: 1; // 6
		uint32 pipe3InnerDr: 1; // 7
		uint32 pipe4OuterDr: 1; // 8
		uint32 pipe4InnerDr: 1; // 9
		uint32 pipe5OuterDr: 1; // 10
		uint32 pipe5InnerDr: 1; // 11
		uint32 pipe2OuterRtr: 1; // 12
		uint32 pipe2InnerRtr: 1; // 13
		uint32 pipe3OuterRtr: 1; // 14
		uint32 pipe3InnerRtr: 1; // 15
		uint32 pipe4OuterRtr: 1; // 16
		uint32 pipe4InnerRtr: 1; // 17
		uint32 pipe5OuterRtr: 1; // 18
		uint32 pipe5InnerRtr: 1; // 19
		uint32 pgConOuterPoint1Rts: 1; // 20
		uint32 pgConOuterPoint2Rts: 1; // 21
		uint32 pgConInnerPoint1Rts: 1; // 22
		uint32 pgConInnerPoint2Rts: 1; // 23
		uint32 pgPatchFifoEmpty: 1; // 24
		uint32 pgEdgeFifoEmpty: 1; // 25
		uint32 pgInner3PerpFifoEmpty: 1; // 26
		uint32 pgPatchFifoFull: 1; // 27
		uint32 pgEdgeFifoFull: 1; // 28
		uint32 pgInnerPerpFifoFull: 1; // 29
		uint32 outerRingDoneQ: 1; // 30
		uint32 innerRingDoneQ: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG32
union VgtDebugReg32 {
	struct {
		uint32 firstRingOfPatch: 1; // 0
		uint32 lastRingOfPatch: 1; // 1
		uint32 lastEdgeOfOuterRing: 1; // 2
		uint32 lastPointOfOuterEdge: 1; // 3
		uint32 lastEdgeOfInnerRing: 1; // 4
		uint32 lastPointOfInnerEdge: 1; // 5
		uint32 lastPatchOfTgP0Q: 1; // 6
		uint32 eventNullSpecialP0Q: 1; // 7
		uint32 eventFlagP5Q: 1; // 8
		uint32 firstPointOfPatchP5Q: 1; // 9
		uint32 firstPointOfEdgeP5Q: 1; // 10
		uint32 lastPatchOfTgP5Q: 1; // 11
		uint32 tessTopologyP5Q: 2; // 12
		uint32 pipe5Inner3Rtr: 1; // 14
		uint32 pipe5Inner2Rtr: 1; // 15
		uint32 pgEdgeFifo3Full: 1; // 16
		uint32 pgEdgeFifo2Full: 1; // 17
		uint32 pgInner3PointFifoFull: 1; // 18
		uint32 pgOuter3PointFifoFull: 1; // 19
		uint32 pgInner2PointFifoFull: 1; // 20
		uint32 pgOuter2PointFifoFull: 1; // 21
		uint32 pgInnerPointFifoFull: 1; // 22
		uint32 pgOuterPointFifoFull: 1; // 23
		uint32 inner2FifosRtr: 1; // 24
		uint32 innerFifosRtr: 1; // 25
		uint32 outerFifosRtr: 1; // 26
		uint32 fifosRtr: 1; // 27
		uint32 unknown1: 3;
		uint32 spare: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG33
union VgtDebugReg33 {
	struct {
		uint32 pipe0PatchDr: 1; // 0
		uint32 ring3Pipe1Dr: 1; // 1
		uint32 pipe1Dr: 1; // 2
		uint32 pipe2Dr: 1; // 3
		uint32 pipe0PatchRtr: 1; // 4
		uint32 ring2Pipe1Dr: 1; // 5
		uint32 ring1Pipe1Dr: 1; // 6
		uint32 pipe2Rtr: 1; // 7
		uint32 pipe3Dr: 1; // 8
		uint32 pipe3Rtr: 1; // 9
		uint32 ring2InSyncQ: 1; // 10
		uint32 ring1InSyncQ: 1; // 11
		uint32 pipe1PatchRtr: 1; // 12
		uint32 ring3InSyncQ: 1; // 13
		uint32 tmTe11EventRtr: 1; // 14
		uint32 firstPrimOfPatchQ: 1; // 15
		uint32 conPrimFifoFull: 1; // 16
		uint32 conVertFifoFull: 1; // 17
		uint32 conPrimFifoEmpty: 1; // 18
		uint32 conVertFifoEmpty: 1; // 19
		uint32 lastPatchOfTgP0Q: 1; // 20
		uint32 ring3ValidP2: 1; // 21
		uint32 ring2ValidP2: 1; // 22
		uint32 ring1ValidP2: 1; // 23
		uint32 tessTypeP0Q: 2; // 24
		uint32 tessTopologyP0Q: 2; // 26
		uint32 te11OutVertGsEn: 1; // 28
		uint32 conRing3Busy: 1; // 29
		uint32 conRing2Busy: 1; // 30
		uint32 conRing1Busy: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG34
union VgtDebugReg34 {
	struct {
		uint32 conStateQ: 4; // 0
		uint32 secondCycleQ: 1; // 4
		uint32 processTriMiddleP0Q: 1; // 5
		uint32 processTri1st2ndHalfP0Q: 1; // 6
		uint32 processTriCenterPolyP0Q: 1; // 7
		uint32 pipe0PatchDr: 1; // 8
		uint32 pipe0EdgeDr: 1; // 9
		uint32 pipe1Dr: 1; // 10
		uint32 pipe0PatchRtr: 1; // 11
		uint32 pipe0EdgeRtr: 1; // 12
		uint32 pipe1Rtr: 1; // 13
		uint32 outerParityP0Q: 1; // 14
		uint32 parallelParityP0Q: 1; // 15
		uint32 firstRingOfPatchP0Q: 1; // 16
		uint32 lastRingOfPatchP0Q: 1; // 17
		uint32 lastEdgeOfOuterRingP0Q: 1; // 18
		uint32 lastPointOfOuterRingP1: 1; // 19
		uint32 lastPointOfInnerRingP1: 1; // 20
		uint32 outerEdgeTfEqOneP0Q: 1; // 21
		uint32 advanceOuterPointP1: 1; // 22
		uint32 advanceInnerPointP1: 1; // 23
		uint32 nextRingIsRectP0Q: 1; // 24
		uint32 pipe1Outer1Rtr: 1; // 25
		uint32 pipe1Outer2Rtr: 1; // 26
		uint32 pipe1Inner1Rtr: 1; // 27
		uint32 pipe1Inner2Rtr: 1; // 28
		uint32 pipe1PatchRtr: 1; // 29
		uint32 pipe1EdgeRtr: 1; // 30
		uint32 useStoredInnerQRing1: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG35
union VgtDebugReg35 {
	struct {
		uint32 pipe0Dr: 1; // 0
		uint32 pipe1Dr: 1; // 1
		uint32 pipe0Rtr: 1; // 2
		uint32 pipe1Rtr: 1; // 3
		uint32 tfreqTgFifoEmpty: 1; // 4
		uint32 tfreqTgFifoFull: 1; // 5
		uint32 tfDataFifoBusyQ: 1; // 6
		uint32 tfDataFifoRtrQ: 1; // 7
		uint32 tfSkidFifoEmpty: 1; // 8
		uint32 tfSkidFifoFull: 1; // 9
		uint32 vgtTcRdreqRtrQ: 1; // 10
		uint32 lastReqOfTgP2: 1; // 11
		uint32 spiVgtHsDoneCntQ: 6; // 12
		uint32 eventFlagP1Q: 1; // 18
		uint32 nullFlagP1Q: 1; // 19
		uint32 tfDataFifoCntQ: 7; // 20
		uint32 secondTfRetDataQ: 1; // 27
		uint32 firstReqOfTgP1Q: 1; // 28
		uint32 vgtTcRdreqSendOut: 1; // 29
		uint32 vgtTcRdnfoStallOut: 1; // 30
		uint32 tcVgtRdretDataIn: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG4
union VgtDebugReg4 {
	struct {
		uint32 spare: 32; // 0
		// uint32 unknown1: -24;
		// uint32 hsprimid15_0: 16;
		// uint32 unknown2: -8;
		// uint32 hscpcnt: 5;
		// uint32 unknown3: -3;
		// uint32 hswavesendflush: 1;
		// uint32 unknown4: -2;
		// uint32 hsfwaveflag: 1;
	};
	uint32 val;
};

// VGT_DEBUG_REG5
union VgtDebugReg5 {
	struct {
		uint32 spare4: 3; // 0
		uint32 hswavecreditcnt0: 5; // 3
		uint32 spare3: 3; // 8
		uint32 hsvertcreditcnt0: 5; // 11
		uint32 spare2: 3; // 16
		uint32 lswavecreditcnt0: 5; // 19
		uint32 spare1: 3; // 24
		uint32 lsvertcreditcnt0: 5; // 27
	};
	uint32 val;
};

// VGT_DEBUG_REG6
union VgtDebugReg6 {
	struct {
		uint32 debugBase: 16; // 0
		uint32 debugSize: 16; // 16
	};
	uint32 val;
};

// VGT_DEBUG_REG7
union VgtDebugReg7 {
	struct {
		uint32 debugTfmmfifoempty: 1; // 0
		uint32 debugTfmmfifofull: 1; // 1
		uint32 hsPipe0Dr: 1; // 2
		uint32 hsPipe0Rtr: 1; // 3
		uint32 hsPipe1Rtr: 1; // 4
		uint32 spare: 11; // 5
		uint32 tfAddr: 16; // 16
	};
	uint32 val;
};

// VGT_DEBUG_REG8
union VgtDebugReg8 {
	struct {
		uint32 rcmBusyQ: 1; // 0
		uint32 rcmNoifBusyQ: 1; // 1
		uint32 r1InstRtr: 1; // 2
		uint32 spiGsprimFifoBusyQ: 1; // 3
		uint32 spiEsvertFifoBusyQ: 1; // 4
		uint32 gsTblValidR3Q: 1; // 5
		uint32 validR0Q: 1; // 6
		uint32 validR1Q: 1; // 7
		uint32 validR2: 1; // 8
		uint32 validR2Q: 1; // 9
		uint32 r0Rtr: 1; // 10
		uint32 r1Rtr: 1; // 11
		uint32 r2IndxRtr: 1; // 12
		uint32 r2Rtr: 1; // 13
		uint32 esGsRtr: 1; // 14
		uint32 gsEventFifoRtr: 1; // 15
		uint32 tmRcmGsEventRtr: 1; // 16
		uint32 gsTblR3Rtr: 1; // 17
		uint32 primSkidFifoEmpty: 1; // 18
		uint32 vgtSpiGsprimRtrQ: 1; // 19
		uint32 tmRcmGsTblRtr: 1; // 20
		uint32 tmRcmEsTblRtr: 1; // 21
		uint32 vgtSpiEsvertRtrQ: 1; // 22
		uint32 r2NoBpRtr: 1; // 23
		uint32 holdForEsFlush: 1; // 24
		uint32 gsEventFifoEmpty: 1; // 25
		uint32 gsprimBuffEmptyQ: 1; // 26
		uint32 gsprimBuffFullQ: 1; // 27
		uint32 tePrimFifoEmpty: 1; // 28
		uint32 tePrimFifoFull: 1; // 29
		uint32 teVertFifoEmpty: 1; // 30
		uint32 teVertFifoFull: 1; // 31
	};
	uint32 val;
};

// VGT_DEBUG_REG9
union VgtDebugReg9 {
	struct {
		uint32 indicesToSendR2Q: 2; // 0
		uint32 validIndicesR3: 1; // 2
		uint32 gsEovR3: 1; // 3
		uint32 eopIndxR3: 1; // 4
		uint32 eopPrimR3: 1; // 5
		uint32 esEovR3: 1; // 6
		uint32 esTblStateR3Q0: 1; // 7
		uint32 pendingEsSendR3Q: 1; // 8
		uint32 pendingEsFlushR3: 1; // 9
		uint32 gsTblNumEsPerGsR3QNot0: 1; // 10
		uint32 gsTblPrimCntR3Q: 7; // 11
		uint32 gsTblEopR3Q: 1; // 18
		uint32 gsTblStateR3Q: 3; // 19
		uint32 gsPendingStateR3Q: 1; // 22
		uint32 invalidateRbRollOverQ: 1; // 23
		uint32 gsInstancingStateQ: 1; // 24
		uint32 esPerGsVertCntR3QNot0: 1; // 25
		uint32 gsPrimPerEsCtrR3QNot0: 1; // 26
		uint32 preR0Rtr: 1; // 27
		uint32 validR3Q: 1; // 28
		uint32 validPreR0Q: 1; // 29
		uint32 spare0: 1; // 30
		uint32 offChipHsR2Q: 1; // 31
	};
	uint32 val;
};

// VGT_DMA_BASE
union VgtDmaBase {
	struct {
		uint32 baseAddr: 32; // 0
	};
	uint32 val;
};

// VGT_DMA_BASE_HI
union VgtDmaBaseHi {
	struct {
		uint32 baseAddr: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// VGT_DMA_DATA_FIFO_DEPTH
union VgtDmaDataFifoDepth {
	struct {
		uint32 dmaDataFifoDepth: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// VGT_DMA_INDEX_TYPE
union VgtDmaIndexType {
	struct {
		uint32 indexType: 2; // 0
		uint32 swapMode: 2; // 2
		uint32 bufType: 2; // 4
		uint32 rdreqPolicy: 2; // 6
		uint32 atc: 1; // 8
		uint32 notEop: 1; // 9
		uint32 reqPath: 1; // 10
		uint32 unknown1: 21;
	};
	uint32 val;
};

// VGT_DMA_MAX_SIZE
union VgtDmaMaxSize {
	struct {
		uint32 maxSize: 32; // 0
	};
	uint32 val;
};

// VGT_DMA_NUM_INSTANCES
union VgtDmaNumInstances {
	struct {
		uint32 numInstances: 32; // 0
	};
	uint32 val;
};

// VGT_DMA_REQ_FIFO_DEPTH
union VgtDmaReqFifoDepth {
	struct {
		uint32 dmaReqFifoDepth: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// VGT_DMA_SIZE
union VgtDmaSize {
	struct {
		uint32 numIndices: 32; // 0
	};
	uint32 val;
};

// VGT_DRAW_INITIATOR
union VgtDrawInitiator {
	struct {
		uint32 sourceSelect: 2; // 0
		uint32 majorMode: 2; // 2
		uint32 spriteEnR6xx: 1; // 4
		uint32 notEop: 1; // 5
		uint32 useOpaque: 1; // 6
		uint32 unknown1: 25;
	};
	uint32 val;
};

// VGT_DRAW_INIT_FIFO_DEPTH
union VgtDrawInitFifoDepth {
	struct {
		uint32 drawInitFifoDepth: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// VGT_ENHANCE
union VgtEnhance {
	struct {
		uint32 misc: 32; // 0
	};
	uint32 val;
};

// VGT_ESGS_RING_ITEMSIZE
union VgtEsgsRingItemsize {
	struct {
		uint32 itemsize: 15; // 0
		uint32 unknown1: 17;
	};
	uint32 val;
};

// VGT_ESGS_RING_SIZE
union VgtEsgsRingSize {
	struct {
		uint32 memSize: 32; // 0
	};
	uint32 val;
};

// VGT_ES_PER_GS
union VgtEsPerGs {
	struct {
		uint32 esPerGs: 11; // 0
		uint32 unknown1: 21;
	};
	uint32 val;
};

// VGT_EVENT_ADDRESS_REG
union VgtEventAddressReg {
	struct {
		uint32 addressLow: 28; // 0
		uint32 unknown1: 4;
	};
	uint32 val;
};

// VGT_EVENT_INITIATOR
union VgtEventInitiator {
	struct {
		uint32 eventType: 6; // 0
		uint32 unknown1: 12;
		uint32 addressHi: 9; // 18
		uint32 extendedEvent: 1; // 27
		uint32 unknown2: 4;
	};
	uint32 val;
};

// VGT_FIFO_DEPTHS
union VgtFifoDepths {
	struct {
		uint32 vsDeallocTblDepth: 7; // 0
		uint32 reserved0: 1; // 7
		uint32 clippFifoDepth: 14; // 8
		uint32 reserved1: 10; // 22
	};
	uint32 val;
};

// VGT_GROUP_DECR
union VgtGroupDecr {
	struct {
		uint32 decr: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// VGT_GROUP_FIRST_DECR
union VgtGroupFirstDecr {
	struct {
		uint32 firstDecr: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// VGT_GROUP_PRIM_TYPE
union VgtGroupPrimType {
	struct {
		uint32 primType: 5; // 0
		uint32 unknown1: 9;
		uint32 retainOrder: 1; // 14
		uint32 retainQuads: 1; // 15
		uint32 primOrder: 3; // 16
		uint32 unknown2: 13;
	};
	uint32 val;
};

// VGT_GROUP_VECT_0_CNTL
union VgtGroupVect0Cntl {
	struct {
		uint32 compXEn: 1; // 0
		uint32 compYEn: 1; // 1
		uint32 compZEn: 1; // 2
		uint32 compWEn: 1; // 3
		uint32 unknown1: 4;
		uint32 stride: 8; // 8
		uint32 shift: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// VGT_GROUP_VECT_0_FMT_CNTL
union VgtGroupVect0FmtCntl {
	struct {
		uint32 xConv: 4; // 0
		uint32 xOffset: 4; // 4
		uint32 yConv: 4; // 8
		uint32 yOffset: 4; // 12
		uint32 zConv: 4; // 16
		uint32 zOffset: 4; // 20
		uint32 wConv: 4; // 24
		uint32 wOffset: 4; // 28
	};
	uint32 val;
};

// VGT_GROUP_VECT_1_CNTL
union VgtGroupVect1Cntl {
	struct {
		uint32 compXEn: 1; // 0
		uint32 compYEn: 1; // 1
		uint32 compZEn: 1; // 2
		uint32 compWEn: 1; // 3
		uint32 unknown1: 4;
		uint32 stride: 8; // 8
		uint32 shift: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// VGT_GROUP_VECT_1_FMT_CNTL
union VgtGroupVect1FmtCntl {
	struct {
		uint32 xConv: 4; // 0
		uint32 xOffset: 4; // 4
		uint32 yConv: 4; // 8
		uint32 yOffset: 4; // 12
		uint32 zConv: 4; // 16
		uint32 zOffset: 4; // 20
		uint32 wConv: 4; // 24
		uint32 wOffset: 4; // 28
	};
	uint32 val;
};

// VGT_GSVS_RING_ITEMSIZE
union VgtGsvsRingItemsize {
	struct {
		uint32 itemsize: 15; // 0
		uint32 unknown1: 17;
	};
	uint32 val;
};

// VGT_GSVS_RING_OFFSET_1
union VgtGsvsRingOffset1 {
	struct {
		uint32 offset: 15; // 0
		uint32 unknown1: 17;
	};
	uint32 val;
};

// VGT_GSVS_RING_OFFSET_2
union VgtGsvsRingOffset2 {
	struct {
		uint32 offset: 15; // 0
		uint32 unknown1: 17;
	};
	uint32 val;
};

// VGT_GSVS_RING_OFFSET_3
union VgtGsvsRingOffset3 {
	struct {
		uint32 offset: 15; // 0
		uint32 unknown1: 17;
	};
	uint32 val;
};

// VGT_GSVS_RING_SIZE
union VgtGsvsRingSize {
	struct {
		uint32 memSize: 32; // 0
	};
	uint32 val;
};

// VGT_GS_INSTANCE_CNT
union VgtGsInstanceCnt {
	struct {
		uint32 enable: 1; // 0
		uint32 unknown1: 1;
		uint32 cnt: 7; // 2
		uint32 unknown2: 23;
	};
	uint32 val;
};

// VGT_GS_MAX_VERT_OUT
union VgtGsMaxVertOut {
	struct {
		uint32 maxVertOut: 11; // 0
		uint32 unknown1: 21;
	};
	uint32 val;
};

// VGT_GS_MODE
union VgtGsMode {
	struct {
		uint32 mode: 3; // 0
		uint32 reserved0: 1; // 3
		uint32 cutMode: 2; // 4
		uint32 reserved1: 5; // 6
		uint32 gsCPackEn: 1; // 11
		uint32 reserved2: 1; // 12
		uint32 esPassthru: 1; // 13
		uint32 computeMode: 1; // 14
		uint32 fastComputeMode: 1; // 15
		uint32 elementInfoEn: 1; // 16
		uint32 partialThdAtEoi: 1; // 17
		uint32 suppressCuts: 1; // 18
		uint32 esWriteOptimize: 1; // 19
		uint32 gsWriteOptimize: 1; // 20
		uint32 onchip: 2; // 21
		uint32 unknown1: 9;
	};
	uint32 val;
};

// VGT_GS_OUT_PRIM_TYPE
union VgtGsOutPrimType {
	struct {
		uint32 outprimType: 6; // 0
		uint32 unknown1: 2;
		uint32 outprimType1: 6; // 8
		uint32 unknown2: 2;
		uint32 outprimType2: 6; // 16
		uint32 outprimType3: 6; // 22
		uint32 unknown3: 3;
		uint32 uniqueTypePerStream: 1; // 31
	};
	uint32 val;
};

// VGT_GS_PER_ES
union VgtGsPerEs {
	struct {
		uint32 gsPerEs: 11; // 0
		uint32 unknown1: 21;
	};
	uint32 val;
};

// VGT_GS_PER_VS
union VgtGsPerVs {
	struct {
		uint32 gsPerVs: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// VGT_GS_VERTEX_REUSE
union VgtGsVertexReuse {
	struct {
		uint32 vertReuse: 5; // 0
		uint32 unknown1: 27;
	};
	uint32 val;
};

// VGT_GS_VERT_ITEMSIZE
union VgtGsVertItemsize {
	struct {
		uint32 itemsize: 15; // 0
		uint32 unknown1: 17;
	};
	uint32 val;
};

// VGT_GS_VERT_ITEMSIZE_1
union VgtGsVertItemsize1 {
	struct {
		uint32 itemsize: 15; // 0
		uint32 unknown1: 17;
	};
	uint32 val;
};

// VGT_GS_VERT_ITEMSIZE_2
union VgtGsVertItemsize2 {
	struct {
		uint32 itemsize: 15; // 0
		uint32 unknown1: 17;
	};
	uint32 val;
};

// VGT_GS_VERT_ITEMSIZE_3
union VgtGsVertItemsize3 {
	struct {
		uint32 itemsize: 15; // 0
		uint32 unknown1: 17;
	};
	uint32 val;
};

// VGT_HOS_CNTL
union VgtHosCntl {
	struct {
		uint32 tessMode: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// VGT_HOS_MAX_TESS_LEVEL
union VgtHosMaxTessLevel {
	struct {
		uint32 maxTess: 32; // 0
	};
	uint32 val;
};

// VGT_HOS_MIN_TESS_LEVEL
union VgtHosMinTessLevel {
	struct {
		uint32 minTess: 32; // 0
	};
	uint32 val;
};

// VGT_HOS_REUSE_DEPTH
union VgtHosReuseDepth {
	struct {
		uint32 reuseDepth: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// VGT_HS_OFFCHIP_PARAM
union VgtHsOffchipParam {
	struct {
		uint32 offchipBuffering: 7; // 0
		uint32 unknown1: 2;
		uint32 offchipGranularity: 2; // 9
		uint32 unknown2: 21;
	};
	uint32 val;
};

// VGT_IMMED_DATA
union VgtImmedData {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

// VGT_INDEX_TYPE
union VgtIndexType {
	struct {
		uint32 indexType: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// VGT_INDX_OFFSET
union VgtIndxOffset {
	struct {
		uint32 indxOffset: 32; // 0
	};
	uint32 val;
};

// VGT_INSTANCE_STEP_RATE_0
union VgtInstanceStepRate0 {
	struct {
		uint32 stepRate: 32; // 0
	};
	uint32 val;
};

// VGT_INSTANCE_STEP_RATE_1
union VgtInstanceStepRate1 {
	struct {
		uint32 stepRate: 32; // 0
	};
	uint32 val;
};

// VGT_LAST_COPY_STATE
union VgtLastCopyState {
	struct {
		uint32 srcStateId: 3; // 0
		uint32 unknown1: 13;
		uint32 dstStateId: 3; // 16
		uint32 unknown2: 13;
	};
	uint32 val;
};

// VGT_LS_HS_CONFIG
union VgtLsHsConfig {
	struct {
		uint32 numPatches: 8; // 0
		uint32 hsNumInputCp: 6; // 8
		uint32 hsNumOutputCp: 6; // 14
		uint32 unknown1: 12;
	};
	uint32 val;
};

// VGT_MAX_VTX_INDX
union VgtMaxVtxIndx {
	struct {
		uint32 maxIndx: 32; // 0
	};
	uint32 val;
};

// VGT_MC_LAT_CNTL
union VgtMcLatCntl {
	struct {
		uint32 mcTimeStampRes: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// VGT_MIN_VTX_INDX
union VgtMinVtxIndx {
	struct {
		uint32 minIndx: 32; // 0
	};
	uint32 val;
};

// VGT_MULTI_PRIM_IB_RESET_EN
union VgtMultiPrimIbResetEn {
	struct {
		uint32 resetEn: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// VGT_MULTI_PRIM_IB_RESET_INDX
union VgtMultiPrimIbResetIndx {
	struct {
		uint32 resetIndx: 32; // 0
	};
	uint32 val;
};

// VGT_NUM_INDICES
union VgtNumIndices {
	struct {
		uint32 numIndices: 32; // 0
	};
	uint32 val;
};

// VGT_NUM_INSTANCES
union VgtNumInstances {
	struct {
		uint32 numInstances: 32; // 0
	};
	uint32 val;
};

// VGT_OUTPUT_PATH_CNTL
union VgtOutputPathCntl {
	struct {
		uint32 pathSelect: 3; // 0
		uint32 unknown1: 29;
	};
	uint32 val;
};

// VGT_OUT_DEALLOC_CNTL
union VgtOutDeallocCntl {
	struct {
		uint32 deallocDist: 7; // 0
		uint32 unknown1: 25;
	};
	uint32 val;
};

// VGT_PERFCOUNTER0_HI
union VgtPerfcounter0Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// VGT_PERFCOUNTER0_LO
union VgtPerfcounter0Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// VGT_PERFCOUNTER0_SELECT
union VgtPerfcounter0Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// VGT_PERFCOUNTER0_SELECT1
union VgtPerfcounter0Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 4;
		uint32 perfMode3: 4; // 24
		uint32 perfMode2: 4; // 28
	};
	uint32 val;
};

// VGT_PERFCOUNTER1_HI
union VgtPerfcounter1Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// VGT_PERFCOUNTER1_LO
union VgtPerfcounter1Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// VGT_PERFCOUNTER1_SELECT
union VgtPerfcounter1Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 2;
		uint32 perfSel1: 10; // 10
		uint32 cntrMode: 4; // 20
		uint32 perfMode1: 4; // 24
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// VGT_PERFCOUNTER1_SELECT1
union VgtPerfcounter1Select1 {
	struct {
		uint32 perfSel2: 10; // 0
		uint32 perfSel3: 10; // 10
		uint32 unknown1: 4;
		uint32 perfMode3: 4; // 24
		uint32 perfMode2: 4; // 28
	};
	uint32 val;
};

// VGT_PERFCOUNTER2_HI
union VgtPerfcounter2Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// VGT_PERFCOUNTER2_LO
union VgtPerfcounter2Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// VGT_PERFCOUNTER2_SELECT
union VgtPerfcounter2Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 20;
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// VGT_PERFCOUNTER3_HI
union VgtPerfcounter3Hi {
	struct {
		uint32 perfcounterHi: 32; // 0
	};
	uint32 val;
};

// VGT_PERFCOUNTER3_LO
union VgtPerfcounter3Lo {
	struct {
		uint32 perfcounterLo: 32; // 0
	};
	uint32 val;
};

// VGT_PERFCOUNTER3_SELECT
union VgtPerfcounter3Select {
	struct {
		uint32 perfSel: 8; // 0
		uint32 unknown1: 20;
		uint32 perfMode: 4; // 28
	};
	uint32 val;
};

// VGT_PERFCOUNTER_SEID_MASK
union VgtPerfcounterSeidMask {
	struct {
		uint32 perfSeidIgnoreMask: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// VGT_PRIMITIVEID_EN
union VgtPrimitiveidEn {
	struct {
		uint32 primitiveidEn: 1; // 0
		uint32 disableResetOnEoi: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// VGT_PRIMITIVEID_RESET
union VgtPrimitiveidReset {
	struct {
		uint32 value: 32; // 0
	};
	uint32 val;
};

// VGT_PRIMITIVE_TYPE
union VgtPrimitiveType {
	struct {
		uint32 primType: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// VGT_REUSE_OFF
union VgtReuseOff {
	struct {
		uint32 reuseOff: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// VGT_SHADER_STAGES_EN
union VgtShaderStagesEn {
	struct {
		uint32 lsEn: 2; // 0
		uint32 hsEn: 1; // 2
		uint32 esEn: 2; // 3
		uint32 gsEn: 1; // 5
		uint32 vsEn: 2; // 6
		uint32 dynamicHs: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// VGT_STRMOUT_BUFFER_CONFIG
union VgtStrmoutBufferConfig {
	struct {
		uint32 stream0BufferEn: 4; // 0
		uint32 stream1BufferEn: 4; // 4
		uint32 stream2BufferEn: 4; // 8
		uint32 stream3BufferEn: 4; // 12
		uint32 unknown1: 16;
	};
	uint32 val;
};

// VGT_STRMOUT_BUFFER_FILLED_SIZE_0
union VgtStrmoutBufferFilledSize0 {
	struct {
		uint32 size: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_BUFFER_FILLED_SIZE_1
union VgtStrmoutBufferFilledSize1 {
	struct {
		uint32 size: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_BUFFER_FILLED_SIZE_2
union VgtStrmoutBufferFilledSize2 {
	struct {
		uint32 size: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_BUFFER_FILLED_SIZE_3
union VgtStrmoutBufferFilledSize3 {
	struct {
		uint32 size: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_BUFFER_OFFSET_0
union VgtStrmoutBufferOffset0 {
	struct {
		uint32 offset: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_BUFFER_OFFSET_1
union VgtStrmoutBufferOffset1 {
	struct {
		uint32 offset: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_BUFFER_OFFSET_2
union VgtStrmoutBufferOffset2 {
	struct {
		uint32 offset: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_BUFFER_OFFSET_3
union VgtStrmoutBufferOffset3 {
	struct {
		uint32 offset: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_BUFFER_SIZE_0
union VgtStrmoutBufferSize0 {
	struct {
		uint32 size: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_BUFFER_SIZE_1
union VgtStrmoutBufferSize1 {
	struct {
		uint32 size: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_BUFFER_SIZE_2
union VgtStrmoutBufferSize2 {
	struct {
		uint32 size: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_BUFFER_SIZE_3
union VgtStrmoutBufferSize3 {
	struct {
		uint32 size: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_CONFIG
union VgtStrmoutConfig {
	struct {
		uint32 streamout0En: 1; // 0
		uint32 streamout1En: 1; // 1
		uint32 streamout2En: 1; // 2
		uint32 streamout3En: 1; // 3
		uint32 rastStream: 3; // 4
		uint32 unknown1: 1;
		uint32 rastStreamMask: 4; // 8
		uint32 unknown2: 19;
		uint32 useRastStreamMask: 1; // 31
	};
	uint32 val;
};

// VGT_STRMOUT_DRAW_OPAQUE_BUFFER_FILLED_SIZE
union VgtStrmoutDrawOpaqueBufferFilledSize {
	struct {
		uint32 size: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_DRAW_OPAQUE_OFFSET
union VgtStrmoutDrawOpaqueOffset {
	struct {
		uint32 offset: 32; // 0
	};
	uint32 val;
};

// VGT_STRMOUT_DRAW_OPAQUE_VERTEX_STRIDE
union VgtStrmoutDrawOpaqueVertexStride {
	struct {
		uint32 vertexStride: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// VGT_STRMOUT_VTX_STRIDE_0
union VgtStrmoutVtxStride0 {
	struct {
		uint32 stride: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// VGT_STRMOUT_VTX_STRIDE_1
union VgtStrmoutVtxStride1 {
	struct {
		uint32 stride: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// VGT_STRMOUT_VTX_STRIDE_2
union VgtStrmoutVtxStride2 {
	struct {
		uint32 stride: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// VGT_STRMOUT_VTX_STRIDE_3
union VgtStrmoutVtxStride3 {
	struct {
		uint32 stride: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// VGT_SYS_CONFIG
union VgtSysConfig {
	struct {
		uint32 dualCoreEn: 1; // 0
		uint32 maxLsHsThdgrp: 6; // 1
		uint32 adcEventFilterDisable: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// VGT_TF_MEMORY_BASE
union VgtTfMemoryBase {
	struct {
		uint32 base: 32; // 0
	};
	uint32 val;
};

// VGT_TF_PARAM
union VgtTfParam {
	struct {
		uint32 type: 2; // 0
		uint32 partitioning: 3; // 2
		uint32 topology: 3; // 5
		uint32 reservedReducAxis: 1; // 8
		uint32 deprecated: 1; // 9
		uint32 numDsWavesPerSimd: 4; // 10
		uint32 disableDonuts: 1; // 14
		uint32 rdreqPolicy: 2; // 15
		uint32 unknown1: 15;
	};
	uint32 val;
};

// VGT_TF_RING_SIZE
union VgtTfRingSize {
	struct {
		uint32 size: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// VGT_VERTEX_REUSE_BLOCK_CNTL
union VgtVertexReuseBlockCntl {
	struct {
		uint32 vtxReuseDepth: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// VGT_VTX_CNT_EN
union VgtVtxCntEn {
	struct {
		uint32 vtxCntEn: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// VGT_VTX_VECT_EJECT_REG
union VgtVtxVectEjectReg {
	struct {
		uint32 primCount: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// WD_DEBUG_DATA
union WdDebugData {
	struct {
		uint32 data: 32; // 0
	};
	uint32 val;
};

