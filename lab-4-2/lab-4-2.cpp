#include "iostream"
#include "string"
#include "vector"

#include "Stack.h"
#include "StackQuery.h"

int main() 
{
    std::vector<Car> cars;
    cars.push_back({ "Subaru Forester WRX STI",  1234, 30000, 2005 });
    cars.push_back({ "Mazda 6", 1221, 70000, 2010 });
    cars.push_back({ "Toyota RAV4", 8771, 20000, 2017 });
    cars.push_back({ "BMW X5M", 1256, 350000, 2000 });
    cars.push_back({ "Nissan 180SX", 14921, 400000, 1988 });
    cars.push_back({ "Turing", 16784, 0, 1936 });
    cars.push_back({ "Scoda Octavia RS", 19731, 250000, 2020 });

    Stack stack;

    for (int i = 0; i < cars.size(); i++)
        stack.push(cars[i]);

    std::cout << " Service: \n";
    stack.productionYearSort();
    stack.print();

    StackQuery stackQuery(stack);

    std::cout << "\n\n Newest cars: \n";
    stackQuery.newestCarsQuer(5).print();
    
    std::cout << "\n\n Mileage > 1e5 cars: \n";
    stackQuery.mileageQuer(100000).print();

    std::cout << std::endl;
    system("pause");
    return 0;
}