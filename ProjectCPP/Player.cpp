#include "Player.h"
#include <iostream>
Player::Player() {
	this->shotCapacity = 50;
	this->nrOfShots = 0;
	this->shotArr = new Shot*[this->shotCapacity];
	for (int i = 0; i < this->shotCapacity; i++) {
		this->shotArr[i] = new BasicShot(Vector2f(-100,-100));
	}

	this->missilesCapacity = 3;
	this->missileArr = new Missile*[this->missilesCapacity];
	for (int i = 0; i < this->missilesCapacity; i++) {
		this->missileArr[i] = new Missile();
	}

	this->setTexture("player-plane-sprite-sheet-2.png");
	this->setSpriteRect(IntRect(0, 0, 50, 63));
	this->setTextureSmooth();
	this->setSpriteOrigin(Vector2f(20, 0));
	this->score = 0;
	this->life = 3;
	this->invulnerability = 0;
	this->shotCD = 0;

}

Player::~Player() {
	for (int i = 0; i < this->shotCapacity; i++) {
		delete this->shotArr[i];
	}
	delete[] this->shotArr;

	for (int i = 0; i < this->missilesCapacity; i++) {
		delete this->missileArr[i];
	}
	delete[] this->missileArr;
}


double Player::getLife() const {
	return this->life;
}

void Player::setLife(double l) {
	this->life = l;
}

int Player::getScore() const {
	return this->score;
}

void Player::setScore(int s) {
	this->score = s;
}

void Player::setShotCD(int CD){
	this->shotCD = CD;
}

int Player::getShotCD(){
	return this->shotCD;
}


void Player::takeDamage(double damage) {
	if (this->invulnerability <= 0) {
		this->life -= damage;
		cout << "You took damage you now have " << this->life << " life left" << endl;
	}
	if (this->life <= 0 ) {
		cout << "You loose" << endl;
	}
	this->invulnerability = 1000;
	
}

void Player::moveUp(Time deltaTime) {
	this->move(Vector2f(0, -.5 * deltaTime.asMilliseconds()));
	this->setSpriteRect(IntRect(0, 0, 50, 63));
}

void Player::moveDown(Time deltaTime) {
	this->move(Vector2f(0, .5 * deltaTime.asMilliseconds()));
	this->setSpriteRect(IntRect(0, 0, 50, 63));
}

void Player::moveRight(Time deltaTime) {
	this->move(Vector2f(.5 * deltaTime.asMilliseconds(), 0));
	this->setSpriteRect(IntRect(551, 0, 50, 63));
}

void Player::moveLeft(Time deltaTime) {
	this->move(Vector2f(-.5 * deltaTime.asMilliseconds(), 0));
	this->setSpriteRect(IntRect(251, 0, 50, 63));
}

void Player::update(Time deltaTime)
{
}

void Player::update(Sprite spriteShotArr[], int &shots, Time deltaTime) {
	if (this->shotCD > 0) {
		this->shotCD -= deltaTime.asMilliseconds();
	}
	shots = 0;
	for (int i = 0; i < this->shotCapacity; i++) {
		if (this->shotArr[i]->getActive() == 1) {
			this->shotArr[i]->update(deltaTime);
			if (this->shotArr[i]->getLifeSpan() <= 0) {
				this->shotArr[i]->setSpritePosition(Vector2f(-100, -100));
				this->shotArr[i]->setActive(0);
			}
			spriteShotArr[shots++] = (this->shotArr[i]->getSprite());
		}
	}
	if (this->invulnerability > 0) {
		this->invulnerability -= deltaTime.asMilliseconds();
	}
}

void Player::shoot(){
	bool shoot = false;
	if (this->shotCD <= 0) {
		for (int i = 0; i < this->shotCapacity && shoot == false; i++) {
			if (this->shotArr[i]->getActive() == 0) {
				this->shotArr[i]->setSpritePosition(Vector2f(this->getSprite().getPosition().x, this->getSprite().getPosition().y));
				this->shotArr[i]->setActive(1);
				this->shotArr[i]->setLifeSpan(800);
				shoot = true;
				this->shotCD = 100;
			}
		}
	}
}

void Player::checkDamage(Sprite enemyArr[], int nrOfEnemies){
	for (int i = 0; i < nrOfEnemies; i++) {
		if (this->getSprite().getGlobalBounds().intersects(enemyArr[i].getGlobalBounds())) {
			this->takeDamage(1);
		}

	}
}

void Player::shootMissile(Enemy * target){
	bool shoot = false;
	for (int i = 0; i < this->shotCapacity && shoot == false; i++) {
		if (this->missileArr[i]->getActive() == 0) {
			this->missileArr[i]->setActive(1);
			this->missileArr[i]->setReDirectCD(.2);
			this->missileArr[i]->setTarget(target);
			this->missileArr[i]->setDirection(0);
			this->missileArr[i]->setSpeed(0);
			this->missileArr[i]->setSpritePosition(this->getSprite().getPosition());
			shoot = true;
		}
	}
}
