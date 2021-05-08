#include "Field.h"

void Field::setChip(sf::Vector2i index, Player currentPlayer)
{
	cells[index.y][index.x].setChip(currentPlayer);
}

void Field::draw()
{
	TextureOwner::draw(); // draw a field picture
	
	// draw all the cells (i.e. chips)
	for (size_t i = 0; i < CELLS_NUMBER; i++)
		for (size_t j = 0; j < CELLS_NUMBER; j++)
			window->draw(cells[i][j].getSprite());
}

sf::Vector2f Field::getCellPosition(sf::Vector2i index)
{
	return cells[index.y][index.x].getPosition();
}

bool Field::checkCursorContained(sf::Vector2f cursorPosition)
{
	//sf::Vector2f fieldPosition = object.getPosition(), fieldSize = object.getSize();
	//return cursorPosition.x >= object.getPosition().x and cursorPosition.x 
	return false;
}
