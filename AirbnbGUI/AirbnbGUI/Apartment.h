#pragma once

#include <list>
#include <string>
#include "Database.h"
#include <msclr\marshal_cppstd.h>

class DataItem;

class BookedApartment;

class Apartment : public Serializable
{
public:

	Apartment(DataItem* dataItem);
	Apartment(std::string address, std::string city, int availableRooms, double capacity, double price);

	static const std::list<Apartment*>& searchByPrice(double givenPrice);
	static const std::list<Apartment*>& searchByCity(std::string givenCity);
	static const std::list<Apartment*>& getApartments();

	std::string address;
	std::string city;
	int availableRooms;
	double capacity;
	double price;

	DataItem* Serialize() override;
};

class BookedApartment : public Serializable
{
public:
	BookedApartment(DataItem* dataItem);
	BookedApartment(int apartmentId, std::string startDate, int numberOfDays);

	double CalculateTotalPrice();

	int apartmentID;
	Apartment* getApartment();
	
	std::string startDate;
	int numberOfDays;

	DataItem* Serialize() override;
};