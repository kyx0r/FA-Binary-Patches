//HOOK FindScript ROffset = 0xC74B0

/*
-- This function does the lua script finding.
It is thread mutable. So everything uses it.
If optimised here, expect to speed everything up.
*/


#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address, 0x004C74B0 \n"
);


__asm__
(
	" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
	" \n " //!; Start of selected range: 0x004C74B0
	"_0x9072B0 =  9466544 - by_pass_address \n "  
	"_0x90C590 =  9487760 - by_pass_address \n " 
	"_0x907D80 =  9469312 - by_pass_address \n " 
	"_0x90CDF0 =  9489904 - by_pass_address \n " 
	"_0x90D000 =  9490432 - by_pass_address \n " 
	"_0x908A70 =  9472624 - by_pass_address \n " 
	"_0x90C5A0 =  9487776 - by_pass_address \n " 	
	//"push 0xFFFFFFFF \n " 
	//"push 0xB82301 \n " 
	
	//"push 0xFFFFFFFF \n " 
	//"push 0xB82301 \n " 
	//"push eax \n " 
	"sub esp,0x2c \n " 
	"push ebx \n " 
	"mov ebx,dword ptr [esp+0x34] \n " 
	"push ebp \n " 
	"push esi \n " 
	"push edi \n " 
	"mov edi,ecx \n " 
	"add edi,0x20 \n " 
	"mov ecx,edi \n " 
	"mov dword ptr [esp+0x14],0x0 \n " 
	
	//"call _0x9072B0 \n " 
	"mov eax,dword ptr [ecx+0x8] \n " 
	"mov ecx,dword ptr [eax] \n " 
	"mov edx,dword ptr [ecx+0x10] \n " 
	"mov eax,dword ptr [edx+0x44] \n " 
	"mov eax,dword ptr [eax+0x44] \n " 
	
	"mov esi,eax \n " 
	"mov ebp,dword ptr [esi] \n " 
	"push ebp \n " 
	"mov dword ptr [esp+0x24],ebp \n " 
	"call _0x90C590 \n " 
	"pop ebp \n " 
	"mov dword ptr [esp+0x24],eax \n " 
	"push esi \n " 
	"lea eax,dword ptr [esp+0x2C] \n " 
	"push eax \n " 
	"mov ecx,edi \n " 
	"mov dword ptr [esp+0x40],0x1 \n " 
	"call _0x907D80 \n " 
	"mov ecx,dword ptr [esp+0x44] \n " 
	"mov edx,dword ptr [esi] \n " 
	"push ecx \n " 
	"push edx \n " 
	"call _0x90CDF0 \n " 
	"mov eax,dword ptr [esi] \n " 
	"push eax \n " 
	"call _0x90C590 \n " 
	"mov ecx,dword ptr [esp+0x38] \n " 
	"mov dword ptr [esp+0x24],esi \n " 
	"mov dword ptr [esp+0x28],eax \n " 
	"mov esi,dword ptr [esi] \n " 
	"push ecx \n " 
	"push esi \n " 
	"call _0x90D000 \n " 
	"add esp,0x14 \n " 
	"lea edx,dword ptr [esp+0x18] \n " 
	"push edx \n " 
	"mov ecx,ebx \n " 
	"call _0x908A70 \n " 
	"mov byte ptr [esp+0x38],0x0 \n " 
	"mov eax,dword ptr [esp+0x24] \n " 
	"push eax \n " 
	"push ebp \n " 
	"mov dword ptr [esp+0x1C],0x1 \n " 
	"call _0x90C5A0 \n " 
	"mov ecx,dword ptr [esp+0x38] \n " 
	"add esp,0x8 \n " 
	"pop edi \n " 
	"pop esi \n " 
	"pop ebp \n " 
	"mov eax,ebx \n " 
	"pop ebx \n " 
	"add esp,0x2C \n " 
	"ret 0x8 \n " 	
	"mov esi, esi \n"
	".align 8192, 0x0 \n"
	" \n " //! 0xFinis of selected range: 0x004C7578
	" \n " //!; Internal calls outside selected range (after)
);

