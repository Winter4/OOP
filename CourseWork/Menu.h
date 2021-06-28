#pragma once
#include "TextureOwner.h"
#include "MenuTale.h"

class Menu : public TextureOwner {
private:
	sf::Texture buttonsTexture;

	MenuTale* playButton;
	MenuTale* exitButton;

	char activeButton;

public:
	Menu(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName, sf::Font* fontToSet);
	~Menu();

	void open(TextureOwner* background);
};

