//HOOK instance running ROffset = 0x4CF0D2
#include <stdlib.h>

__asm__
(
    ".equ by_pass_address,0x008CF23E-0x008CF0D2 \n"
);

__asm__ __volatile__
(
    "jmp . + by_pass_address \n"
	"push 0xE4E9AC \n"
	"push ebx \n"
    ".align 128, 0x0 \n"
);