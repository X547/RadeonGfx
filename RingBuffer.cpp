#include "RingBuffer.h"
#include "Radeon.h"
#include "RingPackets.h"
#include "InterruptHandler.h"
#include "gfx_6_0.h"

#include <stdio.h>


void RadeonRingBuffer::WriteState()
{
	printf("rptr: %#" B_PRIx32 "\n", Rptr());
	printf("wptr: %#" B_PRIx32 "\n", Wptr());
	printf("4*fWptr: %" B_PRIu32 "\n", 4*fWptr);
	printf("*fRptrAdr: %#" B_PRIx32 "\n", *fRptrAdr);
	printf("*fFenceAdr: %" B_PRIu32 "\n", *fFenceAdr);
}


// #pragma mark RadeonRingBuffer

RadeonRingBuffer::RadeonRingBuffer(RingType type):
	fType(type), fFenceGpuAdr(0), fFenceAdr(NULL)
{}

RadeonRingBuffer::~RadeonRingBuffer()
{
	if (fRptrGpuAdr != 0) {gDevice.MemMgr().Switch()->FreeWriteback(fFenceGpuAdr); fRptrGpuAdr = 0;}
	if (fFenceGpuAdr != 0) {gDevice.MemMgr().Switch()->FreeWriteback(fFenceGpuAdr); fFenceGpuAdr = 0;}
}

status_t RadeonRingBuffer::Init(uint32 size)
{
	fBuffer.SetTo(gDevice.MemMgr().Switch()->Alloc(boDomainGtt, size));
	if (!fBuffer.buf.IsSet()) return B_NO_MEMORY;
	fSize = fBuffer.buf->size / 4;
	fRptr = 0;
	fWptr = 0;
	fWseq = 0;

	CheckRet(gDevice.MemMgr().Switch()->AllocWriteback(fFenceGpuAdr, *(void**)&fFenceAdr, sizeof(uint32)));
	CheckRet(gDevice.MemMgr().Switch()->AllocWriteback(fRptrGpuAdr, *(void**)&fRptrAdr, sizeof(uint32)));
	*fFenceAdr = 0;
	*fRptrAdr = 0;

	for (uint32 i = 0; i < fSize; i++) {
		((uint32*)fBuffer.adr)[i] = NopPacket();
	}

	CheckRet(Start());
	return B_OK;
}

uint32 RadeonRingBuffer::PendingSize()
{
	int32 size = (int32)fWptr - (int32)fRptr;
	if (size < 0) size += fSize;
	return size;
}

uint32 RadeonRingBuffer::FreeSize()
{
	return fSize - PendingSize() - 1;
}

void RadeonRingBuffer::UpdateRptr()
{
	fRptr = Rptr() / 4;
}

void RadeonRingBuffer::WriteNops(uint32 count)
{
	uint32 nop = NopPacket();
	for (uint32 i = 0; i < count; i++) {
		Write(nop);
	}
}

void RadeonRingBuffer::WriteFence(RingFence *fence)
{
	fWseq++;
	fence->AcquireReference();
	fence->ring = this;
	fFences.Add(fence);
	fence->SetSeq(fWseq);

	WriteFence2();
}

status_t RadeonRingBuffer::Begin(uint32 len)
{
	//printf("RadeonRingBuffer::Begin(%" B_PRIu32 ")\n", len);
	if (len > fSize) return B_NO_MEMORY;
	UpdateRptr();
	while (len > FreeSize()) {
		RingFence *fence = fFences.First();
		if (fence == NULL) B_ERROR;
		CheckRet(fence->Wait());
		UpdateRptr();
	}
	fWptrBeg = fWptr;
	return B_OK;
}

void RadeonRingBuffer::End()
{
	//printf("RadeonRingBuffer::End(): %" B_PRIu32 "\n", (fWptr - fWptrBeg)%fSize);
	while (fWptr % (0x10/4) != 0) {
		Write(NopPacket());
	}
	SetWptr(fWptr * 4);
}

status_t RadeonRingBuffer::WaitEmpty()
{
	UpdateRptr();
	while (PendingSize() > 0) {
		RingFence *fence = fFences.First();
		if (fence == NULL) return B_ERROR;
		CheckRet(fence->Wait());
		UpdateRptr();
	}
	return B_OK;
}

void RadeonRingBuffer::UpdateFences()
{
	uint32 rseq = Rseq();
	while (fFences.First() != NULL && ((int32)rseq - (int32)fFences.First()->Seq() >= 0)) {
		RingFence *fence = fFences.RemoveHead();
		fence->Signal();
		fence->ReleaseReference();
	}
}


// #pragma mark - RingFence

RingFence::RingFence(): ring(NULL)
{
}

RingFence::~RingFence()
{
}
