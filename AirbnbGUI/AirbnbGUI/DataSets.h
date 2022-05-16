#pragma once

#include "Database.h"
#include "User.h"
#include "Apartment.h"

class ApartmentDataSet : public DataSet<Apartment>
{
	public:
	ApartmentDataSet() : DataSet("apartments.txt") {}

	void Push(Apartment* apartment) override;
};

class BookedApartmentDataSet : public DataSet<BookedApartment>
{
	public:
	BookedApartmentDataSet() : DataSet("booked_apartments.txt") {}

	void Push(BookedApartment* apartment) override;
};

class HostDataSet : DataSet<Host>
{
	public:
	HostDataSet() : DataSet("hosts.txt") {}

	void Push(Host* host) override;
};

class TravelerDataSet : DataSet<Traveler>
{
	public:
	TravelerDataSet() : DataSet("travelers.txt") {}

	void Push(Traveler* host) override;
};

class AdminDataSet : DataSet<Administrator>
{
	public:
	AdminDataSet() : DataSet("admins.txt") {}

	void Push(Administrator* host) override;
};

class Global
{
	public:
	static ApartmentDataSet* Apartments;
	static BookedApartmentDataSet* BookedApartments;
	static AdminDataSet* AdminDataSet;
	static TravelerDataSet* Travelers;
	static HostDataSet* Hosts;
};