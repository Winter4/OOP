#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Rendzu!", sf::Style::Default);
	sf::Event event;

	// main loop
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
	}
	return 0;
}