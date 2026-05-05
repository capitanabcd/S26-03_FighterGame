#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <filesystem>
#include <algorithm>
class SelectionScreen
{
public :
	bool isSelecting;
	int EnterFrames;
	int ArrowFrames;
	int SelectionFrames;
	int index;
	int frames;
	int selectingFor = 1;
	int player1Choice = -1;
	int player2Choice = -1;
	bool isEnterPlaying = false;
	std::vector <int> Characters = { 1,2,3 };
	std::vector <sf::Texture> C1;
	std::vector <sf::Texture> C2;
	std::vector <sf::Texture> C3;
	sf::Clock ArrowClock;
	sf::Clock EnterClock;
	sf::Clock SelectionClock;
	sf::Clock IdleCLock;
	sf::Sprite SelectionSprite;
	sf::Sprite Character;
	std::vector <sf::Texture> EnterTextures;
	std::vector <sf::Texture> OneTextures;
	std::vector <sf::Texture> TwoTextures;
	SelectionScreen();

	void loadSelectionScreen();
	void renderSelectionScreen(sf::RenderWindow& window);
	void UpdateSelectionScreen();
	void HandleInput(sf::Event& event);
	void NormalizeCharacter();
	void Load_IdleTextures();
};