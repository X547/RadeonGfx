#pragma once

#include <ServerThreadLink.h>
#include "TeamState.h"

void RadeonHandleDisplayMessage(BPrivate::PortLink &link, ExternalRef<TeamState> state, int32 what);
