#include "RadeonDevice.h"
#include <radeon_gfx.h>
#include "DmaV1Unit.h"
#include "GfxV6Unit.h"


status_t InstantiateUnits(RadeonDevice *dev)
{
	switch (dev->SharedInfo()->chipsetID) {
		case RADEON_CAPEVERDE:
			//dev->InstallUnit(Gmc6UnitNew(dev));
			//dev->InstallUnit(Ih1UnitNew(dev));
			dev->InstallUnit(DmaV1UnitNew(dev));
			dev->InstallUnit(GfxV6UnitNew(dev));
			//dev->InstallUnit(Dce6UnitNew(dev));
			return B_OK;
	}
	return B_NOT_SUPPORTED;
}
