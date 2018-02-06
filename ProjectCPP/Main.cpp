#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Config.hpp>
#include "Player.h"
#include "EntityHandler.h"
#include <iostream>
using namespace std;
using namespace sf;
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(800, 600),"Window", sf::Style::Default);
	Clock clock;


	Player p1 = Player();
	EntityHandler eH = EntityHandler();
	eH.addBasicEnemy();
	

	//need a path for sprites to move on	array with directions?
	
	while (window.isOpen() && p1.getLife() > 0) {
		Time deltaTime = clock.restart();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
		}
		if (Keyboard::isKeyPressed(Keyboard::E)) {
			cout << "Player cords:" << p1.getSprite().getPosition().x << "," << p1.getSprite().getPosition().y << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			p1.moveRight(deltaTime);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			p1.moveLeft(deltaTime);
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			p1.moveUp(deltaTime);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			p1.moveDown(deltaTime);
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			eH.addShot(p1.getSprite().getPosition());
		}
		if (!Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Down) && !Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right)) {
			p1.setSpriteRect(IntRect(0, 0, 50, 63));
		}
		p1.update(deltaTime);
		Sprite *entityArr = new Sprite[eH.getNrOfEntities()];
		eH.updateEntites(entityArr, deltaTime);

		/*bool found = false;
		for (int i = 0; i < eH.getNrOfEnemies(); i++) {
			found = false;

			if (EnemyArr[i].getGlobalBounds().intersects(p1.getSprite().getGlobalBounds())) {
				p1.takeDamage(1);
			}
			for (int j = 0; j < sH.getNrOfShots() && found == false; j++) {
				if (EnemyArr[i].getGlobalBounds().intersects(ShotsArr[i].getGlobalBounds())) {
					eH.removeEnemy(i);
					found = true;
				}
			}
		}*/


		
		window.clear();
		for (int i = 0; i < eH.getNrOfEntities(); i++) {
			window.draw(entityArr[i]);
		}
		window.draw(p1.getSprite());



		window.display();
		delete[] entityArr;

	}
	if (p1.getLife() <= 0) {
		window.close();
	}
	getchar();

	return 0;
}