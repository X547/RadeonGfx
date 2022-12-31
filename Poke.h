#pragma once

#include <AutoDeleter.h>
#include <AutoDeleterOS.h>


class Poke {
private:
	FileDescriptorCloser fFd;

public:
	Poke();

	status_t GetPhysicalAddress(uint64 &physAdr, void* address, size_t size);
};


extern Poke gPoke;
