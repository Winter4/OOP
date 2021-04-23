#include "GameObject.h"

GameObject::GameObject() 
{
	size = 0;

	position.x = 0;
	position.y = 0;
}

GameObject::GameObject(Parameter sizeToSet, sf::Vector2i positionToSet, std::string textureName)
{
	size = sizeToSet;

	if (positionToSet.x < 0 or positionToSet.y < 0) throw std::invalid_argument("Game object position init error.");

	position.x = positionToSet.x;
	position.y = positionToSet.y;


	if (!texture.loadFromFile(textureName)) throw std::runtime_error("Game object texture init error.");
}

GameObject::~GameObject() {}

// void GameObject::loadTexture(std::string fileName) { if (!texture.loadFromFile(fileName)) throw std::runtime_error("Error while texture loading."); }

void GameObject::setSprite() 
{ 
	sprite.setTexture(texture); 
}

void GameObject::draw(sf::RenderWindow* window) 
{
	window->draw(sprite);
}