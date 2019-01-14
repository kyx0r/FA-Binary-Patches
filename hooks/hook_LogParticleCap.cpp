//HOOK LogParticleCap (removes the info log) runout ROffset = 0x93A9B

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"


__asm__ volatile
(
    "nop \n"
	"nop \n"
	"nop \n"
	"nop \n"
	"nop \n"
    ".align 128, 0x0 \n"
);
