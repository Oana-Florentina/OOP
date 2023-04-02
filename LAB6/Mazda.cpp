#include "Mazda.h"

Mazda::Mazda()
{
	name = new char[] {"Mazda"};
	setFuelCapacity(40.7);
	setFuelConsumption(7.7);
	setAvgSpeed(125);
}

void Mazda::setFuelCapacity(float x)
{
	fuelCapacity = x;
}

void Mazda::setFuelConsumption(float x)
{
	fuelConsumption = x;
}

void Mazda::setAvgSpeed(float x)
{
	avgSpeed = x;
}

float Mazda::getFuelCapacity()
{
	return fuelCapacity;
}

float Mazda::getFuelConsumption()
{
	return fuelConsumption;
}

float Mazda::getAvgSpeed()
{
	return avgSpeed;
}

char* Mazda::getName()
{
	return name;
}
