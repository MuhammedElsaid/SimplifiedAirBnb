#pragma once
#include<iostream>
#include <vector>
using namespace std;

class Traveler {

	int Sday, Eday,Smon,Emon,Syear,Eyear, duration;
	double Hprice, Lprice, price, priceperday;
	string city;
	//The Vectors should be replaced with Apartment Info
	vector <string> cities;
	vector <double> prices;
	vector<int> dates;
public:
	string Email;
	string password;
	Traveler(void);
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
