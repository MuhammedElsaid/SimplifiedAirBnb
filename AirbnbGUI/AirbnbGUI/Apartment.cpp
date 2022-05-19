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
}

Apartment::Apartment(std::string address, std::string city, int availableRooms, double capacity, double price)
{
	this->address = address;
	this->city = city;
	this->availableRooms = availableRooms;
	this->capacity = capacity;
	this->price = price;
}

DataItem* Apartment::Serialize() {

	DataItem* dataItem = new DataItem;

	dataItem->AddField("ID", std::to_string(this->ID));
	dataItem->AddField("Address", this->address);
	dataItem->AddField("City", this->city);
	dataItem->AddField("AvailableRooms", std::to_string(this->availableRooms));
	dataItem->AddField("Price", std::to_string(this->price));
	dataItem->AddField("Capacity", std::to_string(this->capacity));

	return dataItem;
}

Serializable::Serializable()
{
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

BookedApartment::BookedApartment(int Id, std::string startDate, int numberOfDays)
{
	this->apartmentID = Id;
	this->startDate = startDate;
	this->numberOfDays = numberOfDays;
}

double BookedApartment::CalculateTotalPrice() {

	return numberOfDays * getApartment()->price;
}

Apartment* BookedApartment::getApartment()
{
	for (auto bookedApartment : *Global::Apartments->getValues()) {
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
