#pragma once
#include "gameData.h"

class GameOverScreen : public sf::Drawable
{
private:
	sf::Text text[4];
	sf::Sound gameOverSound;
	sf::Sound typingSound;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
public:
	GameOverScreen() = delete;
	GameOverScreen(const sf::Font& font, int scoreNumber, const sf::SoundBuffer& gameoverSoundBuffer, const sf::SoundBuffer& typingSound);
	~GameOverScreen() = default;
	void update(char c, bool add);
	std::string getName();
};

