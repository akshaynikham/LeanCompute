#include "system_info.h"


void system_info_init (struct SystemInfo *info){
    if(!info) return;

    info->is_64bit = false;
    info->cpu_architecture[0] = '\0';
    info->core_count = -1;
    info->thread_count = -1;
    info->ram_mb = -1;
    info->avx_supported = false;
    info->avx2_supported = false;

}
