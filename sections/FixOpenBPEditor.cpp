void FixCreateEntityDialog()
{
	__asm__
    (
        "MOV EAX,[0x10A6470] \n"
        "MOV AL,[EAX+0x4D4] \n"
        "CMP AL,1 \n"
        "JE L1 \n"
        "RET \n"
        "L1: \n"
        "PUSH EBP \n"
        "MOV EBP,ESP \n"
        "AND ESP,0xFFFFFFF8 \n"
        "JMP 0x008D4016 \n"
    );
}