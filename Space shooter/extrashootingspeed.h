#pragma once
#include "bonus.h"

class extraShootingSpeed : public Bonus
{
private:
	unsigned int extraSpeed = _extraSpeed;
public:
	extraShootingSpeed() = delete;
	extraShootingSpeed(const sf::Texture& texture, float t_X, float t_Y);
	~extraShootingSpeed() = default;
	void addBonus(Player& player);
};

