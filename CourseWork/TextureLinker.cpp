#include "TextureLinker.h"

TextureLinker::TextureLinker(sf::RenderWindow* window, sf::Vector2f position, sf::Texture* textureToLink) 
	: Object(window, position)
{
	texture = textureToLink;
}

void TextureLinker::draw()
{
	window->draw(sprite);
}