#include "player.h"


Player::Player(const sf::Texture& texture, const sf::SoundBuffer& ShootingSoundBuffer, const sf::SoundBuffer& PowerUpSoundBuffer, float t_X, float t_Y) : Object(texture)
{
	sprite.setPosition(t_X, t_Y);
	sprite.setScale(playerScale, playerScale);
	velocity = playerVelocity;
	velocityVector = { this->velocity, this->velocity };
	shootingSound.setBuffer(ShootingSoundBuffer);
	powerUpSound.setBuffer(PowerUpSoundBuffer);
}

void Player::update()
{
	this->sprite.move(velocityVector);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && top() > gameAreaTop)
	{
		velocityVector.y = -velocity;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && bottom() < res_Y)
	{
		velocityVector.y = velocity;
	}
	else
	{
		velocityVector.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > leftSideDestroyPosition_X)
	{
		velocityVector.x = - velocity;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < res_X)
	{
		velocityVector.x = velocity;
	}
	else
	{
		velocityVector.x = 0;
	}
}

unsigned int Player::howManyHearts()
{
	if (HP == 0)
	{
		return 0;
	}
	else
	{
		return this->HP / 50; 
	}
}

void Player::collision()
{
	HP = HP - 50;
}

void Player::addHp(unsigned int extraHP)
{
	HP += extraHP;
	if (HP > maxHP)
	{
		HP = maxHP;
	}
	else
		powerUpSound.play();
}

void Player::subShootingTimer(unsigned int extraSpeed)
{
	if (shootingTimer - extraSpeed > 0)
	{
		shootingTimer -= extraSpeed;
		powerUpSound.play();
	}
}

bool Player::shoot(int timer)
{
	if (timer >= this->shootingTimer)
	{
		shootingSound.play();
		return true;
	}
	else
		return false;
}

