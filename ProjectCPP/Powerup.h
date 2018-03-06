#ifndef POWERUP_H
#define POWERUP_H
#include "Entity.h"
#include "Player.h"
class Powerup :public Entity {
private:
	int active;
	//double speed;
	//double reDirectCD;
public:
	Powerup(double speed, double reDirectCD);
	~Powerup();

	int getActive();
	void setActive(int a);

	bool isOutOfBounds(sf::Vector2u viewport);
	virtual void update(sf::Time deltaTime) = 0;
	virtual void triggerPowerup(Player *p) = 0;
	bool isTriggered(int x, int y, int length, int height);
};
#endif // !POWERUP_H
