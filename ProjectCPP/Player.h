#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "BasicShot.h"
#include "Enemy.h"
#include "Missile.h"
using namespace sf;
using namespace std;
class Player :public Entity{
private:
	Shot **shotArr;
	Missile **missileArr;
	double invulnerability;
	int score;
	double life;
	int shotCapacity;
	int nrOfShots;
	int missilesCapacity;
	int shotCD;
public:
	Player();
	~Player();
	double getLife()const;
	void setLife(double l);
	int getScore()const;
	void setScore(int s);
	void setShotCD(int CD);
	int getShotCD();
	void takeDamage(double damage);
	void moveUp(Time deltaTime);
	void moveDown(Time deltaTime);
	void moveRight(Time deltaTime);
	void moveLeft(Time deltaTime);
	void update(Time deltaTime);
	void update(Sprite spriteShotArr[], int &shots, Time deltaTime);
	void shoot();
	void checkDamage(Sprite enemyArr[], int nrOfEnemies);
	void shootMissile(Enemy *target);
};
#endif // !PLAYER_H

