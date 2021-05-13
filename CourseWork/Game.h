#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Background.h"
#include "Field.h"

class Game {
private:
	sf::RenderWindow window; // main  window
	Background background; 
	Field field;

	sf::Vector2i lastHoveredCell;

public:
	Game();
	void run(); 

private:
	void processEvents();
	void update();
	void render();
};

