#include "Cell.h"

Cell::Cell(sf::RenderWindow* window, sf::Vector2f position, sf::Texture* chipsTexture, sf::Vector2i indexToSet) 
	: TextureLinker(window, position, chipsTexture)
{
	// setting the index
	if (indexToSet.x < 0 or indexToSet.x > CELLS_NUMBER) throw std::invalid_argument("Index x error.");
	if (indexToSet.y < 0 or indexToSet.y > CELLS_NUMBER) throw std::invalid_argument("Index y error.");
	index = indexToSet;

	// setting the origin of the sprite to its center to draw it correctly
	// 23, 23 - sprite picture center (width / 2)
	sprite.setOrigin(sf::Vector2f(23, 23));

	isFilled = false;
	player = Player::EMPTY;
}

void Cell::setChip(Player newPlayer)
{
	// the texture is 90x45 png, so there are two squares 45x45
	// the left square is a black ship, and the right square is a white chip
	switch (newPlayer) {
	case Player::EMPTY:
		throw std::logic_error("Empty player arg.");
		break;

	case Player::PLAYER_1:
		sprite.setTextureRect(sf::IntRect(0, 0, 45, 45));
		break;

	case Player::PLAYER_2:
		sprite.setTextureRect(sf::IntRect(45, 0, 45, 45));
		break;
	}
	sprite.setTexture(*texture);
	isFilled = true;
	player = newPlayer;
}

sf::Vector2f Cell::getPosition()
{
	return sprite.getPosition();
}

bool Cell::isCursorHovering(sf::Vector2i cursorPosition)
{
	//std::cout << "pos" << object.getPosition().x << "  " << object.getPosition().y << std::endl;
	sf::Vector2f cellPosition = sprite.getPosition();
	// 23 - width / 2; 46 - width
	if (sf::FloatRect(cellPosition.x - 23, cellPosition.y - 23, 46, 46).contains(cursorPosition.x, cursorPosition.y))
		return true;
	else return false;
	
}

bool Cell::filled()
{
	return isFilled;
}

Player Cell::getPlayer() { return player; }

void Cell::reset() 
{ 
	isFilled = false; 
	player = Player::EMPTY;
	sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
}

void Cell::draw()
{
	if (player != Player::EMPTY)
		TextureLinker::draw();
}