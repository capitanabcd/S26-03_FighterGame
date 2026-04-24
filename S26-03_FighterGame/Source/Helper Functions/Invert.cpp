#include"sfml.h"
void animations::invert()
{
	if (player->MovingRight)
	{
		player->Sprite.setScale(3.f, 3.f);
	}
	if (player->MovingLeft)
	{
		player->Sprite.setScale(-3.f, 3.f);
	}
}
