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

void List::addHead(Car car)
{
	// если в списке уже есть эта машина
	Node* toChange = head;
	for (size_t i = 0; i < count; i++) 
		if (toChange->data.serialNumber == car.serialNumber) {
			toChange->data.mileage = car.mileage;
			return;
		}
	
	// если такой машины нету, создаем новую ячейку	
	Node* newItem = new Node;

	newItem->prev = nullptr;
	newItem->next = head;
	newItem->data = car;

	if (head != nullptr)
		head->prev = newItem;

	if (count == 0)
		head = tail = newItem;
	else
		head = newItem;

	count++;
}

void List::addTail(Car car)
{
	// если в списке уже есть эта машина
	Node* toChange = head;
	for (size_t i = 0; i < count; i++)
		if (toChange->data.serialNumber == car.serialNumber) {
			toChange->data.mileage = car.mileage;
			return;
		}

	Node* newItem = new Node;

	newItem->prev = tail;;
	newItem->next = nullptr;
	newItem->data = car;

	if (tail != nullptr)
		tail->next = newItem;

	if (count == 0)
		head = tail = newItem;
	else
		tail = newItem;

	count++;
}

void List::insertItem(Car car, unsigned position)
{
	// если в списке уже есть эта машина
	Node* toChange = head;
	for (size_t i = 0; i < count; i++)
		if (toChange->data.serialNumber == car.serialNumber) {
			toChange->data.mileage = car.mileage;
			return;
		}

	// проверка на диапазон
	if (position == 0 || position > count + 1) {
		std::cout << "Wrong number to insert. \n";
		return;
	}
	
	// если в конец списка
	if (position == count + 1) {
		addTail(car);
		return;
	}
	else
		// если в начало списка
		if (position == 1) {
			addHead(car);
			return;
		}

	// если не в начало и не в конец 
	Node* toInsert = head;
	for (size_t i = 1; i < position; i++) 
		toInsert = toInsert->next;
	
	Node* newItem = new Node;
	Node* newItemPrev = toInsert->prev;

	newItemPrev->next = newItem;
	toInsert->prev = newItem;

	newItem->prev = newItemPrev;
	newItem->next = toInsert;
	newItem->data = car;

	count++;
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

void List::clearList()
{
	Node* tmp;
	for (; count != 0; count--) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
}

void List::printItem(unsigned position)
{
	if (!(position > 0 && position <= count)) {
		std::cout << "Wrong print position. \n";
		return;
	}

	Node* toPrint = head;
	for (size_t i = 1; i < position; i++) 
		toPrint = toPrint->next;
	
	std::cout << "Model: " << toPrint->data.model << std::endl;
	std::cout << "Serial number: " << toPrint->data.serialNumber << std::endl;
	std::cout << "Mileage: " << toPrint->data.mileage << std::endl;
	std::cout << "Production year: " << toPrint->data.productionYear << std::endl;
	std::cout << std::endl;
}

void List::printList()
{
	//Node* toPrint = head;
	for (size_t i = 1; i <= count; i++) {
		/*
		std::cout << "Model: " << toPrint->data.model << std::endl;
		std::cout << "Serial number: " << toPrint->data.serialNumber << std::endl;
		std::cout << "Mileage: " << toPrint->data.mileage << std::endl;
		std::cout << "Production year: " << toPrint->data.productionYear << std::endl;
		*/
		printItem(i);
		//toPrint = toPrint->next;
	}
}

Car List::operator[] (unsigned position)
{
	
	Node* toReturn = head;
	for (size_t i = 1; i < position; i++) {
		toReturn = toReturn->next;
	}

	return toReturn->data;
}

List List::mileageTask()
{

}

