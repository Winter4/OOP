#include "Board.h"

void Board::draw()
{
	TextureOwner::draw();
	window->draw(text);
}

void Board::setText(const std::string textToSet)
{
	text.setString(textToSet);
}