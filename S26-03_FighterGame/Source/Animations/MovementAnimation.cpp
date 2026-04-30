#include "sfml.h"
void animations :: MovementAnimation()
{
	if (!player->hitTaken && !player->isattacking)
	{
		if (player->clock.getElapsedTime().asSeconds() >= 0.05f)
		{
			if (player->IsMoving)
			{
				player->Sprite.setTexture(player->MovementTextures[player->MovementFrames], true);
				player->clock.restart();
				player->MovementFrames++;
				if (player->MovementFrames >= player->MovementTextures.size()) player->MovementFrames = 0;
				invert();
				RevertOrigin();
			}
		}
	}
} 