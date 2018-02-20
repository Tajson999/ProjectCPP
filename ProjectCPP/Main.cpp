#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Config.hpp>
#include "Player.h"
#include "EntityHandler.h"
#include <iostream>
#include "Game.h"
using namespace std;
 
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::View viewport(sf::FloatRect(0,0,800,600));
	sf::RenderWindow window(sf::VideoMode(800, 600),"Window", sf::Style::Default);
	window.setView(viewport);
	sf::Clock clock;
	srand(time(NULL));
	Game game = Game();
	while (window.isOpen()) {

		sf::Time deltaTime = clock.restart();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
		}
		
		game.update(deltaTime, window.getSize());
		window.clear();
		game.draw(window);
		window.display();
	}
	getchar();

	return 0;
}