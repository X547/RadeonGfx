#include "TeamState.h"
#include "RadeonDevice.h"
#include <stdio.h>


ExternalPtr<TeamRoster> gTeamRoster = MakeExternal<TeamRoster>();


//#pragma mark - RadeonServerThreadLink

RadeonServerThreadLink::RadeonServerThreadLink(port_id clientPort):
	ServerThreadLink(clientPort)
{
	fTeamState = gTeamRoster.Switch()->ThisTeam(ClientTeam(), true);
	auto teamStateLocked = fTeamState.Switch();
	teamStateLocked->fThreadLinks.Insert(this);
	fAddedToList = true;
	InitCompleted();
}

RadeonServerThreadLink::~RadeonServerThreadLink()
{
	printf("-RadeonServerThreadLink, team: %" B_PRId32 "\n", ClientTeam());
	ExternalRef<TeamState> teamState = fTeamState;
	if (!teamState.IsSet()) {
		printf("[!] ~RadeonServerThreadLink(): fTeamState == NULL\n");
		return;
	}
	auto teamStateLocked = teamState.Switch();
	if (!fRemovedFromList) {
		teamStateLocked->fThreadLinks.Remove(this);
		fRemovedFromList = true;
	}
}

ExternalRef<TeamState> RadeonServerThreadLink::StateFor(team_id team)
{
	return gTeamRoster.Switch()->ThisTeam(team, false);
}

ExternalRef<TeamState> RadeonServerThreadLink::ThisState()
{
	return StateFor(ClientTeam());
}


//#pragma mark - TeamState

TeamState::TeamState(team_id team):
	fTeam(team),
	fAddressSpace(new AddressSpace(), true),
	fCsSeq(0),
	fLastCsSeq(0)
{
	printf("+TeamState(%" B_PRId32 ")\n", fTeam);
	fVirtMemPool.Register(0, 0x200000);
}

TeamState::~TeamState()
{
	printf("-TeamState(%" B_PRId32 ")\n", fTeam);
}

void TeamState::FirstReferenceAcquired()
{
	atomic_or((int32*)&fFlags.val, Flags{.reacquired = true}.val);
}

void TeamState::LastReferenceReleased()
{
	Flags oldFlags {.val = atomic_or((int32*)&fFlags.val, Flags{.finalized = true}.val)};
	auto teamRoster = gTeamRoster.Switch();
	if (!oldFlags.finalized) {
		auto it = teamRoster->fTeamStates.find(fTeam);
		if (it == teamRoster->fTeamStates.end()) abort();
		teamRoster->fTeamStates.erase(it);
	}

	oldFlags.val = atomic_and((int32*)&fFlags.val, ~Flags{.reacquired = true}.val);
	if (!oldFlags.reacquired) {
		RefObject::LastReferenceReleased();
	}
}

void TeamState::Terminate()
{
	for (;;) {
		RadeonServerThreadLink *threadLink = fThreadLinks.First();
		if (threadLink == NULL) break;
		threadLink->fRemovedFromList = true;
		fThreadLinks.Remove(threadLink);
		threadLink->Close();
	}
}

int32 TeamState::RegisterHandle(const Handle &handleObj)
{
	return fHandles.Register(handleObj);
}

status_t TeamState::FreeHandle(int32 handle)
{
	return fHandles.Free(handle);
}

TeamState::Handle TeamState::ThisHandle(int32 handle)
{
	return fHandles.This(handle);
}

BReferenceable *TeamState::ThisHandle(int32 handle, HandleType type)
{
	const Handle &handleObj = fHandles.This(handle);
	if (handleObj.type != HandleType::buffer) return NULL;
	BReferenceable *ref = handleObj.ref.Get();
	ref->AcquireReference();
	return ref;
}


//#pragma mark - Buffers

int32 TeamState::AllocBuffer(MemoryDomain domain, uint64 size, uint64 alignment, uint32 flags, area_id area, uint64 offset)
{
	void *clonedAreaAdr = NULL;
	// TODO: read only area support
	AreaDeleter clonedArea;
	if (area >= B_OK) {
		clonedArea.SetTo(clone_area("userptr", &clonedAreaAdr, B_ANY_ADDRESS, B_READ_AREA | B_WRITE_AREA, area));
		CheckRet(clonedArea.Get());
		area_info info;
		CheckRet(get_area_info(clonedArea.Get(), &info));
		if (size < offset || info.size - offset < size) return B_ERROR;
		switch (info.lock) {
			case B_FULL_LOCK:
			case B_CONTIGUOUS:
			case B_LOMEM:
			case B_32_BIT_FULL_LOCK:
			case B_32_BIT_CONTIGUOUS:
				break;
			default:
				return B_ERROR; // area physical memory must be locked
		}
	}
	BReference<BufferObject> buffer = gDevice.MemMgr().Switch()->Alloc(domain, size, alignment, flags, clonedArea.Get(), offset);
	if (!buffer.IsSet()) {
		printf("buffer alloc failed, domain: %d, size: %#" B_PRIx64 "\n", (int)domain, size);
		return B_NO_MEMORY;
	}
	clonedArea.Detach();
	return RegisterHandle(Handle{.type = HandleType::buffer, .ref = buffer});
}

