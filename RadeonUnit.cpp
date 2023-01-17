#include "RadeonUnit.h"
#include "Radeon.h"


status_t RadeonUnit::InitSoftware2() {return B_OK;}
status_t RadeonUnit::FiniSoftware2() {return B_OK;}
status_t RadeonUnit::InitHardware2() {return B_OK;}
status_t RadeonUnit::FiniHardware2() {return B_OK;}


status_t RadeonUnit::InitHardware()
{
	if (fFlags.hardwareInit) return B_OK;
	printf("InitHardware(\"%s\")\n", GetInfo()->name);
	CheckRet(InitHardware2());
	fFlags.hardwareInit = true;
	return B_OK;
}

status_t RadeonUnit::FiniHardware()
{
	if (!fFlags.hardwareInit) return B_OK;
	printf("FiniHardware(\"%s\")\n", GetInfo()->name);
	CheckRet(FiniHardware2());
	fFlags.hardwareInit = false;
	return B_OK;
}

status_t RadeonUnit::InitSoftware()
{
	if (fFlags.softwareInit) return B_OK;
	printf("InitSoftware(\"%s\")\n", GetInfo()->name);
	CheckRet(InitSoftware2());
	fFlags.softwareInit = true;
	return B_OK;
}

status_t RadeonUnit::FiniSoftware()
{
	if (!fFlags.softwareInit) return B_OK;
	printf("FiniSoftware(\"%s\")\n", GetInfo()->name);
	CheckRet(FiniSoftware2());
	fFlags.softwareInit = false;
	return B_OK;
}
