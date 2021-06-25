#pragma once
#include "SFML/Graphics.hpp"
#include "PlayerType.h"
#include "TextureLinker.h"
#include <iostream>

#define CELLS_NUMBER 15

class Cell : public TextureLinker {
private:
	sf::Vector2i index; // cell position in the field

	bool isFilled; // true if there's a chip in this cell
	Player player; // if not empty, defines the chip's owner

public:
	//Cell(sf::RenderWindow* window, sf::Texture* chipsTexture, sf::Vector2f fieldPosition, sf::Vector2i index);
	Cell(sf::RenderWindow* window, sf::Vector2f position, sf::Texture* chipsTexture, sf::Vector2i indexToSet)
		: TextureLinker(window, position, chipsTexture)
	{
		// setting the index
		if (indexToSet.x < 0 or indexToSet.x > CELLS_NUMBER) throw std::invalid_argument("Index x error.");
		if (indexToSet.y < 0 or indexToSet.y > CELLS_NUMBER) throw std::invalid_argument("Index y error.");
		index = indexToSet;

		// setting the origin of the sprite to its center to draw it correctly
		sprite.setOrigin(sf::Vector2f(23, 23));

		isFilled = false;
		player = Player::EMPTY;
	}

	void setChip(Player newPlayer); // set the pointed player's chip
	sf::Vector2f getPosition();
	bool isCursorHovering(sf::Vector2i cursorPosition);
	bool filled();

	Player getPlayer();
	void reset();
	void draw();
};

