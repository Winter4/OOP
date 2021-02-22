#pragma once
#include <iostream>
#include <fstream>

class TapePrint {
public:
	TapePrint() {};
	~TapePrint() {};

	void ScreenPrint_Tape(float, float, float, int);
	void FilePrint_Tape(std::ofstream&, float, float, float, int);
};