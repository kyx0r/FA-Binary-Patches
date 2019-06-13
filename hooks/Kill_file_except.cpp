//HOOK WallSelection ROffset = 0x555A1A
#include <stdlib.h>

__asm__
(
    ".equ by_pass_address, 0x00955A1A \n"
);

__asm__
(
	" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
	" \n " //!; Internal calls outside selected range (before)
	"GetLastError = 0x00C0F548   \n " //!; 0x00000000
	"_0x955890 =  9787536 - by_pass_address \n " 
	"_0xA89950 =  11049296 - by_pass_address \n " 
	" \n " //!; Start of selected range: 0x00955A1A
	"jmp L0xABEL_0x00955A3B  \n " //!; => 0x00955A3B
	"call dword ptr [GetLastError] \n " 
	"push eax \n " 
	"lea ecx,dword ptr [esp+0xC] \n " 
	"call _0x955890 \n " 
	"push 0xEAAE0C \n " 
	"lea ecx,dword ptr [esp+0xC] \n " 
	"push ecx \n " 
	"call _0xA89950 \n " 
	"L0xABEL_0x00955A3B: \n " 
	"mov dword ptr [edi+0x20],esi \n " 
	"pop edi \n " 
	"pop esi \n " 
	"add esp,0x2C \n " 
	"ret 0xC \n " 
	" \n " //! 0xFinis of selected range: 0x00955A45
	" \n " //!; Internal calls outside selected range (after)
	".align 128, 0x0 \n"
);


