//HOOK WallSelection ROffset = 0x5071FE
#include <stdlib.h>

__asm__
(
    ".equ by_pass_address, 0x0090723B-0x009071FE \n"
);

__asm__ __volatile__
(
    "jmp . + by_pass_address \n"
    ".align 128, 0x0 \n"
);


