#include "DataSets.h"

BookedApartmentDataSet* Global::BookedApartments;
ApartmentDataSet* Global::Apartments;
UsersDataSet* Global::Users;
KeyDataSet* Global::Keys;
int Global::currentIdCount;

void Global::LoadSets()
{
	Apartments = new ApartmentDataSet;
	BookedApartments = new BookedApartmentDataSet;
	Users = new UsersDataSet;
	Keys = new KeyDataSet;
}

int Global::getNextId()
{
	return ++currentIdCount;
}
