#include "RadeonMemory.h"
#include "RadeonDevice.h"
#include "DisplayRoster.h"
#include "Radeon.h"
#include "Poke.h"
#include "bif_3_0_d.h"
#include "gmc_6_0_d.h"
#include "gmc_6_0.h"

#include <stdio.h>
#include <string.h>


static void WriteBuffer(BufferObject& buf)
{
	printf("(domain: %d, gpuPhysAdr: %#" B_PRIx64 ", size: %#" B_PRIx64 ")", buf.domain, buf.gpuPhysAdr, buf.size);
}

BufferObject::~BufferObject()
{
	//printf("-BufferObject()\n");
	//printf("  "); WriteBuffer(*this); printf("\n");
	if (auto memMgr = gDevice.MemMgr().Switch()) {
		if (domain == boDomainGtt) {
			memMgr->GartUnmap(this);
		}
		ExternalAllocator& pool = memMgr->fDomainPools[domain];
		//printf("  pool: %p\n", &pool);
		pool.Free(gpuPhysAdr);
	}
}


status_t MappedBuffer::SetTo(BReference<BufferObject> buffer)
{
	buf = buffer;
	if (!buf.IsSet()) {adr = NULL; return B_OK;}
	return gDevice.MemMgr().Switch()->CpuMap(adr, buf, 0, buf->size);
}


// #pragma mark - AddressSpace

AddressSpace::AddressSpace():
	fVmId(-1), fVmIdRefCnt(0)
{
	fPageDirBuf.SetTo(gDevice.MemMgr().Switch()->Alloc(boDomainVramMappable, pageDirLen*sizeof(Pte)));
	if (!fPageDirBuf.buf.IsSet()) {
		printf("[!] +AddressSpace: out of mappable VRAM memory\n");
		return;
	}
	memset(fPageDirBuf.adr, 0, fPageDirBuf.buf->size);
	fPageTableBufs.SetTo(new MappedBuffer[pageDirLen]);
}

AddressSpace::~AddressSpace()
{
}

Pte *AddressSpace::LookupPte(uint64 virtAdr, bool alloc)
{
	uint64 pteIdx = virtAdr / B_PAGE_SIZE % pageTableLen;
	uint64 pdeIdx = virtAdr / B_PAGE_SIZE / pageTableLen;
	if (pdeIdx >= pageDirLen) return NULL;
	Pte *pde = (Pte*)fPageDirBuf.adr + pdeIdx;
	Pte pdeVal = *pde;
	if (!(pdeVal.flags & R600_PTE_VALID)) {
		if (!alloc) return NULL;
		fPageTableBufs[pdeIdx].SetTo(gDevice.MemMgr().Switch()->Alloc(boDomainVramMappable, pageTableLen*sizeof(Pte)));
		if (!fPageTableBufs[pdeIdx].buf.IsSet()) {
			printf("[!] AddressSpace::LookupPte: out of mappable VRAM memory\n");
			return NULL;
		}
		memset(fPageTableBufs[pdeIdx].adr, 0, fPageTableBufs[pdeIdx].buf->size);
		*pde = Pte{
			.flags = R600_PTE_VALID,
			.ppn = fPageTableBufs[pdeIdx].buf->gpuPhysAdr / B_PAGE_SIZE
		};
	}
	return (Pte*)fPageTableBufs[pdeIdx].adr + pteIdx;
}

status_t AddressSpace::MapInt(uint64 virtAdr, uint64 physAdr, uint32 flags)
{
	Pte *pte = LookupPte(virtAdr, true);
	if (pte == NULL) return B_ERROR;
	*pte = Pte{
		.flags = flags | R600_PTE_VALID,
		.ppn = physAdr/B_PAGE_SIZE
	};
	return B_OK;
}

status_t AddressSpace::MapIntRange(uint64 virtAdr, uint64 physAdr, uint64 size, uint32 flags)
{
	for (uint64 ofs = 0; ofs < size; ofs += B_PAGE_SIZE) {
		CheckRet(MapInt(virtAdr + ofs, physAdr + ofs, flags));
	}
	return B_OK;
}

