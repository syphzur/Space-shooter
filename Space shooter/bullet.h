#pragma once
#include "destroyableobject.h"

class Bullet : public destroyableObject
{
public:
	Bullet() = delete;
	Bullet(const sf::Texture & texture, float t_X, float t_Y);
	~Bullet() = default;
	void update();
};

