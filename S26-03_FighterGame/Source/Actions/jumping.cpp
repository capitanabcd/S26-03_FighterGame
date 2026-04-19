#include "sfml.h"

void jumping::jump()
{
	if (!isjumping)
	{
		isjumping = true;
		startY = player->Sprite.getPosition().y;
		VelocityY = jumpStrength;
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