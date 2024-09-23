#pragma once
#include <iostream>
#include <string>

using namespace std;

class addressType {
public:
    // Constructor with default parameter values
    addressType(string adr = "", string c = "", string st = "XX", int zip = 10000) {
        setAddress(adr);
        setCity(c);
        setState(st);
        setZipcode(zip);
    }

    // Setters
    void setAddress(string adr) {
        address = adr;
    }

    void setCity(string c) {
        city = c;
    }

    void setState(string st) {
        if (st.length() == 2) {
            state = st;
        }
        else {
            state = "XX";
        }
    }

    void setZipcode(int zip) {
        if (zip >= 11111 && zip <= 99999) {
            zipcode = zip;
        }
        else {
            zipcode = 10000;
        }
    }

    // Getters
    string getAddress() {
        return address;
    }

    string getCity() {
        return city;
    }

    string getState() {
        return state;
    }

    int getZipcode() {
        return zipcode;
    }

    // Print function
    void print() {
        cout << address << endl;
        cout << city << ", " << state << " " << zipcode << endl;
    }

private:
    string address;
    string city;
    string state;
    int zipcode;
};