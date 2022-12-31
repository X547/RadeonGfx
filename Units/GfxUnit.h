#include "RadeonUnit.h"
#include "RingBuffer.h"

class GfxUnit: public RadeonUnit {
public:
	using RadeonUnit::RadeonUnit;

	virtual uint32 GfxRingCount() = 0;
	virtual ExternalPtr<RadeonRingBuffer> *GfxRings() = 0;
	virtual uint32 ComputeRingCount() = 0;
	virtual ExternalPtr<RadeonRingBuffer> *ComputeRings() = 0;
};
