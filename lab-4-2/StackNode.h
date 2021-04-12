#pragma once
#include "Car.h"

class StackNode {
public:
	Car* data;
	StackNode* prev;

	StackNode();
	StackNode(Car&);
	~StackNode();
};