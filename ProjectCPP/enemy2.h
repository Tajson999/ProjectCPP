#ifndef ENEMY2_H
#define ENEMY2_H
#include <SFML\Graphics.hpp>
#include "Enemy.h"
class Enemy2: public Enemy{
private:
	int life;
	int stage;

public:
	Enemy2();
	~Enemy2();

	void update(Time deltaTime);

};

#endif // !ENEMY2_H
