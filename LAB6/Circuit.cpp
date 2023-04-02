#include "Circuit.h"
#include <iostream>



Circuit::Circuit(){}

Circuit::~Circuit() {}

void Circuit::SetLength(float l){
	length = l;
}

void Circuit::SetWeather(Weather w){
	weather = w;
}

void Circuit::AddCar(Car* new_car){

	cars.push_back(new_car);
	cars[cars.size() - 1]->setAvgSpeed(cars[cars.size() - 1]->getAvgSpeed() * (100 - 20 * this->weather) / 100);
	cars[cars.size() - 1]->setFuelConsumption(cars[cars.size() - 1]->getFuelConsumption() * (100 + 15 * this->weather) / 100);
}

void Circuit::Race(){

	int n = cars.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (cars[i]->getAvgSpeed() < cars[j]->getAvgSpeed())
				std::swap(cars[i], cars[j]);
}

void Circuit::ShowFinalRanks(){

	int p = 1;
	float t;
	for (int i = 0; i < cars.size(); i++)
		if (cars[i]->getFuelCapacity() / cars[i]->getFuelConsumption() * 100 >= length)
		{
			t = length / cars[i]->getAvgSpeed() * 100;
			std::cout << "Locul " << p++ << ": " << cars[i]->getName() << " " << "a terminat cursa in " << t << " minute\n";
		}
}



void Circuit::ShowWhoDidNotFinish(){

	std::cout << "Nu au terminat cursa: ";
	for (int i = 0; i < cars.size(); i++)
		if (cars[i]->getFuelCapacity() / cars[i]->getFuelConsumption() * 100 <= length)
			std::cout << cars[i]->getName() << "\t";
	std::cout << '\n';
}
