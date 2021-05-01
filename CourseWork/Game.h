#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"

class Game {
private:
	sf::RenderWindow window;
	Background background;

public:
	Game();
	void run();

private:
	void processEvents();
	void update();
	void render();
};

