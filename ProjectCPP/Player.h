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
	int score;
	double life;
public:
	Player();
	~Player();
	double getLife()const;
	void setLife(double l);
	int getScore()const;
	void setScore(int s);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
};
#endif // !PLAYER_H

