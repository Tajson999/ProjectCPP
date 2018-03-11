#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <SFML\Graphics.hpp>
using namespace std;
 
class Entity: public sf::Drawable{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:

	Entity();
	~Entity();
	void setTexture(string path, int x, int y, int width, int hight);
	void setTexture(string path, sf::IntRect r);
	void setTexture(string path);
	void setTexture(sf::Texture *texture);
	void setTextureSmooth();
	void setSpriteOrigin(sf::Vector2f v);
	void setSpriteRect(sf::IntRect r);
	void moveSpriteRect(int x, int y);
	void rotateSprite(int angel); //angel in degree
	void setSpriteColor(int a, int b, int c);
	void setSpriteScale(sf::Vector2f v);
	void move(sf::Vector2f v);
	void setSpritePosition(sf::Vector2f v);
	sf::Texture getTexture() const;
	sf::Sprite getSprite() const;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	


};
#endif // !ENTITY_H
