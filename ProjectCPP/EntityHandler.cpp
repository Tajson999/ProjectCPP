#include "EntityHandler.h"

//void EntityHandler::expand() {
//	this->capacity += 10;
//	Entity* *tempArr = new Entity*[this->capacity];
//	for (int i = 0; i < this->nrOfEntites; i++) {
//		tempArr[i] = this->entites[i];
//	}
//	delete[] this->entites;
//
//	for (int i = this->nrOfEntites; i < this->capacity; i++) {
//		tempArr[i] = nullptr;
//	}
//	this->entites = tempArr;
//}

EntityHandler::EntityHandler() {
	this->capacity = 20;
	this->nrOfEntites = 0;
	this->shotCD = 0;
	this->spawnedThisCycle = false;
	this->basicEnemyArr = new BasicEnemy*[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->basicEnemyArr[i] = new BasicEnemy();
		this->basicEnemyArr[i]->setSpritePosition(Vector2f(-200, -200));
	}

	this->enemy2Arr = new Enemy2*[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->enemy2Arr[i] = new Enemy2();
		this->enemy2Arr[i]->setSpritePosition(Vector2f(-200, -200));
	}
}

EntityHandler::~EntityHandler() {
	for (int i = 0; i < this->capacity; i++) {
		delete this->basicEnemyArr[i];
		delete this->enemy2Arr[i];
	}
	delete[] this->basicEnemyArr;
	delete[] this->enemy2Arr;
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


void EntityHandler::spawnBasicEnemy(Vector2f v) {
	for (int i = 0; i < this->capacity; i++) {
		if (this->basicEnemyArr[i]->getActive() == 0) {
			this->basicEnemyArr[i]->setSpritePosition(v);
			this->basicEnemyArr[i]->setActive(1);
			this->basicEnemyArr[i]->setLife(1);
			this->basicEnemyArr[i]->setA(this->basicEnemyArr[i]->getSprite().getPosition().x);
			this->basicEnemyArr[i]->setB(this->basicEnemyArr[i]->getSprite().getPosition().y);
			this->basicEnemyArr[i]->setRadiant(0);
			/*
			
	this->a = this->getSprite().getPosition().x;
	this->b = this->getSprite().getPosition().y;
	this->radiant = 0;*/
		}
	}
}

void EntityHandler::spawnEnemy2(Vector2f v){
	for (int i = 0; i < this->capacity; i++) {
		if (this->enemy2Arr[i]->getActive() == 0) {
			this->enemy2Arr[i]->setSpritePosition(v);
			this->enemy2Arr[i]->setActive(1);
			this->enemy2Arr[i]->setLife(1);
		}
	}
}


//void EntityHandler::removeEntity(int i) {
//	this->nrOfEntites -= 1;
//	if (i == this->nrOfEntites || this->nrOfEntites == 0) {
//		delete this->entites[i];
//		this->entites[i] = nullptr;
//	}
//	else {
//		delete this->entites[i];
//		this->entites[i] = this->entites[this->nrOfEntites];
//		this->entites[this->nrOfEntites] = nullptr;
//	}
//}

void EntityHandler::updateEntites(Sprite enemyArr[], int &enemyArrSize, Sprite shotArr[], int shotArrSize, Time deltaTime) {
	enemyArrSize = 0;
	
	//updating enemy and shot array
	for (int i = 0; i < this->capacity; i++) {
		if (this->basicEnemyArr[i]->getActive() == 1) {
			this->basicEnemyArr[i]->update(deltaTime);
		}
		if (this->enemy2Arr[i]->getActive() == 1) {
			this->enemy2Arr[i]->update(deltaTime);
		}
		for (int j = 0; j < shotArrSize; j++) {
			if (this->basicEnemyArr[i]->getSprite().getGlobalBounds().intersects(shotArr[j].getGlobalBounds())) {
				this->basicEnemyArr[i]->setActive(0);
				this->basicEnemyArr[i]->setSpritePosition(Vector2f(-200, -200));
			}
			if (this->enemy2Arr[i]->getSprite().getGlobalBounds().intersects(shotArr[j].getGlobalBounds())) {
				this->enemy2Arr[i]->setActive(0);
				this->enemy2Arr[i]->setSpritePosition(Vector2f(-200, -200));
			}
		}
		
		//if not shot
		enemyArr[enemyArrSize] = this->basicEnemyArr[i]->getSprite();
		enemyArrSize++;
		enemyArr[i] = this->enemy2Arr[i]->getSprite();
		enemyArrSize++;
		

	}
}

void EntityHandler::spawnEnemies(){
	//spawn enemies
	int a = this->time.getElapsedTime().asSeconds();
	if (a % 5 == 0) {
		if (this->spawnedThisCycle == false) {
			cout << "spawned new enemies" << endl;
			this->spawnBasicEnemy(Vector2f(100,200));
			this->spawnEnemy2(Vector2f(0, 0));
			this->spawnedThisCycle = true;
		}
		
	}else {
		this->spawnedThisCycle = false;
	}
}
