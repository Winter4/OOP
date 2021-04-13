#pragma once
#include "StackNode.h"
#include <iostream>

class Stack {
protected:
	StackNode* head; // верхний элемент

	// забрать самую новую машину из стека
	Car& newestCar(); 

public:
	Stack();
	Stack(Stack&);
	~Stack();

	void push(Car&);
	Car& pop();
	void print();
	StackNode* getHeadPointer();
	void reverse();
	void productionYearSort();
};