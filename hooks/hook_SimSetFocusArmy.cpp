//HOOK SetCommandSource ROffset = 0x00308A9A
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ reg_struct_address,"QU(SSFARegDesc)" \n"
);

__asm__ volatile
(   //00708A9A
    "MOV EAX,reg_struct_address \n"
    ".align 128, 0x0 \n"
);


