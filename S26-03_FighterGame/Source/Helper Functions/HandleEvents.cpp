#include "sfml.h"


void window::HandleEvents()
{
	if (event.type == sf::Event::KeyPressed)
	{
		
		if (event.key.code == sf::Keyboard::W) {
			player1.jump();
		}

		if (event.key.code == sf::Keyboard::Up)
		{
			player2.jump();
		}
		if (event.key.code == sf::Keyboard::F)
		{
			player1.isattacking = true;
		}
		if (event.key.code == sf::Keyboard::J) {
			player2.isattacking = true;
		}
	}
	
	CloseWindow();
}