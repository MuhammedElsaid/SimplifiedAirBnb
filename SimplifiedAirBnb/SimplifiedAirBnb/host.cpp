#include "host.h"
#include "database.h"

void Apartment::ReadData()
{
	cout << "please enter department details" << endl;
	cin >> address >> capacity >> no_of_rooms >> price >> startdate >> enddate>>city;
}

int Apartment::getPrice()
{
	return price;
}

const list<Apartment*>& Apartment::getApartments() {

	if (!apartments) {

		DataSet dataset("Apartments.txt");

		for (auto apartmentDataItem : dataset.getItems()) {

			
		}
	}

	return *apartments;
}

Host::Host(string fullname, int age, string gender, string nationality)
{
	age = age;
	fullname = fullname;
	gender = gender;
	nationality = nationality;
}

Host::Host(string fullname, int age, string gender, string nationality, string email, string password)
{
	age = age;
	fullname = fullname;
	gender = gender;
	nationality = nationality;
	email = email;
	password = password;
}

void Host::addplaces()
{
	int n;
	cout << "please enter number of appartments available for rents" << endl;
	cin >> n;

	for (int i = 0; i < n; i++) {
		Apartment* newApartment = new Apartment;

		newApartment->ReadData();
		apartments.push_back(newApartment);
	}
}
