#pragma once
#include "TextureOwner.h"

class Board : public TextureOwner {
private:
	sf::Text text;

public:
	Board() {}
	Board(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName, sf::Font& font)
		: TextureOwner(window, position, textureFileName)
	{
		text.setFont(font);
		text.setString("ONE");

		//center text
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		text.setPosition(sf::Vector2f(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2.0f,
			sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 2.0f));
		
		text.setCharacterSize(48);
		text.setFillColor(sf::Color::Black);
		
	}

	void draw();
};

