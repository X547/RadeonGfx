/*
 * Copyright 2006-2010, Haiku, Inc. All Rights Reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Axel Dörfler, axeld@pinc-software.de
 *		Clemens Zeidler, haiku@clemens-zeidler.de
 */
#ifndef RADEON_RD_PRIVATE_H
#define RADEON_RD_PRIVATE_H


#include <AGP.h>
#include <KernelExport.h>
#include <PCI.h>
#include <PCI_x86.h>

#include "radeon_gfx.h"
#include "lock.h"


// PCI Base Address Registers
#define PCI_BAR_FB      0

#define RADEON_BIOS8(adr, v) 	(adr[v])
#define RADEON_BIOS16(adr, v) 	((adr[v]) | (adr[(v) + 1] << 8))
#define RADEON_BIOS32(adr, v)	\
	((RADEON_BIOS16(adr, v) | RADEON_BIOS16(adr, v + 2) << 16))


struct radeon_info {
	int32			open_count;
	status_t		init_status;
	int32			id;
	pci_info*		pci;
	addr_t			registers;

	uint8*			atom_buffer;	// buffer for atombios

	area_id			registers_area;
	area_id			framebuffer_area;
	area_id			rom_area;

	struct radeon_shared_info* shared_info;
	area_id			shared_area;

	uint8			irq;
	bool			use_msi;

	uint32			pciID;
	const char*		deviceName;
	uint16			chipsetID;
	const char*		chipsetName;
	uint32			chipsetFlags;
	uint8			dceMajor;
	uint8			dceMinor;
};


extern status_t radeon_hd_init(radeon_info& info);
extern void radeon_hd_uninit(radeon_info& info);


#endif  /* RADEON_RD_PRIVATE_H */
