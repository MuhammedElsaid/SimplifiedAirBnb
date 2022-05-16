#pragma once
#include <string>
#include <list>

#include "Database.h"
#include "Apartment.h"

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
	User(std::string fullName, std::string email, std::string gender, int age);

	DataItem* Serialize() override;

	virtual bool haveAccess() { return false; }
};


class Host : public User
{
public:
	std::list<Apartment*> ownedApartments;

	Host(DataItem* dataItem);
	Host(User user) : User(user) {}

	DataItem* Serialize() override;
};

class Traveler : public User
{
public:
	std::list<BookedApartment*> bookedApartments;

	Traveler(DataItem* dataItem);
	Traveler(User user) : User(user) {}
	DataItem* Serialize() override;
};

class Administrator : public User
{
public:
	Administrator(DataItem* dataItem);
	Administrator(User user) : User(user) {}


	bool haveAccess() override {

		return true;
	}
};