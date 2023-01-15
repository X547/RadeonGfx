#pragma once

#include "RingPackets.h"
#include "sid_amdgpu.h"
#include "gfx_6_0.h"


template <typename Writer> void GenDmaPacketWrite(Writer &wr, uint64 dstAdr, uint32 srcVal); // 4
template <typename Writer> void GenDmaPacketWriteMultiple(Writer &wr, uint64 dstAdr, uint32* srcVal, uint32 cnt); // 3 + cnt
template <typename Writer> void GenDmaPacketCopy(Writer &wr, uint64 dstAdr, uint64 srcAdr, uint32 byteCnt); // 5
template <typename Writer> void GenDmaPacketFill(Writer &wr, uint64 dstAdr, uint32 srcVal, uint32 byteCnt); // 4
template <typename Writer> void GenDmaPacketFence(Writer &wr, uint64 fenceAdr, uint32 seq); // 5
template <typename Writer> void GenDmaPacketSrbmWrite(Writer &wr, uint32 reg, uint32 val); // 3
template <typename Writer> void GenDmaPacketFlushHdp(Writer &wr); // 3
template <typename Writer> void GenDmaPacketIb(Writer &wr, uint64 adr, uint32 count, uint32 vmId); // 8
template <typename Writer> void GenDmaPacketSetPageTable(Writer &wr, uint32 vmId, uint64 pdAddr); // 3
template <typename Writer> void GenDmaPacketInvalidateVm(Writer &wr, uint32 vmId); // 3
template <typename Writer> void GenDmaPacketWaitInvalidate(Writer &wr, uint32 vmId); // 6
template <typename Writer> void GenDmaPacketVmFlush(Writer &wr, uint32 vmId, uint64 pdAdr); // 15


// #pragma mark -

template <typename Writer>
void GenDmaPacketWrite(Writer &wr, uint64 dstAdr, uint32 srcVal)
{
	wr.Write(DMA_PACKET(DMA_PACKET_WRITE, 0, 0, 0, 1));
	wr.Write8(dstAdr);
	wr.Write(srcVal);
}

template <typename Writer>
void GenDmaPacketWriteMultiple(Writer &wr, uint64 dstAdr, uint32* srcVal, uint32 cnt)
{
	// cnt < 0x100000
	wr.Write(DMA_PACKET(DMA_PACKET_WRITE, 0, 0, 0, cnt));
	wr.Write8(dstAdr);
	for (uint32 i = 0; i < cnt; i++) {
		wr.Write(srcVal[i]);
	}
}

template <typename Writer>
void GenDmaPacketCopy(Writer &wr, uint64 dstAdr, uint64 srcAdr, uint32 byteCnt)
{
	// byteCnt < 0x100000
	wr.Write(DMA_PACKET(DMA_PACKET_COPY, 1, 0, 0, byteCnt));
	wr.Write((uint32)dstAdr);
	wr.Write((uint32)srcAdr);
	wr.Write((uint32)(dstAdr >> 32));
	wr.Write((uint32)(srcAdr >> 32));
}

template <typename Writer>
void GenDmaPacketFill(Writer &wr, uint64 dstAdr, uint32 srcVal, uint32 byteCnt)
{
	// byteCnt <= 0xffff8
	wr.Write(DMA_PACKET(DMA_PACKET_CONSTANT_FILL, 0, 0, 0, byteCnt/4));
	wr.Write((uint32)dstAdr);
	wr.Write(srcVal);
	wr.Write((uint32)(dstAdr >> 32) << 16);
}

template <typename Writer>
void GenDmaPacketFence(Writer &wr, uint64 fenceAdr, uint32 seq)
{
	wr.Write(DMA_PACKET(DMA_PACKET_FENCE, 0, 0, 0, 0));
	wr.Write8(fenceAdr);
	wr.Write(seq);
	wr.Write(DMA_PACKET(DMA_PACKET_TRAP, 0, 0, 0, 0));
}

template <typename Writer>
void GenDmaPacketSrbmWrite(Writer &wr, uint32 reg, uint32 val)
{
	wr.Write(DMA_PACKET(DMA_PACKET_SRBM_WRITE, 0, 0, 0, 0));
	wr.Write((0xf << 16) | reg);
	wr.Write(val);
}

template <typename Writer>
void GenDmaPacketFlushHdp(Writer &wr) // 3
{
	GenDmaPacketSrbmWrite(wr, HDP_MEM_COHERENCY_FLUSH_CNTL, 1);
}

template <typename Writer>
void GenDmaPacketIb(Writer &wr, uint64 adr, uint32 count, uint32 vmId)
{
	while ((wr.fWptr % 8) != 5)
		wr.Write(wr.NopPacket());
	wr.Write(DMA_IB_PACKET(DMA_PACKET_INDIRECT_BUFFER, vmId, 0));
	wr.Write(adr & 0xFFFFFFE0);
	wr.Write((count << 12) | ((uint32)(adr >> 32) & 0xFF));
}

template <typename Writer>
void GenDmaPacketSetPageTable(Writer &wr, uint32 vmId, uint64 pdAddr) // 3
{
	GenDmaPacketSrbmWrite(wr,
		(vmId < 8)
			? VM_CONTEXT0_PAGE_TABLE_BASE_ADDR + (vmId << 2)
			: VM_CONTEXT8_PAGE_TABLE_BASE_ADDR + ((vmId - 8) << 2),
		(uint32)(pdAddr >> 12)
	);
}

template <typename Writer>
void GenDmaPacketInvalidateVm(Writer &wr, uint32 vmId) // 3
{
	GenDmaPacketSrbmWrite(wr, VM_INVALIDATE_REQUEST, 1 << vmId);
}

template <typename Writer>
void GenDmaPacketWaitInvalidate(Writer &wr, uint32 vmId) // 6
{
	wr.Write(DMA_PACKET(DMA_PACKET_POLL_REG_MEM, 0, 0, 0, 0));
	wr.Write(VM_INVALIDATE_REQUEST);
	wr.Write(0xff << 16); /* retry */
	wr.Write(1 << vmId); /* mask */
	wr.Write(0); /* value */
	wr.Write((0 << 28) | 0x20); /* func(always) | poll interval */
}

template <typename Writer>
void GenDmaPacketVmFlush(Writer &wr, uint32 vmId, uint64 pdAdr) // 15
{
	GenDmaPacketSetPageTable(wr, vmId, pdAdr); // 3
	GenDmaPacketFlushHdp(wr);                  // 3
	GenDmaPacketInvalidateVm(wr, vmId);        // 3
	GenDmaPacketWaitInvalidate(wr, vmId);      // 6
}
