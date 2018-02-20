#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <SFML\Graphics.hpp>
using namespace std;
 
class Entity; public sf::Drawable{
private:
	Texture texture;
	Sprite sprite;
public:
	Entity();
	~Entity();
	void setTexture(String path, int x, int y, int width, int hight);
	void setTexture(String path, IntRect r);
	void setTexture(String path);
	void setTextureSmooth();
	void setSpriteOrigin(sf::Vector2f v);
	void setSpriteRect(IntRect r);
	void rotateSprite(int angel); //angel in degree
	void setSpriteColor(int a, int b, int c);
	void setSpriteScale(sf::Vector2f v);
	void move(sf::Vector2f v);
	void setSpritePosition(sf::Vector2f v);
	Texture getTexture();
	Sprite getSprite();
	virtual void update(Time deltaTime) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) = 0;
	


};
#endif // !ENTITY_H
