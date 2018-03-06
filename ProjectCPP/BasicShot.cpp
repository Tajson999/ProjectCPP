#include "BasicShot.h"

BasicShot::BasicShot(double life) :Shot(life){
	this->active = 0;
	this->setTexture("spriteSheet.png");
	this->setSpriteRect(sf::IntRect(48,176,8,21));
	this->setTextureSmooth();
}

BasicShot::BasicShot(sf::Texture *texture, sf::Vector2f v, double life): Shot(life) {
	this->active = 0;
	this->setTexture(texture);
	this->setSpriteRect(sf::IntRect(48, 176, 8, 21));
	this->setTextureSmooth();
	this->setSpritePosition(v);
}

BasicShot::~BasicShot() {
}



void BasicShot::update(sf::Time deltaTime) {

	this->move(sf::Vector2f(0, -1 * deltaTime.asMilliseconds()));
	this->setLifeSpan(this->getLifeSpan() - deltaTime.asMilliseconds());
}


