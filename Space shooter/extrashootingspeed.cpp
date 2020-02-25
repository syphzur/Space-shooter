#include "extrashootingspeed.h"


extraShootingSpeed::extraShootingSpeed(const sf::Texture& texture, float t_X, float t_Y) : Bonus(texture, t_X, t_Y) { }

void extraShootingSpeed::addBonus(Player& player)
{
	player.subShootingTimer(extraSpeed);
}
