#pragma once
#include "List.h"

class ListQuery : public List {
public:
	ListQuery() : List() {}
	ListQuery(const List& listToGet) : List(listToGet) {}
	~ListQuery();

	List mileageTask();
	List newestCars();
};

