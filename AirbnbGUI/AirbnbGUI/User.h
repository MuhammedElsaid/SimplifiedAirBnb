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

	enum UserType
	{
		Traveler = 0,
		Host = 1,
		Admin = 2
	};

	UserType userType;
	std::string fullName;
	std::string email;
	std::string gender;
	int age;

	User(DataItem* dataItem);
	User(std::string fullName, std::string email, std::string gender, int age);

	DataItem* Serialize() override;
};

class UserKey : public Serializable
{
public:

	int userId;
	std::string key;

	UserKey(DataItem* dataItem);
	UserKey(int userId, std::string key) {

		this->userId = userId;
		this->key = key;
	}

	DataItem* Serialize() override;
};

class Host : public User
{
public:
	std::list<int> ownedApartmentsIds;
	std::list<Apartment*> getOwnedApartments();

	Host(DataItem* dataItem);
	Host(User user) : User(user) {
		userType = UserType::Host;
	}

	DataItem* Serialize() override;
};

class Traveler : public User
{
public:
	std::list<int> bookedApartmentIds;
	std::list<BookedApartment*> getBookedApartments();

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
};