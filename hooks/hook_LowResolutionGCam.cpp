//HOOK LowResolutionGeonometricCamera ROffset = 0x3F8344

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address,"QU(LowResolutionGeonometricCamera)"-0x007F8344 \n"
);

__asm__ volatile
(
    "call . + by_pass_address \n"
	"pop edi \n"
    ".align 128, 0x0 \n"
);
