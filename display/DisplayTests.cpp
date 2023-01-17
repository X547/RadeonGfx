#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Radeon.h"
#include "DisplayRoster.h"
#include "RadeonMemory.h"
#include "RadeonDevice.h"
#include "InterruptHandler.h"
#include "RingBuffer.h"
#include "Units/DmaV1RingPackets.h"
#include "Atombios.h"
#include "atom.h"
#include "sid_amdgpu.h"
#include "gmc_6_0_d.h"
#include "dce_6_0.h"
#include "dce_6_0_d.h"
#include "oss_1_0_d.h"

#include <Application.h>
#include <Region.h>
#include "DisplayConsumer.h"
#include "CursorData.h"


#define DC_HPDx_CONTROL(x)        (mmDC_HPD1_CONTROL     + (x * 3))
#define DC_HPDx_INT_CONTROL(x)    (mmDC_HPD1_INT_CONTROL + (x * 3))
#define DC_HPDx_INT_STATUS_REG(x) (mmDC_HPD1_INT_STATUS  + (x * 3))

static const uint32 crtc_offsets[] =
{
	SI_CRTC0_REGISTER_OFFSET,
	SI_CRTC1_REGISTER_OFFSET,
	SI_CRTC2_REGISTER_OFFSET,
	SI_CRTC3_REGISTER_OFFSET,
	SI_CRTC4_REGISTER_OFFSET,
	SI_CRTC5_REGISTER_OFFSET
};

static const uint32 si_disp_int_status[] =
{
	mmDISP_INTERRUPT_STATUS,
	mmDISP_INTERRUPT_STATUS_CONTINUE,
	mmDISP_INTERRUPT_STATUS_CONTINUE2,
	mmDISP_INTERRUPT_STATUS_CONTINUE3,
	mmDISP_INTERRUPT_STATUS_CONTINUE4,
	mmDISP_INTERRUPT_STATUS_CONTINUE5
};


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


status_t ShowMemoryCtrlState()
{
	printf("MC_VM_SYSTEM_APERTURE_LOW_ADDR: %#" B_PRIx32 "\n", ReadReg4AmdGpu(mmMC_VM_SYSTEM_APERTURE_LOW_ADDR));
	printf("MC_VM_SYSTEM_APERTURE_HIGH_ADDR: %#" B_PRIx32 "\n", ReadReg4AmdGpu(mmMC_VM_SYSTEM_APERTURE_HIGH_ADDR));
	printf("MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR: %#" B_PRIx32 "\n", ReadReg4AmdGpu(mmMC_VM_SYSTEM_APERTURE_DEFAULT_ADDR));

	uint32 val = ReadReg4AmdGpu(mmMC_VM_FB_LOCATION);
	printf("MC_VM_FB_LOCATION: %#" B_PRIx32 "\n", val);
		printf("  %#" B_PRIx64 " - %#" B_PRIx64 "\n", ((uint64)(val % 0x10000) << 24), ((uint64)(val / 0x10000 % 0x10000) << 24));
	printf("HDP_NONSURFACE_BASE: %#" B_PRIx64 "\n", (uint64)ReadReg4AmdGpu(mmHDP_NONSURFACE_BASE) << 8);
	printf("HDP_NONSURFACE_INFO: %#" B_PRIx32 "\n", ReadReg4AmdGpu(mmHDP_NONSURFACE_INFO));
	printf("HDP_NONSURFACE_SIZE: %#" B_PRIx32 "\n", ReadReg4AmdGpu(mmHDP_NONSURFACE_SIZE));

	return B_OK;
}

