#include <stdlib.h>

char SalemWaterOnlyBp[1536];
char SalemDefaultBp[4];

void luaSimGetStat()
{
	__asm__
	(
        "cmp byte ptr [eax], 0x68 \n"
        "jne EXIT \n "
        "cmp byte ptr [eax+0x1], 0x31 \n "
        "jne EXIT \n "
        "push eax \n"
        "push ebx \n"
        "mov eax, %[SalemWaterOnlyBp] \n"
        "cmp byte ptr [eax], 0x0 \n"
        "jne dummyExists \n "
        "push ebx \n"
        "push ecx \n"
        "push edx \n"
        "mov ebx, dword ptr [ebx+0x74] \n"
        "mov %[SalemDefaultBp], ebx \n "
        "mov eax, ebx \n "
        "mov ebx, %[SalemWaterOnlyBp] \n "
        "mov edx, dword ptr [eax] \n "
        "mov [ebx], edx \n "
        "mov ecx, 0x4 \n"
        "MemCpyCycle: \n"
        "add ebx, 4 \n"
        "mov edx, dword ptr [eax+ecx] \n "
        "mov [ebx], edx \n "
        "add ecx, 4 \n"
        "cmp ecx, 1532 \n"
        "jbe MemCpyCycle \n "
        "mov dword ptr [ebx - 0x51C], 0x3fc00000 \n"  //MinWaterDepth = 1.5 
        "mov dword ptr [ebx - 0x522], 0x8 \n"         //OccupancyCaps = 8
        "pop edx \n"
        "pop ecx \n"
        "pop ebx \n"
        "dummyExists: \n"
        "cmp dword ptr [esp+0x20], 0x0 \n"
        "jne SetAmphON \n "
        "mov eax, dword ptr [ebx+0x74] \n "
        "cmp byte ptr [eax + 0xDA], 0x8 \n"
        "je POPEXIT \n"
        "mov eax, %[SalemWaterOnlyBp] \n"
        "mov dword ptr [ebx+0x74], eax \n"
        "jmp POPEXIT \n"
        "SetAmphON: \n"
        "mov eax, dword ptr [ebx+0x74] \n "
        "cmp byte ptr [eax + 0xDA], 0x9 \n"
        "je POPEXIT \n"
        "mov eax, %[SalemDefaultBp] \n"
        "mov dword ptr [ebx+0x74], eax \n"
        "POPEXIT: \n"
        "pop ebx \n"
        "pop eax \n"
        "EXIT: \n"
        "mov esi, eax \n"
        "add esp,0x8 \n "
        "test esi, esi \n "
        "jmp 0x006CC760 \n "
        :
        : [SalemWaterOnlyBp] "i" (SalemWaterOnlyBp), [SalemDefaultBp] "m" (SalemDefaultBp)
        :
	);
}

/* Lua sim function: unit:GetStat(char statName, int defValue)
unit:GetStat("h1_SetSalemAmph", 1)

if (statName.at(0) == "h") {
    if (statName.at(1) == "1") {

        if !SalemWaterOnlyBp {
            SalemWaterOnlyBp = defaultBP                            //handmade memcpy here :)
            SalemWaterOnlyBp.Footprint.MinWaterDepth = 1.5          //default 0
            SalemWaterOnlyBp.Footprint.OccupancyCaps = 8            //default 9  Only these 2 parameters do matter
        }

        if (defValue == 0){                                         //turn off amphibious
            if (unit.Blueprint.Footprint.OccupancyCaps != 8) {      
                unit.Blueprint = SalemWaterOnlyBp                      
            }
        } else {                                                    //turn on                                   
            if (unit.Blueprint.Footprint.OccupancyCaps != 9) {      
                unit.Blueprint = SalemDefaultBp
            }  
        }
    }
} */