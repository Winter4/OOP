#include "Car.h"

Car::Car()
{
    model = "none";
    serialNumber = mileage = productionYear = 0;
}

Car::Car(std::string modelToSet, unsigned serialNumberToSet, float mileageToSet, unsigned productionYearToSet)
{
    model = modelToSet;
    serialNumber = serialNumberToSet;
    mileage = mileageToSet;
    productionYear = productionYearToSet;
}

Car::Car(const Car& objectToCopy) {
    model = objectToCopy.model;
    serialNumber = objectToCopy.serialNumber;
    mileage = objectToCopy.mileage;
    productionYear = objectToCopy.productionYear;
}

void Car::setModel(std::string modelToSet)
{
    model = modelToSet;
}

void Car::setSerialNumber(unsigned serialNumberToSet)
{
    if (serialNumberToSet > 0) serialNumber = serialNumberToSet;
    else throw std::out_of_range("Serial number should be > 0");
}

void Car::setMileage(unsigned mileageToSet)
{
    if (mileageToSet > 0) mileage = mileageToSet;
    else throw std::out_of_range("Mileage should be > 0");
}

void Car::setProductionYear(unsigned productionYearToSet)
{
    if (productionYearToSet > 0) productionYear = productionYearToSet;
    else throw std::out_of_range("Production year should be > 0");
}

std::string Car::getModel() { return model; }

unsigned Car::getSerialNumber() { return serialNumber; }

unsigned Car::getMileage() { return mileage; }

unsigned Car::getProductionYear() { return productionYear; }


void Car::print()
{
    std::cout.width(20);
    std::cout << model << "\t   "; 
    
    std::cout << serialNumber << "\t" <<
        mileage << "\t" << "  " <<
        productionYear;
    std::cout << std::endl; 
}