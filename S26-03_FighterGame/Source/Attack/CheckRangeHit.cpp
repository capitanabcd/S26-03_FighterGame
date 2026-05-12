#include "sfml.h"

void Attack::CheckRangeHit() {
    Players& victim = (player->PlayerNumber == 1) ? player2 : player1;

    if (!player->fireRanged) return;
    if (victim.GetIsStaggered()) return;

    sf::FloatRect atkbound = player->RangedAttack.getGlobalBounds();
    sf::FloatRect victimBound = victim.Sprite.getGlobalBounds();

    if (atkbound.intersects(victimBound)) {
        if (player->RangedFrames != oldFrame)
        {
            TakeDamageWithStagger(victim, 0.5f);
            StartFlash(victim);
        }
        oldFrame = player->RangedFrames;
    }
}