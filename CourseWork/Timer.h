#pragma once
#include <SFML/Graphics.hpp>

class Timer {
private:
	sf::RenderWindow* window;

	sf::Font font;
	sf::Text text;

	sf::Clock timer;
	short time;

public:
	Timer(sf::RenderWindow* window);
	void substractSecond();
	void refresh();
	sf::Time getElapsedTime();
	void restart();
	short getTime();
	void draw();
};

