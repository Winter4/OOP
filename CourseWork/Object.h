#pragma once
#include <SFML/Graphics.hpp>

// basic textured object
class Object  {
protected:
	// main window link
	sf::RenderWindow* window; 
	// main object - sprite, contanes all the settings
	sf::Sprite sprite; 

	Object();

public:
	// links the window and sets the size and the position
	Object(sf::RenderWindow* window, sf::Vector2f position);
	~Object();

	// draw the object
	virtual void draw();
};