status_t ShowCtrcState()
{
	for (uint32 i = 0; i < 6; i++) {
		printf("%" B_PRIu32 "\n", i);

		//printf("  AFMT_AUDIO_PACKET_CONTROL: %#" B_PRIx32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + AFMT_AUDIO_PACKET_CONTROL));
		//printf("  AFMT_STATUS: %#" B_PRIx32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + AFMT_STATUS));
		printf("  CRTC_STATUS_FRAME_COUNT: %" B_PRIu32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + CRTC_STATUS_FRAME_COUNT));
		printf("  CRTC_BLANK_CONTROL: %#" B_PRIx32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmCRTC_BLANK_CONTROL));
		printf("  CRTC_CONTROL: "); WriteSet(ReadReg4AmdGpu(crtc_offsets[i] + mmCRTC_CONTROL)); printf("\n"); // EVERGREEN_CRTC_MASTER_EN: 0, EVERGREEN_CRTC_DISP_READ_REQUEST_DISABLE: 24
		printf("  CRTC_STATUS: "); WriteSet(ReadReg4AmdGpu(crtc_offsets[i] + mmCRTC_STATUS)); printf("\n"); // EVERGREEN_CRTC_V_BLANK: 0
		printf("  CRTC_STATUS_HV_COUNT: %" B_PRIu32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmCRTC_STATUS_HV_COUNT));
		printf("  CRTC_STATUS_POSITION: %#" B_PRIx32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmCRTC_STATUS_POSITION));
		printf("  CRTC_UPDATE_LOCK: %#" B_PRIx32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmCRTC_UPDATE_LOCK));
		printf("  GRPH_UPDATE: "); WriteSet(ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_UPDATE)); printf("\n");
		printf("  MASTER_UPDATE_LOCK: %#" B_PRIx32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmMASTER_UPDATE_LOCK));
		printf("  MASTER_UPDATE_MODE: %#" B_PRIx32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmMASTER_UPDATE_MODE));
		printf("  GRPH_INT_CONTROL: "); WriteSet(ReadReg4AmdGpu(crtc_offsets[i] + GRPH_INT_CONTROL)); printf("\n");
		printf("  GRPH_INT_STATUS: "); WriteSet(ReadReg4AmdGpu(crtc_offsets[i] + GRPH_INT_STATUS)); printf("\n");
		printf("  INT_MASK: "); WriteSet(ReadReg4AmdGpu(crtc_offsets[i] + INT_MASK)); printf("\n");
		printf("  VBLANK_STATUS: "); WriteSet(ReadReg4AmdGpu(crtc_offsets[i] + VBLANK_STATUS)); printf("\n"); // VBLANK_OCCURRED: 0, VBLANK_STAT: 12
		printf("  VLINE_STATUS: "); WriteSet(ReadReg4AmdGpu(crtc_offsets[i] + VLINE_STATUS)); printf("\n");

		printf("  DESKTOP_HEIGHT: %" B_PRIu32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmDESKTOP_HEIGHT));
		printf("  GRPH_CONTROL: %#" B_PRIx32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_CONTROL));
		printf("  GRPH_ENABLE: %#" B_PRIx32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_ENABLE));
		printf("  GRPH_FLIP_CONTROL: %#" B_PRIx32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_FLIP_CONTROL));
		printf("  GRPH_LUT_10BIT_BYPASS: %#" B_PRIx32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_LUT_10BIT_BYPASS));
		printf("  GRPH_PITCH: %" B_PRIu32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_PITCH));
		printf("  GRPH_SURFACE_OFFSET_X: %" B_PRIu32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_SURFACE_OFFSET_X));
		printf("  GRPH_SURFACE_OFFSET_Y: %" B_PRIu32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_SURFACE_OFFSET_Y));
		printf("  GRPH_SWAP_CNTL: %#" B_PRIx32 "\n", ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_SWAP_CNTL));
		printf("  GRPH_PRIMARY_SURFACE_ADDRESS: %#" B_PRIx64 "\n", (uint64)ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_PRIMARY_SURFACE_ADDRESS) + ((uint64)ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_PRIMARY_SURFACE_ADDRESS_HIGH) << 32));
		printf("  GRPH_SECONDARY_SURFACE_ADDRESS: %#" B_PRIx64 "\n", (uint64)ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_SECONDARY_SURFACE_ADDRESS) + ((uint64)ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_SECONDARY_SURFACE_ADDRESS_HIGH) << 32));

		printf("  total frame: (%" B_PRIu32 ", %" B_PRIu32 ", %" B_PRIu32 ", %" B_PRIu32 ")\n",
			ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_X_START),
			ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_Y_START),
			ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_X_END),
			ReadReg4AmdGpu(crtc_offsets[i] + mmGRPH_Y_END)
		);
		uint32 viewportStart = ReadReg4AmdGpu(crtc_offsets[i] + mmVIEWPORT_START);
		uint32 viewportSize = ReadReg4AmdGpu(crtc_offsets[i] + mmVIEWPORT_SIZE);
		printf("  viewport frame: (%" B_PRIu32 ", %" B_PRIu32 ", %" B_PRIu32 ", %" B_PRIu32 ")\n",
			viewportStart / (1 << 16),
			viewportStart % (1 << 16),
			viewportSize / (1 << 16),
			viewportSize % (1 << 16)
		);
	}

	return B_OK;
}

static void SetFramebuffer(uint32 crtcId, uint64 gpuPhysAdr)
{
	WriteReg8LoHiAmdGpu(crtc_offsets[crtcId] + mmGRPH_PRIMARY_SURFACE_ADDRESS, crtc_offsets[crtcId] + mmGRPH_PRIMARY_SURFACE_ADDRESS_HIGH, gpuPhysAdr);
	ReadReg4AmdGpu(crtc_offsets[crtcId] + mmGRPH_PRIMARY_SURFACE_ADDRESS);
}

static void GetCurrentMode(display_mode &mode, frame_buffer_config &fbc, uint64 &gpuPhysAdr, uint32 crtcId)
{
	uint32 viewportStart = ReadReg4AmdGpu(crtc_offsets[crtcId] + mmVIEWPORT_START);
	uint32 viewportSize = ReadReg4AmdGpu(crtc_offsets[crtcId] + mmVIEWPORT_SIZE);
	mode = {
		.timing {
			.h_display = viewportSize / (1 << 16),
			.v_display = viewportSize % (1 << 16),
		},
		.space = B_RGBA32,
		.virtual_width = ReadReg4AmdGpu(crtc_offsets[crtcId] + mmGRPH_X_END),
		.virtual_height = ReadReg4AmdGpu(crtc_offsets[crtcId] + mmGRPH_Y_END),
		.h_display_start = viewportStart / (1 << 16),
		.v_display_start = viewportStart % (1 << 16)
	};
	fbc = {
		.bytes_per_row = 4*ReadReg4AmdGpu(crtc_offsets[crtcId] + mmGRPH_PITCH)
	};
	gpuPhysAdr = ReadReg8LoHiAmdGpu(crtc_offsets[crtcId] + mmGRPH_PRIMARY_SURFACE_ADDRESS, crtc_offsets[crtcId] + mmGRPH_PRIMARY_SURFACE_ADDRESS_HIGH);
}


