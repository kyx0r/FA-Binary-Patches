//HOOK recvfrom ROffset = 0x8A280

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address,"QU(_recvfrom)"-0x0048A280 \n"
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