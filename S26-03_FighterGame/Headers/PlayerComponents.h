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
    int screenwidth = 1280;
    int screenheight = 720;

    void Movement();
    void ScreenBounds(int screenwidth);
};

class jumping
{
public:
    Players* player = nullptr;
    bool isjumping = false;
    float startY = 0;
    float VelocityY = 0;
    float gravity = 2000.f;
    float jumpStrength = -1165.f;
    float jumpHeight = 1000.f;

    void jump();
    void Updatejump();
};
class Stagger
{
public:
    Players* player = nullptr;

    bool isStaggered = false;
    float currentStaggerTime = 0.0f;

    float damageTakenInWindow = 0.0f;
    sf::Clock damageWindowClock;
    sf::Clock staggerAnimationClock;

    const float StaggerWindow = 5.0f;
    const float DamageToStagger = 20.0f;
    const float StaggerDuration = 3.0f;

    float staggerTime = 0.0f;
    sf::Clock staggerclock;

    void AddDamage(float damage);
    void UpdateStagger(float dt);
    void TriggerStagger();
    void ResetStagger();
    void UpdateStaggerAnimation();

    bool GetIsStaggered() const { return isStaggered; }
    float GetStaggerTimeRemaining() const { return currentStaggerTime; }

    Stagger();
};
class animations
{
public:
    Players* player = nullptr;
    int IdleFrames = 0;
    int MovementFrames = 0;
    int StaggerFrames = 0;
    int HeavyAttackFrames = 0;
    int BeamFrames = 0;
    int RangedFrames = 0;

    void IdleAnimation();
    void MovementAnimation();
	void StaggerAnimation();
    void HeavyAttackAnimation();
    void BeamAnimation();
	void EndBeamAnimation();
    void RangedAttackAnimation();

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

