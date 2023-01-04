#pragma once

#include <map>
#include <Referenceable.h>
#include <private/shared/AutoDeleterOS.h>

#include "ExternalAllocator.h"
#include "BitfieldAllocator.h"
#include "SADomains/Domains.h"
#include "SADomains/DomainCondVars.h"
#include "FdObject.h"

struct BufferObject;
class AddressSpace;


enum MemoryDomain {
	boDomainVram = 0,
	boDomainVramMappable,
	boDomainGtt,
};


#define R600_PTE_VALID		(1 << 0)
#define R600_PTE_SYSTEM		(1 << 1)
#define R600_PTE_SNOOPED	(1 << 2)
#define R600_PTE_READABLE	(1 << 5)
#define R600_PTE_WRITEABLE	(1 << 6)

#define R600_PTE_FRAG_4KB	(0 << 7)
#define R600_PTE_FRAG_64KB	(4 << 7)
#define R600_PTE_FRAG_256KB	(6 << 7)


struct BufferObject: public FdObject {
	// not used yet
	struct Info {
		uint64 size;
		uint64 alignment;
		MemoryDomain domain;
		uint32 flags;
	};

	struct Metadata {
		uint64 flags;
		uint64 tiling_info;
		uint32 data_size_bytes;
		uint32 data[64];
	};

	MemoryDomain domain;
	uint64 gpuPhysAdr;
	uint64 size;
	uint64 offset; // relative to area
	AreaDeleter area;

	Metadata metadata{};

	Info GetInfo();

	~BufferObject();
};

struct MappedBuffer {
	BReference<BufferObject> buf;
	void *adr;
	MappedBuffer(): adr(NULL) {}
	MappedBuffer(BReference<BufferObject> buffer) {SetTo(buffer);}
	status_t SetTo(BReference<BufferObject> buffer);
};

union Pte {
	struct {
		uint64 flags: 12;
		uint64 ppn: 52;
	};
	uint64 val;
};

class AddressSpace: public BReferenceable {
private:
	struct Mapping {
		BReference<BufferObject> buffer;
		uint64 offset;
		uint64 size;
	};

	int32 fVmId;
	int32 fVmIdRefCnt;
	std::map<uint64, Mapping> fMappings;

public:
	enum {
		pageDirLen = 1 << 12,
		pageTableLen = 1 << 9,
	};

private:
	MappedBuffer fPageDirBuf;
	ArrayDeleter<MappedBuffer> fPageTableBufs;

	Pte *LookupPte(uint64 virtAdr, bool alloc);
	status_t MapInt(uint64 virtAdr, uint64 physAdr, uint32 flags);
	status_t MapIntRange(uint64 virtAdr, uint64 physAdr, uint64 size, uint32 flags);
	status_t UnmapInt(uint64 virtAdr);

public:
	AddressSpace();
	virtual ~AddressSpace();
	uint64 PageDir() {return fPageDirBuf.buf->gpuPhysAdr;}
	void DumpPageTable();

	BReference<BufferObject> Lookup(uint64 mapAdr, uint64 &offset);
	status_t Map(BReference<BufferObject> buffer, uint64 mapAdr, uint64 offset, uint64 size);
	status_t Unmap(BReference<BufferObject> buffer, uint64 mapAdr, uint64 offset, uint64 size);

	int32 AcquireVmid();
	void ReleaseVmid();
};


class MemoryManager: public Object {
public:
	struct {
		uint64 beg, size;
	} fVramRange, fGttRange;
private:
	ExternalAllocator fDomainPools[3];
	friend struct BufferObject;
	friend class AddressSpace;

	bool fGartEnabled;
	MappedBuffer fGartPageTable;

	BitfieldAllocator fVmidPool;
	DomainCondVar fFreeVmidCv;

	MappedBuffer fWritebackBuf;
	ExternalAllocator fWritebackPool;

public:
	BReference<BufferObject> fDummyPage;
	BReference<BufferObject> fVramScratch;
private:
	status_t GartMap(BReference<BufferObject> buffer);
	status_t GartUnmap(BufferObject *buffer);
	void GartFlushTlb();

	int32 AllocVmid();
	void FreeVmid(int32 vmid);

public:
	MemoryManager();
	BReference<BufferObject> Alloc(MemoryDomain domain, uint64 size, uint64 alignment = B_PAGE_SIZE, uint32 flags = 0, area_id area = B_ERROR, uint64 offset = 0);
	BReference<BufferObject> AllocAt(uint64 gpuAdr, uint64 size, uint64 alignment = B_PAGE_SIZE, uint32 flags = 0);
	status_t CpuMap(void*& adr, BReference<BufferObject> buffer, uint64 offset, uint64 size);

	status_t GetUsage(uint64 &total, uint64 &alloc, MemoryDomain domain);

	status_t Init();
	status_t InitGart();

	status_t AllocWriteback(uint64 &gpuAdr, void *&cpuAdr, uint64 size);
	void FreeWriteback(uint64 gpuAdr);
};


void MemoryTest();
