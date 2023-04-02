#pragma once
#include "Car.h"

class Ford : public Car {
public:
	Ford();
	~Ford();
	void setFuelCapacity(float);
	void setFuelConsumption(float);
	void setAvgSpeed(float);
	float getFuelCapacity();
	float getFuelConsumption();
	float getAvgSpeed();
	char* getName();
};