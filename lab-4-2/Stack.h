#pragma once
#include "StackNode.h"

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
	Car& peek();
	void print();
	StackNode* getHeadPointer();
	void reverse();
	void productionYearSort();
};