#include "enemy2.h"
#include <iostream>
Enemy2::Enemy2() :Enemy(2.0){
	int life = 1;
	this->setTexture("enemy1.png");
	this->rotateSprite(180);
	this->setSpriteColor(0, 255, 0);
	this->setSpriteOrigin(sf::Vector2f(this->getSprite().getGlobalBounds().width/2, -this->getSprite().getGlobalBounds().height));
	this->setSpriteScale(sf::Vector2f(0.6, 0.6));
	this->setSpritePosition(sf::Vector2f(100, 0));
}

Enemy2::~Enemy2()
{
}

void Enemy2::update(Time deltaTime)
{
	this->move(sf::Vector2f(.1*deltaTime.asMilliseconds(), .1*deltaTime.asMilliseconds()));
}
