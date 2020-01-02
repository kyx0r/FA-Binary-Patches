//HOOK SimArmyCreate ROffset = 0x002FF3D1
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ _funcPtr,"QU(SimArmyCreate)"-0x006FF3D1 \n"
);

__asm__ volatile
(   //006FF3D1
    "JMP _funcPtr \n"
    "NOP \n"
    ".align 128, 0x0 \n"
);