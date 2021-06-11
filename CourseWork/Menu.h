#pragma once
#include "TextureOwner.h"
#include "MenuTale.h"

class Menu : public TextureOwner {
private:
	sf::Texture talesTexture;

	MenuTale* playTale;
	MenuTale* exitTale;

	char activeTale;

public:
	Menu(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName, sf::Font* fontToSet)
		: TextureOwner(window, position, textureFileName)
	{
		activeTale = 0;
		if (not talesTexture.loadFromFile("tale.png")) throw std::runtime_error("Error while tale texture loading.");

		playTale = new MenuTale(window, sf::Vector2f(sprite.getPosition().x + 83, sprite.getPosition().y + 125), &talesTexture, fontToSet, "PLAY");
		exitTale = new MenuTale(window, sf::Vector2f(sprite.getPosition().x + 83, sprite.getPosition().y + 485), &talesTexture, fontToSet, "EXIT");
	}
	~Menu();

	void open(TextureOwner* background);
};

