#include "GfxUnit.h"
#include "GfxV6RingPackets.h"
#include "InterruptHandler.h"
#include "RadeonInit.h"
#include "RadeonFirmware.h"
#include "gfx_6_0.h"
#include "gfx_6_0_d.h"

#define RADEON_CP_PACKET2                           0x80000000

#include <stdio.h>
#include <new>


struct GfxRegs {
	uint32 rbRptr;
	uint32 rbBase;
	uint32 rbCntl;
	uint32 rbRptrAdrLo;
	uint32 rbRptrAdrHi;
	uint32 rbWptr;
	uint32 intCntl;
};


static uint32 OrderBase2(uint64 val)
{
	for (uint32 res = 0; res < 64; res++) {
		if (((uint64)1 << res) >= val) return res;
	}
	return 64;
}

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


static const GfxRegs &GetGfxRegs(RingType type)
{
	switch (type) {
		case RADEON_RING_TYPE_GFX_INDEX: {
			static GfxRegs regs{
				.rbRptr      = mmCP_RB0_RPTR,
				.rbBase      = mmCP_RB0_BASE,
				.rbCntl      = mmCP_RB0_CNTL,
				.rbRptrAdrLo = mmCP_RB0_RPTR_ADDR,
				.rbRptrAdrHi = mmCP_RB0_RPTR_ADDR_HI,
				.rbWptr      = mmCP_RB0_WPTR,
				.intCntl     = mmCP_INT_CNTL_RING0
			};
			return regs;
		}
		case CAYMAN_RING_TYPE_CP1_INDEX: {
			static GfxRegs regs{
				.rbRptr      = mmCP_RB1_RPTR,
				.rbBase      = mmCP_RB1_BASE,
				.rbCntl      = mmCP_RB1_CNTL,
				.rbRptrAdrLo = mmCP_RB1_RPTR_ADDR,
				.rbRptrAdrHi = mmCP_RB1_RPTR_ADDR_HI,
				.rbWptr      = mmCP_RB1_WPTR,
				.intCntl     = mmCP_INT_CNTL_RING1
			};
			return regs;
		}
		case CAYMAN_RING_TYPE_CP2_INDEX: {
			static GfxRegs regs{
				.rbRptr      = mmCP_RB2_RPTR,
				.rbBase      = mmCP_RB2_BASE,
				.rbCntl      = mmCP_RB2_CNTL,
				.rbRptrAdrLo = mmCP_RB2_RPTR_ADDR,
				.rbRptrAdrHi = mmCP_RB2_RPTR_ADDR_HI,
				.rbWptr      = mmCP_RB2_WPTR,
				.intCntl     = mmCP_INT_CNTL_RING2
			};
			return regs;
		}
		default:;
	}
	abort();
}


// #pragma mark RadeonRingBufferGfx

class RadeonRingBufferGfx final: public RadeonRingBuffer {
private:
	const GfxRegs &fRegs;

	class InterruptSource: public ::InterruptSource {
	public:
		RadeonRingBufferGfx &Base() {return ContainerOf(*this, &RadeonRingBufferGfx::fIntSource);}

		status_t Enable(bool doEnable) final;
		void InterruptReceived(InterruptPacket &pkt) final;
	} fIntSource;

protected:
	status_t Start() override;
	status_t Stop() override;

public:
	RadeonRingBufferGfx(RingType type);
	virtual ~RadeonRingBufferGfx();
	uint32 NopPacket() const override;
	uint32 Rptr() override;
	uint32 Wptr() override;
	void SetWptr(uint32 val) override;
	void WriteFence2() override;
	void WriteIb(uint64 adr, uint32 count, uint32 vmId) override;
	void WriteVmFlush(uint32 vmId, uint64 pdAdr) override;
};


status_t RadeonRingBufferGfx::InterruptSource::Enable(bool doEnable)
{
	CpIntCntlRing0 intCntl{.val = ReadReg4AmdGpu(Base().fRegs.intCntl)};
	intCntl.timeStampIntEnable = doEnable != false;
	WriteReg4AmdGpu(Base().fRegs.intCntl, intCntl.val);

	return B_OK;
}

