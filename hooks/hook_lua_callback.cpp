//HOOK luacallback ROffset = 0x181AA0

/*
-- This function allows to make a callback to the functions like
OnDestroy, OnCreate, etc. 
Takes in object as param and a char array literal.
This function is crucial for performance so I will do manual optimization on it
since compiler failed. 
*/


#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address, 0x00581AA0 \n"
);


__asm__
(
	" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
	" \n " //!; Internal calls outside selected range (before)
	"CScriptObject_FindScript =  5010608 - by_pass_address\n " 
	"_0x41F910 =  4323600 - by_pass_address\n "
	"_0x4C7410 =  5010448 - by_pass_address\n "
	"LuaUnspecifiedBoolType =  9466944 - by_pass_address\n "
	"LuaObject_LuaObject =  9472576 - by_pass_address\n " 
	"_0x582DD0 =  5778896 - by_pass_address\n "
	"_0x9075D0 =  9467344 - by_pass_address\n "	
	" \n " //!; Start of selected range: 0x00581AA0
	"push ebp \n " 
	"mov ebp,esp \n " 
	//"push 0xFFFFFFFF \n " 
	//"push 0xB886E0 \n " 
	"push eax \n " 
	"sub esp,0x4C \n " 
	"push ebx \n " 
	"push esi \n " 
	"push edi \n " 
	"mov esi,ecx \n " 
	"xor edi,edi \n " 
	"mov dword ptr [ebp-0x10],esp \n " 
	"lea eax,dword ptr [esi+0x4] \n " 
	"mov dword ptr [ebp-0x24],eax \n " 
	"mov ecx,dword ptr [eax] \n " 
	"lea edx,dword ptr [ebp-0x24] \n " 
	"mov dword ptr [ebp-0x20],ecx \n " 
	"mov dword ptr [eax],edx \n " 
	"mov eax,dword ptr [ebp+0x8] \n " 
	"push eax \n " 
	"lea ecx,dword ptr [ebp-0x38] \n " 
	"push ecx \n " 
	"mov dword ptr [ebp-0x4],edi \n " 
	"mov ecx,esi \n " 
	"mov byte ptr [ebp-0x4],0x1 \n " 
	"call CScriptObject_FindScript \n " 
	"mov bl,0x2 \n " 
	"lea ecx,dword ptr [ebp-0x38] \n " 
	"mov byte ptr [ebp-0x4],bl \n " 
	//"call LuaUnspecifiedBoolType \n " 
	
	"cmp dword ptr [ecx+0x8],edi \n " 
	"je L0xABEL_0x0090745E  \n " //!; => 0x0090745E
	"mov eax,dword ptr [ecx+0xC] \n " 
	"test eax,eax \n " 
	"je L0xABEL_0x0090745E  \n " //!; => 0x0090745E
	"cmp eax,0x1 \n " 
	"jne L0xABEL_0x00907458  \n " //!; => 0x00907458
	"cmp dword ptr [ecx+0x10],edi \n " 
	"je L0xABEL_0x0090745E  \n " //!; => 0x0090745E
	"L0xABEL_0x00907458: \n " 
	"mov al,0x1 \n " 
	"movzx eax,al \n " 
	"jmp yes \n"
	"L0xABEL_0x0090745E: \n " 
	"xor al,al \n " 
	"movzx eax,al \n "
	"yes: \n"
	
	"cmp eax,edi \n " 
	"je L0xABEL_0x00581B86  \n " //!; => 0x00581B86
	"sub esp,0x14 \n " 
	"add esi,0x20 \n " 
	"mov ecx,esp \n " 
	"mov dword ptr [ebp-0x18],esp \n " 
	"push esi \n " 
	"call LuaObject_LuaObject \n " 
	"lea edx,dword ptr [ebp-0x38] \n " 
	"push edx \n " 
	"lea eax,dword ptr [ebp-0x4C] \n " 
	"push eax \n " 
	"mov byte ptr [ebp-0x4],0x3 \n " 
	"call _0x41F910 \n " 
	"mov byte ptr [ebp-0x4],0x4 \n " 
	"mov edi,eax \n " 
	"mov byte ptr [ebp-0x4],0x5 \n " 
	"call _0x582DD0 \n " 
	"lea ecx,dword ptr [ebp-0x4C] \n " 
	"mov byte ptr [ebp-0x4],bl \n " 
	"call _0x9075D0 \n " 
	"lea ecx,dword ptr [ebp-0x38] \n " 
	"mov byte ptr [ebp-0x4],0x1 \n " 
	"call _0x9075D0 \n " 
	"mov ecx,dword ptr [ebp-0x24] \n " 
	"test ecx,ecx \n " 
	"je L0xABEL_0x00581BB1  \n " //!; => 0x00581BB1
	"lea esp,dword ptr [esp] \n " 
	"L0xABEL_0x00581B60: \n " 
	"mov eax,dword ptr [ecx] \n " 
	"lea edx,dword ptr [ebp-0x24] \n " 
	"cmp eax,edx \n " 
	"je L0xABEL_0x00581B6E  \n " //!; => 0x00581B6E
	"lea ecx,dword ptr [eax+0x4] \n " 
	"jmp L0xABEL_0x00581B60  \n " //!; => 0x00581B60
	"L0xABEL_0x00581B6E: \n " 
	"mov eax,dword ptr [ebp-0x20] \n " 
	"mov dword ptr [ecx],eax \n " 
	"mov ecx,dword ptr [ebp-0xC] \n " 
	//"mov dword ptr [0x0],ecx \n " 
	"pop edi \n " 
	"pop esi \n " 
	"pop ebx \n " 
	"mov esp,ebp \n " 
	"pop ebp \n " 
	"ret 0x4 \n " 
	"L0xABEL_0x00581B86: \n " 
	"lea ecx,dword ptr [ebp-0x38] \n " 
	"mov byte ptr [ebp-0x4],0x1 \n " 
	"call _0x9075D0 \n " 
	"mov eax,dword ptr [ebp-0x24] \n " 
	"test eax,eax \n " 
	"je L0xABEL_0x00581BB1  \n " //!; => 0x00581BB1
	"lea edx,dword ptr [ebp-0x24] \n " 
	"cmp dword ptr [eax],edx \n " 
	"je L0xABEL_0x00581BAC  \n " //!; => 0x00581BAC
	"L0xABEL_0x00581BA0: \n " 
	"mov eax,dword ptr [eax] \n " 
	"add eax,0x4 \n " 
	"lea ecx,dword ptr [ebp-0x24] \n " 
	"cmp dword ptr [eax],ecx \n " 
	"jne L0xABEL_0x00581BA0  \n " //!; => 0x00581BA0
	"L0xABEL_0x00581BAC: \n " 
	"mov edx,dword ptr [ebp-0x20] \n " 
	"mov dword ptr [eax],edx \n " 
	"L0xABEL_0x00581BB1: \n " 
	"mov ecx,dword ptr [ebp-0xC] \n " 
	"pop edi \n " 
	"pop esi \n " 
	//"mov dword ptr [0x0],ecx \n " 
	"pop ebx \n " 
	"mov esp,ebp \n " 
	"pop ebp \n " 
	"ret 0x4 \n " 
	"mov eax,dword ptr [ebp-0x24] \n " 
	"test eax,eax \n " 
	"je L0xABEL_0x00581BD0  \n " //!; => 0x00581BD0
	"lea esi,dword ptr [eax-0x4] \n " 
	"jmp L0xABEL_0x00581BD2  \n " //!; => 0x00581BD2
	"L0xABEL_0x00581BD0: \n " 
	"xor esi,esi \n " 
	"L0xABEL_0x00581BD2: \n " 
	"mov ecx,dword ptr [ebp-0x1C] \n " 
	"mov edx,dword ptr [ecx] \n " 
	"mov eax,dword ptr [edx+0x4] \n " 
	"call eax \n " 
	"mov ecx,dword ptr [ebp+0x8] \n " 
	"push eax \n " 
	"push ecx \n " 
	"mov ecx,esi \n " 
	"call _0x4C7410 \n " 
	"add esp,0x8 \n " 
	"mov eax,0x581B92 \n " 
	"ret  \n " 
	".align 8192, 0x0 \n"
	" \n " //! 0xFinis of selected range: 0x00581BF0
	" \n " //!; Internal calls outside selected range (after)
);