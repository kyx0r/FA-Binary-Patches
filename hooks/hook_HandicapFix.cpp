//HOOK SetCommandSource ROffset = 0x00E8B4AA

__asm__ volatile
(   //0128B4AA SetCommandSource
    "MOV EAX,[10A63F0] \n"
    "MOV EAX,[EAX+910] \n"
    "MOV ECX,[ESP+8] \n"
    "MOV EAX,[ECX*4+EAX] \n"
    "MOV ECX,[ESP+0C] \n"
    "MOV EDX,ECX \n"
    "SHR EDX,5 \n"
    "SUB EDX,[EAX+130] \n"
    "MOV EBX,[EAX+138] \n"
    "LEA EBX,[EDX*4+EBX] \n"
    "CMP EBX,[EAX+13C] \n"
    "JB SHORT 0128B4E9 \n"
    "MOV DWORD PTR [EBX],0 \n"
    "ADD DWORD PTR [EAX+13C],4 \n"
    "AND CL,1F \n"
    "MOV EDX,1 \n"
    "SHL EDX,CL \n"
    "MOV EAX,1 \n"
    "CMP DWORD PTR [ESP+10],1 \n"
    "JL SHORT 0128B502 \n"
    "OR [EBX],EDX \n"
    "RET \n"
    "NOT EDX \n"
    "AND [EBX],EDX \n"
    "RET \n"
    ".align 128, 0x0 \n"
);


