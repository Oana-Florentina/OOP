#pragma once
#include "Car.h"

class Toyota : public Car {
public:
	Toyota();
	~Toyota();
	void setFuelCapacity(float);
	void setFuelConsumption(float);
	void setAvgSpeed(float);
	float getFuelCapacity();
	float getFuelConsumption();
	float getAvgSpeed();
	char* getName();
};