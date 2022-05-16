#pragma once

#include "Database.h"
#include "User.h"
#include "Apartment.h"

class ApartmentDataSet : public DataSet<Apartment>
{
	public:
	ApartmentDataSet() : DataSet("apartments.txt") {}
};

class BookedApartmentDataSet : public DataSet<BookedApartment>
{
	public:
	BookedApartmentDataSet() : DataSet("booked_apartments.txt") {}
};

class HostDataSet : public DataSet<Host>
{
	public:
	HostDataSet() : DataSet("hosts.txt") {}
};

class TravelerDataSet : public DataSet<Traveler>
{
	public:
	TravelerDataSet() : DataSet("travelers.txt") {}
};

class AdminDataSet : public DataSet<Administrator>
{
	public:
	AdminDataSet() : DataSet("admins.txt") {}
};

class Global
{
	public:

	static void LoadSets();
	static ApartmentDataSet* Apartments;
	static BookedApartmentDataSet* BookedApartments;
	static AdminDataSet* Admins;
	static TravelerDataSet* Travelers;
	static HostDataSet* Hosts;

	static int getNextId();

private:
	static int currentIdCount;
};