#include "Game.h"

Game::Game() 
	// the window is 1400x900 rect (the w-h values were chosen with hit-or-miss method)
	: window(sf::VideoMode(1400, 900), "Rendzu!"), 
	// the background picture is the same size with the window; takes its beginning in the up left corner
	background(&window, sf::Vector2f(0,0), "background.png"),
	// the field is 860x860 square; tales its beginning in the (50; 20) vector from the up left corner (0; 0)
	field(&window, sf::Vector2f(50, 20), "field2.png")
{ 
	sf::FloatRect fieldRect = field.getRectangle();
	sf::Mouse::setPosition(sf::Vector2i(fieldRect.left + fieldRect.width / 2, fieldRect.top + fieldRect.height / 2), window);
	lastHoveredCell = sf::Vector2i(7, 7);

	window.setFramerateLimit(60);
}

void Game::run()
{
	field.setChip(sf::Vector2i(5, 0), Player::PLAYER_2); // TEMPORARY
	field.setChip(sf::Vector2i(3, 0), Player::PLAYER_1); // TEMPORARY

	// main loop
	while (window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	// event handling
	sf::Event event;
	window.pollEvent(event);

	// the cursor pos inside of the game window (not the full screen!)
	sf::Vector2i cursorPosition;
	cursorPosition = sf::Mouse::getPosition(window);

	// creating the rect to use its contains() method
	sf::FloatRect fieldRect = field.getRectangle();

	switch (event.type) {

	case sf::Event::Closed: // closing the window (red X in the up right)
		window.close();
		break;

	case sf::Event::MouseMoved: 
		// if the cursor is hovering the field
		if (fieldRect.contains(sf::Vector2f(cursorPosition))) {
			lastHoveredCell = field.checkCellHovered(lastHoveredCell, cursorPosition);

			//system("cls");
			if (lastHoveredCell == sf::Vector2i(-1, -1)) std::cout << "none" << std::endl;
			std::cout << lastHoveredCell.x << "  " << lastHoveredCell.y;
		}
		break;
		
	case sf::Event::MouseButtonPressed:
		if (event.key.code == sf::Mouse::Left) {
			if (fieldRect.contains(sf::Vector2f(cursorPosition))) {
				int allegedX = cursorPosition.x / 54, allegedY = cursorPosition.y / 54;
				field.setChip(sf::Vector2i(allegedX - 1, allegedY - 1), Player::PLAYER_1);
			}
		}
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