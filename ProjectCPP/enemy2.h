#ifndef ENEMY2_H
#define ENEMY2_H
#include <SFML\Graphics.hpp>
#include "Enemy.h"
class Enemy2: public Enemy{
private:
	int life;
	int stage;
	int direction;
public:
	static const int LEFT = -1;
	static const int RIGHT = 1;
	Enemy2(sf::Texture *texture);
	Enemy2();
	~Enemy2();
	void setDirection(int d);
	void update(sf::Time deltaTime);

};

#endif // !ENEMY2_H
