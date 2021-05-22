#include "Field.h"

bool Field::setChip(Player currentPlayer)
{
	sf::Vector2i currentCell = chipPhantom.getCell();
	cells[currentCell.y][currentCell.x].setChip(currentPlayer);
	chipPhantom.setState(false);

	// win check
	//
	// counts the number of straight-going chips
	short straightCount = 0;

	// checking the horizontal
	for (short j = 0, count = 0, step = -1; straightCount != 5 and count < 9; j += step, count++) {
	
		if (currentCell.x + j < 0 or currentCell.x + j > 14) continue;

		if (cells[currentCell.y][currentCell.x + j].getPlayer() == currentPlayer)
			straightCount++;
		else {
			if (step == 1) break;

			step *= -1;
			j = 0;
		}
	}
	if (straightCount == 5) return true;
	else straightCount = 0;

	// checking the main diag
	for (short i = 0, count = 0, step = -1; straightCount != 5 and count < 9; i += step, count++) {

		if (currentCell.x + i < 0 or currentCell.x + i > 14 or
			currentCell.y + i < 0 or currentCell.y + i > 14)
			continue;

		if (cells[currentCell.y + i][currentCell.x + i].getPlayer() == currentPlayer)
			straightCount++;
		else {
			if (step == 1) break;

			step *= -1;
			i = 0;
		}
	}
	if (straightCount == 5) return true;
	else straightCount = 0;

	// checking the alternate diag
	for (short i = 0, count = 0, step = -1; straightCount != 5 and count < 9; i += step, count++) {

		if (currentCell.x + i < 0 or currentCell.x + i > 14 or
			currentCell.y + i < 0 or currentCell.y + i > 14)
			continue;

		if (cells[currentCell.y + i][currentCell.x - i].getPlayer() == currentPlayer)
			straightCount++;
		else {
			if (step == 1) break;

			step *= -1;
			i = 0;
		}
	}
	if (straightCount == 5) return true;
	else straightCount = 0;

	// checking the vertical
	for (short i = 0, count = 0, step = -1; straightCount != 5 and count < 9; i += step, count++) {

		if (currentCell.y + i < 0 or currentCell.y + i > 14)
			continue;

		if (cells[currentCell.y + i][currentCell.x].getPlayer() == currentPlayer)
			straightCount++;
		else {
			if (step == 1) break;

			step *= -1;
			i = 0;
		}
	}
	if (straightCount == 5) return true;
	else straightCount = 0;

	return false;
}

void Field::draw()
{
	TextureOwner::draw(); // draw a field picture
	
	// draw all the cells (i.e. chips)
	for (size_t i = 0; i < CELLS_NUMBER; i++)
		for (size_t j = 0; j < CELLS_NUMBER; j++)
			window->draw(cells[i][j].getSprite());

	chipPhantom.draw();
}

sf::Vector2f Field::getCellPosition(sf::Vector2i index) { return cells[index.y][index.x].getPosition(); }

sf::Vector2f Field::getPosition() { return object.getPosition(); }

sf::IntRect Field::getSize() { return object.getTextureRect(); }

sf::FloatRect Field::getRectangle() { return object.getGlobalBounds(); }

void Field::checkCellHovering(sf::Vector2i cursorPosition)
{
	sf::Vector2i allegedCell(cursorPosition.x / 54, cursorPosition.y / 54);

	// check the cells to contain the cursor
	for (short i = -1; i < 2; i++) {
		// out of field check
		if (allegedCell.x + i < 0 or allegedCell.x + i > 14) continue;

		// out of field check
		for (short j = -1; j < 2; j++) {
			if (allegedCell.y + j < 0 or allegedCell.y + j > 14) continue;

			// checking 
			if (cells[allegedCell.y + j][allegedCell.x + i].isCursorHovering(cursorPosition)) {
				// updating last hovered cell
				chipPhantom.setCell(sf::Vector2i(allegedCell.x + i, allegedCell.y + j));
				chipPhantom.setPosition(cells[allegedCell.y + j][allegedCell.x + i].getPosition());

				if (!cells[allegedCell.y + j][allegedCell.x + i].filled())
					chipPhantom.setState(true);

				return;
			}
		}
	}

	// if the cursor doesn't hover any cell
	chipPhantom.setState(false);
}

bool Field::chipPhantomActive() { return chipPhantom.getState(); }
