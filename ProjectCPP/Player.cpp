#include "Player.h"
#include <iostream>
Player::Player() {

	this->setTexture("player-plane-sprite-sheet-2.png");
	this->setSpriteRect(IntRect(0, 0, 50, 63));
	this->setTextureSmooth();
	this->setSpriteOrigin(Vector2f(20, 0));
	this->score = 0;
	this->life = 3;
	this->invulnerability = 0;

}

Player::~Player() {
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

void Player::takeDamage(double damage) {
	if (this->invulnerability <= 0) {
		this->life -= damage;
		cout << "You took damage you now have " << this->life << " life left";
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

void Player::update(Time deltaTime) {
	if (this->invulnerability > 0) {
		this->invulnerability -= deltaTime.asMilliseconds();
	}
}
