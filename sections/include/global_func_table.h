// emit reversed functions for later use.
#include "typeDefs.h"
#include "moho.h"

extern _DWORD tick_num;
extern _DWORD tag_sent;
extern _DWORD num_clients;
extern _DWORD terminated;
extern _DWORD p_index;
extern _DWORD sender_sock;
extern _DWORD current_num_clients;
extern _DWORD sync_buffer[17];
extern bool paused;
extern bool game_ended;

void RangeRings();
void GlobalRings();
void SelectionRings();
void GetSelectedUnits();
void SearchIndexWithString();
void GeometricCamera();
void LowResolutionGeonometricCamera();
void AirMotionTick();
void AllUnitsMotionTick();
void CalcMoveLand();
void MoveTo();
void Unit_MotionTick();
void UpdateCurrentPosition();
void NavigationTick();
void Moho__CDecoder__DecodeMessage();
void MOHO_USER_INPUT();
void SessionEndGame();
void Gpg_Net_Entry();
void Conexecute();
void sim_dispatch();
void Update_Pipeline_Stream();
void EndGame();
void SimSetFocusArmy();
void SSFARegDescFunc();

class GFT
{
public:
	int IssueMove();

	//nantest.cpp----------------------------------------------------
	bool nanTest(float *a1);
	//---------------------------------------------------------------

	//setCoordsArray.cpp---------------------------------------------
	_DWORD* LuaPlus_LuaObject_LuaObject(_DWORD *_this);
	_DWORD* Moho_SSTICommandIssueData_SSTICommandIssueData(_DWORD* _this, int a2);
	int sub_5796A0(_DWORD *a1);
	//---------------------------------------------------------------

	//Validate_IssueCommand.cpp--------------------------------------
	int sub_57DDD0(int a1, int a2, int Src, int a4);
	_DWORD* sub_57FE30(int a1, void *a2, void *Src, int a4);
	__attribute__((fastcall)) int sub_5811A0(_DWORD *a1, int a2, int a3, _DWORD *a4, _DWORD *a5);
	_DWORD* cmp_pointers(_DWORD *result, _DWORD *a2, _DWORD *a3);
	int sub_582EB0(int *a1, int a2, int a3);
	bool Validate_IssueCommand(int a1, int a2, int a3);
	//---------------------------------------------------------------

	//Get_Lua_Coordinates_State.cpp----------------------------------
	int Get_Lua_Coordinates_State(int a1, struct LuaState *a2, int a3, struct lua_State **a4, int a5);

	//Push_Coordinates.cpp----------------------------------
	int Push_Coordinates(int result, int a2);









	//----- (00924050) --------------------------------------------------------
	int lua_getglobaluserdata(int a1)
	{
		return *(_DWORD *)(*(_DWORD *)(a1 + 16) + 328);
	}
	//int lua_gettop(int &a1);

};
