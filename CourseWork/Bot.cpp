#include "Bot.h"

Bot::Bot(Cell*** cellsLink)
{
	cellsRef = cellsLink;
	player = Player::PLAYER_2;

	// [power][potential] weight
	attacksWeights[0][0] = 0.1;  // 1 1
	attacksWeights[1][0] = 2;	 // 2 1
	attacksWeights[2][0] = 4;	 // 3 1
	attacksWeights[3][0] = 6;	 // 4 1
	attacksWeights[4][0] = 200;  // 5 1

	attacksWeights[0][1] = 0.25; // 1 2
	attacksWeights[1][1] = 5;	 // 2 2
	attacksWeights[2][1] = 7;	 // 3 2
	attacksWeights[3][1] = 100;	 // 4 2
	attacksWeights[4][1] = 200;	 // 5 2
}

float Bot::checkLineAttack(Player subPlayer, sf::Vector2i currentCell, sf::Vector2i line)
{
	Player antiSubPlayer = subPlayer == Player::PLAYER_1 ? Player::PLAYER_2 : Player::PLAYER_1;
	short power = 1;
	short potential = 0;
	short attackPlace = 1;
	
	bool flag = true;
	for (short i = -1, direction = -1; flag; i += direction) {
		// in-board check
		if (currentCell.x + i * line.x < 0 or currentCell.x + i * line.x > 14
			or currentCell.y + i * line.y < 0 or currentCell.y + i * line.y > 14) 
		{
			if (direction == 1) break;
			else {
				direction = 1;
				i = 0;
				continue;
			}
		}
		
		// checking main attack
		if (cellsRef[currentCell.y + i * line.y][currentCell.x + i * line.x]->getPlayer() == subPlayer) {
			power++;
			attackPlace++;
		}
		else {
			// attack is locked
			if (cellsRef[currentCell.y + i * line.y][currentCell.x + i * line.x]->getPlayer() == antiSubPlayer) {
				if (direction == 1) break;
				else {
					direction = 1;
					i = 0;
					continue;
				}
			}
			// free place for attack continuing
			else {
				potential++;
				attackPlace++;

				// checking free place for the amount of free place
				for (short j = i + direction; attackPlace < 5; j += direction, i = j) {

					// in-board check
					if (currentCell.x + j * line.x < 0 or currentCell.x + j * line.x > 14
						or currentCell.y + j * line.y < 0 or currentCell.y + j * line.y > 14)
					{
						break;
					}

					// if the cell is empty
					if (cellsRef[currentCell.y + j * line.y][currentCell.x + j * line.x]->getPlayer() == Player::EMPTY)
						attackPlace++;
					else {
						if (cellsRef[currentCell.y + j * line.y][currentCell.x + j * line.x]->getPlayer() == subPlayer)
							attackPlace++;
						else 
							break;
					}
				}
				if (direction == 1) flag = false;
				else {
					direction = 1;
					i = 0;
				}
			}
		}
	}

	if (attackPlace < 5) return 0;
	if (power < 5 and potential == 0) return 0;

	if (power > 5) power = 5;
	//std::cout << attacksWeights[power - 1][potential - 1];
	return attacksWeights[power - 1][potential - 1];
}

std::pair<float, sf::Vector2i> Bot::checkAttacks(Player subPlayer, sf::Vector2i cellToCheck)
{
	float maxWeight = 0;
	sf::Vector2i cellToMove;
	
	float weight = 0;

	weight = checkLineAttack(subPlayer, cellToCheck, sf::Vector2i(1, 0));
	if (weight > maxWeight) {
		maxWeight = weight;
		cellToMove = cellToCheck;
	}
	
	weight = checkLineAttack(subPlayer, cellToCheck, sf::Vector2i(0, 1));
	if (weight > maxWeight) {
		maxWeight = weight;
		cellToMove = cellToCheck;
	}

	weight = checkLineAttack(subPlayer, cellToCheck, sf::Vector2i(1, 1));
	if (weight > maxWeight) {
		maxWeight = weight;
		cellToMove = cellToCheck;
	}

	weight = checkLineAttack(subPlayer, cellToCheck, sf::Vector2i(1, -1));
	if (weight > maxWeight) {
		maxWeight = weight;
		cellToMove = cellToCheck;
	}

	return { maxWeight, cellToMove };
}

sf::Vector2i Bot::makeMove()
{
	float maxWeight = 0;
	sf::Vector2i cellToMove;
	//std::cout << "TEST" << std::endl;

	for (short i = 0; i < CELLS_NUMBER; i++) 
		for (short j = 0; j < CELLS_NUMBER; j++) {
			
			if (cellsRef[i][j]->getPlayer() == Player::EMPTY) {
				
				std::pair<float, sf::Vector2i> analise;

				analise = checkAttacks(Player::PLAYER_2, sf::Vector2i(j, i));

				if (analise.first > maxWeight) {
					maxWeight = analise.first;
					cellToMove = analise.second;
				}
				
				analise = checkAttacks(Player::PLAYER_1, sf::Vector2i(j, i));
				if (analise.first > maxWeight) {
					maxWeight = analise.first;
					cellToMove = analise.second;
				}
			}

			//std::cout << i + 1 << " " << j + 1 << " | " << maxWeight 
			//	<< " | " << cellToMove.y + 1 << " " << cellToMove.x + 1 << std::endl;
		}

	//std::cout << std::endl << std::endl << maxWeight << "  " << cellToMove.y << " " << cellToMove.x << std::endl;
	//system("pause");
	return cellToMove;
}

Player Bot::getPlayer() { return player; }
