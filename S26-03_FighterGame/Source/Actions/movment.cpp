#include "sfml.h"

void movement::Movement()
{	
	player->IsMoving = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& player->PlayerNumber == 1)
	{
		player->Sprite.move(VelocityX * dt, 0.f);
		player->IsMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&& player->PlayerNumber == 1)
	{
		player->Sprite.move(-VelocityX * dt, 0.f);
		player->IsMoving = true;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& player->PlayerNumber == 2)
	{
		player->Sprite.move(VelocityX * dt, 0.f);
		player->IsMoving = true;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& player->PlayerNumber == 2)
	{
		player->Sprite.move(-VelocityX * dt, 0.f);
		player->IsMoving = true;
	}
}