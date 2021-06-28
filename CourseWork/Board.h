#pragma once
#include "TextureOwner.h"

class Board : public TextureOwner {
private:
	sf::Text text;

public:
	Board(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName, sf::Font* fontToSet);

	// draw the board
	void draw();
	// set the board text
	void setText(const std::string textToSet);
};

