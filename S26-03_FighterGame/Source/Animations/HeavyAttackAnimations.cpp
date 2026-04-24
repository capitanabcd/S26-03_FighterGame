#include "sfml.h"

void animations::HeavyAttackAnimation() {

	if (player->clock.getElapsedTime().asSeconds() >= 0.1f)
	{
		if (player->isattacking && player->IsMoving == false)
		{
			player->Sprite.setTexture(player->PlayerHeavyTextures[player->HeavyAttackFrames], true);
			player->clock.restart();
			player->HeavyAttackFrames++;
			if (player->HeavyAttackFrames >= 12) {
				player->Sprite.setTexture(player->PlayerTexture[0]);
				player->HeavyAttackFrames = 0;
				player->isattacking = false;
			}
			
		}
	}
}