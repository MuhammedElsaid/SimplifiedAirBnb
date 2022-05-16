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

	for (auto bookedIdStr : dataItem->getListValues("BookedIDs")) {

		for (auto bookedApartment : Global::BookedApartments->getValues()) 
			if (bookedApartment->bookingID == stoi(bookedIdStr))
				bookedIDs.push_back(bookedApartment);
	}
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
	for (auto bookId : bookedIDs) 
		bookIdsStr.push_back(std::to_string(bookId->bookingID));

	dataItem->AddField("BookedIDs", bookIdsStr);
	return dataItem;
}

DataItem* Serializable::Serialize() {
	return nullptr;
}
template<class T>
const std::list<T*> DataSet<T>::getValues() {
	return values;
}

BookedApartment::BookedApartment(DataItem* dataItem) {

	this->bookingID = stoi(dataItem->at("BookingId"));
	this->numberOfDays = stoi(dataItem->at("NumberOfDays"));

	for (auto bookedApartment : Global::Apartments->getValues()) {
		if (bookedApartment->ID == stoi(dataItem->at("ApartmentId"))) {
			this->apartment = bookedApartment;
			break;
		}
	}

	this->startDate = stoll(dataItem->at("StartDate"));
}

double BookedApartment::CalculateTotalPrice() {

	return numberOfDays * apartment->price;
}

DataItem* BookedApartment::Serialize() {

	auto dataItem = new DataItem;

	dataItem->AddField("BookingId", std::to_string(bookingID));
	dataItem->AddField("ApartmentId", std::to_string(apartment->ID));
	dataItem->AddField("StartDate", std::to_string(startDate));
	dataItem->AddField("NumberOfDays", std::to_string(numberOfDays));

	return dataItem;
}
