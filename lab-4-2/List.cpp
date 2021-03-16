#include "List.h"

List::List()
{
	head = tail = nullptr;
	count = 0;
}

List::~List()
{
	clearList();
}

unsigned List::getCount()
{
	return count;
}

void List::addHead(Car data)
{
	Node* newItem = new Node;

	newItem->prev = nullptr;
	newItem->next = head;
	newItem->data = data;

	if (head != nullptr)
		head->prev = newItem;

	if (count == 0)
		head = tail = newItem;
	else
		head = newItem;

	count++;
}

void List::addTail(Car data)
{
	Node* newItem = new Node;

	newItem->prev = tail;;
	newItem->next = nullptr;
	newItem->data = data;

	if (tail != nullptr)
		tail->next = newItem;

	if (count == 0)
		head = tail = newItem;
	else
		tail = newItem;

	count++;
}

void List::insertItem(Car data, unsigned position)
{
	if (position == 0 || position > count + 1) {
		std::cout << "Wrong number to insert. \n";
		return;
	}

	if (position == count + 1) {

	}
}

void List::deleteItem(unsigned position)
{
	if (position == 0 || position > count) {
		std::cout << "Wrong number to delete. \n";
		return;
	}

	Node* toDelete = head;
	unsigned index = 0;
	
	// пока не найдем нужный элемент
	while (index < position - 1) {
		toDelete = toDelete->next;
		index++;
	}

	Node* toDeletePrev = toDelete->prev;
	Node* toDeleteNext = toDelete->next;

	toDeletePrev->next = toDeleteNext;
	toDeleteNext->prev = toDeletePrev;

	if (position == 1) head = toDeleteNext;
	else if (position == count) tail = toDeletePrev;

	delete toDelete;
	count--;
}
