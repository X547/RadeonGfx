#pragma once

#include "TeamState.h"


int drmIoctlInt(ExternalPtr<TeamState> teamState, unsigned long request, void *arg);
