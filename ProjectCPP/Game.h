#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "EntityHandler.h"
#include "PowerupHandler.h"
#include "ExitButton.h"
#include "PlayButton.h"
class Game {
private:
	Player *p1;
	EntityHandler *eH;
	PowerupHandler *pH;
	ExitButton *ExitB;
	PlayButton *PlayB;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture spriteSheet;
public:
	Game();
	~Game();

	void update(sf::Time deltaTime, sf::Vector2u viewport, sf::Window* target, bool &playing);
	void draw(sf::RenderTarget& target, bool playing);

};
#endif // !GAME_H
