
#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H
#include <stdbool.h>

struct SystemInfo {
    bool is_64bit;
    char cpu_architecture[30];
    int core_count;
    int thread_count;
    int ram_mb;
    bool avx_supported;
    bool avx2_supported;
};

struct formatInfo
{
    char cpu_info[256];
    int ram_GB;
    char avx_text[256];
    char avx2_text[256];
    char ars_text[256];
};


void system_info_init(struct SystemInfo *info);
void detect_os_bitness(struct SystemInfo *info);
void detect_cpu_parallelism(struct SystemInfo *info);
void detect_ram(struct SystemInfo *info);
void system_info_print(const struct SystemInfo *info,int ars_result);
void detect_cpu_features(struct SystemInfo *info);
void detect_cpu_features(struct SystemInfo *info);
int compute_ars(struct SystemInfo *info);
void format_system_info(const struct SystemInfo *raw_info, struct formatInfo *formatted_info, int ars_result);
void format_system_info_print(const struct formatInfo *formatted_info);
#endif