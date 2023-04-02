#pragma once
#include "Car.h"

class Mercedes :public  Car {
public:
	Mercedes();
	~Mercedes();
	void setFuelCapacity(float);
	void setFuelConsumption(float);
	void setAvgSpeed(float);
	float getFuelCapacity();
	float getFuelConsumption();
	float getAvgSpeed();
	char* getName();
};