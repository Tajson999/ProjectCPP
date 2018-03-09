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
	int nrOfCannons;
	int bombCount;
public:
	Player(sf::Texture *texture);
	Player();
	~Player();
	Player(const Player &p);
	double getLife()const;
	void setLife(double l);
	int& getScore();
	void setScore(int s);
	void setShotCD(double CD);
	double getShotCD();
	double getMissileCD();
	void setMissileCD(double CD);
	BasicShot*** getShotArr();
	Missile*** getMissileArr();
	int getBombCount();
	void setBombCount(int count);

	//powerups
	void addOneShot();
	void addBomb();

	void reset();
	void takeDamage(double damage);
	void moveUp(sf::Time deltaTime);
	void moveDown(sf::Time deltaTime);
	void moveRight(sf::Time deltaTime);
	void moveLeft(sf::Time deltaTime);
	void update(sf::Time deltaTime);

	void shoot();
	void checkDamage(Enemy*** enemyArr, int nrOfEnemies);
	void shootMissile(Enemy *arget);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};
#endif // !PLAYER_H

