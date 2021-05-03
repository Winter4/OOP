#include "Game.h"

Game::Game() 
	// the window is 1400x900 rect (the w-h values were chosen with hit-or-miss method)
	: window(sf::VideoMode(1400, 900), "Rendzu!"), 
	// the background picture is the same size with the window; takes its beginning in the up left corner
	background(&window, sf::Vector2f(1400, 900), sf::Vector2f(0,0), "background.png"),
	// the field is 860x860 square; tales its beginning in the (50; 20) vector from the up left corner (0; 0)
	field(&window, sf::Vector2f(860, 860), sf::Vector2f(50, 20), "gridField.png")
{ }

void Game::run()
{
	field.setChip(sf::Vector2i(0, 0), Player::PLAYER_2); // TEMPORARY
	// main loop
	while (window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	window.pollEvent(event);

	switch (event.type) {
	case sf::Event::Closed: // closing the window (red X in the up right)
		window.close();
		break;
	}
}

void Game::update()
{

}

void Game::render()
{
	window.clear();

	background.draw();
	field.draw();

	window.display();
}