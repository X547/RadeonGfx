#include "DmaV1Unit.h"
#include "Radeon.h"
#include "RingBuffer.h"
#include "DmaV1RingPackets.h"
#include "RadeonInterrupts.h"
#include "sid_amdgpu.h"

#include <stdio.h>
#include <new>


struct DmaRegs {
	uint32 rbRptr;
	uint32 rbBase;
	uint32 rbCntl;
	uint32 rbRptrAdrLo;
	uint32 rbRptrAdrHi;
	uint32 rbWptr;
	uint32 ibCntl;
	uint32 cntl;
	uint32 semIncompleteTimerCntl;
	uint32 semWaitFailTimerCntl;

	uint32 irqSrcId;
};


// #pragma mark - RadeonRingBufferDma

class RadeonRingBufferDma final: public RadeonRingBuffer {
private:
	const DmaRegs &fRegs;

protected:
	status_t Start() override;
	status_t Stop() override;

public:
	RadeonRingBufferDma(RingType type);
	virtual ~RadeonRingBufferDma();
	uint32 NopPacket() const override;
	uint32 Rptr() override;
	uint32 Wptr() override;
	void SetWptr(uint32 val) override;
	void WriteFence2() override;
	void WriteIb(uint64 adr, uint32 count, uint32 vmId) override;
	void WriteVmFlush(uint32 vmId, uint64 pdAdr) override;
};

static uint32 OrderBase2(uint64 val)
{
	for (uint32 res = 0; res < 64; res++) {
		if (((uint64)1 << res) >= val) return res;
	}
	return 64;
}

static const DmaRegs &GetDmaRegs(RingType type)
{
	switch (type) {
		case R600_RING_TYPE_DMA_INDEX: {
			static DmaRegs regs{
				.rbRptr      = DMA0_REGISTER_OFFSET + DMA_RB_RPTR,
				.rbBase      = DMA0_REGISTER_OFFSET + DMA_RB_BASE,
				.rbCntl      = DMA0_REGISTER_OFFSET + DMA_RB_CNTL,
				.rbRptrAdrLo = DMA0_REGISTER_OFFSET + DMA_RB_RPTR_ADDR_LO,
				.rbRptrAdrHi = DMA0_REGISTER_OFFSET + DMA_RB_RPTR_ADDR_HI,
				.rbWptr      = DMA0_REGISTER_OFFSET + DMA_RB_WPTR,
				.ibCntl      = DMA0_REGISTER_OFFSET + DMA_IB_CNTL,
				.cntl        = DMA0_REGISTER_OFFSET + DMA_CNTL,
				.semIncompleteTimerCntl
				             = DMA0_REGISTER_OFFSET + DMA_SEM_INCOMPLETE_TIMER_CNTL,
				.semWaitFailTimerCntl
				             = DMA0_REGISTER_OFFSET + DMA_SEM_WAIT_FAIL_TIMER_CNTL,

				.irqSrcId    = intSrcIdRingDma0
			};
			return regs;
		}
		case CAYMAN_RING_TYPE_DMA1_INDEX: {
			static DmaRegs regs{
				.rbRptr      = DMA1_REGISTER_OFFSET + DMA_RB_RPTR,
				.rbBase      = DMA1_REGISTER_OFFSET + DMA_RB_BASE,
				.rbCntl      = DMA1_REGISTER_OFFSET + DMA_RB_CNTL,
				.rbRptrAdrLo = DMA1_REGISTER_OFFSET + DMA_RB_RPTR_ADDR_LO,
				.rbRptrAdrHi = DMA1_REGISTER_OFFSET + DMA_RB_RPTR_ADDR_HI,
				.rbWptr      = DMA1_REGISTER_OFFSET + DMA_RB_WPTR,
				.ibCntl      = DMA1_REGISTER_OFFSET + DMA_IB_CNTL,
				.cntl        = DMA1_REGISTER_OFFSET + DMA_CNTL,
				.semIncompleteTimerCntl
				             = DMA1_REGISTER_OFFSET + DMA_SEM_INCOMPLETE_TIMER_CNTL,
				.semWaitFailTimerCntl
				             = DMA1_REGISTER_OFFSET + DMA_SEM_WAIT_FAIL_TIMER_CNTL,

				.irqSrcId    = intSrcIdRingDma1
			};
			return regs;
		}
		default:;
	}
	abort();
}

RadeonRingBufferDma::RadeonRingBufferDma(RingType type):
	RadeonRingBuffer(type),
	fRegs(GetDmaRegs(type))
{}

RadeonRingBufferDma::~RadeonRingBufferDma() {}

