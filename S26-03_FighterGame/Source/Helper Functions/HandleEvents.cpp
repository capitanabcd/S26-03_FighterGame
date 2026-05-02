#include "sfml.h"

void window::HandleEvents()
{
	if (event.type == sf::Event::KeyPressed)
	{
		
		if (event.key.code == sf::Keyboard::W) {
			player1.jump();
			s.jumpSound.play();
		}

		if (event.key.code == sf::Keyboard::Up)
		{
			player2.jump();
			s.jumpSound.play();
		}
		if (event.key.code == sf::Keyboard::F)
		{
			player1.isattacking = true;
			s.hitSound.play();
		}
		if (event.key.code == sf::Keyboard::J) {
			player2.isattacking = true;
			s.hitSound.play();
		}
	}


	
	CloseWindow();
}