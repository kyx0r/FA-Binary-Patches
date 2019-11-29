//HOOK SetCommandSource ROffset = 0x00BDD4AA

__asm__ volatile
(   //0128B4AA SetCommandSource
    "MOV EAX,[0x10A63F0] \n"
    "MOV EAX,[EAX+0x910] \n"
    "MOV ECX,[ESP+0x8] \n"              // armyId
    "MOV EAX,[ECX*0x4+EAX] \n"
    "MOV ECX,[ESP+0x0C] \n"             // sourceId
    "MOV EDX,ECX \n"
    "SHR EDX,0x5 \n"
    "SUB EDX,[EAX+0x130] \n"
    "MOV EBX,[EAX+0x138] \n"
    "LEA EBX,[EDX*0x4+EBX] \n"
    "CMP EBX,[EAX+0x13C] \n"
    "JB L1 \n"
    "MOV DWORD PTR [EBX],0x0 \n"
    "ADD DWORD PTR [EAX+0x13C],0x4 \n"
    "L1: \n"
    "AND CL,0x1F \n"
    "MOV EDX,0x1 \n"
    "SHL EDX,CL \n"
    "MOV EAX,0x1 \n"
    "CMP DWORD PTR [ESP+0x10],0x1 \n"  // set_or_unset
    "JL L2 \n"
    "OR [EBX],EDX \n"
    "RET \n"
    "L2: \n"
    "NOT EDX \n"
    "AND [EBX],EDX \n"
    "RET \n"
    ".align 128, 0x0 \n"
);

/*
extern "C" int cxx_SetCommandSourceId(lua_state* lua, int armyId, int sourceId, bool set_or_unset)
{
	Sim* sim = g_Sim;
	SimArmy* army = (SimArmy*)sim->armies[armyId];

	if(set_or_unset)
		army->mValidCommandSources.add(sourceId);
	else
		army->mValidCommandSources.remove(sourceId);
	//lua_pushbool(lua, true);
	return 1;
}
*/
