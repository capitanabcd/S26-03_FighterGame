#include"sfml.h"
void animations::invert()
{
	if (player->MovingRight)
	{
		player->Sprite.setScale(4.f, 4.f);
		player->RangedAttack.setScale(9.f, 7.f);
		sf::FloatRect bounds = player->Sprite.getLocalBounds();
		player->Sprite.setOrigin(bounds.width / 2.f, bounds.height);
	}
	if (player->MovingLeft)
	{
		player->Sprite.setScale(-4.f, 4.f);
		player->RangedAttack.setScale(-5.f, 7.f);
		sf::FloatRect bounds = player->Sprite.getLocalBounds();
		player->Sprite.setOrigin(bounds.width / 2.f, bounds.height);
	}
}
