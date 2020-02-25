#include "objectManager.h"


objectManager::objectManager(resourceManager& _resourceManager): rManager(_resourceManager)
{
	rockSpawnTimer = _rockSpawnTimer;
	bonusSpawnTimer = _bonusSpawnTimer;
	shootingTimer = 0;
}


void objectManager::testCollisions(Player& player, Score& score)
{
	//kamienie z pociskami
	for (auto& bullet : bullets)
	{
		for (auto& rock : rocks)
		{
			if (rock->collisionTest(*bullet))
			{
				boom((rock->left() + rock->right()) / 2.f, (rock->top() + rock->bottom()) / 2.f);
				++score;
				break;
			}
		}
	}

	//kamienie z kamieniami
	for (auto rock_it = rocks.begin(); rock_it < rocks.end(); rock_it++)
	{
		for (auto rock_it1 = rock_it + 1; rock_it1 < rocks.end(); rock_it1++)
		{
			if ((*rock_it)->right() < rockCollisionTestLine && (*rock_it1)->right() < rockCollisionTestLine && (*rock_it)->collisionTest(**rock_it1))
			{
				boom(((*rock_it)->left() + (*rock_it)->right()) / 2.f, ((*rock_it)->top() + (*rock_it)->bottom()) / 2.f);
				boom(((*rock_it1)->left() + (*rock_it1)->right()) / 2.f, ((*rock_it1)->top() + (*rock_it1)->bottom()) / 2.f);
				break;
			}
		}
		if ((*rock_it)->collisionTest(player))
		{
			boom(((*rock_it)->left() + (*rock_it)->right()) / 2.f, ((*rock_it)->top() + (*rock_it)->bottom()) / 2.f);
			break;
		}
	}

	//bonusy z kamieniami
	for (auto& bonus : bonuses)
	{
		for (auto& rock : rocks)
		{
			if (rock->collisionTest(*bonus))
			{
				boom((rock->left() + rock->right()) / 2.f, (rock->top() + rock->bottom()) / 2.f);
				break;
			}
		}
	}
	//bonusy z graczem
	for (auto& bonus : bonuses)
	{
		if (bonus->collisionTest(player))
			break;
	}
}

void objectManager::update(Player& player, Score& score)
{
	updateHPbar(player);
	updateRocks(score);
	updateBullets(player);
	updateBonuses();
	updateExplosions();
	player.update();
}

std::vector<std::shared_ptr<Rock>> objectManager::getRocks()
{
	return this->rocks;
}

std::vector<std::shared_ptr<Bullet>> objectManager::getBullets()
{
	return this->bullets;
}

std::vector<std::shared_ptr<Heart>> objectManager::getHPbar()
{
	return this->HPbar;
}

std::vector<std::shared_ptr<Bonus>> objectManager::getBonuses()
{
	return this->bonuses;
}

std::vector<std::shared_ptr<Explosion>> objectManager::getExplosions()
{
	return this->explosions;
}


void objectManager::updateHPbar(Player& player)
{
	//HP bar
	for (unsigned int i = HPbar.size(); i < player.howManyHearts(); i++)
	{
		std::shared_ptr<Heart> heart = std::make_shared<Heart>(rManager.getTexture(HeartTexturePath), HPbarPosition_X + (i * rManager.getTexture(HeartTexturePath).getSize().x), HPbarPosition_Y);
		HPbar.push_back(heart);
	}
	while (HPbar.size() > player.howManyHearts() && HPbar.size() > 0)
	{
		HPbar.pop_back();
	}
}

void objectManager::updateRocks(Score& score)
{
	//rocks
	if (rockSpawnTimer >= _rockSpawnTimer)
	{
		std::shared_ptr<Rock> rock = std::make_shared<Rock>(rManager.getTexture(randomRockTexturePath()), rockSpawnPosition_X, random_float(0, res_Y), score.getLevel());
		rocks.push_back(rock);
		rockSpawnTimer = 0;
	}
	else
	{
		rockSpawnTimer++;
	}
	std::experimental::erase_if(rocks, [](const std::shared_ptr<Rock>& rock) { return rock->isDestroyed(); });
	for (auto& rock : rocks)
	{
		rock->update();
	}
}

void objectManager::updateBullets(Player& player)
{
	//bullets
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && player.shoot(shootingTimer))
	{
		std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(rManager.getTexture(BulletTexturePath), player.right(), (player.top() + player.bottom()) / 2.f);
		bullets.push_back(bullet);
		shootingTimer = 0;
	}
	else
	{
		shootingTimer++;
	}
	std::experimental::erase_if(bullets, [](const std::shared_ptr<Bullet>& bullet) { return bullet->isDestroyed(); });
	for (auto& bullet : bullets)
	{
		bullet->update();
	}
}

void objectManager::updateBonuses()
{
	//bonuses
	if (bonusSpawnTimer >= _bonusSpawnTimer)
	{
		if (random_int(0, 1))
		{
			std::shared_ptr<Bonus> bonus = std::make_shared<extraHealth>(rManager.getTexture(ExtraHealthTexturePath), rockSpawnPosition_X, random_float(0, res_Y));
			bonuses.push_back(bonus);
		}
		else
		{
			std::shared_ptr<Bonus> bonus = std::make_shared<extraShootingSpeed>(rManager.getTexture(ExtraShootingSpeedTexturePath), rockSpawnPosition_X, random_float(0, res_Y));
			bonuses.push_back(bonus);
		}
		bonusSpawnTimer = 0;
	}
	else
	{
		bonusSpawnTimer++;
	}
	std::experimental::erase_if(bonuses, [](const std::shared_ptr<Bonus>& bonus) { return bonus->isDestroyed(); });
	for (auto& bonus : bonuses)
	{
		bonus->update();
	}
}

void objectManager::updateExplosions()
{
	std::experimental::erase_if(explosions, [](const std::shared_ptr<Explosion>& explosion) { return explosion->isDestroyed(); });
	for (auto& explosion : explosions)
	{
		explosion->update();
	}
}

void objectManager::boom(float t_X, float t_Y)
{
	std::shared_ptr<Explosion> explosion = std::make_shared<Explosion>(rManager.getTexture(ExplosionTexturePath), rManager.getSound(ExplosionSound), t_X, t_Y);
	explosions.push_back(explosion);
}

const char * objectManager::randomRockTexturePath()
{
	switch (random_int(1, 5))
	{
	case 1:
		return RockTexturePath1;
		break;
	case 2:
		return RockTexturePath2;
		break;
	case 3:
		return RockTexturePath3;
		break;
	case 4:
		return RockTexturePath4;
		break;
	case 5:
		return RockTexturePath5;
		break;
	default:
		return nullptr;
		break;
	}
}

