#include "Parameter.h"

Parameter::Parameter() { x = 0; y = 0; }

Parameter::Parameter(unsigned xToSet, unsigned yToSet)
{
	if (xToSet < 0 or yToSet < 0) throw std::invalid_argument("Parameter values init error.");
	
	x = xToSet;
	y = yToSet;
}
Parameter::~Parameter() {}

Parameter& Parameter::operator=(const Parameter& other)
{
	this->x = other.x;
	this->y = other.y;

	return *this;
}

Parameter& Parameter::operator=(const unsigned other)
{
	if (other < 0) throw std::invalid_argument("Parameter unsigned assignment error.");

	this->x = other;
	this->y = other;
}

bool Parameter::operator>(const Parameter& other)
{
	return this->x > other.x or this->y > other.y;
}

unsigned Parameter::getX() { return x; }
unsigned Parameter::getY() { return y; }
