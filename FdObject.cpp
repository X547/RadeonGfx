#include "FdObject.h"
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>

AVLTree<FdObject::NodeDef> FdObject::fMap;
mutex FdObject::fMapLock = MUTEX_INITIALIZER("FdObjectMap");


FdObject::~FdObject()
{
	if (fFd.IsSet()) {
		MutexLocker lock(fMapLock);
		fMap.Remove(this);
	}
}

FdObject *FdObject::Lookup(const Key &key)
{
	printf("FdObject::Lookup(%" B_PRIu64 ", %" B_PRIu64 ")\n", (uint64)key.dev, (uint64)key.ino);
	// TODO: Map don't hold reference and object may reach zero reference count during call.
	// It may cause return of already deleted object.
	MutexLocker lock(fMapLock);
	BReference<FdObject> obj(fMap.Find(key), false);
	return obj.Detach();
}

int FdObject::GetFd() const
{
	MutexLocker lock(fLock);
	return fFd.Get();
}

int FdObject::AllocFd()
{
	printf("FdObject::AllocFd()\n");
	MutexLocker lock(fLock);
	if (!fFd.IsSet()) {
		SetFd(shm_open(SHM_ANON, O_RDWR | O_CREAT | O_CLOEXEC, 0600));
		if (!fFd.IsSet()) return -1;
		{
			MutexLocker lock(fMapLock);
			fMap.Insert(this);
		}
	}
	return fFd.Get();
}

void FdObject::SetFd(int fd)
{
	fFd.SetTo(fd);
	struct stat st{};
	if (fstat(fd, &st) < 0) {
		fFd.Unset();
		return;
	}
	fKey.dev = st.st_dev;
	fKey.ino = st.st_ino;
}
