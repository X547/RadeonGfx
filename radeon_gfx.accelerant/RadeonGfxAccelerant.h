#pragma once

#include "AccelerantRoster.h"
#include <Messenger.h>
#include <AutoDeleterPosix.h>


class RadeonGfxAccelerant: public Accelerant, public AccelerantDrm, public AccelerantDisplay {
private:
	FileDescriptorCloser fFd;
	BMessenger fServerMsgr;

public:
	RadeonGfxAccelerant(int fd);
	virtual ~RadeonGfxAccelerant() = default;
	status_t InitCheck();

	void *DrmMmap(void *addr, size_t length, int prot, int flags, off_t offset) final;
	int DrmIoctl(unsigned long request, void *arg) final;

	status_t DisplayGetConsumer(int32 crtc, BMessenger &consumer) final;
	status_t DisplayUpdateCursor(int32 crtc, const CursorUpdateInfo &info) final;
};


extern "C" {

status_t _EXPORT instantiate_accelerant(Accelerant **acc, int fd);

};
