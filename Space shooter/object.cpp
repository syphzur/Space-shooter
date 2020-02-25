#include "object.h"

Object::Object(const sf::Texture& texture)
{
	sprite.setTexture(texture);
	textureResX = texture.getSize().x;
	textureResY = texture.getSize().y;
	sprite.setOrigin(textureResX / 2.f, textureResY / 2.f);
}
sf::FloatRect Object::getPosition()
{
	return sprite.getGlobalBounds();
}
float Object::left()
{
	return sprite.getPosition().x - textureResX / 2.f;
}
float Object::right()
{
	return sprite.getPosition().x + textureResX / 2.f;
}
float Object::top()
{
	return sprite.getPosition().y - textureResY / 2.f;
}
float Object::bottom()
{
	return sprite.getPosition().y + textureResY / 2.f;
}

void Object::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(this->sprite, state);
}