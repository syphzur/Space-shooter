#include "score.h"
#include <iostream>


Score::Score(const sf::Font & font, sf::Texture& texture, const sf::SoundBuffer& buffer)
{
	levelUpSound.setBuffer(buffer);
	scoreText.setFont(font);
	levelText.setFont(font);
	scoreText.setString("Score: " + std::to_string(this->score));
	levelText.setString("Level: " + std::to_string(this->level));
	scoreText.setCharacterSize(scoreCharacterSize);
	levelText.setCharacterSize(levelCharacterSize);
	scoreText.setOrigin((scoreText.getGlobalBounds().width / 2.f), (scoreText.getGlobalBounds().height / 2.f));
	levelText.setOrigin((levelText.getGlobalBounds().width / 2.f), (levelText.getGlobalBounds().height / 2.f));
	scoreText.setPosition(scoreTextPosition_X, scoreTextPosition_Y);
	levelText.setPosition(levelTextPosition_X, levelTextPosition_Y);
	levelText.setStyle(sf::Text::Bold);
	levelText.setFillColor(sf::Color::Green);
	texture.setRepeated(true);  //zapêtla teksturê
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(res_X), 20));
}

Score& Score::operator++() 
{ 
	score++;
	scoreText.setString("Score: " + std::to_string(this->score));
	if (score % 100 == 0)
	{
		level++;
		levelText.setString("Level: " + std::to_string(this->level));
		levelUpSound.play();
	}
	return *this;
}

void Score::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->sprite, state);
	target.draw(this->scoreText, state);
	target.draw(this->levelText, state);
}

unsigned int Score::getScore()
{
	return this->score;
}

unsigned int Score::getLevel()
{
	return this->level;
}

void Score::saveScore(std::vector<std::pair<std::string, unsigned int>>& scoreVec, const std::string& _name)
{
	std::ifstream fileIn;
	std::ofstream fileOut;
	int scoreNumber = getScore();
	std::string name = _name;
	scoreVec.push_back(make_pair(name, scoreNumber));
	fileIn.open("score.score");
	while (fileIn >> name)
	{
		fileIn >> scoreNumber;
		scoreVec.push_back(make_pair(name, scoreNumber));
	}
	fileIn.close();
	fileOut.open(OutFilePath, std::ios::trunc);
	sort(scoreVec.begin(), scoreVec.end(), [](std::pair<std::string, int> pair1, std::pair<std::string, int> pair2) {  return pair1.second > pair2.second; });
	while (scoreVec.size() > 5)
	{
		scoreVec.pop_back();
	}
	for (auto& scorePair : scoreVec)
	{
		if (scorePair.first.length() == 0)
		{
			fileOut << "Anonymous";
		}
		else
		{
			fileOut << scorePair.first;
		}
		fileOut << " ";
		fileOut << scorePair.second << std::endl;
	}
	fileOut.close();
}