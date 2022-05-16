#include "Apartment.h"
#include "DataSets.h"

class Global;
Apartment::Apartment(DataItem* dataItem) {

	this->ID = stoi(dataItem->at("ID"));
	this->address = dataItem->at("Address");
	this->city = dataItem->at("City");
	this->availableRooms = stoi(dataItem->at("AvailableRooms"));
	this->price = stod(dataItem->at("Price"));
	this->capacity = stod(dataItem->at("Capacity"));

	for (auto bookedIdStr : dataItem->getListValues("BookedIDs"))
		bookedApartmentsIDs.push_back(stoi(bookedIdStr));
	
}

Apartment::Apartment(std::string address, std::string city, int availableRooms, double capacity, double price)
{
	this->address = address;
	this->city = city;
	this->availableRooms = availableRooms;
	this->capacity = capacity;
	this->price = price;
}

std::list<BookedApartment*> Apartment::getBookedApartments()
{
	std::list<BookedApartment*> bookedApartments;

	for (auto bookedId : bookedApartmentsIDs) {

		for (auto bookedApartment : Global::BookedApartments->getValues())
			if (bookedApartment->ID == bookedId)
				bookedApartments.push_back(bookedApartment);
	}
	
	return bookedApartments;
}

DataItem* Apartment::Serialize() {

	DataItem* dataItem = new DataItem;

	dataItem->AddField("ID", std::to_string(this->ID));
	dataItem->AddField("Address", this->address);
	dataItem->AddField("City", this->city);
	dataItem->AddField("AvailableRooms", std::to_string(this->availableRooms));
	dataItem->AddField("Price", std::to_string(this->price));
	dataItem->AddField("Capacity", std::to_string(this->capacity));

	std::list<std::string> bookIdsStr;
	for (auto bookId : bookedApartmentsIDs) 
		bookIdsStr.push_back(std::to_string(bookId));

	dataItem->AddField("BookedIDs", bookIdsStr);
	return dataItem;
}

Serializable::Serializable()
{
	this->ID = Global::getNextId();
}

DataItem* Serializable::Serialize() {
	return nullptr;
}

BookedApartment::BookedApartment(DataItem* dataItem) {

	this->ID = stoi(dataItem->at("BookingId"));
	this->numberOfDays = stoi(dataItem->at("NumberOfDays"));
	this->apartmentID = stoi(dataItem->at("ApartmentId"));
	this->startDate = dataItem->at("StartDate");
}

BookedApartment::BookedApartment(int apartmentId, long long startDate, int numberOfDays)
{
	this->ID = Global::getNextId();

	this->apartmentID = apartmentID;
	this->startDate = startDate;
	this->numberOfDays = numberOfDays;
}

double BookedApartment::CalculateTotalPrice() {

	return numberOfDays * getApartment()->price;
}

Apartment* BookedApartment::getApartment()
{
	for (auto bookedApartment : Global::Apartments->getValues()) {
		if (bookedApartment->ID == apartmentID) {
			return bookedApartment;
		}
	}
	return nullptr;
}

DataItem* BookedApartment::Serialize() {

	auto dataItem = new DataItem;

	dataItem->AddField("BookingId", std::to_string(ID));
	dataItem->AddField("ApartmentId", std::to_string(apartmentID));
	dataItem->AddField("StartDate", startDate);
	dataItem->AddField("NumberOfDays", std::to_string(numberOfDays));

	return dataItem;
}
