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
protected:
	enum UserType
	{
		Traveler = 0,
		Host = 1,
		Admin = 2
	};

public:
	UserType userType;
	std::string fullName;
	std::string email;
	std::string gender;
	int age;

	void setKey(std::string key);

	User(DataItem* dataItem);
	User(std::string fullName, std::string email, std::string gender, int age);

	DataItem* Serialize() override;

	virtual bool haveAccess() { return false; }

private:
	std::string tempKey;
};

class Host : public User
{
public:
	std::list<Apartment*> ownedApartments;

	Host(DataItem* dataItem);
	Host(User user) : User(user) {
		userType = UserType::Host;
	}

	DataItem* Serialize() override;
};

class Traveler : public User
{
public:
	std::list<BookedApartment*> bookedApartments;

	Traveler(DataItem* dataItem);
	Traveler(User user) : User(user) {
		//Don't need to anyway
		userType = UserType::Traveler;
	}
	DataItem* Serialize() override;
};

class Administrator : public User
{
public:
	Administrator(DataItem* dataItem);
	Administrator(User user) : User(user) {
		userType = UserType::Admin;
	}

	bool haveAccess() override {

		return true;
	}
};