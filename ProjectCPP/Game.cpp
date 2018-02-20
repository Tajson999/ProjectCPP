#include "Game.h"

Game::Game() {
	this->p1.getShotArr(this->shotRectArr);	
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
	this->p1.update(deltaTime);
	this->p1.getShotArr(this->shotRectArr);
	this->eH.updateEntites(this->shotRectArr, viewport, deltaTime);
	this->eH.spawnEnemies();
}

void Game::draw(sf::RenderTarget & target) {
	target.draw(backgroundSprite);
	this->eH.drawEnemies(target);
	this->p1.draw(target, sf::RenderStates::Default);
}