void RadeonRingBufferGfx::InterruptSource::InterruptReceived(InterruptPacket &pkt)
{
	//ExternalPtr<RadeonRingBufferGfx>(&Base()).Switch()->UpdateFences();

	switch (pkt.ringId) {
	case RADEON_RING_TYPE_GFX_INDEX:
	case CAYMAN_RING_TYPE_CP1_INDEX:
	case CAYMAN_RING_TYPE_CP2_INDEX:
		gDevice.Rings(pkt.ringId).Switch()->UpdateFences();
		break;
	}
}

RadeonRingBufferGfx::RadeonRingBufferGfx(RingType type):
	RadeonRingBuffer(type),
	fRegs(GetGfxRegs(type))
{}

RadeonRingBufferGfx::~RadeonRingBufferGfx() {}

status_t RadeonRingBufferGfx::Start()
{
	CpRb0Cntl rbCntl{
		.rbBufsz = OrderBase2(4*fSize / 8),
		.rbBlksz = OrderBase2(B_PAGE_SIZE / 8)
	};
	WriteReg4AmdGpu(fRegs.rbCntl, rbCntl.val);

	rbCntl.rbRptrWrEna = 1;
	WriteReg4AmdGpu(fRegs.rbCntl, rbCntl.val);
	WriteReg4AmdGpu(fRegs.rbWptr, fWptr);
	WriteReg8LoHiAmdGpu(fRegs.rbRptrAdrLo, fRegs.rbRptrAdrHi, fRptrGpuAdr);
	// rbCntl.rbNoUpdate = 1

	snooze(1000);
	rbCntl.rbRptrWrEna = 0;
	WriteReg4AmdGpu(fRegs.rbCntl, rbCntl.val);

	WriteReg4AmdGpu(fRegs.rbBase, fBuffer.buf->gpuPhysAdr >> 8);

	gDevice.IntHandler().Switch()->InstallHandler(0, intSrcIdCpEop, &fIntSource);
	fIntSource.Enable(true);

	return B_OK;
}

status_t RadeonRingBufferGfx::Stop()
{
	printf("[!] RadeonRingBufferGfx::Stop(): not implemented\n");
	return B_NOT_SUPPORTED;
}

uint32 RadeonRingBufferGfx::NopPacket() const {return RADEON_CP_PACKET2;}
uint32 RadeonRingBufferGfx::Rptr() {return (*fRptrAdr)*4 /* ReadReg4AmdGpu(fRegs.rbRptr)*4 */;}
uint32 RadeonRingBufferGfx::Wptr() {return ReadReg4AmdGpu(fRegs.rbWptr)*4;}
void   RadeonRingBufferGfx::SetWptr(uint32 val) {WriteReg4AmdGpu(fRegs.rbWptr, val/4); Wptr();}
void   RadeonRingBufferGfx::WriteFence2() {GenFence(*this, fFenceGpuAdr, Wseq(), {.intr = true});}
void   RadeonRingBufferGfx::WriteIb(uint64 adr, uint32 count, uint32 vmId) {GenIbFlushCaches(*this, adr, count, vmId);}
void   RadeonRingBufferGfx::WriteVmFlush(uint32 vmId, uint64 pdAdr) {GenFlushVm(*this, vmId, pdAdr);}


// #pragma mark - GfxUnit

class GfxV6Unit: public GfxUnit {
private:
	ExternalUniquePtr<RadeonRingBuffer> fGfxRings[1];
	ExternalUniquePtr<RadeonRingBuffer> fComputeRings[2];

protected:
	status_t InitSoftware2() override;
	status_t FiniSoftware2() override;
	status_t InitHardware2() override;
	status_t FiniHardware2() override;

public:
	using GfxUnit::GfxUnit;

	virtual ~GfxV6Unit();
	const UnitInfo *GetInfo() override;

	uint32 GfxRingCount() override;
	ExternalPtr<RadeonRingBuffer> *GfxRings() override;
	uint32 ComputeRingCount() override;
	ExternalPtr<RadeonRingBuffer> *ComputeRings() override;
};


GfxUnit *GfxV6UnitNew(RadeonDevice *device)
{
	return new(std::nothrow) GfxV6Unit(device);
}


GfxV6Unit::~GfxV6Unit()
{}

const UnitInfo *GfxV6Unit::GetInfo()
{
	static const UnitInfo info {
		.type = UnitType::gfx,
		.version = {6, 0, 0},
		.name = "GFX v6.0"
	};
	return &info;
}

