#include "Shot.h"

Shot::Shot(){
	this->active = 0;
	this->lifeSpan = 800;
}

Shot::Shot(double lifespan){
	this->active = 0;
	this->lifeSpan = lifespan;
}

Shot::~Shot()
{
}
int Shot::getLifeSpan() const {
	return this->lifeSpan;
}

void Shot::setLifeSpan(int l) {
	this->lifeSpan = l;
}
int Shot::getActive() const {
	return this->active;
}

void Shot::setActive(int a){
	this->active = a;
}