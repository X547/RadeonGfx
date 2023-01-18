#include "RadeonDevice.h"
#include "Atombios.h"
#include "RadeonMemory.h"
#include "DisplayRoster.h"
#include "RingBuffer.h"
#include "RadeonInterrupts.h"
#include "RadeonInit.h"
#include "RadeonFirmware.h"
#include "RadeonUnit.h"
#include "Units/InstantiateUnits.h"
#include <RadeonPower.h>
#include "sid_amdgpu.h"
#include <stdio.h>


RadeonDevice gDevice;


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


static void WriteRingRegs()
{
	uint32 dmaCntl = ReadReg4AmdGpu(DMA_CNTL);
	uint32 dmaRbCntl = ReadReg4AmdGpu(DMA_RB_CNTL);
	uint32 dmaIbCntl = ReadReg4AmdGpu(DMA_IB_CNTL);
	uint32 dmaStatus = ReadReg4AmdGpu(DMA_STATUS_REG);
	printf("regs[DMA_CNTL]: %#" B_PRIx32 "\n", dmaCntl);
	printf("regs[DMA_RB_CNTL]: %#" B_PRIx32 "\n", dmaRbCntl);
	printf("regs[DMA_IB_CNTL]: %#" B_PRIx32 "\n", dmaIbCntl);
	printf("regs[DMA_STATUS_REG]: %#" B_PRIx32 "(", dmaStatus);
	WriteSet(dmaStatus); printf(")\n");
	printf("regs[DMA_RB_RPTR_ADDR]: %#" B_PRIx64 "\n", ReadReg4AmdGpu(DMA_RB_RPTR_ADDR_LO) + (((uint64)ReadReg4AmdGpu(DMA_RB_RPTR_ADDR_HI)) << 32));
	printf("rptr: %" B_PRIu32 "\n", ReadReg4AmdGpu(DMA_RB_RPTR));
	printf("wptr: %" B_PRIu32 "\n", ReadReg4AmdGpu(DMA_RB_WPTR));
}


RadeonDevice::RadeonDevice():
	fSharedInfo(NULL), fRegs(NULL),
	fMemMgr(MakeExternal<MemoryManager>()),
	fDisplays(MakeExternal<DisplayRoster>())
{
}

RadeonDevice::~RadeonDevice()
{
	printf("-RadeonDevice\n");
	fIntRing.Switch()->Disable();
	fIntRing.Delete();
	fMemMgr.Delete();
}

void RadeonDevice::InitRing(int ringId, ExternalPtr<RadeonRingBuffer> ring)
{
	fRings[ringId] = ring;
}

void RadeonDevice::InstallUnit(RadeonUnit *unit)
{
	fUnits.Insert(unit);
}

status_t RadeonDevice::InitUnits()
{
	for (RadeonUnit *unit = fUnits.First(); unit != NULL; unit = fUnits.GetNext(unit)) {
		CheckRet(unit->InitSoftware());
	};
	for (RadeonUnit *unit = fUnits.First(); unit != NULL; unit = fUnits.GetNext(unit)) {
		CheckRet(unit->InitHardware());
	};
	return B_OK;
}

status_t RadeonDevice::FiniUnits()
{
	for (RadeonUnit *unit = fUnits.Last(); unit != NULL; unit = fUnits.GetPrevious(unit)) {
		CheckRet(unit->FiniHardware());
	};
	for (RadeonUnit *unit = fUnits.Last(); unit != NULL; unit = fUnits.GetPrevious(unit)) {
		CheckRet(unit->FiniSoftware());
	};
	return B_OK;
}


#define DC_HPDx_INT_CONTROL(x)    (DC_HPD1_INT_CONTROL + (x * 0xc))

