#pragma once

#include <SupportDefs.h>
#include "sid_amdgpu.h"


template <typename Writer> void GenDmaPacketWrite(Writer &wr, uint64 dstAdr, uint32 srcVal); // 4
template <typename Writer> void GenDmaPacketWriteMultiple(Writer &wr, uint64 dstAdr, uint32* srcVal, uint32 cnt); // 3 + cnt
template <typename Writer> void GenDmaPacketCopy(Writer &wr, uint64 dstAdr, uint64 srcAdr, uint32 byteCnt); // 5
template <typename Writer> void GenDmaPacketFill(Writer &wr, uint64 dstAdr, uint32 srcVal, uint32 byteCnt); // 4
template <typename Writer> void GenDmaPacketFence(Writer &wr, uint64 fenceAdr, uint32 seq); // 5
template <typename Writer> void GenDmaPacketSrbmWrite(Writer &wr, uint32 reg, uint32 val); // 3
template <typename Writer> void GenDmaPacketFlushHdp(Writer &wr); // 3
template <typename Writer> void GetDmaPacketIb(Writer &wr, uint64 adr, uint32 count, uint32 vmId); // 8
template <typename Writer> void GenDmaPacketSetPageTable(Writer &wr, uint32 vmId, uint64 pdAddr); // 3
template <typename Writer> void GenDmaPacketInvalidateVm(Writer &wr, uint32 vmId); // 3
template <typename Writer> void GenDmaPacketWaitInvalidate(Writer &wr, uint32 vmId); // 6
template <typename Writer> void GetDmaPacketVmFlush(Writer &wr, uint32 vmId, uint64 pdAdr); // 15

template <typename Writer> void GenSetConfigReg(Writer &wr, uint32 reg, uint32 val);       // 3
template <typename Writer> void GenPfpSyncMe(Writer &wr);                                  // 2
template <typename Writer> void GenSurfaceSync(Writer &wr);                                // 5
template <typename Writer> void GenEventWriteEop(Writer &wr, uint64 addr, uint32 seq);     // 6
template <typename Writer> void GenFence(Writer &wr, uint64 fenceAdr, uint32 seq);         // 14
template <typename Writer> void GenIb(Writer &wr, uint64 addr, uint32 count, uint32 vmid); // 4
template <typename Writer> void GenIbFlushCaches(Writer &wr, uint64 addr, uint32 count, uint32 vmid); // 12
template <typename Writer> void GenWriteDataReg(Writer &wr, uint32 reg, uint32 val);       // 5
template <typename Writer> void GenWriteDataMem(Writer &wr, uint64 adr, uint32 val);       // 5
template <typename Writer> void GenWaitRegMem(Writer &wr, uint32 reg);                     // 7
template <typename Writer> void GenSetPageTable(Writer &wr, uint32 vmId, uint64 pdAddr);   // 5
template <typename Writer> void GenFlushHdp(Writer &wr);                                   // 5
template <typename Writer> void GenInvalidateVm(Writer &wr, uint32 vmId);                  // 5
template <typename Writer> void GenFlushVm(Writer &wr, uint32 vmId, uint64 pdAdr);         // 24


// #pragma mark DMA packets

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
void GetDmaPacketIb(Writer &wr, uint64 adr, uint32 count, uint32 vmId)
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
void GetDmaPacketVmFlush(Writer &wr, uint32 vmId, uint64 pdAdr) // 15
{
	GenDmaPacketSetPageTable(wr, vmId, pdAdr); // 3
	GenDmaPacketFlushHdp(wr);                  // 3      
	GenDmaPacketInvalidateVm(wr, vmId);        // 3        
	GenDmaPacketWaitInvalidate(wr, vmId);      // 6
}


// #pragma mark GFX packets

template <typename Writer> 
void GenSetConfigReg(Writer &wr, uint32 reg, uint32 val)
{
	wr.Write(PACKET3(PACKET3_SET_CONFIG_REG, 1));
	wr.Write(reg - PACKET3_SET_CONFIG_REG_START);
	wr.Write(val);
}

template <typename Writer> 
void GenPfpSyncMe(Writer &wr)
{
	wr.Write(PACKET3(PACKET3_PFP_SYNC_ME, 0));
	wr.Write(0);
}

template <typename Writer> 
void GenSurfaceSync(Writer &wr)
{
	wr.Write(PACKET3(PACKET3_SURFACE_SYNC, 3));
	wr.Write(
		PACKET3_TCL1_ACTION_ENA |
		PACKET3_TC_ACTION_ENA |
		PACKET3_SH_KCACHE_ACTION_ENA |
		PACKET3_SH_ICACHE_ACTION_ENA
	);
	wr.Write(0xFFFFFFFF);
	wr.Write(0);
	wr.Write(10); /* poll interval */
}

