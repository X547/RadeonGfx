#include "Fence.h"

#include <private/shared/AutoLocker.h>
#include <AutoDeleter.h>
#include "SADomains/Domains.h"

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


void Fence::Signal()
{
	TRACE("%p.Signal()\n", this);
	if (Flags{.val = atomic_or((int32*)&fFlags.val, Flags{.signaled = true}.val)}.signaled) {
		return;
	}

	for (;;) {
		Handler* handler;
		{
			AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&fLock);
			handler = fHandlers.RemoveHead();
		}
		if (handler == NULL) return;
		handler->Do(this);
	}
}

void Fence::OnSignal(Handler *handler)
{
	AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&fLock);
	TRACE("Fence(%p).OnSignal(%p)\n", this, handler);
	if (!IsSignaled()) {
		fHandlers.Insert(handler);
	} else {
		handler->Do(this);
	}
}

void Fence::OnSignalCancel(Handler *handler)
{
	AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&fLock);
	TRACE("Fence(%p).OnSignalCancel(%p)\n", this, handler);
	auto link = handler->GetDoublyLinkedListLink();
	if (!fHandlers.Contains(handler) /*fHandlers.First() != handler && link->next == NULL && link->previous == NULL*/) {
		//TRACE("  not registered\n");
		return;
	}
	fHandlers.Remove(handler);
}

status_t Fence::WaitNonDomain(uint32 flags, bigtime_t timeout)
{
	Mutex mutex(true);

	HandlerTemplate handler([&](Fence *fence){mutex.Release();});
	OnSignal(&handler);
	status_t res = mutex.Acquire(flags, timeout);
	OnSignalCancel(&handler);
	return res;
}

status_t Fence::Wait(uint32 flags, bigtime_t timeout)
{
	// TODO: timeout
	Request *rootReq = CurrentRootRequest();

	HandlerTemplate handler([&](Fence *fence){rootReq->Schedule();});
	OnSignal(&handler);

	Domain::Wait();
	return B_OK;
}

status_t Fence::WaitMultiple(uint32 *firstSignaled, BReference<Fence> *fences, uint32 count, WaitFlags flags, bigtime_t timeout)
{
	WaitInfoBase waitInfo {
		.firstSignaled = flags.all ? NULL : firstSignaled,
		.remainingCount = flags.all ? count : 1,
		.flags = flags,
		.timeout = timeout
	};
	waitInfo.Init();

	class WaitHandler: public Handler {
	public:
		WaitInfoBase *fWaitInfo;
		uint32 fIdx;
		void Do(Fence *fence) override {(void)fence; fWaitInfo->Resolved(fIdx);}
	};
	ArrayDeleter<WaitHandler> handlers(new WaitHandler[count]);
	for (uint32 i = 0; i < count; i++) {
		handlers[i].fWaitInfo = &waitInfo;
		handlers[i].fIdx = i;
		fences[i]->OnSignal(&handlers[i]);
	}

	status_t res = waitInfo.Wait();

	for (uint32 i = 0; i < count; i++) {
		fences[i]->OnSignalCancel(&handlers[i]);
	}

	return res;
}


SignaledFence::SignaledFence():
	Fence(0)
{
	Signal();
}

BReference<SignaledFence> SignaledFence::Instance()
{
	static SignaledFence fence;
	return BReference<SignaledFence>(&fence);
}

WaitInfoBase::~WaitInfoBase()
{
	AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&this->lock);
}

void WaitInfoBase::Init()
{
	if (flags.domain) {
		req = CurrentRootRequest();
	}
}

status_t WaitInfoBase::Wait()
{
	AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&this->lock);
	TRACE("%p.WaitInfoBase::Wait(), dom: %p, req: %p\n", this, dom, req);
	if (!flags.absoluteTimeout && timeout == 0) {
		return (remainingCount > 0) ? B_TIMED_OUT : B_OK;
	}
	if (flags.domain) {
		lock.Unlock();
		Domain::Wait();
	} else {
		while (remainingCount > 0) {
			cond.Acquire(this->lock);
		}
	}
	return B_OK;
}

void WaitInfoBase::Resolved(uint32 idx)
{
	AutoLocker<RecursiveLock, AutoLockerLocksLocking<RecursiveLock>> lock(&this->lock);
	TRACE("%p.WaitInfoBase::Resolved(%" B_PRIu32 ")\n", this, idx);
	TRACE("  dom: %p, req: %p\n", dom, req);
	if (remainingCount == 0) return;
	remainingCount--;
	if (remainingCount == 0) {
		if (firstSignaled != NULL) {
			*firstSignaled = idx;
		}
		if (flags.absoluteTimeout || timeout != 0) {
			if (flags.domain) {
				req->Schedule();
			} else {
				cond.Release();
			}
		}
	}
}
