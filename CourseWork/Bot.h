#pragma once
#include "Cell.h"

class Bot {
private:
	Cell*** cellsRef;
	float attacksWeights[5][2];
	Player player;

public:
	Bot(Cell*** cellsLink);
	sf::Vector2i makeMove();
	Player getPlayer();

private:
	float checkLineAttack(Player subPlayer, sf::Vector2i currentCell, sf::Vector2i direction);
	std::pair<float, sf::Vector2i> checkAttacks(Player subPlayer, sf::Vector2i cellToCheck);
};

