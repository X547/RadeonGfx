#include "Syncobj.h"
#include "FenceGroup.h"
#include <AutoDeleter.h>
#include <private/shared/AutoLocker.h>

#include <stdio.h>

#if 0
#define TRACE(x...) printf(x)
#else
#define TRACE(x...) ;
#endif


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


void Syncobj::FenceHandler::Do(Fence *fence)
{
	//TRACE("Syncobj::Handler::Do(%p)\n", fence);
	auto item = (FenceItem*)((char*)this - offsetof(FenceItem, handler));
	Syncobj *syncobj = item->base;
	syncobj->fLastSignaled = item;
}


status_t Syncobj::InsertFence(uint64 point, BReference<Fence> fence)
{
	AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&fLock);
	TRACE("%p.InsertFence(%" B_PRIu64 ", %p)\n", this, point, fence.Get());
	if (point == 0) {
		Reset();
	} else if (fFences.Last() != NULL && fFences.Last()->point >= point) {
		TRACE("  [!] point already present, last: %" B_PRIu64 "\n", fFences.Last()->point);
		return B_BAD_VALUE;
	}
	ObjectDeleter<FenceItem> item(new FenceItem{
		.base = this,
		.fence = fence,
		.point = point
	});
	fence->OnSignal(&item->handler);
	fLastAvail = item.Get();
	fFences.Insert(item.Detach());
	for (Handler* handler = fHandlers.First(); handler != NULL; ) {
		Handler *next = fHandlers.GetNext(handler);
		if (handler->fPoint <= fLastAvail->point) {
			fHandlers.Remove(handler);
			handler->Do(this, fence);
		}
		handler = next;
	}
	return B_OK;
}

BReference<Fence> Syncobj::LookupFence(uint64 point, WaitFlags flags)
{
	AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&fLock);
	if (fFences.Last() == NULL || point > fFences.Last()->point) {
		if (!flags.forSubmit) {
			return NULL;
		}
		BReference<Fence> resFence;
		if (flags.domain) {
			Domain *dom = CurrentRootDomain();
			Request *req = dom->CurrentRequest();
			HandlerTemplate handler([dom, req, &resFence](Syncobj *so, Fence *f) {
				TRACE("Syncobj::Handler::Do(%p, %p)\n", so, f);
				resFence.SetTo(f, false);
				dom->Schedule(req);
			});
			OnAvail(&handler, point);
			lock.Unlock();
			Domain::Wait();
		} else {
			Mutex mutex(true);
			HandlerTemplate handler([&mutex, &resFence](Syncobj *so, Fence *f){
				resFence.SetTo(f, false);
				mutex.Release();
			});
			mutex.Acquire();
		}
		return resFence;
	}
	FenceItem *item = fFences.First();
	while (item != NULL && !(item->point >= point)) item = fFences.GetNext(item);
	return item == NULL ? NULL : item->fence;
}


Syncobj::Syncobj(CreateFlags flags)
{
	TRACE("+%p.Syncobj()\n", this);
	if (flags.signaled) {
		Signal(0);
	}
}

Syncobj::~Syncobj()
{
	TRACE("-%p.Syncobj()\n", this);
	Reset();
	for (Handler* handler = fHandlers.First(); handler != NULL; ) {
		Handler *next = fHandlers.GetNext(handler);
		fHandlers.Remove(handler);
		handler->Do(this, NULL);
		handler = next;
	}
}


status_t Syncobj::Reset()
{
	AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&fLock);
	TRACE("%p.Reset()\n", this);
	while (FenceItem *item = fFences.RemoveHead()) {
		delete item;
	}
	fLastAvail = NULL;
	fLastSignaled = NULL;
	return B_OK;
}

status_t Syncobj::Signal(uint64 point)
{
	TRACE("%p.Signal(%" B_PRIu64 ")\n", this, point);
	return InsertFence(point, SignaledFence::Instance());
}

status_t Syncobj::Query(uint64 &point, QueryFlags flags)
{
	TRACE("%p.Query()\n", this);
	AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&fLock);
	FenceItem *last = flags.lastSubmitted ? fLastAvail : fLastSignaled;
	if (last == NULL) {
		return ENOENT;
	}
	point = last->point;
	return B_OK;
}

status_t Syncobj::Transfer(uint64 dstPoint, SyncobjRef srcSyncobj, uint64 srcPoint, WaitFlags flags)
{
	TRACE("%p.Transfer(%" B_PRIu64 ", %p, %" B_PRIu64 ")\n", this, dstPoint, srcSyncobj.Get(), srcPoint);
	AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&fLock);
	BReference<Fence> srcFence = srcSyncobj->LookupFence(srcPoint, flags);
	if (!srcFence.IsSet()) {
		return ENOENT;
	}
	return InsertFence(dstPoint, srcFence);
}

status_t Syncobj::Accumulate(SyncobjRef srcSyncobj, uint64 srcPoint)
{
	BReference<Fence> dstFence = LookupFence(0, {});
	if (!dstFence.IsSet()) {
		return ENOENT;
	}
	BReference<Fence> srcFence = srcSyncobj->LookupFence(srcPoint, {.domain = true, .forSubmit = true});
	if (!srcFence.IsSet()) {
		return ENOENT;
	}
	BReference<Fence> fences[] = {dstFence, srcFence};
	return InsertFence(0, BReference(new FenceGroup(fences, B_COUNT_OF(fences), {.all = true}), true));
}


