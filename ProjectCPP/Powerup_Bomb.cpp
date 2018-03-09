#include "Powerup_Bomb.h"

Powerup_Bomb::Powerup_Bomb(sf::Texture * texture): Powerup(1,1) {
	this->setTexture(texture);
	this->setSpriteScale(sf::Vector2f(2.0, 2.0));
	this->setSpriteRect(sf::IntRect(279, 272, 10, 21));
	this->setTextureSmooth();
	this->setSpritePosition(sf::Vector2f(-100, -100));
	this->setActive(0);
}

Powerup_Bomb::Powerup_Bomb(): Powerup(1,1) {
	this->setActive(0);
	this->setSpritePosition(sf::Vector2f(-100, -100));
}

Powerup_Bomb::~Powerup_Bomb() {
}

void Powerup_Bomb::update(sf::Time deltaTime) {
	if (this->getActive() == 1) {
		this->move(sf::Vector2f(0, .5 * deltaTime.asMilliseconds()));
	}
}

void Powerup_Bomb::triggerPowerup(Player * p) {
	p->addBomb();
}
