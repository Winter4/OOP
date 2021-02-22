#include "TapePrint.h"

void TapePrint::ScreenPrint_Tape(float x, float S, float func, int k)
{
	std::cout << " x: " << x << "  S: " << S << "  func: " << func << "  k: " << k << std::endl;
}

void TapePrint::FilePrint_Tape(std::ofstream& file, float x, float S, float func, int k)
{
	file << " x: " << x << "  S: " << S << "  func: " << func << "  k: " << k << std::endl;
}