#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

using namespace sf;

int main()
{
	sf::RenderWindow window1(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Rendzu!");
	window1.setPosition(Vector2i(20, 30));
	sf::Event event1;

	while (window1.isOpen()) 
		while (window1.pollEvent(event1)) 
			if (event1.type == sf::Event::Closed) 
				window1.close();

	return 0;
}