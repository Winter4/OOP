#include "Menu.h"

Menu::Menu(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName, sf::Font* fontToSet) 
	: TextureOwner(window, position, textureFileName)
{
	activeButton = 0;
	if (not buttonsTexture.loadFromFile("tale.png")) throw std::runtime_error("Error while tale texture loading.");

	// the button locates the {83; 125} relativly to the menu rect with the PLAY text
	playButton = new MenuTale(window, sf::Vector2f(sprite.getPosition().x + 83, sprite.getPosition().y + 125), &buttonsTexture, fontToSet, "PLAY");
	// same to upper
	exitButton = new MenuTale(window, sf::Vector2f(sprite.getPosition().x + 83, sprite.getPosition().y + 485), &buttonsTexture, fontToSet, "EXIT");
}

void Menu::open(TextureOwner* background)
{
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window->close();
				break;

			// processing the buttons hovering
			case sf::Event::MouseMoved:
				// if hovers, color the button and set the active button
				if (playButton->getRectangle().contains(sf::Mouse::getPosition(*window))) {
					playButton->setColor(sf::Color::Yellow);
					activeButton = 1;
				}
				else
					if (exitButton->getRectangle().contains(sf::Mouse::getPosition(*window))) {
						exitButton->setColor(sf::Color::Yellow);
						activeButton = 2;
					}
					else {
						playButton->setColor(sf::Color::White);
						exitButton->setColor(sf::Color::White);
						activeButton = 0;
					}
				break;

			// process the button click
			case sf::Event::MouseButtonPressed:
				if (event.key.code == sf::Mouse::Left) {
					switch (activeButton) {
					case 1:
						// play click: close the menu
						return;
						break;

					case 2:
						// exit click: close the game
						window->close();
						break;
					}
				}
				break;

			case sf::Event::KeyPressed:
				// escape: close the menu
				if (event.key.code == sf::Keyboard::Escape)
					return;
				break;
			}
		}


		window->clear();

		background->draw();
		draw();
		playButton->draw();
		exitButton->draw();
		
		window->display();
	}
}

Menu::~Menu()
{
	delete playButton;
	delete exitButton;
}