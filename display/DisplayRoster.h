#pragma once

#include <Accelerant.h>
#include "SADomains/Domains.h"
#include "RadeonMemory.h"

class VideoConsumer;
class DisplayConsumer;


enum {
	cursorUpdateEnabled,
	cursorUpdatePos,
	cursorUpdateOrg,
	cursorUpdateBuffer,
	cursorUpdateFormat,
};

union CursorUpdateValid {
	struct {
		uint32 enabled: 1;
		uint32 pos: 1;
		uint32 org: 1;
		uint32 buffer: 1;
		uint32 format: 1;
	};
	uint32 val;
};

struct CursorUpdate {
	CursorUpdateValid valid;

	bool enabled;
	int32 x, y;
	int32 orgX, orgY;

	BReference<BufferObject> buffer;
	uint64 offset;

	int32 bytesPerRow;
	uint32 width, height;
	color_space colorSpace;
};


class RadeonDisplay {
private:
	friend class DisplayRoster;

	uint32 fCrtcId;
	uint32 fCrtcOfs;
	BReference<BufferObject> fBuffer;
	
	CursorUpdate fCursor;
	
	ObjectDeleter<VideoConsumer> fConsumer;

	status_t InitConsumer();

public:
	RadeonDisplay();

	status_t GetMode(display_mode &mode);
	status_t SetMode(const display_mode &mode);
	status_t SetFramebuffer(uint64 gpuAdr);

	status_t ValidateCursorFormat(CursorUpdate &update);
	status_t GetCursor(CursorUpdate &update);
	status_t UpdateCursor(const CursorUpdate &update);

	VideoConsumer *GetConsumer() {return fConsumer.Get();}
};


class DisplayRoster: public Object {
private:
	enum {
		maxCrtcCount = 6,
	};
	RadeonDisplay fDisplays[maxCrtcCount];

public:
	DisplayRoster();
	virtual ~DisplayRoster();
	status_t Init();

	status_t RegisterFramebuffers();

	uint32 CountDisplays();
	RadeonDisplay *DisplayAt(uint32 idx);
};
