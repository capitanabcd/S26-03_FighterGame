#include "sfml.h"

void Attack::CheckHit() {

	Players& attacker = *player;
	Players& victim = (attacker.PlayerNumber == 1) ? player2 : player1;

	if (!attacker.isattacking) return;
	if (victim.hitTaken) return;
	sf::FloatRect atkbound = attacker.Sprite.getGlobalBounds();
	sf::FloatRect victimBound = victim.Sprite.getGlobalBounds();
	if (atkbound.intersects(victimBound)) {
		player->stagger(victim);
	}
}