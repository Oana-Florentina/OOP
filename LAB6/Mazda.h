#pragma once
#include "Car.h"

class Mazda : public Car {
public:
	Mazda();
	~Mazda();
	void setFuelCapacity(float);
	void setFuelConsumption(float);
	void setAvgSpeed(float);
	float getFuelCapacity();
	float getFuelConsumption();
	float getAvgSpeed();
	char* getName();
};