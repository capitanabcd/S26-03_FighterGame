#include "sfml.h"

void Attack::CheckHit() {

    Players& victim = (player->PlayerNumber == 1) ? player2 : player1;

    if (!player->isattacking) return;
    if (victim.hitTaken) return;

    sf::FloatRect atkbound = player->Sprite.getGlobalBounds();
    sf::FloatRect victimBound = victim.Sprite.getGlobalBounds();

    if (atkbound.intersects(victimBound)) {

        player->stagger(victim);
        if (player->HeavyAttackFrames != oldFrame)
        {
            TakeDamage(victim, 1.f);
            victim.hitTaken = true;
        }
        oldFrame = player->HeavyAttackFrames;
    }
}