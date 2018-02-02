#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <SFML\Graphics.hpp>
using namespace std;
using namespace sf;
class Entity {
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
	void setSpriteOrigin(Vector2f v);
	void setSpriteRect(IntRect r);
	void move(Vector2f v);
	void setSpritePosition(Vector2f v);
	Texture getTexture();
	Sprite getSprite();
	


};
#endif // !ENTITY_H
