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
	// конструктор с параметрами
	ShapesKit(float, float, float, float, float, float);

	~ShapesKit();

	// сдвинуть набор фигур
	void Move(float, float);
	// изменить размер набора фигур
	void Scale(float);
	// отрисовать фигуры
	void Draw(HDC);
};
