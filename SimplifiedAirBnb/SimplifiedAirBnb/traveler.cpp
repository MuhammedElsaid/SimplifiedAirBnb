#include "traveler.h"
#include<iostream>
#include<conio.h>
#include "database.h"  

using namespace std;

Traveler::Traveler() {
	Email = "";
	password = "";
	city = " ";
	Sday = 0; Eday = 0; Smon = 0; Emon = 0; Syear = 0; Eyear = 0;
	duration = 0;
	Hprice = 0.0; Lprice = 0.0; price = 0.0; priceperday = 0.0;
};
void Traveler::Search() {
	cout << "Enter Highest Price: "; cin >> Hprice;
	cout << "Enter Lowest Price: "; cin >> Lprice;
	cout << "Results:\n";
	PriceSearch(Hprice,Lprice);
	cout << "Enter City: "; cin >> city;
	cout << "Results:\n";
	CitySearch(city);
	cout << "Stay Details:\n";
	cout<< "Start Day and End Day: "; cin >> Sday>>Eday;
	cout << "Enter Start Month and End Month: "; cin >> Smon>>Emon;
	cout << "Enter Start Year and End Year: "; cin >> Syear>>Eyear;
	cout << "Results:\n";
	DateSearch();
};


void Traveler::Show() {};

//Should remove duplicates in results
void Traveler::RemoveDup() {};


double Traveler::CalcTotalPrice(double priceperday) {
	//priceperday is the apartment price per day
	price = priceperday * duration;
	return price;
};


void Traveler::DateSearch() {
	int Dm = (Emon - Smon);
	int Dy = (Eyear - Syear);
	duration = (Eday - Sday)+30*Dm+365*Dy;
};

void Traveler::CitySearch(string cityy) {
	//City attribute of Apartments should replace Cities
	for (int i = 0; i < cities.size(); i++) {
		if (city._Equal(cities[i]))
			cities[i].pop_back();
	}


};


void Traveler::PriceSearch(double hp,double lp) {
	hp= Hprice; lp = Lprice;
	while (price <= hp && price >= lp) {
		//prices of Apartment should replace Prices[i]
		for(int i=0; i<prices.size(); i++){
			if (price== prices[i]) {
                prices.pop_back();
		      }
		}
	}
};

Traveler::~Traveler(void) {};