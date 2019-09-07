#include "include/funcDefs.h"
#include "include/global_func_table.h"
#include <stdlib.h>

const char* safe_quit = "safeQuit";
_DWORD tick_num = 0;
static bool update_pl_count = true;
_DWORD terminated = 0;
_DWORD num_clients = 0;
_DWORD current_num_clients = 0;
bool paused = false;

int strCmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

void Conexecute()
{
	register int eax asm("eax");
	__asm__
	(
		" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
		" \n " //!; Internal calls outside selected range (before)
		"_0x4154B0 =  4281520 \n " 
		"_0x90C590 =  9487760 \n " 
		"_0x90C1D0 =  9486800 \n " 
		"_0x90CA90 =  9489040 \n " 
		"_0x41CC90 =  4312208 \n " 		
		" \n " //!; Start of selected range: 0x0041CBE0
		"push ebp \n " 
		"mov ebp,esp \n " 
		"and esp,0xFFFFFFF8 \n " 
		"sub esp,0x8 \n " 
		"push esi \n " 
		"mov esi,eax \n " 
		"mov eax,dword ptr [esi] \n " 
		"push edi \n " 
		"mov edi,dword ptr [0x10A7704] \n " 
		"push eax \n " 
		"call _0x90C590 \n " 
		"add esp,0x4 \n " 
		"cmp eax,0x1 \n " 
		"je L0xABEL_0x0041CC15  \n " //!; => 0x0041CC15
		"push eax \n " 
		"push 0x1 \n " 
		"push edi \n " 
		"push 0xE0A220 \n " 
		"push esi \n " 
		"call _0x90C1D0 \n " 
		"add esp,0x14 \n " 
		"L0xABEL_0x0041CC15: \n " 
		"mov dword ptr [esp+0x8],esi \n " 
		"mov dword ptr [esp+0xC],0x1 \n " 
		"mov ecx,dword ptr [esi] \n " 
		"push 0x1 \n " 
		"push ecx \n " 
		"call _0x90CA90 \n " 
		"mov esi,eax \n " 
	);	
	
	if(strCmp(eax, safe_quit) == 0)
	{
		__asm__
		(
			"mov dword ptr [0x011FD24F], 0x1 \n"
			"add esp,0x8 \n " 
			"pop edi \n " 
			"xor eax,eax \n " 
			"pop esi \n " 
			"mov esp,ebp \n " 
			"pop ebp \n " 
		);
		return;
	}
	
	__asm__
	(
		
		"add esp,0x8 \n " 
		"test esi,esi \n " 
		"jne L0xABEL_0x0041CC42  \n " //!; => 0x0041CC42
		"push 0xE00AD0 \n " 
		"lea ecx,dword ptr [esp+0xC] \n " 
		"call _0x4154B0 \n " 
		"L0xABEL_0x0041CC42: \n " 
		"push esi \n " 
		"call _0x41CC90 \n " 
		"add esp,0x4 \n " 
		"pop edi \n " 
		"xor eax,eax \n " 
		"pop esi \n " 
		"mov esp,ebp \n " 
		"pop ebp \n " 
		" \n " //! 0xFinis of selected range: 0x0041CC52
		" \n " //!; Internal calls outside selected range (after)
	);
	return;
}

__attribute__((noinline)) void timed_out()
{
	((int (*)(const char* fmt, ...))_Logf)("SafeQuit sync timed out. \n");
	return;
}

__attribute__((noinline)) void p_Version()
{
	((int (*)(const char* fmt, ...))_Logf)("Exe Version: 1.0 \n");
	return;
}

__attribute__((noinline)) void xor_sync()
{
	register int eax asm("eax");
	__asm__("xor eax,eax \n");
	for(int i = 0; i<16; i++)
	{
		sync_buffer[i] = eax;
	}	
	return;
}

