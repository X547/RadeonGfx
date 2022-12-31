#include "RadeonUnit.h"
#include "SADomains/Domains.h"

class RadeonRingBuffer;

class DmaUnit: public RadeonUnit {
public:
	using RadeonUnit::RadeonUnit;

	virtual ~DmaUnit() {}

	virtual uint32 RingCount() = 0;
	virtual ExternalPtr<RadeonRingBuffer> *Rings() = 0;
};
