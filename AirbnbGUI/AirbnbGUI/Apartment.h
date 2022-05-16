#pragma once

#include <list>
#include <string>
#include "Database.h"

class DataItem;

class BookedApartment;

class Apartment : public Serializable
{
public:

	Apartment(DataItem* dataItem);
	static const std::list<Apartment*>& searchByPrice(double givenPrice);
	static const std::list<Apartment*>& searchByCity(std::string givenCity);
	static const std::list<Apartment*>& getApartments();

	int ID;
	std::string address;
	std::string city;
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