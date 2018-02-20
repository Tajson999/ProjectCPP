#include "BasicEnemy.h"
#include <iostream>
BasicEnemy::BasicEnemy() :Enemy(){
	int life = 1;
	this->setTexture("enemy1.png");
	this->rotateSprite(180);
	this->setSpritePosition(sf::Vector2f(200, 0));
	this->setSpriteScale(sf::Vector2f(0.6, 0.6));
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


void BasicEnemy::update(Time deltaTime) {
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
