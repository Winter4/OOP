#pragma once

#include <iostream>
#include "windows.h"

class Shape {
protected:
	float x; // ��������� �� ��� x
	float y; // ��������� �� ��� y
	float size; // ������ ������ (����� ������ �������������� ����� � ����������� �� ������

	// ����������� �� ���������; x = y = 0
	Shape();
	// ����������� � ��������
	Shape(float);
	// ����������� � �����������; x = int, y = int, size = float
	Shape(float, float, float);
	// ����������� �����������
	Shape(Shape*);

public:
	// ������ ��������������
	void Place(float, float);
	// �������� ������ 
	void Move(float, float);

	// �������������� ������ (size *= rate; rate > 0)
	void Scale(float);

	// ���������� ������ �������� � ��������������
	virtual void Draw(HDC);
};