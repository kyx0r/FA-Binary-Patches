#include "include/funcDefs.h"
#include "include/global_func_table.h"
#include <stdlib.h>

//FUNCTIONS with NAMES ARE WINAPI FOR THIS FILE. FOR EXAMPLE recvfrom

_DWORD tag_sent = 0;
_DWORD p_index = 0;
_DWORD sender_sock = 1;

__attribute__((noinline)) void p_SetEvent()
{
	((int (*)(const char* fmt, ...))_Logf)("Callback packet received, exit sync is over \n");
	return;
}

__attribute__((noinline)) void p_Tag()
{
	((int (*)(const char* fmt, ...))_Logf)("Tag packet sent \n");
	return;
}

void _recvfrom()
{
	register int eax asm("eax");
	__asm__
	(
		" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
		" \n " //!; Internal calls outside selected range (before)
		"recvfrom =  0x00C0F8D8 \n " //WINAPI
		"L0xABEL_0x0048A94C =  4761932 \n " 
		" \n " //!; Internal calls outside selected range (after)
		"_0xA825B9 =  11019705 \n " 
		"SetEvent = 0x00C0F578 \n"
		" \n " //!; Start of selected range: 0x0048A280
		"push ebp \n " 
		"mov ebp,esp \n " 
		"and esp,0xFFFFFFF8 \n " 
		"push 0xFFFFFFFF \n " 
		"push 0xBB3385 \n " 
		//"mov eax,dword ptr [0x0] \n " 
		"push eax \n " 
		//"mov byte ptr [0],esp \n " 
		"sub esp,0xB0 \n " 
		"push ebx \n " 
		"push esi \n " 
		"lea eax,dword ptr [esp+0x18] \n " 
		"push edi \n " 
		"mov edi,ecx \n " 
		"mov ecx,eax \n " 
		"mov dword ptr [esp+0x20],eax \n " 
		"mov dword ptr [esp+0x1C],ecx \n " 
		"mov dword ptr [esp+0xC4],0x0 \n " 
		"mov ebx,dword ptr [esp+0x20] \n " 
		"lea edx,dword ptr [esp+0x1C] \n " 
		"cmp ebx,edx \n " 
		"jne L0xABEL_0x0048A338  \n " //!; => 0x0048A338
		"lea eax,dword ptr [edi+0x2C] \n " 
		"cmp dword ptr [eax+0x4],eax \n " 
		"jne L0xABEL_0x0048A2F3  \n " //!; => 0x0048A2F3
		"push 0x218 \n " 
		"call _0xA825B9 \n " 
		"add esp,0x4 \n " 
		"test eax,eax \n " 
		"je L0xABEL_0x0048A2ED  \n " //!; => 0x0048A2ED
		"mov dword ptr [eax+0x4],eax \n " 
		"mov dword ptr [eax],eax \n " 
		"mov ebx,eax \n " 
		"jmp L0xABEL_0x0048A30E  \n " //!; => 0x0048A30E
		"L0xABEL_0x0048A2ED: \n " 
		"xor eax,eax \n " 
		"mov ebx,eax \n " 
		"jmp L0xABEL_0x0048A30E  \n " //!; => 0x0048A30E
		"L0xABEL_0x0048A2F3: \n " 
		"add dword ptr [edi+0x34],0xFFFFFFFF \n " 
		"mov ebx,dword ptr [eax+0x4] \n " 
		"mov eax,dword ptr [ebx] \n " 
		"mov ecx,dword ptr [ebx+0x4] \n " 
		"mov dword ptr [eax+0x4],ecx \n " 
		"mov edx,dword ptr [ebx+0x4] \n " 
		"mov eax,dword ptr [ebx] \n " 
		"mov dword ptr [edx],eax \n " 
		"mov dword ptr [ebx+0x4],ebx \n " 
		"mov dword ptr [ebx],ebx \n " 
		"L0xABEL_0x0048A30E: \n " 
		"mov ecx,dword ptr [ebx] \n " 
		"mov edx,dword ptr [ebx+0x4] \n " 
		"mov dword ptr [ecx+0x4],edx \n " 
		"mov eax,dword ptr [ebx+0x4] \n " 
		"mov ecx,dword ptr [ebx] \n " 
		"mov dword ptr [eax],ecx \n " 
		"mov dword ptr [ebx],ebx \n " 
		"mov dword ptr [ebx+0x4],ebx \n " 
		"mov edx,dword ptr [esp+0x1C] \n " 
		"mov dword ptr [ebx],edx \n " 
		"lea eax,dword ptr [esp+0x1C] \n " 
		"mov dword ptr [ebx+0x4],eax \n " 
		"mov dword ptr [esp+0x1C],ebx \n " 
		"mov ecx,dword ptr [ebx] \n " 
		"mov dword ptr [ecx+0x4],ebx \n " 
		"L0xABEL_0x0048A338: \n " 
		"lea edx,dword ptr [esp+0x4C] \n " 
		"push edx \n " // (fromlen) An optional pointer to the size, in bytes, of the buffer pointed to by the from parameter.
		"mov edx,dword ptr [edi+0x14] \n " 
		"lea ecx,dword ptr [esp+0xAC] \n " 
		"push ecx \n " // (from) An optional pointer to a buffer in a sockaddr structure that will hold the source address upon return.
		"push 0x0 \n " // (flags) A set of flags that specify the way in which the call is made.
		"lea eax,dword ptr [ebx+0x18] \n " 
		"push 0x200 \n " //(len) The length, in bytes, of the data pointed to by the buf parameter.
		"push eax \n " //(buf) A buffer for the incoming data.
		"push edx \n " // (s)A descriptor identifying a bound socket.
		"mov dword ptr [esp+0x64],0x10 \n " 
		"mov dword ptr [esp+0x3C],eax \n " 
		"mov dword ptr [0x11FD247], eax \n" //STORE NETWORK BUFFER POINTER (SEE REASON BELOW)
		"call dword ptr [recvfrom] \n " //recvfrom RETURNS NUMBER OF BYTES WRITTEN TO THE NET BUFFER IN EAX REGISTER
		"mov esi,eax \n " 
		"mov eax, dword ptr [0x11FD247] \n" //RETREIVE NETBUFFER PTR
	);	
	__asm__ volatile
	(
		"cmp dword ptr [0x011FD243], 0x1 \n" // check if we are the sender
		"jne not_sender \n"
		"cmp byte ptr [eax+0x3], 0xFE \n"
		"jne not_received \n"
		"mov byte ptr [eax+0x3], 0x0 \n" //JUST IN CASE CLEAR THE VARIABLE FROM NET BUFFER	
	);	
	p_index++;
	if((current_num_clients-1) - p_index == 0)
	{
		__asm__
		(
		"push dword ptr [0x11FD253] \n"
		"call dword ptr [SetEvent] \n"			
		);
		p_index = 0;
	}
		
	__asm__ volatile
	(
		"call %[func]\n\t"
		"jmp not_received \n"	
		: 
		: [func] "i" (&p_SetEvent)
		: "memory"
	);	
		
	__asm__
	(	
		"not_sender: \n"
		"cmp byte ptr [eax+0x3], 0xFF \n" //CHECK IF EXIT VARIABLE IS SET 
		"jne _skip \n"
		"mov byte ptr [eax+0x3], 0x0 \n" //JUST IN CASE CLEAR THE VARIABLE FROM NET BUFFER
		"mov dword ptr [0x011FD23F], 0x1 \n" //WRITE INTO THE LOCAL MEMORY SO THAT BLOCK CAN READ IT LATER
		"mov eax,dword ptr [esp+0xA8] \n " //get sender's socket
	);
	if(sender_sock)
	{
		sender_sock = eax;
	}

	__asm__
	(	
		"_skip: \n"
		"not_received: \n"
		
	/* 	"lea edx,dword ptr [esp+0x4C] \n " //CUSTOM PACKET (A BUGGY MESS)
		"push edx \n "
		"lea ecx,dword ptr [esp+0xAC] \n " 
		"push ecx \n " 	
		"push 0x0 \n " 
		"push 0x16 \n " 
		"push 0x011FD24F \n " 
		"mov edx,dword ptr [edi+0x14] \n " 
		"push edx \n " 
		"call dword ptr [recvfrom] \n "
		"test eax,eax \n"
		"jl _skip \n"
		"int3 \n"
		"mov dword ptr [0x011FD23F], 0x1 \n"
		"_skip: \n" */
		
		"test esi,esi \n " 
		"mov dword ptr [esp+0x10],esi \n " 
		"jl L0xABEL_0x0048A94C  \n " // function continues... 
		"jmp 0x0048A374 \n" //THERE ARE A LOT MORE CODE FURTHER BUT I AM LAZY TO WRITE IT BECAUSE THERE IS SWITCH CASE
		//WHICH REQUIRES MANUAL CODING.
		" \n " //! 0xFinis of selected range: 0x0048A373
		" \n " //!; Labels outside selected range (after)
	);
	
}