void SessionEndGame()
{
	register int eax asm("eax");	
	__asm__
	(
		" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
		" \n " //!; Internal calls outside selected range (before)
		" \n " //!; Start of selected range: 0x008984B0
		"_0x90C590 =  9487760 \n " 
		"_0x90C1D0 =  9486800 \n " 	
		"Sleep = 0x00C0F574 \n"
		"GetCurrentThread = 0x00C0F588 \n"
		"SuspendThread = 0x00C0F4F8 \n"
		"WaitForSingleObject = 0x00C0F524 \n"
	);

	if(current_num_clients > 1 && current_num_clients < 17 && !game_ended)
	{
		__asm__
		(	
			"mov dword ptr [0x011FD243], 0x1 \n" // send network var
			"push 0x2500 \n"
			"push dword ptr [0x11FD253] \n"
			"call dword ptr [WaitForSingleObject] \n"
		);
		
		if(eax == 0x00000102)
		{
			__asm__ volatile
			(
				"call %[func]\n\t"
				: 
				: [func] "i" (&timed_out)
				: "memory"
			);			
		}
			
/* 		__asm__
		(
			"push 100 \n"
			"call dword ptr [Sleep] \n"		
		); */
	}
	__asm__
	(
		//"push 30000 \n"
		//"call dword ptr [Sleep] \n"
		"mov dword ptr [0x011FD243], 0xC \n" //reset send trigger		
		"mov eax,dword ptr [edi] \n " 
		"push esi \n " 
		"mov esi,dword ptr [0x10C5234] \n " 
		"push eax \n " 
		"call _0x90C590 \n " 
		"add esp,0x4 \n " 
		"test eax,eax \n " 
		"je L0xABEL_0x008984D8  \n " //!; => 0x008984D8
		"push eax \n " 
		"push 0x0 \n " 
		"push esi \n " 
		"push 0xE0A220 \n " 
		"push edi \n " 
		"call _0x90C1D0 \n " 
		"add esp,0x14 \n " 
		"L0xABEL_0x008984D8: \n " 
		"mov eax,dword ptr [0x10C4F50] \n " 
		"test eax,eax \n " 
		"mov esi,eax \n " 
		"jne L0xABEL_0x008984F1  \n " //!; => 0x008984F1
		"push 0xE4AFCC \n " 
		"push edi \n " 
		"call _0x90C1D0 \n " 
		"add esp,0x8 \n " 
		"L0xABEL_0x008984F1: \n " 
		"mov edx,dword ptr [esi] \n " 
		"mov eax,dword ptr [edx+0x4] \n " 
		"mov ecx,esi \n " 
		"call eax \n " 
	);
	
	__asm__ volatile
	(
		"call %[func]\n\t"
		: 
		: [func] "i" (&xor_sync)
		: "memory"
	);	
	
	__asm__
	(
		"mov dword ptr [0x011FD23F], 0xB \n" //RESET BLOCK VARIABLE
		//"mov dword ptr [0x011FD243], 0xC \n" //reset send trigger	
		"xor eax,eax \n " 
		"pop esi \n " 
		"ret  \n " 
		" \n " //! 0xFinis of selected range: 0x008984FD
		" \n " //!; Internal calls outside selected range (after)
	);	
}

__attribute__((noinline)) void err_print()
{
	((int (*)(const char* fmt, ...))_Logf)("Block is too late ! \n");
	return;
}

__attribute__((noinline)) void term()
{
	((int (*)(const char* fmt, ...))_Logf)("terminated \n");
	return;
}

