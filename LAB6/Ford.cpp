#include "Ford.h"

Ford::Ford()
{
	name = new char[] {"Ford"};
	setFuelCapacity(45.7);
	setFuelConsumption(9.3);
	setAvgSpeed(130);
}

void Ford::setFuelCapacity(float x)
{
	fuelCapacity = x;
}

void Ford::setFuelConsumption(float x)
{
	fuelConsumption = x;
}

void Ford::setAvgSpeed(float x)
{
	avgSpeed = x;
}

float Ford::getFuelCapacity()
{
	return fuelCapacity;
}

float Ford::getFuelConsumption()
{
	return fuelConsumption;
}

float Ford::getAvgSpeed()
{
	return avgSpeed;
}

char* Ford::getName()
{
	return name;
}
