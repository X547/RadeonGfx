#pragma once
#include <SupportDefs.h>

// ABM_TEST_DEBUG_DATA
union AbmTestDebugData {
	struct {
		uint32 abmTestDebugData: 32; // 0
	};
	uint32 val;
};

// ABM_TEST_DEBUG_INDEX
union AbmTestDebugIndex {
	struct {
		uint32 abmTestDebugIndex: 8; // 0
		uint32 abmTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// AFMT_60958_0
union Afmt60958_0 {
	struct {
		uint32 afmt60958CsA: 1; // 0
		uint32 afmt60958CsB: 1; // 1
		uint32 afmt60958CsC: 1; // 2
		uint32 afmt60958CsD: 3; // 3
		uint32 afmt60958CsMode: 2; // 6
		uint32 afmt60958CsCategoryCode: 8; // 8
		uint32 afmt60958CsSourceNumber: 4; // 16
		uint32 afmt60958CsChannelNumberL: 4; // 20
		uint32 afmt60958CsSamplingFrequency: 4; // 24
		uint32 afmt60958CsClockAccuracy: 2; // 28
		uint32 unknown1: 2;
	};
	uint32 val;
};

// AFMT_60958_1
union Afmt60958_1 {
	struct {
		uint32 afmt60958CsWordLength: 4; // 0
		uint32 afmt60958CsOriginalSamplingFrequency: 4; // 4
		uint32 unknown1: 8;
		uint32 afmt60958ValidL: 1; // 16
		uint32 unknown2: 1;
		uint32 afmt60958ValidR: 1; // 18
		uint32 unknown3: 1;
		uint32 afmt60958CsChannelNumberR: 4; // 20
		uint32 unknown4: 8;
	};
	uint32 val;
};

// AFMT_60958_2
union Afmt60958_2 {
	struct {
		uint32 afmt60958CsChannelNumber2: 4; // 0
		uint32 afmt60958CsChannelNumber3: 4; // 4
		uint32 afmt60958CsChannelNumber4: 4; // 8
		uint32 afmt60958CsChannelNumber5: 4; // 12
		uint32 afmt60958CsChannelNumber6: 4; // 16
		uint32 afmt60958CsChannelNumber7: 4; // 20
		uint32 unknown1: 8;
	};
	uint32 val;
};

// AFMT_AUDIO_CRC_CONTROL
union AfmtAudioCrcControl {
	struct {
		uint32 afmtAudioCrcEn: 1; // 0
		uint32 unknown1: 3;
		uint32 afmtAudioCrcCont: 1; // 4
		uint32 unknown2: 3;
		uint32 afmtAudioCrcSource: 1; // 8
		uint32 unknown3: 3;
		uint32 afmtAudioCrcChSel: 4; // 12
		uint32 afmtAudioCrcCount: 16; // 16
	};
	uint32 val;
};

// AFMT_AUDIO_CRC_RESULT
union AfmtAudioCrcResult {
	struct {
		uint32 afmtAudioCrcDone: 1; // 0
		uint32 unknown1: 7;
		uint32 afmtAudioCrc: 24; // 8
	};
	uint32 val;
};

// AFMT_AUDIO_DBG_DTO_CNTL
union AfmtAudioDbgDtoCntl {
	struct {
		uint32 afmtAudioDtoFsDivSel: 3; // 0
		uint32 unknown1: 5;
		uint32 afmtAudioDtoDbgBase: 1; // 8
		uint32 unknown2: 3;
		uint32 afmtAudioDtoDbgMulti: 3; // 12
		uint32 unknown3: 1;
		uint32 afmtAudioDtoDbgDiv: 3; // 16
		uint32 unknown4: 13;
	};
	uint32 val;
};

// AFMT_AUDIO_INFO0
union AfmtAudioInfo0 {
	struct {
		uint32 afmtAudioInfoChecksum: 8; // 0
		uint32 afmtAudioInfoCc: 3; // 8
		uint32 afmtAudioInfoCt: 4; // 11
		uint32 unknown1: 1;
		uint32 afmtAudioInfoChecksumOffset: 8; // 16
		uint32 afmtAudioInfoCxt: 5; // 24
		uint32 unknown2: 3;
	};
	uint32 val;
};

// AFMT_AUDIO_INFO1
union AfmtAudioInfo1 {
	struct {
		uint32 afmtAudioInfoCa: 8; // 0
		uint32 unknown1: 3;
		uint32 afmtAudioInfoLsv: 4; // 11
		uint32 afmtAudioInfoDmInh: 1; // 15
		uint32 afmtAudioInfoLfepbl: 2; // 16
		uint32 unknown2: 14;
	};
	uint32 val;
};

// AFMT_AUDIO_PACKET_CONTROL
union AfmtAudioPacketControl {
	struct {
		uint32 afmtAudioSampleSend: 1; // 0
		uint32 unknown1: 10;
		uint32 afmtResetFifoWhenAudioDis: 1; // 11
		uint32 afmtAudioTestEn: 1; // 12
		uint32 unknown2: 1;
		uint32 afmtAudioTestMode: 1; // 14
		uint32 unknown3: 8;
		uint32 afmtAudioFifoOverflowAck: 1; // 23
		uint32 afmtAudioChannelSwap: 1; // 24
		uint32 unknown4: 1;
		uint32 afmt60958CsUpdate: 1; // 26
		uint32 unknown5: 3;
		uint32 afmtAzAudioEnableChgAck: 1; // 30
		uint32 afmtBlankTestDataOnEncEnb: 1; // 31
	};
	uint32 val;
};

// AFMT_AUDIO_PACKET_CONTROL2
union AfmtAudioPacketControl2 {
	struct {
		uint32 afmtAudioLayoutOvrd: 1; // 0
		uint32 afmtAudioLayoutSelect: 1; // 1
		uint32 unknown1: 6;
		uint32 afmtAudioChannelEnable: 8; // 8
		uint32 afmtDpAudioStreamId: 8; // 16
		uint32 afmtHbrEnableOvrd: 1; // 24
		uint32 unknown2: 3;
		uint32 afmt60958OsfOvrd: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// AFMT_AUDIO_SRC_CONTROL
union AfmtAudioSrcControl {
	struct {
		uint32 afmtAudioSrcSelect: 3; // 0
		uint32 unknown1: 29;
	};
	uint32 val;
};

// AFMT_AVI_INFO0
union AfmtAviInfo0 {
	struct {
		uint32 afmtAviInfoChecksum: 8; // 0
		uint32 afmtAviInfoS: 2; // 8
		uint32 afmtAviInfoB: 2; // 10
		uint32 afmtAviInfoA: 1; // 12
		uint32 afmtAviInfoY: 2; // 13
		uint32 afmtAviInfoPb1Rsvd: 1; // 15
		uint32 afmtAviInfoR: 4; // 16
		uint32 afmtAviInfoM: 2; // 20
		uint32 afmtAviInfoC: 2; // 22
		uint32 afmtAviInfoSc: 2; // 24
		uint32 afmtAviInfoQ: 2; // 26
		uint32 afmtAviInfoEc: 3; // 28
		uint32 afmtAviInfoItc: 1; // 31
	};
	uint32 val;
};

// AFMT_AVI_INFO1
union AfmtAviInfo1 {
	struct {
		uint32 afmtAviInfoVic: 7; // 0
		uint32 afmtAviInfoPb4Rsvd: 1; // 7
		uint32 afmtAviInfoPr: 4; // 8
		uint32 afmtAviInfoCn: 2; // 12
		uint32 afmtAviInfoYq: 2; // 14
		uint32 afmtAviInfoTop: 16; // 16
	};
	uint32 val;
};

// AFMT_AVI_INFO2
union AfmtAviInfo2 {
	struct {
		uint32 afmtAviInfoBottom: 16; // 0
		uint32 afmtAviInfoLeft: 16; // 16
	};
	uint32 val;
};

// AFMT_AVI_INFO3
union AfmtAviInfo3 {
	struct {
		uint32 afmtAviInfoRight: 16; // 0
		uint32 unknown1: 8;
		uint32 afmtAviInfoVersion: 8; // 24
	};
	uint32 val;
};

// AFMT_GENERIC_0
union AfmtGeneric0 {
	struct {
		uint32 afmtGenericByte0: 8; // 0
		uint32 afmtGenericByte1: 8; // 8
		uint32 afmtGenericByte2: 8; // 16
		uint32 afmtGenericByte3: 8; // 24
	};
	uint32 val;
};

// AFMT_GENERIC_1
union AfmtGeneric1 {
	struct {
		uint32 afmtGenericByte4: 8; // 0
		uint32 afmtGenericByte5: 8; // 8
		uint32 afmtGenericByte6: 8; // 16
		uint32 afmtGenericByte7: 8; // 24
	};
	uint32 val;
};

// AFMT_GENERIC_2
union AfmtGeneric2 {
	struct {
		uint32 afmtGenericByte8: 8; // 0
		uint32 afmtGenericByte9: 8; // 8
		uint32 afmtGenericByte10: 8; // 16
		uint32 afmtGenericByte11: 8; // 24
	};
	uint32 val;
};

// AFMT_GENERIC_3
union AfmtGeneric3 {
	struct {
		uint32 afmtGenericByte12: 8; // 0
		uint32 afmtGenericByte13: 8; // 8
		uint32 afmtGenericByte14: 8; // 16
		uint32 afmtGenericByte15: 8; // 24
	};
	uint32 val;
};

// AFMT_GENERIC_4
union AfmtGeneric4 {
	struct {
		uint32 afmtGenericByte16: 8; // 0
		uint32 afmtGenericByte17: 8; // 8
		uint32 afmtGenericByte18: 8; // 16
		uint32 afmtGenericByte19: 8; // 24
	};
	uint32 val;
};

// AFMT_GENERIC_5
union AfmtGeneric5 {
	struct {
		uint32 afmtGenericByte20: 8; // 0
		uint32 afmtGenericByte21: 8; // 8
		uint32 afmtGenericByte22: 8; // 16
		uint32 afmtGenericByte23: 8; // 24
	};
	uint32 val;
};

// AFMT_GENERIC_6
union AfmtGeneric6 {
	struct {
		uint32 afmtGenericByte24: 8; // 0
		uint32 afmtGenericByte25: 8; // 8
		uint32 afmtGenericByte26: 8; // 16
		uint32 afmtGenericByte27: 8; // 24
	};
	uint32 val;
};

// AFMT_GENERIC_7
union AfmtGeneric7 {
	struct {
		uint32 afmtGenericByte28: 8; // 0
		uint32 afmtGenericByte29: 8; // 8
		uint32 afmtGenericByte30: 8; // 16
		uint32 afmtGenericByte31: 8; // 24
	};
	uint32 val;
};

// AFMT_GENERIC_HDR
union AfmtGenericHdr {
	struct {
		uint32 afmtGenericHb0: 8; // 0
		uint32 afmtGenericHb1: 8; // 8
		uint32 afmtGenericHb2: 8; // 16
		uint32 afmtGenericHb3: 8; // 24
	};
	uint32 val;
};

// AFMT_INFOFRAME_CONTROL0
union AfmtInfoframeControl0 {
	struct {
		uint32 unknown1: 6;
		uint32 afmtAudioInfoSource: 1; // 6
		uint32 afmtAudioInfoUpdate: 1; // 7
		uint32 unknown2: 2;
		uint32 afmtMpegInfoUpdate: 1; // 10
		uint32 unknown3: 21;
	};
	uint32 val;
};

// AFMT_ISRC1_0
union AfmtIsrc1_0 {
	struct {
		uint32 afmtIsrcStatus: 3; // 0
		uint32 unknown1: 3;
		uint32 afmtIsrcContinue: 1; // 6
		uint32 afmtIsrcValid: 1; // 7
		uint32 unknown2: 24;
	};
	uint32 val;
};

// AFMT_ISRC1_1
union AfmtIsrc1_1 {
	struct {
		uint32 afmtUpcEanIsrc0: 8; // 0
		uint32 afmtUpcEanIsrc1: 8; // 8
		uint32 afmtUpcEanIsrc2: 8; // 16
		uint32 afmtUpcEanIsrc3: 8; // 24
	};
	uint32 val;
};

// AFMT_ISRC1_2
union AfmtIsrc1_2 {
	struct {
		uint32 afmtUpcEanIsrc4: 8; // 0
		uint32 afmtUpcEanIsrc5: 8; // 8
		uint32 afmtUpcEanIsrc6: 8; // 16
		uint32 afmtUpcEanIsrc7: 8; // 24
	};
	uint32 val;
};

// AFMT_ISRC1_3
union AfmtIsrc1_3 {
	struct {
		uint32 afmtUpcEanIsrc8: 8; // 0
		uint32 afmtUpcEanIsrc9: 8; // 8
		uint32 afmtUpcEanIsrc10: 8; // 16
		uint32 afmtUpcEanIsrc11: 8; // 24
	};
	uint32 val;
};

// AFMT_ISRC1_4
union AfmtIsrc1_4 {
	struct {
		uint32 afmtUpcEanIsrc12: 8; // 0
		uint32 afmtUpcEanIsrc13: 8; // 8
		uint32 afmtUpcEanIsrc14: 8; // 16
		uint32 afmtUpcEanIsrc15: 8; // 24
	};
	uint32 val;
};

// AFMT_ISRC2_0
union AfmtIsrc2_0 {
	struct {
		uint32 afmtUpcEanIsrc16: 8; // 0
		uint32 afmtUpcEanIsrc17: 8; // 8
		uint32 afmtUpcEanIsrc18: 8; // 16
		uint32 afmtUpcEanIsrc19: 8; // 24
	};
	uint32 val;
};

// AFMT_ISRC2_1
union AfmtIsrc2_1 {
	struct {
		uint32 afmtUpcEanIsrc20: 8; // 0
		uint32 afmtUpcEanIsrc21: 8; // 8
		uint32 afmtUpcEanIsrc22: 8; // 16
		uint32 afmtUpcEanIsrc23: 8; // 24
	};
	uint32 val;
};

// AFMT_ISRC2_2
union AfmtIsrc2_2 {
	struct {
		uint32 afmtUpcEanIsrc24: 8; // 0
		uint32 afmtUpcEanIsrc25: 8; // 8
		uint32 afmtUpcEanIsrc26: 8; // 16
		uint32 afmtUpcEanIsrc27: 8; // 24
	};
	uint32 val;
};

// AFMT_ISRC2_3
union AfmtIsrc2_3 {
	struct {
		uint32 afmtUpcEanIsrc28: 8; // 0
		uint32 afmtUpcEanIsrc29: 8; // 8
		uint32 afmtUpcEanIsrc30: 8; // 16
		uint32 afmtUpcEanIsrc31: 8; // 24
	};
	uint32 val;
};

// AFMT_MPEG_INFO0
union AfmtMpegInfo0 {
	struct {
		uint32 afmtMpegInfoChecksum: 8; // 0
		uint32 afmtMpegInfoMb0: 8; // 8
		uint32 afmtMpegInfoMb1: 8; // 16
		uint32 afmtMpegInfoMb2: 8; // 24
	};
	uint32 val;
};

// AFMT_MPEG_INFO1
union AfmtMpegInfo1 {
	struct {
		uint32 afmtMpegInfoMb3: 8; // 0
		uint32 afmtMpegInfoMf: 2; // 8
		uint32 unknown1: 2;
		uint32 afmtMpegInfoFr: 1; // 12
		uint32 unknown2: 19;
	};
	uint32 val;
};

// AFMT_RAMP_CONTROL0
union AfmtRampControl0 {
	struct {
		uint32 afmtRampMaxCount: 24; // 0
		uint32 unknown1: 7;
		uint32 afmtRampDataSign: 1; // 31
	};
	uint32 val;
};

// AFMT_RAMP_CONTROL1
union AfmtRampControl1 {
	struct {
		uint32 afmtRampMinCount: 24; // 0
		uint32 afmtAudioTestChDisable: 8; // 24
	};
	uint32 val;
};

// AFMT_RAMP_CONTROL2
union AfmtRampControl2 {
	struct {
		uint32 afmtRampIncCount: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// AFMT_RAMP_CONTROL3
union AfmtRampControl3 {
	struct {
		uint32 afmtRampDecCount: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// AFMT_STATUS
union AfmtStatus {
	struct {
		uint32 unknown1: 4;
		uint32 afmtAudioEnable: 1; // 4
		uint32 unknown2: 3;
		uint32 afmtAzHbrEnable: 1; // 8
		uint32 unknown3: 15;
		uint32 afmtAudioFifoOverflow: 1; // 24
		uint32 unknown4: 5;
		uint32 afmtAzAudioEnableChg: 1; // 30
		uint32 unknown5: 1;
	};
	uint32 val;
};

// AFMT_VBI_PACKET_CONTROL
union AfmtVbiPacketControl {
	struct {
		uint32 unknown1: 2;
		uint32 afmtGeneric0Update: 1; // 2
		uint32 afmtGeneric2Update: 1; // 3
		uint32 unknown2: 26;
		uint32 afmtGenericIndex: 2; // 30
	};
	uint32 val;
};

// ATTR00
union Attr00 {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR01
union Attr01 {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR02
union Attr02 {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR03
union Attr03 {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR04
union Attr04 {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR05
union Attr05 {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR06
union Attr06 {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR07
union Attr07 {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR08
union Attr08 {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR09
union Attr09 {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR0A
union Attr0a {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR0B
union Attr0b {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR0C
union Attr0c {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR0D
union Attr0d {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR0E
union Attr0e {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR0F
union Attr0f {
	struct {
		uint32 attrPal: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR10
union Attr10 {
	struct {
		uint32 attrGrphMode: 1; // 0
		uint32 attrMonoEn: 1; // 1
		uint32 attrLgrphEn: 1; // 2
		uint32 attrBlinkEn: 1; // 3
		uint32 unknown1: 1;
		uint32 attrPantoponly: 1; // 5
		uint32 attrPclkby2: 1; // 6
		uint32 attrCselEn: 1; // 7
		uint32 unknown2: 24;
	};
	uint32 val;
};

// ATTR11
union Attr11 {
	struct {
		uint32 attrOvsc: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// ATTR12
union Attr12 {
	struct {
		uint32 attrMapEn: 4; // 0
		uint32 attrVsmux: 2; // 4
		uint32 unknown1: 26;
	};
	uint32 val;
};

// ATTR13
union Attr13 {
	struct {
		uint32 attrPpan: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// ATTR14
union Attr14 {
	struct {
		uint32 attrCsel1: 2; // 0
		uint32 attrCsel2: 2; // 2
		uint32 unknown1: 28;
	};
	uint32 val;
};

// ATTRDR
union Attrdr {
	struct {
		uint32 attrData: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// ATTRDW
union Attrdw {
	struct {
		uint32 attrData: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// ATTRX
union Attrx {
	struct {
		uint32 attrIdx: 5; // 0
		uint32 attrPalRwEnb: 1; // 5
		uint32 unknown1: 26;
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR0
union AudioDescriptor0 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR1
union AudioDescriptor1 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR10
union AudioDescriptor10 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR11
union AudioDescriptor11 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR12
union AudioDescriptor12 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR13
union AudioDescriptor13 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR2
union AudioDescriptor2 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR3
union AudioDescriptor3 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR4
union AudioDescriptor4 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR5
union AudioDescriptor5 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR6
union AudioDescriptor6 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR7
union AudioDescriptor7 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR8
union AudioDescriptor8 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUDIO_DESCRIPTOR9
union AudioDescriptor9 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AUXN_IMPCAL
union AuxnImpcal {
	struct {
		uint32 auxnImpcalEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 auxnImpcalCalout: 1; // 8
		uint32 auxnCaloutError: 1; // 9
		uint32 auxnCaloutErrorAk: 1; // 10
		uint32 unknown2: 5;
		uint32 auxnImpcalValue: 4; // 16
		uint32 auxnImpcalStepDelay: 4; // 20
		uint32 auxnImpcalOverride: 4; // 24
		uint32 auxnImpcalOverrideEnable: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// AUXP_IMPCAL
union AuxpImpcal {
	struct {
		uint32 auxpImpcalEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 auxpImpcalCalout: 1; // 8
		uint32 auxpCaloutError: 1; // 9
		uint32 auxpCaloutErrorAk: 1; // 10
		uint32 unknown2: 5;
		uint32 auxpImpcalValue: 4; // 16
		uint32 auxpImpcalStepDelay: 4; // 20
		uint32 auxpImpcalOverride: 4; // 24
		uint32 auxpImpcalOverrideEnable: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// AUX_ARB_CONTROL
union AuxArbControl {
	struct {
		uint32 auxArbPriority: 2; // 0
		uint32 auxRegRwCntlStatus: 2; // 2
		uint32 unknown1: 4;
		uint32 auxNoQueuedSwGo: 1; // 8
		uint32 unknown2: 1;
		uint32 auxNoQueuedLsGo: 1; // 10
		uint32 unknown3: 5;
		uint32 auxSwPendingUseAuxRegReq: 1; // 16
		uint32 auxSwDoneUsingAuxReg: 1; // 17
		uint32 unknown4: 6;
		uint32 auxDmcuPendingUseAuxRegReq: 1; // 24
		uint32 auxDmcuDoneUsingAuxReg: 1; // 25
		uint32 unknown5: 6;
	};
	uint32 val;
};

// AUX_CONTROL
union AuxControl {
	struct {
		uint32 auxEn: 1; // 0
		uint32 unknown1: 7;
		uint32 auxLsReadEn: 1; // 8
		uint32 unknown2: 3;
		uint32 auxLsUpdateDisable: 1; // 12
		uint32 unknown3: 3;
		uint32 auxIgnoreHpdDiscon: 1; // 16
		uint32 unknown4: 1;
		uint32 auxModeDetEn: 1; // 18
		uint32 unknown5: 1;
		uint32 auxHpdSel: 3; // 20
		uint32 unknown6: 1;
		uint32 auxImpcalReqEn: 1; // 24
		uint32 unknown7: 3;
		uint32 auxTestMode: 1; // 28
		uint32 auxDeglitchEn: 1; // 29
		uint32 spare0: 1; // 30
		uint32 spare1: 1; // 31
	};
	uint32 val;
};

// AUX_DPHY_RX_CONTROL0
union AuxDphyRxControl0 {
	struct {
		uint32 unknown1: 4;
		uint32 auxRxStartWindow: 3; // 4
		uint32 unknown2: 1;
		uint32 auxRxReceiveWindow: 3; // 8
		uint32 unknown3: 1;
		uint32 auxRxHalfSymDetectLen: 2; // 12
		uint32 unknown4: 2;
		uint32 auxRxTransitionFilterEn: 1; // 16
		uint32 auxRxAllowBelowThresholdPhaseDetect: 1; // 17
		uint32 auxRxAllowBelowThresholdStart: 1; // 18
		uint32 auxRxAllowBelowThresholdStop: 1; // 19
		uint32 auxRxPhaseDetectLen: 2; // 20
		uint32 unknown5: 2;
		uint32 auxRxTimeoutLen: 3; // 24
		uint32 unknown6: 1;
		uint32 auxRxDetectionThreshold: 3; // 28
		uint32 unknown7: 1;
	};
	uint32 val;
};

// AUX_DPHY_RX_CONTROL1
union AuxDphyRxControl1 {
	struct {
		uint32 auxRxPrechargeSkip: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AUX_DPHY_RX_STATUS
union AuxDphyRxStatus {
	struct {
		uint32 auxRxState: 3; // 0
		uint32 unknown1: 5;
		uint32 auxRxSyncValidCount: 5; // 8
		uint32 unknown2: 3;
		uint32 auxRxHalfSymPeriodFract: 5; // 16
		uint32 auxRxHalfSymPeriod: 9; // 21
		uint32 unknown3: 2;
	};
	uint32 val;
};

// AUX_DPHY_TX_CONTROL
union AuxDphyTxControl {
	struct {
		uint32 auxTxPrechargeLen: 3; // 0
		uint32 unknown1: 5;
		uint32 auxTxPrechargeSymbols: 6; // 8
		uint32 unknown2: 18;
	};
	uint32 val;
};

// AUX_DPHY_TX_REF_CONTROL
union AuxDphyTxRefControl {
	struct {
		uint32 auxTxRefSel: 1; // 0
		uint32 unknown1: 3;
		uint32 auxTxRate: 2; // 4
		uint32 unknown2: 10;
		uint32 auxTxRefDiv: 9; // 16
		uint32 unknown3: 7;
	};
	uint32 val;
};

// AUX_DPHY_TX_STATUS
union AuxDphyTxStatus {
	struct {
		uint32 auxTxActive: 1; // 0
		uint32 unknown1: 3;
		uint32 auxTxState: 3; // 4
		uint32 unknown2: 9;
		uint32 auxTxHalfSymPeriod: 9; // 16
		uint32 unknown3: 7;
	};
	uint32 val;
};

// AUX_GTC_SYNC_CONTROL
union AuxGtcSyncControl {
	struct {
		uint32 auxGtcSyncEn: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// AUX_INTERRUPT_CONTROL
union AuxInterruptControl {
	struct {
		uint32 auxSwDoneInt: 1; // 0
		uint32 auxSwDoneAck: 1; // 1
		uint32 auxSwDoneMask: 1; // 2
		uint32 unknown1: 1;
		uint32 auxLsDoneInt: 1; // 4
		uint32 auxLsDoneAck: 1; // 5
		uint32 auxLsDoneMask: 1; // 6
		uint32 unknown2: 25;
	};
	uint32 val;
};

// AUX_LS_DATA
union AuxLsData {
	struct {
		uint32 unknown1: 8;
		uint32 auxLsData: 8; // 8
		uint32 auxLsIndex: 5; // 16
		uint32 unknown2: 11;
	};
	uint32 val;
};

// AUX_LS_STATUS
union AuxLsStatus {
	struct {
		uint32 auxLsDone: 1; // 0
		uint32 auxLsReq: 1; // 1
		uint32 unknown1: 2;
		uint32 auxLsRxTimeoutState: 3; // 4
		uint32 auxLsRxTimeout: 1; // 7
		uint32 auxLsRxOverflow: 1; // 8
		uint32 auxLsHpdDiscon: 1; // 9
		uint32 auxLsRxPartialByte: 1; // 10
		uint32 auxLsNonAuxMode: 1; // 11
		uint32 auxLsRxMinCountViol: 1; // 12
		uint32 unknown2: 1;
		uint32 auxLsRxInvalidStop: 1; // 14
		uint32 unknown3: 2;
		uint32 auxLsRxSyncInvalidL: 1; // 17
		uint32 auxLsRxSyncInvalidH: 1; // 18
		uint32 auxLsRxInvalidStart: 1; // 19
		uint32 auxLsRxRecvNoDet: 1; // 20
		uint32 unknown4: 1;
		uint32 auxLsRxRecvInvalidH: 1; // 22
		uint32 auxLsRxRecvInvalidL: 1; // 23
		uint32 auxLsReplyByteCount: 5; // 24
		uint32 auxLsCpIrq: 1; // 29
		uint32 auxLsUpdated: 1; // 30
		uint32 auxLsUpdatedAck: 1; // 31
	};
	uint32 val;
};

// AUX_SW_CONTROL
union AuxSwControl {
	struct {
		uint32 auxSwGo: 1; // 0
		uint32 unknown1: 1;
		uint32 auxLsReadTrig: 1; // 2
		uint32 unknown2: 1;
		uint32 auxSwStartDelay: 4; // 4
		uint32 unknown3: 8;
		uint32 auxSwWrBytes: 5; // 16
		uint32 unknown4: 11;
	};
	uint32 val;
};

// AUX_SW_DATA
union AuxSwData {
	struct {
		uint32 auxSwDataRw: 1; // 0
		uint32 unknown1: 7;
		uint32 auxSwData: 8; // 8
		uint32 auxSwIndex: 5; // 16
		uint32 unknown2: 10;
		uint32 auxSwAutoincrementDisable: 1; // 31
	};
	uint32 val;
};

// AUX_SW_STATUS
union AuxSwStatus {
	struct {
		uint32 auxSwDone: 1; // 0
		uint32 auxSwReq: 1; // 1
		uint32 unknown1: 2;
		uint32 auxSwRxTimeoutState: 3; // 4
		uint32 auxSwRxTimeout: 1; // 7
		uint32 auxSwRxOverflow: 1; // 8
		uint32 auxSwHpdDiscon: 1; // 9
		uint32 auxSwRxPartialByte: 1; // 10
		uint32 auxSwNonAuxMode: 1; // 11
		uint32 auxSwRxMinCountViol: 1; // 12
		uint32 unknown2: 1;
		uint32 auxSwRxInvalidStop: 1; // 14
		uint32 unknown3: 2;
		uint32 auxSwRxSyncInvalidL: 1; // 17
		uint32 auxSwRxSyncInvalidH: 1; // 18
		uint32 auxSwRxInvalidStart: 1; // 19
		uint32 auxSwRxRecvNoDet: 1; // 20
		uint32 unknown4: 1;
		uint32 auxSwRxRecvInvalidH: 1; // 22
		uint32 auxSwRxRecvInvalidL: 1; // 23
		uint32 auxSwReplyByteCount: 5; // 24
		uint32 unknown5: 1;
		uint32 auxArbStatus: 2; // 30
	};
	uint32 val;
};

// AZALIA_APPLICATION_POSITION_IN_CYCLIC_BUFFER
union AzaliaApplicationPositionInCyclicBuffer {
	struct {
		uint32 applicationPositionInCyclicBuffer: 32; // 0
	};
	uint32 val;
};

// AZALIA_AUDIO_DTO
union AzaliaAudioDto {
	struct {
		uint32 azaliaAudioDtoPhase: 16; // 0
		uint32 azaliaAudioDtoModule: 16; // 16
	};
	uint32 val;
};

// AZALIA_AUDIO_DTO_CONTROL
union AzaliaAudioDtoControl {
	struct {
		uint32 unknown1: 8;
		uint32 azaliaAudioForceDto: 2; // 8
		uint32 unknown2: 22;
	};
	uint32 val;
};

// AZALIA_BDL_DMA_CONTROL
union AzaliaBdlDmaControl {
	struct {
		uint32 bdlDmaNonSnoop: 2; // 0
		uint32 unknown1: 2;
		uint32 bdlDmaIsochronous: 2; // 4
		uint32 unknown2: 26;
	};
	uint32 val;
};

// AZALIA_CONTROLLER_DEBUG
union AzaliaControllerDebug {
	struct {
		uint32 controllerDebug: 32; // 0
	};
	uint32 val;
};

// AZALIA_CORB_DMA_CONTROL
union AzaliaCorbDmaControl {
	struct {
		uint32 corbDmaNonSnoop: 1; // 0
		uint32 unknown1: 3;
		uint32 corbDmaIsochronous: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// AZALIA_CUMULATIVE_LATENCY_COUNT
union AzaliaCumulativeLatencyCount {
	struct {
		uint32 azaliaCumulativeLatencyCount: 32; // 0
	};
	uint32 val;
};

// AZALIA_CUMULATIVE_REQUEST_COUNT
union AzaliaCumulativeRequestCount {
	struct {
		uint32 azaliaCumulativeRequestCount: 32; // 0
	};
	uint32 val;
};

// AZALIA_CYCLIC_BUFFER_SYNC
union AzaliaCyclicBufferSync {
	struct {
		uint32 cyclicBufferSyncEnable: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// AZALIA_DATA_DMA_CONTROL
union AzaliaDataDmaControl {
	struct {
		uint32 dataDmaNonSnoop: 2; // 0
		uint32 unknown1: 2;
		uint32 dataDmaIsochronous: 2; // 4
		uint32 unknown2: 10;
		uint32 azaliaIocGenerationMethod: 1; // 16
		uint32 azaliaUnderflowControl: 1; // 17
		uint32 unknown3: 14;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_CHANNEL_COUNT_CONTROL
union AzaliaF0CodecChannelCountControl {
	struct {
		uint32 hbrChannelCount: 3; // 0
		uint32 unknown1: 1;
		uint32 compressedChannelCount: 3; // 4
		uint32 unknown2: 25;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_CONVERTER_CONTROL_CHANNEL_STREAM_ID
union AzaliaF0CodecConverterControlChannelStreamId {
	struct {
		uint32 channelId: 4; // 0
		uint32 streamId: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_CONVERTER_CONTROL_CONVERTER_FORMAT
union AzaliaF0CodecConverterControlConverterFormat {
	struct {
		uint32 numberOfChannels: 4; // 0
		uint32 bitsPerSample: 3; // 4
		uint32 unknown1: 1;
		uint32 sampleBaseDivisor: 3; // 8
		uint32 sampleBaseMultiple: 3; // 11
		uint32 sampleBaseRate: 1; // 14
		uint32 streamType: 1; // 15
		uint32 unknown2: 16;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_CONVERTER_CONTROL_DIGITAL_CONVERTER
union AzaliaF0CodecConverterControlDigitalConverter {
	struct {
		uint32 digen: 1; // 0
		uint32 v: 1; // 1
		uint32 vcfg: 1; // 2
		uint32 pre: 1; // 3
		uint32 copy: 1; // 4
		uint32 nonAudio: 1; // 5
		uint32 pro: 1; // 6
		uint32 l: 1; // 7
		uint32 cc: 7; // 8
		uint32 unknown1: 8;
		uint32 keepalive: 1; // 23
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_CONVERTER_CONTROL_GTC_EMBEDDING
union AzaliaF0CodecConverterControlGtcEmbedding {
	struct {
		uint32 presentationTimeEmbeddingEnable: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_CONVERTER_CONTROL_RAMP_RATE
union AzaliaF0CodecConverterControlRampRate {
	struct {
		uint32 rampRate: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_CONVERTER_PARAMETER_AUDIO_WIDGET_CAPABILITIES
union AzaliaF0CodecConverterParameterAudioWidgetCapabilities {
	struct {
		uint32 audioChannelCapabilities: 1; // 0
		uint32 inputAmplifierPresent: 1; // 1
		uint32 outputAmplifierPresent: 1; // 2
		uint32 amplifierParameterOverride: 1; // 3
		uint32 formatOverride: 1; // 4
		uint32 stripe: 1; // 5
		uint32 processingWidget: 1; // 6
		uint32 unsolicitedResponseCapability: 1; // 7
		uint32 connectionList: 1; // 8
		uint32 digital: 1; // 9
		uint32 powerControl: 1; // 10
		uint32 lrSwap: 1; // 11
		uint32 unknown1: 4;
		uint32 audioWidgetCapabilitiesDelay: 4; // 16
		uint32 type: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_CONVERTER_PARAMETER_STREAM_FORMATS
union AzaliaF0CodecConverterParameterStreamFormats {
	struct {
		uint32 streamFormats: 32; // 0
	};
	uint32 val;
};

// AZALIA_F0_CODEC_CONVERTER_PARAMETER_SUPPORTED_SIZE_RATES
union AzaliaF0CodecConverterParameterSupportedSizeRates {
	struct {
		uint32 audioRateCapabilities: 12; // 0
		uint32 unknown1: 4;
		uint32 audioBitCapabilities: 5; // 16
		uint32 unknown2: 11;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_CONVERTER_PIN_DEBUG
union AzaliaF0CodecConverterPinDebug {
	struct {
		uint32 unknown1: 32;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_CONVERTER_STRIPE_CONTROL
union AzaliaF0CodecConverterStripeControl {
	struct {
		uint32 stripeControl: 2; // 0
		uint32 unknown1: 18;
		uint32 stripeCapability: 3; // 20
		uint32 unknown2: 9;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_DEBUG
union AzaliaF0CodecDebug {
	struct {
		uint32 codecDebug: 32; // 0
	};
	uint32 val;
};

// AZALIA_F0_CODEC_ENDPOINT_DATA
union AzaliaF0CodecEndpointData {
	struct {
		uint32 azaliaEndpointRegData: 32; // 0
	};
	uint32 val;
};

// AZALIA_F0_CODEC_ENDPOINT_INDEX
union AzaliaF0CodecEndpointIndex {
	struct {
		uint32 azaliaEndpointRegIndex: 8; // 0
		uint32 azaliaEndpointRegWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_FUNCTION_CONTROL_CONVERTER_SYNCHRONIZATION
union AzaliaF0CodecFunctionControlConverterSynchronization {
	struct {
		uint32 converterSynchronization: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_FUNCTION_CONTROL_POWER_STATE
union AzaliaF0CodecFunctionControlPowerState {
	struct {
		uint32 powerStateSet: 4; // 0
		uint32 powerStateAct: 4; // 4
		uint32 unknown1: 1;
		uint32 clkstopok: 1; // 9
		uint32 powerStateSettingsReset: 1; // 10
		uint32 unknown2: 21;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_FUNCTION_CONTROL_RESET
union AzaliaF0CodecFunctionControlReset {
	struct {
		uint32 codecReset: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_FUNCTION_CONTROL_RESPONSE_SUBSYSTEM_ID
union AzaliaF0CodecFunctionControlResponseSubsystemId {
	struct {
		uint32 subsystemIdByte0: 8; // 0
		uint32 subsystemIdByte1: 8; // 8
		uint32 subsystemIdByte2: 8; // 16
		uint32 subsystemIdByte3: 8; // 24
	};
	uint32 val;
};

// AZALIA_F0_CODEC_FUNCTION_PARAMETER_GROUP_TYPE
union AzaliaF0CodecFunctionParameterGroupType {
	struct {
		uint32 azaliaCodecFunctionParameterGroupType: 32; // 0
	};
	uint32 val;
};

// AZALIA_F0_CODEC_FUNCTION_PARAMETER_POWER_STATES
union AzaliaF0CodecFunctionParameterPowerStates {
	struct {
		uint32 azaliaCodecFunctionParameterPowerStates: 30; // 0
		uint32 clkstop: 1; // 30
		uint32 epss: 1; // 31
	};
	uint32 val;
};

// AZALIA_F0_CODEC_FUNCTION_PARAMETER_STREAM_FORMATS
union AzaliaF0CodecFunctionParameterStreamFormats {
	struct {
		uint32 azaliaCodecFunctionParameterStreamFormats: 32; // 0
	};
	uint32 val;
};

// AZALIA_F0_CODEC_FUNCTION_PARAMETER_SUPPORTED_SIZE_RATES
union AzaliaF0CodecFunctionParameterSupportedSizeRates {
	struct {
		uint32 audioRateCapabilities: 12; // 0
		uint32 unknown1: 4;
		uint32 audioBitCapabilities: 5; // 16
		uint32 unknown2: 11;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_ASSOCIATION_INFO
union AzaliaF0CodecPinAssociationInfo {
	struct {
		uint32 associationInfo: 32; // 0
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR0
union AzaliaF0CodecPinControlAudioDescriptor0 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR1
union AzaliaF0CodecPinControlAudioDescriptor1 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR10
union AzaliaF0CodecPinControlAudioDescriptor10 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR11
union AzaliaF0CodecPinControlAudioDescriptor11 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR12
union AzaliaF0CodecPinControlAudioDescriptor12 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR13
union AzaliaF0CodecPinControlAudioDescriptor13 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR2
union AzaliaF0CodecPinControlAudioDescriptor2 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR3
union AzaliaF0CodecPinControlAudioDescriptor3 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR4
union AzaliaF0CodecPinControlAudioDescriptor4 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR5
union AzaliaF0CodecPinControlAudioDescriptor5 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR6
union AzaliaF0CodecPinControlAudioDescriptor6 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR7
union AzaliaF0CodecPinControlAudioDescriptor7 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR8
union AzaliaF0CodecPinControlAudioDescriptor8 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR9
union AzaliaF0CodecPinControlAudioDescriptor9 {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 unknown1: 5;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_CHANNEL_SPEAKER
union AzaliaF0CodecPinControlChannelSpeaker {
	struct {
		uint32 speakerAllocation: 7; // 0
		uint32 unknown1: 1;
		uint32 channelAllocation: 8; // 8
		uint32 hdmiConnection: 1; // 16
		uint32 dpConnection: 1; // 17
		uint32 extraConnectionInfo: 6; // 18
		uint32 unknown2: 3;
		uint32 levelShift: 4; // 27
		uint32 downMixInhibit: 1; // 31
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_HOT_PLUG_CONTROL
union AzaliaF0CodecPinControlHotPlugControl {
	struct {
		uint32 unknown1: 31;
		uint32 audioEnabled: 1; // 31
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_MULTICHANNEL_ENABLE
union AzaliaF0CodecPinControlMultichannelEnable {
	struct {
		uint32 multichannel01Enable: 1; // 0
		uint32 multichannel01Mute: 1; // 1
		uint32 unknown1: 2;
		uint32 multichannel01ChannelId: 4; // 4
		uint32 multichannel23Enable: 1; // 8
		uint32 multichannel23Mute: 1; // 9
		uint32 unknown2: 2;
		uint32 multichannel23ChannelId: 4; // 12
		uint32 multichannel45Enable: 1; // 16
		uint32 multichannel45Mute: 1; // 17
		uint32 unknown3: 2;
		uint32 multichannel45ChannelId: 4; // 20
		uint32 multichannel67Enable: 1; // 24
		uint32 multichannel67Mute: 1; // 25
		uint32 unknown4: 2;
		uint32 multichannel67ChannelId: 4; // 28
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_MULTICHANNEL_ENABLE2
union AzaliaF0CodecPinControlMultichannelEnable2 {
	struct {
		uint32 multichannel1Enable: 1; // 0
		uint32 multichannel1Mute: 1; // 1
		uint32 unknown1: 2;
		uint32 multichannel1ChannelId: 4; // 4
		uint32 multichannel3Enable: 1; // 8
		uint32 multichannel3Mute: 1; // 9
		uint32 unknown2: 2;
		uint32 multichannel3ChannelId: 4; // 12
		uint32 multichannel5Enable: 1; // 16
		uint32 multichannel5Mute: 1; // 17
		uint32 unknown3: 2;
		uint32 multichannel5ChannelId: 4; // 20
		uint32 multichannel7Enable: 1; // 24
		uint32 multichannel7Mute: 1; // 25
		uint32 unknown4: 2;
		uint32 multichannel7ChannelId: 4; // 28
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_MULTICHANNEL_MODE
union AzaliaF0CodecPinControlMultichannelMode {
	struct {
		uint32 multichannelMode: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_RESPONSE_CONFIGURATION_DEFAULT
union AzaliaF0CodecPinControlResponseConfigurationDefault {
	struct {
		uint32 sequence: 4; // 0
		uint32 defaultAssociation: 4; // 4
		uint32 misc: 4; // 8
		uint32 color: 4; // 12
		uint32 connectionType: 4; // 16
		uint32 defaultDevice: 4; // 20
		uint32 location: 6; // 24
		uint32 portConnectivity: 2; // 30
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_RESPONSE_HBR
union AzaliaF0CodecPinControlResponseHbr {
	struct {
		uint32 hbrCapable: 1; // 0
		uint32 unknown1: 3;
		uint32 hbrEnable: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_RESPONSE_LIPSYNC
union AzaliaF0CodecPinControlResponseLipsync {
	struct {
		uint32 videoLipsync: 8; // 0
		uint32 audioLipsync: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_RESPONSE_PIN_SENSE
union AzaliaF0CodecPinControlResponsePinSense {
	struct {
		uint32 impedanceSense: 31; // 0
		uint32 unknown1: 1;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_SINK_INFO0
union AzaliaF0CodecPinControlSinkInfo0 {
	struct {
		uint32 manufacturerId: 16; // 0
		uint32 productId: 16; // 16
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_SINK_INFO1
union AzaliaF0CodecPinControlSinkInfo1 {
	struct {
		uint32 sinkDescriptionLen: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_SINK_INFO2
union AzaliaF0CodecPinControlSinkInfo2 {
	struct {
		uint32 portId0: 32; // 0
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_SINK_INFO3
union AzaliaF0CodecPinControlSinkInfo3 {
	struct {
		uint32 portId1: 32; // 0
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_SINK_INFO4
union AzaliaF0CodecPinControlSinkInfo4 {
	struct {
		uint32 description0: 8; // 0
		uint32 description1: 8; // 8
		uint32 description2: 8; // 16
		uint32 description3: 8; // 24
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_SINK_INFO5
union AzaliaF0CodecPinControlSinkInfo5 {
	struct {
		uint32 description4: 8; // 0
		uint32 description5: 8; // 8
		uint32 description6: 8; // 16
		uint32 description7: 8; // 24
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_SINK_INFO6
union AzaliaF0CodecPinControlSinkInfo6 {
	struct {
		uint32 description8: 8; // 0
		uint32 description9: 8; // 8
		uint32 description10: 8; // 16
		uint32 description11: 8; // 24
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_SINK_INFO7
union AzaliaF0CodecPinControlSinkInfo7 {
	struct {
		uint32 description12: 8; // 0
		uint32 description13: 8; // 8
		uint32 description14: 8; // 16
		uint32 description15: 8; // 24
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_SINK_INFO8
union AzaliaF0CodecPinControlSinkInfo8 {
	struct {
		uint32 description16: 8; // 0
		uint32 description17: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_UNSOLICITED_RESPONSE
union AzaliaF0CodecPinControlUnsolicitedResponse {
	struct {
		uint32 tag: 6; // 0
		uint32 unknown1: 1;
		uint32 enable: 1; // 7
		uint32 unknown2: 24;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_UNSOLICITED_RESPONSE_FORCE
union AzaliaF0CodecPinControlUnsolicitedResponseForce {
	struct {
		uint32 unsolicitedResponsePayload: 26; // 0
		uint32 unknown1: 2;
		uint32 unsolicitedResponseForce: 1; // 28
		uint32 unknown2: 3;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_CONTROL_WIDGET_CONTROL
union AzaliaF0CodecPinControlWidgetControl {
	struct {
		uint32 unknown1: 6;
		uint32 outEnable: 1; // 6
		uint32 unknown2: 25;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_PARAMETER_AUDIO_WIDGET_CAPABILITIES
union AzaliaF0CodecPinParameterAudioWidgetCapabilities {
	struct {
		uint32 audioChannelCapabilities: 1; // 0
		uint32 inputAmplifierPresent: 1; // 1
		uint32 outputAmplifierPresent: 1; // 2
		uint32 amplifierParameterOverride: 1; // 3
		uint32 unknown1: 1;
		uint32 stripe: 1; // 5
		uint32 processingWidget: 1; // 6
		uint32 unsolicitedResponseCapability: 1; // 7
		uint32 connectionList: 1; // 8
		uint32 digital: 1; // 9
		uint32 powerControl: 1; // 10
		uint32 lrSwap: 1; // 11
		uint32 unknown2: 4;
		uint32 audioWidgetCapabilitiesDelay: 4; // 16
		uint32 type: 4; // 20
		uint32 unknown3: 8;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_PIN_PARAMETER_CAPABILITIES
union AzaliaF0CodecPinParameterCapabilities {
	struct {
		uint32 impedanceSenseCapable: 1; // 0
		uint32 triggerRequired: 1; // 1
		uint32 jackDetectionCapability: 1; // 2
		uint32 headphoneDriveCapable: 1; // 3
		uint32 outputCapable: 1; // 4
		uint32 inputCapable: 1; // 5
		uint32 balancedIOPins: 1; // 6
		uint32 hdmi: 1; // 7
		uint32 vrefControl: 8; // 8
		uint32 eapdCapable: 1; // 16
		uint32 unknown1: 7;
		uint32 dp: 1; // 24
		uint32 unknown2: 7;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_RESYNC_FIFO_CONTROL
union AzaliaF0CodecResyncFifoControl {
	struct {
		uint32 resyncFifoStartupKeepoutWindow: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// AZALIA_F0_CODEC_ROOT_PARAMETER_REVISION_ID
union AzaliaF0CodecRootParameterRevisionId {
	struct {
		uint32 azaliaCodecRootParameterRevisionId: 32; // 0
	};
	uint32 val;
};

// AZALIA_F0_CODEC_ROOT_PARAMETER_VENDOR_AND_DEVICE_ID
union AzaliaF0CodecRootParameterVendorAndDeviceId {
	struct {
		uint32 azaliaCodecRootParameterVendorAndDeviceId: 32; // 0
	};
	uint32 val;
};

// AZALIA_F0_PIN_CONTROL_CODEC_CS_OVERRIDE_0
union AzaliaF0PinControlCodecCsOverride0 {
	struct {
		uint32 iec60958CsMode: 2; // 0
		uint32 iec60958CsSourceNumber: 4; // 2
		uint32 unknown1: 26;
	};
	uint32 val;
};

// AZALIA_F0_PIN_CONTROL_CODEC_CS_OVERRIDE_1
union AzaliaF0PinControlCodecCsOverride1 {
	struct {
		uint32 iec60958CsClockAccuracy: 2; // 0
		uint32 iec60958CsClockAccuracyOvrrdEn: 1; // 2
		uint32 iec60958CsWordLength: 4; // 3
		uint32 iec60958CsWordLengthOvrrdEn: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F0_PIN_CONTROL_CODEC_CS_OVERRIDE_2
union AzaliaF0PinControlCodecCsOverride2 {
	struct {
		uint32 iec60958CsSamplingFrequency: 6; // 0
		uint32 iec60958CsSamplingFrequencyOvrrdEn: 1; // 6
		uint32 unknown1: 25;
	};
	uint32 val;
};

// AZALIA_F0_PIN_CONTROL_CODEC_CS_OVERRIDE_3
union AzaliaF0PinControlCodecCsOverride3 {
	struct {
		uint32 iec60958CsOriginalSamplingFrequency: 4; // 0
		uint32 iec60958CsOriginalSamplingFrequencyOvrrdEn: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// AZALIA_F0_PIN_CONTROL_CODEC_CS_OVERRIDE_4
union AzaliaF0PinControlCodecCsOverride4 {
	struct {
		uint32 iec60958CsSamplingFrequencyCoeff: 4; // 0
		uint32 iec60958CsMpegSurroundInfo: 1; // 4
		uint32 iec60958CsCgmsA: 2; // 5
		uint32 iec60958CsCgmsAValid: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F0_PIN_CONTROL_CODEC_CS_OVERRIDE_5
union AzaliaF0PinControlCodecCsOverride5 {
	struct {
		uint32 iec60958CsChannelNumberL: 4; // 0
		uint32 iec60958CsChannelNumberR: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F0_PIN_CONTROL_CODEC_CS_OVERRIDE_6
union AzaliaF0PinControlCodecCsOverride6 {
	struct {
		uint32 iec60958CsChannelNumber2: 4; // 0
		uint32 iec60958CsChannelNumber3: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F0_PIN_CONTROL_CODEC_CS_OVERRIDE_7
union AzaliaF0PinControlCodecCsOverride7 {
	struct {
		uint32 iec60958CsChannelNumber4: 4; // 0
		uint32 iec60958CsChannelNumber5: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F0_PIN_CONTROL_CODEC_CS_OVERRIDE_8
union AzaliaF0PinControlCodecCsOverride8 {
	struct {
		uint32 iec60958CsChannelNumber6: 4; // 0
		uint32 iec60958CsChannelNumber7: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_CONVERTER_CONTROL_CHANNEL_STREAM_ID
union AzaliaF2CodecConverterControlChannelStreamId {
	struct {
		uint32 channelId: 4; // 0
		uint32 streamId: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_CONVERTER_CONTROL_CONVERTER_FORMAT
union AzaliaF2CodecConverterControlConverterFormat {
	struct {
		uint32 numberOfChannels: 4; // 0
		uint32 bitsPerSample: 3; // 4
		uint32 unknown1: 1;
		uint32 sampleBaseDivisor: 3; // 8
		uint32 sampleBaseMultiple: 3; // 11
		uint32 sampleBaseRate: 1; // 14
		uint32 streamType: 1; // 15
		uint32 unknown2: 16;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_CONVERTER_CONTROL_DIGITAL_CONVERTER
union AzaliaF2CodecConverterControlDigitalConverter {
	struct {
		uint32 digen: 1; // 0
		uint32 v: 1; // 1
		uint32 vcfg: 1; // 2
		uint32 pre: 1; // 3
		uint32 copy: 1; // 4
		uint32 nonAudio: 1; // 5
		uint32 pro: 1; // 6
		uint32 l: 1; // 7
		uint32 cc: 7; // 8
		uint32 unknown1: 8;
		uint32 keepalive: 1; // 23
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_CONVERTER_CONTROL_DIGITAL_CONVERTER_2
union AzaliaF2CodecConverterControlDigitalConverter2 {
	struct {
		uint32 cc: 7; // 0
		uint32 unknown1: 25;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_CONVERTER_CONTROL_DIGITAL_CONVERTER_3
union AzaliaF2CodecConverterControlDigitalConverter3 {
	struct {
		uint32 unknown1: 7;
		uint32 keepalive: 1; // 7
		uint32 unknown2: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_CONVERTER_CONTROL_RAMP_RATE
union AzaliaF2CodecConverterControlRampRate {
	struct {
		uint32 rampRate: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_CONVERTER_PARAMETER_AUDIO_WIDGET_CAPABILITIES
union AzaliaF2CodecConverterParameterAudioWidgetCapabilities {
	struct {
		uint32 audioChannelCapabilities: 1; // 0
		uint32 inputAmplifierPresent: 1; // 1
		uint32 outputAmplifierPresent: 1; // 2
		uint32 amplifierParameterOverride: 1; // 3
		uint32 formatOverride: 1; // 4
		uint32 stripe: 1; // 5
		uint32 processingWidget: 1; // 6
		uint32 unsolicitedResponseCapability: 1; // 7
		uint32 connectionList: 1; // 8
		uint32 digital: 1; // 9
		uint32 powerControl: 1; // 10
		uint32 lrSwap: 1; // 11
		uint32 unknown1: 4;
		uint32 audioWidgetCapabilitiesDelay: 4; // 16
		uint32 type: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_CONVERTER_PARAMETER_STREAM_FORMATS
union AzaliaF2CodecConverterParameterStreamFormats {
	struct {
		uint32 streamFormats: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_CODEC_CONVERTER_PARAMETER_SUPPORTED_SIZE_RATES
union AzaliaF2CodecConverterParameterSupportedSizeRates {
	struct {
		uint32 audioRateCapabilities: 12; // 0
		uint32 unknown1: 4;
		uint32 audioBitCapabilities: 5; // 16
		uint32 unknown2: 11;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_CONVERTER_STRIPE_CONTROL
union AzaliaF2CodecConverterStripeControl {
	struct {
		uint32 stripeControl: 2; // 0
		uint32 unknown1: 18;
		uint32 stripeCapability: 3; // 20
		uint32 unknown2: 9;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_FUNCTION_CONTROL_CONVERTER_SYNCHRONIZATION
union AzaliaF2CodecFunctionControlConverterSynchronization {
	struct {
		uint32 converterSynchronization: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_FUNCTION_CONTROL_POWER_STATE
union AzaliaF2CodecFunctionControlPowerState {
	struct {
		uint32 powerStateSet: 4; // 0
		uint32 powerStateAct: 4; // 4
		uint32 unknown1: 1;
		uint32 clkstopok: 1; // 9
		uint32 powerStateSettingsReset: 1; // 10
		uint32 unknown2: 21;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_FUNCTION_CONTROL_RESET
union AzaliaF2CodecFunctionControlReset {
	struct {
		uint32 codecReset: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_FUNCTION_CONTROL_RESPONSE_SUBSYSTEM_ID
union AzaliaF2CodecFunctionControlResponseSubsystemId {
	struct {
		uint32 subsystemIdByte0: 8; // 0
		uint32 subsystemIdByte1: 8; // 8
		uint32 subsystemIdByte2: 8; // 16
		uint32 subsystemIdByte3: 8; // 24
	};
	uint32 val;
};

// AZALIA_F2_CODEC_FUNCTION_CONTROL_RESPONSE_SUBSYSTEM_ID_2
union AzaliaF2CodecFunctionControlResponseSubsystemId2 {
	struct {
		uint32 subsystemIdByte1: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_FUNCTION_CONTROL_RESPONSE_SUBSYSTEM_ID_3
union AzaliaF2CodecFunctionControlResponseSubsystemId3 {
	struct {
		uint32 subsystemIdByte2: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_FUNCTION_CONTROL_RESPONSE_SUBSYSTEM_ID_4
union AzaliaF2CodecFunctionControlResponseSubsystemId4 {
	struct {
		uint32 subsystemIdByte3: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_FUNCTION_PARAMETER_GROUP_TYPE
union AzaliaF2CodecFunctionParameterGroupType {
	struct {
		uint32 azaliaCodecFunctionParameterGroupType: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_CODEC_FUNCTION_PARAMETER_POWER_STATES
union AzaliaF2CodecFunctionParameterPowerStates {
	struct {
		uint32 azaliaCodecFunctionParameterPowerStates: 30; // 0
		uint32 clkstop: 1; // 30
		uint32 epss: 1; // 31
	};
	uint32 val;
};

// AZALIA_F2_CODEC_FUNCTION_PARAMETER_STREAM_FORMATS
union AzaliaF2CodecFunctionParameterStreamFormats {
	struct {
		uint32 azaliaCodecFunctionParameterStreamFormats: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_CODEC_FUNCTION_PARAMETER_SUBORDINATE_NODE_COUNT
union AzaliaF2CodecFunctionParameterSubordinateNodeCount {
	struct {
		uint32 azaliaCodecFunctionParameterSubordinateNodeCount: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_CODEC_FUNCTION_PARAMETER_SUPPORTED_SIZE_RATES
union AzaliaF2CodecFunctionParameterSupportedSizeRates {
	struct {
		uint32 audioRateCapabilities: 12; // 0
		uint32 unknown1: 4;
		uint32 audioBitCapabilities: 5; // 16
		uint32 unknown2: 11;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_ASSOCIATION_INFO
union AzaliaF2CodecPinAssociationInfo {
	struct {
		uint32 associationInfo: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR
union AzaliaF2CodecPinControlAudioDescriptor {
	struct {
		uint32 maxChannels: 3; // 0
		uint32 formatCode: 4; // 3
		uint32 unknown1: 1;
		uint32 supportedFrequencies: 8; // 8
		uint32 descriptorByte2: 8; // 16
		uint32 supportedFrequenciesStereo: 8; // 24
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_AUDIO_DESCRIPTOR_DATA
union AzaliaF2CodecPinControlAudioDescriptorData {
	struct {
		uint32 descriptor: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_AUDIO_SINK_INFO_DATA
union AzaliaF2CodecPinControlAudioSinkInfoData {
	struct {
		uint32 sinkData: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_AUDIO_SINK_INFO_INDEX
union AzaliaF2CodecPinControlAudioSinkInfoIndex {
	struct {
		uint32 sinkInfoIndex: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_CHANNEL_ALLOCATION
union AzaliaF2CodecPinControlChannelAllocation {
	struct {
		uint32 channelAllocation: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_DOWN_MIX_INFO
union AzaliaF2CodecPinControlDownMixInfo {
	struct {
		uint32 unknown1: 3;
		uint32 levelShift: 4; // 3
		uint32 downMixInhibit: 1; // 7
		uint32 unknown2: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_HBR
union AzaliaF2CodecPinControlHbr {
	struct {
		uint32 hbrCapable: 1; // 0
		uint32 unknown1: 3;
		uint32 hbrEnable: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_LIPSYNC
union AzaliaF2CodecPinControlLipsync {
	struct {
		uint32 videoLipsync: 8; // 0
		uint32 audioLipsync: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_MANUFACTURER_ID
union AzaliaF2CodecPinControlManufacturerId {
	struct {
		uint32 manufacturerId: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_MULTICHANNEL01_ENABLE
union AzaliaF2CodecPinControlMultichannel01Enable {
	struct {
		uint32 multichannel01Enable: 1; // 0
		uint32 multichannel01Mute: 1; // 1
		uint32 unknown1: 2;
		uint32 multichannel01ChannelId: 4; // 4
		uint32 unknown2: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_MULTICHANNEL1_ENABLE
union AzaliaF2CodecPinControlMultichannel1Enable {
	struct {
		uint32 multichannel1Enable: 1; // 0
		uint32 multichannel1Mute: 1; // 1
		uint32 unknown1: 2;
		uint32 multichannel1ChannelId: 4; // 4
		uint32 unknown2: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_MULTICHANNEL23_ENABLE
union AzaliaF2CodecPinControlMultichannel23Enable {
	struct {
		uint32 multichannel23Enable: 1; // 0
		uint32 multichannel23Mute: 1; // 1
		uint32 unknown1: 2;
		uint32 multichannel23ChannelId: 4; // 4
		uint32 unknown2: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_MULTICHANNEL3_ENABLE
union AzaliaF2CodecPinControlMultichannel3Enable {
	struct {
		uint32 multichannel3Enable: 1; // 0
		uint32 multichannel3Mute: 1; // 1
		uint32 unknown1: 2;
		uint32 multichannel3ChannelId: 4; // 4
		uint32 unknown2: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_MULTICHANNEL45_ENABLE
union AzaliaF2CodecPinControlMultichannel45Enable {
	struct {
		uint32 multichannel45Enable: 1; // 0
		uint32 multichannel45Mute: 1; // 1
		uint32 unknown1: 2;
		uint32 multichannel45ChannelId: 4; // 4
		uint32 unknown2: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_MULTICHANNEL5_ENABLE
union AzaliaF2CodecPinControlMultichannel5Enable {
	struct {
		uint32 multichannel5Enable: 1; // 0
		uint32 multichannel5Mute: 1; // 1
		uint32 unknown1: 2;
		uint32 multichannel5ChannelId: 4; // 4
		uint32 unknown2: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_MULTICHANNEL67_ENABLE
union AzaliaF2CodecPinControlMultichannel67Enable {
	struct {
		uint32 multichannel67Enable: 1; // 0
		uint32 multichannel67Mute: 1; // 1
		uint32 unknown1: 2;
		uint32 multichannel67ChannelId: 4; // 4
		uint32 unknown2: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_MULTICHANNEL7_ENABLE
union AzaliaF2CodecPinControlMultichannel7Enable {
	struct {
		uint32 multichannel7Enable: 1; // 0
		uint32 multichannel7Mute: 1; // 1
		uint32 unknown1: 2;
		uint32 multichannel7ChannelId: 4; // 4
		uint32 unknown2: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_MULTICHANNEL_MODE
union AzaliaF2CodecPinControlMultichannelMode {
	struct {
		uint32 multichannelMode: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_PORTID0
union AzaliaF2CodecPinControlPortid0 {
	struct {
		uint32 portid: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_PORTID1
union AzaliaF2CodecPinControlPortid1 {
	struct {
		uint32 portid: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_PRODUCT_ID
union AzaliaF2CodecPinControlProductId {
	struct {
		uint32 productId: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_RESPONSE_CONFIGURATION_DEFAULT
union AzaliaF2CodecPinControlResponseConfigurationDefault {
	struct {
		uint32 sequence: 4; // 0
		uint32 defaultAssociation: 4; // 4
		uint32 misc: 4; // 8
		uint32 color: 4; // 12
		uint32 connectionType: 4; // 16
		uint32 defaultDevice: 4; // 20
		uint32 location: 6; // 24
		uint32 portConnectivity: 2; // 30
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_RESPONSE_CONFIGURATION_DEFAULT_2
union AzaliaF2CodecPinControlResponseConfigurationDefault2 {
	struct {
		uint32 misc: 4; // 0
		uint32 color: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_RESPONSE_CONFIGURATION_DEFAULT_3
union AzaliaF2CodecPinControlResponseConfigurationDefault3 {
	struct {
		uint32 connectionType: 4; // 0
		uint32 defaultDevice: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_RESPONSE_CONFIGURATION_DEFAULT_4
union AzaliaF2CodecPinControlResponseConfigurationDefault4 {
	struct {
		uint32 location: 6; // 0
		uint32 portConnectivity: 2; // 6
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_RESPONSE_CONNECTION_LIST_ENTRY
union AzaliaF2CodecPinControlResponseConnectionListEntry {
	struct {
		uint32 connectionListEntry: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_RESPONSE_PIN_SENSE
union AzaliaF2CodecPinControlResponsePinSense {
	struct {
		uint32 impedanceSense: 31; // 0
		uint32 presenceDetect: 1; // 31
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_RESPONSE_SPEAKER_ALLOCATION
union AzaliaF2CodecPinControlResponseSpeakerAllocation {
	struct {
		uint32 speakerAllocation: 7; // 0
		uint32 unknown1: 1;
		uint32 hdmiConnection: 1; // 8
		uint32 dpConnection: 1; // 9
		uint32 extraConnectionInfo: 6; // 10
		uint32 unknown2: 16;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_SINK_DESCRIPTION_LEN
union AzaliaF2CodecPinControlSinkDescriptionLen {
	struct {
		uint32 sinkDescriptionLen: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_UNSOLICITED_RESPONSE
union AzaliaF2CodecPinControlUnsolicitedResponse {
	struct {
		uint32 tag: 6; // 0
		uint32 unknown1: 1;
		uint32 enable: 1; // 7
		uint32 unknown2: 24;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_CONTROL_WIDGET_CONTROL
union AzaliaF2CodecPinControlWidgetControl {
	struct {
		uint32 unknown1: 6;
		uint32 outEnable: 1; // 6
		uint32 unknown2: 25;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_PARAMETER_AUDIO_WIDGET_CAPABILITIES
union AzaliaF2CodecPinParameterAudioWidgetCapabilities {
	struct {
		uint32 audioChannelCapabilities: 1; // 0
		uint32 inputAmplifierPresent: 1; // 1
		uint32 outputAmplifierPresent: 1; // 2
		uint32 amplifierParameterOverride: 1; // 3
		uint32 unknown1: 1;
		uint32 stripe: 1; // 5
		uint32 processingWidget: 1; // 6
		uint32 unsolicitedResponseCapability: 1; // 7
		uint32 connectionList: 1; // 8
		uint32 digital: 1; // 9
		uint32 powerControl: 1; // 10
		uint32 lrSwap: 1; // 11
		uint32 unknown2: 4;
		uint32 audioWidgetCapabilitiesDelay: 4; // 16
		uint32 type: 4; // 20
		uint32 unknown3: 8;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_PARAMETER_CAPABILITIES
union AzaliaF2CodecPinParameterCapabilities {
	struct {
		uint32 impedanceSenseCapable: 1; // 0
		uint32 triggerRequired: 1; // 1
		uint32 jackDetectionCapability: 1; // 2
		uint32 headphoneDriveCapable: 1; // 3
		uint32 outputCapable: 1; // 4
		uint32 inputCapable: 1; // 5
		uint32 balancedIOPins: 1; // 6
		uint32 hdmi: 1; // 7
		uint32 vrefControl: 8; // 8
		uint32 eapdCapable: 1; // 16
		uint32 unknown1: 7;
		uint32 dp: 1; // 24
		uint32 unknown2: 7;
	};
	uint32 val;
};

// AZALIA_F2_CODEC_PIN_PARAMETER_CONNECTION_LIST_LENGTH
union AzaliaF2CodecPinParameterConnectionListLength {
	struct {
		uint32 connectionListLength: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_CODEC_ROOT_PARAMETER_REVISION_ID
union AzaliaF2CodecRootParameterRevisionId {
	struct {
		uint32 azaliaCodecRootParameterRevisionId: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_CODEC_ROOT_PARAMETER_SUBORDINATE_NODE_COUNT
union AzaliaF2CodecRootParameterSubordinateNodeCount {
	struct {
		uint32 azaliaCodecRootParameterSubordinateNodeCount: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_CODEC_ROOT_PARAMETER_VENDOR_AND_DEVICE_ID
union AzaliaF2CodecRootParameterVendorAndDeviceId {
	struct {
		uint32 azaliaCodecRootParameterVendorAndDeviceId: 32; // 0
	};
	uint32 val;
};

// AZALIA_F2_PIN_CONTROL_CODEC_CS_OVERRIDE_0
union AzaliaF2PinControlCodecCsOverride0 {
	struct {
		uint32 iec60958CsMode: 2; // 0
		uint32 iec60958CsSourceNumber: 4; // 2
		uint32 unknown1: 26;
	};
	uint32 val;
};

// AZALIA_F2_PIN_CONTROL_CODEC_CS_OVERRIDE_1
union AzaliaF2PinControlCodecCsOverride1 {
	struct {
		uint32 iec60958CsClockAccuracy: 2; // 0
		uint32 iec60958CsClockAccuracyOvrrdEn: 1; // 2
		uint32 iec60958CsWordLength: 4; // 3
		uint32 iec60958CsWordLengthOvrrdEn: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_PIN_CONTROL_CODEC_CS_OVERRIDE_2
union AzaliaF2PinControlCodecCsOverride2 {
	struct {
		uint32 iec60958CsSamplingFrequency: 6; // 0
		uint32 iec60958CsSamplingFrequencyOvrrdEn: 1; // 6
		uint32 unknown1: 25;
	};
	uint32 val;
};

// AZALIA_F2_PIN_CONTROL_CODEC_CS_OVERRIDE_3
union AzaliaF2PinControlCodecCsOverride3 {
	struct {
		uint32 iec60958CsOriginalSamplingFrequency: 4; // 0
		uint32 iec60958CsOriginalSamplingFrequencyOvrrdEn: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// AZALIA_F2_PIN_CONTROL_CODEC_CS_OVERRIDE_4
union AzaliaF2PinControlCodecCsOverride4 {
	struct {
		uint32 iec60958CsSamplingFrequencyCoeff: 4; // 0
		uint32 iec60958CsMpegSurroundInfo: 1; // 4
		uint32 iec60958CsCgmsA: 2; // 5
		uint32 iec60958CsCgmsAValid: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_PIN_CONTROL_CODEC_CS_OVERRIDE_5
union AzaliaF2PinControlCodecCsOverride5 {
	struct {
		uint32 iec60958CsChannelNumberL: 4; // 0
		uint32 iec60958CsChannelNumberR: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_PIN_CONTROL_CODEC_CS_OVERRIDE_6
union AzaliaF2PinControlCodecCsOverride6 {
	struct {
		uint32 iec60958CsChannelNumber2: 4; // 0
		uint32 iec60958CsChannelNumber3: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_PIN_CONTROL_CODEC_CS_OVERRIDE_7
union AzaliaF2PinControlCodecCsOverride7 {
	struct {
		uint32 iec60958CsChannelNumber4: 4; // 0
		uint32 iec60958CsChannelNumber5: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_F2_PIN_CONTROL_CODEC_CS_OVERRIDE_8
union AzaliaF2PinControlCodecCsOverride8 {
	struct {
		uint32 iec60958CsChannelNumber6: 4; // 0
		uint32 iec60958CsChannelNumber7: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// AZALIA_FIFO_SIZE_CONTROL
union AzaliaFifoSizeControl {
	struct {
		uint32 minFifoSize: 7; // 0
		uint32 unknown1: 1;
		uint32 maxFifoSize: 7; // 8
		uint32 unknown2: 1;
		uint32 maxLatencySupport: 8; // 16
		uint32 unknown3: 8;
	};
	uint32 val;
};

// AZALIA_GLOBAL_CAPABILITIES
union AzaliaGlobalCapabilities {
	struct {
		uint32 unknown1: 1;
		uint32 numberOfSerialDataOutputSignals: 2; // 1
		uint32 unknown2: 29;
	};
	uint32 val;
};

// AZALIA_LATENCY_COUNTER_CONTROL
union AzaliaLatencyCounterControl {
	struct {
		uint32 azaliaLatencyCounterReset: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// AZALIA_OUTPUT_PAYLOAD_CAPABILITY
union AzaliaOutputPayloadCapability {
	struct {
		uint32 outputPayloadCapability: 16; // 0
		uint32 outstrmpay: 16; // 16
	};
	uint32 val;
};

// AZALIA_OUTPUT_STREAM_ARBITER_CONTROL
union AzaliaOutputStreamArbiterControl {
	struct {
		uint32 latencyHidingLevel: 8; // 0
		uint32 sysMemActiveEnable: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// AZALIA_RIRB_AND_DP_CONTROL
union AzaliaRirbAndDpControl {
	struct {
		uint32 rirbNonSnoop: 1; // 0
		uint32 unknown1: 3;
		uint32 dpDmaNonSnoop: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// AZALIA_SCLK_CONTROL
union AzaliaSclkControl {
	struct {
		uint32 unknown1: 4;
		uint32 audioSclkControl: 2; // 4
		uint32 unknown2: 26;
	};
	uint32 val;
};

// AZALIA_STREAM_DATA
union AzaliaStreamData {
	struct {
		uint32 azaliaStreamRegData: 32; // 0
	};
	uint32 val;
};

// AZALIA_STREAM_DEBUG
union AzaliaStreamDebug {
	struct {
		uint32 streamDebugData: 32; // 0
	};
	uint32 val;
};

// AZALIA_STREAM_INDEX
union AzaliaStreamIndex {
	struct {
		uint32 azaliaStreamRegIndex: 8; // 0
		uint32 azaliaStreamRegWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// AZALIA_UNDERFLOW_FILLER_SAMPLE
union AzaliaUnderflowFillerSample {
	struct {
		uint32 azaliaUnderflowFillerSample: 32; // 0
	};
	uint32 val;
};

// AZALIA_WORSTCASE_LATENCY_COUNT
union AzaliaWorstcaseLatencyCount {
	struct {
		uint32 azaliaWorstcaseLatencyCount: 32; // 0
	};
	uint32 val;
};

// AZ_TEST_DEBUG_DATA
union AzTestDebugData {
	struct {
		uint32 azTestDebugData: 32; // 0
	};
	uint32 val;
};

// AZ_TEST_DEBUG_INDEX
union AzTestDebugIndex {
	struct {
		uint32 azTestDebugIndex: 8; // 0
		uint32 azTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// BL1_PWM_ABM_CNTL
union Bl1PwmAbmCntl {
	struct {
		uint32 bl1PwmUseAbmEn: 1; // 0
		uint32 bl1PwmUseAmbientLevelEn: 1; // 1
		uint32 bl1PwmAutoUpdateCurrentAbmLevelEn: 1; // 2
		uint32 bl1PwmAutoCalcFinalDutyCycleEn: 1; // 3
		uint32 unknown1: 12;
		uint32 bl1PwmAutoUpdateCurrentAbmStepSize: 16; // 16
	};
	uint32 val;
};

// BL1_PWM_AMBIENT_LIGHT_LEVEL
union Bl1PwmAmbientLightLevel {
	struct {
		uint32 bl1PwmAmbientLightLevel: 17; // 0
		uint32 unknown1: 15;
	};
	uint32 val;
};

// BL1_PWM_BL_UPDATE_SAMPLE_RATE
union Bl1PwmBlUpdateSampleRate {
	struct {
		uint32 bl1PwmBlUpdateSampleRateCountEn: 1; // 0
		uint32 bl1PwmBlUpdateResetSampleRateFrameCounter: 1; // 1
		uint32 unknown1: 6;
		uint32 bl1PwmBlUpdateSampleRateFrameCount: 8; // 8
		uint32 bl1PwmBlUpdateInitialSampleRateCountValueWhenReset: 8; // 16
		uint32 unknown2: 7;
		uint32 abm1HglsRegLock: 1; // 31
	};
	uint32 val;
};

// BL1_PWM_CURRENT_ABM_LEVEL
union Bl1PwmCurrentAbmLevel {
	struct {
		uint32 bl1PwmCurrentAbmLevel: 17; // 0
		uint32 unknown1: 15;
	};
	uint32 val;
};

// BL1_PWM_FINAL_DUTY_CYCLE
union Bl1PwmFinalDutyCycle {
	struct {
		uint32 bl1PwmFinalDutyCycle: 17; // 0
		uint32 unknown1: 15;
	};
	uint32 val;
};

// BL1_PWM_GRP2_REG_LOCK
union Bl1PwmGrp2RegLock {
	struct {
		uint32 bl1PwmGrp2RegLock: 1; // 0
		uint32 unknown1: 7;
		uint32 bl1PwmGrp2RegUpdatePending: 1; // 8
		uint32 unknown2: 7;
		uint32 bl1PwmGrp2UpdateAtFrameStart: 1; // 16
		uint32 bl1PwmGrp2FrameStartDispSel: 3; // 17
		uint32 unknown3: 4;
		uint32 bl1PwmGrp2ReadbackDbRegValueEn: 1; // 24
		uint32 unknown4: 6;
		uint32 bl1PwmGrp2IgnoreMasterLockEn: 1; // 31
	};
	uint32 val;
};

// BL1_PWM_MINIMUM_DUTY_CYCLE
union Bl1PwmMinimumDutyCycle {
	struct {
		uint32 bl1PwmMinimumDutyCycle: 17; // 0
		uint32 unknown1: 15;
	};
	uint32 val;
};

// BL1_PWM_TARGET_ABM_LEVEL
union Bl1PwmTargetAbmLevel {
	struct {
		uint32 bl1PwmTargetAbmLevel: 17; // 0
		uint32 unknown1: 15;
	};
	uint32 val;
};

// BL1_PWM_USER_LEVEL
union Bl1PwmUserLevel {
	struct {
		uint32 bl1PwmUserLevel: 17; // 0
		uint32 unknown1: 15;
	};
	uint32 val;
};

// BL_PWM_CNTL
union BlPwmCntl {
	struct {
		uint32 blActiveIntFracCnt: 16; // 0
		uint32 unknown1: 14;
		uint32 blPwmFractionalEn: 1; // 30
		uint32 blPwmEn: 1; // 31
	};
	uint32 val;
};

// BL_PWM_CNTL2
union BlPwmCntl2 {
	struct {
		uint32 blPwmPostFrameStartDelayBeforeUpdate: 16; // 0
		uint32 unknown1: 12;
		uint32 dbgBlPwmInputRefclkSelect: 2; // 28
		uint32 blPwmOverrideBlOutEnable: 1; // 30
		uint32 blPwmOverrideLvtmaPwrseqEn: 1; // 31
	};
	uint32 val;
};

// BL_PWM_GRP1_REG_LOCK
union BlPwmGrp1RegLock {
	struct {
		uint32 blPwmGrp1RegLock: 1; // 0
		uint32 unknown1: 7;
		uint32 blPwmGrp1RegUpdatePending: 1; // 8
		uint32 unknown2: 7;
		uint32 blPwmGrp1UpdateAtFrameStart: 1; // 16
		uint32 blPwmGrp1FrameStartDispSel: 3; // 17
		uint32 unknown3: 4;
		uint32 blPwmGrp1ReadbackDbRegValueEn: 1; // 24
		uint32 unknown4: 6;
		uint32 blPwmGrp1IgnoreMasterLockEn: 1; // 31
	};
	uint32 val;
};

// BL_PWM_PERIOD_CNTL
union BlPwmPeriodCntl {
	struct {
		uint32 blPwmPeriod: 16; // 0
		uint32 blPwmPeriodBitcnt: 4; // 16
		uint32 unknown1: 12;
	};
	uint32 val;
};

// BPHYC_DAC_AUTO_CALIB_CONTROL
union BphycDacAutoCalibControl {
	struct {
		uint32 bphycDacCalInitb: 1; // 0
		uint32 bphycDacCalEn: 1; // 1
		uint32 bphycDacCalDacadjEn: 1; // 2
		uint32 unknown1: 1;
		uint32 bphycDacCalWaitAdjust: 10; // 4
		uint32 unknown2: 6;
		uint32 bphycDacCalMask: 3; // 20
		uint32 unknown3: 5;
		uint32 bphycDacCalComplete: 1; // 28
		uint32 unknown4: 3;
	};
	uint32 val;
};

// BPHYC_DAC_MACRO_CNTL
union BphycDacMacroCntl {
	struct {
		uint32 bphycDacWhiteLevel: 2; // 0
		uint32 unknown1: 6;
		uint32 bphycDacWhiteFineControl: 6; // 8
		uint32 unknown2: 2;
		uint32 bphycDacBandgapAdjustment: 6; // 16
		uint32 unknown3: 2;
		uint32 bphycDacAnalogMonitor: 4; // 24
		uint32 bphycDacCoremon: 1; // 28
		uint32 unknown4: 3;
	};
	uint32 val;
};

// CC_DC_PIPE_DIS
union CcDcPipeDis {
	struct {
		uint32 unknown1: 1;
		uint32 dcPipeDis: 6; // 1
		uint32 unknown2: 25;
	};
	uint32 val;
};

// CC_RCU_DC_AUDIO_PORT_CONNECTIVITY
union CcRcuDcAudioPortConnectivity {
	struct {
		uint32 portConnectivity: 3; // 0
		uint32 unknown1: 1;
		uint32 portConnectivityOverrideEnable: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// COMM_MATRIXA_TRANS_C11_C12
union CommMatrixaTransC11C12 {
	struct {
		uint32 commMatrixaTransC11: 16; // 0
		uint32 commMatrixaTransC12: 16; // 16
	};
	uint32 val;
};

// COMM_MATRIXA_TRANS_C13_C14
union CommMatrixaTransC13C14 {
	struct {
		uint32 commMatrixaTransC13: 16; // 0
		uint32 commMatrixaTransC14: 16; // 16
	};
	uint32 val;
};

// COMM_MATRIXA_TRANS_C21_C22
union CommMatrixaTransC21C22 {
	struct {
		uint32 commMatrixaTransC21: 16; // 0
		uint32 commMatrixaTransC22: 16; // 16
	};
	uint32 val;
};

// COMM_MATRIXA_TRANS_C23_C24
union CommMatrixaTransC23C24 {
	struct {
		uint32 commMatrixaTransC23: 16; // 0
		uint32 commMatrixaTransC24: 16; // 16
	};
	uint32 val;
};

// COMM_MATRIXA_TRANS_C31_C32
union CommMatrixaTransC31C32 {
	struct {
		uint32 commMatrixaTransC31: 16; // 0
		uint32 commMatrixaTransC32: 16; // 16
	};
	uint32 val;
};

// COMM_MATRIXA_TRANS_C33_C34
union CommMatrixaTransC33C34 {
	struct {
		uint32 commMatrixaTransC33: 16; // 0
		uint32 commMatrixaTransC34: 16; // 16
	};
	uint32 val;
};

// COMM_MATRIXB_TRANS_C11_C12
union CommMatrixbTransC11C12 {
	struct {
		uint32 commMatrixbTransC11: 16; // 0
		uint32 commMatrixbTransC12: 16; // 16
	};
	uint32 val;
};

// COMM_MATRIXB_TRANS_C13_C14
union CommMatrixbTransC13C14 {
	struct {
		uint32 commMatrixbTransC13: 16; // 0
		uint32 commMatrixbTransC14: 16; // 16
	};
	uint32 val;
};

// COMM_MATRIXB_TRANS_C21_C22
union CommMatrixbTransC21C22 {
	struct {
		uint32 commMatrixbTransC21: 16; // 0
		uint32 commMatrixbTransC22: 16; // 16
	};
	uint32 val;
};

// COMM_MATRIXB_TRANS_C23_C24
union CommMatrixbTransC23C24 {
	struct {
		uint32 commMatrixbTransC23: 16; // 0
		uint32 commMatrixbTransC24: 16; // 16
	};
	uint32 val;
};

// COMM_MATRIXB_TRANS_C31_C32
union CommMatrixbTransC31C32 {
	struct {
		uint32 commMatrixbTransC31: 16; // 0
		uint32 commMatrixbTransC32: 16; // 16
	};
	uint32 val;
};

// COMM_MATRIXB_TRANS_C33_C34
union CommMatrixbTransC33C34 {
	struct {
		uint32 commMatrixbTransC33: 16; // 0
		uint32 commMatrixbTransC34: 16; // 16
	};
	uint32 val;
};

// CRT00
union Crt00 {
	struct {
		uint32 hTotal: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT01
union Crt01 {
	struct {
		uint32 hDispEnd: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT02
union Crt02 {
	struct {
		uint32 hBlankStart: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT03
union Crt03 {
	struct {
		uint32 hBlankEnd: 5; // 0
		uint32 hDeSkew: 2; // 5
		uint32 cr10cr11RDisB: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT04
union Crt04 {
	struct {
		uint32 hSyncStart: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT05
union Crt05 {
	struct {
		uint32 hSyncEnd: 5; // 0
		uint32 hSyncSkew: 2; // 5
		uint32 hBlankEndB5: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT06
union Crt06 {
	struct {
		uint32 vTotal: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT07
union Crt07 {
	struct {
		uint32 vTotalB8: 1; // 0
		uint32 vDispEndB8: 1; // 1
		uint32 vSyncStartB8: 1; // 2
		uint32 vBlankStartB8: 1; // 3
		uint32 lineCmpB8: 1; // 4
		uint32 vTotalB9: 1; // 5
		uint32 vDispEndB9: 1; // 6
		uint32 vSyncStartB9: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT08
union Crt08 {
	struct {
		uint32 rowScanStart: 5; // 0
		uint32 bytePan: 2; // 5
		uint32 unknown1: 25;
	};
	uint32 val;
};

// CRT09
union Crt09 {
	struct {
		uint32 maxRowScan: 5; // 0
		uint32 vBlankStartB9: 1; // 5
		uint32 lineCmpB9: 1; // 6
		uint32 doubleCharHeight: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT0A
union Crt0a {
	struct {
		uint32 cursorStart: 5; // 0
		uint32 cursorDisable: 1; // 5
		uint32 unknown1: 26;
	};
	uint32 val;
};

// CRT0B
union Crt0b {
	struct {
		uint32 cursorEnd: 5; // 0
		uint32 cursorSkew: 2; // 5
		uint32 unknown1: 25;
	};
	uint32 val;
};

// CRT0C
union Crt0c {
	struct {
		uint32 dispStart: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT0D
union Crt0d {
	struct {
		uint32 dispStart: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT0E
union Crt0e {
	struct {
		uint32 cursorLocHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT0F
union Crt0f {
	struct {
		uint32 cursorLocLo: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT10
union Crt10 {
	struct {
		uint32 vSyncStart: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT11
union Crt11 {
	struct {
		uint32 vSyncEnd: 4; // 0
		uint32 vIntrClr: 1; // 4
		uint32 vIntrEn: 1; // 5
		uint32 sel5RefreshCyc: 1; // 6
		uint32 c0t7WrOnly: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT12
union Crt12 {
	struct {
		uint32 vDispEnd: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT13
union Crt13 {
	struct {
		uint32 dispPitch: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT14
union Crt14 {
	struct {
		uint32 undrlnLoc: 5; // 0
		uint32 addrCntBy4: 1; // 5
		uint32 doubleWord: 1; // 6
		uint32 unknown1: 25;
	};
	uint32 val;
};

// CRT15
union Crt15 {
	struct {
		uint32 vBlankStart: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT16
union Crt16 {
	struct {
		uint32 vBlankEnd: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT17
union Crt17 {
	struct {
		uint32 ra0AsA13b: 1; // 0
		uint32 ra1AsA14b: 1; // 1
		uint32 vcountBy2: 1; // 2
		uint32 addrCntBy2: 1; // 3
		uint32 unknown1: 1;
		uint32 wrapA15toa0: 1; // 5
		uint32 byteMode: 1; // 6
		uint32 crtcSyncEn: 1; // 7
		uint32 unknown2: 24;
	};
	uint32 val;
};

// CRT18
union Crt18 {
	struct {
		uint32 lineCmp: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT1E
union Crt1e {
	struct {
		uint32 unknown1: 1;
		uint32 grphDecRd1: 1; // 1
		uint32 unknown2: 30;
	};
	uint32 val;
};

// CRT1F
union Crt1f {
	struct {
		uint32 grphDecRd0: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRT22
union Crt22 {
	struct {
		uint32 grphLatchData: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRTC0_PIXEL_RATE_CNTL
union Crtc0PixelRateCntl {
	struct {
		uint32 crtc0PixelRateSource: 2; // 0
		uint32 unknown1: 2;
		uint32 dpDto0Enable: 1; // 4
		uint32 unknown2: 3;
		uint32 crtc0AddPixel: 1; // 8
		uint32 crtc0DropPixel: 1; // 9
		uint32 unknown3: 4;
		uint32 crtc0DispoutFifoError: 2; // 14
		uint32 crtc0DispoutErrorCount: 12; // 16
		uint32 unknown4: 4;
	};
	uint32 val;
};

// CRTC1_PIXEL_RATE_CNTL
union Crtc1PixelRateCntl {
	struct {
		uint32 crtc1PixelRateSource: 2; // 0
		uint32 unknown1: 2;
		uint32 dpDto1Enable: 1; // 4
		uint32 unknown2: 3;
		uint32 crtc1AddPixel: 1; // 8
		uint32 crtc1DropPixel: 1; // 9
		uint32 unknown3: 4;
		uint32 crtc1DispoutFifoError: 2; // 14
		uint32 crtc1DispoutErrorCount: 12; // 16
		uint32 unknown4: 4;
	};
	uint32 val;
};

// CRTC2_PIXEL_RATE_CNTL
union Crtc2PixelRateCntl {
	struct {
		uint32 crtc2PixelRateSource: 2; // 0
		uint32 unknown1: 2;
		uint32 dpDto2Enable: 1; // 4
		uint32 unknown2: 3;
		uint32 crtc2AddPixel: 1; // 8
		uint32 crtc2DropPixel: 1; // 9
		uint32 unknown3: 4;
		uint32 crtc2DispoutFifoError: 2; // 14
		uint32 crtc2DispoutErrorCount: 12; // 16
		uint32 unknown4: 4;
	};
	uint32 val;
};

// CRTC3_PIXEL_RATE_CNTL
union Crtc3PixelRateCntl {
	struct {
		uint32 crtc3PixelRateSource: 2; // 0
		uint32 unknown1: 2;
		uint32 dpDto3Enable: 1; // 4
		uint32 unknown2: 3;
		uint32 crtc3AddPixel: 1; // 8
		uint32 crtc3DropPixel: 1; // 9
		uint32 unknown3: 4;
		uint32 crtc3DispoutFifoError: 2; // 14
		uint32 crtc3DispoutErrorCount: 12; // 16
		uint32 unknown4: 4;
	};
	uint32 val;
};

// CRTC4_PIXEL_RATE_CNTL
union Crtc4PixelRateCntl {
	struct {
		uint32 crtc4PixelRateSource: 2; // 0
		uint32 unknown1: 2;
		uint32 dpDto4Enable: 1; // 4
		uint32 unknown2: 3;
		uint32 crtc4AddPixel: 1; // 8
		uint32 crtc4DropPixel: 1; // 9
		uint32 unknown3: 4;
		uint32 crtc4DispoutFifoError: 2; // 14
		uint32 crtc4DispoutErrorCount: 12; // 16
		uint32 unknown4: 4;
	};
	uint32 val;
};

// CRTC5_PIXEL_RATE_CNTL
union Crtc5PixelRateCntl {
	struct {
		uint32 crtc5PixelRateSource: 2; // 0
		uint32 unknown1: 2;
		uint32 dpDto5Enable: 1; // 4
		uint32 unknown2: 3;
		uint32 crtc5AddPixel: 1; // 8
		uint32 crtc5DropPixel: 1; // 9
		uint32 unknown3: 4;
		uint32 crtc5DispoutFifoError: 2; // 14
		uint32 crtc5DispoutErrorCount: 12; // 16
		uint32 unknown4: 4;
	};
	uint32 val;
};

// CRTC8_DATA
union Crtc8Data {
	struct {
		uint32 vcrtcData: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRTC8_IDX
union Crtc8Idx {
	struct {
		uint32 vcrtcIdx: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// CRTC_3D_STRUCTURE_CONTROL
union Crtc3dStructureControl {
	struct {
		uint32 crtc3dStructureEn: 1; // 0
		uint32 unknown1: 3;
		uint32 crtc3dStructureEnDb: 1; // 4
		uint32 unknown2: 3;
		uint32 crtc3dStructureVUpdateMode: 2; // 8
		uint32 unknown3: 2;
		uint32 crtc3dStructureStereoSelOvr: 1; // 12
		uint32 unknown4: 3;
		uint32 crtc3dStructureFCountReset: 1; // 16
		uint32 crtc3dStructureFCountResetPending: 1; // 17
		uint32 crtc3dStructureFCount: 2; // 18
		uint32 unknown5: 12;
	};
	uint32 val;
};

// CRTC_ALLOW_STOP_OFF_V_CNT
union CrtcAllowStopOffVCnt {
	struct {
		uint32 crtcAllowStopOffVCnt: 8; // 0
		uint32 unknown1: 8;
		uint32 crtcDisableAllowStopOffVCnt: 1; // 16
		uint32 unknown2: 15;
	};
	uint32 val;
};

// CRTC_BLACK_COLOR
union CrtcBlackColor {
	struct {
		uint32 crtcBlackColorBCb: 10; // 0
		uint32 crtcBlackColorGY: 10; // 10
		uint32 crtcBlackColorRCr: 10; // 20
		uint32 unknown1: 2;
	};
	uint32 val;
};

// CRTC_BLANK_CONTROL
union CrtcBlankControl {
	struct {
		uint32 crtcCurrentBlankState: 1; // 0
		uint32 unknown1: 7;
		uint32 crtcBlankDataEn: 1; // 8
		uint32 unknown2: 7;
		uint32 crtcBlankDeMode: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// CRTC_BLANK_DATA_COLOR
union CrtcBlankDataColor {
	struct {
		uint32 crtcBlankDataColorBlueCb: 10; // 0
		uint32 crtcBlankDataColorGreenY: 10; // 10
		uint32 crtcBlankDataColorRedCr: 10; // 20
		uint32 unknown1: 2;
	};
	uint32 val;
};

// CRTC_CONTROL
union CrtcControl {
	struct {
		uint32 crtcMasterEn: 1; // 0
		uint32 unknown1: 3;
		uint32 crtcSyncResetSel: 1; // 4
		uint32 unknown2: 3;
		uint32 crtcDisablePointCntl: 2; // 8
		uint32 unknown3: 2;
		uint32 crtcStartPointCntl: 1; // 12
		uint32 crtcFieldNumberCntl: 1; // 13
		uint32 unknown4: 2;
		uint32 crtcCurrentMasterEnState: 1; // 16
		uint32 unknown5: 3;
		uint32 crtcHblankEarlyControl: 3; // 20
		uint32 unknown6: 1;
		uint32 crtcDispReadRequestDisable: 1; // 24
		uint32 unknown7: 3;
		uint32 crtcPrefetchEn: 1; // 28
		uint32 crtcSofPullEn: 1; // 29
		uint32 unknown8: 2;
	};
	uint32 val;
};

// CRTC_COUNT_CONTROL
union CrtcCountControl {
	struct {
		uint32 crtcHorzCountBy2En: 1; // 0
		uint32 crtcHorzRepetitionCount: 4; // 1
		uint32 unknown1: 27;
	};
	uint32 val;
};

// CRTC_COUNT_RESET
union CrtcCountReset {
	struct {
		uint32 crtcResetFrameCount: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CRTC_DCFE_CLOCK_CONTROL
union CrtcDcfeClockControl {
	struct {
		uint32 unknown1: 4;
		uint32 crtcDispclkRDcfeGateDisable: 1; // 4
		uint32 unknown2: 3;
		uint32 crtcDispclkGDcpGateDisable: 1; // 8
		uint32 unknown3: 3;
		uint32 crtcDispclkGSclGateDisable: 1; // 12
		uint32 unknown4: 11;
		uint32 crtcDcfeTestClkSel: 5; // 24
		uint32 unknown5: 2;
		uint32 crtcDcfeClockEnable: 1; // 31
	};
	uint32 val;
};

// CRTC_DOUBLE_BUFFER_CONTROL
union CrtcDoubleBufferControl {
	struct {
		uint32 crtcUpdatePending: 1; // 0
		uint32 unknown1: 7;
		uint32 crtcUpdateInstantly: 1; // 8
		uint32 unknown2: 7;
		uint32 crtcBlankDataDoubleBufferEn: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// CRTC_DTMTEST_CNTL
union CrtcDtmtestCntl {
	struct {
		uint32 crtcDtmtestCrtcEn: 1; // 0
		uint32 crtcDtmtestClkDiv: 4; // 1
		uint32 unknown1: 27;
	};
	uint32 val;
};

// CRTC_DTMTEST_STATUS_POSITION
union CrtcDtmtestStatusPosition {
	struct {
		uint32 crtcDtmtestVertCount: 13; // 0
		uint32 unknown1: 3;
		uint32 crtcDtmtestHorzCount: 13; // 16
		uint32 unknown2: 3;
	};
	uint32 val;
};

// CRTC_FLOW_CONTROL
union CrtcFlowControl {
	struct {
		uint32 crtcFlowControlSourceSelect: 5; // 0
		uint32 unknown1: 3;
		uint32 crtcFlowControlPolarity: 1; // 8
		uint32 unknown2: 7;
		uint32 crtcFlowControlGranularity: 1; // 16
		uint32 unknown3: 7;
		uint32 crtcFlowControlInputStatus: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// CRTC_FORCE_COUNT_NOW_CNTL
union CrtcForceCountNowCntl {
	struct {
		uint32 crtcForceCountNowMode: 2; // 0
		uint32 unknown1: 2;
		uint32 crtcForceCountNowCheck: 1; // 4
		uint32 unknown2: 3;
		uint32 crtcForceCountNowTrigSel: 1; // 8
		uint32 unknown3: 7;
		uint32 crtcForceCountNowOccurred: 1; // 16
		uint32 unknown4: 7;
		uint32 crtcForceCountNowClear: 1; // 24
		uint32 unknown5: 7;
	};
	uint32 val;
};

// CRTC_GSL_CONTROL
union CrtcGslControl {
	struct {
		uint32 crtcGslCheckLineNum: 13; // 0
		uint32 unknown1: 3;
		uint32 crtcGslForceDelay: 5; // 16
		uint32 unknown2: 7;
		uint32 crtcGslCheckAllFields: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// CRTC_GSL_VSYNC_GAP
union CrtcGslVsyncGap {
	struct {
		uint32 crtcGslVsyncGapLimit: 8; // 0
		uint32 crtcGslVsyncGapDelay: 8; // 8
		uint32 crtcGslVsyncGapSourceSel: 1; // 16
		uint32 crtcGslVsyncGapMode: 2; // 17
		uint32 crtcGslVsyncGapClear: 1; // 19
		uint32 crtcGslVsyncGapOccurred: 1; // 20
		uint32 unknown1: 2;
		uint32 crtcGslVsyncGapMasterFaster: 1; // 23
		uint32 crtcGslVsyncGap: 8; // 24
	};
	uint32 val;
};

// CRTC_GSL_WINDOW
union CrtcGslWindow {
	struct {
		uint32 crtcGslWindowStart: 13; // 0
		uint32 unknown1: 3;
		uint32 crtcGslWindowEnd: 13; // 16
		uint32 unknown2: 3;
	};
	uint32 val;
};

// CRTC_H_BLANK_EARLY_NUM
union CrtcHBlankEarlyNum {
	struct {
		uint32 crtcHBlankEarlyNum: 10; // 0
		uint32 unknown1: 6;
		uint32 crtcHBlankEarlyNumDis: 1; // 16
		uint32 unknown2: 15;
	};
	uint32 val;
};

// CRTC_H_BLANK_START_END
union CrtcHBlankStartEnd {
	struct {
		uint32 crtcHBlankStart: 13; // 0
		uint32 unknown1: 3;
		uint32 crtcHBlankEnd: 13; // 16
		uint32 unknown2: 3;
	};
	uint32 val;
};

// CRTC_H_SYNC_A
union CrtcHSyncA {
	struct {
		uint32 crtcHSyncAStart: 13; // 0
		uint32 unknown1: 3;
		uint32 crtcHSyncAEnd: 13; // 16
		uint32 unknown2: 3;
	};
	uint32 val;
};

// CRTC_H_SYNC_A_CNTL
union CrtcHSyncACntl {
	struct {
		uint32 crtcHSyncAPol: 1; // 0
		uint32 unknown1: 15;
		uint32 crtcCompSyncAEn: 1; // 16
		uint32 crtcHSyncACutoff: 1; // 17
		uint32 unknown2: 14;
	};
	uint32 val;
};

// CRTC_H_SYNC_B
union CrtcHSyncB {
	struct {
		uint32 crtcHSyncBStart: 13; // 0
		uint32 unknown1: 3;
		uint32 crtcHSyncBEnd: 13; // 16
		uint32 unknown2: 3;
	};
	uint32 val;
};

// CRTC_H_SYNC_B_CNTL
union CrtcHSyncBCntl {
	struct {
		uint32 crtcHSyncBPol: 1; // 0
		uint32 unknown1: 15;
		uint32 crtcCompSyncBEn: 1; // 16
		uint32 crtcHSyncBCutoff: 1; // 17
		uint32 unknown2: 14;
	};
	uint32 val;
};

// CRTC_H_TOTAL
union CrtcHTotal {
	struct {
		uint32 crtcHTotal: 13; // 0
		uint32 unknown1: 19;
	};
	uint32 val;
};

// CRTC_INTERLACE_CONTROL
union CrtcInterlaceControl {
	struct {
		uint32 crtcInterlaceEnable: 1; // 0
		uint32 unknown1: 15;
		uint32 crtcInterlaceForceNextField: 2; // 16
		uint32 unknown2: 14;
	};
	uint32 val;
};

// CRTC_INTERLACE_STATUS
union CrtcInterlaceStatus {
	struct {
		uint32 crtcInterlaceCurrentField: 1; // 0
		uint32 crtcInterlaceNextField: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// CRTC_INTERRUPT_CONTROL
union CrtcInterruptControl {
	struct {
		uint32 crtcSnapshotIntMsk: 1; // 0
		uint32 crtcSnapshotIntType: 1; // 1
		uint32 unknown1: 2;
		uint32 crtcVUpdateIntMsk: 1; // 4
		uint32 crtcVUpdateIntType: 1; // 5
		uint32 unknown2: 2;
		uint32 crtcForceCountNowIntMsk: 1; // 8
		uint32 crtcForceCountNowIntType: 1; // 9
		uint32 unknown3: 6;
		uint32 crtcForceVsyncNextLineIntMsk: 1; // 16
		uint32 crtcForceVsyncNextLineIntType: 1; // 17
		uint32 unknown4: 6;
		uint32 crtcTrigaIntMsk: 1; // 24
		uint32 crtcTrigbIntMsk: 1; // 25
		uint32 crtcTrigaIntType: 1; // 26
		uint32 crtcTrigbIntType: 1; // 27
		uint32 crtcVsyncNomIntMsk: 1; // 28
		uint32 crtcVsyncNomIntType: 1; // 29
		uint32 crtcGslVsyncGapIntMsk: 1; // 30
		uint32 crtcGslVsyncGapIntType: 1; // 31
	};
	uint32 val;
};

// CRTC_MANUAL_FORCE_VSYNC_NEXT_LINE
union CrtcManualForceVsyncNextLine {
	struct {
		uint32 crtcManualForceVsyncNextLine: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CRTC_MASTER_EN
union CrtcMasterEn {
	struct {
		uint32 crtcMasterEn: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CRTC_MVP_INBAND_CNTL_INSERT
union CrtcMvpInbandCntlInsert {
	struct {
		uint32 crtcMvpInbandOutMode: 2; // 0
		uint32 unknown1: 6;
		uint32 crtcMvpInbandCntlCharInsert: 24; // 8
	};
	uint32 val;
};

// CRTC_MVP_INBAND_CNTL_INSERT_TIMER
union CrtcMvpInbandCntlInsertTimer {
	struct {
		uint32 crtcMvpInbandCntlCharInsertTimer: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CRTC_MVP_STATUS
union CrtcMvpStatus {
	struct {
		uint32 crtcFlipNowOccurred: 1; // 0
		uint32 unknown1: 3;
		uint32 crtcAfrHsyncSwitchDoneOccurred: 1; // 4
		uint32 unknown2: 11;
		uint32 crtcFlipNowClear: 1; // 16
		uint32 unknown3: 3;
		uint32 crtcAfrHsyncSwitchDoneClear: 1; // 20
		uint32 unknown4: 11;
	};
	uint32 val;
};

// CRTC_NOM_VERT_POSITION
union CrtcNomVertPosition {
	struct {
		uint32 crtcVertCountNom: 13; // 0
		uint32 unknown1: 19;
	};
	uint32 val;
};

// CRTC_OVERSCAN_COLOR
union CrtcOverscanColor {
	struct {
		uint32 crtcOverscanColorBlue: 10; // 0
		uint32 crtcOverscanColorGreen: 10; // 10
		uint32 crtcOverscanColorRed: 10; // 20
		uint32 unknown1: 2;
	};
	uint32 val;
};

// CRTC_SNAPSHOT_CONTROL
union CrtcSnapshotControl {
	struct {
		uint32 crtcAutoSnapshotTrigSel: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// CRTC_SNAPSHOT_FRAME
union CrtcSnapshotFrame {
	struct {
		uint32 crtcSnapshotFrameCount: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// CRTC_SNAPSHOT_POSITION
union CrtcSnapshotPosition {
	struct {
		uint32 crtcSnapshotVertCount: 13; // 0
		uint32 unknown1: 3;
		uint32 crtcSnapshotHorzCount: 13; // 16
		uint32 unknown2: 3;
	};
	uint32 val;
};

// CRTC_SNAPSHOT_STATUS
union CrtcSnapshotStatus {
	struct {
		uint32 crtcSnapshotOccurred: 1; // 0
		uint32 crtcSnapshotClear: 1; // 1
		uint32 crtcSnapshotManualTrigger: 1; // 2
		uint32 unknown1: 29;
	};
	uint32 val;
};

// CRTC_START_LINE_CONTROL
union CrtcStartLineControl {
	struct {
		uint32 crtcProgressiveStartLineEarly: 1; // 0
		uint32 unknown1: 7;
		uint32 crtcInterlaceStartLineEarly: 1; // 8
		uint32 unknown2: 7;
		uint32 crtcAdvancedStartLinePosition: 4; // 16
		uint32 unknown3: 12;
	};
	uint32 val;
};

// CRTC_STATUS
union CrtcStatus {
	struct {
		uint32 crtcVBlank: 1; // 0
		uint32 crtcVActiveDisp: 1; // 1
		uint32 crtcVSyncA: 1; // 2
		uint32 crtcVUpdate: 1; // 3
		uint32 crtcVStartLine: 1; // 4
		uint32 crtcVBlank3dStructure: 1; // 5
		uint32 unknown1: 10;
		uint32 crtcHBlank: 1; // 16
		uint32 crtcHActiveDisp: 1; // 17
		uint32 crtcHSyncA: 1; // 18
		uint32 unknown2: 13;
	};
	uint32 val;
};

// CRTC_STATUS_FRAME_COUNT
union CrtcStatusFrameCount {
	struct {
		uint32 crtcFrameCount: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// CRTC_STATUS_HV_COUNT
union CrtcStatusHvCount {
	struct {
		uint32 crtcHvCount: 29; // 0
		uint32 unknown1: 3;
	};
	uint32 val;
};

// CRTC_STATUS_POSITION
union CrtcStatusPosition {
	struct {
		uint32 crtcVertCount: 13; // 0
		uint32 unknown1: 3;
		uint32 crtcHorzCount: 13; // 16
		uint32 unknown2: 3;
	};
	uint32 val;
};

// CRTC_STATUS_VF_COUNT
union CrtcStatusVfCount {
	struct {
		uint32 crtcVfCount: 29; // 0
		uint32 unknown1: 3;
	};
	uint32 val;
};

// CRTC_STEREO_CONTROL
union CrtcStereoControl {
	struct {
		uint32 crtcStereoSyncOutputLineNum: 13; // 0
		uint32 unknown1: 2;
		uint32 crtcStereoSyncOutputPolarity: 1; // 15
		uint32 crtcStereoSyncSelectPolarity: 1; // 16
		uint32 unknown2: 7;
		uint32 crtcStereoEn: 1; // 24
		uint32 unknown3: 7;
	};
	uint32 val;
};

// CRTC_STEREO_FORCE_NEXT_EYE
union CrtcStereoForceNextEye {
	struct {
		uint32 crtcStereoForceNextEye: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// CRTC_STEREO_STATUS
union CrtcStereoStatus {
	struct {
		uint32 crtcStereoCurrentEye: 1; // 0
		uint32 unknown1: 7;
		uint32 crtcStereoSyncOutput: 1; // 8
		uint32 unknown2: 7;
		uint32 crtcStereoSyncSelect: 1; // 16
		uint32 unknown3: 7;
		uint32 crtcStereoForceNextEyePending: 2; // 24
		uint32 unknown4: 6;
	};
	uint32 val;
};

// CRTC_TEST_DEBUG_DATA
union CrtcTestDebugData {
	struct {
		uint32 crtcTestDebugData: 32; // 0
	};
	uint32 val;
};

// CRTC_TEST_DEBUG_INDEX
union CrtcTestDebugIndex {
	struct {
		uint32 crtcTestDebugIndex: 8; // 0
		uint32 crtcTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// CRTC_TEST_PATTERN_COLOR
union CrtcTestPatternColor {
	struct {
		uint32 crtcTestPatternData: 16; // 0
		uint32 crtcTestPatternMask: 6; // 16
		uint32 unknown1: 10;
	};
	uint32 val;
};

// CRTC_TEST_PATTERN_CONTROL
union CrtcTestPatternControl {
	struct {
		uint32 crtcTestPatternEn: 1; // 0
		uint32 unknown1: 7;
		uint32 crtcTestPatternMode: 3; // 8
		uint32 unknown2: 5;
		uint32 crtcTestPatternDynamicRange: 1; // 16
		uint32 unknown3: 7;
		uint32 crtcTestPatternColorFormat: 8; // 24
	};
	uint32 val;
};

// CRTC_TEST_PATTERN_PARAMETERS
union CrtcTestPatternParameters {
	struct {
		uint32 crtcTestPatternInc0: 4; // 0
		uint32 crtcTestPatternInc1: 4; // 4
		uint32 crtcTestPatternVres: 4; // 8
		uint32 crtcTestPatternHres: 4; // 12
		uint32 crtcTestPatternRamp0Offset: 16; // 16
	};
	uint32 val;
};

// CRTC_TRIGA_CNTL
union CrtcTrigaCntl {
	struct {
		uint32 crtcTrigaSourceSelect: 5; // 0
		uint32 crtcTrigaPolaritySelect: 3; // 5
		uint32 crtcTrigaResyncBypassEn: 1; // 8
		uint32 crtcTrigaInputStatus: 1; // 9
		uint32 crtcTrigaPolarityStatus: 1; // 10
		uint32 crtcTrigaOccurred: 1; // 11
		uint32 crtcTrigaRisingEdgeDetectCntl: 2; // 12
		uint32 unknown1: 2;
		uint32 crtcTrigaFallingEdgeDetectCntl: 2; // 16
		uint32 unknown2: 2;
		uint32 crtcTrigaFrequencySelect: 2; // 20
		uint32 unknown3: 2;
		uint32 crtcTrigaDelay: 5; // 24
		uint32 unknown4: 2;
		uint32 crtcTrigaClear: 1; // 31
	};
	uint32 val;
};

// CRTC_TRIGA_MANUAL_TRIG
union CrtcTrigaManualTrig {
	struct {
		uint32 crtcTrigaManualTrig: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CRTC_TRIGB_CNTL
union CrtcTrigbCntl {
	struct {
		uint32 crtcTrigbSourceSelect: 5; // 0
		uint32 crtcTrigbPolaritySelect: 3; // 5
		uint32 crtcTrigbResyncBypassEn: 1; // 8
		uint32 crtcTrigbInputStatus: 1; // 9
		uint32 crtcTrigbPolarityStatus: 1; // 10
		uint32 crtcTrigbOccurred: 1; // 11
		uint32 crtcTrigbRisingEdgeDetectCntl: 2; // 12
		uint32 unknown1: 2;
		uint32 crtcTrigbFallingEdgeDetectCntl: 2; // 16
		uint32 unknown2: 2;
		uint32 crtcTrigbFrequencySelect: 2; // 20
		uint32 unknown3: 2;
		uint32 crtcTrigbDelay: 5; // 24
		uint32 unknown4: 2;
		uint32 crtcTrigbClear: 1; // 31
	};
	uint32 val;
};

// CRTC_TRIGB_MANUAL_TRIG
union CrtcTrigbManualTrig {
	struct {
		uint32 crtcTrigbManualTrig: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CRTC_UPDATE_LOCK
union CrtcUpdateLock {
	struct {
		uint32 crtcUpdateLock: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CRTC_VBI_END
union CrtcVbiEnd {
	struct {
		uint32 crtcVbiVEnd: 13; // 0
		uint32 unknown1: 3;
		uint32 crtcVbiHEnd: 13; // 16
		uint32 unknown2: 3;
	};
	uint32 val;
};

// CRTC_VERT_SYNC_CONTROL
union CrtcVertSyncControl {
	struct {
		uint32 crtcForceVsyncNextLineOccurred: 1; // 0
		uint32 unknown1: 7;
		uint32 crtcForceVsyncNextLineClear: 1; // 8
		uint32 unknown2: 7;
		uint32 crtcAutoForceVsyncMode: 2; // 16
		uint32 unknown3: 14;
	};
	uint32 val;
};

// CRTC_VGA_PARAMETER_CAPTURE_MODE
union CrtcVgaParameterCaptureMode {
	struct {
		uint32 crtcVgaParameterCaptureMode: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CRTC_VSYNC_NOM_INT_STATUS
union CrtcVsyncNomIntStatus {
	struct {
		uint32 crtcVsyncNom: 1; // 0
		uint32 unknown1: 3;
		uint32 crtcVsyncNomIntClear: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// CRTC_V_BLANK_START_END
union CrtcVBlankStartEnd {
	struct {
		uint32 crtcVBlankStart: 13; // 0
		uint32 unknown1: 3;
		uint32 crtcVBlankEnd: 13; // 16
		uint32 unknown2: 3;
	};
	uint32 val;
};

// CRTC_V_SYNC_A
union CrtcVSyncA {
	struct {
		uint32 crtcVSyncAStart: 13; // 0
		uint32 unknown1: 3;
		uint32 crtcVSyncAEnd: 13; // 16
		uint32 unknown2: 3;
	};
	uint32 val;
};

// CRTC_V_SYNC_A_CNTL
union CrtcVSyncACntl {
	struct {
		uint32 crtcVSyncAPol: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CRTC_V_SYNC_B
union CrtcVSyncB {
	struct {
		uint32 crtcVSyncBStart: 13; // 0
		uint32 unknown1: 3;
		uint32 crtcVSyncBEnd: 13; // 16
		uint32 unknown2: 3;
	};
	uint32 val;
};

// CRTC_V_SYNC_B_CNTL
union CrtcVSyncBCntl {
	struct {
		uint32 crtcVSyncBPol: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CRTC_V_TOTAL
union CrtcVTotal {
	struct {
		uint32 crtcVTotal: 13; // 0
		uint32 unknown1: 19;
	};
	uint32 val;
};

// CRTC_V_TOTAL_CONTROL
union CrtcVTotalControl {
	struct {
		uint32 crtcVTotalMinSel: 1; // 0
		uint32 unknown1: 3;
		uint32 crtcVTotalMaxSel: 1; // 4
		uint32 unknown2: 3;
		uint32 crtcForceLockOnEvent: 1; // 8
		uint32 unknown3: 3;
		uint32 crtcForceLockToMasterVsync: 1; // 12
		uint32 unknown4: 3;
		uint32 crtcSetVTotalMinMask: 16; // 16
	};
	uint32 val;
};

// CRTC_V_TOTAL_INT_STATUS
union CrtcVTotalIntStatus {
	struct {
		uint32 crtcSetVTotalMinEventOccured: 1; // 0
		uint32 unknown1: 3;
		uint32 crtcSetVTotalMinEventOccuredInt: 1; // 4
		uint32 unknown2: 3;
		uint32 crtcSetVTotalMinEventOccuredAck: 1; // 8
		uint32 unknown3: 3;
		uint32 crtcSetVTotalMinEventOccuredMsk: 1; // 12
		uint32 unknown4: 19;
	};
	uint32 val;
};

// CRTC_V_TOTAL_MAX
union CrtcVTotalMax {
	struct {
		uint32 crtcVTotalMax: 13; // 0
		uint32 unknown1: 3;
		uint32 crtcAllowVblankExtensionForMcTraining: 1; // 16
		uint32 unknown2: 15;
	};
	uint32 val;
};

// CRTC_V_TOTAL_MIN
union CrtcVTotalMin {
	struct {
		uint32 crtcVTotalMin: 13; // 0
		uint32 unknown1: 19;
	};
	uint32 val;
};

// CRTC_V_UPDATE_INT_STATUS
union CrtcVUpdateIntStatus {
	struct {
		uint32 crtcVUpdateIntOccurred: 1; // 0
		uint32 unknown1: 7;
		uint32 crtcVUpdateIntClear: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// CUR_COLOR1
union CurColor1 {
	struct {
		uint32 curColor1Blue: 8; // 0
		uint32 curColor1Green: 8; // 8
		uint32 curColor1Red: 8; // 16
		uint32 unknown1: 8;
	};
	uint32 val;
};

// CUR_COLOR2
union CurColor2 {
	struct {
		uint32 curColor2Blue: 8; // 0
		uint32 curColor2Green: 8; // 8
		uint32 curColor2Red: 8; // 16
		uint32 unknown1: 8;
	};
	uint32 val;
};

// CUR_CONTROL
union CurControl {
	struct {
		uint32 cursorEn: 1; // 0
		uint32 unknown1: 3;
		uint32 curInvTransClamp: 1; // 4
		uint32 unknown2: 3;
		uint32 cursorMode: 2; // 8
		uint32 unknown3: 6;
		uint32 cursor2xMagnify: 1; // 16
		uint32 unknown4: 3;
		uint32 cursorForceMcOn: 1; // 20
		uint32 unknown5: 3;
		uint32 cursorUrgentControl: 3; // 24
		uint32 unknown6: 5;
	};
	uint32 val;
};

// CUR_HOT_SPOT
union CurHotSpot {
	struct {
		uint32 cursorHotSpotY: 6; // 0
		uint32 unknown1: 10;
		uint32 cursorHotSpotX: 6; // 16
		uint32 unknown2: 10;
	};
	uint32 val;
};

// CUR_POSITION
union CurPosition {
	struct {
		uint32 cursorYPosition: 14; // 0
		uint32 unknown1: 2;
		uint32 cursorXPosition: 14; // 16
		uint32 unknown2: 2;
	};
	uint32 val;
};

// CUR_REQUEST_FILTER_CNTL
union CurRequestFilterCntl {
	struct {
		uint32 curRequestFilterDis: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// CUR_SIZE
union CurSize {
	struct {
		uint32 cursorHeight: 6; // 0
		uint32 unknown1: 10;
		uint32 cursorWidth: 6; // 16
		uint32 unknown2: 10;
	};
	uint32 val;
};

// CUR_SURFACE_ADDRESS
union CurSurfaceAddress {
	struct {
		uint32 cursorSurfaceAddress: 32; // 0
	};
	uint32 val;
};

// CUR_SURFACE_ADDRESS_HIGH
union CurSurfaceAddressHigh {
	struct {
		uint32 cursorSurfaceAddressHigh: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// CUR_UPDATE
union CurUpdate {
	struct {
		uint32 cursorUpdatePending: 1; // 0
		uint32 cursorUpdateTaken: 1; // 1
		uint32 unknown1: 14;
		uint32 cursorUpdateLock: 1; // 16
		uint32 unknown2: 7;
		uint32 cursorDisableMultipleUpdate: 1; // 24
		uint32 unknown3: 7;
	};
	uint32 val;
};

// D1VGA_CONTROL
union D1vgaControl {
	struct {
		uint32 d1vgaModeEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 d1vgaTimingSelect: 1; // 8
		uint32 d1vgaSyncPolaritySelect: 1; // 9
		uint32 unknown2: 6;
		uint32 d1vgaOverscanColorEn: 1; // 16
		uint32 unknown3: 7;
		uint32 d1vgaRotate: 2; // 24
		uint32 unknown4: 6;
	};
	uint32 val;
};

// D2VGA_CONTROL
union D2vgaControl {
	struct {
		uint32 d2vgaModeEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 d2vgaTimingSelect: 1; // 8
		uint32 d2vgaSyncPolaritySelect: 1; // 9
		uint32 unknown2: 6;
		uint32 d2vgaOverscanColorEn: 1; // 16
		uint32 unknown3: 7;
		uint32 d2vgaRotate: 2; // 24
		uint32 unknown4: 6;
	};
	uint32 val;
};

// D3VGA_CONTROL
union D3vgaControl {
	struct {
		uint32 d3vgaModeEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 d3vgaTimingSelect: 1; // 8
		uint32 d3vgaSyncPolaritySelect: 1; // 9
		uint32 unknown2: 6;
		uint32 d3vgaOverscanColorEn: 1; // 16
		uint32 unknown3: 7;
		uint32 d3vgaRotate: 2; // 24
		uint32 unknown4: 6;
	};
	uint32 val;
};

// D4VGA_CONTROL
union D4vgaControl {
	struct {
		uint32 d4vgaModeEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 d4vgaTimingSelect: 1; // 8
		uint32 d4vgaSyncPolaritySelect: 1; // 9
		uint32 unknown2: 6;
		uint32 d4vgaOverscanColorEn: 1; // 16
		uint32 unknown3: 7;
		uint32 d4vgaRotate: 2; // 24
		uint32 unknown4: 6;
	};
	uint32 val;
};

// D5VGA_CONTROL
union D5vgaControl {
	struct {
		uint32 d5vgaModeEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 d5vgaTimingSelect: 1; // 8
		uint32 d5vgaSyncPolaritySelect: 1; // 9
		uint32 unknown2: 6;
		uint32 d5vgaOverscanColorEn: 1; // 16
		uint32 unknown3: 7;
		uint32 d5vgaRotate: 2; // 24
		uint32 unknown4: 6;
	};
	uint32 val;
};

// D6VGA_CONTROL
union D6vgaControl {
	struct {
		uint32 d6vgaModeEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 d6vgaTimingSelect: 1; // 8
		uint32 d6vgaSyncPolaritySelect: 1; // 9
		uint32 unknown2: 6;
		uint32 d6vgaOverscanColorEn: 1; // 16
		uint32 unknown3: 7;
		uint32 d6vgaRotate: 2; // 24
		uint32 unknown4: 6;
	};
	uint32 val;
};

// DAC_AUTODETECT_CONTROL
union DacAutodetectControl {
	struct {
		uint32 dacAutodetectMode: 2; // 0
		uint32 unknown1: 6;
		uint32 dacAutodetectFrameTimeCounter: 8; // 8
		uint32 dacAutodetectCheckMask: 3; // 16
		uint32 unknown2: 13;
	};
	uint32 val;
};

// DAC_AUTODETECT_CONTROL2
union DacAutodetectControl2 {
	struct {
		uint32 dacAutodetectPowerupCounter: 8; // 0
		uint32 dacAutodetectTestmode: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// DAC_AUTODETECT_CONTROL3
union DacAutodetectControl3 {
	struct {
		uint32 dacAutodetComparatorInDelay: 8; // 0
		uint32 dacAutodetComparatorOutDelay: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// DAC_AUTODETECT_INT_CONTROL
union DacAutodetectIntControl {
	struct {
		uint32 dacAutodetectAck: 1; // 0
		uint32 unknown1: 15;
		uint32 dacAutodetectIntEnable: 1; // 16
		uint32 unknown2: 15;
	};
	uint32 val;
};

// DAC_AUTODETECT_STATUS
union DacAutodetectStatus {
	struct {
		uint32 dacAutodetectStatus: 1; // 0
		uint32 unknown1: 3;
		uint32 dacAutodetectConnect: 1; // 4
		uint32 unknown2: 3;
		uint32 dacAutodetectRedSense: 2; // 8
		uint32 unknown3: 6;
		uint32 dacAutodetectGreenSense: 2; // 16
		uint32 unknown4: 6;
		uint32 dacAutodetectBlueSense: 2; // 24
		uint32 unknown5: 6;
	};
	uint32 val;
};

// DAC_CLK_ENABLE
union DacClkEnable {
	struct {
		uint32 dacaClkEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 dacbClkEnable: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// DAC_COMPARATOR_ENABLE
union DacComparatorEnable {
	struct {
		uint32 dacCompDdetRefEn: 1; // 0
		uint32 unknown1: 7;
		uint32 dacCompSdetRefEn: 1; // 8
		uint32 unknown2: 7;
		uint32 dacRAsyncEnable: 1; // 16
		uint32 dacGAsyncEnable: 1; // 17
		uint32 dacBAsyncEnable: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// DAC_COMPARATOR_OUTPUT
union DacComparatorOutput {
	struct {
		uint32 dacComparatorOutput: 1; // 0
		uint32 dacComparatorOutputBlue: 1; // 1
		uint32 dacComparatorOutputGreen: 1; // 2
		uint32 dacComparatorOutputRed: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// DAC_CONTROL
union DacControl {
	struct {
		uint32 dacDforceEn: 1; // 0
		uint32 unknown1: 7;
		uint32 dacTvEnable: 1; // 8
		uint32 unknown2: 7;
		uint32 dacZscaleShift: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// DAC_CRC_CONTROL
union DacCrcControl {
	struct {
		uint32 dacCrcField: 1; // 0
		uint32 unknown1: 7;
		uint32 dacCrcOnlyBlankb: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DAC_CRC_EN
union DacCrcEn {
	struct {
		uint32 dacCrcEn: 1; // 0
		uint32 unknown1: 15;
		uint32 dacCrcContEn: 1; // 16
		uint32 unknown2: 15;
	};
	uint32 val;
};

// DAC_CRC_SIG_CONTROL
union DacCrcSigControl {
	struct {
		uint32 dacCrcSigControl: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// DAC_CRC_SIG_CONTROL_MASK
union DacCrcSigControlMask {
	struct {
		uint32 dacCrcSigControlMask: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// DAC_CRC_SIG_RGB
union DacCrcSigRgb {
	struct {
		uint32 dacCrcSigBlue: 10; // 0
		uint32 dacCrcSigGreen: 10; // 10
		uint32 dacCrcSigRed: 10; // 20
		uint32 unknown1: 2;
	};
	uint32 val;
};

// DAC_CRC_SIG_RGB_MASK
union DacCrcSigRgbMask {
	struct {
		uint32 dacCrcSigBlueMask: 10; // 0
		uint32 dacCrcSigGreenMask: 10; // 10
		uint32 dacCrcSigRedMask: 10; // 20
		uint32 unknown1: 2;
	};
	uint32 val;
};

// DAC_DATA
union DacData {
	struct {
		uint32 dacData: 6; // 0
		uint32 unknown1: 26;
	};
	uint32 val;
};

// DAC_DFT_CONFIG
union DacDftConfig {
	struct {
		uint32 dacDftConfig: 32; // 0
	};
	uint32 val;
};

// DAC_ENABLE
union DacEnable {
	struct {
		uint32 dacEnable: 1; // 0
		uint32 dacResyncFifoEnable: 1; // 1
		uint32 dacResyncFifoPointerSkew: 2; // 2
		uint32 dacResyncFifoError: 1; // 4
		uint32 dacResyncFifoErrorAck: 1; // 5
		uint32 unknown1: 2;
		uint32 dacResyncFifoTvoutSim: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DAC_FIFO_STATUS
union DacFifoStatus {
	struct {
		uint32 unknown1: 1;
		uint32 dacFifoUseOverwriteLevel: 1; // 1
		uint32 dacFifoOverwriteLevel: 6; // 2
		uint32 unknown2: 2;
		uint32 dacFifoCalAverageLevel: 6; // 10
		uint32 dacFifoMaximumLevel: 4; // 16
		uint32 unknown3: 2;
		uint32 dacFifoMinimumLevel: 4; // 22
		uint32 unknown4: 3;
		uint32 dacFifoCalibrated: 1; // 29
		uint32 dacFifoForceRecalAverage: 1; // 30
		uint32 dacFifoForceRecompMinmax: 1; // 31
	};
	uint32 val;
};

// DAC_FORCE_DATA
union DacForceData {
	struct {
		uint32 dacForceData: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// DAC_FORCE_OUTPUT_CNTL
union DacForceOutputCntl {
	struct {
		uint32 dacForceDataEn: 1; // 0
		uint32 unknown1: 7;
		uint32 dacForceDataSel: 3; // 8
		uint32 unknown2: 13;
		uint32 dacForceDataOnBlankbOnly: 1; // 24
		uint32 unknown3: 7;
	};
	uint32 val;
};

// DAC_MACRO_CNTL_RESERVED0
union DacMacroCntlReserved0 {
	struct {
		uint32 dacMacroCntlReserved: 32; // 0
	};
	uint32 val;
};

// DAC_MACRO_CNTL_RESERVED1
union DacMacroCntlReserved1 {
	struct {
		uint32 dacMacroCntlReserved: 32; // 0
	};
	uint32 val;
};

// DAC_MACRO_CNTL_RESERVED2
union DacMacroCntlReserved2 {
	struct {
		uint32 dacMacroCntlReserved: 32; // 0
	};
	uint32 val;
};

// DAC_MACRO_CNTL_RESERVED3
union DacMacroCntlReserved3 {
	struct {
		uint32 dacMacroCntlReserved: 32; // 0
	};
	uint32 val;
};

// DAC_MASK
union DacMask {
	struct {
		uint32 dacMask: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// DAC_POWERDOWN
union DacPowerdown {
	struct {
		uint32 dacPowerdown: 1; // 0
		uint32 unknown1: 7;
		uint32 dacPowerdownBlue: 1; // 8
		uint32 unknown2: 7;
		uint32 dacPowerdownGreen: 1; // 16
		uint32 unknown3: 7;
		uint32 dacPowerdownRed: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// DAC_PWR_CNTL
union DacPwrCntl {
	struct {
		uint32 dacBgMode: 2; // 0
		uint32 unknown1: 14;
		uint32 dacPwrcntl: 2; // 16
		uint32 unknown2: 14;
	};
	uint32 val;
};

// DAC_R_INDEX
union DacRIndex {
	struct {
		uint32 dacRIndex: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// DAC_SOURCE_SELECT
union DacSourceSelect {
	struct {
		uint32 dacSourceSelect: 3; // 0
		uint32 dacTvSelect: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// DAC_STEREOSYNC_SELECT
union DacStereosyncSelect {
	struct {
		uint32 dacStereosyncSelect: 3; // 0
		uint32 unknown1: 29;
	};
	uint32 val;
};

// DAC_SYNC_TRISTATE_CONTROL
union DacSyncTristateControl {
	struct {
		uint32 dacHsyncaTristate: 1; // 0
		uint32 unknown1: 7;
		uint32 dacVsyncaTristate: 1; // 8
		uint32 unknown2: 7;
		uint32 dacSyncaTristate: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// DAC_W_INDEX
union DacWIndex {
	struct {
		uint32 dacWIndex: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// DATA_FORMAT
union DataFormat {
	struct {
		uint32 interleaveEn: 1; // 0
		uint32 unknown1: 3;
		uint32 resetReqAtEol: 1; // 4
		uint32 unknown2: 7;
		uint32 prefetch: 1; // 12
		uint32 unknown3: 3;
		uint32 sofReadPt: 5; // 16
		uint32 unknown4: 3;
		uint32 requestMode: 2; // 24
		uint32 unknown5: 2;
		uint32 allowReqMode1_2: 1; // 28
		uint32 unknown6: 3;
	};
	uint32 val;
};

// DCCG_AUDIO_DTO0_MODULE
union DccgAudioDto0Module {
	struct {
		uint32 dccgAudioDto0Module: 32; // 0
	};
	uint32 val;
};

// DCCG_AUDIO_DTO0_PHASE
union DccgAudioDto0Phase {
	struct {
		uint32 dccgAudioDto0Phase: 32; // 0
	};
	uint32 val;
};

// DCCG_AUDIO_DTO1_MODULE
union DccgAudioDto1Module {
	struct {
		uint32 dccgAudioDto1Module: 32; // 0
	};
	uint32 val;
};

// DCCG_AUDIO_DTO1_PHASE
union DccgAudioDto1Phase {
	struct {
		uint32 dccgAudioDto1Phase: 32; // 0
	};
	uint32 val;
};

// DCCG_AUDIO_DTO_SOURCE
union DccgAudioDtoSource {
	struct {
		uint32 dccgAudioDto0SourceSel: 3; // 0
		uint32 unknown1: 1;
		uint32 dccgAudioDtoSel: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// DCCG_CAC_STATUS
union DccgCacStatus {
	struct {
		uint32 cacStatusRddata: 32; // 0
	};
	uint32 val;
};

// DCCG_GATE_DISABLE_CNTL
union DccgGateDisableCntl {
	struct {
		uint32 dispclkDccgGateDisable: 1; // 0
		uint32 dispclkRDccgGateDisable: 1; // 1
		uint32 sclkGateDisable: 1; // 2
		uint32 unknown1: 1;
		uint32 dacaclkGateDisable: 1; // 4
		uint32 dacbclkGateDisable: 1; // 5
		uint32 dvoaclkGateDisable: 1; // 6
		uint32 unknown2: 1;
		uint32 symclkaGateDisable: 1; // 8
		uint32 symclkbGateDisable: 1; // 9
		uint32 symclkcGateDisable: 1; // 10
		uint32 symclkdGateDisable: 1; // 11
		uint32 symclkeGateDisable: 1; // 12
		uint32 symclkfGateDisable: 1; // 13
		uint32 unknown3: 2;
		uint32 pclkTvGateDisable: 1; // 16
		uint32 unknown4: 3;
		uint32 dispclkRDccgRampDisable: 1; // 20
		uint32 unknown5: 3;
		uint32 dispclkRampDivId: 3; // 24
		uint32 unknown6: 1;
		uint32 sclkRampDivId: 3; // 28
		uint32 unknown7: 1;
	};
	uint32 val;
};

// DCCG_GTC_CNTL
union DccgGtcCntl {
	struct {
		uint32 dccgGtcEnable: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// DCCG_GTC_CURRENT
union DccgGtcCurrent {
	struct {
		uint32 dccgGtcCurrent: 32; // 0
	};
	uint32 val;
};

// DCCG_GTC_DTO_MODULO
union DccgGtcDtoModulo {
	struct {
		uint32 dccgGtcDtoModulo: 32; // 0
	};
	uint32 val;
};

// DCCG_PERFMON_CNTL
union DccgPerfmonCntl {
	struct {
		uint32 dccgPerfDispclkEnable: 1; // 0
		uint32 dccgPerfDprefclkEnable: 1; // 1
		uint32 dccgPerfPixclk1Enable: 1; // 2
		uint32 dccgPerfPixclk2Enable: 1; // 3
		uint32 dccgPerfPixclk0Enable: 1; // 4
		uint32 dccgPerfRun: 1; // 5
		uint32 dccgPerfModeVsync: 1; // 6
		uint32 dccgPerfModeHsync: 1; // 7
		uint32 dccgPerfCrtcSel: 3; // 8
		uint32 unknown1: 21;
	};
	uint32 val;
};

// DCCG_SOFT_RESET
union DccgSoftReset {
	struct {
		uint32 refclkSoftReset: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// DCCG_TEST_CLK_SEL
union DccgTestClkSel {
	struct {
		uint32 dccgTestClkGenericaSel: 8; // 0
		uint32 dccgTestClkGenericbSel: 8; // 8
		uint32 dccgTestClkGenericaInv: 1; // 16
		uint32 unknown1: 7;
		uint32 dccgTestClkGenericbInv: 1; // 24
		uint32 unknown2: 7;
	};
	uint32 val;
};

// DCCG_TEST_DEBUG_DATA
union DccgTestDebugData {
	struct {
		uint32 dccgTestDebugData: 32; // 0
	};
	uint32 val;
};

// DCCG_TEST_DEBUG_INDEX
union DccgTestDebugIndex {
	struct {
		uint32 dccgTestDebugIndex: 8; // 0
		uint32 dccgTestDebugWriteEn: 1; // 8
		uint32 unknown1: 3;
		uint32 dccgDbgSel: 1; // 12
		uint32 unknown2: 19;
	};
	uint32 val;
};

// DCCG_VPCLK_CNTL
union DccgVpclkCntl {
	struct {
		uint32 dccgVpclkPol: 1; // 0
		uint32 vgaLightSleepModeForce: 1; // 1
		uint32 azLightSleepDis: 1; // 2
		uint32 dmcuLightSleepDis: 1; // 3
		uint32 mcifLightSleepModeForce: 1; // 4
		uint32 dmifXlrLightSleepModeForce: 1; // 5
		uint32 unknown1: 2;
		uint32 dmif0LightSleepDis: 1; // 8
		uint32 dmif1LightSleepDis: 1; // 9
		uint32 dmif2LightSleepDis: 1; // 10
		uint32 dmif3LightSleepDis: 1; // 11
		uint32 dmif4LightSleepDis: 1; // 12
		uint32 dmif5LightSleepDis: 1; // 13
		uint32 fbcLightSleepDis: 1; // 14
		uint32 vipLightSleepDis: 1; // 15
		uint32 dmcuMemShutdownDis: 1; // 16
		uint32 mcifMemShutdownModeForce: 1; // 17
		uint32 dmifXlrMemShutdownModeForce: 1; // 18
		uint32 fbcMemShutdownDis: 1; // 19
		uint32 dmif0MemShutdownDis: 1; // 20
		uint32 dmif1MemShutdownDis: 1; // 21
		uint32 dmif2MemShutdownDis: 1; // 22
		uint32 dmif3MemShutdownDis: 1; // 23
		uint32 dmif4MemShutdownDis: 1; // 24
		uint32 dmif5MemShutdownDis: 1; // 25
		uint32 azMemShutdownDis: 1; // 26
		uint32 unknown2: 5;
	};
	uint32 val;
};

// DCDEBUG_BUS_CLK1_SEL
union DcdebugBusClk1Sel {
	struct {
		uint32 dcdebugBusClk1Sel: 32; // 0
	};
	uint32 val;
};

// DCDEBUG_BUS_CLK2_SEL
union DcdebugBusClk2Sel {
	struct {
		uint32 dcdebugBusClk2Sel: 32; // 0
	};
	uint32 val;
};

// DCDEBUG_BUS_CLK3_SEL
union DcdebugBusClk3Sel {
	struct {
		uint32 dcdebugBusClk3Sel: 32; // 0
	};
	uint32 val;
};

// DCDEBUG_BUS_CLK4_SEL
union DcdebugBusClk4Sel {
	struct {
		uint32 dcdebugBusClk4Sel: 32; // 0
	};
	uint32 val;
};

// DCDEBUG_OUT_CNTL
union DcdebugOutCntl {
	struct {
		uint32 dcdebugBlockSel: 5; // 0
		uint32 dcdebugOutEn: 1; // 5
		uint32 dcdebugOutPinSel: 1; // 6
		uint32 dcdebugOutTestDataEn: 1; // 7
		uint32 dcdebugOutTestData: 12; // 8
		uint32 dcdebugOutSel: 2; // 20
		uint32 unknown1: 10;
	};
	uint32 val;
};

// DCDEBUG_OUT_DATA
union DcdebugOutData {
	struct {
		uint32 dcdebugOutData: 32; // 0
	};
	uint32 val;
};

// DCDEBUG_OUT_PIN_OVERRIDE
union DcdebugOutPinOverride {
	struct {
		uint32 dcdebugOutOverride1PinSel: 4; // 0
		uint32 dcdebugOutOverride1RegbitSel: 5; // 4
		uint32 unknown1: 3;
		uint32 dcdebugOutOverride1En: 1; // 12
		uint32 unknown2: 3;
		uint32 dcdebugOutOverride2PinSel: 4; // 16
		uint32 dcdebugOutOverride2RegbitSel: 5; // 20
		uint32 unknown3: 3;
		uint32 dcdebugOutOverride2En: 1; // 28
		uint32 unknown4: 3;
	};
	uint32 val;
};

// DCFE0_SOFT_RESET
union Dcfe0SoftReset {
	struct {
		uint32 dcp0PixpipeSoftReset: 1; // 0
		uint32 dcp0ReqSoftReset: 1; // 1
		uint32 scl0AluSoftReset: 1; // 2
		uint32 scl0SoftReset: 1; // 3
		uint32 crtc0SoftReset: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// DCFE1_SOFT_RESET
union Dcfe1SoftReset {
	struct {
		uint32 dcp1PixpipeSoftReset: 1; // 0
		uint32 dcp1ReqSoftReset: 1; // 1
		uint32 scl1AluSoftReset: 1; // 2
		uint32 scl1SoftReset: 1; // 3
		uint32 crtc1SoftReset: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// DCFE2_SOFT_RESET
union Dcfe2SoftReset {
	struct {
		uint32 dcp2PixpipeSoftReset: 1; // 0
		uint32 dcp2ReqSoftReset: 1; // 1
		uint32 scl2AluSoftReset: 1; // 2
		uint32 scl2SoftReset: 1; // 3
		uint32 crtc2SoftReset: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// DCFE3_SOFT_RESET
union Dcfe3SoftReset {
	struct {
		uint32 dcp3PixpipeSoftReset: 1; // 0
		uint32 dcp3ReqSoftReset: 1; // 1
		uint32 scl3AluSoftReset: 1; // 2
		uint32 scl3SoftReset: 1; // 3
		uint32 crtc3SoftReset: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// DCFE4_SOFT_RESET
union Dcfe4SoftReset {
	struct {
		uint32 dcp4PixpipeSoftReset: 1; // 0
		uint32 dcp4ReqSoftReset: 1; // 1
		uint32 scl4AluSoftReset: 1; // 2
		uint32 scl4SoftReset: 1; // 3
		uint32 crtc4SoftReset: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// DCFE5_SOFT_RESET
union Dcfe5SoftReset {
	struct {
		uint32 dcp5PixpipeSoftReset: 1; // 0
		uint32 dcp5ReqSoftReset: 1; // 1
		uint32 scl5AluSoftReset: 1; // 2
		uint32 scl5SoftReset: 1; // 3
		uint32 crtc5SoftReset: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// DCFE_DBG_SEL
union DcfeDbgSel {
	struct {
		uint32 dcfeDbgSel: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// DCFE_MEM_LIGHT_SLEEP_CNTL
union DcfeMemLightSleepCntl {
	struct {
		uint32 dcpCursorLightSleepDis: 1; // 0
		uint32 unknown1: 1;
		uint32 dcpLutLightSleepDis: 1; // 2
		uint32 ovlsclLightSleepDis: 1; // 3
		uint32 lbLightSleepDis: 1; // 4
		uint32 sclLightSleepDis: 1; // 5
		uint32 regammaLutLightSleepDis: 1; // 6
		uint32 unknown2: 1;
		uint32 dcpCursorMemPwrState: 2; // 8
		uint32 unknown3: 2;
		uint32 dcpLutMemPwrState: 2; // 12
		uint32 ovlsclMemPwrState: 2; // 14
		uint32 lbMemPwrState0: 2; // 16
		uint32 sclMemPwrState: 2; // 18
		uint32 regammaLutMemPwrState: 2; // 20
		uint32 lbMemPwrState1: 2; // 22
		uint32 lbMemPwrState2: 2; // 24
		uint32 unknown4: 2;
		uint32 pipeMemShutdownDis: 1; // 28
		uint32 lb1MemShutdownDis: 1; // 29
		uint32 lb2MemShutdownDis: 1; // 30
		uint32 unknown5: 1;
	};
	uint32 val;
};

// DCIO_DEBUG
union DcioDebug {
	struct {
		uint32 dcioDebug: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUG1
union DcioDebug1 {
	struct {
		uint32 doutDcioMvpDvocntlA0Reg: 2; // 0
		uint32 doutDcioMvpDvocntlMaskReg: 2; // 2
		uint32 doutDcioMvpDvocntlEnReg: 2; // 4
		uint32 doutDcioMvpDvocntlA0: 2; // 6
		uint32 doutDcioMvpDvocntlSel0: 2; // 8
		uint32 doutDcioMvpDvocntlEn: 2; // 10
		uint32 doutDcioMvpDvoclkC: 1; // 12
		uint32 doutDcioDvocntl1A0Reg: 1; // 13
		uint32 doutDcioDvocntl1A0Premux: 1; // 14
		uint32 doutDcioDvocntl1A0: 1; // 15
		uint32 doutDcioDvocntl1EnReg: 1; // 16
		uint32 doutDcioDvoHsyncTristate: 1; // 17
		uint32 doutDcioDvoClkTristate: 1; // 18
		uint32 doutDcioDvocntl1EnPremux: 1; // 19
		uint32 doutDcioDvocntl1En: 1; // 20
		uint32 doutDcioDvocntl1Mux: 1; // 21
		uint32 doutDcioDvocntl1MaskReg: 1; // 22
		uint32 doutDcioDvoEnable: 1; // 23
		uint32 doutDcioDvoVsyncTristate: 1; // 24
		uint32 doutDcioDvoRateSel: 1; // 25
		uint32 doutDcioDvocntl1Sel0Premux: 1; // 26
		uint32 doutDcioDvocntl1Sel0: 1; // 27
		uint32 unknown1: 4;
	};
	uint32 val;
};

// DCIO_DEBUG10
union DcioDebug10 {
	struct {
		uint32 dcioDigcDebug: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUG11
union DcioDebug11 {
	struct {
		uint32 dcioDigdDebug: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUG12
union DcioDebug12 {
	struct {
		uint32 dcioDigeDebug: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUG13
union DcioDebug13 {
	struct {
		uint32 dcioDigfDebug: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUG2
union DcioDebug2 {
	struct {
		uint32 dcioDebug2: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUG3
union DcioDebug3 {
	struct {
		uint32 dcioDebug3: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUG4
union DcioDebug4 {
	struct {
		uint32 dcioDebug4: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUG5
union DcioDebug5 {
	struct {
		uint32 dcioDebug5: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUG6
union DcioDebug6 {
	struct {
		uint32 dcioDebug6: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUG7
union DcioDebug7 {
	struct {
		uint32 dcioDebug7: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUG8
union DcioDebug8 {
	struct {
		uint32 dcioDebug8: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUG9
union DcioDebug9 {
	struct {
		uint32 dcioDebug9: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUGA
union DcioDebuga {
	struct {
		uint32 dcioDebuga: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUGB
union DcioDebugb {
	struct {
		uint32 dcioDebugb: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUGC
union DcioDebugc {
	struct {
		uint32 dcioDebugc: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUGD
union DcioDebugd {
	struct {
		uint32 dcioDebugd: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUGE
union DcioDebuge {
	struct {
		uint32 dcioDigaDebug: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUGF
union DcioDebugf {
	struct {
		uint32 dcioDigbDebug: 32; // 0
	};
	uint32 val;
};

// DCIO_DEBUG_ID
union DcioDebugId {
	struct {
		uint32 dcioDebugId: 32; // 0
	};
	uint32 val;
};

// DCIO_GSL0_CNTL
union DcioGsl0Cntl {
	struct {
		uint32 dcioGsl0VsyncSel: 3; // 0
		uint32 unknown1: 5;
		uint32 dcioGsl0TimingSyncSel: 3; // 8
		uint32 unknown2: 5;
		uint32 dcioGsl0GlobalUnlockSel: 3; // 16
		uint32 unknown3: 13;
	};
	uint32 val;
};

// DCIO_GSL1_CNTL
union DcioGsl1Cntl {
	struct {
		uint32 dcioGsl1VsyncSel: 3; // 0
		uint32 unknown1: 5;
		uint32 dcioGsl1TimingSyncSel: 3; // 8
		uint32 unknown2: 5;
		uint32 dcioGsl1GlobalUnlockSel: 3; // 16
		uint32 unknown3: 13;
	};
	uint32 val;
};

// DCIO_GSL2_CNTL
union DcioGsl2Cntl {
	struct {
		uint32 dcioGsl2VsyncSel: 3; // 0
		uint32 unknown1: 5;
		uint32 dcioGsl2TimingSyncSel: 3; // 8
		uint32 unknown2: 5;
		uint32 dcioGsl2GlobalUnlockSel: 3; // 16
		uint32 unknown3: 13;
	};
	uint32 val;
};

// DCIO_GSL_GENLK_PAD_CNTL
union DcioGslGenlkPadCntl {
	struct {
		uint32 dcioGenlkClkGslTimingSyncSel: 2; // 0
		uint32 unknown1: 2;
		uint32 dcioGenlkClkGslFlipLockSel: 2; // 4
		uint32 unknown2: 2;
		uint32 dcioGenlkClkGslMask: 2; // 8
		uint32 unknown3: 6;
		uint32 dcioGenlkVsyncGslTimingSyncSel: 2; // 16
		uint32 unknown4: 2;
		uint32 dcioGenlkVsyncGslFlipLockSel: 2; // 20
		uint32 unknown5: 2;
		uint32 dcioGenlkVsyncGslMask: 2; // 24
		uint32 unknown6: 6;
	};
	uint32 val;
};

// DCIO_GSL_SWAPLOCK_PAD_CNTL
union DcioGslSwaplockPadCntl {
	struct {
		uint32 dcioSwaplockAGslTimingSyncSel: 2; // 0
		uint32 unknown1: 2;
		uint32 dcioSwaplockAGslFlipLockSel: 2; // 4
		uint32 unknown2: 2;
		uint32 dcioSwaplockAGslMask: 2; // 8
		uint32 unknown3: 6;
		uint32 dcioSwaplockBGslTimingSyncSel: 2; // 16
		uint32 unknown4: 2;
		uint32 dcioSwaplockBGslFlipLockSel: 2; // 20
		uint32 unknown5: 2;
		uint32 dcioSwaplockBGslMask: 2; // 24
		uint32 unknown6: 6;
	};
	uint32 val;
};

// DCIO_IMPCAL_CNTL_AB
union DcioImpcalCntlAb {
	struct {
		uint32 calrCntlOverride: 4; // 0
		uint32 unknown1: 1;
		uint32 impcalSoftReset: 1; // 5
		uint32 unknown2: 2;
		uint32 impcalStatus: 2; // 8
		uint32 unknown3: 2;
		uint32 impcalArbState: 3; // 12
		uint32 unknown4: 17;
	};
	uint32 val;
};

// DCIO_IMPCAL_CNTL_CD
union DcioImpcalCntlCd {
	struct {
		uint32 calrCntlOverride: 4; // 0
		uint32 unknown1: 1;
		uint32 impcalSoftReset: 1; // 5
		uint32 unknown2: 2;
		uint32 impcalStatus: 2; // 8
		uint32 unknown3: 2;
		uint32 impcalArbState: 3; // 12
		uint32 unknown4: 17;
	};
	uint32 val;
};

// DCIO_IMPCAL_CNTL_EF
union DcioImpcalCntlEf {
	struct {
		uint32 calrCntlOverride: 4; // 0
		uint32 unknown1: 1;
		uint32 impcalSoftReset: 1; // 5
		uint32 unknown2: 2;
		uint32 impcalStatus: 2; // 8
		uint32 unknown3: 2;
		uint32 impcalArbState: 3; // 12
		uint32 unknown4: 17;
	};
	uint32 val;
};

// DCIO_TEST_DEBUG_DATA
union DcioTestDebugData {
	struct {
		uint32 dcioTestDebugData: 32; // 0
	};
	uint32 val;
};

// DCIO_TEST_DEBUG_INDEX
union DcioTestDebugIndex {
	struct {
		uint32 dcioTestDebugIndex: 8; // 0
		uint32 dcioTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// DCI_CLK_CNTL
union DciClkCntl {
	struct {
		uint32 dciTestClkSel: 5; // 0
		uint32 dispclkRDciGateDis: 1; // 5
		uint32 dispclkMGateDis: 1; // 6
		uint32 unknown1: 1;
		uint32 sclkRAzGateDis: 1; // 8
		uint32 dispclkGFbcGateDis: 1; // 9
		uint32 dispclkRVgaGateDis: 1; // 10
		uint32 dispclkGVgaGateDis: 1; // 11
		uint32 dispclkRVipGateDis: 1; // 12
		uint32 dispclkGVipGateDis: 1; // 13
		uint32 dispclkRDmcuGateDis: 1; // 14
		uint32 dispclkGDmcuGateDis: 1; // 15
		uint32 dispclkGDmif0GateDis: 1; // 16
		uint32 dispclkGDmif1GateDis: 1; // 17
		uint32 dispclkGDmif2GateDis: 1; // 18
		uint32 dispclkGDmif3GateDis: 1; // 19
		uint32 dispclkGDmif4GateDis: 1; // 20
		uint32 dispclkGDmif5GateDis: 1; // 21
		uint32 sclkGDmifGateDis: 1; // 22
		uint32 sclkGDmiftrkGateDis: 1; // 23
		uint32 unknown2: 3;
		uint32 dciPgTestClkSel: 5; // 27
	};
	uint32 val;
};

// DCI_DEBUG_CONFIG
union DciDebugConfig {
	struct {
		uint32 dciDbgSel: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// DCI_MEM_PWR_CNTL
union DciMemPwrCntl {
	struct {
		uint32 dmif0AsyncLightSleepDis: 1; // 0
		uint32 dmif1AsyncLightSleepDis: 1; // 1
		uint32 dmif2AsyncLightSleepDis: 1; // 2
		uint32 dmif3AsyncLightSleepDis: 1; // 3
		uint32 dmif4AsyncLightSleepDis: 1; // 4
		uint32 dmif5AsyncLightSleepDis: 1; // 5
		uint32 dmif0AsyncMemShutdownDis: 1; // 6
		uint32 dmif1AsyncMemShutdownDis: 1; // 7
		uint32 dmif2AsyncMemShutdownDis: 1; // 8
		uint32 dmif3AsyncMemShutdownDis: 1; // 9
		uint32 dmif4AsyncMemShutdownDis: 1; // 10
		uint32 dmif5AsyncMemShutdownDis: 1; // 11
		uint32 dmif0AsyncMemPwrState: 2; // 12
		uint32 dmif1AsyncMemPwrState: 2; // 14
		uint32 dmif2AsyncMemPwrState: 2; // 16
		uint32 dmif3AsyncMemPwrState: 2; // 18
		uint32 dmif4AsyncMemPwrState: 2; // 20
		uint32 dmif5AsyncMemPwrState: 2; // 22
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DCI_MEM_PWR_STATE
union DciMemPwrState {
	struct {
		uint32 dmcuMemPwrState: 2; // 0
		uint32 dmif0MemPwrState: 2; // 2
		uint32 dmif1MemPwrState: 2; // 4
		uint32 dmif2MemPwrState: 2; // 6
		uint32 dmif3MemPwrState: 2; // 8
		uint32 dmif4MemPwrState: 2; // 10
		uint32 dmif5MemPwrState: 2; // 12
		uint32 vgaMemPwrState: 2; // 14
		uint32 fbcMemPwrState: 2; // 16
		uint32 mcifMemPwrState: 2; // 18
		uint32 vipMemPwrState: 2; // 20
		uint32 azMemPwrState: 2; // 22
		uint32 dmifXlrMemPwrState: 2; // 24
		uint32 dmifXlrMem1PwrState: 2; // 26
		uint32 dmcuIramPwrState: 2; // 28
		uint32 unknown1: 2;
	};
	uint32 val;
};

// DCI_MEM_PWR_STATE2
union DciMemPwrState2 {
	struct {
		uint32 dmcuEram1PwrState: 2; // 0
		uint32 dmcuEram2PwrState: 2; // 2
		uint32 dmcuEram3PwrState: 2; // 4
		uint32 unknown1: 26;
	};
	uint32 val;
};

// DCI_SOFT_RESET
union DciSoftReset {
	struct {
		uint32 vgaSoftReset: 1; // 0
		uint32 vipSoftReset: 1; // 1
		uint32 mcifSoftReset: 1; // 2
		uint32 fbcSoftReset: 1; // 3
		uint32 dmif0SoftReset: 1; // 4
		uint32 dmif1SoftReset: 1; // 5
		uint32 dmif2SoftReset: 1; // 6
		uint32 dmif3SoftReset: 1; // 7
		uint32 dmif4SoftReset: 1; // 8
		uint32 dmif5SoftReset: 1; // 9
		uint32 unknown1: 2;
		uint32 dmifarbSoftReset: 1; // 12
		uint32 unknown2: 19;
	};
	uint32 val;
};

// DCI_TEST_DEBUG_DATA
union DciTestDebugData {
	struct {
		uint32 dciTestDebugData: 32; // 0
	};
	uint32 val;
};

// DCI_TEST_DEBUG_INDEX
union DciTestDebugIndex {
	struct {
		uint32 dciTestDebugIndex: 8; // 0
		uint32 dciTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// DCO_CLK_CNTL
union DcoClkCntl {
	struct {
		uint32 dcoTestClkSel: 5; // 0
		uint32 dispclkRDcoGateDis: 1; // 5
		uint32 dispclkGAbmGateDis: 1; // 6
		uint32 dispclkGDvoGateDis: 1; // 7
		uint32 dispclkGDacaGateDis: 1; // 8
		uint32 dispclkGDacbGateDis: 1; // 9
		uint32 unknown1: 2;
		uint32 dispclkRAbmGateDis: 1; // 12
		uint32 unknown2: 3;
		uint32 dispclkGFmt0GateDis: 1; // 16
		uint32 dispclkGFmt1GateDis: 1; // 17
		uint32 dispclkGFmt2GateDis: 1; // 18
		uint32 dispclkGFmt3GateDis: 1; // 19
		uint32 dispclkGFmt4GateDis: 1; // 20
		uint32 dispclkGFmt5GateDis: 1; // 21
		uint32 unknown3: 2;
		uint32 dispclkGDigaGateDis: 1; // 24
		uint32 dispclkGDigbGateDis: 1; // 25
		uint32 dispclkGDigcGateDis: 1; // 26
		uint32 dispclkGDigdGateDis: 1; // 27
		uint32 dispclkGDigeGateDis: 1; // 28
		uint32 dispclkGDigfGateDis: 1; // 29
		uint32 unknown4: 2;
	};
	uint32 val;
};

// DCO_CLK_RAMP_CNTL
union DcoClkRampCntl {
	struct {
		uint32 unknown1: 5;
		uint32 dispclkRDcoRampDis: 1; // 5
		uint32 dispclkGAbmRampDis: 1; // 6
		uint32 dispclkGDvoRampDis: 1; // 7
		uint32 dispclkGDacaRampDis: 1; // 8
		uint32 dispclkGDacbRampDis: 1; // 9
		uint32 unknown2: 2;
		uint32 dispclkRAbmRampDis: 1; // 12
		uint32 unknown3: 3;
		uint32 dispclkGFmt0RampDis: 1; // 16
		uint32 dispclkGFmt1RampDis: 1; // 17
		uint32 dispclkGFmt2RampDis: 1; // 18
		uint32 dispclkGFmt3RampDis: 1; // 19
		uint32 dispclkGFmt4RampDis: 1; // 20
		uint32 dispclkGFmt5RampDis: 1; // 21
		uint32 unknown4: 2;
		uint32 dispclkGDigaRampDis: 1; // 24
		uint32 dispclkGDigbRampDis: 1; // 25
		uint32 dispclkGDigcRampDis: 1; // 26
		uint32 dispclkGDigdRampDis: 1; // 27
		uint32 dispclkGDigeRampDis: 1; // 28
		uint32 dispclkGDigfRampDis: 1; // 29
		uint32 unknown5: 2;
	};
	uint32 val;
};

// DCO_LIGHT_SLEEP_DIS
union DcoLightSleepDis {
	struct {
		uint32 tvoutLightSleepDis: 1; // 0
		uint32 i2cLightSleepForce: 1; // 1
		uint32 mvpLightSleepDis: 1; // 2
		uint32 dpaLightSleepDis: 1; // 3
		uint32 dpbLightSleepDis: 1; // 4
		uint32 dpcLightSleepDis: 1; // 5
		uint32 dpdLightSleepDis: 1; // 6
		uint32 dpeLightSleepDis: 1; // 7
		uint32 dpfLightSleepDis: 1; // 8
		uint32 hdmi0LightSleepDis: 1; // 9
		uint32 hdmi1LightSleepDis: 1; // 10
		uint32 hdmi2LightSleepDis: 1; // 11
		uint32 hdmi3LightSleepDis: 1; // 12
		uint32 hdmi4LightSleepDis: 1; // 13
		uint32 hdmi5LightSleepDis: 1; // 14
		uint32 unknown1: 1;
		uint32 mvpMemShutdownDis: 1; // 16
		uint32 dpaMemShutdownDis: 1; // 17
		uint32 dpbMemShutdownDis: 1; // 18
		uint32 dpcMemShutdownDis: 1; // 19
		uint32 dpdMemShutdownDis: 1; // 20
		uint32 dpeMemShutdownDis: 1; // 21
		uint32 dpfMemShutdownDis: 1; // 22
		uint32 unknown2: 9;
	};
	uint32 val;
};

// DCO_MEM_POWER_STATE
union DcoMemPowerState {
	struct {
		uint32 tvoutMemPwrState: 2; // 0
		uint32 i2cMemPwrState: 2; // 2
		uint32 mvpMemPwrState: 2; // 4
		uint32 dpaMemPwrState: 2; // 6
		uint32 dpbMemPwrState: 2; // 8
		uint32 dpcMemPwrState: 2; // 10
		uint32 dpdMemPwrState: 2; // 12
		uint32 dpeMemPwrState: 2; // 14
		uint32 dpfMemPwrState: 2; // 16
		uint32 hdmi0MemPwrState: 2; // 18
		uint32 hdmi1MemPwrState: 2; // 20
		uint32 hdmi2MemPwrState: 2; // 22
		uint32 hdmi3MemPwrState: 2; // 24
		uint32 hdmi4MemPwrState: 2; // 26
		uint32 hdmi5MemPwrState: 2; // 28
		uint32 unknown1: 2;
	};
	uint32 val;
};

// DCO_SOFT_RESET
union DcoSoftReset {
	struct {
		uint32 dacaSoftReset: 1; // 0
		uint32 dacbSoftReset: 1; // 1
		uint32 softResetDvo: 1; // 2
		uint32 dvoEnableRst: 1; // 3
		uint32 unknown1: 12;
		uint32 fmt0SoftReset: 1; // 16
		uint32 fmt1SoftReset: 1; // 17
		uint32 fmt2SoftReset: 1; // 18
		uint32 fmt3SoftReset: 1; // 19
		uint32 fmt4SoftReset: 1; // 20
		uint32 fmt5SoftReset: 1; // 21
		uint32 unknown2: 2;
		uint32 mvpSoftReset: 1; // 24
		uint32 abmSoftReset: 1; // 25
		uint32 tvoutSoftReset: 1; // 26
		uint32 dvoSoftReset: 1; // 27
		uint32 srbmSoftResetEnable: 1; // 28
		uint32 dacaCfgIfSoftReset: 1; // 29
		uint32 unknown3: 2;
	};
	uint32 val;
};

// DCPG_TEST_DEBUG_DATA
union DcpgTestDebugData {
	struct {
		uint32 dcpgTestDebugData: 32; // 0
	};
	uint32 val;
};

// DCPG_TEST_DEBUG_INDEX
union DcpgTestDebugIndex {
	struct {
		uint32 dcpgTestDebugIndex: 8; // 0
		uint32 dcpgTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// DCP_CRC_CONTROL
union DcpCrcControl {
	struct {
		uint32 dcpCrcEnable: 1; // 0
		uint32 unknown1: 1;
		uint32 dcpCrcSourceSel: 3; // 2
		uint32 unknown2: 3;
		uint32 dcpCrcLineSel: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// DCP_CRC_CURRENT
union DcpCrcCurrent {
	struct {
		uint32 dcpCrcCurrent: 32; // 0
	};
	uint32 val;
};

// DCP_CRC_LAST
union DcpCrcLast {
	struct {
		uint32 dcpCrcLast: 32; // 0
	};
	uint32 val;
};

// DCP_CRC_MASK
union DcpCrcMask {
	struct {
		uint32 dcpCrcMask: 32; // 0
	};
	uint32 val;
};

// DCP_DEBUG
union DcpDebug {
	struct {
		uint32 dcpDebug: 32; // 0
	};
	uint32 val;
};

// DCP_DEBUG2
union DcpDebug2 {
	struct {
		uint32 dcpDebug2: 32; // 0
	};
	uint32 val;
};

// DCP_FP_CONVERTED_FIELD
union DcpFpConvertedField {
	struct {
		uint32 dcpFpConvertedFieldData: 18; // 0
		uint32 unknown1: 2;
		uint32 dcpFpConvertedFieldIndex: 7; // 20
		uint32 unknown2: 5;
	};
	uint32 val;
};

// DCP_GSL_CONTROL
union DcpGslControl {
	struct {
		uint32 dcpGsl0En: 1; // 0
		uint32 dcpGsl1En: 1; // 1
		uint32 dcpGsl2En: 1; // 2
		uint32 unknown1: 5;
		uint32 dcpGslMode: 2; // 8
		uint32 unknown2: 2;
		uint32 dcpGslHsyncFlipForceDelay: 4; // 12
		uint32 dcpGslMasterEn: 1; // 16
		uint32 unknown3: 7;
		uint32 dcpGslSyncSource: 2; // 24
		uint32 unknown4: 1;
		uint32 dcpGslDelaySurfaceUpdatePending: 1; // 27
		uint32 dcpGslHsyncFlipCheckDelay: 4; // 28
	};
	uint32 val;
};

// DCP_LB_DATA_GAP_BETWEEN_CHUNK
union DcpLbDataGapBetweenChunk {
	struct {
		uint32 dcpLbGapBetweenChunk20bpp: 4; // 0
		uint32 dcpLbGapBetweenChunk30bpp: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// DCP_RANDOM_SEEDS
union DcpRandomSeeds {
	struct {
		uint32 dcpRandRSeed: 8; // 0
		uint32 dcpRandGSeed: 8; // 8
		uint32 dcpRandBSeed: 8; // 16
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DCP_SPATIAL_DITHER_CNTL
union DcpSpatialDitherCntl {
	struct {
		uint32 dcpSpatialDitherEn: 1; // 0
		uint32 unknown1: 3;
		uint32 dcpSpatialDitherMode: 2; // 4
		uint32 dcpSpatialDitherDepth: 1; // 6
		uint32 unknown2: 1;
		uint32 dcpFrameRandomEnable: 1; // 8
		uint32 dcpRgbRandomEnable: 1; // 9
		uint32 dcpHighpassRandomEnable: 1; // 10
		uint32 unknown3: 21;
	};
	uint32 val;
};

// DCP_TEST_DEBUG_DATA
union DcpTestDebugData {
	struct {
		uint32 dcpTestDebugData: 32; // 0
	};
	uint32 val;
};

// DCP_TEST_DEBUG_INDEX
union DcpTestDebugIndex {
	struct {
		uint32 dcpTestDebugIndex: 8; // 0
		uint32 dcpTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// DC_ABM1_ACE_CNTL_MISC
union DcAbm1AceCntlMisc {
	struct {
		uint32 abm1AceRegWrMissedFrame: 1; // 0
		uint32 unknown1: 7;
		uint32 abm1AceRegWrMissedFrameClear: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_ABM1_ACE_OFFSET_SLOPE_0
union DcAbm1AceOffsetSlope0 {
	struct {
		uint32 abm1AceSlope0: 15; // 0
		uint32 unknown1: 1;
		uint32 abm1AceOffset0: 11; // 16
		uint32 unknown2: 4;
		uint32 abm1AceLock: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_ACE_OFFSET_SLOPE_1
union DcAbm1AceOffsetSlope1 {
	struct {
		uint32 abm1AceSlope1: 15; // 0
		uint32 unknown1: 1;
		uint32 abm1AceOffset1: 11; // 16
		uint32 unknown2: 4;
		uint32 abm1AceLock: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_ACE_OFFSET_SLOPE_2
union DcAbm1AceOffsetSlope2 {
	struct {
		uint32 abm1AceSlope2: 15; // 0
		uint32 unknown1: 1;
		uint32 abm1AceOffset2: 11; // 16
		uint32 unknown2: 4;
		uint32 abm1AceLock: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_ACE_OFFSET_SLOPE_3
union DcAbm1AceOffsetSlope3 {
	struct {
		uint32 abm1AceSlope3: 15; // 0
		uint32 unknown1: 1;
		uint32 abm1AceOffset3: 11; // 16
		uint32 unknown2: 4;
		uint32 abm1AceLock: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_ACE_OFFSET_SLOPE_4
union DcAbm1AceOffsetSlope4 {
	struct {
		uint32 abm1AceSlope4: 15; // 0
		uint32 unknown1: 1;
		uint32 abm1AceOffset4: 11; // 16
		uint32 unknown2: 4;
		uint32 abm1AceLock: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_ACE_THRES_12
union DcAbm1AceThres12 {
	struct {
		uint32 abm1AceThres1: 10; // 0
		uint32 unknown1: 6;
		uint32 abm1AceThres2: 10; // 16
		uint32 unknown2: 5;
		uint32 abm1AceLock: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_ACE_THRES_34
union DcAbm1AceThres34 {
	struct {
		uint32 abm1AceThres3: 10; // 0
		uint32 unknown1: 6;
		uint32 abm1AceThres4: 10; // 16
		uint32 unknown2: 2;
		uint32 abm1AceIgnoreMasterLockEn: 1; // 28
		uint32 abm1AceReadbackDbRegValueEn: 1; // 29
		uint32 abm1AceDbufRegUpdatePending: 1; // 30
		uint32 abm1AceLock: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_BL_MASTER_LOCK
union DcAbm1BlMasterLock {
	struct {
		uint32 unknown1: 31;
		uint32 abm1BlMasterLock: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_CNTL
union DcAbm1Cntl {
	struct {
		uint32 abm1En: 1; // 0
		uint32 unknown1: 7;
		uint32 abm1SourceSelect: 3; // 8
		uint32 unknown2: 20;
		uint32 abm1BlankModeSupportEnable: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_DEBUG_MISC
union DcAbm1DebugMisc {
	struct {
		uint32 abm1HgForceInterrupt: 1; // 0
		uint32 unknown1: 7;
		uint32 abm1LsForceInterrupt: 1; // 8
		uint32 unknown2: 7;
		uint32 abm1BlForceInterrupt: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// DC_ABM1_HGLS_REG_READ_PROGRESS
union DcAbm1HglsRegReadProgress {
	struct {
		uint32 abm1HgRegReadInProgress: 1; // 0
		uint32 abm1LsRegReadInProgress: 1; // 1
		uint32 abm1BlRegReadInProgress: 1; // 2
		uint32 unknown1: 5;
		uint32 abm1HgRegReadMissedFrame: 1; // 8
		uint32 abm1LsRegReadMissedFrame: 1; // 9
		uint32 abm1BlRegReadMissedFrame: 1; // 10
		uint32 unknown2: 5;
		uint32 abm1HgRegReadMissedFrameClear: 1; // 16
		uint32 unknown3: 7;
		uint32 abm1LsRegReadMissedFrameClear: 1; // 24
		uint32 unknown4: 6;
		uint32 abm1BlRegReadMissedFrameClear: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_HG_BIN_17_24_SHIFT_INDEX
union DcAbm1HgBin17_24ShiftIndex {
	struct {
		uint32 abm1HgBin17_24ShiftIndex: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_BIN_1_32_SHIFT_FLAG
union DcAbm1HgBin1_32ShiftFlag {
	struct {
		uint32 abm1HgBin1_32ShiftFlag: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_BIN_1_8_SHIFT_INDEX
union DcAbm1HgBin1_8ShiftIndex {
	struct {
		uint32 abm1HgBin1_8ShiftIndex: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_BIN_25_32_SHIFT_INDEX
union DcAbm1HgBin25_32ShiftIndex {
	struct {
		uint32 abm1HgBin25_32ShiftIndex: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_BIN_9_16_SHIFT_INDEX
union DcAbm1HgBin9_16ShiftIndex {
	struct {
		uint32 abm1HgBin9_16ShiftIndex: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_MISC_CTRL
union DcAbm1HgMiscCtrl {
	struct {
		uint32 abm1HgNumOfBinsSel: 2; // 0
		uint32 unknown1: 6;
		uint32 abm1HgVmaxSel: 1; // 8
		uint32 unknown2: 3;
		uint32 abm1HgFineModeBinSel: 1; // 12
		uint32 unknown3: 3;
		uint32 abm1HgBinBitwidthSizeSel: 2; // 16
		uint32 unknown4: 2;
		uint32 abm1OvrScanPixelProcessEn: 1; // 20
		uint32 unknown5: 2;
		uint32 abm1DbufHglsReadbackDbRegValueEn: 1; // 23
		uint32 abm1DbufHglsRegFrameStartDispSel: 3; // 24
		uint32 unknown6: 1;
		uint32 abm1DbufHglsRegUpdateAtFrameStart: 1; // 28
		uint32 abm1HglsIgnoreMasterLockEn: 1; // 29
		uint32 abm1DbufHglsRegUpdatePending: 1; // 30
		uint32 abm1HglsRegLock: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_1
union DcAbm1HgResult1 {
	struct {
		uint32 abm1HgResult1: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_10
union DcAbm1HgResult10 {
	struct {
		uint32 abm1HgResult10: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_11
union DcAbm1HgResult11 {
	struct {
		uint32 abm1HgResult11: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_12
union DcAbm1HgResult12 {
	struct {
		uint32 abm1HgResult12: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_13
union DcAbm1HgResult13 {
	struct {
		uint32 abm1HgResult13: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_14
union DcAbm1HgResult14 {
	struct {
		uint32 abm1HgResult14: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_15
union DcAbm1HgResult15 {
	struct {
		uint32 abm1HgResult15: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_16
union DcAbm1HgResult16 {
	struct {
		uint32 abm1HgResult16: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_17
union DcAbm1HgResult17 {
	struct {
		uint32 abm1HgResult17: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_18
union DcAbm1HgResult18 {
	struct {
		uint32 abm1HgResult18: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_19
union DcAbm1HgResult19 {
	struct {
		uint32 abm1HgResult19: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_2
union DcAbm1HgResult2 {
	struct {
		uint32 abm1HgResult2: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_20
union DcAbm1HgResult20 {
	struct {
		uint32 abm1HgResult20: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_21
union DcAbm1HgResult21 {
	struct {
		uint32 abm1HgResult21: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_22
union DcAbm1HgResult22 {
	struct {
		uint32 abm1HgResult22: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_23
union DcAbm1HgResult23 {
	struct {
		uint32 abm1HgResult23: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_24
union DcAbm1HgResult24 {
	struct {
		uint32 abm1HgResult24: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_3
union DcAbm1HgResult3 {
	struct {
		uint32 abm1HgResult3: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_4
union DcAbm1HgResult4 {
	struct {
		uint32 abm1HgResult4: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_5
union DcAbm1HgResult5 {
	struct {
		uint32 abm1HgResult5: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_6
union DcAbm1HgResult6 {
	struct {
		uint32 abm1HgResult6: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_7
union DcAbm1HgResult7 {
	struct {
		uint32 abm1HgResult7: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_8
union DcAbm1HgResult8 {
	struct {
		uint32 abm1HgResult8: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_RESULT_9
union DcAbm1HgResult9 {
	struct {
		uint32 abm1HgResult9: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_HG_SAMPLE_RATE
union DcAbm1HgSampleRate {
	struct {
		uint32 abm1HgSampleRateCountEn: 1; // 0
		uint32 abm1HgResetSampleRateFrameCounter: 1; // 1
		uint32 unknown1: 6;
		uint32 abm1HgSampleRateFrameCount: 8; // 8
		uint32 abm1HgInitialSampleRateCountValueWhenReset: 8; // 16
		uint32 unknown2: 7;
		uint32 abm1HglsRegLock: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_IPCSC_COEFF_SEL
union DcAbm1IpcscCoeffSel {
	struct {
		uint32 abm1IpcscCoeffSelB: 4; // 0
		uint32 unknown1: 4;
		uint32 abm1IpcscCoeffSelG: 4; // 8
		uint32 unknown2: 4;
		uint32 abm1IpcscCoeffSelR: 4; // 16
		uint32 unknown3: 11;
		uint32 abm1HglsRegLock: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_LS_FILTERED_MIN_MAX_LUMA
union DcAbm1LsFilteredMinMaxLuma {
	struct {
		uint32 abm1LsFilteredMinLuma: 10; // 0
		uint32 unknown1: 6;
		uint32 abm1LsFilteredMaxLuma: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// DC_ABM1_LS_MAX_PIXEL_VALUE_COUNT
union DcAbm1LsMaxPixelValueCount {
	struct {
		uint32 abm1LsMaxPixelValueCount: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DC_ABM1_LS_MIN_MAX_LUMA
union DcAbm1LsMinMaxLuma {
	struct {
		uint32 abm1LsMinLuma: 10; // 0
		uint32 unknown1: 6;
		uint32 abm1LsMaxLuma: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// DC_ABM1_LS_MIN_MAX_PIXEL_VALUE_THRES
union DcAbm1LsMinMaxPixelValueThres {
	struct {
		uint32 abm1LsMinPixelValueThres: 10; // 0
		uint32 unknown1: 6;
		uint32 abm1LsMaxPixelValueThres: 10; // 16
		uint32 unknown2: 5;
		uint32 abm1HglsRegLock: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_LS_MIN_PIXEL_VALUE_COUNT
union DcAbm1LsMinPixelValueCount {
	struct {
		uint32 abm1LsMinPixelValueCount: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DC_ABM1_LS_OVR_SCAN_BIN
union DcAbm1LsOvrScanBin {
	struct {
		uint32 abm1LsOvrScanBin: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DC_ABM1_LS_PIXEL_COUNT
union DcAbm1LsPixelCount {
	struct {
		uint32 abm1LsPixelCount: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DC_ABM1_LS_SAMPLE_RATE
union DcAbm1LsSampleRate {
	struct {
		uint32 abm1LsSampleRateCountEn: 1; // 0
		uint32 abm1LsResetSampleRateFrameCounter: 1; // 1
		uint32 unknown1: 6;
		uint32 abm1LsSampleRateFrameCount: 8; // 8
		uint32 abm1LsInitialSampleRateCountValueWhenReset: 8; // 16
		uint32 unknown2: 7;
		uint32 abm1HglsRegLock: 1; // 31
	};
	uint32 val;
};

// DC_ABM1_LS_SUM_OF_LUMA
union DcAbm1LsSumOfLuma {
	struct {
		uint32 abm1LsSumOfLuma: 32; // 0
	};
	uint32 val;
};

// DC_ABM1_OVERSCAN_PIXEL_VALUE
union DcAbm1OverscanPixelValue {
	struct {
		uint32 abm1OverscanRPixelValue: 10; // 0
		uint32 abm1OverscanGPixelValue: 10; // 10
		uint32 abm1OverscanBPixelValue: 10; // 20
		uint32 unknown1: 2;
	};
	uint32 val;
};

// DC_DMCU_SCRATCH
union DcDmcuScratch {
	struct {
		uint32 dmcuScratch: 32; // 0
	};
	uint32 val;
};

// DC_DVODATA_CONFIG
union DcDvodataConfig {
	struct {
		uint32 unknown1: 19;
		uint32 vipMuxEn: 1; // 19
		uint32 vipAlterMappingEn: 1; // 20
		uint32 dvoAlterMappingEn: 1; // 21
		uint32 unknown2: 10;
	};
	uint32 val;
};

// DC_GENERICA
union DcGenerica {
	struct {
		uint32 genericaEn: 1; // 0
		uint32 unknown1: 7;
		uint32 genericaSel: 4; // 8
		uint32 genericaUniphyRefdivClkSel: 3; // 12
		uint32 unknown2: 1;
		uint32 genericaUniphyFbdivClkSel: 3; // 16
		uint32 unknown3: 1;
		uint32 genericaUniphyFbdivSscClkSel: 3; // 20
		uint32 unknown4: 1;
		uint32 genericaUniphyFbdivClkDiv2Sel: 3; // 24
		uint32 unknown5: 5;
	};
	uint32 val;
};

// DC_GENERICB
union DcGenericb {
	struct {
		uint32 genericbEn: 1; // 0
		uint32 unknown1: 7;
		uint32 genericbSel: 4; // 8
		uint32 genericbUniphyRefdivClkSel: 3; // 12
		uint32 unknown2: 1;
		uint32 genericbUniphyFbdivClkSel: 3; // 16
		uint32 unknown3: 1;
		uint32 genericbUniphyFbdivSscClkSel: 3; // 20
		uint32 unknown4: 1;
		uint32 genericbUniphyFbdivClkDiv2Sel: 3; // 24
		uint32 unknown5: 5;
	};
	uint32 val;
};

// DC_GPIO_DDC1_A
union DcGpioDdc1A {
	struct {
		uint32 dcGpioDdc1clkA: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc1dataA: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC1_EN
union DcGpioDdc1En {
	struct {
		uint32 dcGpioDdc1clkEn: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc1dataEn: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC1_MASK
union DcGpioDdc1Mask {
	struct {
		uint32 dcGpioDdc1clkMask: 1; // 0
		uint32 unknown1: 3;
		uint32 dcGpioDdc1clkPdEn: 1; // 4
		uint32 unknown2: 1;
		uint32 dcGpioDdc1clkRecv: 1; // 6
		uint32 unknown3: 1;
		uint32 dcGpioDdc1dataMask: 1; // 8
		uint32 unknown4: 3;
		uint32 dcGpioDdc1dataPdEn: 1; // 12
		uint32 unknown5: 1;
		uint32 dcGpioDdc1dataRecv: 1; // 14
		uint32 unknown6: 1;
		uint32 auxPad1Mode: 1; // 16
		uint32 unknown7: 3;
		uint32 aux1Pol: 1; // 20
		uint32 unknown8: 1;
		uint32 allowHwDdc1PdEn: 1; // 22
		uint32 unknown9: 1;
		uint32 dcGpioDdc1clkStr: 4; // 24
		uint32 dcGpioDdc1dataStr: 4; // 28
	};
	uint32 val;
};

// DC_GPIO_DDC1_Y
union DcGpioDdc1Y {
	struct {
		uint32 dcGpioDdc1clkY: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc1dataY: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC2_A
union DcGpioDdc2A {
	struct {
		uint32 dcGpioDdc2clkA: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc2dataA: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC2_EN
union DcGpioDdc2En {
	struct {
		uint32 dcGpioDdc2clkEn: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc2dataEn: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC2_MASK
union DcGpioDdc2Mask {
	struct {
		uint32 dcGpioDdc2clkMask: 1; // 0
		uint32 unknown1: 3;
		uint32 dcGpioDdc2clkPdEn: 1; // 4
		uint32 unknown2: 1;
		uint32 dcGpioDdc2clkRecv: 1; // 6
		uint32 unknown3: 1;
		uint32 dcGpioDdc2dataMask: 1; // 8
		uint32 unknown4: 3;
		uint32 dcGpioDdc2dataPdEn: 1; // 12
		uint32 unknown5: 1;
		uint32 dcGpioDdc2dataRecv: 1; // 14
		uint32 unknown6: 1;
		uint32 auxPad2Mode: 1; // 16
		uint32 unknown7: 3;
		uint32 aux2Pol: 1; // 20
		uint32 unknown8: 1;
		uint32 allowHwDdc2PdEn: 1; // 22
		uint32 unknown9: 1;
		uint32 dcGpioDdc2clkStr: 4; // 24
		uint32 dcGpioDdc2dataStr: 4; // 28
	};
	uint32 val;
};

// DC_GPIO_DDC2_Y
union DcGpioDdc2Y {
	struct {
		uint32 dcGpioDdc2clkY: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc2dataY: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC3_A
union DcGpioDdc3A {
	struct {
		uint32 dcGpioDdc3clkA: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc3dataA: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC3_EN
union DcGpioDdc3En {
	struct {
		uint32 dcGpioDdc3clkEn: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc3dataEn: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC3_MASK
union DcGpioDdc3Mask {
	struct {
		uint32 dcGpioDdc3clkMask: 1; // 0
		uint32 unknown1: 3;
		uint32 dcGpioDdc3clkPdEn: 1; // 4
		uint32 unknown2: 1;
		uint32 dcGpioDdc3clkRecv: 1; // 6
		uint32 unknown3: 1;
		uint32 dcGpioDdc3dataMask: 1; // 8
		uint32 unknown4: 3;
		uint32 dcGpioDdc3dataPdEn: 1; // 12
		uint32 unknown5: 1;
		uint32 dcGpioDdc3dataRecv: 1; // 14
		uint32 unknown6: 1;
		uint32 auxPad3Mode: 1; // 16
		uint32 unknown7: 3;
		uint32 aux3Pol: 1; // 20
		uint32 unknown8: 1;
		uint32 allowHwDdc3PdEn: 1; // 22
		uint32 unknown9: 1;
		uint32 dcGpioDdc3clkStr: 4; // 24
		uint32 dcGpioDdc3dataStr: 4; // 28
	};
	uint32 val;
};

// DC_GPIO_DDC3_Y
union DcGpioDdc3Y {
	struct {
		uint32 dcGpioDdc3clkY: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc3dataY: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC4_A
union DcGpioDdc4A {
	struct {
		uint32 dcGpioDdc4clkA: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc4dataA: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC4_EN
union DcGpioDdc4En {
	struct {
		uint32 dcGpioDdc4clkEn: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc4dataEn: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC4_MASK
union DcGpioDdc4Mask {
	struct {
		uint32 dcGpioDdc4clkMask: 1; // 0
		uint32 unknown1: 3;
		uint32 dcGpioDdc4clkPdEn: 1; // 4
		uint32 unknown2: 1;
		uint32 dcGpioDdc4clkRecv: 1; // 6
		uint32 unknown3: 1;
		uint32 dcGpioDdc4dataMask: 1; // 8
		uint32 unknown4: 3;
		uint32 dcGpioDdc4dataPdEn: 1; // 12
		uint32 unknown5: 1;
		uint32 dcGpioDdc4dataRecv: 1; // 14
		uint32 unknown6: 1;
		uint32 auxPad4Mode: 1; // 16
		uint32 unknown7: 3;
		uint32 aux4Pol: 1; // 20
		uint32 unknown8: 1;
		uint32 allowHwDdc4PdEn: 1; // 22
		uint32 unknown9: 1;
		uint32 dcGpioDdc4clkStr: 4; // 24
		uint32 dcGpioDdc4dataStr: 4; // 28
	};
	uint32 val;
};

// DC_GPIO_DDC4_Y
union DcGpioDdc4Y {
	struct {
		uint32 dcGpioDdc4clkY: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc4dataY: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC5_A
union DcGpioDdc5A {
	struct {
		uint32 dcGpioDdc5clkA: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc5dataA: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC5_EN
union DcGpioDdc5En {
	struct {
		uint32 dcGpioDdc5clkEn: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc5dataEn: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC5_MASK
union DcGpioDdc5Mask {
	struct {
		uint32 dcGpioDdc5clkMask: 1; // 0
		uint32 unknown1: 3;
		uint32 dcGpioDdc5clkPdEn: 1; // 4
		uint32 unknown2: 1;
		uint32 dcGpioDdc5clkRecv: 1; // 6
		uint32 unknown3: 1;
		uint32 dcGpioDdc5dataMask: 1; // 8
		uint32 unknown4: 3;
		uint32 dcGpioDdc5dataPdEn: 1; // 12
		uint32 unknown5: 1;
		uint32 dcGpioDdc5dataRecv: 1; // 14
		uint32 unknown6: 1;
		uint32 auxPad5Mode: 1; // 16
		uint32 unknown7: 3;
		uint32 aux5Pol: 1; // 20
		uint32 unknown8: 1;
		uint32 allowHwDdc5PdEn: 1; // 22
		uint32 unknown9: 1;
		uint32 dcGpioDdc5clkStr: 4; // 24
		uint32 dcGpioDdc5dataStr: 4; // 28
	};
	uint32 val;
};

// DC_GPIO_DDC5_Y
union DcGpioDdc5Y {
	struct {
		uint32 dcGpioDdc5clkY: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc5dataY: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC6_A
union DcGpioDdc6A {
	struct {
		uint32 dcGpioDdc6clkA: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc6dataA: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC6_EN
union DcGpioDdc6En {
	struct {
		uint32 dcGpioDdc6clkEn: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc6dataEn: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDC6_MASK
union DcGpioDdc6Mask {
	struct {
		uint32 dcGpioDdc6clkMask: 1; // 0
		uint32 unknown1: 3;
		uint32 dcGpioDdc6clkPdEn: 1; // 4
		uint32 unknown2: 1;
		uint32 dcGpioDdc6clkRecv: 1; // 6
		uint32 unknown3: 1;
		uint32 dcGpioDdc6dataMask: 1; // 8
		uint32 unknown4: 3;
		uint32 dcGpioDdc6dataPdEn: 1; // 12
		uint32 unknown5: 1;
		uint32 dcGpioDdc6dataRecv: 1; // 14
		uint32 unknown6: 1;
		uint32 auxPad6Mode: 1; // 16
		uint32 unknown7: 3;
		uint32 aux6Pol: 1; // 20
		uint32 unknown8: 1;
		uint32 allowHwDdc6PdEn: 1; // 22
		uint32 unknown9: 1;
		uint32 dcGpioDdc6clkStr: 4; // 24
		uint32 dcGpioDdc6dataStr: 4; // 28
	};
	uint32 val;
};

// DC_GPIO_DDC6_Y
union DcGpioDdc6Y {
	struct {
		uint32 dcGpioDdc6clkY: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdc6dataY: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDCVGA_A
union DcGpioDdcvgaA {
	struct {
		uint32 dcGpioDdcvgaclkA: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdcvgadataA: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDCVGA_EN
union DcGpioDdcvgaEn {
	struct {
		uint32 dcGpioDdcvgaclkEn: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdcvgadataEn: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DDCVGA_MASK
union DcGpioDdcvgaMask {
	struct {
		uint32 dcGpioDdcvgaclkMask: 1; // 0
		uint32 unknown1: 5;
		uint32 dcGpioDdcvgaclkRecv: 1; // 6
		uint32 unknown2: 1;
		uint32 dcGpioDdcvgadataMask: 1; // 8
		uint32 unknown3: 3;
		uint32 dcGpioDdcvgadataPdEn: 1; // 12
		uint32 unknown4: 1;
		uint32 dcGpioDdcvgadataRecv: 1; // 14
		uint32 unknown5: 1;
		uint32 auxPadvgaMode: 1; // 16
		uint32 unknown6: 3;
		uint32 auxvgaPol: 1; // 20
		uint32 unknown7: 1;
		uint32 allowHwDdcvgaPdEn: 1; // 22
		uint32 unknown8: 1;
		uint32 dcGpioDdcvgaclkStr: 4; // 24
		uint32 dcGpioDdcvgadataStr: 4; // 28
	};
	uint32 val;
};

// DC_GPIO_DDCVGA_Y
union DcGpioDdcvgaY {
	struct {
		uint32 dcGpioDdcvgaclkY: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDdcvgadataY: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_DEBUG
union DcGpioDebug {
	struct {
		uint32 dcGpioVipDebug: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioMacroDebug: 2; // 8
		uint32 unknown2: 6;
		uint32 dcGpioChipDebugOutPinSel: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// DC_GPIO_DVODATA_A
union DcGpioDvodataA {
	struct {
		uint32 dcGpioDvodataA: 24; // 0
		uint32 dcGpioDvocntlA: 3; // 24
		uint32 unknown1: 1;
		uint32 dcGpioDvoclkA: 1; // 28
		uint32 unknown2: 1;
		uint32 dcGpioMvpDvocntlA: 2; // 30
	};
	uint32 val;
};

// DC_GPIO_DVODATA_EN
union DcGpioDvodataEn {
	struct {
		uint32 dcGpioDvodataEn: 24; // 0
		uint32 dcGpioDvocntlEn: 3; // 24
		uint32 unknown1: 1;
		uint32 dcGpioDvoclkEn: 1; // 28
		uint32 unknown2: 1;
		uint32 dcGpioMvpDvocntlEn: 2; // 30
	};
	uint32 val;
};

// DC_GPIO_DVODATA_MASK
union DcGpioDvodataMask {
	struct {
		uint32 dcGpioDvodataMask: 24; // 0
		uint32 dcGpioDvocntlMask: 3; // 24
		uint32 unknown1: 1;
		uint32 dcGpioDvoclkMask: 1; // 28
		uint32 unknown2: 1;
		uint32 dcGpioMvpDvocntlMask: 2; // 30
	};
	uint32 val;
};

// DC_GPIO_DVODATA_Y
union DcGpioDvodataY {
	struct {
		uint32 dcGpioDvodataY: 24; // 0
		uint32 dcGpioDvocntlY: 3; // 24
		uint32 unknown1: 1;
		uint32 dcGpioDvoclkY: 1; // 28
		uint32 unknown2: 1;
		uint32 dcGpioMvpDvocntlY: 2; // 30
	};
	uint32 val;
};

// DC_GPIO_GENERIC_A
union DcGpioGenericA {
	struct {
		uint32 dcGpioGenericaA: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioGenericbA: 1; // 8
		uint32 unknown2: 7;
		uint32 dcGpioGenericcA: 1; // 16
		uint32 unknown3: 3;
		uint32 dcGpioGenericdA: 1; // 20
		uint32 dcGpioGenericeA: 1; // 21
		uint32 dcGpioGenericfA: 1; // 22
		uint32 dcGpioGenericgA: 1; // 23
		uint32 unknown4: 8;
	};
	uint32 val;
};

// DC_GPIO_GENERIC_EN
union DcGpioGenericEn {
	struct {
		uint32 dcGpioGenericaEn: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioGenericbEn: 1; // 8
		uint32 unknown2: 7;
		uint32 dcGpioGenericcEn: 1; // 16
		uint32 unknown3: 3;
		uint32 dcGpioGenericdEn: 1; // 20
		uint32 dcGpioGenericeEn: 1; // 21
		uint32 dcGpioGenericfEn: 1; // 22
		uint32 dcGpioGenericgEn: 1; // 23
		uint32 unknown4: 8;
	};
	uint32 val;
};

// DC_GPIO_GENERIC_MASK
union DcGpioGenericMask {
	struct {
		uint32 dcGpioGenericaMask: 1; // 0
		uint32 dcGpioGenericaPdDis: 1; // 1
		uint32 dcGpioGenericaRecv: 1; // 2
		uint32 unknown1: 1;
		uint32 dcGpioGenericbMask: 1; // 4
		uint32 dcGpioGenericbPdDis: 1; // 5
		uint32 dcGpioGenericbRecv: 1; // 6
		uint32 unknown2: 1;
		uint32 dcGpioGenericcMask: 1; // 8
		uint32 dcGpioGenericcPdDis: 1; // 9
		uint32 dcGpioGenericcRecv: 1; // 10
		uint32 unknown3: 1;
		uint32 dcGpioGenericdMask: 1; // 12
		uint32 dcGpioGenericdPdDis: 1; // 13
		uint32 dcGpioGenericdRecv: 1; // 14
		uint32 unknown4: 1;
		uint32 dcGpioGenericeMask: 1; // 16
		uint32 dcGpioGenericePdDis: 1; // 17
		uint32 dcGpioGenericeRecv: 1; // 18
		uint32 unknown5: 1;
		uint32 dcGpioGenericfMask: 1; // 20
		uint32 dcGpioGenericfPdDis: 1; // 21
		uint32 dcGpioGenericfRecv: 1; // 22
		uint32 unknown6: 1;
		uint32 dcGpioGenericgMask: 1; // 24
		uint32 dcGpioGenericgPdDis: 1; // 25
		uint32 dcGpioGenericgRecv: 1; // 26
		uint32 unknown7: 5;
	};
	uint32 val;
};

// DC_GPIO_GENERIC_Y
union DcGpioGenericY {
	struct {
		uint32 dcGpioGenericaY: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioGenericbY: 1; // 8
		uint32 unknown2: 7;
		uint32 dcGpioGenericcY: 1; // 16
		uint32 unknown3: 3;
		uint32 dcGpioGenericdY: 1; // 20
		uint32 dcGpioGenericeY: 1; // 21
		uint32 dcGpioGenericfY: 1; // 22
		uint32 dcGpioGenericgY: 1; // 23
		uint32 unknown4: 8;
	};
	uint32 val;
};

// DC_GPIO_GENLK_A
union DcGpioGenlkA {
	struct {
		uint32 dcGpioGenlkClkA: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioGenlkVsyncA: 1; // 8
		uint32 unknown2: 7;
		uint32 dcGpioSwaplockAA: 1; // 16
		uint32 unknown3: 7;
		uint32 dcGpioSwaplockBA: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// DC_GPIO_GENLK_EN
union DcGpioGenlkEn {
	struct {
		uint32 dcGpioGenlkClkEn: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioGenlkVsyncEn: 1; // 8
		uint32 unknown2: 7;
		uint32 dcGpioSwaplockAEn: 1; // 16
		uint32 unknown3: 7;
		uint32 dcGpioSwaplockBEn: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// DC_GPIO_GENLK_MASK
union DcGpioGenlkMask {
	struct {
		uint32 dcGpioGenlkClkMask: 1; // 0
		uint32 dcGpioGenlkClkPdDis: 1; // 1
		uint32 dcGpioGenlkClkRecv: 1; // 2
		uint32 dcGpioGenlkClkPuEn: 1; // 3
		uint32 unknown1: 4;
		uint32 dcGpioGenlkVsyncMask: 1; // 8
		uint32 dcGpioGenlkVsyncPdDis: 1; // 9
		uint32 dcGpioGenlkVsyncRecv: 1; // 10
		uint32 dcGpioGenlkVsyncPuEn: 1; // 11
		uint32 unknown2: 4;
		uint32 dcGpioSwaplockAMask: 1; // 16
		uint32 dcGpioSwaplockAPdDis: 1; // 17
		uint32 dcGpioSwaplockARecv: 1; // 18
		uint32 dcGpioSwaplockAPuEn: 1; // 19
		uint32 unknown3: 4;
		uint32 dcGpioSwaplockBMask: 1; // 24
		uint32 dcGpioSwaplockBPdDis: 1; // 25
		uint32 dcGpioSwaplockBRecv: 1; // 26
		uint32 dcGpioSwaplockBPuEn: 1; // 27
		uint32 unknown4: 4;
	};
	uint32 val;
};

// DC_GPIO_GENLK_Y
union DcGpioGenlkY {
	struct {
		uint32 dcGpioGenlkClkY: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioGenlkVsyncY: 1; // 8
		uint32 unknown2: 7;
		uint32 dcGpioSwaplockAY: 1; // 16
		uint32 unknown3: 7;
		uint32 dcGpioSwaplockBY: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// DC_GPIO_HPD_A
union DcGpioHpdA {
	struct {
		uint32 dcGpioHpd1A: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioHpd2A: 1; // 8
		uint32 unknown2: 7;
		uint32 dcGpioHpd3A: 1; // 16
		uint32 unknown3: 7;
		uint32 dcGpioHpd4A: 1; // 24
		uint32 unknown4: 1;
		uint32 dcGpioHpd5A: 1; // 26
		uint32 unknown5: 1;
		uint32 dcGpioHpd6A: 1; // 28
		uint32 unknown6: 3;
	};
	uint32 val;
};

// DC_GPIO_HPD_EN
union DcGpioHpdEn {
	struct {
		uint32 dcGpioHpd1En: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioHpd2En: 1; // 8
		uint32 unknown2: 7;
		uint32 dcGpioHpd3En: 1; // 16
		uint32 unknown3: 7;
		uint32 dcGpioHpd4En: 1; // 24
		uint32 unknown4: 1;
		uint32 dcGpioHpd5En: 1; // 26
		uint32 unknown5: 1;
		uint32 dcGpioHpd6En: 1; // 28
		uint32 unknown6: 3;
	};
	uint32 val;
};

// DC_GPIO_HPD_MASK
union DcGpioHpdMask {
	struct {
		uint32 dcGpioHpd1Mask: 1; // 0
		uint32 unknown1: 3;
		uint32 dcGpioHpd1PdDis: 1; // 4
		uint32 unknown2: 1;
		uint32 dcGpioHpd1Recv: 1; // 6
		uint32 unknown3: 1;
		uint32 dcGpioHpd2Mask: 1; // 8
		uint32 dcGpioHpd2PdDis: 1; // 9
		uint32 dcGpioHpd2Recv: 1; // 10
		uint32 unknown4: 5;
		uint32 dcGpioHpd3Mask: 1; // 16
		uint32 dcGpioHpd3PdDis: 1; // 17
		uint32 dcGpioHpd3Recv: 1; // 18
		uint32 unknown5: 1;
		uint32 dcGpioHpd4Mask: 1; // 20
		uint32 dcGpioHpd4PdDis: 1; // 21
		uint32 dcGpioHpd4Recv: 1; // 22
		uint32 unknown6: 1;
		uint32 dcGpioHpd5Mask: 1; // 24
		uint32 dcGpioHpd5PdDis: 1; // 25
		uint32 dcGpioHpd5Recv: 1; // 26
		uint32 unknown7: 1;
		uint32 dcGpioHpd6Mask: 1; // 28
		uint32 dcGpioHpd6PdDis: 1; // 29
		uint32 dcGpioHpd6Recv: 1; // 30
		uint32 unknown8: 1;
	};
	uint32 val;
};

// DC_GPIO_HPD_Y
union DcGpioHpdY {
	struct {
		uint32 dcGpioHpd1Y: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioHpd2Y: 1; // 8
		uint32 unknown2: 7;
		uint32 dcGpioHpd3Y: 1; // 16
		uint32 unknown3: 7;
		uint32 dcGpioHpd4Y: 1; // 24
		uint32 unknown4: 1;
		uint32 dcGpioHpd5Y: 1; // 26
		uint32 unknown5: 1;
		uint32 dcGpioHpd6Y: 1; // 28
		uint32 unknown6: 3;
	};
	uint32 val;
};

// DC_GPIO_I2CPAD_A
union DcGpioI2cpadA {
	struct {
		uint32 dcGpioSclA: 1; // 0
		uint32 dcGpioSdaA: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// DC_GPIO_I2CPAD_EN
union DcGpioI2cpadEn {
	struct {
		uint32 dcGpioSclEn: 1; // 0
		uint32 dcGpioSdaEn: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// DC_GPIO_I2CPAD_MASK
union DcGpioI2cpadMask {
	struct {
		uint32 dcGpioSclMask: 1; // 0
		uint32 dcGpioSclPdDis: 1; // 1
		uint32 dcGpioSclRecv: 1; // 2
		uint32 unknown1: 1;
		uint32 dcGpioSdaMask: 1; // 4
		uint32 dcGpioSdaPdDis: 1; // 5
		uint32 dcGpioSdaRecv: 1; // 6
		uint32 unknown2: 25;
	};
	uint32 val;
};

// DC_GPIO_I2CPAD_STRENGTH
union DcGpioI2cpadStrength {
	struct {
		uint32 i2cStrengthSn: 4; // 0
		uint32 i2cStrengthSp: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// DC_GPIO_I2CPAD_Y
union DcGpioI2cpadY {
	struct {
		uint32 dcGpioSclY: 1; // 0
		uint32 dcGpioSdaY: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// DC_GPIO_PAD_STRENGTH_1
union DcGpioPadStrength1 {
	struct {
		uint32 genlkStrengthSn: 4; // 0
		uint32 genlkStrengthSp: 4; // 4
		uint32 unknown1: 16;
		uint32 syncStrengthSn: 4; // 24
		uint32 syncStrengthSp: 4; // 28
	};
	uint32 val;
};

// DC_GPIO_PAD_STRENGTH_2
union DcGpioPadStrength2 {
	struct {
		uint32 strengthSn: 4; // 0
		uint32 strengthSp: 4; // 4
		uint32 unknown1: 8;
		uint32 pwrseqStrengthSn: 4; // 16
		uint32 pwrseqStrengthSp: 4; // 20
		uint32 unknown2: 8;
	};
	uint32 val;
};

// DC_GPIO_PWRSEQ_A
union DcGpioPwrseqA {
	struct {
		uint32 dcGpioBlonA: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDigonA: 1; // 8
		uint32 unknown2: 7;
		uint32 dcGpioEnaBlA: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// DC_GPIO_PWRSEQ_EN
union DcGpioPwrseqEn {
	struct {
		uint32 dcGpioBlonEn: 1; // 0
		uint32 dcGpioVaryBlGenericaEn: 1; // 1
		uint32 unknown1: 6;
		uint32 dcGpioDigonEn: 1; // 8
		uint32 unknown2: 7;
		uint32 dcGpioEnaBlEn: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// DC_GPIO_PWRSEQ_MASK
union DcGpioPwrseqMask {
	struct {
		uint32 dcGpioBlonMask: 1; // 0
		uint32 unknown1: 3;
		uint32 dcGpioBlonPdDis: 1; // 4
		uint32 unknown2: 1;
		uint32 dcGpioBlonRecv: 1; // 6
		uint32 unknown3: 1;
		uint32 dcGpioDigonMask: 1; // 8
		uint32 unknown4: 3;
		uint32 dcGpioDigonPdDis: 1; // 12
		uint32 unknown5: 1;
		uint32 dcGpioDigonRecv: 1; // 14
		uint32 unknown6: 1;
		uint32 dcGpioEnaBlMask: 1; // 16
		uint32 unknown7: 3;
		uint32 dcGpioEnaBlPdDis: 1; // 20
		uint32 unknown8: 1;
		uint32 dcGpioEnaBlRecv: 1; // 22
		uint32 unknown9: 9;
	};
	uint32 val;
};

// DC_GPIO_PWRSEQ_Y
union DcGpioPwrseqY {
	struct {
		uint32 dcGpioBlonY: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioDigonY: 1; // 8
		uint32 unknown2: 7;
		uint32 dcGpioEnaBlY: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// DC_GPIO_SYNCA_A
union DcGpioSyncaA {
	struct {
		uint32 dcGpioHsyncaA: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioVsyncaA: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_SYNCA_EN
union DcGpioSyncaEn {
	struct {
		uint32 dcGpioHsyncaEn: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioVsyncaEn: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPIO_SYNCA_MASK
union DcGpioSyncaMask {
	struct {
		uint32 dcGpioHsyncaMask: 1; // 0
		uint32 unknown1: 3;
		uint32 dcGpioHsyncaPdDis: 1; // 4
		uint32 unknown2: 1;
		uint32 dcGpioHsyncaRecv: 1; // 6
		uint32 unknown3: 1;
		uint32 dcGpioVsyncaMask: 1; // 8
		uint32 unknown4: 3;
		uint32 dcGpioVsyncaPdDis: 1; // 12
		uint32 unknown5: 1;
		uint32 dcGpioVsyncaRecv: 1; // 14
		uint32 unknown6: 9;
		uint32 dcGpioHsyncaCrtcHsyncMask: 3; // 24
		uint32 unknown7: 1;
		uint32 dcGpioVsyncaCrtcVsyncMask: 3; // 28
		uint32 unknown8: 1;
	};
	uint32 val;
};

// DC_GPIO_SYNCA_Y
union DcGpioSyncaY {
	struct {
		uint32 dcGpioHsyncaY: 1; // 0
		uint32 unknown1: 7;
		uint32 dcGpioVsyncaY: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DC_GPU_TIMER_READ
union DcGpuTimerRead {
	struct {
		uint32 dcGpuTimerRead: 32; // 0
	};
	uint32 val;
};

// DC_GPU_TIMER_READ_CNTL
union DcGpuTimerReadCntl {
	struct {
		uint32 dcGpuTimerReadSelect: 6; // 0
		uint32 unknown1: 2;
		uint32 dcGpuTimerStartPositionD1VsyncNom: 3; // 8
		uint32 dcGpuTimerStartPositionD2VsyncNom: 3; // 11
		uint32 dcGpuTimerStartPositionD3VsyncNom: 3; // 14
		uint32 dcGpuTimerStartPositionD4VsyncNom: 3; // 17
		uint32 dcGpuTimerStartPositionD5VsyncNom: 3; // 20
		uint32 dcGpuTimerStartPositionD6VsyncNom: 3; // 23
		uint32 unknown2: 6;
	};
	uint32 val;
};

// DC_GPU_TIMER_START_POSITION_P_FLIP
union DcGpuTimerStartPositionPFlip {
	struct {
		uint32 dcGpuTimerStartPositionD1PFlip: 3; // 0
		uint32 unknown1: 1;
		uint32 dcGpuTimerStartPositionD2PFlip: 3; // 4
		uint32 unknown2: 1;
		uint32 dcGpuTimerStartPositionD3PFlip: 3; // 8
		uint32 unknown3: 1;
		uint32 dcGpuTimerStartPositionD4PFlip: 3; // 12
		uint32 unknown4: 1;
		uint32 dcGpuTimerStartPositionD5PFlip: 3; // 16
		uint32 unknown5: 1;
		uint32 dcGpuTimerStartPositionD6PFlip: 3; // 20
		uint32 unknown6: 9;
	};
	uint32 val;
};

// DC_GPU_TIMER_START_POSITION_V_UPDATE
union DcGpuTimerStartPositionVUpdate {
	struct {
		uint32 dcGpuTimerStartPositionD1VUpdate: 3; // 0
		uint32 unknown1: 1;
		uint32 dcGpuTimerStartPositionD2VUpdate: 3; // 4
		uint32 unknown2: 1;
		uint32 dcGpuTimerStartPositionD3VUpdate: 3; // 8
		uint32 unknown3: 1;
		uint32 dcGpuTimerStartPositionD4VUpdate: 3; // 12
		uint32 unknown4: 1;
		uint32 dcGpuTimerStartPositionD5VUpdate: 3; // 16
		uint32 unknown5: 1;
		uint32 dcGpuTimerStartPositionD6VUpdate: 3; // 20
		uint32 unknown6: 9;
	};
	uint32 val;
};

// DC_HPD1_CONTROL
union DcHpd1Control {
	struct {
		uint32 dcHpd1ConnectionTimer: 13; // 0
		uint32 unknown1: 3;
		uint32 dcHpd1RxIntTimer: 10; // 16
		uint32 unknown2: 2;
		uint32 dcHpd1En: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// DC_HPD1_FAST_TRAIN_CNTL
union DcHpd1FastTrainCntl {
	struct {
		uint32 dcHpd1ConnectAuxTxDelay: 8; // 0
		uint32 unknown1: 4;
		uint32 dcHpd1ConnectFastTrainDelay: 8; // 12
		uint32 unknown2: 4;
		uint32 dcHpd1ConnectAuxTxEn: 1; // 24
		uint32 unknown3: 3;
		uint32 dcHpd1ConnectFastTrainEn: 1; // 28
		uint32 unknown4: 3;
	};
	uint32 val;
};

// DC_HPD1_INT_CONTROL
union DcHpd1IntControl {
	struct {
		uint32 dcHpd1IntAck: 1; // 0
		uint32 unknown1: 7;
		uint32 dcHpd1IntPolarity: 1; // 8
		uint32 unknown2: 7;
		uint32 dcHpd1IntEn: 1; // 16
		uint32 unknown3: 3;
		uint32 dcHpd1RxIntAck: 1; // 20
		uint32 unknown4: 3;
		uint32 dcHpd1RxIntEn: 1; // 24
		uint32 unknown5: 7;
	};
	uint32 val;
};

// DC_HPD1_INT_STATUS
union DcHpd1IntStatus {
	struct {
		uint32 dcHpd1IntStatus: 1; // 0
		uint32 dcHpd1Sense: 1; // 1
		uint32 unknown1: 2;
		uint32 dcHpd1SenseDelayed: 1; // 4
		uint32 unknown2: 3;
		uint32 dcHpd1RxIntStatus: 1; // 8
		uint32 unknown3: 3;
		uint32 dcHpd1ToggleFiltConTimerVal: 8; // 12
		uint32 unknown4: 4;
		uint32 dcHpd1ToggleFiltDisconTimerVal: 8; // 24
	};
	uint32 val;
};

// DC_HPD1_TOGGLE_FILT_CNTL
union DcHpd1ToggleFiltCntl {
	struct {
		uint32 dcHpd1ConnectIntDelay: 8; // 0
		uint32 unknown1: 12;
		uint32 dcHpd1DisconnectIntDelay: 8; // 20
		uint32 unknown2: 4;
	};
	uint32 val;
};

// DC_HPD2_CONTROL
union DcHpd2Control {
	struct {
		uint32 dcHpd2ConnectionTimer: 13; // 0
		uint32 unknown1: 3;
		uint32 dcHpd2RxIntTimer: 10; // 16
		uint32 unknown2: 2;
		uint32 dcHpd2En: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// DC_HPD2_FAST_TRAIN_CNTL
union DcHpd2FastTrainCntl {
	struct {
		uint32 dcHpd2ConnectAuxTxDelay: 8; // 0
		uint32 unknown1: 4;
		uint32 dcHpd2ConnectFastTrainDelay: 8; // 12
		uint32 unknown2: 4;
		uint32 dcHpd2ConnectAuxTxEn: 1; // 24
		uint32 unknown3: 3;
		uint32 dcHpd2ConnectFastTrainEn: 1; // 28
		uint32 unknown4: 3;
	};
	uint32 val;
};

// DC_HPD2_INT_CONTROL
union DcHpd2IntControl {
	struct {
		uint32 dcHpd2IntAck: 1; // 0
		uint32 unknown1: 7;
		uint32 dcHpd2IntPolarity: 1; // 8
		uint32 unknown2: 7;
		uint32 dcHpd2IntEn: 1; // 16
		uint32 unknown3: 3;
		uint32 dcHpd2RxIntAck: 1; // 20
		uint32 unknown4: 3;
		uint32 dcHpd2RxIntEn: 1; // 24
		uint32 unknown5: 7;
	};
	uint32 val;
};

// DC_HPD2_INT_STATUS
union DcHpd2IntStatus {
	struct {
		uint32 dcHpd2IntStatus: 1; // 0
		uint32 dcHpd2Sense: 1; // 1
		uint32 unknown1: 2;
		uint32 dcHpd2SenseDelayed: 1; // 4
		uint32 unknown2: 3;
		uint32 dcHpd2RxIntStatus: 1; // 8
		uint32 unknown3: 3;
		uint32 dcHpd2ToggleFiltConTimerVal: 8; // 12
		uint32 unknown4: 4;
		uint32 dcHpd2ToggleFiltDisconTimerVal: 8; // 24
	};
	uint32 val;
};

// DC_HPD2_TOGGLE_FILT_CNTL
union DcHpd2ToggleFiltCntl {
	struct {
		uint32 dcHpd2ConnectIntDelay: 8; // 0
		uint32 unknown1: 12;
		uint32 dcHpd2DisconnectIntDelay: 8; // 20
		uint32 unknown2: 4;
	};
	uint32 val;
};

// DC_HPD3_CONTROL
union DcHpd3Control {
	struct {
		uint32 dcHpd3ConnectionTimer: 13; // 0
		uint32 unknown1: 3;
		uint32 dcHpd3RxIntTimer: 10; // 16
		uint32 unknown2: 2;
		uint32 dcHpd3En: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// DC_HPD3_FAST_TRAIN_CNTL
union DcHpd3FastTrainCntl {
	struct {
		uint32 dcHpd3ConnectAuxTxDelay: 8; // 0
		uint32 unknown1: 4;
		uint32 dcHpd3ConnectFastTrainDelay: 8; // 12
		uint32 unknown2: 4;
		uint32 dcHpd3ConnectAuxTxEn: 1; // 24
		uint32 unknown3: 3;
		uint32 dcHpd3ConnectFastTrainEn: 1; // 28
		uint32 unknown4: 3;
	};
	uint32 val;
};

// DC_HPD3_INT_CONTROL
union DcHpd3IntControl {
	struct {
		uint32 dcHpd3IntAck: 1; // 0
		uint32 unknown1: 7;
		uint32 dcHpd3IntPolarity: 1; // 8
		uint32 unknown2: 7;
		uint32 dcHpd3IntEn: 1; // 16
		uint32 unknown3: 3;
		uint32 dcHpd3RxIntAck: 1; // 20
		uint32 unknown4: 3;
		uint32 dcHpd3RxIntEn: 1; // 24
		uint32 unknown5: 7;
	};
	uint32 val;
};

// DC_HPD3_INT_STATUS
union DcHpd3IntStatus {
	struct {
		uint32 dcHpd3IntStatus: 1; // 0
		uint32 dcHpd3Sense: 1; // 1
		uint32 unknown1: 2;
		uint32 dcHpd3SenseDelayed: 1; // 4
		uint32 unknown2: 3;
		uint32 dcHpd3RxIntStatus: 1; // 8
		uint32 unknown3: 3;
		uint32 dcHpd3ToggleFiltConTimerVal: 8; // 12
		uint32 unknown4: 4;
		uint32 dcHpd3ToggleFiltDisconTimerVal: 8; // 24
	};
	uint32 val;
};

// DC_HPD3_TOGGLE_FILT_CNTL
union DcHpd3ToggleFiltCntl {
	struct {
		uint32 dcHpd3ConnectIntDelay: 8; // 0
		uint32 unknown1: 12;
		uint32 dcHpd3DisconnectIntDelay: 8; // 20
		uint32 unknown2: 4;
	};
	uint32 val;
};

// DC_HPD4_CONTROL
union DcHpd4Control {
	struct {
		uint32 dcHpd4ConnectionTimer: 13; // 0
		uint32 unknown1: 3;
		uint32 dcHpd4RxIntTimer: 10; // 16
		uint32 unknown2: 2;
		uint32 dcHpd4En: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// DC_HPD4_FAST_TRAIN_CNTL
union DcHpd4FastTrainCntl {
	struct {
		uint32 dcHpd4ConnectAuxTxDelay: 8; // 0
		uint32 unknown1: 4;
		uint32 dcHpd4ConnectFastTrainDelay: 8; // 12
		uint32 unknown2: 4;
		uint32 dcHpd4ConnectAuxTxEn: 1; // 24
		uint32 unknown3: 3;
		uint32 dcHpd4ConnectFastTrainEn: 1; // 28
		uint32 unknown4: 3;
	};
	uint32 val;
};

// DC_HPD4_INT_CONTROL
union DcHpd4IntControl {
	struct {
		uint32 dcHpd4IntAck: 1; // 0
		uint32 unknown1: 7;
		uint32 dcHpd4IntPolarity: 1; // 8
		uint32 unknown2: 7;
		uint32 dcHpd4IntEn: 1; // 16
		uint32 unknown3: 3;
		uint32 dcHpd4RxIntAck: 1; // 20
		uint32 unknown4: 3;
		uint32 dcHpd4RxIntEn: 1; // 24
		uint32 unknown5: 7;
	};
	uint32 val;
};

// DC_HPD4_INT_STATUS
union DcHpd4IntStatus {
	struct {
		uint32 dcHpd4IntStatus: 1; // 0
		uint32 dcHpd4Sense: 1; // 1
		uint32 unknown1: 2;
		uint32 dcHpd4SenseDelayed: 1; // 4
		uint32 unknown2: 3;
		uint32 dcHpd4RxIntStatus: 1; // 8
		uint32 unknown3: 3;
		uint32 dcHpd4ToggleFiltConTimerVal: 8; // 12
		uint32 unknown4: 4;
		uint32 dcHpd4ToggleFiltDisconTimerVal: 8; // 24
	};
	uint32 val;
};

// DC_HPD4_TOGGLE_FILT_CNTL
union DcHpd4ToggleFiltCntl {
	struct {
		uint32 dcHpd4ConnectIntDelay: 8; // 0
		uint32 unknown1: 12;
		uint32 dcHpd4DisconnectIntDelay: 8; // 20
		uint32 unknown2: 4;
	};
	uint32 val;
};

// DC_HPD5_CONTROL
union DcHpd5Control {
	struct {
		uint32 dcHpd5ConnectionTimer: 13; // 0
		uint32 unknown1: 3;
		uint32 dcHpd5RxIntTimer: 10; // 16
		uint32 unknown2: 2;
		uint32 dcHpd5En: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// DC_HPD5_FAST_TRAIN_CNTL
union DcHpd5FastTrainCntl {
	struct {
		uint32 dcHpd5ConnectAuxTxDelay: 8; // 0
		uint32 unknown1: 4;
		uint32 dcHpd5ConnectFastTrainDelay: 8; // 12
		uint32 unknown2: 4;
		uint32 dcHpd5ConnectAuxTxEn: 1; // 24
		uint32 unknown3: 3;
		uint32 dcHpd5ConnectFastTrainEn: 1; // 28
		uint32 unknown4: 3;
	};
	uint32 val;
};

// DC_HPD5_INT_CONTROL
union DcHpd5IntControl {
	struct {
		uint32 dcHpd5IntAck: 1; // 0
		uint32 unknown1: 7;
		uint32 dcHpd5IntPolarity: 1; // 8
		uint32 unknown2: 7;
		uint32 dcHpd5IntEn: 1; // 16
		uint32 unknown3: 3;
		uint32 dcHpd5RxIntAck: 1; // 20
		uint32 unknown4: 3;
		uint32 dcHpd5RxIntEn: 1; // 24
		uint32 unknown5: 7;
	};
	uint32 val;
};

// DC_HPD5_INT_STATUS
union DcHpd5IntStatus {
	struct {
		uint32 dcHpd5IntStatus: 1; // 0
		uint32 dcHpd5Sense: 1; // 1
		uint32 unknown1: 2;
		uint32 dcHpd5SenseDelayed: 1; // 4
		uint32 unknown2: 3;
		uint32 dcHpd5RxIntStatus: 1; // 8
		uint32 unknown3: 3;
		uint32 dcHpd5ToggleFiltConTimerVal: 8; // 12
		uint32 unknown4: 4;
		uint32 dcHpd5ToggleFiltDisconTimerVal: 8; // 24
	};
	uint32 val;
};

// DC_HPD5_TOGGLE_FILT_CNTL
union DcHpd5ToggleFiltCntl {
	struct {
		uint32 dcHpd5ConnectIntDelay: 8; // 0
		uint32 unknown1: 12;
		uint32 dcHpd5DisconnectIntDelay: 8; // 20
		uint32 unknown2: 4;
	};
	uint32 val;
};

// DC_HPD6_CONTROL
union DcHpd6Control {
	struct {
		uint32 dcHpd6ConnectionTimer: 13; // 0
		uint32 unknown1: 3;
		uint32 dcHpd6RxIntTimer: 10; // 16
		uint32 unknown2: 2;
		uint32 dcHpd6En: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// DC_HPD6_FAST_TRAIN_CNTL
union DcHpd6FastTrainCntl {
	struct {
		uint32 dcHpd6ConnectAuxTxDelay: 8; // 0
		uint32 unknown1: 4;
		uint32 dcHpd6ConnectFastTrainDelay: 8; // 12
		uint32 unknown2: 4;
		uint32 dcHpd6ConnectAuxTxEn: 1; // 24
		uint32 unknown3: 3;
		uint32 dcHpd6ConnectFastTrainEn: 1; // 28
		uint32 unknown4: 3;
	};
	uint32 val;
};

// DC_HPD6_INT_CONTROL
union DcHpd6IntControl {
	struct {
		uint32 dcHpd6IntAck: 1; // 0
		uint32 unknown1: 7;
		uint32 dcHpd6IntPolarity: 1; // 8
		uint32 unknown2: 7;
		uint32 dcHpd6IntEn: 1; // 16
		uint32 unknown3: 3;
		uint32 dcHpd6RxIntAck: 1; // 20
		uint32 unknown4: 3;
		uint32 dcHpd6RxIntEn: 1; // 24
		uint32 unknown5: 7;
	};
	uint32 val;
};

// DC_HPD6_INT_STATUS
union DcHpd6IntStatus {
	struct {
		uint32 dcHpd6IntStatus: 1; // 0
		uint32 dcHpd6Sense: 1; // 1
		uint32 unknown1: 2;
		uint32 dcHpd6SenseDelayed: 1; // 4
		uint32 unknown2: 3;
		uint32 dcHpd6RxIntStatus: 1; // 8
		uint32 unknown3: 3;
		uint32 dcHpd6ToggleFiltConTimerVal: 8; // 12
		uint32 unknown4: 4;
		uint32 dcHpd6ToggleFiltDisconTimerVal: 8; // 24
	};
	uint32 val;
};

// DC_HPD6_TOGGLE_FILT_CNTL
union DcHpd6ToggleFiltCntl {
	struct {
		uint32 dcHpd6ConnectIntDelay: 8; // 0
		uint32 unknown1: 12;
		uint32 dcHpd6DisconnectIntDelay: 8; // 20
		uint32 unknown2: 4;
	};
	uint32 val;
};

// DC_I2C_ARBITRATION
union DcI2cArbitration {
	struct {
		uint32 dcI2cSwPriority: 2; // 0
		uint32 dcI2cRegRwCntlStatus: 2; // 2
		uint32 dcI2cNoQueuedSwGo: 1; // 4
		uint32 unknown1: 3;
		uint32 dcI2cAbortHwXfer: 1; // 8
		uint32 unknown2: 3;
		uint32 dcI2cAbortSwXfer: 1; // 12
		uint32 unknown3: 7;
		uint32 dcI2cSwUseI2cRegReq: 1; // 20
		uint32 dcI2cSwDoneUsingI2cReg: 1; // 21
		uint32 unknown4: 2;
		uint32 dcI2cDmcuUseI2cRegReq: 1; // 24
		uint32 dcI2cDmcuDoneUsingI2cReg: 1; // 25
		uint32 unknown5: 6;
	};
	uint32 val;
};

// DC_I2C_CONTROL
union DcI2cControl {
	struct {
		uint32 dcI2cGo: 1; // 0
		uint32 dcI2cSoftReset: 1; // 1
		uint32 dcI2cSendReset: 1; // 2
		uint32 dcI2cSwStatusReset: 1; // 3
		uint32 unknown1: 4;
		uint32 dcI2cDdcSelect: 3; // 8
		uint32 unknown2: 9;
		uint32 dcI2cTransactionCount: 2; // 20
		uint32 unknown3: 9;
		uint32 dcI2cDbgRefSel: 1; // 31
	};
	uint32 val;
};

// DC_I2C_DATA
union DcI2cData {
	struct {
		uint32 dcI2cDataRw: 1; // 0
		uint32 unknown1: 7;
		uint32 dcI2cData: 8; // 8
		uint32 dcI2cIndex: 8; // 16
		uint32 unknown2: 7;
		uint32 dcI2cIndexWrite: 1; // 31
	};
	uint32 val;
};

// DC_I2C_DDC1_HW_STATUS
union DcI2cDdc1HwStatus {
	struct {
		uint32 dcI2cDdc1HwStatus: 2; // 0
		uint32 unknown1: 1;
		uint32 dcI2cDdc1HwDone: 1; // 3
		uint32 unknown2: 12;
		uint32 dcI2cDdc1HwReq: 1; // 16
		uint32 dcI2cDdc1HwUrg: 1; // 17
		uint32 unknown3: 2;
		uint32 dcI2cDdc1EdidDetectStatus: 1; // 20
		uint32 unknown4: 3;
		uint32 dcI2cDdc1EdidDetectNumValidTries: 4; // 24
		uint32 dcI2cDdc1EdidDetectState: 3; // 28
		uint32 unknown5: 1;
	};
	uint32 val;
};

// DC_I2C_DDC1_SETUP
union DcI2cDdc1Setup {
	struct {
		uint32 dcI2cDdc1DataDriveEn: 1; // 0
		uint32 dcI2cDdc1DataDriveSel: 1; // 1
		uint32 unknown1: 2;
		uint32 dcI2cDdc1EdidDetectEnable: 1; // 4
		uint32 dcI2cDdc1EdidDetectMode: 1; // 5
		uint32 dcI2cDdc1Enable: 1; // 6
		uint32 dcI2cDdc1ClkDriveEn: 1; // 7
		uint32 dcI2cDdc1IntraByteDelay: 8; // 8
		uint32 dcI2cDdc1IntraTransactionDelay: 8; // 16
		uint32 dcI2cDdc1TimeLimit: 8; // 24
	};
	uint32 val;
};

// DC_I2C_DDC1_SPEED
union DcI2cDdc1Speed {
	struct {
		uint32 dcI2cDdc1Threshold: 2; // 0
		uint32 unknown1: 2;
		uint32 dcI2cDdc1DisableFilterDuringStall: 1; // 4
		uint32 unknown2: 11;
		uint32 dcI2cDdc1Prescale: 16; // 16
	};
	uint32 val;
};

// DC_I2C_DDC2_HW_STATUS
union DcI2cDdc2HwStatus {
	struct {
		uint32 dcI2cDdc2HwStatus: 2; // 0
		uint32 unknown1: 1;
		uint32 dcI2cDdc2HwDone: 1; // 3
		uint32 unknown2: 12;
		uint32 dcI2cDdc2HwReq: 1; // 16
		uint32 dcI2cDdc2HwUrg: 1; // 17
		uint32 unknown3: 2;
		uint32 dcI2cDdc2EdidDetectStatus: 1; // 20
		uint32 unknown4: 3;
		uint32 dcI2cDdc2EdidDetectNumValidTries: 4; // 24
		uint32 dcI2cDdc2EdidDetectState: 3; // 28
		uint32 unknown5: 1;
	};
	uint32 val;
};

// DC_I2C_DDC2_SETUP
union DcI2cDdc2Setup {
	struct {
		uint32 dcI2cDdc2DataDriveEn: 1; // 0
		uint32 dcI2cDdc2DataDriveSel: 1; // 1
		uint32 unknown1: 2;
		uint32 dcI2cDdc2EdidDetectEnable: 1; // 4
		uint32 dcI2cDdc2EdidDetectMode: 1; // 5
		uint32 dcI2cDdc2Enable: 1; // 6
		uint32 dcI2cDdc2ClkDriveEn: 1; // 7
		uint32 dcI2cDdc2IntraByteDelay: 8; // 8
		uint32 dcI2cDdc2IntraTransactionDelay: 8; // 16
		uint32 dcI2cDdc2TimeLimit: 8; // 24
	};
	uint32 val;
};

// DC_I2C_DDC2_SPEED
union DcI2cDdc2Speed {
	struct {
		uint32 dcI2cDdc2Threshold: 2; // 0
		uint32 unknown1: 2;
		uint32 dcI2cDdc2DisableFilterDuringStall: 1; // 4
		uint32 unknown2: 11;
		uint32 dcI2cDdc2Prescale: 16; // 16
	};
	uint32 val;
};

// DC_I2C_DDC3_HW_STATUS
union DcI2cDdc3HwStatus {
	struct {
		uint32 dcI2cDdc3HwStatus: 2; // 0
		uint32 unknown1: 1;
		uint32 dcI2cDdc3HwDone: 1; // 3
		uint32 unknown2: 12;
		uint32 dcI2cDdc3HwReq: 1; // 16
		uint32 dcI2cDdc3HwUrg: 1; // 17
		uint32 unknown3: 2;
		uint32 dcI2cDdc3EdidDetectStatus: 1; // 20
		uint32 unknown4: 3;
		uint32 dcI2cDdc3EdidDetectNumValidTries: 4; // 24
		uint32 dcI2cDdc3EdidDetectState: 3; // 28
		uint32 unknown5: 1;
	};
	uint32 val;
};

// DC_I2C_DDC3_SETUP
union DcI2cDdc3Setup {
	struct {
		uint32 dcI2cDdc3DataDriveEn: 1; // 0
		uint32 dcI2cDdc3DataDriveSel: 1; // 1
		uint32 unknown1: 2;
		uint32 dcI2cDdc3EdidDetectEnable: 1; // 4
		uint32 dcI2cDdc3EdidDetectMode: 1; // 5
		uint32 dcI2cDdc3Enable: 1; // 6
		uint32 dcI2cDdc3ClkDriveEn: 1; // 7
		uint32 dcI2cDdc3IntraByteDelay: 8; // 8
		uint32 dcI2cDdc3IntraTransactionDelay: 8; // 16
		uint32 dcI2cDdc3TimeLimit: 8; // 24
	};
	uint32 val;
};

// DC_I2C_DDC3_SPEED
union DcI2cDdc3Speed {
	struct {
		uint32 dcI2cDdc3Threshold: 2; // 0
		uint32 unknown1: 2;
		uint32 dcI2cDdc3DisableFilterDuringStall: 1; // 4
		uint32 unknown2: 11;
		uint32 dcI2cDdc3Prescale: 16; // 16
	};
	uint32 val;
};

// DC_I2C_DDC4_HW_STATUS
union DcI2cDdc4HwStatus {
	struct {
		uint32 dcI2cDdc4HwStatus: 2; // 0
		uint32 unknown1: 1;
		uint32 dcI2cDdc4HwDone: 1; // 3
		uint32 unknown2: 12;
		uint32 dcI2cDdc4HwReq: 1; // 16
		uint32 dcI2cDdc4HwUrg: 1; // 17
		uint32 unknown3: 2;
		uint32 dcI2cDdc4EdidDetectStatus: 1; // 20
		uint32 unknown4: 3;
		uint32 dcI2cDdc4EdidDetectNumValidTries: 4; // 24
		uint32 dcI2cDdc4EdidDetectState: 3; // 28
		uint32 unknown5: 1;
	};
	uint32 val;
};

// DC_I2C_DDC4_SETUP
union DcI2cDdc4Setup {
	struct {
		uint32 dcI2cDdc4DataDriveEn: 1; // 0
		uint32 dcI2cDdc4DataDriveSel: 1; // 1
		uint32 unknown1: 2;
		uint32 dcI2cDdc4EdidDetectEnable: 1; // 4
		uint32 dcI2cDdc4EdidDetectMode: 1; // 5
		uint32 dcI2cDdc4Enable: 1; // 6
		uint32 dcI2cDdc4ClkDriveEn: 1; // 7
		uint32 dcI2cDdc4IntraByteDelay: 8; // 8
		uint32 dcI2cDdc4IntraTransactionDelay: 8; // 16
		uint32 dcI2cDdc4TimeLimit: 8; // 24
	};
	uint32 val;
};

// DC_I2C_DDC4_SPEED
union DcI2cDdc4Speed {
	struct {
		uint32 dcI2cDdc4Threshold: 2; // 0
		uint32 unknown1: 2;
		uint32 dcI2cDdc4DisableFilterDuringStall: 1; // 4
		uint32 unknown2: 11;
		uint32 dcI2cDdc4Prescale: 16; // 16
	};
	uint32 val;
};

// DC_I2C_DDC5_HW_STATUS
union DcI2cDdc5HwStatus {
	struct {
		uint32 dcI2cDdc5HwStatus: 2; // 0
		uint32 unknown1: 1;
		uint32 dcI2cDdc5HwDone: 1; // 3
		uint32 unknown2: 12;
		uint32 dcI2cDdc5HwReq: 1; // 16
		uint32 dcI2cDdc5HwUrg: 1; // 17
		uint32 unknown3: 2;
		uint32 dcI2cDdc5EdidDetectStatus: 1; // 20
		uint32 unknown4: 3;
		uint32 dcI2cDdc5EdidDetectNumValidTries: 4; // 24
		uint32 dcI2cDdc5EdidDetectState: 3; // 28
		uint32 unknown5: 1;
	};
	uint32 val;
};

// DC_I2C_DDC5_SETUP
union DcI2cDdc5Setup {
	struct {
		uint32 dcI2cDdc5DataDriveEn: 1; // 0
		uint32 dcI2cDdc5DataDriveSel: 1; // 1
		uint32 unknown1: 2;
		uint32 dcI2cDdc5EdidDetectEnable: 1; // 4
		uint32 dcI2cDdc5EdidDetectMode: 1; // 5
		uint32 dcI2cDdc5Enable: 1; // 6
		uint32 dcI2cDdc5ClkDriveEn: 1; // 7
		uint32 dcI2cDdc5IntraByteDelay: 8; // 8
		uint32 dcI2cDdc5IntraTransactionDelay: 8; // 16
		uint32 dcI2cDdc5TimeLimit: 8; // 24
	};
	uint32 val;
};

// DC_I2C_DDC5_SPEED
union DcI2cDdc5Speed {
	struct {
		uint32 dcI2cDdc5Threshold: 2; // 0
		uint32 unknown1: 2;
		uint32 dcI2cDdc5DisableFilterDuringStall: 1; // 4
		uint32 unknown2: 11;
		uint32 dcI2cDdc5Prescale: 16; // 16
	};
	uint32 val;
};

// DC_I2C_DDC6_HW_STATUS
union DcI2cDdc6HwStatus {
	struct {
		uint32 dcI2cDdc6HwStatus: 2; // 0
		uint32 unknown1: 1;
		uint32 dcI2cDdc6HwDone: 1; // 3
		uint32 unknown2: 12;
		uint32 dcI2cDdc6HwReq: 1; // 16
		uint32 dcI2cDdc6HwUrg: 1; // 17
		uint32 unknown3: 2;
		uint32 dcI2cDdc6EdidDetectStatus: 1; // 20
		uint32 unknown4: 3;
		uint32 dcI2cDdc6EdidDetectNumValidTries: 4; // 24
		uint32 dcI2cDdc6EdidDetectState: 3; // 28
		uint32 unknown5: 1;
	};
	uint32 val;
};

// DC_I2C_DDC6_SETUP
union DcI2cDdc6Setup {
	struct {
		uint32 dcI2cDdc6DataDriveEn: 1; // 0
		uint32 dcI2cDdc6DataDriveSel: 1; // 1
		uint32 unknown1: 2;
		uint32 dcI2cDdc6EdidDetectEnable: 1; // 4
		uint32 dcI2cDdc6EdidDetectMode: 1; // 5
		uint32 dcI2cDdc6Enable: 1; // 6
		uint32 dcI2cDdc6ClkDriveEn: 1; // 7
		uint32 dcI2cDdc6IntraByteDelay: 8; // 8
		uint32 dcI2cDdc6IntraTransactionDelay: 8; // 16
		uint32 dcI2cDdc6TimeLimit: 8; // 24
	};
	uint32 val;
};

// DC_I2C_DDC6_SPEED
union DcI2cDdc6Speed {
	struct {
		uint32 dcI2cDdc6Threshold: 2; // 0
		uint32 unknown1: 2;
		uint32 dcI2cDdc6DisableFilterDuringStall: 1; // 4
		uint32 unknown2: 11;
		uint32 dcI2cDdc6Prescale: 16; // 16
	};
	uint32 val;
};

// DC_I2C_DDCVGA_HW_STATUS
union DcI2cDdcvgaHwStatus {
	struct {
		uint32 dcI2cDdcvgaHwStatus: 2; // 0
		uint32 unknown1: 1;
		uint32 dcI2cDdcvgaHwDone: 1; // 3
		uint32 unknown2: 12;
		uint32 dcI2cDdcvgaHwReq: 1; // 16
		uint32 dcI2cDdcvgaHwUrg: 1; // 17
		uint32 unknown3: 2;
		uint32 dcI2cDdcvgaEdidDetectStatus: 1; // 20
		uint32 unknown4: 3;
		uint32 dcI2cDdcvgaEdidDetectNumValidTries: 4; // 24
		uint32 dcI2cDdcvgaEdidDetectState: 3; // 28
		uint32 unknown5: 1;
	};
	uint32 val;
};

// DC_I2C_DDCVGA_SETUP
union DcI2cDdcvgaSetup {
	struct {
		uint32 dcI2cDdcvgaDataDriveEn: 1; // 0
		uint32 dcI2cDdcvgaDataDriveSel: 1; // 1
		uint32 unknown1: 2;
		uint32 dcI2cDdcvgaEdidDetectEnable: 1; // 4
		uint32 dcI2cDdcvgaEdidDetectMode: 1; // 5
		uint32 dcI2cDdcvgaEnable: 1; // 6
		uint32 dcI2cDdcvgaClkDriveEn: 1; // 7
		uint32 dcI2cDdcvgaIntraByteDelay: 8; // 8
		uint32 dcI2cDdcvgaIntraTransactionDelay: 8; // 16
		uint32 dcI2cDdcvgaTimeLimit: 8; // 24
	};
	uint32 val;
};

// DC_I2C_DDCVGA_SPEED
union DcI2cDdcvgaSpeed {
	struct {
		uint32 dcI2cDdcvgaThreshold: 2; // 0
		uint32 unknown1: 2;
		uint32 dcI2cDdcvgaDisableFilterDuringStall: 1; // 4
		uint32 unknown2: 11;
		uint32 dcI2cDdcvgaPrescale: 16; // 16
	};
	uint32 val;
};

// DC_I2C_EDID_DETECT_CTRL
union DcI2cEdidDetectCtrl {
	struct {
		uint32 dcI2cEdidDetectWaitTime: 16; // 0
		uint32 unknown1: 4;
		uint32 dcI2cEdidDetectNumTriesUntilValid: 4; // 20
		uint32 unknown2: 4;
		uint32 dcI2cEdidDetectSendReset: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// DC_I2C_INTERRUPT_CONTROL
union DcI2cInterruptControl {
	struct {
		uint32 dcI2cSwDoneInt: 1; // 0
		uint32 dcI2cSwDoneAck: 1; // 1
		uint32 dcI2cSwDoneMask: 1; // 2
		uint32 unknown1: 1;
		uint32 dcI2cDdc1HwDoneInt: 1; // 4
		uint32 dcI2cDdc1HwDoneAck: 1; // 5
		uint32 dcI2cDdc1HwDoneMask: 1; // 6
		uint32 unknown2: 1;
		uint32 dcI2cDdc2HwDoneInt: 1; // 8
		uint32 dcI2cDdc2HwDoneAck: 1; // 9
		uint32 dcI2cDdc2HwDoneMask: 1; // 10
		uint32 unknown3: 1;
		uint32 dcI2cDdc3HwDoneInt: 1; // 12
		uint32 dcI2cDdc3HwDoneAck: 1; // 13
		uint32 dcI2cDdc3HwDoneMask: 1; // 14
		uint32 unknown4: 1;
		uint32 dcI2cDdc4HwDoneInt: 1; // 16
		uint32 dcI2cDdc4HwDoneAck: 1; // 17
		uint32 dcI2cDdc4HwDoneMask: 1; // 18
		uint32 unknown5: 1;
		uint32 dcI2cDdc5HwDoneInt: 1; // 20
		uint32 dcI2cDdc5HwDoneAck: 1; // 21
		uint32 dcI2cDdc5HwDoneMask: 1; // 22
		uint32 unknown6: 1;
		uint32 dcI2cDdc6HwDoneInt: 1; // 24
		uint32 dcI2cDdc6HwDoneAck: 1; // 25
		uint32 dcI2cDdc6HwDoneMask: 1; // 26
		uint32 dcI2cDdcvgaHwDoneInt: 1; // 27
		uint32 dcI2cDdcvgaHwDoneAck: 1; // 28
		uint32 dcI2cDdcvgaHwDoneMask: 1; // 29
		uint32 unknown7: 2;
	};
	uint32 val;
};

// DC_I2C_SW_STATUS
union DcI2cSwStatus {
	struct {
		uint32 dcI2cSwStatus: 2; // 0
		uint32 dcI2cSwDone: 1; // 2
		uint32 unknown1: 1;
		uint32 dcI2cSwAborted: 1; // 4
		uint32 dcI2cSwTimeout: 1; // 5
		uint32 dcI2cSwInterrupted: 1; // 6
		uint32 dcI2cSwBufferOverflow: 1; // 7
		uint32 dcI2cSwStoppedOnNack: 1; // 8
		uint32 unknown2: 3;
		uint32 dcI2cSwNack0: 1; // 12
		uint32 dcI2cSwNack1: 1; // 13
		uint32 dcI2cSwNack2: 1; // 14
		uint32 dcI2cSwNack3: 1; // 15
		uint32 unknown3: 2;
		uint32 dcI2cSwReq: 1; // 18
		uint32 unknown4: 13;
	};
	uint32 val;
};

// DC_I2C_TRANSACTION0
union DcI2cTransaction0 {
	struct {
		uint32 dcI2cRw0: 1; // 0
		uint32 unknown1: 7;
		uint32 dcI2cStopOnNack0: 1; // 8
		uint32 unknown2: 3;
		uint32 dcI2cStart0: 1; // 12
		uint32 dcI2cStop0: 1; // 13
		uint32 unknown3: 2;
		uint32 dcI2cCount0: 8; // 16
		uint32 unknown4: 8;
	};
	uint32 val;
};

// DC_I2C_TRANSACTION1
union DcI2cTransaction1 {
	struct {
		uint32 dcI2cRw1: 1; // 0
		uint32 unknown1: 7;
		uint32 dcI2cStopOnNack1: 1; // 8
		uint32 unknown2: 3;
		uint32 dcI2cStart1: 1; // 12
		uint32 dcI2cStop1: 1; // 13
		uint32 unknown3: 2;
		uint32 dcI2cCount1: 8; // 16
		uint32 unknown4: 8;
	};
	uint32 val;
};

// DC_I2C_TRANSACTION2
union DcI2cTransaction2 {
	struct {
		uint32 dcI2cRw2: 1; // 0
		uint32 unknown1: 7;
		uint32 dcI2cStopOnNack2: 1; // 8
		uint32 unknown2: 3;
		uint32 dcI2cStart2: 1; // 12
		uint32 dcI2cStop2: 1; // 13
		uint32 unknown3: 2;
		uint32 dcI2cCount2: 8; // 16
		uint32 unknown4: 8;
	};
	uint32 val;
};

// DC_I2C_TRANSACTION3
union DcI2cTransaction3 {
	struct {
		uint32 dcI2cRw3: 1; // 0
		uint32 unknown1: 7;
		uint32 dcI2cStopOnNack3: 1; // 8
		uint32 unknown2: 3;
		uint32 dcI2cStart3: 1; // 12
		uint32 dcI2cStop3: 1; // 13
		uint32 unknown3: 2;
		uint32 dcI2cCount3: 8; // 16
		uint32 unknown4: 8;
	};
	uint32 val;
};

// DC_LB_MEMORY_SPLIT
union DcLbMemorySplit {
	struct {
		uint32 unknown1: 16;
		uint32 lbNumPartitions: 4; // 16
		uint32 dcLbMemoryConfig: 2; // 20
		uint32 unknown2: 10;
	};
	uint32 val;
};

// DC_LB_MEM_SIZE
union DcLbMemSize {
	struct {
		uint32 dcLbMemSize: 11; // 0
		uint32 unknown1: 21;
	};
	uint32 val;
};

// DC_LUT_30_COLOR
union DcLut30Color {
	struct {
		uint32 dcLutColor10Blue: 10; // 0
		uint32 dcLutColor10Green: 10; // 10
		uint32 dcLutColor10Red: 10; // 20
		uint32 unknown1: 2;
	};
	uint32 val;
};

// DC_LUT_AUTOFILL
union DcLutAutofill {
	struct {
		uint32 dcLutAutofill: 1; // 0
		uint32 dcLutAutofillDone: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// DC_LUT_BLACK_OFFSET_BLUE
union DcLutBlackOffsetBlue {
	struct {
		uint32 dcLutBlackOffsetBlue: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// DC_LUT_BLACK_OFFSET_GREEN
union DcLutBlackOffsetGreen {
	struct {
		uint32 dcLutBlackOffsetGreen: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// DC_LUT_BLACK_OFFSET_RED
union DcLutBlackOffsetRed {
	struct {
		uint32 dcLutBlackOffsetRed: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// DC_LUT_CONTROL
union DcLutControl {
	struct {
		uint32 dcLutIncB: 4; // 0
		uint32 dcLutDataBSignedEn: 1; // 4
		uint32 dcLutDataBFloatPointEn: 1; // 5
		uint32 dcLutDataBFormat: 2; // 6
		uint32 dcLutIncG: 4; // 8
		uint32 dcLutDataGSignedEn: 1; // 12
		uint32 dcLutDataGFloatPointEn: 1; // 13
		uint32 dcLutDataGFormat: 2; // 14
		uint32 dcLutIncR: 4; // 16
		uint32 dcLutDataRSignedEn: 1; // 20
		uint32 dcLutDataRFloatPointEn: 1; // 21
		uint32 dcLutDataRFormat: 2; // 22
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DC_LUT_PWL_DATA
union DcLutPwlData {
	struct {
		uint32 dcLutBase: 16; // 0
		uint32 dcLutDelta: 16; // 16
	};
	uint32 val;
};

// DC_LUT_RW_INDEX
union DcLutRwIndex {
	struct {
		uint32 dcLutRwIndex: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// DC_LUT_RW_MODE
union DcLutRwMode {
	struct {
		uint32 dcLutRwMode: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// DC_LUT_SEQ_COLOR
union DcLutSeqColor {
	struct {
		uint32 dcLutSeqColor: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// DC_LUT_VGA_ACCESS_ENABLE
union DcLutVgaAccessEnable {
	struct {
		uint32 dcLutVgaAccessEnable: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// DC_LUT_WHITE_OFFSET_BLUE
union DcLutWhiteOffsetBlue {
	struct {
		uint32 dcLutWhiteOffsetBlue: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// DC_LUT_WHITE_OFFSET_GREEN
union DcLutWhiteOffsetGreen {
	struct {
		uint32 dcLutWhiteOffsetGreen: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// DC_LUT_WHITE_OFFSET_RED
union DcLutWhiteOffsetRed {
	struct {
		uint32 dcLutWhiteOffsetRed: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// DC_LUT_WRITE_EN_MASK
union DcLutWriteEnMask {
	struct {
		uint32 dcLutWriteEnMask: 3; // 0
		uint32 unknown1: 29;
	};
	uint32 val;
};

// DC_MVP_LB_CONTROL
union DcMvpLbControl {
	struct {
		uint32 mvpSwapLockInMode: 2; // 0
		uint32 unknown1: 6;
		uint32 dcMvpSwapLockOutSel: 1; // 8
		uint32 unknown2: 3;
		uint32 dcMvpSwapLockOutForceOne: 1; // 12
		uint32 unknown3: 3;
		uint32 dcMvpSwapLockOutForceZero: 1; // 16
		uint32 unknown4: 3;
		uint32 dcMvpSwapLockStatus: 1; // 20
		uint32 unknown5: 7;
		uint32 dcMvpSwapLockInCap: 1; // 28
		uint32 unknown6: 2;
		uint32 dcMvpSpareFlops: 1; // 31
	};
	uint32 val;
};

// DC_PAD_EXTERN_SIG
union DcPadExternSig {
	struct {
		uint32 dcPadExternSigSel: 4; // 0
		uint32 mvpPixelSrcStatus: 2; // 4
		uint32 unknown1: 26;
	};
	uint32 val;
};

// DC_PGCNTL_STATUS_REG
union DcPgcntlStatusReg {
	struct {
		uint32 swreqRwopBusy: 1; // 0
		uint32 swreqRwopForce: 1; // 1
		uint32 ipreqIgnoreStatus: 1; // 2
		uint32 unknown1: 13;
		uint32 dcpgEcoDebug: 16; // 16
	};
	uint32 val;
};

// DC_PGFSM_CONFIG_REG
union DcPgfsmConfigReg {
	struct {
		uint32 pgfsmConfigReg: 32; // 0
	};
	uint32 val;
};

// DC_PGFSM_WRITE_REG
union DcPgfsmWriteReg {
	struct {
		uint32 pgfsmWriteReg: 32; // 0
	};
	uint32 val;
};

// DC_PINSTRAPS
union DcPinstraps {
	struct {
		uint32 unknown1: 10;
		uint32 dcPinstrapsBifCecDis: 1; // 10
		uint32 dcPinstrapsVipDevice: 1; // 11
		uint32 unknown2: 1;
		uint32 dcPinstrapsSmsEnHard: 1; // 13
		uint32 dcPinstrapsAudio: 2; // 14
		uint32 dcPinstrapsCcbypass: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// DC_RBBMIF_RDWR_CNTL1
union DcRbbmifRdwrCntl1 {
	struct {
		uint32 dcRbbmifClient0RdwrDelay: 3; // 0
		uint32 dcRbbmifClient0RdwrTimeoutDis: 1; // 3
		uint32 dcRbbmifClient1RdwrDelay: 3; // 4
		uint32 dcRbbmifClient1RdwrTimeoutDis: 1; // 7
		uint32 dcRbbmifClient2RdwrDelay: 3; // 8
		uint32 dcRbbmifClient2RdwrTimeoutDis: 1; // 11
		uint32 dcRbbmifClient3RdwrDelay: 3; // 12
		uint32 dcRbbmifClient3RdwrTimeoutDis: 1; // 15
		uint32 dcRbbmifClient4RdwrDelay: 3; // 16
		uint32 dcRbbmifClient4RdwrTimeoutDis: 1; // 19
		uint32 unknown1: 12;
	};
	uint32 val;
};

// DC_RBBMIF_RDWR_CNTL2
union DcRbbmifRdwrCntl2 {
	struct {
		uint32 dcRbbmifClient8RdwrDelay: 3; // 0
		uint32 dcRbbmifClient8RdwrTimeoutDis: 1; // 3
		uint32 dcRbbmifClient9RdwrDelay: 3; // 4
		uint32 dcRbbmifClient9RdwrTimeoutDis: 1; // 7
		uint32 unknown1: 24;
	};
	uint32 val;
};

// DC_REF_CLK_CNTL
union DcRefClkCntl {
	struct {
		uint32 hsyncaOutputSel: 2; // 0
		uint32 unknown1: 6;
		uint32 genlkClkOutputSel: 2; // 8
		uint32 unknown2: 22;
	};
	uint32 val;
};

// DC_XDMA_INTERFACE_CNTL
union DcXdmaInterfaceCntl {
	struct {
		uint32 xdmaPipeEnable: 6; // 0
		uint32 unknown1: 2;
		uint32 xdmaPipeSel: 3; // 8
		uint32 unknown2: 5;
		uint32 dcXdmaFlipPending: 1; // 16
		uint32 unknown3: 3;
		uint32 xdmaMFlipPendingToDcp: 1; // 20
		uint32 xdmaSFlipPendingToDcp: 1; // 21
		uint32 dcFlipPendingToDcp: 1; // 22
		uint32 unknown4: 9;
	};
	uint32 val;
};

// DEGAMMA_CONTROL
union DegammaControl {
	struct {
		uint32 grphDegammaMode: 2; // 0
		uint32 unknown1: 2;
		uint32 ovlDegammaMode: 2; // 4
		uint32 unknown2: 6;
		uint32 cursorDegammaMode: 2; // 12
		uint32 unknown3: 18;
	};
	uint32 val;
};

// DENORM_CONTROL
union DenormControl {
	struct {
		uint32 denormMode: 3; // 0
		uint32 unknown1: 29;
	};
	uint32 val;
};

// DENTIST_DISPCLK_CNTL
union DentistDispclkCntl {
	struct {
		uint32 dentistDispclkWdivider: 7; // 0
		uint32 unknown1: 1;
		uint32 dentistDispclkRdivider: 7; // 8
		uint32 dentistDispclkChgMode: 2; // 15
		uint32 dentistDispclkChgtog: 1; // 17
		uint32 dentistDispclkDonetog: 1; // 18
		uint32 dentistDispclkChgDone: 1; // 19
		uint32 dentistDprefclkChgDone: 1; // 20
		uint32 dentistDprefclkChgtog: 1; // 21
		uint32 dentistDprefclkDonetog: 1; // 22
		uint32 unknown2: 1;
		uint32 dentistDprefclkWdivider: 7; // 24
		uint32 unknown3: 1;
	};
	uint32 val;
};

// DIG_BE_CNTL
union DigBeCntl {
	struct {
		uint32 unknown1: 8;
		uint32 digFeSourceSelect: 6; // 8
		uint32 unknown2: 2;
		uint32 digMode: 3; // 16
		uint32 unknown3: 9;
		uint32 digHpdSelect: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// DIG_BE_EN_CNTL
union DigBeEnCntl {
	struct {
		uint32 digEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 digSymclkBeOn: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DIG_CLOCK_PATTERN
union DigClockPattern {
	struct {
		uint32 digClockPattern: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// DIG_DISPCLK_SWITCH_CNTL
union DigDispclkSwitchCntl {
	struct {
		uint32 digDispclkSwitchPoint: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// DIG_DISPCLK_SWITCH_STATUS
union DigDispclkSwitchStatus {
	struct {
		uint32 digDispclkSwitchAllowed: 1; // 0
		uint32 unknown1: 3;
		uint32 digDispclkSwitchAllowedInt: 1; // 4
		uint32 unknown2: 3;
		uint32 digDispclkSwitchAllowedIntAck: 1; // 8
		uint32 unknown3: 3;
		uint32 digDispclkSwitchAllowedIntMask: 1; // 12
		uint32 unknown4: 19;
	};
	uint32 val;
};

// DIG_FE_CNTL
union DigFeCntl {
	struct {
		uint32 digSourceSelect: 3; // 0
		uint32 unknown1: 1;
		uint32 digStereosyncSelect: 3; // 4
		uint32 unknown2: 1;
		uint32 digStereosyncGateEn: 1; // 8
		uint32 unknown3: 1;
		uint32 digStart: 1; // 10
		uint32 unknown4: 5;
		uint32 digDualLinkEnable: 1; // 16
		uint32 unknown5: 1;
		uint32 digSwap: 1; // 18
		uint32 unknown6: 1;
		uint32 digRbSwitchEn: 1; // 20
		uint32 unknown7: 3;
		uint32 digSymclkFeOn: 1; // 24
		uint32 unknown8: 7;
	};
	uint32 val;
};

// DIG_FIFO_STATUS
union DigFifoStatus {
	struct {
		uint32 digFifoLevelError: 1; // 0
		uint32 digFifoUseOverwriteLevel: 1; // 1
		uint32 digFifoOverwriteLevel: 6; // 2
		uint32 digFifoErrorAck: 1; // 8
		uint32 unknown1: 1;
		uint32 digFifoCalAverageLevel: 6; // 10
		uint32 digFifoMaximumLevel: 5; // 16
		uint32 unknown2: 1;
		uint32 digFifoMinimumLevel: 4; // 22
		uint32 unknown3: 3;
		uint32 digFifoCalibrated: 1; // 29
		uint32 digFifoForceRecalAverage: 1; // 30
		uint32 digFifoForceRecompMinmax: 1; // 31
	};
	uint32 val;
};

// DIG_LANE_ENABLE
union DigLaneEnable {
	struct {
		uint32 digLane0en: 1; // 0
		uint32 digLane1en: 1; // 1
		uint32 digLane2en: 1; // 2
		uint32 digLane3en: 1; // 3
		uint32 unknown1: 4;
		uint32 digClkEn: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DIG_OUTPUT_CRC_CNTL
union DigOutputCrcCntl {
	struct {
		uint32 digOutputCrcEn: 1; // 0
		uint32 unknown1: 3;
		uint32 digOutputCrcLinkSel: 1; // 4
		uint32 unknown2: 3;
		uint32 digOutputCrcDataSel: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// DIG_OUTPUT_CRC_RESULT
union DigOutputCrcResult {
	struct {
		uint32 digOutputCrcResult: 30; // 0
		uint32 unknown1: 2;
	};
	uint32 val;
};

// DIG_RANDOM_PATTERN_SEED
union DigRandomPatternSeed {
	struct {
		uint32 digRandomPatternSeed: 24; // 0
		uint32 digRanPatDuringDeOnly: 1; // 24
		uint32 unknown1: 7;
	};
	uint32 val;
};

// DIG_SOFT_RESET
union DigSoftReset {
	struct {
		uint32 digaFeSoftReset: 1; // 0
		uint32 digaBeSoftReset: 1; // 1
		uint32 unknown1: 2;
		uint32 digbFeSoftReset: 1; // 4
		uint32 digbBeSoftReset: 1; // 5
		uint32 unknown2: 2;
		uint32 digcFeSoftReset: 1; // 8
		uint32 digcBeSoftReset: 1; // 9
		uint32 unknown3: 2;
		uint32 digdFeSoftReset: 1; // 12
		uint32 digdBeSoftReset: 1; // 13
		uint32 unknown4: 2;
		uint32 digeFeSoftReset: 1; // 16
		uint32 digeBeSoftReset: 1; // 17
		uint32 unknown5: 2;
		uint32 digfFeSoftReset: 1; // 20
		uint32 digfBeSoftReset: 1; // 21
		uint32 unknown6: 10;
	};
	uint32 val;
};

// DIG_TEST_PATTERN
union DigTestPattern {
	struct {
		uint32 digTestPatternOutEn: 1; // 0
		uint32 digHalfClockPatternSel: 1; // 1
		uint32 lvdsTestClockData: 1; // 2
		uint32 unknown1: 1;
		uint32 digRandomPatternOutEn: 1; // 4
		uint32 digRandomPatternReset: 1; // 5
		uint32 digTestPatternExternalResetEn: 1; // 6
		uint32 unknown2: 1;
		uint32 lvdsEyePattern: 1; // 8
		uint32 unknown3: 7;
		uint32 digStaticTestPattern: 10; // 16
		uint32 unknown4: 6;
	};
	uint32 val;
};

// DISPCLK_CGTT_BLK_CTRL_REG
union DispclkCgttBlkCtrlReg {
	struct {
		uint32 dispclkTurnOnDelay: 4; // 0
		uint32 dispclkTurnOffDelay: 8; // 4
		uint32 unknown1: 20;
	};
	uint32 val;
};

// DISPCLK_FREQ_CHANGE_CNTL
union DispclkFreqChangeCntl {
	struct {
		uint32 dispclkStepDelay: 14; // 0
		uint32 unknown1: 2;
		uint32 dispclkStepSize: 4; // 16
		uint32 dispclkFreqRampDone: 1; // 20
		uint32 unknown2: 4;
		uint32 dispclkMaxErrdetCycles: 3; // 25
		uint32 dccgFifoErrdetReset: 1; // 28
		uint32 dccgFifoErrdetState: 1; // 29
		uint32 dccgFifoErrdetOvrEn: 1; // 30
		uint32 dispclkChgFwdCorrDisable: 1; // 31
	};
	uint32 val;
};

// DISPOUT_STEREOSYNC_SEL
union DispoutStereosyncSel {
	struct {
		uint32 genericaStereosyncSel: 3; // 0
		uint32 unknown1: 13;
		uint32 genericbStereosyncSel: 3; // 16
		uint32 unknown2: 13;
	};
	uint32 val;
};

// DISPPLL_BG_CNTL
union DisppllBgCntl {
	struct {
		uint32 disppllBgPdn: 1; // 0
		uint32 unknown1: 3;
		uint32 disppllBgAdj: 4; // 4
		uint32 unknown2: 24;
	};
	uint32 val;
};

// DISP_INTERRUPT_STATUS
union DispInterruptStatus {
	struct {
		uint32 sclDisp1ModeChangeInterrupt: 1; // 0
		uint32 unknown1: 1;
		uint32 lbD1VlineInterrupt: 1; // 2
		uint32 lbD1VblankInterrupt: 1; // 3
		uint32 crtc1SnapshotInterrupt: 1; // 4
		uint32 crtc1ForceVsyncNextLineInterrupt: 1; // 5
		uint32 crtc1ForceCountNowInterrupt: 1; // 6
		uint32 crtc1TrigaInterrupt: 1; // 7
		uint32 crtc1TrigbInterrupt: 1; // 8
		uint32 crtc1VsyncNomInterrupt: 1; // 9
		uint32 crtc1SetVTotalMinEventOccuredInt: 1; // 10
		uint32 unknown2: 4;
		uint32 digaDpFastTrainingCompleteInterrupt: 1; // 15
		uint32 digaDpVidStreamDisableInterrupt: 1; // 16
		uint32 dcHpd1Interrupt: 1; // 17
		uint32 dcHpd1RxInterrupt: 1; // 18
		uint32 aux1SwDoneInterrupt: 1; // 19
		uint32 aux1LsDoneInterrupt: 1; // 20
		uint32 digaDispclkSwitchAllowedInterrupt: 1; // 21
		uint32 dacaAutodetectInterrupt: 1; // 22
		uint32 dacbAutodetectInterrupt: 1; // 23
		uint32 dcI2cSwDoneInterrupt: 1; // 24
		uint32 dcI2cHwDoneInterrupt: 1; // 25
		uint32 dmcuUcInternalInt: 1; // 26
		uint32 dmcuScpInt: 1; // 27
		uint32 abm1HgReadyInt: 1; // 28
		uint32 abm1LsReadyInt: 1; // 29
		uint32 abm1BlUpdateInt: 1; // 30
		uint32 dispInterruptStatusContinue: 1; // 31
	};
	uint32 val;
};

// DISP_INTERRUPT_STATUS_CONTINUE
union DispInterruptStatusContinue {
	struct {
		uint32 sclDisp2ModeChangeInterrupt: 1; // 0
		uint32 unknown1: 1;
		uint32 lbD2VlineInterrupt: 1; // 2
		uint32 lbD2VblankInterrupt: 1; // 3
		uint32 crtc2SnapshotInterrupt: 1; // 4
		uint32 crtc2ForceVsyncNextLineInterrupt: 1; // 5
		uint32 crtc2ForceCountNowInterrupt: 1; // 6
		uint32 crtc2TrigaInterrupt: 1; // 7
		uint32 crtc2TrigbInterrupt: 1; // 8
		uint32 crtc2VsyncNomInterrupt: 1; // 9
		uint32 crtc2SetVTotalMinEventOccuredInt: 1; // 10
		uint32 unknown2: 4;
		uint32 digbDpFastTrainingCompleteInterrupt: 1; // 15
		uint32 digbDpVidStreamDisableInterrupt: 1; // 16
		uint32 dcHpd2Interrupt: 1; // 17
		uint32 dcHpd2RxInterrupt: 1; // 18
		uint32 aux2SwDoneInterrupt: 1; // 19
		uint32 aux2LsDoneInterrupt: 1; // 20
		uint32 unknown3: 3;
		uint32 dispTimerInterrupt: 1; // 24
		uint32 unknown4: 6;
		uint32 dispInterruptStatusContinue2: 1; // 31
	};
	uint32 val;
};

// DISP_INTERRUPT_STATUS_CONTINUE2
union DispInterruptStatusContinue2 {
	struct {
		uint32 sclDisp3ModeChangeInterrupt: 1; // 0
		uint32 unknown1: 1;
		uint32 lbD3VlineInterrupt: 1; // 2
		uint32 lbD3VblankInterrupt: 1; // 3
		uint32 crtc3SnapshotInterrupt: 1; // 4
		uint32 crtc3ForceVsyncNextLineInterrupt: 1; // 5
		uint32 crtc3ForceCountNowInterrupt: 1; // 6
		uint32 crtc3TrigaInterrupt: 1; // 7
		uint32 crtc3TrigbInterrupt: 1; // 8
		uint32 crtc3VsyncNomInterrupt: 1; // 9
		uint32 crtc3SetVTotalMinEventOccuredInt: 1; // 10
		uint32 unknown2: 4;
		uint32 digcDpFastTrainingCompleteInterrupt: 1; // 15
		uint32 digcDpVidStreamDisableInterrupt: 1; // 16
		uint32 dcHpd3Interrupt: 1; // 17
		uint32 dcHpd3RxInterrupt: 1; // 18
		uint32 aux3SwDoneInterrupt: 1; // 19
		uint32 aux3LsDoneInterrupt: 1; // 20
		uint32 unknown3: 10;
		uint32 dispInterruptStatusContinue3: 1; // 31
	};
	uint32 val;
};

// DISP_INTERRUPT_STATUS_CONTINUE3
union DispInterruptStatusContinue3 {
	struct {
		uint32 sclDisp4ModeChangeInterrupt: 1; // 0
		uint32 unknown1: 1;
		uint32 lbD4VlineInterrupt: 1; // 2
		uint32 lbD4VblankInterrupt: 1; // 3
		uint32 crtc4SnapshotInterrupt: 1; // 4
		uint32 crtc4ForceVsyncNextLineInterrupt: 1; // 5
		uint32 crtc4ForceCountNowInterrupt: 1; // 6
		uint32 crtc4TrigaInterrupt: 1; // 7
		uint32 crtc4TrigbInterrupt: 1; // 8
		uint32 crtc4VsyncNomInterrupt: 1; // 9
		uint32 crtc4SetVTotalMinEventOccuredInt: 1; // 10
		uint32 unknown2: 4;
		uint32 digdDpFastTrainingCompleteInterrupt: 1; // 15
		uint32 digdDpVidStreamDisableInterrupt: 1; // 16
		uint32 dcHpd4Interrupt: 1; // 17
		uint32 dcHpd4RxInterrupt: 1; // 18
		uint32 aux4SwDoneInterrupt: 1; // 19
		uint32 aux4LsDoneInterrupt: 1; // 20
		uint32 unknown3: 10;
		uint32 dispInterruptStatusContinue4: 1; // 31
	};
	uint32 val;
};

// DISP_INTERRUPT_STATUS_CONTINUE4
union DispInterruptStatusContinue4 {
	struct {
		uint32 sclDisp5ModeChangeInterrupt: 1; // 0
		uint32 unknown1: 1;
		uint32 lbD5VlineInterrupt: 1; // 2
		uint32 lbD5VblankInterrupt: 1; // 3
		uint32 crtc5SnapshotInterrupt: 1; // 4
		uint32 crtc5ForceVsyncNextLineInterrupt: 1; // 5
		uint32 crtc5ForceCountNowInterrupt: 1; // 6
		uint32 crtc5TrigaInterrupt: 1; // 7
		uint32 crtc5TrigbInterrupt: 1; // 8
		uint32 crtc5VsyncNomInterrupt: 1; // 9
		uint32 crtc5SetVTotalMinEventOccuredInt: 1; // 10
		uint32 unknown2: 4;
		uint32 digeDpFastTrainingCompleteInterrupt: 1; // 15
		uint32 digeDpVidStreamDisableInterrupt: 1; // 16
		uint32 dcHpd5Interrupt: 1; // 17
		uint32 dcHpd5RxInterrupt: 1; // 18
		uint32 aux5SwDoneInterrupt: 1; // 19
		uint32 aux5LsDoneInterrupt: 1; // 20
		uint32 unknown3: 10;
		uint32 dispInterruptStatusContinue5: 1; // 31
	};
	uint32 val;
};

// DISP_INTERRUPT_STATUS_CONTINUE5
union DispInterruptStatusContinue5 {
	struct {
		uint32 sclDisp6ModeChangeInterrupt: 1; // 0
		uint32 unknown1: 1;
		uint32 lbD6VlineInterrupt: 1; // 2
		uint32 lbD6VblankInterrupt: 1; // 3
		uint32 crtc6SnapshotInterrupt: 1; // 4
		uint32 crtc6ForceVsyncNextLineInterrupt: 1; // 5
		uint32 crtc6ForceCountNowInterrupt: 1; // 6
		uint32 crtc6TrigaInterrupt: 1; // 7
		uint32 crtc6TrigbInterrupt: 1; // 8
		uint32 crtc6VsyncNomInterrupt: 1; // 9
		uint32 crtc6SetVTotalMinEventOccuredInt: 1; // 10
		uint32 unknown2: 4;
		uint32 digfDpFastTrainingCompleteInterrupt: 1; // 15
		uint32 digfDpVidStreamDisableInterrupt: 1; // 16
		uint32 dcHpd6Interrupt: 1; // 17
		uint32 dcHpd6RxInterrupt: 1; // 18
		uint32 aux6SwDoneInterrupt: 1; // 19
		uint32 aux6LsDoneInterrupt: 1; // 20
		uint32 unknown3: 11;
	};
	uint32 val;
};

// DISP_TIMER_CONTROL
union DispTimerControl {
	struct {
		uint32 dispTimerIntCount: 25; // 0
		uint32 dispTimerIntEnable: 1; // 25
		uint32 dispTimerIntRunning: 1; // 26
		uint32 dispTimerIntMsk: 1; // 27
		uint32 dispTimerIntStat: 1; // 28
		uint32 dispTimerIntStatAk: 1; // 29
		uint32 dispTimerInt: 1; // 30
		uint32 unknown1: 1;
	};
	uint32 val;
};

// DMCU_CTRL
union DmcuCtrl {
	struct {
		uint32 resetUc: 1; // 0
		uint32 ignorePwrmgt: 1; // 1
		uint32 disableIrqToUc: 1; // 2
		uint32 disableXirqToUc: 1; // 3
		uint32 dmcuEnable: 1; // 4
		uint32 unknown1: 17;
		uint32 ucRegRdTimeout: 10; // 22
	};
	uint32 val;
};

// DMCU_ERAM_RD_CTRL
union DmcuEramRdCtrl {
	struct {
		uint32 eramRdAddr: 16; // 0
		uint32 eramRdBe: 4; // 16
		uint32 eramRdByteMode: 1; // 20
		uint32 unknown1: 11;
	};
	uint32 val;
};

// DMCU_ERAM_RD_DATA
union DmcuEramRdData {
	struct {
		uint32 eramRdData: 32; // 0
	};
	uint32 val;
};

// DMCU_ERAM_WR_CTRL
union DmcuEramWrCtrl {
	struct {
		uint32 eramWrAddr: 16; // 0
		uint32 eramWrBe: 4; // 16
		uint32 eramWrByteMode: 1; // 20
		uint32 unknown1: 11;
	};
	uint32 val;
};

// DMCU_ERAM_WR_DATA
union DmcuEramWrData {
	struct {
		uint32 eramWrData: 32; // 0
	};
	uint32 val;
};

// DMCU_EVENT_TRIGGER
union DmcuEventTrigger {
	struct {
		uint32 genSwIntToUc: 1; // 0
		uint32 unknown1: 15;
		uint32 ucInternalIntCode: 7; // 16
		uint32 genUcInternalIntToHost: 1; // 23
		uint32 unknown2: 8;
	};
	uint32 val;
};

// DMCU_FW_CHECKSUM_SMPL_BYTE_POS
union DmcuFwChecksumSmplBytePos {
	struct {
		uint32 dmcuFwChecksumLoSmplBytePos: 2; // 0
		uint32 dmcuFwChecksumHiSmplBytePos: 2; // 2
		uint32 unknown1: 28;
	};
	uint32 val;
};

// DMCU_FW_CS_HI
union DmcuFwCsHi {
	struct {
		uint32 fwChecksumHi: 32; // 0
	};
	uint32 val;
};

// DMCU_FW_CS_LO
union DmcuFwCsLo {
	struct {
		uint32 fwChecksumLo: 32; // 0
	};
	uint32 val;
};

// DMCU_FW_END_ADDR
union DmcuFwEndAddr {
	struct {
		uint32 fwEndAddrLsb: 8; // 0
		uint32 fwEndAddrMsb: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// DMCU_FW_ISR_START_ADDR
union DmcuFwIsrStartAddr {
	struct {
		uint32 fwIsrStartAddrLsb: 8; // 0
		uint32 fwIsrStartAddrMsb: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// DMCU_FW_START_ADDR
union DmcuFwStartAddr {
	struct {
		uint32 fwStartAddrLsb: 8; // 0
		uint32 fwStartAddrMsb: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// DMCU_INTERRUPT_STATUS
union DmcuInterruptStatus {
	struct {
		uint32 abm1HgReadyIntClear: 1; // 0
		uint32 abm1LsReadyIntClear: 1; // 1
		uint32 abm1BlUpdateIntClear: 1; // 2
		uint32 mcpIntOccurred: 1; // 3
		uint32 unknown1: 4;
		uint32 externalSwIntClear: 1; // 8
		uint32 scpIntOccurred: 1; // 9
		uint32 ucInternalIntClear: 1; // 10
		uint32 ucRegRdTimeoutIntClear: 1; // 11
		uint32 dcpgIhcDcfe0PowerUpIntClear: 1; // 12
		uint32 dcpgIhcDcfe1PowerUpIntClear: 1; // 13
		uint32 dcpgIhcDcfe2PowerUpIntClear: 1; // 14
		uint32 dcpgIhcDcfe3PowerUpIntClear: 1; // 15
		uint32 dcpgIhcDcfe4PowerUpIntClear: 1; // 16
		uint32 dcpgIhcDcfe5PowerUpIntClear: 1; // 17
		uint32 dcpgIhcDcfe0PowerDownIntClear: 1; // 18
		uint32 dcpgIhcDcfe1PowerDownIntClear: 1; // 19
		uint32 dcpgIhcDcfe2PowerDownIntClear: 1; // 20
		uint32 dcpgIhcDcfe3PowerDownIntClear: 1; // 21
		uint32 dcpgIhcDcfe4PowerDownIntClear: 1; // 22
		uint32 dcpgIhcDcfe5PowerDownIntClear: 1; // 23
		uint32 vblank1IntClear: 1; // 24
		uint32 vblank2IntClear: 1; // 25
		uint32 vblank3IntClear: 1; // 26
		uint32 vblank4IntClear: 1; // 27
		uint32 vblank5IntClear: 1; // 28
		uint32 vblank6IntClear: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// DMCU_INTERRUPT_TO_HOST_EN_MASK
union DmcuInterruptToHostEnMask {
	struct {
		uint32 abm1HgReadyIntMask: 1; // 0
		uint32 abm1LsReadyIntMask: 1; // 1
		uint32 abm1BlUpdateIntMask: 1; // 2
		uint32 unknown1: 6;
		uint32 scpIntMask: 1; // 9
		uint32 ucInternalIntMask: 1; // 10
		uint32 ucRegRdTimeoutIntMask: 1; // 11
		uint32 dcpgIhcDcfe0PowerUpIntMask: 1; // 12
		uint32 dcpgIhcDcfe1PowerUpIntMask: 1; // 13
		uint32 dcpgIhcDcfe2PowerUpIntMask: 1; // 14
		uint32 dcpgIhcDcfe3PowerUpIntMask: 1; // 15
		uint32 dcpgIhcDcfe4PowerUpIntMask: 1; // 16
		uint32 dcpgIhcDcfe5PowerUpIntMask: 1; // 17
		uint32 dcpgIhcDcfe0PowerDownIntMask: 1; // 18
		uint32 dcpgIhcDcfe1PowerDownIntMask: 1; // 19
		uint32 dcpgIhcDcfe2PowerDownIntMask: 1; // 20
		uint32 dcpgIhcDcfe3PowerDownIntMask: 1; // 21
		uint32 dcpgIhcDcfe4PowerDownIntMask: 1; // 22
		uint32 dcpgIhcDcfe5PowerDownIntMask: 1; // 23
		uint32 unknown2: 8;
	};
	uint32 val;
};

// DMCU_INTERRUPT_TO_UC_EN_MASK
union DmcuInterruptToUcEnMask {
	struct {
		uint32 abm1HgReadyIntToUcEn: 1; // 0
		uint32 abm1LsReadyIntToUcEn: 1; // 1
		uint32 abm1BlUpdateIntToUcEn: 1; // 2
		uint32 mcpIntToUcEn: 1; // 3
		uint32 unknown1: 4;
		uint32 externalSwIntToUcEn: 1; // 8
		uint32 unknown2: 3;
		uint32 dcpgIhcDcfe0PowerUpIntToUcEn: 1; // 12
		uint32 dcpgIhcDcfe1PowerUpIntToUcEn: 1; // 13
		uint32 dcpgIhcDcfe2PowerUpIntToUcEn: 1; // 14
		uint32 dcpgIhcDcfe3PowerUpIntToUcEn: 1; // 15
		uint32 dcpgIhcDcfe4PowerUpIntToUcEn: 1; // 16
		uint32 dcpgIhcDcfe5PowerUpIntToUcEn: 1; // 17
		uint32 dcpgIhcDcfe0PowerDownIntToUcEn: 1; // 18
		uint32 dcpgIhcDcfe1PowerDownIntToUcEn: 1; // 19
		uint32 dcpgIhcDcfe2PowerDownIntToUcEn: 1; // 20
		uint32 dcpgIhcDcfe3PowerDownIntToUcEn: 1; // 21
		uint32 dcpgIhcDcfe4PowerDownIntToUcEn: 1; // 22
		uint32 dcpgIhcDcfe5PowerDownIntToUcEn: 1; // 23
		uint32 vblank1IntToUcEn: 1; // 24
		uint32 vblank2IntToUcEn: 1; // 25
		uint32 vblank3IntToUcEn: 1; // 26
		uint32 vblank4IntToUcEn: 1; // 27
		uint32 vblank5IntToUcEn: 1; // 28
		uint32 vblank6IntToUcEn: 1; // 29
		uint32 unknown3: 2;
	};
	uint32 val;
};

// DMCU_INTERRUPT_TO_UC_XIRQ_IRQ_SEL
union DmcuInterruptToUcXirqIrqSel {
	struct {
		uint32 abm1HgReadyIntXirqIrqSel: 1; // 0
		uint32 abm1LsReadyIntXirqIrqSel: 1; // 1
		uint32 abm1BlUpdateIntXirqIrqSel: 1; // 2
		uint32 mcpIntXirqIrqSel: 1; // 3
		uint32 unknown1: 4;
		uint32 externalSwIntXirqIrqSel: 1; // 8
		uint32 unknown2: 3;
		uint32 dcpgIhcDcfe0PowerUpIntXirqIrqSel: 1; // 12
		uint32 dcpgIhcDcfe1PowerUpIntXirqIrqSel: 1; // 13
		uint32 dcpgIhcDcfe2PowerUpIntXirqIrqSel: 1; // 14
		uint32 dcpgIhcDcfe3PowerUpIntXirqIrqSel: 1; // 15
		uint32 dcpgIhcDcfe4PowerUpIntXirqIrqSel: 1; // 16
		uint32 dcpgIhcDcfe5PowerUpIntXirqIrqSel: 1; // 17
		uint32 dcpgIhcDcfe0PowerDownIntXirqIrqSel: 1; // 18
		uint32 dcpgIhcDcfe1PowerDownIntXirqIrqSel: 1; // 19
		uint32 dcpgIhcDcfe2PowerDownIntXirqIrqSel: 1; // 20
		uint32 dcpgIhcDcfe3PowerDownIntXirqIrqSel: 1; // 21
		uint32 dcpgIhcDcfe4PowerDownIntXirqIrqSel: 1; // 22
		uint32 dcpgIhcDcfe5PowerDownIntXirqIrqSel: 1; // 23
		uint32 vblank1IntXirqIrqSel: 1; // 24
		uint32 vblank2IntXirqIrqSel: 1; // 25
		uint32 vblank3IntXirqIrqSel: 1; // 26
		uint32 vblank4IntXirqIrqSel: 1; // 27
		uint32 vblank5IntXirqIrqSel: 1; // 28
		uint32 vblank6IntXirqIrqSel: 1; // 29
		uint32 unknown3: 2;
	};
	uint32 val;
};

// DMCU_INT_CNT
union DmcuIntCnt {
	struct {
		uint32 dmcuAbm1HgReadyIntCnt: 8; // 0
		uint32 dmcuAbm1LsReadyIntCnt: 8; // 8
		uint32 dmcuAbm1BlUpdateIntCnt: 8; // 16
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DMCU_IRAM_RD_CTRL
union DmcuIramRdCtrl {
	struct {
		uint32 iramRdAddr: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// DMCU_IRAM_RD_DATA
union DmcuIramRdData {
	struct {
		uint32 iramRdData: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// DMCU_IRAM_WR_CTRL
union DmcuIramWrCtrl {
	struct {
		uint32 iramWrAddr: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// DMCU_IRAM_WR_DATA
union DmcuIramWrData {
	struct {
		uint32 iramWrData: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// DMCU_PC_START_ADDR
union DmcuPcStartAddr {
	struct {
		uint32 pcStartAddrLsb: 8; // 0
		uint32 pcStartAddrMsb: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// DMCU_RAM_ACCESS_CTRL
union DmcuRamAccessCtrl {
	struct {
		uint32 eramWrAddrAutoInc: 1; // 0
		uint32 eramRdAddrAutoInc: 1; // 1
		uint32 iramWrAddrAutoInc: 1; // 2
		uint32 iramRdAddrAutoInc: 1; // 3
		uint32 eramHostAccessEn: 1; // 4
		uint32 iramHostAccessEn: 1; // 5
		uint32 unknown1: 2;
		uint32 ucRstReleaseDelayCnt: 8; // 8
		uint32 unknown2: 16;
	};
	uint32 val;
};

// DMCU_STATUS
union DmcuStatus {
	struct {
		uint32 ucInReset: 1; // 0
		uint32 ucInWaitMode: 1; // 1
		uint32 ucInStopMode: 1; // 2
		uint32 unknown1: 29;
	};
	uint32 val;
};

// DMCU_TEST_DEBUG_DATA
union DmcuTestDebugData {
	struct {
		uint32 dmcuTestDebugData: 32; // 0
	};
	uint32 val;
};

// DMCU_TEST_DEBUG_INDEX
union DmcuTestDebugIndex {
	struct {
		uint32 dmcuTestDebugIndex: 8; // 0
		uint32 dmcuTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// DMCU_UC_CLK_GATING_CNTL
union DmcuUcClkGatingCntl {
	struct {
		uint32 ucIramRdDelay: 3; // 0
		uint32 unknown1: 5;
		uint32 ucEramRdDelay: 3; // 8
		uint32 unknown2: 5;
		uint32 ucRbbmRdClkGatingEn: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// DMCU_UC_INTERNAL_INT_STATUS
union DmcuUcInternalIntStatus {
	struct {
		uint32 ucIntIrqNPin: 1; // 0
		uint32 ucIntXirqNPin: 1; // 1
		uint32 ucIntSoftwareInterrupt: 1; // 2
		uint32 ucIntIllegalOpcodeTrap: 1; // 3
		uint32 ucIntTimerOutputCompare4: 1; // 4
		uint32 ucIntTimerOutputCompare3: 1; // 5
		uint32 ucIntTimerOutputCompare2: 1; // 6
		uint32 ucIntTimerOutputCompare1: 1; // 7
		uint32 ucIntTimerOverflow: 1; // 8
		uint32 ucIntRealTimeInterrupt: 1; // 9
		uint32 ucIntTimerInputCapture4OutputCompare5: 1; // 10
		uint32 ucIntTimerInputCapture3: 1; // 11
		uint32 ucIntTimerInputCapture2: 1; // 12
		uint32 ucIntTimerInputCapture1: 1; // 13
		uint32 ucIntPulseAccumulatorInputEdge: 1; // 14
		uint32 ucIntPulseAccumulatorOverflow: 1; // 15
		uint32 unknown1: 16;
	};
	uint32 val;
};

// DMIF_ADDR_CALC
union DmifAddrCalc {
	struct {
		uint32 unknown1: 4;
		uint32 addrConfigPipeInterleaveSize: 3; // 4
		uint32 unknown2: 21;
		uint32 addrConfigRowSize: 2; // 28
		uint32 unknown3: 2;
	};
	uint32 val;
};

// DMIF_ADDR_CONFIG
union DmifAddrConfig {
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
		uint32 unknown5: 9;
		uint32 rowSize: 2; // 28
		uint32 numLowerPipes: 1; // 30
		uint32 unknown6: 1;
	};
	uint32 val;
};

// DMIF_ARBITRATION_CONTROL
union DmifArbitrationControl {
	struct {
		uint32 dmifArbitrationReferenceClockPeriod: 16; // 0
		uint32 pipeSwitchEfficiencyWeight: 16; // 16
	};
	uint32 val;
};

// DMIF_CONTROL
union DmifControl {
	struct {
		uint32 dmifBuffSize: 2; // 0
		uint32 dmifGroupRequestsInChunk: 1; // 2
		uint32 unknown1: 1;
		uint32 dmifDisableEarlyReceivedLevelCount: 1; // 4
		uint32 unknown2: 3;
		uint32 dmifReqBurstSize: 3; // 8
		uint32 unknown3: 1;
		uint32 dmifForceTotalReqBurstSize: 4; // 12
		uint32 dmifMaxTotalOutstandingChunkRequests: 6; // 16
		uint32 unknown4: 2;
		uint32 dmifDelayArbitration: 5; // 24
		uint32 dmifChunkBuffMargin: 2; // 29
		uint32 unknown5: 1;
	};
	uint32 val;
};

// DMIF_DEBUG02_CORE0
union DmifDebug02Core0 {
	struct {
		uint32 dbData: 16; // 0
		uint32 mcRdretCountEn: 1; // 16
		uint32 mcRdretCounter: 11; // 17
		uint32 unknown1: 4;
	};
	uint32 val;
};

// DMIF_DEBUG02_CORE1
union DmifDebug02Core1 {
	struct {
		uint32 dbData: 16; // 0
		uint32 mcRdretCountEn: 1; // 16
		uint32 mcRdretCounter: 11; // 17
		uint32 unknown1: 4;
	};
	uint32 val;
};

// DMIF_HW_DEBUG
union DmifHwDebug {
	struct {
		uint32 dmifHwDebug: 32; // 0
	};
	uint32 val;
};

// DMIF_STATUS
union DmifStatus {
	struct {
		uint32 dmifMcSendOnIdle: 6; // 0
		uint32 unknown1: 2;
		uint32 dmifClearMcSendOnIdle: 6; // 8
		uint32 unknown2: 2;
		uint32 dmifMcLatencyCounterEnable: 1; // 16
		uint32 dmifMcLatencyCounterUrgentOnly: 1; // 17
		uint32 unknown3: 2;
		uint32 dmifMcLatencyCounterSourceSelect: 3; // 20
		uint32 unknown4: 1;
		uint32 dmifPerformanceCounterSourceSelect: 3; // 24
		uint32 unknown5: 1;
		uint32 dmifUnderflow: 1; // 28
		uint32 unknown6: 3;
	};
	uint32 val;
};

// DMIF_STATUS2
union DmifStatus2 {
	struct {
		uint32 dmifPipe0DispclkStatus: 1; // 0
		uint32 dmifPipe1DispclkStatus: 1; // 1
		uint32 dmifPipe2DispclkStatus: 1; // 2
		uint32 dmifPipe3DispclkStatus: 1; // 3
		uint32 dmifPipe4DispclkStatus: 1; // 4
		uint32 dmifPipe5DispclkStatus: 1; // 5
		uint32 unknown1: 2;
		uint32 dmifChunkTrackerSclkStatus: 1; // 8
		uint32 dmifFbcTrackerSclkStatus: 1; // 9
		uint32 unknown2: 22;
	};
	uint32 val;
};

// DMIF_TEST_DEBUG_DATA
union DmifTestDebugData {
	struct {
		uint32 dmifTestDebugData: 32; // 0
	};
	uint32 val;
};

// DMIF_TEST_DEBUG_INDEX
union DmifTestDebugIndex {
	struct {
		uint32 dmifTestDebugIndex: 8; // 0
		uint32 dmifTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// DOUT_DCE_VCE_CONTROL
union DoutDceVceControl {
	struct {
		uint32 dcVceVideoPipeSelect: 3; // 0
		uint32 unknown1: 1;
		uint32 dcVceAudioStreamSelect: 3; // 4
		uint32 unknown2: 25;
	};
	uint32 val;
};

// DOUT_POWER_MANAGEMENT_CNTL
union DoutPowerManagementCntl {
	struct {
		uint32 pmAssertReset: 1; // 0
		uint32 unknown1: 7;
		uint32 pmAllBusyOff: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DOUT_SCRATCH0
union DoutScratch0 {
	struct {
		uint32 doutScratch0: 32; // 0
	};
	uint32 val;
};

// DOUT_SCRATCH1
union DoutScratch1 {
	struct {
		uint32 doutScratch1: 32; // 0
	};
	uint32 val;
};

// DOUT_SCRATCH2
union DoutScratch2 {
	struct {
		uint32 doutScratch2: 32; // 0
	};
	uint32 val;
};

// DOUT_SCRATCH3
union DoutScratch3 {
	struct {
		uint32 doutScratch3: 32; // 0
	};
	uint32 val;
};

// DOUT_SCRATCH4
union DoutScratch4 {
	struct {
		uint32 doutScratch4: 32; // 0
	};
	uint32 val;
};

// DOUT_SCRATCH5
union DoutScratch5 {
	struct {
		uint32 doutScratch5: 32; // 0
	};
	uint32 val;
};

// DOUT_SCRATCH6
union DoutScratch6 {
	struct {
		uint32 doutScratch6: 32; // 0
	};
	uint32 val;
};

// DOUT_SCRATCH7
union DoutScratch7 {
	struct {
		uint32 doutScratch7: 32; // 0
	};
	uint32 val;
};

// DOUT_TEST_DEBUG_DATA
union DoutTestDebugData {
	struct {
		uint32 doutTestDebugData: 32; // 0
	};
	uint32 val;
};

// DOUT_TEST_DEBUG_INDEX
union DoutTestDebugIndex {
	struct {
		uint32 doutTestDebugIndex: 8; // 0
		uint32 doutTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// DPG_PIPE_ARBITRATION_CONTROL1
union DpgPipeArbitrationControl1 {
	struct {
		uint32 pixelDuration: 16; // 0
		uint32 baseWeight: 16; // 16
	};
	uint32 val;
};

// DPG_PIPE_ARBITRATION_CONTROL2
union DpgPipeArbitrationControl2 {
	struct {
		uint32 timeWeight: 16; // 0
		uint32 urgencyWeight: 16; // 16
	};
	uint32 val;
};

// DPG_PIPE_ARBITRATION_CONTROL3
union DpgPipeArbitrationControl3 {
	struct {
		uint32 unknown1: 16;
		uint32 urgencyWatermarkMask: 2; // 16
		uint32 unknown2: 14;
	};
	uint32 val;
};

// DPG_PIPE_DPM_CONTROL
union DpgPipeDpmControl {
	struct {
		uint32 dpmEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 mclkChangeEnable: 1; // 4
		uint32 unknown2: 3;
		uint32 mclkChangeForceOn: 1; // 8
		uint32 unknown3: 3;
		uint32 mclkChangeWatermarkMask: 2; // 12
		uint32 unknown4: 2;
		uint32 mclkChangeWatermark: 16; // 16
	};
	uint32 val;
};

// DPG_PIPE_NB_PSTATE_CHANGE_CONTROL
union DpgPipeNbPstateChangeControl {
	struct {
		uint32 nbPstateChangeEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 nbPstateChangeUrgentDuringRequest: 1; // 4
		uint32 unknown2: 3;
		uint32 nbPstateChangeNotSelfRefreshDuringRequest: 1; // 8
		uint32 nbPstateChangeForceOn: 1; // 9
		uint32 nbPstateAllowForUrgent: 1; // 10
		uint32 unknown3: 1;
		uint32 nbPstateChangeWatermarkMask: 2; // 12
		uint32 unknown4: 2;
		uint32 nbPstateChangeWatermark: 16; // 16
	};
	uint32 val;
};

// DPG_PIPE_STUTTER_CONTROL
union DpgPipeStutterControl {
	struct {
		uint32 stutterEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 stutterIgnoreCursor: 1; // 4
		uint32 stutterIgnoreIcon: 1; // 5
		uint32 stutterIgnoreVga: 1; // 6
		uint32 stutterIgnoreFbc: 1; // 7
		uint32 stutterWmHighForceOn: 1; // 8
		uint32 stutterWmHighExcludesVblank: 1; // 9
		uint32 stutterUrgentInNotSelfRefresh: 1; // 10
		uint32 stutterSelfRefreshForceOn: 1; // 11
		uint32 stutterExitSelfRefreshWatermarkMask: 2; // 12
		uint32 unknown2: 2;
		uint32 stutterExitSelfRefreshWatermark: 16; // 16
	};
	uint32 val;
};

// DPG_PIPE_STUTTER_CONTROL_NONLPTCH
union DpgPipeStutterControlNonlptch {
	struct {
		uint32 stutterEnableNonlptch: 1; // 0
		uint32 unknown1: 3;
		uint32 stutterIgnoreCursorNonlptch: 1; // 4
		uint32 stutterIgnoreIconNonlptch: 1; // 5
		uint32 stutterIgnoreVgaNonlptch: 1; // 6
		uint32 stutterIgnoreFbcNonlptch: 1; // 7
		uint32 stutterWmHighForceOnNonlptch: 1; // 8
		uint32 stutterWmHighExcludesVblankNonlptch: 1; // 9
		uint32 stutterUrgentInNotSelfRefreshNonlptch: 1; // 10
		uint32 stutterSelfRefreshForceOnNonlptch: 1; // 11
		uint32 unknown2: 20;
	};
	uint32 val;
};

// DPG_PIPE_URGENCY_CONTROL
union DpgPipeUrgencyControl {
	struct {
		uint32 urgencyLowWatermark: 16; // 0
		uint32 urgencyHighWatermark: 16; // 16
	};
	uint32 val;
};

// DPG_TEST_DEBUG_DATA
union DpgTestDebugData {
	struct {
		uint32 dpgTestDebugData: 32; // 0
	};
	uint32 val;
};

// DPG_TEST_DEBUG_INDEX
union DpgTestDebugIndex {
	struct {
		uint32 dpgTestDebugIndex: 8; // 0
		uint32 dpgTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// DP_AUX1_DEBUG_A
union DpAux1DebugA {
	struct {
		uint32 dpAux1DebugA: 32; // 0
	};
	uint32 val;
};

// DP_AUX1_DEBUG_B
union DpAux1DebugB {
	struct {
		uint32 dpAux1DebugB: 32; // 0
	};
	uint32 val;
};

// DP_AUX1_DEBUG_C
union DpAux1DebugC {
	struct {
		uint32 dpAux1DebugC: 32; // 0
	};
	uint32 val;
};

// DP_AUX1_DEBUG_D
union DpAux1DebugD {
	struct {
		uint32 dpAux1DebugD: 32; // 0
	};
	uint32 val;
};

// DP_AUX1_DEBUG_E
union DpAux1DebugE {
	struct {
		uint32 dpAux1DebugE: 32; // 0
	};
	uint32 val;
};

// DP_AUX1_DEBUG_F
union DpAux1DebugF {
	struct {
		uint32 dpAux1DebugF: 32; // 0
	};
	uint32 val;
};

// DP_AUX1_DEBUG_G
union DpAux1DebugG {
	struct {
		uint32 dpAux1DebugG: 32; // 0
	};
	uint32 val;
};

// DP_AUX1_DEBUG_H
union DpAux1DebugH {
	struct {
		uint32 dpAux1DebugH: 32; // 0
	};
	uint32 val;
};

// DP_AUX1_DEBUG_I
union DpAux1DebugI {
	struct {
		uint32 dpAux1DebugI: 32; // 0
	};
	uint32 val;
};

// DP_AUX2_DEBUG_A
union DpAux2DebugA {
	struct {
		uint32 dpAux2DebugA: 32; // 0
	};
	uint32 val;
};

// DP_AUX2_DEBUG_B
union DpAux2DebugB {
	struct {
		uint32 dpAux2DebugB: 32; // 0
	};
	uint32 val;
};

// DP_AUX2_DEBUG_C
union DpAux2DebugC {
	struct {
		uint32 dpAux2DebugC: 32; // 0
	};
	uint32 val;
};

// DP_AUX2_DEBUG_D
union DpAux2DebugD {
	struct {
		uint32 dpAux2DebugD: 32; // 0
	};
	uint32 val;
};

// DP_AUX2_DEBUG_E
union DpAux2DebugE {
	struct {
		uint32 dpAux2DebugE: 32; // 0
	};
	uint32 val;
};

// DP_AUX2_DEBUG_F
union DpAux2DebugF {
	struct {
		uint32 dpAux2DebugF: 32; // 0
	};
	uint32 val;
};

// DP_AUX2_DEBUG_G
union DpAux2DebugG {
	struct {
		uint32 dpAux2DebugG: 32; // 0
	};
	uint32 val;
};

// DP_AUX2_DEBUG_H
union DpAux2DebugH {
	struct {
		uint32 dpAux2DebugH: 32; // 0
	};
	uint32 val;
};

// DP_AUX2_DEBUG_I
union DpAux2DebugI {
	struct {
		uint32 dpAux2DebugI: 32; // 0
	};
	uint32 val;
};

// DP_AUX3_DEBUG_A
union DpAux3DebugA {
	struct {
		uint32 dpAux3DebugA: 32; // 0
	};
	uint32 val;
};

// DP_AUX3_DEBUG_B
union DpAux3DebugB {
	struct {
		uint32 dpAux3DebugB: 32; // 0
	};
	uint32 val;
};

// DP_AUX3_DEBUG_C
union DpAux3DebugC {
	struct {
		uint32 dpAux3DebugC: 32; // 0
	};
	uint32 val;
};

// DP_AUX3_DEBUG_D
union DpAux3DebugD {
	struct {
		uint32 dpAux3DebugD: 32; // 0
	};
	uint32 val;
};

// DP_AUX3_DEBUG_E
union DpAux3DebugE {
	struct {
		uint32 dpAux3DebugE: 32; // 0
	};
	uint32 val;
};

// DP_AUX3_DEBUG_F
union DpAux3DebugF {
	struct {
		uint32 dpAux3DebugF: 32; // 0
	};
	uint32 val;
};

// DP_AUX3_DEBUG_G
union DpAux3DebugG {
	struct {
		uint32 dpAux3DebugG: 32; // 0
	};
	uint32 val;
};

// DP_AUX3_DEBUG_H
union DpAux3DebugH {
	struct {
		uint32 dpAux3DebugH: 32; // 0
	};
	uint32 val;
};

// DP_AUX3_DEBUG_I
union DpAux3DebugI {
	struct {
		uint32 dpAux3DebugI: 32; // 0
	};
	uint32 val;
};

// DP_AUX4_DEBUG_A
union DpAux4DebugA {
	struct {
		uint32 dpAux4DebugA: 32; // 0
	};
	uint32 val;
};

// DP_AUX4_DEBUG_B
union DpAux4DebugB {
	struct {
		uint32 dpAux4DebugB: 32; // 0
	};
	uint32 val;
};

// DP_AUX4_DEBUG_C
union DpAux4DebugC {
	struct {
		uint32 dpAux4DebugC: 32; // 0
	};
	uint32 val;
};

// DP_AUX4_DEBUG_D
union DpAux4DebugD {
	struct {
		uint32 dpAux4DebugD: 32; // 0
	};
	uint32 val;
};

// DP_AUX4_DEBUG_E
union DpAux4DebugE {
	struct {
		uint32 dpAux4DebugE: 32; // 0
	};
	uint32 val;
};

// DP_AUX4_DEBUG_F
union DpAux4DebugF {
	struct {
		uint32 dpAux4DebugF: 32; // 0
	};
	uint32 val;
};

// DP_AUX4_DEBUG_G
union DpAux4DebugG {
	struct {
		uint32 dpAux4DebugG: 32; // 0
	};
	uint32 val;
};

// DP_AUX4_DEBUG_H
union DpAux4DebugH {
	struct {
		uint32 dpAux4DebugH: 32; // 0
	};
	uint32 val;
};

// DP_AUX4_DEBUG_I
union DpAux4DebugI {
	struct {
		uint32 dpAux4DebugI: 32; // 0
	};
	uint32 val;
};

// DP_AUX5_DEBUG_A
union DpAux5DebugA {
	struct {
		uint32 dpAux5DebugA: 32; // 0
	};
	uint32 val;
};

// DP_AUX5_DEBUG_B
union DpAux5DebugB {
	struct {
		uint32 dpAux5DebugB: 32; // 0
	};
	uint32 val;
};

// DP_AUX5_DEBUG_C
union DpAux5DebugC {
	struct {
		uint32 dpAux5DebugC: 32; // 0
	};
	uint32 val;
};

// DP_AUX5_DEBUG_D
union DpAux5DebugD {
	struct {
		uint32 dpAux5DebugD: 32; // 0
	};
	uint32 val;
};

// DP_AUX5_DEBUG_E
union DpAux5DebugE {
	struct {
		uint32 dpAux5DebugE: 32; // 0
	};
	uint32 val;
};

// DP_AUX5_DEBUG_F
union DpAux5DebugF {
	struct {
		uint32 dpAux5DebugF: 32; // 0
	};
	uint32 val;
};

// DP_AUX5_DEBUG_G
union DpAux5DebugG {
	struct {
		uint32 dpAux5DebugG: 32; // 0
	};
	uint32 val;
};

// DP_AUX5_DEBUG_H
union DpAux5DebugH {
	struct {
		uint32 dpAux5DebugH: 32; // 0
	};
	uint32 val;
};

// DP_AUX5_DEBUG_I
union DpAux5DebugI {
	struct {
		uint32 dpAux5DebugI: 32; // 0
	};
	uint32 val;
};

// DP_AUX6_DEBUG_A
union DpAux6DebugA {
	struct {
		uint32 dpAux6DebugA: 32; // 0
	};
	uint32 val;
};

// DP_AUX6_DEBUG_B
union DpAux6DebugB {
	struct {
		uint32 dpAux6DebugB: 32; // 0
	};
	uint32 val;
};

// DP_AUX6_DEBUG_C
union DpAux6DebugC {
	struct {
		uint32 dpAux6DebugC: 32; // 0
	};
	uint32 val;
};

// DP_AUX6_DEBUG_D
union DpAux6DebugD {
	struct {
		uint32 dpAux6DebugD: 32; // 0
	};
	uint32 val;
};

// DP_AUX6_DEBUG_E
union DpAux6DebugE {
	struct {
		uint32 dpAux6DebugE: 32; // 0
	};
	uint32 val;
};

// DP_AUX6_DEBUG_F
union DpAux6DebugF {
	struct {
		uint32 dpAux6DebugF: 32; // 0
	};
	uint32 val;
};

// DP_AUX6_DEBUG_G
union DpAux6DebugG {
	struct {
		uint32 dpAux6DebugG: 32; // 0
	};
	uint32 val;
};

// DP_AUX6_DEBUG_H
union DpAux6DebugH {
	struct {
		uint32 dpAux6DebugH: 32; // 0
	};
	uint32 val;
};

// DP_AUX6_DEBUG_I
union DpAux6DebugI {
	struct {
		uint32 dpAux6DebugI: 32; // 0
	};
	uint32 val;
};

// DP_CONFIG
union DpConfig {
	struct {
		uint32 dpUdiLanes: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// DP_DPHY_8B10B_CNTL
union DpDphy8b10bCntl {
	struct {
		uint32 unknown1: 8;
		uint32 dphy8b10bReset: 1; // 8
		uint32 unknown2: 7;
		uint32 dphy8b10bExtDisp: 1; // 16
		uint32 unknown3: 7;
		uint32 dphy8b10bCurDisp: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// DP_DPHY_CNTL
union DpDphyCntl {
	struct {
		uint32 dphyAtestSelLane0: 1; // 0
		uint32 dphyAtestSelLane1: 1; // 1
		uint32 dphyAtestSelLane2: 1; // 2
		uint32 dphyAtestSelLane3: 1; // 3
		uint32 unknown1: 12;
		uint32 dphyBypass: 1; // 16
		uint32 unknown2: 7;
		uint32 dphySkewBypass: 1; // 24
		uint32 unknown3: 7;
	};
	uint32 val;
};

// DP_DPHY_CRC_CNTL
union DpDphyCrcCntl {
	struct {
		uint32 dphyCrcField: 1; // 0
		uint32 unknown1: 3;
		uint32 dphyCrcSel: 2; // 4
		uint32 unknown2: 10;
		uint32 dphyCrcMask: 8; // 16
		uint32 unknown3: 8;
	};
	uint32 val;
};

// DP_DPHY_CRC_EN
union DpDphyCrcEn {
	struct {
		uint32 dphyCrcEn: 1; // 0
		uint32 unknown1: 3;
		uint32 dphyCrcContEn: 1; // 4
		uint32 unknown2: 3;
		uint32 dphyCrcResultValid: 1; // 8
		uint32 unknown3: 23;
	};
	uint32 val;
};

// DP_DPHY_CRC_MST_CNTL
union DpDphyCrcMstCntl {
	struct {
		uint32 dphyCrcMstFirstSlot: 6; // 0
		uint32 unknown1: 2;
		uint32 dphyCrcMstLastSlot: 6; // 8
		uint32 unknown2: 18;
	};
	uint32 val;
};

// DP_DPHY_CRC_MST_STATUS
union DpDphyCrcMstStatus {
	struct {
		uint32 dphyCrcMstPhaseLock: 1; // 0
		uint32 unknown1: 7;
		uint32 dphyCrcMstPhaseError: 1; // 8
		uint32 unknown2: 7;
		uint32 dphyCrcMstPhaseErrorAck: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// DP_DPHY_CRC_RESULT
union DpDphyCrcResult {
	struct {
		uint32 dphyCrcResult: 8; // 0
		uint32 dphyCrcResult1: 8; // 8
		uint32 dphyCrcResult2: 8; // 16
		uint32 dphyCrcResult3: 8; // 24
	};
	uint32 val;
};

// DP_DPHY_FAST_TRAINING
union DpDphyFastTraining {
	struct {
		uint32 dphyRxFastTrainingCapable: 1; // 0
		uint32 dphySwFastTrainingStart: 1; // 1
		uint32 dphyFastTrainingVblankEdgeDetectEn: 1; // 2
		uint32 unknown1: 5;
		uint32 dphyFastTrainingTp1Time: 12; // 8
		uint32 dphyFastTrainingTp2Time: 12; // 20
	};
	uint32 val;
};

// DP_DPHY_FAST_TRAINING_STATUS
union DpDphyFastTrainingStatus {
	struct {
		uint32 dphyFastTrainingState: 3; // 0
		uint32 unknown1: 1;
		uint32 dphyFastTrainingCompleteOccurred: 1; // 4
		uint32 unknown2: 3;
		uint32 dphyFastTrainingCompleteMask: 1; // 8
		uint32 unknown3: 3;
		uint32 dphyFastTrainingCompleteAck: 1; // 12
		uint32 unknown4: 19;
	};
	uint32 val;
};

// DP_DPHY_PRBS_CNTL
union DpDphyPrbsCntl {
	struct {
		uint32 dphyPrbsEn: 1; // 0
		uint32 unknown1: 3;
		uint32 dphyPrbsSel: 2; // 4
		uint32 unknown2: 2;
		uint32 dphyPrbsSeed: 23; // 8
		uint32 unknown3: 1;
	};
	uint32 val;
};

// DP_DPHY_SYM0
union DpDphySym0 {
	struct {
		uint32 dphySym1: 10; // 0
		uint32 dphySym2: 10; // 10
		uint32 dphySym3: 10; // 20
		uint32 unknown1: 2;
	};
	uint32 val;
};

// DP_DPHY_SYM1
union DpDphySym1 {
	struct {
		uint32 dphySym4: 10; // 0
		uint32 dphySym5: 10; // 10
		uint32 dphySym6: 10; // 20
		uint32 unknown1: 2;
	};
	uint32 val;
};

// DP_DPHY_SYM2
union DpDphySym2 {
	struct {
		uint32 dphySym7: 10; // 0
		uint32 dphySym8: 10; // 10
		uint32 unknown1: 12;
	};
	uint32 val;
};

// DP_DPHY_TRAINING_PATTERN_SEL
union DpDphyTrainingPatternSel {
	struct {
		uint32 dphyTrainingPatternSel: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// DP_DTO0_MODULO
union DpDto0Modulo {
	struct {
		uint32 dpDto0Modulo: 32; // 0
	};
	uint32 val;
};

// DP_DTO0_PHASE
union DpDto0Phase {
	struct {
		uint32 dpDto0Phase: 32; // 0
	};
	uint32 val;
};

// DP_DTO1_MODULO
union DpDto1Modulo {
	struct {
		uint32 dpDto1Modulo: 32; // 0
	};
	uint32 val;
};

// DP_DTO1_PHASE
union DpDto1Phase {
	struct {
		uint32 dpDto1Phase: 32; // 0
	};
	uint32 val;
};

// DP_DTO2_MODULO
union DpDto2Modulo {
	struct {
		uint32 dpDto2Modulo: 32; // 0
	};
	uint32 val;
};

// DP_DTO2_PHASE
union DpDto2Phase {
	struct {
		uint32 dpDto2Phase: 32; // 0
	};
	uint32 val;
};

// DP_DTO3_MODULO
union DpDto3Modulo {
	struct {
		uint32 dpDto3Modulo: 32; // 0
	};
	uint32 val;
};

// DP_DTO3_PHASE
union DpDto3Phase {
	struct {
		uint32 dpDto3Phase: 32; // 0
	};
	uint32 val;
};

// DP_DTO4_MODULO
union DpDto4Modulo {
	struct {
		uint32 dpDto4Modulo: 32; // 0
	};
	uint32 val;
};

// DP_DTO4_PHASE
union DpDto4Phase {
	struct {
		uint32 dpDto4Phase: 32; // 0
	};
	uint32 val;
};

// DP_DTO5_MODULO
union DpDto5Modulo {
	struct {
		uint32 dpDto5Modulo: 32; // 0
	};
	uint32 val;
};

// DP_DTO5_PHASE
union DpDto5Phase {
	struct {
		uint32 dpDto5Phase: 32; // 0
	};
	uint32 val;
};

// DP_HBR2_EYE_PATTERN
union DpHbr2EyePattern {
	struct {
		uint32 dpHbr2EyePatternEnable: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// DP_LINK_CNTL
union DpLinkCntl {
	struct {
		uint32 unknown1: 4;
		uint32 dpLinkTrainingComplete: 1; // 4
		uint32 unknown2: 3;
		uint32 dpLinkStatus: 1; // 8
		uint32 unknown3: 8;
		uint32 dpEmbeddedPanelMode: 1; // 17
		uint32 unknown4: 14;
	};
	uint32 val;
};

// DP_LINK_FRAMING_CNTL
union DpLinkFramingCntl {
	struct {
		uint32 dpIdleBsInterval: 18; // 0
		uint32 unknown1: 6;
		uint32 dpVbidDisable: 1; // 24
		uint32 unknown2: 3;
		uint32 dpVidEnhancedFrameMode: 1; // 28
		uint32 unknown3: 3;
	};
	uint32 val;
};

// DP_MSA_COLORIMETRY
union DpMsaColorimetry {
	struct {
		uint32 dpMsaMisc0Override: 8; // 0
		uint32 dpMsaMisc0OverrideEnable: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// DP_MSA_MISC
union DpMsaMisc {
	struct {
		uint32 unknown1: 3;
		uint32 dpMsaMisc1: 5; // 3
		uint32 dpMsaMisc2: 8; // 8
		uint32 dpMsaMisc3: 8; // 16
		uint32 dpMsaMisc4: 8; // 24
	};
	uint32 val;
};

// DP_MSA_V_TIMING_OVERRIDE1
union DpMsaVTimingOverride1 {
	struct {
		uint32 dpMsaVTimingOverrideEn: 1; // 0
		uint32 unknown1: 3;
		uint32 dpMsaVTotalOverride: 13; // 4
		uint32 unknown2: 15;
	};
	uint32 val;
};

// DP_MSA_V_TIMING_OVERRIDE2
union DpMsaVTimingOverride2 {
	struct {
		uint32 dpMsaVBlankStartOverride: 13; // 0
		uint32 unknown1: 3;
		uint32 dpMsaVBlankEndOverride: 13; // 16
		uint32 unknown2: 3;
	};
	uint32 val;
};

// DP_MSE_LINK_TIMING
union DpMseLinkTiming {
	struct {
		uint32 dpMseLinkFrame: 10; // 0
		uint32 unknown1: 6;
		uint32 dpMseLinkLine: 2; // 16
		uint32 unknown2: 14;
	};
	uint32 val;
};

// DP_MSE_MISC_CNTL
union DpMseMiscCntl {
	struct {
		uint32 dpMseBlankCode: 1; // 0
		uint32 unknown1: 3;
		uint32 dpMseTimestampMode: 1; // 4
		uint32 unknown2: 3;
		uint32 dpMseZeroEncoder: 1; // 8
		uint32 unknown3: 23;
	};
	uint32 val;
};

// DP_MSE_RATE_CNTL
union DpMseRateCntl {
	struct {
		uint32 dpMseRateY: 26; // 0
		uint32 dpMseRateX: 6; // 26
	};
	uint32 val;
};

// DP_MSE_RATE_UPDATE
union DpMseRateUpdate {
	struct {
		uint32 dpMseRateUpdatePending: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// DP_MSE_SAT0
union DpMseSat0 {
	struct {
		uint32 dpMseSatSrc0: 3; // 0
		uint32 unknown1: 5;
		uint32 dpMseSatSlotCount0: 6; // 8
		uint32 unknown2: 2;
		uint32 dpMseSatSrc1: 3; // 16
		uint32 unknown3: 5;
		uint32 dpMseSatSlotCount1: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// DP_MSE_SAT1
union DpMseSat1 {
	struct {
		uint32 dpMseSatSrc2: 3; // 0
		uint32 unknown1: 5;
		uint32 dpMseSatSlotCount2: 6; // 8
		uint32 unknown2: 2;
		uint32 dpMseSatSrc3: 3; // 16
		uint32 unknown3: 5;
		uint32 dpMseSatSlotCount3: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// DP_MSE_SAT2
union DpMseSat2 {
	struct {
		uint32 dpMseSatSrc4: 3; // 0
		uint32 unknown1: 5;
		uint32 dpMseSatSlotCount4: 6; // 8
		uint32 unknown2: 2;
		uint32 dpMseSatSrc5: 3; // 16
		uint32 unknown3: 5;
		uint32 dpMseSatSlotCount5: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// DP_MSE_SAT_UPDATE
union DpMseSatUpdate {
	struct {
		uint32 dpMseSatUpdate: 2; // 0
		uint32 unknown1: 6;
		uint32 dpMse16MtpKeepout: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DP_PIXEL_FORMAT
union DpPixelFormat {
	struct {
		uint32 dpPixelEncoding: 2; // 0
		uint32 unknown1: 6;
		uint32 dpDynRange: 1; // 8
		uint32 unknown2: 7;
		uint32 dpYcbcrRange: 1; // 16
		uint32 unknown3: 7;
		uint32 dpComponentDepth: 3; // 24
		uint32 unknown4: 5;
	};
	uint32 val;
};

// DP_SEC_AUD_M
union DpSecAudM {
	struct {
		uint32 dpSecAudM: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DP_SEC_AUD_M_READBACK
union DpSecAudMReadback {
	struct {
		uint32 dpSecAudMReadback: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DP_SEC_AUD_N
union DpSecAudN {
	struct {
		uint32 dpSecAudN: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DP_SEC_AUD_N_READBACK
union DpSecAudNReadback {
	struct {
		uint32 dpSecAudNReadback: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DP_SEC_CNTL
union DpSecCntl {
	struct {
		uint32 dpSecStreamEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 dpSecAspEnable: 1; // 4
		uint32 unknown2: 3;
		uint32 dpSecAtpEnable: 1; // 8
		uint32 unknown3: 3;
		uint32 dpSecAipEnable: 1; // 12
		uint32 unknown4: 3;
		uint32 dpSecAcmEnable: 1; // 16
		uint32 unknown5: 3;
		uint32 dpSecGsp0Enable: 1; // 20
		uint32 dpSecGsp1Enable: 1; // 21
		uint32 dpSecGsp2Enable: 1; // 22
		uint32 dpSecGsp3Enable: 1; // 23
		uint32 dpSecAviEnable: 1; // 24
		uint32 unknown6: 3;
		uint32 dpSecMpgEnable: 1; // 28
		uint32 unknown7: 3;
	};
	uint32 val;
};

// DP_SEC_CNTL1
union DpSecCntl1 {
	struct {
		uint32 dpSecIsrcEnable: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// DP_SEC_FRAMING1
union DpSecFraming1 {
	struct {
		uint32 dpSecFrameStartLocation: 12; // 0
		uint32 unknown1: 4;
		uint32 dpSecVblankTransmitWidth: 16; // 16
	};
	uint32 val;
};

// DP_SEC_FRAMING2
union DpSecFraming2 {
	struct {
		uint32 dpSecStartPosition: 16; // 0
		uint32 dpSecHblankTransmitWidth: 16; // 16
	};
	uint32 val;
};

// DP_SEC_FRAMING3
union DpSecFraming3 {
	struct {
		uint32 dpSecIdleFrameSize: 14; // 0
		uint32 unknown1: 2;
		uint32 dpSecIdleTransmitWidth: 16; // 16
	};
	uint32 val;
};

// DP_SEC_FRAMING4
union DpSecFraming4 {
	struct {
		uint32 unknown1: 20;
		uint32 dpSecCollisionStatus: 1; // 20
		uint32 unknown2: 3;
		uint32 dpSecCollisionAck: 1; // 24
		uint32 unknown3: 3;
		uint32 dpSecAudioMute: 1; // 28
		uint32 dpSecAudioMuteStatus: 1; // 29
		uint32 unknown4: 2;
	};
	uint32 val;
};

// DP_SEC_PACKET_CNTL
union DpSecPacketCntl {
	struct {
		uint32 unknown1: 1;
		uint32 dpSecAspCodingType: 3; // 1
		uint32 dpSecAspPriority: 1; // 4
		uint32 unknown2: 3;
		uint32 dpSecVersion: 6; // 8
		uint32 unknown3: 2;
		uint32 dpSecAspChannelCountOverride: 1; // 16
		uint32 unknown4: 15;
	};
	uint32 val;
};

// DP_SEC_TIMESTAMP
union DpSecTimestamp {
	struct {
		uint32 dpSecTimestampMode: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// DP_STEER_FIFO
union DpSteerFifo {
	struct {
		uint32 dpSteerFifoReset: 1; // 0
		uint32 unknown1: 3;
		uint32 dpSteerOverflowFlag: 1; // 4
		uint32 dpSteerOverflowInt: 1; // 5
		uint32 dpSteerOverflowAck: 1; // 6
		uint32 dpSteerOverflowMask: 1; // 7
		uint32 dpTuOverflowFlag: 1; // 8
		uint32 unknown2: 3;
		uint32 dpTuOverflowAck: 1; // 12
		uint32 unknown3: 19;
	};
	uint32 val;
};

// DP_TEST_DEBUG_DATA
union DpTestDebugData {
	struct {
		uint32 dpTestDebugData: 32; // 0
	};
	uint32 val;
};

// DP_TEST_DEBUG_INDEX
union DpTestDebugIndex {
	struct {
		uint32 dpTestDebugIndex: 8; // 0
		uint32 dpTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// DP_VID_INTERRUPT_CNTL
union DpVidInterruptCntl {
	struct {
		uint32 dpVidStreamDisableInt: 1; // 0
		uint32 dpVidStreamDisableAck: 1; // 1
		uint32 dpVidStreamDisableMask: 1; // 2
		uint32 unknown1: 29;
	};
	uint32 val;
};

// DP_VID_M
union DpVidM {
	struct {
		uint32 dpVidM: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DP_VID_MSA_VBID
union DpVidMsaVbid {
	struct {
		uint32 dpVidMsaLocation: 12; // 0
		uint32 unknown1: 4;
		uint32 dpVidMsaTopFieldMode: 1; // 16
		uint32 unknown2: 7;
		uint32 dpVidVbidFieldPol: 1; // 24
		uint32 unknown3: 7;
	};
	uint32 val;
};

// DP_VID_N
union DpVidN {
	struct {
		uint32 dpVidN: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// DP_VID_STREAM_CNTL
union DpVidStreamCntl {
	struct {
		uint32 dpVidStreamEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 dpVidStreamDisDefer: 2; // 8
		uint32 unknown2: 6;
		uint32 dpVidStreamStatus: 1; // 16
		uint32 unknown3: 3;
		uint32 dpVidStreamChangeKeepout: 1; // 20
		uint32 unknown4: 11;
	};
	uint32 val;
};

// DP_VID_TIMING
union DpVidTiming {
	struct {
		uint32 dpVidTimingMode: 1; // 0
		uint32 unknown1: 7;
		uint32 dpVidMNGenEn: 1; // 8
		uint32 unknown2: 15;
		uint32 dpVidNDiv: 8; // 24
	};
	uint32 val;
};

// DVOACLKC_CNTL
union DvoaclkcCntl {
	struct {
		uint32 dvoaclkcFineSkewCntl: 3; // 0
		uint32 unknown1: 5;
		uint32 dvoaclkcCoarseSkewCntl: 5; // 8
		uint32 unknown2: 3;
		uint32 dvoaclkcFineAdjustEn: 1; // 16
		uint32 dvoaclkcCoarseAdjustEn: 1; // 17
		uint32 dvoaclkcInPhase: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// DVOACLKC_MVP_CNTL
union DvoaclkcMvpCntl {
	struct {
		uint32 dvoaclkcMvpFineSkewCntl: 3; // 0
		uint32 unknown1: 5;
		uint32 dvoaclkcMvpCoarseSkewCntl: 5; // 8
		uint32 unknown2: 3;
		uint32 dvoaclkcMvpFineAdjustEn: 1; // 16
		uint32 dvoaclkcMvpCoarseAdjustEn: 1; // 17
		uint32 dvoaclkcMvpInPhase: 1; // 18
		uint32 unknown3: 1;
		uint32 dvoaclkcMvpSkewPhaseOverride: 1; // 20
		uint32 unknown4: 3;
		uint32 mvpClkASrcSel: 2; // 24
		uint32 unknown5: 2;
		uint32 mvpClkBSrcSel: 2; // 28
		uint32 unknown6: 2;
	};
	uint32 val;
};

// DVOACLKD_CNTL
union DvoaclkdCntl {
	struct {
		uint32 dvoaclkdFineSkewCntl: 3; // 0
		uint32 unknown1: 5;
		uint32 dvoaclkdCoarseSkewCntl: 5; // 8
		uint32 unknown2: 3;
		uint32 dvoaclkdFineAdjustEn: 1; // 16
		uint32 dvoaclkdCoarseAdjustEn: 1; // 17
		uint32 dvoaclkdInPhase: 1; // 18
		uint32 unknown3: 13;
	};
	uint32 val;
};

// DVO_CLK_ENABLE
union DvoClkEnable {
	struct {
		uint32 dvoClkEnable: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// DVO_CONTROL
union DvoControl {
	struct {
		uint32 dvoRateSelect: 1; // 0
		uint32 dvoSdrclkSel: 1; // 1
		uint32 unknown1: 6;
		uint32 dvoDualChannelEn: 1; // 8
		uint32 unknown2: 7;
		uint32 dvoResetFifo: 1; // 16
		uint32 dvoSyncPhase: 1; // 17
		uint32 dvoInvertDvoclk: 1; // 18
		uint32 unknown3: 5;
		uint32 dvoColorFormat: 2; // 24
		uint32 unknown4: 5;
		uint32 dvoCtl3: 1; // 31
	};
	uint32 val;
};

// DVO_CRC2_SIG_MASK
union DvoCrc2SigMask {
	struct {
		uint32 dvoCrc2SigMask: 27; // 0
		uint32 unknown1: 5;
	};
	uint32 val;
};

// DVO_CRC2_SIG_RESULT
union DvoCrc2SigResult {
	struct {
		uint32 dvoCrc2SigResult: 27; // 0
		uint32 unknown1: 5;
	};
	uint32 val;
};

// DVO_CRC_EN
union DvoCrcEn {
	struct {
		uint32 unknown1: 16;
		uint32 dvoCrc2En: 1; // 16
		uint32 unknown2: 15;
	};
	uint32 val;
};

// DVO_ENABLE
union DvoEnable {
	struct {
		uint32 dvoEnable: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// DVO_FIFO_ERROR_STATUS
union DvoFifoErrorStatus {
	struct {
		uint32 dvoFifoLevelError: 1; // 0
		uint32 dvoFifoUseOverwriteLevel: 1; // 1
		uint32 dvoFifoOverwriteLevel: 6; // 2
		uint32 dvoFifoErrorAck: 1; // 8
		uint32 unknown1: 1;
		uint32 dvoFifoCalAverageLevel: 6; // 10
		uint32 dvoFifoMaximumLevel: 4; // 16
		uint32 unknown2: 2;
		uint32 dvoFifoMinimumLevel: 4; // 22
		uint32 unknown3: 3;
		uint32 dvoFifoCalibrated: 1; // 29
		uint32 dvoFifoForceRecalAverage: 1; // 30
		uint32 dvoFifoForceRecompMinmax: 1; // 31
	};
	uint32 val;
};

// DVO_OUTPUT
union DvoOutput {
	struct {
		uint32 dvoOutputEnableMode: 2; // 0
		uint32 unknown1: 6;
		uint32 dvoClockMode: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// DVO_SKEW_ADJUST
union DvoSkewAdjust {
	struct {
		uint32 dvoSkewAdjust: 32; // 0
	};
	uint32 val;
};

// DVO_SOURCE_SELECT
union DvoSourceSelect {
	struct {
		uint32 dvoSourceSelect: 3; // 0
		uint32 unknown1: 13;
		uint32 dvoStereosyncSelect: 3; // 16
		uint32 unknown2: 13;
	};
	uint32 val;
};

// DVO_STRENGTH_CONTROL
union DvoStrengthControl {
	struct {
		uint32 dvoSp: 4; // 0
		uint32 dvoSn: 4; // 4
		uint32 dvoclkSp: 4; // 8
		uint32 dvoclkSn: 4; // 12
		uint32 unknown1: 12;
		uint32 dvoLsbVmode: 1; // 28
		uint32 dvoMsbVmode: 1; // 29
		uint32 unknown2: 2;
	};
	uint32 val;
};

// DVO_VREF_CONTROL
union DvoVrefControl {
	struct {
		uint32 dvoVrefpon: 1; // 0
		uint32 dvoVrefsel: 1; // 1
		uint32 unknown1: 2;
		uint32 dvoVrefcal: 4; // 4
		uint32 unknown2: 24;
	};
	uint32 val;
};

// EXT_OVERSCAN_LEFT_RIGHT
union ExtOverscanLeftRight {
	struct {
		uint32 extOverscanRight: 12; // 0
		uint32 unknown1: 4;
		uint32 extOverscanLeft: 12; // 16
		uint32 unknown2: 4;
	};
	uint32 val;
};

// EXT_OVERSCAN_TOP_BOTTOM
union ExtOverscanTopBottom {
	struct {
		uint32 extOverscanBottom: 12; // 0
		uint32 unknown1: 4;
		uint32 extOverscanTop: 12; // 16
		uint32 unknown2: 4;
	};
	uint32 val;
};

// FBC_CLIENT_REGION_MASK
union FbcClientRegionMask {
	struct {
		uint32 unknown1: 16;
		uint32 fbcMemoryRegionMask: 4; // 16
		uint32 unknown2: 12;
	};
	uint32 val;
};

// FBC_CNTL
union FbcCntl {
	struct {
		uint32 fbcGrphCompEn: 1; // 0
		uint32 fbcSrcSel: 3; // 1
		uint32 unknown1: 12;
		uint32 fbcCoherencyMode: 2; // 16
		uint32 unknown2: 7;
		uint32 fbcSoftCompressEn: 1; // 25
		uint32 unknown3: 5;
		uint32 fbcEn: 1; // 31
	};
	uint32 val;
};

// FBC_COMP_CNTL
union FbcCompCntl {
	struct {
		uint32 fbcMinCompression: 4; // 0
		uint32 unknown1: 12;
		uint32 fbcDepthMono08En: 1; // 16
		uint32 fbcDepthMono16En: 1; // 17
		uint32 fbcDepthRgb04En: 1; // 18
		uint32 fbcDepthRgb08En: 1; // 19
		uint32 fbcDepthRgb16En: 1; // 20
		uint32 unknown2: 11;
	};
	uint32 val;
};

// FBC_COMP_MODE
union FbcCompMode {
	struct {
		uint32 fbcRleEn: 1; // 0
		uint32 unknown1: 7;
		uint32 fbcDpcm4RgbEn: 1; // 8
		uint32 fbcDpcm8RgbEn: 1; // 9
		uint32 fbcDpcm4YuvEn: 1; // 10
		uint32 fbcDpcm8YuvEn: 1; // 11
		uint32 unknown2: 4;
		uint32 fbcIndEn: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// FBC_CSM_REGION_OFFSET_01
union FbcCsmRegionOffset01 {
	struct {
		uint32 fbcCsmRegionOffset0: 10; // 0
		uint32 unknown1: 6;
		uint32 fbcCsmRegionOffset1: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// FBC_CSM_REGION_OFFSET_23
union FbcCsmRegionOffset23 {
	struct {
		uint32 fbcCsmRegionOffset2: 10; // 0
		uint32 unknown1: 6;
		uint32 fbcCsmRegionOffset3: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// FBC_DEBUG0
union FbcDebug0 {
	struct {
		uint32 fbcPerfMux0: 8; // 0
		uint32 fbcPerfMux1: 8; // 8
		uint32 fbcCompWakeDis: 1; // 16
		uint32 fbcDebug0: 7; // 17
		uint32 fbcDebugMux: 8; // 24
	};
	uint32 val;
};

// FBC_DEBUG1
union FbcDebug1 {
	struct {
		uint32 fbcDebug1: 32; // 0
	};
	uint32 val;
};

// FBC_DEBUG2
union FbcDebug2 {
	struct {
		uint32 fbcDebug2: 32; // 0
	};
	uint32 val;
};

// FBC_DEBUG_COMP
union FbcDebugComp {
	struct {
		uint32 fbcCompSwap: 2; // 0
		uint32 unknown1: 1;
		uint32 fbcCompRsize: 1; // 3
		uint32 fbcCompBusyHysteresis: 4; // 4
		uint32 fbcCompClkCntl: 2; // 8
		uint32 fbcCompPrivilegedAccessEnable: 1; // 10
		uint32 fbcCompAddressTranslationEnable: 1; // 11
		uint32 unknown2: 20;
	};
	uint32 val;
};

// FBC_DEBUG_CSR
union FbcDebugCsr {
	struct {
		uint32 fbcDebugCsrAddr: 10; // 0
		uint32 unknown1: 6;
		uint32 fbcDebugCsrWrData: 1; // 16
		uint32 fbcDebugCsrRdData: 1; // 17
		uint32 unknown2: 13;
		uint32 fbcDebugCsrEn: 1; // 31
	};
	uint32 val;
};

// FBC_DEBUG_CSR_RDATA
union FbcDebugCsrRdata {
	struct {
		uint32 fbcDebugCsrRdata: 32; // 0
	};
	uint32 val;
};

// FBC_DEBUG_CSR_RDATA_HI
union FbcDebugCsrRdataHi {
	struct {
		uint32 fbcDebugCsrRdataHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// FBC_DEBUG_CSR_WDATA
union FbcDebugCsrWdata {
	struct {
		uint32 fbcDebugCsrWdata: 32; // 0
	};
	uint32 val;
};

// FBC_DEBUG_CSR_WDATA_HI
union FbcDebugCsrWdataHi {
	struct {
		uint32 fbcDebugCsrWdataHi: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// FBC_IDLE_FORCE_CLEAR_MASK
union FbcIdleForceClearMask {
	struct {
		uint32 fbcIdleForceClearMask: 32; // 0
	};
	uint32 val;
};

// FBC_IDLE_MASK
union FbcIdleMask {
	struct {
		uint32 fbcIdleMask: 32; // 0
	};
	uint32 val;
};

// FBC_IND_LUT0
union FbcIndLut0 {
	struct {
		uint32 fbcIndLut0: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT1
union FbcIndLut1 {
	struct {
		uint32 fbcIndLut1: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT10
union FbcIndLut10 {
	struct {
		uint32 fbcIndLut10: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT11
union FbcIndLut11 {
	struct {
		uint32 fbcIndLut11: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT12
union FbcIndLut12 {
	struct {
		uint32 fbcIndLut12: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT13
union FbcIndLut13 {
	struct {
		uint32 fbcIndLut13: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT14
union FbcIndLut14 {
	struct {
		uint32 fbcIndLut14: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT15
union FbcIndLut15 {
	struct {
		uint32 fbcIndLut15: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT2
union FbcIndLut2 {
	struct {
		uint32 fbcIndLut2: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT3
union FbcIndLut3 {
	struct {
		uint32 fbcIndLut3: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT4
union FbcIndLut4 {
	struct {
		uint32 fbcIndLut4: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT5
union FbcIndLut5 {
	struct {
		uint32 fbcIndLut5: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT6
union FbcIndLut6 {
	struct {
		uint32 fbcIndLut6: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT7
union FbcIndLut7 {
	struct {
		uint32 fbcIndLut7: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT8
union FbcIndLut8 {
	struct {
		uint32 fbcIndLut8: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_IND_LUT9
union FbcIndLut9 {
	struct {
		uint32 fbcIndLut9: 24; // 0
		uint32 unknown1: 8;
	};
	uint32 val;
};

// FBC_MISC
union FbcMisc {
	struct {
		uint32 fbcDecompressError: 2; // 0
		uint32 fbcStopOnError: 1; // 2
		uint32 fbcInvalidateOnError: 1; // 3
		uint32 fbcErrorPixel: 4; // 4
		uint32 fbcDivideX: 2; // 8
		uint32 fbcDivideY: 1; // 10
		uint32 fbcRsmWriteValue: 1; // 11
		uint32 fbcRsmUncompDataImmediately: 1; // 12
		uint32 unknown1: 3;
		uint32 fbcDecompressErrorClear: 1; // 16
		uint32 unknown2: 3;
		uint32 fbcResetAtEnable: 1; // 20
		uint32 fbcResetAtDisable: 1; // 21
		uint32 unknown3: 6;
		uint32 fbcSlowReqInterval: 4; // 28
	};
	uint32 val;
};

// FBC_START_STOP_DELAY
union FbcStartStopDelay {
	struct {
		uint32 fbcDecompStartDelay: 5; // 0
		uint32 unknown1: 2;
		uint32 fbcDecompStopDelay: 1; // 7
		uint32 fbcCompStartDelay: 5; // 8
		uint32 unknown2: 19;
	};
	uint32 val;
};

// FBC_STATUS
union FbcStatus {
	struct {
		uint32 fbcEnableStatus: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// FBC_TEST_DEBUG_DATA
union FbcTestDebugData {
	struct {
		uint32 fbcTestDebugData: 32; // 0
	};
	uint32 val;
};

// FBC_TEST_DEBUG_INDEX
union FbcTestDebugIndex {
	struct {
		uint32 fbcTestDebugIndex: 8; // 0
		uint32 fbcTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// FMT_BIT_DEPTH_CONTROL
union FmtBitDepthControl {
	struct {
		uint32 fmtTruncateEn: 1; // 0
		uint32 unknown1: 3;
		uint32 fmtTruncateDepth: 1; // 4
		uint32 unknown2: 3;
		uint32 fmtSpatialDitherEn: 1; // 8
		uint32 fmtSpatialDitherMode: 2; // 9
		uint32 unknown3: 1;
		uint32 fmtSpatialDitherDepth: 1; // 12
		uint32 fmtFrameRandomEnable: 1; // 13
		uint32 fmtRgbRandomEnable: 1; // 14
		uint32 fmtHighpassRandomEnable: 1; // 15
		uint32 fmtTemporalDitherEn: 1; // 16
		uint32 unknown4: 3;
		uint32 fmtTemporalDitherDepth: 1; // 20
		uint32 fmtTemporalDitherOffset: 2; // 21
		uint32 unknown5: 1;
		uint32 fmtTemporalLevel: 1; // 24
		uint32 fmtTemporalDitherReset: 1; // 25
		uint32 fmt25frcSel: 2; // 26
		uint32 fmt50frcSel: 2; // 28
		uint32 fmt75frcSel: 2; // 30
	};
	uint32 val;
};

// FMT_CLAMP_CNTL
union FmtClampCntl {
	struct {
		uint32 fmtClampDataEn: 1; // 0
		uint32 unknown1: 15;
		uint32 fmtClampColorFormat: 3; // 16
		uint32 unknown2: 13;
	};
	uint32 val;
};

// FMT_CONTROL
union FmtControl {
	struct {
		uint32 fmtStereosyncOverride: 1; // 0
		uint32 unknown1: 3;
		uint32 fmtStereosyncOvrPol: 1; // 4
		uint32 unknown2: 11;
		uint32 fmtPixelEncoding: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// FMT_CRC_CNTL
union FmtCrcCntl {
	struct {
		uint32 fmtCrcEn: 1; // 0
		uint32 unknown1: 3;
		uint32 fmtCrcContEn: 1; // 4
		uint32 unknown2: 3;
		uint32 fmtCrcOnlyBlankb: 1; // 8
		uint32 unknown3: 3;
		uint32 fmtCrcInterlaceMode: 2; // 12
		uint32 unknown4: 2;
		uint32 fmtCrcUseNewAndRepeatedPixels: 1; // 16
		uint32 unknown5: 3;
		uint32 fmtCrcEvenOddPixEnable: 1; // 20
		uint32 unknown6: 3;
		uint32 fmtCrcEvenOddPixSelect: 1; // 24
		uint32 unknown7: 7;
	};
	uint32 val;
};

// FMT_CRC_SIG_BLUE_CONTROL
union FmtCrcSigBlueControl {
	struct {
		uint32 fmtCrcSigBlue: 16; // 0
		uint32 fmtCrcSigControl: 16; // 16
	};
	uint32 val;
};

// FMT_CRC_SIG_BLUE_CONTROL_MASK
union FmtCrcSigBlueControlMask {
	struct {
		uint32 fmtCrcSigBlueMask: 16; // 0
		uint32 fmtCrcSigControlMask: 16; // 16
	};
	uint32 val;
};

// FMT_CRC_SIG_RED_GREEN
union FmtCrcSigRedGreen {
	struct {
		uint32 fmtCrcSigRed: 16; // 0
		uint32 fmtCrcSigGreen: 16; // 16
	};
	uint32 val;
};

// FMT_CRC_SIG_RED_GREEN_MASK
union FmtCrcSigRedGreenMask {
	struct {
		uint32 fmtCrcSigRedMask: 16; // 0
		uint32 fmtCrcSigGreenMask: 16; // 16
	};
	uint32 val;
};

// FMT_DEBUG0
union FmtDebug0 {
	struct {
		uint32 fmtDebug0: 32; // 0
	};
	uint32 val;
};

// FMT_DEBUG1
union FmtDebug1 {
	struct {
		uint32 fmtDebug1: 32; // 0
	};
	uint32 val;
};

// FMT_DEBUG2
union FmtDebug2 {
	struct {
		uint32 fmtDebug2: 32; // 0
	};
	uint32 val;
};

// FMT_DEBUG_CNTL
union FmtDebugCntl {
	struct {
		uint32 fmtDebugColorSelect: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// FMT_DEBUG_ID
union FmtDebugId {
	struct {
		uint32 fmtDebugId: 32; // 0
	};
	uint32 val;
};

// FMT_DITHER_RAND_B_SEED
union FmtDitherRandBSeed {
	struct {
		uint32 fmtRandBSeed: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// FMT_DITHER_RAND_G_SEED
union FmtDitherRandGSeed {
	struct {
		uint32 fmtRandGSeed: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// FMT_DITHER_RAND_R_SEED
union FmtDitherRandRSeed {
	struct {
		uint32 fmtRandRSeed: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// FMT_DYNAMIC_EXP_CNTL
union FmtDynamicExpCntl {
	struct {
		uint32 fmtDynamicExpEn: 1; // 0
		uint32 unknown1: 3;
		uint32 fmtDynamicExpMode: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// FMT_FORCE_DATA_0_1
union FmtForceData0_1 {
	struct {
		uint32 fmtForceData0: 16; // 0
		uint32 fmtForceData1: 16; // 16
	};
	uint32 val;
};

// FMT_FORCE_DATA_2_3
union FmtForceData2_3 {
	struct {
		uint32 fmtForceData2: 16; // 0
		uint32 fmtForceData3: 16; // 16
	};
	uint32 val;
};

// FMT_FORCE_OUTPUT_CNTL
union FmtForceOutputCntl {
	struct {
		uint32 fmtForceDataEn: 1; // 0
		uint32 unknown1: 7;
		uint32 fmtForceDataSelColor: 3; // 8
		uint32 unknown2: 1;
		uint32 fmtForceDataSelSlot: 4; // 12
		uint32 fmtForceDataOnBlankbOnly: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// FMT_TEMPORAL_DITHER_PATTERN_CONTROL
union FmtTemporalDitherPatternControl {
	struct {
		uint32 fmtTemporalDitherProgrammablePatternSelect: 1; // 0
		uint32 unknown1: 3;
		uint32 fmtTemporalDitherProgrammablePatternRgb1Bgr0: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_S_MATRIX
union FmtTemporalDitherProgrammablePatternSMatrix {
	struct {
		uint32 fmtTemporalDitherProgrammablePatternSMatrix: 32; // 0
	};
	uint32 val;
};

// FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_T_MATRIX
union FmtTemporalDitherProgrammablePatternTMatrix {
	struct {
		uint32 fmtTemporalDitherProgrammablePatternTMatrix: 32; // 0
	};
	uint32 val;
};

// FMT_TEST_DEBUG_DATA
union FmtTestDebugData {
	struct {
		uint32 fmtTestDebugData: 32; // 0
	};
	uint32 val;
};

// FMT_TEST_DEBUG_INDEX
union FmtTestDebugIndex {
	struct {
		uint32 fmtTestDebugIndex: 8; // 0
		uint32 fmtTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// GAMUT_REMAP_C11_C12
union GamutRemapC11C12 {
	struct {
		uint32 gamutRemapC11: 16; // 0
		uint32 gamutRemapC12: 16; // 16
	};
	uint32 val;
};

// GAMUT_REMAP_C13_C14
union GamutRemapC13C14 {
	struct {
		uint32 gamutRemapC13: 16; // 0
		uint32 gamutRemapC14: 16; // 16
	};
	uint32 val;
};

// GAMUT_REMAP_C21_C22
union GamutRemapC21C22 {
	struct {
		uint32 gamutRemapC21: 16; // 0
		uint32 gamutRemapC22: 16; // 16
	};
	uint32 val;
};

// GAMUT_REMAP_C23_C24
union GamutRemapC23C24 {
	struct {
		uint32 gamutRemapC23: 16; // 0
		uint32 gamutRemapC24: 16; // 16
	};
	uint32 val;
};

// GAMUT_REMAP_C31_C32
union GamutRemapC31C32 {
	struct {
		uint32 gamutRemapC31: 16; // 0
		uint32 gamutRemapC32: 16; // 16
	};
	uint32 val;
};

// GAMUT_REMAP_C33_C34
union GamutRemapC33C34 {
	struct {
		uint32 gamutRemapC33: 16; // 0
		uint32 gamutRemapC34: 16; // 16
	};
	uint32 val;
};

// GAMUT_REMAP_CONTROL
union GamutRemapControl {
	struct {
		uint32 grphGamutRemapMode: 2; // 0
		uint32 unknown1: 2;
		uint32 ovlGamutRemapMode: 2; // 4
		uint32 unknown2: 26;
	};
	uint32 val;
};

// GENENB
union Genenb {
	struct {
		uint32 blkIoBase: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// GENERIC_I2C_CONTROL
union GenericI2cControl {
	struct {
		uint32 genericI2cGo: 1; // 0
		uint32 genericI2cSoftReset: 1; // 1
		uint32 genericI2cSendReset: 1; // 2
		uint32 genericI2cEnable: 1; // 3
		uint32 unknown1: 27;
		uint32 genericI2cDbgRefSel: 1; // 31
	};
	uint32 val;
};

// GENERIC_I2C_DATA
union GenericI2cData {
	struct {
		uint32 genericI2cDataRw: 1; // 0
		uint32 unknown1: 7;
		uint32 genericI2cData: 8; // 8
		uint32 genericI2cIndex: 4; // 16
		uint32 unknown2: 11;
		uint32 genericI2cIndexWrite: 1; // 31
	};
	uint32 val;
};

// GENERIC_I2C_INTERRUPT_CONTROL
union GenericI2cInterruptControl {
	struct {
		uint32 genericI2cDoneInt: 1; // 0
		uint32 genericI2cDoneAck: 1; // 1
		uint32 genericI2cDoneMask: 1; // 2
		uint32 unknown1: 29;
	};
	uint32 val;
};

// GENERIC_I2C_PIN_DEBUG
union GenericI2cPinDebug {
	struct {
		uint32 genericI2cSclOutput: 1; // 0
		uint32 genericI2cSclInput: 1; // 1
		uint32 genericI2cSclEn: 1; // 2
		uint32 unknown1: 1;
		uint32 genericI2cSdaOutput: 1; // 4
		uint32 genericI2cSdaInput: 1; // 5
		uint32 genericI2cSdaEn: 1; // 6
		uint32 unknown2: 25;
	};
	uint32 val;
};

// GENERIC_I2C_PIN_SELECTION
union GenericI2cPinSelection {
	struct {
		uint32 genericI2cSclPinSel: 7; // 0
		uint32 unknown1: 1;
		uint32 genericI2cSdaPinSel: 7; // 8
		uint32 unknown2: 17;
	};
	uint32 val;
};

// GENERIC_I2C_SETUP
union GenericI2cSetup {
	struct {
		uint32 genericI2cDataDriveEn: 1; // 0
		uint32 genericI2cDataDriveSel: 1; // 1
		uint32 unknown1: 5;
		uint32 genericI2cClkDriveEn: 1; // 7
		uint32 genericI2cIntraByteDelay: 8; // 8
		uint32 unknown2: 8;
		uint32 genericI2cTimeLimit: 8; // 24
	};
	uint32 val;
};

// GENERIC_I2C_SPEED
union GenericI2cSpeed {
	struct {
		uint32 genericI2cThreshold: 2; // 0
		uint32 unknown1: 2;
		uint32 genericI2cDisableFilterDuringStall: 1; // 4
		uint32 unknown2: 11;
		uint32 genericI2cPrescale: 16; // 16
	};
	uint32 val;
};

// GENERIC_I2C_STATUS
union GenericI2cStatus {
	struct {
		uint32 genericI2cStatus: 4; // 0
		uint32 genericI2cDone: 1; // 4
		uint32 genericI2cAborted: 1; // 5
		uint32 genericI2cTimeout: 1; // 6
		uint32 unknown1: 2;
		uint32 genericI2cStoppedOnNack: 1; // 9
		uint32 genericI2cNack: 1; // 10
		uint32 unknown2: 21;
	};
	uint32 val;
};

// GENERIC_I2C_TRANSACTION
union GenericI2cTransaction {
	struct {
		uint32 genericI2cRw: 1; // 0
		uint32 unknown1: 7;
		uint32 genericI2cStopOnNack: 1; // 8
		uint32 genericI2cAckOnRead: 1; // 9
		uint32 unknown2: 2;
		uint32 genericI2cStart: 1; // 12
		uint32 genericI2cStop: 1; // 13
		uint32 unknown3: 2;
		uint32 genericI2cCount: 4; // 16
		uint32 unknown4: 12;
	};
	uint32 val;
};

// GENFC_RD
union GenfcRd {
	struct {
		uint32 unknown1: 3;
		uint32 vsyncSelR: 1; // 3
		uint32 unknown2: 28;
	};
	uint32 val;
};

// GENFC_WT
union GenfcWt {
	struct {
		uint32 unknown1: 3;
		uint32 vsyncSelW: 1; // 3
		uint32 unknown2: 28;
	};
	uint32 val;
};

// GENMO_RD
union GenmoRd {
	struct {
		uint32 genmoMonoAddressB: 1; // 0
		uint32 vgaRamEn: 1; // 1
		uint32 vgaCksel: 2; // 2
		uint32 unknown1: 1;
		uint32 oddEvenMdPgsel: 1; // 5
		uint32 vgaHsyncPol: 1; // 6
		uint32 vgaVsyncPol: 1; // 7
		uint32 unknown2: 24;
	};
	uint32 val;
};

// GENMO_WT
union GenmoWt {
	struct {
		uint32 genmoMonoAddressB: 1; // 0
		uint32 vgaRamEn: 1; // 1
		uint32 vgaCksel: 2; // 2
		uint32 unknown1: 1;
		uint32 oddEvenMdPgsel: 1; // 5
		uint32 vgaHsyncPol: 1; // 6
		uint32 vgaVsyncPol: 1; // 7
		uint32 unknown2: 24;
	};
	uint32 val;
};

// GENS0
union Gens0 {
	struct {
		uint32 unknown1: 4;
		uint32 senseSwitch: 1; // 4
		uint32 unknown2: 2;
		uint32 crtIntr: 1; // 7
		uint32 unknown3: 24;
	};
	uint32 val;
};

// GENS1
union Gens1 {
	struct {
		uint32 noDisplay: 1; // 0
		uint32 unknown1: 2;
		uint32 vgaVstatus: 1; // 3
		uint32 pixelReadBack: 2; // 4
		uint32 unknown2: 26;
	};
	uint32 val;
};

// GRA00
union Gra00 {
	struct {
		uint32 grphSetReset0: 1; // 0
		uint32 grphSetReset1: 1; // 1
		uint32 grphSetReset2: 1; // 2
		uint32 grphSetReset3: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// GRA01
union Gra01 {
	struct {
		uint32 grphSetResetEna0: 1; // 0
		uint32 grphSetResetEna1: 1; // 1
		uint32 grphSetResetEna2: 1; // 2
		uint32 grphSetResetEna3: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// GRA02
union Gra02 {
	struct {
		uint32 grphCcomp: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// GRA03
union Gra03 {
	struct {
		uint32 grphRotate: 3; // 0
		uint32 grphFnSel: 2; // 3
		uint32 unknown1: 27;
	};
	uint32 val;
};

// GRA04
union Gra04 {
	struct {
		uint32 grphRmap: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// GRA05
union Gra05 {
	struct {
		uint32 grphWriteMode: 2; // 0
		uint32 unknown1: 1;
		uint32 grphRead1: 1; // 3
		uint32 cgaOddeven: 1; // 4
		uint32 grphOes: 1; // 5
		uint32 grphPack: 1; // 6
		uint32 unknown2: 25;
	};
	uint32 val;
};

// GRA06
union Gra06 {
	struct {
		uint32 grphGraphics: 1; // 0
		uint32 grphOddeven: 1; // 1
		uint32 grphAdrsel: 2; // 2
		uint32 unknown1: 28;
	};
	uint32 val;
};

// GRA07
union Gra07 {
	struct {
		uint32 grphXcare0: 1; // 0
		uint32 grphXcare1: 1; // 1
		uint32 grphXcare2: 1; // 2
		uint32 grphXcare3: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// GRA08
union Gra08 {
	struct {
		uint32 grphBmsk: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// GRPH8_DATA
union Grph8Data {
	struct {
		uint32 grphData: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// GRPH8_IDX
union Grph8Idx {
	struct {
		uint32 grphIdx: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// GRPH_COMPRESS_PITCH
union GrphCompressPitch {
	struct {
		uint32 unknown1: 6;
		uint32 grphCompressPitch: 11; // 6
		uint32 unknown2: 15;
	};
	uint32 val;
};

// GRPH_COMPRESS_SURFACE_ADDRESS
union GrphCompressSurfaceAddress {
	struct {
		uint32 unknown1: 8;
		uint32 grphCompressSurfaceAddress: 24; // 8
	};
	uint32 val;
};

// GRPH_COMPRESS_SURFACE_ADDRESS_HIGH
union GrphCompressSurfaceAddressHigh {
	struct {
		uint32 grphCompressSurfaceAddressHigh: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// GRPH_CONTROL
union GrphControl {
	struct {
		uint32 grphDepth: 2; // 0
		uint32 grphNumBanks: 2; // 2
		uint32 grphZ: 2; // 4
		uint32 grphBankWidth: 2; // 6
		uint32 grphFormat: 3; // 8
		uint32 grphBankHeight: 2; // 11
		uint32 grphTileSplit: 3; // 13
		uint32 grphAddressTranslationEnable: 1; // 16
		uint32 grphPrivilegedAccessEnable: 1; // 17
		uint32 grphMacroTileAspect: 2; // 18
		uint32 grphArrayMode: 4; // 20
		uint32 grphPipeConfig: 5; // 24
		uint32 unknown1: 2;
		uint32 grphColorExpansionMode: 1; // 31
	};
	uint32 val;
};

// GRPH_DFQ_CONTROL
union GrphDfqControl {
	struct {
		uint32 grphDfqReset: 1; // 0
		uint32 unknown1: 3;
		uint32 grphDfqSize: 3; // 4
		uint32 unknown2: 1;
		uint32 grphDfqMinFreeEntries: 3; // 8
		uint32 unknown3: 21;
	};
	uint32 val;
};

// GRPH_DFQ_STATUS
union GrphDfqStatus {
	struct {
		uint32 grphPrimaryDfqNumEntries: 4; // 0
		uint32 grphSecondaryDfqNumEntries: 4; // 4
		uint32 grphDfqResetFlag: 1; // 8
		uint32 grphDfqResetAck: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// GRPH_ENABLE
union GrphEnable {
	struct {
		uint32 grphEnable: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// GRPH_FLIP_CONTROL
union GrphFlipControl {
	struct {
		uint32 grphSurfaceUpdateHRetraceEn: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// GRPH_INTERRUPT_CONTROL
union GrphInterruptControl {
	struct {
		uint32 grphPflipIntMask: 1; // 0
		uint32 unknown1: 7;
		uint32 grphPflipIntType: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// GRPH_INTERRUPT_STATUS
union GrphInterruptStatus {
	struct {
		uint32 grphPflipIntOccurred: 1; // 0
		uint32 unknown1: 7;
		uint32 grphPflipIntClear: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// GRPH_LUT_10BIT_BYPASS
union GrphLut10bitBypass {
	struct {
		uint32 unknown1: 8;
		uint32 grphLut10bitBypassEn: 1; // 8
		uint32 unknown2: 7;
		uint32 grphLut10bitBypassDblBufEn: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// GRPH_PITCH
union GrphPitch {
	struct {
		uint32 grphPitch: 15; // 0
		uint32 unknown1: 17;
	};
	uint32 val;
};

// GRPH_PRIMARY_SURFACE_ADDRESS
union GrphPrimarySurfaceAddress {
	struct {
		uint32 grphPrimaryDfqEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 grphPrimarySurfaceAddress: 24; // 8
	};
	uint32 val;
};

// GRPH_PRIMARY_SURFACE_ADDRESS_HIGH
union GrphPrimarySurfaceAddressHigh {
	struct {
		uint32 grphPrimarySurfaceAddressHigh: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// GRPH_SECONDARY_SURFACE_ADDRESS
union GrphSecondarySurfaceAddress {
	struct {
		uint32 grphSecondaryDfqEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 grphSecondarySurfaceAddress: 24; // 8
	};
	uint32 val;
};

// GRPH_SECONDARY_SURFACE_ADDRESS_HIGH
union GrphSecondarySurfaceAddressHigh {
	struct {
		uint32 grphSecondarySurfaceAddressHigh: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// GRPH_STEREOSYNC_FLIP
union GrphStereosyncFlip {
	struct {
		uint32 grphStereosyncFlipEn: 1; // 0
		uint32 unknown1: 7;
		uint32 grphStereosyncFlipMode: 2; // 8
		uint32 unknown2: 6;
		uint32 grphPrimarySurfacePending: 1; // 16
		uint32 grphSecondarySurfacePending: 1; // 17
		uint32 unknown3: 10;
		uint32 grphStereosyncSelectDisable: 1; // 28
		uint32 unknown4: 3;
	};
	uint32 val;
};

// GRPH_SURFACE_ADDRESS_HIGH_INUSE
union GrphSurfaceAddressHighInuse {
	struct {
		uint32 grphSurfaceAddressHighInuse: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// GRPH_SURFACE_ADDRESS_INUSE
union GrphSurfaceAddressInuse {
	struct {
		uint32 unknown1: 8;
		uint32 grphSurfaceAddressInuse: 24; // 8
	};
	uint32 val;
};

// GRPH_SURFACE_OFFSET_X
union GrphSurfaceOffsetX {
	struct {
		uint32 grphSurfaceOffsetX: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// GRPH_SURFACE_OFFSET_Y
union GrphSurfaceOffsetY {
	struct {
		uint32 grphSurfaceOffsetY: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// GRPH_SWAP_CNTL
union GrphSwapCntl {
	struct {
		uint32 grphEndianSwap: 2; // 0
		uint32 unknown1: 2;
		uint32 grphRedCrossbar: 2; // 4
		uint32 grphGreenCrossbar: 2; // 6
		uint32 grphBlueCrossbar: 2; // 8
		uint32 grphAlphaCrossbar: 2; // 10
		uint32 unknown2: 20;
	};
	uint32 val;
};

// GRPH_UPDATE
union GrphUpdate {
	struct {
		uint32 grphModeUpdatePending: 1; // 0
		uint32 grphModeUpdateTaken: 1; // 1
		uint32 grphSurfaceUpdatePending: 1; // 2
		uint32 grphSurfaceUpdateTaken: 1; // 3
		uint32 unknown1: 4;
		uint32 grphSurfaceXdmaPendingEnable: 1; // 8
		uint32 unknown2: 7;
		uint32 grphUpdateLock: 1; // 16
		uint32 unknown3: 7;
		uint32 grphModeDisableMultipleUpdate: 1; // 24
		uint32 unknown4: 3;
		uint32 grphSurfaceDisableMultipleUpdate: 1; // 28
		uint32 unknown5: 3;
	};
	uint32 val;
};

// GRPH_X_END
union GrphXEnd {
	struct {
		uint32 grphXEnd: 15; // 0
		uint32 unknown1: 17;
	};
	uint32 val;
};

// GRPH_X_START
union GrphXStart {
	struct {
		uint32 grphXStart: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// GRPH_Y_END
union GrphYEnd {
	struct {
		uint32 grphYEnd: 15; // 0
		uint32 unknown1: 17;
	};
	uint32 val;
};

// GRPH_Y_START
union GrphYStart {
	struct {
		uint32 grphYStart: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// HDMI_ACR_32_0
union HdmiAcr32_0 {
	struct {
		uint32 unknown1: 12;
		uint32 hdmiAcrCts32: 20; // 12
	};
	uint32 val;
};

// HDMI_ACR_32_1
union HdmiAcr32_1 {
	struct {
		uint32 hdmiAcrN32: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// HDMI_ACR_44_0
union HdmiAcr44_0 {
	struct {
		uint32 unknown1: 12;
		uint32 hdmiAcrCts44: 20; // 12
	};
	uint32 val;
};

// HDMI_ACR_44_1
union HdmiAcr44_1 {
	struct {
		uint32 hdmiAcrN44: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// HDMI_ACR_48_0
union HdmiAcr48_0 {
	struct {
		uint32 unknown1: 12;
		uint32 hdmiAcrCts48: 20; // 12
	};
	uint32 val;
};

// HDMI_ACR_48_1
union HdmiAcr48_1 {
	struct {
		uint32 hdmiAcrN48: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// HDMI_ACR_PACKET_CONTROL
union HdmiAcrPacketControl {
	struct {
		uint32 hdmiAcrSend: 1; // 0
		uint32 hdmiAcrCont: 1; // 1
		uint32 unknown1: 2;
		uint32 hdmiAcrSelect: 2; // 4
		uint32 unknown2: 2;
		uint32 hdmiAcrSource: 1; // 8
		uint32 unknown3: 3;
		uint32 hdmiAcrAutoSend: 1; // 12
		uint32 unknown4: 3;
		uint32 hdmiAcrNMultiple: 3; // 16
		uint32 unknown5: 12;
		uint32 hdmiAcrAudioPriority: 1; // 31
	};
	uint32 val;
};

// HDMI_ACR_STATUS_0
union HdmiAcrStatus0 {
	struct {
		uint32 unknown1: 12;
		uint32 hdmiAcrCts: 20; // 12
	};
	uint32 val;
};

// HDMI_ACR_STATUS_1
union HdmiAcrStatus1 {
	struct {
		uint32 hdmiAcrN: 20; // 0
		uint32 unknown1: 12;
	};
	uint32 val;
};

// HDMI_AUDIO_PACKET_CONTROL
union HdmiAudioPacketControl {
	struct {
		uint32 unknown1: 4;
		uint32 hdmiAudioDelayEn: 2; // 4
		uint32 unknown2: 2;
		uint32 hdmiAudioSendMaxPackets: 1; // 8
		uint32 unknown3: 7;
		uint32 hdmiAudioPacketsPerLine: 5; // 16
		uint32 unknown4: 11;
	};
	uint32 val;
};

// HDMI_CONTROL
union HdmiControl {
	struct {
		uint32 hdmiKeepoutMode: 1; // 0
		uint32 unknown1: 3;
		uint32 hdmiPacketGenVersion: 1; // 4
		uint32 unknown2: 3;
		uint32 hdmiErrorAck: 1; // 8
		uint32 hdmiErrorMask: 1; // 9
		uint32 unknown3: 14;
		uint32 hdmiDeepColorEnable: 1; // 24
		uint32 unknown4: 3;
		uint32 hdmiDeepColorDepth: 2; // 28
		uint32 unknown5: 2;
	};
	uint32 val;
};

// HDMI_GC
union HdmiGc {
	struct {
		uint32 hdmiGcAvmute: 1; // 0
		uint32 unknown1: 1;
		uint32 hdmiGcAvmuteCont: 1; // 2
		uint32 unknown2: 1;
		uint32 hdmiDefaultPhase: 1; // 4
		uint32 unknown3: 3;
		uint32 hdmiPackingPhase: 4; // 8
		uint32 hdmiPackingPhaseOverride: 1; // 12
		uint32 unknown4: 19;
	};
	uint32 val;
};

// HDMI_GENERIC_PACKET_CONTROL0
union HdmiGenericPacketControl0 {
	struct {
		uint32 hdmiGeneric0Send: 1; // 0
		uint32 hdmiGeneric0Cont: 1; // 1
		uint32 unknown1: 2;
		uint32 hdmiGeneric1Send: 1; // 4
		uint32 hdmiGeneric1Cont: 1; // 5
		uint32 unknown2: 10;
		uint32 hdmiGeneric0Line: 6; // 16
		uint32 unknown3: 2;
		uint32 hdmiGeneric1Line: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// HDMI_GENERIC_PACKET_CONTROL1
union HdmiGenericPacketControl1 {
	struct {
		uint32 hdmiGeneric2Send: 1; // 0
		uint32 hdmiGeneric2Cont: 1; // 1
		uint32 unknown1: 2;
		uint32 hdmiGeneric3Send: 1; // 4
		uint32 hdmiGeneric3Cont: 1; // 5
		uint32 unknown2: 10;
		uint32 hdmiGeneric2Line: 6; // 16
		uint32 unknown3: 2;
		uint32 hdmiGeneric3Line: 6; // 24
		uint32 unknown4: 2;
	};
	uint32 val;
};

// HDMI_INFOFRAME_CONTROL0
union HdmiInfoframeControl0 {
	struct {
		uint32 hdmiAviInfoSend: 1; // 0
		uint32 hdmiAviInfoCont: 1; // 1
		uint32 unknown1: 2;
		uint32 hdmiAudioInfoSend: 1; // 4
		uint32 hdmiAudioInfoCont: 1; // 5
		uint32 unknown2: 2;
		uint32 hdmiMpegInfoSend: 1; // 8
		uint32 hdmiMpegInfoCont: 1; // 9
		uint32 unknown3: 22;
	};
	uint32 val;
};

// HDMI_INFOFRAME_CONTROL1
union HdmiInfoframeControl1 {
	struct {
		uint32 hdmiAviInfoLine: 6; // 0
		uint32 unknown1: 2;
		uint32 hdmiAudioInfoLine: 6; // 8
		uint32 unknown2: 2;
		uint32 hdmiMpegInfoLine: 6; // 16
		uint32 unknown3: 10;
	};
	uint32 val;
};

// HDMI_STATUS
union HdmiStatus {
	struct {
		uint32 hdmiActiveAvmute: 1; // 0
		uint32 unknown1: 15;
		uint32 hdmiAudioPacketError: 1; // 16
		uint32 unknown2: 3;
		uint32 hdmiVbiPacketError: 1; // 20
		uint32 unknown3: 6;
		uint32 hdmiErrorInt: 1; // 27
		uint32 unknown4: 4;
	};
	uint32 val;
};

// HDMI_VBI_PACKET_CONTROL
union HdmiVbiPacketControl {
	struct {
		uint32 hdmiNullSend: 1; // 0
		uint32 unknown1: 3;
		uint32 hdmiGcSend: 1; // 4
		uint32 hdmiGcCont: 1; // 5
		uint32 unknown2: 2;
		uint32 hdmiIsrcSend: 1; // 8
		uint32 hdmiIsrcCont: 1; // 9
		uint32 unknown3: 6;
		uint32 hdmiIsrcLine: 6; // 16
		uint32 unknown4: 10;
	};
	uint32 val;
};

// IDDCCIF02_DBG_DCCIF_C
union Iddccif02DbgDccifC {
	struct {
		uint32 dbgDccifC: 32; // 0
	};
	uint32 val;
};

// IDDCCIF04_DBG_DCCIF_E
union Iddccif04DbgDccifE {
	struct {
		uint32 dbgDccifE: 32; // 0
	};
	uint32 val;
};

// IDDCCIF05_DBG_DCCIF_F
union Iddccif05DbgDccifF {
	struct {
		uint32 dbgDccifF: 32; // 0
	};
	uint32 val;
};

// INPUT_CSC_C11_C12
union InputCscC11C12 {
	struct {
		uint32 inputCscC11: 16; // 0
		uint32 inputCscC12: 16; // 16
	};
	uint32 val;
};

// INPUT_CSC_C13_C14
union InputCscC13C14 {
	struct {
		uint32 inputCscC13: 16; // 0
		uint32 inputCscC14: 16; // 16
	};
	uint32 val;
};

// INPUT_CSC_C21_C22
union InputCscC21C22 {
	struct {
		uint32 inputCscC21: 16; // 0
		uint32 inputCscC22: 16; // 16
	};
	uint32 val;
};

// INPUT_CSC_C23_C24
union InputCscC23C24 {
	struct {
		uint32 inputCscC23: 16; // 0
		uint32 inputCscC24: 16; // 16
	};
	uint32 val;
};

// INPUT_CSC_C31_C32
union InputCscC31C32 {
	struct {
		uint32 inputCscC31: 16; // 0
		uint32 inputCscC32: 16; // 16
	};
	uint32 val;
};

// INPUT_CSC_C33_C34
union InputCscC33C34 {
	struct {
		uint32 inputCscC33: 16; // 0
		uint32 inputCscC34: 16; // 16
	};
	uint32 val;
};

// INPUT_CSC_CONTROL
union InputCscControl {
	struct {
		uint32 inputCscGrphMode: 2; // 0
		uint32 unknown1: 2;
		uint32 inputCscOvlMode: 2; // 4
		uint32 unknown2: 26;
	};
	uint32 val;
};

// INPUT_GAMMA_CONTROL
union InputGammaControl {
	struct {
		uint32 grphInputGammaMode: 2; // 0
		uint32 unknown1: 2;
		uint32 ovlInputGammaMode: 2; // 4
		uint32 unknown2: 26;
	};
	uint32 val;
};

// INT_MASK
union IntMask {
	struct {
		uint32 vblankInt: 1; // 0
		uint32 unknown1: 3;
		uint32 vlineInt: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// KEY_CONTROL
union KeyControl {
	struct {
		uint32 keySelect: 1; // 0
		uint32 keyMode: 2; // 1
		uint32 unknown1: 25;
		uint32 grphOvlHalfBlend: 1; // 28
		uint32 unknown2: 3;
	};
	uint32 val;
};

// KEY_RANGE_ALPHA
union KeyRangeAlpha {
	struct {
		uint32 keyAlphaLow: 16; // 0
		uint32 keyAlphaHigh: 16; // 16
	};
	uint32 val;
};

// KEY_RANGE_BLUE
union KeyRangeBlue {
	struct {
		uint32 keyBlueLow: 16; // 0
		uint32 keyBlueHigh: 16; // 16
	};
	uint32 val;
};

// KEY_RANGE_GREEN
union KeyRangeGreen {
	struct {
		uint32 keyGreenLow: 16; // 0
		uint32 keyGreenHigh: 16; // 16
	};
	uint32 val;
};

// KEY_RANGE_RED
union KeyRangeRed {
	struct {
		uint32 keyRedLow: 16; // 0
		uint32 keyRedHigh: 16; // 16
	};
	uint32 val;
};

// LB_DEBUG
union LbDebug {
	struct {
		uint32 lbDebug: 32; // 0
	};
	uint32 val;
};

// LB_DEBUG2
union LbDebug2 {
	struct {
		uint32 lbDebug2: 32; // 0
	};
	uint32 val;
};

// LB_NO_OUTSTANDING_REQ_STATUS
union LbNoOutstandingReqStatus {
	struct {
		uint32 lbNoOutstandingReqStat: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// LB_SYNC_RESET_SEL
union LbSyncResetSel {
	struct {
		uint32 lbSyncResetSel: 2; // 0
		uint32 unknown1: 2;
		uint32 lbSyncResetSel2: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// LB_TEST_DEBUG_DATA
union LbTestDebugData {
	struct {
		uint32 lbTestDebugData: 32; // 0
	};
	uint32 val;
};

// LB_TEST_DEBUG_INDEX
union LbTestDebugIndex {
	struct {
		uint32 lbTestDebugIndex: 8; // 0
		uint32 lbTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// LIGHT_SLEEP_CNTL
union LightSleepCntl {
	struct {
		uint32 lightSleepDis: 1; // 0
		uint32 unknown1: 7;
		uint32 memShutdownDis: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// LOW_POWER_TILING_CONTROL
union LowPowerTilingControl {
	struct {
		uint32 lowPowerTilingEnable: 1; // 0
		uint32 unknown1: 2;
		uint32 lowPowerTilingMode: 2; // 3
		uint32 lowPowerTilingNumPipes: 3; // 5
		uint32 lowPowerTilingNumBanks: 3; // 8
		uint32 lowPowerTilingPipeInterleaveSize: 1; // 11
		uint32 lowPowerTilingRowSize: 3; // 12
		uint32 unknown2: 1;
		uint32 lowPowerTilingRowsPerChan: 12; // 16
		uint32 unknown3: 4;
	};
	uint32 val;
};

// LVDS_DATA_CNTL
union LvdsDataCntl {
	struct {
		uint32 lvds24bitEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 lvds24bitFormat: 1; // 4
		uint32 unknown2: 3;
		uint32 lvds2ndChanDe: 1; // 8
		uint32 lvds2ndChanVs: 1; // 9
		uint32 lvds2ndChanHs: 1; // 10
		uint32 unknown3: 1;
		uint32 lvds2ndLinkCntlBits: 3; // 12
		uint32 unknown4: 1;
		uint32 lvdsFpPol: 1; // 16
		uint32 lvdsLpPol: 1; // 17
		uint32 lvdsDtmgPol: 1; // 18
		uint32 unknown5: 13;
	};
	uint32 val;
};

// LVTMA_PWRSEQ_CNTL
union LvtmaPwrseqCntl {
	struct {
		uint32 lvtmaPwrseqEn: 1; // 0
		uint32 lvtmaPwrseqDisableSyncenControlOfTxEn: 1; // 1
		uint32 unknown1: 2;
		uint32 lvtmaPwrseqTargetState: 1; // 4
		uint32 unknown2: 3;
		uint32 lvtmaSyncen: 1; // 8
		uint32 lvtmaSyncenOvrd: 1; // 9
		uint32 lvtmaSyncenPol: 1; // 10
		uint32 unknown3: 5;
		uint32 lvtmaDigon: 1; // 16
		uint32 lvtmaDigonOvrd: 1; // 17
		uint32 lvtmaDigonPol: 1; // 18
		uint32 unknown4: 5;
		uint32 lvtmaBlon: 1; // 24
		uint32 lvtmaBlonOvrd: 1; // 25
		uint32 lvtmaBlonPol: 1; // 26
		uint32 unknown5: 5;
	};
	uint32 val;
};

// LVTMA_PWRSEQ_DELAY1
union LvtmaPwrseqDelay1 {
	struct {
		uint32 lvtmaPwrupDelay1: 8; // 0
		uint32 lvtmaPwrupDelay2: 8; // 8
		uint32 lvtmaPwrdnDelay1: 8; // 16
		uint32 lvtmaPwrdnDelay2: 8; // 24
	};
	uint32 val;
};

// LVTMA_PWRSEQ_DELAY2
union LvtmaPwrseqDelay2 {
	struct {
		uint32 lvtmaPwrdnMinLength: 8; // 0
		uint32 lvtmaPwrupDelay3: 8; // 8
		uint32 lvtmaPwrdnDelay3: 8; // 16
		uint32 lvtmaVaryBlOverrideEn: 1; // 24
		uint32 unknown1: 7;
	};
	uint32 val;
};

// LVTMA_PWRSEQ_REF_DIV
union LvtmaPwrseqRefDiv {
	struct {
		uint32 lvtmaPwrseqRefDiv: 12; // 0
		uint32 unknown1: 4;
		uint32 blPwmRefDiv: 16; // 16
	};
	uint32 val;
};

// LVTMA_PWRSEQ_STATE
union LvtmaPwrseqState {
	struct {
		uint32 lvtmaPwrseqTargetStateR: 1; // 0
		uint32 lvtmaPwrseqDigon: 1; // 1
		uint32 lvtmaPwrseqSyncen: 1; // 2
		uint32 lvtmaPwrseqBlon: 1; // 3
		uint32 lvtmaPwrseqDone: 1; // 4
		uint32 unknown1: 3;
		uint32 lvtmaPwrseqState: 4; // 8
		uint32 unknown2: 20;
	};
	uint32 val;
};

// MASTER_COMM_CMD_REG
union MasterCommCmdReg {
	struct {
		uint32 masterCommCmdRegByte0: 8; // 0
		uint32 masterCommCmdRegByte1: 8; // 8
		uint32 masterCommCmdRegByte2: 8; // 16
		uint32 masterCommCmdRegByte3: 8; // 24
	};
	uint32 val;
};

// MASTER_COMM_CNTL_REG
union MasterCommCntlReg {
	struct {
		uint32 masterCommInterrupt: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// MASTER_COMM_DATA_REG1
union MasterCommDataReg1 {
	struct {
		uint32 masterCommDataReg1Byte0: 8; // 0
		uint32 masterCommDataReg1Byte1: 8; // 8
		uint32 masterCommDataReg1Byte2: 8; // 16
		uint32 masterCommDataReg1Byte3: 8; // 24
	};
	uint32 val;
};

// MASTER_COMM_DATA_REG2
union MasterCommDataReg2 {
	struct {
		uint32 masterCommDataReg2Byte0: 8; // 0
		uint32 masterCommDataReg2Byte1: 8; // 8
		uint32 masterCommDataReg2Byte2: 8; // 16
		uint32 masterCommDataReg2Byte3: 8; // 24
	};
	uint32 val;
};

// MASTER_COMM_DATA_REG3
union MasterCommDataReg3 {
	struct {
		uint32 masterCommDataReg3Byte0: 8; // 0
		uint32 masterCommDataReg3Byte1: 8; // 8
		uint32 masterCommDataReg3Byte2: 8; // 16
		uint32 masterCommDataReg3Byte3: 8; // 24
	};
	uint32 val;
};

// MASTER_UPDATE_LOCK
union MasterUpdateLock {
	struct {
		uint32 masterUpdateLock: 1; // 0
		uint32 unknown1: 7;
		uint32 gslControlMasterUpdateLock: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// MASTER_UPDATE_MODE
union MasterUpdateMode {
	struct {
		uint32 masterUpdateMode: 3; // 0
		uint32 unknown1: 13;
		uint32 masterUpdateInterlacedMode: 2; // 16
		uint32 unknown2: 14;
	};
	uint32 val;
};

// MCIF_CONTROL
union McifControl {
	struct {
		uint32 mcifBuffSize: 2; // 0
		uint32 unknown1: 2;
		uint32 addressTranslationEnable: 1; // 4
		uint32 unknown2: 3;
		uint32 privilegedAccessEnable: 1; // 8
		uint32 unknown3: 3;
		uint32 mcifSlowReqInterval: 4; // 12
		uint32 lowReadUrgLevel: 8; // 16
		uint32 mcCleanDeassertLatency: 6; // 24
		uint32 mcifMcLatencyCounterEnable: 1; // 30
		uint32 mcifMcLatencyCounterUrgentOnly: 1; // 31
	};
	uint32 val;
};

// MCIF_MEM_CONTROL
union McifMemControl {
	struct {
		uint32 mcifmemCacheModeDis: 1; // 0
		uint32 unknown1: 3;
		uint32 mcifmemCacheMode: 2; // 4
		uint32 unknown2: 2;
		uint32 mcifmemCacheSize: 7; // 8
		uint32 unknown3: 1;
		uint32 mcifmemCachePipe: 3; // 16
		uint32 mcifmemCacheType: 2; // 19
		uint32 unknown4: 11;
	};
	uint32 val;
};

// MCIF_TEST_DEBUG_DATA
union McifTestDebugData {
	struct {
		uint32 mcifTestDebugData: 32; // 0
	};
	uint32 val;
};

// MCIF_TEST_DEBUG_INDEX
union McifTestDebugIndex {
	struct {
		uint32 mcifTestDebugIndex: 8; // 0
		uint32 mcifTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// MCIF_VMID
union McifVmid {
	struct {
		uint32 mcifWrVmid: 4; // 0
		uint32 vipWrVmid: 4; // 4
		uint32 unknown1: 24;
	};
	uint32 val;
};

// MCIF_WRITE_COMBINE_CONTROL
union McifWriteCombineControl {
	struct {
		uint32 mcifWriteCombineTimeout: 8; // 0
		uint32 vipWriteCombineTimeout: 8; // 8
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MC_DC_INTERFACE_NACK_STATUS
union McDcInterfaceNackStatus {
	struct {
		uint32 dmifRdretNackOccurred: 1; // 0
		uint32 unknown1: 3;
		uint32 dmifRdretNackClear: 1; // 4
		uint32 unknown2: 3;
		uint32 vipWrretNackOccurred: 1; // 8
		uint32 unknown3: 3;
		uint32 vipWrretNackClear: 1; // 12
		uint32 unknown4: 3;
		uint32 mcifRdretNackOccurred: 1; // 16
		uint32 unknown5: 3;
		uint32 mcifRdretNackClear: 1; // 20
		uint32 unknown6: 3;
		uint32 mcifWrretNackOccurred: 1; // 24
		uint32 unknown7: 3;
		uint32 mcifWrretNackClear: 1; // 28
		uint32 unknown8: 3;
	};
	uint32 val;
};

// MICROSECOND_TIME_BASE_DIV
union MicrosecondTimeBaseDiv {
	struct {
		uint32 microsecondTimeBaseDiv: 7; // 0
		uint32 unknown1: 1;
		uint32 xtalRefDiv: 7; // 8
		uint32 unknown2: 1;
		uint32 xtalRefSel: 1; // 16
		uint32 xtalRefClockSourceSel: 1; // 17
		uint32 unknown3: 2;
		uint32 microsecondTimeBaseClockSourceSel: 1; // 20
		uint32 unknown4: 11;
	};
	uint32 val;
};

// MILLISECOND_TIME_BASE_DIV
union MillisecondTimeBaseDiv {
	struct {
		uint32 millisecondTimeBaseDiv: 17; // 0
		uint32 unknown1: 3;
		uint32 millisecondTimeBaseClockSourceSel: 1; // 20
		uint32 unknown2: 11;
	};
	uint32 val;
};

// MVP_AFR_FLIP_FIFO_CNTL
union MvpAfrFlipFifoCntl {
	struct {
		uint32 mvpAfrFlipFifoNumEntries: 4; // 0
		uint32 mvpAfrFlipFifoReset: 1; // 4
		uint32 unknown1: 3;
		uint32 mvpAfrFlipFifoResetFlag: 1; // 8
		uint32 unknown2: 3;
		uint32 mvpAfrFlipFifoResetAck: 1; // 12
		uint32 unknown3: 19;
	};
	uint32 val;
};

// MVP_AFR_FLIP_MODE
union MvpAfrFlipMode {
	struct {
		uint32 mvpAfrFlipMode: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// MVP_BLACK_KEYER
union MvpBlackKeyer {
	struct {
		uint32 mvpBlackKeyerR: 10; // 0
		uint32 mvpBlackKeyerG: 10; // 10
		uint32 mvpBlackKeyerB: 10; // 20
		uint32 unknown1: 2;
	};
	uint32 val;
};

// MVP_CONTROL1
union MvpControl1 {
	struct {
		uint32 mvpEn: 1; // 0
		uint32 unknown1: 3;
		uint32 mvpMixerMode: 3; // 4
		uint32 unknown2: 1;
		uint32 mvpMixerSlaveSel: 1; // 8
		uint32 mvpMixerSlaveSelDelayUntilEndOfBlank: 1; // 9
		uint32 mvpArbitrationModeForAfrManualSwitchMode: 1; // 10
		uint32 unknown3: 1;
		uint32 mvpRateControl: 1; // 12
		uint32 unknown4: 3;
		uint32 mvpChannelControl: 1; // 16
		uint32 unknown5: 3;
		uint32 mvpGpuChainLocation: 2; // 20
		uint32 unknown6: 2;
		uint32 mvpDisableMsbExpand: 1; // 24
		uint32 unknown7: 3;
		uint32 mvp30bppEn: 1; // 28
		uint32 unknown8: 1;
		uint32 mvpTerminationCntlA: 1; // 30
		uint32 mvpTerminationCntlB: 1; // 31
	};
	uint32 val;
};

// MVP_CONTROL2
union MvpControl2 {
	struct {
		uint32 mvpMuxDeDvocntl0Sel: 1; // 0
		uint32 unknown1: 3;
		uint32 mvpMuxDeDvocntl2Sel: 1; // 4
		uint32 unknown2: 3;
		uint32 mvpMuxaClkSel: 1; // 8
		uint32 unknown3: 3;
		uint32 mvpMuxbClkSel: 1; // 12
		uint32 unknown4: 3;
		uint32 mvpDvocntlMux: 1; // 16
		uint32 unknown5: 3;
		uint32 mvpFlowControlOutEn: 1; // 20
		uint32 unknown6: 3;
		uint32 mvpSwapLockOutEn: 1; // 24
		uint32 unknown7: 3;
		uint32 mvpSwapAbInDcDdr: 1; // 28
		uint32 unknown8: 3;
	};
	uint32 val;
};

// MVP_CONTROL3
union MvpControl3 {
	struct {
		uint32 mvpResetInBetweenFrames: 1; // 0
		uint32 unknown1: 3;
		uint32 mvpDdrScAbSel: 1; // 4
		uint32 unknown2: 3;
		uint32 mvpDdrScBStartMode: 1; // 8
		uint32 unknown3: 3;
		uint32 mvpFlowControlOutForceOne: 1; // 12
		uint32 unknown4: 3;
		uint32 mvpFlowControlOutForceZero: 1; // 16
		uint32 unknown5: 3;
		uint32 mvpFlowControlCascadeEn: 1; // 20
		uint32 unknown6: 3;
		uint32 mvpSwap48bitEn: 1; // 24
		uint32 unknown7: 3;
		uint32 mvpFlowControlInCap: 1; // 28
		uint32 unknown8: 3;
	};
	uint32 val;
};

// MVP_CRC_CNTL
union MvpCrcCntl {
	struct {
		uint32 mvpCrcBlueMask: 8; // 0
		uint32 mvpCrcGreenMask: 8; // 8
		uint32 mvpCrcRedMask: 8; // 16
		uint32 unknown1: 4;
		uint32 mvpCrcEn: 1; // 28
		uint32 mvpCrcContEn: 1; // 29
		uint32 mvpDcDdrCrcEvenOddPixSel: 1; // 30
		uint32 unknown2: 1;
	};
	uint32 val;
};

// MVP_CRC_RESULT_BLUE_GREEN
union MvpCrcResultBlueGreen {
	struct {
		uint32 mvpCrcBlueResult: 16; // 0
		uint32 mvpCrcGreenResult: 16; // 16
	};
	uint32 val;
};

// MVP_CRC_RESULT_RED
union MvpCrcResultRed {
	struct {
		uint32 mvpCrcRedResult: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// MVP_DEBUG
union MvpDebug {
	struct {
		uint32 mvpSwapLockInEn: 1; // 0
		uint32 mvpFlowControlInEn: 1; // 1
		uint32 mvpSwapLockInSel: 1; // 2
		uint32 mvpFlowControlInSel: 1; // 3
		uint32 mvpDisFixAfrManualHsyncFlip: 1; // 4
		uint32 mvpDisFixAfrAutoVsyncFlip: 1; // 5
		uint32 mvpEnFixAfrManualSwitchInSfr: 1; // 6
		uint32 mvpDisReadPointerResetDelay: 1; // 7
		uint32 mvpDebugBits: 24; // 8
	};
	uint32 val;
};

// MVP_DEBUG_05
union MvpDebug05 {
	struct {
		uint32 unknown1: 1;
		uint32 ide0MvpGpuChainLocation: 2; // 1
		uint32 unknown2: 29;
	};
	uint32 val;
};

// MVP_DEBUG_09
union MvpDebug09 {
	struct {
		uint32 unknown1: 1;
		uint32 ide4Crtc2MvpGpuChainLocation: 2; // 1
		uint32 unknown2: 29;
	};
	uint32 val;
};

// MVP_DEBUG_12
union MvpDebug12 {
	struct {
		uint32 idecMvpDataAH: 1; // 0
		uint32 idecMvpDataA: 24; // 1
		uint32 unknown1: 7;
	};
	uint32 val;
};

// MVP_DEBUG_13
union MvpDebug13 {
	struct {
		uint32 idedMvpDataBH: 1; // 0
		uint32 idedMvpDataB: 24; // 1
		uint32 idedStartReadB: 1; // 25
		uint32 idedReadFifoEntryDeB: 1; // 26
		uint32 idedWriteAddB: 3; // 27
		uint32 unknown1: 2;
	};
	uint32 val;
};

// MVP_DEBUG_14
union MvpDebug14 {
	struct {
		uint32 ideeReadAdd: 3; // 0
		uint32 ideeWriteAddA: 3; // 3
		uint32 ideeWriteAddB: 3; // 6
		uint32 ideeStartRead: 1; // 9
		uint32 ideeStartReadB: 1; // 10
		uint32 ideeStartIncrWrA: 1; // 11
		uint32 ideeStartIncrWrB: 1; // 12
		uint32 ideeWrite2fifo: 1; // 13
		uint32 ideeReadFifoEntryDe: 1; // 14
		uint32 ideeReadFifoEntryDeB: 1; // 15
		uint32 ideeReadFifoDe: 1; // 16
		uint32 ideeReadFifoDeB: 1; // 17
		uint32 ideeReadFifoEnable: 1; // 18
		uint32 ideeCrtc1CntlCaptureStartA: 1; // 19
		uint32 ideeCrcPhase: 1; // 20
		uint32 unknown1: 11;
	};
	uint32 val;
};

// MVP_DEBUG_15
union MvpDebug15 {
	struct {
		uint32 idefMvpAsyncFifoWen: 1; // 0
		uint32 unknown1: 3;
		uint32 idefMvpAsyncFifoWdata: 28; // 4
	};
	uint32 val;
};

// MVP_DEBUG_16
union MvpDebug16 {
	struct {
		uint32 idccMvpAsyncFifoRead: 1; // 0
		uint32 idccMvpAsyncFifoExceedStopLevel: 1; // 1
		uint32 idccMvpAsyncFifoExceedPauseLevel: 1; // 2
		uint32 idccFlowControlOut: 1; // 3
		uint32 idccMvpAsyncFifoNumEntries: 8; // 4
		uint32 idccMvpAsyncFifoOverflow: 1; // 12
		uint32 idccMvpAsyncFifoUnderflow: 1; // 13
		uint32 unknown1: 2;
		uint32 idccMvpAsyncReadAddr: 8; // 16
		uint32 idccMvpAsyncWriteAddr: 8; // 24
	};
	uint32 val;
};

// MVP_DEBUG_17
union MvpDebug17 {
	struct {
		uint32 idcdMvpAsyncFifoRead: 1; // 0
		uint32 idcdMvpAsyncFifoPhase: 1; // 1
		uint32 idcdMvpAsyncFifoReadData: 30; // 2
	};
	uint32 val;
};

// MVP_FIFO_CONTROL
union MvpFifoControl {
	struct {
		uint32 mvpStopSlaveWm: 8; // 0
		uint32 mvpPauseSlaveWm: 8; // 8
		uint32 mvpPauseSlaveCnt: 8; // 16
		uint32 unknown1: 8;
	};
	uint32 val;
};

// MVP_FIFO_STATUS
union MvpFifoStatus {
	struct {
		uint32 mvpFifoLevel: 8; // 0
		uint32 mvpFifoOverflow: 1; // 8
		uint32 unknown1: 3;
		uint32 mvpFifoOverflowOccurred: 1; // 12
		uint32 unknown2: 3;
		uint32 mvpFifoOverflowAck: 1; // 16
		uint32 unknown3: 3;
		uint32 mvpFifoUnderflow: 1; // 20
		uint32 unknown4: 3;
		uint32 mvpFifoUnderflowOccurred: 1; // 24
		uint32 unknown5: 3;
		uint32 mvpFifoUnderflowAck: 1; // 28
		uint32 unknown6: 1;
		uint32 mvpFifoErrorMask: 1; // 30
		uint32 mvpFifoErrorIntStatus: 1; // 31
	};
	uint32 val;
};

// MVP_FLIP_LINE_NUM_INSERT
union MvpFlipLineNumInsert {
	struct {
		uint32 mvpFlipLineNumInsertMode: 2; // 0
		uint32 unknown1: 6;
		uint32 mvpFlipLineNumInsert: 15; // 8
		uint32 unknown2: 1;
		uint32 mvpFlipLineNumOffset: 6; // 24
		uint32 mvpFlipAutoEnable: 1; // 30
		uint32 unknown3: 1;
	};
	uint32 val;
};

// MVP_INBAND_CNTL_CAP
union MvpInbandCntlCap {
	struct {
		uint32 mvpIgnorInbandCntl: 1; // 0
		uint32 unknown1: 3;
		uint32 mvpPassingInbandCntlEn: 1; // 4
		uint32 unknown2: 3;
		uint32 mvpInbandCntlCharCap: 24; // 8
	};
	uint32 val;
};

// MVP_RECEIVE_CNT_CNTL1
union MvpReceiveCntCntl1 {
	struct {
		uint32 mvpSlavePixelErrorCnt: 13; // 0
		uint32 unknown1: 3;
		uint32 mvpSlaveLineErrorCnt: 13; // 16
		uint32 unknown2: 2;
		uint32 mvpSlaveDataChkEn: 1; // 31
	};
	uint32 val;
};

// MVP_RECEIVE_CNT_CNTL2
union MvpReceiveCntCntl2 {
	struct {
		uint32 mvpSlaveFrameErrorCnt: 13; // 0
		uint32 unknown1: 18;
		uint32 mvpSlaveFrameErrorCntReset: 1; // 31
	};
	uint32 val;
};

// MVP_SLAVE_STATUS
union MvpSlaveStatus {
	struct {
		uint32 mvpSlavePixelsPerLineRcved: 13; // 0
		uint32 unknown1: 3;
		uint32 mvpSlaveLinesPerFrameRcved: 13; // 16
		uint32 unknown2: 3;
	};
	uint32 val;
};

// MVP_TEST_DEBUG_DATA
union MvpTestDebugData {
	struct {
		uint32 mvpTestDebugData: 32; // 0
	};
	uint32 val;
};

// MVP_TEST_DEBUG_INDEX
union MvpTestDebugIndex {
	struct {
		uint32 mvpTestDebugIndex: 8; // 0
		uint32 mvpTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// OUTPUT_CSC_C11_C12
union OutputCscC11C12 {
	struct {
		uint32 outputCscC11: 16; // 0
		uint32 outputCscC12: 16; // 16
	};
	uint32 val;
};

// OUTPUT_CSC_C13_C14
union OutputCscC13C14 {
	struct {
		uint32 outputCscC13: 16; // 0
		uint32 outputCscC14: 16; // 16
	};
	uint32 val;
};

// OUTPUT_CSC_C21_C22
union OutputCscC21C22 {
	struct {
		uint32 outputCscC21: 16; // 0
		uint32 outputCscC22: 16; // 16
	};
	uint32 val;
};

// OUTPUT_CSC_C23_C24
union OutputCscC23C24 {
	struct {
		uint32 outputCscC23: 16; // 0
		uint32 outputCscC24: 16; // 16
	};
	uint32 val;
};

// OUTPUT_CSC_C31_C32
union OutputCscC31C32 {
	struct {
		uint32 outputCscC31: 16; // 0
		uint32 outputCscC32: 16; // 16
	};
	uint32 val;
};

// OUTPUT_CSC_C33_C34
union OutputCscC33C34 {
	struct {
		uint32 outputCscC33: 16; // 0
		uint32 outputCscC34: 16; // 16
	};
	uint32 val;
};

// OUTPUT_CSC_CONTROL
union OutputCscControl {
	struct {
		uint32 outputCscGrphMode: 3; // 0
		uint32 unknown1: 1;
		uint32 outputCscOvlMode: 3; // 4
		uint32 unknown2: 25;
	};
	uint32 val;
};

// OUT_ROUND_CONTROL
union OutRoundControl {
	struct {
		uint32 outRoundTruncMode: 4; // 0
		uint32 unknown1: 28;
	};
	uint32 val;
};

// OVLSCL_EDGE_PIXEL_CNTL
union OvlsclEdgePixelCntl {
	struct {
		uint32 ovlsclBlackColorBcb: 10; // 0
		uint32 ovlsclBlackColorGy: 10; // 10
		uint32 ovlsclBlackColorRcr: 10; // 20
		uint32 unknown1: 1;
		uint32 ovlsclEdgePixelSel: 1; // 31
	};
	uint32 val;
};

// OVL_CONTROL1
union OvlControl1 {
	struct {
		uint32 ovlDepth: 2; // 0
		uint32 ovlNumBanks: 2; // 2
		uint32 ovlZ: 2; // 4
		uint32 ovlBankWidth: 2; // 6
		uint32 ovlFormat: 3; // 8
		uint32 ovlBankHeight: 2; // 11
		uint32 ovlTileSplit: 3; // 13
		uint32 ovlAddressTranslationEnable: 1; // 16
		uint32 ovlPrivilegedAccessEnable: 1; // 17
		uint32 ovlMacroTileAspect: 2; // 18
		uint32 ovlArrayMode: 4; // 20
		uint32 ovlColorExpansionMode: 1; // 24
		uint32 ovlPipeConfig: 5; // 25
		uint32 unknown1: 2;
	};
	uint32 val;
};

// OVL_CONTROL2
union OvlControl2 {
	struct {
		uint32 ovlHalfResolutionEnable: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// OVL_DFQ_CONTROL
union OvlDfqControl {
	struct {
		uint32 ovlDfqReset: 1; // 0
		uint32 unknown1: 3;
		uint32 ovlDfqSize: 3; // 4
		uint32 unknown2: 1;
		uint32 ovlDfqMinFreeEntries: 3; // 8
		uint32 unknown3: 21;
	};
	uint32 val;
};

// OVL_DFQ_STATUS
union OvlDfqStatus {
	struct {
		uint32 ovlDfqNumEntries: 4; // 0
		uint32 ovlSecondaryDfqNumEntries: 4; // 4
		uint32 ovlDfqResetFlag: 1; // 8
		uint32 ovlDfqResetAck: 1; // 9
		uint32 unknown1: 22;
	};
	uint32 val;
};

// OVL_ENABLE
union OvlEnable {
	struct {
		uint32 ovlEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 ovlsclEn: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// OVL_END
union OvlEnd {
	struct {
		uint32 ovlYEnd: 15; // 0
		uint32 unknown1: 1;
		uint32 ovlXEnd: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// OVL_PITCH
union OvlPitch {
	struct {
		uint32 ovlPitch: 15; // 0
		uint32 unknown1: 17;
	};
	uint32 val;
};

// OVL_SECONDARY_SURFACE_ADDRESS
union OvlSecondarySurfaceAddress {
	struct {
		uint32 ovlSecondaryDfqEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 ovlSecondarySurfaceAddress: 24; // 8
	};
	uint32 val;
};

// OVL_SECONDARY_SURFACE_ADDRESS_HIGH
union OvlSecondarySurfaceAddressHigh {
	struct {
		uint32 ovlSecondarySurfaceAddressHigh: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// OVL_START
union OvlStart {
	struct {
		uint32 ovlYStart: 14; // 0
		uint32 unknown1: 2;
		uint32 ovlXStart: 14; // 16
		uint32 unknown2: 2;
	};
	uint32 val;
};

// OVL_STEREOSYNC_FLIP
union OvlStereosyncFlip {
	struct {
		uint32 ovlStereosyncFlipEn: 1; // 0
		uint32 unknown1: 7;
		uint32 ovlStereosyncFlipMode: 2; // 8
		uint32 unknown2: 6;
		uint32 ovlPrimarySurfacePending: 1; // 16
		uint32 ovlSecondarySurfacePending: 1; // 17
		uint32 unknown3: 10;
		uint32 ovlStereosyncSelectDisable: 1; // 28
		uint32 unknown4: 3;
	};
	uint32 val;
};

// OVL_SURFACE_ADDRESS
union OvlSurfaceAddress {
	struct {
		uint32 ovlDfqEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 ovlSurfaceAddress: 24; // 8
	};
	uint32 val;
};

// OVL_SURFACE_ADDRESS_HIGH
union OvlSurfaceAddressHigh {
	struct {
		uint32 ovlSurfaceAddressHigh: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// OVL_SURFACE_ADDRESS_HIGH_INUSE
union OvlSurfaceAddressHighInuse {
	struct {
		uint32 ovlSurfaceAddressHighInuse: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// OVL_SURFACE_ADDRESS_INUSE
union OvlSurfaceAddressInuse {
	struct {
		uint32 unknown1: 8;
		uint32 ovlSurfaceAddressInuse: 24; // 8
	};
	uint32 val;
};

// OVL_SURFACE_OFFSET_X
union OvlSurfaceOffsetX {
	struct {
		uint32 ovlSurfaceOffsetX: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// OVL_SURFACE_OFFSET_Y
union OvlSurfaceOffsetY {
	struct {
		uint32 ovlSurfaceOffsetY: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// OVL_SWAP_CNTL
union OvlSwapCntl {
	struct {
		uint32 ovlEndianSwap: 2; // 0
		uint32 unknown1: 2;
		uint32 ovlRedCrossbar: 2; // 4
		uint32 ovlGreenCrossbar: 2; // 6
		uint32 ovlBlueCrossbar: 2; // 8
		uint32 ovlAlphaCrossbar: 2; // 10
		uint32 unknown2: 20;
	};
	uint32 val;
};

// OVL_UPDATE
union OvlUpdate {
	struct {
		uint32 ovlUpdatePending: 1; // 0
		uint32 ovlUpdateTaken: 1; // 1
		uint32 unknown1: 14;
		uint32 ovlUpdateLock: 1; // 16
		uint32 unknown2: 7;
		uint32 ovlDisableMultipleUpdate: 1; // 24
		uint32 unknown3: 7;
	};
	uint32 val;
};

// PHY_AUX_CNTL
union PhyAuxCntl {
	struct {
		uint32 unknown1: 12;
		uint32 auxPadSlewn: 1; // 12
		uint32 unknown2: 1;
		uint32 auxPadWake: 1; // 14
		uint32 unknown3: 1;
		uint32 auxPadRxsel: 1; // 16
		uint32 unknown4: 15;
	};
	uint32 val;
};

// PIPE0_ARBITRATION_CONTROL3
union Pipe0ArbitrationControl3 {
	struct {
		uint32 efficiencyWeight: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PIPE0_DMIF_BUFFER_CONTROL
union Pipe0DmifBufferControl {
	struct {
		uint32 dmifBuffersAllocated: 3; // 0
		uint32 unknown1: 1;
		uint32 dmifBuffersAllocationCompleted: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// PIPE0_MAX_REQUESTS
union Pipe0MaxRequests {
	struct {
		uint32 maxRequests: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PIPE0_PG_CONFIG
union Pipe0PgConfig {
	struct {
		uint32 pipe0PowerForceon: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// PIPE0_PG_ENABLE
union Pipe0PgEnable {
	struct {
		uint32 pipe0PowerGate: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// PIPE0_PG_STATUS
union Pipe0PgStatus {
	struct {
		uint32 pipe0PgfsmReadData: 24; // 0
		uint32 unknown1: 4;
		uint32 pipe0DesiredPwrState: 1; // 28
		uint32 pipe0RequestedPwrState: 1; // 29
		uint32 pipe0PgfsmPwrStatus: 2; // 30
	};
	uint32 val;
};

// PIPE1_ARBITRATION_CONTROL3
union Pipe1ArbitrationControl3 {
	struct {
		uint32 efficiencyWeight: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PIPE1_DMIF_BUFFER_CONTROL
union Pipe1DmifBufferControl {
	struct {
		uint32 dmifBuffersAllocated: 3; // 0
		uint32 unknown1: 1;
		uint32 dmifBuffersAllocationCompleted: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// PIPE1_MAX_REQUESTS
union Pipe1MaxRequests {
	struct {
		uint32 maxRequests: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PIPE1_PG_CONFIG
union Pipe1PgConfig {
	struct {
		uint32 pipe1PowerForceon: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// PIPE1_PG_ENABLE
union Pipe1PgEnable {
	struct {
		uint32 pipe1PowerGate: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// PIPE1_PG_STATUS
union Pipe1PgStatus {
	struct {
		uint32 pipe1PgfsmReadData: 24; // 0
		uint32 unknown1: 4;
		uint32 pipe1DesiredPwrState: 1; // 28
		uint32 pipe1RequestedPwrState: 1; // 29
		uint32 pipe1PgfsmPwrStatus: 2; // 30
	};
	uint32 val;
};

// PIPE2_ARBITRATION_CONTROL3
union Pipe2ArbitrationControl3 {
	struct {
		uint32 efficiencyWeight: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PIPE2_DMIF_BUFFER_CONTROL
union Pipe2DmifBufferControl {
	struct {
		uint32 dmifBuffersAllocated: 3; // 0
		uint32 unknown1: 1;
		uint32 dmifBuffersAllocationCompleted: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// PIPE2_MAX_REQUESTS
union Pipe2MaxRequests {
	struct {
		uint32 maxRequests: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PIPE2_PG_CONFIG
union Pipe2PgConfig {
	struct {
		uint32 pipe2PowerForceon: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// PIPE2_PG_ENABLE
union Pipe2PgEnable {
	struct {
		uint32 pipe2PowerGate: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// PIPE2_PG_STATUS
union Pipe2PgStatus {
	struct {
		uint32 pipe2PgfsmReadData: 24; // 0
		uint32 unknown1: 4;
		uint32 pipe2DesiredPwrState: 1; // 28
		uint32 pipe2RequestedPwrState: 1; // 29
		uint32 pipe2PgfsmPwrStatus: 2; // 30
	};
	uint32 val;
};

// PIPE3_ARBITRATION_CONTROL3
union Pipe3ArbitrationControl3 {
	struct {
		uint32 efficiencyWeight: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PIPE3_DMIF_BUFFER_CONTROL
union Pipe3DmifBufferControl {
	struct {
		uint32 dmifBuffersAllocated: 3; // 0
		uint32 unknown1: 1;
		uint32 dmifBuffersAllocationCompleted: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// PIPE3_MAX_REQUESTS
union Pipe3MaxRequests {
	struct {
		uint32 maxRequests: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PIPE3_PG_CONFIG
union Pipe3PgConfig {
	struct {
		uint32 pipe3PowerForceon: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// PIPE3_PG_ENABLE
union Pipe3PgEnable {
	struct {
		uint32 pipe3PowerGate: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// PIPE3_PG_STATUS
union Pipe3PgStatus {
	struct {
		uint32 pipe3PgfsmReadData: 24; // 0
		uint32 unknown1: 4;
		uint32 pipe3DesiredPwrState: 1; // 28
		uint32 pipe3RequestedPwrState: 1; // 29
		uint32 pipe3PgfsmPwrStatus: 2; // 30
	};
	uint32 val;
};

// PIPE4_ARBITRATION_CONTROL3
union Pipe4ArbitrationControl3 {
	struct {
		uint32 efficiencyWeight: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PIPE4_DMIF_BUFFER_CONTROL
union Pipe4DmifBufferControl {
	struct {
		uint32 dmifBuffersAllocated: 3; // 0
		uint32 unknown1: 1;
		uint32 dmifBuffersAllocationCompleted: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// PIPE4_MAX_REQUESTS
union Pipe4MaxRequests {
	struct {
		uint32 maxRequests: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PIPE4_PG_CONFIG
union Pipe4PgConfig {
	struct {
		uint32 pipe4PowerForceon: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// PIPE4_PG_ENABLE
union Pipe4PgEnable {
	struct {
		uint32 pipe4PowerGate: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// PIPE4_PG_STATUS
union Pipe4PgStatus {
	struct {
		uint32 pipe4PgfsmReadData: 24; // 0
		uint32 unknown1: 4;
		uint32 pipe4DesiredPwrState: 1; // 28
		uint32 pipe4RequestedPwrState: 1; // 29
		uint32 pipe4PgfsmPwrStatus: 2; // 30
	};
	uint32 val;
};

// PIPE5_ARBITRATION_CONTROL3
union Pipe5ArbitrationControl3 {
	struct {
		uint32 efficiencyWeight: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PIPE5_DMIF_BUFFER_CONTROL
union Pipe5DmifBufferControl {
	struct {
		uint32 dmifBuffersAllocated: 3; // 0
		uint32 unknown1: 1;
		uint32 dmifBuffersAllocationCompleted: 1; // 4
		uint32 unknown2: 27;
	};
	uint32 val;
};

// PIPE5_MAX_REQUESTS
union Pipe5MaxRequests {
	struct {
		uint32 maxRequests: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// PIPE5_PG_CONFIG
union Pipe5PgConfig {
	struct {
		uint32 pipe5PowerForceon: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// PIPE5_PG_ENABLE
union Pipe5PgEnable {
	struct {
		uint32 pipe5PowerGate: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// PIPE5_PG_STATUS
union Pipe5PgStatus {
	struct {
		uint32 pipe5PgfsmReadData: 24; // 0
		uint32 unknown1: 4;
		uint32 pipe5DesiredPwrState: 1; // 28
		uint32 pipe5RequestedPwrState: 1; // 29
		uint32 pipe5PgfsmPwrStatus: 2; // 30
	};
	uint32 val;
};

// PIXCLK0_RESYNC_CNTL
union Pixclk0ResyncCntl {
	struct {
		uint32 pixclk0ResyncEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 dccgDeepColorCntl0: 2; // 4
		uint32 unknown2: 26;
	};
	uint32 val;
};

// PIXCLK1_RESYNC_CNTL
union Pixclk1ResyncCntl {
	struct {
		uint32 pixclk1ResyncEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 dccgDeepColorCntl1: 2; // 4
		uint32 unknown2: 26;
	};
	uint32 val;
};

// PIXCLK2_RESYNC_CNTL
union Pixclk2ResyncCntl {
	struct {
		uint32 pixclk2ResyncEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 dccgDeepColorCntl2: 2; // 4
		uint32 unknown2: 26;
	};
	uint32 val;
};

// PLL_ANALOG
union PllAnalog {
	struct {
		uint32 pllCalMode: 5; // 0
		uint32 pllPfdPulseSel: 2; // 5
		uint32 unknown1: 1;
		uint32 pllCp: 4; // 8
		uint32 pllLfMode: 9; // 12
		uint32 unknown2: 3;
		uint32 pllIbias: 8; // 24
	};
	uint32 val;
};

// PLL_CNTL
union PllCntl {
	struct {
		uint32 pllReset: 1; // 0
		uint32 pllPowerDown: 1; // 1
		uint32 pllBypassCal: 1; // 2
		uint32 pllPostDivSrc: 1; // 3
		uint32 pllVcoref: 2; // 4
		uint32 pllPcieRefclkSel: 1; // 6
		uint32 pllAntiglitchResetb: 1; // 7
		uint32 pllCalref: 2; // 8
		uint32 pllCalBypassRefdiv: 1; // 10
		uint32 pllRefclkSel: 2; // 11
		uint32 pllAntiGlitchReset: 1; // 13
		uint32 unknown1: 2;
		uint32 pllRefDivSrc: 3; // 16
		uint32 pllLockFreqSel: 1; // 19
		uint32 pllCalibDone: 1; // 20
		uint32 pllLocked: 1; // 21
		uint32 unknown2: 2;
		uint32 pllTimingModeStatus: 2; // 24
		uint32 pllDigSpare: 6; // 26
	};
	uint32 val;
};

// PLL_DEBUG_CNTL
union PllDebugCntl {
	struct {
		uint32 pllDebugSignalsEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 pllDebugMuxoutSel: 4; // 4
		uint32 pllDebugClkSel: 4; // 8
		uint32 unknown2: 20;
	};
	uint32 val;
};

// PLL_DISPCLK_CURRENT_DTO_PHASE
union PllDispclkCurrentDtoPhase {
	struct {
		uint32 pllDispclkCurrentDtoPhase: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// PLL_DISPCLK_DTO_CNTL
union PllDispclkDtoCntl {
	struct {
		uint32 pllDispclkDtoPhase: 9; // 0
		uint32 unknown1: 7;
		uint32 pllDispclkDtoDis: 1; // 16
		uint32 pllDispclkDtoUpdateMode: 2; // 17
		uint32 unknown2: 1;
		uint32 pllDispclkDtoUpdatePending: 1; // 20
		uint32 pllDispclkDtoUpdateReq: 1; // 21
		uint32 pllDispclkDtoUpdateAck: 1; // 22
		uint32 unknown3: 1;
		uint32 pllDispclkDtoComplDelay: 8; // 24
	};
	uint32 val;
};

// PLL_DS_CNTL
union PllDsCntl {
	struct {
		uint32 pllDsFrac: 16; // 0
		uint32 pllDsOrder: 2; // 16
		uint32 pllDsMode: 1; // 18
		uint32 pllDsPrbsEn: 1; // 19
		uint32 unknown1: 12;
	};
	uint32 val;
};

// PLL_FB_DIV
union PllFbDiv {
	struct {
		uint32 pllFbDivFraction: 4; // 0
		uint32 pllFbDivFractionCntl: 2; // 4
		uint32 unknown1: 10;
		uint32 pllFbDiv: 12; // 16
		uint32 unknown2: 4;
	};
	uint32 val;
};

// PLL_IDCLK_CNTL
union PllIdclkCntl {
	struct {
		uint32 pllLtdpIdclkEn: 1; // 0
		uint32 pllLtdpIdclkDiffEn: 1; // 1
		uint32 pllTmdpIdclkEn: 1; // 2
		uint32 pllTmdpIdclkDiffEn: 1; // 3
		uint32 pllUniphyIdclkDiffEn: 1; // 4
		uint32 unknown1: 3;
		uint32 pllDiffPostDivReset: 1; // 8
		uint32 unknown2: 3;
		uint32 pllDiffPostDivSelect: 1; // 12
		uint32 unknown3: 3;
		uint32 pllDiffPostDiv: 4; // 16
		uint32 unknown4: 12;
	};
	uint32 val;
};

// PLL_POST_DIV
union PllPostDiv {
	struct {
		uint32 pllPostDivPixclk: 7; // 0
		uint32 pllPostDiv1p5Dispclk: 1; // 7
		uint32 pllPostDivDvoclk: 7; // 8
		uint32 pllPostDiv1p5Dprefclk: 1; // 15
		uint32 pllPostDivIdclk: 7; // 16
		uint32 unknown1: 9;
	};
	uint32 val;
};

// PLL_REF_DIV
union PllRefDiv {
	struct {
		uint32 pllRefDiv: 10; // 0
		uint32 unknown1: 2;
		uint32 pllCalibrationRefDiv: 4; // 12
		uint32 unknown2: 16;
	};
	uint32 val;
};

// PLL_SS_AMOUNT_DSFRAC
union PllSsAmountDsfrac {
	struct {
		uint32 pllSsAmountDsfrac: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// PLL_SS_CNTL
union PllSsCntl {
	struct {
		uint32 pllSsAmountFbdiv: 8; // 0
		uint32 pllSsAmountNfracSlip: 4; // 8
		uint32 pllSsEn: 1; // 12
		uint32 pllSsMode: 1; // 13
		uint32 unknown1: 2;
		uint32 pllSsStepSizeDsfrac: 16; // 16
	};
	uint32 val;
};

// PLL_UNLOCK_DETECT_CNTL
union PllUnlockDetectCntl {
	struct {
		uint32 pllUnlockDetectEnable: 1; // 0
		uint32 pllUnlockDetRes100Select: 1; // 1
		uint32 pllUnlockStickyStatus: 1; // 2
		uint32 pllUnlockStickyClear: 1; // 3
		uint32 pllUnlockDetCount: 3; // 4
		uint32 unknown1: 25;
	};
	uint32 val;
};

// PLL_UPDATE_CNTL
union PllUpdateCntl {
	struct {
		uint32 pllUpdatePending: 1; // 0
		uint32 unknown1: 7;
		uint32 pllUpdatePoint: 1; // 8
		uint32 unknown2: 7;
		uint32 pllAutoResetDisable: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// PLL_UPDATE_LOCK
union PllUpdateLock {
	struct {
		uint32 pllUpdateLock: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// PLL_VREG_CNTL
union PllVregCntl {
	struct {
		uint32 pllVregCntl: 20; // 0
		uint32 unknown1: 6;
		uint32 pllVrefSel: 1; // 26
		uint32 unknown2: 1;
		uint32 pllVregBias: 4; // 28
	};
	uint32 val;
};

// PRESCALE_GRPH_CONTROL
union PrescaleGrphControl {
	struct {
		uint32 grphPrescaleSelect: 1; // 0
		uint32 grphPrescaleRSign: 1; // 1
		uint32 grphPrescaleGSign: 1; // 2
		uint32 grphPrescaleBSign: 1; // 3
		uint32 grphPrescaleBypass: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// PRESCALE_OVL_CONTROL
union PrescaleOvlControl {
	struct {
		uint32 ovlPrescaleSelect: 1; // 0
		uint32 ovlPrescaleCbSign: 1; // 1
		uint32 ovlPrescaleYSign: 1; // 2
		uint32 ovlPrescaleCrSign: 1; // 3
		uint32 ovlPrescaleBypass: 1; // 4
		uint32 unknown1: 27;
	};
	uint32 val;
};

// PRESCALE_VALUES_GRPH_B
union PrescaleValuesGrphB {
	struct {
		uint32 grphPrescaleBiasB: 16; // 0
		uint32 grphPrescaleScaleB: 16; // 16
	};
	uint32 val;
};

// PRESCALE_VALUES_GRPH_G
union PrescaleValuesGrphG {
	struct {
		uint32 grphPrescaleBiasG: 16; // 0
		uint32 grphPrescaleScaleG: 16; // 16
	};
	uint32 val;
};

// PRESCALE_VALUES_GRPH_R
union PrescaleValuesGrphR {
	struct {
		uint32 grphPrescaleBiasR: 16; // 0
		uint32 grphPrescaleScaleR: 16; // 16
	};
	uint32 val;
};

// PRESCALE_VALUES_OVL_CB
union PrescaleValuesOvlCb {
	struct {
		uint32 ovlPrescaleBiasCb: 16; // 0
		uint32 ovlPrescaleScaleCb: 16; // 16
	};
	uint32 val;
};

// PRESCALE_VALUES_OVL_CR
union PrescaleValuesOvlCr {
	struct {
		uint32 ovlPrescaleBiasCr: 16; // 0
		uint32 ovlPrescaleScaleCr: 16; // 16
	};
	uint32 val;
};

// PRESCALE_VALUES_OVL_Y
union PrescaleValuesOvlY {
	struct {
		uint32 ovlPrescaleBiasY: 16; // 0
		uint32 ovlPrescaleScaleY: 16; // 16
	};
	uint32 val;
};

// PRIORITY_A_CNT
union PriorityACnt {
	struct {
		uint32 priorityMarkA: 15; // 0
		uint32 unknown1: 1;
		uint32 priorityAOff: 1; // 16
		uint32 unknown2: 3;
		uint32 priorityAAlwaysOn: 1; // 20
		uint32 unknown3: 3;
		uint32 priorityAForceMask: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// PRIORITY_B_CNT
union PriorityBCnt {
	struct {
		uint32 priorityMarkB: 15; // 0
		uint32 unknown1: 1;
		uint32 priorityBOff: 1; // 16
		uint32 unknown2: 3;
		uint32 priorityBAlwaysOn: 1; // 20
		uint32 unknown3: 3;
		uint32 priorityBForceMask: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// REGAMMA_CNTLA_END_CNTL1
union RegammaCntlaEndCntl1 {
	struct {
		uint32 regammaCntlaExpRegionEnd: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// REGAMMA_CNTLA_END_CNTL2
union RegammaCntlaEndCntl2 {
	struct {
		uint32 regammaCntlaExpRegionEndSlope: 16; // 0
		uint32 regammaCntlaExpRegionEndBase: 16; // 16
	};
	uint32 val;
};

// REGAMMA_CNTLA_REGION_0_1
union RegammaCntlaRegion0_1 {
	struct {
		uint32 regammaCntlaExpRegion0LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlaExpRegion0NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlaExpRegion1LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlaExpRegion1NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLA_REGION_10_11
union RegammaCntlaRegion10_11 {
	struct {
		uint32 regammaCntlaExpRegion10LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlaExpRegion10NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlaExpRegion11LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlaExpRegion11NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLA_REGION_12_13
union RegammaCntlaRegion12_13 {
	struct {
		uint32 regammaCntlaExpRegion12LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlaExpRegion12NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlaExpRegion13LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlaExpRegion13NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLA_REGION_14_15
union RegammaCntlaRegion14_15 {
	struct {
		uint32 regammaCntlaExpRegion14LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlaExpRegion14NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlaExpRegion15LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlaExpRegion15NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLA_REGION_2_3
union RegammaCntlaRegion2_3 {
	struct {
		uint32 regammaCntlaExpRegion2LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlaExpRegion2NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlaExpRegion3LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlaExpRegion3NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLA_REGION_4_5
union RegammaCntlaRegion4_5 {
	struct {
		uint32 regammaCntlaExpRegion4LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlaExpRegion4NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlaExpRegion5LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlaExpRegion5NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLA_REGION_6_7
union RegammaCntlaRegion6_7 {
	struct {
		uint32 regammaCntlaExpRegion6LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlaExpRegion6NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlaExpRegion7LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlaExpRegion7NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLA_REGION_8_9
union RegammaCntlaRegion8_9 {
	struct {
		uint32 regammaCntlaExpRegion8LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlaExpRegion8NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlaExpRegion9LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlaExpRegion9NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLA_SLOPE_CNTL
union RegammaCntlaSlopeCntl {
	struct {
		uint32 regammaCntlaExpRegionLinearSlope: 18; // 0
		uint32 unknown1: 14;
	};
	uint32 val;
};

// REGAMMA_CNTLA_START_CNTL
union RegammaCntlaStartCntl {
	struct {
		uint32 regammaCntlaExpRegionStart: 18; // 0
		uint32 unknown1: 2;
		uint32 regammaCntlaExpRegionStartSegment: 7; // 20
		uint32 unknown2: 5;
	};
	uint32 val;
};

// REGAMMA_CNTLB_END_CNTL1
union RegammaCntlbEndCntl1 {
	struct {
		uint32 regammaCntlbExpRegionEnd: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// REGAMMA_CNTLB_END_CNTL2
union RegammaCntlbEndCntl2 {
	struct {
		uint32 regammaCntlbExpRegionEndSlope: 16; // 0
		uint32 regammaCntlbExpRegionEndBase: 16; // 16
	};
	uint32 val;
};

// REGAMMA_CNTLB_REGION_0_1
union RegammaCntlbRegion0_1 {
	struct {
		uint32 regammaCntlbExpRegion0LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlbExpRegion0NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlbExpRegion1LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlbExpRegion1NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLB_REGION_10_11
union RegammaCntlbRegion10_11 {
	struct {
		uint32 regammaCntlbExpRegion10LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlbExpRegion10NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlbExpRegion11LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlbExpRegion11NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLB_REGION_12_13
union RegammaCntlbRegion12_13 {
	struct {
		uint32 regammaCntlbExpRegion12LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlbExpRegion12NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlbExpRegion13LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlbExpRegion13NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLB_REGION_14_15
union RegammaCntlbRegion14_15 {
	struct {
		uint32 regammaCntlbExpRegion14LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlbExpRegion14NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlbExpRegion15LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlbExpRegion15NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLB_REGION_2_3
union RegammaCntlbRegion2_3 {
	struct {
		uint32 regammaCntlbExpRegion2LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlbExpRegion2NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlbExpRegion3LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlbExpRegion3NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLB_REGION_4_5
union RegammaCntlbRegion4_5 {
	struct {
		uint32 regammaCntlbExpRegion4LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlbExpRegion4NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlbExpRegion5LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlbExpRegion5NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLB_REGION_6_7
union RegammaCntlbRegion6_7 {
	struct {
		uint32 regammaCntlbExpRegion6LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlbExpRegion6NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlbExpRegion7LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlbExpRegion7NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLB_REGION_8_9
union RegammaCntlbRegion8_9 {
	struct {
		uint32 regammaCntlbExpRegion8LutOffset: 9; // 0
		uint32 unknown1: 3;
		uint32 regammaCntlbExpRegion8NumSegments: 3; // 12
		uint32 unknown2: 1;
		uint32 regammaCntlbExpRegion9LutOffset: 9; // 16
		uint32 unknown3: 3;
		uint32 regammaCntlbExpRegion9NumSegments: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// REGAMMA_CNTLB_SLOPE_CNTL
union RegammaCntlbSlopeCntl {
	struct {
		uint32 regammaCntlbExpRegionLinearSlope: 18; // 0
		uint32 unknown1: 14;
	};
	uint32 val;
};

// REGAMMA_CNTLB_START_CNTL
union RegammaCntlbStartCntl {
	struct {
		uint32 regammaCntlbExpRegionStart: 18; // 0
		uint32 unknown1: 2;
		uint32 regammaCntlbExpRegionStartSegment: 7; // 20
		uint32 unknown2: 5;
	};
	uint32 val;
};

// REGAMMA_CONTROL
union RegammaControl {
	struct {
		uint32 grphRegammaMode: 3; // 0
		uint32 unknown1: 1;
		uint32 ovlRegammaMode: 3; // 4
		uint32 unknown2: 25;
	};
	uint32 val;
};

// REGAMMA_LUT_DATA
union RegammaLutData {
	struct {
		uint32 regammaLutData: 19; // 0
		uint32 unknown1: 13;
	};
	uint32 val;
};

// REGAMMA_LUT_INDEX
union RegammaLutIndex {
	struct {
		uint32 regammaLutIndex: 9; // 0
		uint32 unknown1: 23;
	};
	uint32 val;
};

// REGAMMA_LUT_WRITE_EN_MASK
union RegammaLutWriteEnMask {
	struct {
		uint32 regammaLutWriteEnMask: 3; // 0
		uint32 unknown1: 29;
	};
	uint32 val;
};

// SCLK_CGTT_BLK_CTRL_REG
union SclkCgttBlkCtrlReg {
	struct {
		uint32 sclkTurnOnDelay: 4; // 0
		uint32 sclkTurnOffDelay: 8; // 4
		uint32 unknown1: 20;
	};
	uint32 val;
};

// SCL_ALU_CONTROL
union SclAluControl {
	struct {
		uint32 sclAluDisable: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// SCL_BYPASS_CONTROL
union SclBypassControl {
	struct {
		uint32 sclBypassMode: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// SCL_COEF_RAM_CONFLICT_STATUS
union SclCoefRamConflictStatus {
	struct {
		uint32 sclHostConflictFlag: 1; // 0
		uint32 unknown1: 7;
		uint32 sclHostConflictAck: 1; // 8
		uint32 unknown2: 3;
		uint32 sclHostConflictMask: 1; // 12
		uint32 unknown3: 3;
		uint32 sclHostConflictIntStatus: 1; // 16
		uint32 unknown4: 15;
	};
	uint32 val;
};

// SCL_COEF_RAM_SELECT
union SclCoefRamSelect {
	struct {
		uint32 sclCRamTapPairIdx: 4; // 0
		uint32 unknown1: 4;
		uint32 sclCRamPhase: 4; // 8
		uint32 unknown2: 4;
		uint32 sclCRamFilterType: 2; // 16
		uint32 unknown3: 14;
	};
	uint32 val;
};

// SCL_COEF_RAM_TAP_DATA
union SclCoefRamTapData {
	struct {
		uint32 sclCRamEvenTapCoef: 14; // 0
		uint32 unknown1: 1;
		uint32 sclCRamEvenTapCoefEn: 1; // 15
		uint32 sclCRamOddTapCoef: 14; // 16
		uint32 unknown2: 1;
		uint32 sclCRamOddTapCoefEn: 1; // 31
	};
	uint32 val;
};

// SCL_DEBUG
union SclDebug {
	struct {
		uint32 sclDebug: 32; // 0
	};
	uint32 val;
};

// SCL_DEBUG2
union SclDebug2 {
	struct {
		uint32 sclDebug2: 32; // 0
	};
	uint32 val;
};

// SCL_F_SHARP_CONTROL
union SclFSharpControl {
	struct {
		uint32 sclHfSharpScaleFactor: 3; // 0
		uint32 unknown1: 1;
		uint32 sclHfSharpEn: 1; // 4
		uint32 unknown2: 3;
		uint32 sclVfSharpScaleFactor: 3; // 8
		uint32 unknown3: 1;
		uint32 sclVfSharpEn: 1; // 12
		uint32 unknown4: 19;
	};
	uint32 val;
};

// SCL_HORZ_FILTER_CONTROL
union SclHorzFilterControl {
	struct {
		uint32 sclHFilterPickNearest: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// SCL_HORZ_FILTER_INIT_CHROMA
union SclHorzFilterInitChroma {
	struct {
		uint32 sclHInitFracCbcr: 16; // 0
		uint32 sclHInitIntCbcr: 3; // 16
		uint32 unknown1: 13;
	};
	uint32 val;
};

// SCL_HORZ_FILTER_INIT_RGB_LUMA
union SclHorzFilterInitRgbLuma {
	struct {
		uint32 sclHInitFracRgbY: 16; // 0
		uint32 sclHInitIntRgbY: 4; // 16
		uint32 unknown1: 12;
	};
	uint32 val;
};

// SCL_HORZ_FILTER_SCALE_RATIO
union SclHorzFilterScaleRatio {
	struct {
		uint32 sclHScaleRatio: 26; // 0
		uint32 unknown1: 6;
	};
	uint32 val;
};

// SCL_MANUAL_REPLICATE_CONTROL
union SclManualReplicateControl {
	struct {
		uint32 sclVManualReplicateFactor: 4; // 0
		uint32 unknown1: 4;
		uint32 sclHManualReplicateFactor: 4; // 8
		uint32 unknown2: 20;
	};
	uint32 val;
};

// SCL_MODE_CHANGE_DET1
union SclModeChangeDet1 {
	struct {
		uint32 sclModeChange: 1; // 0
		uint32 unknown1: 3;
		uint32 sclModeChangeAck: 1; // 4
		uint32 unknown2: 2;
		uint32 sclAluHScaleRatio: 21; // 7
		uint32 unknown3: 4;
	};
	uint32 val;
};

// SCL_MODE_CHANGE_DET2
union SclModeChangeDet2 {
	struct {
		uint32 sclAluVScaleRatio: 21; // 0
		uint32 unknown1: 11;
	};
	uint32 val;
};

// SCL_MODE_CHANGE_DET3
union SclModeChangeDet3 {
	struct {
		uint32 sclAluSourceHeight: 14; // 0
		uint32 unknown1: 2;
		uint32 sclAluSourceWidth: 14; // 16
		uint32 unknown2: 2;
	};
	uint32 val;
};

// SCL_MODE_CHANGE_MASK
union SclModeChangeMask {
	struct {
		uint32 sclModeChangeMask: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// SCL_TAP_CONTROL
union SclTapControl {
	struct {
		uint32 sclVNumOfTaps: 3; // 0
		uint32 unknown1: 5;
		uint32 sclHNumOfTaps: 4; // 8
		uint32 unknown2: 20;
	};
	uint32 val;
};

// SCL_TEST_DEBUG_DATA
union SclTestDebugData {
	struct {
		uint32 sclTestDebugData: 32; // 0
	};
	uint32 val;
};

// SCL_TEST_DEBUG_INDEX
union SclTestDebugIndex {
	struct {
		uint32 sclTestDebugIndex: 8; // 0
		uint32 sclTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// SCL_UPDATE
union SclUpdate {
	struct {
		uint32 sclUpdatePending: 1; // 0
		uint32 unknown1: 7;
		uint32 sclUpdateTaken: 1; // 8
		uint32 unknown2: 7;
		uint32 sclUpdateLock: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// SCL_VERT_FILTER_CONTROL
union SclVertFilterControl {
	struct {
		uint32 sclVFilterPickNearest: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// SCL_VERT_FILTER_INIT
union SclVertFilterInit {
	struct {
		uint32 sclVInitFrac: 16; // 0
		uint32 sclVInitInt: 3; // 16
		uint32 unknown1: 13;
	};
	uint32 val;
};

// SCL_VERT_FILTER_INIT_BOT
union SclVertFilterInitBot {
	struct {
		uint32 sclVInitFracBot: 16; // 0
		uint32 sclVInitIntBot: 3; // 16
		uint32 unknown1: 13;
	};
	uint32 val;
};

// SCL_VERT_FILTER_SCALE_RATIO
union SclVertFilterScaleRatio {
	struct {
		uint32 sclVScaleRatio: 26; // 0
		uint32 unknown1: 6;
	};
	uint32 val;
};

// SEQ00
union Seq00 {
	struct {
		uint32 seqRst0b: 1; // 0
		uint32 seqRst1b: 1; // 1
		uint32 unknown1: 30;
	};
	uint32 val;
};

// SEQ01
union Seq01 {
	struct {
		uint32 seqDot8: 1; // 0
		uint32 unknown1: 1;
		uint32 seqShift2: 1; // 2
		uint32 seqPclkby2: 1; // 3
		uint32 seqShift4: 1; // 4
		uint32 seqMaxbw: 1; // 5
		uint32 unknown2: 26;
	};
	uint32 val;
};

// SEQ02
union Seq02 {
	struct {
		uint32 seqMap0En: 1; // 0
		uint32 seqMap1En: 1; // 1
		uint32 seqMap2En: 1; // 2
		uint32 seqMap3En: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// SEQ03
union Seq03 {
	struct {
		uint32 seqFontB1: 1; // 0
		uint32 seqFontB2: 1; // 1
		uint32 seqFontA1: 1; // 2
		uint32 seqFontA2: 1; // 3
		uint32 seqFontB0: 1; // 4
		uint32 seqFontA0: 1; // 5
		uint32 unknown1: 26;
	};
	uint32 val;
};

// SEQ04
union Seq04 {
	struct {
		uint32 unknown1: 1;
		uint32 seq256k: 1; // 1
		uint32 seqOddeven: 1; // 2
		uint32 seqChain: 1; // 3
		uint32 unknown2: 28;
	};
	uint32 val;
};

// SEQ8_DATA
union Seq8Data {
	struct {
		uint32 seqData: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SEQ8_IDX
union Seq8Idx {
	struct {
		uint32 seqIdx: 3; // 0
		uint32 unknown1: 29;
	};
	uint32 val;
};

// SINK_DESCRIPTION0
union SinkDescription0 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION1
union SinkDescription1 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION10
union SinkDescription10 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION11
union SinkDescription11 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION12
union SinkDescription12 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION13
union SinkDescription13 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION14
union SinkDescription14 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION15
union SinkDescription15 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION16
union SinkDescription16 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION17
union SinkDescription17 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION2
union SinkDescription2 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION3
union SinkDescription3 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION4
union SinkDescription4 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION5
union SinkDescription5 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION6
union SinkDescription6 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION7
union SinkDescription7 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION8
union SinkDescription8 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SINK_DESCRIPTION9
union SinkDescription9 {
	struct {
		uint32 description: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// SLAVE_COMM_CMD_REG
union SlaveCommCmdReg {
	struct {
		uint32 slaveCommCmdRegByte0: 8; // 0
		uint32 slaveCommCmdRegByte1: 8; // 8
		uint32 slaveCommCmdRegByte2: 8; // 16
		uint32 slaveCommCmdRegByte3: 8; // 24
	};
	uint32 val;
};

// SLAVE_COMM_CNTL_REG
union SlaveCommCntlReg {
	struct {
		uint32 slaveCommInterrupt: 1; // 0
		uint32 unknown1: 7;
		uint32 commPortMsgToHostInProgress: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// SLAVE_COMM_DATA_REG1
union SlaveCommDataReg1 {
	struct {
		uint32 slaveCommDataReg1Byte0: 8; // 0
		uint32 slaveCommDataReg1Byte1: 8; // 8
		uint32 slaveCommDataReg1Byte2: 8; // 16
		uint32 slaveCommDataReg1Byte3: 8; // 24
	};
	uint32 val;
};

// SLAVE_COMM_DATA_REG2
union SlaveCommDataReg2 {
	struct {
		uint32 slaveCommDataReg2Byte0: 8; // 0
		uint32 slaveCommDataReg2Byte1: 8; // 8
		uint32 slaveCommDataReg2Byte2: 8; // 16
		uint32 slaveCommDataReg2Byte3: 8; // 24
	};
	uint32 val;
};

// SLAVE_COMM_DATA_REG3
union SlaveCommDataReg3 {
	struct {
		uint32 slaveCommDataReg3Byte0: 8; // 0
		uint32 slaveCommDataReg3Byte1: 8; // 8
		uint32 slaveCommDataReg3Byte2: 8; // 16
		uint32 slaveCommDataReg3Byte3: 8; // 24
	};
	uint32 val;
};

// SYMCLKA_CLOCK_ENABLE
union SymclkaClockEnable {
	struct {
		uint32 symclkaClockEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 symclkaFeForceEn: 1; // 4
		uint32 unknown2: 3;
		uint32 symclkaFeForceSrc: 3; // 8
		uint32 unknown3: 21;
	};
	uint32 val;
};

// SYMCLKB_CLOCK_ENABLE
union SymclkbClockEnable {
	struct {
		uint32 symclkbClockEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 symclkbFeForceEn: 1; // 4
		uint32 unknown2: 3;
		uint32 symclkbFeForceSrc: 3; // 8
		uint32 unknown3: 21;
	};
	uint32 val;
};

// SYMCLKC_CLOCK_ENABLE
union SymclkcClockEnable {
	struct {
		uint32 symclkcClockEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 symclkcFeForceEn: 1; // 4
		uint32 unknown2: 3;
		uint32 symclkcFeForceSrc: 3; // 8
		uint32 unknown3: 21;
	};
	uint32 val;
};

// SYMCLKD_CLOCK_ENABLE
union SymclkdClockEnable {
	struct {
		uint32 symclkdClockEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 symclkdFeForceEn: 1; // 4
		uint32 unknown2: 3;
		uint32 symclkdFeForceSrc: 3; // 8
		uint32 unknown3: 21;
	};
	uint32 val;
};

// SYMCLKE_CLOCK_ENABLE
union SymclkeClockEnable {
	struct {
		uint32 symclkeClockEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 symclkeFeForceEn: 1; // 4
		uint32 unknown2: 3;
		uint32 symclkeFeForceSrc: 3; // 8
		uint32 unknown3: 21;
	};
	uint32 val;
};

// SYMCLKF_CLOCK_ENABLE
union SymclkfClockEnable {
	struct {
		uint32 symclkfClockEnable: 1; // 0
		uint32 unknown1: 3;
		uint32 symclkfFeForceEn: 1; // 4
		uint32 unknown2: 3;
		uint32 symclkfFeForceSrc: 3; // 8
		uint32 unknown3: 21;
	};
	uint32 val;
};

// TMDS_CNTL
union TmdsCntl {
	struct {
		uint32 tmdsSyncPhase: 1; // 0
		uint32 unknown1: 3;
		uint32 tmdsPixelEncoding: 1; // 4
		uint32 unknown2: 3;
		uint32 tmdsColorFormat: 2; // 8
		uint32 unknown3: 22;
	};
	uint32 val;
};

// TMDS_CONTROL0_FEEDBACK
union TmdsControl0Feedback {
	struct {
		uint32 tmdsControl0FeedbackSelect: 2; // 0
		uint32 unknown1: 6;
		uint32 tmdsControl0FeedbackDelay: 2; // 8
		uint32 unknown2: 22;
	};
	uint32 val;
};

// TMDS_CONTROL_CHAR
union TmdsControlChar {
	struct {
		uint32 tmdsControlChar0OutEn: 1; // 0
		uint32 tmdsControlChar1OutEn: 1; // 1
		uint32 tmdsControlChar2OutEn: 1; // 2
		uint32 tmdsControlChar3OutEn: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// TMDS_CTL0_1_GEN_CNTL
union TmdsCtl0_1GenCntl {
	struct {
		uint32 tmdsCtl0DataSel: 4; // 0
		uint32 tmdsCtl0DataDelay: 3; // 4
		uint32 tmdsCtl0DataInvert: 1; // 7
		uint32 tmdsCtl0DataModulation: 2; // 8
		uint32 tmdsCtl0UseFeedbackPath: 1; // 10
		uint32 tmdsCtl0FbSyncCont: 1; // 11
		uint32 tmdsCtl0PatternOutEn: 1; // 12
		uint32 unknown1: 3;
		uint32 tmdsCtl1DataSel: 4; // 16
		uint32 tmdsCtl1DataDelay: 3; // 20
		uint32 tmdsCtl1DataInvert: 1; // 23
		uint32 tmdsCtl1DataModulation: 2; // 24
		uint32 tmdsCtl1UseFeedbackPath: 1; // 26
		uint32 tmdsCtl1FbSyncCont: 1; // 27
		uint32 tmdsCtl1PatternOutEn: 1; // 28
		uint32 unknown2: 2;
		uint32 tmds2bitCounterEn: 1; // 31
	};
	uint32 val;
};

// TMDS_CTL2_3_GEN_CNTL
union TmdsCtl2_3GenCntl {
	struct {
		uint32 tmdsCtl2DataSel: 4; // 0
		uint32 tmdsCtl2DataDelay: 3; // 4
		uint32 tmdsCtl2DataInvert: 1; // 7
		uint32 tmdsCtl2DataModulation: 2; // 8
		uint32 tmdsCtl2UseFeedbackPath: 1; // 10
		uint32 tmdsCtl2FbSyncCont: 1; // 11
		uint32 tmdsCtl2PatternOutEn: 1; // 12
		uint32 unknown1: 3;
		uint32 tmdsCtl3DataSel: 4; // 16
		uint32 tmdsCtl3DataDelay: 3; // 20
		uint32 tmdsCtl3DataInvert: 1; // 23
		uint32 tmdsCtl3DataModulation: 2; // 24
		uint32 tmdsCtl3UseFeedbackPath: 1; // 26
		uint32 tmdsCtl3FbSyncCont: 1; // 27
		uint32 tmdsCtl3PatternOutEn: 1; // 28
		uint32 unknown2: 3;
	};
	uint32 val;
};

// TMDS_CTL_BITS
union TmdsCtlBits {
	struct {
		uint32 tmdsCtl0: 1; // 0
		uint32 unknown1: 7;
		uint32 tmdsCtl1: 1; // 8
		uint32 unknown2: 7;
		uint32 tmdsCtl2: 1; // 16
		uint32 unknown3: 7;
		uint32 tmdsCtl3: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// TMDS_DCBALANCER_CONTROL
union TmdsDcbalancerControl {
	struct {
		uint32 tmdsDcbalancerEn: 1; // 0
		uint32 unknown1: 3;
		uint32 tmdsSyncDcbalEn: 3; // 4
		uint32 unknown2: 1;
		uint32 tmdsDcbalancerTestEn: 1; // 8
		uint32 unknown3: 7;
		uint32 tmdsDcbalancerTestIn: 4; // 16
		uint32 unknown4: 4;
		uint32 tmdsDcbalancerForce: 1; // 24
		uint32 unknown5: 7;
	};
	uint32 val;
};

// TMDS_DEBUG
union TmdsDebug {
	struct {
		uint32 tmdsDebugEn: 1; // 0
		uint32 unknown1: 7;
		uint32 tmdsDebugHsync: 1; // 8
		uint32 tmdsDebugHsyncEn: 1; // 9
		uint32 unknown2: 6;
		uint32 tmdsDebugVsync: 1; // 16
		uint32 tmdsDebugVsyncEn: 1; // 17
		uint32 unknown3: 6;
		uint32 tmdsDebugDe: 1; // 24
		uint32 tmdsDebugDeEn: 1; // 25
		uint32 unknown4: 6;
	};
	uint32 val;
};

// TMDS_STEREOSYNC_CTL_SEL
union TmdsStereosyncCtlSel {
	struct {
		uint32 tmdsStereosyncCtlSel: 2; // 0
		uint32 unknown1: 30;
	};
	uint32 val;
};

// TMDS_SYNC_CHAR_PATTERN_0_1
union TmdsSyncCharPattern0_1 {
	struct {
		uint32 tmdsSyncCharPattern0: 10; // 0
		uint32 unknown1: 6;
		uint32 tmdsSyncCharPattern1: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// TMDS_SYNC_CHAR_PATTERN_2_3
union TmdsSyncCharPattern2_3 {
	struct {
		uint32 tmdsSyncCharPattern2: 10; // 0
		uint32 unknown1: 6;
		uint32 tmdsSyncCharPattern3: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// UNIPHYAB_TPG_CONTROL
union UniphyabTpgControl {
	struct {
		uint32 uniphyabStaticTestPattern: 10; // 0
		uint32 unknown1: 6;
		uint32 uniphyabTpgEn: 1; // 16
		uint32 uniphyabTpgSel: 3; // 17
		uint32 unknown2: 12;
	};
	uint32 val;
};

// UNIPHYAB_TPG_SEED
union UniphyabTpgSeed {
	struct {
		uint32 uniphyabTpgSeed: 23; // 0
		uint32 unknown1: 9;
	};
	uint32 val;
};

// UNIPHYCD_TPG_CONTROL
union UniphycdTpgControl {
	struct {
		uint32 uniphycdStaticTestPattern: 10; // 0
		uint32 unknown1: 6;
		uint32 uniphycdTpgEn: 1; // 16
		uint32 uniphycdTpgSel: 3; // 17
		uint32 unknown2: 12;
	};
	uint32 val;
};

// UNIPHYCD_TPG_SEED
union UniphycdTpgSeed {
	struct {
		uint32 uniphycdTpgSeed: 23; // 0
		uint32 unknown1: 9;
	};
	uint32 val;
};

// UNIPHYEF_TPG_CONTROL
union UniphyefTpgControl {
	struct {
		uint32 uniphyefStaticTestPattern: 10; // 0
		uint32 unknown1: 6;
		uint32 uniphyefTpgEn: 1; // 16
		uint32 uniphyefTpgSel: 3; // 17
		uint32 unknown2: 12;
	};
	uint32 val;
};

// UNIPHYEF_TPG_SEED
union UniphyefTpgSeed {
	struct {
		uint32 uniphyefTpgSeed: 23; // 0
		uint32 unknown1: 9;
	};
	uint32 val;
};

// UNIPHY_ANG_BIST_CNTL
union UniphyAngBistCntl {
	struct {
		uint32 uniphyTestRxEn: 1; // 0
		uint32 uniphyAngBistReset: 1; // 1
		uint32 unknown1: 6;
		uint32 uniphyRxBias: 4; // 8
		uint32 unknown2: 4;
		uint32 uniphyAngBistError: 5; // 16
		uint32 unknown3: 3;
		uint32 uniphyPresetb: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// UNIPHY_CHANNEL_XBAR_CNTL
union UniphyChannelXbarCntl {
	struct {
		uint32 uniphyChannel0XbarSource: 2; // 0
		uint32 unknown1: 6;
		uint32 uniphyChannel1XbarSource: 2; // 8
		uint32 unknown2: 6;
		uint32 uniphyChannel2XbarSource: 2; // 16
		uint32 unknown3: 6;
		uint32 uniphyChannel3XbarSource: 2; // 24
		uint32 unknown4: 6;
	};
	uint32 val;
};

// UNIPHY_DATA_SYNCHRONIZATION
union UniphyDataSynchronization {
	struct {
		uint32 uniphyDsynsel: 1; // 0
		uint32 unknown1: 3;
		uint32 uniphyDsynLevel: 2; // 4
		uint32 uniphyDsynError: 1; // 6
		uint32 unknown2: 1;
		uint32 uniphySourceSelect: 1; // 8
		uint32 unknown3: 3;
		uint32 uniphyLinkEnable: 1; // 12
		uint32 unknown4: 3;
		uint32 uniphyDualLinkPhase: 1; // 16
		uint32 unknown5: 15;
	};
	uint32 val;
};

// UNIPHY_IMPCAL_LINKA
union UniphyImpcalLinka {
	struct {
		uint32 uniphyImpcalEnableLinka: 1; // 0
		uint32 unknown1: 7;
		uint32 uniphyImpcalCaloutLinka: 1; // 8
		uint32 uniphyCaloutErrorLinka: 1; // 9
		uint32 uniphyCaloutErrorLinkaAk: 1; // 10
		uint32 unknown2: 5;
		uint32 uniphyImpcalValueLinka: 4; // 16
		uint32 uniphyImpcalStepDelayLinka: 4; // 20
		uint32 uniphyImpcalOverrideLinka: 4; // 24
		uint32 uniphyImpcalOverrideEnableLinka: 1; // 28
		uint32 unknown3: 1;
		uint32 uniphyImpcalSelLinka: 1; // 30
		uint32 unknown4: 1;
	};
	uint32 val;
};

// UNIPHY_IMPCAL_LINKB
union UniphyImpcalLinkb {
	struct {
		uint32 uniphyImpcalEnableLinkb: 1; // 0
		uint32 unknown1: 7;
		uint32 uniphyImpcalCaloutLinkb: 1; // 8
		uint32 uniphyCaloutErrorLinkb: 1; // 9
		uint32 uniphyCaloutErrorLinkbAk: 1; // 10
		uint32 unknown2: 5;
		uint32 uniphyImpcalValueLinkb: 4; // 16
		uint32 uniphyImpcalStepDelayLinkb: 4; // 20
		uint32 uniphyImpcalOverrideLinkb: 4; // 24
		uint32 uniphyImpcalOverrideEnableLinkb: 1; // 28
		uint32 unknown3: 1;
		uint32 uniphyImpcalSelLinkb: 1; // 30
		uint32 unknown4: 1;
	};
	uint32 val;
};

// UNIPHY_IMPCAL_LINKC
union UniphyImpcalLinkc {
	struct {
		uint32 uniphyImpcalEnableLinkc: 1; // 0
		uint32 unknown1: 7;
		uint32 uniphyImpcalCaloutLinkc: 1; // 8
		uint32 uniphyCaloutErrorLinkc: 1; // 9
		uint32 uniphyCaloutErrorLinkcAk: 1; // 10
		uint32 unknown2: 5;
		uint32 uniphyImpcalValueLinkc: 4; // 16
		uint32 uniphyImpcalStepDelayLinkc: 4; // 20
		uint32 uniphyImpcalOverrideLinkc: 4; // 24
		uint32 uniphyImpcalOverrideEnableLinkc: 1; // 28
		uint32 unknown3: 1;
		uint32 uniphyImpcalSelLinkc: 1; // 30
		uint32 unknown4: 1;
	};
	uint32 val;
};

// UNIPHY_IMPCAL_LINKD
union UniphyImpcalLinkd {
	struct {
		uint32 uniphyImpcalEnableLinkd: 1; // 0
		uint32 unknown1: 7;
		uint32 uniphyImpcalCaloutLinkd: 1; // 8
		uint32 uniphyCaloutErrorLinkd: 1; // 9
		uint32 uniphyCaloutErrorLinkdAk: 1; // 10
		uint32 unknown2: 5;
		uint32 uniphyImpcalValueLinkd: 4; // 16
		uint32 uniphyImpcalStepDelayLinkd: 4; // 20
		uint32 uniphyImpcalOverrideLinkd: 4; // 24
		uint32 uniphyImpcalOverrideEnableLinkd: 1; // 28
		uint32 unknown3: 1;
		uint32 uniphyImpcalSelLinkd: 1; // 30
		uint32 unknown4: 1;
	};
	uint32 val;
};

// UNIPHY_IMPCAL_LINKE
union UniphyImpcalLinke {
	struct {
		uint32 uniphyImpcalEnableLinke: 1; // 0
		uint32 unknown1: 7;
		uint32 uniphyImpcalCaloutLinke: 1; // 8
		uint32 uniphyCaloutErrorLinke: 1; // 9
		uint32 uniphyCaloutErrorLinkeAk: 1; // 10
		uint32 unknown2: 5;
		uint32 uniphyImpcalValueLinke: 4; // 16
		uint32 uniphyImpcalStepDelayLinke: 4; // 20
		uint32 uniphyImpcalOverrideLinke: 4; // 24
		uint32 uniphyImpcalOverrideEnableLinke: 1; // 28
		uint32 unknown3: 1;
		uint32 uniphyImpcalSelLinke: 1; // 30
		uint32 unknown4: 1;
	};
	uint32 val;
};

// UNIPHY_IMPCAL_LINKF
union UniphyImpcalLinkf {
	struct {
		uint32 uniphyImpcalEnableLinkf: 1; // 0
		uint32 unknown1: 7;
		uint32 uniphyImpcalCaloutLinkf: 1; // 8
		uint32 uniphyCaloutErrorLinkf: 1; // 9
		uint32 uniphyCaloutErrorLinkfAk: 1; // 10
		uint32 unknown2: 5;
		uint32 uniphyImpcalValueLinkf: 4; // 16
		uint32 uniphyImpcalStepDelayLinkf: 4; // 20
		uint32 uniphyImpcalOverrideLinkf: 4; // 24
		uint32 uniphyImpcalOverrideEnableLinkf: 1; // 28
		uint32 unknown3: 1;
		uint32 uniphyImpcalSelLinkf: 1; // 30
		uint32 unknown4: 1;
	};
	uint32 val;
};

// UNIPHY_IMPCAL_PERIOD
union UniphyImpcalPeriod {
	struct {
		uint32 uniphyImpcalPeriod: 32; // 0
	};
	uint32 val;
};

// UNIPHY_IMPCAL_PSW_AB
union UniphyImpcalPswAb {
	struct {
		uint32 uniphyImpcalPswLinka: 15; // 0
		uint32 unknown1: 1;
		uint32 uniphyImpcalPswLinkb: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// UNIPHY_IMPCAL_PSW_CD
union UniphyImpcalPswCd {
	struct {
		uint32 uniphyImpcalPswLinkc: 15; // 0
		uint32 unknown1: 1;
		uint32 uniphyImpcalPswLinkd: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// UNIPHY_IMPCAL_PSW_EF
union UniphyImpcalPswEf {
	struct {
		uint32 uniphyImpcalPswLinke: 15; // 0
		uint32 unknown1: 1;
		uint32 uniphyImpcalPswLinkf: 15; // 16
		uint32 unknown2: 1;
	};
	uint32 val;
};

// UNIPHY_LINK_CNTL
union UniphyLinkCntl {
	struct {
		uint32 uniphyPfreqchg: 1; // 0
		uint32 unknown1: 3;
		uint32 uniphyPixvldReset: 1; // 4
		uint32 unknown2: 3;
		uint32 uniphyMinimumPixvldLowDuration: 3; // 8
		uint32 unknown3: 1;
		uint32 uniphyChannel0Invert: 1; // 12
		uint32 uniphyChannel1Invert: 1; // 13
		uint32 uniphyChannel2Invert: 1; // 14
		uint32 uniphyChannel3Invert: 1; // 15
		uint32 uniphyLinkEnableHpdMask: 2; // 16
		uint32 unknown4: 2;
		uint32 uniphyLaneStaggerDelay: 3; // 20
		uint32 unknown5: 9;
	};
	uint32 val;
};

// UNIPHY_PLL_CONTROL1
union UniphyPllControl1 {
	struct {
		uint32 uniphyPllEnable: 1; // 0
		uint32 uniphyPllReset: 1; // 1
		uint32 uniphyPllExtResetEn: 1; // 2
		uint32 uniphyPllClkEn: 1; // 3
		uint32 uniphyPllClkphEn: 4; // 4
		uint32 uniphyPllLfCntl: 7; // 8
		uint32 unknown1: 1;
		uint32 uniphyPllBwCntl: 8; // 16
		uint32 uniphyPllTestBypclkSrc: 1; // 24
		uint32 uniphyPllTestBypclkEn: 1; // 25
		uint32 uniphyPllTestVctlAdcEn: 1; // 26
		uint32 unknown2: 1;
		uint32 uniphyVcoMode: 2; // 28
		uint32 unknown3: 2;
	};
	uint32 val;
};

// UNIPHY_PLL_CONTROL2
union UniphyPllControl2 {
	struct {
		uint32 uniphyPllDispclkMode: 2; // 0
		uint32 uniphyDpllsel: 2; // 2
		uint32 uniphyIdclkSel: 1; // 4
		uint32 uniphyIpcieRefclkSel: 1; // 5
		uint32 uniphyIxtalinSel: 1; // 6
		uint32 unknown1: 1;
		uint32 uniphyPllRefclkSrc: 3; // 8
		uint32 uniphyPcierefClkEn: 1; // 11
		uint32 uniphyIdclkEn: 1; // 12
		uint32 uniphyClkinv: 1; // 13
		uint32 unknown2: 2;
		uint32 uniphyPllVtoiBiasCntl: 1; // 16
		uint32 unknown3: 2;
		uint32 uniphyPllTestFbdivFracBypass: 1; // 19
		uint32 uniphyPdivfracSel: 1; // 20
		uint32 unknown4: 3;
		uint32 uniphyPllRefdiv: 5; // 24
		uint32 uniphyPdivSel: 3; // 29
	};
	uint32 val;
};

// UNIPHY_PLL_FBDIV
union UniphyPllFbdiv {
	struct {
		uint32 unknown1: 2;
		uint32 uniphyPllFbdivFraction: 14; // 2
		uint32 uniphyPllFbdiv: 12; // 16
		uint32 unknown2: 4;
	};
	uint32 val;
};

// UNIPHY_PLL_SS_CNTL
union UniphyPllSsCntl {
	struct {
		uint32 uniphyPllSsStepNum: 12; // 0
		uint32 uniphyPllDsmodEn: 1; // 12
		uint32 uniphyPllSsEn: 1; // 13
		uint32 unknown1: 18;
	};
	uint32 val;
};

// UNIPHY_PLL_SS_STEP_SIZE
union UniphyPllSsStepSize {
	struct {
		uint32 uniphyPllSsStepSize: 26; // 0
		uint32 unknown1: 6;
	};
	uint32 val;
};

// UNIPHY_POWER_CONTROL
union UniphyPowerControl {
	struct {
		uint32 uniphyBgpdn: 1; // 0
		uint32 uniphyRstLogic: 1; // 1
		uint32 uniphyBiasrefSel: 1; // 2
		uint32 unknown1: 5;
		uint32 uniphyBgadj1p00: 4; // 8
		uint32 uniphyBgadj1p25: 4; // 12
		uint32 uniphyBgadj0p45: 4; // 16
		uint32 unknown2: 12;
	};
	uint32 val;
};

// UNIPHY_REG_TEST_OUTPUT
union UniphyRegTestOutput {
	struct {
		uint32 uniphyTestCntl: 5; // 0
		uint32 unknown1: 10;
		uint32 uniphyDigBistReset: 1; // 15
		uint32 uniphyDigBistSel: 1; // 16
		uint32 uniphyTestVctlEn: 1; // 17
		uint32 unknown2: 2;
		uint32 uniphyDigBistError: 5; // 20
		uint32 uniphyPllTestVctlAdc: 3; // 25
		uint32 uniphyPllTestFreqLock: 1; // 28
		uint32 uniphyPllIntreset: 1; // 29
		uint32 unknown3: 2;
	};
	uint32 val;
};

// UNIPHY_SOFT_RESET
union UniphySoftReset {
	struct {
		uint32 dsyncaSoftReset: 1; // 0
		uint32 dsyncbSoftReset: 1; // 1
		uint32 dsynccSoftReset: 1; // 2
		uint32 dsyncdSoftReset: 1; // 3
		uint32 dsynceSoftReset: 1; // 4
		uint32 dsyncfSoftReset: 1; // 5
		uint32 unknown1: 26;
	};
	uint32 val;
};

// UNIPHY_TX_CONTROL1
union UniphyTxControl1 {
	struct {
		uint32 uniphyPremphStr0: 3; // 0
		uint32 unknown1: 1;
		uint32 uniphyPremphStr1: 3; // 4
		uint32 unknown2: 1;
		uint32 uniphyPremphStr2: 3; // 8
		uint32 unknown3: 1;
		uint32 uniphyPremphStr3: 3; // 12
		uint32 unknown4: 1;
		uint32 uniphyPremphStr4: 3; // 16
		uint32 unknown5: 1;
		uint32 uniphyTxVs0: 2; // 20
		uint32 uniphyTxVs1: 2; // 22
		uint32 uniphyTxVs2: 2; // 24
		uint32 uniphyTxVs3: 2; // 26
		uint32 uniphyTxVs4: 2; // 28
		uint32 unknown6: 2;
	};
	uint32 val;
};

// UNIPHY_TX_CONTROL2
union UniphyTxControl2 {
	struct {
		uint32 uniphyPremph0Pc: 2; // 0
		uint32 unknown1: 2;
		uint32 uniphyPremph1Pc: 2; // 4
		uint32 unknown2: 2;
		uint32 uniphyPremph2Pc: 2; // 8
		uint32 unknown3: 2;
		uint32 uniphyPremph3Pc: 2; // 12
		uint32 unknown4: 2;
		uint32 uniphyPremph4Pc: 2; // 16
		uint32 unknown5: 2;
		uint32 uniphyPremphSel: 1; // 20
		uint32 uniphyRt0Cpsel: 2; // 21
		uint32 uniphyRt1Cpsel: 2; // 23
		uint32 uniphyRt2Cpsel: 2; // 25
		uint32 uniphyRt3Cpsel: 2; // 27
		uint32 uniphyRt4Cpsel: 2; // 29
		uint32 unknown6: 1;
	};
	uint32 val;
};

// UNIPHY_TX_CONTROL3
union UniphyTxControl3 {
	struct {
		uint32 uniphyPremphPwClk: 2; // 0
		uint32 uniphyPremphPwDat: 2; // 2
		uint32 uniphyPremphCsClk: 4; // 4
		uint32 uniphyPremphCsDat: 4; // 8
		uint32 uniphyPremphStrClk: 3; // 12
		uint32 unknown1: 1;
		uint32 uniphyPremphStrDat: 3; // 16
		uint32 unknown2: 1;
		uint32 uniphyPesel0: 1; // 20
		uint32 uniphyPesel1: 1; // 21
		uint32 uniphyPesel2: 1; // 22
		uint32 uniphyPesel3: 1; // 23
		uint32 uniphyTxVsAdj: 5; // 24
		uint32 unknown3: 2;
		uint32 uniphyLvdsPulldwn: 1; // 31
	};
	uint32 val;
};

// UNIPHY_TX_CONTROL4
union UniphyTxControl4 {
	struct {
		uint32 uniphyTxNvsClk: 5; // 0
		uint32 uniphyTxNvsDat: 5; // 5
		uint32 unknown1: 2;
		uint32 uniphyTxPvsClk: 5; // 12
		uint32 uniphyTxPvsDat: 5; // 17
		uint32 unknown2: 2;
		uint32 uniphyTxOpClk: 3; // 24
		uint32 unknown3: 1;
		uint32 uniphyTxOpDat: 3; // 28
		uint32 unknown4: 1;
	};
	uint32 val;
};

// VBLANK_STATUS
union VblankStatus {
	struct {
		uint32 vblankOccurred: 1; // 0
		uint32 unknown1: 3;
		uint32 vblankAck: 1; // 4
		uint32 unknown2: 7;
		uint32 vblankStat: 1; // 12
		uint32 unknown3: 3;
		uint32 vblankInterrupt: 1; // 16
		uint32 vblankInterruptType: 1; // 17
		uint32 unknown4: 14;
	};
	uint32 val;
};

// VGA25_PPLL_ANALOG
union Vga25PpllAnalog {
	struct {
		uint32 vga25CalMode: 5; // 0
		uint32 vga25PpllPfdPulseSel: 2; // 5
		uint32 unknown1: 1;
		uint32 vga25PpllCp: 4; // 8
		uint32 vga25PpllLfMode: 9; // 12
		uint32 unknown2: 3;
		uint32 vga25PpllIbias: 8; // 24
	};
	uint32 val;
};

// VGA25_PPLL_FB_DIV
union Vga25PpllFbDiv {
	struct {
		uint32 vga25PpllFbDivFraction: 4; // 0
		uint32 vga25PpllFbDivFractionCntl: 2; // 4
		uint32 unknown1: 10;
		uint32 vga25PpllFbDiv: 11; // 16
		uint32 unknown2: 5;
	};
	uint32 val;
};

// VGA25_PPLL_POST_DIV
union Vga25PpllPostDiv {
	struct {
		uint32 vga25PpllPostDivPixclk: 7; // 0
		uint32 unknown1: 1;
		uint32 vga25PpllPostDivDvoclk: 7; // 8
		uint32 unknown2: 1;
		uint32 vga25PpllPostDivIdclk: 7; // 16
		uint32 unknown3: 9;
	};
	uint32 val;
};

// VGA25_PPLL_REF_DIV
union Vga25PpllRefDiv {
	struct {
		uint32 vga25PpllRefDiv: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// VGA28_PPLL_ANALOG
union Vga28PpllAnalog {
	struct {
		uint32 vga28CalMode: 5; // 0
		uint32 vga28PpllPfdPulseSel: 2; // 5
		uint32 unknown1: 1;
		uint32 vga28PpllCp: 4; // 8
		uint32 vga28PpllLfMode: 9; // 12
		uint32 unknown2: 3;
		uint32 vga28PpllIbias: 8; // 24
	};
	uint32 val;
};

// VGA28_PPLL_FB_DIV
union Vga28PpllFbDiv {
	struct {
		uint32 vga28PpllFbDivFraction: 4; // 0
		uint32 vga28PpllFbDivFractionCntl: 2; // 4
		uint32 unknown1: 10;
		uint32 vga28PpllFbDiv: 11; // 16
		uint32 unknown2: 5;
	};
	uint32 val;
};

// VGA28_PPLL_POST_DIV
union Vga28PpllPostDiv {
	struct {
		uint32 vga28PpllPostDivPixclk: 7; // 0
		uint32 unknown1: 1;
		uint32 vga28PpllPostDivDvoclk: 7; // 8
		uint32 unknown2: 1;
		uint32 vga28PpllPostDivIdclk: 7; // 16
		uint32 unknown3: 9;
	};
	uint32 val;
};

// VGA28_PPLL_REF_DIV
union Vga28PpllRefDiv {
	struct {
		uint32 vga28PpllRefDiv: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// VGA41_PPLL_ANALOG
union Vga41PpllAnalog {
	struct {
		uint32 vga41CalMode: 5; // 0
		uint32 vga41PpllPfdPulseSel: 2; // 5
		uint32 unknown1: 1;
		uint32 vga41PpllCp: 4; // 8
		uint32 vga41PpllLfMode: 9; // 12
		uint32 unknown2: 3;
		uint32 vga41PpllIbias: 8; // 24
	};
	uint32 val;
};

// VGA41_PPLL_FB_DIV
union Vga41PpllFbDiv {
	struct {
		uint32 vga41PpllFbDivFraction: 4; // 0
		uint32 vga41PpllFbDivFractionCntl: 2; // 4
		uint32 unknown1: 10;
		uint32 vga41PpllFbDiv: 11; // 16
		uint32 unknown2: 5;
	};
	uint32 val;
};

// VGA41_PPLL_POST_DIV
union Vga41PpllPostDiv {
	struct {
		uint32 vga41PpllPostDivPixclk: 7; // 0
		uint32 unknown1: 1;
		uint32 vga41PpllPostDivDvoclk: 7; // 8
		uint32 unknown2: 1;
		uint32 vga41PpllPostDivIdclk: 7; // 16
		uint32 unknown3: 9;
	};
	uint32 val;
};

// VGA41_PPLL_REF_DIV
union Vga41PpllRefDiv {
	struct {
		uint32 vga41PpllRefDiv: 10; // 0
		uint32 unknown1: 22;
	};
	uint32 val;
};

// VGADCC_DBG_DCCIF_C
union VgadccDbgDccifC {
	struct {
		uint32 dbgDccifC: 32; // 0
	};
	uint32 val;
};

// VGA_CACHE_CONTROL
union VgaCacheControl {
	struct {
		uint32 vgaWriteThroughCacheDis: 1; // 0
		uint32 unknown1: 7;
		uint32 vgaReadCacheDisable: 1; // 8
		uint32 unknown2: 7;
		uint32 vgaReadBufferInvalidate: 1; // 16
		uint32 unknown3: 3;
		uint32 vgaDccifW256only: 1; // 20
		uint32 unknown4: 3;
		uint32 vgaDccifWcTimeout: 6; // 24
		uint32 unknown5: 2;
	};
	uint32 val;
};

// VGA_DEBUG_READBACK_DATA
union VgaDebugReadbackData {
	struct {
		uint32 vgaDebugReadbackData: 32; // 0
	};
	uint32 val;
};

// VGA_DEBUG_READBACK_INDEX
union VgaDebugReadbackIndex {
	struct {
		uint32 vgaDebugReadbackIndex: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// VGA_DISPBUF1_SURFACE_ADDR
union VgaDispbuf1SurfaceAddr {
	struct {
		uint32 vgaDispbuf1SurfaceAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// VGA_DISPBUF2_SURFACE_ADDR
union VgaDispbuf2SurfaceAddr {
	struct {
		uint32 vgaDispbuf2SurfaceAddr: 25; // 0
		uint32 unknown1: 7;
	};
	uint32 val;
};

// VGA_HDP_CONTROL
union VgaHdpControl {
	struct {
		uint32 vgaMemPageSelectEn: 1; // 0
		uint32 unknown1: 3;
		uint32 vgaMemoryDisable: 1; // 4
		uint32 unknown2: 3;
		uint32 vgaRbbmLockDisable: 1; // 8
		uint32 unknown3: 7;
		uint32 vgaSoftReset: 1; // 16
		uint32 unknown4: 7;
		uint32 vgaTestResetControl: 1; // 24
		uint32 unknown5: 7;
	};
	uint32 val;
};

// VGA_HW_DEBUG
union VgaHwDebug {
	struct {
		uint32 vgaHwDebug: 32; // 0
	};
	uint32 val;
};

// VGA_INTERRUPT_CONTROL
union VgaInterruptControl {
	struct {
		uint32 vgaMemAccessIntMask: 1; // 0
		uint32 unknown1: 7;
		uint32 vgaRegAccessIntMask: 1; // 8
		uint32 unknown2: 7;
		uint32 vgaDisplaySwitchIntMask: 1; // 16
		uint32 unknown3: 7;
		uint32 vgaModeAutoTriggerIntMask: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// VGA_INTERRUPT_STATUS
union VgaInterruptStatus {
	struct {
		uint32 vgaMemAccessIntStatus: 1; // 0
		uint32 vgaRegAccessIntStatus: 1; // 1
		uint32 vgaDisplaySwitchIntStatus: 1; // 2
		uint32 vgaModeAutoTriggerIntStatus: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// VGA_MAIN_CONTROL
union VgaMainControl {
	struct {
		uint32 vgaCrtcTimeout: 2; // 0
		uint32 unknown1: 1;
		uint32 vgaRenderTimeoutCount: 2; // 3
		uint32 vgaVirtualVerticalRetraceDuration: 3; // 5
		uint32 vgaReadbackVgaVstatusSourceSelect: 2; // 8
		uint32 unknown2: 6;
		uint32 vgaReadbackNoDisplaySourceSelect: 2; // 16
		uint32 unknown3: 6;
		uint32 vgaReadbackCrtIntrSourceSelect: 2; // 24
		uint32 vgaReadbackSenseSwitchSelect: 1; // 26
		uint32 vgaReadUrgentEnable: 1; // 27
		uint32 vgaWritesUrgentEnable: 1; // 28
		uint32 vgaExternalDacSense: 1; // 29
		uint32 unknown4: 1;
		uint32 vgaMainTestVstatusNoDisplayCrtcTimeout: 1; // 31
	};
	uint32 val;
};

// VGA_MEMORY_BASE_ADDRESS
union VgaMemoryBaseAddress {
	struct {
		uint32 vgaMemoryBaseAddress: 32; // 0
	};
	uint32 val;
};

// VGA_MEMORY_BASE_ADDRESS_HIGH
union VgaMemoryBaseAddressHigh {
	struct {
		uint32 vgaMemoryBaseAddressHigh: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// VGA_MEM_READ_PAGE_ADDR
union VgaMemReadPageAddr {
	struct {
		uint32 vgaMemReadPage0Addr: 10; // 0
		uint32 unknown1: 6;
		uint32 vgaMemReadPage1Addr: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// VGA_MEM_WRITE_PAGE_ADDR
union VgaMemWritePageAddr {
	struct {
		uint32 vgaMemWritePage0Addr: 10; // 0
		uint32 unknown1: 6;
		uint32 vgaMemWritePage1Addr: 10; // 16
		uint32 unknown2: 6;
	};
	uint32 val;
};

// VGA_MODE_CONTROL
union VgaModeControl {
	struct {
		uint32 vgaAtiLinear: 1; // 0
		uint32 unknown1: 3;
		uint32 vgaLutPaletteUpdateMode: 2; // 4
		uint32 unknown2: 2;
		uint32 vga128kAperturePaging: 1; // 8
		uint32 unknown3: 7;
		uint32 vgaText132ColumnsEn: 1; // 16
		uint32 unknown4: 15;
	};
	uint32 val;
};

// VGA_RENDER_CONTROL
union VgaRenderControl {
	struct {
		uint32 vgaBlinkRate: 5; // 0
		uint32 vgaBlinkMode: 2; // 5
		uint32 vgaCursorBlinkInvert: 1; // 7
		uint32 vgaExtdAddrCountEnable: 1; // 8
		uint32 unknown1: 7;
		uint32 vgaVstatusCntl: 2; // 16
		uint32 unknown2: 6;
		uint32 vgaLock8dot: 1; // 24
		uint32 vgaregLinecmpCompatibilitySel: 1; // 25
		uint32 unknown3: 6;
	};
	uint32 val;
};

// VGA_SEQUENCER_RESET_CONTROL
union VgaSequencerResetControl {
	struct {
		uint32 d1BlankDisplayWhenSequencerReset: 1; // 0
		uint32 d2BlankDisplayWhenSequencerReset: 1; // 1
		uint32 d3BlankDisplayWhenSequencerReset: 1; // 2
		uint32 d4BlankDisplayWhenSequencerReset: 1; // 3
		uint32 d5BlankDisplayWhenSequencerReset: 1; // 4
		uint32 d6BlankDisplayWhenSequencerReset: 1; // 5
		uint32 unknown1: 2;
		uint32 d1DisableSyncsAndDeWhenSequencerReset: 1; // 8
		uint32 d2DisableSyncsAndDeWhenSequencerReset: 1; // 9
		uint32 d3DisableSyncsAndDeWhenSequencerReset: 1; // 10
		uint32 d4DisableSyncsAndDeWhenSequencerReset: 1; // 11
		uint32 d5DisableSyncsAndDeWhenSequencerReset: 1; // 12
		uint32 d6DisableSyncsAndDeWhenSequencerReset: 1; // 13
		uint32 unknown2: 2;
		uint32 vgaModeAutoTriggerEnable: 1; // 16
		uint32 vgaModeAutoTriggerRegisterSelect: 1; // 17
		uint32 vgaModeAutoTriggerIndexSelect: 6; // 18
		uint32 unknown3: 8;
	};
	uint32 val;
};

// VGA_SOURCE_SELECT
union VgaSourceSelect {
	struct {
		uint32 vgaSourceSelA: 3; // 0
		uint32 unknown1: 5;
		uint32 vgaSourceSelB: 3; // 8
		uint32 unknown2: 21;
	};
	uint32 val;
};

// VGA_STATUS
union VgaStatus {
	struct {
		uint32 vgaMemAccessStatus: 1; // 0
		uint32 vgaRegAccessStatus: 1; // 1
		uint32 vgaDisplaySwitchStatus: 1; // 2
		uint32 vgaModeAutoTriggerStatus: 1; // 3
		uint32 unknown1: 28;
	};
	uint32 val;
};

// VGA_STATUS_CLEAR
union VgaStatusClear {
	struct {
		uint32 vgaMemAccessIntClear: 1; // 0
		uint32 unknown1: 7;
		uint32 vgaRegAccessIntClear: 1; // 8
		uint32 unknown2: 7;
		uint32 vgaDisplaySwitchIntClear: 1; // 16
		uint32 unknown3: 7;
		uint32 vgaModeAutoTriggerIntClear: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// VGA_SURFACE_PITCH_SELECT
union VgaSurfacePitchSelect {
	struct {
		uint32 vgaSurfacePitchSelect: 2; // 0
		uint32 unknown1: 6;
		uint32 vgaSurfaceHeightSelect: 2; // 8
		uint32 unknown2: 22;
	};
	uint32 val;
};

// VGA_TEST_CONTROL
union VgaTestControl {
	struct {
		uint32 vgaTestEnable: 1; // 0
		uint32 unknown1: 7;
		uint32 vgaTestRenderStart: 1; // 8
		uint32 unknown2: 7;
		uint32 vgaTestRenderDone: 1; // 16
		uint32 unknown3: 7;
		uint32 vgaTestRenderDispbufSelect: 1; // 24
		uint32 unknown4: 7;
	};
	uint32 val;
};

// VGA_TEST_DEBUG_DATA
union VgaTestDebugData {
	struct {
		uint32 vgaTestDebugData: 32; // 0
	};
	uint32 val;
};

// VGA_TEST_DEBUG_INDEX
union VgaTestDebugIndex {
	struct {
		uint32 vgaTestDebugIndex: 8; // 0
		uint32 vgaTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

// VIEWPORT_SIZE
union ViewportSize {
	struct {
		uint32 viewportHeight: 14; // 0
		uint32 unknown1: 2;
		uint32 viewportWidth: 14; // 16
		uint32 unknown2: 2;
	};
	uint32 val;
};

// VIEWPORT_START
union ViewportStart {
	struct {
		uint32 viewportYStart: 14; // 0
		uint32 unknown1: 2;
		uint32 viewportXStart: 14; // 16
		uint32 unknown2: 2;
	};
	uint32 val;
};

// VLINE_STATUS
union VlineStatus {
	struct {
		uint32 vlineOccurred: 1; // 0
		uint32 unknown1: 3;
		uint32 vlineAck: 1; // 4
		uint32 unknown2: 7;
		uint32 vlineStat: 1; // 12
		uint32 unknown3: 3;
		uint32 vlineInterrupt: 1; // 16
		uint32 vlineInterruptType: 1; // 17
		uint32 unknown4: 14;
	};
	uint32 val;
};

// XDMA_CLOCK_GATING_CNTL
union XdmaClockGatingCntl {
	struct {
		uint32 xdmaSclkTurnOnDelay: 4; // 0
		uint32 xdmaSclkTurnOffDelay: 8; // 4
		uint32 unknown1: 3;
		uint32 xdmaSclkGateDis: 1; // 15
		uint32 xdmaSclkRegGateDis: 1; // 16
		uint32 unknown2: 1;
		uint32 xdmaSclkGSdynGateDis: 1; // 18
		uint32 xdmaSclkGMstatGateDis: 1; // 19
		uint32 xdmaSclkGSstatGateDis: 1; // 20
		uint32 unknown3: 11;
	};
	uint32 val;
};

// XDMA_IF_BIF_STATUS
union XdmaIfBifStatus {
	struct {
		uint32 xdmaIfBifErrorStatus: 4; // 0
		uint32 unknown1: 4;
		uint32 xdmaIfBifErrorClear: 1; // 8
		uint32 unknown2: 23;
	};
	uint32 val;
};

// XDMA_INTERRUPT
union XdmaInterrupt {
	struct {
		uint32 unknown1: 8;
		uint32 xdmaMstrMemUrgentStat: 1; // 8
		uint32 xdmaMstrMemUrgentMask: 1; // 9
		uint32 xdmaMstrMemUrgentAck: 1; // 10
		uint32 unknown2: 1;
		uint32 xdmaMstrUnderflowStat: 1; // 12
		uint32 xdmaMstrUnderflowMask: 1; // 13
		uint32 xdmaMstrUnderflowAck: 1; // 14
		uint32 unknown3: 1;
		uint32 xdmaSlvReadUrgentStat: 1; // 16
		uint32 xdmaSlvReadUrgentMask: 1; // 17
		uint32 xdmaSlvReadUrgentAck: 1; // 18
		uint32 unknown4: 13;
	};
	uint32 val;
};

// XDMA_LOCAL_SURFACE_TILING1
union XdmaLocalSurfaceTiling1 {
	struct {
		uint32 xdmaLocalArrayMode: 4; // 0
		uint32 xdmaLocalTileSplit: 3; // 4
		uint32 unknown1: 1;
		uint32 xdmaLocalBankWidth: 2; // 8
		uint32 xdmaLocalBankHeight: 2; // 10
		uint32 xdmaLocalMacroTileAspect: 2; // 12
		uint32 unknown2: 6;
		uint32 xdmaLocalNumBanks: 2; // 20
		uint32 unknown3: 10;
	};
	uint32 val;
};

// XDMA_LOCAL_SURFACE_TILING2
union XdmaLocalSurfaceTiling2 {
	struct {
		uint32 xdmaLocalPipeInterleaveSize: 3; // 0
		uint32 unknown1: 19;
		uint32 xdmaLocalMicroTileMode: 2; // 22
		uint32 unknown2: 3;
		uint32 xdmaLocalPipeConfig: 5; // 27
	};
	uint32 val;
};

// XDMA_MC_PCIE_CLIENT_CONFIG
union XdmaMcPcieClientConfig {
	struct {
		uint32 unknown1: 8;
		uint32 xdmaMcPcieSwap: 2; // 8
		uint32 unknown2: 2;
		uint32 xdmaMcPcieVmid: 4; // 12
		uint32 xdmaMcPciePriv: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// XDMA_MEM_POWER_CNTL
union XdmaMemPowerCntl {
	struct {
		uint32 xdmaMemLightSleepDis: 1; // 0
		uint32 unknown1: 7;
		uint32 xdmaMemShutdownDis: 1; // 8
		uint32 unknown2: 7;
		uint32 xdmaMemLightSleepModeForce: 1; // 16
		uint32 unknown3: 7;
		uint32 xdmaMemShutdownModeForce: 1; // 24
		uint32 unknown4: 5;
		uint32 xdmaMemPowerState: 2; // 30
	};
	uint32 val;
};

// XDMA_MSTR_CMD_URGENT_CNTL
union XdmaMstrCmdUrgentCntl {
	struct {
		uint32 unknown1: 8;
		uint32 xdmaMstrCmdUrgentLevel: 4; // 8
		uint32 unknown2: 20;
	};
	uint32 val;
};

// XDMA_MSTR_CNTL
union XdmaMstrCntl {
	struct {
		uint32 unknown1: 9;
		uint32 xdmaMstrMemReady: 1; // 9
		uint32 unknown2: 6;
		uint32 xdmaMstrEnable: 1; // 16
		uint32 unknown3: 1;
		uint32 xdmaMstrDebugMode: 1; // 18
		uint32 xdmaMstrLatTestEn: 1; // 19
		uint32 xdmaMstrSoftReset: 1; // 20
		uint32 unknown4: 11;
	};
	uint32 val;
};

// XDMA_MSTR_HEIGHT
union XdmaMstrHeight {
	struct {
		uint32 xdmaMstrActiveHeight: 14; // 0
		uint32 unknown1: 2;
		uint32 xdmaMstrFrameHeight: 14; // 16
		uint32 unknown2: 2;
	};
	uint32 val;
};

// XDMA_MSTR_LOCAL_SURFACE_BASE_ADDR
union XdmaMstrLocalSurfaceBaseAddr {
	struct {
		uint32 xdmaMstrLocalSurfaceBaseAddr: 32; // 0
	};
	uint32 val;
};

// XDMA_MSTR_LOCAL_SURFACE_BASE_ADDR_HIGH
union XdmaMstrLocalSurfaceBaseAddrHigh {
	struct {
		uint32 xdmaMstrLocalSurfaceBaseAddrHigh: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// XDMA_MSTR_LOCAL_SURFACE_PITCH
union XdmaMstrLocalSurfacePitch {
	struct {
		uint32 xdmaMstrLocalSurfacePitch: 14; // 0
		uint32 unknown1: 18;
	};
	uint32 val;
};

// XDMA_MSTR_MEM_CLIENT_CONFIG
union XdmaMstrMemClientConfig {
	struct {
		uint32 unknown1: 8;
		uint32 xdmaMstrMemClientSwap: 2; // 8
		uint32 unknown2: 2;
		uint32 xdmaMstrMemClientVmid: 4; // 12
		uint32 xdmaMstrMemClientPriv: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// XDMA_MSTR_MEM_NACK_STATUS
union XdmaMstrMemNackStatus {
	struct {
		uint32 xdmaMstrMemNackTag: 10; // 0
		uint32 unknown1: 2;
		uint32 xdmaMstrMemNack: 2; // 12
		uint32 unknown2: 2;
		uint32 xdmaMstrMemNackClr: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// XDMA_MSTR_MEM_URGENT_CNTL
union XdmaMstrMemUrgentCntl {
	struct {
		uint32 xdmaMstrMemClientStall: 1; // 0
		uint32 unknown1: 3;
		uint32 xdmaMstrMemUrgentLimit: 4; // 4
		uint32 xdmaMstrMemUrgentLevel: 4; // 8
		uint32 xdmaMstrMemStallDelay: 4; // 12
		uint32 xdmaMstrMemUrgentTimer: 16; // 16
	};
	uint32 val;
};

// XDMA_MSTR_PCIE_NACK_STATUS
union XdmaMstrPcieNackStatus {
	struct {
		uint32 xdmaMstrPcieNackTag: 10; // 0
		uint32 unknown1: 2;
		uint32 xdmaMstrPcieNack: 2; // 12
		uint32 unknown2: 2;
		uint32 xdmaMstrPcieNackClr: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// XDMA_MSTR_READ_COMMAND
union XdmaMstrReadCommand {
	struct {
		uint32 xdmaMstrRequestSize: 14; // 0
		uint32 unknown1: 2;
		uint32 xdmaMstrRequestPrefetch: 14; // 16
		uint32 unknown2: 2;
	};
	uint32 val;
};

// XDMA_MSTR_REMOTE_GPU_ADDRESS
union XdmaMstrRemoteGpuAddress {
	struct {
		uint32 xdmaMstrRemoteGpuAddress: 32; // 0
	};
	uint32 val;
};

// XDMA_MSTR_REMOTE_GPU_ADDRESS_HIGH
union XdmaMstrRemoteGpuAddressHigh {
	struct {
		uint32 xdmaMstrRemoteGpuAddressHigh: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// XDMA_MSTR_REMOTE_SURFACE_BASE
union XdmaMstrRemoteSurfaceBase {
	struct {
		uint32 xdmaMstrRemoteSurfaceBase: 32; // 0
	};
	uint32 val;
};

// XDMA_MSTR_REMOTE_SURFACE_BASE_HIGH
union XdmaMstrRemoteSurfaceBaseHigh {
	struct {
		uint32 xdmaMstrRemoteSurfaceBaseHigh: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// XDMA_MSTR_STATUS
union XdmaMstrStatus {
	struct {
		uint32 xdmaMstrVcountCurrent: 14; // 0
		uint32 unknown1: 2;
		uint32 xdmaMstrWriteLineCurrent: 14; // 16
		uint32 unknown2: 2;
	};
	uint32 val;
};

// XDMA_RBBMIF_RDWR_CNTL
union XdmaRbbmifRdwrCntl {
	struct {
		uint32 xdmaRbbmifRdwrDelay: 3; // 0
		uint32 xdmaRbbmifRdwrTimeoutDis: 1; // 3
		uint32 unknown1: 11;
		uint32 xdmaRbbmifTimeoutDelay: 17; // 15
	};
	uint32 val;
};

// XDMA_SLV_CNTL
union XdmaSlvCntl {
	struct {
		uint32 unknown1: 8;
		uint32 xdmaSlvActive: 1; // 8
		uint32 xdmaSlvMemReady: 1; // 9
		uint32 unknown2: 6;
		uint32 xdmaSlvEnable: 1; // 16
		uint32 unknown3: 2;
		uint32 xdmaSlvReadLatTestEn: 1; // 19
		uint32 xdmaSlvSoftReset: 1; // 20
		uint32 unknown4: 11;
	};
	uint32 val;
};

// XDMA_SLV_FLIP_PENDING
union XdmaSlvFlipPending {
	struct {
		uint32 xdmaSlvFlipPending: 1; // 0
		uint32 unknown1: 31;
	};
	uint32 val;
};

// XDMA_SLV_MEM_CLIENT_CONFIG
union XdmaSlvMemClientConfig {
	struct {
		uint32 unknown1: 8;
		uint32 xdmaSlvMemClientSwap: 2; // 8
		uint32 unknown2: 2;
		uint32 xdmaSlvMemClientVmid: 4; // 12
		uint32 xdmaSlvMemClientPriv: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// XDMA_SLV_MEM_NACK_STATUS
union XdmaSlvMemNackStatus {
	struct {
		uint32 xdmaSlvMemNackTag: 16; // 0
		uint32 xdmaSlvMemNack: 2; // 16
		uint32 unknown1: 13;
		uint32 xdmaSlvMemNackClr: 1; // 31
	};
	uint32 val;
};

// XDMA_SLV_PCIE_NACK_STATUS
union XdmaSlvPcieNackStatus {
	struct {
		uint32 xdmaSlvPcieNackTag: 10; // 0
		uint32 unknown1: 2;
		uint32 xdmaSlvPcieNack: 2; // 12
		uint32 unknown2: 2;
		uint32 xdmaSlvPcieNackClr: 1; // 16
		uint32 unknown3: 15;
	};
	uint32 val;
};

// XDMA_SLV_READ_LATENCY_AVE
union XdmaSlvReadLatencyAve {
	struct {
		uint32 xdmaSlvReadLatencyAcc: 20; // 0
		uint32 xdmaSlvReadLatencyCount: 12; // 20
	};
	uint32 val;
};

// XDMA_SLV_READ_LATENCY_MINMAX
union XdmaSlvReadLatencyMinmax {
	struct {
		uint32 xdmaSlvReadLatencyMin: 16; // 0
		uint32 xdmaSlvReadLatencyMax: 16; // 16
	};
	uint32 val;
};

// XDMA_SLV_READ_LATENCY_TIMER
union XdmaSlvReadLatencyTimer {
	struct {
		uint32 xdmaSlvReadLatencyTimer: 16; // 0
		uint32 unknown1: 16;
	};
	uint32 val;
};

// XDMA_SLV_READ_URGENT_CNTL
union XdmaSlvReadUrgentCntl {
	struct {
		uint32 xdmaSlvReadClientStall: 1; // 0
		uint32 unknown1: 3;
		uint32 xdmaSlvReadUrgentLimit: 4; // 4
		uint32 xdmaSlvReadUrgentLevel: 4; // 8
		uint32 xdmaSlvReadStallDelay: 4; // 12
		uint32 xdmaSlvReadUrgentTimer: 16; // 16
	};
	uint32 val;
};

// XDMA_SLV_REMOTE_GPU_ADDRESS
union XdmaSlvRemoteGpuAddress {
	struct {
		uint32 xdmaSlvRemoteGpuAddress: 32; // 0
	};
	uint32 val;
};

// XDMA_SLV_REMOTE_GPU_ADDRESS_HIGH
union XdmaSlvRemoteGpuAddressHigh {
	struct {
		uint32 xdmaSlvRemoteGpuAddressHigh: 8; // 0
		uint32 unknown1: 24;
	};
	uint32 val;
};

// XDMA_SLV_SLS_PITCH
union XdmaSlvSlsPitch {
	struct {
		uint32 xdmaSlvSlsPitch: 14; // 0
		uint32 unknown1: 2;
		uint32 xdmaSlvSlsWidth: 14; // 16
		uint32 unknown2: 2;
	};
	uint32 val;
};

// XDMA_SLV_WB_RATE_CNTL
union XdmaSlvWbRateCntl {
	struct {
		uint32 xdmaSlvWbBurstSize: 9; // 0
		uint32 unknown1: 7;
		uint32 xdmaSlvWbBurstPeriod: 16; // 16
	};
	uint32 val;
};

// XDMA_SLV_WRITE_URGENT_CNTL
union XdmaSlvWriteUrgentCntl {
	struct {
		uint32 xdmaSlvWriteStall: 1; // 0
		uint32 unknown1: 7;
		uint32 xdmaSlvWriteUrgentLevel: 4; // 8
		uint32 xdmaSlvWriteStallDelay: 4; // 12
		uint32 unknown2: 16;
	};
	uint32 val;
};

// XDMA_TEST_DEBUG_DATA
union XdmaTestDebugData {
	struct {
		uint32 xdmaTestDebugData: 32; // 0
	};
	uint32 val;
};

// XDMA_TEST_DEBUG_INDEX
union XdmaTestDebugIndex {
	struct {
		uint32 xdmaTestDebugIndex: 8; // 0
		uint32 xdmaTestDebugWriteEn: 1; // 8
		uint32 unknown1: 23;
	};
	uint32 val;
};

