#include "sfml.h"
void animations :: MovementAnimation()
{
	if (player->clock.getElapsedTime().asSeconds() >= 0.1f)
	{
		if (player->IsMoving || player->MovingRight || player->MovingLeft)
		{
			player->Sprite.setTexture(player->PlayerTexture[player->MovementFrames],true);
			player->clock.restart();
			player->MovementFrames++;
			if (player->MovementFrames > 7) player->MovementFrames = 4;
			invert();
		}
	}
} 