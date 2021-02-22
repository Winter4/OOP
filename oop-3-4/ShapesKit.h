#pragma once

#include "Shape.h"
#include "Square.h"
#include "triangle.h"

class ShapesKit {
private:
	Square* square;
	Triangle* triangle;
	
public:
	ShapesKit();
	// ����������� � �����������
	ShapesKit(float, float, float, float, float, float);

	~ShapesKit();

	// �������� ����� �����
	void Move(float, float);
	// �������� ������ ������ �����
	void Scale(float);
	// ���������� ������
	void Draw(HDC);
};
