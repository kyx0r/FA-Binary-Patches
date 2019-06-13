//HOOK SimThread_VFT ROffset = 0x91F0

#include <stdlib.h>
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ by_pass_address, 0x004091F0 \n"
);


__asm__
(
	" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
	" \n " //!; Internal calls outside selected range (before)
	//"eax =  0 \n " 
	"_0x409190 =  4231568 - by_pass_address \n " 
	"_0x937D30 =  9665840 - by_pass_address \n " 
	"_0x4093E0 =  4232160 - by_pass_address \n " 
	" \n " //!; Start of selected range: 0x004091F0
	"push ebp \n " 
	"mov ebp,esp \n " 
	"push 0xFFFFFFFF \n " 
	"push 0xB83220 \n " 
	//"mov eax,dword ptr [0x0] \n " 
	"push eax \n " 
	//"mov dword ptr [0x0],esp \n " 
	"sub esp,0x14 \n " 
	"push ebx \n " 
	"push esi \n " 
	"mov esi,dword ptr [ebp+0x8] \n " 
	"add dword ptr [esi+0x14],0xFFFFFFFF \n " 
	"mov eax,dword ptr [esi+0x14] \n " 
	"xor ebx,ebx \n " 
	"cmp eax,ebx \n " 
	"push edi \n " 
	"mov dword ptr [ebp-0x10],esp \n " 
	"jg L0xABEL_0x00409335  \n " //!; => 0x00409335
	"L0xABEL_0x00409225: \n " 
	"mov edi,dword ptr [esi+0x10] \n " 
	"cmp edi,ebx \n " 
	"mov dword ptr [ebp-0x18],edi \n " 
	"je L0xABEL_0x004092EA  \n " //!; => 0x004092EA
	"mov byte ptr [ebp-0x11],bl \n " 
	"mov dword ptr [ebp-0x4],ebx \n " 
	"mov edx,dword ptr [edi] \n " 
	"lea eax,dword ptr [ebp-0x11] \n " 
	"mov dword ptr [edi+0x8],eax \n " 
	"mov eax,dword ptr [edx+0x4] \n " 
	"mov ecx,edi \n " 
	"call eax \n " 
	"mov ecx,eax \n " 
	"mov dword ptr [ebp-0x4],0xFFFFFFFF \n " 
//	"jmp L0xABEL_0x0040928A  \n " //!; => 0x0040928A
/* 	"mov ecx,dword ptr [ebp-0x20] \n " 
	"mov edx,dword ptr [ecx] \n " 
	"mov eax,dword ptr [edx+0x4] \n " 
	"call eax \n " 
	"push eax \n " 
	"push 0xE0023C \n " 
	"call _0x937D30 \n " 
	"add esp,0x8 \n " 
	"mov dword ptr [ebp-0x1C],0xFFFFFFFD \n " 
	"mov dword ptr [ebp-0x4],0xFFFFFFFF \n " 
	"mov eax,0x40927F \n " 
	"ret  \n " 
	"mov esi,dword ptr [ebp+0x8] \n " 
	"mov edi,dword ptr [ebp-0x18] \n " 
	"mov ecx,dword ptr [ebp-0x1C] \n " 
	"xor ebx,ebx \n "  */
	"L0xABEL_0x0040928A: \n " 
	"cmp byte ptr [ebp-0x11],bl \n " 
	"jne L0xABEL_0x00409292  \n " //!; => 0x00409292
	"mov dword ptr [edi+0x8],ebx \n " 
	"L0xABEL_0x00409292: \n " 
	"lea eax,dword ptr [ecx+0x4] \n " 
	"cmp eax,0x5 \n " 
	"ja L0xABEL_0x0040932F  \n " //!; => 0x0040932F
	"jmp dword ptr ds:[eax*4+0x40934C]  \n " //!; => 0x00409300
	"cmp dword ptr [esi+0x10],edi \n " 
	"lea eax,dword ptr [esi+0x10] \n " 
	"je L0xABEL_0x004092B9  \n " //!; => 0x004092B9
	"lea ecx,dword ptr [ecx] \n " 
	"L0xABEL_0x004092B0: \n " 
	"mov eax,dword ptr [eax] \n " 
	"add eax,0x10 \n " 
	"cmp dword ptr [eax],edi \n " 
	"jne L0xABEL_0x004092B0  \n " //!; => 0x004092B0
	"L0xABEL_0x004092B9: \n " 
	"mov ecx,dword ptr [edi+0x10] \n " 
	"mov dword ptr [eax],ecx \n " 
	"cmp byte ptr [edi+0x14],bl \n " 
	"mov dword ptr [edi+0x10],ebx \n " 
	"mov dword ptr [edi+0xC],ebx \n " 
	"je L0xABEL_0x00409225  \n " //!; => 0x00409225
	"mov edx,dword ptr [edi] \n " 
	"mov eax,dword ptr [edx] \n " 
	"push 0x1 \n " 
	"mov ecx,edi \n " 
	"call eax \n " 
	"jmp L0xABEL_0x00409225  \n " //!; => 0x00409225
	"mov eax,esi \n " 
	"call _0x4093E0 \n " 
	"jmp L0xABEL_0x00409335  \n " //!; => 0x00409335
	"call _0x409190 \n " 
	"L0xABEL_0x004092EA: \n " 
	"or eax,0xFFFFFFFF \n " 
	"mov ecx,dword ptr [ebp-0xC] \n " 
	//"mov dword ptr [0x0],ecx \n " 
	"pop edi \n " 
	"pop esi \n " 
	"pop ebx \n " 
	"mov esp,ebp \n " 
	"pop ebp \n " 
	"ret 0x4 \n " 
	"L0xABEL_0x00409300: \n " 
	"nop \n"
	"nop \n"
	"mov eax,0xFFFFFFFE \n " 
	"mov ecx,dword ptr [ebp-0xC] \n " 
	//"mov dword ptr [0x0],ecx \n " 
	"pop edi \n " 
	"pop esi \n " 
	"pop ebx \n " 
	"mov esp,ebp \n " 
	"pop ebp \n " 
	"ret 0x4 \n " 
	"cmp byte ptr [esi+0x18],bl \n " 
	"mov dword ptr [esi+0x14],ebx \n " 
	"je L0xABEL_0x00409225  \n " //!; => 0x00409225
	"jmp L0xABEL_0x00409335  \n " //!; => 0x00409335
	"mov dword ptr [esi+0x14],0x1 \n " 
	"jmp L0xABEL_0x00409335  \n " //!; => 0x00409335
	"L0xABEL_0x0040932F: \n " 
	"add ecx,0xFFFFFFFF \n " 
	"mov dword ptr [esi+0x14],ecx \n " 
	"L0xABEL_0x00409335: \n " 
	"mov ecx,dword ptr [ebp-0xC] \n " 
	"pop edi \n " 
	"pop esi \n " 
	"xor eax,eax \n " 
	//"mov dword ptr [0x0],ecx \n " 
	"pop ebx \n " 
	"mov esp,ebp \n " 
	"pop ebp \n " 
	"ret 0x4 \n " 
	"push eax \n"
	" \n " //! 0xFinis of selected range: 0x00409349
	" \n " //!; Internal calls outside selected range (after)
	".align 8192, 0x0 \n"
);
