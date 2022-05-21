#pragma once

#include "Database.h"
#include "User.h"
#include "Apartment.h"

class ApartmentDataSet : public DataSet<Apartment>
{
	public:
	ApartmentDataSet() : DataSet("apartments.txt") 
	{
		this->values = loadValues();
	}
};

class BookedApartmentDataSet : public DataSet<BookedApartment>
{
	public:
	BookedApartmentDataSet() : DataSet("booked_apartments.txt") {
		this->values = loadValues();
	}
};

class UsersDataSet : public DataSet<User>
{
public:
	UsersDataSet() : DataSet("users.txt") {
		this->values = loadValues();
	}

	const std::list<User*> loadValues() override;

	//TODO:: getter and setter
	User* currentSignedInUser;
};

class KeyDataSet : public DataSet<UserKey>
{
public:
	KeyDataSet() : DataSet("keys.txt") {
		this->values = loadValues();
	}
};

class Global
{
	public:

	static void LoadSets();
	static ApartmentDataSet* Apartments;
	static BookedApartmentDataSet* BookedApartments;
	static UsersDataSet* Users;
	static KeyDataSet* Keys;
};

