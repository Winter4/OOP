#include "ListQuery.h"

ListQuery::~ListQuery() {}

List ListQuery::mileageTask()
{
	List mileage;
	Node* check = head;
	for (size_t i = 0; i < this->count; i++) {
		if (check->data.mileage > 1e5) mileage.addHead(check->data);
		check = check->next;
	}

	mileage.sort();
	return mileage;
}

List ListQuery::newestCars()
{
	this->sort();
	List newest;

	Node* tmp = tail;
	for (size_t i = 0; i < 5 && tmp != nullptr; i++, tmp = tmp->prev)
		newest.addHead(tmp->data);

	return newest;
}

