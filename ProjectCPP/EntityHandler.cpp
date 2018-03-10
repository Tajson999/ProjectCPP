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

EntityHandler::EntityHandler(sf::Texture *texture) {
	this->capacity = 20;
	this->shotCD = 0;
	this->spawnedThisCycle = false;
	this->basicEnemyArr = new BasicEnemy*[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->basicEnemyArr[i] = new BasicEnemy(texture);
		this->basicEnemyArr[i]->setSpritePosition(sf::Vector2f(-200, -200));
	}

	this->enemy2Arr = new Enemy2*[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->enemy2Arr[i] = new Enemy2(texture);
		this->enemy2Arr[i]->setSpritePosition(sf::Vector2f(-200, -200));
	}
}

EntityHandler::EntityHandler(const EntityHandler * eH) {
	this->capacity = eH->capacity;
	this->shotCD = eH->capacity;
	this->spawnedThisCycle = eH->spawnedThisCycle;
	this->basicEnemyArr = new BasicEnemy*[eH->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->basicEnemyArr[i] = new BasicEnemy(*eH->basicEnemyArr[i]);
	}

	this->enemy2Arr = new Enemy2*[eH->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->enemy2Arr[i] = new Enemy2(*eH->enemy2Arr[i]);
	}

}

EntityHandler::EntityHandler() {
	this->capacity = 20;
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

BasicEnemy *** EntityHandler::getBasicEnemyArr() {
	return &this->basicEnemyArr;
}

Enemy2 *** EntityHandler::getEnemy2Arr() {
	return &this->enemy2Arr;
}


void EntityHandler::spawnBasicEnemy(sf::Vector2f v, int life, int damage) {
	bool spawned = false;
	for (int i = 0; i < this->capacity && spawned == false; i++) {
		if (this->basicEnemyArr[i]->getActive() == 0) {
			this->basicEnemyArr[i]->setSpritePosition(v);
			this->basicEnemyArr[i]->setActive(1);
			this->basicEnemyArr[i]->setLife(life);
			this->basicEnemyArr[i]->setDamage(damage);
			this->basicEnemyArr[i]->setA(this->basicEnemyArr[i]->getSprite().getPosition().x);
			this->basicEnemyArr[i]->setB(this->basicEnemyArr[i]->getSprite().getPosition().y);
			this->basicEnemyArr[i]->setRadiant(0);
			spawned = true;
		}
	}
}

void EntityHandler::spawnEnemy2(sf::Vector2f v, int life, int damage, int direction){
	bool spawned = false;
	for (int i = 0; i < this->capacity && spawned == false; i++) {
		if (this->enemy2Arr[i]->getActive() == 0) {
			this->enemy2Arr[i]->setSpritePosition(v);
			this->enemy2Arr[i]->setActive(1);
			this->enemy2Arr[i]->setLife(life);
			this->enemy2Arr[i]->setDirection(direction);
			this->enemy2Arr[i]->setDamage(damage);
			spawned = true;
		}
	}
}


void EntityHandler::updateEntites(BasicShot*** shotArr, Missile*** missileArr, sf::Vector2u viewport, sf::Time deltaTime, int &score) {
	//updating enemy
	

	for (int i = 0; i < this->capacity; i++) {
		if (this->basicEnemyArr[i]->getActive() == 1) {
			this->basicEnemyArr[i]->update(deltaTime);
			if (this->basicEnemyArr[i]->isDestroyed(viewport)) {
				this->deactivateEnemy(this->basicEnemyArr[i]);
				cout << "Destoryed a basic Enemy " << endl;
			}
			else if (this->basicEnemyArr[i]->isDestroyed((Shot ***)shotArr, 50, score)) {
				this->deactivateEnemy(this->basicEnemyArr[i]);
				cout << "Destoryed a basic Enemy " << endl;
			}else if(this->basicEnemyArr[i]->isDestroyed((Shot ***)missileArr,3, score)){
				this->deactivateEnemy(this->basicEnemyArr[i]);
				cout << "Destoryed a basic Enemy " << endl;
			}
		}
		if (this->enemy2Arr[i]->getActive() == 1) {
			this->enemy2Arr[i]->update(deltaTime);
			if (this->enemy2Arr[i]->isDestroyed(viewport)) {
				this->deactivateEnemy(this->enemy2Arr[i]);
				cout << "Destoryed a basic Enemy " << endl;
			}
			else if (this->enemy2Arr[i]->isDestroyed((Shot ***)shotArr, 50, score)) {
				this->deactivateEnemy(this->enemy2Arr[i]);
				cout << "Destoryed a basic Enemy " << endl;
			}
			else if (this->enemy2Arr[i]->isDestroyed((Shot ***)missileArr, 3, score)) {
				this->deactivateEnemy(this->enemy2Arr[i]);
				cout << "Destoryed a basic Enemy " << endl;
			}

		}

	}
}

void EntityHandler::drawEnemies(sf::RenderTarget & target) {
	for (int i = 0; i < this->capacity; i++) {
		if (this->basicEnemyArr[i]->getActive() == 1) {
			this->basicEnemyArr[i]->draw(target, sf::RenderStates::Default);
		}
		if (this->enemy2Arr[i]->getActive() == 1) {
			this->enemy2Arr[i]->draw(target, sf::RenderStates::Default);
		}
	}
}

void EntityHandler::spawnEnemies(){
	//spawn enemies
	int a = this->time.getElapsedTime().asSeconds();
	if (a % 5 == 0) {
		if (this->spawnedThisCycle == false) {
			int random = rand() % 2;
			switch (random) {
			case 0:
				this->spawnEnemy2(sf::Vector2f(10, 1), (a / 60) + 1, (a / 120) + 1, Enemy2::RIGHT);
				this->spawnEnemy2(sf::Vector2f(84, 1), (a / 60) + 1, (a / 120) + 1, Enemy2::RIGHT);
				this->spawnEnemy2(sf::Vector2f(158, 1), (a / 60) + 1, (a / 120) + 1, Enemy2::RIGHT);
				break;
			case 1:
				this->spawnEnemy2(sf::Vector2f(410, 1), (a / 60) + 1, (a / 120) + 1, Enemy2::LEFT);
				this->spawnEnemy2(sf::Vector2f(484, 1), (a / 60) + 1, (a / 120) + 1, Enemy2::LEFT);
				this->spawnEnemy2(sf::Vector2f(558, 1), (a / 60) + 1, (a / 120) + 1, Enemy2::LEFT);
				break;
			default:
				break;
			}
			cout << "spawned new enemies with life " << (a / 60) + 1 << " and damage " << (a / 120) + 1 << endl;
			this->spawnedThisCycle = true;
		}
		
	}
	else if (a % 3 == 0) {
		if (this->spawnedThisCycle == false) {
			cout << "spawned new enemies with life " << (a / 60) + 1 << " and damage " << (a / 120) + 1 << endl;
			this->spawnBasicEnemy(sf::Vector2f(rand() % 700, 20), (a / 60) + 1, (a / 120) + 1);
			this->spawnedThisCycle = true;
		}
	}
	else {
		this->spawnedThisCycle = false;
	}
}

void EntityHandler::reset() {
	for (int i = 0; i < this->capacity; i++) {
		deactivateEnemy(this->basicEnemyArr[i]);
		deactivateEnemy(this->enemy2Arr[i]);
	}
	this->shotCD = 0;
	this->time.restart();
}

void EntityHandler::deactivateAllEnemies(int &score) {
	cout << "Deactivating all enmies" << endl;
	for (int i = 0; i < this->capacity; i++) {
		if (this->basicEnemyArr[i]->getActive() == 1) {
			deactivateEnemy(this->basicEnemyArr[i]);
			score += 100;
		}
		if (this->enemy2Arr[i]->getActive() == 1) {
			score += 100;
			deactivateEnemy(this->enemy2Arr[i]);
		}
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

Enemy* EntityHandler::closestEnemy(int x, int y){
	Enemy* closest = this->basicEnemyArr[0];
	double playerX = x;
	double playerY = y;
	double closestDis = (pow((playerX - this->basicEnemyArr[0]->getSprite().getPosition().x), 2) + pow((playerY - this->basicEnemyArr[0]->getSprite().getPosition().y), 2));
	double deltaDis;

	for (int i = 0; i < this->capacity; i++) {
		if (this->basicEnemyArr[i]->getActive() == 1) {
			deltaDis = (pow((playerX - this->basicEnemyArr[i]->getSprite().getPosition().x),2) + pow((playerY - this->basicEnemyArr[i]->getSprite().getPosition().y), 2));
			if (deltaDis < closestDis) {
				closest = this->basicEnemyArr[i];
			}
		}
		if (this->enemy2Arr[i]->getActive() == 1) {
			deltaDis = (pow((playerX - this->enemy2Arr[i]->getSprite().getPosition().x), 2) + pow((playerY - this->enemy2Arr[i]->getSprite().getPosition().y), 2));
			if (deltaDis < closestDis) {
				closest = this->enemy2Arr[i];
			}
		}
	}
	return closest;

}
