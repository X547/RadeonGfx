#include "BitfieldAllocator.h"
#include <stdio.h>
#include <inttypes.h>


BitfieldAllocator::BitfieldAllocator():
	fAllocSet(0), fTotalSize(0), fAllocSize(0)
{}

void BitfieldAllocator::Register(uint64_t ptr, size_t size)
{
	for (uint32_t i = 0; i < size; i++) {
		fAllocSet |= 1 << (uint32_t(ptr) + i);
	}
	fTotalSize += size;
}

bool BitfieldAllocator::Alloc(uint64_t &ptr, size_t size)
{
	if (size != 1) return false;
	for (uint32_t i = 0; i < 32; i++) {
		if ((1 << i) & fAllocSet) {
			fAllocSet &= ~(1 << i);
			fAllocSize += 1;
			ptr = i;
			return true;
		}
	}
	return false;
}

void BitfieldAllocator::Free(uint64_t ptr)
{
	if (ptr >= 32 || ((1 << uint32_t(ptr)) & fAllocSet)) {
		printf("[!] Free(%#" PRIx64 "): pointer is not allocated\n", ptr);
		return;
	}
	fAllocSet |= (1 << uint32_t(ptr));
	fAllocSize -= 1;
}
