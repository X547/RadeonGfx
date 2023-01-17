#pragma once

#include <SupportDefs.h>
#include <AutoDeleter.h>
#include "RadeonMemory.h"
#include "SADomains/Domains.h"

enum {
	intSrcIdProtFault  = 146,
	intSrcIdProtFault2 = 147, // ?
	intSrcIdRingGfx    = 176,
	intSrcIdRingCp1    = 177,
	intSrcIdRingCp2    = 178,
	intSrcIdCpEop      = 181,
	intSrcIdRingDma0   = 224,
	intSrcIdGuiIdle    = 233,
	intSrcIdRingDma1   = 244,
};

struct InterruptPacket {
	uint32 clientId;
	uint32 srcId;
	uint32 srcData;
	uint32 ringId;
	uint32 vmId;
};

class InterruptSource {
public:
	virtual ~InterruptSource() = default;

	virtual status_t Enable(bool doEnable) = 0;
	virtual void InterruptReceived(InterruptPacket &pkt) = 0;
};


class InterruptHandler: public Object {
public:
	enum {
		srcIdCnt = 256,
	};

private:
	struct HandlerEntry {
		InterruptSource *handler;
	};

private:
	HandlerEntry fHandlers[srcIdCnt];

	thread_id fThread;
	bool fRun;

private:
	status_t ThreadEntry();
	bool Handle();

protected:
	MappedBuffer fBuffer;
	bool fEnabled;
	uint32 fRptr, fWptr;
	vuint32 *fWptrAdr;
	uint64 fWptrGpuAdr;

protected:
	virtual uint32 Rptr() = 0;
	virtual uint32 Wptr() = 0;
	virtual void SetRptr() = 0;
	virtual void ReadPacket(InterruptPacket &pkt) = 0;

protected:
	status_t Init(uint64 size);
	void Fini();
	void Read(uint32 &val);

public:
	InterruptHandler();
	virtual ~InterruptHandler();

	void InstallHandler(uint32 clientId, uint32 srcId, InterruptSource *handler);
	void UninstallHandler(uint32 clientId, uint32 srcId);
};
