#include "Radeon.h"
#include "RadeonInit.h"
#include "RadeonFirmware.h"
#include "RadeonMemory.h"
#include "RadeonDevice.h"
#include "RingBuffer.h"
#include "RingPackets.h"
#include "Atombios.h"
#include "atom.h"
#include "gfx_6_0_d.h"

#include <stdio.h>
#include <string.h>
#include <algorithm>

#include <private/shared/AutoDeleter.h>
#include <private/shared/AutoDeleterOS.h>
#include <private/shared/AutoDeleterPosix.h>

#include <radeon_gfx.h>


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


struct IBWriter {
	uint32 *testIbAdr, *testIbPos;

	IBWriter(uint32 *adr): testIbAdr(adr), testIbPos(adr) {}
	
	size_t Length() {return testIbPos - testIbAdr;}

	void Write(uint32 val)
	{
		*testIbPos++ = val;
	}

	void Write8(uint64 val)
	{
		Write((uint32)(val));
		Write((uint32)(val >> 32));
	}
};


//#pragma mark -

static void GenDmaCopy(RadeonRingBuffer &ring, uint64 dstAdr, uint64 srcAdr, uint64 byteCnt)
{
	enum {blockSize = 0xfffff};
	while (byteCnt > 0) {
		uint64 copyCnt = std::min<uint32>(byteCnt, 0xfffff);
		//printf("GenDmaPacketCopy(%#" B_PRIx64 ", %#" B_PRIx64 ", %#" B_PRIx64 ")\n", dstAdr, srcAdr, copyCnt);
		GenDmaPacketCopy(ring, dstAdr, srcAdr, copyCnt);
		dstAdr += copyCnt;
		srcAdr += copyCnt;
		byteCnt -= copyCnt;
	}
}

static uint32 GenDmaCopyLen(uint64 byteCnt)
{
	enum {blockSize = 0xfffff};
	return 5*((byteCnt + (blockSize - 1)) / blockSize);
}

status_t TestCopyVRAM(ExternalPtr<RadeonRingBuffer> ringExt)
{
	printf("TestCopyVRAM()\n");
	
	size_t size = 1024*1024*256;
	MappedBuffer buf1(gDevice.MemMgr().Switch()->Alloc(boDomainGtt, size));
	BReference<BufferObject> buf2(gDevice.MemMgr().Switch()->Alloc(boDomainVram, size));
	BReference<BufferObject> buf2_1(gDevice.MemMgr().Switch()->Alloc(boDomainVram, size));
	MappedBuffer buf3(gDevice.MemMgr().Switch()->Alloc(boDomainGtt, size));
	printf("buf1: %#" B_PRIx64 "\n", buf1.buf->gpuPhysAdr);
	printf("buf2: %#" B_PRIx64 "\n", buf2->gpuPhysAdr);
	printf("buf3: %#" B_PRIx64 "\n", buf3.buf->gpuPhysAdr);
	if (buf1.buf == NULL) return B_NO_MEMORY;
	if (buf2 == NULL) return B_NO_MEMORY;
	if (buf2_1 == NULL) return B_NO_MEMORY;
	if (buf3.buf == NULL) return B_NO_MEMORY;
	memset(buf3.adr, 0xff, size);
	for (uint32 i = 0; i < size / 4; i++) {
		((uint32*)buf1.adr)[i] = i;
	}
	for (uint32 i = 0; i < 8; i++) {
		printf("(1) memcmp: %d\n", memcmp(buf1.adr, buf3.adr, size));

		RingFence fence1, fence2, fence3;
		bigtime_t t1 = system_time();
		if (auto ring = ringExt.Switch()) {
			ring->Begin(GenDmaCopyLen(size) + 5);
			GenDmaCopy(*ring, buf2->gpuPhysAdr, buf1.buf->gpuPhysAdr, size);
			ring->WriteFence(&fence1);
			ring->End();
			fence1.Wait();
		}
		bigtime_t t2 = system_time();
		if (auto ring = ringExt.Switch()) {
			ring->Begin(GenDmaCopyLen(size) + 5);
			GenDmaCopy(*ring, buf3.buf->gpuPhysAdr, buf2->gpuPhysAdr, size);
			ring->WriteFence(&fence2);
			ring->End();
			fence2.Wait();
		}
		bigtime_t t3 = system_time();
		if (auto ring = ringExt.Switch()) {
			ring->Begin(GenDmaCopyLen(size) + 5);
			GenDmaCopy(*ring, buf2_1->gpuPhysAdr, buf2->gpuPhysAdr, size);
			ring->WriteFence(&fence3);
			ring->End();
			fence3.Wait();
		}
		bigtime_t t4 = system_time();
		printf("GTT -> VRAM: %g\n", size / ((double)(t2 - t1) / 1000000.0));
		printf("VRAM -> GTT: %g\n", size / ((double)(t3 - t2) / 1000000.0));
		printf("VRAM -> VRAM: %g\n", size / ((double)(t4 - t3) / 1000000.0));
		printf("(2) memcmp: %d\n", memcmp(buf1.adr, buf3.adr, size));
		ringExt.Switch()->WriteState();
/*		
		FILE *file = fopen("buffer.bin", "wb");
		fwrite(buf3.adr, size, 1, file);
		fclose(file);
*/
	}

	return B_OK;
}


