#include "RadeonFirmware.h"
#include "Radeon.h"
#include "RadeonDevice.h"
#include "gfx_6_0.h"
#include "gfx_6_0_d.h"
#include "gmc_6_0.h"
#include "gmc_6_0_d.h"

#include <stdio.h>
#include <ByteOrder.h>
#include <File.h>
#include <String.h>
#include <AutoDeleter.h>

#define CheckRet(err) {status_t _err = (err); if (_err < B_OK) return _err;}


static void radeon_ucode_print_common_hdr(const common_firmware_header *hdr)
{
	printf("  size_bytes: %u\n", B_LENDIAN_TO_HOST_INT32(hdr->size_bytes));
	printf("  header_size_bytes: %u\n", B_LENDIAN_TO_HOST_INT32(hdr->header_size_bytes));
	printf("  header_version_major: %u\n", B_LENDIAN_TO_HOST_INT16(hdr->header_version_major));
	printf("  header_version_minor: %u\n", B_LENDIAN_TO_HOST_INT16(hdr->header_version_minor));
	printf("  ip_version_major: %u\n", B_LENDIAN_TO_HOST_INT16(hdr->ip_version_major));
	printf("  ip_version_minor: %u\n", B_LENDIAN_TO_HOST_INT16(hdr->ip_version_minor));
	printf("  ucode_version: 0x%08x\n", B_LENDIAN_TO_HOST_INT32(hdr->ucode_version));
	printf("  ucode_size_bytes: %u\n", B_LENDIAN_TO_HOST_INT32(hdr->ucode_size_bytes));
	printf("  ucode_array_offset_bytes: %u\n",
		  B_LENDIAN_TO_HOST_INT32(hdr->ucode_array_offset_bytes));
	printf("  crc32: 0x%08x\n", B_LENDIAN_TO_HOST_INT32(hdr->crc32));
}

static void radeon_ucode_print_gfx_hdr(const radeon_firmware_header *hdr)
{
	uint16_t version_major = B_LENDIAN_TO_HOST_INT16(hdr->common.header_version_major);
	uint16_t version_minor = B_LENDIAN_TO_HOST_INT16(hdr->common.header_version_minor);

	printf("  GFX\n");
	radeon_ucode_print_common_hdr(&hdr->common);

	if (version_major == 1) {
		const struct gfx_firmware_header_v1_0 *gfx_hdr = &hdr->gfx;

		printf("  ucode_feature_version: %u\n",
			  B_LENDIAN_TO_HOST_INT32(gfx_hdr->ucode_feature_version));
		printf("  jt_offset: %u\n", B_LENDIAN_TO_HOST_INT32(gfx_hdr->jt_offset));
		printf("  jt_size: %u\n", B_LENDIAN_TO_HOST_INT32(gfx_hdr->jt_size));
	} else {
		printf("  Unknown GFX ucode version: %u.%u\n", version_major, version_minor);
	}
}


status_t LoadFirmware()
{
	struct {
		RadeonDevice::Firmware &firmware;
		const char *name;
	} firmwares[] = {
		{gDevice.fFirmwares.pfp, "verde_pfp.bin"},
		{gDevice.fFirmwares.ce, "verde_ce.bin"},
		{gDevice.fFirmwares.me, "verde_me.bin"},
		{gDevice.fFirmwares.mc, "verde_mc.bin"},
		{gDevice.fFirmwares.rlc, "verde_rlc.bin"},
	};
	
	for (size_t i = 0; i < B_COUNT_OF(firmwares); i++) {
		printf("loading firmware \"%s\"\n", firmwares[i].name);
		BString path;
		path.SetToFormat("../firmware/%s", firmwares[i].name);
		BFile file(path.String(), B_READ_ONLY);
		CheckRet(file.InitCheck());
		CheckRet(file.GetSize(&firmwares[i].firmware.size));
		firmwares[i].firmware.data.SetTo(new uint8[firmwares[i].firmware.size]);
		CheckRet(file.Read(firmwares[i].firmware.data.Get(), firmwares[i].firmware.size));
		
		radeon_ucode_print_gfx_hdr((radeon_firmware_header*)firmwares[i].firmware.data.Get());
	}

	return B_OK;
}

