/*
 * Copyright 2006-2011, Haiku, Inc. All Rights Reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Axel Dörfler, axeld@pinc-software.de
 *		Alexander von Gluck IV, kallisti5@unixzen.com
 */
#ifndef RADEON_GFX_H
#define RADEON_GFX_H


#include "radeon_gfx_lock.h"

#include <Accelerant.h>
#include <Drivers.h>
#include <edid.h>


#define VENDOR_ID_ATI	0x1002

// Card chipset flags
#define CHIP_STD		(1 << 0) // Standard chipset
#define CHIP_X2			(1 << 1) // Dual cpu
#define CHIP_IGP		(1 << 2) // IGP chipset
#define CHIP_MOBILE		(1 << 3) // Mobile chipset
#define CHIP_DISCREET	(1 << 4) // Discreet chipset
#define CHIP_APU		(1 << 5) // APU chipset

#define DEVICE_NAME				"radeon_gfx"
#define RADEON_ACCELERANT_NAME	"radeon_gfx.accelerant"

#define MAX_NAME_LENGTH		32

// Used to collect EDID from boot loader
#define EDID_BOOT_INFO "vesa_edid/v1"
#define MODES_BOOT_INFO "vesa_modes/v1"

#define RHD_POWER_ON       0
#define RHD_POWER_RESET    1   /* off temporarily */
#define RHD_POWER_SHUTDOWN 2   /* long term shutdown */
#define RHD_POWER_UNKNOWN  3   /* initial state */


// Radeon Chipsets
// !! Must match chipset names below
enum radeon_chipset {
	RADEON_R420 = 0,	//r400, Radeon X700-X850
	RADEON_R423,
	RADEON_RV410,
	RADEON_RS400,
	RADEON_RS480,
	RADEON_RS600,
	RADEON_RS690,
	RADEON_RS740,
	RADEON_RV515,
	RADEON_R520,		//r500, DCE 1.0
	RADEON_RV530,		// DCE 1.0
	RADEON_RV560,		// DCE 1.0
	RADEON_RV570,		// DCE 1.0
	RADEON_R580,		// DCE 1.0
	RADEON_R600,		//r600, DCE 2.0
	RADEON_RV610,		// DCE 2.0
	RADEON_RV630,		// DCE 2.0
	RADEON_RV670,		// DCE 2.0
	RADEON_RV620,		// DCE 3.0
	RADEON_RV635,		// DCE 3.0
	RADEON_RS780,		// DCE 3.0
	RADEON_RS880,		// DCE 3.0
	RADEON_RV770,		//r700, DCE 3.1
	RADEON_RV730,		// DCE 3.2
	RADEON_RV710,		// DCE 3.2
	RADEON_RV740,		// DCE 3.2
	RADEON_CEDAR,		//Evergreen, DCE 4.0
	RADEON_REDWOOD,		// DCE 4.0
	RADEON_JUNIPER,		// DCE 4.0
	RADEON_CYPRESS,		// DCE 4.0
	RADEON_HEMLOCK,		// DCE 4.0?
	RADEON_PALM,		//Fusion APU (NI), DCE 4.1
	RADEON_SUMO,		// DCE 4.1
	RADEON_SUMO2,		// DCE 4.1
	RADEON_CAICOS,		//Nothern Islands, DCE 5.0
	RADEON_TURKS,		// DCE 5.0
	RADEON_BARTS,		// DCE 5.0
	RADEON_CAYMAN,		// DCE 5.0
	RADEON_ANTILLES,	// DCE 5.0?
	RADEON_CAPEVERDE,	//Southern Islands, DCE 6.0
	RADEON_PITCAIRN,	// DCE 6.0
	RADEON_TAHITI,		// DCE 6.0
	RADEON_ARUBA,		// DCE 6.1 Trinity/Richland
	RADEON_OLAND,		// DCE 6.4
	RADEON_HAINAN,		// NO DCE, only compute
	RADEON_KAVERI,		//Sea Islands, DCE 8.1
	RADEON_BONAIRE,		// DCE 8.2
	RADEON_KABINI,		// DCE 8.3
	RADEON_MULLINS,		// DCE 8.3
	RADEON_HAWAII,		// DCE 8.5
	RADEON_TOPAZ,		//Volcanic Islands, NO DCE
	RADEON_TONGA,		// DCE 10.0
	RADEON_FIJI,		// DCE 10.1?
	RADEON_CARRIZO,		// DCE 11.0
	RADEON_STONEY,		// DCE 11.1?
	RADEON_POLARIS11,	//Artic Islands, DCE 12.1?
	RADEON_POLARIS10,	// DCE 12.0?
	RADEON_POLARIS12,	// DCE 12.2?
	RADEON_VEGAM,		// DCE 13.0?
	RADEON_VEGA10,		// DCE 13.0?
	RADEON_VEGA12,		// DCE 13.0?
	RADEON_VEGA20,		// DCE 13.0?
	RADEON_RAVEN,		// DCE 13?
	RADEON_NAVI,		// DCE 13.0?
};