status_t AddressSpace::UnmapInt(uint64 virtAdr)
{
	Pte *pte = LookupPte(virtAdr, false);
	if (pte == NULL) return B_ERROR;
	Pte oldPte = *pte;
	if (!(oldPte.flags & R600_PTE_VALID)) return B_ERROR;
	*pte = Pte{.val = 0};
	return B_OK;
}

static void WritePteFlags(uint32 flags) {
	bool first = true;
	printf("{");
	for (uint32 i = 0; i < 32; i++) {
		if ((1 << i) & flags) {
			if (first) first = false; else printf(", ");
			switch (i) {
				case 0: printf("valid"); break;
				case 1: printf("system"); break;
				case 2: printf("snooped"); break;
				case 5: printf("read"); break;
				case 6: printf("write"); break;
				default: printf("?(%" B_PRIu32 ")", i);
			}
		}
	}
	printf("}");
}

void AddressSpace::DumpPageTable()
{
	printf("page table\n");
	for (uint64 pdeIdx = 0; pdeIdx < pageDirLen; pdeIdx ++) {
		Pte *pde = (Pte*)fPageDirBuf.adr + pdeIdx;
		Pte pdeVal = *pde;
		if (pdeVal.flags & R600_PTE_VALID) {
			printf("  %#" B_PRIx64 ": %#" B_PRIx64 ", %#" B_PRIx64 ", ", pdeIdx * pageTableLen * B_PAGE_SIZE, pdeVal.ppn * B_PAGE_SIZE, fPageTableBufs[pdeIdx].buf->gpuPhysAdr);
			WritePteFlags(pdeVal.flags); printf("\n");
			
			for (uint64 pteIdx = 0; pteIdx < pageTableLen; pteIdx ++) {
				Pte *pte = (Pte*)fPageTableBufs[pdeIdx].adr + pteIdx;
				Pte pteVal = *pte;
				if (pteVal.flags & R600_PTE_VALID) {
					printf("    %#" B_PRIx64 ": %#" B_PRIx64 ", ", (pdeIdx * pageTableLen + pteIdx) * B_PAGE_SIZE, pteVal.ppn * B_PAGE_SIZE);
					WritePteFlags(pteVal.flags); printf("\n");
				}
			}
		}
	}
}

BReference<BufferObject> AddressSpace::Lookup(uint64 mapAdr, uint64 &offset)
{
	auto it = fMappings.upper_bound(mapAdr);
	if (it == fMappings.begin()) return NULL;
	it--;
	uint64_t bufferMapAdr = it->first;
	Mapping& mapping = it->second;
	if (!(mapAdr < bufferMapAdr + mapping.size)) return NULL;
	offset = mapping.offset + mapAdr - bufferMapAdr;
	return mapping.buffer;
}

status_t AddressSpace::Map(BReference<BufferObject> buffer, uint64 mapAdr, uint64 offset, uint64 size)
{
	size = RoundUp<uint64>(size, B_PAGE_SIZE);
	uint32 flags = R600_PTE_READABLE | R600_PTE_WRITEABLE;
	if (buffer->domain == boDomainGtt) {
		flags |= R600_PTE_SYSTEM | R600_PTE_SNOOPED;
		Pte *gartPageTableAdr = (Pte*)gDevice.MemMgr().Switch()->fGartPageTable.adr;
		for (uint64 ofs = 0; ofs < size; ofs += B_PAGE_SIZE) {
			uint64 gttAdr = buffer->gpuPhysAdr + ofs - gDevice.MemMgr().Switch()->fGttRange.beg;
			Pte gttPte = gartPageTableAdr[gttAdr/B_PAGE_SIZE];
			MapInt(mapAdr + ofs, gttPte.ppn*B_PAGE_SIZE, flags);
		}
	} else {
		uint64 virtBeg = mapAdr/B_PAGE_SIZE;
		uint64 virtEnd = (mapAdr + size)/B_PAGE_SIZE;
		uint64 physAdr = buffer->gpuPhysAdr;

		uint64 fragFlags = R600_PTE_FRAG_64KB;
		uint64 fragAlign = 0x10;
		uint64 fragBeg = RoundUp(virtBeg, fragAlign);
		uint64 fragEnd = RoundDown(virtEnd, fragAlign);

		if (fragBeg >= fragEnd) {
			MapIntRange(mapAdr, buffer->gpuPhysAdr, size, flags);
		} else {
			uint64 count;

			if (virtBeg != fragBeg) {
				count = (fragBeg - virtBeg);
				MapIntRange(virtBeg * B_PAGE_SIZE, physAdr, B_PAGE_SIZE * count, flags);
				physAdr += B_PAGE_SIZE * count;
			}

			count = (fragEnd - fragBeg);
			MapIntRange(fragBeg * B_PAGE_SIZE, physAdr, B_PAGE_SIZE * count, flags | fragFlags);

			if (fragEnd != virtEnd) {
				physAdr += B_PAGE_SIZE * count;
				count = (virtEnd - fragEnd);
				MapIntRange(fragEnd * B_PAGE_SIZE, physAdr, B_PAGE_SIZE * count, flags);
			}
		}
	}

	// TODO: check mapping intersections
	fMappings.emplace(mapAdr, Mapping{buffer, offset, size});
	return B_OK;
}

