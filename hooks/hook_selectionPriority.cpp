//HOOK selectionPriority ROffset = 0x463C11

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address,"QU(selectionPriority)"-0x00863C11 \n"
);

__asm__ volatile
(
    "jmp . + by_pass_address \n"
	"nop \n"
	"nop \n"
	"nop \n"
    ".align 128, 0x0 \n"
);
