#pragma once
#include "StackNode.h"
#include <iostream>

class Stack {
protected:
	StackNode* head; // ������� �������

	// ������� ����� ����� ������ �� �����
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