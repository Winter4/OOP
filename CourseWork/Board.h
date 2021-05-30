#pragma once
#include "TextureOwner.h"

class Board : public TextureOwner {
private:
	sf::Font font;
	sf::Text text;

public:
	Board() {}
	Board(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName)
		: TextureOwner(window, position, textureFileName)
	{
		if (not font.loadFromFile("gilroy.ttf")) throw std::runtime_error("Error while board text loading.");
		text.setFont(font);

		text.setCharacterSize(30);
		text.setFillColor(sf::Color::White);
		setText("Make your move!");

		text.setPosition(sf::Vector2f(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2.0f,
			sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 2.0f));
	}

	void draw();
	void setText(const std::string textToSet);
};

