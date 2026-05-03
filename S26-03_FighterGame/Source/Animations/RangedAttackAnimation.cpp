#include "sfml.h"
void animations::RangedAttackAnimation() {
    if (player->clock.getElapsedTime().asSeconds() >= 0.009f)
    {
        if (player->fireRanged)
        {
            sf::FloatRect playerBounds = player->Sprite.getGlobalBounds();
            sf::Vector2f playerPos = player->Sprite.getPosition();

            float spawnX = playerPos.x;
            float spawnY = playerPos.y - (playerBounds.height * 1.1f);

            float offsetDistance = 10.0f;

            if (player->MovingRight) {
                spawnX += (playerBounds.width / 2.0f) + offsetDistance;
                player->RangedAttack.setScale(1.f, 0.6f);
            }
            else {
                spawnX -= (playerBounds.width / 2.0f) + offsetDistance;
                player->RangedAttack.setScale(-1.f, 0.6f);
            }

            player->RangedAttack.setPosition(spawnX, spawnY);
            player->RangedAttack.setTexture(player->RangedTexture[player->RangedFrames], true);
            player->clock.restart();
            player->RangedFrames++;

            if (player->RangedFrames >= player->RangedTexture.size()) {
                player->RangedAttack.setTexture(player->EmptyTexture, true);
                player->RangedFrames = 0;
                player->fireRanged = false;
                player->Sprite.setTexture(player->IdleTextures[0], true);
                EndBeamAnimation();
            }
        }
    }
}