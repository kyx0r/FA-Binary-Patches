//HOOK lua_func_check ROffset = 0x1F910

/*
-- This function does type check for callbacks.
For some reason it makes a great use.
*/


#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address, 0x0041F910 \n"
);

__asm__
(
	" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
	" \n " //!; Start of selected range: 0x0041F910
	"_0x908A40 =  9472576 - by_pass_address \n " 
	"_0x907810 =  9467920 - by_pass_address \n " 
	"_0x9072D0 =  9466576 - by_pass_address \n " 
	//"mov eax,dword ptr [0x0] \n " 
	//"push 0xFFFFFFFF \n " 
	//"push 0xB792B8 \n "
	//"sub esp, 0x8 \n"	
	"push eax \n " 
	"mov eax,dword ptr [esp+0xc] \n " 
	//"mov dword ptr [0x0],esp \n " 
	"push esi \n " 
	"mov esi,dword ptr [esp+0xc] \n " 
	"push eax \n " 
	"mov ecx,esi \n " 
	"call _0x908A40 \n " //luaobject constructor
	"mov ecx,esi \n " 
	"mov dword ptr [esp+0x4],0x0 \n " 
	"call _0x907810 \n " 
	"test al,al \n " 
	"jne L0xABEL_0x0041F955  \n " //!; => 0x0041F955
	"push 0xE01214 \n " 
	"mov ecx,esi \n " 
	"call _0x9072D0 \n " 
	"L0xABEL_0x0041F955: \n " 
	"mov ecx,dword ptr [esp-0x4] \n " 
	"mov eax,esi \n " 
	"pop esi \n "
	"add esp, 0x4 \n"
	"ret 0x8 \n " 
	"pop edi \n"
	".align 128, 0x0 \n"
	" \n " //! 0xFinis of selected range: 0x0041F968
	" \n " //!; Internal calls outside selected range (after)
);
