#pragma once
#include "Cell.h"

class Bot {
private:
	Cell*** cellsRef;
	short attacksWeights[5][2];
	Player player;

	short checkLineAttack(Player subPlayer, sf::Vector2i currentCell, sf::Vector2i direction);
	std::pair<short, sf::Vector2i> checkAttacks(Player subPlayer, sf::Vector2i cellToCheck);

public:
	Bot(Cell*** cellsLink);
	sf::Vector2i makeMove();
	Player getPlayer();
};

