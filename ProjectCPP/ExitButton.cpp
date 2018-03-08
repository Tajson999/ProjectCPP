#include "ExitButton.h"
#include <iostream>

ExitButton::ExitButton(sf::Texture * texture) {
	this->setTexture(texture);
	this->setSpriteRect(sf::IntRect(581,462,40,13));
	this->setTextureSmooth();
	this->setSpritePosition(sf::Vector2f(300, 250));
	this->setSpriteScale(sf::Vector2f(2, 2));
}

ExitButton::ExitButton() {
}

ExitButton::~ExitButton() {
}

void ExitButton::update(sf::Time deltaTime) {
	
}

// && spriteTopFlank < sf::Mouse::getPosition(*window).y && sf::Mouse::getPosition(*window).y > spriteBottomFlank

void ExitButton::update(sf::Window *window, bool playing, HighScoreHandler hsH) {
	double spriteRightFlank = this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width;
	double spriteLeftFlank = this->getSprite().getGlobalBounds().left;
	double spriteBottomFlank = this->getSprite().getGlobalBounds().top + this->getSprite().getGlobalBounds().height;
	double spriteTopFlank = this->getSprite().getGlobalBounds().top;
	if(spriteLeftFlank < sf::Mouse::getPosition(*window).x && sf::Mouse::getPosition(*window).x < spriteRightFlank && spriteTopFlank < sf::Mouse::getPosition(*window).y && sf::Mouse::getPosition(*window).y < spriteBottomFlank){
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !playing) {
			cout << "closing window" << endl;
			window->close();
		}
	}
}
