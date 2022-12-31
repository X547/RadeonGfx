#pragma once

#include <ServerThreadLink.h>


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
