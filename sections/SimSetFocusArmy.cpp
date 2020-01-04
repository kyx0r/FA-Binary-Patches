void SimSetFocusArmy()
{
    __asm__
    (
        "MOV EAX,[ESI+0xC] \n"
        "CVTTSS2SI EAX,[EAX+0x4] \n" // ArmyIndex
        "MOV ECX,[0x10C4F50] \n"     // g_STIDriver
        "MOV [ECX+0x0B0],EAX \n"
        "XOR EAX,EAX \n"             // Num return values
    );
}