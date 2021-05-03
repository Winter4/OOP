#include "Cell.h"

Cell::Cell()
{
	isFilled = false;
	player = Player::EMPTY;
}

Cell::Cell(sf::RenderWindow* window, sf::Texture* chipsTexture, sf::Vector2f fieldPosition, sf::Vector2i index)
{
	// linking to the main window
	if (window != NULL) this->window = window;
	else throw std::exception("Null window pointer.");

	// linking to the chips texture
	this->chipsTexture = chipsTexture;
	sprite.setTexture(*chipsTexture);

	// setting the index
	if (index.x < 0 or index.x > 13) throw std::invalid_argument("Index x error.");
	if (index.y < 0 or index.y > 13) throw std::invalid_argument("Index y error.");
	this->index = index;

	// setting sprite position to draw it correctly
	sprite.setPosition(sf::Vector2f(fieldPosition.x + 10 + index.x * 60, fieldPosition.y + 10 + index.y * 60));

	Cell();
}

sf::Sprite& Cell::getSprite() 
{
	return sprite;
}

void Cell::setChip(Player player)
{
	// the texture is 120x60 png, so there are two squares 60x60
	// the left square is a black ship, and the right square is a white chip
	switch (player) {
	case Player::PLAYER_1:
		sprite.setTextureRect(sf::IntRect(0, 0, 60, 60));
		break;
	case Player::PLAYER_2:
		sprite.setTextureRect(sf::IntRect(60, 0, 60, 60));
		break;
	default:
		throw std::logic_error("Empty player arg.");
	}
	// setting the origin of the sprite to its center to draw it correctly
	sprite.setOrigin(sf::Vector2f(30, 30));
}