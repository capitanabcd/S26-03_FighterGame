#include "sfml.h"

void Attack::CheckBasicHit() {

    Players& victim = (player->PlayerNumber == 1) ? player2 : player1;

    if (!player->isbasicattacking) return;
    if (victim.hitTaken) return;

    sf::FloatRect atkbound = player->Sprite.getGlobalBounds();
    sf::FloatRect victimBound = victim.Sprite.getGlobalBounds();

    if (atkbound.intersects(victimBound)) {

        player->stagger(victim);
        if (player->BasicAttackFrames != oldFrame)
        {
            if (player->staggerTime <= 0) {
                if (victim.fireRanged == false)
                {
                    victim.EndBeamAnimation();
                }
                TakeDamage(victim, 1.f);
                victim.hitTaken = true;

            }
        }
        oldFrame = player->BasicAttackFrames;
    }
}