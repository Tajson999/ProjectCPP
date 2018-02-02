#include "Shot.h"

Shot::Shot(int life) {
	this->lifeSpan = life;
	this->setTexture("bullet.png");
	this->setTextureSmooth();
}

Shot::Shot(Vector2f v, int life) {
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

