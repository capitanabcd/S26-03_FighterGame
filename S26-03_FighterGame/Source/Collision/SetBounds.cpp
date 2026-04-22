#include "sfml.h"

void collide::setbounds() {
	Player1Bounds = player1.Sprite.getGlobalBounds();
	Player2Bounds = player2.Sprite.getGlobalBounds();
}


