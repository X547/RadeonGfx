#include "FenceGroup.h"
#include <private/shared/AutoLocker.h>

#include <stdio.h>


template<typename Lockable>
class AutoLockerLocksLocking {
public:
	inline bool Lock(Lockable* lockable)
	{
		return lockable->Acquire() >= B_OK;
	}

	inline void Unlock(Lockable* lockable)
	{
		lockable->Release();
	}
};


void FenceGroup::GroupHandler::Do(Fence *fence)
{
	AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&fGroup->fLock);
	if (fGroup->fRemainingCount > 0) {
		fGroup->fRemainingCount--;
		if (fGroup->fRemainingCount == 0) {
			for (uint32 i = 0; i < fGroup->fCount; i++) {
				fGroup->fHandlers[i].fFence->OnSignalCancel(&fGroup->fHandlers[i]);
			}
			lock.Unlock();
			fGroup->Signal();
		}
	}
}

FenceGroup::FenceGroup(BReference<Fence> *fences, uint32 count, CreateFlags flags)
{
	fFlags.all = flags.all;
	fCount = count;

	for (uint32 i = 0; i < count; i++) {
		FenceGroup *group = dynamic_cast<FenceGroup*>(fences[i].Get());
		if (group != NULL && group->fFlags.all == fFlags.all) {
			fCount += group->fCount - 1;
		}
	}

	fRemainingCount = fFlags.all ? fCount : 1;

	fHandlers.SetTo(new GroupHandler[fCount]);

	uint32 i = 0, j = 0;
	for (uint32 i = 0; i < count; i++) {
		FenceGroup *group = dynamic_cast<FenceGroup*>(fences[i].Get());
		if (group != NULL && group->fFlags.all == fFlags.all) {
			for (uint32 k = 0; k < group->fCount; k++) {
				fHandlers[j].fGroup = this;
				fHandlers[j].fFence = group->fHandlers[k].fFence;
				fHandlers[j].fIdx = j;
				fHandlers[j].fFence->OnSignal(&fHandlers[j]);
				j++;
			}
		} else {
			fHandlers[j].fGroup = this;
			fHandlers[j].fFence = fences[i];
			fHandlers[j].fIdx = j;
			fHandlers[j].fFence->OnSignal(&fHandlers[j]);
			j++;
		}
	}
}

FenceGroup::~FenceGroup()
{
	for (uint32 i = 0; i < fCount; i++) {
		fHandlers[i].fFence->OnSignalCancel(&fHandlers[i]);
	}
}
