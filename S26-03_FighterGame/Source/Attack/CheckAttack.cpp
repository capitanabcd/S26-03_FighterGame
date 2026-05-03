#include "sfml.h"

void Attack::CheckHit() {
    Players& victim = (player->PlayerNumber == 1) ? player2 : player1;

    if (!player->isattacking) return;
    if (victim.GetIsStaggered()) return;

    sf::FloatRect atkbound = player->Sprite.getGlobalBounds();
    sf::FloatRect victimBound = victim.Sprite.getGlobalBounds();

    if (atkbound.intersects(victimBound)) {
        if (player->HeavyAttackFrames != oldFrame)
        {
            TakeDamageWithStagger(victim, 1.7f);

            if (victim.fireRanged == false)
            {
                victim.EndBeamAnimation();
            }
        }
        oldFrame = player->HeavyAttackFrames;
    }
}