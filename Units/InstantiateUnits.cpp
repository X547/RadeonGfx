#include "RadeonDevice.h"
#include <radeon_gfx.h>
#include "IhV1Unit.h"
#include "DmaV1Unit.h"
#include "GfxV6Unit.h"


status_t InstantiateUnits(RadeonDevice *dev)
{
	switch (dev->SharedInfo()->chipsetID) {
		case RADEON_CAPEVERDE:
		case RADEON_PITCAIRN:
		case RADEON_TAHITI:
		case RADEON_OLAND:
		case RADEON_HAINAN:
			//dev->InstallUnit(Gmc6UnitNew(dev));
			dev->InstallUnit(IhV1UnitNew(dev));
			dev->InstallUnit(DmaV1UnitNew(dev));
			dev->InstallUnit(GfxV6UnitNew(dev));
			//dev->InstallUnit(Dce6UnitNew(dev));
			return B_OK;
	}
	return B_NOT_SUPPORTED;
}
