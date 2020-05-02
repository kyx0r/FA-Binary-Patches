//MohoEngine.dll Disassembling notes

#pragma once
typedef unsigned int uint;

struct luaFuncDescReg
{
	void** RegisterFunc; // call for register lua function
	char* FuncName; // lua name function
	char* ClassName; // lua class name. <global> if class none
	char* FuncDesc; // for log
	luaFuncDescReg* PrevStruct; // reg calls the chain
	void* FuncPtr; // code address
	void* ClassPtr; // C++ class type address. NULL if class none
};

struct string
{       // 0x1c bytes
	void* ptr1;
	char str[0x10]; // DataPtr or used as memory for 'Short Set Optimization'
	uint strLen;
	uint size; // 0f if SSO, 1f not SSO

#ifdef CXX_BUILD
	const char* data()
	{
		if(size < 0x10)
			return (const char*)&m_data;
		else
			return (const char*)m_data;
	}
#endif
};

struct vector
{
	char pad[4];
	void** objects_begin;
	void** objects_end;
	void** objects_capacity_end;

#ifdef CXX_BUILD
	void* operator[](int index)
	{
		if(index >= size())
			return 0;
		return objects_begin[index];
	}

	int size()
	{
		return objects_end - objects_begin;
	}
#endif
};

struct list // probably not from visual c++, but made by gpg
// considering, it's not capacity based, probably made by gpg
{       // 0x0C bytes
	void* objects_start; // 0 if empty
	void* objects_end;
	void* objects_capacity_end;
};

typedef int SOCKET;
// GPGCore

struct Vector2f
{	// 0x8 bytes
	float x,z;
};

struct Vector3f
{	// 0xC bytes
	float x,y,z;
};

struct Vector4f
{	// 0x10 bytes
	float x,y,z,w;
};

struct RObject
{	// ~0x10 bytes
	void* vtable;
};

struct CScriptObject // : RObject
{	// ~0x34 bytes
};

struct WeakObject
{
	void* vtable;
};

struct gpg_mutex
{
	int unknown1;
	bool unknown2; // if value is 0 then NTDLL.RtlEnterCriticalSection is bypassed
};

struct Stream
{	// 0x1C bytes
	void* vtable;
};

struct PipeStream // : Stream
{	// 0x48 bytes
};

struct FileStream // : Stream
{	// 0x34 bytes
};

//LuaPlus
struct lua_var
{	// 0x8 bytes
	int type;
	void* value;

	/* Types:
		-1 - None
		0 - Nil
		1 - Boolean
		2 - LightUserData || UserData
		3 - Number || Integer
		4 - String
		5 - Table
		6 - CFunction
		7 - Function
		8 - UserData
		9 - NumTags?
	*/
};

struct lua_State // www.lua.org/source/5.0/lstate.h.html#lua_State
{
	void* unknown1;
	void* unknown2;
	lua_var* objects_end;
	lua_var* objects_start; // 1 based index
	void* global_State;     // ?
	void* callInfo;         // ?
	lua_var* stack_last;
	lua_var* stack;
	int stacksize;          // numVars
	// at 0x44
	void* LuaState;         // ?
};
struct LuaObject;
struct LuaState
{	// 0x28 bytes ?
	lua_State* lua_State;
	void* unknown1;
	void* unknown2;
	void* unknown3;
	void* important1;
	// at 0x20
	LuaState* self;
	LuaObject* prev;
};
struct LuaStackObject
{	// 0x8 bytes
	LuaState* state;
	int stack_index;
};
struct LuaObject
{	// 0x14 bytes
	LuaObject* prev;
	LuaObject* next;
	LuaState* m_state;
	lua_var value;
};

// Moho
struct Moho__SSTICommandIssueData
{
};

struct Camera // : RCamCamera
{	// 0x858 bytes
};

struct CMauiControl // : CScriptObject
{
};

struct CUIWorldView // : CMauiControl
{	// 0x2A8 bytes
	// at 0x120
	Camera* Camera;
};

struct linked_list
{
};

struct moho_set
{       // 0x20 bytes
	int baseIndex; // integer_base >> 5 (bits in uint)
	int unknown2;
	uint* items_begin;
	uint* items_end;
	uint* items_capacity_end;
	void* unknown6;
	uint value; // Used as memory for 'Short Set Optimization'
	void* unknown8;

#ifdef CXX_BUILD
	void add(int item)
	{
		uint* itemPtr = &items_begin[item >> 5];
		if (itemPtr >= items_end)
			items_end = itemPtr + 1;
		*itemPtr |= 1 << (item & 0x1f);
	}

