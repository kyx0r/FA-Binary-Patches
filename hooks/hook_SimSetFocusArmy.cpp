//HOOK SetCommandSource ROffset = 0x00308A9A
#include "../preprocessor/define.h"
#include "../preprocessor/macro.h"
#include "../sections/include/moho.h"

luaFuncDescReg SSFARegDesc = {0x00E45E90,          // Std register func
                              0x00E43408,          // "SetFocusArmy"
                              0x00E00D90,          // "<global>"
                              0x00E451FC,          // "SetFocusArmy(armyIndex or -1)"
                              0x010B8AE8,          // Prev reg desc: ArmyGetHandicap
                              QU(SimSetFocusArmy), // Func ptr
                              0x00000000};         // C++ class vtable ptr
                              
__asm__ volatile
(   //00708A9A
    "MOV EAX, SSFARegDesc \n"
    ".align 128, 0x0 \n"
);
