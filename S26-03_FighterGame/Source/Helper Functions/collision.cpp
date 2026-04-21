#include "sfml.h"

bool collide::MoveCollision() {

	setbounds();
	
	if (Player1Bounds.intersects(Player2Bounds) || player1.Sprite.getPosition().x > player2.Sprite.getPosition().x) {
		return true;
	}
	if (Player1Bounds.intersects(Player2Bounds) || player1.Sprite.getPosition().x < player2.Sprite.getPosition().x) {
		return true;
	}
	if (Player2Bounds.intersects(Player1Bounds) || player1.Sprite.getPosition().x > player2.Sprite.getPosition().x) {
		return true;
	}
	if (Player2Bounds.intersects(Player1Bounds) || player1.Sprite.getPosition().x < player2.Sprite.getPosition().x) {
		return true;
	}

}