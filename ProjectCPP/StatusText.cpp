#include "StatusText.h"

StatusText::StatusText() {
	font.loadFromFile("arial.ttf");
	this->text.setFont(this->font);
	this->text.setString("");
	this->text.setCharacterSize(12);
	this->text.setPosition(sf::Vector2f(5, 583));
}

StatusText::~StatusText() {
}

void StatusText::setText(std::string s) {
	this->text.setString(s);
}

void StatusText::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(this->text, states);
}
