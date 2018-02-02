#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Config.hpp>
#include "Player.h"
#include "ShotHandler.h"
#include "BasicEnemy.h"
#include "EnemyHandler.h"
#include <iostream>
using namespace std;
using namespace sf;
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(800, 600),"Window", sf::Style::Default);
	Clock clock;


	Player p1 = Player();
	ShotHandler sH = ShotHandler();
	EnemyHandler eH = EnemyHandler();
	eH.addEnemy();


	//need a path for sprites to move on	array with directions?
	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			p1.moveRight();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			p1.moveLeft();
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			p1.moveUp();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			p1.moveDown();
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			sH.addShot(p1.getSprite().getPosition());
		}
		if (!Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Down) && !Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right)) {
			p1.setSpriteRect(IntRect(0, 0, 50, 63));
		}
		if (sH.getShotCD() != 0) {
			sH.setShotCD(sH.getShotCD() - 1);
		}
		if (clock.getElapsedTime().asSeconds() >= 5) {
			eH.addEnemy();
			clock.restart();
		}
			
		Sprite *ShotsArr = new Sprite[sH.getNrOfShots()];
		sH.updateShots(ShotsArr);

		Sprite *EnemyArr = new Sprite[eH.getNrOfEnemies()];
		eH.updateEnemies(EnemyArr);
		bool found = false;
		for (int i = 0; i < eH.getNrOfEnemies(); i++) {
			found = false;
			for (int j = 0; j < sH.getNrOfShots() && found == false; j++) {
				if (EnemyArr[i].getGlobalBounds().intersects(ShotsArr[i].getGlobalBounds())) {
					eH.removeEnemy(i);
					found = true;
				}
			}
		}


		
		window.clear();
		for (int i = 0; i < sH.getNrOfShots(); i++) {
			window.draw(ShotsArr[i]);
		}
		for (int i = 0; i < eH.getNrOfEnemies(); i++) {
			window.draw(EnemyArr[i]);
		}
		window.draw(p1.getSprite());
		window.display();
		delete[] ShotsArr;
		delete[] EnemyArr;

	}

	return 0;
}