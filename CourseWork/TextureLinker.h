#pragma once
#include "Object.h"

// the object, containing the link to the texter
// some objects-parts of the one large object
class TextureLinker : public Object {
protected:
	// texture link
	sf::Texture* texture;

public:
	TextureLinker(sf::RenderWindow* window, sf::Vector2f position, sf::Texture* textureToLink);

	void virtual draw();
};