status_t TestMode()
{
	printf("TestMode()\n");

	int setIndex = GetIndexIntoMasterTable(COMMAND, SetPixelClock);
	int index = GetIndexIntoMasterTable(COMMAND, GetPixelClock);
	uint8 tableMajor, tableMinor;
	atom_parse_cmd_header(gDevice.Atom().Context(), index, &tableMajor, &tableMinor);
	printf("GetPixelClock tableMajor: %" B_PRIu8 ", tableMinor: %" B_PRIu8 "\n", tableMajor, tableMinor);
	atom_parse_cmd_header(gDevice.Atom().Context(), setIndex, &tableMajor, &tableMinor);
	printf("SetPixelClock tableMajor: %" B_PRIu8 ", tableMinor: %" B_PRIu8 "\n", tableMajor, tableMinor);
	union setPixelClock {
		SET_PIXEL_CLOCK_PS_ALLOCATION base;
		PIXEL_CLOCK_PARAMETERS v1;
		PIXEL_CLOCK_PARAMETERS_V2 v2;
		PIXEL_CLOCK_PARAMETERS_V3 v3;
		PIXEL_CLOCK_PARAMETERS_V5 v5;
		PIXEL_CLOCK_PARAMETERS_V6 v6;
		PIXEL_CLOCK_PARAMETERS_V7 v7;
	};
	for (int i = 0; i < 6; i++) {
		union setPixelClock args{};
		args.v6.ulCrtcPclkFreq.ucCRTC = i;
		CheckRet(atom_execute_table(gDevice.Atom().Context(), index, (uint32*)&args));
	/*
		printf("args.v3.usPixelClock: %"    B_PRIu16 "\n", args.v3.usPixelClock);
		printf("args.v3.usRefDiv: %"        B_PRIu16 "\n", args.v3.usRefDiv);
		printf("args.v3.usFbDiv: %"         B_PRIu16 "\n", args.v3.usFbDiv);
		printf("args.v3.ucPostDiv: %"       B_PRIu8  "\n", args.v3.ucPostDiv);
		printf("args.v3.ucFracFbDiv: %"     B_PRIu8  "\n", args.v3.ucFracFbDiv);
		printf("args.v3.ucPpll: %"          B_PRIu8  "\n", args.v3.ucPpll);
		printf("args.v3.ucTransmitterId: %" B_PRIu8  "\n", args.v3.ucTransmitterId);
		printf("args.v3.ucEncoderMode: %"   B_PRIu8  "\n", args.v3.ucEncoderMode);
		printf("args.v3.ucMiscInfo: %"      B_PRIu8  "\n", args.v3.ucMiscInfo);
	*/
		printf("args.v6.ulDispEngClkFreq: %" B_PRIu32 "\n", args.v6.ulDispEngClkFreq);
		printf("args.v6.usFbDiv: %"          B_PRIu16 "\n", args.v6.usFbDiv);
		printf("args.v6.ucPostDiv: %"        B_PRIu8  "\n", args.v6.ucPostDiv);
		printf("args.v6.ucRefDiv: %"         B_PRIu8  "\n", args.v6.ucRefDiv);
		printf("args.v6.ucPpll: %"           B_PRIu8  "\n", args.v6.ucPpll);
		printf("args.v6.ucTransmitterID: %"  B_PRIu8  "\n", args.v6.ucTransmitterID);
		printf("args.v6.ucEncoderMode: %"    B_PRIu8  "\n", args.v6.ucEncoderMode);
		printf("args.v6.ucMiscInfo: %"       B_PRIu8  "\n", args.v6.ucMiscInfo);
		printf("args.v6.ulFbDivDecFrac: %"   B_PRIu32 "\n", args.v6.ulFbDivDecFrac);
	}

    return B_OK;
}

status_t TestSetFramebuffer()
{
	uint32 crtcId = 0;
	display_mode mode{};
	frame_buffer_config fbc{};
	uint64 origGpuPhysAdr = 0;
	GetCurrentMode(mode, fbc, origGpuPhysAdr, crtcId);

	MappedBuffer buf(gDevice.MemMgr().Switch()->Alloc(boDomainVramMappable, fbc.bytes_per_row*mode.virtual_height));
	if (!buf.buf.IsSet()) return B_NO_MEMORY;
	uint64 gpuPhysAdr = buf.buf->gpuPhysAdr;
	fbc.frame_buffer = buf.adr;
	printf("gpuPhysAdr: %#" B_PRIx64 "\n", gpuPhysAdr);

	for (uint32 y = mode.v_display_start; y < mode.v_display_start + mode.timing.v_display; y++) {
		uint32 *line = (uint32*)((uint8*)fbc.frame_buffer + y*fbc.bytes_per_row);
		for (uint32 x = mode.h_display_start; x < mode.h_display_start + mode.timing.h_display; x++) {
			line[x] = x%0x100 + ((y%0x100) << 8) + 0x800000;
		}
	}

	//uint64 gpuPhysAdr = origGpuPhysAdr + fbc.bytes_per_row*1024;

	WriteReg4AmdGpu(crtc_offsets[crtcId] + mmGRPH_FLIP_CONTROL, 0);

	SetFramebuffer(crtcId, gpuPhysAdr);
	printf("[WAIT]"); fgetc(stdin);

	SetFramebuffer(crtcId, origGpuPhysAdr);
	printf("[WAIT]"); fgetc(stdin);

	return B_OK;
}

