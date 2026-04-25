#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

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
    bool RightCollison = false;
    bool LeftCollision = false;

    void Movement();
};

class jumping
{
public:
    Players* player = nullptr;
    bool isjumping = false;
    float startY = 0;
    float VelocityY = 0;
    float gravity = 2000.f;
    float jumpStrength = -1000.f;
    float jumpHeight = 1000.f;

    void jump();
    void Updatejump();
};

class animations
{
public:
    Players* player = nullptr;
    int IdleFrames = 0;
    int MovementFrames = 4;
    float staggerTime = 0.0f;

    void IdleAnimation();
    void MovementAnimation();
    void invert();
    void RevertOrigin();
};

class collide
{
public:
    Players* player = nullptr;
    sf::FloatRect Player1Bounds;
    sf::FloatRect Player2Bounds;

    bool MoveCollision();
    void setbounds();
};