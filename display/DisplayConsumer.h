#pragma once

#include <VideoConsumer.h>
#include <Accelerant.h>
#include "RadeonInterrupts.h"


class DisplayConsumer final: public VideoConsumer
{
private:
	uint32 fCrtcId;
	display_mode fDm;
	frame_buffer_config fFbc;
	uint32 fOrigGrphControl;
	uint64 fOrigGpuPhysAdr;
	ArrayDeleter<MappedBuffer> fBufs;

	status_t SetupSwapChain(const SwapChainSpec& spec);
	status_t BindSwapChain();

	void IrqHandler(InterruptPacket &pkt);

public:
	DisplayConsumer(const char* name);
	virtual ~DisplayConsumer();
	status_t Init(uint32 crtcId, const display_mode &dm, const frame_buffer_config &fbc);

	void Connected(bool isActive) final;
	status_t SwapChainRequested(const SwapChainSpec& spec) final;
	void SwapChainChanged(bool isValid) final;
	void Present(int32 bufferId, const BRegion* dirty) final;
};
