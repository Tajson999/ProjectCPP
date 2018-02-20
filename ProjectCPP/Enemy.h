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
	void setDamage(double damage);
	double getDamage();

	virtual void update(sf::Time deltaTime) = 0;
	bool isDestroyed(sf::FloatRect shotRectArr[], int shotArrSize, sf::Vector2u viewport);


};
#endif // !BASICENEMY_H
