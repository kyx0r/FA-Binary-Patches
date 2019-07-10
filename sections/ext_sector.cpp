
#include "include/moho.h"
#include "include/funcDefs.h"
#include <stdlib.h>
#include "include/global_func_table.h"
/* #include <iostream>
#include <cstring>
#include <limits>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <boost/thread/thread.hpp> */

// New unit categories.
//const char* sCQUEMOV = "CQUEMOV";
//const char* sSTAYONWATSUR = "STAYONWATSUR";
// ForgedAlliance.exe addresses.

funcDefs fd;
GFT Gft;
register int eax asm("eax");

void print_hello_world()
{
	fd.Logf("Hello World!");
}

int dec_IssueMove()
{
	return Gft.IssueMove();
}

void EndGame()
{
	__asm__("mov dword ptr [0x011FD23F], 0xB \n"); //remove block when last player remains.
	__asm__
	(
		"_0x90C590 =  9487760 \n " 
		"_0x90C1D0 =  9486800 \n " 
		"_0x924050 =  9584720 \n " 	
		" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
		" \n " //!; Internal calls outside selected range (before)
		" \n " //!; Start of selected range: 0x0074B8B0
		"push esi \n " 
		"mov esi,eax \n " 
		"mov eax,dword ptr [esi] \n " 
		"push edi \n " 
		"mov edi,dword ptr [0x10BA600] \n " 
		"push eax \n " 
		"call _0x90C590 \n " 
		"add esp,0x4 \n " 
		"test eax,eax \n " 
		"je L0xABEL_0x0074B8DB  \n " //!; => 0x0074B8DB
		"push eax \n " 
		"push 0x0 \n " 
		"push edi \n " 
		"push 0xE0A220 \n " 
		"push esi \n " 
		"call _0x90C1D0 \n " 
		"add esp,0x14 \n " 
		"L0xABEL_0x0074B8DB: \n " 
		"mov esi,dword ptr [esi] \n " 
		"push esi \n " 
		"call _0x924050 \n " 
		"mov edx,dword ptr [eax] \n " 
		"mov ecx,eax \n " 
		"mov eax,dword ptr [edx+0x5C] \n " 
		"add esp,0x4 \n " 
		"call eax \n " 
		"pop edi \n " 
		"xor eax,eax \n " 
		"pop esi \n " 
		"ret  \n " 
		" \n " //! 0xFinis of selected range: 0x0074B8F3
		" \n " //!; Internal calls outside selected range (after)
	);	
}

void xact_3d_apply()
{
	static bool once = true;
	__asm__
	(
		" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
		" \n " //!; Internal calls outside selected range (before)
		"_0x4D81E0 =  5079520 \n " 
		"_0x4D8A50 =  5081680 \n " 
		"_0x4D82A0 =  5079712 \n " 
		"_0xA89110 =  11047184 \n " 
		"_0x937D30 =  9665840 \n " 	
		" \n " //!; Start of selected range: 0x004D9A60
		"push ebx \n " 
		"push edi \n " 
		"mov ebx,ecx \n " 
		"mov edi,eax \n " 
		"mov eax,dword ptr [ebx] \n " 
		"cmp dword ptr [eax+0x34],0x0 \n " 
		"je L0xABEL_0x004D9B2A  \n " //!; => 0x004D9B2A
		"push esi \n " 
		"push 0x64 \n " 
		"lea esi,dword ptr [eax+0xAC] \n " 
		"push 0x0 \n " 
		"push esi \n " 
		"call _0xA89110 \n " 
		"xorps xmm0,xmm0 \n " 
		"mov dword ptr [esi+0x3C],0x1 \n " 
		"mov dword ptr [esi],0x0 \n " 
		"fld dword ptr [edi] \n " 
		"fstp dword ptr [esi+0x1C] \n " 
		"fld dword ptr [edi+0x4] \n " 
		"fstp dword ptr [esi+0x20] \n " 
		"fld dword ptr [edi+0x8] \n " 
		"movss dword ptr [esi+0x28],xmm0 \n " 
		"movss dword ptr [esi+0x2C],xmm0 \n " 
		"fstp dword ptr [esi+0x24] \n " 
		"movss dword ptr [esi+0x30],xmm0 \n " 
		"movss xmm0,dword ptr [0xDFEC20] \n " 
		"movss dword ptr [esi+0x5C],xmm0 \n " 
		"movss dword ptr [esi+0xC],xmm0 \n " 
		"movss dword ptr [esi+0x14],xmm0 \n " 
		"mov ecx,dword ptr [ebx] \n " 
		"lea edi,dword ptr [ecx+0x7C] \n " 
		"lea eax,dword ptr [ecx+0xAC] \n " 
		"lea edx,dword ptr [ecx+0x38] \n " 
		"add ecx,0x110 \n " 
		"push ecx \n " 
		"call _0x4D81E0 \n " 
		"add esp,0x10 \n " 
		"test eax,eax \n " 
		"jge L0xABEL_0x004D9B04  \n " //!; => 0x004D9B04
		"call _0x4D8A50 \n " 
	);

	__asm__
	(	
		"push eax \n " 
		"push 0xE0B410 \n " 
		"call _0x937D30 \n " 
		"add esp,0x8 \n " 
	);

	__asm__
	(
		"pop esi \n " 
		"pop edi \n " 
		"pop ebx \n " 
		"ret 0x4 \n " 
		"L0xABEL_0x004D9B04: \n " 
		"mov ebx,dword ptr [ebx] \n " 
		"mov esi,dword ptr [esp+0x10] \n " 
		"lea edi,dword ptr [ebx+0x7C] \n " 
		"call _0x4D82A0 \n " 
		"test eax,eax \n " 
		"jge L0xABEL_0x004D9B29  \n " //!; => 0x004D9B29
		"call _0x4D8A50 \n " 
	);
	if(once)
	{
		__asm__
		(		
			"push eax \n " 
			"push 0xE0B430 \n " 
			"call _0x937D30 \n " 
			"add esp,0x8 \n " 
		);
		once = false;
	}
	
	__asm__
	(
		"L0xABEL_0x004D9B29: \n " 
		"pop esi \n " 
		"L0xABEL_0x004D9B2A: \n " 
		"pop edi \n " 
		"pop ebx \n " 
		"ret 0x4 \n " 
		" \n " //! 0xFinis of selected range: 0x004D9B2E
		" \n " //!; Internal calls outside selected range (after)
	);
}

/* void Thread__()
{
	hw HW;
	boost::thread worker(boost::bind(&hw::print_hello_world, &HW));
	worker.join();
}

int main(){} */
