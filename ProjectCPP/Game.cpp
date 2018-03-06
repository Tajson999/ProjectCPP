#include "Game.h"

Game::Game() {
	this->backgroundTexture.loadFromFile("background.png");
	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->spriteSheet.loadFromFile("spriteSheet.png");
	this->pH = new PowerupHandler(&this->spriteSheet);
	this->eH = new EntityHandler(&this->spriteSheet);
	this->p1 = new Player(&this->spriteSheet);
	this->ExitB = new ExitButton(&this->spriteSheet);
	this->PlayB = new PlayButton(&this->spriteSheet);
}

Game::~Game() {
	delete pH;
	delete p1;
	delete eH;
	delete ExitB, PlayB;
}

void Game::update(sf::Time deltaTime, sf::Vector2u viewport, sf::Window* target, bool &playing) {
	
	if (playing) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
			if (p1->getMissileCD() <= 0) {
				cout << "started missile shoot" << endl;
				sf::Clock timer;
				p1->setMissileCD(3);
				p1->shootMissile(eH->closestEnemy(p1->getSprite().getPosition().x, p1->getSprite().getPosition().y));
				cout << "missile shot took" << timer.getElapsedTime().asSeconds() << endl;
			}
		}

		//player updates
		this->p1->update(deltaTime);
		this->p1->checkDamage((Enemy ***)eH->getBasicEnemyArr(), 20);
		this->p1->checkDamage((Enemy ***)eH->getEnemy2Arr(), 20);

		//Powerups updates
		this->pH->updateEntites(p1, viewport, deltaTime);
		this->pH->spawnPowerups();

		//enemy updates
		this->eH->updateEntites(this->p1->getShotArr(), this->p1->getMissileArr(), viewport, deltaTime);
		this->eH->spawnEnemies();

	}
	else {
		//buttons;
		this->ExitB->update(target, playing);
		this->PlayB->update(target, playing);
	}
	if (p1->getLife() <= 0) {
		playing = false;
		p1->setLife(3);
	}
}

void Game::draw(sf::RenderTarget & target, bool playing) {
	
	target.draw(backgroundSprite);
	if (playing) {
		this->pH->drawPowerups(target);
		this->eH->drawEnemies(target);
		this->p1->draw(target, sf::RenderStates::Default);
	}
	else {
		this->ExitB->draw(target, sf::RenderStates::Default);
		this->PlayB->draw(target, sf::RenderStates::Default);
	}
}
