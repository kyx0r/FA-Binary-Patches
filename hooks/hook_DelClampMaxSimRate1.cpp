//HOOK DelClampMaxSimRate ROffset = 0x0015AE56

__asm__ volatile
(   //0055AE56 CalcMaxSimRate
    "MOV ESP,EBP \n"
    "POP EBP \n"
    "RET \n"
    "NOP \n"
    ".align 128,0x0 \n"
);