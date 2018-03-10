#ifndef POWERUP_MISSILE_H
#define POWERUP_MISSILE_H
#include "Powerup.h"
class Powerup_Missile:public Powerup {
private:

public:
	Powerup_Missile(sf::Texture *texture);
	Powerup_Missile();
	~Powerup_Missile();

	void update(sf::Time deltaTime);
	void triggerPowerup(Player *p);

};
#endif // !POWERUP_MISSILE_H
