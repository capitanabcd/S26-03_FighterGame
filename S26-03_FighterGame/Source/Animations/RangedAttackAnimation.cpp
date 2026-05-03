#include "sfml.h"

void animations::RangedAttackAnimation() {
    if (player->clock.getElapsedTime().asSeconds() >= 0.009f)
    {
        if (player->fireRanged)
        {
            sf::FloatRect characterBounds = player->Sprite.getGlobalBounds();

            float spawnX = player->Sprite.getPosition().x;
            float spawnY = player->Sprite.getPosition().y/2;

            if (player->MovingRight) {
                spawnX += characterBounds.width/2;
            }
            else {
                spawnX -= characterBounds.width/2;
            }
            player->RangedAttack.setPosition(spawnX, spawnY);

            invert();
            player->RangedAttack.setTexture(player->RangedTexture[player->RangedFrames], true);
            player->clock.restart();
            player->RangedFrames++;

            if (player->RangedFrames >= player->RangedTexture.size()) {
                player->RangedAttack.setTexture(player->EmptyTexture, true);
                player->RangedFrames = 0;
                player->fireRanged = false;
                EndBeamAnimation();
            }

            invert();
            RevertOrigin();
        }
    }
}