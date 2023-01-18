#include "DisplayConsumer.h"
#include <VideoBuffer.h>
#include "Radeon.h"
#include "RadeonDevice.h"
#include "RadeonMemory.h"
#include "TeamState.h"
#include "si_enums.h"
#include "dce_6_0.h"
#include "dce_6_0_d.h"
#include <stdio.h>
#include <syscalls.h>

#define RADEON_TILING_MACRO				0x1
#define RADEON_TILING_MICRO				0x2

struct AmdgpuTiling {
	union {
		struct {
			uint32 arrayMode: 4; // 0
			uint32 pipeConfig: 5; // 4
			uint32 tileSplit: 3; // 9
			uint32 microTileMode: 3; // 12
			uint32 bankWidth: 2; // 15
			uint32 bankHeight: 2; // 17
			uint32 macroTileAspect: 2; // 19
			uint32 numBanks: 2; // 21
		};
		uint32 val;
	};
};

#define SI_ADDR_SURF_P2              0
#define SI_ADDR_SURF_P4_8x16         4
#define SI_ADDR_SURF_P4_16x16        5
#define SI_ADDR_SURF_P4_16x32        6
#define SI_ADDR_SURF_P4_32x32        7
#define SI_ADDR_SURF_P8_16x16_8x16   8
#define SI_ADDR_SURF_P8_16x32_8x16   9
#define SI_ADDR_SURF_P8_32x32_8x16  10
#define SI_ADDR_SURF_P8_16x32_16x16 11
#define SI_ADDR_SURF_P8_32x32_16x16 12
#define SI_ADDR_SURF_P8_32x32_16x32 13
#define SI_ADDR_SURF_P8_32x64_32x32 14


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

static void evergreen_tiling_fields(
	AmdgpuTiling tiling_flags, unsigned *bankw,
	unsigned *bankh, unsigned *mtaspect,
	unsigned *tile_split
) {
	*bankw = tiling_flags.bankWidth;
	*bankh = tiling_flags.bankHeight;
	*mtaspect = tiling_flags.macroTileAspect;
	*tile_split = tiling_flags.tileSplit;
	switch (*bankw) {
	default:
	case 1: *bankw = 0; break;
	case 2: *bankw = 1; break;
	case 4: *bankw = 2; break;
	case 8: *bankw = 3; break;
	}
	switch (*bankh) {
	default:
	case 1: *bankh = 0; break;
	case 2: *bankh = 1; break;
	case 4: *bankh = 2; break;
	case 8: *bankh = 3; break;
	}
	switch (*mtaspect) {
	default:
	case 1: *mtaspect = 0; break;
	case 2: *mtaspect = 1; break;
	case 4: *mtaspect = 2; break;
	case 8: *mtaspect = 3; break;
	}
}

static void DumpGrphControl(GrphControl grphControl)
{
	printf("  grphDepth: %" B_PRIu32 "\n", grphControl.grphDepth);
	printf("  grphNumBanks: %" B_PRIu32 "\n", grphControl.grphNumBanks);
	printf("  grphZ: %" B_PRIu32 "\n", grphControl.grphZ);
	printf("  grphBankWidth: %" B_PRIu32 "\n", grphControl.grphBankWidth);
	printf("  grphFormat: %" B_PRIu32 "\n", grphControl.grphFormat);
	printf("  grphBankHeight: %" B_PRIu32 "\n", grphControl.grphBankHeight);
	printf("  grphTileSplit: %" B_PRIu32 "\n", grphControl.grphTileSplit);
	printf("  grphAddressTranslationEnable: %" B_PRIu32 "\n", grphControl.grphAddressTranslationEnable);
	printf("  grphPrivilegedAccessEnable: %" B_PRIu32 "\n", grphControl.grphPrivilegedAccessEnable);
	printf("  grphMacroTileAspect: %" B_PRIu32 "\n", grphControl.grphMacroTileAspect);
	printf("  grphArrayMode: %" B_PRIu32 "\n", grphControl.grphArrayMode);
	printf("  grphPipeConfig: %" B_PRIu32 "\n", grphControl.grphPipeConfig);
	printf("  unknown1: %" B_PRIu32 "\n", grphControl.unknown1);
	printf("  grphColorExpansionMode: %" B_PRIu32 "\n", grphControl.grphColorExpansionMode);
}

