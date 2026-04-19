#include "sfml.h"

void movement::Movement()
{

	player->IsMoving = false;
	bool p1movingRight = false;
	bool p1movingLeft = false;
	bool p2movingLeft = false;
	bool p2movingRight = false;



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player->PlayerNumber == 1)
	{
		p1movingRight = true;


	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player->PlayerNumber == 1)
	{
		p1movingLeft = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player->PlayerNumber == 2)
	{
		p2movingRight = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player->PlayerNumber == 2)
	{
		p2movingLeft = true;

	}

	sf::FloatRect p1bound = player1.Sprite.getGlobalBounds();
	sf::FloatRect p2bound = player2.Sprite.getGlobalBounds();

	if (p1movingRight) {
		if (!p1bound.intersects(p2bound) || player1.Sprite.getPosition().x > player2.Sprite.getPosition().x) {

			player->Sprite.move(VelocityX * dt, 0.f);
			player->IsMoving = true;
		}

	}
	if (p1movingLeft) {
		if (!p1bound.intersects(p2bound) || player1.Sprite.getPosition().x < player2.Sprite.getPosition().x) {
			player->Sprite.move(-VelocityX * dt, 0.f);
		}
	}
	if (p2movingRight) {
		if (!p2bound.intersects(p1bound) || player2.Sprite.getPosition().x > player1.Sprite.getPosition().x) {
			player->Sprite.move(VelocityX * dt, 0.f);
			player->IsMoving = true;
		}
	}
	if (p2movingLeft) {
		if (!p2bound.intersects(p1bound) || player2.Sprite.getPosition().x < player1.Sprite.getPosition().x) {
			player->Sprite.move(-VelocityX * dt, 0.f);
			player->IsMoving = true;
		}
	}

}