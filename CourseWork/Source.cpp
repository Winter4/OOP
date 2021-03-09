#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

using namespace sf;

void firstWindow()
{
	sf::RenderWindow window(sf::VideoMode(500, 300), "Rendzu!");
	window.setPosition(Vector2i(400, 300));
	sf::Event event;

	int mover = 0;
	float angle = 1.0;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(Color(250, 220, 100, 0));

		CircleShape circle(50);
		circle.setFillColor(Color(230, 0, 230));
		circle.move({ float(mover++), float(mover++) });
		sf::sleep(seconds(0.5));

		CircleShape triangle(50, 3);
		triangle.setFillColor(Color(0, 0, 0));

		Transform transform;
		transform.rotate(angle);
		
		window.draw(transform, triangle);

		window.draw(circle);
		window.display();
	}
}

void secondWindow()
{
	sf::RenderWindow window(sf::VideoMode(500, 300), "Rendzu!");
	window.setPosition(Vector2i(900, 500));
	sf::Event event;

	float angle = 1.0;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(Color(250, 220, 100, 0));

		CircleShape triangle(50, 3);
		triangle.setFillColor(Color(0, 0, 0));

		Transform transform;
		transform.rotate(angle);

		window.draw()

		window.display();
	}
}

int main()
{
	Thread firstWindowThread(&firstWindow);
	firstWindowThread.launch();

	Thread secondWindowThread(&secondWindow);
	secondWindowThread.launch();
	return 0;
}