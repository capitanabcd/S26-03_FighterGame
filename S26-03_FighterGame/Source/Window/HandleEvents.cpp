#include "sfml.h"


void window::HandleEvents()
{
	if (event.type == sf::Event::KeyPressed)

		
		
	{
		
		if (event.key.code == sf::Keyboard::W) {
			player1.jump();
		}
	}
	if(event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Up)
		{
			player2.jump();
		}
	}
	CloseWindow();
}