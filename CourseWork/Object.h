#pragma once
#include <SFML/Graphics.hpp>

class Object abstract {
protected:
	sf::RenderWindow* window;
	sf::RectangleShape object;
	sf::Texture texture;

public:
	Object(sf::RenderWindow* window, sf::Vector2f size, sf::Vector2f position, std::string textureFileName);

	void draw();
};

