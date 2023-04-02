#include "Toyota.h"

Toyota::Toyota()
{
	name = new char[] {"Toyota"};
	setFuelCapacity(30.3);
	setFuelConsumption(7.7);
	setAvgSpeed(115);
}

void Toyota::setFuelCapacity(float x)
{
	fuelCapacity = x;
}

void Toyota::setFuelConsumption(float x)
{
	fuelConsumption = x;
}

void Toyota::setAvgSpeed(float x)
{
	avgSpeed = x;
}

float Toyota::getFuelCapacity()
{
	return fuelCapacity;
}

float Toyota::getFuelConsumption()
{
	return fuelConsumption;
}

float Toyota::getAvgSpeed()
{
	return avgSpeed;
}

char* Toyota::getName()
{
	return name;
}
