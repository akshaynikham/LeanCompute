#include "system_info.h"
#include "stdio.h"

void system_info_print(const struct SystemInfo *info){
    if(!info) return;

    printf("is_64bit: %d\n", info->is_64bit);
    printf("cpu_architecture: %s \n", info->cpu_architecture);
    printf("core_count: %d\n", info->core_count);
    printf("thread_count: %d\n", info->thread_count);
    printf("ram_mb %d\n", info->ram_mb);
    printf("avx_supported: %d\n", info->avx_supported);
    printf("avx2_supported: %d\n", info->avx2_supported);

}