/* The order we write back each register here is important */
static void DisplayIrqAck()
{
	uint32 num_crtc = 2;
	DispInterruptStatus disp_int[6];
	GrphInterruptStatus grph_int[6];

	for (uint32 i = 0; i < 6; i++) {
		disp_int[i].val = ReadReg4AmdGpu(si_disp_int_status[i]);
		if (i < num_crtc)
			grph_int[i].val = ReadReg4AmdGpu(mmGRPH_INTERRUPT_STATUS + crtc_offsets[i]);
	}

	/* We write back each interrupt register in pairs of two */
	for (uint32 i = 0; i < num_crtc; i += 2) {
		for (uint32 j = i; j < (i + 2); j++) {
			if (grph_int[j].grphPflipIntOccurred)
				WriteReg4AmdGpu(mmGRPH_INTERRUPT_STATUS + crtc_offsets[j], GrphInterruptStatus{.grphPflipIntClear = true}.val);
		}

		for (uint32 j = i; j < (i + 2); j++) {
			if (disp_int[j].lbD1VblankInterrupt)
				WriteReg4AmdGpu(mmVBLANK_STATUS + crtc_offsets[j], VblankStatus{.vblankAck = true}.val);
			if (disp_int[j].lbD1VlineInterrupt)
				WriteReg4AmdGpu(mmVLINE_STATUS + crtc_offsets[j], VlineStatus{.vlineAck = true}.val);
		}
	}

	for (uint32 i = 0; i < 6; i++) {
		if (disp_int[i].dcHpd1Interrupt)
			WriteReg4AmdGpu(DC_HPDx_INT_CONTROL(i), ReadReg4AmdGpu(DC_HPDx_INT_CONTROL(i)) | DcHpd1IntControl{.dcHpd1IntAck = true}.val);
	}

	for (uint32 i = 0; i < 6; i++) {
		if (disp_int[i].dcHpd1RxInterrupt)
			WriteReg4AmdGpu(DC_HPDx_INT_CONTROL(i), ReadReg4AmdGpu(DC_HPDx_INT_CONTROL(i)) | DcHpd1IntControl{.dcHpd1RxIntAck = true}.val);
	}
}

static bool evergreen_hpd_sense(uint32 hpd)
{
	return (ReadReg4AmdGpu(DC_HPDx_INT_STATUS_REG(hpd)) & DC_HPDx_SENSE) != 0;
}

static void evergreen_hpd_set_polarity(uint32 hpd)
{
	bool connected = evergreen_hpd_sense(hpd);
	printf("Hotplug(hpd: %" B_PRIu32 ", %d)\n", hpd, connected);

	if (connected)
		WriteReg4AmdGpu(DC_HPDx_INT_CONTROL(hpd), ReadReg4AmdGpu(DC_HPDx_INT_CONTROL(hpd)) & ~DC_HPDx_INT_POLARITY);
	else
		WriteReg4AmdGpu(DC_HPDx_INT_CONTROL(hpd), ReadReg4AmdGpu(DC_HPDx_INT_CONTROL(hpd)) | DC_HPDx_INT_POLARITY);
}

class DisplayIrqHandler: public InterruptSource {
public:
	status_t Enable(bool doEnable);
	void InterruptReceived(InterruptPacket &pkt);
};

static DisplayIrqHandler sDisplayIrqHandler;

status_t DisplayIrqHandler::Enable(bool doEnable)
{
	// TODO
	return B_OK;
}

void DisplayIrqHandler::InterruptReceived(InterruptPacket &pkt)
{
	printf("DisplayIrqHandler: %" B_PRIu32 "\n", pkt.srcId);
	uint32 num_crtc = 2;
	for (uint32 i = 0; i < num_crtc; i++) {
		printf("CRTC_STATUS_FRAME_COUNT[%" B_PRIu32 "]: %" B_PRIu32 "\n", i, ReadReg4AmdGpu(crtc_offsets[i] + CRTC_STATUS_FRAME_COUNT));
	}

	if (pkt.srcId == 42) {
		uint32 hpd_idx;
		if (pkt.srcData < 6) {

			hpd_idx = pkt.srcData;
			evergreen_hpd_set_polarity(hpd_idx);
		} else if (pkt.srcData < 12) {
			hpd_idx = pkt.srcData - 6;
		}
	}

	DisplayIrqAck();
}

