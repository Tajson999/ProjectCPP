#ifndef POWERUP_H
#define POWERUP_H
#include "Entity.h"
#include "Player.h"
class Powerup :public Entity {
private:
	int active;
public:
	Powerup();
	~Powerup();

	int getActive() const;
	void setActive(int a);

	bool isOutOfBounds(sf::Vector2u viewport) const;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void triggerPowerup(Player *p) = 0;
	bool isTriggered(int x, int y, int length, int height) const;
};
#endif // !POWERUP_H
