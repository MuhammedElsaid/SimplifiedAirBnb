#include "User.h"
#include "DataSets.h"

User::User(DataItem* dataItem) {

	this->ID = stoi(dataItem->at("ID"));
	this->fullName = dataItem->at("FullName");
	this->email = dataItem->at("Email");
	this->gender = dataItem->at("Gender");
	this->age = stoi(dataItem->at("Age"));
	this->userType = (UserType)std::stoi(dataItem->at("UserType"));
}

User::User(std::string fullName, std::string email, std::string gender, int age)
{
	this->fullName = fullName;
	this->email = email;
	this->gender = gender;
	this->age = age;
}


DataItem* User::Serialize() {
	auto dataItem = new DataItem;
	dataItem->AddField("UserType", std::to_string(userType));
	dataItem->AddField("ID", std::to_string(this->ID));
	dataItem->AddField("FullName", this->fullName);
	dataItem->AddField("Email", this->email);
	dataItem->AddField("Gender", this->gender);
	dataItem->AddField("Age", std::to_string(this->age));

	return dataItem;
}

std::list<Apartment*> Host::getOwnedApartments()
{
	std::list<Apartment*> ownedApartments;

	for (auto apartmentId : ownedApartmentsIds)
		for (auto apartment : *Global::Apartments->getValues()) {

			if (apartmentId == apartment->ID) {
				ownedApartments.push_back(apartment);
				break;
			}
		}

	return ownedApartments;
}

Host::Host(DataItem* dataItem) : User(dataItem) {

	auto ownedApartmentsStr = dataItem->getListValues("OwnedApartments");

	for (auto id : ownedApartmentsStr) {

		this->ownedApartmentsIds.push_back(stoi(id));
	}
}

DataItem* Host::Serialize() {

	auto baseDataItem = User::Serialize();

	std::list<std::string> ownedApartmentIds;
	for (auto ownedApartmentId : this->ownedApartmentsIds)
		ownedApartmentIds.push_back(std::to_string(ownedApartmentId));

	baseDataItem->AddField("OwnedApartments", ownedApartmentIds);

	return baseDataItem;
}

Administrator::Administrator(DataItem* dataItem) : User(dataItem) {

}

DataItem* Traveler::Serialize() {
	auto baseDataItem = User::Serialize();

	std::list<std::string> bookedApartmentsIds;
	for (auto bookedApartmentId : this->bookedApartmentIds)
		bookedApartmentsIds.push_back(std::to_string(bookedApartmentId));

	baseDataItem->AddField("BookedIds", bookedApartmentsIds);

	return baseDataItem;
}

std::list<BookedApartment*> Traveler::getBookedApartments()
{
	std::list<BookedApartment*> bookedApartments;

	for (auto bookedApartmentId : bookedApartmentIds)
		for (auto bookedApartment : *Global::BookedApartments->getValues()) {

			if (bookedApartmentId == bookedApartment->ID) {
				bookedApartments.push_back(bookedApartment);
				break;
			}
		}

	return bookedApartments;
}

Traveler::Traveler(DataItem* dataItem) : User(dataItem) {

	auto bookedApartmentsStr = dataItem->getListValues("BookedIds");

	for (auto id : bookedApartmentsStr) {
		this->bookedApartmentIds.push_back(stoi(id));
	}
}

UserKey::UserKey(DataItem* dataItem)
{
	this->userId = std::stoi(dataItem->at("UserID"));
	this->key = dataItem->at("Key");
}

DataItem* UserKey::Serialize()
{
	auto dataItem = new DataItem;

	dataItem->AddField("UserID", std::to_string(userId));
	dataItem->AddField("Key", key);

	return dataItem;
}
