#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
class Enemy :public Entity {
private:
	int active;
	double life;
public:
	Enemy(int active = 0);
	~Enemy();

	void setActive(int a);
	int getActive();
	void setLife(double a);
	double getLife();

	virtual void update(Time deltaTime) = 0;


};
#endif // !BASICENEMY_H
