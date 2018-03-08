#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "EntityHandler.h"
#include "PowerupHandler.h"
#include "ExitButton.h"
#include "PlayButton.h"
#include "StatusText.h"
#include "HighScoreHandler.h"
#include "TextInputBox.h"
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
	bool staringNewGame;
	StatusText statusText;
	HighScoreHandler hsH;
	TextInputBox textInputBox;
public:
	Game();
	~Game();

	void update(sf::Time deltaTime, sf::Vector2u viewport, sf::Window* target, int &playing);
	void draw(sf::RenderTarget& target, int playing);

};
#endif // !GAME_H
