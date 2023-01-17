#pragma once

#include <VideoConsumer.h>
#include <Accelerant.h>
#include "InterruptHandler.h"
#include "Syncobj.h"


class DisplayConsumer final: public VideoConsumer
{
private:
	uint32 fCrtcId;
	display_mode fDm;
	frame_buffer_config fFbc;
	uint32 fOrigGrphControl;
	uint64 fOrigGpuPhysAdr;
	ArrayDeleter<MappedBuffer> fBufs;
	ArrayDeleter<BReference<Syncobj>> fSyncobjs;

	class InterruptSource: public ::InterruptSource {
	public:
		DisplayConsumer &Base() {return ContainerOf(*this, &DisplayConsumer::fIntSource);}

		status_t Enable(bool doEnable) final;
		void InterruptReceived(InterruptPacket &pkt) final;
	} fIntSource;

	status_t SetupSwapChain(const SwapChainSpec& spec);
	status_t BindSwapChain();

public:
	DisplayConsumer(const char* name);
	virtual ~DisplayConsumer();
	status_t Init(uint32 crtcId, const display_mode &dm, const frame_buffer_config &fbc);

	void Connected(bool isActive) final;
	status_t SwapChainRequested(const SwapChainSpec& spec) final;
	void SwapChainChanged(bool isValid) final;
	void Present(int32 bufferId, const BRegion* dirty) final;
};
