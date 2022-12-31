#pragma once

#include <map>
#include <ServerThreadLink.h>
#include "RadeonMemory.h"
#include "Syncobj.h"
#include "RingBuffer.h"
#include "CommandSubmission.h"
#include "ExternalAllocator.h"
#include "HandleTable.h"
#include "SADomains/Domains.h"

class TeamState;


class RadeonServerThreadLink final: public ServerThreadLink {
private:
	friend class TeamState;
	ExternalRef<TeamState> fTeamState;
	DoublyLinkedListLink<RadeonServerThreadLink> fLink;
	bool fAddedToList = false;
	bool fRemovedFromList = false;

public:
	RadeonServerThreadLink(port_id clientPort);
	virtual ~RadeonServerThreadLink();
	ExternalRef<TeamState> StateFor(team_id team);
	ExternalRef<TeamState> ThisState();

	void MessageReceived(int32 what) final;
};


class TeamState: public RefObject {
public:
	enum class HandleType {
		buffer,
		syncobj
	};

	struct Handle {
		HandleType type;
		BReference<BReferenceable> ref;
	};

private:
	union Flags {
		struct {
			uint32 finalized: 1;
			uint32 reacquired: 1;
			uint32 unused: 30;
		};
		uint32 val;
	};

	friend class RadeonServerThreadLink;
	friend struct CommandSubmission;
	team_id fTeam;
	DoublyLinkedList<RadeonServerThreadLink, DoublyLinkedListMemberGetLink<RadeonServerThreadLink, &RadeonServerThreadLink::fLink>> fThreadLinks;
	Flags fFlags {.val = 0};
	HandleTable<Handle> fHandles;
	BReference<AddressSpace> fAddressSpace;
	ExternalAllocator fVirtMemPool;
	std::map<uint32, CommandSubmission* > fCmdSubs;
	uint32 fCsSeq, fLastCsSeq;

public:
	TeamState(team_id team);
	virtual ~TeamState();
	void FirstReferenceAcquired() override;
	void LastReferenceReleased() override;
	inline team_id Team() const {return fTeam;}
	void Terminate();

	int32 RegisterHandle(const Handle &handleObj);
	status_t FreeHandle(int32 handle);
	Handle ThisHandle(int32 handle);
	BReferenceable *ThisHandle(int32 handle, HandleType type);

	int32 AllocBuffer(MemoryDomain domain, uint64 size, uint64 alignment = B_PAGE_SIZE, uint32 flags = 0, area_id area = -1, uint64 offset = 0);
	BReference<BufferObject> ThisBuffer(int32 handle);
	status_t Map(uint64 virtAdr, int32 handle, uint64 offset, uint64 size, uint32 flags);
	status_t Unmap(uint64 virtAdr, int32 handle, uint64 offset, uint64 size, uint32 flags);
	status_t CpuMap(void *&adr, int32 handle, uint64 offset, uint64 size, uint32 flags);
	status_t CpuUnmap(void *adr, int32 handle, uint64 offset, uint64 size, uint32 flags);

	int32 CreateSyncobj(Syncobj::CreateFlags flags);
	SyncobjRef ThisSyncobj(int32 handle);
	void DumpSyncobjs();

	status_t ScheduleCS(uint64 &handle, CommandSubmission *cs);
	status_t WaitCS(uint64 handle);
};

class TeamRoster: public Object {
private:
	friend class TeamState;
	std::map<team_id, ExternalPtr<TeamState> /* weak reference */ > fTeamStates;

public:
	ExternalRef<TeamState> ThisTeam(team_id team, bool create);
	int32 CountTeams();
	void ListTeams(bool (*Handler)(ExternalRef<TeamState> ts, void *arg), void *arg);
};

extern ExternalPtr<TeamRoster> gTeamRoster;
