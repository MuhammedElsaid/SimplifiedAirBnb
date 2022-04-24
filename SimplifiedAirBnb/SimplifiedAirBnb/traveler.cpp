#include "traveler.h"
#include<iostream>
#include<conio.h>
#include "database.h"  

using namespace std;

travelers::travelers() {
	Email = "";
	password = "";
};


bool LogIn() {
	DataSet dataset("Users.txt");

	auto savedEmail = dataset.items["email"];
	auto savedPassword = dataset.items["password"];

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

	return email == savedEmail && password == savedPassword;
};





string signup() {
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
	dataItem.AddField("name", FullName);
	cout << "Enter your email :" << endl;
	cin >> Email;
	cout << "Enter your Password :" << endl;
	dataItem.AddField("email", Email);

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
	cout << "Enter your gender:" << endl;
	cin >> gender;
	cout << "Enter your nationality:" << endl;
	cin >> nationality;
	cout << "Enter your age:" << endl;
	cin >> age;

	dataset.Save();
	return 0;
};




int main() {
	
	int op;

	cout << "press 1 for signup" << endl;
	cout << "press 2 for login" << endl;
	cin >> op;
	if (op == 1) {
		signup();

	}
	else {
		 LogIn();

	}
	travelers T1;
	bool status = T1.LogIn();
	if (!status) {
		cout << "\n Failed to logIn!" << endl;
		return 1;
	}
	else {
		cout << "\n WELCOME " << endl;
		return 0;
	}
	string signnp = T1.signup();
	return 0;

};