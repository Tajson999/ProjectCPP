#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include "Shot.h"
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
	int getActive() const;
	void setLife(double a);
	double getLife() const;
	void setDamage(double damage);
	double getDamage() const;
	void deactivate();

	virtual void update(sf::Time deltaTime) = 0;
	bool isDestroyed(sf::Vector2u viewport) const;
	bool isDestroyed(Shot*** missileArr, int shotArrSize, int &score);

};
#endif // !BASICENEMY_H
