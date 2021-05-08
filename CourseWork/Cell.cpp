#include "Cell.h"

sf::Sprite& Cell::getSprite() 
{
	return object;
}

void Cell::setChip(Player player)
{
	// the texture is 90x45 png, so there are two squares 45x45
	// the left square is a black ship, and the right square is a white chip
	switch (player) {
	case Player::EMPTY:
		throw std::logic_error("Empty player arg.");
		break;

	case Player::PLAYER_1:
		object.setTextureRect(sf::IntRect(0, 0, 45, 45));
		break;

	case Player::PLAYER_2:
		object.setTextureRect(sf::IntRect(46, 0, 45, 45));
		break;
	}
	object.setTexture(*texture);
}

sf::Vector2f Cell::getPosition()
{
	return object.getPosition();
}