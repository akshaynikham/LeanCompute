#include <stdio.h>
#include "system_info.h"

int main(){

    struct SystemInfo test_info;
    system_info_init(&test_info);
    detect_os_bitness(&test_info);
    system_info_print(&test_info);
     
    return 0;
}