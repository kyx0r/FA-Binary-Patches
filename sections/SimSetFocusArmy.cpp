#include "include/moho.h"
#include "include/global.h"

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

luaFuncDescReg SSFARegDesc = {0x00E45E90,      // Std register func
                              0x00E43408,      // "SetFocusArmy"
                              0x00E00D90,      // "<global>"
                              0x00E451FC,      // "SetFocusArmy(armyIndex or -1)"
                              0x010B8AE8,      // Prev reg desc: ArmyGetHandicap
                              SimSetFocusArmy, // Func ptr
                              0x00000000};     // C++ class vtable ptr
