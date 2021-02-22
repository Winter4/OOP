#include <iostream>
#include "Handler.h"
#define PI 3.1415926535

int main()
{
	int destination;
	do {
		std::cout << " Choose the printing destination: " << std::endl
			<< "1 - Screen" << std::endl << "2 - File" << std::endl;

		std::cin >> destination;
	} while (destination < 1 || destination > 2);

	int type;
	do {
		std::cout << " Choose the printing type: " << std::endl
			<< "1 - Tape" << std::endl << "2 - Table" << std::endl;
		
		std::cin >> type;
	} while (type < 1 || type > 2);

	Handler handler;
	handler.SetError(powf(10, -6));

	
	const float dx = PI / 20.0;

	std::cout << std::endl << "Function: " << std::endl;
	if (destination == 1 && type == 2)
		std::cout << std::setw(10) << "x" << "  |  "
		<< std::setw(10) << "S" << "  |  "
		<< std::setw(10) << "func" << "  |  "
		<< std::setw(10) << "k" << "  |  "
		<< std::endl;

	for (float x = -PI / 4; x < PI / 4 + dx; x += dx) {
		handler.SetX(x);
		handler.CalcParameters(atan);
		handler.Print(destination, type);
	}

	std::cout << std::endl << std::endl;
	system("pause");
	return 0;
}