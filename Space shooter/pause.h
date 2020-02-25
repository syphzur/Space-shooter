#pragma once
#include "object.h"

class Pause : public sf::Drawable
{
private:
	sf::Sprite sprite;
	sf::Text text;
	sf::Sound sound;
	unsigned int textureResX, textureResY; //rozmiar tekstury
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
public:
	Pause() = delete;
	Pause(const sf::Texture& texture, const sf::Font& font, const sf::SoundBuffer& buffer);
	~Pause() = default;
	void playSound();
};

