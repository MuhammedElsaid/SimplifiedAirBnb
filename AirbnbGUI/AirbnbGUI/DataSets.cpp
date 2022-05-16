#include "DataSets.h"

BookedApartmentDataSet* Global::BookedApartments;
ApartmentDataSet* Global::Apartments;
AdminDataSet* Global::Admins;
TravelerDataSet* Global::Travelers;
HostDataSet* Global::Hosts;
int Global::currentIdCount;

void Global::LoadSets()
{
	Apartments = new ApartmentDataSet;
	BookedApartments = new BookedApartmentDataSet;
	Admins = new AdminDataSet;
	Travelers = new TravelerDataSet;
	Hosts = new HostDataSet;
}

int Global::getNextId()
{
	return ++currentIdCount;
}