status_t AddressSpace::Unmap(BReference<BufferObject> buffer, uint64 mapAdr, uint64 offset, uint64 size)
{
	(void)buffer;
	(void)offset;
	auto it = fMappings.find(mapAdr);
	if (it == fMappings.end()) return B_ERROR;
	Mapping &mapping = it->second;

	if (size != mapping.size) {
		printf("[!] AddressSpace::Unmap: size != mapping.size\n");
	}

	for (uint64 ofs = 0; ofs < mapping.size; ofs += B_PAGE_SIZE) {
		UnmapInt(mapAdr + ofs);
	}

	fMappings.erase(it);
	return B_OK;
}


int32 AddressSpace::AcquireVmid()
{
	if (atomic_add(&fVmIdRefCnt, 1) == 0) {
		fVmId = gDevice.MemMgr().Switch()->AllocVmid();
		if (fVmId < 0) {
			atomic_add(&fVmIdRefCnt, -1);
		}
	}
	return fVmId;
}

void AddressSpace::ReleaseVmid()
{
	if (atomic_add(&fVmIdRefCnt, -1) == 1) {
		gDevice.MemMgr().Switch()->FreeVmid(fVmId);
		fVmId = -1;
	}
}


// #pragma mark - MemoryManager

MemoryManager::MemoryManager():
	fVramRange({.beg = 0, .size = 0}),
	fGttRange({.beg = 0, .size = 0}),
	fGartEnabled(false)
{
}

status_t MemoryManager::Init()
{
	fVramRange = {.beg = 0xf400000000, .size = 0x80000000};
	fGttRange = {.beg = 0xFF00000000, .size = 0x80000000};
	uint64 vramMappableSize = 0x10000000;
	fDomainPools[boDomainVramMappable].Register(fVramRange.beg, vramMappableSize);
	fDomainPools[boDomainVram].Register(fVramRange.beg + vramMappableSize, fVramRange.size - vramMappableSize);
	fDomainPools[boDomainGtt].Register(fGttRange.beg, fGttRange.size);

	printf("VRAM size: %" B_PRIu32 " MB\n", ReadReg4AmdGpu(mmCONFIG_MEMSIZE));

	printf("VRAM range: %#" B_PRIx64 " - %#" B_PRIx64 "(%#" B_PRIx64 ")\n", fVramRange.beg, fVramRange.beg + fVramRange.size - 1, fVramRange.size);
	printf("GTT range:  %#" B_PRIx64 " - %#" B_PRIx64 "(%#" B_PRIx64 ")\n", fGttRange.beg, fGttRange.beg + fGttRange.size - 1, fGttRange.size);

	CheckRet(gDevice.Displays().Switch()->RegisterFramebuffers());

	MappedBuffer dummyPage(Alloc(boDomainVramMappable, B_PAGE_SIZE));
	memset(dummyPage.adr, 0, dummyPage.buf->size);
	fDummyPage = dummyPage.buf;

	MappedBuffer vramScratch(Alloc(boDomainVramMappable, B_PAGE_SIZE));
	memset(vramScratch.adr, 0, vramScratch.buf->size);
	fVramScratch = vramScratch.buf;

	fVmidPool.Register(1, 15);

	return B_OK;
}

