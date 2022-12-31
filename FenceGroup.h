#pragma once

#include "Fence.h"
#include <AutoDeleter.h>

class FenceGroup: public Fence {
public:
	struct CreateFlags {
		union {
			struct {
				uint32 all: 1;
			};
			uint32 val;
		};
	};
	struct Flags {
		union {
			struct {
				uint32 all: 1;
			};
			uint32 val;
		};
	};

private:
	struct GroupHandler: public Handler {
	public:
		FenceGroup *fGroup;
		BReference<Fence> fFence;
		uint32 fIdx;

		void Do(Fence *fence) override;
	};

	Flags fFlags;
	ArrayDeleter<GroupHandler> fHandlers;
	uint32 fCount, fRemainingCount;

public:
	FenceGroup(BReference<Fence> *fences, uint32 count, CreateFlags flags = {});
	virtual ~FenceGroup();

};
