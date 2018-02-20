#include "Entity.h"

Entity::Entity() {
}

Entity::~Entity() {
}

void Entity::setTexture(string path, int x, int y, int width, int hight) {
	this->texture.loadFromFile(path,sf::IntRect(x,y,width,hight));
	this->sprite.setTexture(texture);
}

void Entity::setTexture(string path, sf::IntRect r) {
	this->texture.loadFromFile(path, r);
	this->sprite.setTexture(texture);
}

void Entity::setTexture(string path) {
	this->texture.loadFromFile(path);
	this->sprite.setTexture(texture);
}

void Entity::setTextureSmooth() {
	this->texture.setSmooth(true);
}

void Entity::setSpriteOrigin(sf::Vector2f v) {
	this->sprite.setOrigin(v);
}

void Entity::setSpriteRect(sf::IntRect r) {
	this->sprite.setTextureRect(r);
}

void Entity::moveSpriteRect(int x, int y) {
	this->sprite.setTextureRect(sf::IntRect(this->sprite.getTextureRect().left + x, this->sprite.getTextureRect().top + y, this->sprite.getTextureRect().width, this->sprite.getTextureRect().height));
}

void Entity::rotateSprite(int angel) {
	this->sprite.rotate(angel);
}

void Entity::setSpriteColor(int a, int b, int c){
	this->sprite.setColor(sf::Color(a,b,c));
}

void Entity::setSpriteScale(sf::Vector2f v){
	this->sprite.setScale(v);
}

void Entity::move(sf::Vector2f v) {
	this->sprite.move(v);
}

void Entity::setSpritePosition(sf::Vector2f v) {
	this->sprite.setPosition(v);
}

sf::Texture Entity::getTexture() {
	return this->texture;
}

sf::Sprite Entity::getSprite() {
	return this->sprite;
}

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(sprite, states);
}
