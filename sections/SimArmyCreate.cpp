void SimArmyCreate()
{
    __asm__
    (
        "SUB ECX,ESI\n"
        "PUSH ECX \n"
        "PUSH EAX \n"
        "PUSHAD \n"
        "MOV ESI,0 \n"
        "MOV EBX,0 \n"
    "L1: PUSH EAX \n"
        "MOV EAX,0x0A \n"
        "MUL BX \n"
        "MOV EBX,EAX \n"
        "POP EAX \n"
        "MOV EDX,DS:[ESI+EAX] \n"
        "SUB EDX,0x30 \n"
        "ADD BL,DL \n"
        "INC ESI \n"
        "LOOP SHORT L1 \n"
        "MOV EAX,0x258 \n"
        "MUL BX \n"
        "MOV SS:[EBP+0x1CC],EAX \n"
        "POPAD \n"
        "LEA ECX,SS:[ESP+0x70] \n"
        "JMP 0x006FF3D6 \n"
    );
}