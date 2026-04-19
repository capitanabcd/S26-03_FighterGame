#include "sfml.h"
void goku :: LoadTexture(sf::Texture* temp)
{
	GokuTexture[0].loadFromFile("assets/goku/goku1.png");
	GokuTexture[1].loadFromFile("assets/goku/goku2.png");
	GokuTexture[2].loadFromFile("assets/goku/goku3.png");
	GokuTexture[3].loadFromFile("assets/goku/goku4.png");
	GokuTexture[4].loadFromFile("assets/goku/goku5.png");
	GokuTexture[5].loadFromFile("assets/goku/goku6.png");
	GokuTexture[6].loadFromFile("assets/goku/goku7.png");
	GokuTexture[7].loadFromFile("assets/goku/goku8.png");
	for(int i = 0; i < 8; i++)
	{
		temp[i] = GokuTexture[i];
	}
}