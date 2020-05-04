#pragma once

// GetClassNamePtr -> [[[Self]-4]+C]+8
// GetParentClassNamePtr -> [[[[Self]-4]+28]]+8

// Globals
const int g_STIDriver = 0x10C4F50;
const int g_SWldSessionInfo = 0x10C4F58;
const int g_CWldSession = 0x10A6470;
const int g_Sim = 0x10A63F0;
const int g_EntityCategoryTypeInfo = 0x10C6E70;
const int g_CAiBrainTypeInfo = 0x10C6FA0;
const int g_CUIManager = 0x10A6450;

const int ui_SelectTolerance = 0x0F57A90;
const int ui_ExtractSnapTolerance = 0x0F57A94;
const int ui_DisableCursorFixing = 0x10A6464;
const int ui_RenderIcons = 0x00F57B27;
const int range_RenderSelected = 0x010A640A;
const int range_RenderHighlighted = 0x010A640B;
const int range_RenderBuild = 0x010A6414;

// String const
const int s_FACTORY = 0xE19824;
const int s_EXPERIMENTAL = 0xE204B8;
const int s_global = 0xE00D90; // "<global>"

// Int const

//Adress const
const int _CannotQueCommandInConstruct = 0x006EFB0E;
const int _CanQueCommandInConstruct = 0x006EFAF8;
const int _NeitherInCategoryInConstruct = 0x006EFACE;
const int _EndCalculateNoRushTimerVariable = 0x006FF3D6;

// c Symbols

const int _CheckCategory = 	0x00405550;
const int _CheckCategory_sub_func = 0x004059E0;
const int _GetCatCmpResult = 0x0067B050;
const int _exit_STAYONWATSUR_check = 0x0062ADEE;
const int _exit_STAYONWATSUR_NoMatch = 0x0062ADEC;
const int _Moho_SSTICommandIssueData_SSTICommandIssueData = 0x00552550;

//extern functions:
//MSVCR80.dll
const int _memmove_s = 0x00A824E7;

