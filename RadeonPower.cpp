#include "RadeonPower.h"
#include "Radeon.h"
#include <RadeonDevice.h>
#include "Atombios.h"
#include "obsolete/r600_reg.h"
#include "obsolete/evergreen_reg.h"
#include "obsolete/si_reg.h"
#include "obsolete/r700_reg.h"


uint32 radeon_gpu_get_engine_clock()
{
	GET_ENGINE_CLOCK_PS_ALLOCATION args{0};
	int index = GetIndexIntoMasterTable(COMMAND, GetEngineClock);
	atom_execute_table(gDevice.Atom().Context(), index, (uint32*)&args);
	return args.ulReturnEngineClock;
}

uint32 radeon_gpu_get_memory_clock()
{
	GET_MEMORY_CLOCK_PS_ALLOCATION args{0};
	int index = GetIndexIntoMasterTable(COMMAND, GetMemoryClock);
	atom_execute_table(gDevice.Atom().Context(), index, (uint32*)&args);
	return args.ulReturnMemoryClock;
}

void radeon_gpu_set_engine_clock(uint32 value)
{
	SET_ENGINE_CLOCK_PS_ALLOCATION args{
		.ulTargetEngineClock = value
	};
	int index = GetIndexIntoMasterTable(COMMAND, SetEngineClock);
	atom_execute_table(gDevice.Atom().Context(), index, (uint32*)&args);
}

void radeon_gpu_set_memory_clock(uint32 value)
{
	SET_MEMORY_CLOCK_PS_ALLOCATION args{
		.ulTargetMemoryClock = value
	};
	int index = GetIndexIntoMasterTable(COMMAND, SetMemoryClock);
	atom_execute_table(gDevice.Atom().Context(), index, (uint32*)&args);
}


int32 radeon_thermal_query()
{
	// return GPU temp in millidegrees C

	auto &info = *gDevice.SharedInfo();

	uint32 rawTemp = 0;
	int32 finalTemp = 0;

	if (info.chipsetID >= RADEON_CAPEVERDE) {
		rawTemp = (ReadReg4(SI_CG_MULT_THERMAL_STATUS)
			& SI_CTF_TEMP_MASK) >> SI_CTF_TEMP_SHIFT;

		if (rawTemp & 0x200)
			finalTemp = 255;
		else
			finalTemp = rawTemp & 0x1ff;

		return finalTemp * 1000;
	} else if (info.chipsetID == RADEON_JUNIPER) {
		uint32 offset = (ReadReg4(EVERGREEN_CG_THERMAL_CTRL)
			& EVERGREEN_TOFFSET_MASK) >> EVERGREEN_TOFFSET_SHIFT;
		rawTemp = (ReadReg4(EVERGREEN_CG_TS0_STATUS)
			& EVERGREEN_TS0_ADC_DOUT_MASK) >> EVERGREEN_TS0_ADC_DOUT_SHIFT;

		if (offset & 0x100)
			finalTemp = rawTemp / 2 - (0x200 - offset);
		else
			finalTemp = rawTemp / 2 + offset;

		return finalTemp * 1000;
	} else if (info.chipsetID == RADEON_SUMO
		|| info.chipsetID == RADEON_SUMO2) {
		uint32 rawTemp = ReadReg4(EVERGREEN_CG_THERMAL_STATUS)
			& 0xff;
		finalTemp = rawTemp - 49;

		return finalTemp * 1000;
	} else if (info.chipsetID >= RADEON_CEDAR) {
		rawTemp = (ReadReg4(EVERGREEN_CG_MULT_THERMAL_STATUS)
			& EVERGREEN_ASIC_T_MASK) >> EVERGREEN_ASIC_T_SHIFT;

		if (rawTemp & 0x400)
			finalTemp = -256;
		else if (rawTemp & 0x200)
			finalTemp = 255;
		else if (rawTemp & 0x100) {
			finalTemp = rawTemp & 0x1ff;
			finalTemp |= ~0x1ff;
		} else
			finalTemp = rawTemp & 0xff;

		return (finalTemp * 1000) / 2;
	} else if (info.chipsetID >= RADEON_RV770) {
		rawTemp = (ReadReg4(R700_CG_MULT_THERMAL_STATUS)
			& R700_ASIC_T_MASK) >> R700_ASIC_T_SHIFT;
		if (rawTemp & 0x400)
			finalTemp = -256;
		else if (rawTemp & 0x200)
			finalTemp = 255;
		else if (rawTemp & 0x100) {
			finalTemp = rawTemp & 0x1ff;
			finalTemp |= ~0x1ff;
		} else
			finalTemp = rawTemp & 0xff;

		return (finalTemp * 1000) / 2;
	} else if (info.chipsetID >= RADEON_R600) {
		rawTemp = (ReadReg4(R600_CG_THERMAL_STATUS)
			& R600_ASIC_T_MASK) >> R600_ASIC_T_SHIFT;
		finalTemp = rawTemp & 0xff;

		if (rawTemp & 0x100)
			finalTemp -= 256;

		return finalTemp * 1000;
	}

	return -1;
}

