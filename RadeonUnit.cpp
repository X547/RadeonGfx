#include "RadeonUnit.h"
#include "Radeon.h"


status_t RadeonUnit::InitHardware2() {return ENOSYS;}
status_t RadeonUnit::FiniHardware2() {return ENOSYS;}
status_t RadeonUnit::InitSoftware2() {return ENOSYS;}
status_t RadeonUnit::FiniSoftware2() {return ENOSYS;}


status_t RadeonUnit::InitHardware()
{
	if (fFlags & (1 << (uint32)UnitFlag::hardwareInit)) {
		return B_OK;
	}
	status_t res = InitHardware2();
	if (res != ENOSYS) CheckRet(res);
	fFlags |= 1 << (uint32)UnitFlag::hardwareInit;
	return B_OK;
}

status_t RadeonUnit::FiniHardware()
{
	if (!(fFlags & (1 << (uint32)UnitFlag::hardwareInit))) {
		return B_OK;
	}
	status_t res = FiniHardware2();
	if (res != ENOSYS) CheckRet(res);
	fFlags &= ~(1 << (uint32)UnitFlag::hardwareInit);
	return B_OK;
}

status_t RadeonUnit::InitSoftware()
{
	if (fFlags & (1 << (uint32)UnitFlag::softwareInit)) {
		return B_OK;
	}
	status_t res = InitSoftware2();
	if (res != ENOSYS) CheckRet(res);
	fFlags |= 1 << (uint32)UnitFlag::softwareInit;
	return B_OK;
}

status_t RadeonUnit::FiniSoftware()
{
	if (!(fFlags & (1 << (uint32)UnitFlag::softwareInit))) {
		return B_OK;
	}
	status_t res = FiniSoftware2();
	if (res != ENOSYS) CheckRet(res);
	fFlags &= ~(1 << (uint32)UnitFlag::softwareInit);
	return B_OK;
}
