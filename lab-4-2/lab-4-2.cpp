#define _CRT_SECURE_NO_WARNINGS

#include "iostream"
#include "string"
#include "vector"

#include "Stack.h"
#include "StackQuery.h"


void readFile(std::vector<Car>* cars)
{
    char model[20] = " ";
    Car tmp;
    unsigned serial = 0, mileage = 0, year = 0;
    FILE* file = fopen("file.txt", "r");
    rewind(file);
    while (!feof(file)) {
        fscanf(file, "%s%d%d%d", &model, &serial, &mileage, &year);

        tmp.setModel(model);
        tmp.setSerialNumber(serial);
        tmp.setMileage(mileage);
        tmp.setProductionYear(year);

        (*cars).push_back(tmp);
    }
    fclose(file);
}


int main() 
{
    std::vector<Car> cars;
    /*
    cars.push_back({ "Subaru Forester",  1271856, 30000, 2005 });
    cars.push_back({ "Mazda 6", 1291056, 70000, 2010 });
    cars.push_back({ "Toyota RAV4", 8771318, 20000, 2017 });
    cars.push_back({ "BMW X5M", 1256097, 350000, 2000 });
    cars.push_back({ "Nissan 180SX", 1492104, 400000, 1988 });
    cars.push_back({ "Turing", 1678481, 0, 1936 });
    cars.push_back({ "Scoda Octavia", 1973109, 250000, 2020 });
    */
    
    readFile(&cars);
    Stack stack;

    for (int i = 0; i < cars.size(); i++)
        stack.push(cars[i]);
    stack.productionYearSort();

    StackQuery stackQuery(stack);

    short choice = 0;
    do {
        std::cout << "\n Choose option: \n";
        std::cout << "1 - Print all \n2 - Find 5 newest cars \n3 - Find cars mileage > 100 000 \n0 - Exit\n";
        std::cout << " Choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            stack.print();
            break;
        case 2:
            stackQuery.newestCarsQuer(5).print();
            break;
        case 3:
            stackQuery.mileageQuer(100000).print();
            break;
        }
    } while (choice != 0);

    return 0;
}