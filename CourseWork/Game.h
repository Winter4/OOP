#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Background.h"
#include "Field.h"
#include "Menu.h"
#include "Timer.h"

class Game {
private:
	sf::RenderWindow window; // main  window
	Background background; 
	Field field;

	Menu menu;
	Timer timerText;
	sf::Clock timer;
	
	bool gameOver;

public:
	Game();
	void run(); 

private:
	void processEvents();
	void update();
	void render();
};


