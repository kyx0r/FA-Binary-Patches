//HOOK GeometricCamera ROffset = 0x3FF0AC

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address,"QU(GeometricCamera)"-0x007FF0AC \n"
);

__asm__ volatile
(
    "call . + by_pass_address \n"
	"fld dword ptr ss:[esp+0x10] \n"
    ".align 128, 0x0 \n"
);
