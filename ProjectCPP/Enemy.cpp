#include "Enemy.h"

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

int Enemy::getActive()
{
	return this->active;
}

void Enemy::setLife(double a){
	this->life = a;
}

double Enemy::getLife()
{
	return this->life;
}

double Enemy::getDamage(){
	return this->damage;
}

bool Enemy::isDestroyed(Sprite shotArr[], int shotArrSize, Vector2u viewport){
	bool destroyed = false;
	//if active == 1 && (sprite.x < viewport.x || sprite.x + sprite.height < 0 || sprite.y > viewport.y || sprite.y + sprite.width < 0)
	if (this->getActive() == 1 && ((viewport.x < this->getSprite().getGlobalBounds().left || 0 > this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().height) || (viewport.y < this->getSprite().getGlobalBounds().top) || 0 > this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width)) {
		destroyed = true;
	}
	for (int j = 0; j < shotArrSize && destroyed == false; j++) {
		if (this->getSprite().getGlobalBounds().intersects(shotArr[j].getGlobalBounds())) {
			destroyed = true;
		}
	}

	return destroyed;
}
