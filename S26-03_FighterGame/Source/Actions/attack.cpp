#include "sfml.h"

void animations::stagger(){

	if (staggerTime > 0) {
		staggerTime -= dt;
	}
	else {
		staggerTime = 0;
	}

}

void attack::punch() 
{
	bool isHit = false;
	if (isattacking == false)
	{
		
			isattacking = true;


			sf::FloatRect p1Bounds = player1.Sprite.getGlobalBounds();
			sf::FloatRect p2Bounds = player2.Sprite.getGlobalBounds();

			if (p1Bounds.intersects(p2Bounds)) {
				if (!player2.hitTaken&& player2.staggerTime <= 0) {
					isHit = true;
					player2.hitTaken = true;
					player2.staggerTime = 0.5f;
					
				}
			}

		

		/*player2.hitTaken = true;*/
	}
}