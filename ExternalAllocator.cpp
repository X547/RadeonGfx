#include "ExternalAllocator.h"
#include <stdio.h>
#include <stdlib.h>

template <typename T>
T RoundDown(T a, T b)
{
	return a / b * b;
}

template <typename T>
T RoundUp(T a, T b)
{
	return RoundDown(a + b - 1, b);
}

static void Assert(bool cond) {if (!cond) abort();}


ExternalAllocator::~ExternalAllocator()
{
	fSizeMap.Clear();
	for (;;) {
		Block *block = fAdrMap.LeftMost();
		if (block == NULL) break;
		fAdrMap.Remove(block);
		delete block;
	}
}

void ExternalAllocator::Register(uint64_t ptr, uint64_t size)
{
	Block *block = new Block(ptr, size);
	fAdrMap.Insert(block);
	fSizeMap.Insert(block);
	fTotalSize += size;
}

bool ExternalAllocator::Alloc(uint64_t &ptr, uint64_t size)
{
	Block *block = fSizeMap.FindClosest(size, false);
	if (block == NULL)
		return false;

	fSizeMap.Remove(block);
	if (block->fSize > size) {
		Block *remainingBlock = new Block(block->fAdr + size, block->fSize - size);
		fAdrMap.Insert(remainingBlock);
		fSizeMap.Insert(remainingBlock);
		block->fSize = size;
	}

	block->fAllocated = true;
	ptr = block->fAdr;
	fAllocSize += block->fSize;
	return true;
}

bool ExternalAllocator::AllocAligned(uint64_t &ptr, uint64_t size, uint64_t align)
{
	Block *block = fSizeMap.FindClosest(size + (align - 1), false);
	if (block == NULL)
		return false;

	uint64_t retPtr = RoundUp(block->fAdr, align);
	ptr = retPtr;
	return AllocAt(retPtr, size);
}

bool ExternalAllocator::AllocAt(uint64_t ptr, uint64_t size)
{
	Block *block = fAdrMap.FindClosest(ptr, true);

	if (block == NULL || block->fAllocated || !(ptr >= block->fAdr && ptr + size <= block->fAdr + block->fSize))
		return false;

	if (block->fAdr < ptr) {
		Block *left = block;
		block = new Block(ptr, left->fSize - (ptr - left->fAdr));
		fAdrMap.Insert(block);
		fSizeMap.Insert(block);
		fSizeMap.Remove(left);
		left->fSize = ptr - left->fAdr;
		fSizeMap.Insert(left);
	}
	if (block->fSize > size) {
		Block *right = new Block(ptr + size, block->fSize - size);
		fAdrMap.Insert(right);
		fSizeMap.Insert(right);

		fSizeMap.Remove(block);
		block->fSize = size;
		fSizeMap.Insert(block);
	}

	fSizeMap.Remove(block);
	block->fAllocated = true;
	fAllocSize += block->fSize;
	return true;
}

void ExternalAllocator::Free(uint64_t ptr)
{
	Block *block = fAdrMap.Find(ptr);
	if (block == NULL || !block->fAllocated) abort();
	fSizeMap.Insert(block);
	block->fAllocated = false;
	fAllocSize -= block->fSize;

	Block *prev = fAdrMap.Previous(block);
	if (prev != NULL && !prev->fAllocated) {
		fSizeMap.Remove(prev);
		prev->fSize += block->fSize;

		fAdrMap.Remove(block);
		fSizeMap.Remove(block);
		delete block;

		block = prev;
		fSizeMap.Insert(block);
	}

	Block *next = fAdrMap.Next(block);
	if (next != NULL && !next->fAllocated) {
		fSizeMap.Remove(block);
		block->fSize += next->fSize;

		fAdrMap.Remove(next);
		fSizeMap.Remove(next);
		delete next;

		fSizeMap.Insert(block);
	}
}

void ExternalAllocator::Dump()
{
	printf("\n");
	printf("Blocks:\n");
	for (Block *it = fAdrMap.LeftMost(); it != NULL; it = fAdrMap.Next(it)) {
		printf("  %#" PRIx64 ": %#" PRIx64 ": %s\n", it->fAdr, it->fAdr + it->fSize - 1, it->fAllocated ? "alloc" : "free");
	}
	printf("Free:\n");
	for (Block *it = fSizeMap.LeftMost(); it != NULL; it = fSizeMap.Next(it)) {
		printf("  %#" PRIx64 ": %#" PRIx64 "\n", it->fSize, it->fAdr);
	}
}
