#pragma once
#include "Object.h"
class TextureOwner : public Object {
protected:
	sf::Texture texture;

public:
	TextureOwner() {}
	TextureOwner(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName) 
		: Object(window, position) 
	{
		// loading a texture
		if (!texture.loadFromFile(textureFileName)) throw std::exception("Texture init error");
		// setting the texture
		object.setTexture(texture);
	}
};

