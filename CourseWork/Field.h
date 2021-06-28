#pragma once
#include "TextureOwner.h"
#include "Cell.h"
#include "ChipPhantom.h"

class Field : public TextureOwner {
private:
	// cells collection
	Cell*** cells; 
	// texture for the chips (2 sprites inside)
	sf::Texture chipsTexture; 

	// the phantom of the chip: shows, whether the chip can be set
	ChipPhantom chipPhantom; 

public:
	Field(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName);
	~Field();

	// draw a field with all the cells
	void draw(); 
	// set chip to the pointed position with a cur player's chip
	bool setChip(Player currentPlayer);
	bool setChip(Player currentPlayer, sf::Vector2i cell);

	// get the pointed cell position
	sf::Vector2f getCellPosition(sf::Vector2i index);
	// get field ...
	sf::Vector2f getPosition();
	sf::IntRect getSize();
	sf::FloatRect getRectangle();

	Cell*** getCellsRef();
	// handles the cursor hovering the cell
	void checkCellHovering(sf::Vector2i cursorPosition);
	// true if the chip phantom is active
	bool chipPhantomActive();
	// for game restarting
	void reset();

private:
	// check the line to win
	bool checkLine(Player currentPlayer, sf::Vector2i currentCell, sf::Vector2i checkDirection);
};

