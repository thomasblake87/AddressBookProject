#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "personType.h"
#include "AddressType.h"
#include "DateType.h"
using namespace std;

class extPersonType :
    public personType
{
private:
    addressType address;
    dateType birthDate;
    string phoneNumber;
    string relationship;
public:
    //Default constructor
    extPersonType() : 
        personType("", ""), 
        birthDate(1, 1, 1900), 
        address("", "", "XX", 10000), 
        phoneNumber(""), 
        relationship("") {}

    //Normal constructor
    extPersonType(string fName, string lName, int d, int m, int y, string str,
        string cit, string sta, int zip, string phone, string relat) :
        personType(fName, lName), birthDate(d, m, y), address(str, cit, sta, zip), phoneNumber(phone), relationship(relat) {}

    void setPhoneNumber(string phone) {
        phoneNumber = phone;
    }
    void setRelationship(string relat) {
        if (relat == "Family" || relat == "Friend" || relat == "Business") {
            relationship = relat;
        }
        else {
            relationship = "";
        }
    }

    string getPhoneNumber() {
        return phoneNumber;
    }

    string getRelationship() {
        return relationship;
    }

    int getBirthMonth() {
        return birthDate.getMonth();
    }

    void print() {
        personType::print();
        birthDate.print();
        address.print();
        cout << phoneNumber << endl;
        cout << relationship << endl;

    }
};