void _sendto()
{
	register int eax asm("eax");
	__asm__
	(
		" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
		" \n " //!; Internal calls outside selected range (before)
		"_0x488170 =  4751728 \n " 
		"_0x47D0A0 =  4706464 \n " 
		"_0x488BC0 =  4754368 \n " 
		"_0x485CB0 =  4742320 \n " 
		"_0x488260 =  4751968 \n " 
		"_0x489F30 =  4759344 \n " 
		"_0x48B040 =  4763712 \n " 
		"_0x489ED0 =  4759248 \n " 
		"_0x937C30 =  9665584 \n " 
		"_0x9566C0 =  9791168 \n " 
		"_0xA899A0 =  11049376 \n " 
		"_0x9556F0 =  9787120 \n " 	
		"_0x957A60 =  0x957A60 \n"
		"htons = 0x00C0F8D0 \n"
		"htonl = 0x00C0F8CC \n"
		"sendto = 0x00C0F8E0 \n"
		" \n " //!; Start of selected range: 0x00488D80
		"push 0xFFFFFFFF \n " 
		"push 0xB9B638 \n " 
		//"mov eax,dword ptr [0x0] \n " 
		"push eax \n " 
		//"mov dword ptr [0x0],esp \n " 
		"sub esp,0x7C \n " 
		"push ebx \n " 
		"push ebp \n " 
		"mov ebp,dword ptr [esp+0x94] \n " 
		"mov ax,word ptr [ebp+0x4A0] \n " 
		"push esi \n " 
		"mov ebx,ecx \n " 
		"push edi \n " 
		"lea edi,dword ptr [ebx+0x18] \n " 
		"mov word ptr [edi+0x5],ax \n " 
		"mov cx,word ptr [ebp+0x4A2] \n " 
		"mov word ptr [edi+0x7],cx \n " 
		"movzx edx,word ptr [ebp+0x420] \n " 
		"push edx \n " 
		"mov dword ptr [esp+0x18],edi \n " 
		"mov word ptr [esp+0x28],0x2 \n " 
		
		"call dword ptr [htons] \n " 
		
		"mov word ptr [esp+0x26],ax \n " 
		"mov eax,dword ptr [ebp+0x41C] \n " 
		"push eax \n " 
		
		"call dword ptr [htonl] \n " 
		
		"mov edx,dword ptr [ebp+0x418] \n " 
		"mov ecx,dword ptr [ebx+0x14] \n " 
		"push 0x10 \n " // (tolen) The size, in bytes, of the address pointed to by the to parameter.
		"mov dword ptr [esp+0x2C],eax \n " 
		"mov eax,dword ptr [edx+0x14] \n " 
		"lea edx,dword ptr [esp+0x28] \n " 
		"push edx \n " // (to) An optional pointer to a sockaddr structure that contains the address of the target socket.
		"push 0x0 \n " // (flags) A set of flags that specify the way in which the call is made.
		"push ecx \n " //(len) The length, in bytes, of the data pointed to by the buf parameter.
		"push edi \n " //(buf) A pointer to a buffer containing the data to be transmitted.
		"push eax \n " // (s) A descriptor identifying a (possibly connected) socket.
		"mov dword ptr [esp+0x28],ecx \n " 
		"cmp dword ptr [0x011FD243], 0x1 \n" //CHECK IF SESSIONENDGAME WAS TRIGGERED (sender only)
		"jne is_receiver \n"
		"mov eax, edi \n" //if here, it is sender
		"mov byte ptr [eax + 0x3], 0xFF \n" //WRITE VAR INTO THE PACKET HEADER
		"jmp skip \n"
		
		"is_receiver: \n"
		
		"cmp dword ptr [0x011FD23F], 0x1 \n" //check if receiver got packet (block var)
		"jne skip \n"
		"mov eax, dword ptr [edx] \n"
	);
	if(!terminated)
	{
		if(sender_sock == eax)
		{
			__asm__ volatile
			(
				"mov dword ptr [0x011FD23F+0x30],eax \n"
				"call %[func]\n\t"
				: 
				: [func] "i" (&p_Tag)
				: "memory"
			);				
			__asm__
			(
			"mov eax, edi \n"
			"mov byte ptr [eax + 0x3], 0xFE \n" //if receiver got the packet, notify the sender with 0xFE
			);
			sender_sock = 0;
		}
	}
	__asm__
	(		
		"skip: \n"
		"call dword ptr [sendto] \n " 
		
/* 		"cmp dword ptr [0x011FD23F], 0x1 \n" //CUSTOM PACKET (A BUGGY MESS)
		"jne skip \n"
		"mov dword ptr [0x011FD24F], 0x1 \n"
		"push 0x10 \n "
		"lea edx,dword ptr [esp+0x28] \n "
		"push edx \n " 
		"push 0x0 \n " 
		"push 0x16 \n " 
		"push 0x011FD24F \n " 
		"mov edx,dword ptr [ebp+0x418] \n "
		"mov eax,dword ptr [edx+0x14] \n "
		"push eax \n "	
		"call dword ptr [sendto] \n "
		"skip: \n" */
		
		"mov esi,dword ptr [ebp+0x418] \n " 
		"call _0x489F30 \n " 
		"cmp byte ptr [0x10A6381],0x0 \n " 
		"mov ecx,dword ptr [ebp+0x41C] \n " 
		"mov esi,eax \n " 
		"movzx eax,word ptr [ebp+0x420] \n " 
		"mov dword ptr [esp+0x1C],esi \n " 
		"mov dword ptr [esp+0x20],edx \n " 
		"je L0xABEL_0x00488E59  \n " //!; => 0x00488E59
		"mov edx,dword ptr [esp+0x10] \n " 
		"push edx \n " 
		"push edi \n " 
		"mov edi,dword ptr [ebp+0x418] \n " 
		"push eax \n " 
		"mov eax,dword ptr [esp+0x2C] \n " 
		"push ecx \n " 
		"push eax \n " 
		"push esi \n " 
		"xor ecx,ecx \n " 
		"call _0x48B040 \n " 
		"mov edi,dword ptr [esp+0x14] \n " 
		"L0xABEL_0x00488E59: \n " 
		"cmp byte ptr [edi],0x4 \n " 
		"jne L0xABEL_0x00488EC4  \n " //!; => 0x00488EC4
		"mov ecx,ebx \n " 
		"mov eax,ebp \n " 
		"call _0x488170 \n " 
		"add eax,esi \n " 
		"adc edx,dword ptr [esp+0x20] \n " 
		"add dword ptr [ebx+0x10],0x1 \n " 
		"mov dword ptr [ebx+0x8],eax \n " 
		"mov dword ptr [ebx+0xC],edx \n " 
		"mov eax,dword ptr [ebp+0x514] \n " 
		"lea ecx,dword ptr [ebp+0x510] \n " 
		"cmp eax,ecx \n " 
		"je L0xABEL_0x00488EA0  \n " //!; => 0x00488EA0
		"L0xABEL_0x00488E87: \n " 
		"mov edx,dword ptr [ebx+0xC] \n " 
		"cmp edx,dword ptr [eax+0xC] \n " 
		"jl L0xABEL_0x00488EA0  \n " //!; => 0x00488EA0
		"jg L0xABEL_0x00488E99  \n " //!; => 0x00488E99
		"mov edx,dword ptr [ebx+0x8] \n " 
		"cmp edx,dword ptr [eax+0x8] \n " 
		"jb L0xABEL_0x00488EA0  \n " //!; => 0x00488EA0
		"L0xABEL_0x00488E99: \n " 
		"mov eax,dword ptr [eax+0x4] \n " 
		"cmp eax,ecx \n " 
		"jne L0xABEL_0x00488E87  \n " //!; => 0x00488E87
		"L0xABEL_0x00488EA0: \n " 
		"mov ecx,dword ptr [ebx] \n " 
		"mov edx,dword ptr [ebx+0x4] \n " 
		"mov dword ptr [ecx+0x4],edx \n " 
		"mov ecx,dword ptr [ebx+0x4] \n " 
		"mov edx,dword ptr [ebx] \n " 
		"mov dword ptr [ecx],edx \n " 
		"mov dword ptr [ebx],ebx \n " 
		"mov dword ptr [ebx+0x4],ebx \n " 
		"mov ecx,dword ptr [eax] \n " 
		"mov dword ptr [ebx],ecx \n " 
		"mov dword ptr [ebx+0x4],eax \n " 
		"mov dword ptr [eax],ebx \n " 
		"mov edx,dword ptr [ebx] \n " 
		"mov dword ptr [edx+0x4],ebx \n " 
		"jmp L0xABEL_0x00488ED1  \n " //!; => 0x00488ED1
		"L0xABEL_0x00488EC4: \n " 
		"mov edx,dword ptr [ebp+0x418] \n " 
		"mov eax,ebx \n " 
		"call _0x489ED0 \n " 
		"L0xABEL_0x00488ED1: \n " 
		"mov ecx,dword ptr [esp+0x10] \n " 
		"mov edx,dword ptr [esp+0x20] \n " 
		"mov eax,dword ptr [ebp+0x418] \n " 
		"push ecx \n " 
		"push edx \n " 
		"push esi \n " 
		"push 0x0 \n " 
		"lea edx,dword ptr [eax+0x80] \n " 
		"call _0x47D0A0 \n " 
		"cmp dword ptr [0x10A6384],0x2 \n " 
		"jl L0xABEL_0x0048901B  \n " //!; => 0x0048901B
		"lea eax,dword ptr [esp+0x6C] \n " 
		"push eax \n " 
		"mov esi,ebx \n " 
		"call _0x488BC0 \n " 
		"add esp,0x4 \n " 
		"mov ebx,eax \n " 
		"mov dword ptr [esp+0x94],0x0 \n " 
		"mov edx,dword ptr [ebp] \n " 
		"mov edx,dword ptr [edx+0x18] \n " 
		"lea eax,dword ptr [esp+0x50] \n " 
		"push eax \n " 
		"mov ecx,ebp \n " 
		"call edx \n " 
		"mov dword ptr [esp+0x14],eax \n " 
		"mov eax,dword ptr [esp+0x20] \n " 
		"mov ecx,dword ptr [esp+0x1C] \n " 
		"push eax \n " 
		"push ecx \n " 
		"lea esi,dword ptr [esp+0x3C] \n " 
		"mov byte ptr [esp+0x9C],0x1 \n " 
		"call _0x485CB0 \n " 
		"add esp,0x8 \n " 
		"mov esi,0x10 \n " 
		"mov byte ptr [esp+0x94],0x2 \n " 
		"cmp dword ptr [ebx+0x18],esi \n " 
		"jb L0xABEL_0x00488F60  \n " //!; => 0x00488F60
		"mov ebx,dword ptr [ebx+0x4] \n " 
		"jmp L0xABEL_0x00488F63  \n " //!; => 0x00488F63
		"L0xABEL_0x00488F60: \n " 
		"add ebx,0x4 \n " 
		"L0xABEL_0x00488F63: \n " 
		"mov ecx,dword ptr [esp+0x14] \n " 
		"cmp dword ptr [ecx+0x18],esi \n " 
		"jb L0xABEL_0x00488F71  \n " //!; => 0x00488F71
		"mov ecx,dword ptr [ecx+0x4] \n " 
		"jmp L0xABEL_0x00488F74  \n " //!; => 0x00488F74
		"L0xABEL_0x00488F71: \n " 
		"add ecx,0x4 \n " 
		"L0xABEL_0x00488F74: \n " 
		"cmp dword ptr [eax+0x18],esi \n " 
		"jb L0xABEL_0x00488F7E  \n " //!; => 0x00488F7E
		"mov eax,dword ptr [eax+0x4] \n " 
		"jmp L0xABEL_0x00488F81  \n " //!; => 0x00488F81
		"L0xABEL_0x00488F7E: \n " 
		"add eax,0x4 \n " 
		"L0xABEL_0x00488F81: \n " 
		"push 0xE00779 \n " 
		"push ebx \n " 
		"push ecx \n " 
		"push eax \n " 
		"push 0xE05AB0 \n " 
		"call _0x937C30 \n " 
		"add esp,0x14 \n " 
		"cmp dword ptr [esp+0x4C],esi \n " 
		"jb L0xABEL_0x00488FA9  \n " //!; => 0x00488FA9
		"mov edx,dword ptr [esp+0x38] \n " 
		"push edx \n " 
		"call _0x957A60 \n " 
		"add esp,0x4 \n " 
		"L0xABEL_0x00488FA9: \n " 
		"xor ebx,ebx \n " 
		"cmp dword ptr [esp+0x68],esi \n " 
		"mov dword ptr [esp+0x4C],0xF \n " 
		"mov dword ptr [esp+0x48],ebx \n " 
		"mov byte ptr [esp+0x38],bl \n " 
		"jb L0xABEL_0x00488FCE  \n " //!; => 0x00488FCE
		"mov eax,dword ptr [esp+0x54] \n " 
		"push eax \n " 
		"call _0x957A60 \n " 
		"add esp,0x4 \n " 
		"L0xABEL_0x00488FCE: \n " 
		"mov dword ptr [esp+0x94],0xFFFFFFFF \n " 
		"cmp dword ptr [esp+0x84],esi \n " 
		"mov dword ptr [esp+0x68],0xF \n " 
		"mov dword ptr [esp+0x64],ebx \n " 
		"mov byte ptr [esp+0x54],0x0 \n " 
		"jb L0xABEL_0x00489000  \n " //!; => 0x00489000
		"mov ecx,dword ptr [esp+0x70] \n " 
		"push ecx \n " 
		"call _0x957A60 \n " 
		"add esp,0x4 \n " 
		"L0xABEL_0x00489000: \n " 
		"mov esi,dword ptr [esp+0x1C] \n " 
		"mov dword ptr [esp+0x84],0xF \n " 
		"mov dword ptr [esp+0x80],ebx \n " 
		"mov byte ptr [esp+0x70],0x0 \n " 
		"L0xABEL_0x0048901B: \n " 
		"add word ptr [ebp+0x4A0],0x1 \n " 
		"xor ebx,ebx \n " 
		"lea ecx,dword ptr [ebp+0x4B8] \n " 
		"mov word ptr [ebp+0x4A2],bx \n " 
		"call _0x9566C0 \n " 
		"test eax,eax \n " 
		"je L0xABEL_0x00489077  \n " //!; => 0x00489077
		"mov eax,dword ptr [0xF58DE4] \n " 
		"push ebx \n " 
		"cdq  \n " 
		"push 0x3E8 \n " 
		"push edx \n " 
		"push eax \n " 
		"call _0xA899A0 \n " 
		"mov esi,dword ptr [ebp+0x418] \n " 
		"mov ebx,eax \n " 
		"mov dword ptr [esp+0x18],edx \n " 
		"call _0x489F30 \n " 
		"mov esi,dword ptr [esp+0x1C] \n " 
		"add eax,ebx \n " 
		"adc edx,dword ptr [esp+0x18] \n " 
		"mov dword ptr [ebp+0x4A8],eax \n " 
		"mov dword ptr [ebp+0x4AC],edx \n " 
		"jmp L0xABEL_0x00489083  \n " //!; => 0x00489083
		"L0xABEL_0x00489077: \n " 
		"mov dword ptr [ebp+0x4A8],ebx \n " 
		"mov dword ptr [ebp+0x4AC],ebx \n " 
		"L0xABEL_0x00489083: \n " 
		"movzx eax,word ptr [edi+0x5] \n " 
		"movzx edx,ax \n " 
		"and edx,0x8000007F \n " 
		"jns L0xABEL_0x00489097  \n " //!; => 0x00489097
		"dec edx \n " 
		"or edx,0xFFFFFF80 \n " 
		"inc edx \n " 
		"L0xABEL_0x00489097: \n " 
		"shl edx,0x4 \n " 
		"mov word ptr [edx+ebp+0x518],ax \n " 
		"movzx ecx,word ptr [edi+0x5] \n " 
		"and ecx,0x8000007F \n " 
		"jns L0xABEL_0x004890B3  \n " //!; => 0x004890B3
		"dec ecx \n " 
		"or ecx,0xFFFFFF80 \n " 
		"inc ecx \n " 
		"L0xABEL_0x004890B3: \n " 
		"add ecx,0x52 \n " 
		"shl ecx,0x4 \n " 
		"add ecx,ebp \n " 
		"call _0x9556F0 \n " 
		"mov eax,dword ptr [esp+0x20] \n " 
		"push eax \n " 
		"push esi \n " 
		"mov esi,ebp \n " 
		"call _0x488260 \n " 
		"add eax,dword ptr [esp+0x10] \n " 
		"mov ecx,dword ptr [esp+0x20] \n " 
		"mov dword ptr [ebp+0x438],eax \n " 
		"mov eax,dword ptr [esp+0x1C] \n " 
		"mov dword ptr [ebp+0x430],eax \n " 
		"mov dword ptr [ebp+0x434],ecx \n " 
		"cmp byte ptr [edi],0x5 \n " 
		"je L0xABEL_0x004890FC  \n " //!; => 0x004890FC
		"mov dword ptr [ebp+0x448],eax \n " 
		"mov dword ptr [ebp+0x44C],ecx \n " 
		"L0xABEL_0x004890FC: \n " 
		"cmp byte ptr [edi],0x6 \n " 
		"jne L0xABEL_0x0048910B  \n " //!; => 0x0048910B
		"mov dword ptr [ebp+0x450],0x1E8480 \n " 
		"L0xABEL_0x0048910B: \n " 
		"mov ecx,dword ptr [esp+0x8C] \n " 
		"pop edi \n " 
		"pop esi \n " 
		"pop ebp \n " 
		//"mov dword ptr [0x0],ecx \n " 
		"pop ebx \n " 
		"add esp,0x88 \n " 
		"ret 0x4 \n " 
		" \n " //! 0xFinis of selected range: 0x00489125
		" \n " //!; Internal calls outside selected range (after)
	);
	
}