static status_t InitRing(RadeonDevice *dev, ExternalUniquePtr<RadeonRingBuffer> &ring, ExternalPtr<RadeonRingBuffer> (*New)(RingType type), RingType type, uint32 size)
{
	ring.SetTo(New(type));
	if (!ring.IsSet()) return B_NO_MEMORY;
	CheckRet(ring.Switch()->Init(size));
	dev->InitRing(type, ring);
	return B_OK;
}

static status_t PreinitGfxRings()
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

status_t GfxV6Unit::InitSoftware2()
{
	return B_OK;
}

status_t GfxV6Unit::FiniSoftware2()
{
	return B_OK;
}

status_t GfxV6Unit::InitHardware2()
{
#if 0
	printf("InitGpu()\n");
	CheckRet(InitGpu());
	snooze(10000);

	printf("InitRlc()\n");
	CheckRet(InitRlc());
	snooze(10000);

	printf("LoadCpMicrocode()\n");
	CheckRet(LoadCpMicrocode());
	printf("regs[CP_ME_CNTL]: %#" B_PRIx32 "\n", ReadReg4AmdGpu(mmCP_ME_CNTL));
	snooze(10000);

	{
		uint32 grbmStatus = ReadReg4AmdGpu(mmGRBM_STATUS);
		printf("regs[GRBM_STATUS]: %#" B_PRIx32 "(", grbmStatus);
		WriteSet(grbmStatus); printf(")\n");
	}
	printf("reset CP\n");
	uint32 resetGfx =
		SOFT_RESET_CB |
		SOFT_RESET_DB |
		SOFT_RESET_GDS |
		SOFT_RESET_PA |
		SOFT_RESET_SC |
		SOFT_RESET_BCI |
		SOFT_RESET_SPI |
		SOFT_RESET_SX |
		SOFT_RESET_TC |
		SOFT_RESET_TA |
		SOFT_RESET_VGT |
		SOFT_RESET_IA;
	WriteReg4AmdGpu(mmGRBM_SOFT_RESET, SOFT_RESET_CP | resetGfx);
	ReadReg4AmdGpu(mmGRBM_SOFT_RESET);
	snooze(15000);
	WriteReg4AmdGpu(mmGRBM_SOFT_RESET, 0);
	snooze(15000);
	{
		uint32 grbmStatus = ReadReg4AmdGpu(mmGRBM_STATUS);
		printf("regs[GRBM_STATUS]: %#" B_PRIx32 "(", grbmStatus);
		WriteSet(grbmStatus); printf(")\n");
	}

#endif
	printf("PreinitGfxRings()\n");
	PreinitGfxRings();

	static RingType gfxRingTypes[] = {RADEON_RING_TYPE_GFX_INDEX};
	static RingType computeRingTypes[] = {CAYMAN_RING_TYPE_CP1_INDEX, CAYMAN_RING_TYPE_CP2_INDEX};
	for (uint32 i = 0; i < B_COUNT_OF(fGfxRings); i++) {
		CheckRet(InitRing(Device(), fGfxRings[i], [](RingType type) -> ExternalPtr<RadeonRingBuffer> {return MakeExternal<RadeonRingBufferGfx>(type);}, gfxRingTypes[i], 0x2000));
	}
	for (uint32 i = 0; i < B_COUNT_OF(fComputeRings); i++) {
		CheckRet(InitRing(Device(), fComputeRings[i], [](RingType type) -> ExternalPtr<RadeonRingBuffer> {return MakeExternal<RadeonRingBufferGfx>(type);}, computeRingTypes[i], 0x2000));
	}
	snooze(10000);

	printf("+InitCP()\n");
	CheckRet(InitCP());
	printf("-InitCP()\n");
	snooze(10000);
	printf("regs[CP_ME_CNTL]: %#" B_PRIx32 "\n", ReadReg4AmdGpu(mmCP_ME_CNTL));

	return B_OK;
}

status_t GfxV6Unit::FiniHardware2()
{
	return B_OK;
}

uint32 GfxV6Unit::GfxRingCount()
{
	return B_COUNT_OF(fGfxRings);
}

ExternalPtr<RadeonRingBuffer> *GfxV6Unit::GfxRings()
{
	return (ExternalPtr<RadeonRingBuffer>*)fGfxRings;
}

uint32 GfxV6Unit::ComputeRingCount()
{
	return B_COUNT_OF(fComputeRings);
}

ExternalPtr<RadeonRingBuffer> *GfxV6Unit::ComputeRings()
{
	return (ExternalPtr<RadeonRingBuffer>*)fComputeRings;
}
