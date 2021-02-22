#pragma once
#include <math.h>
#include <iomanip>

#include "TablePrint.h"
#include "TapePrint.h"

class Handler : public TablePrint, TapePrint {
private:
	float x; // аргумент
	float func; // значение фнукци
	float S; // значение формулы
	float error; // погрешность
	int k; // номер итерации вычисления

	std::ofstream file;

public:
	Handler();
	~Handler();

	void SetX(float);
	void SetError(float);
	void CalcParameters(float f(float));
	void Print(int, int);
};