#include "sfml.h"

void cell::LoadTexture(sf::Texture* temp)
{
	CellTexture[0].loadFromFile("assets/cell/cell1.png");
	CellTexture[1].loadFromFile("assets/cell/cell2.png");
	CellTexture[2].loadFromFile("assets/cell/cell3.png");
	CellTexture[3].loadFromFile("assets/cell/cell4.png");
	CellTexture[4].loadFromFile("assets/cell/cell1.png");
	CellTexture[5].loadFromFile("assets/cell/cell2.png");
	CellTexture[6].loadFromFile("assets/cell/cell3.png");
	CellTexture[7].loadFromFile("assets/cell/cell4.png");
	for(int i = 0; i < 8; i++)
	{
		temp[i] = CellTexture[i];
	}
}