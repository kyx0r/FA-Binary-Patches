//HOOK SetCommandSource ROffset = 0x00308A9A
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address,"QU(SSFARegDescFunc)"-0x00708A9A \n"
);

__asm__ volatile
(   //00708A9A
    "call . + by_pass_address \n"
	"mov dword ptr [0x010B8AEC], 0xE2FD9C\n"
    ".align 128, 0x0 \n"
);