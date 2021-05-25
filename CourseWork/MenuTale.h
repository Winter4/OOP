#pragma once
#include "TextureLinker.h"

class MenuTale : public TextureLinker {
private:
	sf::Text text;

public:
	MenuTale() {}
	MenuTale(sf::RenderWindow* window, sf::Vector2f position, sf::Texture* textureToLink, sf::Font& fontToLink, const std::string textToSet) 
		: TextureLinker(window, position, textureToLink)
	{
		sprite.setTexture(*textureToLink);

		text.setFont(fontToLink);
		text.setCharacterSize(24);
		text.setString(textToSet);
		text.setFillColor(sf::Color::Black);

		//center text
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		text.setPosition(sf::Vector2f(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2.0f,
			sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 2.0f));
	}

	void draw();
	sf::IntRect getRectangle();
	void setColor(sf::Color color);
};

