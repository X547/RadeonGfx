#include "RadeonInterrupts.h"
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


static uint32 OrderBase2(uint64 val)
{
	for (uint32 res = 0; res < 64; res++) {
		if (((uint64)1 << res) >= val) return res;
	}
	return 64;
}



struct InterruptPacketInt {
	uint32 srcId:      8;
	uint32 reserved1: 24;
	uint32 srcData:   28;
	uint32 reserved2:  4;
	uint32 ringId:     8;
	uint32 vmId:       8;
	uint32 reserved3: 16;
	uint32 reserved4;
};


RadeonRingBufferInt::RadeonRingBufferInt():
	fEnabled(false), fWptrGpuAdr(0)
{
	memset(fHandlers, 0, sizeof(fHandlers));
}

RadeonRingBufferInt::~RadeonRingBufferInt()
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

status_t RadeonRingBufferInt::Init(uint64 size)
{
	Disable();

	CheckRet(gDevice.MemMgr().Switch()->AllocWriteback(fWptrGpuAdr, *(void**)&fWptrAdr, sizeof(uint32)));

	WriteReg4AmdGpu(mmINTERRUPT_CNTL2, gDevice.MemMgr().Switch()->fDummyPage->gpuPhysAdr >> 8);
	
	InterruptCntl interruptCntl {.val = ReadReg4AmdGpu(mmINTERRUPT_CNTL)};
	interruptCntl.ihDummyRdOverride = false;
	interruptCntl.ihReqNonsnoopEn = false;
	WriteReg4AmdGpu(mmINTERRUPT_CNTL, interruptCntl.val);

	fBuffer.SetTo(gDevice.MemMgr().Switch()->Alloc(boDomainGtt, size));
	WriteReg4AmdGpu(mmIH_RB_BASE, fBuffer.buf->gpuPhysAdr >> 8);
	uint32 rbBufSz = OrderBase2(fBuffer.buf->size / 4);
	IhRbCntl ihRbCntl {
		.rbSize = rbBufSz,
		.wptrWritebackEnable = true,
		.wptrOverflowEnable = true,
		.wptrOverflowClear = true,
	};

	WriteReg8LoHiAmdGpu(mmIH_RB_WPTR_ADDR_LO, mmIH_RB_WPTR_ADDR_HI, fWptrGpuAdr);
	WriteReg4AmdGpu(mmIH_RB_CNTL, ihRbCntl.val);
	WriteReg4AmdGpu(mmIH_RB_RPTR, 0);
	WriteReg4AmdGpu(mmIH_RB_WPTR, 0);

	IhCntl ihCntl {
		.mcWrreqCredit = 0x10,
		.mcWrCleanCnt = 0x10,
		.mcVmid = 0
	};

/*
	if (adev->irq.msi_enabled)
		ih_cntl |= RPTR_REARM;
*/
	WriteReg4AmdGpu(mmIH_CNTL, ihCntl.val);

	fRun = true;
	fThread = spawn_thread(
		[](void *arg) -> status_t {
			return ((RadeonRingBufferInt*)arg)->ThreadEntry();
		},
		"interrupt watcher",
		B_URGENT_DISPLAY_PRIORITY,
		this
	);
	CheckRet(fThread);
	resume_thread(fThread);

	Enable();

	return B_OK;
}

void RadeonRingBufferInt::Enable()
{
	IhCntl ihCntl {.val = ReadReg4AmdGpu(mmIH_CNTL)};
	IhRbCntl ihRbCntl {.val = ReadReg4AmdGpu(mmIH_RB_CNTL)};
	ihCntl.enableIntr = true;
	ihRbCntl.rbEnable = true;
	WriteReg4AmdGpu(mmIH_CNTL, ihCntl.val);
	WriteReg4AmdGpu(mmIH_RB_CNTL, ihRbCntl.val);
	fEnabled = true;
}

