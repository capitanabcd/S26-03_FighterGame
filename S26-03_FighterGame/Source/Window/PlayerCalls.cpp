#include "sfml.h"
void PlayerCalls()
{
	player1.Updatejump();
	player1.Movement();
	player2.Updatejump();
	player2.Movement();
	player1.CheckHit();
	player2.CheckHit();
	player1.CheckRangeHit();
	player2.CheckRangeHit();
	player1.CheckBasicHit();
	player2.CheckBasicHit();
	player1.UpdateStagger();
	player2.UpdateStagger();
}