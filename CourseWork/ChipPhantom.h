#pragma once
#include "TextureOwner.h"

#define CELLS_NUMBER 15

class ChipPhantom : public TextureOwner {
private:
	bool state;
	sf::Vector2i index;

	sf::Vector2f cellsPositions[CELLS_NUMBER][CELLS_NUMBER];

public:
	ChipPhantom();
	ChipPhantom(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName) 
		: TextureOwner(window, position, textureFileName)
	{
		state = true;
		index = sf::Vector2i(7, 7);

		sprite.setOrigin(sf::Vector2f(22.5, 22.5));
	}

	void draw();

	void setPosition(sf::Vector2f positionToSet);
	void setCell(sf::Vector2i indexToSet);
	sf::Vector2i getCell();
	void setState(bool stateToSet);
	bool getState();
};

