#pragma once

#include <SupportDefs.h>
#include <private/kernel/util/DoublyLinkedList.h>

class RadeonDevice;

union UnitFlags {
	struct {
		uint32 softwareInit: 1;
		uint32 hardwareInit: 1;
		uint32 padding: 30;
	};
	uint32 val;
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
	UnitFlags fFlags {};

protected:
	virtual status_t InitSoftware2();
	virtual status_t FiniSoftware2();
	virtual status_t InitHardware2();
	virtual status_t FiniHardware2();

public:
	RadeonUnit(RadeonDevice *device): fDevice(device) {}
	virtual ~RadeonUnit() {}
	virtual const UnitInfo *GetInfo() = 0;

	status_t InitSoftware();
	status_t FiniSoftware();
	status_t InitHardware();
	status_t FiniHardware();

	inline RadeonDevice *Device() {return fDevice;}
	inline UnitFlags Flags() {return fFlags;}
};
