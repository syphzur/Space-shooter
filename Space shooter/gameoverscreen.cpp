#include "gameoverscreen.h"



GameOverScreen::GameOverScreen(const sf::Font & font, int scoreNumber, const sf::SoundBuffer& gameoverSoundBuffer, const sf::SoundBuffer& typingSoundBuffer)
{
	for (auto& i : text)
	{
		i.setFont(font);
		i.setCharacterSize(40);
	}
	text[0].setString("GAME OVER");
	text[1].setString("Your score: " + std::to_string(scoreNumber));
	text[2].setString("Enter your name below");
	text[0].setFillColor(sf::Color::Red);
	text[1].setFillColor(sf::Color::Red);
	text[2].setFillColor(sf::Color::Red);
	text[3].setFillColor(sf::Color::Yellow);
	text[0].setOrigin((text[0].getGlobalBounds().width / 2.f), (text[0].getGlobalBounds().height / 2.f));
	text[1].setOrigin((text[1].getGlobalBounds().width / 2.f), (text[1].getGlobalBounds().height / 2.f));
	text[2].setOrigin((text[2].getGlobalBounds().width / 2.f), (text[2].getGlobalBounds().height / 2.f));
	for (int i = 0; i < 4; i++)
	{
		text[i].setPosition(static_cast<float>(res_X) / 2.f, static_cast<float>(res_Y / (numberOfItemsInMenu + 2) * (i + 1)));
	}
	gameOverSound.setBuffer(gameoverSoundBuffer);
	typingSound.setBuffer(typingSoundBuffer);
	gameOverSound.play();
}

void GameOverScreen::update(char c, bool add) // add jest true jeœli gracz doda³ symbol, false jeœli usun¹³ 
{
	if (add)
	{
		if (text[numberOfRowsInHelp - 1].getString().getSize() <= maxNameLength)
			text[numberOfRowsInHelp - 1].setString(text[numberOfRowsInHelp - 1].getString() + c);
	}
	else if (text[numberOfRowsInHelp - 1].getString().getSize() > 0)
	{
		std::string tmp = text[numberOfRowsInHelp - 1].getString();
		tmp.erase(tmp.size() - 1);
		text[numberOfRowsInHelp - 1].setString(tmp);
	}
	text[numberOfRowsInHelp - 1].setOrigin((text[numberOfRowsInHelp - 1].getGlobalBounds().width / 2.f), (text[numberOfRowsInHelp - 1].getGlobalBounds().height / 2.f));
	typingSound.play();
}



void GameOverScreen::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	for (int i = 0; i < numberOfRowsInHelp; i++)
	{
		target.draw(this->text[i], state);
	}
}

std::string GameOverScreen::getName()
{
	return text[3].getString();
}
