#pragma once
#include "gameData.h"

class Menu : public sf::Drawable
{
private:
	sf::Sound movingSound;
	int selectedItem = 0;
	sf::Text menu[numberOfItemsInMenu];
	sf::Text help[numberOfRowsInHelp];
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
public:
	Menu() = delete;
	Menu(const sf::Font& font, const sf::SoundBuffer& movingSoundBuffer);
	~Menu() = default;
	void moveUp();
	void moveDown();
	unsigned int getSelectedItem();
	sf::Text getHelp(unsigned int row);
};

