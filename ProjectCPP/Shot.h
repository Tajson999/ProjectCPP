#ifndef SHOT_H
#define SHOT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
using namespace std;
using namespace sf;
class Shot: public Entity {
private:
	int lifeSpan;
public:
	Shot(int life = 240);
	Shot(Vector2f v, int life = 240);
	~Shot();
	int getLifeSpan();
	void setLifeSpan(int l);
};
#endif // !SHOT_H

