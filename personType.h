#pragma once
#import <iomanip>
#import <iostream>
using namespace std;

class personType
{
private:
	string firstName();
	string lastName();
public:
	personType(string fName = "", string lName = "") : firstName(fName), lastName(lName);

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
		return lastName
	}

	void print();
};

