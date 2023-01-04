#pragma once

#include <ServerThreadLink.h>


#define RADEON_GFX_SERVER_SIGNATURE "application/x-vnd.X512-RadeonGfx"

enum {
	// DRM
	radeonMmapMsg = userMsgBase,
	radeonMunmapMsg,
	radeonIoctlMsg,

	radeonListTeams,
	radeonListBuffers,
	radeonGetMemoryUsage,

	radeonThermalQuery,
	radeonSetClocks,
	// display
	radeonGetDisplayConsumer,
	radeonUpdateCursor,

	radeonBufferDup,
};

enum RadeonHandleType {
	radeonHandleBuffer,
	radeonHandleSyncobj,
};

void RadeonInitServer();
void RadeonRunServer();
