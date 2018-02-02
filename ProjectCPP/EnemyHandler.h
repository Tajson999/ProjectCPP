#ifndef ENEMYHANDLER_H
#define ENEMYHANDLER_H
#include "BasicEnemy.h"
#include <iostream>
class EnemyHandler {
private:
	int capacity;
	int nrOfEnemies;
	Entity* *enemies;

	void expand();
public:
	EnemyHandler();
	~EnemyHandler();
	void setCapacity(int c);
	int getCapacity();
	void setNrOfEnemies(int e);
	int getNrOfEnemies();

	void addEnemy();
	void removeEnemy(int i);
	void updateEnemies(Sprite arr[]);

};

#endif // !ENEMYHANDLER_H
