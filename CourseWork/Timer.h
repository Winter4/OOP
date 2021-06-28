#pragma once
#include <SFML/Graphics.hpp>

class Timer {
private:
	sf::RenderWindow* window;

	sf::Text text;

	// inner clock
	sf::Clock timer;
	// time in the number type
	short time;

public:
	Timer(sf::RenderWindow* window, sf::Font* fontToSet);

	void substractSecond();
	// set the time to the start
	void refresh();
	// get the time on the inner clock (the runtime)
	sf::Time getElapsedTime();
	// restart the inner clock
	void restart();
	short getTime();
	// draw the figures
	void draw();

};

