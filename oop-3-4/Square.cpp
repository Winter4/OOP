#include "Square.h"

void Square::Draw(HDC hdc)
{
	int x1, y1, x2, y2; // 1 - ����� ������� ����, 2 - ������ ������ ���� ��������������

	// ������ ��������� � ������� ���������� ����� ������� ��������� � [��. ������ �� 2] ���
	int cyclicRadius = size / sqrt(2.0); 

	// ������ ��������� � ������� ���������� = �������� �������
	x1 = x - cyclicRadius;
	y1 = y - cyclicRadius;
	x2 = x + cyclicRadius;
	y2 = y + cyclicRadius;

	Rectangle(hdc, x1, y1, x2, y2);
}