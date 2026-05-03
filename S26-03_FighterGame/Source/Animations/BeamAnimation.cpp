#include "sfml.h"

void animations::BeamAnimation() {
    if (player->clock.getElapsedTime().asSeconds() >= 0.1f)
    {
        if (player->isbeaming)
        {
            if (player->BeamFrames < player->BeamTextures.size() - 1) {
                player->Sprite.setTexture(player->BeamTextures[player->BeamFrames], true);
                player->clock.restart();
                player->BeamFrames++;
            }
            else if (player->BeamFrames == player->BeamTextures.size() - 1) {
                if (!player->fireRanged) {
                    player->fireRanged = true;
                }
                player->Sprite.setTexture(player->BeamTextures[player->BeamFrames], true);
            }

            RevertOrigin();
        }
    }
}
void animations::EndBeamAnimation() {
    if (player->isbeaming) {
        player->isbeaming = false;
        player->BeamFrames = 0;
        player->Sprite.setTexture(player->IdleTextures[0], true);
    }
}