void Moho__CDecoder__DecodeMessage()
{
	register int eax asm("eax");
	__asm__
	(
		" \n " //!; Source: forgedalliancetest2.exe (base 0x00400000 - 4194304)
		" \n " //!; Internal calls outside selected range (before)
		"_0x405130 = 0x405130 \n " 
		"_0x406590 = 0x406590 \n " 
		"_0x956DB0 = 0x956DB0 \n " 
		"_0x6E4400 = 0x6E4400 \n " 
		"_0x956DD0 = 0x956DD0 \n " 
		"_0x6E4440 = 0x6E4440 \n " 
		"_0x6E4480 = 0x6E4480 \n " 
		"_0x6E44F0 = 0x6E44F0 \n " 
		"_0x6E45D0 = 0x6E45D0 \n " 
		"_0x6E4670 = 0x6E4670 \n " 
		"_0x6E46A0 = 0x6E46A0 \n " 
		"_0x6E46E0 = 0x6E46E0 \n " 
		"_0x6E47D0 = 0x6E47D0 \n " 
		"_0x6E48E0 = 0x6E48E0 \n " 
		"_0x6E49F0 = 0x6E49F0 \n " 
		"_0x6E4A30 = 0x6E4A30 \n " 
		"_0x6E4A70 = 0x6E4A70 \n " 
		"_0x6E4AC0 = 0x6E4AC0 \n " 
		"_0x6E4B00 = 0x6E4B00 \n " 
		"_0x6E4BB0 = 0x6E4BB0 \n " 
		"_0x6E4D80 = 0x6E4D80 \n " 
		"_0x6E4BF0 = 0x6E4BF0 \n " 
		"_0x6E4CA0 = 0x6E4CA0 \n " 
		"_0x6E4E70 = 0x6E4E70 \n " 
		"_0x938F10 = 0x938F10 \n " 
		"_0xA89950 = 0xA89950 \n " 		
		" \n " //!; Start of selected range: 0x006E4150
		"push ebp \n " 
		"mov ebp,esp \n " 
		"and esp,0xFFFFFFF8 \n " 
		"push 0xFFFFFFFF \n " 
		"push 0xBA8D10 \n " 
		//"mov eax,dword ptr [0x0] \n " 
		"push eax \n " 
		//"mov dword ptr [0x0],esp \n " 
		"sub esp,0x70 \n " 
		"push esi \n " 
		"mov esi,ecx \n " 
		"lea ecx,dword ptr [esp+0x28] \n " 
		"call _0x956DB0 \n " 
		"mov ecx,dword ptr [edi] \n " 
		"xor edx,edx \n " 
		"mov dword ptr [esp+0x28],0xE03BEC \n " 
		"mov dword ptr [esp+0x44],edi \n " 
		"mov dh,byte ptr [ecx+0x2] \n " 
		"mov eax,dword ptr [edi] \n " 
		"add eax,0x3 \n " 
		"mov dl,byte ptr [ecx+0x1] \n " // <- test for size of the message
		"cmp edx,0x3 \n " 
		"jae L0xABEL_0x006E419E  \n " //!; => 0x006E419E
		"xor edx,edx \n " 
		"jmp L0xABEL_0x006E41A1  \n " //!; => 0x006E41A1
		"L0xABEL_0x006E419E: \n " 
		"add edx,0xFFFFFFFD \n " 
		"L0xABEL_0x006E41A1: \n " 
		"add edx,eax \n " 
		"mov dword ptr [esp+0x30],eax \n " 
		"mov dword ptr [esp+0x2C],eax \n " 
		"mov dword ptr [esp+0x34],edx \n " 
		"mov dword ptr [esp+0x7C],0x0 \n " 
		"mov cl,byte ptr [ecx] \n " 
		"lea eax,dword ptr [esp+0x28] \n " 
		"mov dword ptr [esp+0x8],eax \n " 
		"movzx eax,cl \n " 
		
/* 		"cmp dword ptr [0x011FD23F], 0x1 \n"
		"jne skip \n"
		"mov byte ptr [0x10A6380],0x0 \n "
		"inc dword ptr [0x011FD23F+0xC] \n"
		"cmp dword ptr [0x011FD23F+0xC], 0x4 \n"
		"jl skip \n"
		"mov dword ptr [0x011FD23F+0xC], 0x0 \n"
		"mov dword ptr [0x011FD23F], 0x0 \n"
		"skip: \n" */
		
		
	);		
	
	switch (eax)
	{
	case 0: //decode_advance -> On_Beat()
		__asm__
		(
		"lea ecx,dword ptr [esp+0x8] \n " 
		"push ecx \n " 
		"call _0x6E4400 \n " 
		);
		break;
	case 1: //decode_set_command_source
		__asm__
		(
		"push esi \n " 
		"lea eax,dword ptr [esp+0xC] \n " 
		"call _0x6E4440 \n " 
		);	
		break;		
	case 2:	// command source terminated
	
		//This acts both, like a boolean and a 32bit integer
		//this is what i like about C the most, there is no limitation of what you can do with 
		//the data type, i bet you to try this in Java and see what kind of shit code you'll have to write
		//tag_sent = 0;
		__asm__
		(
		"cmp dword ptr [0x011FD23F], 0x1 \n"
		"jne late \n"
		);
		terminated = tick_num;	
		__asm__("jmp next \n");
		__asm__("late: \n");
		__asm__ volatile
		(
		    "call %[func]\n\t"
		    : 
		    : [func] "i" (&err_print)
		    : "memory"
		);		
		
		__asm__
		(
		"next: \n"
		"mov ecx,dword ptr [esi+0xC] \n " 
		"mov edx,dword ptr [ecx] \n " 
		"mov eax,dword ptr [edx+0x4] \n " 
		"call eax \n "
		);
		__asm__ volatile
		(
		    "call %[func]\n\t"
		    : 
		    : [func] "i" (&term)
		    : "memory"
		);	
		current_num_clients--;		
		break;
	case 3: //verify checksum
		__asm__
		(		
		"push esi \n " 
		"lea esi,dword ptr [esp+0xC] \n " 
		"call _0x6E4480 \n " 
		);
		break;
	case 4: //sim request pause
		paused = true;
		__asm__
		(
		"pause: \n"
		"mov ecx,dword ptr [esi+0xC] \n " //3
		"mov edx,dword ptr [ecx] \n " 
		"mov eax,dword ptr [edx+0xC] \n " 
		"call eax \n " 
		);	
		break;
	case 5: // sim resume
		paused = false;
		__asm__
		(
		"mov ecx,dword ptr [esi+0xC] \n " //4
		"mov edx,dword ptr [ecx] \n " 
		"mov eax,dword ptr [edx+0x10] \n " 
		"call eax \n " 
		);	
		break;
	case 6:
		__asm__
		(
		"mov ecx,dword ptr [esi+0xC] \n " 
		"mov edx,dword ptr [ecx] \n " 
		"mov eax,dword ptr [edx+0x14] \n " 
		"call eax \n " 
		);	
		break;
	case 7:
		__asm__
		(
		"push esi \n " 
		"lea ecx,dword ptr [esp+0xC] \n " 
		"call _0x6E44F0 \n " 
		);	
		break;
	case 8:
		__asm__
		(
		"push esi \n " 
		"lea ecx,dword ptr [esp+0xC] \n " //7
		"call _0x6E45D0 \n " 
		);	
		break;
	case 9:
		__asm__
		(
		"push esi \n " 
		"lea eax,dword ptr [esp+0xC] \n " 
		"call _0x6E4670 \n " 
		);	
		break;
	case 0xA:
		__asm__
		(
		"push esi \n " 
		"lea esi,dword ptr [esp+0xC] \n " //9
		"call _0x6E46A0 \n " 
		);	
		break;
	case 0xB:
		__asm__
		(
		"push esi \n " 
		"lea ecx,dword ptr [esp+0xC] \n " //10
		"call _0x6E46E0 \n " 
		);	
		break;
	case 0xC:
		__asm__
		(
		"push esi \n " 
		"lea esi,dword ptr [esp+0xC] \n " //11
		"call _0x6E47D0 \n "
		);	
		break;
	case 0xD:
		__asm__
		(
		"push esi \n " 
		"lea esi,dword ptr [esp+0xC] \n " //12
		"call _0x6E48E0 \n " 
		);	
		break;
	case 0xE:
		__asm__
		(
		"push esi \n " 
		"lea esi,dword ptr [esp+0xC] \n " //13
		"call _0x6E49F0 \n " 
		);	
		break;
	case 0xF:
		__asm__
		(
		"push esi \n " 
		"lea esi,dword ptr [esp+0xC] \n " //14
		"call _0x6E4A30 \n " 
		);	
		break;
	case 0x10:
		__asm__
		(
		"push esi \n " 
		"lea eax,dword ptr [esp+0xC] \n " //15
		"call _0x6E4A70 \n " 
		);	
		break;
	case 0x11:
		__asm__
		(
		"push esi \n " 
		"lea esi,dword ptr [esp+0xC] \n " //16
		"call _0x6E4AC0 \n " 
		);	
		break;
	case 0x12:
		__asm__
		(
		"push esi \n " 
		"lea esi,dword ptr [esp+0xC] \n " //17
		"call _0x6E4B00 \n " 
		);	
		break;
	case 0x13:
		__asm__
		(
		"push esi \n " 
		"lea esi,dword ptr [esp+0xC] \n " //18
		"call _0x6E4BB0 \n " 
		);	
		break;
	case 0x14:
		__asm__
		(
		"push esi \n " 
		"lea ecx,dword ptr [esp+0xC] \n " //19
		"call _0x6E4D80 \n "  
		);	
		break;
	case 0x15:
		__asm__
		(
		"lea ecx,dword ptr [esp+0x8] \n " //20
		"call _0x6E4BF0 \n " 
		);	
		break;
	case 0x16:
		__asm__
		(
		"lea ecx,dword ptr [esp+0x8] \n " //21
		"call _0x6E4CA0 \n " 
		);	
		break;
	case 0x17:
		__asm__
		(
		"call _0x6E4E70 \n " //22
		);	
		break;
	default:
		__asm__
		(	
			"movzx ecx,cl \n " 
			"push ecx \n " 
			"lea edx,dword ptr [esp+0x10] \n " 
			"push 0xE2E568 \n " 
			"push edx \n " 
			"call _0x938F10 \n " 
			"add esp,0xC \n " 
			"push eax \n " 
			"lea ecx,dword ptr [esp+0x4C] \n " 
			"mov byte ptr [esp+0x80],0x1 \n " 
			"call _0x405130 \n " 
			"push 0xEC2624 \n " 
			"lea eax,dword ptr [esp+0x4C] \n " 
			"push eax \n " 
			"mov dword ptr [esp+0x50],0xE2E73C \n " 
			"call _0xA89950 \n " 
			"int3 \n"
		);
		return;
	}
	__asm__
	(	
		"lea ecx,dword ptr [esp+0x28] \n " 
		"mov dword ptr [esp+0x7C],0xFFFFFFFF \n " 
		"call _0x956DD0 \n " 
		"mov ecx,dword ptr [esp+0x74] \n " 
		"pop esi \n " 
		"mov esp,ebp \n " 
		"pop ebp \n " 
		"ret  \n " 
	);
}

