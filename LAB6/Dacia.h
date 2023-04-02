#pragma once
#include "Car.h"

class Dacia : public Car {
public:
	Dacia();
	~Dacia();
	void setFuelCapacity(float);
	void setFuelConsumption(float);
	void setAvgSpeed(float);
	float getFuelCapacity();
	float getFuelConsumption();
	float getAvgSpeed();
	char* getName();
};