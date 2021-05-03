#pragma once
#include "Object.h"
#include "Cell.h"
#define CELLS_NUMBER 14

class Field : public Object {
private:
	Cell cells[14][14]; // cells collection
	sf::Texture chipsTexture; // texture for the chips (2 sprites inside)

public:
	Field(sf::RenderWindow* window, sf::Vector2f size, sf::Vector2f position, std::string textureFileName) :
		Object(window, size, position, textureFileName) 
	{
		for (size_t i = 0; i < CELLS_NUMBER; i++)
			for (size_t j = 0; j < CELLS_NUMBER; j++)
				// setting every cell's pos, index and fillnes (empty)
				cells[i][j] = Cell(window, &chipsTexture, object.getPosition(), sf::Vector2i (i, j));

		// loading chips texture
		if(!chipsTexture.loadFromFile("chips.png")) throw std::exception("Texture init error.");
	}

	// draw a field with all the cells
	void draw(); 
	// set chip to the pointed position with a cur player's chip
	void setChip(sf::Vector2i index, Player currentPlayer);
};

