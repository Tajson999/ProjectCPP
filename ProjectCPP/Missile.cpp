#include "Missile.h"
#include <iostream>

Missile::Missile(Enemy * target, double lifespan): Shot(lifespan){
	this->target = target;
	this->speed = 0;
	this->direction = 0;
	this->setTexture("missile.png");
	this->setSpriteScale(sf::Vector2f(0.3f, 0.3f));
	this->reDirectCD = 0;
	cout << "create a missile with active: " << this->getActive() << endl;
}

Missile::Missile(sf::Texture *texture) : Shot() {
	this->speed = 0;
	this->direction = 0;
	this->setTexture(texture);
	this->setSpriteRect(sf::IntRect(79, 207, 11, 23));
	this->setSpriteScale(sf::Vector2f(2, 2));
	this->reDirectCD = 0;
	this->target = nullptr;
	cout << "create a missile with active: " << this->getActive() << endl;
	// 69 202 80 225
}

Missile::Missile(): Shot(){
	this->speed = 0;
	this->direction = 0;
	this->setTexture("missile.png");
	this->setSpriteScale(sf::Vector2f(0.3f, 0.3f));
	this->reDirectCD = 0;
	this->target = nullptr;
	cout << "create a missile with active: "<< this->getActive() << endl;
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

void Missile::update(sf::Time deltaTime){
	if (this->getActive() == 1) {
		//cout << "missile target cords is" << this->target->getSprite().getPosition().x << "," << this->target->getSprite().getPosition().y << endl;
		if (this->speed < 1) {
			this->speed += 0.05 *deltaTime.asMilliseconds();
		}
		if (this->target->getSprite().getPosition().y > 0) {
			if (this->reDirectCD <= 0 && this->getSprite().getPosition().y  > this->target->getSprite().getPosition().y) {
				double deltaX = this->target->getSprite().getPosition().x - this->getSprite().getPosition().x;
				double deltaY = this->target->getSprite().getPosition().y - this->getSprite().getPosition().y;
				double absAngle = atan(deltaY / deltaX);
				this->direction = absAngle;
				if (this->getSprite().getPosition().x < this->target->getSprite().getPosition().x) {
					this->move(sf::Vector2f(cos(this->direction) * speed * deltaTime.asMilliseconds(),  -speed *.5* deltaTime.asMilliseconds() + .1));
				}
				else {
					this->move(sf::Vector2f(-cos(this->direction)  * speed * deltaTime.asMilliseconds(), -speed *.5* deltaTime.asMilliseconds() + .1));
				}
				this->reDirectCD = .2;
			}
			else {
				this->move(sf::Vector2f(0, -speed *.5* deltaTime.asMilliseconds()));
				this->reDirectCD -= deltaTime.asMilliseconds();
			}
		}
		else {
			this->move(sf::Vector2f(0, -speed *.5* deltaTime.asMilliseconds()));
		}
		
		this->setLifeSpan(this->getLifeSpan() - deltaTime.asMilliseconds());
	}
}