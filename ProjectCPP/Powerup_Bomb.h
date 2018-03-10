#ifndef POWERUP_BOMB_H
#define POWERUP_BOMB_H
#include "Powerup.h"
class Powerup_Bomb : public Powerup{
private:

public:
	Powerup_Bomb(sf::Texture *texture);
	Powerup_Bomb();
	~Powerup_Bomb();

	void update(sf::Time deltaTime);
	void triggerPowerup(Player *p);
};
#endif // !POWERUP_BOMB_H
