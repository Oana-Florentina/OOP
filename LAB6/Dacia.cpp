#include "Dacia.h"

Dacia::Dacia()
{
	name = new char[] {"Dacia"};
	setFuelCapacity(40.6);
	setFuelConsumption(8.7);
	setAvgSpeed(110);
}

void Dacia::setFuelCapacity(float x)
{
	fuelCapacity = x;
}

void Dacia::setFuelConsumption(float x)
{
	fuelConsumption = x;
}

void Dacia::setAvgSpeed(float x)
{
	avgSpeed = x;
}

float Dacia::getFuelCapacity()
{
	return fuelCapacity;
}

float Dacia::getFuelConsumption()
{
	return fuelConsumption;
}

float Dacia::getAvgSpeed()
{
	return avgSpeed;
}

char* Dacia::getName()
{
	return name;
}
