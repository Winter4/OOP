#pragma once
#include <SFML/Graphics.hpp>

class Timer {
private:
	sf::RenderWindow* window;

	sf::Font font;
	sf::Text text;

	short time;

public:
	Timer(sf::RenderWindow* window);
	void substractSecond();
	void refresh();
	void draw();
};

