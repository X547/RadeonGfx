#include "si_enums.h"
#include "dce_6_0.h"
#include "dce_6_0_d.h"

#include "DisplayRoster.h"
#include "Radeon.h"
#include "RadeonDevice.h"
#include "RadeonMemory.h"
#include "DisplayConsumer.h"
#include <stdio.h>

#include <Application.h>

#include <map>

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


//#pragma mark - RadeonDisplay

RadeonDisplay::RadeonDisplay():
	fCursor{.valid = {.enabled = true}, .enabled = false}
{
}

status_t RadeonDisplay::InitConsumer()
{
	fConsumer.SetTo(new DisplayConsumer("RadeonGfxConsumer"));
	be_app->AddHandler(fConsumer.Get());
	
	display_mode mode{};
	frame_buffer_config fbc{};
	uint64 origGpuPhysAdr = 0;
	GetCurrentMode(mode, fbc, origGpuPhysAdr, fCrtcId);
	CheckRet(((DisplayConsumer*)fConsumer.Get())->Init(fCrtcId, mode, fbc));
	return B_OK;
}


status_t RadeonDisplay::SetFramebuffer(uint64 gpuAdr)
{
	WriteReg8LoHiAmdGpu(crtc_offsets[fCrtcId] + mmGRPH_PRIMARY_SURFACE_ADDRESS, crtc_offsets[fCrtcId] + mmGRPH_PRIMARY_SURFACE_ADDRESS_HIGH, gpuAdr);
	ReadReg4AmdGpu(crtc_offsets[fCrtcId] + mmGRPH_PRIMARY_SURFACE_ADDRESS);

	return B_OK;
}

status_t RadeonDisplay::ValidateCursorFormat(CursorUpdate &update)
{
	if (!update.valid.format)
		return B_BAD_VALUE;
	if (update.width > 64 || update.height > 64)
		return B_NOT_SUPPORTED;
	if (update.colorSpace != B_RGBA32)
		return B_NOT_SUPPORTED;
	update.bytesPerRow = 4*64;
	return B_OK;
}

status_t RadeonDisplay::GetCursor(CursorUpdate &update)
{
	update = fCursor;
	return B_OK;
}

status_t RadeonDisplay::UpdateCursor(const CursorUpdate &update)
{
	// TODO: checks
	if (update.valid.enabled) {
		fCursor.enabled = update.enabled;
	}
	if (update.valid.pos) {
		fCursor.x = update.x;
		fCursor.y = update.y;
	}
	if (update.valid.org) {
		fCursor.orgX = update.orgX;
		fCursor.orgY = update.orgY;
	}
	if (update.valid.buffer) {
		fCursor.buffer = update.buffer;
		fCursor.offset = update.offset;
	}
	if (update.valid.format) {
		fCursor.bytesPerRow = update.bytesPerRow;
		fCursor.width = update.width;
		fCursor.height = update.height;
		fCursor.colorSpace = update.colorSpace;
	}
	fCursor.valid.val |= update.valid.val;

	CurUpdate curUpdate {.val = ReadReg4AmdGpu(crtc_offsets[fCrtcId] + mmCUR_UPDATE)};
	curUpdate.cursorUpdateLock = true;
	WriteReg4AmdGpu(crtc_offsets[fCrtcId] + mmCUR_UPDATE, curUpdate.val);

	if (update.valid.pos)
		WriteReg4AmdGpu(crtc_offsets[fCrtcId] + mmCUR_POSITION, CurPosition{
			.cursorYPosition = fCursor.y,
			.cursorXPosition = fCursor.x
		}.val);
	if (update.valid.org)
		WriteReg4AmdGpu(crtc_offsets[fCrtcId] + mmCUR_HOT_SPOT, CurHotSpot{
			.cursorHotSpotY = fCursor.orgY,
			.cursorHotSpotX = fCursor.orgX
		}.val);
	if (update.valid.format)
		WriteReg4AmdGpu(crtc_offsets[fCrtcId] + mmCUR_SIZE, CurSize{
			.cursorHeight = fCursor.height - 1,
			.cursorWidth = fCursor.width - 1
		}.val);
	if (update.valid.buffer)
		WriteReg8LoHiAmdGpu(mmCUR_SURFACE_ADDRESS, mmCUR_SURFACE_ADDRESS_HIGH, fCursor.buffer->gpuPhysAdr + fCursor.offset);
	if (update.valid.enabled || update.valid.format) {
		/*WriteRegIdx4*/WriteReg4AmdGpu(mmCUR_CONTROL + crtc_offsets[fCrtcId], CurControl{
			.cursorEn = fCursor.enabled,
			.cursorMode = CURSOR_24_8_UNPRE_MULT,
			.cursorUrgentControl = CURSOR_URGENT_1_2,
		}.val);
	}

	curUpdate.val = ReadReg4AmdGpu(crtc_offsets[fCrtcId] + mmCUR_UPDATE);
	curUpdate.cursorUpdateLock = false;
	WriteReg4AmdGpu(crtc_offsets[fCrtcId] + mmCUR_UPDATE, curUpdate.val);

	return B_OK;
}


