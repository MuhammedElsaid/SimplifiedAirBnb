#pragma once
#include <string>
#include <list>

#include "Database.h"
#include "Apartment.h"


using namespace std;

class Serializable;
class DataItem;
class Apartment;
class BookedApartment;

class User : public Serializable
{
public:
	int UserId;
	std::string fullName;
	std::string email;
	std::string gender;
	int age;

	User(DataItem* dataItem);

	DataItem* Serialize() override;

	virtual bool haveAccess() { return false; }
};


class Host : public User
{
public:
	std::list<Apartment*> ownedApartments;

	Host(DataItem* dataItem);
	DataItem* Serialize() override;
};

class Traveler : public User
{
public:
	std::list<BookedApartment*> bookedApartments;

	Traveler(DataItem* dataItem);
	DataItem* Serialize() override;
};

class Administrator : public User
{
public:
	Administrator(DataItem* dataItem);

	bool haveAccess() override {

		return true;
	}
};