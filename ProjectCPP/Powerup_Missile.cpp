#include "Powerup_Missile.h"

Powerup_Missile::Powerup_Missile(sf::Texture * texture):Powerup(1,1) {
	this->setTexture(texture);
	this->setSpriteRect(sf::IntRect(79, 207, 11, 23));
	this->setSpriteScale(sf::Vector2f(2, 2));
	this->setTextureSmooth();
	this->setSpritePosition(sf::Vector2f(-100, -100));
	this->setActive(0);
}

Powerup_Missile::Powerup_Missile():Powerup(1,1) {
	this->setSpritePosition(sf::Vector2f(-100, -100));
	this->setActive(0);
}

Powerup_Missile::~Powerup_Missile() {
}

void Powerup_Missile::update(sf::Time deltaTime) {
	if (this->getActive() == 1) {
		this->move(sf::Vector2f(0, .5 * deltaTime.asMilliseconds()));
	}
}

void Powerup_Missile::triggerPowerup(Player * p) {
	p->addMissile();
}
