#include "bonus.h"

Bonus::Bonus(const sf::Texture& texture, float t_X, float t_Y) : destroyableObject(texture)
{ 
	sprite.setPosition(t_X, t_Y);
	velocity = bonusVelocity;
	velocityVector = { -velocity, 0 }; //bonus porusza siê tylko w lewo
}

void Bonus::update()
{
	sprite.move(velocityVector);
	if (right() < leftSideDestroyPosition_X)
	{
		destroy();
	}
}

bool Bonus::collisionTest(Player& player)
{
	if (sprite.getGlobalBounds().intersects(player.getPosition())) // sprawdza czy obrysy nachodz¹ na siebie
	{
		addBonus(player);
		destroy();
		return true;
	}
	else
		return false;
}