status_t TestDisplayIrq()
{
	uint32 crtcId = 0;

	DisplayIrqAck();

	uint32 irqs[] = {
		1, 2, 3, 4, 5, 6, // vblank/vline
		8, 10, 12, 14, 16, 18, // page flip
		42 // HPD hotplug
	};

	for (uint32 i = 0; i < B_COUNT_OF(irqs); i++) {
		gDevice.IntHandler().Switch()->InstallHandler(0, irqs[i], &sDisplayIrqHandler);
	}

	//WriteReg4AmdGpu(crtc_offsets[crtcId] + INT_MASK, VBLANK_INT_MASK);
	WriteReg4AmdGpu(crtc_offsets[crtcId] + GRPH_INT_CONTROL, GRPH_PFLIP_INT_MASK);
	WriteReg4AmdGpu(DC_HPDx_INT_CONTROL(crtcId), DC_HPDx_INT_CONTROL(crtcId) | DC_HPDx_INT_EN | DC_HPDx_RX_INT_EN);
	printf("[WAIT]"); fgetc(stdin);
	TestSetFramebuffer();
	WriteReg4AmdGpu(DC_HPDx_INT_CONTROL(crtcId), DC_HPDx_INT_CONTROL(crtcId) & ~(DC_HPDx_INT_EN | DC_HPDx_RX_INT_EN));
	WriteReg4AmdGpu(crtc_offsets[crtcId] + GRPH_INT_CONTROL, 0);
	WriteReg4AmdGpu(crtc_offsets[crtcId] + INT_MASK, 0);
	printf("[WAIT]"); fgetc(stdin);

	return B_OK;
}

MappedBuffer gBufs[2];
display_mode gMode{};
frame_buffer_config gFbc{};
uint32 gCurBuf;
uint32 gSeq = 0;

static void FillBuffer(const display_mode &mode, const frame_buffer_config &fbc, int32 ofsX, int32 ofsY)
{
	for (uint32 y = mode.v_display_start; y < mode.v_display_start + mode.timing.v_display; y++) {
		uint32 *line = (uint32*)((uint8*)fbc.frame_buffer + y*fbc.bytes_per_row);
		for (uint32 x = mode.h_display_start; x < mode.h_display_start + mode.timing.h_display; x++) {
			line[x] = (x + ofsX)%0x100 + (((y + ofsY)%0x100) << 8) + 0x800000;
		}
	}
}


class DisplayIrqHandler2: public InterruptSource {
public:
	status_t Enable(bool doEnable);
	void InterruptReceived(InterruptPacket &pkt);
};

static DisplayIrqHandler2 sDisplayIrqHandler2;

status_t DisplayIrqHandler2::Enable(bool doEnable)
{
	// TODO
	return B_OK;
}

void DisplayIrqHandler2::InterruptReceived(InterruptPacket &pkt)
{
	printf("DisplayIrqHandler2: %" B_PRIu32 "\n", pkt.srcId);
	gCurBuf = (gCurBuf + 1)%2;
	gFbc.frame_buffer = gBufs[gCurBuf].adr;
	gSeq++;
	FillBuffer(gMode, gFbc, gSeq, gSeq);
	SetFramebuffer(0, gBufs[gCurBuf].buf->gpuPhysAdr);
	DisplayIrqAck();
}

status_t TestDisplayIrq2()
{
	uint32 crtcId = 0;

	uint64 origGpuPhysAdr = 0;
	GetCurrentMode(gMode, gFbc, origGpuPhysAdr, crtcId);

	for (uint32 i = 0; i < 2; i++) {
		gBufs[i].SetTo(gDevice.MemMgr().Switch()->Alloc(boDomainVramMappable, gFbc.bytes_per_row*gMode.virtual_height));
		gFbc.frame_buffer = gBufs[i].adr;
		FillBuffer(gMode, gFbc, 0, 0);
	}
	gCurBuf = 0;

	DisplayIrqAck();

	uint32 irqs[] = {
		8, // page flip
	};

	for (uint32 i = 0; i < B_COUNT_OF(irqs); i++) {
		gDevice.IntHandler().Switch()->InstallHandler(0, irqs[i], &sDisplayIrqHandler2);
	}

	//WriteReg4AmdGpu(crtc_offsets[crtcId] + INT_MASK, VBLANK_INT_MASK);
	WriteReg4AmdGpu(crtc_offsets[crtcId] + GRPH_INT_CONTROL, GRPH_PFLIP_INT_MASK);
	printf("[WAIT]"); fgetc(stdin);
	SetFramebuffer(crtcId, gBufs[gCurBuf].buf->gpuPhysAdr);
	printf("[WAIT]"); fgetc(stdin);
	WriteReg4AmdGpu(crtc_offsets[crtcId] + GRPH_INT_CONTROL, 0);
	WriteReg4AmdGpu(crtc_offsets[crtcId] + INT_MASK, 0);
	printf("[WAIT]"); fgetc(stdin);
	SetFramebuffer(crtcId, origGpuPhysAdr);
	printf("[WAIT]"); fgetc(stdin);
	for (uint32 i = 0; i < 2; i++) {
		gBufs[i].SetTo(NULL);
	}

	return B_OK;
}

status_t TestDisplayConsumer()
{
	BApplication app("application/x-vnd.X512-RadeonGfx");
	ObjectDeleter<DisplayConsumer> consumer(new DisplayConsumer("RadeonGfxConsumer"));
	app.AddHandler(consumer.Get());

	uint32 crtcId = 0;
	display_mode mode{};
	frame_buffer_config fbc{};
	uint64 origGpuPhysAdr = 0;
	GetCurrentMode(mode, fbc, origGpuPhysAdr, crtcId);
	CheckRet(consumer->Init(crtcId, mode, fbc));

	app.Run();
	SetFramebuffer(crtcId, origGpuPhysAdr);
	snooze(10000);
	//printf("[WAIT]"); fgetc(stdin);
	return B_OK;
}


//#pragma mark - DMA utilities

