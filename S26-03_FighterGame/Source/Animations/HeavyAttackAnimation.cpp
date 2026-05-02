#include "sfml.h"

void animations::HeavyAttackAnimation() {

	if (player->clock.getElapsedTime().asSeconds() >= 0.15f)
	{
		if (player->isattacking)
		{
			player->Sprite.setTexture(player->HeavyAttackTextures[player->HeavyAttackFrames], true);
			player->clock.restart();
			player->HeavyAttackFrames++;

			if (player->HeavyAttackFrames >= player->HeavyAttackTextures.size()) {
				player->Sprite.setTexture(player->IdleTextures[0], true);
				player->HeavyAttackFrames = 0;
				player->isattacking = false;
			}
				RevertOrigin();
		}
	}
}