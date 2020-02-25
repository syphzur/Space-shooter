#pragma once
#include "destroyableobject.h"
#include "Player.h"
#include "gameData.h"
#include "functions.h"

class Bonus :public destroyableObject
{
public:
	Bonus() = delete;
	Bonus(const sf::Texture& texture, float t_X, float t_Y);
	virtual ~Bonus() = default;
	virtual void update();
	virtual void addBonus(Player& player) = 0;
	bool collisionTest(Player& player); // sprawdza kolizje z graczem
};

