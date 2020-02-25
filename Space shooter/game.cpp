#include "game.h"

Game::Game(): objectManager(rManager)
{
	window.create(sf::VideoMode(res_X, res_Y), "2D Space shooter");
	window.setFramerateLimit(FramerateLimit);
}

void Game::mainLoop(sf::Event& event)
{
	rManager.getMusic(MusicPath).play();
	Background background(rManager.getTexture(BackgroundTexturePath));
	Player player(rManager.getTexture(PlayerTexturePath), rManager.getSound(PlayerShootingSound), rManager.getSound(PowerUpSoundPath),
		playerSpawnPosition_X, playerSpawnPosition_Y);
	Score score(rManager.getFont(FontPath), rManager.getTexture(MetalTexturePath), rManager.getSound(LevelUpSoundPath));
	Pause pauseIcon(rManager.getTexture(PauseTexturePath), rManager.getFont(FontPath), rManager.getSound(PauseSoundPath));
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape && !pause)
			{
				pause = true;
				pauseIcon.playSound();
			}
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape && pause)
			{
				pause = false;
				pauseIcon.playSound();
			}
		}
		window.clear();
		if (!pause)
		{
			objectManager.testCollisions(player, score);
			objectManager.update(player, score);
			if (objectManager.getHPbar().size() == 0)
			{
				gameOver(score, event);
			}
		}
		drawObjects(player, score, background, pauseIcon);
		window.display();
	}
}


void Game::drawObjects(const Player& player, const Score& score, const Background& background, const Pause& pauseIcon)
{
	//background
	window.draw(background);
	//rocks
	for (auto& rock : objectManager.getRocks())
	{
		window.draw(*rock);
	}
	//bullets
	for (auto& bullet : objectManager.getBullets())
	{
		window.draw(*bullet);
	}
	//extraHealth
	for (auto& bonus : objectManager.getBonuses())
	{
		window.draw(*bonus);
	}
	//explosions
	for (auto& explosion : objectManager.getExplosions())
	{
		window.draw(*explosion);
	}
	//player
	window.draw(player);
	//score
	window.draw(score);
	//hpbar
	for (auto& heart : objectManager.getHPbar())
	{
		window.draw(*heart);
	}
	//pause
	if (pause)
	{
		window.draw(pauseIcon);
	}
}

void Game::menu()
{
	sf::Event event;
	bool help = false;
	rManager.getMusic(MenuMusicSoundPath).play();
	Menu menu(rManager.getFont(FontPath), rManager.getSound(MenuMovingSoundPath));
	Background background(rManager.getTexture(MenuBackgroundTexturePath));
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
				{
					help = false;
					break;
				}
				case sf::Keyboard::Up:
				{
					menu.moveUp();
					break;
				}
				case sf::Keyboard::Down:
				{
					menu.moveDown();
					break;
				}
				case sf::Keyboard::Return:
				{
					if (menu.getSelectedItem() == 0)
					{
						rManager.getMusic(MenuMusicSoundPath).stop();
						mainLoop(event);
					}
					else if (menu.getSelectedItem() == 1)
					{
						help = true;
					}
					else if (menu.getSelectedItem() == 2)
					{
						rManager.getMusic(MenuMusicSoundPath).stop();
						event.type = sf::Event::Closed;
					}
					break;
				}
				}
			}
		}
		window.clear();
		window.draw(background);
		if(help)
		{ 
			for (unsigned int i = 0; i < numberOfRowsInHelp; i++)
			{
				window.draw(menu.getHelp(i));
			}
		}
		else
		{
			window.draw(menu);
		}
		window.display();
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Game::gameOver(Score& score, sf::Event& event)
{
	std::vector<std::pair<std::string, unsigned int>> scoreVec;
	score.saveScore(scoreVec, getName(score.getScore(), event));
	viewHighscore(scoreVec, event);
}

std::string Game::getName(unsigned int scoreNumber, sf::Event& event) // funkcja w której gracz wpisuje swoje imie
{
	GameOverScreen gameoverscreen(rManager.getFont(FontPath), scoreNumber, rManager.getSound(GameOverSoundPath), rManager.getSound(TypingSoundPath));
	bool nameReady = false; // true jeœli ju¿ wpisa³ 
	while (window.isOpen() && !nameReady)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode <= 126 && event.text.unicode >= 32) // zakres pobieranych znaków
				{
					char tmp = static_cast<char>(event.text.unicode);
					gameoverscreen.update(tmp, true);
				}
				else if (event.text.unicode == 8) // backspace
				{
					gameoverscreen.update(0, false);
				}
			}
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) // return == enter 
			{
				nameReady = true;
			}
			else if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		window.draw(gameoverscreen);
		window.display();
	}
	return gameoverscreen.getName();
}

void Game::viewHighscore(const std::vector<std::pair<std::string, unsigned int>>& scoreVec, sf::Event& event) // 1 parametr to wektor par punktów i imion 
{
	highScore highscore(rManager.getFont(FontPath), scoreVec);
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(highscore);
		window.display();
	}
}
