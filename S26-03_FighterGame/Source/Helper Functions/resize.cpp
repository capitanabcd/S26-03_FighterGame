#include "sfml.h"
void resize()
{
    float player1Bottom = player1.Sprite.getPosition().y;
    float player2Bottom = player2.Sprite.getPosition().y;

    if (player1Bottom >= ground)
    {
        player1.Sprite.setPosition(player1.Sprite.getPosition().x, ground);
        player1.VelocityY = 0;
        player1.isjumping = false;
    }
    if (player2Bottom >= ground)
    {
        player2.Sprite.setPosition(player2.Sprite.getPosition().x, ground);
        player2.VelocityY = 0;
        player2.isjumping = false;
    }
}