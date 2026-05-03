#include "sfml.h"

void animations::BasicAttackAnimation() {

	if (player->clock.getElapsedTime().asSeconds() >= 0.1f)
	{

		if (player->isbasicattacking)
		{


			player->Sprite.setTexture(player->BasicAttackTexture[player->BasicAttackFrames], true);
			player->clock.restart();
			player->BasicAttackFrames++;

			if (player->BasicAttackFrames >= player->BasicAttackTexture.size()) {
				player->Sprite.setTexture(player->IdleTextures[0], true);
				player->BasicAttackFrames = 0;
				player->isbasicattacking = false;
			}
			RevertOrigin();
		}
	}
}