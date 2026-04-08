#include "system_info.h"
#include <sys/utsname.h>
#include <stdio.h>
#include <string.h>

void detect_os_bitness(struct SystemInfo *info){
    if(!info) return ;

    struct utsname u;
    if (uname(&u) !=0 ) return;

    strcpy(info->cpu_architecture,u.machine);

    if ( strstr(info->cpu_architecture,"64")){
        info->is_64bit = true;
    }
    else{
        info->is_64bit = false;
    }
    
}