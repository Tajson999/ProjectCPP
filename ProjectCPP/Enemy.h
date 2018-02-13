#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
class Enemy :public Entity {
private:
	int active;
	double life;
	double damage;
public:
	Enemy(int active = 0, double damage = 1);
	Enemy(double damage);
	~Enemy();

	void setActive(int a);
	int getActive();
	void setLife(double a);
	double getLife();
	double getDamage();

	virtual void update(Time deltaTime) = 0;
	bool isDestroyed(Sprite shotArr[], int shotArrSize, Vector2u viewport);


};
#endif // !BASICENEMY_H
