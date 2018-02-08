#include "BasicShot.h"

BasicShot::BasicShot(double life) :Shot(life){
	this->active = 0;
	this->setTexture("bullet.png");
	this->setTextureSmooth();
}

BasicShot::BasicShot(Vector2f v, double life): Shot(life) {
	this->active = 0;
	this->setTexture("bullet.png");
	this->setTextureSmooth();
	this->setSpritePosition(v);
}

BasicShot::~BasicShot() {
}



void BasicShot::update(Time deltaTime) {

	this->move(Vector2f(0, -1 * deltaTime.asMilliseconds()));
	this->setLifeSpan(this->getLifeSpan() - deltaTime.asMilliseconds());
}





