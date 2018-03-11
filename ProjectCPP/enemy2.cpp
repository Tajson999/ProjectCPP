#include "enemy2.h"
#include <iostream>
Enemy2::Enemy2(sf::Texture *texture) :Enemy(2.0) {
	this->setLife(1);
	this->direction = Enemy2::RIGHT;
	this->setTexture(texture);
	this->setSpriteRect(sf::IntRect(37, 37, 31, 31));
	this->setSpriteOrigin(sf::Vector2f(18.5, 18.5));
	this->setSpriteScale(sf::Vector2f(2, 2));
	this->setSpritePosition(sf::Vector2f(100, 0));
}

Enemy2::Enemy2(Enemy2 & enemy2) {
	this->setLife(enemy2.getLife());
	this->setTexture(&(enemy2.getTexture()));
	this->setSpriteRect((sf::IntRect)enemy2.getSprite().getLocalBounds());
	this->setSpritePosition(enemy2.getSprite().getPosition());
	this->setSpriteScale(enemy2.getSprite().getScale());
	this->direction = enemy2.direction;
}

Enemy2::Enemy2() :Enemy(2.0){
	int life = 1;
	this->direction = Enemy2::RIGHT;
	this->setTexture("spriteSheet.png");
	this->setSpriteRect(sf::IntRect(37, 37, 31, 31));
	this->setSpriteOrigin(sf::Vector2f(18.5, 18.5));
	this->setSpriteScale(sf::Vector2f(2, 2));
	this->setSpritePosition(sf::Vector2f(100, 0));
}

Enemy2::~Enemy2()
{
}

void Enemy2::setDirection(int d) {
	this->direction = d;
}

void Enemy2::update(sf::Time deltaTime)
{
	if (this->getSprite().getTextureRect().left == 37) {
		this->moveSpriteRect(66, 0);
	}
	else {
		this->moveSpriteRect(-66, 0);
	}
	if (this->direction == Enemy2::RIGHT) {
		this->move(sf::Vector2f(100*deltaTime.asSeconds(), 100*deltaTime.asSeconds()));
	}
	else {
		this->move(sf::Vector2f(-100*deltaTime.asSeconds(), 100*deltaTime.asSeconds()));
	}
}
