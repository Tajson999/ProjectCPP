#include "PowerupHandler.h"

PowerupHandler::PowerupHandler(sf::Texture * texture) {
	this->nrOfMoreShots = 3;
	this->spawnedThisCycle = false;

	this->moreShotsPtr = new Powerup_MoreShots[this->nrOfMoreShots];
	for (int i = 0; i < this->nrOfMoreShots; i++) {
		this->moreShotsPtr[i] = Powerup_MoreShots(texture);
	}

	this->nrOfBombs = 3;
	this->bombPtr = new Powerup_Bomb[this->nrOfBombs];
	for (int i = 0; i < this->nrOfBombs; i++) {
		this->bombPtr[i] = Powerup_Bomb(texture);
	}

	this->nrOfMissiles = 5;
	this->missilePtr = new Powerup_Missile[this->nrOfMissiles];
	for (int i = 0; i < this->nrOfMissiles; i++) {
		this->missilePtr[i] = Powerup_Missile(texture);
	}
}

PowerupHandler::PowerupHandler() {
	this->nrOfMoreShots = 3;
	this->spawnedThisCycle = false;

	this->moreShotsPtr = new Powerup_MoreShots[3];
}

PowerupHandler::~PowerupHandler() {
	delete[] this->moreShotsPtr;
	delete[] this->bombPtr;
	delete[] this->missilePtr;
}

void PowerupHandler::setTextures(sf::Texture * texture) {
	for (int i = 0; i < this->nrOfMoreShots; i++) {
		this->moreShotsPtr[i].setTexture(texture);
	}
}

void PowerupHandler::spawnMoreShot(sf::Vector2f v) {
	bool spawned = false;
	for (int i = 0; i < this->nrOfMoreShots && spawned == false; i++) {
		if (this->moreShotsPtr[i].getActive() == 0) {
			this->moreShotsPtr[i].setActive(1);
			this->moreShotsPtr[i].setSpritePosition(v);
			spawned = true;
		}
	}
}

void PowerupHandler::spawnBomb(sf::Vector2f v) {
	bool spawned = false;
	for (int i = 0; i < this->nrOfBombs && spawned == false; i++) {
		if (this->bombPtr[i].getActive() == 0) {
			this->bombPtr[i].setActive(1);
			this->bombPtr[i].setSpritePosition(v);
			spawned = true;
		}
	}
}

void PowerupHandler::spawnMissile(sf::Vector2f v) {
	bool spawned = false;
	for (int i = 0; i < this->nrOfMissiles && spawned == false; i++) {
		if (this->missilePtr[i].getActive() == 0) {
			this->missilePtr[i].setActive(1);
			this->missilePtr[i].setSpritePosition(v);
			spawned = true;
		}
	}
}

void PowerupHandler::deActivatePowerup(Powerup *p) {
	p->setActive(0);
	p->setSpritePosition(sf::Vector2f(-100, -100));
}

void PowerupHandler::reset() {
	for (int i = 0; i < this->nrOfMoreShots; i++) {
		this->deActivatePowerup(&moreShotsPtr[i]);		
	}
	for (int i = 0; i < this->nrOfBombs; i++) {
		this->deActivatePowerup(&bombPtr[i]);
	}
	for (int i = 0; i < this->nrOfMissiles; i++) {
		this->deActivatePowerup(&this->missilePtr[i]);
	}
	this->time.restart();
}


void PowerupHandler::spawnPowerups() {
	//spawn powerups
	int a = this->time.getElapsedTime().asSeconds();
	if (a % 10 == 0) {
		if (this->spawnedThisCycle == false) {
			this->spawnMoreShot(sf::Vector2f(rand() % 750, 1));
			cout << "Created moreShot" << endl;
			this->spawnedThisCycle = true;
		}
	}
	else if (a % 8 == 0) {
		if (this->spawnedThisCycle == false) {
			this->spawnBomb(sf::Vector2f(rand() % 750, 1));
			cout << "Created bomb" << endl;
			this->spawnedThisCycle = true;
		}
	}
	else if (a % 5 == 0) {
		if (this->spawnedThisCycle == false) {
			this->spawnMissile(sf::Vector2f(rand() % 750, 1));
			cout << "Created Missile" << endl;
			this->spawnedThisCycle = true;
		}
	}
	else {
		this->spawnedThisCycle = false;
	}
}

void PowerupHandler::updateEntites(Player * p, sf::Vector2u viewport, sf::Time deltaTime) {
	int PlayerX = p->getSprite().getGlobalBounds().left;
	int PlayerY = p->getSprite().getGlobalBounds().top;
	int PlayerHeight = p->getSprite().getGlobalBounds().height;
	int PlayerWidth = p->getSprite().getGlobalBounds().width;
	//update moreShots
	for (int i = 0; i < this->nrOfMoreShots; i++) {
		if (this->moreShotsPtr[i].getActive() == 1) {
			this->moreShotsPtr[i].update(deltaTime);
			if (this->moreShotsPtr->isTriggered(PlayerX, PlayerY, PlayerWidth, PlayerHeight) == true) {
				this->moreShotsPtr[i].triggerPowerup(p);
				this->deActivatePowerup(&this->moreShotsPtr[i]);
			}
			else if (this->moreShotsPtr[i].isOutOfBounds(viewport) == true) {
				this->deActivatePowerup(&this->moreShotsPtr[i]);
			}
		}
	}
	//updateBomb
	for (int i = 0; i < this->nrOfBombs; i++) {
		if (this->bombPtr[i].getActive() == 1) {
			this->bombPtr[i].update(deltaTime);
			if (this->bombPtr->isTriggered(PlayerX, PlayerY, PlayerWidth, PlayerHeight) == true) {
				this->bombPtr[i].triggerPowerup(p);
				this->deActivatePowerup(&this->bombPtr[i]);
			}
			else if (this->bombPtr[i].isOutOfBounds(viewport) == true) {
				this->deActivatePowerup(&this->bombPtr[i]);
			}
		}
	}
	//update missile
	for (int i = 0; i < this->nrOfMissiles; i++) {
		if (this->missilePtr[i].getActive() == 1) {
			this->missilePtr[i].update(deltaTime);
			if (this->missilePtr->isTriggered(PlayerX, PlayerY, PlayerWidth, PlayerHeight) == true) {
				this->missilePtr[i].triggerPowerup(p);
				this->deActivatePowerup(&this->missilePtr[i]);
			}
			else if (this->missilePtr[i].isOutOfBounds(viewport) == true) {
				this->deActivatePowerup(&this->missilePtr[i]);
			}
		}
	}
}

void PowerupHandler::drawPowerups(sf::RenderTarget & target) {
	for (int i = 0; i < nrOfMoreShots; i++) {
		if (this->moreShotsPtr[i].getActive() == 1) {
			this->moreShotsPtr[i].draw(target, sf::RenderStates::Default);
		}
	}
	for (int i = 0; i < this->nrOfBombs; i++) {
		if (this->bombPtr[i].getActive() == 1) {
			this->bombPtr[i].draw(target, sf::RenderStates::Default);
		}
	}
	for (int i = 0; i < this->nrOfMissiles; i++) {
		if (this->missilePtr[i].getActive() == 1) {
			this->missilePtr[i].draw(target, sf::RenderStates::Default);
		}
	}
}
