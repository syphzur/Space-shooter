#include "highscore.h"


highScore::highScore(const sf::Font & font, const std::vector<std::pair<std::string, unsigned int>>& scoreVec)
{
	text[0].setFont(font);
	text[0].setCharacterSize(highscoreCharacterSize);
	text[0].setFillColor(sf::Color::Green);
	text[0].setString("Highscore:");
	text[0].setOrigin((text[0].getGlobalBounds().width / 2.f), (text[0].getGlobalBounds().height / 2.f));
	text[0].setPosition(res_X / 2.f, res_Y / (numberOfRowsInHighscore + 1) * 1.f);
	for (unsigned int i = 1; i < scoreVec.size() + 1; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(highscoreCharacterSize);
		text[i].setFillColor(sf::Color::Green);
		text[i].setString(scoreVec[i - 1].first + " " + std::to_string(scoreVec[i - 1].second));
		text[i].setOrigin((text[i].getGlobalBounds().width / 2.f), (text[i].getGlobalBounds().height / 2.f));
		text[i].setPosition(static_cast<float>(res_X) / 2.f, static_cast<float>(res_Y / (numberOfRowsInHighscore + 1) * (i + 1)));
	}
}

void highScore::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	for (unsigned int i = 0; i < numberOfRowsInHighscore; i++)
	{
		target.draw(this->text[i], state);
	}
}