void sim_dispatch()
{
	register int eax asm("eax");
	__asm__
	(
		" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
		" \n " //!; Internal calls outside selected range (before)
		"_0x4E6DF0 =  5139952 \n " 
		"_0x408940 =  4229440 \n " 
		"_0x417B60 =  4291424 \n " 
		"_0x4151E0 =  4280800 \n " 
		"_0x4E6E90 =  5140112 \n " 
		"_0x48BF00 =  4767488 \n " 
		"_0x55AE10 =  5615120 \n " 
		"_0x9556D0 =  9787088 \n " 
		"_0xAC1E60 =  11279968 \n " 
		"_0xA89950 =  11049296 \n " 
		"_0xAC1AD0 =  11279056 \n " 
		"_0x955700 =  9787136 \n " 
		"_0x955520 =  9786656 \n " 
		"_0xAC1AB0 =  11279024 \n " 
		"_0x73DAD0 =  7592656 \n " 
		"_0x9554E0 =  9786592 \n " 		
		"Sleep = 0x00C0F574 \n"
		"ResetEvent = 0x00C0F4CC \n"
		" \n " //!; Start of selected range: 0x0073D8C0
		"push ebp \n " 
		"mov ebp,esp \n " 
		"and esp,0xFFFFFFF8 \n " 
		"push 0xFFFFFFFF \n " 
		"push 0xBB49E0 \n " 
		//"mov eax,dword ptr [0x0] \n " 
		"push eax \n " 
		//"mov dword ptr [0x0],esp \n " 
		"sub esp,0x4C \n " 
		"push ebx \n " 
		"mov ebx,ecx \n " 
		"push esi \n " 
		"lea ecx,dword ptr [esp+0x10] \n " 
		"call _0x9556D0 \n " 
		"mov eax,dword ptr [edi+0x20] \n " 
		"mov dword ptr [esp+0x8],eax \n " 
		
		"add eax,0x1 \n " // counts sim ticks
	);
		
		tick_num = eax;
		if(terminated && eax >= (terminated + 10)) //wait 10 more sim ticks
		{
			__asm__
			(		
				"mov dword ptr [0x011FD23F], 0xB \n" //RESET BLOCK VARIABLE
				"mov dword ptr [0x011FD243], 0xC \n" //reset send trigger
				"mov byte ptr  [0x011FD24F], 0x0 \n" //reset safeQuit		
			);	
			tag_sent = 0;
			terminated = 0;
			p_index = 0;
			sender_sock = 1;
		}
		
		static bool overflow = false;
		if(eax <= 10)
		{
			__asm__
			(		
				"mov dword ptr [0x011FD23F], 0xB \n" //RESET BLOCK VARIABLE
				"mov dword ptr [0x011FD243], 0xC \n" //reset send trigger
				"mov byte ptr  [0x011FD24F], 0x0 \n" //reset safeQuit		
			);	
			tag_sent = 0;
			terminated = 0;
			p_index = 0;
			sender_sock = 1;
			game_ended = false;
			if(!overflow)
			{
				update_pl_count = true;
			}
		}
		else
		{
			overflow = false;
		}
		
		if(eax == 0xFFFFFFFF)
		{
			overflow = true;
		}		
		
	__asm__
	(		
		"mov dword ptr [edi+0x20],eax \n " 
		"cmp byte ptr [ebx+0x4],0x0 \n " 
		"jne L0xABEL_0x0073D916  \n " //!; => 0x0073D916
		"lea ecx,dword ptr [esp+0x18] \n " 
		"call _0xAC1E60 \n " 
		"push 0xEC2180 \n " 
		"lea eax,dword ptr [esp+0x1C] \n " 
		"push eax \n " 
		"call _0xA89950 \n " 
		"L0xABEL_0x0073D916: \n " 
		"mov ecx,dword ptr [ebx] \n " 
		"call _0xAC1AD0 \n " 
		"mov eax,0xE3333C \n " 
		"lea esi,dword ptr [esp+0x38] \n " 
		"mov byte ptr [ebx+0x4],0x0 \n " 
		"call _0x4E6DF0 \n " 
		"mov dword ptr [esp+0x5C],0x0 \n " 
		"cmp dword ptr [0x10C7694],0x0 \n " 
		"jne L0xABEL_0x0073D962  \n " //!; => 0x0073D962
		"call _0x408940 \n " 
		"push 0xE00B5C \n " 
		"mov ecx,eax \n " 
		"call _0x417B60 \n " 
		"mov esi,0x1 \n " 
		"mov edx,eax \n " 
		"mov dword ptr [0x10C7694],eax \n " 
		"call _0x4151E0 \n " 
		"L0xABEL_0x0073D962: \n " 
		"mov ecx,dword ptr [0x10C7694] \n " 
		"mov dword ptr [esp+0x18],ecx \n " 
		"lea ecx,dword ptr [esp+0x20] \n " 
		"call _0x9556D0 \n " 
		"mov eax,dword ptr [esp+0x8] \n " 
		"mov byte ptr [esp+0x5C],0x1 \n " 
		"mov ecx,dword ptr [edi+0x8] \n " 
		"mov edx,dword ptr [ecx] \n " 
		"mov edx,dword ptr [edx+0x58] \n " 
		"push eax \n " 
		"call edx \n " 
		"mov eax,dword ptr [0x10A63E8] \n " 
		"test eax,eax \n " 
		"je L0xABEL_0x0073D999  \n " //!; => 0x0073D999
		"push eax \n " 
		"call dword ptr [Sleep] \n " 
		"L0xABEL_0x0073D999: \n " 
		"lea ecx,dword ptr [esp+0x20] \n " 
		"mov byte ptr [esp+0x5C],0x0 \n " 
		"call _0x955700 \n " 
		"push edx \n " 
		"push eax \n " 
		"call _0x955520 \n " 
		"mov ecx,dword ptr [esp+0x20] \n " 
		"add esp,0x8 \n " 
		"mov dword ptr [esp+0xC],edx \n " 
		"add ecx,0x24 \n " 
		"lock xadd dword ptr [ecx],eax \n " 
		"lea esi,dword ptr [esp+0x38] \n " 
		"mov dword ptr [esp+0x5C],0xFFFFFFFF \n " 
		"call _0x4E6E90 \n " 
		"cmp byte ptr [ebx+0x4],0x0 \n " 
		"je L0xABEL_0x0073D9EF  \n " //!; => 0x0073D9EF
		"lea ecx,dword ptr [esp+0x28] \n " 
		"call _0xAC1E60 \n " 
		"push 0xEC2180 \n " 
		"lea edx,dword ptr [esp+0x2C] \n " 
		"push edx \n " 
		"call _0xA89950 \n " 
		"L0xABEL_0x0073D9EF: \n " 
		"mov ecx,dword ptr [ebx] \n " 
		"call _0xAC1AB0 \n " 
		"mov byte ptr [ebx+0x4],0x1 \n " 
		"mov ecx,ebx \n " 
		"mov ebx,edi \n " 
		"call _0x73DAD0 \n " 
		"cmp byte ptr [edi+0x68],0x0 \n " 
		"jne L0xABEL_0x0073DAB7  \n " //!; => 0x0073DAB7
		"lea ecx,dword ptr [esp+0x10] \n " 
		"call _0x955700 \n " 
		"push edx \n " 
		"push eax \n " 
		"call _0x9554E0 \n " 
		"fstp dword ptr [esp+0x10] \n " 
		"mov eax,dword ptr [edi+0x224] \n " 
		"lea ecx,dword ptr [edi+0x1B8] \n " 
		"add eax,0x1 \n " 
		"cdq  \n " 
		"mov ebx,0x19 \n " 
		"idiv ebx \n " 
		"mov esi,dword ptr [ecx+0x68] \n " 
		"add esp,0x8 \n " 
		"cmp edx,esi \n " 
		"jne L0xABEL_0x0073DA4D  \n " //!; => 0x0073DA4D
		"lea eax,dword ptr [esi+0x1] \n " 
		"cdq  \n " 
		"mov esi,ebx \n " 
		"idiv esi \n " 
		"mov dword ptr [ecx+0x68],edx \n " 
		"L0xABEL_0x0073DA4D: \n " 
		"mov eax,dword ptr [ecx+0x6C] \n " 
		"lea eax,dword ptr [ecx+eax*0x4] \n " 
		"test eax,eax \n " 
		"je L0xABEL_0x0073DA61  \n " //!; => 0x0073DA61
		"movss xmm0,dword ptr [esp+0x8] \n " 
		"movss dword ptr [eax],xmm0 \n " 
		"L0xABEL_0x0073DA61: \n " 
		"mov eax,dword ptr [ecx+0x6C] \n " 
		"add eax,0x1 \n " 
		"cdq  \n " 
		"mov esi,ebx \n " 
		"idiv esi \n " 
		"mov dword ptr [ecx+0x6C],edx \n " 
		"call _0x48BF00 \n " 
		"movss xmm1,dword ptr [0xE4F814] \n " 
		"divss xmm1,xmm0 \n " 
		"mulss xmm1,dword ptr [0xE4F714] \n " 
		"movss dword ptr [esp+0x8],xmm1 \n " 
		"fld dword ptr [esp+0x8] \n " 
		"push ecx \n " 
		"fstp dword ptr [esp] \n " 
		"call _0x55AE10 \n " 
		"add esp,0x4 \n " 
		"cmp eax,dword ptr [edi+0x228] \n " 
		"je L0xABEL_0x0073DAB7  \n " //!; => 0x0073DAB7
		"mov ecx,dword ptr [edi+0x8] \n " 
		"mov dword ptr [edi+0x228],eax \n " 
		"mov edx,dword ptr [ecx] \n " 
		"push eax \n " 
		"mov eax,dword ptr [edx+0x40] \n " 
		"call eax \n " 
		"L0xABEL_0x0073DAB7: \n " 
		"mov ecx,dword ptr [esp+0x54] \n " 
		"pop esi \n " 
		//"mov dword ptr [0x0],ecx \n " 
		"pop ebx \n " 
		"mov esp,ebp \n " 
		"pop ebp \n " 
	//	"ret  \n " 
		" \n " //! 0xFinis of selected range: 0x0073DAC7
		" \n " //!; Internal calls outside selected range (after)
	);
	return;
}

