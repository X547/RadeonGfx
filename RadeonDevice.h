#pragma once

#include <private/shared/AutoDeleterOS.h>
#include "SADomains/Domains.h"
#include "RadeonMemory.h"
#include "RadeonInfo.h"


enum section_id {
    SECT_NONE,
    SECT_CONTEXT,
    SECT_CLEAR,
    SECT_CTRLCONST
};

struct cs_extent_def {
    const uint32 *extent;
    const uint32 reg_index;
    const uint32 reg_count;
};

struct cs_section_def {
    const struct cs_extent_def *section;
    const enum section_id id;
};


struct radeon_shared_info;
class Atombios;
class DisplayRoster;
class MemoryManager;
class RadeonRingBuffer;
class RadeonRingBufferInt;
class RadeonUnit;


class RadeonDevice {
private:
	FileDescriptorCloser fFd;
	AreaDeleter fSharedArea;
	AreaDeleter fRegsArea;
	radeon_shared_info *fSharedInfo;
	uint8 *fRegs;

	DoublyLinkedList<RadeonUnit> fUnits;

	ObjectDeleter<Atombios> fAtombios;
	ExternalPtr<MemoryManager> fMemMgr;
	ExternalPtr<DisplayRoster> fDisplays;
	ExternalPtr<RadeonRingBuffer> fRings[8];
	ExternalPtr<RadeonRingBufferInt> fIntRing;

	status_t InitUnits();
	status_t FiniUnits();

public:
	struct Firmware {
		ArrayDeleter<uint8> data;
		off_t size;
	};

	struct {
		Firmware pfp;
		Firmware ce;
		Firmware me;
		Firmware mc;
		Firmware rlc;
	} fFirmwares;

	struct amdgpu_device fInfo{};

	struct {
		const uint32 *regList;
		uint32 regListLen;
		const struct cs_section_def *csData;
		MappedBuffer saveRestoreBuf;
		uint32 clearStateSize;
		MappedBuffer clearStateBuf;
	} fRlc;

	RadeonDevice();
	~RadeonDevice();
	status_t Init(int fd);

	radeon_shared_info *SharedInfo() {return fSharedInfo;}
	uint8 *Regs() {return fRegs;}

	void InstallUnit(RadeonUnit *unit);
	void InitRing(int ringId, ExternalPtr<RadeonRingBuffer> ring);

	Atombios &Atom() {return *fAtombios.Get();}
	ExternalPtr<MemoryManager> MemMgr() {return fMemMgr;}
	ExternalPtr<DisplayRoster> Displays() {return fDisplays;}
	ExternalPtr<RadeonRingBuffer> Rings(int ringId) {return fRings[ringId];}
	ExternalPtr<RadeonRingBufferInt> IntRing() {return fIntRing;}
};


extern RadeonDevice gDevice;