//LuaPlus
/*
Use Tables example:
CreateTable
  CreateTable
    PushNumber
    PushNumber
    PushNumber
    PushStack
    PushTable
  LuaObjectFinalize
  PushStack
LuaObjectFinalize

// Table self -> ecx

004D3250 DoFile(out Table*, LuaState*, char* filename):eax
00908F60 GetVar(Table* ecx, out LuaObject*, char* key):eax

00907FF0 PushNumber(Table* ecx, value)

00907FA0 PushNil(Table* ecx, char* key)
009080C0 PushBoolean(Table* ecx, char* key, value)
009081F0 PushInteger(Table* ecx, char* key, value)
00908320 PushNumber(Table* ecx, char* key, value)
00908450 PushString(Table* ecx, char* key, value)
00908630 PushLightUserData(Table* ecx, char* key, value)
00907D80 PushStack(Table* ecx, lua_State*, LuaState*)
00908760 PushTable(Table* ecx, char* key, value)

00908240 PushInteger(Table* ecx, int key, value)
00908370 PushNumber(Table* ecx, int key, value)
009087A0 PushTable(Table* ecx, int key, value)

009074B0 PushValue(Table* ecx, char* Name, lua_var* Value)
00907630 PushCFunction(Table* ecx, char* name, void* ptr, int numArgs = 0)

00929450 SetValue(lua_State*, lua_var* table, lua_var* key, lua_var* value)
004154B0 use as number, string, integer(Arg1)
004579D0 LUA GetVarByName(Arg1,Arg2):eax ?
00908F60 GetLUAVarByName(lua_State* ecx, char* name, ?):edx ?
004CFFC0 PushFloat3(LuaState* ecx, out table*, float3*)

// LuaState self -> ecx

00909940 CreateTable(out LuaObject* ecx, LuaState*, numArr, numRec)

00908890 PushObject(out LuaObject* ecx, LuaState*)
009088E0 PushVar(out LuaObject* ecx, LuaState*, lua_var*)

009089F0 PushVar(out LuaObject* ecx, LuaState*, lua_var*):eax

// LuaObject self -> ecx

009072F0 IsNil(LuaObject* ecx):eax
00907310 IsTable(LuaObject* ecx):al
00907320 IsUserDataOrLight(LuaObject* ecx):eax
00907340 IsCFunction(LuaObject* ecx):al
00907350 IsInteger(LuaObject* ecx):al
00907360 IsNumber(LuaObject* ecx):al
00907370 IsString(LuaObject* ecx):al

00907380 GetInteger(LuaObject* ecx):eax
009073B0 GetNumber(LuaObject* ecx):ST0
009073E0 GetString(LuaObject* ecx):eax
00907410 GetStringLen(LuaObject* ecx):eax

00907910 GetAsInteger(LuaObject* ecx):eax
00907970 GetAsNumber(LuaObject* ecx):ST0
009079D0 GetAsNumber(LuaObject* ecx):ST0
00907A30 GetAsNumber(LuaObject* ecx):ST0
00907A90 GetAsString(LuaObject* ecx):eax
00907AF0 GetAsStringLen(LuaObject* ecx):eax
00907B50 GetAsCFunction(LuaObject* ecx):eax
00907BC0 GetAsUserData(LuaObject* ecx, out Result*):eax
00907C30 GetAsLightUserData(LuaObject* ecx):eax
00907C90 GetAsBoolean(LuaObject* ecx):eax

00907510 SetInteger(LuaObject* ecx, value)
009075D0 LuaObjectFinalize(LuaObject* ecx)

009076D0 GetType(LuaObject* ecx):eax
00907850 IsNone(LuaObject* ecx):al
00907440 IsNil(LuaObject* ecx):eax
009078D0 IsBoolean(LuaObject* ecx):al
00907890 IsLightUserData(LuaObject* ecx):al
00907700 IsNumber(LuaObject* ecx):eax
00907760 IsNumber(LuaObject* ecx):eax
009077C0 IsNumberOrString(LuaObject* ecx):eax
00907810 IsFunction(LuaObject* ecx):al

// lua_State

009240A0 GetLuaState(lua_State*):eax
0090A510 GetLuaState+1

0090C590 GetNumArgs(lua_state*):eax          // lua_gettop
0090C9F0 GetNumber(lua_State*, index):ST0    // lua_tonumber
0090CA40 GetBoolean(lua_State*, index):eax   // lua_toboolean
0090CA90 GetString(lua_State*, index):eax    // lua_tostring
0090CB10 GetStringLen(lua_State*, index):eax
0090CB70 GetCFunction(lua_State*, index):eax
0090CC90 GetValue(lua_State*, index):eax

0090CD00 PushNil(lua_State*)
0090CD40 PushNumber(lua_State*, value)       // lua_pushnumber
0090CF80 PushBool(lua_State*, value)         // lua_pushbool
0090CDF0 PushString(lua_State*, char* value)
0090CD80 PushString(lua_State*, char* str, strLen)
0090CFC0 PushLightUserData(lua_State*, value)

00924050 GetGlobalUserData(lua_State*):eax
00924060 SetGlobalUserData(lua_State*, value)

0090C5A0 MoveTop(lua_state*, int Offset)
00913990 PushNewArgs(lua_State*, numArgs)
00914E90 AllocCFunction(lua_State*, int numArgs)
0091A240 StackAllocate(lua_State*, lua_var* stack opt, int stackSize opt, int newSize):eax
009248E0 CreateStr(lua_State*, char* str, strLen):eax
00924860 CreateStr(lua_State* ebx, hash eax, char* str, strLen):eax
00927320 AllocTable(lua_State*, numArr, numRec):eax

// Other

00937C30 SpewF(char* str, args...)
00937CB0 LogF(char* str, args...)
00937D30 WarningF(char* str, args...)
0041C990 ConsoleLogF(char* str, args...)

00958B20 AllocMemory(Size):eax
00957A70 AllocMemory+1
00A825B9 AllocMemory2(Size):eax
00958C40 FreeMemory(Ptr)
00957AF0 FreeMemory+1
00957A60 FreeMemory+2
00A82542 FreeMemory+3

00AA549E StrCmp(char* str1, char* str2)
00A89190 CopyMem(void* dest, void* src, len)
006E5660 Moho_SetSetSize(moho_set* ecx, setSize)
004036A0 Moho_SetAdd(moho_set* edi, setSize esi, out 0xC)
009072A0 NullifyBytes16(ecx)
00A89CC0 FloatToInt(value):eax
004035F0 IsValidCommandSource
00408450 CompareStrings(char* str1, char* str2, strLen1):eax -1,0,1
0040A880 CompareStrings2(char* str1, strLen1, char* str2, strLen2) ?
0041CC90 SimConExecute
004CD3A0 Register LUA function
00528460 RRuleGameRulesAlloc(Arg1,Arg2)
00529120 RRuleGameRulesInit(Arg1,Arg2,Arg3)
00529510 DestroyRRuleGameRules
00546650 FindRes(CSimResources* ecx, Type, Rect*):Bool
00546760 FindRes(CSimResources* ecx, PtrPosXY, PtrResultXY, Radius, Type):Bool
00581AA0 OnInit(Arg1)
005BD630 Internal IsAlly
005D5540 Internal IsEnemy
00707BF0 Internal IsNeutral
006FE530 SimArmyAlloc(Arg1,Arg2,Arg3,Arg4,Arg5,Arg6)
006FE690 SimArmyCreate(Arg1,Arg2,Arg3,Arg4,Arg5,Arg6)
006FE670 DestroySimArmy
005930D0 GetBrain(Table* eax):eax
00707D60 GetSimArmy
0073B1B0 SetArmyIndex(CSimDriver* ecx, value)
0073F4E0 CSimDriverAlloc(Arg1,Arg2,Arg3,Arg4)
0073B570 CSimDriverInit(Arg1,Arg2,Arg3)
007433B0 SimAlloc
007434D0 SimCreate(Arg1,Arg2)
00744060 SimSetup(Arg1,Arg2)
007458E0 SimFinalize(Sim*)
00747180 IsCheating!
007A4970 OnMouseMove
008704B0 OnMouseMoveOverMap
0086E480 CUIWorldViewInit(Arg1,Arg2,Arg3,Arg4,Arg5,Arg6,Arg7)
00885DE0 WorldSessionLoad(Arg1)
0088C000 DoLoading
00897220 CWldSessionAlloc
00893160 CWldSessionCreate(Arg1,Arg2,Arg3)
008965E0 Internal SetFocusArmy
00896670 Test Set focus access rights
008C0500 SelectUnit
008CEDE0 AppInit
008D4010 SC_CreateEntityDialog
0055AE10 CalcMaxSimRate
0053E590 SetSimRate
0053E720 GetSimRate
0053E7E0 GetSimRateRequested
007EF9B0 RenderRing
008F3C40 D3DXEffect::GetPassCount ?
008F4080 D3DXEffect::BeginPass ?
008F4260 D3DXEffect::EndPass ?
00941D70 D3DXEffect::SetMatrix ?
00941F60 D3DXEffect::SetTechnique
0053E180 CreateCLocalClient
0053BD40 InitCClientBase
0053FAF0 CreateCClientManager
0053DF20 InitCClientManager
0053E400 CreateCReplayClient
0053BA50 InitCReplayClient
00956DB0 InitStream
009565D0 InitPipeStream
00955BD0 InitFileStream
00955870 DestroyFileStream
0048BBE0 CreateCNetUDPConnetor
004896F0 InitCNetUDPConnetor
004899E0 DestroyCNetUDPConnetor
007AA9C0 CreateCamera
007A7950 InitCamera
007A7DC0 DestroyCamera
00894530 UserSync
008B1520 InitUserArmy
008B85E0 InitUserEntity
008BF420 InitUserUnit
008B8760 DestroyUserEntity
008BF990 DestroyUserUnit
004C7010 InitRObjectAndCScriptObject
00677C90 InitEntity
007489E0 CreateUnit
006A53F0 InitUnit
006A5320 DestroyUnit
006A0FB0 CreateProjectile
0069AFE0 InitProjectile
006FB3B0 CreateProp
006F9D90 InitProp
0050DD60 InitRBlueprint
00511C30 InitREntityBlueprint
00532680 CreateRMeshBlueprint
005283A0 InitRMeshBlueprint
00531D80 CreateRUnitBlueprint
0051E480 InitRUnitBlueprint
00532080 CreateRPropBlueprint
0051D250 InitRPropBlueprint
00532380 CreateRProjectileBlueprint
0051B740 InitRProjectileBlueprint
005289D0 RegisterBlueprint(RRuleGameRules*, char* Category)
00577890 InitSTIMap
005790E0 CreateCHeightField
0044FB90 GetTerrainHeight(float x, float z):int ecx
0074B120 FlattenTerrain(STIMap*, int Rect*, float Height)
00476BB0 UpdateMinimap(MapData*, int x1, int y1, int x2, int y2)
00890DA0 MapLoad
0057CBB0 CanBuildStructureAt(CAiBrain*, x, y, z, Blueprint*, ?, ?, ?):al
006856C0 SimFindEntityChainById(ecx* entities, ebx* id, eax* result)
00898DC0 UserFindEntityChainById(ecx* entities, ebx* id, eax* result)
*/
const int _Logf = 0x937CB0;
const int LuaState__CastState = 0x90A510; // LuaState* (lua_state*)
const int _LuaState__Error = 0x90C1D0; // (LuaState*, fmt, args...)
const int _CastState_LuaState_LuaPlus__SAPAV12_PAUlua_State___Z = 0x90A510;
const int __0LuaObject_LuaPlus__QAE_ABVLuaStackObject_1__Z = 0x908A70;
const int __1LuaObject_LuaPlus__QAE_XZ = 0x9075D0;

const int LuaStackObject__GetBoolean = 0x415560;

const int _AssignClientIndex_CLobby_Moho__AAEXHVStrArg_gpg__AAIAAH_Z = 0x7C4E80;
const int _AssignCommandSource_CLobby_vector_allocator_USSTICommandSource = 0x7C4F60;

const int lua_cast_CLobby_ = 0x7CB7E0;

const int Moho__NET_MakeNATTraversal_ = 0x7BC5F0; //(LuaObject* rvo, LuaState*)
const int _Eval_Lua_Object = 0x6EEE40;

// Utils
const int __imp_atoi = 0xA835CE;

const int __ftol2_sse = 0xA89CC0;

const int __stricmp = 0xAA549E; //int (const char*, const char*)

const int _Validate_IssueCommand = 0x006EECF0;
const int _j_shi_delete_0 = 0x00A82542;
const int _j_shi_new_0 = 0x00A82130;
const int _Get_Lua_Coordinates_State = 0x006EEF60;
const int _Push_Coordinates = 0x005E27D0;
const int _Moho_UNIT_IssueCommand = 0x006F12C0;
const int _Moho_SSTICommandIssueData_Destructor_SSTICommandIssueData = 0x0057ABB0;