#include "sfml.h"


void window::HandleEvents()
{
	if (event.type == sf::Event::KeyPressed)
	{
		
		if (event.key.code == sf::Keyboard::W && player1.isattacking == false && player1.isbeaming == false) {
			player1.jump();
		}
		if (event.key.code == sf::Keyboard::Up && player2.isattacking == false && player2.isbeaming == false)
		{
			player2.jump();
		}
		if (event.key.code == sf::Keyboard::F && player1.IsMoving == false && player1.isjumping == false)
		{
			player1.isattacking = true;
		}
		if (event.key.code == sf::Keyboard::J && player2.IsMoving == false && player2.isjumping == false) {
			player2.isattacking = true;
		}
		if (event.key.code == sf::Keyboard::Q && player1.IsMoving == false && player1.isjumping == false) {
			player1.isbeaming = true;
		}
		if (event.key.code == sf::Keyboard::L) {
			player2.isbeaming = true;
		}
	}
	
	CloseWindow();
}