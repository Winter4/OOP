#include "Background.h"

Background::Background(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName)
	: TextureOwner(window, position, textureFileName)
{}