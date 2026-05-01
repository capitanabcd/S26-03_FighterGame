#include "sfml.h"
void Loadtextures::LoadTexture(std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&){}
void Loadtextures::SetCharacterTexture()
{
	int choice;
	std::cout << "Choose your character: " << std::endl;
	std::cin >> choice;
	if(choice == 1)
	{
		cell::LoadTexture(HeavyAttackTextures,IdleTextures,MovementTextures,StaggerTextures,BeamTextures);
	}
	else if(choice == 2)
	{
		goku::LoadTexture(HeavyAttackTextures, IdleTextures, MovementTextures, StaggerTextures, BeamTextures);
	}
	else if (choice == 3)
	{
		freeza::LoadTexture(HeavyAttackTextures, IdleTextures, MovementTextures, StaggerTextures, BeamTextures);
	}
}