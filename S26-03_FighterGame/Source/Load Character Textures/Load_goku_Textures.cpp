#include "sfml.h"
void goku :: LoadTexture(sf::Texture* temp)
{
	GokuTexture[0].loadFromFile("assets/goku/goku Idle1.png");
	GokuTexture[1].loadFromFile("assets/goku/goku Idle2.png");
	GokuTexture[2].loadFromFile("assets/goku/goku Idle3.png");
	GokuTexture[3].loadFromFile("assets/goku/goku Idle4.png");
	GokuTexture[4].loadFromFile("assets/goku/goku Movement1.png");
	GokuTexture[5].loadFromFile("assets/goku/goku Movement2.png");
	GokuTexture[6].loadFromFile("assets/goku/goku Movement3.png");
	GokuTexture[7].loadFromFile("assets/goku/goku Movement4.png");
	for(int i = 0; i < 8; i++)
	{
		temp[i] = GokuTexture[i];
	}
}