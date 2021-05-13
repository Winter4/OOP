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

sf::Vector2f Field::getPosition()
{
	return object.getPosition();
}

sf::IntRect Field::getSize()
{
	return object.getTextureRect();
}

sf::FloatRect Field::getRectangle()
{
	return object.getGlobalBounds();
}

sf::Vector2i Field::checkCellHovered(sf::Vector2i lastHoveredCell, sf::Vector2i cursorPosition)
{
	// cursor is still on the last hovered cell
	if (cells[lastHoveredCell.y][lastHoveredCell.x].checkCursorHovered(cursorPosition))
		return lastHoveredCell;

	// if not, checking the around cells
	for (short i = -1; i < 2; i++) {
		// out of field check
		if (lastHoveredCell.x + i < 0 or lastHoveredCell.x + i > 14) continue;

		// out of field check
		for (short j = -1; j < 2; j++) {
			if (lastHoveredCell.y + j < 0 or lastHoveredCell.y + j > 14) continue;

			// checking itself
			if (cells[lastHoveredCell.y + j][lastHoveredCell.x + i].checkCursorHovered(cursorPosition))
				return sf::Vector2i(lastHoveredCell.y + j, lastHoveredCell.x + i);
		}
	}

	// if the cursor doesn't hover any cell, return some kind of a flag
	return { -1, -1 };
}
