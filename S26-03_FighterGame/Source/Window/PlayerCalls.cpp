#include "sfml.h"

void PlayerCalls()
{
    float currentDt = dt;

    player1.Updatejump();
    player1.Movement();
    player2.Updatejump();
    player2.Movement();

    player1.UpdateStagger(currentDt);
    player2.UpdateStagger(currentDt);

    player1.UpdateFlash(player1, currentDt);
    player2.UpdateFlash(player2, currentDt);

    player1.CheckHit();
    player2.CheckHit();
    player1.CheckBasicHit();
    player2.CheckBasicHit();
    player1.CheckRangeHit();
    player2.CheckRangeHit();
}