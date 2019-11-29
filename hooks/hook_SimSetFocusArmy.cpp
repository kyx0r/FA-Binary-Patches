//HOOK SetCommandSource ROffset = 0x00308A9A
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ _SSFARegDesc,"QU(SSFARegDesc)"\n"
);

__asm__ volatile
(   //00708A9A
    "mov eax, _SSFARegDesc \n"
	"mov dword ptr [0x010B8AEC], 0xE2FD9C\n"
    ".align 128, 0x0 \n"
);