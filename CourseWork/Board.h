#pragma once
#include "TextureOwner.h"

class Board : public TextureOwner {
private:
	sf::Text text;

public:
	Board() {}
	Board(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName, sf::Font* fontToSet)
		: TextureOwner(window, position, textureFileName)
	{
		text.setFont(*fontToSet);

		text.setCharacterSize(30);
		text.setFillColor(sf::Color::White);
		setText("Make your move!");

		text.setPosition(sf::Vector2f(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2.0f,
			sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 2.0f));
	}

	void draw();
	void setText(const std::string textToSet);
};

