#include "rock.h"

Rock::Rock(const sf::Texture & texture, float t_X, float t_Y, unsigned int level): destroyableObject(texture)
{
	velocity = rockVelocity_X + level;
	velocityVector = { -velocity, random_float(-maxRockVelocity_Y, maxRockVelocity_Y) };
	sprite.setPosition(t_X, t_Y);
	sprite.setRotation(random_float(0.f, 360.f));
}

void Rock::update()
{
	sprite.rotate(rockRotation);
	sprite.move(this->velocityVector);
	if (right() < rockDestroyPosition_X)
	{
		destroy();
	}
}

bool Rock::collisionTest(Bullet& bullet)
{
	if (this->getPosition().intersects(bullet.getPosition()))
	{
		bullet.destroy();
		destroy();
		return true;
	}
	else
		return false;
}

bool Rock::collisionTest(Rock& rock1)
{
	if (this->getPosition().intersects(rock1.getPosition()))
	{
		rock1.destroy();
		destroy();
		return true;
	}
	else
		return false;
}

bool Rock::collisionTest(Bonus& bonus)
{
	if (this->getPosition().intersects(bonus.getPosition()))
	{
		bonus.destroy();
		destroy();
		return true;
	}
	else
		return false;
}

bool Rock::collisionTest(Player& player)
{
	if (this->getPosition().intersects(player.getPosition()))
	{
		destroy();
		player.collision();
		return true;
	}
	else
		return false;
}
