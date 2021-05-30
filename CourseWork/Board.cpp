#include "Board.h"

void Board::draw()
{
	TextureOwner::draw();
	window->draw(text);
}

void Board::setText(const std::string textToSet)
{
	text.setString(textToSet);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
}