BReference<BufferObject> TeamState::ThisBuffer(int32 handle)
{
	const Handle &handleObj = fHandles.This(handle);
	if (handleObj.type != HandleType::buffer) return NULL;
	return BReference<BufferObject>((BufferObject*)handleObj.ref.Get(), false);
}

status_t TeamState::Map(uint64 virtAdr, int32 handle, uint64 offset, uint64 size, uint32 flags)
{
	//printf("\nMap(%#" B_PRIx64 ", %" B_PRId32 ", %#" B_PRIx64 ", %#" B_PRIx64 ")\n", virtAdr, handle, offset, size);
	(void)flags;
	BReference<BufferObject> buffer = ThisBuffer(handle);
	if (!buffer.IsSet()) return B_ERROR;
	status_t res = fAddressSpace->Map(buffer, virtAdr, offset, size);
	if (res < B_OK) return res;
	return res;
}

status_t TeamState::Unmap(uint64 virtAdr, int32 handle, uint64 offset, uint64 size, uint32 flags)
{
	(void)flags;
	//printf("\nUnmap(%#" B_PRIx64 ", %" B_PRId32 ", %#" B_PRIx64 ", %#" B_PRIx64 ")\n", virtAdr, handle, offset, size);
	BReference<BufferObject> buffer = ThisBuffer(handle);
	if (!buffer.IsSet()) return B_ERROR;
	return fAddressSpace->Unmap(buffer, virtAdr, offset, size);
}

status_t TeamState::CpuMap(void *&adr, int32 handle, uint64 offset, uint64 size, uint32 flags)
{
	(void)flags;
	BReference<BufferObject> buffer = ThisBuffer(handle);
	if (!buffer.IsSet()) return B_ERROR;
	return gDevice.MemMgr().Switch()->CpuMap(adr, buffer, offset, size);
}

status_t TeamState::CpuUnmap(void *adr, int32 handle, uint64 offset, uint64 size, uint32 flags)
{
	(void)adr;
	(void)handle;
	(void)offset;
	(void)size;
	(void)flags;
	return B_OK;
}


//#pragma mark - Syncobjs

int32 TeamState::CreateSyncobj(Syncobj::CreateFlags flags)
{
	SyncobjRef syncobj(new Syncobj(flags), true);
	return RegisterHandle(Handle{.type = HandleType::syncobj, .ref = syncobj});
}

SyncobjRef TeamState::ThisSyncobj(int32 handle)
{
	const Handle &handleObj = fHandles.This(handle);
	if (handleObj.type != HandleType::syncobj) return NULL;
	return SyncobjRef((Syncobj*)handleObj.ref.Get(), false);
}

void TeamState::DumpSyncobjs()
{
	for (auto it = fHandles.Handles().begin(); it != fHandles.Handles().end(); it++) {
		int32 handle = it->first;
		const Handle &handleObj = it->second;
		if (handleObj.type == HandleType::syncobj) {
			SyncobjRef syncobj((Syncobj*)handleObj.ref.Get(), false);
			printf("%" B_PRId32 "(%p): ", handle, syncobj.Get());
			syncobj->Dump();
		}
	}
	printf("\n");
}


//#pragma mark - Command submissions

status_t TeamState::ScheduleCS(uint64 &handle, CommandSubmission *cs)
{
	if (GetDomain() != CurrentDomain()) {
		printf("[!] Domain() != CurrentDomain()\n");
		abort();
	}
	handle = fLastCsSeq++;
	cs->seq = handle;
	//printf("TeamState::ScheduleCS() -> %" B_PRIu64 "\n", handle);

	CheckRet(cs->Schedule());
	fCmdSubs.emplace(handle, cs);

	return B_OK;
}

status_t TeamState::WaitCS(uint64 handle)
{
	//printf("TeamState::WaitCS(%" B_PRIu64 ")\n", handle);

	if ((int32)fCsSeq - (int32)handle >= 0) return B_OK;
	auto it = fCmdSubs.find((uint32)handle);
	if (it == fCmdSubs.end()) return B_ERROR;
	CommandSubmission *cs = it->second;
	if (auto ring = ExternalPtr<RadeonRingBuffer>(cs->fence->Ring()).Switch()) {
		CheckRet(cs->fence->Wait());
	}
	return B_OK;
}


//#pragma mark - TeamRoster

ExternalRef<TeamState> TeamRoster::ThisTeam(team_id team, bool create)
{
	auto it = fTeamStates.find(team);
	if (it == fTeamStates.end()) {
		if (!create) return NULL;
		ExternalRef<TeamState> newTeamState(MakeExternal<TeamState>(team), true);
		fTeamStates.emplace(team, newTeamState);
		return newTeamState;
	}
	return ExternalRef<TeamState>(it->second, false);
}

int32 TeamRoster::CountTeams()
{
	return fTeamStates.size();
}

void TeamRoster::ListTeams(bool (*Handler)(ExternalRef<TeamState> ts, void *arg), void *arg)
{
	for (auto it = fTeamStates.begin(); it != fTeamStates.end(); it++) {
		if (!Handler(it->second, arg)) return;
	}
}
