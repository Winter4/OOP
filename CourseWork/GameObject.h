#pragma once
#include <SFML/Graphics.hpp>
#include "Parameter.h"

class GameObject {
private:
	Parameter size;
	sf::Vector2i position;

	sf::Texture texture;
	sf::Sprite sprite;

public:
	// Implementors
	GameObject();
	GameObject(Parameter sizeToSet, sf::Vector2i positionToSet, std::string textureName);
	~GameObject();

	// Methods
	//void loadTexture(std::string);
	void setSprite();
	void draw(sf::RenderWindow*);
};