bool SetGrphControl(GrphControl &grphControl, color_space colorSpace, AmdgpuTiling tilingFlags)
{
	grphControl.val = 0;
	unsigned index;

	switch (colorSpace) {
		case B_CMAP8:
			grphControl.grphDepth = GRPH_DEPTH_8BPP;
			grphControl.grphFormat = GRPH_FORMAT_INDEXED;
			index = 10;
			break;
		case B_RGB15_LITTLE:
			grphControl.grphDepth = GRPH_DEPTH_16BPP;
			grphControl.grphFormat = GRPH_FORMAT_ARGB1555;
			index = 11 /*SI_TILE_MODE_COLOR_2D_SCANOUT_16BPP*/;
			break;
		case B_RGB16_LITTLE:
			grphControl.grphDepth = GRPH_DEPTH_16BPP;
			grphControl.grphFormat = GRPH_FORMAT_ARGB565;
			index = 11 /*SI_TILE_MODE_COLOR_2D_SCANOUT_16BPP*/;
			break;
		case B_RGB24_LITTLE: // ?
		case B_RGB32_LITTLE:
			grphControl.grphDepth = GRPH_DEPTH_32BPP;
			grphControl.grphFormat = GRPH_FORMAT_ARGB8888;
			index = 12 /*SI_TILE_MODE_COLOR_2D_SCANOUT_32BPP*/;
			break;
		default:
			return false;
	}

	if (tilingFlags.arrayMode == GRPH_ARRAY_2D_TILED_THIN1) {
		unsigned bankw, bankh, mtaspect, tile_split;
		evergreen_tiling_fields(tilingFlags, &bankw, &bankh, &mtaspect, &tile_split);

		unsigned num_banks = (gDevice.fInfo.gfx.config.tile_mode_array[index] >> 20) & 0x3;

		grphControl.grphNumBanks = num_banks;
		grphControl.grphArrayMode = GRPH_ARRAY_2D_TILED_THIN1;
		grphControl.grphTileSplit = tile_split;
		grphControl.grphBankWidth = bankw;
		grphControl.grphBankHeight = bankh;
		grphControl.grphMacroTileAspect = mtaspect;
	} else if (tilingFlags.arrayMode == GRPH_ARRAY_1D_TILED_THIN1)
		grphControl.grphArrayMode = GRPH_ARRAY_1D_TILED_THIN1;

	grphControl.grphPipeConfig = SI_ADDR_SURF_P4_8x16;

	return true;
}


static uint64 GetFramebuffer(uint32 crtcId)
{
	return ReadReg8LoHiAmdGpu(crtc_offsets[crtcId] + mmGRPH_PRIMARY_SURFACE_ADDRESS, crtc_offsets[crtcId] + mmGRPH_PRIMARY_SURFACE_ADDRESS_HIGH);
}

static void SetFramebuffer(uint32 crtcId, uint64 gpuPhysAdr)
{
	WriteReg8LoHiAmdGpu(crtc_offsets[crtcId] + mmGRPH_PRIMARY_SURFACE_ADDRESS, crtc_offsets[crtcId] + mmGRPH_PRIMARY_SURFACE_ADDRESS_HIGH, gpuPhysAdr);
	ReadReg4AmdGpu(crtc_offsets[crtcId] + mmGRPH_PRIMARY_SURFACE_ADDRESS);
}

static void AreaOfsFromAdr(area_id &area, uint64 &ofs, void *adr)
{
	area = area_for(adr);
	if (area < B_OK) return;
	area_info areaInfo;
	get_area_info(area, &areaInfo);
	ofs = (uint8*)adr - (uint8*)areaInfo.address;
}

