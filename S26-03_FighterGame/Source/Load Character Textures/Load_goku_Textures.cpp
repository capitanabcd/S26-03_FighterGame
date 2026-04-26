#include "sfml.h"
void goku :: LoadTexture(sf::Texture* temp, sf::Texture* heavy, sf::Texture* stagger)
{
	
	GokuTexture[0].loadFromFile("assets/goku/goku Idle1.png");
	GokuTexture[1].loadFromFile("assets/goku/goku Idle2.png");
	GokuTexture[2].loadFromFile("assets/goku/goku Idle3.png");
	GokuTexture[3].loadFromFile("assets/goku/goku Idle4.png");
	GokuTexture[4].loadFromFile("assets/goku/goku Movement1.png");
	GokuTexture[5].loadFromFile("assets/goku/goku Movement2.png");
	GokuTexture[6].loadFromFile("assets/goku/goku Movement3.png");
	GokuTexture[7].loadFromFile("assets/goku/goku Movement4.png");
	GokuHeavyAttack[0].loadFromFile("assets/goku/goku HeavyAttack1.png");
	GokuHeavyAttack[1].loadFromFile("assets/goku/goku HeavyAttack2.png");
	GokuHeavyAttack[2].loadFromFile("assets/goku/goku HeavyAttack3.png");
	GokuHeavyAttack[3].loadFromFile("assets/goku/goku HeavyAttack4.png");
	GokuHeavyAttack[4].loadFromFile("assets/goku/goku HeavyAttack5.png");
	GokuHeavyAttack[5].loadFromFile("assets/goku/goku HeavyAttack6.png");
	GokuHeavyAttack[6].loadFromFile("assets/goku/goku HeavyAttack7.png");
	GokuHeavyAttack[7].loadFromFile("assets/goku/goku HeavyAttack8.png");
	GokuHeavyAttack[8].loadFromFile("assets/goku/goku HeavyAttack9.png");
	GokuHeavyAttack[9].loadFromFile("assets/goku/goku HeavyAttack10.png");
	GokuHeavyAttack[10].loadFromFile("assets/goku/goku HeavyAttack11.png");
	GokuHeavyAttack[11].loadFromFile("assets/goku/goku HeavyAttack12.png");
	GokuHeavyAttack[12].loadFromFile("assets/goku/goku HeavyAttack13.png");

	for(int i = 0; i < 8; i++)
	{
		temp[i] = GokuTexture[i];
	}
	for (int i = 0; i <13; i++) {
		heavy[i] = GokuHeavyAttack[i];
	}
}