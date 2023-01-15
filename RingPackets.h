#pragma once

#include <SupportDefs.h>


union GenFenceFlags {
	struct {
		uint32 is64Bit: 1;
		uint32 intr: 1;
		uint32 padding: 30;
	};
	uint32 val;
};
