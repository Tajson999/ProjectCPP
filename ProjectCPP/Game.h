#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "EntityHandler.h"
class Game {
private:
	Player p1;
	EntityHandler eH;
	sf::FloatRect shotRectArr[53];
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
public:
	Game();
	~Game();

	void update(sf::Time deltaTime, sf::Vector2u viewport);
	void draw(sf::RenderTarget& target);

};
#endif // !GAME_H
