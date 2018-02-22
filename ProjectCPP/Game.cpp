#include "Game.h"

Game::Game() {
	this->backgroundTexture.loadFromFile("background.png");
	this->backgroundSprite.setTexture(this->backgroundTexture);
}

Game::~Game() {
}

void Game::update(sf::Time deltaTime, sf::Vector2u viewport) {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
		if (p1.getMissileCD() <= 0) {
			p1.shootMissile(eH.closestEnemy(p1));
		}
	}

	//player updates
	this->p1.update(deltaTime);
	this->p1.checkDamage((Enemy ***)eH.getBasicEnemyArr(), 20);
	this->p1.checkDamage((Enemy ***)eH.getEnemy2Arr(), 20);

	//enemy updates
	this->eH.updateEntites(this->p1.getShotArr(), this->p1.getMissileArr(), viewport, deltaTime);
	this->eH.spawnEnemies();
}

void Game::draw(sf::RenderTarget & target) {
	target.draw(backgroundSprite);
	this->eH.drawEnemies(target);
	this->p1.draw(target, sf::RenderStates::Default);
}
