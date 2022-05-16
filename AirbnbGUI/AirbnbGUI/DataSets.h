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

	const std::list<User*> loadValues() override{

		auto readItems = Open();

		for (auto readItem : readItems) {

			User* user = nullptr;

			int accountType = std::stoi(readItem->at("UserType"));
			if (accountType == 0)
				user = new Traveler(readItem);
			else if (accountType == 1)
				user = new Host(readItem);
			else 
				user = new Administrator(readItem);

			values.push_back(user);
		}
		Close();
		return values;
	}
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