#pragma once
#include "Shape.h"
#include "windows.h"

class Square : public Shape {
private:
	// float x, y; - �������������� ����� ����������� ��������� ��������
	// float size; - ������ ��������� ������ �������� ����������
public:
	// ����������� �� ���������
	Square() : Shape() {};
	// ����������� � ��������
	Square(float size) : Shape(size) {};
	// ����������� � �����������
	Square(float x, float y, float size) : Shape(x, y, size) {};
	// ����������� �����������
	Square(Square* squareToCopy) : Shape(squareToCopy) {};

	// ���������� ������
	void Draw(HDC);
};