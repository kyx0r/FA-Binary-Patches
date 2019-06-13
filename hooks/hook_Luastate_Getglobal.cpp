//HOOK Beat ROffset = 0x579D0

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address, 0x004579D0 \n"
);

__asm__
(
	" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
	" \n " //!; Start of selected range: 0x004579D0
	"_0x90A690 =  9479824 - by_pass_address \n " 
	"_0x908F60 =  9473888 - by_pass_address \n " 
	"_0x9075D0 =  9467344 - by_pass_address \n " 
	//"push 0xFFFFFFFF \n " 
	//"push 0xB77CF1 \n " 
	//"mov eax,dword ptr [0x0] \n " 
	//"push eax \n " 
	//"mov dword ptr [0x0],esp \n " 
	"sub esp,0x24 \n " 
	"push esi \n " 
	"lea eax,dword ptr [esp+0x8] \n " 
	"push eax \n " 
	"mov dword ptr [esp+0x8],0x0 \n " 
	"call _0x90A690 \n " 
	"mov ecx,dword ptr [esp+0x30] \n " 
	"mov dword ptr [esp+0x24],0x1 \n " 
	"mov esi,dword ptr [esp+0x2C] \n " 
	"push ecx \n " 
	"push esi \n " 
	"mov ecx,eax \n " 
	"call _0x908F60 \n " 
	"lea ecx,dword ptr [esp+0x8] \n " 
	"mov dword ptr [esp+0x4],0x1 \n " 
	"mov byte ptr [esp+0x24],0x0 \n " 
	"call _0x9075D0 \n " 
	"mov ecx,dword ptr [esp+0x1C] \n " 
	"mov eax,esi \n " 
	"pop esi \n " 
	//"mov dword ptr [0x0],ecx \n " 
	"add esp,0x24 \n " 
	"ret 0x8 \n " 
	" \n " //! 0xFinis of selected range: 0x00457A3D
	" \n " //!; Internal calls outside selected range (after)
);
