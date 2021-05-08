#pragma once
#include "TextureOwner.h"

// background object
// loading a background picture - all it does
class Background : public TextureOwner {
public:
	Background(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName)
		: TextureOwner(window, position, textureFileName) 
	{}
};

