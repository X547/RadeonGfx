#include "RadeonServerDisplay.h"
#include "RadeonServer.h"
#include "DisplayRoster.h"

#include <stdio.h>
#include <string.h>

#define CheckLink(err) {status_t _err = (err); if (_err < B_OK) {link.StartMessage(_err); link.Flush(); return;}}


void RadeonHandleDisplayMessage(BPrivate::PortLink &link, ExternalRef<TeamState> state, int32 what)
{
	switch (what) {
		case radeonGetDisplayConsumer: {
			int32 crtc;
			link.Read(&crtc);
			auto displayRoster = gDevice.Displays().Switch();
			auto display = displayRoster->DisplayAt(crtc);
			if (display == NULL) CheckLink(B_ERROR);
			link.StartMessage(B_OK);
			link.Attach(BMessenger((const BHandler*)display->GetConsumer()));
			link.Flush();
			return;
		}
		case radeonUpdateCursor: {
			printf("radeonUpdateCursor\n");
			int32 crtc;
			CursorUpdate cursor;
			int32 origBytesPerRow = 0;
			link.Read(&crtc);
			link.Read(&cursor.valid.val);
			if (cursor.valid.enabled) {
				link.Read(&cursor.enabled);
				printf("  enabled: %d\n", cursor.enabled);
			}
			if (cursor.valid.pos) {
				link.Read(&cursor.x);
				link.Read(&cursor.y);
				printf("  x: %" B_PRId32 "\n", cursor.x);
				printf("  y: %" B_PRId32 "\n", cursor.y);
			}
			if (cursor.valid.org) {
				link.Read(&cursor.orgX);
				link.Read(&cursor.orgY);
				printf("  orgX: %" B_PRId32 "\n", cursor.orgX);
				printf("  orgY: %" B_PRId32 "\n", cursor.orgY);
			}
			if (cursor.valid.format) {
				link.Read(&cursor.bytesPerRow);
				link.Read(&cursor.width);
				link.Read(&cursor.height);
				link.Read((int32*)&cursor.colorSpace);
				origBytesPerRow = cursor.bytesPerRow;
				printf("  bytesPerRow: %" B_PRId32 "\n", cursor.bytesPerRow);
				printf("  width: %" B_PRIu32 "\n", cursor.width);
				printf("  height: %" B_PRIu32 "\n", cursor.height);
				printf("  colorSpace: %" B_PRId32 "\n", (int32)cursor.colorSpace);
			}

			ArrayDeleter<uint8> data;
			if (cursor.valid.format) {
				if (!cursor.valid.buffer) CheckLink(B_ERROR);
				printf("  data\n");
				size_t size = cursor.bytesPerRow*cursor.height;
				data.SetTo(new uint8[size]);
				link.Read(&data[0], size);
			}

			auto displayRoster = gDevice.Displays().Switch();
			auto display = displayRoster->DisplayAt(crtc);
			if (display == NULL) CheckLink(B_ERROR);

			if (cursor.valid.format) {
				CheckLink(display->ValidateCursorFormat(cursor));
				cursor.buffer = gDevice.MemMgr().Switch()->Alloc(boDomainVramMappable, cursor.bytesPerRow*cursor.height);
				cursor.offset = 0;
				MappedBuffer mappedBuf(cursor.buffer);
				for (uint32 y = 0; y < cursor.height; y++) {
					uint8 *dstLine = (uint8*)mappedBuf.adr + y*cursor.bytesPerRow;
					uint8 *srcLine = (uint8*)&data[0] + y*origBytesPerRow;
					memcpy(dstLine, srcLine, origBytesPerRow);
				}
			}
			CheckLink(display->UpdateCursor(cursor));
			link.StartMessage(B_OK);
			link.Flush();
			return;
		}
	};
}