void RadeonRingBufferInt::Disable()
{
	IhRbCntl ihRbCntl {.val = ReadReg4AmdGpu(mmIH_RB_CNTL)};
	IhCntl ihCntl {.val = ReadReg4AmdGpu(mmIH_CNTL)};
	ihRbCntl.rbEnable = false;
	ihCntl.enableIntr = false;
	WriteReg4AmdGpu(mmIH_RB_CNTL, ihRbCntl.val);
	WriteReg4AmdGpu(mmIH_CNTL, ihCntl.val);
	WriteReg4AmdGpu(mmIH_RB_RPTR, 0);
	WriteReg4AmdGpu(mmIH_RB_WPTR, 0);
	fRptr = 0;
	fEnabled = false;
}


void RadeonRingBufferInt::InstallHandler(uint32 clientId, uint32 srcId, InterruptHandler handler, void *arg)
{
	if (!(clientId == 0)) return;
	if (!(srcId < srcIdCnt)) return;
	fHandlers[srcId] = {
		.handler = handler,
		.arg = arg
	};
}

void RadeonRingBufferInt::UninstallHandler(uint32 clientId, uint32 srcId)
{
	if (clientId != 0) return;
	if (srcId >= srcIdCnt) return;
	fHandlers[srcId] = {
		.handler = NULL,
		.arg = NULL
	};
}

uint32 RadeonRingBufferInt::Rptr()
{
	return ReadReg4AmdGpu(mmIH_RB_RPTR);
}

uint32 RadeonRingBufferInt::Wptr()
{
	uint32 wptr = /* *fWptrAdr */ ReadReg4AmdGpu(mmIH_RB_WPTR);
	if (IhRbWptr{.val = wptr}.rbOverflow) {
		wptr &= ~IhRbWptr{.rbOverflow = true}.val;
		printf("[!] IH ring overflow\n");
		fRptr = (wptr + 16) % fBuffer.buf->size;
		IhRbCntl tmp {.val = ReadReg4AmdGpu(mmIH_RB_CNTL)};
		tmp.wptrOverflowClear = true;
		WriteReg4AmdGpu(mmIH_RB_CNTL, tmp.val);
	}
	return wptr % fBuffer.buf->size;
}

void RadeonRingBufferInt::SetRptr()
{
	WriteReg4AmdGpu(mmIH_RB_RPTR, fRptr);
}

void RadeonRingBufferInt::Read(uint32 &val)
{
	val = *(uint32*)((uint8*)fBuffer.adr + fRptr);
	fRptr = (fRptr + sizeof(uint32)) % fBuffer.buf->size;
}

void RadeonRingBufferInt::ReadPacket(InterruptPacket &pkt)
{
	InterruptPacketInt data;
	if (sizeof(data) != 4*sizeof(uint32)) abort();
	memcpy(&data, (uint8*)fBuffer.adr + fRptr, 4*sizeof(uint32));
	fRptr = (fRptr + 4*sizeof(uint32)) % fBuffer.buf->size;

	pkt = InterruptPacket{
		.clientId = 0 /*AMDGPU_IRQ_CLIENTID_LEGACY*/,
		.srcId    = data.srcId,
		.srcData  = data.srcData,
		.ringId   = data.ringId,
		.vmId     = data.vmId
	};
}

static void WriteSet(uint32 val)
{
	printf("{");
	bool first = true;
	for (uint32 i = 0; i < 32; i++) {
		if ((1 << i) & val) {
			if (first) first = false; else printf(", ");
			printf("%" B_PRIu32, i);
		}
	}
	printf("}");
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

bool RadeonRingBufferInt::Handle()
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
					handlerItem.handler(handlerItem.arg, pkt);
				}
				else
					WriteInterruptPacket(pkt);
			} else {
				WriteInterruptPacket(pkt);
			}
		}
		SetRptr();
	}

	return handled;
}


status_t RadeonRingBufferInt::ThreadEntry()
{
	sem_id intSem = gDevice.SharedInfo()->vblank_sem;
	while (fRun) {
		status_t res = acquire_sem_etc(intSem, 1, B_RELATIVE_TIMEOUT, 1000000);
		if (res == B_INTERRUPTED) continue;
		if (res < B_OK && res != B_TIMED_OUT) abort();
		auto thisLocked = ExternalPtr<RadeonRingBufferInt>(this).Switch();
		bool handled = Handle();
		if (handled && res == B_TIMED_OUT) {
			printf("[!] interrupt handled by timeout\n");
		}
	}
	return B_OK;
}
