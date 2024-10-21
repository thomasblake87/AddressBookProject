#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "extPersonType.h"
#include "personType.h"
#include "AddressType.h"
#include "DateType.h"
#include "orderedLinkedList.h"

using namespace std;

class addressBookType : public orderedLinkedList<extPersonType>
{
public:

    addressBookType() {}

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
            this->insert(person);
        }
        infile.close();
    }

    //find a person by last name
    void findPerson(string lName) const {
        bool found = false;
        nodeType<extPersonType>* current = this->first;

        while (current != nullptr && !found) {
            if (current->info.getLastName() == lName) {
                current->info.print();
                found = true;
            }
            current = current->link;
        }
        if (!found) {
            cout << "Person not found" << endl;
        }
    }

    //find people by birth month
    void findBirthdays(int month) const {
        bool found = false;
        nodeType<extPersonType>* current = this->first;

        while (current != nullptr) {
            if (current->info.getBirthMonth() == month) {
                current->info.print();
                found = true;
            }
            current = current->link;
        }
        if (!found) {
            cout << "No entries found for the given month" << endl;
        }
    }

    //find people by relationship
    void findRelations(string relationship) const {
        bool found = false;
        nodeType<extPersonType>* current = this->first;

        while (current != nullptr) {
            if (current->info.getRelationship() == relationship) {
                current->info.print();
                found = true;
            }
            current = current->link;
        }
        if (!found) {
            cout << "No entries found for the given relationship" << endl;
        }
    }

    //print
    void print() {
        nodeType<extPersonType>* current = this->first;

        while (current != nullptr) {
            current->info.print();
            cout << endl;
            current = current->link;
        }
    }
};