#pragma once

#include <OS.h>
#include <Referenceable.h>
#include <private/kernel/util/DoublyLinkedList.h>
#include "Locks/Mutex.h"
#include "Locks/RecursiveLock.h"
#include "Locks/ConditionVariable.h"
#include "SADomains/Domains.h"


class Fence: public BReferenceable
{
public:
	union Flags {
		struct {
			uint32 signaled: 1;
		};
		uint32 val;
	};
	union WaitFlags {
		struct {
			uint32 absoluteTimeout: 1;
			uint32 all: 1;
			uint32 domain: 1;
		};
		uint32 val;
	};

private:
	uint64 fSeq;
	Flags fFlags = {};

protected:
	RecursiveLock fLock;

public:
	class Handler: public DoublyLinkedListLinkImpl<Handler> {
	public:
		virtual void Do(Fence *fence) = 0;
	};

	template<typename DoFn>
	class HandlerTemplate: public Handler {
	private:
		DoFn fDoFn;
	public:
		HandlerTemplate(DoFn &&doFn): fDoFn(doFn) {}
		void Do(Fence *fence) override {fDoFn(fence);}
	};

private:
	DoublyLinkedList<Handler> fHandlers;

public:
	Fence(uint64 seq = 0): fSeq(seq) {}
	virtual ~Fence() {}

	void Signal();
	void OnSignal(Handler *handler);
	void OnSignalCancel(Handler *handler);
	status_t WaitNonDomain(uint32 flags = 0, bigtime_t timeout = B_INFINITE_TIMEOUT);
	status_t Wait(uint32 flags = 0, bigtime_t timeout = B_INFINITE_TIMEOUT);
	static status_t WaitMultiple(uint32 *firstSignaled, BReference<Fence> *fences, uint32 count, WaitFlags flags = {}, bigtime_t timeout = B_INFINITE_TIMEOUT);

	uint64 Seq() {return fSeq;}
	void SetSeq(uint64 seq) {fSeq = seq;}
	bool IsSignaled() {return fFlags.signaled;}
};


class SignaledFence: public Fence
{
private:
	SignaledFence();
	virtual ~SignaledFence() {}

public:
	static BReference<SignaledFence> Instance();
};


struct WaitInfoBase {
	RecursiveLock lock;
	ConditionVariable cond;
	Request *req = NULL;
	uint32 *firstSignaled;
	uint32 remainingCount;
	Fence::WaitFlags flags;
	bigtime_t timeout = B_INFINITE_TIMEOUT;

	~WaitInfoBase();

	void Init();
	status_t Wait();
	void Resolved(uint32 idx);
};
