#include "App.h"

App::App()
{
	// create window
	// 1400, 900 - window sizes (W, H) - were picked up to suit 
	window = new sf::RenderWindow(sf::VideoMode(1400, 900), "Rendzu!", sf::Style::Default);

	// create background 
	// 
	background = new GameObject({ 1400, 900 }, sf::Vector2i(1000, 1000), "background.png");
	background->setSprite();

	// create field
	field = new GameObject({ 860, 860 }, sf::Vector2i(50, 20), "field.png");

	// main loop
	while (window->isOpen()) {
		while (window->pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window->close();
				break;
			}
		}

		window->clear();
		background->draw(window);
		window->display();
	}
}

App::~App()
{
	delete window;
	delete background;
	delete field;
}