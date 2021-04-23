#pragma once
#include <stdexcept>

class Parameter {
private:
	unsigned x;
	unsigned y;

public:
	Parameter();
	Parameter(unsigned, unsigned);
	~Parameter();

	Parameter& operator = (const Parameter&);
	Parameter& operator= (const unsigned);
	// true if the rectangle, formed with 
	// the (0; 0) dot (left upper window corner) and
	// the (rightOperand.x; rightOperand.y) dot
	// doesn't contain the (leftOperand.x; leftOperand.y) dot
	bool operator > (const Parameter&);

	unsigned getX();
	unsigned getY();
};

