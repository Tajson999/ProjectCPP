#ifndef POWERUP_MORESHOTS_H
#define POWERUP_MORESHOTS_H
#include "Powerup.h"
class Powerup_MoreShots :public Powerup {
private:

public:
	Powerup_MoreShots();
	Powerup_MoreShots(sf::Texture *texture);
	~Powerup_MoreShots();

	void update(sf::Time deltaTime);
	void triggerPowerup(Player *p);
};
#endif // !POWERUP_MORESHOTS_H