status_t RadeonRingBufferDma::Start()
{
	gDevice.IntRing().Switch()->InstallHandler(0, fRegs.irqSrcId, [](void *arg, InterruptPacket &pkt) {
		(void)pkt;
		ExternalPtr<RadeonRingBufferDma>((RadeonRingBufferDma*)arg).Switch()->UpdateFences();
	}, this);

	WriteReg4AmdGpu(fRegs.semIncompleteTimerCntl, 0);
	WriteReg4AmdGpu(fRegs.semWaitFailTimerCntl, 0);

	uint32 dmaRbCntl = 0;
	dmaRbCntl |= DMA_RB_SIZE(OrderBase2(fSize));
	WriteReg4AmdGpu(fRegs.rbCntl, dmaRbCntl);

	WriteReg4AmdGpu(fRegs.rbRptr, 0);
	WriteReg4AmdGpu(fRegs.rbWptr, 0);

	WriteReg8LoHiAmdGpu(fRegs.rbRptrAdrLo, fRegs.rbRptrAdrHi, fRptrGpuAdr);
	dmaRbCntl |= DMA_RPTR_WRITEBACK_ENABLE;

	uint64 ibCntl = DMA_IB_ENABLE;
	WriteReg4AmdGpu(fRegs.ibCntl, ibCntl);

	WriteReg4AmdGpu(fRegs.rbBase, fBuffer.buf->gpuPhysAdr >> 8);

	uint32 dmaCntl = ReadReg4AmdGpu(fRegs.cntl);
	dmaCntl |= TRAP_ENABLE;
	WriteReg4AmdGpu(fRegs.cntl, dmaCntl);

	WriteReg4AmdGpu(fRegs.rbWptr, 0);
	WriteReg4AmdGpu(fRegs.rbCntl, dmaRbCntl | DMA_RB_ENABLE);

	return B_OK;
}

status_t RadeonRingBufferDma::Stop()
{
	WriteReg4AmdGpu(fRegs.rbCntl, ReadReg4AmdGpu(fRegs.rbCntl) & ~DMA_RB_ENABLE);
	WriteReg4AmdGpu(fRegs.cntl, ReadReg4AmdGpu(fRegs.cntl) & ~TRAP_ENABLE);
	gDevice.IntRing().Switch()->UninstallHandler(0, fRegs.irqSrcId);
	return B_OK;
}


uint32 RadeonRingBufferDma::NopPacket() const {return DMA_PACKET(DMA_PACKET_NOP, 0, 0, 0, 0);}
uint32 RadeonRingBufferDma::Rptr() {return *fRptrAdr /*ReadReg4AmdGpu(fRegs.rbRptr)*/;}
uint32 RadeonRingBufferDma::Wptr() {return ReadReg4AmdGpu(fRegs.rbWptr);}
void   RadeonRingBufferDma::SetWptr(uint32 val) {WriteReg4AmdGpu(fRegs.rbWptr, val);}
void   RadeonRingBufferDma::WriteFence2() {GenDmaPacketFence(*this, fFenceGpuAdr, Wseq());}
void   RadeonRingBufferDma::WriteIb(uint64 adr, uint32 count, uint32 vmId) {GenDmaPacketIb(*this, adr, count, vmId);}
void   RadeonRingBufferDma::WriteVmFlush(uint32 vmId, uint64 pdAdr) {GenDmaPacketVmFlush(*this, vmId, pdAdr);}


// #pragma mark - DmaV1Unit

class DmaV1Unit: public DmaUnit {
private:
	ExternalUniquePtr<RadeonRingBuffer> fRings[2];

protected:
	status_t InitHardware2() override;
	status_t FiniHardware2() override;
	status_t InitSoftware2() override;
	status_t FiniSoftware2() override;

public:
	using DmaUnit::DmaUnit;

	virtual ~DmaV1Unit();
	const UnitInfo *GetInfo() override;

	uint32 RingCount() override;
	ExternalPtr<RadeonRingBuffer> *Rings() override;
};


DmaUnit *DmaV1UnitNew(RadeonDevice *device)
{
	return new(std::nothrow) DmaV1Unit(device);
}


DmaV1Unit::~DmaV1Unit()
{}

const UnitInfo *DmaV1Unit::GetInfo()
{
	static const UnitInfo info {
		.type = UnitType::sdma,
		.version = {1, 0, 0},
		.name = "SI DMA"
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

status_t DmaV1Unit::InitHardware2()
{
	printf("disabling DMA rings\n");
	WriteReg4AmdGpu(DMA_RB_CNTL, ReadReg4AmdGpu(DMA_RB_CNTL) & ~DMA_RB_ENABLE);
	WriteReg4AmdGpu(DMA_RB_CNTL + DMA1_REGISTER_OFFSET, ReadReg4AmdGpu(DMA_RB_CNTL + DMA1_REGISTER_OFFSET) & ~DMA_RB_ENABLE);
	snooze(10000);
	printf("init DMA rings\n");
	static RingType ringTypes[] = {R600_RING_TYPE_DMA_INDEX, CAYMAN_RING_TYPE_DMA1_INDEX};
	for (uint32 i = 0; i < B_COUNT_OF(fRings); i++) {
		CheckRet(InitRing(Device(), fRings[i], [](RingType type) -> ExternalPtr<RadeonRingBuffer> {return MakeExternal<RadeonRingBufferDma>(type);}, ringTypes[i], 0x10000));
	}
	return B_OK;
}

status_t DmaV1Unit::FiniHardware2()
{
	return B_OK;
}

status_t DmaV1Unit::InitSoftware2()
{
	return B_OK;
}

status_t DmaV1Unit::FiniSoftware2()
{
	return B_OK;
}


uint32 DmaV1Unit::RingCount()
{
	return B_COUNT_OF(fRings);
}

ExternalPtr<RadeonRingBuffer> *DmaV1Unit::Rings()
{
	return (ExternalPtr<RadeonRingBuffer>*)fRings;
}
