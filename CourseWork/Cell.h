#pragma once
#include "SFML/Graphics.hpp"
#include "PlayerType.h"
#include "TextureLinker.h"
#include <iostream>

#define CELLS_NUMBER 15

class Cell : public TextureLinker {
private:
	// cell position in the field
	sf::Vector2i index; 

	// true if there's a chip in this cell
	bool isFilled; 
	// if not empty, defines the chip's owner
	Player player; 

public:
	Cell(sf::RenderWindow* window, sf::Vector2f position, sf::Texture* chipsTexture, sf::Vector2i indexToSet);
		
	// set the pointed player's chip
	void setChip(Player newPlayer); 
	sf::Vector2f getPosition();
	// returns true if the cursor hovers the object
	bool isCursorHovering(sf::Vector2i cursorPosition);
	// returns true if there is any chip in the cell
	bool filled();

	Player getPlayer();
	// game restarting
	void reset();
	// draw the chip if it is
	void draw();
};

