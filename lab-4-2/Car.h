#pragma once
#include "iostream"


class Car {
private:
	std::string model;
	unsigned serialNumber;
	float mileage;
	unsigned productionYear;

public:
	Car();
	Car(std::string, unsigned, float, unsigned);
	Car(const Car& objectToCopy);

	void setModel(std::string modelToSet);
	void setSerialNumber(unsigned);
	void setMileage(float);
	void setProductionYear(unsigned);

	std::string getModel();
	unsigned getSerialNumber();
	float getMileage();
	unsigned getProductionYear();

	void print();
};