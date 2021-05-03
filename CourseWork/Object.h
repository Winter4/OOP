#pragma once
#include <SFML/Graphics.hpp>

// basic textured object
class Object abstract {
protected:
	sf::RenderWindow* window; // main window link
	sf::RectangleShape object; // main object - rectangle shape, contanes all the settings
	sf::Texture texture; // texture for the rectangle

public:
	Object(sf::RenderWindow* window, sf::Vector2f size, sf::Vector2f position, std::string textureFileName);

	void virtual draw();
};

