#include "TextInputBox.h"

TextInputBox::TextInputBox() {
	font.loadFromFile("arial.ttf");
	this->messageText.setFont(this->font);
	this->messageText.setString("Enter Your name then press Enter:");
	this->messageText.setCharacterSize(24);
	this->messageText.setPosition(sf::Vector2f(100, 300));

	this->inputText.setFont(this->font);
	this->inputText.setString("");
	this->inputText.setCharacterSize(24);
	this->inputText.setPosition(sf::Vector2f(100, 324));
}

TextInputBox::~TextInputBox() {
}

string TextInputBox::getInputText() {
	return this->inputText.getString();
}

void TextInputBox::resetInputText() {
	this->inputText.setString("");
}

void TextInputBox::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(messageText, states);
	target.draw(inputText, states);
}

void TextInputBox::update() {
	if (clock.getElapsedTime().asSeconds() > .2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			this->inputText.setString(this->inputText.getString() + "A");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
			this->inputText.setString(this->inputText.getString() + "B");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
			this->inputText.setString(this->inputText.getString() + "C");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			this->inputText.setString(this->inputText.getString() + "D");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
			this->inputText.setString(this->inputText.getString() + "E");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
			this->inputText.setString(this->inputText.getString() + "F");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
			this->inputText.setString(this->inputText.getString() + "G");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
			this->inputText.setString(this->inputText.getString() + "H");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
			this->inputText.setString(this->inputText.getString() + "I");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
			this->inputText.setString(this->inputText.getString() + "J");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			this->inputText.setString(this->inputText.getString() + "K");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
			this->inputText.setString(this->inputText.getString() + "L");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
			this->inputText.setString(this->inputText.getString() + "M");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
			this->inputText.setString(this->inputText.getString() + "N");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
			this->inputText.setString(this->inputText.getString() + "O");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
			this->inputText.setString(this->inputText.getString() + "P");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			this->inputText.setString(this->inputText.getString() + "Q");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			this->inputText.setString(this->inputText.getString() + "R");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			this->inputText.setString(this->inputText.getString() + "S");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
			this->inputText.setString(this->inputText.getString() + "T");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
			this->inputText.setString(this->inputText.getString() + "U");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
			this->inputText.setString(this->inputText.getString() + "V");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			this->inputText.setString(this->inputText.getString() + "W");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
			this->inputText.setString(this->inputText.getString() + "X");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
			this->inputText.setString(this->inputText.getString() + "Y");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			this->inputText.setString(this->inputText.getString() + "Z");
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			string input = this->inputText.getString();
			input = input.substr(0, input.size() - 1);
			this->inputText.setString(input);
			clock.restart();
		}
	}
	

}
