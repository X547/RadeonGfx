#pragma once

#include <ServerThreadLink.h>
#include "TeamState.h"

void RadeonHandleDrmMessage(BPrivate::PortLink &link, ExternalRef<TeamState> state, int32 what);
