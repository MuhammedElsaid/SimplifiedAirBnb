#include "DataSets.h"

BookedApartmentDataSet* Global::BookedApartments;
ApartmentDataSet* Global::Apartments;
UsersDataSet* Global::Users;
int Global::currentIdCount;

void Global::LoadSets()
{
	Apartments = new ApartmentDataSet;
	BookedApartments = new BookedApartmentDataSet;
	Users = new UsersDataSet;
}

int Global::getNextId()
{
	return ++currentIdCount;
}
