#include "bullet.h"

Bullet::Bullet(const sf::Texture & texture, float t_X, float t_Y): destroyableObject(texture)
{
	sprite.setPosition(t_X, t_Y);
	velocity = bulletVelocity;
	velocityVector = { this->velocity, 0 }; // pociski poruszaj¹ siê tylko w lewo
}

void Bullet::update()
{
	sprite.move(velocityVector);
	if (left() > rightSideDestroyPosition_X)
	{
		destroy();
	}
}