void Gpg_Net_Entry()
{
	__asm__
	(
		" \n " //!; Source: forgedalliance_exxt.exe (base 0x00400000 - 4194304)
		" \n " //!; Internal calls outside selected range (before)
		"_0x4141A0 =  4276640 \n " 
		"_0x486150 =  4743504 \n " 
		"_0x489F30 =  4759344 \n " 
		"_0x485CB0 =  4742320 \n " 
		"_0x938F10 =  9670416 \n " 
		"_0x9071D0 =  9466320 \n " 
		"_0xAC51B0 =  11293104 \n " 
		"_0xA8540F =  11031567 \n " 
		"_0x48AC40 =  4762688 \n " 
		"_0xAC5200 =  11293184 \n " 
		"_0x937C30 =  9665584 \n " 
		"_0xA8EB30 =  11070256 \n " 
		"_0x48A280 = 0x48A280 \n"
		"GetCurrentThread = 0x00C0F588 \n"
		"SetThreadPriority = 0x00C0F52C \n"
		"WSAWaitForMultipleEvents = 0x00C0F930 \n"
		"WSAResetEvent = 0x00C0F8FC \n"
		"CreateEvent = 0x00C0F57C \n"
		
		" \n " //!; Start of selected range: 0x00489F90
		"push 0xFFFFFFFF \n " 
		"push 0xBB33B8 \n " 
	//	"mov eax,dword ptr [0x0] \n " 
		"push eax \n " 
	//	"mov dword ptr [0x0],esp \n " 
		"sub esp,0x58 \n " 
		"push ebx \n " 
		"push ebp \n " 
		"push esi \n " 
		"push edi \n " 
		"mov edi,ecx \n " 
		"mov dword ptr [esp+0x14],edi \n " 
		"mov dword ptr [esp+0x70],0x0 \n " 
		"mov eax,dword ptr [edi] \n " 
		"mov edx,dword ptr [eax+0xC] \n " 
		"call edx \n " 
		"movzx eax,ax \n " 
		"push eax \n " 
		"lea ecx,dword ptr [esp+0x34] \n " 
		"push 0xE05B04 \n " 
		"push ecx \n " 
		"call _0x938F10 \n " 
		"add esp,0xC \n " 
		"mov byte ptr [esp+0x70],0x1 \n " 
		"cmp dword ptr [esp+0x48],0x10 \n " 
		"mov eax,dword ptr [esp+0x34] \n " 
		"jae L0xABEL_0x00489FEB  \n " //!; => 0x00489FEB
		"lea eax,dword ptr [esp+0x34] \n " 
		"L0xABEL_0x00489FEB: \n " 
		"push eax \n " 
		"push 0xFFFFFFFF \n " 
		"call _0x9071D0 \n " 
		"add esp,0x8 \n " 
		"xor bl,bl \n " 
		"call _0x4141A0 \n " 
		"push 0x2 \n " 
		"call dword ptr [GetCurrentThread] \n " 
		"push eax \n " 
		"call dword ptr [SetThreadPriority] \n " 
		
		"xor ecx, ecx \n"
		"push ecx \n"
		"push ecx \n"
		"push ecx \n"
		"push ecx \n"
		"call dword ptr [CreateEvent] \n"
		"mov dword ptr [0x11FD253], eax \n"
		
		
		"lea ecx,dword ptr [edi+0x8] \n " 
		"mov dword ptr [esp+0x1C],ecx \n " 
		"call _0xAC51B0 \n " 
		"mov byte ptr [esp+0x20],0x1 \n " 
		"mov byte ptr [esp+0x70],0x2 \n " 
		"L0xABEL_0x0048A022: \n " 
		"cmp byte ptr [0x10A6381],0x0 \n " 
		"jne L0xABEL_0x0048A048  \n " //!; => 0x0048A048
		"mov eax,dword ptr [edi+0x18088] \n " 
		"test eax,eax \n " 
		"je L0xABEL_0x0048A048  \n " //!; => 0x0048A048
		"push eax \n " 
		"call _0xA8540F \n " 
		"add esp,0x4 \n " 
		"mov dword ptr [edi+0x18088],0x0 \n " 
		"L0xABEL_0x0048A048: \n " 
		"mov ecx,edi \n " 
		"call _0x48A280 \n " 
		"mov ecx,edi \n " 
		"call _0x48AC40 \n " 
		"cmp byte ptr [edi+0x50],0x0 \n " 
		"mov ebx,eax \n " 
		"mov dword ptr [esp+0x18],ebx \n " 
		"je L0xABEL_0x0048A0AC  \n " //!; => 0x0048A0AC
		"cmp byte ptr [edi+0x51],0x0 \n " 
		"jne L0xABEL_0x0048A0AC  \n " //!; => 0x0048A0AC
		"mov esi,dword ptr [edi+0x28] \n " 
		"lea ebx,dword ptr [edi+0x24] \n " 
		"cmp esi,ebx \n " 
		"je L0xABEL_0x0048A09F  \n " //!; => 0x0048A09F
		"L0xABEL_0x0048A072: \n " 
		"test esi,esi \n " 
		"je L0xABEL_0x0048A07E  \n " //!; => 0x0048A07E
		"lea ebp,dword ptr [esi-0x410] \n " 
		"jmp L0xABEL_0x0048A080  \n " //!; => 0x0048A080
		"L0xABEL_0x0048A07E: \n " 
		"xor ebp,ebp \n " 
		"L0xABEL_0x0048A080: \n " 
		"cmp byte ptr [ebp+0xE41],0x0 \n " 
		"mov esi,dword ptr [esi+0x4] \n " 
		"je L0xABEL_0x0048A09B  \n " //!; => 0x0048A09B
		"push ebp \n " 
		"call _0x486150 \n " 
		"push ebp \n " 
		"call _0x957A60 \n " 
		"add esp,0x4 \n " 
		"L0xABEL_0x0048A09B: \n " 
		"cmp esi,ebx \n " 
		"jne L0xABEL_0x0048A072  \n " //!; => 0x0048A072
		"L0xABEL_0x0048A09F: \n " 
		"cmp dword ptr [ebx+0x4],ebx \n " 
		"je L0xABEL_0x0048A1D5  \n " //!; => 0x0048A1D5
		"mov ebx,dword ptr [esp+0x18] \n " 
		"L0xABEL_0x0048A0AC: \n " 
		"mov ecx,dword ptr [esp+0x1C] \n " 
		"call _0xAC5200 \n " 
		
		"cmp byte ptr [0x10A6380],0x0 \n " 
		"mov byte ptr [esp+0x20],0x0 \n " 
		"je L0xABEL_0x0048A0CA  \n " //!; => 0x0048A0CA
		"mov dword ptr [0x0], eax \n"
		"L0xABEL_0x0048A0CA: \n " 
		
		"cmp byte ptr [0x011FD24F], 0x0 \n"
		"je no_quit \n"
		"mov dword ptr [0x011FD243], 0x1 \n"
		"no_quit: \n"

		"xor ebp,ebp \n " 
		"cmp dword ptr [0x10A6384],0x3 \n " 
		"mov dword ptr [esp+0x28],ebp \n " 
		"jl L0xABEL_0x0048A132  \n " //!; => 0x0048A132
		"mov esi,edi \n " 
		"call _0x489F30 \n " 
		"mov ebp,eax \n " 
		"push edx \n " 
		"push ebp \n " 
		"lea esi,dword ptr [esp+0x54] \n " 
		"mov dword ptr [esp+0x30],edx \n " 
		"call _0x485CB0 \n " 
		"add esp,0x8 \n " 
		"mov esi,0x10 \n " 
		"mov byte ptr [esp+0x70],0x3 \n " 
		"cmp dword ptr [eax+0x18],esi \n " 
		"jb L0xABEL_0x0048A108  \n " //!; => 0x0048A108
		"mov eax,dword ptr [eax+0x4] \n " 
		"jmp L0xABEL_0x0048A10B  \n " //!; => 0x0048A10B
		"L0xABEL_0x0048A108: \n " 
		"add eax,0x4 \n " 
		"L0xABEL_0x0048A10B: \n " 
		"push ebx \n " 
		"push eax \n " 
		"push 0xE05B24 \n " 
		"call _0x937C30 \n " 
		"add esp,0xC \n " 
		"mov byte ptr [esp+0x70],0x2 \n " 
		"cmp dword ptr [esp+0x64],esi \n " 
		"jb L0xABEL_0x0048A132  \n " //!; => 0x0048A132
		"mov edx,dword ptr [esp+0x50] \n " 
		"push edx \n " 
		"call _0x957A60 \n " 
		"add esp,0x4 \n " 
		"L0xABEL_0x0048A132: \n " 
		"push 0x1 \n " 
		"push ebx \n " 
		"push 0x0 \n " 
		"lea eax,dword ptr [edi+0x18] \n " 
		"push eax \n " 
		"push 0x1 \n " 
		"call dword ptr [WSAWaitForMultipleEvents] \n " 
		"mov eax,ebp \n " 
		"or eax,dword ptr [esp+0x28] \n " 
		"je L0xABEL_0x0048A1B8  \n " //!; => 0x0048A1B8
		"mov esi,edi \n " 
		"call _0x489F30 \n " 
		"mov ebx,edx \n " 
		"mov edi,eax \n " 
		"push ebx \n " 
		"push edi \n " 
		"lea esi,dword ptr [esp+0x54] \n " 
		"call _0x485CB0 \n " 
		"add esp,0x8 \n " 
		"mov byte ptr [esp+0x70],0x4 \n " 
		"cmp dword ptr [eax+0x18],0x10 \n " 
		"jb L0xABEL_0x0048A174  \n " //!; => 0x0048A174
		"mov esi,dword ptr [eax+0x4] \n " 
		"jmp L0xABEL_0x0048A177  \n " //!; => 0x0048A177
		"L0xABEL_0x0048A174: \n " 
		"lea esi,dword ptr [eax+0x4] \n " 
		"L0xABEL_0x0048A177: \n " 
		"push 0x0 \n " 
		"sub edi,ebp \n " 
		"sbb ebx,dword ptr [esp+0x2C] \n " 
		"push 0x3E8 \n " 
		"push ebx \n " 
		"push edi \n " 
		"call _0xA8EB30 \n " 
		"push edx \n " 
		"push eax \n " 
		"push esi \n " 
		"push 0xE05B40 \n " 
		"call _0x937C30 \n " 
		"add esp,0x10 \n " 
		"mov byte ptr [esp+0x70],0x2 \n " 
		"cmp dword ptr [esp+0x64],0x10 \n " 
		"jb L0xABEL_0x0048A1B4  \n " //!; => 0x0048A1B4
		"mov ecx,dword ptr [esp+0x50] \n " 
		"push ecx \n " 
		"call _0x957A60 \n " 
		"add esp,0x4 \n " 
		"L0xABEL_0x0048A1B4: \n " 
		"mov edi,dword ptr [esp+0x14] \n " 
		"L0xABEL_0x0048A1B8: \n " 
		"mov ecx,dword ptr [esp+0x1C] \n " 
		"call _0xAC51B0 \n " 
		"mov edx,dword ptr [edi+0x18] \n " 
		"push edx \n " 
		"mov byte ptr [esp+0x24],0x1 \n " 
		"call dword ptr [WSAResetEvent] \n " 
		"jmp L0xABEL_0x0048A022  \n " //!; => 0x0048A022
		"L0xABEL_0x0048A1D5: \n " 
		"mov ecx,dword ptr [esp+0x1C] \n " 
		"call _0xAC5200 \n " 
		"cmp dword ptr [esp+0x48],0x10 \n " 
		"jb L0xABEL_0x0048A1F2  \n " //!; => 0x0048A1F2
		"mov eax,dword ptr [esp+0x34] \n " 
		"push eax \n " 
		"call _0x957A60 \n " 
		"add esp,0x4 \n " 
		"L0xABEL_0x0048A1F2: \n " 
		"mov dword ptr [esp+0x70],0xFFFFFFFF \n " 
		"mov esi,dword ptr [esp+0x7C] \n " 
		"test esi,esi \n " 
		"mov dword ptr [esp+0x48],0xF \n " 
		"mov dword ptr [esp+0x44],0x0 \n " 
		"mov byte ptr [esp+0x34],0x0 \n " 
		"je L0xABEL_0x0048A241  \n " //!; => 0x0048A241
		"lea ecx,dword ptr [esi+0x4] \n " 
		"or edx,0xFFFFFFFF \n " 
		"lock xadd dword ptr [ecx],edx \n " 
		"jne L0xABEL_0x0048A241  \n " //!; => 0x0048A241
		"mov eax,dword ptr [esi] \n " 
		"mov edx,dword ptr [eax+0x4] \n " 
		"mov ecx,esi \n " 
		"call edx \n " 
		"lea eax,dword ptr [esi+0x8] \n " 
		"or ecx,0xFFFFFFFF \n " 
		"lock xadd dword ptr [eax],ecx \n " 
		"jne L0xABEL_0x0048A241  \n " //!; => 0x0048A241
		"mov edx,dword ptr [esi] \n " 
		"mov eax,dword ptr [edx+0x8] \n " 
		"mov ecx,esi \n " 
		"call eax \n " 
		"L0xABEL_0x0048A241: \n " 
		"mov ecx,dword ptr [esp+0x68] \n " 
		"pop edi \n " 
		"pop esi \n " 
		"pop ebp \n " 
		//"mov dword ptr [0x0],ecx \n " 
		"pop ebx \n " 
		"add esp,0x64 \n " 
		"ret 0x8 \n " 
		" \n " //! 0xFinis of selected range: 0x0048A255
		" \n " //!; Internal calls outside selected range (after)
	);
	
}