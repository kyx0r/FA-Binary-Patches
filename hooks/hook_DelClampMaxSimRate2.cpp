//HOOK DelClampMaxSimRate ROffset = 0x0048D1FE

__asm__ volatile
(   //0088D1FE WLD_IncreaseSimRate
    "CMP EAX,0x32 \n"
    ".align 128,0x0 \n"
);