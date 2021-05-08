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
	object.setPosition(position);
}
/*
Object::Object(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName)
{ 
	Object(window, position);

	this->texture = new sf::Texture;
	// loading texture
	if (!(*texture).loadFromFile(textureFileName)) throw std::exception("Texture init error.");
}

Object::Object(sf::RenderWindow* window, sf::Vector2f position, sf::Texture* texture)
{
	Object(window, position);

	// linking texture
	this->texture = texture;
}
*/
Object::~Object() {}

void Object::draw()
{
	window->draw(object);
}