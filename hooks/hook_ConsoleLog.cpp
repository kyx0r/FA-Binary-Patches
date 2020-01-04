//HOOK ConsoleLog ROffset = 0x0001CE0A
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ _funcPtr,"QU(ConsoleLog)"-0x0041CE0A \n"
);

__asm__ volatile
(   //0041CE0A
    "JMP _funcPtr \n"
    "NOP \n"
    "NOP \n"
    ".align 128, 0x0 \n"
);