//HOOK LowResolutionGeonometricCamera2 ROffset = 0x3F7E93

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address,"QU(LowResolutionGeonometricCamera)"-0x007F7E93 \n"
);

__asm__ volatile
(
    "call . + by_pass_address \n"
	"pop edi \n"
    ".align 128, 0x0 \n"
);
