#include "PlayButton.h"
#include <iostream>

PlayButton::PlayButton(sf::Texture * texture) {
	this->setTexture(texture);
	this->setSpriteRect(sf::IntRect(581, 390, 93, 12));
	this->setTextureSmooth();
	this->setSpritePosition(sf::Vector2f(300, 150));
	this->setSpriteScale(sf::Vector2f(2, 2));
}

PlayButton::PlayButton() {
}

PlayButton::~PlayButton() {
}

void PlayButton::update(sf::Time deltaTime) {
}
void PlayButton::update(sf::Window *window, bool & playing) {
	double spriteRightFlank = this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width;
	double spriteLeftFlank = this->getSprite().getGlobalBounds().left;
	double spriteBottomFlank = this->getSprite().getGlobalBounds().top + this->getSprite().getGlobalBounds().height;
	double spriteTopFlank = this->getSprite().getGlobalBounds().top;
	if (spriteLeftFlank < sf::Mouse::getPosition(*window).x && sf::Mouse::getPosition(*window).x < spriteRightFlank && spriteTopFlank < sf::Mouse::getPosition(*window).y && sf::Mouse::getPosition(*window).y < spriteBottomFlank) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !playing) {
			cout << "staring game" << endl;
			playing = true;
		}
	}
}
