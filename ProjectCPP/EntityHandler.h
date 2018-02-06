#ifndef ENTITYHANDLER_H
#define ENTITYHANDLER_H
#include "BasicEnemy.h"
#include "Shot.h"
#include <iostream>
class EntityHandler {
private:
	int capacity;
	int nrOfEntites;
	Entity* *entites;
	double shotCD;

	void expand();
public:
	EntityHandler();
	~EntityHandler();
	void setCapacity(int c);
	int getCapacity();
	void setNrOfEntites(int e);
	int getNrOfEntities();
	void setShotCD(double CD);
	double getShotCD();

	void addBasicEnemy();
	void addShot(Vector2f v);
	void removeEntity(int i);
	void updateEntites(Sprite arr[], Time deltaTime);

};

#endif // !ENEMYHANDLER_H
