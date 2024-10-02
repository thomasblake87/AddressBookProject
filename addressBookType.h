#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "extPersonType.h"
#include "personType.h"
#include "AddressType.h"
#include "DateType.h"

using namespace std;

class addressBookType
{
private:
    extPersonType addressList[500];  //array
    int length;
    const int maxLength = 500;

public:
    //constructor
    addressBookType() : length(0) {}

    //initialize entries from file
    void initEntry() {
        ifstream infile("AddressBookData.txt");

        string fName, lName, name, phone, relationship, street, city, state;
        string date, zips;
        int day, month, year, zip;

        while (getline(infile, name)) {
            //seperate name
            istringstream nameStream(name);
            nameStream >> fName >> lName;
            getline(infile, date); //read date as string
            //separate date
            istringstream dateStream(date);
            dateStream >> day >> month >> year;
            getline(infile, street);
            getline(infile, city);
            getline(infile, state);
            getline(infile, zips);  //read zip as string
            //separate zip code
            istringstream zipStream(zips);
            zipStream >> zip;
            getline(infile, phone);
            getline(infile, relationship);


            //create person object, add to addressbook
            extPersonType person(fName, lName, day, month, year, street, city, state, zip, phone, relationship);
            addEntry(person);
        }
        infile.close();
    }

    //add an entry to the address book
    void addEntry(const extPersonType& person) {
        if (length < maxLength) {
            addressList[length] = person;
            ++length;
        }
        else {
            cout << "Address book is full" << endl;
        }
    }

    //find a person by last name
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

    //find people by birth month
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

    //find people by relationship
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

    //print
    void print() {
        for (int i = 0; i < length; i++) {
            addressList[i].print();
            cout << endl;
        }
    }

    //function sort entires insertion point
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