struct DmaPacket {
	union {
		struct {
			uint32 n: 20; // 0
			uint32 unknown1: 2;
			uint32 s: 1; // 22
			uint32 t: 1; // 23
			uint32 unknown2: 2;
			uint32 b: 1; // 26
			uint32 unknown3: 1;
			uint32 cmd: 4; // 28
		};
		uint32 val;
	};
};

struct DmaIbPacket {
	union {
		struct {
			uint32 n: 20; // 0
			uint32 vmid: 4; // 20
			uint32 unknown1: 4;
			uint32 cmd: 4; // 28
		};
		uint32 val;
	};
};

struct DmaPacketFill {
	DmaPacket cmd;
	uint32 dstAdr1;
	uint32 srcVal;
	uint32 dstAdr2;
	DmaPacketFill(uint64 dstAdr, uint32 srcVal, uint32 byteCnt):
		cmd({.n = byteCnt/4, .cmd = DMA_PACKET_CONSTANT_FILL}),
		dstAdr1((uint32)dstAdr),
		srcVal(srcVal),
		dstAdr2((uint32)(dstAdr >> 32) << 16)
	{}
};

struct DmaPacketIb {
	DmaIbPacket cmd;
	uint32 adr1;
	uint32 adr2count;
	DmaPacketIb(uint64 adr, uint32 count, uint32 vmId):
		cmd({.vmid = vmId, .cmd = DMA_PACKET_INDIRECT_BUFFER}),
		adr1(adr & 0xFFFFFFE0),
		adr2count((count << 12) | ((uint32)(adr >> 32) & 0xFF))
	{}
};

static void GenDmaCopy(RadeonRingBuffer &ring, uint64 dstAdr, uint64 srcAdr, uint64 byteCnt)
{
	enum {blockSize = 0xffff8};
	while (byteCnt > 0) {
		uint64 copyCnt = std::min<uint32>(byteCnt, blockSize);
		GenDmaPacketCopy(ring, dstAdr, srcAdr, copyCnt);
		dstAdr += copyCnt;
		srcAdr += copyCnt;
		byteCnt -= copyCnt;
	}
}

static uint32 GenDmaCopyLen(uint64 byteCnt)
{
	enum {blockSize = 0xffff8};
	return 5*((byteCnt + (blockSize - 1)) / blockSize);
}

static void CopyDma(uint64 dstGpuAdr, uint64 srcGpuAdr, uint64 size)
{
	auto ringExt = gDevice.Rings(CAYMAN_RING_TYPE_DMA1_INDEX);
	RingFence fence;
	{auto ring = ringExt.Switch();
		ring->Begin(GenDmaCopyLen(size) + 5);
		GenDmaCopy(*ring, dstGpuAdr, srcGpuAdr, size);
		ring->WriteFence(&fence);
		ring->End();
		fence.Wait();
	}
}

template <typename Writer>
static void GenDmaFill(Writer &wr, uint64 dstAdr, uint32 srcVal, uint64 byteCnt)
{
	enum {blockSize = 0xffff8};
	while (byteCnt > 0) {
		uint64 copyCnt = std::min<uint32>(byteCnt, blockSize);
		wr.template Write<DmaPacketFill>() = {dstAdr, srcVal, copyCnt};
		//GenDmaPacketFill(wr, dstAdr, srcVal, copyCnt);
		dstAdr += copyCnt;
		byteCnt -= copyCnt;
	}
}

static uint32 GenDmaFillLen(uint64 byteCnt)
{
	enum {blockSize = 0xffff8};
	return 4*((byteCnt + (blockSize - 1)) / blockSize);
}

struct IBWriter {
	enum {bufSize = 1024*16};
	ExternalPtr<RadeonRingBuffer> ringExt;
	MappedBuffer ibMem;
	uint32 *testIbAdr, *testIbPos;

	IBWriter(ExternalPtr<RadeonRingBuffer> ring):
		ringExt(ring),
		ibMem(gDevice.MemMgr().Switch()->Alloc(boDomainGtt, bufSize)),
		testIbAdr((uint32*)ibMem.adr), testIbPos((uint32*)ibMem.adr)
	{}

	~IBWriter()
	{
		Flush();
	}

	size_t Length() {return testIbPos - testIbAdr;}

	inline void Write(uint32 val)
	{
		*testIbPos++ = val;
	}

	inline void Write8(uint64 val)
	{
		Write((uint32)(val));
		Write((uint32)(val >> 32));
	}

	template<typename Type>
	inline Type &Write()
	{
		Type *res = (Type*)testIbPos;
		testIbPos = (uint32*)(res + 1);
		return *res;
	}

	void Ensure(size_t size)
	{
		if (bufSize - 4*Length() < size) {
			Flush();
		}
	}

	void Flush()
	{
		if (Length() == 0) return;
		{
			auto ring = ringExt.Switch();
			RingFence fence;
			ring->Begin(8 + 5);
			GenDmaPacketIb(*ring, ibMem.buf->gpuPhysAdr, Length(), 0);
			ring->WriteFence(&fence);
			ring->End();
			fence.Wait();
		}
		testIbPos = testIbAdr;
	}
};

