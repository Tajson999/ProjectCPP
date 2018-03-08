#ifndef TEXTINPUTBOX_H
#define TEXTINPUTBOX_H
#include <SFML\Graphics.hpp>
#include <string>
using namespace std;
class TextInputBox :public sf::Drawable{
private:
	sf::Text messageText;
	sf::Text inputText;
	sf::Font font;
	sf::Clock clock;
public:
	TextInputBox();
	~TextInputBox();

	string getInputText();
	void resetInputText();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update();
};


#endif // !TEXTINPUTBOX_H
