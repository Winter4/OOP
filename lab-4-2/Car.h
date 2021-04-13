#pragma once
#include "iostream"


class Car {
private:
	std::string model;
	unsigned serialNumber;
	unsigned mileage;
	unsigned productionYear;

public:
	Car();
	Car(std::string, unsigned, float, unsigned);
	Car(const Car& objectToCopy);

	void setModel(std::string modelToSet);
	void setSerialNumber(unsigned);
	void setMileage(unsigned);
	void setProductionYear(unsigned);

	std::string getModel();
	unsigned getSerialNumber();
	unsigned getMileage();
	unsigned getProductionYear();

	void print();
};