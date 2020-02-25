#pragma once
#include "Bonus.h"

class extraHealth : public Bonus
{
private:
	unsigned int extraHP = _extraHP;
public:
	extraHealth() = delete;
	extraHealth(const sf::Texture& texture, float t_X, float t_Y);
	~extraHealth() = default;
	void addBonus(Player& player);
};

