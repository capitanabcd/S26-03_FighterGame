#include "Player.h"
void movement::Movement()
{
	if (player->hitTaken || player->isattacking) return;
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

    if (player->MovingRight || player->MovingLeft) { player->IsMoving = true; }
    else player->IsMoving = false;

    float direction = 0.f;
    if (player->MovingRight) direction = 1.f;
    if (player->MovingLeft) direction = -1.f;

    if (direction != 0.f) {
        float oldX = player->Sprite.getPosition().x;

        Players& other = (player->PlayerNumber == 1) ? player2 : player1;


        float newX = oldX + direction * VelocityX * dt;
        player->Sprite.setPosition(newX, player->Sprite.getPosition().y);

        bool movingToward = false;
        if (direction > 0 && newX < other.Sprite.getPosition().x) {
            movingToward = true; 
        }
        else if (direction < 0 && newX > other.Sprite.getPosition().x) {
            movingToward = true; 
        }

        if (movingToward && player->MoveCollision()) {
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
    ScreenBounds(screenwidth);
}