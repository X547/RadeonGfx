#include "RadeonServerDrm.h"
#include "RadeonServer.h"
#include "DrmInterface.h"
#define _DEFAULT_SOURCE
extern "C" {
#include <xf86drm.h>
#include <libdrm/drm.h>
#include <libdrm/amdgpu_drm.h>
}
#include <stdio.h>

#define CheckLink(err) {status_t _err = (err); if (_err < B_OK) {link.StartMessage(_err); link.Flush(); return;}}


void RadeonHandleDrmMessage(BPrivate::PortLink &link, ExternalRef<TeamState> state, int32 what)
{
	switch (what) {
		case radeonMmapMsg: {
			int32 handle;
			link.Read(&handle);
			void *adr;
			CheckLink(state.Switch()->CpuMap(adr, handle, 0, 0, 0));
			area_id area;
			addr_t areaOfs;
			area = area_for(adr);
			area_info areaInfo;
			get_area_info(area, &areaInfo);
			areaOfs = (addr_t)adr - (addr_t)areaInfo.address;
			link.StartMessage(B_OK);
			link.Attach<int32>(area);
			link.Attach<uint64>(areaOfs);
			link.Flush();
			return;
		}
		case radeonMunmapMsg: {
			link.StartMessage(B_OK);
			link.Flush();
			return;
		}
		case radeonIoctlMsg: {
			int fd;
			unsigned long request;
			link.Read(&fd);
			link.Read(&request);
			unsigned long requestCmd = request%0x100;
			if (requestCmd >= DRM_COMMAND_BASE && requestCmd < DRM_COMMAND_END) {
				requestCmd -= DRM_COMMAND_BASE;
				switch (requestCmd) {
					case DRM_AMDGPU_INFO: {
						struct drm_amdgpu_info args{};
						link.Read(&args.return_size);
						link.Read(&args.query);
						ArrayDeleter<uint8> returnData(new uint8[args.return_size]);
						args.return_pointer = (addr_t)returnData.Get();
						switch (args.query) {
							case AMDGPU_INFO_ACCEL_WORKING:
							case AMDGPU_INFO_VRAM_USAGE:
							case AMDGPU_INFO_GTT_USAGE:
							case AMDGPU_INFO_GDS_CONFIG:
							case AMDGPU_INFO_VRAM_GTT:
							case AMDGPU_INFO_DEV_INFO:
							case AMDGPU_INFO_VIS_VRAM_USAGE:
								// no input arguments
								break;
							case AMDGPU_INFO_READ_MMR_REG: {
								link.Read(&args.read_mmr_reg, sizeof(args.read_mmr_reg));
								break;
							}
		/*
							case AMDGPU_INFO_CRTC_FROM_ID:
							case AMDGPU_INFO_HW_IP_INFO:
							case AMDGPU_INFO_HW_IP_COUNT:
							case AMDGPU_INFO_TIMESTAMP:
							case AMDGPU_INFO_FW_VERSION:
							case AMDGPU_INFO_NUM_BYTES_MOVED:
							case AMDGPU_INFO_NUM_EVICTIONS:
							case AMDGPU_INFO_MEMORY:
							case AMDGPU_INFO_VCE_CLOCK_TABLE:
							case AMDGPU_INFO_VBIOS:
							case AMDGPU_INFO_SENSOR:
							case AMDGPU_INFO_NUM_VRAM_CPU_PAGE_FAULTS:
							case AMDGPU_INFO_VRAM_LOST_COUNTER:
							case AMDGPU_INFO_RAS_ENABLED_FEATURES:
							case AMDGPU_INFO_VIDEO_CAPS:
								break;
		*/
							default:
								CheckLink(ENOSYS);
						}
						status_t res = drmIoctlInt(state, request, &args);
						link.StartMessage(res);
						link.Attach(args.return_size);
						link.Attach(returnData.Get(), args.return_size);
						link.Flush();
						return;
					}
					case DRM_AMDGPU_GEM_METADATA: {
						struct drm_amdgpu_gem_metadata args;
						link.Read(&args, offsetof(struct drm_amdgpu_gem_metadata, data));
						switch (args.op) {
							case AMDGPU_GEM_METADATA_OP_SET_METADATA: {
								link.Read(&args.data, sizeof(args.data));
								status_t res = drmIoctlInt(state, request, &args);
								link.StartMessage(res);
								link.Flush();
								return;
							}
							case AMDGPU_GEM_METADATA_OP_GET_METADATA: {
								status_t res = drmIoctlInt(state, request, &args);
								link.StartMessage(res);
								link.Attach(&args.data, sizeof(args.data));
								link.Flush();
								return;
							}
						}
						link.StartMessage(ENOSYS);
						link.Flush();
					}
					case DRM_AMDGPU_CTX: {
						union drm_amdgpu_ctx args;
						link.Read(&args.in, sizeof(args.in));
						status_t res = drmIoctlInt(state, request, &args);
						link.StartMessage(res);
						link.Attach(&args.out, sizeof(args.out));
						link.Flush();
						return;
					}
					case DRM_AMDGPU_GEM_CREATE: {
						union drm_amdgpu_gem_create args;
						link.Read(&args.in, sizeof(args.in));
						status_t res = drmIoctlInt(state, request, &args);
						link.StartMessage(res);
						link.Attach(&args.out, sizeof(args.out));
						link.Flush();
						return;
					}
					case DRM_AMDGPU_GEM_OP: {
						struct drm_amdgpu_gem_op args;
						link.Read(&args, offsetof(struct drm_amdgpu_gem_op, value));
						switch (args.op) {
							case AMDGPU_GEM_OP_GET_GEM_CREATE_INFO: {
								struct drm_amdgpu_gem_create_in boInfo = {};
								args.value = (uintptr_t)&boInfo;
								status_t res = drmIoctlInt(state, request, &args);
								link.StartMessage(res);
								link.Attach(&boInfo, sizeof(boInfo));
								link.Flush();
								return;
							}
							default:
								link.StartMessage(ENOSYS);
								link.Flush();
								return;
						}
						return;
					}
					case DRM_AMDGPU_GEM_USERPTR: {
						struct drm_amdgpu_gem_userptr args;
						link.Read(&args, sizeof(args));
						status_t res = drmIoctlInt(state, request, &args);
						link.StartMessage(res);
						link.Attach(&args.handle, sizeof(args.handle));
						link.Flush();
						return;
					}
					case DRM_AMDGPU_GEM_VA: {
						struct drm_amdgpu_gem_va args;
						link.Read(&args, sizeof(args));
						status_t res = drmIoctlInt(state, request, &args);
						link.StartMessage(res);
						link.Flush();
						return;
					}
					case DRM_AMDGPU_GEM_MMAP: {
						union drm_amdgpu_gem_mmap args;
						link.Read(&args.in, sizeof(args.in));
						status_t res = drmIoctlInt(state, request, &args);
						link.StartMessage(res);
						link.Attach(&args.out, sizeof(args.out));
						link.Flush();
						return;
					}
					case DRM_AMDGPU_CS: {
						union drm_amdgpu_cs args;
						link.Read(&args.in, sizeof(args.in));

						ArrayDeleter<ObjectDeleter<struct drm_amdgpu_cs_chunk> > chunks(new ObjectDeleter<struct drm_amdgpu_cs_chunk>[args.in.num_chunks]);
						for (size_t i = 0; i < args.in.num_chunks; i++) {
							chunks[i].SetTo(new struct drm_amdgpu_cs_chunk());
							link.Read(chunks[i].Get(), sizeof(struct drm_amdgpu_cs_chunk));
						}
						args.in.chunks = (addr_t)&chunks[0];

						ObjectDeleter<struct drm_amdgpu_bo_list_in> chunk_data_handles;

						ArrayDeleter<uint32> chunk_data_ib;
						ArrayDeleter<uint32> chunk_data_fence;
						ArrayDeleter<uint32> chunk_data_dependencies;
						ArrayDeleter<uint32> chunk_data_syncobj_wait;
						ArrayDeleter<uint32> chunk_data_syncobj_signal;

						ArrayDeleter<uint8> bo_info_array;
						for (size_t i = 0; i < args.in.num_chunks; i++) {
							switch(chunks[i]->chunk_id) {
								case AMDGPU_CHUNK_ID_IB: {
									chunk_data_ib.SetTo(new uint32[chunks[i]->length_dw]);
									link.Read(&chunk_data_ib[0], 4*chunks[i]->length_dw);
									chunks[i]->chunk_data = (addr_t)&chunk_data_ib[0];
									break;
								}
								case AMDGPU_CHUNK_ID_FENCE: {
									chunk_data_fence.SetTo(new uint32[chunks[i]->length_dw]);
									link.Read(&chunk_data_fence[0], 4*chunks[i]->length_dw);
									chunks[i]->chunk_data = (addr_t)&chunk_data_fence[0];
									break;
								}
								case AMDGPU_CHUNK_ID_DEPENDENCIES: {
									chunk_data_dependencies.SetTo(new uint32[chunks[i]->length_dw]);
									link.Read(&chunk_data_dependencies[0], 4*chunks[i]->length_dw);
									chunks[i]->chunk_data = (addr_t)&chunk_data_dependencies[0];
									break;
								}
								case AMDGPU_CHUNK_ID_SYNCOBJ_TIMELINE_WAIT: {
									chunk_data_syncobj_wait.SetTo(new uint32[chunks[i]->length_dw]);
									link.Read(&chunk_data_syncobj_wait[0], 4*chunks[i]->length_dw);
									chunks[i]->chunk_data = (addr_t)&chunk_data_syncobj_wait[0];
									break;
								}
								case AMDGPU_CHUNK_ID_SYNCOBJ_TIMELINE_SIGNAL: {
									chunk_data_syncobj_signal.SetTo(new uint32[chunks[i]->length_dw]);
									link.Read(&chunk_data_syncobj_signal[0], 4*chunks[i]->length_dw);
									chunks[i]->chunk_data = (addr_t)&chunk_data_syncobj_signal[0];
									break;
								}
								case AMDGPU_CHUNK_ID_BO_HANDLES: {
									chunk_data_handles.SetTo(new struct drm_amdgpu_bo_list_in());
									link.Read(chunk_data_handles.Get(), sizeof(struct drm_amdgpu_bo_list_in));
									chunks[i]->chunk_data = (addr_t)chunk_data_handles.Get();

									bo_info_array.SetTo(new uint8[chunk_data_handles->bo_info_size*chunk_data_handles->bo_number]);
									link.Read(&bo_info_array[0], chunk_data_handles->bo_info_size*chunk_data_handles->bo_number);
									chunk_data_handles->bo_info_ptr = (addr_t)&bo_info_array[0];
									break;
								}
								default:
									CheckLink(ENOSYS);
							}
						}

						status_t res = drmIoctlInt(state, request, &args);
						link.StartMessage(res);
						link.Attach(&args.out, sizeof(args.out));
						link.Flush();
						return;
					}
					case DRM_AMDGPU_WAIT_CS: {
						union drm_amdgpu_wait_cs args;
						link.Read(&args.in, sizeof(args.in));
						status_t res = drmIoctlInt(state, request, &args);
						link.StartMessage(res);
						link.Attach(&args.out, sizeof(args.out));
						link.Flush();
						return;
					}
				}
			}
			switch (request) {
				case DRM_IOCTL_GEM_CLOSE: {
					struct drm_gem_close args;
					link.Read(&args, sizeof(args));
					status_t res = drmIoctlInt(state, request, &args);
					link.StartMessage(res);
					link.Flush();
					return;
				}
				case DRM_IOCTL_PRIME_HANDLE_TO_FD: {
					struct drm_prime_handle args;
					link.Read(&args.handle, sizeof(args.handle));
					status_t res = drmIoctlInt(state, request, &args);
					link.StartMessage(res);
					link.Attach(&args.fd, sizeof(args.fd));
					link.Flush();
					return;
				}
				case DRM_IOCTL_PRIME_FD_TO_HANDLE: {
					struct drm_prime_handle args;
					link.Read(&args.fd, sizeof(args.fd));
					status_t res = drmIoctlInt(state, request, &args);
					link.StartMessage(res);
					link.Attach(&args.handle, sizeof(args.handle));
					link.Flush();
					return;
				}

				// syncobj
				case DRM_IOCTL_SYNCOBJ_CREATE: {
					struct drm_syncobj_create args;
					link.Read(&args.flags, sizeof(args.flags));
					status_t res = drmIoctlInt(state, request, &args);
					link.StartMessage(res);
					link.Attach(&args.handle, sizeof(args.handle));
					link.Flush();
					return;
				}
				case DRM_IOCTL_SYNCOBJ_DESTROY: {
					struct drm_syncobj_destroy args;
					link.Read(&args, sizeof(args));
					status_t res = drmIoctlInt(state, request, &args);
					link.StartMessage(res);
					link.Flush();
					return;
				}
				case DRM_IOCTL_SYNCOBJ_HANDLE_TO_FD: {
					struct drm_syncobj_handle args;
					link.Read(&args.handle, sizeof(args.handle));
					status_t res = drmIoctlInt(state, request, &args);
					link.StartMessage(res);
					link.Attach(&args.fd, sizeof(args.fd));
					link.Flush();
					return;
				}
				case DRM_IOCTL_SYNCOBJ_FD_TO_HANDLE: {
					struct drm_syncobj_handle args;
					link.Read(&args.fd, sizeof(args.fd));
					status_t res = drmIoctlInt(state, request, &args);
					link.StartMessage(res);
					link.Attach(&args.handle, sizeof(args.handle));
					link.Flush();
					return;
				}
				case DRM_IOCTL_SYNCOBJ_WAIT: {
					struct drm_syncobj_wait args;
					link.Read(&args, offsetof(drm_syncobj_wait, first_signaled));
					ArrayDeleter<uint32_t> handles(new uint32_t[args.count_handles]);
					args.handles = (uint64_t)(addr_t)&handles[0];
					link.Read(&handles[0], sizeof(uint32_t)*args.count_handles);
					status_t res = drmIoctlInt(state, request, &args);
					link.StartMessage(res);
					link.Attach(&args.first_signaled, sizeof(args.first_signaled));
					link.Flush();
					return;
				}
				case DRM_IOCTL_SYNCOBJ_TIMELINE_WAIT: {
					struct drm_syncobj_timeline_wait args;
					link.Read(&args, offsetof(drm_syncobj_timeline_wait, first_signaled));
					ArrayDeleter<uint32_t> handles(new uint32_t[args.count_handles]);
					ArrayDeleter<uint64_t> points(new uint64_t[args.count_handles]);
					args.handles = (uint64_t)(addr_t)&handles[0];
					args.points = (uint64_t)(addr_t)&points[0];
					link.Read(&handles[0], sizeof(uint32_t)*args.count_handles);
					link.Read(&points[0], sizeof(uint64_t)*args.count_handles);
					status_t res = drmIoctlInt(state, request, &args);
					link.StartMessage(res);
					link.Attach(&args.first_signaled, sizeof(args.first_signaled));
					link.Flush();
					return;
				}
				case DRM_IOCTL_SYNCOBJ_TRANSFER: {
					struct drm_syncobj_transfer args;
					link.Read(&args, sizeof(args));
					status_t res = drmIoctlInt(state, request, &args);
					link.StartMessage(res);
					link.Flush();
					return;
				}
				case DRM_IOCTL_SYNCOBJ_RESET: {
					struct drm_syncobj_array args;
					link.Read(&args.count_handles, sizeof(args.count_handles));
					ArrayDeleter<uint32_t> handles(new uint32_t[args.count_handles]);
					args.handles = (uint64_t)(addr_t)&handles[0];
					link.Read(&handles[0], sizeof(uint32_t)*args.count_handles);
					status_t res = drmIoctlInt(state, request, &args);
					link.StartMessage(res);
					link.Flush();
					return;
				}
				case DRM_IOCTL_SYNCOBJ_ACCUMULATE: {
					struct drm_syncobj_accumulate args;
					link.Read(&args, sizeof(args));
					status_t res = drmIoctlInt(state, request, &args);
					link.StartMessage(res);
					link.Flush();
					return;
				}
			}
			return;
		}
	}
	link.StartMessage(ENOSYS);
	link.Flush();
}
