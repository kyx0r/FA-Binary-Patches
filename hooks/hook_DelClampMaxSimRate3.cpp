//HOOK DelClampMaxSimRate ROffset = 0x0048E1A8

__asm__ volatile
(   //0088E1A8 WLD_GameSpeed
    "CMP ESI,0x32 \n"
    "MOV EDX,ESI \n"
    "JLE L1 \n"
    "MOV EDX,0x32 \n"
    "L1: \n"
    ".align 128,0x0 \n"
);