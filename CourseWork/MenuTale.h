#pragma once
#include "TextureLinker.h"

class MenuTale : public TextureLinker {
private:
	sf::Text text;

public:
	MenuTale(sf::RenderWindow* window, sf::Vector2f position, sf::Texture* textureToLink, sf::Font* fontToSet, const std::string textToSet);

	// draw the button
	void draw();
	sf::IntRect getRectangle();
	void setColor(sf::Color color);
};

