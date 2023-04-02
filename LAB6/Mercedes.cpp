#include "Mercedes.h"

Mercedes::Mercedes()
{
	name = new char[] {"Mercedes"};
	setFuelCapacity(40.5);
	setFuelConsumption(8.1);
	setAvgSpeed(120);
}

void Mercedes::setFuelCapacity(float x)
{
	fuelCapacity = x;
}

void Mercedes::setFuelConsumption(float x)
{
	fuelConsumption = x;
}

void Mercedes::setAvgSpeed(float x)
{
	avgSpeed = x;
}

float Mercedes::getFuelCapacity()
{
	return fuelCapacity;
}

float Mercedes::getFuelConsumption()
{
	return fuelConsumption;
}

float Mercedes::getAvgSpeed()
{
	return avgSpeed;
}

char* Mercedes::getName()
{
	return name;
}
