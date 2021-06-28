#include "ChipPhantom.h"

ChipPhantom::ChipPhantom(sf::RenderWindow* window, sf::Vector2f position, std::string textureFileName) 
	: TextureOwner(window, position, textureFileName)
{
	state = true;
	index = sf::Vector2i(7, 7);

	// 22.5 - width / 2
	sprite.setOrigin(sf::Vector2f(22.5, 22.5));
}

void ChipPhantom::draw()
{
	if (state) TextureOwner::draw();
}

void ChipPhantom::setPosition(sf::Vector2f positionToSet)
{
	sprite.setPosition(positionToSet);
}

void ChipPhantom::setCell(sf::Vector2i indexToSet)
{
	// in-board check
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

