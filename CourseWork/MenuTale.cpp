#include "MenuTale.h"

void MenuTale::draw()
{
	TextureLinker::draw();
	window->draw(text);
}

sf::IntRect MenuTale::getRectangle()
{
	return sf::IntRect(sprite.getGlobalBounds());
}

void MenuTale::setColor(sf::Color color)
{
	sprite.setColor(color);
}