BReference<BufferObject> MemoryManager::Alloc(MemoryDomain domain, uint64 size, uint64 alignment, uint32 flags, area_id area, uint64 offset)
{
	(void)alignment;
	(void)flags;
	size = (size + B_PAGE_SIZE - 1) / B_PAGE_SIZE * B_PAGE_SIZE;
	ExternalAllocator& pool = fDomainPools[domain];
	//printf("  pool: %p\n", &pool);
	uint64 gpuPhysAdr;
	if (!pool.Alloc(gpuPhysAdr, size)) return NULL;
	// printf("MemoryManager::Alloc(%#" B_PRIx64 ") -> %#" B_PRIx64 "\n", size, gpuPhysAdr);
	BReference<BufferObject> buffer(new BufferObject(), true);
	buffer->domain = domain;
	buffer->gpuPhysAdr = gpuPhysAdr;
	buffer->size = size;
	buffer->offset = offset;

	if (domain == boDomainGtt) {
		if (!fGartEnabled) return NULL;
		void *virtAdr = NULL;
		if (area >= B_OK) {
			buffer->area.SetTo(area);
			if (GartMap(buffer) < B_OK) {
				buffer->area.Detach();
				return NULL;
			}
		} else {
			buffer->area.SetTo(create_area("GPU GTT", &virtAdr, B_ANY_ADDRESS, size, B_FULL_LOCK /*B_CONTIGUOUS*/, B_READ_AREA | B_WRITE_AREA | B_CLONEABLE_AREA));
			if (!buffer->area.IsSet()) return NULL;
			if (GartMap(buffer) < B_OK) return NULL;
		}
	}

	//pool.Dump();
	return buffer;
}

BReference<BufferObject> MemoryManager::AllocAt(uint64 gpuAdr, uint64 size, uint64 alignment, uint32 flags)
{
	(void)alignment;
	(void)flags;
	size = (size + B_PAGE_SIZE - 1) / B_PAGE_SIZE * B_PAGE_SIZE;
	MemoryDomain domain = boDomainVramMappable;
	ExternalAllocator& pool = fDomainPools[domain];
	if (!pool.AllocAt(gpuAdr, size)) return NULL;
	BReference<BufferObject> buffer(new BufferObject(), true);
	buffer->domain = domain;
	buffer->gpuPhysAdr = gpuAdr;
	buffer->size = size;

	return buffer;
}

status_t MemoryManager::CpuMap(void*& ptr, BReference<BufferObject> buffer, uint64 offset, uint64 size)
{
	if (!buffer.IsSet()) return B_BAD_VALUE;
	if (!(offset + size <= buffer->size)) return B_BAD_VALUE;
	switch (buffer->domain) {
		case boDomainVramMappable: {
			ptr = gDevice.SharedInfo()->frame_buffer + (buffer->gpuPhysAdr - fVramRange.beg) + offset;
			return B_OK;
		}
		case boDomainGtt: {
			area_info areaInfo;
			CheckRet(get_area_info(buffer->area.Get(), &areaInfo));
			ptr = (uint8*)areaInfo.address + buffer->offset + offset;
			return B_OK;
		}
		default:
			;
	}
	return B_NOT_ALLOWED;
}

int32 MemoryManager::AllocVmid()
{
	uint64_t vmid;
	while (!fVmidPool.Alloc(vmid, 1)) {
		fFreeVmidCv.Acquire();
	}
	return (int32)vmid;
}

void MemoryManager::FreeVmid(int32 vmid)
{
	fVmidPool.Free((uint64_t)vmid);
	if (fVmidPool.AllocSize() == 0) {
		fFreeVmidCv.Release();
	}
}

status_t MemoryManager::AllocWriteback(uint64 &gpuAdr, void *&cpuAdr, uint64 size)
{
	if (!fWritebackPool.Alloc(gpuAdr, size)) {
		return B_NO_MEMORY;
	}
	cpuAdr = (void*)((addr_t)(gpuAdr - fWritebackBuf.buf->gpuPhysAdr) + (addr_t)fWritebackBuf.adr);
	return B_OK;
}

void MemoryManager::FreeWriteback(uint64 gpuAdr)
{
	fWritebackPool.Free(gpuAdr);
}


