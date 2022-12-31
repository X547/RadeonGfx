#pragma once

#include <SupportDefs.h>


uint32 radeon_gpu_get_engine_clock();
uint32 radeon_gpu_get_memory_clock();
void radeon_gpu_set_engine_clock(uint32 value);
void radeon_gpu_set_memory_clock(uint32 value);
int32 radeon_thermal_query();
