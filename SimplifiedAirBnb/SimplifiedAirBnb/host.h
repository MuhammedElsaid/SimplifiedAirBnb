#pragma once

#include <iostream>
#include <stack>
#include <list>
#include <vector>

using namespace std;

class Apartment {

public:
	void ReadData();

	int getPrice();
	static const list<Apartment*>& searchByPrice(double givenPrice);
	static const list<Apartment*>& searchByCity(string givenCity);
	static const list<Apartment*>& getApartments();

private:
	static list<Apartment*>* apartments;

	string address;
	string city;
	double capacity;
	int no_of_rooms;
	double price;
	string startdate;
	string enddate;
};

class Host {
private:
	vector<Apartment*> apartments;
	string fullname;
	int age;
	string gender;
	string nationality;
	string email;
	string password;

public:
	Host(string fullname, int age, string gender, string nationality);
	Host(string fullname, int age, string gender, string nationality, string email, string password);
	Host();
	//login
	void addplaces();

};
	