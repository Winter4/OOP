#pragma once
#include "Cell.h"

class Bot {
private:
	// cells matrix ref
	Cell*** cellsRef;
	// attack weights array
	float attacksWeights[5][2];
	// bot player
	Player player;

public:
	Bot(Cell*** cellsLink);

	// calc the most profit move
	sf::Vector2i makeMove();
	Player getPlayer();

private:
	// check the line attack, containing the cell
	float checkLineAttack(Player subPlayer, sf::Vector2i currentCell, sf::Vector2i direction);
	// check all the cell's attacks
	std::pair<float, sf::Vector2i> checkAttacks(Player subPlayer, sf::Vector2i cellToCheck);
};

