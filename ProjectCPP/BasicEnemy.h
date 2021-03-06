#ifndef BASICENEMY_H
#define BASICENEMY_H
#include "Enemy.h"
class BasicEnemy:public Enemy{
private:
	int stage;
	double a;
	double b;
	double radiant;
public:
	BasicEnemy(sf::Texture *texture);
	BasicEnemy(BasicEnemy &basicEnemy);
	BasicEnemy();
	~BasicEnemy();

	void setA(double a);
	void setB(double b);
	void setRadiant(double r);
	void update(sf::Time deltaTime);


};
#endif // !BASICENEMY_H
