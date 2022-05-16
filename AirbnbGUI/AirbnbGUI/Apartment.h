#pragma once

#include <list>
#include <string>
#include "Database.h"

using namespace std;

class DataItem;

class BookedApartment;

class Apartment : public Serializable
{
public:

	Apartment(DataItem* dataItem);
	static const list<Apartment*>& searchByPrice(double givenPrice);
	static const list<Apartment*>& searchByCity(string givenCity);
	static const list<Apartment*>& getApartments();

	int ID;
	string address;
	string city;
	int availableRooms;
	double capacity;
	double price;

	std::list<BookedApartment*> bookedIDs;

	DataItem* Serialize() override;
};

class BookedApartment : public Serializable
{
public:
	BookedApartment(DataItem* dataItem);
	double CalculateTotalPrice();
	
	int bookingID;

	Apartment* apartment;
	long long startDate;
	int numberOfDays;

	DataItem* Serialize() override;
};