#include "ChipPhantom.h"

ChipPhantom::ChipPhantom() {}

void ChipPhantom::draw()
{
	if (state) TextureOwner::draw();
}

void ChipPhantom::setPosition(sf::Vector2f positionToSet)
{
	object.setPosition(positionToSet);
}

void ChipPhantom::setCell(sf::Vector2i indexToSet)
{
	if (indexToSet.x >= 0 and indexToSet.x < CELLS_NUMBER and
		indexToSet.y >= 0 and indexToSet.y < CELLS_NUMBER) {

		index = indexToSet;
	}
	else
		throw std::invalid_argument("Invalid indexToSet while setting chipPhantom index.");
}

void ChipPhantom::setState(bool stateToSet) { state = stateToSet; }

bool ChipPhantom::getState() { return state; }

sf::Vector2i ChipPhantom::getCell() { return index; }

