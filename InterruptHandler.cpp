#include "InterruptHandler.h"
#include "Radeon.h"
#include "gmc_6_0_d.h"
#include "gmc_6_0.h"
#include "bif_3_0_d.h"
#include "bif_3_0.h"
#include "oss_1_0_d.h"
#include "oss_1_0.h"
#include <string.h>
#include <stdio.h>
#include <OS.h>


InterruptHandler::InterruptHandler():
	fEnabled(false), fWptrGpuAdr(0)
{
	memset(fHandlers, 0, sizeof(fHandlers));
}

InterruptHandler::~InterruptHandler()
{
	Fini();
}

status_t InterruptHandler::Init(uint64 size)
{
	CheckRet(gDevice.MemMgr().Switch()->AllocWriteback(fWptrGpuAdr, *(void**)&fWptrAdr, sizeof(uint32)));

	fBuffer.SetTo(gDevice.MemMgr().Switch()->Alloc(boDomainGtt, size));

	fRun = true;
	fThread = spawn_thread(
		[](void *arg) -> status_t {
			return ((InterruptHandler*)arg)->ThreadEntry();
		},
		"interrupt watcher",
		B_URGENT_DISPLAY_PRIORITY,
		this
	);
	CheckRet(fThread);
	resume_thread(fThread);

	return B_OK;
}

void InterruptHandler::Fini()
{
	if (fThread >= B_OK) {
		status_t res;
		suspend_thread(fThread);
		fRun = false;
		wait_for_thread(fThread, &res);
		fThread = -1;
	}
	if (fWptrGpuAdr != 0) {gDevice.MemMgr().Switch()->FreeWriteback(fWptrGpuAdr); fWptrGpuAdr = 0;}
}


void InterruptHandler::InstallHandler(uint32 clientId, uint32 srcId, InterruptSource *handler)
{
	if (!(clientId == 0)) return;
	if (!(srcId < srcIdCnt)) return;
	fHandlers[srcId] = {
		.handler = handler
	};
}

void InterruptHandler::UninstallHandler(uint32 clientId, uint32 srcId)
{
	if (clientId != 0) return;
	if (srcId >= srcIdCnt) return;
	fHandlers[srcId] = {};
}

void InterruptHandler::Read(uint32 &val)
{
	val = *(uint32*)((uint8*)fBuffer.adr + fRptr);
	fRptr = (fRptr + sizeof(uint32)) % fBuffer.buf->size;
}

static void WriteInterruptPacket(const InterruptPacket &pkt)
{
	printf("InterruptPacket(%" B_PRIu32 ", %" B_PRIu32 ", %" B_PRIu32 ", %" B_PRIu32 ")\n",
		pkt.srcId, pkt.srcData, pkt.ringId, pkt.vmId
	);
	switch (pkt.srcId) {
		case intSrcIdProtFault:
		case intSrcIdProtFault2: {
			uint64 protFaultAdr = (uint64)ReadReg4AmdGpu(mmVM_CONTEXT1_PROTECTION_FAULT_ADDR) * B_PAGE_SIZE;
			VmContext1ProtectionFaultStatus protFaultStatus {.val = ReadReg4AmdGpu(mmVM_CONTEXT1_PROTECTION_FAULT_STATUS)};
			WriteReg4MaskAmdGpu(mmVM_CONTEXT1_CNTL2, 1, ~1);

			uint32 prot     = protFaultStatus.protections;
			uint32 clientId = protFaultStatus.memoryClientId;
			uint32 clientRw = protFaultStatus.memoryClientRw;
			uint32 vmId     = protFaultStatus.vmid;

			printf("VM_CONTEXT1_PROTECTION_FAULT_ADDR: %#" B_PRIx64 "\n", protFaultAdr);
			printf("VM_CONTEXT1_PROTECTION_FAULT_STATUS: (");

			printf("prot: {");
			bool first = true;
			for (uint32 i = 0; i < 32; i++) {
				if (((1 << i) & prot) != 0) {
					if (first) first = false; else printf(", ");
					switch (i) {
						case 0: printf("range"); break;
						case 1: printf("pde0"); break;
						case 2: printf("valid"); break;
						case 3: printf("read"); break;
						case 4: printf("write"); break;
						default: printf("?(%u)", i);
					}
				}
			}
			printf("}");
			printf(", clientId: %" B_PRIu32, clientId);
			printf(", access: %s", (clientRw != 0) ? "write" : "read");
			printf(", vmId: %" B_PRIu32, vmId);
			printf(")\n");
			break;
		}
	}
}

bool InterruptHandler::Handle()
{
	bool handled = false;
	for (;;) {
		fWptr = Wptr();
		if (fWptr == fRptr) break;
		handled = true;
		while (fWptr != fRptr) {
			//printf("IH: fWptr: %" B_PRIu32 "\n", fWptr);
			InterruptPacket pkt;
			ReadPacket(pkt);
			if (pkt.clientId == 0 && pkt.srcId < srcIdCnt) {
				auto &handlerItem = fHandlers[pkt.srcId];
				if (handlerItem.handler != NULL) {
					handlerItem.handler->InterruptReceived(pkt);
				} else {
					WriteInterruptPacket(pkt);
				}
			} else {
				WriteInterruptPacket(pkt);
			}
		}
		SetRptr();
	}

	return handled;
}


status_t InterruptHandler::ThreadEntry()
{
	sem_id intSem = gDevice.SharedInfo()->vblank_sem;
	while (fRun) {
		status_t res = acquire_sem_etc(intSem, 1, B_RELATIVE_TIMEOUT, 1000000);
		if (res == B_INTERRUPTED) continue;
		if (res < B_OK && res != B_TIMED_OUT) abort();
		auto thisLocked = ExternalPtr<InterruptHandler>(this).Switch();
		bool handled = Handle();
		if (handled && res == B_TIMED_OUT) {
			printf("[!] interrupt handled by timeout\n");
		}
	}
	return B_OK;
}
