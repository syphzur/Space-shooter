#pragma once
#include "player.h"
#include "bullet.h"
#include "heart.h"
#include "bonus.h"
#include "explosion.h"
#include "rock.h"
#include "score.h"
#include "resourcemanager.h"
#include "gameData.h"
#include "extrashootingspeed.h"
#include "extrahealth.h"
#include "functions.h"
#include <experimental/vector>


class objectManager
{
private:
	unsigned int rockSpawnTimer;
	unsigned int bonusSpawnTimer;
	unsigned int shootingTimer;
	resourceManager& rManager;
	std::vector<std::shared_ptr<Rock>> rocks;
	std::vector<std::shared_ptr<Bullet>> bullets;
	std::vector<std::shared_ptr<Heart>> HPbar;
	std::vector<std::shared_ptr<Bonus>> bonuses;
	std::vector<std::shared_ptr<Explosion>> explosions;
	void updateHPbar(Player& player);
	void updateRocks(Score& score);
	void updateBullets(Player& player);
	void updateBonuses();
	void updateExplosions();
	void boom(float t_X, float t_Y);
	const char * randomRockTexturePath();
public:
	objectManager(resourceManager& _rManager);
	~objectManager() = default;
	void testCollisions(Player& player, Score& score);
	void update(Player& player, Score& score);
	std::vector<std::shared_ptr<Rock>> getRocks();
	std::vector<std::shared_ptr<Bullet>> getBullets();
	std::vector<std::shared_ptr<Heart>> getHPbar();
	std::vector<std::shared_ptr<Bonus>> getBonuses();
	std::vector<std::shared_ptr<Explosion>> getExplosions();
};

