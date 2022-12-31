#include "Atombios.h"
#include "Radeon.h"
#include "obsolete/evergreen_reg.h"
#include "obsolete/si_reg.h"

#include <stdio.h>


static void RegWrite(uint32 reg, uint32 val) {WriteReg4(4*reg, val);}
static uint32 RegRead(uint32 reg) {return ReadReg4(4*reg);}

card_info sCardInfo {
	.reg_write   = RegWrite,
	.reg_read    = RegRead,
	.ioreg_write = RegWrite,
	.ioreg_read  = RegRead,
	.mc_write    = WriteReg4,
	.mc_read     = ReadReg4,
	.pll_write   = WriteReg4,
	.pll_read    = ReadReg4
};


Atombios::Atombios()
{}

status_t Atombios::Init()
{
	fBiosArea.SetTo(clone_area("AtomBIOS", (void**)&fBios, B_ANY_ADDRESS, B_READ_AREA | B_WRITE_AREA, gDevice.SharedInfo()->rom_area));
	CheckRet(fBiosArea.Get());
	fContext.SetTo(atom_parse(&sCardInfo, fBios));
	if (!fContext.IsSet()) return B_ERROR;
	fContext->exec_sem = create_sem(1, "AtomBIOS_exec");
	CheckRet(fContext->exec_sem);
	atom_allocate_fb_scratch(fContext.Get());
	return B_OK;
}

bool Atombios::IsPosted()
{
	// aka, is primary graphics card that POST loaded

	radeon_shared_info &info = *gDevice.SharedInfo();
	uint32 reg;

	if (info.chipsetID == RADEON_PALM) {
		// palms
		reg = 
			ReadReg4(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC0_REGISTER_OFFSET) |
			ReadReg4(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC1_REGISTER_OFFSET);
		if ((reg & EVERGREEN_CRTC_MASTER_EN) != 0)
			return true;
	} else if (info.chipsetID >= RADEON_CEDAR) {
		// evergreen or higher
		reg =
			ReadReg4(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC0_REGISTER_OFFSET) |
			ReadReg4(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC1_REGISTER_OFFSET) |
			ReadReg4(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC2_REGISTER_OFFSET) |
			ReadReg4(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC3_REGISTER_OFFSET) |
			ReadReg4(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC4_REGISTER_OFFSET) |
			ReadReg4(EVERGREEN_CRTC_CONTROL + EVERGREEN_CRTC5_REGISTER_OFFSET);
		if ((reg & EVERGREEN_CRTC_MASTER_EN) != 0)
			return true;
	} else {
		fprintf(stderr, "GPUs earlier then Evergreen are unsupported\n");
		abort();
	}

	// also check memory size incase crt controlers are disabled
	reg = ReadReg4(SI_CONFIG_MEMSIZE);

	if (reg)
		return true;

	return false;
}
