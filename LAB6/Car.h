#pragma once

class Car{
protected:
	char* name;
	float fuelCapacity, fuelConsumption, avgSpeed;
public:
	virtual void setFuelCapacity(float) = 0;
	virtual void setFuelConsumption(float) = 0;
	virtual void setAvgSpeed(float) = 0;
	virtual float getFuelCapacity() = 0;
	virtual float getFuelConsumption() = 0;
	virtual float getAvgSpeed() = 0;
	virtual char* getName() = 0;
};