#include "sfml.h"
void Loadtextures::LoadTexture(sf::Texture* temp, sf::Texture* heavy){}
void Loadtextures::SetCharacterTexture()
{
	int choice;
	std::cout << "Choose your character: " << std::endl;
	std::cin >> choice;
	if(choice == 1)
	{
		cell::LoadTexture(Textures, HeavyAttackTexture);
	}
	else if(choice == 2)
	{
		goku::LoadTexture(Textures, HeavyAttackTexture);
	}
	else if (choice == 3)
	{
		freeza::LoadTexture(Textures, HeavyAttackTexture);
	}
}