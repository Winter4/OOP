#pragma once

#include "Shape.h"

class Triangle : public Shape {
private:
	// float x, y; - местоположение вершины не у основания треугольника
	// float size; - длина высота треугольника
public:
	// конструктор по умолчанию
	Triangle() : Shape() {};
	// конструктор с размером
	Triangle(float size) : Shape(size) {};
	// конструктор с параметрами
	Triangle(float x, float y, float size) : Shape(x, y, size) {};
	// конструктор копирования
	Triangle(Triangle* triangleToCopy) : Shape(triangleToCopy) {};

	// отрисовать фигуру
	void Draw(HDC);
};