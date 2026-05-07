#include "sfml.h"
void Loadtextures::LoadTexture(std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&){}
void Loadtextures::SetCharacterTexture()
{
	int choice;
	std::cout << "Choose your character: " << std::endl;
	std::cin >> choice;
	if(choice == 1)
	{

		trunks::LoadTexture(HeavyAttackTextures,IdleTextures,MovementTextures,StaggerTextures,BeamTextures, RangedTexture, BasicAttackTexture);
		characterName = "Trunks";
	}
	else if(choice == 2)
	{
		goku::LoadTexture(HeavyAttackTextures, IdleTextures, MovementTextures, StaggerTextures, BeamTextures, RangedTexture, BasicAttackTexture);
		characterName = "Goku";
	}
	else if (choice == 3)
	{
		freeza::LoadTexture(HeavyAttackTextures, IdleTextures, MovementTextures, StaggerTextures, BeamTextures, RangedTexture, BasicAttackTexture);
		characterName = "Freeza";
	}

	else if (choice == 4)
	{
		trunks::LoadTexture(HeavyAttackTextures, IdleTextures, MovementTextures, StaggerTextures, BeamTextures, RangedTexture, BasicAttackTexture);
		characterName = "trunks";
	}
	else if (choice == 5)
	{
		broly::LoadTexture(HeavyAttackTextures, IdleTextures, MovementTextures, StaggerTextures, BeamTextures, RangedTexture, BasicAttackTexture);
		characterName = "trunks";
	}
}