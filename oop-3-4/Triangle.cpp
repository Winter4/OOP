#include "Triangle.h"
#include "windows.h"

void Triangle::Draw(HDC hdc)
{
	float a = 2 * size / sqrt(3.0); // сторона треугольника

	MoveToEx(hdc, x, y, NULL); // ставим курсор в вершину

	// рисуем стороны
	LineTo(hdc, x - a/2, y + size); 
	LineTo(hdc, x + a/2, y + size);
	LineTo(hdc, x, y);
}