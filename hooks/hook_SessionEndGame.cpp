//HOOK decode ROffset = 0x4984B0

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address,"QU(SessionEndGame)"-0x008984B0 \n"
);

__asm__ volatile
(
    "jmp . + by_pass_address \n"
	"nop \n"
	"nop \n"
	"nop \n"
	"nop \n"
	"nop \n"
	"nop \n"
	"nop \n"
	"nop \n"
	"nop \n"
	"nop \n"
    ".align 128, 0x0 \n"
);
