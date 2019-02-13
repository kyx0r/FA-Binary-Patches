//HOOK MotionTick ROffset = 0x2A9010

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address,"QU(Unit_MotionTick)"-0x006A9010 \n"
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
