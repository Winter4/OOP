#pragma once
#include "TextureOwner.h"
#include "MenuTale.h"

class Menu : public TextureOwner {
private:
	sf::Texture talesTexture;
	sf::Font font;

	MenuTale playTale;
	MenuTale settingsTale;
	MenuTale exitTale;

	char activeTale;

public:
	Menu(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName)
		: TextureOwner(window, position, textureFileName)
	{
		if (not talesTexture.loadFromFile("tale.png")) throw std::runtime_error("Error while tales texture loading.");
		if (not font.loadFromFile("gilroy.ttf")) throw std::runtime_error("Error while font loading.");

		playTale = MenuTale(window, sf::Vector2f(sprite.getPosition().x + 83, sprite.getPosition().y + 125), &talesTexture, font, "PLAY");
		exitTale = MenuTale(window, sf::Vector2f(sprite.getPosition().x + 83, sprite.getPosition().y + 485), &talesTexture, font, "EXIT");
	}

	void open(TextureOwner& background);
};

