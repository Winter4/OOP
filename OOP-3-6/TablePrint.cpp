#include "TablePrint.h"

void TablePrint::ScreenPrint_Table(float x, float S, float func, int k)
{
	std::cout << std::setw(10) << x << "  |  "
		<< std::setw(10) << S << "  |  "
		<< std::setw(10) << func << "  |  "
		<< std::setw(10) << k << "  |  "
		<< std::endl;
}

void TablePrint::FilePrint_Table(std::ofstream& file, float x, float S, float func, int k)
{
	file << "Table: " << std::endl;
	file << std::setw(10) << x << "  |  "
		<< std::setw(10) << S << "  |  "
		<< std::setw(10) << func << "  |  "
		<< std::setw(10) << k << "  |  "
		<< std::endl;
}