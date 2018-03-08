#ifndef STATUSTEXT_H
#define STATUSTEXT_H
#include <string>
#include <SFML\Graphics.hpp>
class StatusText :public sf::Drawable{
private:
	sf::Text text;
	sf::Font font;
public:
	StatusText();
	~StatusText();

	void setText(std::string s);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif // !STATUSTEXT_H
