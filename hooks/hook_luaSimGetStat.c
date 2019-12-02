//HOOK luaSimGetStat ROffset = 0x2CC759

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address,"QU(luaSimGetStat)"-0x006CC759 \n"
);

__asm__ volatile
(
    "jmp . + by_pass_address \n"
    "nop \n"
    "nop \n"
    ".align 128, 0x0 \n"
);