#include "User.h"
#include "DataSets.h"

void User::setKey(std::string key)
{
	this->tempKey = key;
}

User::User(DataItem* dataItem) {

	this->ID = stoi(dataItem->at("ID"));
	this->fullName = dataItem->at("FullName");
	this->email = dataItem->at("Email");
	this->gender = dataItem->at("Gender");
	this->age = stoi(dataItem->at("Age"));

	//Doesn't check out :)
	Global::getNextId();
}

User::User(std::string fullName, std::string email, std::string gender, int age)
{

	this->fullName = fullName;
	this->email = email;
	this->gender = gender;
	this->age = age;

	this->ID = Global::getNextId();
}


DataItem* User::Serialize() {
	auto dataItem = new DataItem;
	dataItem->AddField("UserType", std::to_string(userType));
	dataItem->AddField("ID", std::to_string(this->ID));
	dataItem->AddField("FullName", this->fullName);
	dataItem->AddField("Email", this->email);
	dataItem->AddField("Gender", this->gender);
	dataItem->AddField("Age", std::to_string(this->age));

	dataItem->AddField("Key", tempKey);
	tempKey = "";

	return dataItem;
}

Host::Host(DataItem* dataItem) : User(dataItem) {

	auto ownedApartmentsStr = dataItem->getListValues("OwnedApartments");

	for (auto id : ownedApartmentsStr) {

		int apartmentId = stoi(id);

		for (auto apartment : Global::Apartments->getValues())
			if (apartment->ID == apartmentId)
				this->ownedApartments.push_back(apartment);
	}
}

DataItem* Host::Serialize() {

	auto baseDataItem = User::Serialize();

	std::list<std::string> ownedApartmentIds;
	for (auto ownedApartment : this->ownedApartments)
		ownedApartmentIds.push_back(std::to_string(ownedApartment->ID));

	baseDataItem->AddField("OwnedApartments", ownedApartmentIds);

	return baseDataItem;
}

Administrator::Administrator(DataItem* dataItem) : User(dataItem) {

}

DataItem* Traveler::Serialize() {
	auto baseDataItem = User::Serialize();

	std::list<std::string> bookedApartmentsIds;
	for (auto bookedApartment : this->bookedApartments)
		bookedApartmentsIds.push_back(std::to_string(bookedApartment->ID));

	baseDataItem->AddField("BookedIds", bookedApartmentsIds);

	return baseDataItem;
}

Traveler::Traveler(DataItem* dataItem) : User(dataItem) {

	auto bookedApartmentsStr = dataItem->getListValues("BookedIds");

	for (auto id : bookedApartmentsStr) {

		int apartmentId = stoi(id);

		for (auto bookedApartment : Global::BookedApartments->getValues())
			if (bookedApartment->ID == apartmentId)
				this->bookedApartments.push_back(bookedApartment);
	}
}