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

bool Field::isCellHovered(sf::Vector2i allegedCell, sf::Vector2i& lastHoveredCell, sf::Vector2i cursorPosition)
{
	// check the cells to contain the cursor
	for (short i = -1; i < 2; i++) {
		// out of field check
		if (allegedCell.x + i < 0 or allegedCell.x + i > 14) continue;

		// out of field check
		for (short j = -1; j < 2; j++) {
			if (allegedCell.y + j < 0 or allegedCell.y + j > 14) continue;

			// checking 
			if (cells[allegedCell.y + j][allegedCell.x + i].isCursorHovering(cursorPosition)) {
				lastHoveredCell.x = allegedCell.x + i;
				lastHoveredCell.y = allegedCell.y + j;
				return true;
			}
		}
	}

	// if the cursor doesn't hover any cell
	return false;
}
