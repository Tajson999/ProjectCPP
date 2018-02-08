#include "Enemy.h"

Enemy::Enemy(int active) {
	this->active = active;
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