// !! Must match chipset families above
static const char radeon_chip_name[][MAX_NAME_LENGTH] = {
	"R420",
	"R423",
	"RV410",
	"RS400",
	"RS480",
	"RS600",
	"RS690",
	"RS740",
	"RV515",
	"R520",
	"RV530",
	"RV560",
	"RV570",
	"R580",
	"R600",
	"RV610",
	"RV630",
	"RV670",
	"RV620",
	"RV635",
	"RS780",
	"RS880",
	"RV770",
	"RV730",
	"RV710",
	"RV740",
	"Cedar",
	"Redwood",
	"Juniper",
	"Cypress",
	"Hemlock",
	"Palm",
	"Sumo",
	"Sumo2",
	"Caicos",
	"Turks",
	"Barts",
	"Cayman",
	"Antilles",
	"Cape Verde",
	"Pitcairn",
	"Tahiti",
	"Aruba",
	"Oland",
	"Hainan",
	"Kaveri",
	"Bonaire",
	"Kabini",
	"Mullins",
	"Hawaii",
	"Topaz",
	"Tonga",
	"Fiji",
	"Carrizo",
	"Stoney Ridge",
	"Polaris 11",
	"Polaris 10",
	"Polaris 12",
	"Vega Mobile",
	"Vega 10",
	"Vega 12",
	"Vega 20",
	"Raven",
	"Navi",
};


struct ring_buffer {
	struct lock		lock;
	uint32			register_base;
	uint32			offset;
	uint32			size;
	uint32			position;
	uint32			space_left;
	uint8*			base;
};


struct overlay_registers;


struct radeon_shared_info {
	uint32			deviceIndex;		// accelerant index
	uint32			pciID;				// device pci id
	uint32			pciRev;				// device pci revision
	area_id			mode_list_area;		// area containing display mode list
	uint32			mode_count;

	bool			has_rom;			// was rom mapped?
	area_id			rom_area;			// area of mapped rom
	uint32			rom_phys;			// rom base location
	uint32			rom_size;			// rom size
	uint8*			rom;				// cloned, memory mapped PCI ROM

	display_mode	current_mode;
	uint32			bytes_per_row;
	uint32			bits_per_pixel;
	uint32			dpms_mode;

	area_id			registers_area;			// area of memory mapped registers
	uint8*			status_page;
	addr_t			physical_status_page;
	uint32			graphics_memory_size;

	uint8*			frame_buffer;			// virtual memory mapped FB
	area_id			frame_buffer_area;		// area of memory mapped FB
	addr_t			frame_buffer_phys;		// card PCI BAR address of FB
	uint32			frame_buffer_size;		// FB size mapped

	bool			has_edid;
	edid1_info		edid_info;

	struct lock		accelerant_lock;
	struct lock		engine_lock;

	ring_buffer		primary_ring_buffer;

	int32			overlay_channel_used;
	bool			overlay_active;
	uint32			overlay_token;
	addr_t			physical_overlay_registers;
	uint32			overlay_offset;

	bool			hardware_cursor_enabled;
	sem_id			vblank_sem;

	uint8*			cursor_memory;
	addr_t			physical_cursor_memory;
	uint32			cursor_buffer_offset;
	uint32			cursor_format;
	bool			cursor_visible;
	uint16			cursor_hot_x;
	uint16			cursor_hot_y;

	char			deviceName[MAX_NAME_LENGTH];
	uint16			chipsetID;
	char			chipsetName[MAX_NAME_LENGTH];
	uint32			chipsetFlags;
	uint8			dceMajor;
	uint8			dceMinor;

	uint16			color_data[3 * 256];    // colour lookup table
};

//----------------- ioctl() interface ----------------

// magic code for ioctls
#define RADEON_PRIVATE_DATA_MAGIC		'rdhd'

// list ioctls
enum {
	RADEON_GET_PRIVATE_DATA = B_DEVICE_OP_CODES_END + 1,

	RADEON_GET_DEVICE_NAME
};

// retrieve the area_id of the kernel/accelerant shared info
struct radeon_get_private_data {
	uint32	magic;				// magic number
	area_id	shared_info_area;
};

#endif	/* RADEON_GFX_H */