status_t Syncobj::Wait(uint32 *firstSignaled, SyncobjRef *syncobjs, uint64 *points, uint32 count, WaitFlags flags, bigtime_t timeout)
{
	TRACE("Syncobj::Wait(%p, %" B_PRIu64 ", %" B_PRIu32 ", %#" B_PRIx32 ")\n", syncobjs[0].Get(), points[0], count, flags.val);
	if (!flags.forSubmit && !flags.available) {
		ArrayDeleter<BReference<Fence>> fences(new BReference<Fence>[count]);
		for (uint32 i = 0; i < count; i++) {
			fences[i] = syncobjs[i]->LookupFence(points[i]);
			if (!fences[i].IsSet()) return ENOENT;
		}
		return Fence::WaitMultiple(firstSignaled, fences.Get(), count, {.absoluteTimeout = flags.absoluteTimeout, .all = flags.all}, timeout);
	}
	if (flags.available) {
		return WaitAvail(firstSignaled, syncobjs, points, count, flags, timeout);
	}

	return WaitForSubmit(firstSignaled, syncobjs, points, count, flags, timeout);
}

status_t Syncobj::WaitAvail(uint32 *firstSignaled, SyncobjRef *syncobjs, uint64 *points, uint32 count, WaitFlags flags, bigtime_t timeout)
{
	WaitInfoBase waitInfo {
		.firstSignaled = flags.all ? NULL : firstSignaled,
		.remainingCount = flags.all ? count : 1,
		.flags = {.val = flags.val},
		.timeout = timeout
	};
	waitInfo.Init();

	class WaitHandler: public Handler {
	public:
		WaitInfoBase *fWaitInfo;
		uint32 fIdx;
		void Do(Syncobj *syncobj, Fence *fence) override {(void)syncobj; fWaitInfo->Resolved(fIdx);}
	};
	ArrayDeleter<WaitHandler> handlers(new WaitHandler[count]);
	for (uint32 i = 0; i < count; i++) {
		handlers[i].fWaitInfo = &waitInfo;
		handlers[i].fIdx = i;
		syncobjs[i]->OnAvail(&handlers[i], points[i]);
	}

	status_t res = waitInfo.Wait();

	for (uint32 i = 0; i < count; i++) {
		syncobjs[i]->OnAvailCancel(&handlers[i]);
	}

	return res;
}

status_t Syncobj::WaitForSubmit(uint32 *firstSignaled, SyncobjRef *syncobjs, uint64 *points, uint32 count, WaitFlags flags, bigtime_t timeout)
{
	struct WaitInfo {
		WaitInfoBase base;
		ArrayDeleter<BReference<Fence>> fences;
	};
	WaitInfo waitInfo {
		.base = {
			.firstSignaled = flags.all ? NULL : firstSignaled,
			.remainingCount = flags.all ? count : 1,
			.flags = {.val = flags.val},
			.timeout = timeout
		},
		.fences = new BReference<Fence>[count]
	};
	waitInfo.base.Init();
	
	class FenceWaitHandler: public Fence::Handler {
	public:
		WaitInfo *fWaitInfo;
		uint32 fIdx;

		void Do(Fence *fence) override
		{
			(void)fence;
			fWaitInfo->base.Resolved(fIdx);
		}
	};

	class WaitHandler: public Handler {
	public:
		WaitInfo *fWaitInfo;
		uint32 fIdx;
		FenceWaitHandler fFenceHandler;

		void Do(Syncobj *syncobj, Fence *fence) override
		{
			(void)syncobj;
			fWaitInfo->fences[fIdx] = fence;
			fence->OnSignal(&fFenceHandler);
		}
	};

	ArrayDeleter<WaitHandler> handlers(new WaitHandler[count]);
	for (uint32 i = 0; i < count; i++) {
		handlers[i].fWaitInfo = &waitInfo;
		handlers[i].fIdx = i;
		handlers[i].fFenceHandler.fWaitInfo = &waitInfo;
		handlers[i].fFenceHandler.fIdx = i;
		syncobjs[i]->OnAvail(&handlers[i], points[i]);
	}

	status_t res = waitInfo.base.Wait();

	for (uint32 i = 0; i < count; i++) {
		auto fence = waitInfo.fences[i].Get();
		if (fence != NULL) {
			fence->OnSignalCancel(&handlers[i].fFenceHandler);
		}
		syncobjs[i]->OnAvailCancel(&handlers[i]);
	}

	return res;
}


void Syncobj::OnAvail(Handler *handler, uint64 point)
{
	AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&fLock);
	//TRACE("Fence(%p).OnSignal(%p)\n", this, handler);
	handler->fPoint = point;
	if (fLastAvail == NULL || handler->fPoint > fLastAvail->point) {
		fHandlers.Insert(handler);
	} else {
		handler->Do(this, LookupFence(point));
	}
}

void Syncobj::OnAvailCancel(Handler *handler)
{
	AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&fLock);
	//TRACE("Fence(%p).OnSignalCancel(%p)\n", this, handler);
	auto link = handler->GetDoublyLinkedListLink();
	if (!fHandlers.Contains(handler) /*fHandlers.First() != handler && link->next == NULL && link->previous == NULL*/) {
		//TRACE("  not registered\n");
		return;
	}
	fHandlers.Remove(handler);
}


void Syncobj::Dump()
{
	printf("Syncobj:\n");
	printf("  lastAvail: "); if (fLastAvail == NULL) {printf("NULL");} else {printf("%" B_PRIu64, fLastAvail->point);} printf("\n");
	printf("  lastSignaled: "); if (fLastSignaled == NULL) {printf("NULL");} else {printf("%" B_PRIu64, fLastSignaled->point);} printf("\n");
	for (FenceItem *item = fFences.First(); item != NULL; item = fFences.GetNext(item)) {
		printf("  %" B_PRIu64 ": Fence(%" B_PRIu64 ", %d)\n", item->point, item->fence->Seq(), item->fence->IsSignaled());
	}
}
