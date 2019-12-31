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
	void* unknown1;
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

struct Stream
{

};

struct PipeStream // : Stream
{	// 0x48 bytes

};

struct gpg_mutex
{
	int vooodoo;
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
	int unknown;
};

struct Moho__CUnitCommand
{
	int unknown;
};

struct linked_list
{
	void* not_sure;
};
struct moho_set
{       // 0x20 bytes
	int baseIndex; // integer_base >> 5 (bits in dword)
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
struct CSimResources
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
struct SimArmy
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
	struct
	{
		float X;
		float Z;
	} StartPosition;
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

struct Sim
{	// 0xAF8 bytes
	void* vtable;
#ifdef FORGED_ALLIANCE
	// at 0x8C8
	RRuleGameRules* rules; // from STIDriver.LaunchInfoNew
	void* STIMap;          // from STIDriver.LaunchInfoNew
	CSimResources* Deposits;
	// at 0x904
	void* unknown1; // 0x9CC bytes
	// at 0x91C Moho | at 0x90C FA
	vector armies;// <class Moho::SimArmy *>
	// at 0x920
	list SSTICommandSources;
	// at 0x93C Moho | at 0x92C FA
	int ourCmdSource; // possibly just current in simulation.
	// at 0x984 FA
	void* thing;
#else
#endif
};
struct CWldSession
{	// 0x508 bytes
	// Information about values is from constructor.

	CWldSession* self1; // = this
	CWldSession* self2; // = this

	void* self_weird1; // = this + 0x8
	void* self_weird2; // = this + 0x8

	// at 0x10
	LuaState* state; // sim? set from constructor argument
	void* zero1;

	RRuleGameRules* rules;
	CWldMap* map;

	// at 0x20
	void* LaunchInfoNew;
	void* zero3; // .?AV?$sp_counted_impl_p@ULaunchInfoNew@Moho@@@detail@boost@@
	string map_name;

	char stuff[0x3ac];

	// at 0x3f0
	list armies; // <UserArmy*>
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
	// at 0x4b4
	float mouseWorldPosX;
	float mouseWorldPosY;
	float mouseWorldPosZ;
	// at 0x4d4
	bool cheatsEnabled;
};

struct STIDriver // : ISTIDriver
{	// 0x230 bytes
	void* vtable;
	// at 0x10
	void* LaunchInfoNew; // from g_SWldSessionInfo
	// at 0xb0
	int simFocusArmyIndex;
};

struct STIMap
{	// 0x1548 bytes

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
	int mGameSpeedClock;
	int mGameSpeedRequester; // misspelling? :D
	int mGameSpeed;
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
	/**
		+-------------------------------------------------------+
		|                                                       |
		|    GOOD NEWS EVERYONE, IT'S A MOHO::SET***            |
		|                                                       |
		|    ( It's still a really weird structure              |
		|      due to the magical optimizations                 |
		|      possible for AABB Sets via bit manipulation. )   |
		|                                                       |
		|    *** Probably                                       |
		+-------------------------------------------------------+

		Actually, a shitty bitvector
	*/
	struct Unknown
	{
		int set_base; // integer_base >> 5 (bits in dword)
		int unknown2;
		void* memory;
		void* memory_end;
		void* unknown5;
		void* unknown6;
		void* unknown7;
		void* unknown8;
	} thisIsTheWeirdestStructureIHaveSeen;

	//vector mValidCommandSources; // <int>?

	//int unknwon3;
	//int unknown4;
	//int unknwon5;
	//int unknown6;

	// at 0x50
	int mCommandSource;
	bool mReady;
	char _pad1[3];

	PipeStream mPipe;

	// at 0xA0
	int mQueuedBeat;
	int mDispatchedBeat;
	int mAvailableBeatRemote;
	vector mLatestAckReceived;
	int mLatestBeatDispatchedRemote;
	// at 0xC0
	bool mEjectPending;
	bool mEjected;
	char _pad2[2];
	list mEjectRequests; // <struct{ IClient* mRequester; int mAfterBeat;}>

	void* unknown;
	// at 0xD0
	void* uknown;
};

struct CNetUDPConnetor // : INetConnector
{
	INetConnector _base;
	void* smth; // listen socket fd?
	gpg_mutex mMutex;
	// at 0x14
	SOCKET mSocket;
	// at 0x24
	linked_list mConnections;// CNetUDPConnection*
};

struct ISTIDriver
{
	void* vtable;
};
struct CSTIDriver // : ISTIDriver
{
	ISTIDriver _base;
	void* notcarenow;
	IClientManager* clientManager;
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
