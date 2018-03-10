#include "Powerup_MoreShots.h"

Powerup_MoreShots::Powerup_MoreShots():Powerup() {
	this->setSpriteRect(sf::IntRect(209, 237, 19, 27));
	this->setTextureSmooth();
	this->setSpritePosition(sf::Vector2f(-100, -100));
	this->setActive(0);
}

Powerup_MoreShots::Powerup_MoreShots(sf::Texture * texture) :Powerup(){
	this->setTexture(texture);
	this->setSpriteScale(sf::Vector2f(2.0, 2.0));
	this->setSpriteRect(sf::IntRect(209, 237, 19, 27));
	this->setTextureSmooth();
	this->setSpritePosition(sf::Vector2f(-100, -100));
	this->setActive(0);
}

Powerup_MoreShots::~Powerup_MoreShots() {
}

void Powerup_MoreShots::update(sf::Time deltaTime) {
	if (this->getActive() == 1) {
		this->move(sf::Vector2f(0, .5 * deltaTime.asMilliseconds()));
	}
}

void Powerup_MoreShots::triggerPowerup(Player *p) {
	p->addOneShot();
}
