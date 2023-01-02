#include "Poke.h"
#include <errno.h>
#include <private/drivers/poke.h>


Poke gPoke;


Poke::Poke(): fFd(open("/dev/misc/poke", B_READ_WRITE))
{
	if (!fFd.IsSet()) abort();
}

status_t Poke::GetPhysicalAddress(uint64 &physAdr, void* address, size_t size)
{
	mem_map_args args{
		.signature = POKE_SIGNATURE,
		.size = size,
		.address = address
	};
	status_t res = ioctl(fFd.Get(), POKE_GET_PHYSICAL_ADDRESS, &args, sizeof(args));
	if (res < 0) return errno;
	physAdr = (uint64)args.physical_address;
	return res;
}
