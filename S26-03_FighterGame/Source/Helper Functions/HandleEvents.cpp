#include "sfml.h"

void window::HandleEvents()
{
	if (event.type == sf::Event::KeyPressed)
	{
		
		if (event.key.code == sf::Keyboard::W && player1.isattacking == false && player1.isbeaming == false)
		{
			player1.jump();
			player1.s->jumpSound.play();
		}
		if (event.key.code == sf::Keyboard::Up && player2.isattacking == false && player2.isbeaming == false)
		{
			player2.jump();
			player2.s->jumpSound.play();
		}
		if (event.key.code == sf::Keyboard::F && player1.IsMoving == false && player1.isjumping == false && player1.isbeaming == false && player1.hitTaken == false && player1.isbasicattacking == false)
		{
			player1.isattacking = true;
			player1.s->hitSound.play();
		}
		if (event.key.code == sf::Keyboard::J && player2.IsMoving == false && player2.isjumping == false && player2.isbeaming == false && player2.hitTaken == false && player2.isbasicattacking == false) {
			player2.isattacking = true;
			player2.s->hitSound.play();
		}
		if (event.key.code == sf::Keyboard::Q && player1.IsMoving == false && player1.isjumping == false && player1.isbasicattacking == false && player1.isattacking == false && player1.hitTaken == false) {
			if (player1.BeamNumbers > 0)
				player1.isbeaming = true;
			player1.s->beamSound.play();
		}
		if (event.key.code == sf::Keyboard::L && player2.IsMoving == false && player2.isjumping == false && player2.isattacking == false && player2.isbasicattacking == false && player2.hitTaken == false) {
			if (player2.BeamNumbers > 0)
				player2.isbeaming = true;
			player2.s->beamSound.play();
		}
		if (event.key.code == sf::Keyboard::E && player1.IsMoving == false && player1.isjumping == false && player1.isbeaming == false && player1.isattacking == false && player1.hitTaken == false) {

			player1.isbasicattacking = true;
			player1.s->kickSound.play();
		}
		if (event.key.code == sf::Keyboard::K && player2.IsMoving == false && player2.isjumping == false &&  player2.isbeaming == false && player2.isattacking == false && player2.hitTaken == false) {

			player2.isbasicattacking = true;
			player2.s->kickSound.play();
		}
	}


	
	CloseWindow();
}