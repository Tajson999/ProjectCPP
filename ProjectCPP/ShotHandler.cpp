#include "ShotHandler.h"

void ShotHandler::expand() {
	this->capacity += 10;
	Shot* *tempShot = new Shot*[this->capacity];
	for (int i = 0; i < this->nrOfShots; i++) {
		tempShot[i] = this->shots[i];
	}
	delete[] this->shots;

	for (int i = this->nrOfShots; i < this->capacity; i++){
		tempShot[i] = nullptr;
	}
	this->shots = tempShot;
	cout << "Expanded to " << this->capacity << endl;
}

ShotHandler::ShotHandler() {
	this->capacity = 10;
	this->nrOfShots = 0;
	this->shotCD = 0;
	this->shots = new Shot*[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->shots[i] = nullptr;
	}
}

ShotHandler::~ShotHandler() {
	for (int i = 0; i < this->nrOfShots; i++) {
		delete this->shots[i];
	}
	delete[] this->shots;
}

int ShotHandler::getNrOfShots() {
	return this->nrOfShots;
}

void ShotHandler::setNrOfShots(int s) {
	this->nrOfShots = s;
}

int ShotHandler::getCapacity() {
	return this->capacity;
}

void ShotHandler::setCapacity(int c) {
	this->capacity = c;
}

void ShotHandler::setShotCD(int i) {
	this->shotCD = i;
}

int ShotHandler::getShotCD() {
	return this->shotCD;
}

void ShotHandler::addShot(Vector2f v) {
	if (this->shotCD == 0) {
		if (this->nrOfShots >= this->capacity) {
			this->expand();
		}
		this->shots[this->nrOfShots++] = new Shot(v);
		this->shotCD = 20;
		cout << "Added a new shot for a total of " << this->nrOfShots << endl;
	}
	
}

void ShotHandler::removeShot(int i) {
	this->nrOfShots -= 1;
	if (i == this->nrOfShots || this->nrOfShots == 0) {
		delete this->shots[i];
		this->shots[i] = nullptr;
	}
	else {
		delete this->shots[i];
		this->shots[i] = this->shots[this->nrOfShots];
		this->shots[this->nrOfShots] = nullptr;
	}
	cout << "Removed one shot with new total " << this->nrOfShots << endl;

}

void ShotHandler::updateShots(Sprite arr[]) {
	for (int i = 0; i < this->nrOfShots; i++) {
		if (this->shots[i]->getLifeSpan() <= 0) {
			this->removeShot(i);
			if (i != 0) {
				i--;
			}
		}
		else {
			this->shots[i]->setLifeSpan(this->shots[i]->getLifeSpan() - 1);
			this->shots[i]->move(Vector2f(0, -5));
			arr[i] = this->shots[i]->getSprite();
		}
	}
}
