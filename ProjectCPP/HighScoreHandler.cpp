#include "HighScoreHandler.h"

HighScoreHandler::HighScoreHandler() {
	this->nrOf = 10;
	for (int i = 0; i < this->nrOf; i++) {
		names[i] = "";
		scores[i] = 0;
	}
	font.loadFromFile("arial.ttf");
	this->highScoreList.setFont(this->font);
	this->highScoreList.setString("");
	this->highScoreList.setCharacterSize(12);
	this->highScoreList.setPosition(sf::Vector2f(300, 300));
}

HighScoreHandler::~HighScoreHandler() {

}

void HighScoreHandler::addHighScore(int score, string name) {
	bool added = false;
	for (int i = 0; i < this->nrOf && added == false; i++) {
		cout << "i = " << i << endl;
		if (this->scores[i] <= score) {
			for (int j = this->nrOf-1; j > i; j--) {
				cout << "j = " << j << endl;
				this->scores[j] = this->scores[j - 1];
				this->names[j] = this->names[j - 1];
			}
			this->scores[i] = score;
			this->names[i] = name;
			added = true;
		}
	}
	string highScores = "";

	for (int i = 0; i < this->nrOf; i++) {
		highScores += to_string(scores[i]);
		highScores += ":   " + names[i] + "\n";

	}
	this->highScoreList.setString(highScores);

}

void HighScoreHandler::saveScoresToFile() {
	ofstream file;
	file.open("highScore.txt", ios::out);
	for (int i = 0; i < this->nrOf; i++) {
		file << scores[i] << endl;
		file << names[i] << endl;
	}
	file.close();
	cout << "Saved highscores" << endl;
}

void HighScoreHandler::loadScoresFromFile() {
	ifstream file;
	string row;
	string highScores = "";
	file.open("highScore.txt", ios::in);
	if (file.is_open()) {
		for (int i = 0; i < this->nrOf; i++) {
			getline(file, row);
			scores[i] = stoi(row);
			highScores += to_string(scores[i]);
			getline(file, row);
			names[i] = row;
			highScores += ":   " + names[i] + "\n";
		}
		file.close();
		this->highScoreList.setString(highScores);
	}
	else {
		cout << "Creating highScore file" << endl;
		ofstream file2;
		file2.open("highScore.txt");
		file2.close();
		loadScoresFromFile();
	}
	
}

void HighScoreHandler::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(this->highScoreList, states);
}
