#include "Triangle.h"
#include "windows.h"

void Triangle::Draw(HDC hdc)
{
	float a = 2 * size / sqrt(3.0); // ������� ������������

	MoveToEx(hdc, x, y, NULL); // ������ ������ � �������

	// ������ �������
	LineTo(hdc, x - a/2, y + size); 
	LineTo(hdc, x + a/2, y + size);
	LineTo(hdc, x, y);
}