status_t LoadCpMicrocode()
{
	WriteReg4AmdGpu(mmCP_ME_CNTL, CpMeCntl{.ceHalt = true, .pfpHalt = true, .meHalt = true}.val);
	WriteReg4AmdGpu(mmSCRATCH_UMSK, 0);
	snooze(50);

	const struct gfx_firmware_header_v1_0 *pfp_hdr = (const struct gfx_firmware_header_v1_0 *)gDevice.fFirmwares.pfp.data.Get();
	const struct gfx_firmware_header_v1_0 *ce_hdr = (const struct gfx_firmware_header_v1_0 *)gDevice.fFirmwares.ce.data.Get();
	const struct gfx_firmware_header_v1_0 *me_hdr = (const struct gfx_firmware_header_v1_0 *)gDevice.fFirmwares.me.data.Get();
	const uint32 *fw_data;
	uint32 fw_size;

	/* PFP */
	fw_data = (const uint32 *)(gDevice.fFirmwares.pfp.data.Get() + B_LENDIAN_TO_HOST_INT32(pfp_hdr->header.ucode_array_offset_bytes));
	fw_size = B_LENDIAN_TO_HOST_INT32(pfp_hdr->header.ucode_size_bytes) / 4;
	WriteReg4AmdGpu(mmCP_PFP_UCODE_ADDR, 0);
	for (uint32 i = 0; i < fw_size; i++)
		WriteReg4AmdGpu(mmCP_PFP_UCODE_DATA, B_LENDIAN_TO_HOST_INT32(fw_data[i]));
	WriteReg4AmdGpu(mmCP_PFP_UCODE_ADDR, 0);

	/* CE */
	fw_data = (const uint32 *)(gDevice.fFirmwares.ce.data.Get() + B_LENDIAN_TO_HOST_INT32(ce_hdr->header.ucode_array_offset_bytes));
	fw_size = B_LENDIAN_TO_HOST_INT32(ce_hdr->header.ucode_size_bytes) / 4;
	WriteReg4AmdGpu(mmCP_CE_UCODE_ADDR, 0);
	for (uint32 i = 0; i < fw_size; i++)
		WriteReg4AmdGpu(mmCP_CE_UCODE_DATA, B_LENDIAN_TO_HOST_INT32(fw_data[i]));
	WriteReg4AmdGpu(mmCP_CE_UCODE_ADDR, 0);

	/* ME */
	fw_data = (const uint32 *)(gDevice.fFirmwares.me.data.Get() + B_LENDIAN_TO_HOST_INT32(me_hdr->header.ucode_array_offset_bytes));
	fw_size = B_LENDIAN_TO_HOST_INT32(me_hdr->header.ucode_size_bytes) / 4;
	WriteReg4AmdGpu(mmCP_ME_RAM_WADDR, 0);
	for (uint32 i = 0; i < fw_size; i++)
		WriteReg4AmdGpu(mmCP_ME_RAM_DATA, B_LENDIAN_TO_HOST_INT32(fw_data[i]));
	WriteReg4AmdGpu(mmCP_ME_RAM_WADDR, 0);
	
	WriteReg4AmdGpu(mmCP_PFP_UCODE_ADDR, 0);
	WriteReg4AmdGpu(mmCP_CE_UCODE_ADDR, 0);
	WriteReg4AmdGpu(mmCP_ME_RAM_WADDR, 0);
	WriteReg4AmdGpu(mmCP_ME_RAM_RADDR, 0);

	return B_OK;
}

