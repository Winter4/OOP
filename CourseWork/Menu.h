#pragma once
#include "TextureOwner.h"
#include "MenuTale.h"

class Menu : public TextureOwner {
private:
	sf::Texture talesTexture;

	MenuTale playTale;
	MenuTale settingsTale;
	MenuTale exitTale;

	char activeTale;

public:
	Menu() {}
	Menu(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName, sf::Font& font)
		: TextureOwner(window, position, textureFileName)
	{
		if (not talesTexture.loadFromFile("tale.png")) throw std::runtime_error("Error while tales texture loading.");

		playTale = MenuTale(window, sf::Vector2f(sprite.getPosition().x + 83, sprite.getPosition().y + 125), &talesTexture, font, "PLAY");
		exitTale = MenuTale(window, sf::Vector2f(sprite.getPosition().x + 83, sprite.getPosition().y + 485), &talesTexture, font, "EXIT");
	}

	void open(TextureOwner& background);
};

