#include "sfml.h"

void jumping::jump()
{	
	player->staggerTime -= dt;
	if (player->staggerTime <= 0) {
		if (!isjumping)
		{
			isjumping = true;
			startY = player->Sprite.getPosition().y;
			VelocityY = jumpStrength;
		}
	}
}
void jumping::Updatejump()
{
	if (isjumping)
	{
		VelocityY += gravity * dt;
		player->Sprite.move(0, VelocityY * dt);
		if (player->Sprite.getPosition().y <= startY - jumpHeight) {
			VelocityY = 0;
		}
	}
} 