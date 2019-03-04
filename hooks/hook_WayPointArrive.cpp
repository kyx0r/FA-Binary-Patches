//HOOK Fixes crash when unit arrives at the waypoint ROffset = 0x198E80

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address, 0x00598E80 \n"
);

__asm__
(
	" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
	" \n " //!; Internal calls outside selected range (before)
	//"edx =  0 \n " 
	"_0x598B90 =  5868432 - by_pass_address \n " 
	"_0x6EDFC0 =  7266240 - by_pass_address \n " 
	"_0x6EDE70 =  7265904 - by_pass_address \n " 
	"_0x6EDBF0 =  7265264 - by_pass_address \n " 
	"_0x608EF0 =  6328048 - by_pass_address \n " 
	"_0x6EDC20 =  7265312 - by_pass_address \n " 
	"_0x6E8D70 =  7245168 - by_pass_address \n " 	
	" \n " //!; Start of selected range: 0x00598E80
	"push ebp \n " 
	"mov ebp,esp \n " 
	"and esp,0xFFFFFFF8 \n " 
	"push ecx \n " 
	"push ebp \n " 
	"push esi \n " 
	"push edi \n " 
	"mov edi,ecx \n " 
	"cmp byte ptr [edi+0x40], bl \n " 
	"je L0xABEL_0x00598F6C  \n " //!; => 0x00598F6C
	"mov ecx,dword ptr [edi+0x44] \n " 
	"mov eax,dword ptr [ecx+0x10] \n " 
	"test eax,eax \n " 
	"je L0xABEL_0x00598EB5  \n " //!; => 0x00598EB5
	"mov edx,dword ptr [ecx+0x14] \n " 
	"sub edx,eax \n " 
	"sar edx,0x3 \n " 
	"je L0xABEL_0x00598EB5  \n " //!; => 0x00598EB5
	"mov eax,dword ptr [eax] \n " 
	"test eax,eax \n " 
	"je L0xABEL_0x00598EB5  \n " //!; => 0x00598EB5
	"lea esi,dword ptr [eax-0x4] \n " 
	"jmp L0xABEL_0x00598EB7  \n " //!; => 0x00598EB7
	"L0xABEL_0x00598EB5: \n " 
	"xor esi,esi \n " 
	"L0xABEL_0x00598EB7: \n " 
	"mov edx,0x2 \n " 
	"cmp dword ptr [edi+0x2C],edx \n " 
	"mov byte ptr [edi+0x40], bl \n " 
	"jne L0xABEL_0x00598EEC  \n " //!; => 0x00598EEC
	"mov esi,dword ptr [esi+0x98] \n " 
	"sub esi,0xA \n " 
	"je L0xABEL_0x00598F66  \n " //!; => 0x00598F66
	"sub esi,0x6 \n " 
	"je L0xABEL_0x00598EE1  \n " //!; => 0x00598EE1
	"sub esi,edx \n " 
	"jne L0xABEL_0x00598F66  \n " //!; => 0x00598F66
	"L0xABEL_0x00598EE1: \n " 
	"push ecx \n " 
	"call _0x6EDFC0 \n " 
	"jmp L0xABEL_0x00598F6C  \n " //!; => 0x00598F6C
	"L0xABEL_0x00598EEC: \n " 
	//CRASH FIX (null pointer)
	"cmp esi, ebx \n"
	"je RETURN1 \n"	
	//------------------------	
	"mov eax,dword ptr [esi+0xE4] \n " 
	"cmp eax,0x1 \n " 
	"jle L0xABEL_0x00598F09  \n " //!; => 0x00598F09
	"add eax,0xFFFFFFFF \n " 
	"mov dword ptr [esi+0xE4],eax \n " 
	"mov byte ptr [esi+0x141],0x1 \n " 
	"jmp L0xABEL_0x00598F6C  \n " //!; => 0x00598F6C
	"L0xABEL_0x00598F09: \n " 
	"mov ebp,dword ptr [edi+0x1C] \n " 
	"cmp byte ptr [ebp+0x2A2],bl \n " 
	"je L0xABEL_0x00598F46  \n " //!; => 0x00598F46
	"cmp dword ptr [esi+0x98],0x7 \n " 
	"jne L0xABEL_0x00598F46  \n " //!; => 0x00598F46
	"mov eax,dword ptr [esi+0xE0] \n " 
	"mov dword ptr [esi+0xE4],eax \n " 
	"mov byte ptr [esi+0x141],0x1 \n " 
	"mov ecx,dword ptr [edi+0x44] \n " 
	"push ecx \n " 
	"call _0x6EDFC0 \n " 
	"L0xABEL_0x00598F3A: \n " 
	"RETURN1: \n"
	"mov eax,0x1 \n " 
	"pop edi \n " 
	"pop esi \n " 
	"pop ebp \n " 
	"mov esp,ebp \n " 
	"pop ebp \n " 
	"ret  \n " 
	"L0xABEL_0x00598F46: \n " 
	"mov eax,dword ptr [esi+0x98] \n " 
	"sub eax,0xA \n " 
	"je L0xABEL_0x00598FDB  \n " //!; => 0x00598FDB
	"sub eax,0x6 \n " 
	"je L0xABEL_0x00598FEC  \n " //!; => 0x00598FEC
	"sub eax,edx \n " 
	"je L0xABEL_0x00598FEC  \n " //!; => 0x00598FEC
	"L0xABEL_0x00598F66: \n " 
	"push ecx \n " 
	"call _0x6EDE70 \n " 
	"L0xABEL_0x00598F6C: \n " 
	"mov ecx,dword ptr [edi+0x1C] \n " 
	"mov eax,dword ptr [ecx] \n " 
	"mov edx,dword ptr [eax+0x34] \n " 
	"call edx \n " 
	"test al,al \n " 
	"jne L0xABEL_0x00598F3A  \n " //!; => 0x00598F3A
	"mov ecx,dword ptr [edi+0x1C] \n " 
	"mov eax,dword ptr [ecx] \n " 
	"mov edx,dword ptr [eax+0x28] \n " 
	"call edx \n " 
	"test al,al \n " 
	"jne L0xABEL_0x00598F3A  \n " //!; => 0x00598F3A
	"mov ecx,dword ptr [edi+0x1C] \n " 
	"mov eax,dword ptr [ecx] \n " 
	"mov edx,dword ptr [eax+0x3C] \n " 
	"push 0xE \n " 
	"call edx \n " 
	"test al,al \n " 
	"jne L0xABEL_0x00598F3A  \n " //!; => 0x00598F3A
	"mov ecx,dword ptr [edi+0x1C] \n " 
	"mov eax,dword ptr [ecx] \n " 
	"mov edx,dword ptr [eax+0x3C] \n " 
	"push 0x2A \n " 
	"call edx \n " 
	"test al,al \n " 
	"jne L0xABEL_0x00598F3A  \n " //!; => 0x00598F3A
	"mov esi,dword ptr [edi+0x44] \n " 
	"mov eax,esi \n " 
	"call _0x598B90 \n " 
	"test al,al \n " 
	"jne L0xABEL_0x00598F3A  \n " //!; => 0x00598F3A
	"mov eax,esi \n " 
	"call _0x6EDBF0 \n " 
	"push eax \n " 
	"push edi \n " 
	"mov byte ptr [edi+0x40],0x1 \n " 
	"mov dword ptr [edi+0x2C],0x0 \n " 
	"call _0x608EF0 \n " 
	"add esp,0x8 \n " 
	"xor eax,eax \n " 
	"pop edi \n " 
	"pop esi \n " 
	"pop ebp \n " 
	"mov esp,ebp \n " 
	"pop ebp \n " 
	"ret  \n " 
	"L0xABEL_0x00598FDB: \n " 
	"cmp dword ptr [esi+0x11C],edx \n " 
	"sete al \n " 
	"test al,al \n " 
	"je L0xABEL_0x00598F66  \n " //!; => 0x00598F66
	"L0xABEL_0x00598FEC: \n " 
	"call _0x6EDC20 \n " 
	"test eax,eax \n " 
	"je L0xABEL_0x00599011  \n " //!; => 0x00599011
	"mov edx,ebp \n " 
	"call _0x6E8D70 \n " 
	"mov edx,dword ptr [edi+0x44] \n " 
	"push edx \n " 
	"call _0x6EDFC0 \n " 
	"mov eax,0x1 \n " 
	"pop edi \n " 
	"pop esi \n " 
	"pop ebp \n " 
	"mov esp,ebp \n " 
	"pop ebp \n " 
	"ret  \n " 
	"L0xABEL_0x00599011: \n " 
	"push ecx \n " 
	"call _0x6EDE70 \n " 
	"pop edi \n " 
	"mov eax,0x1 \n " 
	"pop esi \n " 
	"pop ebp \n " 
	"mov esp,ebp \n " 
	"pop ebp \n " 
	"ret  \n " 
	" \n " //! 0xFinis of selected range: 0x00599022
	" \n " //!; Internal calls outside selected range (after)
	".align 8192, 0x0 \n"
);
