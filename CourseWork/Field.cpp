#include "Field.h"

Field::~Field()
{
	for (int i = 0; i < CELLS_NUMBER; i++) {
		for (int j = 0; j < CELLS_NUMBER; j++)
			delete cells[i][j];
		delete[] cells[i];
	}
	delete[] cells;
}

bool Field::checkLine(Player currentPlayer, sf::Vector2i currentCell, sf::Vector2i line)
{
	// counts the number of straight-going chips
	short straightCount = 0;

	for (short i = 0, count = 0, direction = -1; straightCount != 5 and count < 9; i += direction, count++) {

		//if (currentCell.x + i * line.x < 0 or currentCell.x + i * line.x > 14) continue;
		//if (currentCell.y + i  * line.y < 0 or currentCell.y + i * line.y > 14) continue;
		if (currentCell.x + i * line.x < 0 or currentCell.y + i * line.y < 0) {
			direction = 1;
			i = 0;
			continue;
		}
		if (currentCell.x + i * line.x > 14 or currentCell.y + i * line.y > 14)
			break;

		if (cells[currentCell.y + i * line.y][currentCell.x + i * line.x]->getPlayer() == currentPlayer)
			straightCount++;
		else {
			if (direction == 1) break;

			direction = 1;
			i = 0;
		}
	}

	//std::cout << "Line " << line.y << " " << line.x << ": " << straightCount << std::endl;
	//if (currentPlayer == Player::PLAYER_2) system("pause");
	return straightCount == 5;
}

bool Field::setChip(Player currentPlayer)
{
	sf::Vector2i currentCell = chipPhantom.getCell();
	cells[currentCell.y][currentCell.x]->setChip(currentPlayer);
	chipPhantom.setState(false);

	// win check
	//
	return 
		checkLine(currentPlayer, currentCell, { 1,0 })		// horiznotal
		or checkLine(currentPlayer, currentCell, { 0,1 })	// vertical
		or checkLine(currentPlayer, currentCell, { 1,1 })	// main diag
		or checkLine(currentPlayer, currentCell, { 1,-1 }); // alt diag
}

bool Field::setChip(Player currentPlayer, sf::Vector2i cell)
{
	cells[cell.y][cell.x]->setChip(currentPlayer);

	return
		checkLine(currentPlayer, cell, { 0,1 })		// horiznotal
		or checkLine(currentPlayer, cell, { 1, 0 })	// vertical
		or checkLine(currentPlayer, cell, { 1,1 })	// main diag
		or checkLine(currentPlayer, cell, { -1,1 }); // alt diag
}

void Field::draw()
{
	TextureOwner::draw(); // draw a field picture
	
	// draw all the cells (i.e. chips)
	for (size_t i = 0; i < CELLS_NUMBER; i++)
		for (size_t j = 0; j < CELLS_NUMBER; j++)
			cells[i][j]->draw();

	chipPhantom.draw();
}

sf::Vector2f Field::getCellPosition(sf::Vector2i index) { return cells[index.y][index.x]->getPosition(); }

sf::Vector2f Field::getPosition() { return sprite.getPosition(); }

sf::IntRect Field::getSize() { return sprite.getTextureRect(); }

sf::FloatRect Field::getRectangle() { return sprite.getGlobalBounds(); }

Cell*** Field::getCellsRef() { return cells; }

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
			if (cells[allegedCell.y + j][allegedCell.x + i]->isCursorHovering(cursorPosition)) {
				// updating last hovered cell
				chipPhantom.setCell(sf::Vector2i(allegedCell.x + i, allegedCell.y + j));
				chipPhantom.setPosition(cells[allegedCell.y + j][allegedCell.x + i]->getPosition());

				if (!cells[allegedCell.y + j][allegedCell.x + i]->filled())
					chipPhantom.setState(true);

				return;
			}
		}
	}

	// if the cursor doesn't hover any cell
	chipPhantom.setState(false);
}

bool Field::chipPhantomActive() { return chipPhantom.getState(); }

void Field::reset()
{
	for (short i = 0; i < CELLS_NUMBER; i++)
		for (short j = 0; j < CELLS_NUMBER; j++)
			cells[i][j]->reset();
}
