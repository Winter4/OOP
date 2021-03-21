#include <iostream>
#include "List.h"

int main()
{
	List service;
	Car subaru = { "Forester",  1234, 30000, 2005 }, mazda = { "5", 1221, 70000, 2010 }, 
		toyota{"RAV4", 8771, 20000, 2017};
	service.addHead(subaru);
	service.addHead(toyota);
	service.addTail(mazda);
	service.insertItem({ "Trueno", 1228, 500000, 1980 }, 2);

	Car myCar = service[2];
	std::cout << myCar.model;

	std::cout << std::endl;
	system("pause");
	return 0;
}
