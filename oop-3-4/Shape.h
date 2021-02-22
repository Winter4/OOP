#pragma once

#include <iostream>
#include "windows.h"

class Shape {
protected:
	float x; // положение по оси x
	float y; // положение по оси y
	float size; // размер фигуры (имеет разный геометрический смысл в зависимости от фигуры

	// конструктор по умолчанию; x = y = 0
	Shape();
	// конструктор с размером
	Shape(float);
	// конструктор с параметрами; x = int, y = int, size = float
	Shape(float, float, float);
	// конструктор копирования
	Shape(Shape*);

public:
	// задать местоположение
	void Place(float, float);
	// сдвинуть фигуру 
	void Move(float, float);

	// масштабировать фигуру (size *= rate; rate > 0)
	void Scale(float);

	// отрисовать фигуру согласно её местоположению
	virtual void Draw(HDC);
};