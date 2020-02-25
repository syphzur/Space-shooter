#pragma once
#include "destroyableobject.h"
#include <iostream>

class Explosion : public destroyableObject
{
private:
	sf::Sound sound;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage = {0, 0};
	sf::IntRect rect;
	unsigned int totalTime = 0;
	unsigned int oneFrameTime;
public:
	Explosion() = delete;
	Explosion(const sf::Texture& texture, const sf::SoundBuffer& buffer, float t_X, float t_Y);
	~Explosion() = default;
	void update();
};

