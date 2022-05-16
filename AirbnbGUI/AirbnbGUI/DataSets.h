#pragma once

#include "Database.h"
#include "User.h"
#include "Apartment.h"

class ApartmentDataSet : public DataSet<Apartment>
{
	public:
	ApartmentDataSet() : DataSet("apartments.txt") {}
};

class BookedApartmentDataSet : public DataSet<BookedApartment>
{
	public:
	BookedApartmentDataSet() : DataSet("booked_apartments.txt") {}
};

class UsersDataSet : public DataSet<User>
{
	public:
	UsersDataSet() : DataSet("users.txt") {}
};

class Global
{
	public:

	static void LoadSets();
	static ApartmentDataSet* Apartments;
	static BookedApartmentDataSet* BookedApartments;
	static UsersDataSet* Users;

	static int getNextId();

private:
	static int currentIdCount;
};