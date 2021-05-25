#include "Board.h"

void Board::draw()
{
	TextureOwner::draw();
	window->draw(text);
}
