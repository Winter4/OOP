#include "Shape.h"

Shape::Shape()
{
	x = 0;
	y = 0;
	size = 0;
}

Shape::Shape(float size)
{
	this->size = size;
}

Shape::Shape(float x, float y, float size)
{
	this->x = x;
	this->y = y;
	this->size = size;
}

Shape::Shape(Shape* shapeToCopy)
{
	this->x = shapeToCopy->x;
	this->y = shapeToCopy->y;
	this->size = shapeToCopy->size;
}

void Shape::Place(float newX, float newY)
{
	x = newX;
	y = newY;
}

void Shape::Move(float dX, float dY)
{
	x += dX;
	y += dY;
}

void Shape::Scale(float rate)
{
	size *= rate;
}

void Shape::Draw(HDC hdc) {}