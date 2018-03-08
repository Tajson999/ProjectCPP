#ifndef PLAYBUTTON
#define PLAYBUTTON_H
#include "Entity.h"
class PlayButton :public Entity {
private:

public:
	PlayButton(sf::Texture *texture);
	PlayButton();
	~PlayButton();

	void update(sf::Time deltaTime);
	void update(sf::Window *window, int &playing, bool &startingNewGame);

};
#endif // !EXITBUTTON_H
#pragma once
