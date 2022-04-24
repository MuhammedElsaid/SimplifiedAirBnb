#include "traveler.h"
#include<iostream>
#include<conio.h>

using namespace std;

travelers::travelers() {
	Email = "\0";
	password = "\0";
};

bool travelers::LogIn() {
	string mail = "mayadazain";
	string password1 = "2020";
	char ch;
	cout << "Enter your Email/UserName:" << endl;
	cin >> Email;
	cout << "Enter your Password:" << endl;
	ch = _getch();
	while (ch != 13) {
		password.push_back(ch);
		cout << '*';

		ch = _getch();

	}



	if (Email == mail && password == password1) {
		return true;
	}
	else {
		return false;
	}

};





string travelers::signup() {
	string FullName;
	string Email;
	string Password;
	string repassword;
	string gender;
	string nationality;
	int age;


	cout << "Enter your name :" << endl;
	cin >> FullName;
	cout << "Enter your email :" << endl;
	cin >> Email;
	cout << "Enter your Password :" << endl;
	cin >> Password;
	cout << "Enter the password again :" << endl;
	cin >> repassword;
	while (Password != repassword) {
		cout << "Success !" << endl;
		cout << "Welcome To AirBNB" << endl;
	}
	cout << "Enter your gender:" << endl;
	cin >> gender;
	cout << "Enter your nationality:" << endl;
	cin >> nationality;
	cout << "Enter your age:" << endl;
	cin >> age;
	return 0;
};




int main() {
	bool LogIn();
	int signup();
	int op;

	cout << "press 1 for signup" << endl;
	cout << "press 2 for login" << endl;
	cin >> op;
	if (op == 1) {
		string signup();

	}
	else {
		void LogIn();

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