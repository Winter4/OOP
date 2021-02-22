#pragma once
#include <math.h>
#include <iomanip>

#include "TablePrint.h"
#include "TapePrint.h"

class Handler : public TablePrint, TapePrint {
private:
	float x; // ��������
	float func; // �������� ������
	float S; // �������� �������
	float error; // �����������
	int k; // ����� �������� ����������

	std::ofstream file;

public:
	Handler();
	~Handler();

	void SetX(float);
	void SetError(float);
	void CalcParameters(float f(float));
	void Print(int, int);
};