static void FillRegion(IBWriter &wr, const display_mode &mode, const frame_buffer_config &fbc, uint64 gpuAdr, const BRegion &rgn, uint32 color)
{
	int32 rectCnt = rgn.CountRects();

	for (int32 i = 0; i < rectCnt; i++) {
		clipping_rect rect = rgn.RectAtInt(i);
			for (int32 y = rect.top; y <= rect.bottom; y++) {
				wr.Ensure(GenDmaFillLen(4*(rect.bottom - rect.top + 1)*(rect.right - rect.left + 1)));
				GenDmaFill(wr, gpuAdr + y*fbc.bytes_per_row + 4*rect.left, color, 4*(rect.right - rect.left + 1));
			}
	}
}

static void FillRegionCpu(const display_mode &mode, const frame_buffer_config &fbc, void *cpuAdr, const BRegion &rgn, uint32 color)
{
	int32 rectCnt = rgn.CountRects();
	for (int32 i = 0; i < rectCnt; i++) {
		clipping_rect rect = rgn.RectAtInt(i);
		for (int32 y = rect.top; y <= rect.bottom; y++) {
			uint32 *line = (uint32*)((uint8*)cpuAdr + y*fbc.bytes_per_row) + rect.left;
			for (int32 cnt = rect.right + 1 - rect.left; cnt > 0; cnt--)
				*line++ = color;
		}
	}
}

//#pragma mark -

static void SaveImage(void *data, uint32 width, uint32 height, uint32 stride, uint32 idx)
{
	char name[256];
	sprintf(name, "%" B_PRIu32 ".ppm", idx);
	FILE *f = fopen(name, "wb+");
	fprintf(f, "P6\n%" B_PRIu32 "\n%" B_PRIu32 "\n255\n", width, height);
	ArrayDeleter<uint8> dstLine(new uint8[width*3]);
	for (uint32 y = 0; y < height; y++) {
		uint32 *line = (uint32*)((uint8*)data + y*stride);
		for(uint32 x = 0; x < width; x++) {
			uint32 val = line[x];
			dstLine[3*x] = (val >> 16) % 0x100;
			dstLine[3*x + 1] = (val >> 8) % 0x100;
			dstLine[3*x + 2] = (val) % 0x100;
		}
		fwrite(&dstLine[0], width*3, 1, f);
	}
	fclose(f);
}

status_t TestDisplayDma()
{
	printf("TestDisplayDma()\n");

	uint32 crtcId = 0;
	display_mode mode{};
	frame_buffer_config fbc{};
	uint64 origGpuPhysAdr = 0;
	GetCurrentMode(mode, fbc, origGpuPhysAdr, crtcId);

	size_t size = fbc.bytes_per_row*mode.virtual_height;
	MappedBuffer dstBuf(gDevice.MemMgr().Switch()->Alloc(boDomainVramMappable, size));

	enum {
		count = 1000,
	};
	bigtime_t t0 = system_time();
	for(uint32 i = 0; i < count; i++) {
		printf("step %" B_PRIu32 "\n", i);
		CopyDma(dstBuf.buf->gpuPhysAdr, origGpuPhysAdr, size);
		//memcpy(dstBuf.adr, gDevice.SharedInfo()->frame_buffer, size);
		//SaveImage(dstBuf.adr, mode.virtual_width, mode.virtual_height, fbc.bytes_per_row, i);
	}
	bigtime_t t1 = system_time();
	printf("%g FPS\n", (double)count/((t1 - t0)/1000000.0));
	printf("[WAIT]"); fgetc(stdin);

	return B_OK;
}

struct DrawDmaTask: public Object {
	bool run, done;

	display_mode mode;
	frame_buffer_config fbc;
	BReference<BufferObject> buf;

	DrawDmaTask(): run(true), done(false) {}

	void Do()
	{
		IBWriter wr(gDevice.Rings(CAYMAN_RING_TYPE_DMA1_INDEX));

		while (run) {
			for (uint32 i = 0; i < 100; i++) {
/*
				int32 l = rand()%mode.timing.h_display;
				int32 t = rand()%mode.timing.v_display;
				int32 r = rand()%mode.timing.h_display;
				int32 b = rand()%mode.timing.v_display;
*/
				enum {
					width = 16,
					height = 16
				};
				int32 l = rand()%(mode.timing.h_display - width);
				int32 t = rand()%(mode.timing.v_display - height);
				int32 r = l + width;
				int32 b = t + height;
				uint32 c = rand()%(1 << 24);
				if (l > r) std::swap<int32>(l, r);
				if (t > b) std::swap<int32>(t, b);
				FillRegion(wr, mode, fbc, buf->gpuPhysAdr, BRegion(BRect(l, t, r, b)), c);
			}
			Domain::Yield();
			//CurrentRootRequest()->Schedule();
		}
		wr.Flush();
		done = true;
	}
};

