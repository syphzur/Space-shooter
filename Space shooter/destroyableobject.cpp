#include "destroyableobject.h"

destroyableObject::destroyableObject(const sf::Texture & texture): Object(texture) {}

bool destroyableObject::isDestroyed()
{
	return this->destroyed;
}

void destroyableObject::destroy()
{
	this->destroyed = true;
}

