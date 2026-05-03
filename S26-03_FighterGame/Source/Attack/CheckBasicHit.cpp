#include "sfml.h"

void Attack::CheckBasicHit() {
    Players& victim = (player->PlayerNumber == 1) ? player2 : player1;

    if (!player->isbasicattacking) return;
    if (victim.GetIsStaggered()) return;

    sf::FloatRect atkbound = player->Sprite.getGlobalBounds();
    sf::FloatRect victimBound = victim.Sprite.getGlobalBounds();

    if (atkbound.intersects(victimBound)) {
        if (player->BasicAttackFrames != oldFrame)
        {
            TakeDamageWithStagger(victim, 1.0f);

            if (victim.fireRanged == false)
            {
                victim.EndBeamAnimation();
            }
        }
        oldFrame = player->BasicAttackFrames;
    }
}