#include "sfml.h"

void animations::RangedAttackAnimation() {

	if (player->clock.getElapsedTime().asSeconds() >= 0.1f)
	{
		if (player->fireRanged)

		{
			player->RangedAttack.setPosition(player->Sprite.getOrigin().x + 5, player->Sprite.getOrigin().y);
			player->RangedAttack.setScale(2.f, 2.f);
			player->RangedAttack.setTexture(player->RangedTexture[player->RangedFrames], true);
			player->clock.restart();
			player->RangedFrames++;

			if (player->RangedFrames >= player->RangedTexture.size()) {
				player->RangedAttack.setTexture(player->EmptyTexture, true);
				player->RangedFrames = 0;
				player->fireRanged = false;
			}
			RevertOrigin();
		}
	}
}