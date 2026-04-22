#include "sfml.h"
bool collide::MoveCollision() {
	setbounds();

	if (Player1Bounds.intersects(Player2Bounds)) {
		return true;
	}

	return false;
}