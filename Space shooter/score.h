#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "gameData.h"
#include <fstream>

class Score : public sf::Drawable
{
private: 
	sf::Sprite sprite;
	sf::Text scoreText;
	sf::Text levelText;
	sf::Sound levelUpSound;
	unsigned int score = 0;
	unsigned int level = 1;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
public:
	Score() = delete;
	Score(const sf::Font& font, sf::Texture& texture, const sf::SoundBuffer& buffer);
	~Score() = default;
	Score& operator ++(); // inkrementuje punkty
	unsigned int getScore();
	unsigned int getLevel();
	void saveScore(std::vector<std::pair<std::string, unsigned int>>& scoreVec, const std::string& name); // zapisuje wektor do pliku
};