//#pragma mark - DisplayRoster

DisplayRoster::DisplayRoster()
{
	for (uint32 i = 0; i < maxCrtcCount; i++) {
		auto &display = fDisplays[i];
		display.fCrtcId = i;
		display.fCrtcOfs = crtc_offsets[i];
	}
}

DisplayRoster::~DisplayRoster()
{}

status_t DisplayRoster::Init()
{
	CheckRet(DisplayAt(0)->InitConsumer());
	return B_OK;
}

status_t DisplayRoster::RegisterFramebuffers()
{
	printf("DisplayRoster::RegisterFramebuffers()\n");
	std::map<uint64, BReference<BufferObject> > buffers;

	for (uint32 crtcId = 0; crtcId < maxCrtcCount; crtcId++) {
		CrtcControl crtcControl {.val = ReadReg4AmdGpu(crtc_offsets[crtcId] + mmCRTC_CONTROL)};
		if (!crtcControl.crtcMasterEn) continue;
		printf("CRTC %" B_PRIu32 "\n", crtcId);
		display_mode mode;
		frame_buffer_config fbc;
		uint64 gpuPhysAdr;
		GetCurrentMode(mode, fbc, gpuPhysAdr, crtcId);
		printf("  total frame: (%" B_PRIu32 ", %" B_PRIu32 ")\n",
			mode.virtual_width, mode.virtual_height
		);
		printf("  viewport frame: (%" B_PRIu32 ", %" B_PRIu32 ", %" B_PRIu32 ", %" B_PRIu32 ")\n",
			mode.h_display_start, mode.v_display_start,
			mode.h_display_start + mode.timing.h_display, mode.v_display_start + mode.timing.v_display
		);
		printf("  bytes per row: %" B_PRIu32 "\n", fbc.bytes_per_row);
		printf("  GPU address: %#" B_PRIx64 "\n", gpuPhysAdr);

		auto it = buffers.find(gpuPhysAdr);
		if (it == buffers.end()) {
			BReference<BufferObject> buffer = gDevice.MemMgr().Switch()->AllocAt(gpuPhysAdr, fbc.bytes_per_row*mode.virtual_height);
			if (!buffer.IsSet()) {
				printf("  can't allocate buffer\n");
			} else {
				it = buffers.emplace(gpuPhysAdr, buffer).first;
				printf("  buffer allocated, adr: %#" B_PRIx64 ", size: %#" B_PRIx64 "\n", it->second->gpuPhysAdr, it->second->size);
			}
		}
		fDisplays[crtcId].fBuffer = it->second;
	}

	return B_OK;
}


uint32 DisplayRoster::CountDisplays()
{
	return maxCrtcCount;
}

RadeonDisplay *DisplayRoster::DisplayAt(uint32 idx)
{
	if (idx >= maxCrtcCount) return NULL;
	return &fDisplays[idx];
}
