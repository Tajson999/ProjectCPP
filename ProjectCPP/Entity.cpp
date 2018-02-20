#include "Entity.h"

Entity::Entity() {
}

Entity::~Entity() {
}

void Entity::setTexture(String path, int x, int y, int width, int hight) {
	this->texture.loadFromFile(path,IntRect(x,y,width,hight));
	this->sprite.setTexture(texture);
}

void Entity::setTexture(String path, IntRect r) {
	this->texture.loadFromFile(path, r);
	this->sprite.setTexture(texture);
}

void Entity::setTexture(String path) {
	this->texture.loadFromFile(path);
	this->sprite.setTexture(texture);
}

void Entity::setTextureSmooth() {
	this->texture.setSmooth(true);
}

void Entity::setSpriteOrigin(sf::Vector2f v) {
	this->sprite.setOrigin(v);
}

void Entity::setSpriteRect(IntRect r) {
	this->sprite.setTextureRect(r);
}

void Entity::rotateSprite(int angel) {
	this->sprite.rotate(angel);
}

void Entity::setSpriteColor(int a, int b, int c)
{
	this->sprite.setColor(Color(a,b,c));
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

Texture Entity::getTexture() {
	return this->texture;
}

Sprite Entity::getSprite() {
	return this->sprite;
}
