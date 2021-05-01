#pragma once
#include "SFML/Graphics.hpp"

class Cell {
private:
	sf::Sprite sprite;

public:
	Cell(sf::Texture& texture);
};

