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


void detect_cpu_features(struct SystemInfo *info){
    if(!info) return;

    FILE *info_file = fopen("/proc/cpuinfo", "r");
    if(info_file == NULL) return;

    char buffer[1024];

    while(fgets(buffer, sizeof(buffer), info_file) != NULL){

        if(strstr(buffer, "flags")){

            char *ptr = strchr(buffer, ':');
            if(ptr == NULL) continue;

            char temp[256];
            strcpy(temp, ptr + 1);   

            char *token = strtok(temp, " \t\n");

            while(token != NULL){

                if(strcmp(token, "avx") == 0){
                    info->avx_supported = true;
                }

                if(strcmp(token, "avx2") == 0){
                    info->avx2_supported = true;
                }

                if(info->avx_supported && info->avx2_supported){
                    break;
                }
                
                
                token = strtok(NULL, " \t\n");
            }

        }

        if(info->avx_supported && info->avx2_supported){
                    break;
                }
    }

    fclose(info_file);
}



int compute_ars(struct SystemInfo *info){
    if (!info) return 0;

    // NOT CAPABLE
    if (!info->avx_supported){
        return 0;
    }

    // LIMITED
    if (info->ram_mb < 8192 || 
        info->thread_count < 4 || 
        !info->avx2_supported){
        return 1;
    }

    // GOOD
    return 2;
}



void system_info_print(const struct SystemInfo *info, int ars_result){
    if(!info) return;

    printf("is_64bit: %d\n", info->is_64bit);
    printf("cpu_architecture: %s \n", info->cpu_architecture);
    printf("core_count: %d\n", info->core_count);
    printf("thread_count: %d\n", info->thread_count);
    printf("ram_mb %d\n", info->ram_mb);
    printf("avx_supported: %d\n", info->avx_supported);
    printf("avx2_supported: %d\n", info->avx2_supported);

    switch (ars_result)
    {
    case 0:
        printf("\nAI READINESS: NOT CAPABLE \n\n");
        break;
    case 1:
        printf("\nAI READINESS: LIMITED \n\n");
        break;
    case 2:
        printf("\nAI READINESS: GOOD \n\n");
        break;
    }
    

}

void format_system_info(const struct SystemInfo *raw_info, struct formatInfo *formatted_info, int ars_result){
    if(!raw_info) return ;
    if(!formatted_info) return;

    //format CPU info
    sprintf(formatted_info->cpu_info, "%s (%d cores / %d threads)", raw_info->cpu_architecture, 
        raw_info->core_count, raw_info->thread_count);


    // ram convertion from MB to GB
    int ram_mb = raw_info->ram_mb;
    int ram_gb = ram_mb / 1024;
    formatted_info->ram_GB = ram_gb;


    // avx text conversion
    if ((raw_info->avx_supported) == true) {
        strcpy(formatted_info->avx_text, "Yes" );
    } else{
        strcpy(formatted_info->avx_text, "No" );
    }


    // avx2 text conversion
    if ((raw_info->avx2_supported) == true) {
        strcpy(formatted_info->avx2_text, "Yes" );
    } else{
        strcpy(formatted_info->avx2_text, "No" );
    }


    //ARS Text conversion
    
    switch (ars_result)
    {
    case 0:
        strcpy(formatted_info->ars_text, "NOT CAPABLE");
        break;
    case 1:
        strcpy(formatted_info->ars_text, "LIMITED");
        break;
    default:
        strcpy(formatted_info->ars_text, "GOOD");
        break;
    }
    
}

void format_system_info_print(const struct formatInfo *formatted_info){

    printf("\nSystem Summary\n");
    printf("---------------\n");
    printf("CPU: %s\t\n", formatted_info->cpu_info);
    printf("RAM: %d GB\t\n", formatted_info->ram_GB);
    printf("AVX: %s\t\n", formatted_info->avx_text);
    printf("AVX2: %s\t\n\n", formatted_info->avx2_text);
    printf("AI Readiness: %s\t\n\n", formatted_info->ars_text);
}