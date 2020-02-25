#include "heart.h"

Heart::Heart(const sf::Texture & texture, float t_X, float t_Y): Object(texture)
{
	this->sprite.setPosition(t_X, t_Y);
}
