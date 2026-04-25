#include "sfml.h"
void animations::RevertOrigin()
{
	sf::FloatRect bounds = player->Sprite.getLocalBounds();
	player->Sprite.setOrigin(bounds.width / 2.f, bounds.height);
}