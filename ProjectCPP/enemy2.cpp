#include "enemy2.h"
#include <iostream>
Enemy2::Enemy2() :Enemy(){
	int life = 1;
	this->setTexture("enemy1.png");
	this->rotateSprite(180);
	this->setSpriteColor(0, 255, 0);
	this->setSpriteScale(Vector2f(0.6, 0.6));
	this->setSpritePosition(Vector2f(100, 0));
}

Enemy2::~Enemy2()
{
}

void Enemy2::update(Time deltaTime)
{
	this->move(Vector2f(.1*deltaTime.asMilliseconds(), .1*deltaTime.asMilliseconds()));
}
