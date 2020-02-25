#include "menu.h"

Menu::Menu(const sf::Font& font, const sf::SoundBuffer& movingSoundBuffer)
{
	menu[0].setFillColor(sf::Color::Yellow);
	menu[1].setFillColor(sf::Color::White);
	menu[2].setFillColor(sf::Color::White);
	menu[0].setString("Play");
	menu[1].setString("Help");
	menu[2].setString("Exit");
	help[0].setString("Destroy all rocks and get the highest score!");
	help[1].setString("Pause the game with ESC.");
	help[2].setString("Shoot with space and move with arrows.");
	help[3].setString("Press ESC to return to the menu.");
	for (int i = 0; i < numberOfItemsInMenu; i++)
	{
		menu[i].setFont(font);
		menu[i].setOrigin((menu[i].getGlobalBounds().width / 2.f), (menu[i].getGlobalBounds().height / 2.f));
		menu[i].setPosition(static_cast<float>(res_X) / 2.f, static_cast<float>(res_Y / (numberOfItemsInMenu + 1) * (i + 1)));
	}
	for (unsigned int i = 0; i < numberOfRowsInHelp; i++)
	{
		help[i].setFont(font);
		help[i].setFillColor(sf::Color::Red);
		help[i].setOrigin((help[i].getGlobalBounds().width / 2.f), (help[i].getGlobalBounds().height / 2.f));
		help[i].setPosition(static_cast<float>(res_X) / 2.f, static_cast<float>(res_Y / (numberOfRowsInHelp + 1) * (i + 1)));
	}
	this->movingSound.setBuffer(movingSoundBuffer);
}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	for (int i = 0; i < numberOfItemsInMenu; i++)
	{
		target.draw(this->menu[i], state);
	}
}

void Menu::moveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		menu[selectedItem].setFillColor(sf::Color::Yellow);
		movingSound.play();
	}
}

void Menu::moveDown()
{
	if (selectedItem + 1 < numberOfItemsInMenu)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		menu[selectedItem].setFillColor(sf::Color::Yellow);
		movingSound.play();
	}
}

unsigned int Menu::getSelectedItem()
{
	return this->selectedItem;
}

sf::Text Menu::getHelp(unsigned int row)
{
	return this->help[row];
}