status_t LoadMcMicrocode()
{
	const struct mc_firmware_header_v1_0 *hdr = (const struct mc_firmware_header_v1_0 *)gDevice.fFirmwares.mc.data.Get();

	uint32 regs_size = B_LENDIAN_TO_HOST_INT32(hdr->io_debug_size_bytes) / (4 * 2);
	const uint32 *new_io_mc_regs = (const uint32 *)(gDevice.fFirmwares.mc.data.Get() + B_LENDIAN_TO_HOST_INT32(hdr->io_debug_array_offset_bytes));
	uint32 ucode_size = B_LENDIAN_TO_HOST_INT32(hdr->header.ucode_size_bytes) / 4;
	const uint32 *new_fw_data = (const uint32 *)(gDevice.fFirmwares.mc.data.Get() + B_LENDIAN_TO_HOST_INT32(hdr->header.ucode_array_offset_bytes));

	uint32 running = McSeqSupCntl{.val = ReadReg4AmdGpu(mmMC_SEQ_SUP_CNTL)}.run;
	printf("mc.running: %" B_PRIu32 "\n", running);

	if (running == 0) {
		/* reset the engine and set to writable */
		WriteReg4AmdGpu(mmMC_SEQ_SUP_CNTL, 0x00000008);
		WriteReg4AmdGpu(mmMC_SEQ_SUP_CNTL, 0x00000010);

		/* load mc io regs */
		for (uint32 i = 0; i < regs_size; i++) {
			WriteReg4AmdGpu(mmMC_SEQ_IO_DEBUG_INDEX, B_LENDIAN_TO_HOST_INT32(*new_io_mc_regs++));
			WriteReg4AmdGpu(mmMC_SEQ_IO_DEBUG_DATA, B_LENDIAN_TO_HOST_INT32(*new_io_mc_regs++));
		}
		/* load the MC ucode */
		for (uint32 i = 0; i < ucode_size; i++) {
			WriteReg4AmdGpu(mmMC_SEQ_SUP_PGM, B_LENDIAN_TO_HOST_INT32(*new_fw_data++));
		}

		/* put the engine back into the active state */
		WriteReg4AmdGpu(mmMC_SEQ_SUP_CNTL, 0x00000008);
		WriteReg4AmdGpu(mmMC_SEQ_SUP_CNTL, 0x00000004);
		WriteReg4AmdGpu(mmMC_SEQ_SUP_CNTL, 0x00000001);

		/* wait for training to complete */
		for (uint32 i = 0; ; i++) {
			if (!(i < 100000)) return B_ERROR;
			if (McSeqTrainWakeupCntl{.val = ReadReg4AmdGpu(mmMC_SEQ_TRAIN_WAKEUP_CNTL)}.trainDoneD0)
				break;
			snooze(1000);
		}
		for (uint32 i = 0; ; i++) {
			if (!(i < 100000)) return B_ERROR;
			if (McSeqTrainWakeupCntl{.val = ReadReg4AmdGpu(mmMC_SEQ_TRAIN_WAKEUP_CNTL)}.trainDoneD1)
				break;
			snooze(1000);
		}
	}
	return B_OK;
}

status_t LoadRlcFirmware()
{
	WriteReg4AmdGpu(mmRLC_MC_CNTL, 0);
	WriteReg4AmdGpu(mmRLC_UCODE_CNTL, 0);
	auto hdr = (const struct rlc_firmware_header_v1_0 *)gDevice.fFirmwares.rlc.data.Get();
	uint32 fw_size = B_LENDIAN_TO_HOST_INT32(hdr->header.ucode_size_bytes) / 4;
	auto fw_data = (const uint32 *)(gDevice.fFirmwares.rlc.data.Get() + B_LENDIAN_TO_HOST_INT32(hdr->header.ucode_array_offset_bytes));
	for (uint32 i = 0; i < fw_size; i++) {
		WriteReg4AmdGpu(mmRLC_UCODE_ADDR, i);
		WriteReg4AmdGpu(mmRLC_UCODE_DATA, B_LENDIAN_TO_HOST_INT32(fw_data[i]));
	}
	WriteReg4AmdGpu(mmRLC_UCODE_ADDR, 0);
	return B_OK;
}
