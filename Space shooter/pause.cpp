#include "pause.h"



Pause::Pause(const sf::Texture& texture, const sf::Font& font, const sf::SoundBuffer& buffer)
{
	sprite.setTexture(texture);
	textureResX = texture.getSize().x;
	textureResY = texture.getSize().y;
	sprite.setOrigin(this->textureResX / 2.f, this->textureResY / 2.f);
	sprite.setPosition(res_X / 2.f, res_Y / 2.f);
	sprite.setScale(2.0f, 2.0f);
	text.setFont(font);
	text.setFillColor(sf::Color::Yellow);
	text.setString("Pause");
	text.setCharacterSize(50);
	text.setOrigin((text.getGlobalBounds().width / 2.f), (text.getGlobalBounds().height / 2.f));
	text.setPosition(res_X / 2.f, res_Y / 2.f - 200.0f);
	sound.setBuffer(buffer);
}

void Pause::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(this->sprite, state);
	target.draw(this->text, state);
}

void Pause::playSound()
{
	this->sound.play();
}