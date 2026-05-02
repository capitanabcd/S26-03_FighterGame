#include "sfml.h"
void animations :: IdleAnimation()
{
	if (!player->hitTaken && !player->isattacking)
	{
		if (player->clock.getElapsedTime().asSeconds() >= 0.2f)
		{
			if (!player->IsMoving && !player->isjumping)
			{
				if (player->IdleFrames == 0) {
					float p1Yscale = player1.Sprite.getScale().y;
					float p1Xscale = (player2.Sprite.getPosition().x > player1.Sprite.getPosition().x) ? 4.4f : -4.4f;
					player1.Sprite.setScale(p1Xscale, p1Yscale);

					float p2Yscale = player2.Sprite.getScale().y;
					float p2Xscale = (player1.Sprite.getPosition().x > player2.Sprite.getPosition().x) ? 4.4f : -4.4f;
					player2.Sprite.setScale(p2Xscale, p2Yscale);
				}
				player->Sprite.setTexture(player->IdleTextures[player->IdleFrames], true);
				player->clock.restart();
				player->IdleFrames++;
				if (player->IdleFrames >= player->IdleTextures.size()) player->IdleFrames = 0;
				RevertOrigin();
			}
		}
	}
}