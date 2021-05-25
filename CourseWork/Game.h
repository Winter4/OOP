#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Background.h"
#include "Field.h"
#include "Menu.h"
#include "Timer.h"
//#include "Board.h"

class Game {
private:
	sf::RenderWindow window; // main  window
	Background background; 
	Field field;

	Menu menu;
	Timer timer;

	sf::Font font;
	//Board board;
	
	bool gameOver;
	Player currentPlayer;

public:
	Game();
	void run(); 

private:
	void changePlayer();

	void processEvents();
	void update();
	void render();
};


