//HOOK Beat ROffset = 0x13F010

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address,"QU(Update_Pipeline_Stream)"-0x0053F010 \n"
);

__asm__
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

	