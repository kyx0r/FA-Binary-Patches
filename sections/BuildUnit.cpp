void BuildUnit()
{
    const char* sCQUEMOV = "CQUEMOV";
    __asm__
    (
        "PUSH 0x00E19824 \n"
        "JMP SHORT L1 \n"
    "L2: PUSH DWORD PTR SS:%[sCQUEMOV] \n"
        "MOV EDX,SS:[ESP-0x80] \n"
        "MOV ECX,SS:[ESP] \n"
        "MOV EDX,SS:[EDX] \n"
        "MOV ECX,SS:[ECX] \n"
        "CMP EDX,ECX \n"
        "JE 0x006EFACE \n"
        "MOV SS:[ESP+0x20],EAX \n"
    "L1: LEA ECX,SS:[ESP+0x44] \n"
        "CALL 0x00405550 \n"
        "MOV BYTE PTR SS:[ESP+0x36C],1 \n"
        "MOV EBX,1 \n"
        "LEA ECX,DS:[EDI+8] \n"
        "LEA EAX,SS:[ESP+0x40] \n"
        "MOV SS:[ESP+0x18],EBX \n"
        "CALL 0x0067B050 \n"
        "TEST AL,AL \n"
        "JNE 0x006EFAF8 \n"
        "JMP SHORT L2 \n"
        :
        : [sCQUEMOV] "i" (sCQUEMOV)
        :
    );
}