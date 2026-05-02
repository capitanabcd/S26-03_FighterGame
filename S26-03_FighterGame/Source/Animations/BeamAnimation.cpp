#include "sfml.h"

void animations::BeamAnimation() {

	if (player->clock.getElapsedTime().asSeconds() >= 0.1f)
	{
		if (player->isbeaming)
		{
			if (player->BeamFrames == 9 && !player->fireRanged) {
				player->fireRanged = true;
			}
			player->Sprite.setTexture(player->BeamTextures[player->BeamFrames], true);
			player->clock.restart();
			player->BeamFrames++;

			

			if (player->BeamFrames >= player->BeamTextures.size()) {
				player->Sprite.setTexture(player->IdleTextures[0], true);
				player->BeamFrames = 0;
				player->isbeaming = false;
			}
			RevertOrigin();
		}
	}
}