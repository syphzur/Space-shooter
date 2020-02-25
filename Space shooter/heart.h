#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "object.h"

class Heart : public Object
{
public:
	Heart() = delete;
	Heart(const sf::Texture& texture, float t_X, float t_Y);
	~Heart() = default;
};

