#include "BasicEnemy.h"
#include <iostream>
BasicEnemy::BasicEnemy() :Entity(){
	int life = 1;
	this->setTexture("enemy1.png");
	this->rotateSprite(180);
	this->setSpritePosition(Vector2f(200, 0));
	this->a = this->getSprite().getPosition().x;
	this->b = this->getSprite().getPosition().y;
	this->radiant = 0;
	cout << "Created enemy with center:" << this->a << "," << this->b << endl;
}

BasicEnemy::~BasicEnemy() {

}

void BasicEnemy::update(Time deltaTime) {
	if (this->stage == 0) {
		
		this->radiant += (.4 * deltaTime.asMilliseconds() * 3.1415) / 180;
		int radius = 100;
		//generate absolute cordiantes
		int newX = cos(this->radiant) * radius;
		int newY = sin(this->radiant) * radius;
		newX -= this->getSprite().getPosition().x - this->a;
		newY -= this->getSprite().getPosition().y - this->b;
		this->b += .2;
		this->move(Vector2f(newX, newY));
	}
}