	void remove(int item)
	{
		items_begin[item>>5]  &= ~( 1 << (item & 0x1f) );
	}

	bool operator[](int item)
	{
		return items_begin[item>>5] & (1 << (item & 0x1f));
	}
#endif
};

struct RRuleGameRules
{	// 0xD0 bytes
	void* vtable;
	// at 0x2C
	//list L1;
	// at 0x48
	//list L2;
	// at 0xB8
	list Blueprints; // <RBlueprint*>
	//list L3;
	// at 0xC4
	//void* Blueprints;
	//void* Start, End;
};

struct LaunchInfoNew
{	// 0xA4 bytes
	void* vtable;

	RRuleGameRules* rules;
	void* STIMap;

	// at 0xC
	string lua_gameMods;
	// at 0x28
	string str2;

	// at 0x60
	int unknown1;
	int unknown2;
	int unknown3; // = -1
	// at 0x6C
	string str3;
	// at 0x88
	bool boolean1;
	char _pad1[3];
	int unknown4;
};

struct REffectBlueprint // : RObject
{
};

struct RBeamBlueprint // : REffectBlueprint
{	// 0x140 bytes
};

struct RBlueprint // : RObject
{	// ~0x60 bytes
	// at 0x4
	RRuleGameRules* owner;
	string name;
};

struct RMeshBlueprint // : RBlueprint
{	// 0x80 bytes
};

struct REntityBlueprint // : RBlueprint
{	// ~0x17C bytes
	// at 0x64
	list Categories; // <string>
};

struct RPropBlueprint // : REntityBlueprint
{	// 0x1AC bytes
};

struct RProjectileBlueprint // : REntityBlueprint
{	// 0x268 bytes
};

struct RUnitBlueprint // : REntityBlueprint
{	// 0x568 bytes
	// at 0x43C
	string ArmorType;
	// at 0x564
	float MaxBuildDistance;
};

struct IClientManager
{
	void* vtable;
};

struct CWldMap
{
	void* zero1;
	void* zero2;
	void* zero3;
};

struct Deposit
{	// 0x14 bytes
	int X1,Z1,X2,Z2; // Rect
	int Type; // 1 - Mass, 2 - Energy
};

struct CSimResources // : ISimResources // : IResources
{	// 0x1C bytes
	void* vtable;
	// at 0x8 in vtable
	// ecx:CreateResourceDeposit(type, x, y, z, size)
	// at 0x28 in vtable
	// ecx:FindResourceDeposit(PtrPosXZ, PtrResultXZ, Radius, Type):Bool

	// at 0x10
	list Deposits; // <Deposit*>
};

struct SWldSessionInfo
{	// 0x30 bytes
	string map_name;

	// at 0x1C
	void* LaunchInfoNew;

	// at 0x20
	int unknown2;
	bool isBeingRecorded;
	bool isReplay;
	bool isMultiplayer;
	char _pad1;
	// at 0x2C
	int ourCmdSource;

	IClientManager* clientManager;
	int unknown4; // = 255 possibly cmdSourceIndex
};

struct SimArmyEconomyInfo
{	// 0x60 bytes
	void* unknown1;
	int unknown2;
	float _incomeEnergy;    // div 10
	float _incomeMass;      // div 10

	float baseIncomeEnergy; // div 10
	float baseIncomeMass;   // div 10
	float storedEnergy;
	float storedMass;

	float incomeEnergy;     // div 10
	float incomeMass;       // div 10
	float reclaimedEnergy;
	float reclaimedMass;

	float requestedMass;    // div 10
	float requestedEnergy;  // div 10
	float lossMass;         // div 10
	float lossEnergy;       // div 10

	uint maxEnergy;
	int unknown3;
	uint maxMass;
	int unknown4;

	float unknown5;
	uint isResourceSharing;
	float unknown6;
	float unknown7;
};

struct UserArmy
{	// 0x210 bytes
	void* unknown1;

	string name;

	// at 0x20
	string nickname;
	// at 0x3C
	bool isCivilian;
	// at 0x80
	float storedEnergy;
	float storedMass;

	float incomeEnergy;     // div 10
	float incomeMass;       // div 10
	float reclaimedEnergy;
	float reclaimedMass;

	float requestedMass;    // div 10
	float requestedEnergy;  // div 10
	float lossMass;         // div 10
	float lossEnergy;       // div 10

