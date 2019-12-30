//HOOK GetDepositsAroundPoint ROffset = 0x00442E8A
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ _UGDAPRegDesc,"QU(UGDAPRegDesc)"\n"
);

__asm__ volatile
(   //00842E8A
    "mov eax, _UGDAPRegDesc \n"
    "mov dword ptr [0x010C3CA8], 0xE43408 \n"
    ".align 128, 0x0 \n"
);