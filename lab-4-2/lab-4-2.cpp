#include <iostream>
#include "List.h"
#include "ListQuery.h"

int main()
{
	std::vector<Car> cars;
	cars.push_back({ "Subaru Forester",  1234, 30000, 2005 });
	cars.push_back({ "Mazda 6", 1221, 70000, 2010 });
	cars.push_back({ "Toyota RAV4", 8771, 20000, 2017 });
	cars.push_back({ "BMW X5", 1256, 350000, 2000 });
	cars.push_back({ "Nissan 180SX", 14921, 400000, 1988 });
	cars.push_back({ "Turing", 16784, 0, 1936 });
	cars.push_back({ "Scoda Octavia", 19731, 250000, 2020 });

	List service(cars);
	service.insertItem({ "Trueno", 1228, 500000, 1980 }, 2);


	std::cout << "_____ Service: _________________\n\n\n";
	service.sort();
	service.printList();

	ListQuery serviceQuery(service);
	std::cout << "______ Mileage: ________________\n\n\n";
	serviceQuery.mileageTask().printList();

	std::cout << "______ Newest: ________________\n\n\n";
	serviceQuery.newestCars().printList();

	std::cout << std::endl;
	system("pause");
	return 0;
}
