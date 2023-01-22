#pragma once

#include <AutoDeleter.h>
#include <AutoDeleterOS.h>
#include <private/drivers/poke.h>


class Poke {
private:
	FileDescriptorCloser fFd;

public:
	Poke();

	status_t GetPhysicalAddress(uint64 &physAdr, void* address, size_t size);
	status_t GetNthPciInfo(uint32 index, pci_info &info);
};


extern Poke gPoke;