status_t TestDrawDma()
{
	printf("TestDrawDma()\n");

	uint32 crtcId = 0;
	uint64 origGpuPhysAdr = 0;

/*
	WriteReg4AmdGpu(crtc_offsets[crtcId] + mmGRPH_PITCH, 1920);
	WriteReg4AmdGpu(crtc_offsets[crtcId] + mmGRPH_X_START, 0);
	WriteReg4AmdGpu(crtc_offsets[crtcId] + mmGRPH_Y_START, 0);
	WriteReg4AmdGpu(crtc_offsets[crtcId] + mmGRPH_X_END, 1920);
	WriteReg4AmdGpu(crtc_offsets[crtcId] + mmGRPH_Y_END, 1080);
*/
	printf("[WAIT]"); fgetc(stdin);

	auto task = MakeExternal<DrawDmaTask>();
	{auto taskLocked = task.Switch();
		GetCurrentMode(taskLocked->mode, taskLocked->fbc, origGpuPhysAdr, crtcId);
		taskLocked->buf = gDevice.MemMgr().Switch()->Alloc(boDomainVramMappable, taskLocked->fbc.bytes_per_row*taskLocked->mode.virtual_height);

		MappedBuffer buf(taskLocked->buf);
		memset(buf.adr, 0xff, taskLocked->fbc.bytes_per_row*taskLocked->mode.virtual_height);

		SetFramebuffer(crtcId, taskLocked->buf->gpuPhysAdr);
	}

	MakeAsyncRequestMth(task, &DrawDmaTask::Do)->Schedule();
	printf("[WAIT]"); fgetc(stdin);
	task.Switch()->run = false;
	while (!task.Switch()->done) {}
	task.Delete();

#if 0
	enum {
		count = 1000,
	};
	bigtime_t t0 = system_time();
	for (uint32 i = 0; i < count; i++) {
		int32 l = rand()%mode.timing.h_display;
		int32 t = rand()%mode.timing.v_display;
		int32 r = rand()%mode.timing.h_display;
		int32 b = rand()%mode.timing.v_display;
		uint32 c = rand()%(1 << 24);
		if (l > r) std::swap<int32>(l, r);
		if (t > b) std::swap<int32>(t, b);
		FillRegion(mode, fbc, buf.buf->gpuPhysAdr, BRegion(BRect(l, t, r, b)), c);
		//FillRegionCpu(mode, fbc, buf.adr, BRegion(BRect(l, t, r, b)), c);
	}
	bigtime_t t1 = system_time();
	printf("%g rects/sec\n", (double)count/((t1 - t0)/1000000.0));
	printf("[WAIT]"); fgetc(stdin);
#endif

	SetFramebuffer(crtcId, origGpuPhysAdr);
	printf("[WAIT]"); fgetc(stdin);

	return B_OK;
}


status_t TestCursor()
{
	printf("TestCursor()\n");

	auto displayRoster = gDevice.Displays().Switch();
	auto display = displayRoster->DisplayAt(0);

	int32 bytesPerRow = 4*kCursorWidth;
	{
		CursorUpdate cursor{
			.valid = {
				.enabled = true,
				.pos = true,
				.org = true,
				.buffer = true,
				.format = true,
			},
			.enabled = true,
			.x = 256, .y = 192,
			.orgX = 1, .orgY = 1,
			.buffer = gDevice.MemMgr().Switch()->Alloc(boDomainVramMappable, bytesPerRow*kCursorHeight),
			.offset = 0,
			.bytesPerRow = bytesPerRow,
			.width = kCursorWidth, .height = kCursorHeight,
			.colorSpace = B_RGBA32
		};
		CheckRet(display->ValidateCursorFormat(cursor));
		MappedBuffer mappedBuf(cursor.buffer);

		for (uint32 y = 0; y < kCursorHeight; y++) {
			uint8 *dstLine = (uint8*)mappedBuf.adr + y*cursor.bytesPerRow;
			uint8 *srcLine = (uint8*)kCursorSystemDefaultBits + y*bytesPerRow;
			memcpy(dstLine, srcLine, bytesPerRow);
		}

		CheckRet(display->UpdateCursor(cursor));
	}
	printf("[WAIT]"); fgetc(stdin);

	{
		CursorUpdate cursor;
		CheckRet(display->GetCursor(cursor));
		MappedBuffer mappedBuf(cursor.buffer);
		for (uint32 y = 0; y < kCursorHeight; y++) {
			uint8 *dstLine = (uint8*)mappedBuf.adr + y*cursor.bytesPerRow;
			uint8 *srcLine = (uint8*)kCursorIBeamBits + y*bytesPerRow;
			memcpy(dstLine, srcLine, bytesPerRow);
		}
		CheckRet(display->UpdateCursor(CursorUpdate{
			.valid = {.org = true},
			.orgX = 7, .orgY = 9
		}));
	}
	printf("[WAIT]"); fgetc(stdin);

	CheckRet(display->UpdateCursor(CursorUpdate{
		.valid = {.pos = true},
		.x = 512, .y = 64
	}));
	printf("[WAIT]"); fgetc(stdin);

	CheckRet(display->UpdateCursor(CursorUpdate{
		.valid = {.enabled = true},
		.enabled = false,
	}));
	printf("[WAIT]"); fgetc(stdin);

	return B_OK;
}


status_t TestDisplay()
{
	printf("TestDisplay()\n");

	CheckRet(ShowMemoryCtrlState());
	//CheckRet(ShowCtrcState());
	switch (5) {
		case 0: CheckRet(TestMode()); break;
		case 1: CheckRet(TestSetFramebuffer()); break;
		case 2: CheckRet(TestDisplayIrq2()); break;
		case 3: CheckRet(TestDisplayConsumer()); break;
		case 4: CheckRet(TestDisplayDma()); break;
		case 5: CheckRet(TestDrawDma()); break;
		case 6: CheckRet(TestCursor()); break;
	}
	return B_OK;
}
