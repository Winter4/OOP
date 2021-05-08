#pragma once
#include <SFML/Graphics.hpp>

// basic textured object
class Object  {
protected:
	sf::RenderWindow* window; // main window link
	//sf::Texture texture; // texture for the rectangle
	sf::Sprite object; // main object - sprite, contanes all the settings

	Object();

public:
	// links the window and sets the size and the position
	Object(sf::RenderWindow* window, sf::Vector2f position);
	~Object();

	virtual void draw();
};