status_t DisplayConsumer::SetupSwapChain(const SwapChainSpec& spec)
{
	SwapChain swapChain;
	swapChain.size = sizeof(SwapChain);
	swapChain.presentEffect = presentEffectSwap;
	swapChain.bufferCnt = spec.bufferCnt;
	ArrayDeleter<VideoBuffer> buffers(new VideoBuffer[swapChain.bufferCnt]);
	swapChain.buffers = buffers.Get();
	fBufs.SetTo(new MappedBuffer[swapChain.bufferCnt]);
	fSyncobjs.SetTo(new BReference<Syncobj>[swapChain.bufferCnt]);
	for (uint32 i = 0; i < swapChain.bufferCnt; i++) {
		fBufs[i] = gDevice.MemMgr().Switch()->Alloc(boDomainVramMappable, fFbc.bytes_per_row*fDm.virtual_height);
		buffers[i].id = i;
		buffers[i].ref.kind = spec.kind;
		switch (spec.kind) {
			case bufferRefArea: {
				AreaOfsFromAdr(buffers[i].ref.area.id, buffers[i].ref.offset, fBufs[i].adr);
				break;
			}
			case bufferRefGpu: {
				buffers[i].ref.gpu.fd = -1;
				buffers[i].ref.gpu.fenceFd = -1;
				int fd = fBufs[i].buf->AllocFd();
				if (fd < 0) return B_ERROR;
				buffers[i].ref.gpu.fd = _kern_dup_foreign(B_CURRENT_TEAM, B_CURRENT_TEAM, fd, O_CLOEXEC);
				CheckRet(buffers[i].ref.gpu.fd);
				fSyncobjs[i].SetTo(new Syncobj({.signaled = true}), true);
				fd = fSyncobjs[i]->AllocFd();
				if (fd < 0) return B_ERROR;
				buffers[i].ref.gpu.fenceFd = _kern_dup_foreign(B_CURRENT_TEAM, B_CURRENT_TEAM, fd, O_CLOEXEC);
				CheckRet(buffers[i].ref.gpu.fd);
				buffers[i].ref.offset = 0;
				break;
			}
			default:
				return B_BAD_VALUE;
		}
		buffers[i].ref.size           = fFbc.bytes_per_row * fDm.timing.v_display;
		buffers[i].format.bytesPerRow = fFbc.bytes_per_row;
		buffers[i].format.width       = fDm.timing.h_display;
		buffers[i].format.height      = fDm.timing.v_display;
		buffers[i].format.colorSpace  = (color_space)fDm.space;
	}
	SetSwapChain(&swapChain);
	return B_OK;
}

status_t DisplayConsumer::BindSwapChain()
{
	if (!SwapChainValid()) {
		fBufs.Unset();
		return B_OK;
	}
	if (OwnsSwapChain()) {
		return B_OK;
	}
	ExternalRef<TeamState> teamState = gTeamRoster.Switch()->ThisTeam(Link().Team(), false);
	fBufs.SetTo(new(std::nothrow) MappedBuffer[GetSwapChain().bufferCnt]);
	if (!fBufs.IsSet()) return B_NO_MEMORY;
	for (uint32 i = 0; i < GetSwapChain().bufferCnt; i++) {
		switch (GetSwapChain().buffers[i].ref.kind) {
			case bufferRefGpu: {
				struct stat st{};
				CheckRet(fstat(GetSwapChain().buffers[i].ref.gpu.fd, &st));
				BReference<FdObject> obj(FdObject::Lookup({st.st_dev, st.st_ino}), true);
				if (!obj.IsSet()) return ENOENT;
				BufferObject *buffer = dynamic_cast<BufferObject*>(obj.Get());
				if (buffer == NULL) return ENOENT;
				fBufs[i] = BReference(buffer);
#if 0
				AmdgpuTiling tilingInfo {.val = fBufs[i].buf->metadata.tiling_info};
				printf("fBufs[%" B_PRIu32 "].tiling_info: %#" B_PRIx32 "\n", i, tilingInfo.val);
				printf("fBufs[%" B_PRIu32 "].tiling_info.arrayMode: %" B_PRIu32 "\n", i, tilingInfo.arrayMode);
				printf("fBufs[%" B_PRIu32 "].tiling_info.pipeConfig: %" B_PRIu32 "\n", i, tilingInfo.pipeConfig);
				printf("fBufs[%" B_PRIu32 "].tiling_info.tileSplit: %" B_PRIu32 "\n", i, tilingInfo.tileSplit);
				printf("fBufs[%" B_PRIu32 "].tiling_info.microTileMode: %" B_PRIu32 "\n", i, tilingInfo.microTileMode);
				printf("fBufs[%" B_PRIu32 "].tiling_info.bankWidth: %" B_PRIu32 "\n", i, tilingInfo.bankWidth);
				printf("fBufs[%" B_PRIu32 "].tiling_info.bankHeight: %" B_PRIu32 "\n", i, tilingInfo.bankHeight);
				printf("fBufs[%" B_PRIu32 "].tiling_info.macroTileAspect: %" B_PRIu32 "\n", i, tilingInfo.macroTileAspect);
				printf("fBufs[%" B_PRIu32 "].tiling_info.numBanks: %" B_PRIu32 "\n", i, tilingInfo.numBanks);
				if (i == 0) {
					GrphControl grphControl;
					if (!SetGrphControl(grphControl, B_RGB32_LITTLE /*GetSwapChain().buffers[i].format.colorSpace*/, tilingInfo)) {
						fprintf(stderr, "[!] SetGrphControl failed\n");
					}
					printf("grphControl:\n");
					DumpGrphControl(grphControl);
					WriteReg4AmdGpu(crtc_offsets[fCrtcId] + mmGRPH_CONTROL, grphControl.val);
				}
#endif
				break;
			}
			default:
				return B_NOT_ALLOWED;
		}
	}
	return B_OK;
}


