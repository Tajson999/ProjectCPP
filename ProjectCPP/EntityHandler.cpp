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
		this->basicEnemyArr[i]->setSpritePosition(sf::Vector2f(-200, -200));
	}

	this->enemy2Arr = new Enemy2*[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->enemy2Arr[i] = new Enemy2();
		this->enemy2Arr[i]->setSpritePosition(sf::Vector2f(-200, -200));
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


void EntityHandler::spawnBasicEnemy(sf::Vector2f v) {
	bool spawned = false;
	for (int i = 0; i < this->capacity && spawned == false; i++) {
		if (this->basicEnemyArr[i]->getActive() == 0) {
			this->basicEnemyArr[i]->setSpritePosition(v);
			this->basicEnemyArr[i]->setActive(1);
			this->basicEnemyArr[i]->setLife(1);
			this->basicEnemyArr[i]->setA(this->basicEnemyArr[i]->getSprite().getPosition().x);
			this->basicEnemyArr[i]->setB(this->basicEnemyArr[i]->getSprite().getPosition().y);
			this->basicEnemyArr[i]->setRadiant(0);
			spawned = true;
		}
	}
}

void EntityHandler::spawnEnemy2(sf::Vector2f v){
	bool spawned = false;
	for (int i = 0; i < this->capacity && spawned == false; i++) {
		if (this->enemy2Arr[i]->getActive() == 0) {
			this->enemy2Arr[i]->setSpritePosition(v);
			this->enemy2Arr[i]->setActive(1);
			this->enemy2Arr[i]->setLife(1);
			spawned = true;
		}
	}
}

void EntityHandler::updateEntites(Sprite enemyArr[], int &enemyArrSize, Sprite shotArr[], int shotArrSize, Vector2u viewport, Time deltaTime) {
	enemyArrSize = 0;
	
	//updating enemy
	for (int i = 0; i < this->capacity; i++) {
		if (this->basicEnemyArr[i]->getActive() == 1) {
			this->basicEnemyArr[i]->update(deltaTime);
			if (this->basicEnemyArr[i]->isDestroyed(shotArr, shotArrSize, viewport)) {
				this->deactivateEnemy(this->basicEnemyArr[i]);
				cout << "Destoryed a basic Enemy " << endl;
			}
		}
		if (this->enemy2Arr[i]->getActive() == 1) {
			this->enemy2Arr[i]->update(deltaTime);
			if (this->enemy2Arr[i]->isDestroyed(shotArr, shotArrSize, viewport)) {
				this->deactivateEnemy(this->enemy2Arr[i]);
				cout << "Destoryed a basic Enemy " << endl;
			}

		}
		enemyArr[enemyArrSize] = this->basicEnemyArr[i]->getSprite();
		enemyArrSize++;
		enemyArr[enemyArrSize] = this->enemy2Arr[i]->getSprite();
		enemyArrSize++;
		

	}
}

void EntityHandler::spawnEnemies(){
	//spawn enemies
	int a = this->time.getElapsedTime().asSeconds();
	if (a % 5 == 0) {
		if (this->spawnedThisCycle == false) {
			cout << "spawned new enemies" << endl;
			//this->spawnBasicEnemy(sf::Vector2f(300,200));
			this->spawnEnemy2(sf::Vector2f(500, 200));
			this->spawnedThisCycle = true;
		}
		
	}else {
		this->spawnedThisCycle = false;
	}
}

void EntityHandler::deactivateEnemy(BasicEnemy *e){
	e->setActive(0);
	e->setSpritePosition(sf::Vector2f(-200, -200));
}

void EntityHandler::deactivateEnemy(Enemy2 *e){
	e->setActive(0);
	e->setSpritePosition(sf::Vector2f(-200, -200));
}

Enemy* EntityHandler::closestEnemy(Player p){
	Enemy* closest = this->basicEnemyArr[0];
	double closestDis = 999, deltaDis;
	int playerX = p.getSprite().getPosition().x;
	int playerY = p.getSprite().getPosition().y;
	for (int i = 0; i < this->capacity; i++) {
		if (this->basicEnemyArr[i]->getActive() == 1) {
			deltaDis = pow((pow((playerX - this->basicEnemyArr[i]->getSprite().getPosition().x),2) +	pow((playerY - this->basicEnemyArr[i]->getSprite().getPosition().y), 2)), .5);
			if (deltaDis < closestDis) {
				closest = this->basicEnemyArr[i];
			}
		}
		if (this->enemy2Arr[i]->getActive() == 1) {
			deltaDis = pow((pow((playerX - this->enemy2Arr[i]->getSprite().getPosition().x), 2) + pow((playerY - this->enemy2Arr[i]->getSprite().getPosition().y), 2)), .5);
			if (deltaDis < closestDis) {
				closest = this->enemy2Arr[i];
			}
		}
	}
	return closest;

}
