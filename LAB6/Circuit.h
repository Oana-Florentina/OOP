#pragma once
#include "WeatherEnum.h"
#include "Car.h"
#include <vector>


class Circuit {
private:
	float length;
	Weather weather;
	std::vector<Car*> cars;
	//int numberOfCarsOnTrack;

public:
	Circuit();
	~Circuit();
	void SetLength(float);
	void SetWeather(Weather w);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks();
	void ShowConsumptionRanks();
	void ShowWhoDidNotFinish();
};