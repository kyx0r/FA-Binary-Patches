void SessionIsReplay()
{
	__asm__
    (
        "MOV EAX,[0x10A6470] \n"
        "MOVZX EAX,byte ptr[EAX+0x484] \n"
        "PUSH EAX \n"
        "PUSH ESI \n"
        "CALL 0x0090CF80 \n"     // lua_pushbool
        "ADD ESP,0x8 \n"
        "MOV EAX,0x1 \n"
        "RET \n"
    );
}