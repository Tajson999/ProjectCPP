#include "Player.h"
#include <iostream>
Player::Player() {
	this->shotCapacity = 50;
	this->shotArr = new BasicShot*[this->shotCapacity];
	for (int i = 0; i < this->shotCapacity; i++) {
		this->shotArr[i] = new BasicShot(sf::Vector2f(-100,-100));
	}

	this->missilesCapacity = 3;
	this->missileArr = new Missile*[this->missilesCapacity];
	for (int i = 0; i < this->missilesCapacity; i++) {
		this->missileArr[i] = new Missile();
		this->missileArr[i]->setActive(0);
		this->missileArr[i]->setSpritePosition(sf::Vector2f(100, 100));
	}

	this->setTexture("spriteSheet.png");
	this->setSpriteRect(sf::IntRect(275, 414, 50, 40));
	this->setTextureSmooth();
	this->setSpriteScale(sf::Vector2f(1.5f, 1.5f));
	this->setSpriteOrigin(sf::Vector2f(25, 0));
	this->score = 0;
	this->life = 3;
	this->invulnerability = 0;
	this->shotCD = 0;
	this->missileCD = 0;
	cout << "Create player" << endl;
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

Player::Player(const Player & p):Entity(p){
	this->invulnerability = p.invulnerability;
	this->life = p.life;
	this->score = p.score;
	this->shotCD = p.shotCD;
	this->missileCD = p.missileCD;

	this->shotCapacity = p.shotCapacity;
	this->shotArr = new BasicShot*[this->shotCapacity];
	for (int i = 0; i < this->shotCapacity; i++) {
		this->shotArr[i] = new BasicShot(*(p.shotArr[i]));
	}

	this->missilesCapacity = p.missilesCapacity;
	this->missileArr = new Missile*[this->missilesCapacity];
	for (int i = 0; i < this->missilesCapacity; i++) {
		this->missileArr[i] = new Missile(*(p.missileArr[i]));
	}
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

void Player::setShotCD(double CD){
	this->shotCD = CD;
}

double Player::getShotCD(){
	return this->shotCD;
}

double Player::getMissileCD(){
	return this->missileCD;
}

BasicShot*** Player::getShotArr() {
	return &this->shotArr;
}

Missile *** Player::getMissileArr() {
	return &this->missileArr;
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

void Player::moveUp(sf::Time deltaTime) {
	this->move(sf::Vector2f(0, -.5 * deltaTime.asMilliseconds()));
}

void Player::moveDown(sf::Time deltaTime) {
	this->move(sf::Vector2f(0, .5 * deltaTime.asMilliseconds()));
}

void Player::moveRight(sf::Time deltaTime) {
	this->move(sf::Vector2f(.5 * deltaTime.asMilliseconds(), 0));
}

void Player::moveLeft(sf::Time deltaTime) {
	this->move(sf::Vector2f(-.5 * deltaTime.asMilliseconds(), 0));
}

void Player::update( sf::Time deltaTime) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		cout << "Player cords:" << this->getSprite().getPosition().x << "," << this->getSprite().getPosition().y << endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		this->moveRight(deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		this->moveLeft(deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->moveUp(deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		this->moveDown(deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		this->shoot();
		//out << this->getShotCD() << endl;
	}
	


	if (this->invulnerability > 0) {
		this->invulnerability -= deltaTime.asMilliseconds();
	}
	if (this->shotCD > 0) {
		this->shotCD -= deltaTime.asMilliseconds();
	}
	if (this->missileCD > 0) {
		this->missileCD -= deltaTime.asMicroseconds();
	}
	for (int i = 0; i < this->shotCapacity; i++) {
		if (this->shotArr[i]->getActive() == 1) {
			this->shotArr[i]->update(deltaTime);
			if (this->shotArr[i]->getLifeSpan() <= 0) {
				this->shotArr[i]->setSpritePosition(sf::Vector2f(-100, -100));
				this->shotArr[i]->setActive(0);
			}
		}
	}
	for (int i = 0; i < this->missilesCapacity; i++) {
		if (this->missileArr[i]->getActive() == 1) {
			this->missileArr[i]->update(deltaTime);
			if (this->missileArr[i]->getLifeSpan() <= 0) {
				this->missileArr[i]->setSpritePosition(sf::Vector2f(-100, -100));
				this->missileArr[i]->setActive(0);
			}
		}
	}
	if (this->getSprite().getTextureRect().left == 407) {
		this->moveSpriteRect(-132, 0);
	}
	else {
		this->moveSpriteRect(66, 0);
	}
}

void Player::shoot(){
	bool shoot = false;
	if (this->shotCD <= 0) {
		for (int i = 0; i < this->shotCapacity && shoot == false; i++) {
			if (this->shotArr[i]->getActive() == 0) {
				this->shotArr[i]->setSpritePosition(sf::Vector2f(this->getSprite().getPosition().x, this->getSprite().getPosition().y));
				this->shotArr[i]->setActive(1);
				this->shotArr[i]->setLifeSpan(800);
				shoot = true;
				this->shotCD = 100;
			}
		}
	}
}

void Player::checkDamage(Enemy*** enemyArr, int nrOfEnemies){
	Enemy **enemyArrPtr = *(enemyArr);

	for (int i = 0; i < nrOfEnemies; i++) {
		if (this->getSprite().getGlobalBounds().intersects(enemyArrPtr[i]->getSprite().getGlobalBounds())) {
			enemyArrPtr[i]->deactivate();
			this->takeDamage(1);
		}

	}
}

void Player::shootMissile(Enemy *target){
	if (this->missileCD <= 0) {
		this->missileCD = 500000;
		bool shoot = false;
		for (int i = 0; i < this->missilesCapacity && shoot == false; i++) {
			if (this->missileArr[i]->getActive() == 0) {
				cout << "missile " << i << "was set to active" << endl;
				this->missileArr[i]->setActive(1);
				this->missileArr[i]->setReDirectCD(.2);
				this->missileArr[i]->setTarget(target);
				cout << "missile target locatin is " << target->getSprite().getPosition().x << "," << target->getSprite().getPosition().y << endl;
				this->missileArr[i]->setDirection(0);
				this->missileArr[i]->setSpeed(0);
				this->missileArr[i]->setLifeSpan(4000);
				this->missileArr[i]->setSpritePosition(this->getSprite().getPosition());
				shoot = true;
			}
		}
	}
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	Entity::draw(target, states);
	for (int i = 0; i < this->shotCapacity; i++) {
		if (this->shotArr[i]->getActive() == 1) {
			target.draw(this->shotArr[i]->getSprite(), states);
		}
	}
	for (int i = 0; i < this->missilesCapacity; i++) {
		if (this->missileArr[i]->getActive() == 1) {
			target.draw(this->missileArr[i]->getSprite(), states);
		}
	}
}

