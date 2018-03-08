#ifndef HIGHSCOREHANDLER_H
#define HIGHSCOREHANDLER_H
#include <string>
#include <iostream>
#include <fstream>
#include <SFML\Graphics.hpp>
using namespace std;
class HighScoreHandler: public sf::Drawable {
private:
	int nrOf;
	string names[10];
	int scores[10];
	sf::Text highScoreList;
	sf::Font font;
public:
	HighScoreHandler();
	~HighScoreHandler();

	void addHighScore(int score, string name);

	void saveScoresToFile();
	void loadScoresFromFile();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
#endif // !HIGHSCOREHANDLER_H
