
void SimSetFocusArmy()
{
	__asm__
    (
        "PUSH 0x1 \n"
        "PUSH ESI \n"
        "CALL 0x0128B20C \n"     // lua_ToInt
        "ADD ESP,0x8 \n"
        "MOV ECX,[0x10C4F50] \n" // g_STIDriver
        "MOV [ECX+0x0B0],EAX \n" // simFocusArmyIndex
        "MOV EAX,0x1 \n"
        "RET \n"
    );
}