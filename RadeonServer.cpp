#include "RadeonServer.h"
#include "RadeonServerDrm.h"
#include "RadeonServerDisplay.h"
#include "TeamState.h"
#include "RadeonPower.h"
#include <ServerThreadLink.h>

#include <Application.h>
#include <Messenger.h>
#include <MessengerPrivate.h>
#include <system_info.h>

#include <stdio.h>

#define CheckLink(err) {status_t _err = (err); if (_err < B_OK) {Link().StartMessage(_err); Link().Flush(); return;}}


//#pragma mark - RadeonServerThreadLink

void RadeonServerThreadLink::MessageReceived(int32 what)
{
	switch (what) {
		case radeonMmapMsg:
		case radeonIoctlMsg:
			return RadeonHandleDrmMessage(Link(), ThisState(), what);
		case radeonListTeams: {
			Link().StartMessage(B_OK);
			{
				auto teamRoster = gTeamRoster.Switch();
				Link().Attach<int32>(teamRoster->CountTeams());
				teamRoster->ListTeams([](ExternalRef<TeamState> ts, void *arg) -> bool {
					((RadeonServerThreadLink*)arg)->Link().Attach<int32>(ts.Switch()->Team());
					return true;
				}, this);
			}
			Link().Flush();
			return;
		}
		case radeonListBuffers: {
			CheckLink(B_BAD_VALUE);
#if 0
			int32 team;
			Link().Read(&team);
			ExternalRef<TeamState> stateExt = StateFor(team);
			if (stateExt == NULL) CheckLink(B_ERROR);
			Link().StartMessage(B_OK);
			if (auto state = stateExt.Switch()) {
				Link().Attach<int32>(state->fBufferHandles.Handles().size());
				for (auto it = state->fBufferHandles.Handles().begin(); it != state->fBufferHandles.Handles().end(); it++) {
					int32 handle = it->first;
					BReference<BufferObject> buf = it->second;
					Link().Attach<int32>(handle);
					Link().Attach<int32>(buf->domain);
					Link().Attach<uint64>(buf->gpuPhysAdr);
					Link().Attach<uint64>(buf->size);
				}
			}
			Link().Flush();
#endif
			return;
		}
		case radeonGetMemoryUsage: {
			Link().StartMessage(B_OK);
			Link().Attach<uint32>(boDomainGtt + 1 - boDomainVram);
			for (int32 i = boDomainVram; i <= boDomainGtt; i++) {
				uint64 total, alloc;
				Link().Attach<int32>(i);
				gDevice.MemMgr().Switch()->GetUsage(total, alloc, (MemoryDomain)i);
				Link().Attach<uint64>(total);
				Link().Attach<uint64>(alloc);
			}
			Link().Flush();
			return;
		}

		case radeonThermalQuery: {
			Link().StartMessage(B_OK);
			Link().Attach<int32>(radeon_thermal_query());
			Link().Flush();
			return;
		}

		case radeonSetClocks: {
			uint32 valid;
			uint32 engineClock, memoryClock;
			Link().Read(&valid);
			if ((1 << 0) & valid) {
				Link().Read(&engineClock);
				switch (engineClock) {
				case 30000:
				case 80000: break;
				default: CheckLink(B_BAD_VALUE);
				}
			}
			if ((1 << 1) & valid) {
				Link().Read(&memoryClock);
				switch (memoryClock) {
				case 15000:
				case 112500: break;
				default: CheckLink(B_BAD_VALUE);
				}
			}
			if ((1 << 0) & valid) radeon_gpu_set_engine_clock(engineClock);
			if ((1 << 1) & valid) radeon_gpu_set_memory_clock(memoryClock);
			Link().StartMessage(B_OK);
			Link().Attach<uint32>(radeon_gpu_get_engine_clock());
			Link().Attach<uint32>(radeon_gpu_get_memory_clock());
			Link().Flush();
			return;
		}

		case radeonGetDisplayConsumer:
		case radeonUpdateCursor:
			return RadeonHandleDisplayMessage(Link(), ThisState(), what);

		case radeonBufferDup: {
			uint32_t dstHandle;
			uint32_t srcHandle;
			RadeonHandleType handleType;
			team_id dstTeam;
			team_id srcTeam;
			Link().Read(&srcHandle);
			Link().Read(&handleType);
			Link().Read(&dstTeam);
			CheckLink(Link().Read(&srcTeam));

			if (dstTeam == B_CURRENT_TEAM) dstTeam = ClientTeam();
			if (srcTeam == B_CURRENT_TEAM) srcTeam = ClientTeam();

			ExternalRef<TeamState> dstTeamState = StateFor(dstTeam);
			if (!dstTeamState.IsSet()) CheckLink(ENOENT);
			ExternalRef<TeamState> srcTeamState = StateFor(srcTeam);
			if (!srcTeamState.IsSet()) CheckLink(ENOENT);

			TeamState::Handle srcObj = srcTeamState.Switch()->ThisHandle(srcHandle);
			if (!srcObj.ref.IsSet()) CheckLink(ENOENT);
			dstHandle = dstTeamState.Switch()->RegisterHandle(srcObj);

			Link().StartMessage(B_OK);
			Link().Attach<uint32_t>(dstHandle);
			Link().Flush();
			return;
		}
	}
	return ServerThreadLink::MessageReceived(what);
}


//#pragma mark - RadeonServer

class RadeonServer: public BApplication
{
public:
	RadeonServer();
	virtual ~RadeonServer();

	void MessageReceived(BMessage *msg) override;
};


RadeonServer::RadeonServer(): BApplication(RADEON_GFX_SERVER_SIGNATURE)
{
	BMessenger msgr(this);
	__start_watching_system(-1,
		B_WATCH_SYSTEM_TEAM_DELETION,
		BMessenger::Private(msgr).Port(), BMessenger::Private(msgr).Token()
	);
}

RadeonServer::~RadeonServer()
{}


void RadeonServer::MessageReceived(BMessage *msg)
{
	switch (msg->what) {
		case connectMsg: {
			port_id clientPort = -1;
			msg->FindInt32("port", &clientPort);
			new RadeonServerThreadLink(clientPort);
			return;
		}
		case B_SYSTEM_OBJECT_UPDATE: {
			int32 opcode;
			team_id team;
			msg->FindInt32("opcode", &opcode);
			msg->FindInt32("team", &team);
			switch (opcode) {
				case B_TEAM_DELETED: {
					ExternalRef<TeamState> teamState = gTeamRoster.Switch()->ThisTeam(team, false);
					BReference<Domain> dom = teamState.GetDomain();
					if (!teamState.IsSet()) return;
					printf("B_TEAM_DELETED(%" B_PRId32 ")\n", team);
					teamState.Switch()->Terminate();
					return;
				}
				default:;
			}
			return;
		}
	}
	BApplication::MessageReceived(msg);
}


void RadeonInitServer()
{
	new RadeonServer();
}

void RadeonRunServer()
{
	be_app->Run();
}