DisplayConsumer::DisplayConsumer(const char* name): VideoConsumer(name)
{
}

DisplayConsumer::~DisplayConsumer()
{
	printf("-DisplayConsumer: "); WriteMessenger(BMessenger(this)); printf("\n");

	WriteReg4AmdGpu(crtc_offsets[fCrtcId] + mmGRPH_INTERRUPT_CONTROL, 0);

	gDevice.IntRing().Switch()->UninstallHandler(0, 8 + 2*fCrtcId);
}

status_t DisplayConsumer::Init(uint32 crtcId, const display_mode &dm, const frame_buffer_config &fbc)
{
	fCrtcId = crtcId;
	fDm = dm;
	fFbc = fbc;
	fOrigGrphControl = ReadReg4AmdGpu(crtc_offsets[fCrtcId] + mmGRPH_CONTROL);
	fOrigGpuPhysAdr = GetFramebuffer(fCrtcId);
	fBufs.Unset();

#if 0
	GrphControl origGrphControl {.val = fOrigGrphControl};
	printf("origGrphControl:\n");
	DumpGrphControl(GrphControl{.val = fOrigGrphControl});
#endif

	gDevice.IntRing().Switch()->InstallHandler(0, 8 + 2*fCrtcId, [](void *arg, InterruptPacket &pkt) {
		((DisplayConsumer*)arg)->IrqHandler(pkt);
	}, this);

	WriteReg4AmdGpu(crtc_offsets[fCrtcId] + mmGRPH_FLIP_CONTROL, 0);
	WriteReg4AmdGpu(crtc_offsets[fCrtcId] + mmGRPH_INTERRUPT_CONTROL, GrphInterruptControl{.grphPflipIntMask = true}.val);

	return B_OK;
}

void DisplayConsumer::Connected(bool isActive)
{
	if (isActive) {
		printf("DisplayConsumer: connected to ");
		WriteMessenger(Link());
		printf("\n");
	} else {
		printf("DisplayConsumer: disconnected\n");
		SetSwapChain(NULL);
		WriteReg4AmdGpu(crtc_offsets[fCrtcId] + mmGRPH_CONTROL, fOrigGrphControl);
		SetFramebuffer(fCrtcId, fOrigGpuPhysAdr);
	}
}

status_t DisplayConsumer::SwapChainRequested(const SwapChainSpec& spec)
{
	printf("DisplayConsumer::SwapChainRequested(%" B_PRIuSIZE ")\n", spec.bufferCnt);
	return SetupSwapChain(spec);
}

void DisplayConsumer::SwapChainChanged(bool isValid)
{
	printf("DisplayConsumer::SwapChainChanged(%d)\n", isValid);
	VideoConsumer::SwapChainChanged(isValid);
	status_t res = BindSwapChain();
	if (res < B_OK) {
		printf("[!] BindSwapChain() failed: %#" B_PRIx32 "(%s)\n", res, strerror(res));
	}
}

void DisplayConsumer::Present(int32 bufferId, const BRegion* dirty)
{
	SetFramebuffer(fCrtcId, fBufs[bufferId].buf->gpuPhysAdr);
}


void DisplayConsumer::IrqHandler(InterruptPacket &pkt)
{
	printf("DisplayConsumer::IrqHandler: %" B_PRIu32 "\n", pkt.srcId);
	PresentedInfo presentedInfo {};
	Presented(presentedInfo);
	DisplayIrqAck();
}
