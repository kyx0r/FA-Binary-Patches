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
void SessionIsReplay();

class GFT
{
public:

};
