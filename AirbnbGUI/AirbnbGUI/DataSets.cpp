#include "DataSets.h"

BookedApartmentDataSet* Global::BookedApartments;
ApartmentDataSet* Global::Apartments;
UsersDataSet* Global::Users;
KeyDataSet* Global::Keys;

void Global::LoadSets()
{
	Apartments = new ApartmentDataSet;
	BookedApartments = new BookedApartmentDataSet;
	Users = new UsersDataSet;
	Keys = new KeyDataSet;
}

const std::list<User*> UsersDataSet::loadValues() {

	values.clear();
	auto readItems = Open();

	for (auto readItem : readItems) {

		User* user = nullptr;

		int accountType = std::stoi(readItem->at("UserType"));

		if (accountType == User::UserType::Traveler)
			user = new Traveler(readItem);
		else if (accountType == User::UserType::Host)
			user = new Host(readItem);
		else
			user = new Administrator(readItem);

		values.push_back(user);
	}
	Close();
	return values;
}