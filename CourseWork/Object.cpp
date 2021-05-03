#include "Object.h"

Object::Object(sf::RenderWindow* window, sf::Vector2f size, sf::Vector2f position, std::string textureFileName)
	: object(size)
{ 
	// loading texture
	if (!texture.loadFromFile(textureFileName)) throw std::exception("Texture init error.");

	// linking to the window
	if (window != NULL) this->window = window;
	else throw std::exception("Null window pointer.");
	
	// setting the position
	object.setPosition(position);
	// texturing
	object.setTexture(&texture, false);
}

void Object::draw()
{
	window->draw(object);
}