	uint maxEnergy;
	int unknown3; // =0
	uint maxMass;
	int unknown4; // =0
	bool isResourceSharing;
#ifndef FORGED_ALLIANCE
	char datas[0xba];
#else
	char datas[0xb2];
#endif
	// at 0x130 Moho | at 0x128 FA
	moho_set mValidCommandSources;
	// at 0x148 FA
	uint color;
	uint iconColor;
	string mArmyType; // 'human' for players
	// at 0x16C FA
	int faction;
	// at 0x188 FA
	bool showScore;
	// at 0x1B8 FA
	bool outOfGame;
};

struct SimArmy // : IArmy
{	// 0x288 bytes
#ifdef FORGED_ALLIANCE
	void* vtable;
	// at 0xA4 in vtable
	//void* GetUnitCap;
	//void* SetUnitCap;

	string name;
	string nickname;

	// at 0x44
	bool isCivilian;
	// at 0x88 Copy from [[self+1F4]+18]
	float storedEnergy;
	float storedMass;

	float incomeEnergy;     // div 10
	float incomeMass;       // div 10
	float reclaimedEnergy;
	float reclaimedMass;

	float requestedMass;    // div 10
	float requestedEnergy;  // div 10
	float lossMass;         // div 10
	float lossEnergy;       // div 10

	uint maxEnergy;
	int unknown3; // =0
	uint maxMass;
	int unknown4; // =0
	bool isResourceSharing;
	// at 0xC8
	moho_set neutrals;
	moho_set allies;
	moho_set enemies;

	char datas[0x52];
	// at 0x130 FA
	moho_set mValidCommandSources;

	// at 0x150 FA
	uint color;
	uint iconColor;
	string mArmyType; // 'human' for players
	// at 0x174 FA
	int faction;
	// at 0x1C0 FA
	bool outOfGame;
	// at 0x1C4 FA
	Vector2f StartPosition;
	// at 0x1D0
	float noRushRadius;
	float noRushOffsetX;
	float noRushOffsetY;

	// at 0x1E8
	void* Sim;
	void* CAiBrain;

	// at 0x1F0 FA
	void* CAiReconDBImpl;
	SimArmyEconomyInfo* EconomyInfo;
	// at 0x1F8 FA
	string unknown5;
	// at 0x270
	float unitCap;
	// at 0x278
	int pathCap_Land;
	int pathCap_Sea;
	int pathCap_Both;
#else
	// at 0x138 Moho
	moho_set mValidCommandSources;
#endif
};

struct CArmyImpl // : SimArmy
{
};

struct Entities
{	// 0x50 bytes
};

struct EntityChain // [[Entities+4]+4]
{
	void* Next;
	//void* ?;
	//void* ?;
	int ID;
	void* Entity;
};

struct Entity // : CScriptObject
{	// ~0x270 bytes
};

struct Projectile // : Entity
{	// 0x380 bytes
	// at 0x6C
	RProjectileBlueprint* Blueprint;
};

struct Prop // : Entity
{	// 0x288 bytes
	// at 0x6C
	RPropBlueprint* Blueprint;
};

struct Unit // : IUnit
{	// 0x6A8 bytes
	// at 0x44
	int UnitID;
	// at 0x50
	void* self1;
	// at 0x74
	RUnitBlueprint* Blueprint;
	// at 0x98
	float CurHealth;
	float MaxHealth;
	// at 0xA4
	Vector4f Rot1;
	Vector3f Pos1;
	Vector4f Rot2;
	Vector4f Pos2;
	// at 0x158
	Vector4f Rot3;
	Vector3f Pos3;
	// at 0x17C
	int TickCount1; // Readonly
	// at 0x248
	Vector3f Pos4;
	Vector3f Pos5;
	// at 0x298
	float ShieldPercent; // Readonly
	// at 0x59C
	Vector3f Pos6;
	// at 0x668
	int TickCount2; // Readonly
};

struct UserEntity // : WeakObject
{	// 0x148 bytes
	// at 0x48
	RPropBlueprint* Blueprint;
	// at 0x74
	Vector4f Rot1;
	Vector4f Pos1;
	// at 0x90
	Vector4f Rot2;
	Vector4f Pos2;
	// at 0xD0
	//float x1,y1,x2,y2;
	// at 0x120
	UserArmy* Owner;
	Vector4f Rot3;
	Vector4f Pos3;
};

struct UserUnit // : UserEntity
{	// 0x3E8 bytes
	// at 0x48
	RUnitBlueprint* Blueprint;
};

