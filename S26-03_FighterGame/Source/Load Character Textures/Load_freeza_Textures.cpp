#include "sfml.h"
void freeza::LoadTexture(sf::Texture* temp, sf::Texture* heavy)
{
	
	FreezaTexture[0].loadFromFile("assets/freeza/freeza Idle1.png");
	FreezaTexture[1].loadFromFile("assets/freeza/freeza Idle2.png");
	FreezaTexture[2].loadFromFile("assets/freeza/freeza Idle3.png");
	FreezaTexture[3].loadFromFile("assets/freeza/freeza Idle4.png");
	FreezaTexture[4].loadFromFile("assets/freeza/freeza Movement1.png");
	FreezaTexture[5].loadFromFile("assets/freeza/freeza Movement2.png");
	FreezaTexture[6].loadFromFile("assets/freeza/freeza Movement3.png");
	FreezaTexture[7].loadFromFile("assets/freeza/freeza Movement4.png");
	for (int i = 0; i < 8; i++)
	{
		temp[i] = FreezaTexture[i];
	}
}