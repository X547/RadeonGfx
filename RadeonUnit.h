#pragma once

#include <SupportDefs.h>
#include <private/kernel/util/DoublyLinkedList.h>

class RadeonDevice;

enum class UnitFlag {
	softwareInit,
	hardwareInit,
};

enum class UnitType {
	common,
	gmc,
	ih,
	smc,
	psp,
	dce,
	gfx,
	sdma,
	uvd,
	vce,
	acp,
	vcn,
	mes,
	jpeg,
	num,
};

struct UnitInfo {
	UnitType type;
	struct {
		uint32 major, minor, rev;
	} version;
	const char *name;
};

class RadeonUnit: public DoublyLinkedListLinkImpl<RadeonUnit> {
private:
	friend class RadeonDevice;
	RadeonDevice *fDevice;
	uint32 fFlags;

protected:
	virtual status_t InitHardware2();
	virtual status_t FiniHardware2();
	virtual status_t InitSoftware2();
	virtual status_t FiniSoftware2();

public:
	RadeonUnit(RadeonDevice *device): fDevice(device), fFlags(0) {}
	virtual ~RadeonUnit() {}
	virtual const UnitInfo *GetInfo() = 0;

	status_t InitHardware();
	status_t FiniHardware();
	status_t InitSoftware();
	status_t FiniSoftware();

	inline RadeonDevice *Device() {return fDevice;}
	inline uint32 Flags() {return fFlags;}
};
