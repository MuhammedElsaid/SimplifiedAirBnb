#include "User.h"
#include "DataSets.h"

template<class T>
const std::list<T*> DataSet<T>::getValues() {
	return values;
}

User::User(DataItem* dataItem) {

	this->UserId = stoi(dataItem->at("UserId"));
	this->fullName = dataItem->at("FullName");
	this->email = dataItem->at("Email");
	this->gender = dataItem->at("Gender");
	this->age = stoi(dataItem->at("Age"));
}


DataItem* User::Serialize() {
	auto dataItem = new DataItem;
	dataItem->AddField("UserId", to_string(this->UserId));
	dataItem->AddField("FullName", this->fullName);
	dataItem->AddField("Email", this->email);
	dataItem->AddField("Gender", this->gender);
	dataItem->AddField("Age", to_string(this->age));

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

	list<string> ownedApartmentIds;
	for (auto ownedApartment : this->ownedApartments)
		ownedApartmentIds.push_back(to_string(ownedApartment->ID));

	baseDataItem->AddField("OwnedApartments", ownedApartmentIds);

	return baseDataItem;
}

Administrator::Administrator(DataItem* dataItem) : User(dataItem) {

}

DataItem* Traveler::Serialize() {
	auto baseDataItem = User::Serialize();

	list<string> bookedApartmentsIds;
	for (auto bookedApartment : this->bookedApartments)
		bookedApartmentsIds.push_back(to_string(bookedApartment->bookingID));

	baseDataItem->AddField("BookedIds", bookedApartmentsIds);

	return baseDataItem;
}

Traveler::Traveler(DataItem* dataItem) : User(dataItem) {

	auto bookedApartmentsStr = dataItem->getListValues("BookedIds");

	for (auto id : bookedApartmentsStr) {

		int apartmentId = stoi(id);

		for (auto bookedApartment : Global::BookedApartments->getValues())
			if (bookedApartment->bookingID == apartmentId)
				this->bookedApartments.push_back(bookedApartment);
	}
}