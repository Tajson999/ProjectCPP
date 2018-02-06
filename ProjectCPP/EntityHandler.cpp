#include "EntityHandler.h"

void EntityHandler::expand() {
	this->capacity += 10;
	Entity* *tempArr = new Entity*[this->capacity];
	for (int i = 0; i < this->nrOfEntites; i++) {
		tempArr[i] = this->entites[i];
	}
	delete[] this->entites;

	for (int i = this->nrOfEntites; i < this->capacity; i++) {
		tempArr[i] = nullptr;
	}
	this->entites = tempArr;
}

EntityHandler::EntityHandler() {
	this->capacity = 10;
	this->nrOfEntites = 0;
	this->shotCD = 0;
	this->entites = new Entity*[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->entites[i] = nullptr;
	}
}

EntityHandler::~EntityHandler() {
	for (int i = 0; i < this->nrOfEntites; i++) {
		delete this->entites[i];
	}
	delete[] this->entites;
}

void EntityHandler::setCapacity(int c) {
	this->capacity = c;
}

int EntityHandler::getCapacity() {
	return this->capacity;
}

void EntityHandler::setNrOfEntites(int e) {
	this->nrOfEntites = e;
}

int EntityHandler::getNrOfEntities() {
	return this->nrOfEntites;
}

void EntityHandler::setShotCD(double CD) {
	this->shotCD = CD;
}

double EntityHandler::getShotCD() {
	return this->shotCD;
}

void EntityHandler::addBasicEnemy() {
	if (this->nrOfEntites >= this->capacity) {
		this->expand();
	}
	this->entites[this->nrOfEntites++] = new BasicEnemy();
}

void EntityHandler::addShot(Vector2f v) {
	if (this->shotCD <= 0) {
		if (this->nrOfEntites >= this->capacity) {
			this->expand();
		}
		this->entites[this->nrOfEntites++] = new Shot(v);
		this->shotCD = 50;
	}
}


void EntityHandler::removeEntity(int i) {
	this->nrOfEntites -= 1;
	if (i == this->nrOfEntites || this->nrOfEntites == 0) {
		delete this->entites[i];
		this->entites[i] = nullptr;
	}
	else {
		delete this->entites[i];
		this->entites[i] = this->entites[this->nrOfEntites];
		this->entites[this->nrOfEntites] = nullptr;
	}
}

void EntityHandler::updateEntites(Sprite arr[], Time deltaTime) {
	Shot *shotPtr = nullptr;
	
	if (this->shotCD > 0) {
		this->shotCD -= deltaTime.asMilliseconds();
	}

	for (int i = 0; i < this->nrOfEntites; i++) {
		this->entites[i]->update(deltaTime);
		shotPtr = dynamic_cast<Shot*>(this->entites[i]);
		if (shotPtr != nullptr) {
			if (shotPtr->getLifeSpan() <= 0) {
				this->removeEntity(i);
				if (i != 0) {
					i--;
				}
			}
			//if shot not is removed
			else {
				arr[i] = this->entites[i]->getSprite();
			}
		}
		//if not shot
		else {
			arr[i] = this->entites[i]->getSprite();
		}

	}
}