template <typename Writer> 
void GenEventWriteEop(Writer &wr, uint64 addr, uint32 seq)
{
	/* EVENT_WRITE_EOP - flush caches, send int */
	wr.Write(PACKET3(PACKET3_EVENT_WRITE_EOP, 4));
	wr.Write(EVENT_TYPE(CACHE_FLUSH_AND_INV_TS_EVENT) | EVENT_INDEX(5));
	wr.Write((uint32)addr);
	wr.Write((((uint32)(addr >> 32)) & 0xff) | DATA_SEL(1) | INT_SEL(2));
	wr.Write(seq);
	wr.Write(0);
}

template <typename Writer> 
void GenFence(Writer &wr, uint64 fenceAdr, uint32 seq)
{
	/* flush read cache over gart */
	GenSetConfigReg(wr, CP_COHER_CNTL2, 0); // 3
	GenSurfaceSync(wr);                     // 5
	GenEventWriteEop(wr, fenceAdr, seq);    // 6
}

template <typename Writer> 
void GenIb(Writer &wr, uint64 addr, uint32 count, uint32 vmid)
{
	wr.Write(PACKET3(PACKET3_INDIRECT_BUFFER, 2));
	wr.Write((uint32)(addr & 0xFFFFFFFC));
	wr.Write(((uint32)(addr >> 32)) & 0xFFFF);
	wr.Write(count | (vmid << 24));
}

template <typename Writer> 
void GenIbFlushCaches(Writer &wr, uint64 addr, uint32 count, uint32 vmid)
{
	GenIb(wr, addr, count, vmid);              // 4
	GenSetConfigReg(wr, CP_COHER_CNTL2, vmid); // 3
	GenSurfaceSync(wr);                        // 5
}


template <typename Writer> 
void GenWriteDataReg(Writer &wr, uint32 reg, uint32 val)
{
	wr.Write(PACKET3(PACKET3_WRITE_DATA, 3));
	wr.Write((WRITE_DATA_ENGINE_SEL(1 /* pfp */) | WRITE_DATA_DST_SEL(0)));
	wr.Write(reg);
	wr.Write(0);
	wr.Write(val);
}

template <typename Writer> 
void GenWriteDataMem(Writer &wr, uint64 adr, uint32 val)
{
	wr.Write(PACKET3(PACKET3_WRITE_DATA, 3));
	wr.Write((WRITE_DATA_ENGINE_SEL(0 /* me */) | WRITE_DATA_DST_SEL(1)));
	wr.Write8(adr);
	wr.Write(val);
}

template <typename Writer> 
void GenWaitRegMem(Writer &wr, uint32 reg)
{
	wr.Write(PACKET3(PACKET3_WAIT_REG_MEM, 5));
	wr.Write((WAIT_REG_MEM_FUNCTION(0) /* always */ | WAIT_REG_MEM_ENGINE(0)) /* me */);
	wr.Write(reg);
	wr.Write(0);
	wr.Write(0); /* ref */
	wr.Write(0); /* mask */
	wr.Write(0x20); /* poll interval */
}

template <typename Writer> 
void GenSetPageTable(Writer &wr, uint32 vmId, uint64 pdAddr)
{
	GenWriteDataReg(wr,
		(vmId < 8)
			? VM_CONTEXT0_PAGE_TABLE_BASE_ADDR + vmId
			: VM_CONTEXT8_PAGE_TABLE_BASE_ADDR + (vmId - 8),
		(uint32)(pdAddr >> 12)
	);
}

template <typename Writer> 
void GenFlushHdp(Writer &wr)
{
	GenWriteDataReg(wr, HDP_MEM_COHERENCY_FLUSH_CNTL, 1);
}

template <typename Writer> 
void GenInvalidateVm(Writer &wr, uint32 vmId)
{
	GenWriteDataReg(wr, VM_INVALIDATE_REQUEST, 1 << vmId);
}

template <typename Writer> 
void GenFlushVm(Writer &wr, uint32 vmId, uint64 pdAdr)
{
	GenSetPageTable(wr, vmId, pdAdr);         // 5
	GenFlushHdp(wr);                          // 5
	GenInvalidateVm(wr, vmId);                // 5
	GenWaitRegMem(wr, VM_INVALIDATE_REQUEST); // 7
	GenPfpSyncMe(wr);                         // 2
}
