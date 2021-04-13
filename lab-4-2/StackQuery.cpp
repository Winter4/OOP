#include "StackQuery.h"

StackQuery::StackQuery() {}

StackQuery::StackQuery(Stack& object) {
    Stack* newStack = new Stack(object);
    this->head = newStack->getHeadPointer();
}

// 5 самых новых машин
Stack& StackQuery::newestCarsQuer(unsigned number = 5) {
    if (number < 0) throw std::out_of_range("Cars number should be >= 0");

    Car* tmpCar;
    Stack* source = new Stack(*this);
    Stack* result = new Stack;
    unsigned count = 0;

    while (head != nullptr && count < number) {
        result->push(newestCar());
        count++;
    }

    this->head = source->getHeadPointer();
    return *result;
}

// машины с пробегом > 1e5
Stack& StackQuery::mileageQuer(float querValue = 100000)
{
    Car* tmpCar;
    Stack* source = new Stack(*this);
    Stack* result = new Stack;

    while (head != nullptr) {
        tmpCar = &pop();
        if (tmpCar->getMileage() > querValue)
            result->push(*tmpCar);
    }

    this->head = source->getHeadPointer();
    result->productionYearSort();
    
    return *result;
}