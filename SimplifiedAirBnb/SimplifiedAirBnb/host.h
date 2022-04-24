#pragma once

#include <iostream>
using namespace std;
#include <stack>
#include<list>
#include<vector>
class apartment {
public:
	string address;
	float capacity;
	int no_of_rooms;
	int price;
	string startdate;
	string enddate;
	void readdata();
};




class host {
private:
	vector<apartment>v1;
	string fullname;
	int age;
	string gender;
	string nationality;
	string email;
	string password;
public:
	host(string fullname, int age, string gender, string nationality);
	host(string fullname, int age, string gender, string nationality, string email, string password);
	host();
	//login
	void addplaces();

};
	