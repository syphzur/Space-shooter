#include "bonustoplayer.h"

bonusToPlayer::bonusToPlayer(const sf::Texture & texture) : destroyableObject(texture) {}

void bonusToPlayer::update()
{
	this->sprite.move(this->velocityVector);
	if (this->right() < bonusToPlayerDestroyPosition_X)
	{
		this->destroy();
	}
}
