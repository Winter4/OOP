#pragma once
#include "Cell.h"

class Bot {
private:
	// ссылка на матрицу ячеек
	Cell*** cellsRef;
	// массив весов атак
	float attacksWeights[5][2];
	// игрок, за которого играет бот
	Player player;

public:
	Bot(Cell*** cellsLink);

	// просчитать ход бота
	sf::Vector2i makeMove();
	// геттер игрока бота
	Player getPlayer();

private:
	// проверить атаку по данной линии, содержащей данную клетку
	float checkLineAttack(Player subPlayer, sf::Vector2i currentCell, sf::Vector2i direction);
	// проверить все атаки клетки
	std::pair<float, sf::Vector2i> checkAttacks(Player subPlayer, sf::Vector2i cellToCheck);
};