struct Sim // : ICommandSink
{	// 0xAF8 bytes
	void* vtable;
#ifdef FORGED_ALLIANCE
	// at 0x8C0
	void* CEffectManager;   // 0x18 bytes
	void* CSimSoundManager; // 0x720 bytes
	RRuleGameRules* rules;  // from CSimDriver.LaunchInfoNew
	void* STIMap;           // from CSimDriver.LaunchInfoNew
	CSimResources* Deposits;
	// at 0x8D8
	void* LuaStack; // 0x34 bytes
	// at 0x904
	void* unknown1; // 0x9CC bytes
	void* unknown2; // 0x68 bytes
	// at 0x91C Moho | at 0x90C FA
	vector armies;// <class Moho::SimArmy *>
	// at 0x920
	list SSTICommandSources;
	// at 0x93C Moho | at 0x92C FA
	int ourCmdSource; // possibly just current in simulation.
	// at 0x97C
	void** unknown3; // 0x30 bytes
	void* CAiFormationDB; // 0x40 bytes
	// at 0x984
	void* Entities;
	void* unknown4; // 0xCD0 bytes
	// at 0x99C
	void* unknown5; // 0xCF0 bytes
	// at 0xA38
	void* unknown6; // 0xC bytes
#else
#endif
};
struct CWldSession
{	// 0x508 bytes
	CWldSession* self1;
	CWldSession* self2;

	void* self_weird1; // = this + 0x8
	void* self_weird2; // = this + 0x8

	// at 0x10
	LuaState* state; // sim? set from constructor argument
	void* unknown1; // 0x14 bytes
	RRuleGameRules* rules;
	CWldMap* map;
	void* LaunchInfoNew;
	void* unknown2; // .?AV?$sp_counted_impl_p@ULaunchInfoNew@Moho@@@detail@boost@@
	string map_name;
	Entities entities;

	char stuff[0x35c];

	// at 0x3F0
	list armies; // <UserArmy*>
	// at 0x3FC
	void* unknown3; // 0xCC0 bytes
	void* unknown4; // 0x64 bytes
	// at 0x424
	CSimResources* Deposits;
	// at 0x470
	vector cmdSources; // <SSTICommandSource>

	// at 0x480
	int ourCmdSource;

	bool isReplay;
	bool isBeingRecorded;
	bool isMultiplayer;
	bool allowObservers;

	int focusArmyIndex; // focused army, -1 = observer

	bool isGameOver;
	// at 0x4B4
	float mouseWorldPosX;
	float mouseWorldPosY;
	float mouseWorldPosZ;
	// at 0x4D4
	bool cheatsEnabled;
};

struct CSimDriver // : ISTIDriver
{	// 0x230 bytes
	void* vtable;
	Sim* sim;
	IClientManager* ClientManager;
	// at 0x10
	void* LaunchInfoNew; // from g_SWldSessionInfo, only when loading game init
	// at 0x1C
	uint beatCounter1;
	uint beatCounter2; // copied to address 0x1290710
	uint beatCounter3;
	// at 0xb0
	int simFocusArmyIndex;
	// at 0x228
	int maxSimRate; // from CalcMaxSimRate
};

struct CHeightField // : .?AVsp_counted_base@detail@boost@@
{	// 0x10 bytes
	void* vtable;
};

struct MapData
{	// 0x1C bytes
	uint* TerrainHeights; // Word(TerrainHeights+(Y*SizeX+X)*2)
	int SizeX; // +1
	int SizeY; // +1
};

struct STIMap
{	// 0x1548 bytes
	MapData* MapData;
	CHeightField* HeightField;
	// at 0x18
	//list Data; -> Data
	// at 0x28
	char Data[0x1400];
	char* TerrainTypes; // TerrainTypes+(Y*SizeX+X)
	int SizeX;
	int SizeY;
	// at 0x1534
	bool Water;
	// at 0x1538
	float WaterLevel;
};

struct SSTICommandSource
{       // 0x24 bytes
	int index;
	string name;
	int protocol; // -1 SinglePlayer, 3 MultiPlayer
};

struct CPushTask
{
	char datas[0x24];
};

typedef CPushTask CPullTask;

struct INetConnector
{
	void* vtable;
};
struct CLobby
{	// 0xC8 bytes

	// at 0x20
	LuaObject unknown0;

	int unknown1;
	int unknown2;
	int unknown3;
	int unknown4;
	// at 0x44
	CPushTask pushTask;

	// at 0x60
	CPullTask pullTask;

	// at 0x84
	bool hosted_or_joined; // Has CLobby been used to host/join yet?

	// at 0x88
	void* not_host; // 0 if we're host

	// at 0x90
	string our_name;
	// at 0xAC
	int our_UID;

	// at 0xB0
	struct
	{
		INetConnector* first_element;
		INetConnector* last_element; // It will probably always be our CNetXXXConnector
	} peer_list; // Probably singly-linked list
};

