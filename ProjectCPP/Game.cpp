#include "Game.h"

Game::Game() {
	staringNewGame = true;
	this->backgroundTexture.loadFromFile("background.png");
	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->spriteSheet.loadFromFile("spriteSheet.png");
	this->pH = new PowerupHandler(&this->spriteSheet);
	this->eH = new EntityHandler(&this->spriteSheet);
	this->p1 = new Player(&this->spriteSheet);
	this->ExitB = new ExitButton(&this->spriteSheet);
	this->PlayB = new PlayButton(&this->spriteSheet);
	hsH.loadScoresFromFile();
}

Game::~Game() {
	delete pH;
	delete p1;
	delete eH;
	delete ExitB;
	delete PlayB;
}

void Game::update(sf::Time deltaTime, sf::Vector2u viewport, sf::Window* target, int &playing) {
	
	if (staringNewGame == true && playing == 1) {
		eH->reset();
		p1->reset();
		pH->reset();

		staringNewGame = false;
	}
	statusText.setText("Score: " + to_string(p1->getScore()) + "   Life: " + to_string((int)p1->getLife()) + "   Bombs: " + to_string(p1->getBombCount()));
	if (playing == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
			if (p1->getMissileCD() <= 0) {
				p1->shootMissile(eH->closestEnemy(p1->getSprite().getPosition().x, p1->getSprite().getPosition().y));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
			if (p1->getBombCount() > 0) {
				eH->deactivateAllEnemies(p1->getScore());
				p1->setBombCount(p1->getBombCount() - 1);
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
		this->eH->updateEntites(this->p1->getShotArr(), this->p1->getMissileArr(), viewport, deltaTime, p1->getScore());
		this->eH->spawnEnemies();

	}
	else if(playing == 0){
		//buttons;
		this->ExitB->update(target, playing, hsH);
		this->PlayB->update(target, playing, staringNewGame);
	}
	else if (playing == 2) {
		textInputBox.update();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			playing = 0;
			cout << "Score " << p1->getScore() << " name " << textInputBox.getInputText() << endl;
			hsH.addHighScore(p1->getScore(), textInputBox.getInputText());
			hsH.saveScoresToFile();
			textInputBox.resetInputText();
		}
	}
	if (p1->getLife() <= 0) {
		playing = false;
		p1->setLife(3);
		playing = 2;
	}
}

void Game::draw(sf::RenderTarget & target, int playing) {
	
	target.draw(backgroundSprite);
	if (playing == 1) {
		this->pH->drawPowerups(target);
		this->eH->drawEnemies(target);
		this->p1->draw(target, sf::RenderStates::Default);
		this->statusText.draw(target, sf::RenderStates::Default);
	}
	else if(playing == 0) {
		this->ExitB->draw(target, sf::RenderStates::Default);
		this->PlayB->draw(target, sf::RenderStates::Default);
		this->hsH.draw(target, sf::RenderStates::Default);
	}
	else if (playing == 2) {
		textInputBox.draw(target, sf::RenderStates::Default);
	}
}