void Update_Pipeline_Stream()
{
	register int eax asm("eax");
	__asm__
	(
		" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
		" \n " //!; Internal calls outside selected range (before)
		"_0x53C550 =  5490000 \n " 
		"_0x483490 =  4732048 \n " 
		"_0x47BD40 =  4701504 \n " 
		"_0x47C680 =  4703872 \n " 
		"_0xAC51B0 =  11293104 \n " 
		"_0x956DB0 =  9792944 \n " 
		"_0xAC5200 =  11293184 \n " 
		"_0x9566C0 =  9791168 \n " 
		"_0x9556F0 =  9787120 \n " 
		"_0x956DD0 =  9792976 \n " 	
		"_0xA82542 = 0xA82542 \n"
		" \n " //!; Start of selected range: 0x0053F010
		"push ebp \n " 
		"mov ebp,esp \n " 
		"and esp,0xFFFFFFF8 \n " 
		"push 0xFFFFFFFF \n " 
		"push 0xBAA10B \n " 
	//	"mov eax,dword ptr [0x0] \n " 
		"push eax \n " 
	//	"mov dword ptr [0x0],esp \n " 
		"sub esp,0x88 \n " 
		"push ebx \n " 
		"push esi \n " 
		"push edi \n " 
		"mov edi,ecx \n " 
		"lea ecx,dword ptr [edi+0x40C] \n " 
		"mov dword ptr [esp+0x18],ecx \n " 
		"call _0xAC51B0 \n " 
		"mov byte ptr [esp+0x1C],0x1 \n " 
		"xor esi,esi \n " 
		"mov dword ptr [esp+0x9C],esi \n " 
		"mov eax,dword ptr [edi+0x420] \n " 
		"cmp eax,esi \n " 
		"je L0xABEL_0x0053F098  \n " //!; => 0x0053F098
		"mov ebx,dword ptr [edi+0x424] \n " 
		"sub ebx,eax \n " 
		"sar ebx,0x2 \n " 
		"je L0xABEL_0x0053F098  \n " //!; => 0x0053F098
		"lea ebx,dword ptr [ebx] \n " 
		"L0xABEL_0x0053F070: \n " 
		"mov ecx,dword ptr [edi+0x420] \n " 
		"mov edx,dword ptr [ecx+esi*0x4] \n " 
		"lea eax,dword ptr [edi+0x18470] \n " 
		"push eax \n " 
		"lea eax,dword ptr [edi+0x184B8] \n " 
		"push eax \n " 
		"mov eax,dword ptr [ebp+0x8] \n " 
		"push eax \n " 
		"push edx \n " 
		"call _0x53C550 \n " 
		"add esi,0x1 \n " 
		"cmp esi,ebx \n " 
		"jb L0xABEL_0x0053F070  \n " //!; => 0x0053F070
		"L0xABEL_0x0053F098: \n " 
		"mov eax,ebx \n"
	);
		num_clients = eax;
		if(update_pl_count)
		{
			__asm__ volatile
			(
				"call %[func]\n\t"
				: 
				: [func] "i" (&p_Version)
				: "memory"
			);				
			current_num_clients = num_clients;
			update_pl_count = false;
		}
	__asm__
	(	
		"push 0x33 \n " 
		"lea eax,dword ptr [esp+0x44] \n " 
		"push eax \n " 
		"xor edx,edx \n " 
		"call _0x483490 \n " 
		"lea ecx,dword ptr [esp+0x20] \n " 
		"mov byte ptr [esp+0x9C],0x1 \n " 
		"call _0x956DB0 \n " 
		"lea ecx,dword ptr [esp+0x40] \n " 
		"mov dword ptr [esp+0x3C],ecx \n " 
		"mov ecx,dword ptr [esp+0x40] \n " 
		"xor edx,edx \n " 
		"mov dword ptr [esp+0x20],0xE03BEC \n " 
		"mov dh,byte ptr [ecx+0x2] \n " 
		"lea eax,dword ptr [ecx+0x3] \n " 
		"mov dl,byte ptr [ecx+0x1] \n " 
		"mov ecx,edx \n " 
		"cmp ecx,0x3 \n " 
		"jae L0xABEL_0x0053F0E1  \n " //!; => 0x0053F0E1
		"xor ecx,ecx \n " 
		"jmp L0xABEL_0x0053F0E4  \n " //!; => 0x0053F0E4
		"L0xABEL_0x0053F0E1: \n " 
		"add ecx,0xFFFFFFFD \n " 
		"L0xABEL_0x0053F0E4: \n " 
		"add ecx,eax \n " 
		"mov dword ptr [esp+0x28],eax \n " 
		"mov dword ptr [esp+0x24],eax \n " 
		"mov dword ptr [esp+0x2C],ecx \n " 
		"mov dword ptr [esp+0x34],eax \n " 
		"mov dword ptr [esp+0x30],eax \n " 
		"mov dword ptr [esp+0x38],ecx \n " 
		"sub ecx,eax \n " 
		"cmp ecx,0x4 \n " 
		"mov byte ptr [esp+0x9C],0x2 \n " 
		"jb L0xABEL_0x0053F119  \n " //!; => 0x0053F119
		"mov ecx,dword ptr [ebp+0x8] \n " 
		"mov dword ptr [eax],ecx \n " 
		"add dword ptr [esp+0x34],0x4 \n " 
		"jmp L0xABEL_0x0053F129  \n " //!; => 0x0053F129
		"L0xABEL_0x0053F119: \n " 
		"push 0x4 \n " 
		"lea edx,dword ptr [ebp+0x8] \n " 
		"push edx \n " 
		"lea ecx,dword ptr [esp+0x28] \n " 
		"call dword ptr [0xE03C08] \n " 
		"L0xABEL_0x0053F129: \n " 
		"mov eax,dword ptr [edi] \n " 
		"mov edx,dword ptr [eax+0x44] \n " 
		"lea ecx,dword ptr [esp+0x40] \n " 
		"push ecx \n " 
		"mov ecx,edi \n " 
		"call edx \n " 
		"mov ecx,dword ptr [esp+0x18] \n " 
		"add dword ptr [edi+0x438],0x1 \n " 
		"call _0xAC5200 \n " 
		"mov eax,dword ptr [edi+0x18470] \n " 
		"mov edx,dword ptr [eax+0x20] \n " 
		"lea esi,dword ptr [edi+0x18470] \n " 
		"mov ecx,esi \n " 
		"mov byte ptr [esp+0x1C],0x0 \n " 
		"call edx \n " 
		"mov ecx,esi \n " 
		"call _0x9566C0 \n " 
		"test eax,eax \n " 
		
		"je L0xABEL_0x0053F1A0  \n " //!; => 0x0053F1A0
		"lea ebx,dword ptr [edi+0x4] \n " 
		"lea ecx,dword ptr [ecx] \n " 
		
		"L0xABEL_0x0053F170: \n " 
	);
	__asm__
	(
		"push esi \n " 
		"lea eax,dword ptr [esp+0x44] \n " 
		"call _0x47BD40 \n " 
		"mov eax,dword ptr [esp+0x40] \n " 
		"movzx ecx,byte ptr [eax] \n " 
		"mov ecx,dword ptr [ebx+ecx*0x4+0x8] \n " 
		"test ecx,ecx \n " 
		"je L0xABEL_0x0053F195  \n " //!; => 0x0053F195
		"mov edx,dword ptr [ecx] \n " 
		"mov edx,dword ptr [edx] \n " 
		"push ebx \n " 
		"lea eax,dword ptr [esp+0x44] \n " 
		"push eax \n " 
		"call edx \n " 
		"L0xABEL_0x0053F195: \n " 
		"mov ecx,esi \n " 
		"call _0x9566C0 \n " 
		"test eax,eax \n " 
		
		"jne L0xABEL_0x0053F170  \n " //!; => 0x0053F170
		"L0xABEL_0x0053F1A0: \n " 
	);

	__asm__
	(
		"lea eax,dword ptr [esp+0x13] \n " 
		"push eax \n " 
		"mov eax,0x3 \n " 
		"lea esi,dword ptr [esp+0x44] \n " 
		"mov byte ptr [esp+0x17],0x0 \n " 
		"call _0x47C680 \n " 
		"mov ecx,dword ptr [esp+0x40] \n " 
		"mov byte ptr [ecx+0x1],0x3 \n " 
		"mov edx,dword ptr [esp+0x40] \n " 
		"mov byte ptr [edx+0x2],0x0 \n " 
		"mov eax,dword ptr [esp+0x40] \n " 
		"mov byte ptr [eax],0x0 \n " 
		"mov ecx,dword ptr [esp+0x3C] \n " 
		"mov ecx,dword ptr [ecx] \n " 
		"xor edx,edx \n " 
		"mov dh,byte ptr [ecx+0x2] \n " 
		"lea eax,dword ptr [ecx+0x3] \n " 
		"mov dl,byte ptr [ecx+0x1] \n " 
		"mov ecx,edx \n " 
		"cmp ecx,0x3 \n " 
		"jae L0xABEL_0x0053F1EB  \n " //!; => 0x0053F1EB
		"xor ecx,ecx \n " 
		"jmp L0xABEL_0x0053F1EE  \n " //!; => 0x0053F1EE
		"L0xABEL_0x0053F1EB: \n " 
		"add ecx,0xFFFFFFFD \n " 
		"L0xABEL_0x0053F1EE: \n " 
		"add ecx,eax \n " 
		"cmp dword ptr [esp+0x30],0x0 \n " 
		"mov dword ptr [esp+0x28],eax \n " 
		"mov dword ptr [esp+0x24],eax \n " 
		"mov dword ptr [esp+0x2C],ecx \n " 
		"je L0xABEL_0x0053F211  \n " //!; => 0x0053F211
		"mov dword ptr [esp+0x34],eax \n " 
		"mov dword ptr [esp+0x30],eax \n " 
		"mov dword ptr [esp+0x38],ecx \n " 
		"jmp L0xABEL_0x0053F219  \n " //!; => 0x0053F219
		"L0xABEL_0x0053F211: \n " 
		"mov ecx,dword ptr [esp+0x38] \n " 
		"mov eax,dword ptr [esp+0x34] \n " 
		"L0xABEL_0x0053F219: \n " 
		"sub ecx,eax \n " 
		"cmp ecx,0x4 \n " 
		"mov edx,0x1 \n " 
		"mov dword ptr [esp+0x14],edx \n " 
		"jb L0xABEL_0x0053F232  \n " //!; => 0x0053F232
		"mov dword ptr [eax],edx \n " 
		"add dword ptr [esp+0x34],0x4 \n " 
		"jmp L0xABEL_0x0053F246  \n " //!; => 0x0053F246
		"L0xABEL_0x0053F232: \n " 
		"mov edx,dword ptr [esp+0x20] \n " 
		"push 0x4 \n " 
		"lea eax,dword ptr [esp+0x18] \n " 
		"push eax \n " 
		"mov eax,dword ptr [edx+0x1C] \n " 
		"lea ecx,dword ptr [esp+0x28] \n " 
		"call eax \n " 
		"L0xABEL_0x0053F246: \n " 
		"mov ecx,dword ptr [esp+0x40] \n " 
		"movzx edx,byte ptr [ecx] \n " 
		"mov ecx,dword ptr [edi+edx*0x4+0xC] \n " 
		"test ecx,ecx \n " 
		"lea eax,dword ptr [edi+0x4] \n " 
		"je L0xABEL_0x0053F264  \n " //!; => 0x0053F264
		"mov edx,dword ptr [ecx] \n " 
		"mov edx,dword ptr [edx] \n " 
		"push eax \n " 
		"lea eax,dword ptr [esp+0x44] \n " 
		"push eax \n " 
		"call edx \n " 
		"L0xABEL_0x0053F264: \n " 
		"mov eax,dword ptr [edi+0x438] \n " 
		"cmp eax,dword ptr [edi+0x43C] \n " 
		"jne L0xABEL_0x0053F27D  \n " //!; => 0x0053F27D
		"lea ecx,dword ptr [edi+0x184C0] \n " 
		"call _0x9556F0 \n " 
		"L0xABEL_0x0053F27D: \n " 
		"lea ecx,dword ptr [esp+0x20] \n " 
		"mov byte ptr [esp+0x9C],0x1 \n " 
		"call _0x956DD0 \n " 
		"mov eax,dword ptr [esp+0x40] \n " 
		"cmp eax,dword ptr [esp+0x4C] \n " 
		"je L0xABEL_0x0053F2A1  \n " //!; => 0x0053F2A1
		"push eax \n " 
		"call _0xA82542 \n " 
		"add esp,0x4 \n " 
		"L0xABEL_0x0053F2A1: \n " 
		"mov ecx,dword ptr [esp+0x94] \n " 
		"pop edi \n " 
		"pop esi \n " 
	//	"mov dword ptr [0x0],ecx \n " 
		"pop ebx \n " 
		"mov esp,ebp \n " 
		"pop ebp \n " 
		"ret 0x4 \n " 
		" \n " //! 0xFinis of selected range: 0x0053F2B7
		" \n " //!; Internal calls outside selected range (after)
	);
}