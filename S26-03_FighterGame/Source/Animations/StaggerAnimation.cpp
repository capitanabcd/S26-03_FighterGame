#include "sfml.h"

void animations::StaggerAnimation() {

	if (!player->hitTaken) return;

	player->staggerTime -= dt;

	if (player->staggerclock.getElapsedTime().asSeconds() >= 0.2f)
	{
		player->Sprite.setTexture(player->StaggerTextures[player->StaggerFrames], true);
		player->staggerclock.restart();
		player->StaggerFrames++;
		if (player->StaggerFrames = player->StaggerTextures.size()) {
			player->StaggerFrames--;
		}
		RevertOrigin();
	}
	if (player->staggerTime <= 0.0f) {
		player->hitTaken = false;
		player->StaggerFrames = 0;
		player->staggerTime = 0.0f;
		player->Sprite.setTexture(player->IdleTextures[0], true);
		RevertOrigin();
	}
}