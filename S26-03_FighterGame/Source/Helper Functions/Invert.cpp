#include"sfml.h"
void animations::invert()
{
	//if (player->MovingRight)
	//{
	//	player->RangedAttack.setScale(0.9f, 0.9f);
	//	sf::FloatRect bounds = player->Sprite.getLocalBounds();
	//	player->Sprite.setOrigin(bounds.width / 2.f, bounds.height);
	//}
	//if (player->MovingLeft)
	//{
	//	player->RangedAttack.setScale(-0.9f, 0.9);
	//	sf::FloatRect bounds = player->Sprite.getLocalBounds();
	//	player->Sprite.setOrigin(bounds.width / 2.f, bounds.height);
	//}

	float p1Yscale = player1.Sprite.getScale().y;
	float p1Xscale;
	if (player2.Sprite.getPosition().x > player1.Sprite.getPosition().x) {
		p1Xscale = 4.4f;
		player1.MovingRight = true;
	}
	else {
		p1Xscale = -4.4f;
		player1.MovingLeft = true;
	}
	player1.Sprite.setScale(p1Xscale, p1Yscale);

	float p2Yscale = player2.Sprite.getScale().y;
	float p2Xscale;
	if (player1.Sprite.getPosition().x > player2.Sprite.getPosition().x) {
		p2Xscale = 4.4f;
		player2.MovingRight = true;
	}
	else {
		p2Xscale = -4.4f;
		player2.MovingLeft = true;
	}
	player2.Sprite.setScale(p2Xscale, p2Yscale);
}
