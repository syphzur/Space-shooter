#pragma once
#include "destroyableobject.h"
#include "player.h"

#define bonusToPlayerDestroyPosition_X 0

class bonusToPlayer : public destroyableObject
{
public:
	bonusToPlayer() = delete;
	bonusToPlayer(const sf::Texture & texture);
	virtual void addBonusToPlayer(Player & player) = 0;
	virtual ~bonusToPlayer() = default;
	void update();
};

