#include "sfml.h"

void Attack::CheckHit() {

	Players& attacker = *player;
	Players& victim = (attacker.PlayerNumber == 1) ? player2 : player1;

	sf::FloatRect atkbound = attacker.Sprite.getGlobalBounds();
	sf::FloatRect victimBound = victim.Sprite.getGlobalBounds();
	if (atkbound.intersects(victimBound)) {
		if (!victim.hitTaken && victim.staggerTime <= 0) {
			victim.hitTaken = true;
			victim.staggerTime = 0.8f;
			victim.staggerclock.restart();
			victim.StaggerFrames = 0;

		}
	}
}