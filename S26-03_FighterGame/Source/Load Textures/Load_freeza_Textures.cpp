#include "sfml.h"
void freeza::LoadTexture(sf::Texture* temp)
{
	FreezaTexture[0].loadFromFile("assets/freeza/freeza1.png");
	FreezaTexture[1].loadFromFile("assets/freeza/freeza2.png");
	FreezaTexture[2].loadFromFile("assets/freeza/freeza3.png");
	FreezaTexture[3].loadFromFile("assets/freeza/freeza4.png");
	FreezaTexture[4].loadFromFile("assets/freeza/freeza5.png");
	FreezaTexture[5].loadFromFile("assets/freeza/freeza6.png");
	FreezaTexture[6].loadFromFile("assets/freeza/freeza7.png");
	FreezaTexture[7].loadFromFile("assets/freeza/freeza8.png");
	for (int i = 0; i < 8; i++)
	{
		temp[i] = FreezaTexture[i];
	}
}