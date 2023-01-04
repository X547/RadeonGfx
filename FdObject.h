#pragma once

#include <Referenceable.h>
#include <util/AVLTree.h>
#include <AutoDeleterPosix.h>
#include <locks.h>


class FdObject: public BReferenceable {
public:
	struct Key {
		dev_t dev;
		ino_t ino;

		inline int Compare(const Key &b) const
		{
			if (dev < b.dev) return -1;
			if (dev > b.dev) return 1;
			if (ino < b.ino) return -1;
			if (ino > b.ino) return 1;
			return 0;
		}
	};

private:
	FileDescriptorCloser fFd;
	Key fKey{};
	AVLTreeNode fNode;

	struct NodeDef {
		typedef FdObject::Key Key;
		typedef FdObject Value;

		inline AVLTreeNode* GetAVLTreeNode(Value* value) const
		{
			return &value->fNode;
		}

		inline Value* GetValue(AVLTreeNode* node) const
		{
			return (Value*)((char*)node - offsetof(FdObject, fNode));
		}

		inline int Compare(const Key& a, const Value* b) const
		{
			return a.Compare(b->fKey);
		}

		inline int Compare(const Value* a, const Value* b) const
		{
			return a->fKey.Compare(b->fKey);
		}
	};

	static AVLTree<NodeDef> fMap;
	mutable mutex fLock = MUTEX_INITIALIZER("FdObject");
	static mutex fMapLock;

	void SetFd(int fd);

public:
	virtual ~FdObject();

	static FdObject *Lookup(const Key &key);

	int GetFd() const;
	int AllocFd();
	inline Key const &GetKey() const {return fKey;}
};
