#include "Game.h"

Game::Game()
// the window is 1400x900 rect (the w-h values were chosen with hit-or-miss method)
	: window(sf::VideoMode(1400, 900), "Rendzu!"),
	// the background picture is the same size with the window; takes its beginning in the up left corner
	background(&window, sf::Vector2f(0, 0), "background.png"),
	// the field is 860x860 square; tales its beginning in the (50; 20) vector from the up left corner (0; 0)
	field(&window, sf::Vector2f(50, 20), "field2.png")
{ 
	if (not font.loadFromFile("gilroy.ttf")) throw std::runtime_error("Error while font loading.");
	
	menu = Menu(&window, sf::Vector2f(100, 100), "menu.png", font);
	timer = Timer(&window, font);
	//board = Board(&window, sf::Vector2f(960, 485), "board.png", font);

	sf::FloatRect fieldRect = field.getRectangle();
	sf::Mouse::setPosition(sf::Vector2i(fieldRect.left + fieldRect.width / 2, fieldRect.top + fieldRect.height / 2), window);

	currentPlayer = PLAYER_1;

	gameOver = false;
	window.setFramerateLimit(60);
}

void Game::run()
{
	menu.open(background);

	timer.restart();
	// main loop
	while (window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Game::changePlayer()
{
	if (currentPlayer == Player::PLAYER_1) currentPlayer = Player::PLAYER_2;
	else currentPlayer = Player::PLAYER_1;
}

void Game::processEvents()
{
	// event handling
	sf::Event event;
	window.pollEvent(event);

	// the cursor pos inside of the game window (not the full screen!)
	sf::Vector2i cursorPosition;
	cursorPosition = sf::Mouse::getPosition(window);
	
	std::cout << std::endl << cursorPosition.x << "  " << cursorPosition.y << std::endl;

	switch (event.type) {

	case sf::Event::Closed: // closing the window (red X in the up right)
		window.close();
		break;

	case sf::Event::MouseMoved: 
		// if the cursor is hovering the field
		if (field.getRectangle().contains(sf::Vector2f(cursorPosition))) 
			field.checkCellHovering(cursorPosition);
		
		break;
		
	case sf::Event::MouseButtonPressed:
		// if click, try to set the chip
		if (event.key.code == sf::Mouse::Left) {
			if (field.getRectangle().contains(sf::Vector2f(cursorPosition))) 
				if (field.chipPhantomActive()) {
					gameOver = field.setChip(currentPlayer);
					changePlayer();
					timer.refresh();
				}
		}
		break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				menu.open(background);
	}
}

void Game::update()
{
	if (timer.getTime() <= 0) gameOver = true;

	if (timer.getElapsedTime() >= sf::seconds(1)) {
		timer.substractSecond();
		timer.restart();
	}

	if (gameOver) {
		render();

		system("cls");
		std::cout << "GAME OVER! \n";
		system("pause");

		window.close();
	}

	system("cls");
	std::cout << gameOver;
}

void Game::render()
{
	window.clear();

	background.draw();
	field.draw();
	timer.draw();
	//board.draw();

	window.display();
}