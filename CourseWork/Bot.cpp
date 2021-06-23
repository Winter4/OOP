#include "Bot.h"

Bot::Bot(Cell*** cellsLink)
{
	cellsRef = cellsLink;
	player = Player::PLAYER_2;

	// [power][potential] weight
	attacksWeights[0][0] = 0.1;  // 1 1
	attacksWeights[1][0] = 2;	// 2 1
	attacksWeights[2][0] = 4;	// 3 1
	attacksWeights[3][0] = 6;	// 4 1
	attacksWeights[4][0] = 200;  // 5 1

	attacksWeights[0][1] = 0.25; // 1 2
	attacksWeights[1][1] = 5;	// 2 2
	attacksWeights[2][1] = 7;	// 3 2
	attacksWeights[3][1] = 100;	// 4 2
	attacksWeights[4][1] = 200;	// 5 2
}

short Bot::checkLineAttack(Player subPlayer, sf::Vector2i currentCell, sf::Vector2i line)
{
	Player antiSubPlayer = subPlayer == Player::PLAYER_1 ? Player::PLAYER_2 : Player::PLAYER_1;
	short power = 1;
	short potential = 0;
	short attackPlace = 1;
	
	for (short i = -1, direction = -1; ; i += direction) {
		if (currentCell.x + i * line.x < 0 or currentCell.x + i * line.x > 14) 
			if (direction == 1) break;
			else {
				direction = 1;
				i = 0;
			}
		if (currentCell.y + i * line.y < 0 or currentCell.y + i * line.y > 14) 
			if (direction == 1) break;
			else {
				direction = 1;
				i = 0;
			}
		
		// checking main attack
		if (cellsRef[currentCell.y + i * line.y][currentCell.x + i * line.x]->getPlayer() == subPlayer) {
			power++;
			attackPlace++;
		}
		else {
			// attack is locked
			if (cellsRef[currentCell.y + i * line.y][currentCell.x + i * line.x]->getPlayer() == antiSubPlayer) {
				direction = 1;
				i = 0;
			}
			// attack isn't continued, but is't free to be
			else if (cellsRef[currentCell.y + i * line.y][currentCell.x + i * line.x]->getPlayer() == Player::EMPTY) {
				potential++;
				attackPlace++;

				// checking free place for the amount of free place
				for (short j = i + direction; attackPlace < 5; j += direction) {

					// the line is over
					if (currentCell.x + j * line.x < 0 or currentCell.x + j * line.x > 14) break;
					if (currentCell.y + j * line.y < 0 or currentCell.y + j * line.y > 14) break;

					if (cellsRef[currentCell.y + i * line.y][currentCell.x + i * line.x]->getPlayer() == Player::EMPTY)
						attackPlace++;
					else if (cellsRef[currentCell.y + i * line.y][currentCell.x + i * line.x]->getPlayer() == subPlayer)
						if (direction != 1) {
							direction = 1;
							i = 0;
						}
					else break;
				}
			}
			if (direction == 1) break;
		}
	}

	if (attackPlace < 5) return 0;
	if (power < 5 and potential == 0) return 0;

	if (power > 5) power = 5;
	return attacksWeights[power - 1][potential - 1];
}

std::pair<short, sf::Vector2i> Bot::checkAttacks(Player subPlayer, sf::Vector2i cellToCheck)
{
	short maxWeight = 0;
	sf::Vector2i cellToMove;
	

	if (checkLineAttack(subPlayer, cellToCheck, sf::Vector2i(1, 0)) > maxWeight) {
		maxWeight = checkLineAttack(subPlayer, cellToCheck, sf::Vector2i(1, 0));
		cellToMove = cellToCheck;
	}
	
	if (checkLineAttack(subPlayer, cellToCheck, sf::Vector2i(0, 1)) > maxWeight) {
		maxWeight = checkLineAttack(subPlayer, cellToCheck, sf::Vector2i(0, 1));
		cellToMove = cellToCheck;
	}
	if (checkLineAttack(subPlayer, cellToCheck, sf::Vector2i(1, 1)) > maxWeight) {
		maxWeight = checkLineAttack(subPlayer, cellToCheck, sf::Vector2i(1, 1));
		cellToMove = cellToCheck;
	}
	if (checkLineAttack(subPlayer, cellToCheck, sf::Vector2i(1, -1)) > maxWeight) {
		maxWeight = checkLineAttack(subPlayer, cellToCheck, sf::Vector2i(1, -1));
		cellToMove = cellToCheck;
	}

	return { maxWeight, cellToMove };
}

sf::Vector2i Bot::makeMove()
{
	short maxWeight = 0;
	sf::Vector2i cellToMove;

	for (short i = 0; i < CELLS_NUMBER; i++) 
		for (short j = 0; j < CELLS_NUMBER; j++) {
			
			if (cellsRef[i][j]->getPlayer() == Player::EMPTY) {
				
				if (checkAttacks(Player::PLAYER_2, sf::Vector2i(i, j)).first > maxWeight) {
					maxWeight = checkAttacks(Player::PLAYER_2, sf::Vector2i(i, j)).first;
					cellToMove = checkAttacks(Player::PLAYER_2, sf::Vector2i(i, j)).second;
				}
				std::cout << "\n TEST";
				if (checkAttacks(Player::PLAYER_1, sf::Vector2i(i, j)).first > maxWeight) {
					maxWeight = checkAttacks(Player::PLAYER_1, sf::Vector2i(i, j)).first;
					cellToMove = checkAttacks(Player::PLAYER_1, sf::Vector2i(i, j)).second;
				}
			}
		}

	return cellToMove;
}

Player Bot::getPlayer() { return player; }
