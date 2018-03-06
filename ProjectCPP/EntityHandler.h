#ifndef ENTITYHANDLER_H
#define ENTITYHANDLER_H
#include "BasicEnemy.h"
#include "Shot.h"
#include "enemy2.h"
#include "Player.h"
#include <iostream>
#include <ctime>
class EntityHandler {
private:
	sf::Clock time;
	int capacity;
	int nrOfEntites;
	BasicEnemy* *basicEnemyArr;
	Enemy2* *enemy2Arr;
	double shotCD;
	bool spawnedThisCycle;

	//void expand();
public:
	EntityHandler(sf::Texture *textue);
	EntityHandler();
	~EntityHandler();
	void setCapacity(int c);
	int getCapacity();
	void setNrOfEntites(int e);
	int getNrOfEntities();

	BasicEnemy*** getBasicEnemyArr();
	Enemy2*** getEnemy2Arr();

	void spawnBasicEnemy(sf::Vector2f v, int life, int damage);
	void spawnEnemy2(sf::Vector2f v, int life, int damage, int direction);
	//void removeEntity(int i);
	void updateEntites(BasicShot*** shotArr, Missile*** missileArr, sf::Vector2u viewport,sf::Time deltaTime);
	void drawEnemies(sf::RenderTarget & target);
	void spawnEnemies();

	void deactivateEnemy(BasicEnemy *e);
	void deactivateEnemy(Enemy2 *e);

	Enemy* closestEnemy(int x, int y);

};

#endif // !ENEMYHANDLER_H
