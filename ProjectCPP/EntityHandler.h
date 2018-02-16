#ifndef ENTITYHANDLER_H
#define ENTITYHANDLER_H
#include "BasicEnemy.h"
#include "Shot.h"
#include "enemy2.h"
#include "Player.h"
#include <iostream>
class EntityHandler {
private:
	Clock time;
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

	void spawnBasicEnemy(Vector2f v);
	void spawnEnemy2(Vector2f v);
	//void removeEntity(int i);
	void updateEntites(Sprite enemyArr[], int &enemyArrSize, Sprite shotArr[], int shotArrSize, Vector2u viewport,Time deltaTime);
	void spawnEnemies();

	void deactivateEnemy(BasicEnemy *e);
	void deactivateEnemy(Enemy2 *e);

	Enemy* closestEnemy(Player p);

};

#endif // !ENEMYHANDLER_H
