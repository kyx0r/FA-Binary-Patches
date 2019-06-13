//HOOK sync_beat ROffset = 0x33DB9C

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address,"QU(Sync_Beat)"-0x0073DB9C \n"
);

__asm__ volatile
(
    "call . + by_pass_address \n"
	"mov edx, dword ptr ds:[eax] \n"
    ".align 128, 0x0 \n"
);
