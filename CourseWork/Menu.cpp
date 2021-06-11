#include "Menu.h"

void Menu::open(TextureOwner* background)
{
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window->close();
				break;

			case sf::Event::MouseMoved:
				if (playTale->getRectangle().contains(sf::Mouse::getPosition(*window))) {
					playTale->setColor(sf::Color::Yellow);
					activeTale = 1;
				}
				else
					if (exitTale->getRectangle().contains(sf::Mouse::getPosition(*window))) {
						exitTale->setColor(sf::Color::Yellow);
						activeTale = 2;
					}
					else {
						playTale->setColor(sf::Color::White);
						exitTale->setColor(sf::Color::White);
						activeTale = 0;
					}
				break;

			case sf::Event::MouseButtonPressed:
				if (event.key.code == sf::Mouse::Left) {
					switch (activeTale) {
					case 1:
						return;
						break;

					case 2:
						window->close();
						break;
					}
				}
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					return;
				break;
			}
		}


		window->clear();

		background->draw();
		draw();
		playTale->draw();
		exitTale->draw();
		
		window->display();
	}
}