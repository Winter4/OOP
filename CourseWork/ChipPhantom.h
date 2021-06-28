#pragma once
#include "TextureOwner.h"

#define CELLS_NUMBER 15

class ChipPhantom : public TextureOwner {
private:
	// true if the cursor hovers the cell
	bool state;
	// if state == true, the index of the hovered cell
	sf::Vector2i index;

	// window cells coordinates 
	sf::Vector2f cellsPositions[CELLS_NUMBER][CELLS_NUMBER];

public:
	ChipPhantom(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName);

	// draw if it's active
	void draw();

	void setPosition(sf::Vector2f positionToSet);
	// set cell index
	void setCell(sf::Vector2i indexToSet);
	sf::Vector2i getCell();
	void setState(bool stateToSet);
	bool getState();
};

