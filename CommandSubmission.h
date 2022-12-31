#pragma once

#include <map>
#include "RadeonMemory.h"
#include "Syncobj.h"
#include "RingBuffer.h"
#include "ExternalAllocator.h"
#include "SADomains/Domains.h"


class TeamState;

struct IndirectBufferDef {
	BReference<BufferObject> buf;
	uint64 offset;
	uint64 va;
	uint64 vaRemapped;
	uint64 size;
};

struct CommandSubmission {

	struct WaitHandler: public Fence::Handler {
		inline CommandSubmission &Base() {return *(CommandSubmission*)((char*)this - offsetof(CommandSubmission, waitHandler));}
		void Do(Fence *fence) final;
	} waitHandler;

	struct FenceHandler: public Fence::Handler {
		inline CommandSubmission &Base() {return *(CommandSubmission*)((char*)this - offsetof(CommandSubmission, handler));}
		void Do(Fence *fence) final;
	} handler;

	struct FenceResolvedReq: public AsyncRequest {
		inline CommandSubmission &Base() {return *(CommandSubmission*)((char*)this - offsetof(CommandSubmission, fenceResolvedReq));}
		using AsyncRequest::AsyncRequest;
		virtual ~FenceResolvedReq() {}
		void Do(Object *ptr) final;
		void Resolved() final;
	} fenceResolvedReq;

	TeamState *teamState;
	uint32 seq;
	BReference<RingFence> fence;
	BReference<Fence> waitFenceGroup;

	// filled by client
	int32 ringId;
	uint32 bufferCnt = 0, indBufCnt = 0;
	uint32 waitCnt = 0, signalCnt = 0;
	ArrayDeleter<BReference<BufferObject>> buffers;
	ArrayDeleter<IndirectBufferDef> indBufs;
	ArrayDeleter<SyncobjRef> waitSyncobjs, signalSyncobjs;
	ArrayDeleter<uint64> waitPoints, signalPoints;
	struct {
		BReference<BufferObject> buffer;
		uint64 offset;
	} userFence;

	CommandSubmission(TeamState *teamState);
	~CommandSubmission();

	status_t Schedule();
	status_t Remap();
};
