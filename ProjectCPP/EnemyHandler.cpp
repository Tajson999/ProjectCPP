#include "EnemyHandler.h"

void EnemyHandler::expand() {
	this->capacity += 10;
	Entity* *tempShot = new Entity*[this->capacity];
	for (int i = 0; i < this->nrOfEnemies; i++) {
		tempShot[i] = this->enemies[i];
	}
	delete[] this->enemies;

	for (int i = this->nrOfEnemies; i < this->capacity; i++) {
		tempShot[i] = nullptr;
	}
	this->enemies = tempShot;
	cout << "EnemyHandler expanded to " << this->capacity << endl;
}

EnemyHandler::EnemyHandler() {
	this->capacity = 10;
	this->nrOfEnemies = 0;
	this->enemies = new Entity*[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->enemies[i] = nullptr;
	}
}

EnemyHandler::~EnemyHandler() {
	for (int i = 0; i < this->nrOfEnemies; i++) {
		delete this->enemies[i];
	}
	delete[] this->enemies;
}

void EnemyHandler::setCapacity(int c) {
	this->capacity = c;
}

int EnemyHandler::getCapacity() {
	return this->capacity;
}

void EnemyHandler::setNrOfEnemies(int e) {
	this->nrOfEnemies = e;
}

int EnemyHandler::getNrOfEnemies() {
	return this->nrOfEnemies;
}

void EnemyHandler::addEnemy() {
	if (this->nrOfEnemies >= this->capacity) {
		this->expand();
	}
	this->enemies[this->nrOfEnemies++] = new BasicEnemy();
	//add enemy
	cout << "Added a new enemy for a total of " << this->nrOfEnemies << endl;
	
}

void EnemyHandler::removeEnemy(int i) {
	this->nrOfEnemies -= 1;
	if (i == this->nrOfEnemies || this->nrOfEnemies == 0) {
		delete this->enemies[i];
		this->enemies[i] = nullptr;
	}
	else {
		delete this->enemies[i];
		this->enemies[i] = this->enemies[this->nrOfEnemies];
		this->enemies[this->nrOfEnemies] = nullptr;
	}
	cout << "Removed one enemy with new total " << this->nrOfEnemies << endl;
}

void EnemyHandler::updateEnemies(Sprite arr[]) {
	for (int i = 0; i < this->nrOfEnemies; i++) {
		//this->enemies[i].update();
		
		arr[i] = this->enemies[i]->getSprite();
		
	}
}
