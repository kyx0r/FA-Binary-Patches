#include <stdlib.h>

char LOWSELECTPRIO[] = "LOWSELECTPRIO";
char buf[48];

void selectionPriority()
{
	__asm__
    (
        "call edx \n "
        "cmp byte ptr [ebx-0xD8],0x1 \n "
        "je label1 \n "	
        "label2: \n"
        "mov eax,dword ptr [eax+0x1FC] \n "
        "jmp 0x00863C19 \n "
        "label1: \n"
        "push eax \n "
        "push ecx \n "
        "push edx \n "
        "push %[LOWSELECTPRIO] \n " 
        "mov ecx, %[buf] \n"
        "call 0x00405550 \n "
        "mov eax, %[buf] \n"
        "lea ecx,dword ptr [ebx-0x148] \n"
        "call 0x008B97C0 \n "
        "test al, al \n"
        "pop edx \n"
        "pop ecx \n"
        "pop eax \n"
        "je label2 \n "
        "mov eax, 0x6 \n"
        "jmp 0x00863C19 \n "
        :
        : [LOWSELECTPRIO] "i" (LOWSELECTPRIO), [buf] "i" (buf)
        :
    );
}


/* This patch changes the drag selection code so unfinished units 
with "LOWSELECTPRIO" category get lowest priority - 6.

Before patch:
    selectionPriority = unitBlueprint.General.SelectionPriority
    
After:
    if (unit::IsBeingBuilt() && unit::IsInCatgory("LOWSELECTPRIO")) {
        selectionPriority = 6
    } else {
        selectionPriority = unitBP.General.SelectionPriority
    }     
*/
    