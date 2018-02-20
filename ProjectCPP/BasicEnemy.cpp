#include "BasicEnemy.h"
#include <iostream>
BasicEnemy::BasicEnemy() :Enemy(){
	int life = 1;
	this->setTexture("spriteSheet.png");
	this->setSpriteRect(sf::IntRect(4,4,31,31));
	this->setSpritePosition(sf::Vector2f(200, 0));
	this->setSpriteScale(sf::Vector2f(2, 2));
	this->a = this->getSprite().getPosition().x;
	this->b = this->getSprite().getPosition().y;
	this->radiant = 0;
	this->stage = 0;
}

BasicEnemy::~BasicEnemy() {

}

void BasicEnemy::setA(double a){
	this->a = a;
}

void BasicEnemy::setB(double b){
	this->b = b;
}

void BasicEnemy::setRadiant(double r){
	this->radiant = r;
}


void BasicEnemy::update(sf::Time deltaTime) {
	if (this->getSprite().getTextureRect().left == 4) {
		this->moveSpriteRect(66, 0);
	}
	else {
		this->moveSpriteRect(-66, 0);
	}
	this->radiant += (.4 * deltaTime.asMilliseconds() * 3.1415) / 180;
	int radius = 100;
	//generate absolute cordiantes
	int newX = cos(this->radiant) * radius;
	int newY = sin(this->radiant) * radius;
	newX -= this->getSprite().getPosition().x - this->a;
	newY -= this->getSprite().getPosition().y - this->b;
	this->b += .2;
	this->move(sf::Vector2f(newX, newY));
	
}
