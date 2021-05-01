#include "Game.h"

Game::Game() 
	: window(sf::VideoMode(1400, 900), "Rendzu!"), 
	background(&window, sf::Vector2f(1400, 900), sf::Vector2f(0,0), "background.png")
{ }

void Game::run()
{
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
	case sf::Event::Closed:
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
	window.display();
}