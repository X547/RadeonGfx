#pragma once

#ifndef ASSERT
#define ASSERT(cond) if (!(cond)) abort();
#endif

#include "Radeon.h"
#include "RadeonMemory.h"
#include "Fence.h"
#include "SADomains/Domains.h"
#include "Locks/Timer.h"
#include <private/kernel/util/DoublyLinkedList.h>


enum RingType {
	RADEON_RING_TYPE_GFX_INDEX = 0,
	CAYMAN_RING_TYPE_CP1_INDEX = 1,
	CAYMAN_RING_TYPE_CP2_INDEX = 2,
	R600_RING_TYPE_DMA_INDEX = 3,
	CAYMAN_RING_TYPE_DMA1_INDEX = 4,
	R600_RING_TYPE_UVD_INDEX = 5,
	TN_RING_TYPE_VCE1_INDEX = 6,
	TN_RING_TYPE_VCE2_INDEX = 7,
	RADEON_NUM_RINGS = 8,
};


class RadeonRingBuffer;
class RingFence: public Fence, public DoublyLinkedListLinkImpl<RingFence> {
private:
	friend class RadeonRingBuffer;
	RadeonRingBuffer *ring;

public:
	RingFence();
	virtual ~RingFence();

	inline RadeonRingBuffer* Ring() {return ring;}
};


class RadeonRingBuffer: public Object {
private:
	RingType fType;

	uint32 fWseq;
	uint32 fRptr, fWptrBeg;

	DoublyLinkedList<RingFence> fFences;

protected:
	friend class RingFence;

	uint32 fSize;
	uint64 fFenceGpuAdr;
	uint64 fRptrGpuAdr;
	vuint32 *fRptrAdr;
	vuint32 *fFenceAdr;

	MappedBuffer fBuffer;

	virtual status_t Start() = 0;
	virtual status_t Stop() = 0;

public: // !!! used in GetDmaPacketIb
	uint32 fWptr;

public:
	RadeonRingBuffer(RingType type);
	virtual ~RadeonRingBuffer();
	status_t Init(uint32 size);
	inline RingType Type();
	virtual uint32 NopPacket() const = 0;
	virtual uint32 Rptr() = 0;
	virtual uint32 Wptr() = 0;
	virtual void SetWptr(uint32 val) = 0;
	uint32 PendingSize();
	uint32 FreeSize();
	void UpdateRptr();
	inline void Write(uint32 val);
	inline void Write8(uint64 val);
	template<typename Type>
	inline Type &Write();
	void WriteNops(uint32 count);
	uint32 Rseq() {return *fFenceAdr;}
	uint32 Wseq() {return fWseq;}
	void WriteFence(RingFence *fence);
	virtual void WriteFence2() = 0;
	virtual void WriteIb(uint64 adr, uint32 count, uint32 vmId) = 0;
	virtual void WriteVmFlush(uint32 vmId, uint64 pdAdr) = 0;
	virtual status_t Begin(uint32 len);
	void End();
	status_t WaitEmpty();
	void UpdateFences();

	void WriteState();
};


RingType RadeonRingBuffer::Type() {return fType;}

void RadeonRingBuffer::Write(uint32 val)
{
	((uint32*)fBuffer.adr)[fWptr % fSize] = val;
	fWptr = (fWptr + 1) % fSize;
}

void RadeonRingBuffer::Write8(uint64 val)
{
	Write((uint32)(val));
	Write((uint32)(val >> 32));
}

template<typename Type>
Type &RadeonRingBuffer::Write()
{
	Type *res = (Type*)(((uint32*)fBuffer.adr)[fWptr % fSize]);
	fWptr = (fWptr + sizeof(Type)/4) % fSize;
	return *res;
}
