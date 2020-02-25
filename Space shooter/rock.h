#pragma once
#include "destroyableobject.h"
#include "functions.h"
#include "bullet.h"
#include "bonus.h"

class Rock: public destroyableObject
{
public:
	Rock() = delete;
	Rock(const sf::Texture & texture, float t_X, float t_Y, unsigned int level);
	~Rock() = default;
	void update();
	bool collisionTest(Rock& rock1);
	bool collisionTest(Bullet& bullet);
	bool collisionTest(Bonus& bonus);
	bool collisionTest(Player& player);
};

