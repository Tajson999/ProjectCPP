#ifndef BASICSHOT_H
#define BASICSHOT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shot.h"
using namespace std;
 
class BasicShot : public Shot {
private:
	int active;
public:
	BasicShot(double life = 800);
	BasicShot(sf::Vector2f v, double life = 800);
	~BasicShot();
	void update(Time deltaTime);
};
#endif // !SHOT_H

