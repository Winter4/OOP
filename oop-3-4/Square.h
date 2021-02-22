#pragma once
#include "Shape.h"
#include "windows.h"

class Square : public Shape {
private:
	// float x, y; - местоположение точки пересечения дигоналей квадрата
	// float size; - радиус описанной вокруг квадрата окружности
public:
	// конструктор по умолчанию
	Square() : Shape() {};
	// конструктор с размером
	Square(float size) : Shape(size) {};
	// конструктор с параметрами
	Square(float x, float y, float size) : Shape(x, y, size) {};
	// конструктор копирования
	Square(Square* squareToCopy) : Shape(squareToCopy) {};

	// отрисовать фигуру
	void Draw(HDC);
};