#include "sfml.h"

void collide::setbounds() {
	Player1Bounds = player1.Sprite.getGlobalBounds();
	Player2Bounds = player2.Sprite.getGlobalBounds();
	Player1Bounds.width /= 1.5;
	Player2Bounds.width /= 1.5;
}


