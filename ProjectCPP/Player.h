#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "BasicShot.h"
#include "Enemy.h"
#include "Missile.h"
 
using namespace std;
class Player :public Entity{
private:
	BasicShot **shotArr;
	Missile **missileArr;
	double invulnerability;
	int score;
	double life;
	int shotCapacity;
	int nrOfShots;
	int missilesCapacity;
	double shotCD;
	double missileCD;
public:
	Player();
	~Player();
	Player(const Player &p);
	double getLife()const;
	void setLife(double l);
	int getScore()const;
	void setScore(int s);
	void setShotCD(double CD);
	double getShotCD();
	double getMissileCD();
	void takeDamage(double damage);
	void moveUp(Time deltaTime);
	void moveDown(Time deltaTime);
	void moveRight(Time deltaTime);
	void moveLeft(Time deltaTime);
	void update(Time deltaTime);
	void update(Sprite spriteShotArr[], int &shots, Time deltaTime);
	void shoot();
	void checkDamage(Sprite enemyArr[], int nrOfEnemies);
	void shootMissile(Enemy *arget);
};
#endif // !PLAYER_H

