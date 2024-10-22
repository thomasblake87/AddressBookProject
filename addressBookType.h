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
            addEntry(person);
        }
        infile.close();
    }

    void addEntry(const extPersonType& person){
        this->insert(person);
    }


    //find a person by last name
    void findPerson(string lName, string fName) const {
        bool found = false;
        string key = fName + " " + lName;
        nodeType<extPersonType>* current = this->first;

        while (current != nullptr && !found) {
            if (current->info.getKey() == key) {
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

    void addStrings(){

        nodeType<extPersonType>* current = this->first;

        string fName, lName, street, city, state, phone, relationship;
        int day, month, year, zip;
        cout << "Enter the first name of the person: ";
        cin >> fName;
        cout << "\nEnter the last name of the person: ";
        cin >> lName;
        cout << "\nEnter the month the person was born: ";
        cin >> month;
        cout << "\nEnter the day the person was born: ";
        cin >> day;
        cout << "\nEnter the year the person was born: ";
        cin >> year;
        cout << "\nEnter the street the person lives on: ";
        cin >> street;
        cout << "\nEnter the city the person lives in: ";
        cin >> city;
        cout << "\nEnter the abbreviation for the state the person lives in: ";
        cin >> state;
        cout << "\nEnter the zip code the person lives in: ";
        cin >> zip;
        cout << "\nEnter the persons phone number in the format XXX-XXX-XXXX: ";
        cin >> phone;
        cout << "\nEnter your relationship with the person (available answers are: Friend, Business, or Family): ";
        cin >> relationship;

        ofstream outFile("AddressBookData.txt");

        extPersonType person(fName, lName, day, month, year, street, city, state, zip, phone, relationship);
        this->addEntry(person);

        outFile << fName << " " << lName << endl;
        outFile << month << " " << day << " " << year << endl;
        outFile << street << endl << city << endl << state << endl;
        outFile << zip << endl;
        outFile << phone << endl;
        outFile << relationship << endl;

        outFile.close();
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