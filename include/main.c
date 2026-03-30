#include <stdio.h>
#include "system_info.h"

int main(){

    struct SystemInfo test_info;
    struct formatInfo format_info;
    system_info_init(&test_info);
    detect_os_bitness(&test_info);
    detect_cpu_parallelism(&test_info);
    detect_ram(&test_info);
    detect_cpu_features(&test_info);
    int ars_result = compute_ars(&test_info);
    // system_info_print(&test_info, ars_result);
    format_system_info(&test_info, &format_info, ars_result);
    format_system_info_print(&format_info);
     
    return 0;
}
