#pragma once

#include "TeamState.h"


int drmIoctlInt(ExternalPtr<TeamState> teamState, uint32_t request, void *arg);