status_t RadeonDevice::Init(int fd)
{
	fFd.SetTo(dup(fd));

	radeon_get_private_data data {
		.magic = RADEON_PRIVATE_DATA_MAGIC
	};
	if (ioctl(fFd.Get(), RADEON_GET_PRIVATE_DATA, &data, sizeof(radeon_get_private_data)) != 0) {
		return B_ERROR;
	}
	fSharedArea.SetTo(clone_area("radeon hd shared info", (void**)&fSharedInfo, B_ANY_ADDRESS, B_READ_AREA | B_WRITE_AREA, data.shared_info_area));
	if (!fSharedArea.IsSet()) return fSharedArea.Get();
	fRegsArea.SetTo(clone_area("radeon hd regs", (void**)&fRegs, B_ANY_ADDRESS, B_READ_AREA | B_WRITE_AREA, fSharedInfo->registers_area));
	if (!fRegsArea.IsSet()) return fRegsArea.Get();

	printf("fSharedInfo->frame_buffer_size: %#" B_PRIx32 "\n", fSharedInfo->frame_buffer_size);

	fAtombios.SetTo(new Atombios());
	if (!fAtombios.IsSet()) return B_NO_MEMORY;
	printf("Atom()->Init()\n");
	CheckRet(Atom().Init());
	bool isPosted = Atom().IsPosted();
	printf("isPosted: %d\n", isPosted);
	if (!isPosted)
		atom_asic_init(Atom().Context());

	fIntRing = MakeExternal<RadeonRingBufferInt>();
	fIntRing.Switch()->Disable();

	printf("MemMgr().Init()\n");
	CheckRet(MemMgr().Switch()->Init());

	printf("LoadFirmware()\n");
	CheckRet(LoadFirmware());

	printf("InitGoldenRegisters()\n");
	InitGoldenRegisters();

	// GMC init
/*
	printf("ResetMC()\n");
	ResetMC();
*/
	printf("InitMC()\n");
	InitMC();
	printf("LoadMcMicrocode()\n");
	CheckRet(LoadMcMicrocode());
	printf("init GART\n");
	CheckRet(MemMgr().Switch()->InitGart());
	
	printf("disable interrupt ring\n");
	fIntRing.Switch()->Disable();

	printf("InitGpu()\n");
	CheckRet(InitGpu(&fInfo));

	printf("init interrupt ring\n");
	CheckRet(fIntRing.Switch()->Init(64 * 1024));

//	for (uint32  i = 0; i < 6; i++)
//		WriteReg4AmdGpu(DC_HPDx_INT_CONTROL(i), ReadReg4AmdGpu(DC_HPDx_INT_CONTROL(i)) | DC_HPDx_INT_EN | DC_HPDx_RX_INT_EN);

	printf("InitRlc()\n");
	CheckRet(InitRlc());

	printf("disabling DMA rings\n");
	WriteReg4AmdGpu(DMA_RB_CNTL, ReadReg4AmdGpu(DMA_RB_CNTL) & ~DMA_RB_ENABLE);
	WriteReg4AmdGpu(DMA_RB_CNTL + DMA1_REGISTER_OFFSET, ReadReg4AmdGpu(DMA_RB_CNTL + DMA1_REGISTER_OFFSET) & ~DMA_RB_ENABLE);
	snooze(10000);
	WriteRingRegs();

	printf("LoadCpMicrocode()\n");
	CheckRet(LoadCpMicrocode());
	printf("regs[CP_ME_CNTL]: %#" B_PRIx32 "\n", ReadReg4AmdGpu(CP_ME_CNTL));

	{
		uint32 grbmStatus = ReadReg4AmdGpu(GRBM_STATUS);
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
	WriteReg4AmdGpu(GRBM_SOFT_RESET, SOFT_RESET_CP | resetGfx);
	ReadReg4AmdGpu(GRBM_SOFT_RESET);
	snooze(15000);
	WriteReg4AmdGpu(GRBM_SOFT_RESET, 0);
	snooze(15000);
	{
		uint32 grbmStatus = ReadReg4AmdGpu(GRBM_STATUS);
		printf("regs[GRBM_STATUS]: %#" B_PRIx32 "(", grbmStatus);
		WriteSet(grbmStatus); printf(")\n");
	}

	printf("PreinitGfxRings()\n");
	PreinitGfxRings();

	CheckRet(InstantiateUnits(this));
	CheckRet(InitUnits());
	snooze(10000);

	printf("+InitCP()\n");
	CheckRet(InitCP());
	printf("-InitCP()\n");
	snooze(10000);
	printf("regs[CP_ME_CNTL]: %#" B_PRIx32 "\n", ReadReg4AmdGpu(CP_ME_CNTL));

	printf("engine clock: %" B_PRIu32 "\n", radeon_gpu_get_engine_clock());
	printf("memory clock: %" B_PRIu32 "\n", radeon_gpu_get_memory_clock());

	printf("init displays\n");
	CheckRet(fDisplays.Switch()->Init());

	return B_OK;
}
