#ifndef POWERUPHANDLER_H
#define POWERUPHANDLER _H
#include "Powerup_MoreShots.h"
#include "Player.h"
class PowerupHandler {
private:
	Powerup_MoreShots *moreShotsPtr;
	int nrOfMoreShots;
	sf::Clock time;
	bool spawnedThisCycle;

public:
	PowerupHandler(sf::Texture * texture);
	PowerupHandler();
	~PowerupHandler();

	void setTextures(sf::Texture *texture);

	void spawnMoreShot(sf::Vector2f v);
	void deActivatePowerup(Powerup *p);

	void reset();

	void spawnPowerups();
	void updateEntites(Player *p, sf::Vector2u viewport, sf::Time deltaTime);
	void drawPowerups(sf::RenderTarget & target);

};
#endif // !POWERUPHANDLER_H
