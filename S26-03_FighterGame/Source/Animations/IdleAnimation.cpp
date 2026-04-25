#include "sfml.h"
void animations :: IdleAnimation()
{
	
	if(player->clock.getElapsedTime().asSeconds() >= 0.1f)
	{
		if (!player->IsMoving && !player->isjumping)
		{
			player->Sprite.setTexture(player->PlayerTexture[player->IdleFrames],true);
			player->clock.restart();
			player->IdleFrames++;
			if (player->IdleFrames > 3) player->IdleFrames = 0;
			RevertOrigin();
		}
	}
}