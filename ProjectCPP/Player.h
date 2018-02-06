#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Config.hpp>
#include "Entity.h"
using namespace sf;
using namespace std;
class Player :public Entity{
private:
	double invulnerability;
	int score;
	double life;
public:
	Player();
	~Player();
	double getLife()const;
	void setLife(double l);
	int getScore()const;
	void setScore(int s);
	void takeDamage(double damage);
	void moveUp(Time deltaTime);
	void moveDown(Time deltaTime);
	void moveRight(Time deltaTime);
	void moveLeft(Time deltaTime);
	void update(Time deltaTime);
};
#endif // !PLAYER_H

