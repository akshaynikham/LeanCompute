#include "system_info.h"
#include <stdio.h>
#include <string.h>

void detect_cpu_parallelism(struct SystemInfo *info){
    if(!info) return;

    FILE *info_file;
    
    info_file = fopen("/proc/cpuinfo", "r");

    if (info_file == NULL) return ;

    char buffer[256];
    int processor_count = 0;
    int cpu_cores = 0;

    while(fgets(buffer,sizeof(buffer), info_file) != NULL){

        if (strstr(buffer,"processor")){
            processor_count++;
        }

        if (strstr(buffer, "cpu cores") && cpu_cores == 0){
            // cpu_cores = atoi(buffer);
        }
    }

    fclose(info_file);

    printf("total processor: %d \n", info->thread_count);
    printf("cpu cores: %d \n", cpu_cores);

}



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


