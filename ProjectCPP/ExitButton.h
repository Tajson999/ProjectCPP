#ifndef EXITBUTTON_H
#define EXITBUTTON_H
#include "Entity.h"
#include "HighScoreHandler.h"
class ExitButton :public Entity {
private:

public:
	ExitButton(sf::Texture *texture);
	ExitButton();
	~ExitButton();

	void update(sf::Time deltaTime);
	void update(sf::Window *window, bool playing, HighScoreHandler hsH);

};
#endif // !EXITBUTTON_H
