#pragma once
#include "player.h"
#include "background.h"
#include "score.h"
#include "resourcemanager.h"
#include "functions.h"
#include "menu.h"
#include "pause.h"
#include "gameoverscreen.h"
#include "highscore.h"
#include "objectManager.h"
#include <fstream>

class Game
{
private:
	sf::RenderWindow window;
	resourceManager rManager; 
	objectManager objectManager;
	bool pause = false;
	void drawObjects(const Player& player, const Score& score, const Background& background, const Pause& pauseIcon);
	void mainLoop(sf::Event& event);
	void gameOver(Score& score, sf::Event& event);
	std::string getName(unsigned int scoreNumber, sf::Event& event);
	void viewHighscore(const std::vector<std::pair<std::string, unsigned int>>& scoreVec, sf::Event& event);
public:
	Game();
	~Game() = default;
	void menu();
};

