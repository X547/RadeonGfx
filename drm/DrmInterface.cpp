#include "DrmInterface.h"
#include <SupportDefs.h>
#include "Radeon.h"
#include "RadeonMemory.h"
#include "gfx_6_0_d.h"
#include "gmc_6_0_d.h"
#include "oss_1_0_d.h"
#include "sid_amdgpu.h"
#define _DEFAULT_SOURCE
extern "C" {
#include <xf86drm.h>
#include <libdrm/drm.h>
#include <libdrm/amdgpu_drm.h>
}
#include <stdio.h>
#include <string.h>


ExternalPtr<TeamState> gTeamState;


status_t InitDevice();


static int drmAmdgpuReadMmrReg(uint32_t offset, uint32_t seNum, uint32_t shNum, uint32_t *value)
{
	uint32_t seIdx = (seNum == 0xffffffff) ? 0 : seNum;
	uint32_t shIdx = (shNum == 0xffffffff) ? 0 : shNum;
	switch (offset) {
		case mmCC_RB_BACKEND_DISABLE:
			*value = gDevice.fInfo.gfx.config.rb_config[seIdx][shIdx].rb_backend_disable; return 0;
		case mmGC_USER_RB_BACKEND_DISABLE:
			*value = gDevice.fInfo.gfx.config.rb_config[seIdx][shIdx].user_rb_backend_disable; return 0;
		case mmPA_SC_RASTER_CONFIG:
			*value = gDevice.fInfo.gfx.config.rb_config[seIdx][shIdx].raster_config; return 0;
		case mmGB_ADDR_CONFIG:
			*value = gDevice.fInfo.gfx.config.gb_addr_config; return 0;
		case mmMC_ARB_RAMCFG:
			*value = gDevice.fInfo.gfx.config.mc_arb_ramcfg; return 0;
		case mmGRBM_STATUS:
		case mmGRBM_STATUS2:
		case mmGRBM_STATUS_SE0:
		case mmGRBM_STATUS_SE1:
		case mmSRBM_STATUS:
		case mmSRBM_STATUS2:
		case DMA_STATUS_REG + DMA0_REGISTER_OFFSET:
		case DMA_STATUS_REG + DMA1_REGISTER_OFFSET:
		case mmCP_STAT:
		case mmCP_STALLED_STAT1:
		case mmCP_STALLED_STAT2:
		case mmCP_STALLED_STAT3:
			*value = ReadReg4AmdGpu(offset); return 0;
		default:
			if (offset >= mmGB_TILE_MODE0 && offset <= mmGB_TILE_MODE0 + 0x1f) {
				*value = gDevice.fInfo.gfx.config.tile_mode_array[offset - mmGB_TILE_MODE0];
				return 0;
			}
	}
	printf("unknown register: %#" B_PRIx32 "\n", offset);
	return -1;
}


extern "C" _EXPORT status_t drmInit()
{
	CheckRet(InitDevice());
	gTeamState = MakeExternal<TeamState>(-1);
	return B_OK;
}

extern "C" _EXPORT void *drmMmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	(void)addr;
	(void)prot;
	(void)flags;
	(void)fd;
	//printf("drmMmap()\n");
	int32 handle = (int32)offset;
	void *resAdr = NULL;
	if (gTeamState.Switch()->CpuMap(resAdr, handle, 0, length, 0) < B_OK) return NULL;
	//printf("resAdr: %p\n", resAdr);
	return resAdr;
}

extern "C" _EXPORT int drmMunmap(void *addr, size_t length)
{
	return gTeamState.Switch()->CpuUnmap(addr, -1, 0, length, 0);
}

