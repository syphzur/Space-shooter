#pragma once
#include "gameData.h"

class Object: public sf::Drawable
{
protected:
	sf::Sprite sprite;
	sf::Vector2f velocityVector;
	unsigned int textureResX, textureResY; //rozmiar tekstury
	float velocity;
private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
public:
	Object() = delete;
	Object(const sf::Texture& texture);
	virtual ~Object() = default;
	sf::FloatRect getPosition();
	float left();
	float right();
	float top();
	float bottom();
};

