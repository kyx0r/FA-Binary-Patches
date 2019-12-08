//HOOK FixCreateEntityDialog ROffset = 0x004D4010
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ FCED,"QU(FixCreateEntityDialog)"-0x008D4010 \n"
);

__asm__ volatile
(   //008D4010 SC_CreateEntityDialog
    "JMP FCED \n"
    "NOP \n"
    ".align 128, 0x0 \n"
);