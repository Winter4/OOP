#include "Square.h"

void Square::Draw(HDC hdc)
{
	int x1, y1, x2, y2; // 1 - левый верхний угол, 2 - правый нижний угол прямоугольника

	// радиус вписанной в квадрат окружности менше радиуса описанной в [кв. корень из 2] раз
	int cyclicRadius = size / sqrt(2.0); 

	// радиус вписанной в квадрат окружности = половине стороны
	x1 = x - cyclicRadius;
	y1 = y - cyclicRadius;
	x2 = x + cyclicRadius;
	y2 = y + cyclicRadius;

	Rectangle(hdc, x1, y1, x2, y2);
}