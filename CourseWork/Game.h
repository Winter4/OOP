#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>

#include "Background.h"
#include "Field.h"
#include "Menu.h"
#include "Timer.h"
#include "Board.h"
#include "Bot.h"

class Game {
private:
	sf::RenderWindow window; // main  window
	Background* background; 
	Field* field;

	Menu* menu;
	Timer* timer;

	Board* board;
	
	Bot* bot;

	sf::Font gilroy;
	bool gameOver;
	Player currentPlayer;

public:
	Game();
	~Game();
	void run(); 

private:
	void changePlayer();
	void resetGame();

	void processEvents();
	void update();
	void render();
};

// TODO: bottom line bug 
// TODO: timer ending bug

