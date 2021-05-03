#pragma once
#include "SFML/Graphics.hpp"
#include "PlayerType.h"

class Cell {
private:
	sf::RenderWindow* window; // main window link
	sf::Texture* chipsTexture; // chips texture link
	sf::Sprite sprite; // chip sprite (white or black chip)
	sf::Vector2i index; // cell position in the field

	bool isFilled; // true if there's a chip in this cell
	Player player; // if not empty, defines the chip's owner

public:
	Cell();
	Cell(sf::RenderWindow* window, sf::Texture* chipsTexture, sf::Vector2f fieldPosition, sf::Vector2i index);

	sf::Sprite& getSprite(); // returns the sprite link
	void setChip(Player player); // set the pointed player's chip
};

