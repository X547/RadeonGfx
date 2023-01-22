#include "Poke.h"
#include <errno.h>


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

status_t Poke::GetNthPciInfo(uint32 index, pci_info &info)
{
	if (index > UINT8_MAX) return ENOENT;
	pci_info_args args{
		.signature = POKE_SIGNATURE,
		.index = (uint8)index,
		.info = &info
	};
	status_t res = ioctl(fFd.Get(), POKE_GET_NTH_PCI_INFO, &args, sizeof(args));
	if (res < 0) return errno;
	return args.status;
}
