#ifndef SHOT_H
#define SHOT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
using namespace std;
using namespace sf;
class Shot: public Entity {
private:
	double lifeSpan;
public:
	Shot(double life = 800);
	Shot(Vector2f v, double life = 800);
	~Shot();
	int getLifeSpan();
	void setLifeSpan(int l);
	void update(Time deltaTime);
};
#endif // !SHOT_H

