#include "traveler.h"
#include<iostream>
#include<conio.h>
#include "database.h"  
#include "host.h"
#include"host.cpp"

using namespace std;


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
	price =  * duration;
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

void BookedApartment::CalculateTotalPrice()
{
	apartment->getPrice();
}

const list <Apartment*>&
Apartment::searchByPrice(double givenPrice) {

	list<Apartment*> foundResults;
	for (auto apartment : getApartments()) {
		if (apartment->price <= givenPrice)
			foundResults.push_back(apartment);
	}

	return foundResults;
}
const list<Apartment*>& Apartment::searchByCity(string givenCity) {
	list<Apartment*> foundResults;
	for (auto apartment : getApartments()) {
		if (apartment->city == givenCity)
			foundResults.push_back(apartment);
	}

	return foundResults;
}


