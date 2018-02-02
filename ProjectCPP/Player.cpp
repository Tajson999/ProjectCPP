#include "Player.h"

Player::Player() {

	this->setTexture("C:/Users/alexa/source/repos/ProjectCPP/ProjectCPP/player-plane-sprite-sheet-2.png");
	this->setSpriteRect(IntRect(0, 0, 50, 63));
	this->setTextureSmooth();
	this->setSpriteOrigin(Vector2f(20, 0));
	this->score = 0;
	this->life = 100;

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

void Player::moveUp() {
	this->move(Vector2f(0, -1));
	this->setSpriteRect(IntRect(0, 0, 50, 63));
}

void Player::moveDown() {
	this->move(Vector2f(0, 1));
	this->setSpriteRect(IntRect(0, 0, 50, 63));
}

void Player::moveRight() {
	this->move(Vector2f(1, 0));
	this->setSpriteRect(IntRect(551, 0, 50, 63));
}

void Player::moveLeft() {
	this->move(Vector2f(-1, 0));
	this->setSpriteRect(IntRect(251, 0, 50, 63));
}
