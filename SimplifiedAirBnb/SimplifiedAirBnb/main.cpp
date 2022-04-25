// SimplifiedAirBnb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iostream>
#include<conio.h>
#include "database.h"  

using namespace std;

bool LogIn() {

	string email;
	string password;

	char ch;
	cout << "Enter your Email/UserName:" << endl;
	cin >> email;
	cout << "Enter your Password:" << endl;

	ch = _getch();
	while (ch != 13) {
		password += ch;
		cout << '*';

		ch = _getch();
	}

	DataSet dataset("Users.txt");

	DataItem* itemDesc = new DataItem;

	itemDesc->AddField("email", email);
	itemDesc->AddField("password", password);

	auto result = dataset.searchForDataItem(itemDesc);

	if (!result) {

		cout << "Couldn't sign in\nWorng username or password..\n";
		return false;
	}

	cout << "Logged in sucessfully..\n";
	return true;
};


void signup() {

	string FullName;
	string Email;
	string Password;
	string repassword;
	string gender;
	string nationality;
	int age;

	DataSet dataset("Users.txt");

	DataItem* dataItem = new DataItem;
	dataset.Push(dataItem);

	cout << "Enter your name :" << endl;
	cin >> FullName;
	dataItem->AddField("name", FullName);

	cout << "Enter your email :" << endl;
	cin >> Email;
	dataItem->AddField("email", Email);

	cout << "Enter your Password :" << endl;
	cin >> Password;

	cout << "Enter the password again :" << endl;
	cin >> repassword;

	while (Password != repassword) {
		cout << "The two password doen't match" << endl;

		cout << "Enter your Password :" << endl;
		cin >> Password;
		cout << "Enter the password again :" << endl;
		cin >> repassword;
	}

	dataItem->AddField("password", Password);

	cout << "Enter your gender:" << endl;
	cin >> gender;
	dataItem->AddField("gender", gender);

	cout << "Enter your nationality:" << endl;
	cin >> nationality;
	dataItem->AddField("nationality", nationality);

	cout << "Enter your age:" << endl;
	cin >> age;
	dataItem->AddField("age", std::to_string(age));

	dataset.Save();
};



int main()
{
	int input = 0;

	cout << "Enter 1 for loggin in\nEnter 2 for signing up\n";

	while (true) {
		cin >> input;

		if (input == 1) {
			LogIn();
			break;
		}
		else if (input == 2) {
			signup();
			break;
		}
		else
			cout << "Invalid output\n";
	}
}