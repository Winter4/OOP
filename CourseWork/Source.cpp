#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 1400
#define WINDOW_HEIGHT 900

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Rendzu!", sf::Style::Default);
	sf::Event event;
	
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("background.png");
	sf::Sprite background(backgroundTexture);

	// main loop
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.draw(background);
		window.display();
	}
	return 0;
}