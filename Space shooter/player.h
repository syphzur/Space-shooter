#pragma once
#include "object.h"

class Player : public Object
{
private:
	unsigned int HP = playerHP;
	const unsigned int maxHP = playerMaxHP;
	int shootingTimer = _shootingTimer;
	sf::Sound shootingSound;
	sf::Sound powerUpSound;
public:
	Player() = delete;
	Player(const sf::Texture& texture, const sf::SoundBuffer& ShootingSoundBuffer, const sf::SoundBuffer& PowerUpSoundBuffer, float t_X, float t_Y);
	~Player() = default;
	void update();
	void collision();
	void addHp(unsigned int extraHP);
	void subShootingTimer(unsigned int extraSpeed);
	bool shoot(int timer);
	unsigned int howManyHearts();
};
