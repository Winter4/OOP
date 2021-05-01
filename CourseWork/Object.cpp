#include "Object.h"

Object::Object(sf::RenderWindow* window, sf::Vector2f size, sf::Vector2f position, std::string textureFileName)
	: object(size)
{ 
	if (!texture.loadFromFile(textureFileName)) throw std::exception("Texture init error.");

	if (window != NULL) this->window = window;
	else throw std::exception("Null window pointer.");

	object.setPosition(position);
	object.setTexture(&texture, false);
}

void Object::draw()
{
	window->draw(object);
}