#pragma once

#include <stddef.h>
#include <stdint.h>


class BitfieldAllocator {
private:
	uint32_t fAllocSet;
	uint64_t fTotalSize, fAllocSize;

public:
	BitfieldAllocator();
	void Register(uint64_t ptr, size_t size);

	void CoalesceFreeBlocks();

	bool Alloc(uint64_t &ptr, size_t size);
	bool AllocAt(uint64_t ptr, size_t size);
	void Free(uint64_t ptr);

	inline uint64_t TotalSize() {return fTotalSize;}
	inline uint64_t AllocSize() {return fAllocSize;}
};
