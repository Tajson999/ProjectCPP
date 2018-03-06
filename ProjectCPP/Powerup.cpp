#include "Powerup.h"

Powerup::Powerup(double speed, double reDirectCD) {
	this->active = 0;
}

Powerup::~Powerup() {
}

int Powerup::getActive() {
	return this->active;
}

void Powerup::setActive(int a) {
	this->active = a;
}

bool Powerup::isOutOfBounds(sf::Vector2u viewport) {
	bool out = false;
	//if active == 1 && (sprite.x < viewport.x || sprite.x + sprite.height < 0 || sprite.y > viewport.y || sprite.y + sprite.width < 0)
	if (this->getActive() == 1 && ((viewport.x < this->getSprite().getGlobalBounds().left || 0 > this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().height) || (viewport.y < this->getSprite().getGlobalBounds().top) || 0 > this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width)) {
		out = true;
		cout << "power up out of bounds ";
	}
	return out;
}

bool Powerup::isTriggered(int x, int y, int length, int height) {
	return this->getSprite().getGlobalBounds().intersects(sf::FloatRect(x, y, length, height));;
}
