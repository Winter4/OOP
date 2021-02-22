#pragma once

#include "Shape.h"

class Triangle : public Shape {
private:
	// float x, y; - �������������� ������� �� � ��������� ������������
	// float size; - ����� ������ ������������
public:
	// ����������� �� ���������
	Triangle() : Shape() {};
	// ����������� � ��������
	Triangle(float size) : Shape(size) {};
	// ����������� � �����������
	Triangle(float x, float y, float size) : Shape(x, y, size) {};
	// ����������� �����������
	Triangle(Triangle* triangleToCopy) : Shape(triangleToCopy) {};

	// ���������� ������
	void Draw(HDC);
};