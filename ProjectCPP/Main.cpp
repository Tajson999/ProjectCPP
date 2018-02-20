#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Config.hpp>
#include "Player.h"
#include "EntityHandler.h"
#include <iostream>
using namespace std;
 
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	View viewport(FloatRect(0,0,800,600));
	sf::RenderWindow window(sf::VideoMode(800, 600),"Window", sf::Style::Default);
	window.setView(viewport);
	Clock clock;


	Player p1 = Player();
	EntityHandler eH = EntityHandler();
	eH.spawnEnemy2(sf::Vector2f(100,100));

	Sprite *shotArr = new Sprite[50];
	int shots = 0;
	Sprite *enemyArr = new Sprite[100];
	int enemies = 0;
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
			p1.shoot();
			//out << p1.getShotCD() << endl;
		}
		if (!Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Down) && !Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right)) {
			p1.setSpriteRect(IntRect(0, 0, 50, 63));
		}
		if (Keyboard::isKeyPressed(Keyboard::C)) {
			if (p1.getMissileCD() <= 0) {
				p1.shootMissile(eH.closestEnemy(p1));
			}
		}
		eH.spawnEnemies();
		p1.update(shotArr,shots, deltaTime);
		eH.updateEntites(enemyArr, enemies, shotArr, shots,window.getSize(), deltaTime);
		p1.checkDamage(enemyArr, enemies);
		window.clear();

		for (int i = 0; i < shots; i++) {
			window.draw(shotArr[i]);
		}
		for (int i = 0; i < enemies; i++) {
			window.draw(enemyArr[i]);
		}
		window.draw(p1.getSprite());

		window.display();
		}
	if (p1.getLife() <= 0) {
		window.close();
	}
	delete[] shotArr;
	delete[] enemyArr;
	getchar();

	return 0;
}