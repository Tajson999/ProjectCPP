#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int active, double damage) {
	this->active = active;
	this->damage = damage;
}

Enemy::Enemy(double damage){
	this->damage = damage;
	this->active = 0;
}

Enemy::~Enemy()
{
}

void Enemy::setActive(int a){
	this->active = a;
}

int Enemy::getActive() const
{
	return this->active;
}

void Enemy::setLife(double a){
	this->life = a;
}

double Enemy::getLife() const
{
	return this->life;
}

void Enemy::setDamage(double damage) {
	this->damage = damage;
}

double Enemy::getDamage() const {
	return this->damage;
}

void Enemy::deactivate() {
	this->setActive(0);
	this->setSpritePosition(sf::Vector2f(-200, -200));
}

bool Enemy::isDestroyed(sf::Vector2u viewport) const {
	bool destroyed = false;
	//if active == 1 && (sprite.x < viewport.x || sprite.x + sprite.height < 0 || sprite.y > viewport.y || sprite.y + sprite.width < 0)
	if (this->getActive() == 1 && ((viewport.x < this->getSprite().getGlobalBounds().left || 0 > this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().height) || (viewport.y < this->getSprite().getGlobalBounds().top) || 0 > this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width)) {
		destroyed = true;
		cout << "out of bounds ";
	}
	return destroyed;
}

bool Enemy::isDestroyed(Shot*** missileArr, int shotArrSize, int &score) {
	Shot **shotArrPtr = (*missileArr);
	bool destroyed = false;
	for (int j = 0; j < shotArrSize && destroyed == false; j++) {
		if (this->getSprite().getGlobalBounds().intersects(shotArrPtr[j]->getSprite().getGlobalBounds())) {
			if (this->life == 1) {
				destroyed = true;
				score += 100;
				cout << "shot down ";
			}
			else {
				this->life -= 1;
			}
			shotArrPtr[j]->setSpritePosition(sf::Vector2f(-100, -100));
			shotArrPtr[j]->setActive(0);
			shotArrPtr[j]->setLifeSpan(0);
		}
	}

	return destroyed;
}
