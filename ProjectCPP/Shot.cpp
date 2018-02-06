#include "Shot.h"

Shot::Shot(double life) {
	this->lifeSpan = life;
	this->setTexture("bullet.png");
	this->setTextureSmooth();
}

Shot::Shot(Vector2f v, double life) {
	this->lifeSpan = life;
	this->setTexture("bullet.png");
	this->setTextureSmooth();
	this->setSpritePosition(v);
}

Shot::~Shot() {
}

int Shot::getLifeSpan() {
	return this->lifeSpan;
}

void Shot::setLifeSpan(int l) {
	this->lifeSpan = l;
}

void Shot::update(Time deltaTime) {
	
	this->move(Vector2f(0, -1 * deltaTime.asMilliseconds()));
	this->lifeSpan -= deltaTime.asMilliseconds();
}



