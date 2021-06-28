#include "Game.h"

Game::Game()
	// the window is 1400x900 rect (the w-h values were chosen with hit-or-miss method)
	: window(sf::VideoMode(1400, 900), "Rendzu!")
{ 
	// font loading
	if (not gilroy.loadFromFile("gilroy.ttf")) throw std::runtime_error("Error while tale font loading.");
	
	// the background picture is the same size with the window; takes its beginning in the up left corner
	background = new Background(&window, sf::Vector2f(0, 0), "background.png");
	// the field is 860x860 square; takes its beginning in the (50; 20) vector from the up left corner (0; 0)
	field = new Field(&window, sf::Vector2f(50, 20), "field.png");
	// same to upper; the text in the menu has the gilroy font
	menu = new Menu(&window, sf::Vector2f(100, 100), "menu.png", &gilroy);
	// same to upper
	timer = new Timer(&window, &gilroy);
	// same to upper
	board = new Board(&window, sf::Vector2f(960, 485), "board.png", &gilroy);
	// just pushing the cells ref to the bot
	bot = new Bot(field->getCellsRef());

	sf::FloatRect fieldRect = field->getRectangle();
	sf::Mouse::setPosition(sf::Vector2i(fieldRect.left + fieldRect.width / 2, fieldRect.top + fieldRect.height / 2), window);

	// the player starts the game
	currentPlayer = PLAYER_1;

	gameOver = false;
	window.setFramerateLimit(60);
}

void Game::run()
{
	menu->open(background);

	timer->restart();
	// main loop
	while (window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Game::changePlayer()
{
	if (currentPlayer == Player::PLAYER_1) { 
		board->setText("Turn: \nwhite");
		currentPlayer = Player::PLAYER_2; 
	}
	else {
		board->setText("Turn: \nblack");
		currentPlayer = Player::PLAYER_1;
	}
}

void Game::resetGame()
{
	field->reset();
	gameOver = false;
	currentPlayer = Player::PLAYER_1;
	timer->refresh();
	board->setText("Make your move!");
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

	// closing the window (red X in the up right)
	case sf::Event::Closed: 
		window.close();
		break;

	case sf::Event::MouseMoved: 
		// if the cursor is hovering the field
		if (field->getRectangle().contains(sf::Vector2f(cursorPosition))) 
			field->checkCellHovering(cursorPosition);
		break;
		
	case sf::Event::MouseButtonPressed:
		// if click, try to set the chip
		if (event.key.code == sf::Mouse::Left) {
			if (field->getRectangle().contains(sf::Vector2f(cursorPosition))) 
				if (field->chipPhantomActive()) {
					gameOver = field->setChip(currentPlayer);
					changePlayer();
					timer->refresh();
				}
		}
		break;

	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Escape)
			menu->open(background);
		break;
	}
}

void Game::update()
{
	// timer ending = game over
	if (timer->getTime() <= 0) gameOver = true;

	// processing the timer
	if (timer->getElapsedTime() >= sf::seconds(1)) {
		timer->substractSecond();
		timer->restart();
	}

	// checking the bot to make a move
	if (currentPlayer == bot->getPlayer()) {
		gameOver = field->setChip(currentPlayer, bot->makeMove());
		changePlayer();
		timer->refresh();
	}

	// if game over, reload the game
	if (gameOver) {
		// board text processing
		std::string winner;
		winner = currentPlayer == Player::PLAYER_1 ? "The white chips won!" :
			"The black chips won!";
		winner += "\nPress any key to continue";
		board->setText(winner);

		// calling the render to make the text appear
		render();

		// waiting for the key to be pressed
		sf::Event event;
		while (true) {
			if (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::KeyPressed)
					break;
			}
		}

		// reseting
		resetGame();
		menu->open(background);
	}

	system("cls");
	std::cout << gameOver;
}

void Game::render()
{
	window.clear();

	background->draw();
	field->draw();
	timer->draw();
	board->draw();

	window.display();
}

Game::~Game()
{
	delete background;
	delete field;
	delete menu;
	delete timer;
	delete board;

}