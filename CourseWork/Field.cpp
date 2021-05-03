#include "Field.h"

void Field::setChip(sf::Vector2i index, Player currentPlayer)
{
	cells[index.y][index.x].setChip(currentPlayer);
}

void Field::draw()
{
	Object::draw(); // draw a field picture
	
	// draw all the cells (i.e. chips)
	for (size_t i = 0; i < CELLS_NUMBER; i++)
		for (size_t j = 0; j < CELLS_NUMBER; j++)
			window->draw(cells[i][j].getSprite());
}