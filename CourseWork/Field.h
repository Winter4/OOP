#pragma once
#include "TextureOwner.h"
#include "Cell.h"
#include "ChipPhantom.h"

class Field : public TextureOwner {
private:
	Cell cells[CELLS_NUMBER][CELLS_NUMBER]; // cells collection
	sf::Texture chipsTexture; // texture for the chips (2 sprites inside)

	// the phantom of the chip: shows, whether the chip can be set
	ChipPhantom chipPhantom; 

	bool checkLine(Player currentPlayer, sf::Vector2i currentCell, sf::Vector2i checkDirection);

public:
	Field(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName)
		: TextureOwner(window, position, textureFileName),
		chipPhantom(window, sf::Vector2f(0,0), "greenCross.png")
	{
		// loading chips texture
		if (!chipsTexture.loadFromFile("chips.png")) throw std::exception("Texture init error.");

		sf::Vector2f fieldPosition = sprite.getPosition();
		for (size_t i = 0; i < CELLS_NUMBER; i++)
			for (size_t j = 0; j < CELLS_NUMBER; j++) {
				// setting sprite position to draw it correctly
				// fP.x + 54: 54 is a grid's margin
				// index.x * 54: 54 is a grid cell's width (or height: square it is)
				float x = fieldPosition.x + 54 + j * 54;
				float y = fieldPosition.y + 54 + i * 54;

				// setting every cell's pos, index and fillnes (empty)
				cells[i][j] = Cell(window, sf::Vector2f(x, y), &chipsTexture, sf::Vector2i(i, j));
			}
	}

	// draw a field with all the cells
	void draw(); 
	// set chip to the pointed position with a cur player's chip
	bool setChip(Player currentPlayer);
	// get the pointed cell position
	sf::Vector2f getCellPosition(sf::Vector2i index);
	sf::Vector2f getPosition();
	sf::IntRect getSize();
	sf::FloatRect getRectangle();
	// handles the cursor hovering the cell
	void checkCellHovering(sf::Vector2i cursorPosition);
	bool chipPhantomActive();
};