status_t MemoryManager::GetUsage(uint64 &total, uint64 &alloc, MemoryDomain domain)
{
	if (!(domain >= boDomainVram && domain <= boDomainGtt)) return B_BAD_VALUE;
	auto &pool = fDomainPools[domain];
	total = pool.TotalSize();
	alloc = pool.AllocSize();
	return B_OK;
}

status_t MemoryManager::InitGart()
{
	if (fGartEnabled) return B_OK;
	
	uint32 radeon_vm_block_size = 9;

	fGartPageTable.SetTo(Alloc(boDomainVramMappable, fGttRange.size / B_PAGE_SIZE * sizeof(uint64)));
	memset(fGartPageTable.adr, 0, fGartPageTable.buf->size);

	/* Setup TLB control */
	WriteReg4AmdGpu(mmMC_VM_MX_L1_TLB_CNTL, McVmMxL1TlbCntl {
			.enableL1Tlb = true,
			.enableL1FragmentProcessing = true,
			.systemAccessMode = 3, // SYSTEM_ACCESS_MODE_NOT_IN_SYS
			.systemApertureUnmappedAccess = 0, // SYSTEM_APERTURE_UNMAPPED_ACCESS_PASS_THRU
			.enableAdvancedDriverModel = true,
			.ecoBits = 0xA
	}.val);
#if 0
	WriteReg4AmdGpu(mmMC_VM_MX_L1_TLB_CNTL,
	       (0xA << 7) |
	       ENABLE_L1_TLB |
	       ENABLE_L1_FRAGMENT_PROCESSING |
	       SYSTEM_ACCESS_MODE_NOT_IN_SYS |
	       ENABLE_ADVANCED_DRIVER_MODEL |
	       SYSTEM_APERTURE_UNMAPPED_ACCESS_PASS_THRU);
#endif
	/* Setup L2 cache */
	WriteReg4AmdGpu(mmVM_L2_CNTL, VmL2Cntl {
			.enableL2Cache = true,
			.enableL2FragmentProcessing = true,
			.enableL2PteCacheLruUpdateByWrite = true,
			.enableL2Pde0CacheLruUpdateByWrite = true,
			.effectiveL2QueueSize = 7,
			.context1IdentityAccessMode = 1
	}.val);
#if 0
	WriteReg4AmdGpu(mmVM_L2_CNTL, ENABLE_L2_CACHE |
	       ENABLE_L2_FRAGMENT_PROCESSING |
	       ENABLE_L2_PTE_CACHE_LRU_UPDATE_BY_WRITE |
	       ENABLE_L2_PDE0_CACHE_LRU_UPDATE_BY_WRITE |
	       EFFECTIVE_L2_QUEUE_SIZE(7) |
	       CONTEXT1_IDENTITY_ACCESS_MODE(1));
#endif
	WriteReg4AmdGpu(mmVM_L2_CNTL2, VmL2Cntl2 {
			.invalidateAllL1Tlbs = true,
			.invalidateL2Cache = true,
	}.val);
#if 0
	WriteReg4AmdGpu(mmVM_L2_CNTL2, INVALIDATE_ALL_L1_TLBS | INVALIDATE_L2_CACHE);
#endif
	WriteReg4AmdGpu(mmVM_L2_CNTL3, VmL2Cntl3 {
			.bankSelect = 4,
			.l2CacheBigkFragmentSize = 4,
			.l2CacheBigkAssociativity = true,
	}.val);
#if 0
	WriteReg4AmdGpu(mmVM_L2_CNTL3, L2_CACHE_BIGK_ASSOCIATIVITY |
	       BANK_SELECT(4) |
	       L2_CACHE_BIGK_FRAGMENT_SIZE(4));
#endif
	/* setup context0 */
	WriteReg4AmdGpu(mmVM_CONTEXT0_PAGE_TABLE_START_ADDR, fGttRange.beg / B_PAGE_SIZE);
	WriteReg4AmdGpu(mmVM_CONTEXT0_PAGE_TABLE_END_ADDR, (fGttRange.beg + fGttRange.size) / B_PAGE_SIZE - 1);
	
	printf("VM_CONTEXT0_PAGE_TABLE_START_ADDR: %#" B_PRIx32 "\n", ReadReg4AmdGpu(mmVM_CONTEXT0_PAGE_TABLE_START_ADDR));
	printf("VM_CONTEXT0_PAGE_TABLE_END_ADDR: %#" B_PRIx32 "\n", ReadReg4AmdGpu(mmVM_CONTEXT0_PAGE_TABLE_END_ADDR));
	
	WriteReg4AmdGpu(mmVM_CONTEXT0_PAGE_TABLE_BASE_ADDR, fGartPageTable.buf->gpuPhysAdr >> 12);
	WriteReg4AmdGpu(mmVM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR,
			(uint32)(fDummyPage->gpuPhysAdr >> 12));
	WriteReg4AmdGpu(mmVM_CONTEXT0_CNTL2, 0);
	WriteReg4AmdGpu(mmVM_CONTEXT0_CNTL, VmContext0Cntl {
			.enableContext = true,
			.pageTableDepth = 0,
			.rangeProtectionFaultEnableDefault = true,
	}.val);
#if 0
	WriteReg4AmdGpu(mmVM_CONTEXT0_CNTL, (ENABLE_CONTEXT | PAGE_TABLE_DEPTH(0) |
				  RANGE_PROTECTION_FAULT_ENABLE_DEFAULT));
#endif

	WriteReg4AmdGpu(mmVM_L2_CONTEXT1_IDENTITY_APERTURE_LOW_ADDR, 0);
	WriteReg4AmdGpu(mmVM_L2_CONTEXT1_IDENTITY_APERTURE_HIGH_ADDR, 0);
	WriteReg4AmdGpu(mmVM_L2_CONTEXT_IDENTITY_PHYSICAL_OFFSET, 0);

#if 1
	/* empty context1-15 */
	/* set vm size, must be a multiple of 4 */
	WriteReg4AmdGpu(mmVM_CONTEXT1_PAGE_TABLE_START_ADDR, 0);
	WriteReg4AmdGpu(mmVM_CONTEXT1_PAGE_TABLE_END_ADDR, uint64(AddressSpace::pageDirLen)*uint64(AddressSpace::pageTableLen) - 1);
	/* Assign the pt base to something valid for now; the pts used for
	 * the VMs are determined by the application and setup and assigned
	 * on the fly in the vm part of radeon_gart.c
	 */
/*
	for (i = 1; i < 16; i++) {
		if (i < 8)
			WriteReg4AmdGpu(mmVM_CONTEXT0_PAGE_TABLE_BASE_ADDR + (i << 2),
			       rdev->vm_manager.saved_table_addr[i]);
		else
			WriteReg4AmdGpu(mmVM_CONTEXT8_PAGE_TABLE_BASE_ADDR + ((i - 8) << 2),
			       rdev->vm_manager.saved_table_addr[i]);
	}
*/
	/* enable context1-15 */

	WriteReg4AmdGpu(mmVM_CONTEXT1_PROTECTION_FAULT_DEFAULT_ADDR,
	       (uint32)(fDummyPage->gpuPhysAdr >> 12));

	WriteReg4AmdGpu(mmVM_CONTEXT1_CNTL2, 4);
	WriteReg4AmdGpu(mmVM_CONTEXT1_CNTL, VmContext1Cntl {
			.enableContext = true,
			.pageTableDepth = 1,
			.rangeProtectionFaultEnableInterrupt = true,
			.rangeProtectionFaultEnableDefault = true,
			.dummyPageProtectionFaultEnableInterrupt = true,
			.dummyPageProtectionFaultEnableDefault = true,
			.pde0ProtectionFaultEnableInterrupt = true,
			.pde0ProtectionFaultEnableDefault = true,
			.validProtectionFaultEnableInterrupt = true,
			.validProtectionFaultEnableDefault = true,
			.readProtectionFaultEnableInterrupt = true,
			.readProtectionFaultEnableDefault = true,
			.writeProtectionFaultEnableInterrupt = true,
			.writeProtectionFaultEnableDefault = true,
			.pageTableBlockSize = radeon_vm_block_size - 9
	}.val);
#if 0
	WriteReg4AmdGpu(mmVM_CONTEXT1_CNTL, ENABLE_CONTEXT | PAGE_TABLE_DEPTH(1) |
				PAGE_TABLE_BLOCK_SIZE(radeon_vm_block_size - 9) |
				RANGE_PROTECTION_FAULT_ENABLE_INTERRUPT |
				RANGE_PROTECTION_FAULT_ENABLE_DEFAULT |
				DUMMY_PAGE_PROTECTION_FAULT_ENABLE_INTERRUPT |
				DUMMY_PAGE_PROTECTION_FAULT_ENABLE_DEFAULT |
				PDE0_PROTECTION_FAULT_ENABLE_INTERRUPT |
				PDE0_PROTECTION_FAULT_ENABLE_DEFAULT |
				VALID_PROTECTION_FAULT_ENABLE_INTERRUPT |
				VALID_PROTECTION_FAULT_ENABLE_DEFAULT |
				READ_PROTECTION_FAULT_ENABLE_INTERRUPT |
				READ_PROTECTION_FAULT_ENABLE_DEFAULT |
				WRITE_PROTECTION_FAULT_ENABLE_INTERRUPT |
				WRITE_PROTECTION_FAULT_ENABLE_DEFAULT);
#endif
#endif

	fGartEnabled = true;

	fWritebackBuf.SetTo(Alloc(boDomainGtt, 4096));
	fWritebackPool.Register(fWritebackBuf.buf->gpuPhysAdr, fWritebackBuf.buf->size);

	return B_OK;
}

