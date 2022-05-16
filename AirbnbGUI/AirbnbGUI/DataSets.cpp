#include "DataSets.h"

BookedApartmentDataSet* Global::BookedApartments;
ApartmentDataSet* Global::Apartments;
AdminDataSet* Global::AdminDataSet;
TravelerDataSet* Global::Travelers;
HostDataSet* Global::Hosts;

void BookedApartmentDataSet::Push(BookedApartment* apartment) {
}


void HostDataSet::Push(Host* host) {

	items.push_back(host->Serialize());
	values.push_back(host);
}

void ApartmentDataSet::Push(Apartment* apartment) {

	items.push_back(apartment->Serialize());
	values.push_back(apartment);
}

void TravelerDataSet::Push(Traveler* host) {
}

void AdminDataSet::Push(Administrator* host) {
}