status_t TestGfxFences()
{
	printf("TestGfxFences()\n");

	ExternalPtr<RadeonRingBuffer> ringExt = gDevice.Rings(RADEON_RING_TYPE_GFX_INDEX);

	for (int i = 0; i < 10000; i++) {
		printf("\nstep %d\n", i);

		{
			uint32 grbmStatus = ReadReg4AmdGpu(mmGRBM_STATUS);
			printf("(1) regs[GRBM_STATUS]: %#" B_PRIx32 "(", grbmStatus); WriteSet(grbmStatus); printf(")\n");
		}
		RingFence fence;
		if (auto ring = ringExt.Switch()) {
			ring->Begin(14);
			ring->WriteFence(&fence);
			ring->End();
			fence.Wait();
		}
		ringExt.Switch()->WriteState();
		{
			uint32 grbmStatus = ReadReg4AmdGpu(mmGRBM_STATUS);
			printf("(2) regs[GRBM_STATUS]: %#" B_PRIx32 "(", grbmStatus); WriteSet(grbmStatus); printf(")\n");
		}
	}
	return B_OK;
}


status_t TestDisplay();


//#pragma mark -

status_t RadeonTest()
{
	srand(time(NULL));
/*
	printf("[WAIT]"); fgetc(stdin);
	return B_OK;
*/
	auto ring = gDevice.Rings(R600_RING_TYPE_DMA_INDEX);
	switch (2) {
		case 1: return TestCopyVRAM(ring);
		case 2: return TestGfxFences();
		case 3: return TestDisplay();
	default: ;
	}

	return B_ERROR;
}

/*

0x44483146: {   1, 2,    6, 8,         12, 13, 19, 22,     26, 30}
0x44c83d57: {0, 1, 2, 4, 6, 8, 10, 11, 12, 13, 19, 22, 23, 26, 30}
0x44ca1142: {1         , 6, 8,         12, 17, 19, 22, 23, 26, 30})

regs[DMA_CNTL]: 0x8210400
regs[DMA_RB_CNTL]: 0x1015
regs[DMA_IB_CNTL]: 0x80000000
regs[DMA_STATUS_REG]: 0x44483146


regs[DMA_CNTL]: 0x8210400
regs[DMA_RB_CNTL]: 0
regs[DMA_IB_CNTL]: 0x80000000
regs[DMA_STATUS_REG]: 0x44c83d57
regs[DMA_RB_RPTR_ADDR]: 0
rptr: 0
wptr: 0
disabling rings
[WAIT]
init ring
[WAIT]
regs[DMA_CNTL]: 0x8210400
regs[DMA_RB_CNTL]: 0x1015
regs[DMA_IB_CNTL]: 0x80000000
regs[DMA_STATUS_REG]: 0x44c83d57
regs[DMA_RB_RPTR_ADDR]: 1000000000000
rptr: 0
wptr: 0
step 0
*fenceCpuAdr: 0
testCpuAdr[0]: 0x10
testCpuAdr[1]: 0x11
testCpuAdr[2]: 0x12
testCpuAdr[3]: 0x13
*fenceCpuAdr: 0
*fenceCpuAdr: 0
*fenceCpuAdr: 100
testCpuAdr[0]: 0x20
testCpuAdr[1]: 0x21
testCpuAdr[2]: 0x22
testCpuAdr[3]: 0x23

GRBM_STATUS:     0x3028({3, 5, 12, 13        })
GRBM_STATUS: 0xa0003028({3, 5, 12, 13, 29, 31})

#define		SRBM_RQ_PENDING					(1 << 5)
#define		DB_CLEAN					(1 << 12)
#define		CB_CLEAN					(1 << 13)
#define		CP_BUSY 					(1 << 29)
#define		GUI_ACTIVE					(1 << 31)

*/
