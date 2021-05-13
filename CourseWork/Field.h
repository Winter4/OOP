#pragma once
#include "TextureOwner.h"
#include "Cell.h"

class Field : public TextureOwner {
private:
	Cell cells[CELLS_NUMBER][CELLS_NUMBER]; // cells collection
	sf::Texture chipsTexture; // texture for the chips (2 sprites inside)

public:
	Field(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName)
		: TextureOwner(window, position, textureFileName)
	{
		// loading chips texture
		if (!chipsTexture.loadFromFile("chips.png")) throw std::exception("Texture init error.");

		sf::Vector2f fieldPosition = object.getPosition();
		for (size_t i = 0; i < CELLS_NUMBER; i++)
			for (size_t j = 0; j < CELLS_NUMBER; j++) {
				// setting sprite position to draw it correctly
				// fP.x + 54: 54 is a grid's margin
				// index.x * 54: 54 is a grid cell's width (or height: square it is)
				//object.setPosition(sf::Vector2f(fieldPosition.x + 54 + index.x * 54, fieldPosition.y + 54 + index.y * 54));

				float x = fieldPosition.x + 54 + j * 54;
				float y = fieldPosition.y + 54 + i * 54;
				// setting every cell's pos, index and fillnes (empty)
				cells[i][j] = Cell(window, sf::Vector2f(x, y), &chipsTexture, sf::Vector2i(i, j));
			}
	}

	// draw a field with all the cells
	void draw(); 
	// set chip to the pointed position with a cur player's chip
	void setChip(sf::Vector2i index, Player currentPlayer);
	// get the pointed cell position
	sf::Vector2f getCellPosition(sf::Vector2i index);
	sf::Vector2f getPosition();
	sf::IntRect getSize();
	sf::FloatRect getRectangle();
	// returns the cell that's hovered with the cursor
	sf::Vector2i checkCellHovered(sf::Vector2i lastHoveredCell, sf::Vector2i cursorPosition);
};