int drmIoctlInt(ExternalPtr<TeamState> teamState, unsigned long request, void *arg)
{
	unsigned long requestCmd = request%0x100;
	if (requestCmd >= DRM_COMMAND_BASE && requestCmd < DRM_COMMAND_END) {
		requestCmd -= DRM_COMMAND_BASE;
		switch (requestCmd) {
			case DRM_AMDGPU_INFO: {
				struct drm_amdgpu_info *request = (struct drm_amdgpu_info*)arg;
				switch (request->query) {
					case AMDGPU_INFO_ACCEL_WORKING: {
						*(uint32_t*)request->return_pointer = 1;
						return 0;
					}
					case AMDGPU_INFO_DEV_INFO: {
						struct drm_amdgpu_info_device *dev_info = (struct drm_amdgpu_info_device*)request->return_pointer;
						memset(dev_info, 0, sizeof(struct drm_amdgpu_info_device));
						dev_info->device_id = gDevice.SharedInfo()->pciID;
						dev_info->chip_rev = gDevice.fInfo.rev_id;
						dev_info->external_rev = gDevice.fInfo.external_rev_id;
						dev_info->pci_rev = gDevice.SharedInfo()->pciRev;
						dev_info->family = AMDGPU_FAMILY_SI;
						dev_info->num_shader_engines = gDevice.fInfo.gfx.config.max_shader_engines;
						dev_info->num_shader_arrays_per_engine = gDevice.fInfo.gfx.config.max_sh_per_se;
						dev_info->gpu_counter_freq = 0x6978; // !!!
						dev_info->max_engine_clock = 0xc3500; // !!!
						dev_info->max_memory_clock = 0x112a88; // !!!
						dev_info->cu_active_number = gDevice.fInfo.gfx.cu_info.number;
						dev_info->cu_ao_mask = gDevice.fInfo.gfx.cu_info.ao_cu_mask;
						memcpy(&dev_info->cu_bitmap[0], &gDevice.fInfo.gfx.cu_info.bitmap[0], sizeof(gDevice.fInfo.gfx.cu_info.bitmap));
						dev_info->enabled_rb_pipes_mask = gDevice.fInfo.gfx.config.backend_enable_mask;
						dev_info->num_rb_pipes = gDevice.fInfo.gfx.config.max_backends_per_se * gDevice.fInfo.gfx.config.max_shader_engines;
						dev_info->num_hw_gfx_contexts = gDevice.fInfo.gfx.config.max_hw_contexts;
						dev_info->virtual_address_offset = 0x200000;
						dev_info->virtual_address_max = 0xfffe00000;
						dev_info->virtual_address_alignment = 0x1000;
						dev_info->pte_fragment_size = 0x200000;
						dev_info->gart_page_size = 0x1000;
						dev_info->ce_ram_size = 0x8000;
						dev_info->vram_type = 0x5;
						dev_info->vram_bit_width = 0x80;
						dev_info->num_shader_visible_vgprs = gDevice.fInfo.gfx.config.max_gprs;
						dev_info->num_cu_per_sh = gDevice.fInfo.gfx.config.max_cu_per_sh;
						dev_info->num_tcc_blocks = gDevice.fInfo.gfx.config.max_texture_channel_caches;
						dev_info->max_gs_waves_per_vgt = gDevice.fInfo.gfx.config.max_gs_threads;
						memcpy(&dev_info->cu_ao_bitmap[0], &gDevice.fInfo.gfx.cu_info.ao_cu_bitmap[0], sizeof(gDevice.fInfo.gfx.cu_info.ao_cu_bitmap));

						return 0;
					}
					case AMDGPU_INFO_READ_MMR_REG: {
						uint32_t seNum = (request->read_mmr_reg.instance >> AMDGPU_INFO_MMR_SE_INDEX_SHIFT) & AMDGPU_INFO_MMR_SE_INDEX_MASK;
						uint32_t shNum = (request->read_mmr_reg.instance >> AMDGPU_INFO_MMR_SH_INDEX_SHIFT) & AMDGPU_INFO_MMR_SH_INDEX_MASK;
						if (seNum == AMDGPU_INFO_MMR_SE_INDEX_MASK)
							seNum = 0xffffffff;
						else if (seNum >= AMDGPU_GFX_MAX_SE)
							return EINVAL;
						if (shNum == AMDGPU_INFO_MMR_SH_INDEX_MASK)
							shNum = 0xffffffff;
						else if (shNum >= AMDGPU_GFX_MAX_SH_PER_SE)
							return EINVAL;

						uint32_t *values = (uint32_t*)request->return_pointer;
						for (uint32_t i = 0; i < request->read_mmr_reg.count; i++) {
							int res = drmAmdgpuReadMmrReg(request->read_mmr_reg.dword_offset + i, seNum, shNum, &values[i]);
							if (res != 0)
								return res;
						}
						return 0;
					}
					case AMDGPU_INFO_FW_TA: {
						return 0;
					}
					case AMDGPU_INFO_VRAM_GTT: {
						if (request->return_size < sizeof(struct drm_amdgpu_info_vram_gtt)) {
							return B_BAD_VALUE;
						}
						auto vram_gtt = (struct drm_amdgpu_info_vram_gtt *)request->return_pointer;
						uint64 totalVram, totalVramMap, totalGtt, alloc;
						{
							auto memMgr = gDevice.MemMgr().Switch();
							memMgr->GetUsage(totalVram, alloc, boDomainVram);
							memMgr->GetUsage(totalVramMap, alloc, boDomainVramMappable);
							memMgr->GetUsage(totalGtt, alloc, boDomainGtt);
						}
						vram_gtt->vram_size = totalVram + totalVramMap;
						vram_gtt->gtt_size = totalGtt;
						return 0;
					}
					case AMDGPU_INFO_VRAM_USAGE: {
						uint64 total, alloc, allocMap;
						{
							auto memMgr = gDevice.MemMgr().Switch();
							memMgr->GetUsage(total, alloc, boDomainVram);
							memMgr->GetUsage(total, allocMap, boDomainVramMappable);
						}
						*(uint64_t*)request->return_pointer = alloc + allocMap;
						return 0;
					}
					case AMDGPU_INFO_VIS_VRAM_USAGE: {
						uint64 total, alloc;
						gDevice.MemMgr().Switch()->GetUsage(total, alloc, boDomainVramMappable);
						*(uint64_t*)request->return_pointer = alloc;
						return 0;
					}
					case AMDGPU_INFO_GTT_USAGE: {
						uint64 total, alloc;
						gDevice.MemMgr().Switch()->GetUsage(total, alloc, boDomainGtt);
						*(uint64_t*)request->return_pointer = alloc;
						return 0;
					}
					case AMDGPU_INFO_MEMORY: {
						struct drm_amdgpu_memory_info *meminfo = (struct drm_amdgpu_memory_info*)request->return_pointer;
						meminfo->vram.total_heap_size = 0x80000000;
						meminfo->vram.usable_heap_size = 0x7e380000;
						meminfo->vram.heap_usage = 0x2664000;
						meminfo->vram.max_allocation = 0x5eaa0000;

						meminfo->cpu_accessible_vram.total_heap_size = 0x10000000;
						meminfo->cpu_accessible_vram.usable_heap_size = 0xf378000;
						meminfo->cpu_accessible_vram.heap_usage = 0x1290000;
						meminfo->cpu_accessible_vram.max_allocation = 0xb69a000;

						meminfo->gtt.total_heap_size = 0xc0000000;
						meminfo->gtt.usable_heap_size = 0xbfddd000;
						meminfo->gtt.heap_usage = 0xce1000;
						meminfo->gtt.max_allocation = 0x8fe65c00;
						return 0;
					}
					case AMDGPU_INFO_FW_VERSION: {
						struct drm_amdgpu_info_firmware *firmware = (struct drm_amdgpu_info_firmware*)request->return_pointer;
						switch (request->query_fw.fw_type) {
							case AMDGPU_INFO_FW_GFX_ME: {
								firmware->ver = 0x91;
								firmware->feature = 0x1d;
								return 0;
							}
							case AMDGPU_INFO_FW_GFX_PFP: {
								firmware->ver = 0x54;
								firmware->feature = 0x1d;
								return 0;
							}
							case AMDGPU_INFO_FW_GFX_CE: {
								firmware->ver = 0x3d;
								firmware->feature = 0x1d;
								return 0;
							}
							case AMDGPU_INFO_FW_UVD: {
								firmware->ver = 0x40000d00;
								firmware->feature = 0;
								return 0;
							}
							case AMDGPU_INFO_FW_VCE: {
								firmware->ver = 0;
								firmware->feature = 0;
								return 0;
							}
						}
						return -1;
					}
					case AMDGPU_INFO_HW_IP_INFO: {
						struct drm_amdgpu_info_hw_ip *info = (struct drm_amdgpu_info_hw_ip*)request->return_pointer;
						switch (request->query_hw_ip.type) {
							case AMDGPU_HW_IP_GFX: {
								info->hw_ip_version_major = 0x6;
								info->hw_ip_version_minor = 0;
								info->capabilities_flags = 0;
								info->ib_start_alignment = 0x20;
								info->ib_size_alignment = 0x20;
								info->available_rings = 1;
								return 0;
							}
							case AMDGPU_HW_IP_COMPUTE: {
								info->hw_ip_version_major = 0x6;
								info->hw_ip_version_minor = 0;
								info->capabilities_flags = 0;
								info->ib_start_alignment = 0x20;
								info->ib_size_alignment = 0x20;
								info->available_rings = 3;
								return 0;
							}
							case AMDGPU_HW_IP_DMA: {
								info->hw_ip_version_major = 0x1;
								info->hw_ip_version_minor = 0;
								info->capabilities_flags = 0;
								info->ib_start_alignment = 0x100;
								info->ib_size_alignment = 0x4;
								info->available_rings = 3;
								return 0;
							}
							case AMDGPU_HW_IP_UVD: {
								info->hw_ip_version_major = 0x3;
								info->hw_ip_version_minor = 0x1;
								info->capabilities_flags = 0;
								info->ib_start_alignment = 0x40;
								info->ib_size_alignment = 0x40;
								info->available_rings = 1;
								return 0;
							}
							case AMDGPU_HW_IP_VCE: {
								return 0;
							}
							case AMDGPU_HW_IP_UVD_ENC: {
								info->hw_ip_version_major = 0x3;
								info->hw_ip_version_minor = 0x1;
								info->capabilities_flags = 0;
								info->ib_start_alignment = 0x40;
								info->ib_size_alignment = 0x40;
								info->available_rings = 0;
								return 0;
							}
							case AMDGPU_HW_IP_VCN_DEC: {
								return 0;
							}
							case AMDGPU_HW_IP_VCN_ENC: {
								return 0;
							}
							case AMDGPU_HW_IP_VCN_JPEG: {
								return 0;
							}
						}
						return -1;
					}
					default:
						return ENOSYS;
				}
			}
			case DRM_AMDGPU_GEM_METADATA: {
				auto *args = (struct drm_amdgpu_gem_metadata*)arg;
				BReference<BufferObject> buffer = teamState.Switch()->ThisBuffer(args->handle);
				if (!buffer.IsSet()) return ENOENT;
				auto memMgr = gDevice.MemMgr().Switch();
				switch (args->op) {
					case AMDGPU_GEM_METADATA_OP_SET_METADATA: {
						memcpy(&buffer->metadata, &args->data, sizeof(buffer->metadata));
						return B_OK;
					}
					case AMDGPU_GEM_METADATA_OP_GET_METADATA: {
						memcpy(&args->data, &buffer->metadata, sizeof(buffer->metadata));
						return B_OK;
					}
				}
				break;
			}
			case DRM_AMDGPU_CTX: {
				auto *request = (union drm_amdgpu_ctx*)arg;
				switch (request->in.op) {
					case AMDGPU_CTX_OP_ALLOC_CTX: {
						static uint32_t newCtx = 1;
						request->out.alloc.ctx_id = newCtx++;
						return 0;
					}
					case AMDGPU_CTX_OP_FREE_CTX: {
						return 0;
					}
					case AMDGPU_CTX_OP_QUERY_STATE: {
						return ENOSYS;
					}
					case AMDGPU_CTX_OP_QUERY_STATE2: {
						return ENOSYS;
					}
				}
				break;
			}
			case DRM_AMDGPU_GEM_CREATE: {
				auto *args = (union drm_amdgpu_gem_create*)arg;
				MemoryDomain domain;
				if (AMDGPU_GEM_DOMAIN_VRAM & args->in.domains) {
					domain = (args->in.domain_flags & AMDGPU_GEM_CREATE_NO_CPU_ACCESS) ? boDomainVram : boDomainVramMappable;
				} else {
					domain = boDomainGtt;
				}
				int32 handle = teamState.Switch()->AllocBuffer(domain, args->in.bo_size, args->in.alignment, 0);
				if (handle < B_OK) return handle;
				args->out.handle = handle;
				return B_OK;
			}
			case DRM_AMDGPU_GEM_OP: {
				auto *args = (struct drm_amdgpu_gem_op*)arg;
				switch (args->op) {
					case AMDGPU_GEM_OP_GET_GEM_CREATE_INFO: {
						auto boInfo = (struct drm_amdgpu_gem_create_in*)(uintptr_t)args->value;
						BReference<BufferObject> buffer = teamState.Switch()->ThisBuffer(args->handle);
						if (!buffer.IsSet()) return ENOENT;
						auto memMgr = gDevice.MemMgr().Switch();
						memset(boInfo, 0, sizeof(*boInfo));
						boInfo->bo_size = buffer->size;
						boInfo->alignment = B_PAGE_SIZE; // !!!
						switch (buffer->domain) {
							case boDomainVram:
								boInfo->domains = AMDGPU_GEM_DOMAIN_VRAM;
								boInfo->domain_flags = AMDGPU_GEM_CREATE_NO_CPU_ACCESS;
								break;
							case boDomainVramMappable:
								boInfo->domains = AMDGPU_GEM_DOMAIN_VRAM;
								boInfo->domain_flags = AMDGPU_GEM_CREATE_CPU_ACCESS_REQUIRED;
								break;
							case boDomainGtt:
								boInfo->domains = AMDGPU_GEM_DOMAIN_GTT;
								break;
						}
						break;
					}
					default:
						return ENOSYS;
				}
				return B_OK;
			}
			case DRM_AMDGPU_GEM_USERPTR: {
				auto *args = (struct drm_amdgpu_gem_userptr*)arg;
				// NOTE: server mode only, incompatible with local calls
				int32 handle = teamState.Switch()->AllocBuffer(boDomainGtt, args->size, B_PAGE_SIZE, 0, args->handle /* area_id */, args->addr);
				if (handle < B_OK) return handle;
				args->handle = handle;
				return B_OK;
			}
			case DRM_AMDGPU_GEM_VA: {
				auto *args = (struct drm_amdgpu_gem_va*)arg;
				switch (args->operation) {
					case AMDGPU_VA_OP_MAP: {
						return teamState.Switch()->Map(args->va_address, args->handle, args->offset_in_bo, args->map_size, 0);
					}
					case AMDGPU_VA_OP_UNMAP:
					case AMDGPU_VA_OP_CLEAR: {
						return teamState.Switch()->Unmap(args->va_address, args->handle, args->offset_in_bo, args->map_size, 0);
					}
				}
				break;
			}
			case DRM_AMDGPU_GEM_MMAP: {
				auto *args = (union drm_amdgpu_gem_mmap*)arg;
				args->out.addr_ptr = args->in.handle;
				return 0;
			}
			case DRM_AMDGPU_CS: {
				//printf("DRM_AMDGPU_CS\n");
				auto args = (union drm_amdgpu_cs*)arg;
				auto chunks = (struct drm_amdgpu_cs_chunk**)args->in.chunks;
				ObjectDeleter cs(new CommandSubmission(teamState.Get()));
				cs->ringId = RADEON_RING_TYPE_GFX_INDEX;

				for (size_t i = 0; i < args->in.num_chunks; i++) {
					switch (chunks[i]->chunk_id) {
						case AMDGPU_CHUNK_ID_IB: cs->indBufCnt++; break;
						case AMDGPU_CHUNK_ID_SYNCOBJ_TIMELINE_WAIT: {
							struct drm_amdgpu_cs_chunk_syncobj *syncobj = (struct drm_amdgpu_cs_chunk_syncobj*)chunks[i]->chunk_data;
							cs->waitCnt += chunks[i]->length_dw/(sizeof(struct drm_amdgpu_cs_chunk_syncobj)/4);
							break;
						}
						case AMDGPU_CHUNK_ID_SYNCOBJ_TIMELINE_SIGNAL: {
							struct drm_amdgpu_cs_chunk_syncobj *syncobj = (struct drm_amdgpu_cs_chunk_syncobj*)chunks[i]->chunk_data;
							cs->signalCnt += chunks[i]->length_dw/(sizeof(struct drm_amdgpu_cs_chunk_syncobj)/4);
							break;
						}
					}
				}
				cs->indBufs.SetTo(new IndirectBufferDef[cs->indBufCnt]);
				cs->waitSyncobjs.SetTo(new SyncobjRef[cs->waitCnt]);
				cs->waitPoints.SetTo(new uint64[cs->waitCnt]);
				cs->signalSyncobjs.SetTo(new SyncobjRef[cs->signalCnt]);
				cs->signalPoints.SetTo(new uint64[cs->signalCnt]);
				uint32 ibIdx = 0;
				uint32 waitIdx = 0, signalIdx = 0;

				for (size_t i = 0; i < args->in.num_chunks; i++) {
					switch(chunks[i]->chunk_id) {
						case AMDGPU_CHUNK_ID_IB: {
							auto ib = (struct drm_amdgpu_cs_chunk_ib*)chunks[i]->chunk_data;
							//printf("  AMDGPU_CHUNK_ID_IB: (va_start: %#" B_PRIx64 ", ib_bytes: %#" B_PRIx64 ")\n", ib->va_start, ib->ib_bytes);
							cs->indBufs[ibIdx].va = ib->va_start;
							cs->indBufs[ibIdx].size = ib->ib_bytes;
							ibIdx++;
							break;
						}
						case AMDGPU_CHUNK_ID_FENCE: {
							auto fence = (struct drm_amdgpu_cs_chunk_fence*)chunks[i]->chunk_data;
							//printf("  AMDGPU_CHUNK_ID_FENCE: (handle: %" B_PRIu32 ", offset: %#" B_PRIx64 ")\n", fence->handle, fence->offset);
							cs->userFence.buffer = teamState.Switch()->ThisBuffer(fence->handle);
							if (!cs->userFence.buffer.IsSet()) return ENOENT;
							cs->userFence.offset = fence->offset;
							break;
						}
						case AMDGPU_CHUNK_ID_SYNCOBJ_TIMELINE_WAIT: {
							auto syncobj = (struct drm_amdgpu_cs_chunk_syncobj*)chunks[i]->chunk_data;
							for (size_t j = 0; j < chunks[i]->length_dw; j += sizeof(struct drm_amdgpu_cs_chunk_syncobj) / 4) {
								//printf("  waitSyncobjs[%" B_PRIu32 "]: (%" B_PRIu32 ", %" B_PRIu64 ")\n", waitIdx, syncobj->handle, syncobj->point);
								cs->waitSyncobjs[waitIdx] = teamState.Switch()->ThisSyncobj(syncobj->handle);
								if (!cs->waitSyncobjs[waitIdx].IsSet()) {
									return ENOENT;
								}
								cs->waitPoints[waitIdx] = syncobj->point;
								waitIdx++;
								syncobj++;
							}
							break;
						}
						case AMDGPU_CHUNK_ID_SYNCOBJ_TIMELINE_SIGNAL: {
							auto syncobj = (struct drm_amdgpu_cs_chunk_syncobj*)chunks[i]->chunk_data;
							for (size_t j = 0; j < chunks[i]->length_dw; j += sizeof(struct drm_amdgpu_cs_chunk_syncobj) / 4) {
								//printf("  signalSyncobjs[%" B_PRIu32 "]: (%" B_PRIu32 ", %" B_PRIu64 ")\n", signalIdx, syncobj->handle, syncobj->point);
								cs->signalSyncobjs[signalIdx] = teamState.Switch()->ThisSyncobj(syncobj->handle);
								if (!cs->signalSyncobjs[signalIdx].IsSet()) return ENOENT;
								cs->signalPoints[signalIdx] = syncobj->point;
								signalIdx++;
								syncobj++;
							}
							break;
						}
						case AMDGPU_CHUNK_ID_BO_HANDLES: {
							auto boList = (struct drm_amdgpu_bo_list_in*)chunks[i]->chunk_data;
							cs->bufferCnt = boList->bo_number;
							cs->buffers.SetTo(new BReference<BufferObject>[boList->bo_number]);
							for (size_t j = 0; j < boList->bo_number; j++) {
								uint32 bufHandle = *(int32_t*)((char*)boList->bo_info_ptr + j*boList->bo_info_size);
								cs->buffers[j] = teamState.Switch()->ThisBuffer(bufHandle);
								if (!cs->buffers[j].IsSet()) return ENOENT;
							}
							break;
						}
					}
				}
				return teamState.Switch()->ScheduleCS(args->out.handle, cs.Detach());
			}
			case DRM_AMDGPU_WAIT_CS: {
				auto *args = (union drm_amdgpu_wait_cs*)arg;
				status_t res = teamState.Switch()->WaitCS(args->in.handle);
				args->out.status = (res < B_OK) ? 1 : 0;
				return res;
			}
		}
		return ENOSYS;
	}
	switch (request) {
		case DRM_IOCTL_GEM_CLOSE: {
			auto args = (struct drm_gem_close*)arg;
			return teamState.Switch()->FreeHandle(args->handle);
		}

		// syncobj
		case DRM_IOCTL_SYNCOBJ_CREATE: {
			auto args = (struct drm_syncobj_create*)arg;
			Syncobj::CreateFlags flags{};
			if ((DRM_SYNCOBJ_CREATE_SIGNALED & args->flags) != 0) flags.signaled = true;
			int32 res = teamState.Switch()->CreateSyncobj(flags);
			CheckRet(res);
			args->handle = res;
			return 0;
		}
		case DRM_IOCTL_SYNCOBJ_DESTROY: {
			auto args = (struct drm_syncobj_destroy*)arg;
			return teamState.Switch()->FreeHandle(args->handle);
		}
		case DRM_IOCTL_SYNCOBJ_WAIT: {
			auto args = (struct drm_syncobj_wait*)arg;
			Syncobj::WaitFlags flags{
				.all = (DRM_SYNCOBJ_WAIT_FLAGS_WAIT_ALL & args->flags) != 0,
				.domain = true,
				.forSubmit = (DRM_SYNCOBJ_WAIT_FLAGS_WAIT_FOR_SUBMIT & args->flags) != 0,
				.available = (DRM_SYNCOBJ_WAIT_FLAGS_WAIT_AVAILABLE & args->flags) != 0
			};
			uint32_t *handles = (uint32_t*)args->handles;
			ArrayDeleter<SyncobjRef> syncobjs(new SyncobjRef[args->count_handles]);
			for (uint32 i = 0; i < args->count_handles; i++) {
				syncobjs[i] = teamState.Switch()->ThisSyncobj(handles[i]);
			}
			ArrayDeleter<uint64> points(new uint64[args->count_handles]);
			memset(points.Get(), 0, sizeof(uint64)*args->count_handles);
			auto teamStateLocked = teamState.Switch();
			return Syncobj::Wait((uint32*)&args->first_signaled, syncobjs.Get(), points.Get(), args->count_handles, flags, args->timeout_nsec/1000);
		}
		case DRM_IOCTL_SYNCOBJ_TIMELINE_WAIT: {
			auto args = (struct drm_syncobj_timeline_wait*)arg;
			Syncobj::WaitFlags flags{
				.all = (DRM_SYNCOBJ_WAIT_FLAGS_WAIT_ALL & args->flags) != 0,
				.domain = true,
				.forSubmit = (DRM_SYNCOBJ_WAIT_FLAGS_WAIT_FOR_SUBMIT & args->flags) != 0,
				.available = (DRM_SYNCOBJ_WAIT_FLAGS_WAIT_AVAILABLE & args->flags) != 0
			};
			uint32_t *handles = (uint32_t*)args->handles;
			uint64_t *points = (uint64_t*)args->points;
			ArrayDeleter<SyncobjRef> syncobjs(new SyncobjRef[args->count_handles]);
			for (uint32 i = 0; i < args->count_handles; i++) {
				syncobjs[i] = teamState.Switch()->ThisSyncobj(handles[i]);
			}
			auto teamStateLocked = teamState.Switch();
			return Syncobj::Wait((uint32*)&args->first_signaled, syncobjs.Get(), points, args->count_handles, flags, args->timeout_nsec/1000);
		}
		case DRM_IOCTL_SYNCOBJ_TRANSFER: {
			auto args = (struct drm_syncobj_transfer*)arg;
			Syncobj::WaitFlags flags{
				.all = (DRM_SYNCOBJ_WAIT_FLAGS_WAIT_ALL & args->flags) != 0,
				.domain = true,
				.forSubmit = (DRM_SYNCOBJ_WAIT_FLAGS_WAIT_FOR_SUBMIT & args->flags) != 0,
				.available = (DRM_SYNCOBJ_WAIT_FLAGS_WAIT_AVAILABLE & args->flags) != 0
			};
			SyncobjRef dstSyncobj = teamState.Switch()->ThisSyncobj(args->dst_handle);
			if (!dstSyncobj.IsSet()) return B_BAD_VALUE;
			SyncobjRef srcSyncobj = teamState.Switch()->ThisSyncobj(args->src_handle);
			if (!srcSyncobj.IsSet()) return B_BAD_VALUE;
			auto teamStateLocked = teamState.Switch();
			return dstSyncobj->Transfer(args->dst_point, srcSyncobj, args->src_point, flags);
		}
		case DRM_IOCTL_SYNCOBJ_RESET: {
			auto args = (struct drm_syncobj_array*)arg;
			uint32_t *handles = (uint32_t*)args->handles;
			for (uint32 i = 0; i < args->count_handles; i++) {
				SyncobjRef syncobj = teamState.Switch()->ThisSyncobj(handles[i]);
				if (!syncobj.IsSet()) return B_BAD_VALUE;
				CheckRet(syncobj->Reset());
			}
			return 0;
		}
		case DRM_IOCTL_SYNCOBJ_ACCUMULATE: {
			auto args = (struct drm_syncobj_accumulate*)arg;
			SyncobjRef dstSyncobj = teamState.Switch()->ThisSyncobj(args->syncobj1);
			if (!dstSyncobj.IsSet()) return B_BAD_VALUE;
			SyncobjRef srcSyncobj = teamState.Switch()->ThisSyncobj(args->syncobj2);
			if (!srcSyncobj.IsSet()) return B_BAD_VALUE;
			auto teamStateLocked = teamState.Switch();
			return dstSyncobj->Accumulate(srcSyncobj, args->point);
		}
	}
	return ENOSYS;
}

extern "C" _EXPORT int drmIoctl(int fd, unsigned long request, void *arg)
{
	return drmIoctlInt(gTeamState, request, arg);
}
