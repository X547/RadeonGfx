#pragma once

#include <SupportDefs.h>
#include "ExternalAllocator.h"


template <typename Type>
class HandleTable {
private:
	std::map<void*, int32> fObjects;
	std::map<int32, Type> fHandles;
	ExternalAllocator fHandlePool;

public:
	HandleTable();

	int32 Register(Type obj);
	status_t Free(int32 handle);
	Type This(int32 handle);

	inline std::map<int32, Type> &Handles() {return fHandles;}
};

template <typename Type>
HandleTable<Type>::HandleTable()
{
	fHandlePool.Register(1, 0x7fffffff - 1);
}

template <typename Type>
int32 HandleTable<Type>::Register(Type obj)
{
	//if (!obj.IsSet()) return B_ERROR;
	auto it = fObjects.find(obj.ref.Get());
	if (it != fObjects.end()) return it->second;
	uint64_t handle64;
	if (!fHandlePool.Alloc(handle64, 1)) return B_NO_MEMORY;
	int32 handle = (int32)handle64;
	fObjects.emplace(obj.ref.Get(), handle);
	fHandles.emplace(handle, obj);
	return handle;
}

template <typename Type>
status_t HandleTable<Type>::Free(int32 handle)
{
	auto it = fHandles.find(handle);
	if (it == fHandles.end()) return B_ERROR;
	fObjects.erase(it->second.ref.Get());
	fHandles.erase(it);
	fHandlePool.Free(handle);
	return B_OK;
}

template <typename Type>
Type HandleTable<Type>::This(int32 handle)
{
	auto it = fHandles.find(handle);
	if (it == fHandles.end()) return {};
	return it->second;
}
