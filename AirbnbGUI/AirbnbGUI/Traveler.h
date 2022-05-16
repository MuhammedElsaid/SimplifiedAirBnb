#pragma once
#include <string>
#include <list>
#include "Apartment.h"

using namespace std;

class Traveler
{

private:
	string fullName;
	string email;
	string city;

	list<BookedApartment*> bookedApartments;

public:
	double CalcTotalPrice();
};