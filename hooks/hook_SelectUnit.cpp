//HOOK SelectUnit ROffset = 0x004C05FE
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ _funcPtr,"QU(SelectUnit)"-0x008C05FE \n"
);

__asm__ volatile
(   //008C05FE
    "JMP _funcPtr \n"
    "NOP \n"
    "NOP \n"
    "NOP \n"
    "NOP \n"
    ".align 128, 0x0 \n"
);