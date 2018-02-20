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
	EntityHandler();
	~EntityHandler();
	void setCapacity(int c);
	int getCapacity();
	void setNrOfEntites(int e);
	int getNrOfEntities();

	void spawnBasicEnemy(sf::Vector2f v, int life, int damage);
	void spawnEnemy2(sf::Vector2f v, int life, int damage);
	//void removeEntity(int i);
	void updateEntites(sf::FloatRect shotRectArr[], sf::Vector2u viewport,sf::Time deltaTime);
	void drawEnemies(sf::RenderTarget & target);
	void spawnEnemies();

	void deactivateEnemy(BasicEnemy *e);
	void deactivateEnemy(Enemy2 *e);

	Enemy* closestEnemy(Player p);

};

#endif // !ENEMYHANDLER_H
