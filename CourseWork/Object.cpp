#include "Object.h"

Object::Object() 
{ 
	window = nullptr;
}

Object::Object(sf::RenderWindow* window, sf::Vector2f position)
{
	// linking to the window
	if (window != NULL) this->window = window;
	else throw std::exception("Null window pointer.");

	// setting the position
	sprite.setPosition(position);
}

Object::~Object() {}

void Object::draw()
{
	window->draw(sprite);
}