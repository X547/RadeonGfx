#include "IhV1Unit.h"
#include "InterruptHandler.h"
#include "Radeon.h"
#include "gmc_6_0_d.h"
#include "gmc_6_0.h"
#include "bif_3_0_d.h"
#include "bif_3_0.h"
#include "oss_1_0_d.h"
#include "oss_1_0.h"
#include <string.h>


struct InterruptPacketInt {
	uint32 srcId:      8;
	uint32 reserved1: 24;
	uint32 srcData:   28;
	uint32 reserved2:  4;
	uint32 ringId:     8;
	uint32 vmId:       8;
	uint32 reserved3: 16;
	uint32 reserved4;
};


static uint32 OrderBase2(uint64 val)
{
	for (uint32 res = 0; res < 64; res++) {
		if (((uint64)1 << res) >= val) return res;
	}
	return 64;
}


class InterruptHandlerV1: public InterruptHandler {
private:
	friend class IhV1Unit;

public:
	virtual ~InterruptHandlerV1() = default;

	uint32 Rptr() final;
	uint32 Wptr() final;
	void SetRptr() final;
	void ReadPacket(InterruptPacket &pkt) final;
};

class IhV1Unit: public RadeonUnit {
private:
	InterruptHandlerV1 fIntHandler;

protected:
	status_t InitSoftware2() override;
	status_t FiniSoftware2() override;
	status_t InitHardware2() override;
	status_t FiniHardware2() override;

public:
	IhV1Unit(RadeonDevice *device);
	virtual ~IhV1Unit();
	const UnitInfo *GetInfo() override;
};


// #pragma mark - InterruptHandlerV1

uint32 InterruptHandlerV1::Rptr()
{
	return ReadReg4AmdGpu(mmIH_RB_RPTR);
}

uint32 InterruptHandlerV1::Wptr()
{
	uint32 wptr = /* *fWptrAdr */ ReadReg4AmdGpu(mmIH_RB_WPTR);
	if (IhRbWptr{.val = wptr}.rbOverflow) {
		wptr &= ~IhRbWptr{.rbOverflow = true}.val;
		printf("[!] IH ring overflow\n");
		fRptr = (wptr + 16) % fBuffer.buf->size;
		IhRbCntl tmp {.val = ReadReg4AmdGpu(mmIH_RB_CNTL)};
		tmp.wptrOverflowClear = true;
		WriteReg4AmdGpu(mmIH_RB_CNTL, tmp.val);
	}
	return wptr % fBuffer.buf->size;
}

void InterruptHandlerV1::SetRptr()
{
	WriteReg4AmdGpu(mmIH_RB_RPTR, fRptr);
}

void InterruptHandlerV1::ReadPacket(InterruptPacket &pkt)
{
	InterruptPacketInt data;
	if (sizeof(data) != 4*sizeof(uint32)) abort();
	memcpy(&data, (uint8*)fBuffer.adr + fRptr, 4*sizeof(uint32));
	fRptr = (fRptr + 4*sizeof(uint32)) % fBuffer.buf->size;

	pkt = InterruptPacket{
		.clientId = 0 /*AMDGPU_IRQ_CLIENTID_LEGACY*/,
		.srcId    = data.srcId,
		.srcData  = data.srcData,
		.ringId   = data.ringId,
		.vmId     = data.vmId
	};
}


// #pragma mark - IhV1Unit

IhV1Unit::IhV1Unit(RadeonDevice *device): RadeonUnit(device)
{
}

IhV1Unit::~IhV1Unit()
{
}


status_t IhV1Unit::InitSoftware2()
{
	Device()->SetIntHandler(&fIntHandler);

	CheckRet(fIntHandler.Init(64 * 1024));

	return B_OK;
}

status_t IhV1Unit::FiniSoftware2()
{
	fIntHandler.Fini();
	Device()->SetIntHandler(NULL);
	return B_OK;
}

status_t IhV1Unit::InitHardware2()
{
	WriteReg4AmdGpu(mmINTERRUPT_CNTL2, gDevice.MemMgr().Switch()->fDummyPage->gpuPhysAdr >> 8);

	InterruptCntl interruptCntl {.val = ReadReg4AmdGpu(mmINTERRUPT_CNTL)};
	interruptCntl.ihDummyRdOverride = false;
	interruptCntl.ihReqNonsnoopEn = false;
	WriteReg4AmdGpu(mmINTERRUPT_CNTL, interruptCntl.val);

	WriteReg4AmdGpu(mmIH_RB_BASE, fIntHandler.fBuffer.buf->gpuPhysAdr >> 8);
	uint32 rbBufSz = OrderBase2(fIntHandler.fBuffer.buf->size / 4);
	IhRbCntl ihRbCntl {
		.rbSize = rbBufSz,
		.wptrWritebackEnable = true,
		.wptrOverflowEnable = true,
		.wptrOverflowClear = true,
	};

	WriteReg8LoHiAmdGpu(mmIH_RB_WPTR_ADDR_LO, mmIH_RB_WPTR_ADDR_HI, fIntHandler.fWptrGpuAdr);
	WriteReg4AmdGpu(mmIH_RB_CNTL, ihRbCntl.val);
	WriteReg4AmdGpu(mmIH_RB_RPTR, 0);
	WriteReg4AmdGpu(mmIH_RB_WPTR, 0);

	IhCntl ihCntl {
		.mcWrreqCredit = 0x10,
		.mcWrCleanCnt = 0x10,
		.mcVmid = 0
	};

/*
	if (adev->irq.msi_enabled)
		ih_cntl |= RPTR_REARM;
*/
	WriteReg4AmdGpu(mmIH_CNTL, ihCntl.val);


	{
		IhCntl ihCntl {.val = ReadReg4AmdGpu(mmIH_CNTL)};
		IhRbCntl ihRbCntl {.val = ReadReg4AmdGpu(mmIH_RB_CNTL)};
		ihCntl.enableIntr = true;
		ihRbCntl.rbEnable = true;
		WriteReg4AmdGpu(mmIH_CNTL, ihCntl.val);
		WriteReg4AmdGpu(mmIH_RB_CNTL, ihRbCntl.val);
		fIntHandler.fEnabled = true;
	}

	return B_OK;
}

status_t IhV1Unit::FiniHardware2()
{
	IhRbCntl ihRbCntl {.val = ReadReg4AmdGpu(mmIH_RB_CNTL)};
	IhCntl ihCntl {.val = ReadReg4AmdGpu(mmIH_CNTL)};
	ihRbCntl.rbEnable = false;
	ihCntl.enableIntr = false;
	WriteReg4AmdGpu(mmIH_RB_CNTL, ihRbCntl.val);
	WriteReg4AmdGpu(mmIH_CNTL, ihCntl.val);
	WriteReg4AmdGpu(mmIH_RB_RPTR, 0);
	WriteReg4AmdGpu(mmIH_RB_WPTR, 0);
	fIntHandler.fRptr = 0;
	fIntHandler.fEnabled = false;

	return B_OK;
}

const UnitInfo *IhV1Unit::GetInfo()
{
	static const UnitInfo info {
		.type = UnitType::ih,
		.version = {1, 0, 0},
		.name = "IH v1.0"
	};
	return &info;
}


// #pragma mark - IhV1Unit

RadeonUnit *IhV1UnitNew(RadeonDevice *device)
{
	BReference<Domain> domain(new Domain(), true);
	domain->BeginSync();
	DomainSection sect(domain);

	RadeonUnit *unit = new(std::nothrow) IhV1Unit(device);

	sect.Unset();
	domain->EndSync();

	return unit;
}
