#pragma once
#include<iostream>
#include <vector>
#include "host.h"

using namespace std;

class BookedApartment
{
public:
	void CalculateTotalPrice();
	static const list<Apartment*>& searchByPrice(double givenPrice);
	static const list<Apartment*>& searchByCity(string givenCity);

private:
	Apartment* apartment;
	int numberOfDays;
};

class Traveler {

private:

	//TODO:: refactor
	int Sday, Eday,Smon,Emon,Syear,Eyear, duration;

	//TODO:: remove
	double Hprice, Lprice, price, priceperday;

	//The Vectors should be replaced with Apartment Info
	//TODO:: remove
	vector <string> cities;
	vector <double> prices;
	vector <int> dates;

	string email;
	string password;
	string city;

public:
	//Search Functions
	void Search();
	void Show();
	void RemoveDup();
	double CalcTotalPrice(double);
	void DateSearch();
	void CitySearch(string city);
	void PriceSearch(double,double);

	~Traveler(void);
};
