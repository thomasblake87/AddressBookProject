#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "extPersonType.h"
#include "personType.h"
#include "AddressType.h"
#include "DateType.h"

using namespace std;

class addressBookType
{
private:
    extPersonType addressList[500];  // Array to store extPersonType objects
    int length;
    const int maxLength = 500;

public:
    // Default constructor
    addressBookType() : length(0) {}

    // Function to initialize entries from a file
    void initEntry() {
        ifstream infile("AddressBookData.txt");

        string fName, lName, phone, relationship, street, city, state;
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

    // Function to add an entry to the address book
    void addEntry(const extPersonType& person) {
        if (length < maxLength) {
            addressList[length] = person;
            ++length;
        }
        else {
            cout << "Address book is full" << endl;
        }
    }

    // Function to find a person by last name
    void findPerson(string lName) {
        bool found = false;
        for (int i = 0; i < length; i++) {
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

    // Function to find persons by birth month
    void findBirthdays(int month) {
        bool found = false;
        for (int i = 0; i < length; i++) {
            if (addressList[i].getBirthMonth() == month) {
                addressList[i].print();
                found = true;
            }
        }
        if (!found) {
            cout << "No entries found for the given month" << endl;
        }
    }

    // Function to find persons by relationship
    void findRelations(string relationship) {
        bool found = false;
        for (int i = 0; i < length; i++) {
            if (addressList[i].getRelationship() == relationship) {
                addressList[i].print();
                found = true;
            }
        }
        if (!found) {
            cout << "No entries found for the given relationship" << endl;
        }
    }

    // Function to print all entries
    void print() {
        for (int i = 0; i < length; i++) {
            addressList[i].print();
            cout << endl;
        }
    }

    // Function to sort the entries using the insertion sort algorithm
    void sortEntries() {
        for (int current = 1; current < length; current++) {
            int i = current;
            bool placeFound = false;
            while (i > 0 && !placeFound) {
                if (addressList[i].getLastName() < addressList[i - 1].getLastName()) {
                    extPersonType temp = addressList[i];
                    addressList[i] = addressList[i - 1];
                    addressList[i - 1] = temp;
                    i--;
                }
                else {
                    placeFound = true;
                }
            }
        }
    }
};