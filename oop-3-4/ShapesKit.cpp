#include "ShapesKit.h"

// префикс s - square, t - triangle; S - size
ShapesKit::ShapesKit(float sX, float sY, float sS, float tX, float tY, float tS)
{
	square = new Square(sX, sY, sS);
	triangle = new Triangle(tX, tY, tS);
}

ShapesKit::~ShapesKit()
{
	delete square;
	delete triangle;
}

void ShapesKit::Move(float dX, float dY)
{
	square->Move(dX, dY);
	triangle->Move(dX, dY);
}

void ShapesKit::Scale(float rate)
{
	square->Scale(rate);
	triangle->Scale(rate);
}

void ShapesKit::Draw(HDC hdc)
{
	square->Draw(hdc);
	triangle->Draw(hdc);
}

