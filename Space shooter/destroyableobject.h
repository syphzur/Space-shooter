#pragma once
#include "object.h"
#include "gameData.h"

class destroyableObject :public Object
{
private:
	bool destroyed = false;
public:
	destroyableObject() = delete;
	destroyableObject(const sf::Texture & texture);
	virtual ~destroyableObject() = default;
	virtual void update() = 0;
	void destroy();
	bool isDestroyed();
};

