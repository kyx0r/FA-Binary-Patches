void SelectUnit()
{
    const char* sCQUEMOV = "CQUEMOV";
    __asm__
    (
        "PUSH DWORD PTR SS:%[sCQUEMOV] \n"
        "LEA ECX,SS:[ESP+0x50] \n"
        "CALL 0x00405550 \n"
        "MOV DWORD PTR SS:[ESP+0x70],1 \n"
        "OR EBX,00000002 \n"
        "LEA EAX,SS:[ESP+0x4C] \n"
        "MOV ECX,ESI \n"
        "MOV SS:[ESP+0x10],EBX \n"
        "CALL 0x008B97C0 \n"
        "TEST AL,AL \n"
        "JNZ 0x008C062A \n"
        "PUSH 0x00E19824 \n"
        "LEA ECX,SS:[ESP+0x50] \n"
        "JMP 0x008C0603 \n"
        :
        : [sCQUEMOV] "i" (sCQUEMOV)
        :
    );
}