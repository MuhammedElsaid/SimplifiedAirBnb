#include "host.h"

void apartment::readdata()
{
	cout << "please enter department details" << endl;
	cin >> address >> capacity >> no_of_rooms >> price >> startdate >> enddate;
}

host::host(string fullname, int age, string gender, string nationality)
{
	age = age;
	fullname = fullname;
	gender = gender;
	nationality = nationality;
}

host::host(string fullname, int age, string gender, string nationality, string email, string password)
{
	age = age;
	fullname = fullname;
	gender = gender;
	nationality = nationality;
	email = email;
	password = password;
}

void host::addplaces()
{
	int n;
	cout << "please enter number of appartments available for rents" << endl;
	cin >> n;
	apartment a;

	for (int i = 0; i < n; i++) {
		a.readdata();

		v1.push_back(a);
	}
}
