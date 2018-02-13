#include "Missile.h"

Missile::Missile(Enemy * target, double lifespan): Shot(lifespan){
	this->target = target;
	this->speed = 0;
	this->direction = 0;
	this->setTexture("missile.png");
	this->reDirectCD = 0;
}

Missile::Missile(): Shot(){
	this->speed = 0;
	this->direction = 0;
	this->setTexture("missile.png");
	this->reDirectCD = 0;
	this->target = nullptr;
}

Missile::~Missile(){
}

void Missile::setSpeed(double speed){
	this->speed = speed;
}

double Missile::getSpeed(){
	return this->speed;
}

void Missile::setDirection(double d){
	this->direction = d;
}

void Missile::setTarget(Enemy *target){
	this->target = target;
}

void Missile::setReDirectCD(double CD){
	this->reDirectCD = CD;
}

void Missile::update(Time deltaTime){
	if (this->getActive() == 1) {
		if (this->speed < 1) {
			this->speed += deltaTime.asMilliseconds() / 10;
		}
		if (this->reDirectCD <= 0 && this->getSprite().getPosition().y > this->target->getSprite().getPosition().y) {
			double deltaX = this->target->getSprite().getPosition().x - this->getSprite().getPosition().x;
			double deltaY = this->target->getSprite().getPosition().y - this->getSprite().getPosition().y;
			double absAngle = atan(deltaY / deltaX);
			this->direction = absAngle;
			this->move(Vector2f(cos(this->direction)*  speed * deltaTime.asMilliseconds(), sin(this->direction) * speed * deltaTime.asMilliseconds()));
			this->reDirectCD = .2;
		}
		else {
			this->reDirectCD -= deltaTime.asMilliseconds();
		}
	}
}
