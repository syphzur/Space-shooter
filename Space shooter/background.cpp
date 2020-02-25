#include "background.h"

void Background::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(this->sprite, state);
}

Background::Background(const sf::Texture & backgroundTexture)
{
	sprite.setTexture(backgroundTexture);
}