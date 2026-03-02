
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

#endif