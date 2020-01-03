//HOOK SimArmyCreate ROffset = 0x002FF3D1
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"

__asm__
(
    ".equ _funcPtr,"QU(SimArmyCreate)"-0x006FF3D1 \n"
);

__asm__
(
    "JMP _funcPtr \n"
    "NOP \n"
	"call 0x004059E0 -0x006FF3D1\n " 
	"mov bl,0x28 \n " 
	"lea ecx, [esp+0x10C] \n " 
	"mov byte [esp+0x150],bl \n " 
	"call 0x009075D0 -0x006FF3D1\n " 
	"mov ecx, dword ptr [esp+0x7C] \n " 
	"nop  \n " 
	"nop  \n " 
	"push 0x3 \n " 
	"push 0xE2F868 \n " //s_Off
	"push ecx \n " 
	"push edi \n " 
	"lea ecx, [esp+0x78] \n " 
	"call 0x0040A880 -0x006FF3D1\n " 
	"test eax,eax \n " 
	"je TimerIsOff \n " 
	"jmp  0x006FF47D -0x006FF3D1 \n " //_EndTimerValidation
	"TimerIsOff: \n " 
	"mov dword ptr [ebp+0x1CC],0x0 \n " 
	"jmp  0x006FF47D - 0x006FF3D1 \n " //_EndTimerValidation
	"nop\n"
	"nop\n"
	".align 128, 0x0 \n"
);
