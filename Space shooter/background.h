#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Background: public sf::Drawable
{
private:
	sf::Sprite sprite; // reprezentacja tekstury
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
public:
	Background() = delete;
	Background(const sf::Texture & backgroundTexture);
	~Background() = default;
};

