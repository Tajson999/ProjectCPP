#include "enemy2.h"
#include <iostream>
Enemy2::Enemy2() :Enemy(2.0){
	int life = 1;
	this->setTexture("spriteSheet.png");
	this->setSpriteRect(sf::IntRect(37, 37, 31, 31));
	this->setSpriteOrigin(sf::Vector2f(18.5, 18.5));
	this->setSpriteScale(sf::Vector2f(2, 2));
	this->setSpritePosition(sf::Vector2f(100, 0));
}

Enemy2::~Enemy2()
{
}

void Enemy2::update(sf::Time deltaTime)
{
	if (this->getSprite().getTextureRect().left == 37) {
		this->moveSpriteRect(66, 0);
	}
	else {
		this->moveSpriteRect(-66, 0);
	}
	this->move(sf::Vector2f(.1*deltaTime.asMilliseconds(), .1*deltaTime.asMilliseconds()));
}
