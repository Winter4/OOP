#include "Game.h"

Game::Game() 
	// the window is 1400x900 rect (the w-h values were chosen with hit-or-miss method)
	: window(sf::VideoMode(1400, 900), "Rendzu!"), 
	// the background picture is the same size with the window; takes its beginning in the up left corner
	background(&window, sf::Vector2f(0,0), "background.png"),
	// the field is 860x860 square; tales its beginning in the (50; 20) vector from the up left corner (0; 0)
	field(&window, sf::Vector2f(50, 20), "field2.png")
{ }

void Game::run()
{
	field.setChip(sf::Vector2i(5, 0), Player::PLAYER_2); // TEMPORARY
	field.setChip(sf::Vector2i(3, 0), Player::PLAYER_1); // TEMPORARY

	sf::Texture greenCross;
	greenCross.loadFromFile("greencross.png");
	sf::Sprite mouseTrigger;
	mouseTrigger.setTexture(greenCross);
	mouseTrigger.setOrigin(sf::Vector2f(20, 20));


	mouseTrigger.setPosition(50, 20);
	window.draw(mouseTrigger);


	// main loop
	while (window.isOpen()) {
		processEvents(mouseTrigger);
		update();
		render();
	}
}

void Game::processEvents(sf::Sprite& mouseTrigger)
{
	sf::Event event;
	window.pollEvent(event);

	sf::Vector2i cursorPosition;
	sf::Vector2f cellPosition;
	sf::Rect<int> cellArea;

	switch (event.type) {
	case sf::Event::Closed: // closing the window (red X in the up right)
		window.close();
		break;

	case sf::Event::MouseMoved: 
		/*
		cursorPosition = sf::Mouse::getPosition(window);

		for (size_t i = 0; i < CELLS_NUMBER; i++)
			for (size_t j = 0; j < CELLS_NUMBER; j++) {
				cellPosition = field.getCellPosition(sf::Vector2i(j, i));
				cellArea = sf::Rect<int>(cellPosition.x - 15, cellPosition.y - 15, cellPosition.x + 15, cellPosition.y + 15);

				sf::RectangleShape test;
				test.setPosition(sf::Vector2f(cellArea.left, cellArea.top));
				test.setSize(sf::Vector2f(cellArea.width, cellArea.height));
				test.setFillColor(sf::Color::Red);
				window.draw(test);
				//system("pause");

				if (cellArea.contains(cursorPosition)) {
					mouseTrigger.setPosition(cellPosition);
					window.draw(mouseTrigger);
					return;
					//throw std::exception("HZ");
				}
			}
			*/

		cursorPosition = sf::Mouse::getPosition(window);
		
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