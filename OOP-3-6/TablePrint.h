#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>

class TablePrint {
public:
	TablePrint() {};
	~TablePrint() {};
	

	void ScreenPrint_Table(float, float, float, int);
	void FilePrint_Table(std::ofstream&, float, float, float, int);
};