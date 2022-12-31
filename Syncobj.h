#pragma once

#include <Referenceable.h>
#include <OS.h>
#include <private/kernel/util/DoublyLinkedList.h>
#include "Locks/Mutex.h"
#include "Locks/RecursiveLock.h"
#include "Locks/ConditionVariable.h"

#include "Fence.h"


class Syncobj;
typedef BReference<Syncobj> SyncobjRef;

class Syncobj: public BReferenceable {
public:
	struct CreateFlags {
		union {
			struct {
				uint32 signaled: 1;
			};
			uint32 val;
		};
	};
	struct QueryFlags {
		union {
			struct {
				uint32 lastSubmitted: 1;
			};
			uint32 val;
		};
	};
	struct WaitFlags {
		union {
			struct {
				// Fence::WaitFlags
				uint32 absoluteTimeout: 1;
				uint32 all: 1;
				uint32 domain: 1;

				uint32 forSubmit: 1;
				uint32 available: 1;
			};
			uint32 val;
		};
	};

private:
	class FenceHandler: public Fence::Handler {
	public:
		void Do(Fence *fence) override;
	};

	struct FenceItem {
		DoublyLinkedListLink<FenceItem> link;
		FenceHandler handler;
		Syncobj *base;
		BReference<Fence> fence;
		uint64 point;

		~FenceItem() {fence->OnSignalCancel(&handler);}
	};

public:
	struct Handler: public DoublyLinkedListLinkImpl<Handler> {
	private:
		friend class Syncobj;
		uint64 fPoint;
	public:
		virtual void Do(Syncobj *syncobj, Fence *fence) = 0;
	};

	template<typename DoFn>
	class HandlerTemplate: public Handler {
	private:
		DoFn fDoFn;
	public:
		HandlerTemplate(DoFn &&doFn): fDoFn(doFn) {}
		void Do(Syncobj *syncobj, Fence *fence) override {fDoFn(syncobj, fence);}
	};

private:
	RecursiveLock fLock;
	DoublyLinkedList<FenceItem, DoublyLinkedListMemberGetLink<FenceItem, &FenceItem::link>> fFences;
	DoublyLinkedList<Handler> fHandlers;
	FenceItem *fLastAvail = NULL, *fLastSignaled = NULL;

	static status_t WaitAvail(uint32 *firstSignaled, SyncobjRef *syncobjs, uint64 *points, uint32 count, WaitFlags flags, bigtime_t timeout = B_INFINITE_TIMEOUT);
	static status_t WaitForSubmit(uint32 *firstSignaled, SyncobjRef *syncobjs, uint64 *points, uint32 count, WaitFlags flags, bigtime_t timeout = B_INFINITE_TIMEOUT);

public:
	// external API
	Syncobj(CreateFlags flags = {});
	virtual ~Syncobj();

	status_t Reset();
	status_t Signal(uint64 point = 0);
	status_t Query(uint64 &point, QueryFlags flags = {});
	status_t Transfer(uint64 dstPoint, SyncobjRef srcSyncobj, uint64 srcPoint, WaitFlags flags = {});
	status_t Accumulate(SyncobjRef srcSyncobj, uint64 srcPoint);

	static status_t Wait(uint32 *firstSignaled, SyncobjRef *syncobjs, uint64 *points, uint32 count, WaitFlags flags = {}, bigtime_t timeout = B_INFINITE_TIMEOUT);

	// internal API
	status_t InsertFence(uint64 point, BReference<Fence> fence);
	BReference<Fence> LookupFence(uint64 point, WaitFlags flags = {});

	void OnAvail(Handler *handler, uint64 point);
	void OnAvailCancel(Handler *handler);

	void Dump();
};
