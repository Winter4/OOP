#pragma once
#include "Stack.h"

class StackQuery:public Stack {
public:
	StackQuery();
	StackQuery(Stack&);
	Stack& newestCarsQuer(unsigned);
	Stack& mileageQuer(float);
};