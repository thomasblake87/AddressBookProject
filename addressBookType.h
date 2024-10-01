#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "extPersonType.h"
#include "personType.h"
#include "AddressType.h"
#include "DateType.h"
#include "AddressBookData.txt"
using namespace std;

class addressBookType
{
private:
	extPersonType addressList[500];
	int length;
	const int maxLength = 500;
public:
	//Default constructor
	addressBookType() : length(0) {}

	void initEntry(string AddressBookData) {
		ifstream infile("AddressBookData.txt");

		std::string fName, lName, phone, relationship, street, city, state;
		int day, month, year, zip;

		while (getline(infile, fName)) {
			getline(infile, lName);
			infile >> day >> month >> year;
			infile.ignore();
			getline(infile, street);
			getline(infile, city);
			getline(infile, state);
			infile >> zip;
			infile.ignore();
			getline(infile, phone);
			getline(infile, relationship);

			extPersonType person(fName, lName, day, month, year, street, city, state, zip, phone, relationship);
			addEntry(person);
		}
		infile.close();
	}
	void addEntry(const extPersonType& person) {
		if (length < maxLength) {
			addressList[length] = person;
			++length;
		}
		else {
			cout << "Address book is full" << endl;
		}
	}
	void findPerson(string lName) {
		bool found = false;
		for (i = 0, i < length, i++) {
			if (addressList[i].getLastName() == lName) {
				addressList[i].print();
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Person not found" << endl;
		}
	}
	void findBirthdays(int month) {
		bool found = false;
		for (i = 0, i < length, i++) {
			if (addressList[i].getBirthMonth() == month) {
				addressList[i].print();
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "No entries found for the given month" << endl;
		}
	}
	void findRelations(string relationship) {
		bool found = false;
		for (i = 0, i < length, i++) {
			if (addressList[i].getRelationship() == relationship) {
				addressList[i].print();
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "No entries found for the given relationship" << endl;
		}
	}
	void print() {
		for (i = 0, i < length, i++) {
			addressList[i].print();
			cout << endl;
		}
	}
	void sortEntries(int length) {
		int current = 1;
		while (current < length) {
			int index = current;
			extPersonType temp 
		}
	}
};