status_t MemoryManager::GartMap(BReference<BufferObject> buffer)
{
	// printf("GartMap()\n");
	uint8 *cpuVirtAdr;
	Pte *pageTableVirtAdr = (Pte*)fGartPageTable.adr;
	CheckRet(gDevice.MemMgr().Switch()->CpuMap(*(void**)&cpuVirtAdr, buffer, 0, buffer->size));
	for (uint64 offset = 0; offset < buffer->size; offset += B_PAGE_SIZE) {
		uint64 cpuPhysAdr;
		CheckRet(gPoke.GetPhysicalAddress(cpuPhysAdr, cpuVirtAdr + offset, B_PAGE_SIZE));
		Pte pte{
			.flags = R600_PTE_VALID | R600_PTE_SYSTEM | R600_PTE_READABLE | R600_PTE_WRITEABLE | R600_PTE_SNOOPED,
			.ppn = cpuPhysAdr / B_PAGE_SIZE
		};
		pageTableVirtAdr[(buffer->gpuPhysAdr - fGttRange.beg + offset) / B_PAGE_SIZE] = pte;
		// printf("  %#" B_PRIx64 ": %#" B_PRIx64 "\n", buffer->gpuPhysAdr - fGttRange.beg + offset, cpuPhysAdr);
	}
	GartFlushTlb();
	return B_OK;
}

