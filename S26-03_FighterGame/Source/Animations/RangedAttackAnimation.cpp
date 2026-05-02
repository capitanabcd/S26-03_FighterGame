#include "sfml.h"

void animations::RangedAttackAnimation() {

	if (player->clock.getElapsedTime().asSeconds() >= 0.02f)
	{
		if (player->fireRanged)

		{
			player->RangedAttack.setPosition(player->Sprite.getPosition().x + 50, player->Sprite.getPosition().y - 300);
			invert();
			player->RangedAttack.setTexture(player->RangedTexture[player->RangedFrames], true);
			player->clock.restart();
			player->RangedFrames++;

			if (player->RangedFrames >= player->RangedTexture.size()) {
				player->RangedAttack.setTexture(player->EmptyTexture, true);
				player->RangedFrames = 0;
				player->fireRanged = false;
			}
			invert();
			RevertOrigin();
		}
	}
}