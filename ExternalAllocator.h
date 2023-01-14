#pragma once
#include "CppUtils.h"
#include <util/AVLTree.h>


class ExternalAllocator {
private:
	class Block {
	public:
		struct AdrNodeDef {
			typedef uint64 Key;
			typedef Block Value;

			inline AVLTreeNode* GetAVLTreeNode(Value* value) const
			{
				return &value->fAdrNode;
			}

			inline Value* GetValue(AVLTreeNode* node) const
			{
				return &ContainerOf(*node, &Block::fAdrNode);
			}

			inline int Compare(const Key& a, const Value* b) const
			{
				if (a < b->fAdr) return -1;
				if (a > b->fAdr) return 1;
				return 0;
			}

			inline int Compare(const Value* a, const Value* b) const
			{
				if (a->fAdr < b->fAdr) return -1;
				if (a->fAdr > b->fAdr) return 1;
				return 0;
			}
		};

		struct SizeNodeDef {
			typedef uint64 Key;
			typedef Block Value;

			inline AVLTreeNode* GetAVLTreeNode(Value* value) const
			{
				return &value->fSizeNode;
			}

			inline Value* GetValue(AVLTreeNode* node) const
			{
				return &ContainerOf(*node, &Block::fSizeNode);
			}

			inline int Compare(const Key& a, const Value* b) const
			{
				if (a < b->fSize) return -1;
				if (a > b->fSize) return 1;
				return 0;
			}

			inline int Compare(const Value* a, const Value* b) const
			{
				if (a->fSize < b->fSize) return -1;
				if (a->fSize > b->fSize) return 1;
				if (a->fAdr < b->fAdr) return -1;
				if (a->fAdr > b->fAdr) return 1;
				return 0;
			}
		};

		uint64 fAdr;
		uint64 fSize;
		AVLTreeNode fAdrNode;
		AVLTreeNode fSizeNode;
		bool fAllocated = false;

		Block(uint64 adr, uint64 size): fAdr(adr), fSize(size) {}
	};

	AVLTree<Block::AdrNodeDef> fAdrMap;
	AVLTree<Block::SizeNodeDef> fSizeMap;
	uint64_t fTotalSize, fAllocSize;

public:
	~ExternalAllocator();

	void Register(uint64_t ptr, uint64_t size);

	[[nodiscard]] bool Alloc(uint64_t &ptr, uint64_t size);
	[[nodiscard]] bool AllocAligned(uint64_t &ptr, uint64_t size, uint64_t align);
	[[nodiscard]] bool AllocAt(uint64_t ptr, uint64_t size);
	void Free(uint64_t ptr);

	inline uint64_t TotalSize() {return fTotalSize;}
	inline uint64_t AllocSize() {return fAllocSize;}

	void Dump();
};
