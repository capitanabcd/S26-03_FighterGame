#include"sfml.h"
void animations::invert()
{
	if (player->MovingRight)
	{
		player->Sprite.setScale(4.f, 4.f);
		sf::FloatRect bounds = player->Sprite.getLocalBounds();
		player->Sprite.setOrigin(bounds.width / 2.f, bounds.height);
	}
	if (player->MovingLeft)
	{
		player->Sprite.setScale(-4.f, 4.f);
		sf::FloatRect bounds = player->Sprite.getLocalBounds();
		player->Sprite.setOrigin(bounds.width / 2.f, bounds.height);
	}
}
