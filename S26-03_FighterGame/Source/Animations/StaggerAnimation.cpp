#include "sfml.h"

void animations::StaggerAnimation() {

	if (player->staggerclock.getElapsedTime().asSeconds() >= 0.25f)
	{
		if (player->hitTaken)
		{
			player->Sprite.setTexture(player->StaggerTextures[player->StaggerFrames], true);
			player->staggerclock.restart();
			player->StaggerFrames++;
			if (player->StaggerFrames >= player->StaggerTextures.size()) {
				if (staggerTime <= 0) {
					player->Sprite.setTexture(player->IdleTextures[0]);
					player->StaggerFrames = 0;
					player->hitTaken = false;
				}
				else {
					player->StaggerFrames = 2;
				}

			}

		}
	}
}