status_t MemoryManager::GartUnmap(BufferObject *buffer)
{
	Pte *pageTableVirtAdr = (Pte*)fGartPageTable.adr;
	for (uint64 offset = 0; offset < buffer->size; offset += B_PAGE_SIZE) {
		pageTableVirtAdr[(buffer->gpuPhysAdr - fGttRange.beg + offset) / B_PAGE_SIZE] = Pte{.val = 0};
	}
	GartFlushTlb();
	return B_OK;
}

void MemoryManager::GartFlushTlb()
{
	/* flush hdp cache */
	WriteReg4AmdGpu(mmHDP_MEM_COHERENCY_FLUSH_CNTL, 0x1);
	/* bits 0-15 are the VM contexts0-15 */
	WriteReg4AmdGpu(mmVM_INVALIDATE_REQUEST, 1);
}


// #pragma mark - Tests

void MemoryTest()
{
	for (int i = 0; i < 3; i++) {
		BReference<BufferObject> buf1 = gDevice.MemMgr().Switch()->Alloc(boDomainGtt, B_PAGE_SIZE*16, B_PAGE_SIZE);
		BReference<BufferObject> buf2 = gDevice.MemMgr().Switch()->Alloc(boDomainGtt, B_PAGE_SIZE*6, B_PAGE_SIZE);
		BReference<BufferObject> buf3 = gDevice.MemMgr().Switch()->Alloc(boDomainGtt, B_PAGE_SIZE*24, B_PAGE_SIZE);
		printf("buf1: "); WriteBuffer(*buf1.Get()); printf("\n");
		printf("buf2: "); WriteBuffer(*buf2.Get()); printf("\n");
		printf("buf3: "); WriteBuffer(*buf3.Get()); printf("\n");
	}
}
