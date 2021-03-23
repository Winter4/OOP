#pragma once
#include <string>
#include <iostream>
#include <vector>

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
protected:
	Node* head;
	Node* tail;
	size_t count;

	// поменять местами 2 узла
	void swap(Node*, Node*);

public:
	List();
	List(std::vector<Car>);
	List(const List&);
	~List();

	unsigned size();

	void addHead(Car);
	void addTail(Car);
	void insertItem(Car, unsigned);

	void deleteItem(unsigned);
	void clearList(); 
	
	void printItem(unsigned);
	void printList();

	// position [1; N]
	Car operator[] (unsigned);

	// отсортировать по году выпуска
	void sort();
};

