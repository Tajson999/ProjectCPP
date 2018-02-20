#ifndef MISSILE_H
#define MISSILE_H
#include "Shot.h"
#include "Enemy.h"
using namespace std;
 
class Missile: public Shot{
private:
	double reDirectCD;
	double direction;
	double speed;
	Enemy *target;
public:
	Missile(Enemy *target, double lifespan = 800);
	Missile();
	~Missile();

	void setSpeed(double speed);
	double getSpeed();
	void setDirection(double d);
	void setTarget(Enemy *target);
	void setReDirectCD(double CD);

	void update(sf::Time deltaTime);
};
#endif // !MISSILE_H

