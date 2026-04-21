#include "sfml.h"



void attack::punch() 
{
	bool isHit = false;
	if (isattacking == false) 
	{
		isattacking = true;
		//animation here. Add the loop for the animation and put this code in the loop
		//to check every frame, or just check at the last few

		sf::FloatRect p1Bounds = player1.Sprite.getGlobalBounds();
		sf::FloatRect p2Bounds = player2.Sprite.getGlobalBounds();

		if (p1Bounds.intersects(p2Bounds)) {
			isHit = true;
			player->stagger();
		}

	}

			/*player2.hitTaken = true;*/

}