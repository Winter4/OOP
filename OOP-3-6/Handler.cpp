#include "Handler.h"

Handler::Handler()
{
	x = 0;
	func = 0;
	S = 0;
	error = 0;
	k = 0;
	file.open("file.txt", std::ios::out);
}

Handler::~Handler()
{
	file.close();
}

void Handler::SetX(float xToSet)
{
	this->x = xToSet;
}

void Handler::SetError(float errorToSet)
{
	this->error = errorToSet;
}

void Handler::CalcParameters(float f(float))
{
	func = f(x);

	float tmp;
	float pw = 0; // степень

	k = 0;
	S = tmp = x;

	do {
		pw = 2 * k + 1;
		//tmp = (-(x * x) * (k - 0.5)) / (k + 0.5);
		tmp = powf(-1, k) * powf(x, pw) / pw;
		S += tmp;
		k++;
		//std::cout << k;
	} while (fabs(tmp) > error);
}

void Handler::Print(int destination, int type)
{
	if (destination == 1) {
		if (type == 1)
			ScreenPrint_Tape(x, S, func, k);
		else
			ScreenPrint_Table(x, S, func, k);
	}
	else {
		
		if (type == 1)
			FilePrint_Tape(file, x, S, func, k);
		else
			FilePrint_Table(file, x, S, func, k);
	}
}