#include "extrahealth.h"

extraHealth::extraHealth(const sf::Texture& texture, float t_X, float t_Y) : Bonus(texture, t_X, t_Y) { }

void extraHealth::addBonus(Player& player)
{
	player.addHp(extraHP);
}
