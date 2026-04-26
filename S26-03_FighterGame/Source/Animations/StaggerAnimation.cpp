#include "sfml.h"

void animations::StaggerAnimation() {

	if (player->staggerclock.getElapsedTime().asSeconds() >= 0.25f)
	{
		if (player->hitTaken)
		{
			player->Sprite.setTexture(player->PlayerStaggerTexture[player->StaggerFrames], true);
			player->staggerclock.restart();
			player->StaggerFrames++;
			if (player->StaggerFrames >= 2) {
				player->Sprite.setTexture(player->PlayerTexture[0]);
				player->StaggerFrames = 0;
				player->hitTaken = false;
			}

		}
	}
}