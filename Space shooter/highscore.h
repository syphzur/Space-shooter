#pragma once
#include "gameData.h"

class highScore: public sf::Drawable
{
private:
	sf::Text text[numberOfRowsInHighscore];
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
public:
	highScore() = delete;
	highScore(const sf::Font& font, const std::vector<std::pair<std::string, unsigned int>>& scoreVec);
	~highScore() = default;
};

