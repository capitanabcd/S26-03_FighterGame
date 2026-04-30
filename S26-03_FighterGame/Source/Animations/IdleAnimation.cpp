#include "sfml.h"
void animations :: IdleAnimation()
{
	if (!player->hitTaken && !player->isattacking)
	{
		if (player->clock.getElapsedTime().asSeconds() >= 0.2f)
		{
			if (!player->IsMoving && !player->isjumping)
			{
				player->Sprite.setTexture(player->IdleTextures[player->IdleFrames], true);
				player->clock.restart();
				player->IdleFrames++;
				if (player->IdleFrames >= player->IdleTextures.size()) player->IdleFrames = 0;
				RevertOrigin();
			}
		}
	}
}