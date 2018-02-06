#ifndef BASICENEMY_H
#define BASICENEMY_H
#include "Entity.h"
class BasicEnemy:public Entity{
private:
	int life;
	int stage;
	double a;
	double b;
	double radiant;
public:
	BasicEnemy();
	~BasicEnemy();

	void update(Time deltaTime);


};
#endif // !BASICENEMY_H
