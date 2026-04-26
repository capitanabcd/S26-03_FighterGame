#include "sfml.h"
void freeza::LoadTexture(sf::Texture* temp, sf::Texture* heavy, sf::Texture* stagger)
{
	
	FreezaTexture[0].loadFromFile("assets/freeza/freeza Idle1.png");
	FreezaTexture[1].loadFromFile("assets/freeza/freeza Idle2.png");
	FreezaTexture[2].loadFromFile("assets/freeza/freeza Idle3.png");
	FreezaTexture[3].loadFromFile("assets/freeza/freeza Idle4.png");
	FreezaTexture[4].loadFromFile("assets/freeza/freeza Movement1.png");
	FreezaTexture[5].loadFromFile("assets/freeza/freeza Movement2.png");
	FreezaTexture[6].loadFromFile("assets/freeza/freeza Movement3.png");
	FreezaTexture[7].loadFromFile("assets/freeza/freeza Movement4.png");
	FreezaStagger[0].loadFromFile("assets/goku/goku stagger_1.png");
	FreezaStagger[1].loadFromFile("assets/goku/goku stagger_2.png");
	FreezaStagger[2].loadFromFile("assets/goku/goku stagger_3.png");
	for (int i = 0; i < 8; i++)
	{
		temp[i] = FreezaTexture[i];
	}
	for (int i = 0; i < 3; i++) {
		stagger[i] = FreezaStagger[i];
	}
}