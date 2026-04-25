//#include "sfml.h"
//void movement::Movement()
//{
//	player->IsMoving = false;
//	player->MovingRight = false;
//	player->MovingLeft = false;
//
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player->PlayerNumber == 1)
//		player->MovingRight = true;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player->PlayerNumber == 1)
//		player->MovingLeft = true;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player->PlayerNumber == 2)
//		player->MovingRight = true;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player->PlayerNumber == 2)
//		player->MovingLeft = true;
//
//	float direction = 0.f;
//	bool collision = false;
//	if (player->MovingRight) direction = 1.f;
//	if (player->MovingLeft) direction = -1.f;
//	if (player->MoveCollision())
//	{
//		collision = true;
//	}
//
//	if (player->MovingRight && collision)
//	{
//		player->RightCollison = true;
//	}
//	else if (player->MovingLeft && collision)
//	{
//		player->LeftCollision = true;
//	}
//	if (direction != 0.f && !collision) {
//		player->Sprite.move(direction * VelocityX * dt, 0.f);
//		player->IsMoving = true;
//	}else{
//
//		if(player->RightCollison && player->MovingLeft)
//		{
//			player->Sprite.move(direction * VelocityX * dt, 0.f);
//			player->IsMoving = true;
//			player->RightCollison = false;
//		}
//		if (player->LeftCollision && player->MovingRight)
//		{
//			player->Sprite.move(direction * VelocityX * dt, 0.f);
//			player->IsMoving = true;
//			player->LeftCollision = false;
//		}
//	}
//}
#include "sfml.h"
void movement::Movement()
{
    player->MovingRight = false;
    player->MovingLeft = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player->PlayerNumber == 1)
        player->MovingRight = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player->PlayerNumber == 1)
        player->MovingLeft = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player->PlayerNumber == 2)
        player->MovingRight = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player->PlayerNumber == 2)
        player->MovingLeft = true;

    if (player->MovingRight || player->MovingLeft)
    {
        player->IsMoving = true;
    }
    else player->IsMoving = false;
    float direction = 0.f;
    if (player->MovingRight) direction = 1.f;
    if (player->MovingLeft) direction = -1.f;

    if (direction != 0.f) {
        float oldX = player->Sprite.getPosition().x;

        player->Sprite.move(direction * VelocityX * dt, 0.f);

        if (player->MoveCollision()) {
            player->Sprite.setPosition(oldX, player->Sprite.getPosition().y);
            if (direction > 0) {
                player->RightCollison = true;
            }
            else {
                player->LeftCollision = true;
            }
        }
        else {
            player->RightCollison = false;
            player->LeftCollision = false;
        }
    }
}