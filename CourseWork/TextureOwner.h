#pragma once
#include "Object.h"

// the object, containing its own texture
// the large object
class TextureOwner : public Object {
protected:
	sf::Texture texture;

public:
	TextureOwner(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName);

	void virtual draw();
};

