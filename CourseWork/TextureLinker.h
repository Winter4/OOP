#pragma once
#include "Object.h"

class TextureLinker : public Object {
protected:
	sf::Texture* texture;

public:
	TextureLinker() {}
	TextureLinker(sf::RenderWindow* window, sf::Vector2f position, sf::Texture* textureToLink)
		: Object(window, position)
	{
		texture = textureToLink;
	}

	void draw();
};

