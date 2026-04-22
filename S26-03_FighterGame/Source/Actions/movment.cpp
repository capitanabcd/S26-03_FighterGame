#include "sfml.h"
void movement::Movement()
{
	player->IsMoving = false;
	player->MovingRight = false;
	player->MovingLeft = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player->PlayerNumber == 1)
		player->MovingRight = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player->PlayerNumber == 1)
		player->MovingLeft = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player->PlayerNumber == 2)
		player->MovingRight = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player->PlayerNumber == 2)
		player->MovingLeft = true;

	float direction = 0.f;
	if (player->MovingRight) direction = 1.f;
	if (player->MovingLeft) direction = -1.f;

	if (direction != 0.f && !player->MoveCollision()) {
		player->Sprite.move(direction * VelocityX * dt, 0.f);
		player->IsMoving = true;
	}
}