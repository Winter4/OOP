#pragma once
#include <string>
#include <iostream>

struct Car {
	std::string model;
	unsigned serialNumber;
	unsigned mileage;
	unsigned productionYear;
};

struct Node {
	Car data;
	Node* next;
	Node* prev;
};

class List {
private:
	Node* head;
	Node* tail;
	unsigned count;

public:
	List();
	~List();

	unsigned getCount();

	void addHead(Car);
	void addTail(Car);
	void insertItem(Car, unsigned);

	void deleteItem(unsigned);
	void clearList(); 

	void printList();
	void printItem(unsigned);

	Car operator[] (unsigned);
};

