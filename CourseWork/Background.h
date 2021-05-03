#pragma once
#include "Object.h"

// background object
// loading a background picture - all it does
class Background : public Object {
public:
	Background(sf::RenderWindow* window, sf::Vector2f size, sf::Vector2f position, std::string textureFileName) :
		Object(window, size, position, textureFileName) { }
};

