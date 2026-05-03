#include "sfml.h"

void Attack::CheckRangeHit() {
    Players& victim = (player->PlayerNumber == 1) ? player2 : player1;

    if (!player->fireRanged) return;
    if (victim.hitTaken) return;

    sf::FloatRect atkbound = player->RangedAttack.getGlobalBounds();
    sf::FloatRect victimBound = victim.Sprite.getGlobalBounds();

    if (atkbound.intersects(victimBound)) {

        player->stagger(victim);
        if (player->RangedFrames!= oldFrame)
        {
            TakeDamage(victim, 0.5f);
            victim.hitTaken = true;
        }
        oldFrame = player->RangedFrames;
    }
}