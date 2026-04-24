#include "sfml.h"



void attack::punch() 
{
	bool isHit = false;
	if (isattacking == false) 
	{
		isattacking = true;

		
		sf::FloatRect p1Bounds = player1.Sprite.getGlobalBounds();
		sf::FloatRect p2Bounds = player2.Sprite.getGlobalBounds();

		if (p1Bounds.intersects(p2Bounds)) {
			isHit = true;
			player->stagger();
		}

	}

			/*player2.hitTaken = true;*/

}