//HOOK BuildUnit ROffset = 0x002EFAC9
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ _funcPtr,"QU(BuildUnit)"-0x006EFAC9 \n"
);

__asm__ volatile
(   //006EFAC9
    "JMP _funcPtr \n"
    "ADD ESP,4 \n"
	"xor ecx,ecx \n"
	"xor eax,eax\n"
	"jmp 0x006EFB0E - 0x006EFAC9 \n" //_CannotQueCommandInConstruct
	"nop\n"
	"nop\n"
	"nop\n"
	"nop\n"
	"nop\n"
	"nop\n"
    ".align 128, 0x0 \n"
);