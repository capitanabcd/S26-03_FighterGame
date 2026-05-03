#include "sfml.h"

void window::HandleEvents()
{
	if (event.type == sf::Event::KeyPressed)
	{
		
		if (event.key.code == sf::Keyboard::W) {
			player1.jump();
			player1.s->jumpSound.play();
		}

		if (event.key.code == sf::Keyboard::Up)
		{
			player2.jump();
			player2.s->jumpSound.play();
		}
		if (event.key.code == sf::Keyboard::F)
		{
			player1.isattacking = true;
			player1.s->hitSound.play();
		}
		if (event.key.code == sf::Keyboard::J) {
			player2.isattacking = true;
			player2.s->hitSound.play();
		}
	}


	
	CloseWindow();
}