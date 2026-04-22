#include "characters.h"
#pragma once

const int ground = 720;
extern float dt;
void DeltaTime();
void resize();
class Players;

class movement
{
	public:
	Players* player = nullptr;
	bool MovingRight = false;
	bool MovingLeft = false;
	float VelocityX = 500.f;
	bool IsMoving = false;
	
	void Movement();
};


class jumping
{
	public:
	Players* player = nullptr;
	bool isjumping = false;
	int startY = 0;
	float VelocityY = 0;
	float gravity = 2000.f;
	float jumpStrength = -1000.f;
	float jumpHeight = 1000.f;
	void jump();
	void Updatejump();
};

class attack {
public:
	Players* player = nullptr;
	bool isattacking = false;
	bool hitTaken = false;
	
	void punch();

};

class animations
{
	public:
		Players* player = nullptr;
		int IdleFrames = 0;
		int MovementFrames = 4;
		int StaggerFrames = 8;
		float staggerTime = 0.0f;
		void IdleAnimation();
		void MovementAnimation();
		void stagger();
};

class Loadtextures :public cell, public goku, public freeza
{
	public:
	sf::Texture Textures[8];
	void LoadTexture(sf::Texture* temp) override;
	void SetCharacterTexture();
	Loadtextures()
	{
		SetCharacterTexture();
	}
};
class collide {

public:
	Players* player = nullptr;
	sf::FloatRect Player1Bounds;
	sf::FloatRect Player2Bounds;
	bool MoveCollision();
	void setbounds();

};

class Players : public movement,public jumping , public animations, public attack, public collide
{
	public:
	int PlayerNumber;
	int x;
	int y;
	sf::Clock clock;
	sf::Texture PlayerTexture[8];
	sf::Sprite Sprite;
	Players()
	{
		movement::player = this;
		jumping::player = this;
		animations::player = this;
		attack::player = this;
		static int nextPlayerNumber = 1;
		PlayerNumber = nextPlayerNumber;
		nextPlayerNumber++;
		clock.restart();
		Loadtextures ChosenTexture;
		for (int i = 0; i < 8; i++)
		{
			PlayerTexture[i] = ChosenTexture.Textures[i];
		}
		x = 100;
		Sprite.setTexture(PlayerTexture[0]);
		Sprite.setScale(3.f, 3.f);
		y = ground - Sprite.getGlobalBounds().height;
		if (PlayerNumber == 1)
		{
			Sprite.setPosition(x, y);
		}
		if (PlayerNumber == 2)
		{
			Sprite.setPosition(x + 400, y);
		}
	}
};

extern Players player1;
extern Players player2;