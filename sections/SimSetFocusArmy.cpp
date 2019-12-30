void SimSetFocusArmy()
{
    __asm__
    (
        "MOV EAX,[ESI+0xC] \n"
        "CVTTSS2SI EAX,[EAX+0x4] \n" // ArmyIndex
        "MOV ECX,[0x10C4F50] \n"     // g_STIDriver
        "MOV [ECX+0x0B0],EAX \n"
        "MOV EAX,0x1 \n"
    );
}