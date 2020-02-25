#include "explosion.h"

Explosion::Explosion(const sf::Texture & texture, const sf::SoundBuffer& buffer, float t_X, float t_Y) : destroyableObject(texture)
{
	rect.height = explosionImageSize_Y;
	rect.width = explosionImageSize_X;
	sprite.setTextureRect(rect);
	sprite.setOrigin(explosionImageSize_X / 2.f, explosionImageSize_Y / 2.f);
	sprite.setPosition(t_X, t_Y);
	oneFrameTime = explosionOneFrameTime;
	sprite.setScale(explosionScale, explosionScale);
	imageCount = { explosionImageCount_X, explosionImageCount_Y };
	velocity = 0;
	velocityVector = { 0, 0 };
	sound.setBuffer(buffer);
	sound.play();
}

void Explosion::update() // animacja
{
  	totalTime++;
	if (totalTime >= oneFrameTime)
	{
		totalTime = 0;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
			currentImage.y++;
			if (currentImage.y >= imageCount.y)
			{
				destroy();
			}
		}
	}
	rect.top = currentImage.y * rect.height;
	rect.left = currentImage.x * rect.width;
	sprite.setTextureRect(rect);
}