/// Tres Importante
struct sub_10392B10_ret
{	// 0x20 bytes

	void* zero1; // self in CLobbyPeer.unknown2
	void* zero2; // self in CLobbyPeer.unknown2
	void* zero3; // self in CLobbyPeer.unknown2
	int unknown1;

	// at 0x10
	char one1;
	char zero4; // 1 in CLobbyPeer.unknown2
};
struct CLobbyPeer
{	// 0x50 bytes

	CLobbyPeer* next; // Doubly linked list pointers
	CLobbyPeer* prev;

	string			  playerName;

	// at 0x24
	int ownerID; // User UID
	int constant1;
	short constant2;
	char _pad1[2];

	// at 0x30
	int constant3;	// enum?
	float constant4; // = 0
	int constant5;
	int unknown1;

	// at 0x40
	sub_10392B10_ret* unknown2; // made in sub_10394180
	int zero1;
	int cmdSourceIndex; // == 255 => Unassigned
	int playerNo;

	/*
		constant1, constant2, constant3, constant5
		specially define the CLobbyUser

		constant3:
		1 - Host for a lobby we joined?
		3 - Peer who connected to us?
		6 - Game Peer of a Launched Game?
	*/
};

struct CClientManagerImpl // : IClientManager
{	// 0x184D0 bytes
	void* vtable;

	// at 0x40C
	gpg_mutex mLock;

	// at 0x420
	list mClients; // <IClient*>
	INetConnector* mConnector;

	// at 0x434
	bool mWeAreReady;
	bool mEveryoneIsReady;
	char _pad1[2];
	int mDispatchedBeat;
	int mAvailableBeat;
	int mFullyQueuedBeat;
	int mPartiallyQueuedBeat;
	int gameSpeedChangeCounter; // mGameSpeedClock
	int mGameSpeedRequester;    // always 0
	int gameSpeedRequested;     // mGameSpeed
	bool speedControlEnabled;
	// at 0x458
	uint hEvent; // for KERNEL32.SetEvent
	// at 0x18470
	PipeStream mPipe;
	// at 0x184BC
	bool unknown; // if value is 1 then KERNEL32.SetEvent is bypassed
};

struct CClientBase // : IClient
{	// 0xD8 bytes
	void* vtable;
	string mNickname;
	// at 0x20
	int mIndex; // client index
	int mUID;
	IClientManager* clientManager;

	// at 0x30
	moho_set unknown1;
	// at 0x50
	int mCommandSource;
	bool mReady;
	char _pad1[3];
	PipeStream mPipe;

	// at 0xA0
	int mQueuedBeat;
	int mDispatchedBeat;
	int mAvailableBeatRemote;
	vector mLatestAckReceived; // <int>
	int mLatestBeatDispatchedRemote;
	// at 0xC0
	bool mEjectPending;
	bool mEjected;
	char _pad2[2];
	vector mEjectRequests; // <struct{IClient* mRequester; int mAfterBeat;}>
	int maxSimRate; // from CalcMaxSimRate
};

struct CLocalClient // : CClientBase
{	// 0xD8 bytes
};  // equal CClientBase

struct CReplayClient // : CClientBase
{	// 0x160 bytes
	// before 0xD8 it CClientBase
	// at 0xD8
	FileStream* stream;
	// at 0xE0
	void* ptr1; // self+0xF0
	void* ptr2; // self+0xF0
	void* ptr3; // self+0x130
	void* ptr4; // self+0xF0
	void* unknown1;
	// at 0x130
	void* unknown2;
	// at 0x138
	uint replayBeat;
	char unknown3;
	void* unknown4;
	uint hSemaphore1;
	uint hSemaphore2;
	uint hMutex;
	// at 0x15C
	char unknown5;
	char unknown6;
};

struct CNetUDPConnetor // : INetConnector
{	// 0x18090 bytes
	void* vtable;
	void* smth; // listen socket fd?
	gpg_mutex mMutex;
	// at 0x14
	SOCKET mSocket;
	// at 0x24
	linked_list mConnections; // <CNetUDPConnection*>
};
/** Game Types
  Multiplayer - CLobby::LaunchGame
  Replay - VCR_SetupReplaySession
  SinglePlayer - WLD_SetupSessionInfo
  Saved Game - CSavedGame::CreateSinglePlayerSession
*/

/** Session State
	0 - None?
	1 - Loading?
	2 - Started?
	3 - SIM Initialized
	4 - SIM Started
	5 - Game Started
	7 - Restart Requested
	8 - Session Halted
*/
