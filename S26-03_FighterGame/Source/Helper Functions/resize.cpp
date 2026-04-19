#include "sfml.h"
void resize()
{
	if (player1.Sprite.getPosition().y >= ground - player1.Sprite.getGlobalBounds().height)
	{
		player1.Sprite.setPosition(player1.Sprite.getPosition().x, ground - player1.Sprite.getGlobalBounds().height);
		player1.VelocityY = 0;
		player1.isjumping = false;
	}
	if (player2.Sprite.getPosition().y >= ground - player2.Sprite.getGlobalBounds().height)
	{
		player2.Sprite.setPosition(player2.Sprite.getPosition().x, ground - player2.Sprite.getGlobalBounds().height);
		player2.VelocityY = 0;
		player2.isjumping = false;
	}
}