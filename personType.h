#pragma once
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

class personType
{
private:
	string firstName;
	string lastName;
public:
	//Constructor
	personType(string fName = "", string lName = "") : firstName(fName), lastName(lName) {};

	void setFirstName(string fName) {
		firstName = fName;
	}
	void setLastName(string lName) {
		lastName = lName;
	}

	string getFirstName() {
		return firstName;
	}
	string getLastName() {
		return lastName;
	}

	void print() {
		cout << firstName << " " << lastName << endl;
	}
};

