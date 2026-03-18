#include "system_info.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
            char *ptr = strchr(buffer, ':');
            if(ptr != NULL) {cpu_cores = atoi(ptr + 1);}
            
        }
    }

    fclose(info_file);

    info->thread_count = processor_count;
    info->core_count = cpu_cores;

}

void detect_ram(struct SystemInfo *info){
    if (!info) return;

    FILE *info_file;

    info_file = fopen("/proc/meminfo", "r");

    if(info_file == NULL) return;

    char buffer[256];
    int ram_MB = 0;

    while (fgets(buffer, sizeof(buffer), info_file)!= NULL)
    {
        if (strstr(buffer,"MemTotal")){
            char *ptr = strchr(buffer, ':');
            if(ptr !=NULL ) {ram_MB = atoi(ptr + 1);}
            ram_MB = ram_MB / 1024;
            info->ram_mb = ram_MB;
            break;
        }
    }

    fclose(info_file);
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


